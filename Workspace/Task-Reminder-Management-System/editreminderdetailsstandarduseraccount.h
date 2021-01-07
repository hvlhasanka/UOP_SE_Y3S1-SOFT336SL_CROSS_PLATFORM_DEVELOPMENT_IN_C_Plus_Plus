#ifndef EDITREMINDERDETAILSSTANDARDUSERACCOUNT_H
#define EDITREMINDERDETAILSSTANDARDUSERACCOUNT_H

#include <QDialog>

#include "databaseconnection.h"

namespace Ui {
class EditReminderDetailsStandardUserAccount;
}

class EditReminderDetailsStandardUserAccount : public QDialog
{
    Q_OBJECT

public:
    explicit EditReminderDetailsStandardUserAccount(int reminderID, QWidget *parent = nullptr);
    ~EditReminderDetailsStandardUserAccount();

private slots:
    void on_setReminder_pushButton_clicked();

private:
    int passedReminderID;
    Ui::EditReminderDetailsStandardUserAccount *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;

};

#endif // EDITREMINDERDETAILSSTANDARDUSERACCOUNT_H
