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
    QRegularExpression re("^[A-z]+$");
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

    if(enteredSubjectValueAcceptable == true && enteredFeedbackValueAcceptable == true){
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
    QString enteredFeedback = ui->feedback_textEdit.text();
    QRegularExpression re("^[A-z]+$");
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

    if(enteredSubjectValueAcceptable == true && enteredFeedbackValueAcceptable == true){
        // Enabling submit report push button
        ui->feedback_textEdit->setEnabled(true);
    }
    else{
        // Disabling submit report push button
        ui->feedback_textEdit->setEnabled(false);
    }

}
