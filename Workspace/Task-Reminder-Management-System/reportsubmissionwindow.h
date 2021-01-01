#ifndef REPORTSUBMISSIONWINDOW_H
#define REPORTSUBMISSIONWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>

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

private slots:
    void on_subject_lineEdit_textChanged(const QString &arg1);
    void on_feedback_textEdit_textChanged();

private:
    Ui::ReportSubmissionWindow *ui;

};

#endif // REPORTSUBMISSIONWINDOW_H
