/********************************************************************************
** Form generated from reading UI file 'reportsubmissionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTSUBMISSIONWINDOW_H
#define UI_REPORTSUBMISSIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportSubmissionWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *logo_label;
    QLabel *subject_label;
    QLabel *label;
    QLabel *label_4;
    QPushButton *submitReport_pushButton;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *subject_lineEdit;
    QLabel *subject_label_2;
    QTextEdit *textEdit;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ReportSubmissionWindow)
    {
        if (ReportSubmissionWindow->objectName().isEmpty())
            ReportSubmissionWindow->setObjectName(QString::fromUtf8("ReportSubmissionWindow"));
        ReportSubmissionWindow->resize(550, 526);
        centralwidget = new QWidget(ReportSubmissionWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 551, 481));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 192, 196);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        logo_label = new QLabel(frame);
        logo_label->setObjectName(QString::fromUtf8("logo_label"));
        logo_label->setGeometry(QRect(20, 10, 81, 51));
        subject_label = new QLabel(frame);
        subject_label->setObjectName(QString::fromUtf8("subject_label"));
        subject_label->setGeometry(QRect(70, 150, 91, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        subject_label->setFont(font);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 50, 381, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Malgun Gothic"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 150, 16, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft New Tai Lue"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setWeight(50);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        submitReport_pushButton = new QPushButton(frame);
        submitReport_pushButton->setObjectName(QString::fromUtf8("submitReport_pushButton"));
        submitReport_pushButton->setGeometry(QRect(80, 420, 371, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        submitReport_pushButton->setFont(font3);
        submitReport_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 10, 371, 41));
        QFont font4;
        font4.setPointSize(16);
        label_3->setFont(font4);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 10, 71, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Myriad Hebrew"));
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        label_2->setFont(font5);
        subject_lineEdit = new QLineEdit(frame);
        subject_lineEdit->setObjectName(QString::fromUtf8("subject_lineEdit"));
        subject_lineEdit->setGeometry(QRect(200, 150, 261, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Segoe UI"));
        font6.setPointSize(12);
        subject_lineEdit->setFont(font6);
        subject_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        subject_label_2 = new QLabel(frame);
        subject_label_2->setObjectName(QString::fromUtf8("subject_label_2"));
        subject_label_2->setGeometry(QRect(70, 200, 131, 21));
        subject_label_2->setFont(font);
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(200, 190, 261, 211));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 190, 16, 21));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 21, 0);"));
        ReportSubmissionWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ReportSubmissionWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 550, 21));
        ReportSubmissionWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ReportSubmissionWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ReportSubmissionWindow->setStatusBar(statusbar);

        retranslateUi(ReportSubmissionWindow);

        QMetaObject::connectSlotsByName(ReportSubmissionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ReportSubmissionWindow)
    {
        ReportSubmissionWindow->setWindowTitle(QCoreApplication::translate("ReportSubmissionWindow", "MainWindow", nullptr));
        logo_label->setText(QCoreApplication::translate("ReportSubmissionWindow", "LOGO", nullptr));
        subject_label->setText(QCoreApplication::translate("ReportSubmissionWindow", "Subject", nullptr));
        label->setText(QCoreApplication::translate("ReportSubmissionWindow", "Feedback Report Submission", nullptr));
        label_4->setText(QCoreApplication::translate("ReportSubmissionWindow", "*", nullptr));
        submitReport_pushButton->setText(QCoreApplication::translate("ReportSubmissionWindow", "SUBMIT REPORT", nullptr));
        label_3->setText(QCoreApplication::translate("ReportSubmissionWindow", "Task Reminder Management System", nullptr));
        label_2->setText(QCoreApplication::translate("ReportSubmissionWindow", "TRMS - ", nullptr));
#if QT_CONFIG(tooltip)
        subject_lineEdit->setToolTip(QCoreApplication::translate("ReportSubmissionWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Provide a Subject for your Feedback</span></p><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        subject_label_2->setText(QCoreApplication::translate("ReportSubmissionWindow", "Feedback", nullptr));
#if QT_CONFIG(tooltip)
        textEdit->setToolTip(QCoreApplication::translate("ReportSubmissionWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Provide your feedback</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("ReportSubmissionWindow", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportSubmissionWindow: public Ui_ReportSubmissionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTSUBMISSIONWINDOW_H
