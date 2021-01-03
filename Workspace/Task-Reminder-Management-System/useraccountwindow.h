#ifndef USERACCOUNTWINDOW_H
#define USERACCOUNTWINDOW_H

#include <iostream>

#include <QMainWindow>

#include "authenticatelogic.h"
#include "addnewtaskstandarduseraccountwindow.h"
#include "addnewtaskpremiumuseraccountwindow.h"
#include "reportsubmissionwindow.h"

using namespace std;

namespace Ui {
class UserAccountWindow;
}

class UserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserAccountWindow(QWidget *parent = nullptr);
    ~UserAccountWindow();

private slots:

    void on_addNewTask_pushButton_clicked();

    void on_report_pushButton_clicked();

private:
    Ui::UserAccountWindow *ui;
    // Connecting the authenticatelogic.h
    // Retireving the authenticatelogic.h class path to a pointer
    AuthenticateLogic *auth;
    // Connecting the addnewtaskstandarduseraccountwindow.h
    // Retireving the addnewtaskstandarduseraccountwindow.h class path to a pointer
    AddNewTaskStandardUserAccountWindow *addNewTaskStandardUserAccountWindow;
    // Connecting the addnewtaskpremiumuseraccountwindow.h
    // Retireving the addnewtaskpremiumuseraccountwindow.h class path to a pointer
    AddNewTaskPremiumUserAccountWindow *addNewTaskPremiumUserAccountWindow;
    // Connecting the addnewtaskpremiumuseraccountwindow.h
    // Retireving the addnewtaskpremiumuseraccountwindow.h class path to a pointer
    ReportSubmissionWindow *reportSubmissionWindow;

};

#endif // USERACCOUNTWINDOW_H
