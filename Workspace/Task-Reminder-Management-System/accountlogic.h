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
    void setLoginID(int loginID);
    void setAccountID(int accountID);
    void setNamePrefix(QString namePrefix);
    void setFirstName(QString firstName);
    void setMiddleName(QString middleName);
    void setLastName(QString lastName);
    void setCreatedDateTime(QString createdDateTime);
    void setAccountTypeID(int accountTypeID);
    void setAccountType(QString accountType);
    void setDoNotDistrubBooleanValueID(int doNotDistrubBooleanValueID);
    void setDoNotDistrubBooleanValue(bool doNotDistrubBooleanValue);
    void setAccountActivityID(int accountActivityID);
    void setAccountActivity(QString accountActivity);
    // Getters
    int getLoginID();
    int getAccountID();
    QString getNamePrefix();
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
    QString setNewReminder();
    QString removeReminder(int reminderID);

private:
    // Private variables
    int loginID;
    int accountID;
    QString namePrefix;
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
