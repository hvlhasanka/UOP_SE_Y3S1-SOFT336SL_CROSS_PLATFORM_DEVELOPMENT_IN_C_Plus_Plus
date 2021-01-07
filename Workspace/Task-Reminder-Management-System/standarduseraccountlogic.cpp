#include "standarduseraccountlogic.h"

StandardUserAccountLogic::StandardUserAccountLogic()
{

}

StandardUserAccountLogic::StandardUserAccountLogic(int accountID)
{
    passedAccountID = accountID;

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of Authenticate class
    auth = new AuthenticateLogic();

    // Creating an object of AccountLogic class
    account = new AccountLogic();

}

QString StandardUserAccountLogic::addNewTask(QString enteredTaskTitle, QString enteredTaskDescription, QString selectedTaskCategoryName){

    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        /* Retrieving categoryID for the selected categoryName and loggedInAccountID from 'Category' relation (table) */
        int selectedCategoryIDDB;
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery categoryIDQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        categoryIDQuery.prepare(QString("SELECT CategoryID FROM Category WHERE CategoryName = :selectedCategoryName AND aAccountID = :loggedInAccountID;"));
        qDebug() << account->getAccountID();
        categoryIDQuery.bindValue(":selectedCategoryName", selectedTaskCategoryName);
        categoryIDQuery.bindValue(":loggedInAccountID", passedAccountID);

        // Executing sql query and checking the status
        if(!categoryIDQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << categoryIDQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            if(categoryIDQuery.next()){
                selectedCategoryIDDB = categoryIDQuery.value(0).toInt();
            }
            else{
                return "Execution Unsuccessful: (SQL Query Error) Failed to retrieve CategoryID from database";
            }
        }


        /* Inserting record into the 'Task' relation (table)  */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery taskQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        taskQuery.prepare(QString("INSERT INTO Task(Title, TaskDescription, CreatedDateTime, LastEditDateTime, aAccountID, cCategoryID) VALUES "
                                              "(:enteredTaskTitle, :enteredTaskDescription, :currentDateTime, :currentDateTime, :loggedInAccountID, :selectedCategoryID);"));

        taskQuery.bindValue(":enteredTaskTitle", enteredTaskTitle);
        taskQuery.bindValue(":enteredTaskDescription", enteredTaskDescription);
        taskQuery.bindValue(":currentDateTime", auth->retrieveCurrentDateTime());
        taskQuery.bindValue(":loggedInAccountID", passedAccountID);
        taskQuery.bindValue(":selectedCategoryID", selectedCategoryIDDB);

        // Executing sql query and checking the status
        if(!taskQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << taskQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Unsuccessful: (SQL Query Error) Failed to Insert Task Record";
        }
        else{
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Successful: Task successfully added";
        }

    }
    else if(databaseConnected == false){
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
        return "Execution Unsuccessful: Database Connection Error";
    }

    trms_dbConnection->closeDatebaseConnection();
    return "default";
}


QString StandardUserAccountLogic::setNewReminder(int taskID, QString reminderDateTime){

    /* Adding reminder record into 'Reminder' relation (table) */
    // Assigning database configuration
    databaseConnection = QSqlDatabase::addDatabase("QSQLITE", "trms_db");
    databaseConnection.setDatabaseName("C:/Users/Lucas.L.H.H/Documents/GitHub/UOP_SE_Y3S1-SOFT336SL_CROSS_PLATFORM_DEVELOPMENT_IN_C_Plus_Plus/Workspace/Task-Reminder-Management-System/database/trms_db.db");

    // Establishing database connection and checking connection status
    if (!databaseConnection.open()){
        qWarning() << "Database Connection Error";
        qWarning() << databaseConnection.lastError();
        return "Execution Unsuccessful: Database Connection Error";
    }
    else{
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reminderQuery(QSqlDatabase::database("trms_db"));

        // Preparing sql query for execution
        reminderQuery.prepare(QString("INSERT INTO Reminder(ReminderDateTime, tTaskID) VALUES "
                                      "(:reminderDateTime, :taskID);"));

        reminderQuery.bindValue(":reminderDateTime", reminderDateTime);
        reminderQuery.bindValue(":taskID", taskID);

        // Executing sql query and checking the status
        if(!reminderQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << reminderQuery.lastError();
            return "Execution Unsuccessful: (SQL Query Error)";
        }
        else{
            return "Execution Successful: Reminder successfully added";
        }
    }


    // Closing established database connection
    databaseConnection.close();
    databaseConnection.removeDatabase(QSqlDatabase::defaultConnection);
    qWarning() << "Database Connection Closed";
    return 0;
}

QString StandardUserAccountLogic::changeAccountType(int accountID, int accountTypeID)
{

    // Updating account record in the database
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery accountTypeQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        accountTypeQuery.prepare(QString("UPDATE Account SET atAccountTypeID = :accountTypeID WHERE AccountID = :accountID;"));

        accountTypeQuery.bindValue(":accountTypeID", accountTypeID);
        accountTypeQuery.bindValue(":accountID", accountID);

        // Executing sql query and checking the status
        if(!accountTypeQuery.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Unsuccessful: (SQL Query Error)";
        }
        else{
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Successful: Account Type Updated";
        }
    }
    else if(databaseConnected == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
        return "Execution Unsuccessful: Database Connection Error";
    }
    return "default";
}

QString StandardUserAccountLogic::editTaskDetails(int accountID, int taskID, QString newTaskTitle, QString newTaskDescription, QString selectedCategoryName)
{

    // Assigning database configuration
    databaseConnection = QSqlDatabase::addDatabase("QSQLITE", "trms_db");
    databaseConnection.setDatabaseName("C:/Users/Lucas.L.H.H/Documents/GitHub/UOP_SE_Y3S1-SOFT336SL_CROSS_PLATFORM_DEVELOPMENT_IN_C_Plus_Plus/Workspace/Task-Reminder-Management-System/database/trms_db.db");

    // Establishing database connection and checking connection status
    if (!databaseConnection.open()){
        qWarning() << "Database Connection Error";
        qWarning() << databaseConnection.lastError();
        return "Execution Unsuccessful: Database Connection Error";
    }
    else{

        /* Retrieving categoryID for the selected categoryName from the database */
        int categoryIDDB = 0;
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery categoryIDDBQuery(QSqlDatabase::database("trms_db"));

        // Preparing sql query for execution
        categoryIDDBQuery.prepare(QString("SELECT CategoryID FROM Category WHERE CategoryName = :categoryName AND aAccountID = :accountID;"));

        categoryIDDBQuery.bindValue(":categoryName", selectedCategoryName);
        categoryIDDBQuery.bindValue(":accountID", accountID);

        // Executing sql query and checking the status
        if(!categoryIDDBQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << categoryIDDBQuery.lastError();
            return "Execution Unsuccessful: (SQL Query Error)";
        }
        else{
            if(categoryIDDBQuery.next()){
                categoryIDDB = categoryIDDBQuery.value(0).toInt();
            }
        }


        /* Adding updated task details value into the 'Task' relation (table) */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery taskQuery(QSqlDatabase::database("trms_db"));

        // Preparing sql query for execution
        taskQuery.prepare(QString("UPDATE Task SET Title = :taskTitle, TaskDescription = :taskDescription, LastEditDateTime = :currentDateTime, cCategoryID = :categoryID "
                                  "WHERE TaskID = :taskID;"));

        taskQuery.bindValue(":taskTitle", newTaskTitle);
        taskQuery.bindValue(":taskDescription", newTaskDescription);
        taskQuery.bindValue(":currentDateTime", auth->retrieveCurrentDateTime());
        taskQuery.bindValue(":categoryID", categoryIDDB);
        taskQuery.bindValue(":taskID", taskID);

        // Executing sql query and checking the status
        if(!taskQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << taskQuery.lastError();
            return "Execution Unsuccessful: (SQL Query Error)";
        }
        else{
            return "Execution Successful: Task Details Successfully Updated";
        }

    }


    // Closing established database connection
    databaseConnection.close();
    databaseConnection.removeDatabase(QSqlDatabase::defaultConnection);
    qWarning() << "Database Connection Closed";
    return 0;

}
