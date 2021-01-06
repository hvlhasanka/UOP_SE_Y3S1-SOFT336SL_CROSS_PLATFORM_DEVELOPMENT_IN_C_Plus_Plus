#include "viewcategorydetailsdialog.h"
#include "ui_viewcategorydetailsdialog.h"

ViewCategoryDetailsDialog::ViewCategoryDetailsDialog(int accountID, QString categoryName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCategoryDetailsDialog)
{
    ui->setupUi(this);

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    bool databaseConnection = trms_dbConnection->openDatebaseConnection();
    if(databaseConnection == true){

        /* Retrieving the category ID from the database */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery categoryIDDBQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        categoryIDDBQuery.prepare(QString("SELECT CategoryID FROM Category WHERE CategoryName = :categoryName AND aAccountID = :accountID"));

        categoryIDDBQuery.bindValue(":categoryName", categoryName);
        categoryIDDBQuery.bindValue(":accountID", accountID);

        // Executing sql query and checking the status
        if(!categoryIDDBQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << categoryIDDBQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
        }
        else{
            if(categoryIDDBQuery.next()){

                /* Retrieving the category details from the database */
                // Declaring new QSqlQuery object by passing the database name
                QSqlQuery categoryDetailsQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

                // Preparing sql query for execution
                categoryDetailsQuery.prepare(QString("SELECT c.CategoryName, c.CategoryDescription, ct.CategoryType, cc.HexColourCode FROM "
                                              "Category c INNER JOIN CategoryType ct ON ct.CategoryTypeID = c.ctCategoryTypeID "
                                              "INNER JOIN CategoryColour cc ON cc.ColourID = c.ccColourID "
                                              "WHERE CategoryID = :categoryID;"));

                categoryDetailsQuery.bindValue(":categoryID", categoryIDDBQuery.value(0).toInt());

                // Executing sql query and checking the status
                if(!categoryDetailsQuery.exec()){
                    qWarning() << "SQL query execution error";
                    qWarning() << categoryDetailsQuery.lastError();
                    trms_dbConnection->closeDatebaseConnection();
                }
                else{
                    if(categoryDetailsQuery.next()){
                        ui->categoryTitle_label->setText(categoryDetailsQuery.value(0).toString());
                        ui->categoryDescription_plainTextEdit->setPlainText(categoryDetailsQuery.value(1).toString());
                        ui->categoryTypeText_label->setText(categoryDetailsQuery.value(2).toString());
                        ui->color_label->setStyleSheet("background-color: '"+ categoryDetailsQuery.value(3).toString() +"'");
                    }
                    trms_dbConnection->closeDatebaseConnection();
                }

            }
            trms_dbConnection->closeDatebaseConnection();
        }



    }
    else{
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
    }

}

ViewCategoryDetailsDialog::~ViewCategoryDetailsDialog()
{
    delete ui;
}
