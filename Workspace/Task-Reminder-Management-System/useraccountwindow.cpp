#include "useraccountwindow.h"
#include "ui_useraccountwindow.h"

UserAccountWindow::UserAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserAccountWindow)
{
    ui->setupUi(this);

    // Creating an object of AccountLogic class
    account = new AccountLogic();

}

UserAccountWindow::~UserAccountWindow()
{
    delete ui;
}

void UserAccountWindow::on_addNewTask_pushButton_clicked()
{
   // auth->setAccountType("fff");
   // qWarning() << auth->getAccountType();

    addNewTaskStandardUserAccountWindowForm = new AddNewTaskStandardUserAccountWindow(this);
    addNewTaskStandardUserAccountWindowForm->show();

}

void UserAccountWindow::on_report_pushButton_clicked()
{

    reportSubmissionWindowForm = new ReportSubmissionWindow(this);
    reportSubmissionWindowForm->show();

}
