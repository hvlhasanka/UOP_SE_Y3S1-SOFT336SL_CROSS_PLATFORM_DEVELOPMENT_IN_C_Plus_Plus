#ifndef PREMIUMUSERACCOUNTLOGIC_H
#define PREMIUMUSERACCOUNTLOGIC_H

#include "accountlogic.h"

class PremiumUserAccountLogic: public AccountLogic
{
public:
    PremiumUserAccountLogic();
    QString addNewTask(QString taskTitle,
                       QString taskDescription,
                       QString taskstartDateTime,
                       QString taskEndDateTime,
                       int taskCategoryTypeID,
                       QString taskCategoryType,
                       bool pinTaskToCategory,
                       bool markTaskAsImportant,
                       bool enableTaskTermination,
                       QString taskTermininationDateTime);
};

#endif // PREMIUMUSERACCOUNTLOGIC_H
