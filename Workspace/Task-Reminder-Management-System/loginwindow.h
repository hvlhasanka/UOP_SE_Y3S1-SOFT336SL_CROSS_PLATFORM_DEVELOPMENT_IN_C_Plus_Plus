/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>

#include <authenticatelogic.h>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    bool enteredEmailAddressValueAcceptable;
    bool enteredPasswordValueAcceptable;

private slots:
    void on_showPassword_checkBox_stateChanged(int arg1);
    void on_forgotPassword_pushButton_clicked();
    void on_emailAddress_lineEdit_textChanged(const QString &arg1);
    void on_password_lineEdit_textChanged(const QString &arg1);
    void on_login_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
    QLineEdit *password_lineEdit;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;
};
#endif // LOGINWINDOW_H
