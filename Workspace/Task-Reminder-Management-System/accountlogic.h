#ifndef ACCOUNTLOGIC_H
#define ACCOUNTLOGIC_H

#include <QString>

#include <databaseconnection.h>

class AccountLogic
{
public:
    // Public Default Constructor
    AccountLogic();
    // Public Function Methods
    QString submitReport(QString enteredReportSubject,
                         QString enteredReportDescription);

private:
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;

};

#endif // ACCOUNTLOGIC_H
