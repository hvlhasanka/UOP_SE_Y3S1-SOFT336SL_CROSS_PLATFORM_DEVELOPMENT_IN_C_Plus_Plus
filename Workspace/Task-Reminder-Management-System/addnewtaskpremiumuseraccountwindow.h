#ifndef ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H
#define ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include <databaseconnection.h>
#include <authenticatelogic.h>
#include <premiumuseraccountlogic.h>

namespace Ui {
class AddNewTaskPremiumUserAccountWindow;
}

class AddNewTaskPremiumUserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewTaskPremiumUserAccountWindow(QWidget *parent = nullptr);
    ~AddNewTaskPremiumUserAccountWindow();

private:
    Ui::AddNewTaskPremiumUserAccountWindow *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the authenticate.h
    // Retireving the authenticate.h class path to a pointer
    AuthenticateLogic *auth;
    // Connecting the premiumuseraccountlogic.h
    // Retireving the premiumuseraccountlogic.h class path to a pointer
    PremiumUserAccountLogic *premiumUserAccountLogic;
};

#endif // ADDNEWTASKPREMIUMUSERACCOUNTWINDOW_H
