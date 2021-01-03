#include "standarduseraccountlogic.h"

StandardUserAccountLogic::StandardUserAccountLogic()
{

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of Authenticate class
    auth = new AuthenticateLogic();


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

        categoryIDQuery.bindValue(":selectedCategoryName", selectedTaskCategoryName);
        categoryIDQuery.bindValue(":loggedInAccountID", auth->getAccountID());

        // Executing sql query and checking the status
        if(!categoryIDQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << categoryIDQuery.lastError();
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
        taskQuery.bindValue(":loggedInAccountID", auth->getAccountID());
        taskQuery.bindValue(":selectedCategoryID", selectedCategoryIDDB);

        // Executing sql query and checking the status
        if(!taskQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << taskQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Unsuccessful: (SQL Query Error) Failed to Insert Task Record";
        }
        else{
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Successful: Task successfully added";
        }

    }
    else if(databaseConnected == false){
        qDebug() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
        return "Execution Unsuccessful: Database Connection Error";
    }

    trms_dbConnection->closeDatebaseConnection();
    return "default";
}
