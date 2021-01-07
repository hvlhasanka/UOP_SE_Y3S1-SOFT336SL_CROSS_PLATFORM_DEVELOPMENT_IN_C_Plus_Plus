#ifndef PREMIUMUSERACCOUNTLOGIC_H
#define PREMIUMUSERACCOUNTLOGIC_H

#include "accountlogic.h"

class PremiumUserAccountLogic: public AccountLogic
{
public:
    PremiumUserAccountLogic();
    QString addNewTask(QString taskTitle,
                       QString taskDescription,
                       QString taskStartDateTime,
                       QString taskEndDateTime,
                       QString taskCategoryName,
                       bool pinTaskToCategory,
                       bool markTaskAsImportant,
                       bool enableTaskTermination,
                       QString taskTermininationDateTime);
    QString editTaskDetails(int accountID,
                            int taskID,
                            QString newTaskTitle,
                            QString newTaskDescription,
                            QString newTaskStartDateTime,
                            QString newTaskEndDateTime,
                            QString selectedCategoryName,
                            bool pinTaskToCategory,
                            bool markTaskAsImportant,
                            bool enableTaskTermination,
                            QString newTaskTerminationDateTime
                            );
    QString setNewReminder(int taskID,
                           QString reminderDateTime,
                           int snoozeDuration,
                           int noOfSnoozes,
                           QString repeatOccasions);
    QString editReminderDetails(int reminderID,
                                QString newReminderDateTime,
                                int newSnoozeDuration,
                                int newNoOfSnoozes,
                                QString newRepeatOccasions);
    QString changeDoNotDisturbStatus(int accountID);

};

#endif // PREMIUMUSERACCOUNTLOGIC_H
