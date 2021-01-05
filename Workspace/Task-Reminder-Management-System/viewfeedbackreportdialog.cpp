#include "viewfeedbackreportdialog.h"
#include "ui_viewfeedbackreportdialog.h"

ViewFeedbackReportDialog::ViewFeedbackReportDialog(int reportID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewFeedbackReportDialog)
{
    ui->setupUi(this);

    passedReportID = reportID;

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of AdminAccountLogic class
    adminAccountLogic = new AdminAccountLogic();

    /* Retrieving report details from the database and assigning it to the user interface */
    bool databaseConnected = trms_dbConnection->openDatebaseConnection();
    if(databaseConnected == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reportQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        reportQuery.prepare(QString("SELECT ReportSubject, Feedback, AuthorReachableEmailAddress, SubmittedDateTime FROM "
                                    "Report WHERE ReportID = :reportID;"));

        reportQuery.bindValue(":reportID", passedReportID);

        // Executing sql query and checking the status
        if(!reportQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << reportQuery.lastError();
        }
        else{
            if(reportQuery.next()){
                ui->reportSubject_label->setText(reportQuery.value(0).toString());
                ui->reportFeedback_plainTextEdit->setPlainText(reportQuery.value(1).toString());
                if(reportQuery.value(2).toString().length() != 0){
                    ui->reachableEmailAddressText_label->setText(reportQuery.value(2).toString());
                }
                else{
                    ui->reachableEmailAddress_label->setVisible(false);
                    ui->reachableEmailAddressText_label->setVisible(false);
                }
                ui->reportSubmittedDateTime_label->setText(reportQuery.value(3).toString());
            }
        }
        trms_dbConnection->closeDatebaseConnection();
    }
    else if(databaseConnected == false){
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
    }

}

ViewFeedbackReportDialog::~ViewFeedbackReportDialog()
{
    delete ui;
}

void ViewFeedbackReportDialog::on_reviewed_pushButton_clicked()
{

    QString updateFeedbackReportStatus = adminAccountLogic->updateFeedbackReportStatusToReviewed(passedReportID);

    if(updateFeedbackReportStatus == "Report Status Successfully Updated"){
        QMessageBox::information(this, "Report Review Status Updated", "Feedback report status has been updated to reviewed.");
        this->hide();
    }
    else if(updateFeedbackReportStatus == "Execution Unsuccessful: (SQL Query Error)"){
        QMessageBox::critical(this, "ERROR", "SQL query execution error");
    }
    else if(updateFeedbackReportStatus == "Execution Unsuccessful: Database Connection Error"){
        QMessageBox::critical(this, "ERROR", "Database connectivity error");
    }

}
