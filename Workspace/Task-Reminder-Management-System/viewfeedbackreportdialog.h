#ifndef VIEWFEEDBACKREPORTDIALOG_H
#define VIEWFEEDBACKREPORTDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "databaseconnection.h"
#include "adminaccountlogic.h"

namespace Ui {
class ViewFeedbackReportDialog;
}

class ViewFeedbackReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewFeedbackReportDialog(int reportID, QWidget *parent = nullptr);
    ~ViewFeedbackReportDialog();

private slots:
    void on_reviewed_pushButton_clicked();

private:
    int passedReportID;
    Ui::ViewFeedbackReportDialog *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;
    // Connecting the adminaccountlogic.h
    // Retireving the adminaccountlogic.h class path to a pointer
    AdminAccountLogic *adminAccountLogic;

};

#endif // VIEWFEEDBACKREPORTDIALOG_H
