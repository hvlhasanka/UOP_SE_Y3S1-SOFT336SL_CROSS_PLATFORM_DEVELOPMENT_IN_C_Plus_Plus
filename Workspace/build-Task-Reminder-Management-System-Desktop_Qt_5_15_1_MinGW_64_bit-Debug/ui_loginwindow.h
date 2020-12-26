/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *coverImage_label;
    QFrame *signInForm_frame;
    QLabel *logo_label;
    QPushButton *login_pushButton;
    QCheckBox *showPassword_checkBox;
    QPushButton *forgotPassword_pushButton;
    QPushButton *register_pushButton;
    QLineEdit *password_lineEdit;
    QLabel *emailAddress_label;
    QLabel *password_label;
    QLineEdit *emailAddress_lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->setEnabled(true);
        LoginWindow->resize(790, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWindow->sizePolicy().hasHeightForWidth());
        LoginWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 190, 196)"));
        coverImage_label = new QLabel(centralwidget);
        coverImage_label->setObjectName(QString::fromUtf8("coverImage_label"));
        coverImage_label->setGeometry(QRect(20, 0, 361, 451));
        signInForm_frame = new QFrame(centralwidget);
        signInForm_frame->setObjectName(QString::fromUtf8("signInForm_frame"));
        signInForm_frame->setGeometry(QRect(390, 0, 391, 451));
        signInForm_frame->setFrameShape(QFrame::StyledPanel);
        signInForm_frame->setFrameShadow(QFrame::Raised);
        logo_label = new QLabel(signInForm_frame);
        logo_label->setObjectName(QString::fromUtf8("logo_label"));
        logo_label->setGeometry(QRect(70, 30, 271, 211));
        login_pushButton = new QPushButton(signInForm_frame);
        login_pushButton->setObjectName(QString::fromUtf8("login_pushButton"));
        login_pushButton->setGeometry(QRect(10, 340, 371, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        login_pushButton->setFont(font);
        login_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);"));
        showPassword_checkBox = new QCheckBox(signInForm_frame);
        showPassword_checkBox->setObjectName(QString::fromUtf8("showPassword_checkBox"));
        showPassword_checkBox->setGeometry(QRect(270, 320, 111, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Myanmar Text"));
        font1.setPointSize(10);
        showPassword_checkBox->setFont(font1);
        forgotPassword_pushButton = new QPushButton(signInForm_frame);
        forgotPassword_pushButton->setObjectName(QString::fromUtf8("forgotPassword_pushButton"));
        forgotPassword_pushButton->setGeometry(QRect(274, 412, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(9);
        forgotPassword_pushButton->setFont(font2);
        forgotPassword_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);"));
        register_pushButton = new QPushButton(signInForm_frame);
        register_pushButton->setObjectName(QString::fromUtf8("register_pushButton"));
        register_pushButton->setGeometry(QRect(10, 410, 111, 31));
        register_pushButton->setFont(font2);
        register_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);"));
        password_lineEdit = new QLineEdit(signInForm_frame);
        password_lineEdit->setObjectName(QString::fromUtf8("password_lineEdit"));
        password_lineEdit->setGeometry(QRect(120, 280, 261, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(11);
        password_lineEdit->setFont(font3);
        password_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        password_lineEdit->setEchoMode(QLineEdit::Password);
        emailAddress_label = new QLabel(signInForm_frame);
        emailAddress_label->setObjectName(QString::fromUtf8("emailAddress_label"));
        emailAddress_label->setGeometry(QRect(10, 240, 121, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(12);
        emailAddress_label->setFont(font4);
        password_label = new QLabel(signInForm_frame);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(10, 280, 91, 21));
        password_label->setFont(font4);
        emailAddress_lineEdit = new QLineEdit(signInForm_frame);
        emailAddress_lineEdit->setObjectName(QString::fromUtf8("emailAddress_lineEdit"));
        emailAddress_lineEdit->setGeometry(QRect(120, 240, 261, 31));
        emailAddress_lineEdit->setFont(font3);
        emailAddress_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(false);
        menubar->setGeometry(QRect(0, 0, 790, 21));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        coverImage_label->setText(QCoreApplication::translate("LoginWindow", "Cover Image", nullptr));
        logo_label->setText(QCoreApplication::translate("LoginWindow", "Logo", nullptr));
        login_pushButton->setText(QCoreApplication::translate("LoginWindow", "LOGIN", nullptr));
        showPassword_checkBox->setText(QCoreApplication::translate("LoginWindow", "Show Password", nullptr));
        forgotPassword_pushButton->setText(QCoreApplication::translate("LoginWindow", "Forgot Password?", nullptr));
        register_pushButton->setText(QCoreApplication::translate("LoginWindow", "REGISTER", nullptr));
        emailAddress_label->setText(QCoreApplication::translate("LoginWindow", "Email Address", nullptr));
        password_label->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
