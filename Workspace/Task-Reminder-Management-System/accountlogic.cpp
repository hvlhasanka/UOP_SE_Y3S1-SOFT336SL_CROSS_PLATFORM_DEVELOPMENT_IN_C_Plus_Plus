#include "accountlogic.h"

AccountLogic::AccountLogic()
{

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

}


/* Function Methods */
QString AccountLogic::submitReport(QString enteredReportSubject, QString enteredReportDescription){

    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        /* Inserting record into the 'Report' relation (table)  */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reportQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        reportQuery.prepare(QString("INSERT INTO Report(ReportSubject, Feedback, SubmittedDateTime, rsReviewStatusID) VALUES "
                                              "(:enteredSubject, :enteredFeedback, 1);"));

        reportQuery.bindValue(":enteredSubject", );
        reportQuery.bindValue(":enteredFeedback", );

        // Executing sql query and checking the status
        if(!reportQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << reportQuery.lastError();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{

        }

    }
    else if(databaseConnected == false){

    }

}
