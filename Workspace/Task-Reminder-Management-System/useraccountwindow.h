#ifndef USERACCOUNTWINDOW_H
#define USERACCOUNTWINDOW_H

#include <QMainWindow>

#include "authenticatelogic.h"
#include "reportsubmissionwindow.h"
#include "addnewtaskstandarduseraccountwindow.h"
#include "addnewtaskpremiumuseraccountwindow.h"
#include "accountlogic.h"
#include "databaseconnection.h"

namespace Ui {
class UserAccountWindow;
}

class UserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserAccountWindow(int loginID, QWidget *parent = nullptr);
    ~UserAccountWindow();

private slots:
    void on_addNewTask_pushButton_clicked();
    void on_report_pushButton_clicked();

private:
    Ui::UserAccountWindow *ui;
    // Connecting the authenticatelogic.h
    // Retireving the authenticatelogic.h class path to a pointer
    AuthenticateLogic *auth;
    // Connecting the ReportSubmissionWindow.h
    // Retireving the ReportSubmissionWindow.h class path to a pointer
    ReportSubmissionWindow *reportSubmissionWindowForm;
    // Connecting the addnewtaskstandarduseraccountwindow.h
    // Retireving the addnewtaskstandarduseraccountwindow.h class path to a pointer
    AddNewTaskStandardUserAccountWindow *addNewTaskStandardUserAccountWindowForm;
    // Connecting the addnewtaskpremiumuseraccountwindow.h
    // Retireving the addnewtaskpremiumuseraccountwindow.h class path to a pointer
    AddNewTaskPremiumUserAccountWindow *addNewTaskPremiumUserAccountWindowForm;
    // Connecting the accountlogic.h
    // Retireving the accountlogic.h class path to a pointer
    AccountLogic *account;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;

};

#endif // USERACCOUNTWINDOW_H
