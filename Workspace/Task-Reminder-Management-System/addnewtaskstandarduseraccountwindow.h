#ifndef ADDNEWTASKSTANDARDUSERACCOUNTWINDOW_H
#define ADDNEWTASKSTANDARDUSERACCOUNTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include <databaseconnection.h>
#include <accountlogic.h>
#include <standarduseraccountlogic.h>

namespace Ui {
class AddNewTaskStandardUserAccountWindow;
}

class AddNewTaskStandardUserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewTaskStandardUserAccountWindow(int accountID, QWidget *parent = nullptr);
    ~AddNewTaskStandardUserAccountWindow();

private slots:
    void on_addTask_pushButton_clicked();

private:
    Ui::AddNewTaskStandardUserAccountWindow *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the accountlogic.h
    // Retireving the accountlogic.h class path to a pointer
    AccountLogic *account;
    // Connecting the standarduseraccountlogic.h
    // Retireving the standarduseraccountlogic.h class path to a pointer
    StandardUserAccountLogic *standardUserAccountLogic;
};

#endif // ADDNEWTASKSTANDARDUSERACCOUNTWINDOW_H
