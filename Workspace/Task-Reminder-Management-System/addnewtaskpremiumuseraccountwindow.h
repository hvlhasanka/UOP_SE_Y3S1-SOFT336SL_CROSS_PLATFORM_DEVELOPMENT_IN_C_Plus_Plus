#ifndef ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H
#define ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "databaseconnection.h"
#include "accountlogic.h"
#include "premiumuseraccountlogic.h"

namespace Ui {
class AddNewTaskPremiumUserAccountWindow;
}

class AddNewTaskPremiumUserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewTaskPremiumUserAccountWindow(int accountID, QWidget *parent = nullptr);
    ~AddNewTaskPremiumUserAccountWindow();

private:
    Ui::AddNewTaskPremiumUserAccountWindow *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the accountlogic.h
    // Retireving the accountlogic.h class path to a pointer
    AccountLogic *account;
    // Connecting the premiumuseraccountlogic.h
    // Retireving the premiumuseraccountlogic.h class path to a pointer
    PremiumUserAccountLogic *premiumUserAccountLogic;
};

#endif // ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H
