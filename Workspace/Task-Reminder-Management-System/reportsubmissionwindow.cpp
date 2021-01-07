#include "reportsubmissionwindow.h"
#include "ui_reportsubmissionwindow.h"

ReportSubmissionWindow::ReportSubmissionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReportSubmissionWindow)
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

    // Disabling submit report push button
    ui->submitReport_pushButton->setEnabled(false);

    // Creating an object of AccountLogic class
    accountLogic = new AccountLogic();

}

ReportSubmissionWindow::~ReportSubmissionWindow()
{
    delete ui;
}

void ReportSubmissionWindow::on_subject_lineEdit_textChanged(const QString &arg1)
{

    // Checking whether the user entered subject value is in the correct regular expression
    // arg1 = ui->subject_lineEdit->text();
    QString enteredSubject = arg1;
    QRegularExpression re("^[a-zA-Z0-9_ ]*$");
    QRegularExpressionMatch validationCheck = re.match(enteredSubject);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->subject_lineEdit->setStyleSheet("border: 2px solid green;"
                                            "background-color: rgb(255, 255, 255);");
        // Setting enteredSubjectValueAcceptable to true
        enteredSubjectValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->subject_lineEdit->setStyleSheet("border: 2px solid red;"
                                            "background-color: rgb(255, 255, 255);");
        // Setting enteredSubjectValueAcceptable to false as the entered subject value is not acceptable
        enteredSubjectValueAcceptable = false;
    }

    if(enteredSubjectValueAcceptable == true && enteredFeedbackValueAcceptable == true
            && enteredReachableEmailAddressAcceptable == true){
        // Enabling submit report push button
        ui->submitReport_pushButton->setEnabled(true);
    }
    else{
        // Disabling submit report push button
        ui->submitReport_pushButton->setEnabled(false);
    }

}

void ReportSubmissionWindow::on_feedback_textEdit_textChanged()
{

    // Checking whether the user entered feedback value is in the correct regular expression
    QString enteredFeedback = ui->feedback_textEdit->toPlainText();
    QRegularExpression re("^[a-zA-Z0-9_ ]*$");
    QRegularExpressionMatch validationCheck = re.match(enteredFeedback);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->feedback_textEdit->setStyleSheet("border: 2px solid green;"
                                             "background-color: rgb(255, 255, 255);");
        // Setting enteredFeedbackValueAcceptable to true
        enteredFeedbackValueAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->feedback_textEdit->setStyleSheet("border: 2px solid red;"
                                             "background-color: rgb(255, 255, 255);");
        // Setting enteredFeedbackValueAcceptable to false as the entered subject value is not acceptable
        enteredFeedbackValueAcceptable = false;
    }

    if(enteredSubjectValueAcceptable == true && enteredFeedbackValueAcceptable == true
            && enteredReachableEmailAddressAcceptable == true){
        // Enabling submit report push button
        ui->submitReport_pushButton->setEnabled(true);
    }
    else{
        // Disabling submit report push button
        ui->submitReport_pushButton->setEnabled(false);
    }

}

void ReportSubmissionWindow::on_authorReachableEmailAddress_lineEdit_textChanged(const QString &arg1)
{

    // Checking whether the user entered reachable email address value is in the correct regular expression
    // arg1 = ui->reachableEmailAddress_lineEdit->text();
    QString enteredEmailAddress = arg1;
    QRegularExpression re("^[A-Za-z0-9_]+@[a-zA-Z_]+?.[a-zA-Z]{2,3}+");
    QRegularExpressionMatch validationCheck = re.match(enteredEmailAddress);
    bool validationResponse = validationCheck.hasMatch();
    if(validationResponse == true){
        // Changing lineEdit border styles
        ui->authorReachableEmailAddress_lineEdit->setStyleSheet("border: 2px solid green;"
                                                                "background-color: rgb(255, 255, 255);");
        // Setting enteredReachableEmailAddressAcceptable to true
        enteredReachableEmailAddressAcceptable = true;
    }
    else if (validationResponse == false){
        // Changing lineEdit border styles
        ui->authorReachableEmailAddress_lineEdit->setStyleSheet("border: 2px solid red;"
                                                                "background-color: rgb(255, 255, 255);");
        // Setting enteredReachableEmailAddressAcceptable to false as the entered subject value is not acceptable
        enteredReachableEmailAddressAcceptable = false;
    }

    if(enteredSubjectValueAcceptable == true && enteredFeedbackValueAcceptable == true
            && enteredReachableEmailAddressAcceptable == true){
        // Enabling submit report push button
        ui->submitReport_pushButton->setEnabled(true);
    }
    else{
        // Disabling submit report push button
        ui->submitReport_pushButton->setEnabled(false);
    }

}

void ReportSubmissionWindow::on_submitReport_pushButton_clicked()
{

    QString enteredSubject = ui->subject_lineEdit->text();
    QString enteredFeedback = ui->feedback_textEdit->toPlainText();
    QString enteredAuthorReachableEmailAddress = ui->authorReachableEmailAddress_lineEdit->text();

    QString reportSubmissionStatus = accountLogic->submitReport(enteredSubject, enteredFeedback, enteredAuthorReachableEmailAddress);

    if(reportSubmissionStatus == "Report Submission Successful"){
        QMessageBox::information(this, "REPORT SUBMISSION SUCCESSFUL", "Report was successull submitted.");
    }
    else if(reportSubmissionStatus == "Execution Unsuccessful: Database Connection Error"){
        QMessageBox::critical(this, "REPORT SUBMISSION ERROR", "Database Connection has lost, please submit a report.");
    }
    else if(reportSubmissionStatus == "Execution Unsuccessful: SQL query execution error"){
        QMessageBox::critical(this, "REPORT SUBMISSION ERROR", "SQL query execution was unsuccessful, please submit a report including your email address.");
    }
    else if(reportSubmissionStatus == "default"){
        QMessageBox::critical(this, "REPORT SUBMISSION ERROR", "Please try again later");
    }

}




