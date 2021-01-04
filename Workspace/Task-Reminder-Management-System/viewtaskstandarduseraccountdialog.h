#ifndef VIEWTASKSTANDARDUSERACCOUNTDIALOG_H
#define VIEWTASKSTANDARDUSERACCOUNTDIALOG_H

#include <QDialog>

#include "databaseconnection.h"
#include "setnewreminderstandarduseraccountdialog.h"

namespace Ui {
class ViewTaskStandardUserAccountDialog;
}

class ViewTaskStandardUserAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTaskStandardUserAccountDialog(int taskID, QWidget *parent = nullptr);
    ~ViewTaskStandardUserAccountDialog();

private slots:
    void on_setReminder_pushButton_clicked();

private:
    Ui::ViewTaskStandardUserAccountDialog *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the setnewreminderstandarduseraccountdialog.h
    // Retireving the setnewreminderstandarduseraccountdialog.h class path to a pointer
    SetNewReminderStandardUserAccountDialog *setNewReminderStandardUserAccountDialogForm;
};

#endif // VIEWTASKSTANDARDUSERACCOUNTDIALOG_H
