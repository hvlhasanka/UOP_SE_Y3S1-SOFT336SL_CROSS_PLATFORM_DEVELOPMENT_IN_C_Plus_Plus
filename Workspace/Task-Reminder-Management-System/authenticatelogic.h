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

#include <databaseconnection.h>

using namespace std;

class AuthenticateLogic
{
public:
    // Default constructor
    AuthenticateLogic();
    // Setter Methods
    void setEmailAddress(QString emailAddressValue);
    void setPasswordHash(QString passwordHashValue);
    // Function Methods
    bool validateEnteredEmailAddress(QString enteredEmailAddress);
    bool validateEnteredPassword(QString enteredPasswordValue);
    string generatePasswordHash(string passwordValue);
    QString loginCredentialVerification();
    QString checkEmailAddressAvailability(QString enteredEmailAddress);
    QString registerNewUser(QString enteredFirstName, QString enteredMiddleName,
                            QString enteredLastName, QString enteredEmailAddress,
                            QString generatedConfirmPasswordHash, QString selectedAccountType);

private:
    // Private string variables
    QString emailAddress;
    QString generatedPasswordHash;
    QString userID;
    QString accountType;
    QString firstName;
    QString middleName;
    QString lastName;
    // Private methods
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
};

#endif // AUTHENTICATELOGIC_H
