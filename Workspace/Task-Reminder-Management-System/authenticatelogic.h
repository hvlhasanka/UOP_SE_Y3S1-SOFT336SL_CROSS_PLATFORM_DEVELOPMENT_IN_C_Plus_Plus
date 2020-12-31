/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#ifndef AUTHENTICATELOGIC_H
#define AUTHENTICATELOGIC_H

#include <functional>
#include <string>
#include <regex>
#include <QString>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QtSql>
#include "QSqlError"
using namespace std;

class AuthenticateLogic
{
public:
    // Default constructor
    AuthenticateLogic();
    // Setter Methods
    void setEmailAddress(string emailAddressValue);
    void setPasswordHash(string passwordHashValue);
    // Function Methods
    bool validateEnteredEmailAddress(QString enteredEmailAddress);
    bool validateEnteredPassword(QString enteredPasswordValue);
    string generatePasswordHash(string passwordValue);
    string loginCredentialVerification(string enteredEmailAddress, string enteredPasswordHash);

private:
    QSqlDatabase databaseConnection;
    // Private string variables
    string emailAddress;
    string passwordHash;
    // Private methods


};

#endif // AUTHENTICATELOGIC_H
