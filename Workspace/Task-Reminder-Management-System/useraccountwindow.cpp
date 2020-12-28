#include "useraccountwindow.h"
#include "ui_useraccountwindow.h"

UserAccountWindow::UserAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserAccountWindow)
{
    ui->setupUi(this);
}

UserAccountWindow::~UserAccountWindow()
{
    delete ui;
}
