#ifndef SETNEWREMINDERSTANDARDUSERACCOUNTDIALOG_H
#define SETNEWREMINDERSTANDARDUSERACCOUNTDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "databaseconnection.h"
#include "standarduseraccountlogic.h"
#include "authenticatelogic.h"

namespace Ui {
class SetNewReminderStandardUserAccountDialog;
}

class SetNewReminderStandardUserAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetNewReminderStandardUserAccountDialog(int taskID, QWidget *parent = nullptr);
    ~SetNewReminderStandardUserAccountDialog();

private slots:
    void on_setReminder_pushButton_clicked();

private:
    // Private variable
    int passedTaskID;
    Ui::SetNewReminderStandardUserAccountDialog *ui;
    // Connecting the databaseconnection.h
    // Retireving the databaseconnection.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the standarduseraccountlogic.h
    // Retireving the standarduseraccountlogic.h class path to a pointer
    StandardUserAccountLogic *standardUserAccountLogic;
    // Connecting the authenticatelogic.h
    // Retireving the authenticatelogic.h class path to a pointer
    AuthenticateLogic *auth;

};

#endif // SETNEWREMINDERSTANDARDUSERACCOUNTDIALOG_H
