#include "adminaccountwindow.h"
#include "ui_adminaccountwindow.h"

AdminAccountWindow::AdminAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminAccountWindow)
{
    ui->setupUi(this);

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix(":/images/TRMS-Logo-Without-Text.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));



}

AdminAccountWindow::~AdminAccountWindow()
{
    delete ui;
}
