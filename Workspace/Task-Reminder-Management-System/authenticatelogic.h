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
    void setLoginID(int loginIDValue);
    void setAccountID(int accountIDValue);
    void setEmailAddress(QString emailAddressValue);
    void setPasswordHash(QString passwordHashValue);
    void setFirstName(QString firstNameValue);
    void setMiddleName(QString middleNameValue);
    void setLastName(QString lastNameValue);
    void setCreatedDateTime(QString createdDateTimeValue);
    void setAccountStatusID(int accountStatusIDValue);
    void setAccountStatus(QString accountStatusValue);
    void setAccountTypeID(int accountTypeIDValue);
    void setAccountType(QString accountTypeValue);
    void setDoNotDistrubBooleanValueID(int doNotDistrubBooleanValueIDValue);
    void setDoNotDistrubBooleanValue(bool doNotDistrubBooleanValueValue);
    void setAccountActivityID(int accountActivityIDValue);
    void setAccountActivity(QString accountActivityValue);
    //Getter Methods
    int getLoginID();
    int getAccountID();
    QString getEmailAddress();
    QString getPasswordHash();
    QString getFirstName();
    QString getMiddleName();
    QString getLastName();
    QString getCreatedDateTime();
    int getAccountStatusID();
    QString getAccountStatus();
    int getAccountTypeID();
    QString getAccountType();
    int getDoNotDistrubBooleanValueID();
    bool getDoNotDistrubBooleanValue();
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
    // Private string variables
    int loginID;
    int accountID;
    QString emailAddress;
    QString passwordHash;
    QString firstName;
    QString middleName;
    QString lastName;
    QString createdDateTime;
    int accountStatusID;
    QString accountStatus;
    int accountTypeID;
    QString accountType;
    int doNotDistrubBooleanValueID;
    bool doNotDistrubBooleanValue;
    int accountActivityID;
    QString accountActivity;
    // Private methods
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
};

#endif // AUTHENTICATELOGIC_H
