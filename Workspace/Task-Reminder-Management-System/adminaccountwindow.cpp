#include "adminaccountwindow.h"
#include "ui_adminaccountwindow.h"

AdminAccountWindow::AdminAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminAccountWindow)
{
    ui->setupUi(this);
}

AdminAccountWindow::~AdminAccountWindow()
{
    delete ui;
}
