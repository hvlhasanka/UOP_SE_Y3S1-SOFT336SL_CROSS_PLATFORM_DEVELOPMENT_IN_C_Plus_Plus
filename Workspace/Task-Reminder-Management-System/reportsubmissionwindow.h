#ifndef REPORTSUBMISSIONWINDOW_H
#define REPORTSUBMISSIONWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QMessageBox>

#include "accountlogic.h"

namespace Ui {
class ReportSubmissionWindow;
}

class ReportSubmissionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReportSubmissionWindow(QWidget *parent = nullptr);
    ~ReportSubmissionWindow();
    bool enteredSubjectValueAcceptable;
    bool enteredFeedbackValueAcceptable;
    bool enteredReachableEmailAddressAcceptable;

private slots:
    void on_subject_lineEdit_textChanged(const QString &arg1);
    void on_feedback_textEdit_textChanged();
    void on_submitReport_pushButton_clicked();
    void on_authorReachableEmailAddress_lineEdit_textChanged(const QString &arg1);

private:
    Ui::ReportSubmissionWindow *ui;
    // Connecting the accountlogic.h
    // Retireving the accountlogic.h class path to a pointer
    AccountLogic *accountLogic;


};

#endif // REPORTSUBMISSIONWINDOW_H
