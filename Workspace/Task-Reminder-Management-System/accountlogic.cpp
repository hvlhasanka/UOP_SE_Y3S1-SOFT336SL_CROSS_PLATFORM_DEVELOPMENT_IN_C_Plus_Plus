#include "accountlogic.h"

AccountLogic::AccountLogic()
{

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of Authenticate class
    auth = new AuthenticateLogic();

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
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            return "Report Submission Successful";
        }

    }
    else if(databaseConnected == false){
        return "Execution Unsuccessful: Database Connection Error";
    }
    trms_dbConnection->closeDatebaseConnection();
    return "default";

}
