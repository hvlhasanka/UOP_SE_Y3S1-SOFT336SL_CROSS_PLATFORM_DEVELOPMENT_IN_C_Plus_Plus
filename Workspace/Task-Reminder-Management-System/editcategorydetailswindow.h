#ifndef EDITCATEGORYDETAILSWINDOW_H
#define EDITCATEGORYDETAILSWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditCategoryDetailsWindow;
}

class EditCategoryDetailsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditCategoryDetailsWindow(QWidget *parent = nullptr);
    ~EditCategoryDetailsWindow();

private:
    Ui::EditCategoryDetailsWindow *ui;
};

#endif // EDITCATEGORYDETAILSWINDOW_H
