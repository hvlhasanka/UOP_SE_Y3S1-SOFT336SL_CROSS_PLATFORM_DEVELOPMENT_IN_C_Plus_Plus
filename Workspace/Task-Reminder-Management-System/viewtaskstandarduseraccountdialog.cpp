#include "viewtaskstandarduseraccountdialog.h"
#include "ui_viewtaskstandarduseraccountdialog.h"

ViewTaskStandardUserAccountDialog::ViewTaskStandardUserAccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTaskStandardUserAccountDialog)
{
    ui->setupUi(this);
}

ViewTaskStandardUserAccountDialog::~ViewTaskStandardUserAccountDialog()
{
    delete ui;
}
