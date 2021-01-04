#include "addnewtaskpremiumuseraccountwindow.h"
#include "ui_addnewtaskpremiumuseraccountwindow.h"

AddNewTaskPremiumUserAccountWindow::AddNewTaskPremiumUserAccountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewTaskPremiumUserAccountWindow)
{
    ui->setupUi(this);

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix(":/images/TRMS-Logo-Without-Text.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of AccountLogic class
    account = new AccountLogic();

    /* Retrieving category values from the database and assigning it to category combobox */
    bool connectionStatus = trms_dbConnection->openDatebaseConnection();
    if(connectionStatus == true){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery categoryQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        categoryQuery.prepare(QString("SELECT CategoryName FROM Category WHERE aAccountID == :accountID;"));

        categoryQuery.bindValue("accountID", account->getAccountID());

        // Executing sql query and checking the status
        if(!categoryQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << categoryQuery.lastError();
        }
        else{
            QSqlQueryModel *categoryModal = new QSqlQueryModel();
            categoryModal->setQuery(categoryQuery);
            ui->category_comboBox->setModel(categoryModal);
        }
    }
}

AddNewTaskPremiumUserAccountWindow::~AddNewTaskPremiumUserAccountWindow()
{
    delete ui;
}
