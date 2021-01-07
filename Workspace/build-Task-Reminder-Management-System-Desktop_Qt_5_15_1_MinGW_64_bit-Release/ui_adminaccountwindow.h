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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminAccountWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminAccountWindow)
    {
        if (AdminAccountWindow->objectName().isEmpty())
            AdminAccountWindow->setObjectName(QString::fromUtf8("AdminAccountWindow"));
        AdminAccountWindow->resize(800, 600);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("trms-logo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/images/TRMS-Logo-Without-Text.ico"), QSize(), QIcon::Normal, QIcon::Off);
        }
        AdminAccountWindow->setWindowIcon(icon);
        centralwidget = new QWidget(AdminAccountWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AdminAccountWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminAccountWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AdminAccountWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminAccountWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminAccountWindow->setStatusBar(statusbar);

        retranslateUi(AdminAccountWindow);

        QMetaObject::connectSlotsByName(AdminAccountWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminAccountWindow)
    {
        AdminAccountWindow->setWindowTitle(QCoreApplication::translate("AdminAccountWindow", "TRMS - Admin Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminAccountWindow: public Ui_AdminAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINACCOUNTWINDOW_H
