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
