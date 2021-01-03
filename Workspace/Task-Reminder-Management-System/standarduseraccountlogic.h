#ifndef STANDARDUSERACCOUNTLOGIC_H
#define STANDARDUSERACCOUNTLOGIC_H

#include "accountlogic.h"
#include "databaseconnection.h"
#include "authenticatelogic.h"

class standardUserAccountLogic
{
public:
    standardUserAccountLogic();
    QString addNewTask(QString enteredTaskTitle,
                       QString enteredTaskDescription,
                       QString selectedTaskCategoryName);

private:
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;

};

#endif // STANDARDUSERACCOUNTLOGIC_H
