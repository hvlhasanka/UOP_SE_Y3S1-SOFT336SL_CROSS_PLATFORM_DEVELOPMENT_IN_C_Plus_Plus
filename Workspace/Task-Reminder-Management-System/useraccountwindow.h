#ifndef USERACCOUNTWINDOW_H
#define USERACCOUNTWINDOW_H

#include <QMainWindow>

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
};

#endif // USERACCOUNTWINDOW_H
