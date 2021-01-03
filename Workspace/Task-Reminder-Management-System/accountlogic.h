#ifndef ACCOUNTLOGIC_H
#define ACCOUNTLOGIC_H

#include <iostream>

#include <QString>

#include <databaseconnection.h>
#include <authenticatelogic.h>

using namespace std;


class AccountLogic
{
public:
    // Public Default Constructor
    AccountLogic();
    // Public Function Methods
    QString submitReport(QString enteredReportSubject,
                         QString enteredReportFeedback,
                         QString enteredAuthorReachableEmailAddress);
    QString addNewTask();


private:
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;
};

#endif // ACCOUNTLOGIC_H
