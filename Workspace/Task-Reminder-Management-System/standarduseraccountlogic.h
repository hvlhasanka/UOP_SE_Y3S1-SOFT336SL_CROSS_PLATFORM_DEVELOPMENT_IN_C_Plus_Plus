#ifndef STANDARDUSERACCOUNTLOGIC_H
#define STANDARDUSERACCOUNTLOGIC_H

#include <QSqlDatabase>

#include "accountlogic.h"
#include "databaseconnection.h"
#include "accountlogic.h"
#include "authenticatelogic.h"

class StandardUserAccountLogic: public AccountLogic
{
public:
    StandardUserAccountLogic();
    StandardUserAccountLogic(int accountID);
    QString addNewTask(QString enteredTaskTitle,
                       QString enteredTaskDescription,
                       QString selectedTaskCategoryName);
    QString setNewReminder(int taskID,
                           QString reminderDateTime);
    QString editTaskDetails(int accountID,
                            int taskID,
                            QString taskTitle,
                            QString taskDescription,
                            QString categoryName);

private:
    // Private variables
    int passedAccountID;
    // Pointer declaration
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    QSqlDatabase databaseConnection;
    // Connecting the accountlogic.h
    // Retireving the accountlogic.h class path to a pointer
    AccountLogic *account;
    // Connecting the authenticatelogic.h
    // Retireving the authenticatelogic.h class path to a pointer
    AuthenticateLogic *auth;

};

#endif // STANDARDUSERACCOUNTLOGIC_H
