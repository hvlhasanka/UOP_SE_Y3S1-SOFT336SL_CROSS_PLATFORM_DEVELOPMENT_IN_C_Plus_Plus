#ifndef ADDNEWTASKSTANDARDUSERACCOUNTWINDOW_H
#define ADDNEWTASKSTANDARDUSERACCOUNTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include <databaseconnection.h>
#include <authenticatelogic.h>
#include <standarduseraccountlogic.h>

namespace Ui {
class AddNewTaskStandardUserAccountWindow;
}

class AddNewTaskStandardUserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewTaskStandardUserAccountWindow(QWidget *parent = nullptr);
    ~AddNewTaskStandardUserAccountWindow();

private slots:
    void on_addTask_pushButton_clicked();

private:
    Ui::AddNewTaskStandardUserAccountWindow *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;
    // Connecting the standarduseraccountlogic.h
    // Retireving the standarduseraccountlogic.h class path to a pointer
    StandardUserAccountLogic *standardUserAccountLogic;
};

#endif // ADDNEWTASKSTANDARDUSERACCOUNTWINDOW_H
