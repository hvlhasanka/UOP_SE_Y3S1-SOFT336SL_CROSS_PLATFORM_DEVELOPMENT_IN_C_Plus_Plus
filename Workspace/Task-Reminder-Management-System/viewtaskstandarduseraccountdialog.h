#ifndef VIEWTASKSTANDARDUSERACCOUNTDIALOG_H
#define VIEWTASKSTANDARDUSERACCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class ViewTaskStandardUserAccountDialog;
}

class ViewTaskStandardUserAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTaskStandardUserAccountDialog(QWidget *parent = nullptr);
    ~ViewTaskStandardUserAccountDialog();

private:
    Ui::ViewTaskStandardUserAccountDialog *ui;
};

#endif // VIEWTASKSTANDARDUSERACCOUNTDIALOG_H
