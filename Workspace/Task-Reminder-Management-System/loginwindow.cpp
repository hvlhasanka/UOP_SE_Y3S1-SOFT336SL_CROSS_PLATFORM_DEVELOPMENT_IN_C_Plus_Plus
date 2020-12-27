/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QPixmap>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <QRegularExpression>

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

    // Creating an object of Authenticate class
    auth = new AuthenticateLogic;
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

// If the user clicks on 'Forgot Password?' push button
void LoginWindow::on_forgotPassword_pushButton_clicked()
{

    // Showing message box to explain the procedure
    QString forgotPasswordResponseEmailAddress = QInputDialog::getText(this, "Password Recovery",
                                                                       "Unfortunately you are unable to recover the existing password, \n"
                                                                       "you are required to update the password.\n\n"
                                                                       "Please enter your email address and a pin code will be emailed.\n");
    qDebug() << forgotPasswordResponseEmailAddress;
   /*
    QMessageBox::question(this, "Password Recovery",
                          "Unfortunately you are unable to recover the existing password, "
                          "you are required to update the password."
                          "Please enter your email address and a pin code will be emailed."
                          , "Cancel", "Continue");

*/
}

void LoginWindow::on_emailAddress_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered email address value is in the correct regular expression
    // arg1 = ui->emailAddress_lineEdit->text();
    QString enteredEmailAddressValue = arg1;
    QRegularExpression re("^[A-Za-z0-9_]+@[a-zA-Z_]+?.[a-zA-Z]{2,3}+");
    QRegularExpressionMatch validationCheck = re.match(enteredEmailAddressValue);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        ui->emailAddress_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
    }
    else if (validationResponse == false){
        ui->emailAddress_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
    }
}

void LoginWindow::on_password_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered password value is in the correct regular expression
    // arg1 = ui->password_lineEdit->text();
    QString enteredPasswordValue = arg1;
    // Password Guidelines:
    //  Minimum of seven characters
    //  Atleast one uppercase letter
    //  Atleast one lowercase letter
    //  Atleast one numeric character
    //  Atleast one special character
    QRegularExpression re("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#[\\$%[\\^&[\\*])(?=.{7,})");
    QRegularExpressionMatch validationCheck = re.match(enteredPasswordValue);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        ui->password_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
    }
    else if (validationResponse == false){
        ui->password_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
    }
}
