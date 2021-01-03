#ifndef USERACCOUNTWINDOW_H
#define USERACCOUNTWINDOW_H

#include <QMainWindow>

#include "authenticatelogic.h"

#include "reportsubmissionwindow.h"

namespace Ui {
class UserAccountWindow;
}

class UserAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserAccountWindow(QWidget *parent = nullptr);
    ~UserAccountWindow();

private:
    Ui::UserAccountWindow *ui;
    // Connecting the authenticatelogic.h
    // Retireving the authenticatelogic.h class path to a pointer
    AuthenticateLogic *auth;
    // Connecting the addnewtaskpremiumuseraccountwindow.h
    // Retireving the addnewtaskpremiumuseraccountwindow.h class path to a pointer
    ReportSubmissionWindow *reportSubmissionWindow;

};

#endif // USERACCOUNTWINDOW_H
