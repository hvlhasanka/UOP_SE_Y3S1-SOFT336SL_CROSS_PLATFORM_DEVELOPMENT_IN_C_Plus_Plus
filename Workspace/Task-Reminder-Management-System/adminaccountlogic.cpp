#include "adminaccountlogic.h"

AdminAccountLogic::AdminAccountLogic()
{

}

QString AdminAccountLogic::updateFeedbackReportStatusToReviewed(int reportID)
{

    /* Updating report record to reviewed in the database */
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reportQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        reportQuery.prepare(QString("UPDATE Report SET rsReviewStatusID = 2 WHERE ReportID = :reportID;"));

        reportQuery.bindValue(":reportID", reportID);

        // Executing sql query and checking the status
        if(!reportQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << reportQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
            return "Execution Unsuccessful: (SQL Query Error)";
        }
        else{
            if(reportQuery.next()){
                trms_dbConnection->closeDatebaseConnection();
                return "Report Status Successfully Updated";
            }
        }
    }
    else if(databaseConnected == false){
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
        return "Execution Unsuccessful: Database Connection Error";
    }
    return "default";

}
