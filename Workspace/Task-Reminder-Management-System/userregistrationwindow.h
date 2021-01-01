#ifndef USERREGISTRATIONWINDOW_H
#define USERREGISTRATIONWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include <databaseconnection.h>
#include <authenticatelogic.h>

namespace Ui {
class UserRegistrationWindow;
}

class UserRegistrationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserRegistrationWindow(QWidget *parent = nullptr);
    ~UserRegistrationWindow();
    // Public variable declaration
    bool enteredFirstNameValueAcceptable;
    bool enteredMiddleNameValueAcceptable;
    bool enteredLastNameValueAcceptable;
    bool enteredEmailAddressValueAcceptable;
    bool enteredPasswordValueAcceptable;
    bool enteredConfirmPasswordValueAcceptable;
    bool checkedTermsAndConditions;
    bool selectedAccountType;

private slots:
    void on_viewPasswordGuidelines_pushButton_clicked();
    void on_firstName_lineEdit_textChanged(const QString &arg1);
    void on_termsAndConditions_checkBox_stateChanged(int arg1);
    void on_middleName_lineEdit_textChanged(const QString &arg1);
    void on_emailAddress_lineEdit_textChanged(const QString &arg1);
    void on_password_lineEdit_textChanged(const QString &arg1);
    void on_lastName_lineEdit_textChanged(const QString &arg1);
    void on_confirmPassword_lineEdit_textChanged(const QString &arg1);
    void on_register_pushButton_clicked();

private:
    Ui::UserRegistrationWindow *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;

};

#endif // USERREGISTRATIONWINDOW_H
