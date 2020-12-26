/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QPixmap>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    /* Cover Image Implementation Source Code */
    // Getting the cover image
    QPixmap coverImagePix("C:/Users/Lucas.L.H.H/Documents/GitHub/UOP_SE_Y3S1-SOFT336SL_CROSS_PLATFORM_DEVELOPMENT_IN_C_Plus_Plus/Workspace/Task-Reminder-Management-System/assets/images/Cover-Image.jpg");
    // Getting the width of the coverImage_label
    int coverImageLabelWidth = ui->coverImage_label->width();
    // Getting the height of the coverImage_label
    int coverImageLabelHeight = ui->coverImage_label->height();
    // Setting the cover image to the coverImage_Label
    ui->coverImage_label->setPixmap(coverImagePix.scaled(coverImageLabelWidth, coverImageLabelHeight, Qt::KeepAspectRatio));

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix("C:/Users/Lucas.L.H.H/Documents/GitHub/UOP_SE_Y3S1-SOFT336SL_CROSS_PLATFORM_DEVELOPMENT_IN_C_Plus_Plus/Workspace/Task-Reminder-Management-System/assets/images/TRMS-Logo-WithBackground.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

// If user checks or unchecks 'showPassword_checkBox'
void LoginWindow::on_showPassword_checkBox_stateChanged(int arg1)
{
    // Checking whether the 'showPassword_checkBox' is checked or not
    // arg1 = ui->showPassword_checkBox->isChecked()
    if(arg1){
        // If it is checked the 'password_lineEdit' text will be visible
        password_lineEdit = ui->password_lineEdit;
        password_lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else{
        // If it is unchecked the 'password_lineEdit' text will be invisible - password value
        password_lineEdit = ui->password_lineEdit;
        password_lineEdit->setEchoMode(QLineEdit::Password);
    }
}
