#ifndef VIEWTASKSTANDARDUSERACCOUNTDIALOG_H
#define VIEWTASKSTANDARDUSERACCOUNTDIALOG_H

#include <QDialog>

#include "databaseconnection.h"
#include "setnewreminderstandarduseraccountdialog.h"
#include "edittaskdetailsstandarduseraccountdialog.h"
#include "accountlogic.h"

namespace Ui {
class ViewTaskStandardUserAccountDialog;
}

class ViewTaskStandardUserAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTaskStandardUserAccountDialog(int accountID, int taskID, QWidget *parent = nullptr);
    ~ViewTaskStandardUserAccountDialog();

private slots:
    void on_setReminder_pushButton_clicked();
    void on_editTaskDetails_pushButton_clicked();
    void on_removeTask_pushButton_clicked();

private:
    int passedTaskID;
    Ui::ViewTaskStandardUserAccountDialog *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the setnewreminderstandarduseraccountdialog.h
    // Retireving the setnewreminderstandarduseraccountdialog.h class path to a pointer
    SetNewReminderStandardUserAccountDialog *setNewReminderStandardUserAccountDialogForm;
    // Connecting the edittaskdetailsstandarduseraccountdialog.h
    // Retireving the edittaskdetailsstandarduseraccountdialog.h class path to a pointer
    EditTaskDetailsStandardUserAccountDialog *editTaskDetailsStandardUserAccountDialogForm;
    // Connecting the accountlogic.h
    // Retireving the accountlogic.h class path to a pointer
    AccountLogic *account;

};

#endif // VIEWTASKSTANDARDUSERACCOUNTDIALOG_H
