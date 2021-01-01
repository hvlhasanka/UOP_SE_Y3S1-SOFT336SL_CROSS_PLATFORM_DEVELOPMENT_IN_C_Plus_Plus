/********************************************************************************
** Form generated from reading UI file 'userregistrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREGISTRATIONWINDOW_H
#define UI_USERREGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserRegistrationWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *emailAddress_label;
    QPushButton *viewPasswordGuidelines_pushButton;
    QLabel *emailAddress_label_2;
    QLineEdit *confirmPassword_lineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *password_label;
    QLineEdit *lastName_lineEdit;
    QFrame *form_line;
    QLineEdit *emailAddress_lineEdit;
    QLabel *label_9;
    QLabel *label_2;
    QLabel *label_7;
    QPushButton *register_pushButton;
    QLineEdit *password_lineEdit;
    QLabel *label_3;
    QLabel *accountType_label;
    QLabel *label_6;
    QCheckBox *checkBox;
    QLineEdit *middleName_lineEdit;
    QLabel *confirmPassword_label;
    QLabel *emailAddress_label_4;
    QComboBox *accountType_comboBox;
    QFrame *form_line_2;
    QLabel *logo_label;
    QLabel *label_10;
    QLineEdit *firstName_lineEdit;
    QLabel *emailAddress_label_3;
    QLabel *name_label;
    QLabel *label;
    QLabel *label_8;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserRegistrationWindow)
    {
        if (UserRegistrationWindow->objectName().isEmpty())
            UserRegistrationWindow->setObjectName(QString::fromUtf8("UserRegistrationWindow"));
        UserRegistrationWindow->resize(573, 688);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Sans Serif"));
        font.setPointSize(16);
        UserRegistrationWindow->setFont(font);
        UserRegistrationWindow->setAutoFillBackground(false);
        UserRegistrationWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(UserRegistrationWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 571, 651));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 192, 196);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        emailAddress_label = new QLabel(frame);
        emailAddress_label->setObjectName(QString::fromUtf8("emailAddress_label"));
        emailAddress_label->setGeometry(QRect(60, 300, 121, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        emailAddress_label->setFont(font1);
        viewPasswordGuidelines_pushButton = new QPushButton(frame);
        viewPasswordGuidelines_pushButton->setObjectName(QString::fromUtf8("viewPasswordGuidelines_pushButton"));
        viewPasswordGuidelines_pushButton->setGeometry(QRect(330, 420, 161, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nirmala UI"));
        font2.setPointSize(10);
        viewPasswordGuidelines_pushButton->setFont(font2);
        viewPasswordGuidelines_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        emailAddress_label_2 = new QLabel(frame);
        emailAddress_label_2->setObjectName(QString::fromUtf8("emailAddress_label_2"));
        emailAddress_label_2->setGeometry(QRect(90, 170, 121, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(12);
        emailAddress_label_2->setFont(font3);
        confirmPassword_lineEdit = new QLineEdit(frame);
        confirmPassword_lineEdit->setObjectName(QString::fromUtf8("confirmPassword_lineEdit"));
        confirmPassword_lineEdit->setGeometry(QRect(230, 380, 261, 31));
        confirmPassword_lineEdit->setFont(font3);
        confirmPassword_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        confirmPassword_lineEdit->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 170, 16, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Microsoft New Tai Lue"));
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setWeight(50);
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(500, 250, 16, 21));
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        password_label = new QLabel(frame);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(60, 350, 121, 21));
        password_label->setFont(font1);
        lastName_lineEdit = new QLineEdit(frame);
        lastName_lineEdit->setObjectName(QString::fromUtf8("lastName_lineEdit"));
        lastName_lineEdit->setGeometry(QRect(230, 250, 261, 31));
        lastName_lineEdit->setFont(font3);
        lastName_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lastName_lineEdit->setEchoMode(QLineEdit::Normal);
        form_line = new QFrame(frame);
        form_line->setObjectName(QString::fromUtf8("form_line"));
        form_line->setGeometry(QRect(50, 490, 441, 20));
        form_line->setFrameShape(QFrame::HLine);
        form_line->setFrameShadow(QFrame::Sunken);
        emailAddress_lineEdit = new QLineEdit(frame);
        emailAddress_lineEdit->setObjectName(QString::fromUtf8("emailAddress_lineEdit"));
        emailAddress_lineEdit->setGeometry(QRect(230, 290, 261, 31));
        emailAddress_lineEdit->setFont(font3);
        emailAddress_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        emailAddress_lineEdit->setEchoMode(QLineEdit::Normal);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(430, 510, 16, 21));
        label_9->setFont(font4);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 20, 71, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Myriad Hebrew"));
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        label_2->setFont(font5);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 380, 16, 21));
        label_7->setFont(font4);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        register_pushButton = new QPushButton(frame);
        register_pushButton->setObjectName(QString::fromUtf8("register_pushButton"));
        register_pushButton->setGeometry(QRect(100, 590, 371, 41));
        QFont font6;
        font6.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setWeight(50);
        register_pushButton->setFont(font6);
        register_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);"));
        password_lineEdit = new QLineEdit(frame);
        password_lineEdit->setObjectName(QString::fromUtf8("password_lineEdit"));
        password_lineEdit->setGeometry(QRect(230, 340, 261, 31));
        password_lineEdit->setFont(font3);
        password_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        password_lineEdit->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 20, 371, 41));
        QFont font7;
        font7.setPointSize(16);
        label_3->setFont(font7);
        accountType_label = new QLabel(frame);
        accountType_label->setObjectName(QString::fromUtf8("accountType_label"));
        accountType_label->setGeometry(QRect(60, 460, 121, 21));
        accountType_label->setFont(font1);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 340, 16, 21));
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(170, 510, 261, 31));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font8.setPointSize(12);
        checkBox->setFont(font8);
        middleName_lineEdit = new QLineEdit(frame);
        middleName_lineEdit->setObjectName(QString::fromUtf8("middleName_lineEdit"));
        middleName_lineEdit->setGeometry(QRect(230, 210, 261, 31));
        middleName_lineEdit->setFont(font3);
        middleName_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        middleName_lineEdit->setEchoMode(QLineEdit::Normal);
        confirmPassword_label = new QLabel(frame);
        confirmPassword_label->setObjectName(QString::fromUtf8("confirmPassword_label"));
        confirmPassword_label->setGeometry(QRect(60, 390, 161, 21));
        confirmPassword_label->setFont(font1);
        emailAddress_label_4 = new QLabel(frame);
        emailAddress_label_4->setObjectName(QString::fromUtf8("emailAddress_label_4"));
        emailAddress_label_4->setGeometry(QRect(90, 250, 121, 21));
        emailAddress_label_4->setFont(font3);
        accountType_comboBox = new QComboBox(frame);
        accountType_comboBox->setObjectName(QString::fromUtf8("accountType_comboBox"));
        accountType_comboBox->setGeometry(QRect(230, 450, 261, 31));
        accountType_comboBox->setFont(font3);
        accountType_comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        form_line_2 = new QFrame(frame);
        form_line_2->setObjectName(QString::fromUtf8("form_line_2"));
        form_line_2->setGeometry(QRect(50, 570, 441, 20));
        form_line_2->setFrameShape(QFrame::HLine);
        form_line_2->setFrameShadow(QFrame::Sunken);
        logo_label = new QLabel(frame);
        logo_label->setObjectName(QString::fromUtf8("logo_label"));
        logo_label->setGeometry(QRect(10, 20, 81, 51));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(500, 290, 16, 21));
        label_10->setFont(font4);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        firstName_lineEdit = new QLineEdit(frame);
        firstName_lineEdit->setObjectName(QString::fromUtf8("firstName_lineEdit"));
        firstName_lineEdit->setGeometry(QRect(230, 170, 261, 31));
        firstName_lineEdit->setFont(font3);
        firstName_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        emailAddress_label_3 = new QLabel(frame);
        emailAddress_label_3->setObjectName(QString::fromUtf8("emailAddress_label_3"));
        emailAddress_label_3->setGeometry(QRect(90, 210, 121, 21));
        emailAddress_label_3->setFont(font3);
        name_label = new QLabel(frame);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(60, 140, 121, 21));
        name_label->setFont(font1);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 60, 251, 51));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Malgun Gothic"));
        font9.setPointSize(20);
        font9.setBold(true);
        font9.setWeight(75);
        label->setFont(font9);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(500, 450, 16, 21));
        label_8->setFont(font4);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 540, 261, 31));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Nirmala UI Semilight"));
        font10.setPointSize(12);
        pushButton->setFont(font10);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UserRegistrationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserRegistrationWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 573, 30));
        UserRegistrationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserRegistrationWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserRegistrationWindow->setStatusBar(statusbar);

        retranslateUi(UserRegistrationWindow);

        QMetaObject::connectSlotsByName(UserRegistrationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserRegistrationWindow)
    {
        UserRegistrationWindow->setWindowTitle(QCoreApplication::translate("UserRegistrationWindow", "MainWindow", nullptr));
        emailAddress_label->setText(QCoreApplication::translate("UserRegistrationWindow", "Email Address", nullptr));
        viewPasswordGuidelines_pushButton->setText(QCoreApplication::translate("UserRegistrationWindow", "View Password Guidelines", nullptr));
        emailAddress_label_2->setText(QCoreApplication::translate("UserRegistrationWindow", "First Name", nullptr));
#if QT_CONFIG(tooltip)
        confirmPassword_lineEdit->setToolTip(QCoreApplication::translate("UserRegistrationWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600; color:#000000;\">Password Guidelines:</span></p><p align=\"center\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#000000;\">Minimum of seven(7)characters</span></p><p align=\"center\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#000000;\">Maximum of twenty(20)characters</span></p><p align=\"center\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#000000;\">At least one uppercase letter</span></p><p align=\"center\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#000000;\">At least one lowercase letter</span></p><p align=\"center\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#000000;\">At least one numeric character</span></p><p align=\"center\"><span style=\" font-family:'Courier New'; font-size:10pt; color:#000000;\">At least one special character</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("UserRegistrationWindow", "*", nullptr));
        label_5->setText(QCoreApplication::translate("UserRegistrationWindow", "*", nullptr));
        password_label->setText(QCoreApplication::translate("UserRegistrationWindow", "Password", nullptr));
        label_9->setText(QCoreApplication::translate("UserRegistrationWindow", "*", nullptr));
        label_2->setText(QCoreApplication::translate("UserRegistrationWindow", "TRMS - ", nullptr));
        label_7->setText(QCoreApplication::translate("UserRegistrationWindow", "*", nullptr));
        register_pushButton->setText(QCoreApplication::translate("UserRegistrationWindow", "REGISTER", nullptr));
        label_3->setText(QCoreApplication::translate("UserRegistrationWindow", "Task Reminder Management System", nullptr));
        accountType_label->setText(QCoreApplication::translate("UserRegistrationWindow", "Account Type", nullptr));
        label_6->setText(QCoreApplication::translate("UserRegistrationWindow", "*", nullptr));
        checkBox->setText(QCoreApplication::translate("UserRegistrationWindow", "I accept the Terms and Conditions", nullptr));
        confirmPassword_label->setText(QCoreApplication::translate("UserRegistrationWindow", "Confirm Password", nullptr));
        emailAddress_label_4->setText(QCoreApplication::translate("UserRegistrationWindow", "Last Name", nullptr));
        logo_label->setText(QCoreApplication::translate("UserRegistrationWindow", "LOGO", nullptr));
        label_10->setText(QCoreApplication::translate("UserRegistrationWindow", "*", nullptr));
        emailAddress_label_3->setText(QCoreApplication::translate("UserRegistrationWindow", "Middle Name", nullptr));
        name_label->setText(QCoreApplication::translate("UserRegistrationWindow", "NAME", nullptr));
        label->setText(QCoreApplication::translate("UserRegistrationWindow", "User Registration", nullptr));
        label_8->setText(QCoreApplication::translate("UserRegistrationWindow", "*", nullptr));
        pushButton->setText(QCoreApplication::translate("UserRegistrationWindow", "View Terms and Conditions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserRegistrationWindow: public Ui_UserRegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREGISTRATIONWINDOW_H
