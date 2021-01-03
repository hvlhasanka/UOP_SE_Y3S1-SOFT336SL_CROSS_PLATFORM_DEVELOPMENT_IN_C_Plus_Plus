#include "accountlogic.h"

AccountLogic::AccountLogic()
{

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

}

// Setters

void AccountLogic::setLoginID(int loginID){
    this->loginID = loginID;
}

void AccountLogic::setAccountID(int accountID){
    this->accountID = accountID;
}

void AccountLogic::setNamePrefix(QString namePrefix){
    this->namePrefix = namePrefix;
}

void AccountLogic::setFirstName(QString firstName){
    this->firstName = firstName;
}

void AccountLogic::setMiddleName(QString middleName){
    this->middleName = middleName;
}

void AccountLogic::setLastName(QString lastName){
    this->lastName = lastName;
}

void AccountLogic::setCreatedDateTime(QString createdDateTime){
    this->createdDateTime = createdDateTime;
}

void AccountLogic::setAccountTypeID(int accountTypeID){
    this->accountTypeID = accountTypeID;
}

void AccountLogic::setAccountType(QString accountType){
    this->accountType = accountType;
}

void AccountLogic::setDoNotDistrubBooleanValueID(int doNotDistrubBooleanValueID){
    this->doNotDistrubBooleanValueID = doNotDistrubBooleanValueID;
}

void AccountLogic::setDoNotDistrubBooleanValue(bool doNotDistrubBooleanValue){
    this->doNotDistrubBooleanValue = doNotDistrubBooleanValue;
}

// Getters

int AccountLogic::getLoginID(){
    return loginID;
}

int AccountLogic::getAccountID(){
    return accountID;
}

QString AccountLogic::getNamePrefix(){
    return namePrefix;
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
