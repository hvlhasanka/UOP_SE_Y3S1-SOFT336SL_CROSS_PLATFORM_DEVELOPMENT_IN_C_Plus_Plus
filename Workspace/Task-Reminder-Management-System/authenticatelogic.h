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

#include "databaseconnection.h"

using namespace std;

class AuthenticateLogic
{
public:
    // Default constructor
    AuthenticateLogic();
    // Setter Methods
    void setLoginID(int loginID);
    void setEmailAddress(QString emailAddress);
    void setPasswordHash(QString passwordHash);
    void setAccountStatusID(int accountStatusID);
    void setAccountStatus(QString accountStatus);
    void setAccountTypeID(int accountTypeID);
    void setAccountType(QString accountType);
    void setAccountActivityID(int accountActivityID);
    void setAccountActivity(QString accountActivity);
    //Getter Methods
    int getLoginID();
    QString getEmailAddress();
    QString getPasswordHash();
    int getAccountStatusID();
    QString getAccountStatus();
    int getAccountTypeID();
    QString getAccountType();
    int getAccountActivityID();
    QString getAccountActivity();
    // Function Methods
    QString retrieveCurrentDateTime();
    bool validateEnteredEmailAddress(QString enteredEmailAddress);
    bool validateEnteredPassword(QString enteredPasswordValue);
    string generatePasswordHash(string passwordValue);
    QString loginCredentialVerification(QString enteredEmailAddress, QString enteredPasswordHash);
    QString checkEmailAddressAvailability(QString enteredEmailAddress);
    QString registerNewUser(QString enteredFirstName, QString enteredMiddleName,
                            QString enteredLastName, QString enteredEmailAddress,
                            QString generatedConfirmPasswordHash, QString selectedAccountType);
    void addSessionStartToDB();

private:
    // Private variables
    int loginID;
    QString emailAddress;
    QString passwordHash;
    int accountStatusID;
    QString accountStatus;
    int accountTypeID;
    QString accountType;
    int accountActivityID;
    QString accountActivity;
    // Private methods
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;

};

#endif // AUTHENTICATELOGIC_H
