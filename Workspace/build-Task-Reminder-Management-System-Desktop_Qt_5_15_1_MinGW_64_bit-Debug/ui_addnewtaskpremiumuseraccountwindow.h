/********************************************************************************
** Form generated from reading UI file 'addnewtaskpremiumuseraccountwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H
#define UI_ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewTaskPremiumUserAccountWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QLabel *title_label;
    QLabel *label_3;
    QPushButton *add_pushButton;
    QLabel *logo_label;
    QLineEdit *title_lineEdit;
    QLabel *description_name_label;
    QPlainTextEdit *description_plainTextEdit;
    QLabel *startDateTime_name_label;
    QDateTimeEdit *startDateTime_dateTimeEdit;
    QLabel *endDateTime_name_label;
    QDateTimeEdit *endDateTime_dateTimeEdit;
    QLabel *category_label;
    QComboBox *category_comboBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *startDateTime_name_label_2;
    QDateTimeEdit *startDateTime_dateTimeEdit_2;
    QFrame *line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddNewTaskPremiumUserAccountWindow)
    {
        if (AddNewTaskPremiumUserAccountWindow->objectName().isEmpty())
            AddNewTaskPremiumUserAccountWindow->setObjectName(QString::fromUtf8("AddNewTaskPremiumUserAccountWindow"));
        AddNewTaskPremiumUserAccountWindow->resize(541, 664);
        centralwidget = new QWidget(AddNewTaskPremiumUserAccountWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 541, 621));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 192, 196);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 50, 251, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Malgun Gothic"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        title_label = new QLabel(frame);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setGeometry(QRect(80, 120, 71, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        title_label->setFont(font1);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 10, 371, 41));
        QFont font2;
        font2.setPointSize(16);
        label_3->setFont(font2);
        add_pushButton = new QPushButton(frame);
        add_pushButton->setObjectName(QString::fromUtf8("add_pushButton"));
        add_pushButton->setGeometry(QRect(90, 570, 371, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        add_pushButton->setFont(font3);
        add_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);"));
        logo_label = new QLabel(frame);
        logo_label->setObjectName(QString::fromUtf8("logo_label"));
        logo_label->setGeometry(QRect(10, 10, 81, 51));
        title_lineEdit = new QLineEdit(frame);
        title_lineEdit->setObjectName(QString::fromUtf8("title_lineEdit"));
        title_lineEdit->setGeometry(QRect(200, 120, 261, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(12);
        title_lineEdit->setFont(font4);
        title_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        description_name_label = new QLabel(frame);
        description_name_label->setObjectName(QString::fromUtf8("description_name_label"));
        description_name_label->setGeometry(QRect(80, 170, 111, 21));
        description_name_label->setFont(font1);
        description_plainTextEdit = new QPlainTextEdit(frame);
        description_plainTextEdit->setObjectName(QString::fromUtf8("description_plainTextEdit"));
        description_plainTextEdit->setGeometry(QRect(200, 160, 261, 121));
        description_plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        startDateTime_name_label = new QLabel(frame);
        startDateTime_name_label->setObjectName(QString::fromUtf8("startDateTime_name_label"));
        startDateTime_name_label->setGeometry(QRect(20, 290, 141, 21));
        startDateTime_name_label->setFont(font1);
        startDateTime_dateTimeEdit = new QDateTimeEdit(frame);
        startDateTime_dateTimeEdit->setObjectName(QString::fromUtf8("startDateTime_dateTimeEdit"));
        startDateTime_dateTimeEdit->setGeometry(QRect(20, 320, 251, 31));
        QFont font5;
        font5.setPointSize(12);
        startDateTime_dateTimeEdit->setFont(font5);
        startDateTime_dateTimeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        endDateTime_name_label = new QLabel(frame);
        endDateTime_name_label->setObjectName(QString::fromUtf8("endDateTime_name_label"));
        endDateTime_name_label->setGeometry(QRect(280, 290, 141, 21));
        endDateTime_name_label->setFont(font1);
        endDateTime_dateTimeEdit = new QDateTimeEdit(frame);
        endDateTime_dateTimeEdit->setObjectName(QString::fromUtf8("endDateTime_dateTimeEdit"));
        endDateTime_dateTimeEdit->setGeometry(QRect(280, 320, 251, 31));
        endDateTime_dateTimeEdit->setFont(font5);
        endDateTime_dateTimeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        category_label = new QLabel(frame);
        category_label->setObjectName(QString::fromUtf8("category_label"));
        category_label->setGeometry(QRect(90, 360, 101, 31));
        category_label->setFont(font1);
        category_comboBox = new QComboBox(frame);
        category_comboBox->setObjectName(QString::fromUtf8("category_comboBox"));
        category_comboBox->setGeometry(QRect(190, 360, 251, 31));
        category_comboBox->setFont(font5);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 400, 221, 41));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Segoe UI Semibold"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        checkBox->setFont(font6);
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(310, 400, 201, 41));
        checkBox_2->setFont(font6);
        checkBox_3 = new QCheckBox(frame);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(170, 460, 211, 41));
        checkBox_3->setFont(font6);
        startDateTime_name_label_2 = new QLabel(frame);
        startDateTime_name_label_2->setObjectName(QString::fromUtf8("startDateTime_name_label_2"));
        startDateTime_name_label_2->setGeometry(QRect(50, 500, 201, 31));
        startDateTime_name_label_2->setFont(font1);
        startDateTime_dateTimeEdit_2 = new QDateTimeEdit(frame);
        startDateTime_dateTimeEdit_2->setObjectName(QString::fromUtf8("startDateTime_dateTimeEdit_2"));
        startDateTime_dateTimeEdit_2->setGeometry(QRect(250, 500, 251, 31));
        startDateTime_dateTimeEdit_2->setFont(font5);
        startDateTime_dateTimeEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 540, 521, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        AddNewTaskPremiumUserAccountWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddNewTaskPremiumUserAccountWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 541, 21));
        AddNewTaskPremiumUserAccountWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddNewTaskPremiumUserAccountWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddNewTaskPremiumUserAccountWindow->setStatusBar(statusbar);

        retranslateUi(AddNewTaskPremiumUserAccountWindow);

        QMetaObject::connectSlotsByName(AddNewTaskPremiumUserAccountWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddNewTaskPremiumUserAccountWindow)
    {
        AddNewTaskPremiumUserAccountWindow->setWindowTitle(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Create New Task", nullptr));
        title_label->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Title", nullptr));
        label_3->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Task Reminder Management System", nullptr));
        add_pushButton->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "ADD TASK", nullptr));
        logo_label->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "LOGO", nullptr));
#if QT_CONFIG(tooltip)
        title_lineEdit->setToolTip(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Enter First Name</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        description_name_label->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Description", nullptr));
        startDateTime_name_label->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Start Date Time", nullptr));
        endDateTime_name_label->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "End Date Time", nullptr));
        category_label->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Category", nullptr));
        checkBox->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Pin Task to Top of Category", nullptr));
        checkBox_2->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Mark as Important", nullptr));
        checkBox_3->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Enable Task Termination", nullptr));
        startDateTime_name_label_2->setText(QCoreApplication::translate("AddNewTaskPremiumUserAccountWindow", "Termination Date Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewTaskPremiumUserAccountWindow: public Ui_AddNewTaskPremiumUserAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H
