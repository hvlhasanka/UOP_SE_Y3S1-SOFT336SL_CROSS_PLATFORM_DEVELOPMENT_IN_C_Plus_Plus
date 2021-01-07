/********************************************************************************
** Form generated from reading UI file 'addnewtasksuawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWTASKSUAWINDOW_H
#define UI_ADDNEWTASKSUAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AddNewTaskSUAWindow
{
public:

    void setupUi(QDialog *AddNewTaskSUAWindow)
    {
        if (AddNewTaskSUAWindow->objectName().isEmpty())
            AddNewTaskSUAWindow->setObjectName(QString::fromUtf8("AddNewTaskSUAWindow"));
        AddNewTaskSUAWindow->resize(400, 300);

        retranslateUi(AddNewTaskSUAWindow);

        QMetaObject::connectSlotsByName(AddNewTaskSUAWindow);
    } // setupUi

    void retranslateUi(QDialog *AddNewTaskSUAWindow)
    {
        AddNewTaskSUAWindow->setWindowTitle(QCoreApplication::translate("AddNewTaskSUAWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewTaskSUAWindow: public Ui_AddNewTaskSUAWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWTASKSUAWINDOW_H
