#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
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

    /* About Image Implementation Source Code */
    // Getting the about image
    QPixmap aboutImagePix(":/images/AboutImage.png");
    // Getting the width of the aboutImage_label
    int aboutLabelWidth = ui->aboutImage_label->width();
    // Getting the height of the aboutImage_label
    int aboutLabelHeight = ui->aboutImage_label->height();
    // Setting the cover image of the aboutImage_label
    ui->aboutImage_label->setPixmap(aboutImagePix.scaled(aboutLabelWidth, aboutLabelHeight, Qt::KeepAspectRatio));


}

AboutDialog::~AboutDialog()
{
    delete ui;
}
