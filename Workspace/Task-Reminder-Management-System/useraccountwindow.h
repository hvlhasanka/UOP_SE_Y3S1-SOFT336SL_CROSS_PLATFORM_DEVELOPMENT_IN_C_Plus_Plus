#ifndef USERACCOUNTWINDOW_H
#define USERACCOUNTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QTimer>

#include "authenticatelogic.h"
#include "reportsubmissionwindow.h"
#include "addnewtaskstandarduseraccountwindow.h"
#include "addnewtaskpremiumuseraccountwindow.h"
#include "accountlogic.h"
#include "databaseconnection.h"
#include "viewtaskstandarduseraccountdialog.h"
#include "editreminderdetailsstandarduseraccount.h"
#include "aboutdialog.h"
#include "viewcategorydetailsdialog.h"

namespace Ui {
class UserAccountWindow;
}

class UserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserAccountWindow(int loginID, QWidget *parent = nullptr);
    ~UserAccountWindow();

public slots:
    void executeReminderStandardUserAccount();
    void executeReminderPremiumUserAccount();
    void changeUIForSelectedDate(QDate selectedDate);

private slots:
    void on_addNewTask_pushButton_clicked();
    void on_report_pushButton_clicked();
    void on_logout_pushButton_clicked();
    void on_refresh_pushButton_clicked();
    void on_showTaskDetails_lineEdit_textChanged(const QString &arg1);
    void on_showTaskDetails_pushButton_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_change_Membership_pushButton_clicked();
    void on_standardAccount_radioButton_toggled(bool checked);
    void on_premiumAccount_radioButton_toggled(bool checked);
    void on_editReminder_pushButton_clicked();
    void on_actionAbout_triggered();
    void on_actionLogout_triggered();
    void on_actionExit_triggered();
    void on_category1_toolButton_clicked();
    void on_category2_toolButton_clicked();
    void on_category3_toolButton_clicked();
    void on_category4_toolButton_clicked();

private:
    QString category1Name;
    QString category2Name;
    QString category3Name;
    QString category4Name;
    Ui::UserAccountWindow *ui;
    // Connecting the authenticatelogic.h
    // Retireving the authenticatelogic.h class path to a pointer
    AuthenticateLogic *auth;
    // Connecting the ReportSubmissionWindow.h
    // Retireving the ReportSubmissionWindow.h class path to a pointer
    ReportSubmissionWindow *reportSubmissionWindowForm;
    // Connecting the addnewtaskstandarduseraccountwindow.h
    // Retireving the addnewtaskstandarduseraccountwindow.h class path to a pointer
    AddNewTaskStandardUserAccountWindow *addNewTaskStandardUserAccountWindowForm;
    // Connecting the addnewtaskpremiumuseraccountwindow.h
    // Retireving the addnewtaskpremiumuseraccountwindow.h class path to a pointer
    AddNewTaskPremiumUserAccountWindow *addNewTaskPremiumUserAccountWindowForm;
    // Connecting the accountlogic.h
    // Retireving the accountlogic.h class path to a pointer
    AccountLogic *account;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the viewtaskstandarduseraccountdialog.h
    // Retireving the viewtaskstandarduseraccountdialog.h class path to a pointer
    ViewTaskStandardUserAccountDialog *viewTaskStandardUserAccountDialogForm;
    // Connecting the editreminderdetailsstandarduseraccount.h
    // Retireving the editreminderdetailsstandarduseraccount.h class path to a pointer
    EditReminderDetailsStandardUserAccount *editReminderDetailsStandardUserAccountForm;
    // Connecting the aboutdialog.h
    // Retireving the aboutdialog.h class path to a pointer
    AboutDialog *aboutDialogForm;
    // Connecting the viewcategorydetailsdialog.h
    // Retireving the viewcategorydetailsdialog.h class path to a pointer
    ViewCategoryDetailsDialog *viewCategoryDetailsDialogForm;
    QSystemTrayIcon *reminderAlert;
    QTimer *timer;
};

#endif // USERACCOUNTWINDOW_H
