#include "editcategorydetailswindow.h"
#include "ui_editcategorydetailswindow.h"

EditCategoryDetailsWindow::EditCategoryDetailsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditCategoryDetailsWindow)
{
    ui->setupUi(this);
}

EditCategoryDetailsWindow::~EditCategoryDetailsWindow()
{
    delete ui;
}
