#ifndef VIEWTERMSANDCONDITIONSDIALOG_H
#define VIEWTERMSANDCONDITIONSDIALOG_H

#include <QDialog>

namespace Ui {
class ViewTermsAndConditionsDialog;
}

class ViewTermsAndConditionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTermsAndConditionsDialog(QWidget *parent = nullptr);
    ~ViewTermsAndConditionsDialog();

private:
    Ui::ViewTermsAndConditionsDialog *ui;
};

#endif // VIEWTERMSANDCONDITIONSDIALOG_H
