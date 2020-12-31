#include "userregistrationwindow.h"
#include "ui_userregistrationwindow.h"

UserRegistrationWindow::UserRegistrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserRegistrationWindow)
{
    ui->setupUi(this);

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix("C:/Users/Lucas.L.H.H/Documents/GitHub/UOP_SE_Y3S1-SOFT336SL_CROSS_PLATFORM_DEVELOPMENT_IN_C_Plus_Plus/Workspace/Task-Reminder-Management-System/assets/images/TRMS-Logo-Without-Text.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));

    // Disabling 'Register' push button
    ui->register_pushButton->setEnabled(false);

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    /* Retrieving account type values from the database and assigning it to account type combobox */
    bool connectionStatus = trms_dbConnection->openDatebaseConnection();
    if(connectionStatus == true){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery accountTypesQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        accountTypesQuery.prepare(QString("SELECT AccountType FROM AccountType WHERE AccountType != 'AdminAccount';"));

        // Executing sql query and checking the status
        if(!accountTypesQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << accountTypesQuery.lastError();
        }
        else{
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal->setQuery(accountTypesQuery);
            ui->accountType_comboBox->setModel(modal);
        }
    }
    trms_dbConnection->closeDatebaseConnection();


}

UserRegistrationWindow::~UserRegistrationWindow()
{
    delete ui;
}

// If user clicks on the 'Register' push button
void UserRegistrationWindow::on_login_pushButton_clicked()
{



}

// If user clicks on 'View Password Guidelines' button
void UserRegistrationWindow::on_viewPasswordGuidelines_pushButton_clicked()
{
    QMessageBox::information(this, "Password Guidelines", "Minimum of seven (7) characters\n"
                                                          "Maximum of twenty (20) characters\n"
                                                          "Atleast one uppercase letter\n"
                                                          "Atleast one lowercase letter\n"
                                                          "Atleast one numeric character\n"
                                                          "Atleast one special character");
}

// When user changes the 'firstName' text
void UserRegistrationWindow::on_firstName_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered first name value is in the correct regular expression
    // arg1 = ui->firstName_lineEdit->text();
    QString enteredFirstName = arg1;
    QRegularExpression re("^[A-z]+$");
    QRegularExpressionMatch validationCheck = re.match(enteredFirstName);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->firstName_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredFirstNameValueAcceptable to true
        enteredFirstNameValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->firstName_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredFirstNameValueAcceptable to false as the entered first name value is not acceptable
        enteredFirstNameValueAcceptable = false;
    }

    if(enteredFirstNameValueAcceptable == true && enteredLastNameValueAcceptable == true
            && enteredEmailAddressValueAcceptable == true && enteredPasswordValueAcceptable == true
            && enteredConfirmPasswordValueAcceptable == true && checkedTermsAndConditions == true){
        // Enabling register push button
        ui->register_pushButton->setEnabled(true);
    }
    else{
        // Disabling register push button
        ui->register_pushButton->setEnabled(false);
    }
}

// When user changes the 'middleName' text
void UserRegistrationWindow::on_middleName_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered middle name value is in the correct regular expression
    // arg1 = ui->middleName_lineEdit->text();
    QString enteredMiddleName = arg1;
    QRegularExpression re("^[A-z]+$");
    QRegularExpressionMatch validationCheck = re.match(enteredMiddleName);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->middleName_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredMiddleNameValueAcceptable to true
        enteredMiddleNameValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->middleName_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredMiddleNameValueAcceptable to false as the entered middle name value is not acceptable
        enteredMiddleNameValueAcceptable = false;
    }
}

// When user changes the 'lastName' text
void UserRegistrationWindow::on_lastName_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered last name value is in the correct regular expression
    // arg1 = ui->lastName_lineEdit->text();
    QString enteredLastName = arg1;
    QRegularExpression re("^[A-z]+$");
    QRegularExpressionMatch validationCheck = re.match(enteredLastName);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->lastName_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredLastNameValueAcceptable to true
        enteredLastNameValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->lastName_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredLastNameValueAcceptable to false as the entered last name value is not acceptable
        enteredLastNameValueAcceptable = false;
    }

    if(enteredFirstNameValueAcceptable == true && enteredLastNameValueAcceptable == true
            && enteredEmailAddressValueAcceptable == true && enteredPasswordValueAcceptable == true
            && enteredConfirmPasswordValueAcceptable == true && checkedTermsAndConditions == true){
        // Enabling register push button
        ui->register_pushButton->setEnabled(true);
    }
    else{
        // Disabling register push button
        ui->register_pushButton->setEnabled(false);
    }
}

// When the user changes the 'emailAddress' text
void UserRegistrationWindow::on_emailAddress_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered email address value is in the correct regular expression
    // arg1 = ui->emailAddress_lineEdit->text();
    QString enteredEmailAddress = arg1;
    QRegularExpression re("^[A-Za-z0-9_]+@[a-zA-Z_]+?.[a-zA-Z]{2,3}+");
    QRegularExpressionMatch validationCheck = re.match(enteredEmailAddress);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->emailAddress_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredEmailAddressValueAcceptable to true
        enteredEmailAddressValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->emailAddress_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredEmailAddressValueAcceptable to false as the entered email address value is not acceptable
        enteredEmailAddressValueAcceptable = false;
    }

    if(enteredFirstNameValueAcceptable == true && enteredLastNameValueAcceptable == true
            && enteredEmailAddressValueAcceptable == true && enteredPasswordValueAcceptable == true
            && enteredConfirmPasswordValueAcceptable == true && checkedTermsAndConditions == true){
        // Enabling register push button
        ui->register_pushButton->setEnabled(true);
    }
    else{
        // Disabling register push button
        ui->register_pushButton->setEnabled(false);
    }
}

// When the user changes the 'Password' text
void UserRegistrationWindow::on_password_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered password value is in the correct regular expression
    // arg1 = ui->password_lineEdit->text();
    QString enteredPassword = arg1;
    QRegularExpression re("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#[\\$%[\\^&[\\*])(?=.{7,20})");
    QRegularExpressionMatch validationCheck = re.match(enteredPassword);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->password_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredPasswordValueAcceptable to true
        enteredPasswordValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->password_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredPasswordValueAcceptable to false as the entered password value is not acceptable
        enteredPasswordValueAcceptable = false;
    }

    if(enteredFirstNameValueAcceptable == true && enteredLastNameValueAcceptable == true
            && enteredEmailAddressValueAcceptable == true && enteredPasswordValueAcceptable == true
            && enteredConfirmPasswordValueAcceptable == true && checkedTermsAndConditions == true){
        // Enabling register push button
        ui->register_pushButton->setEnabled(true);
    }
    else{
        // Disabling register push button
        ui->register_pushButton->setEnabled(false);
    }
}

// When user changes the 'Confirm Password' text
void UserRegistrationWindow::on_confirmPassword_lineEdit_textChanged(const QString &arg1)
{
    // Checking whether the user entered confirm password value is in the correct regular expression
    // arg1 = ui->confirmPassword_lineEdit->text();
    QString enteredConfirmPassword = arg1;
    QRegularExpression re("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#[\\$%[\\^&[\\*])(?=.{7,20})");
    QRegularExpressionMatch validationCheck = re.match(enteredConfirmPassword);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->confirmPassword_lineEdit->setStyleSheet("border: 2px solid green;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredConfirmPasswordValueAcceptable to true
        enteredConfirmPasswordValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->confirmPassword_lineEdit->setStyleSheet("border: 2px solid red;"
                                                 "background-color: rgb(255, 255, 255);");
        // Setting enteredConfirmPasswordValueAcceptable to false as the entered confirm password value is not acceptable
        enteredConfirmPasswordValueAcceptable = false;
    }

    if(enteredFirstNameValueAcceptable == true && enteredLastNameValueAcceptable == true
            && enteredEmailAddressValueAcceptable == true && enteredPasswordValueAcceptable == true
            && enteredConfirmPasswordValueAcceptable == true && checkedTermsAndConditions == true){
        // Enabling register push button
        ui->register_pushButton->setEnabled(true);
    }
    else{
        // Disabling register push button
        ui->register_pushButton->setEnabled(false);
    }
}

// When user checks the 'termsAndConditions' checkbox
void UserRegistrationWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        checkedTermsAndConditions = true;
    }
    else{
        checkedTermsAndConditions = false;
    }

    if(enteredFirstNameValueAcceptable == true && enteredLastNameValueAcceptable == true
            && enteredEmailAddressValueAcceptable == true && enteredPasswordValueAcceptable == true
            && enteredConfirmPasswordValueAcceptable == true && checkedTermsAndConditions == true){
        // Enabling register push button
        ui->register_pushButton->setEnabled(true);
    }
    else{
        // Disabling register push button
        ui->register_pushButton->setEnabled(false);
    }
}

// When user clicks on 'Register' button
void UserRegistrationWindow::on_register_pushButton_clicked()
{
    /* Checking whether the enter email address already existing in the database */
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery emailAddressQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        emailAddressQuery.prepare(QString("SELECT EmailAddress FROM Login WHERE EmailAddress = ':enteredEmailAddress'"));

        // Executing sql query and checking the status
        if(!emailAddressQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << emailAddressQuery.lastError();
        }
        else{
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal->setQuery(emailAddressQuery);
            ui->accountType_comboBox->setModel(modal);
        }

    }
    else if(databaseConnected == false){


    }

    int enteredMiddleNameStringLength = ui->middleName_lineEdit->text().length();

    if(enteredMiddleNameStringLength == 0){



    }

}
