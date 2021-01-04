#include "useraccountwindow.h"
#include "ui_useraccountwindow.h"

UserAccountWindow::UserAccountWindow(int loginID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserAccountWindow)
{
    ui->setupUi(this);

    // Creating an object of AccountLogic class
    account = new AccountLogic();

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    /* Retrieving the relevant user details from the database */
    bool databaseConnection = trms_dbConnection->openDatebaseConnection();

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
                trms_dbConnection->closeDatebaseConnection();
                qWarning() << "User Account Details Successfully retrieved from Database";
            }
        }
    }
    else{
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
    }

   // account->setAccountActivityID(1);
   // account->setAccountActivity("Online");

    /* Do Not Disturb Image Implementation Source Code */
    // Getting the Do Not Disturb image
    QPixmap doNotDisturbImagePix(":/images/Do-Not-Distrub.png");
    // Getting the width of the doNotDisturbImage_label
    int doNotDisturbLabelWidth = ui->doNotDisturbImage_label->width();
    // Getting the height of the doNotDisturbImage_label
    int doNotDisturbLabelHeight = ui->doNotDisturbImage_label->height();
    // Setting the cover image of the doNotDisturbImage_label
    ui->doNotDisturbImage_label->setPixmap(doNotDisturbImagePix.scaled(doNotDisturbLabelWidth, doNotDisturbLabelHeight, Qt::KeepAspectRatio));

    /* Logout Image Implementation Source Code */
    // Getting the Logout image
    QPixmap logoutImagePix(":/images/Logout.png");
    // Getting the width of the logoutImage_label
    int logoutLabelWidth = ui->logoutImage_label->width();
    // Getting the height of the logoutImage_label
    int logoutLabelHeight = ui->logoutImage_label->height();
    // Setting the cover image of the doNotDisturbImage_label
    ui->logoutImage_label->setPixmap(logoutImagePix.scaled(logoutLabelWidth, logoutLabelHeight, Qt::KeepAspectRatio));


    /* Changin the 'Welcome' message in the Dasbboard tab to show the relevant message for new users and existing users */
    QString recordCount;
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Checking whether there are existing records of the user logged in before in the 'LoginActivity' relation (table)
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery messageQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        messageQuery.prepare(QString("SELECT COUNT(LoginDateTime) as 'RecordCount' FROM LoginActivity WHERE lLoginID = :loginID;"));

        messageQuery.bindValue("loginID", account->getLoginID());

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
            ui->welcomeMessage_label->text().clear();
            ui->welcomeMessage_label->text() = "Welcome to TRMS!,";
        }
        else if(recordCount.toInt() > 1){
            ui->welcomeMessage_label->text().clear();
            ui->welcomeMessage_label->text() = "Welcome Back,";
        }
    }
    else if(databaseConnected == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }



    /* Retrieving task details from the database and populating the relevant table views according the to category type */

    // Category 1
    bool databaseConnectedCategory = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery category1Query(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        category1Query.prepare(QString("SELECT t.Title as 'Task Title', t.TaskDescription as 'Task Description', c.CategoryName as 'Category Name' FROM "
                                                 "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                                 "INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                                 "WHERE t.aAccountID == 1 AND ct.CategoryType = 'Category 1';"));

        category1Query.bindValue("accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!category1Query.exec()){
            qWarning() << "SQL query execution error";
            trms_dbConnection->closeDatebaseConnection();
            qWarning() << category1Query.lastError();
        }
        else{
            QSqlQueryModel *category1Modal = new QSqlQueryModel();
            category1Modal->setQuery(category1Query);

            ui->category1_tableView->setModel(category1Modal);
            ui->category1_tableView->resizeColumnsToContents();

            trms_dbConnection->closeDatebaseConnection();
        }
    }
    else if(databaseConnectedCategory == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }




}

UserAccountWindow::~UserAccountWindow()
{
    delete ui;
}

void UserAccountWindow::on_addNewTask_pushButton_clicked()
{
    // Openning the appropriate add new task window according to the account type
    if(account->getAccountType() == "Standard User Account"){
        addNewTaskStandardUserAccountWindowForm = new AddNewTaskStandardUserAccountWindow(this);
        addNewTaskStandardUserAccountWindowForm->show();
    }
    else if(account->getAccountType() == "Premium User Account"){
        addNewTaskPremiumUserAccountWindowForm = new AddNewTaskPremiumUserAccountWindow(this);
        addNewTaskPremiumUserAccountWindowForm->show();
    }
}

void UserAccountWindow::on_report_pushButton_clicked()
{

    reportSubmissionWindowForm = new ReportSubmissionWindow(this);
    reportSubmissionWindowForm->show();

}

void UserAccountWindow::on_addNewTask_pushButton_2_clicked()
{

    // End Session
    // Close Window
    // Open Login Window

}
