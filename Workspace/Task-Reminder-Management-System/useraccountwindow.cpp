#include "useraccountwindow.h"
#include "ui_useraccountwindow.h"

UserAccountWindow::UserAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserAccountWindow)
{
    ui->setupUi(this);

    // Creating an object of Authenticate class
    auth = new AuthenticateLogic();
}

UserAccountWindow::~UserAccountWindow()
{
    delete ui;
}


void UserAccountWindow::on_addNewTask_pushButton_clicked()
{
    qDebug() << auth->getAccountType();
    // Checking the accountType and opening the addNewTask window accordingly
    if(auth->getAccountType() == "Standard User Account"){
        addNewTaskStandardUserAccountWindow = new AddNewTaskStandardUserAccountWindow(this);
        addNewTaskStandardUserAccountWindow->show();
    }
    else if(auth->getAccountType() == "Premium User Account"){
        addNewTaskPremiumUserAccountWindow = new AddNewTaskPremiumUserAccountWindow(this);
        addNewTaskPremiumUserAccountWindow->show();
    }

}


void UserAccountWindow::on_report_pushButton_clicked()
{

    reportSubmissionWindow = new ReportSubmissionWindow(this);
    reportSubmissionWindow->show();

}
