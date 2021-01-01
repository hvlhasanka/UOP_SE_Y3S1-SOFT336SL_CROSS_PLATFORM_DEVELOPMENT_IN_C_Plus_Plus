/********************************************************************************
** Form generated from reading UI file 'useraccountwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERACCOUNTWINDOW_H
#define UI_USERACCOUNTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserAccountWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserAccountWindow)
    {
        if (UserAccountWindow->objectName().isEmpty())
            UserAccountWindow->setObjectName(QString::fromUtf8("UserAccountWindow"));
        UserAccountWindow->resize(805, 677);
        centralwidget = new QWidget(UserAccountWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        UserAccountWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserAccountWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 805, 21));
        UserAccountWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserAccountWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserAccountWindow->setStatusBar(statusbar);

        retranslateUi(UserAccountWindow);

        QMetaObject::connectSlotsByName(UserAccountWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserAccountWindow)
    {
        UserAccountWindow->setWindowTitle(QCoreApplication::translate("UserAccountWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserAccountWindow: public Ui_UserAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERACCOUNTWINDOW_H
