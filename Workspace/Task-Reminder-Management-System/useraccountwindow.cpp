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
            qDebug() << "SQL query execution error";
            qDebug() << userDetailsQuery.lastError();
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
                qDebug() << "User Account Details Successfully retrieved from Database";
            }
        }
    }
    else{
        qDebug() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
    }

}

UserAccountWindow::~UserAccountWindow()
{
    delete ui;
}

void UserAccountWindow::on_addNewTask_pushButton_clicked()
{
    qDebug() << account->getAccountType();
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
