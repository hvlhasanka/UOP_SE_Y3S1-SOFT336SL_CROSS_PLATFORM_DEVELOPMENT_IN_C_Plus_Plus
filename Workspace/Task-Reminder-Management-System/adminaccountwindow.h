#ifndef ADMINACCOUNTWINDOW_H
#define ADMINACCOUNTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminAccountWindow;
}

class AdminAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminAccountWindow(QWidget *parent = nullptr);
    ~AdminAccountWindow();

private:
    Ui::AdminAccountWindow *ui;
};

#endif // ADMINACCOUNTWINDOW_H
