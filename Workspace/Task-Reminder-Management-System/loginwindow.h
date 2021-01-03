/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>

#include <authenticatelogic.h>
#include <useraccountwindow.h>
#include <adminaccountwindow.h>
#include <userregistrationwindow.h>
#include <reportsubmissionwindow.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    // Public variable declaration
    bool enteredEmailAddressValueAcceptable;
    bool enteredPasswordValueAcceptable;

private slots:
    void on_showPassword_checkBox_stateChanged(int arg1);
    void on_forgotPassword_pushButton_clicked();
    void on_emailAddress_lineEdit_textChanged(const QString &arg1);
    void on_password_lineEdit_textChanged(const QString &arg1);
    void on_login_pushButton_clicked();
    void on_register_pushButton_clicked();

    void on_report_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
    QLineEdit *password_lineEdit;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;
    // Connecting the useraccountwindow.h
    // Retireving the useraccountwindow.h class path to a pointer
    UserAccountWindow *userAccountWindowForm;
    // Connecting the adminaccountwindow.h
    // Retireving the adminaccountwindow.h class path to a pointer
    AdminAccountWindow *adminAccountWindowForm;
    // Connecting the userregistrationwindow.h
    // Retireving the userregistrationwindow.h class path to a pointer
    UserRegistrationWindow *userRegistrationWindowForm;
    // Connecting the reportsubmissionwindow.h
    // Retireving the reportsubmissionwindow.h class path to a pointer
    ReportSubmissionWindow *reportSubmissionWindowFrom;

};
#endif // LOGINWINDOW_H
