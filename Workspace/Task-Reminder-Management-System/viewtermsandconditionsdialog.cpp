#include "viewtermsandconditionsdialog.h"
#include "ui_viewtermsandconditionsdialog.h"

ViewTermsAndConditionsDialog::ViewTermsAndConditionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTermsAndConditionsDialog)
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

ViewTermsAndConditionsDialog::~ViewTermsAndConditionsDialog()
{
    delete ui;
}
