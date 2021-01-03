#include "accountlogic.h"

AccountLogic::AccountLogic()
{

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

}

// Setters

void AccountLogic::setLoginID(int loginIDValue){
    loginID = loginIDValue;
}

void AccountLogic::setAccountID(int accountIDValue){
    accountID = accountIDValue;
}

void AccountLogic::setFirstName(QString firstNameValue){
    firstName = firstNameValue;
}

void AccountLogic::setMiddleName(QString middleNameValue){
    middleName = middleNameValue;
}

void AccountLogic::setLastName(QString lastNameValue){
    lastName = lastNameValue;
}

void AccountLogic::setCreatedDateTime(QString createdDateTimeValue){
    createdDateTime = createdDateTimeValue;
}

void AccountLogic::setAccountTypeID(int accountTypeIDValue){
    accountTypeID = accountTypeIDValue;
}

void AccountLogic::setAccountType(QString accountTypeValue){
    accountType = accountTypeValue;
}

void AccountLogic::setDoNotDistrubBooleanValueID(int doNotDistrubBooleanValueIDValue){
    doNotDistrubBooleanValueID = doNotDistrubBooleanValueIDValue;
}

void AccountLogic::setDoNotDistrubBooleanValue(bool doNotDistrubBooleanValueValue){
    doNotDistrubBooleanValue = doNotDistrubBooleanValueValue;
}

// Getters

int AccountLogic::getLoginID(){
    return loginID;
}

int AccountLogic::getAccountID(){
    return accountID;
}

QString AccountLogic::getFirstName(){
    return firstName;
}

QString AccountLogic::getMiddleName(){
    return middleName;
}

QString AccountLogic::getLastName(){
    return lastName;
}

QString AccountLogic::getCreatedDateTime(){
    return createdDateTime;
}

int AccountLogic::getAccountTypeID(){
    return accountTypeID;
}

QString AccountLogic::getAccountType(){
    return accountType;
}

int AccountLogic::getDoNotDistrubBooleanValueID(){
    return doNotDistrubBooleanValueID;
}

bool AccountLogic::getDoNotDistrubBooleanValue(){
    return doNotDistrubBooleanValue;
}

/* Function Methods */
QString AccountLogic::submitReport(QString enteredReportSubject, QString enteredReportFeedback, QString enteredAuthorReachableEmailAddress){

    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        /* Inserting record into the 'Report' relation (table)  */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reportQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        reportQuery.prepare(QString("INSERT INTO Report(ReportSubject, Feedback, SubmittedDateTime, AuthorReachableEmailAddress) VALUES "
                                              "(:enteredSubject, :enteredFeedback, :submitedDateTime, :enteredAuthorReachableEmailAddress);"));

        reportQuery.bindValue(":enteredSubject", enteredReportSubject);
        reportQuery.bindValue(":enteredFeedback", enteredReportFeedback);
        reportQuery.bindValue(":submitedDateTime", auth->retrieveCurrentDateTime());
        reportQuery.bindValue(":enteredAuthorReachableEmailAddress", enteredAuthorReachableEmailAddress);

        // Executing sql query and checking the status
        if(!reportQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << reportQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            trms_dbConnection->closeDatebaseConnection();
            return "Report Submission Successful";
        }

    }
    else if(databaseConnected == false){
        trms_dbConnection->closeDatebaseConnection();
        return "Execution Unsuccessful: Database Connection Error";
    }
    trms_dbConnection->closeDatebaseConnection();
    return "default";

}
