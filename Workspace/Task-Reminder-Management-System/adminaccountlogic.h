#ifndef ADMINACCOUNTLOGIC_H
#define ADMINACCOUNTLOGIC_H

#include "accountlogic.h"
#include "databaseconnection.h"

class AdminAccountLogic: public AccountLogic
{
public:
    AdminAccountLogic();
    QString updateFeedbackReportStatusToReviewed(int reportID);

private:
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;

};

#endif // ADMINACCOUNTLOGIC_H
