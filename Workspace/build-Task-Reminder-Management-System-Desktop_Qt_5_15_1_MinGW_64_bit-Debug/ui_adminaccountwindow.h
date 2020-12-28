/********************************************************************************
** Form generated from reading UI file 'adminaccountwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINACCOUNTWINDOW_H
#define UI_ADMINACCOUNTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminAccountWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminAccountWindow)
    {
        if (AdminAccountWindow->objectName().isEmpty())
            AdminAccountWindow->setObjectName(QString::fromUtf8("AdminAccountWindow"));
        AdminAccountWindow->resize(800, 600);
        menubar = new QMenuBar(AdminAccountWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        AdminAccountWindow->setMenuBar(menubar);
        centralwidget = new QWidget(AdminAccountWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AdminAccountWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AdminAccountWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminAccountWindow->setStatusBar(statusbar);

        retranslateUi(AdminAccountWindow);

        QMetaObject::connectSlotsByName(AdminAccountWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminAccountWindow)
    {
        AdminAccountWindow->setWindowTitle(QCoreApplication::translate("AdminAccountWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminAccountWindow: public Ui_AdminAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINACCOUNTWINDOW_H
