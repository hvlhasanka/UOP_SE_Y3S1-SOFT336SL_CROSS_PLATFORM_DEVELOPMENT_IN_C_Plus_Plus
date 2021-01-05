#include "adminaccountwindow.h"
#include "ui_adminaccountwindow.h"

AdminAccountWindow::AdminAccountWindow(int loginID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminAccountWindow)
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

    // Setting 'Dashboard' tab as the initial tab
    ui->adminAccount_tabWidget->setCurrentIndex(0);

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of AuthenticateLogic class
    auth = new AuthenticateLogic();

    // Creating an object of AccountLogic class
    account = new AccountLogic();


    /* DASHBOARD TAB */

    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery adminDetailsQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        adminDetailsQuery.prepare(QString("SELECT l.LoginID, a.AccountID, np.NamePrefix, a.FirstName, a.MiddleName, a.LastName, "
                                         "a.CreatedDateTime FROM "
                                         "Login l INNER JOIN Account a ON l.LoginID = a.lLoginID "
                                         "INNER JOIN NamePrefix np ON np.NamePrefixID = a.npNamePrefixID "
                                         "WHERE LoginID = :loginID;"));

        adminDetailsQuery.bindValue(":loginID", loginID);

        // Executing sql query and checking the status
        if(!adminDetailsQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << adminDetailsQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
        }
        else{
            if(adminDetailsQuery.next()){
                account->setLoginID(adminDetailsQuery.value(0).toInt());
                account->setAccountID(adminDetailsQuery.value(1).toInt());
                account->setNamePrefix(adminDetailsQuery.value(2).toString());
                account->setFirstName(adminDetailsQuery.value(3).toString());
                account->setMiddleName(adminDetailsQuery.value(4).toString());
                account->setLastName(adminDetailsQuery.value(5).toString());
                account->setCreatedDateTime(adminDetailsQuery.value(6).toString());
            }
            trms_dbConnection->closeDatebaseConnection();
        }

        /* Retrieving the relevant user details from the database and assigning it to the user interface */
        /* Getting number of standard user accounts from the database */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery noOfStandardAccountQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        noOfStandardAccountQuery.prepare(QString("SELECT COUNT(AccountID) FROM Account WHERE atAccountTypeID = 1;"));

        // Executing sql query and checking the status
        if(!noOfStandardAccountQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << noOfStandardAccountQuery.lastError();
        }
        else{
            if(noOfStandardAccountQuery.next()){
                ui->noOfStandardUserAccounts_label->setText(noOfStandardAccountQuery.value(0).toString());
            }
        }

        /* Retrieving the relevant user details from the database and assigning it to the user interface */
        /* Getting number of premium user accounts from the database */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery noOfPremiumAccountQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        noOfPremiumAccountQuery.prepare(QString("SELECT COUNT(AccountID) FROM Account WHERE atAccountTypeID = 1;"));

        // Executing sql query and checking the status
        if(!noOfPremiumAccountQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << noOfPremiumAccountQuery.lastError();
        }
        else{
            if(noOfPremiumAccountQuery.next()){
                ui->noOfPremiumUserAccounts_label->setText(noOfStandardAccountQuery.value(0).toString());
            }
        }

        trms_dbConnection->closeDatebaseConnection();
    }
    else if(databaseConnected == false){
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
    }




    /* REPORTS TAB */

    // Setting 'noNewReportsAvailable_label' to hide
    ui->noNewReportsAvailable_label->setVisible(false);

    // Setting 'feedbackReport_tableView' to hide
    ui->feedbackReport_tableView->setVisible(false);

    bool databaseConnectedCategory = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectedCategory == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reportQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        reportQuery.prepare(QString("SELECT r.ReportID, r.ReportSubject, r.Feedback FROM "
                                    "Report r INNER JOIN ReviewStatus ts ON ts.ReviewStatusID = r.rsReviewStatusID "
                                    "WHERE ts.ReviewStatus = 'Review Pending';"));

        // Executing sql query and checking the status
        if(!reportQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << reportQuery.lastError();
        }
        else{
            if(reportQuery.next()){
                QSqlQueryModel *reportModal = new QSqlQueryModel();
                reportModal->setQuery(reportQuery);

                ui->feedbackReport_tableView->setVisible(true);
                ui->feedbackReport_tableView->setModel(reportModal);
                ui->feedbackReport_tableView->resizeColumnsToContents();
            }
            else{
                ui->noNewReportsAvailable_label->setVisible(true);
            }
        }
        trms_dbConnection->closeDatebaseConnection();
    }
    else if(databaseConnectedCategory == false){
        trms_dbConnection->closeDatebaseConnection();
        qWarning() << "Database Connection Error";
    }


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


}

AdminAccountWindow::~AdminAccountWindow()
{
    delete ui;
}

void AdminAccountWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0){
        /* DASHBOARD TAB */

        /* Retrieving the relevant user details from the database and assigning it to the user interface */
        bool databaseConnected = trms_dbConnection->openDatebaseConnection();
        if(databaseConnected == true){

            /* Getting number of standard user accounts from the database */
            // Declaring new QSqlQuery object by passing the database name
            QSqlQuery noOfStandardAccountQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

            // Preparing sql query for execution
            noOfStandardAccountQuery.prepare(QString("SELECT COUNT(AccountID) FROM Account WHERE atAccountTypeID = 1;"));

            // Executing sql query and checking the status
            if(!noOfStandardAccountQuery.exec()){
                qWarning() << "SQL query execution error";
                qWarning() << noOfStandardAccountQuery.lastError();
            }
            else{
                if(noOfStandardAccountQuery.next()){
                    ui->noOfStandardUserAccounts_label->setText(noOfStandardAccountQuery.value(0).toString());
                }
            }

            /* Getting number of premium user accounts from the database */
            // Declaring new QSqlQuery object by passing the database name
            QSqlQuery noOfPremiumAccountQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

            // Preparing sql query for execution
            noOfPremiumAccountQuery.prepare(QString("SELECT COUNT(AccountID) FROM Account WHERE atAccountTypeID = 1;"));

            // Executing sql query and checking the status
            if(!noOfPremiumAccountQuery.exec()){
                qWarning() << "SQL query execution error";
                qWarning() << noOfPremiumAccountQuery.lastError();
            }
            else{
                if(noOfPremiumAccountQuery.next()){
                    ui->noOfPremiumUserAccounts_label->setText(noOfStandardAccountQuery.value(0).toString());
                }
            }

            trms_dbConnection->closeDatebaseConnection();
        }
        else if(databaseConnected == false){
            qWarning() << "Database Connection Error";
            trms_dbConnection->closeDatebaseConnection();
        }

    }

}

void AdminAccountWindow::on_showMoreDetails_pushButton_clicked()
{

    /* Passing user entered 'ReportID' */
    /* Opening viewfeedbackreportdialog to show more report details */
    viewFeedbackReportDialogForm = new ViewFeedbackReportDialog(ui->showMoreDetails_lineEdit->text().toInt(), this);
    viewFeedbackReportDialogForm->show();

}

void AdminAccountWindow::on_logout_pushButton_clicked()
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

void AdminAccountWindow::on_actionAbout_triggered()
{

    aboutDialogForm = new AboutDialog(this);
    aboutDialogForm->show();

}

void AdminAccountWindow::on_actionLogout_triggered()
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

void AdminAccountWindow::on_actionExit_triggered()
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
