#ifndef ACCOUNTLOGIC_H
#define ACCOUNTLOGIC_H

#include <QString>

#include "databaseconnection.h"
#include "authenticatelogic.h"

class AccountLogic
{
public:
    // Public Default Constructor
    AccountLogic();
    // Setters
    void setLoginID(int loginIDValue);
    void setAccountID(int accountIDValue);
    void setFirstName(QString firstNameValue);
    void setMiddleName(QString middleNameValue);
    void setLastName(QString lastNameValue);
    void setCreatedDateTime(QString createdDateTimeValue);
    void setAccountTypeID(int accountTypeIDValue);
    void setAccountType(QString accountTypeValue);
    void setDoNotDistrubBooleanValueID(int doNotDistrubBooleanValueIDValue);
    void setDoNotDistrubBooleanValue(bool doNotDistrubBooleanValueValue);
    void setAccountActivityID(int accountActivityIDValue);
    void setAccountActivity(QString accountActivityValue);
    // Getters
    int getLoginID();
    int getAccountID();
    QString getFirstName();
    QString getMiddleName();
    QString getLastName();
    QString getCreatedDateTime();
    int getAccountTypeID();
    QString getAccountType();
    int getDoNotDistrubBooleanValueID();
    bool getDoNotDistrubBooleanValue();
    int getAccountActivityID();
    QString getAccountActivity();
    // Public Function Methods
    QString submitReport(QString enteredReportSubject,
                         QString enteredReportFeedback,
                         QString enteredAuthorReachableEmailAddress);
    QString addNewTask();

private:
    // Private variables
    int loginID;
    int accountID;
    QString firstName;
    QString middleName;
    QString lastName;
    QString createdDateTime;
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
    // Connecting the authenticatelogic.h
    // Retireving the authenticatelogic.h class path to a pointer
    AuthenticateLogic *auth;
};

#endif // ACCOUNTLOGIC_H
