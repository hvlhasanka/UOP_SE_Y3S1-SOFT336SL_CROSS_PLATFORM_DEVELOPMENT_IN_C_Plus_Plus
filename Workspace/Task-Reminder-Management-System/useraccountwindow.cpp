#include "useraccountwindow.h"
#include "ui_useraccountwindow.h"

UserAccountWindow::UserAccountWindow(int loginID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserAccountWindow)
{
    ui->setupUi(this);

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix(":/images/TRMS-Logo-Without-Text.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));

    // Creating an object of AccountLogic class
    account = new AccountLogic();

    // Creating an object of AuthenticateLogic class
    auth = new AuthenticateLogic();

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    /* Retrieving the relevant user details from the database */
    bool databaseConnection = trms_dbConnection->openDatebaseConnection();


    /* Setting timer and sending signals to function every second */
    // Declaring a new object of the 'QObject' class
    timer = new QTimer(this);
    // SIGNAL AND SLOT - Signal used to call the executeReminderStandardUserAccount() function when timer is timeout()
    connect(timer, SIGNAL(timeout()), this, SLOT(executeReminderStandardUserAccount()));
    // Assgining number of milliseconds during each time gap
    // 1 seconds - 1000 milliseconds
    timer->start(1000);


    /* Setting reminder alert implementation */
    // Creating a new object of 'QSystemTrayIcon' object
    reminderAlert = new QSystemTrayIcon(this);
    // Setting icon path
    reminderAlert->setIcon(QIcon(":/images/TRMS-Logo-Without-Text.ico"));
    // Setting reminderAlert to be visible
    reminderAlert->setVisible(true);


    // SIGNAL AND SLOT - Used to call changeUIForSelectedDate(QDate) when ui->taskReminders_calendarWidget is clicked(QDate)
    // User interfae will change accordingly to the selected date
    connect(ui->taskReminders_calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(changeUIForSelectedDate(QDate)));


    if(databaseConnection == true){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery userDetailsQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        userDetailsQuery.prepare(QString("SELECT l.LoginID, a.AccountID, np.NamePrefix, a.FirstName, a.MiddleName, a.LastName, "
                                         "a.CreatedDateTime, at.AccountTypeID, at.AccountType, bv.BooleanValueID, bv.BooleanValue FROM "
                                         "Login l INNER JOIN Account a ON l.LoginID = a.lLoginID "
                                         "INNER JOIN NamePrefix np ON np.NamePrefixID = a.npNamePrefixID "
                                         "INNER JOIN AccountType at ON at.AccountTypeID = a.atAccountTypeID "
                                         "INNER JOIN BooleanValue bv ON bv.BooleanValueID = a.dvDoNotDistrubBooleanValueID "
                                         "WHERE LoginID=:loginID;"));

        userDetailsQuery.bindValue(":loginID", loginID);

        // Executing sql query and checking the status
        if(!userDetailsQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << userDetailsQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
        }
        else{
            if(userDetailsQuery.next()){
                account->setLoginID(userDetailsQuery.value(0).toInt());
                account->setAccountID(userDetailsQuery.value(1).toInt());
                account->setNamePrefix(userDetailsQuery.value(2).toString());
                account->setFirstName(userDetailsQuery.value(3).toString());
                account->setMiddleName(userDetailsQuery.value(4).toString());
                account->setLastName(userDetailsQuery.value(5).toString());
                account->setCreatedDateTime(userDetailsQuery.value(6).toString());
                account->setAccountTypeID(userDetailsQuery.value(7).toInt());
                account->setAccountType(userDetailsQuery.value(8).toString());
                account->setDoNotDistrubBooleanValueID(userDetailsQuery.value(9).toInt());
                account->setDoNotDistrubBooleanValue(userDetailsQuery.value(10).toBool());
            }
            else{
                qWarning() << "User Account Details Successfully retrieved from Database";
            }
            trms_dbConnection->closeDatebaseConnection();
        }
    }
    else{
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
    }

   // account->setAccountActivityID(1);
   // account->setAccountActivity("Online");





    /* DASHBOARD TAB */
    // Setting welcome messages to hide (false)
    ui->welcomeToTRMSMessage_label->setVisible(false);
    ui->welcomeBackMessage_label->setVisible(false);

    /* Changin the 'Welcome' message in the Dasbboard tab to show the relevant message for new users and existing users */
    QString recordCount;
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Checking whether there are existing records of the user logged in before in the 'LoginActivity' relation (table)
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery messageQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        messageQuery.prepare(QString("SELECT COUNT(LoginDateTime) as 'RecordCount' FROM LoginActivity WHERE lLoginID = :loginID;"));

        messageQuery.bindValue(":loginID", account->getLoginID());

        // Executing sql query and checking the status
        if(!messageQuery.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << messageQuery.lastError();
        }
        else{
            if(messageQuery.next()){
                recordCount = messageQuery.value(0).toString();
            }
        }

        if(recordCount.toInt() == 1){
            ui->welcomeToTRMSMessage_label->setVisible(true);
        }
        else if(recordCount.toInt() > 1){
            ui->welcomeBackMessage_label->setVisible(true);
        }
    }
    else if(databaseConnected == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }


    /* Retrieving data from database to show statictcs in the dashboard tab */
    bool databaseConnectedStat = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectedStat == true){

        /* Geting the number to upcoming reminders */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery noOfRemindersQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        noOfRemindersQuery.prepare(QString("SELECT COUNT(r.ReminderID) FROM Reminder r INNER JOIN Task t ON t.TaskID = r.tTaskID "
                                           "WHERE t.aAccountID = :accountID AND r.ReminderDateTime > ':currentDateTime';"));

        noOfRemindersQuery.bindValue(":accountID", account->getAccountID());
        noOfRemindersQuery.bindValue(":currentDateTime", auth->retrieveCurrentDateTime());

        // Executing sql query and checking the status
        if(!noOfRemindersQuery.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << noOfRemindersQuery.lastError();
        }
        else{
            if(noOfRemindersQuery.next()){
                ui->noOfReminders_label->setText(noOfRemindersQuery.value(0).toString());
            }
        }

        /* Getting the number of assigned tasks */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery noOfTasksQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        noOfTasksQuery.prepare(QString("SELECT COUNT(TaskID) FROM Task WHERE aAccountID = :accountID;"));

        noOfTasksQuery.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!noOfTasksQuery.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << noOfTasksQuery.lastError();
        }
        else{
            if(noOfTasksQuery.next()){
                ui->noOfTasks_label->setText(noOfTasksQuery.value(0).toString());
            }
        }
    }
    else if(databaseConnectedStat == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }





    /* TASKS TAB */

    ui->showTaskDetails_pushButton->setEnabled(false);

    /* Checking account type to show 'Do Not Disturb' check box */
    ui->doNotDisturb_frame->setVisible(false);
    if(account->getAccountType() == "Premium User Account"){
        ui->doNotDisturb_frame->setVisible(true);
    }

    /* Assigning the user's name in the 'Dashboard' tab */
    ui->name_label->setText(account->getNamePrefix() + " " + account->getFirstName() + "  " + account->getLastName());


    /* Retrieving the category names from the database and assigning them in the user interface */
    bool databaseConnectedCategoryName = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectedCategoryName == true){

        // Category 1 Name
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category1Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category1Query.prepare(QString("SELECT c.CategoryName FROM "
                                       "Category c INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                       "WHERE aAccountID = :accountID AND ct.CategoryType = 'Category 1';"));

        category1Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category1Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category1Query.lastError();
        }
        else{
            if(category1Query.next()){
                ui->category1_label->setText(category1Query.value(0).toString());
            }
            trms_dbConnection->closeDatebaseConnection();
        }


        // Category 2 Name
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category2Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category2Query.prepare(QString("SELECT c.CategoryName FROM "
                                       "Category c INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                       "WHERE aAccountID = :accountID AND ct.CategoryType = 'Category 2';"));

        category2Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category2Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category2Query.lastError();
        }
        else{
            if(category2Query.next()){
                ui->category2_label->setText(category2Query.value(0).toString());
            }
            trms_dbConnection->closeDatebaseConnection();
        }

        // Category 3 Name
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category3Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category3Query.prepare(QString("SELECT c.CategoryName FROM "
                                       "Category c INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                       "WHERE aAccountID = :accountID AND ct.CategoryType = 'Category 3';"));

        category3Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category3Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category3Query.lastError();
        }
        else{
            if(category3Query.next()){
                ui->category3_label->setText(category3Query.value(0).toString());
            }
            trms_dbConnection->closeDatebaseConnection();
        }


        // Category 4 Name
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category4Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category4Query.prepare(QString("SELECT c.CategoryName FROM "
                                       "Category c INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                       "WHERE aAccountID = :accountID AND ct.CategoryType = 'Category 4';"));

        category4Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category4Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category4Query.lastError();
        }
        else{
            if(category4Query.next()){
                ui->category4_label->setText(category4Query.value(0).toString());
            }
            trms_dbConnection->closeDatebaseConnection();
        }

    }
    else if(databaseConnectedCategoryName == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }



    // Setting 'No Reminder Assigned' message to hide (false)
    ui->noRemindersAssigned_label->setVisible(false);


    // Setting 'No Tasks Available' messages to hide (false)
    ui->category1NoAvailableTasks_label->setVisible(false);
    ui->category2NoAvailableTasks_label->setVisible(false);
    ui->category3NoAvailableTasks_label->setVisible(false);
    ui->category4NoAvailableTasks_label->setVisible(false);


    /* Retrieving task details from the database and populating the relevant table views according the to category type */
    bool databaseConnectedCategory = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectedCategory == true){

        // Category 1 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category1Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category1Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 1';"));

        category1Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category1Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category1Query.lastError();
        }
        else{
            if(category1Query.next()){
                QSqlQueryModel *category1Modal = new QSqlQueryModel();
                category1Modal->setQuery(category1Query);

                ui->category1_tableView->setModel(category1Modal);
                ui->category1_tableView->resizeColumnsToContents();
            }
            else{
                ui->category1NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

        // Category 2 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category2Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category2Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 2';"));

        category2Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category2Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category2Query.lastError();
        }
        else{
            if(category2Query.next()){
                QSqlQueryModel *category2Model = new QSqlQueryModel();
                category2Model->setQuery(category2Query);

                ui->category2_tableView->setModel(category2Model);
                ui->category2_tableView->resizeColumnsToContents();
            }
            else{
                ui->category2NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

        // Category 3 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category3Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category3Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 3';"));

        category3Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category3Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category3Query.lastError();
        }
        else{
            if(category3Query.next()){
                QSqlQueryModel *category3Modal = new QSqlQueryModel();
                category3Modal->setQuery(category3Query);

                ui->category3_tableView->setModel(category3Modal);
                ui->category3_tableView->resizeColumnsToContents();
            }
            else{
                ui->category3NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

        // Category 4 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category4Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category4Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 4';"));

        category4Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category4Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category4Query.lastError();
        }
        else{
            if(category4Query.next()){
                QSqlQueryModel *category4Model = new QSqlQueryModel();
                category4Model->setQuery(category4Query);

                ui->category4_tableView->setModel(category4Model);
                ui->category4_tableView->resizeColumnsToContents();
            }
            else{
                ui->category4NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

    }
    else if(databaseConnectedCategory == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }



    /* REMINDERS TAB */

    /* Retrieving the current data, reminders on the current date and applying it to the user interface */
    QDate currentDate = QDate::currentDate();
    this->changeUIForSelectedDate(currentDate);



    /* PROFILE TAB */

    /* Profile Image Implementation Source Code */
    // Getting the profile image
    QPixmap profileImagePix(":/images/ProfileImage.png");
    // Getting the width of the profileImage_label
    int profileLabelWidth = ui->profileImage_label->width();
    // Getting the height of the profileImage_label
    int profileLabelHeight = ui->profileImage_label->height();
    // Setting the profile image of the profileImage_label
    ui->profileImage_label->setPixmap(profileImagePix.scaled(profileLabelWidth, profileLabelHeight, Qt::KeepAspectRatio));

    /* Assigning user data into the user inferface */
    ui->nameText_label->setText(account->getNamePrefix() + " " + account->getFirstName() + "  " + account->getMiddleName() + " " + account->getLastName());
    ui->accountTypeText_label->setText(account->getAccountType());
    ui->accountCreatedDateTimeText_label->setText(account->getCreatedDateTime());


    bool databaseConnectedEmailAddress = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectedEmailAddress == true){

        // Getting the user email address from the database
        QSqlQuery emailAddressQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        emailAddressQuery.prepare(QString("SELECT l.EmailAddress FROM "
                                          "Login l INNER JOIN Account a ON l.loginID = a.lLoginID "
                                          "WHERE a.AccountID = :accountID;"));

        emailAddressQuery.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!emailAddressQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << emailAddressQuery.lastError();
        }
        else{
            while(emailAddressQuery.next()){
                ui->emailAddressText_label->setText(emailAddressQuery.value(0).toString());
            }
        }

        /* Retrieving the account activity details from the database */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery accountActivityQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        accountActivityQuery.prepare(QString("SELECT la.LoginDateTime as 'Login Date Time', la.LogoutDateTime as 'Logout Date Time', aa.AccountActivity as 'Account Activity' FROM "
                                             "LoginActivity la INNER JOIN Login l ON l.LoginID = la.lLoginID "
                                             "INNER JOIN AccountActivity aa ON aa.AccountActivityID = la.aaAccountActivityID "
                                             "INNER JOIN Account a ON l.LoginID = a.lLoginID "
                                             "WHERE a.AccountID = :accountID ORDER BY la.LoginDateTime DESC;"));

        accountActivityQuery.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!accountActivityQuery.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << accountActivityQuery.lastError();
        }
        else{
            if(accountActivityQuery.next()){
                QSqlQueryModel *accountActivityModel = new QSqlQueryModel();
                accountActivityModel->setQuery(accountActivityQuery);

                ui->accountActivity_tableView->setModel(accountActivityModel);
                ui->accountActivity_tableView->resizeColumnsToContents();
            }

            trms_dbConnection->closeDatebaseConnection();
        }

    }
    else if(databaseConnectedEmailAddress == false){
        qWarning() << "Database Connectivity ERROR";
    }


    /* SETTINGS TAB */

    /* About Image Implementation Source Code */
    // Getting the about image
    QPixmap aboutImagePix(":/images/AboutImage.png");
    // Getting the width of the aboutImage_label
    int aboutLabelWidth = ui->aboutImage_label->width();
    // Getting the height of the aboutImage_label
    int aboutLabelHeight = ui->aboutImage_label->height();
    // Setting the cover image of the aboutImage_label
    ui->aboutImage_label->setPixmap(aboutImagePix.scaled(aboutLabelWidth, aboutLabelHeight, Qt::KeepAspectRatio));

    // Assigning account type to the user interface
    ui->standardAccount_radioButton->setChecked(false);
    ui->premiumAccount_radioButton->setChecked(false);
    if(account->getAccountType() == "Standard User Account"){
        ui->standardAccount_radioButton->setChecked(true);
    }
    else if(account->getAccountType() == "Premium User Account"){
        ui->premiumAccount_radioButton->setChecked(false);
    }


}

UserAccountWindow::~UserAccountWindow()
{
    delete ui;
}

// Function used to identify the time to run the reminder and will execute the reminder functionality
void UserAccountWindow::executeReminderStandardUserAccount()
{

    // Getting current datetime
    QString currentDateTime = auth->retrieveCurrentDateTime();

    /* Retrieving all available reminders from the 'Reminders' relation (table) */
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        QSqlQuery remindersQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        remindersQuery.prepare(QString("SELECT r.ReminderID, r.ReminderDateTime, t.Title, t.TaskDescription FROM "
                                       "Reminder r INNER JOIN Task t ON t.TaskID = r.tTaskID "
                                       "WHERE t.aAccountID = :accountID;"));

        remindersQuery.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!remindersQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << remindersQuery.lastError();
        }
        else{
            while(remindersQuery.next()){
                if(currentDateTime == remindersQuery.value(1).toString()){
                    reminderAlert->showMessage(remindersQuery.value(2).toString(), remindersQuery.value(2).toString());
                    QString removeExecutedReminderStatus = account->removeReminder(remindersQuery.value(0).toInt());
                    if(removeExecutedReminderStatus == "Execution Unsuccessful: (SQL Query Error)"){
                        qWarning() << "ERROR: SQL Query execution error";
                    }
                    else if(removeExecutedReminderStatus == "Execution Unsuccessful: Database Connection Error"){
                        qWarning() << "ERROR: Database Connectivity Error";
                    }
                }
            }
        }
    }
    else if(databaseConnected == false){
        qWarning() << "Database Connectivity ERROR";
    }
    trms_dbConnection->closeDatebaseConnection();

}

void UserAccountWindow::executeReminderPremiumUserAccount()
{

}

void UserAccountWindow::changeUIForSelectedDate(QDate selectedDate)
{

    // Setting 'No Reminder Assigned' message to hide (false)
    ui->noRemindersAssigned_label->setVisible(false);

    // Reformatting QDate that was sent as a parameter
    QString selectedDateReformat = selectedDate.toString("dddd, d MMMM yyyy");

    // Assigning the reformatted QDate value
    ui->selectedDate_label->setText(selectedDateReformat);

    /* Retrieving the reminders details and task details from the database */
    bool databaseConnectedCategory = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectedCategory == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reminderQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        reminderQuery.prepare(QString("SELECT r.ReminderID as 'Reminder ID', r.ReminderDateTime as 'Reminder Date Time', t.TaskID as 'Task ID', "
                                      "t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                      "Reminder r INNER JOIN Task t ON t.TaskID = r.tTaskID "
                                      "INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                      "WHERE t.aAccountID == :accountID AND r.ReminderDateTime LIKE :selectedDateTime;"));

        reminderQuery.bindValue(":accountID", account->getAccountID());
        reminderQuery.bindValue(":selectedDateTime", (selectedDate.toString("yyyy-MM-dd") + "%"));

        // Executing sql query and checking the status
        if(!reminderQuery.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << reminderQuery.lastError();
        }
        else{
            if(reminderQuery.next()){
                QSqlQueryModel *reminderModal = new QSqlQueryModel();
                reminderModal->setQuery(reminderQuery);

                ui->taskReminders_tableView->setModel(reminderModal);
              //  ui->category1_tableView->resizeColumnsToContents();
            }
            else{
                ui->noRemindersAssigned_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }
    }
    else if(databaseConnectedCategory == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }

}

void UserAccountWindow::on_addNewTask_pushButton_clicked()
{
    // Openning the appropriate add new task window according to the account type
    if(account->getAccountType() == "Standard User Account"){
        addNewTaskStandardUserAccountWindowForm = new AddNewTaskStandardUserAccountWindow(account->getAccountID(), this);
        addNewTaskStandardUserAccountWindowForm->show();
    }
    else if(account->getAccountType() == "Premium User Account"){
        addNewTaskPremiumUserAccountWindowForm = new AddNewTaskPremiumUserAccountWindow(account->getAccountID(), this);
        addNewTaskPremiumUserAccountWindowForm->show();
    }
}

void UserAccountWindow::on_report_pushButton_clicked()
{

    reportSubmissionWindowForm = new ReportSubmissionWindow(this);
    reportSubmissionWindowForm->show();

}

void UserAccountWindow::on_logout_pushButton_clicked()
{

    // Showing message box to the user to get the confirmation to logout
    int userLogoutResponse = QMessageBox::question(this, "LOGOUT CONFIRMATION",
                          "This action will logout you out, do you want to continue?"
                          , "Cancel", "Continue");

    if(userLogoutResponse == 1){
        /* Recording session end */
        QString sessionEndStatus = auth->addSessionEndToDB(account->getLoginID());

        if(sessionEndStatus == "Session End Recorded"){
            this->hide();
        }
        else if(sessionEndStatus == "SQL Execution Failed"){
            QMessageBox::critical(this, "LOGIN - SESSION END ERROR", "SQL query execution was unsuccessful, please submit a report including your email address.");
        }
        else if(sessionEndStatus == "Database Connectivity Failed"){
            QMessageBox::critical(this, "LOGIN - SESSION END ERROR", "Database Connection has lost, please submit a report.");
        }

    }

}


void UserAccountWindow::on_refresh_pushButton_clicked()
{

    // Setting 'No Tasks Available' messages to hide (false)
    ui->category1NoAvailableTasks_label->setVisible(false);
    ui->category2NoAvailableTasks_label->setVisible(false);
    ui->category3NoAvailableTasks_label->setVisible(false);
    ui->category4NoAvailableTasks_label->setVisible(false);


    /* Retrieving task details from the database and populating the relevant table views according the to category type */
    bool databaseConnectedCategory = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectedCategory == true){

        // Category 1 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category1Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category1Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 1';"));

        category1Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category1Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category1Query.lastError();
        }
        else{
            if(category1Query.next()){
                QSqlQueryModel *category1Modal = new QSqlQueryModel();
                category1Modal->setQuery(category1Query);

                ui->category1_tableView->setModel(category1Modal);
                ui->category1_tableView->resizeColumnsToContents();
            }
            else{
                ui->category1NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

        // Category 2 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category2Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category2Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 2';"));

        category2Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category2Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category2Query.lastError();
        }
        else{
            if(category2Query.next()){
                QSqlQueryModel *category2Model = new QSqlQueryModel();
                category2Model->setQuery(category2Query);

                ui->category2_tableView->setModel(category2Model);
                ui->category2_tableView->resizeColumnsToContents();
            }
            else{
                ui->category2NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

        // Category 3 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category3Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category3Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 3';"));

        category3Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category3Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category3Query.lastError();
        }
        else{
            if(category3Query.next()){
                QSqlQueryModel *category3Modal = new QSqlQueryModel();
                category3Modal->setQuery(category3Query);

                ui->category3_tableView->setModel(category3Modal);
                ui->category3_tableView->resizeColumnsToContents();
            }
            else{
                ui->category3NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

        // Category 4 Tasks
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category4Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category4Query.prepare(QString("SELECT t.TaskID as 'Task ID', t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                     "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                     "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                     "WHERE t.aAccountID == :accountID AND ct.CategoryType = 'Category 4';"));

        category4Query.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category4Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category4Query.lastError();
        }
        else{
            if(category4Query.next()){
                QSqlQueryModel *category4Model = new QSqlQueryModel();
                category4Model->setQuery(category4Query);

                ui->category4_tableView->setModel(category4Model);
                ui->category4_tableView->resizeColumnsToContents();
            }
            else{
                ui->category4NoAvailableTasks_label->setVisible(true);
            }

            trms_dbConnection->closeDatebaseConnection();
        }

    }
    else if(databaseConnectedCategory == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }


}



void UserAccountWindow::on_showTaskDetails_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered task IS value is in the correct regular expression
    // arg1 = ui->showTaskDetails_lineEdit->text();
    QString enteredTaskID = arg1;
    QRegularExpression re("[0-9]+");
    QRegularExpressionMatch validationCheck = re.match(enteredTaskID);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->showTaskDetails_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
        ui->showTaskDetails_pushButton->setEnabled(true);
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->showTaskDetails_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
        ui->showTaskDetails_pushButton->setEnabled(false);
    }

}

void UserAccountWindow::on_showTaskDetails_pushButton_clicked()
{

    viewTaskStandardUserAccountDialogForm = new ViewTaskStandardUserAccountDialog(ui->showTaskDetails_lineEdit->text().toInt(), this);
    viewTaskStandardUserAccountDialogForm->show();

}


void UserAccountWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0){
        // DASHBOARD TAB

        /* Retrieving data from database to show statictcs in the dashboard tab */
        bool databaseConnectedStat = trms_dbConnection->openDatebaseConnection();
        if(databaseConnectedStat == true){

            /* Geting the number to upcoming reminders */
            // Declaring new QSqlQuery object by passing the database name
            QSqlQuery noOfRemindersQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

            // Preparing sql query for execution
            noOfRemindersQuery.prepare(QString("SELECT COUNT(r.ReminderID) FROM Reminder r INNER JOIN Task t ON t.TaskID = r.tTaskID "
                                               "WHERE t.aAccountID = :accountID AND r.ReminderDateTime > ':currentDateTime';"));

            noOfRemindersQuery.bindValue(":accountID", account->getAccountID());
            noOfRemindersQuery.bindValue(":currentDateTime", auth->retrieveCurrentDateTime());

            // Executing sql query and checking the status
            if(!noOfRemindersQuery.exec()){
                qWarning() << "SQL query execution error";
                trms_dbConnection->closeDatebaseConnection();
                qWarning() << noOfRemindersQuery.lastError();
            }
            else{
                if(noOfRemindersQuery.next()){
                    ui->noOfReminders_label->setText(noOfRemindersQuery.value(0).toString());
                }
            }

            /* Getting the number of assigned tasks */
            // Declaring new QSqlQuery object by passing the database name
            QSqlQuery noOfTasksQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

            // Preparing sql query for execution
            noOfTasksQuery.prepare(QString("SELECT COUNT(TaskID) FROM Task WHERE aAccountID = :accountID;"));

            noOfTasksQuery.bindValue(":accountID", account->getAccountID());

            // Executing sql query and checking the status
            if(!noOfTasksQuery.exec()){
                qWarning() << "SQL query execution error";
                trms_dbConnection->closeDatebaseConnection();
                qWarning() << noOfTasksQuery.lastError();
            }
            else{
                if(noOfTasksQuery.next()){
                    ui->noOfTasks_label->setText(noOfTasksQuery.value(0).toString());
                }
            }
        }
        else if(databaseConnectedStat == false){
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << "Database Connection Error";
        }
    }
}

void UserAccountWindow::on_standardAccount_radioButton_toggled(bool checked)
{
    if(checked == true){
        ui->premiumAccount_radioButton->setChecked(false);
    }
    else if(checked == false){
        ui->premiumAccount_radioButton->setChecked(true);
    }
}

void UserAccountWindow::on_premiumAccount_radioButton_toggled(bool checked)
{
    if(checked == true){
        ui->standardAccount_radioButton->setChecked(false);
    }
    else if(checked == false){
        ui->standardAccount_radioButton->setChecked(true);
    }
}

void UserAccountWindow::on_change_Membership_pushButton_clicked()
{

    // Updating account record in the database
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery accountTypeQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        accountTypeQuery.prepare(QString("UPDATE Account SET atAccountTypeID = :accountTypeID WHERE AccountID = :accountID;"));

        if(ui->standardAccount_radioButton->isChecked()){
            accountTypeQuery.bindValue(":accountTypeID", 1);

            account->setAccountTypeID(1);
            account->setAccountType("Standard User Account");
        }
        else if(ui->premiumAccount_radioButton->isChecked()){
            accountTypeQuery.bindValue(":accountTypeID", 2);

            account->setAccountTypeID(2);
            account->setAccountType("Premium User Account");
        }
        accountTypeQuery.bindValue(":accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!accountTypeQuery.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
        }
        else{
            if(accountTypeQuery.next()){
                ui->noOfReminders_label->setText(accountTypeQuery.value(0).toString());
            }
        }
    }
    else if(databaseConnected == false){
        qWarning() << "Database Connection Error";
    }
    trms_dbConnection->closeDatebaseConnection();

}



void UserAccountWindow::on_editReminder_pushButton_clicked()
{

    editReminderDetailsStandardUserAccountForm = new EditReminderDetailsStandardUserAccount(ui->editReminder_lineEdit->text().toInt(), this);
    editReminderDetailsStandardUserAccountForm->show();

}

void UserAccountWindow::on_actionAbout_triggered()
{

    aboutDialogForm = new AboutDialog(this);
    aboutDialogForm->show();

}
