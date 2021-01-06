#ifndef EDITTASKDETAILSSTANDARDUSERACCOUNTDIALOG_H
#define EDITTASKDETAILSSTANDARDUSERACCOUNTDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "databaseconnection.h"
#include "standarduseraccountlogic.h"

namespace Ui {
class EditTaskDetailsStandardUserAccountDialog;
}

class EditTaskDetailsStandardUserAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditTaskDetailsStandardUserAccountDialog(int accountID, int taskID, QWidget *parent = nullptr);
    ~EditTaskDetailsStandardUserAccountDialog();

private slots:
    void on_editTask_pushButton_clicked();

private:
    int passedAccountID;
    int passedTaskID;
    Ui::EditTaskDetailsStandardUserAccountDialog *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the standarduseraccountlogic.h
    // Retireving the standarduseraccountlogic.h class path to a pointer
    StandardUserAccountLogic *standardUserAccountLogic;

};

#endif // EDITTASKDETAILSSTANDARDUSERACCOUNTDIALOG_H
