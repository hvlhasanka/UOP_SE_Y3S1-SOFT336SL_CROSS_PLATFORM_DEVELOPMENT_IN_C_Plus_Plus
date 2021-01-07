#ifndef VIEWCATEGORYDETAILSDIALOG_H
#define VIEWCATEGORYDETAILSDIALOG_H

#include <QDialog>

#include "databaseconnection.h"

namespace Ui {
class ViewCategoryDetailsDialog;
}

class ViewCategoryDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCategoryDetailsDialog(int accountID, QString categoryName, QWidget *parent = nullptr);
    ~ViewCategoryDetailsDialog();

private:
    Ui::ViewCategoryDetailsDialog *ui;
    // Connecting the databaseconnecion.h
    // Retireving the databaseconnecion.h class path to a pointer
    DatabaseConnection *trms_dbConnection;

};

#endif // VIEWCATEGORYDETAILSDIALOG_H
