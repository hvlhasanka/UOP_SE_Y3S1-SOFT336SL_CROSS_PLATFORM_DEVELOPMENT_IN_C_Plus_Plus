#ifndef ACCOUNTLOGIC_H
#define ACCOUNTLOGIC_H

#include <QString>

#include <databaseconnection.h>
#include <authenticatelogic.h>

class AccountLogic
{
public:
    // Public Default Constructor
    AccountLogic();
    // Public Function Methods
    QString submitReport(QString enteredReportSubject,
                         QString enteredReportFeedback,
                         QString enteredAuthorReachableEmailAddress);

private:
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;
};

#endif // ACCOUNTLOGIC_H
