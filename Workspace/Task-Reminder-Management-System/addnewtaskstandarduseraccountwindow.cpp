#include "addnewtaskstandarduseraccountwindow.h"
#include "ui_addnewtaskstandarduseraccountwindow.h"

AddNewTaskStandardUserAccountWindow::AddNewTaskStandardUserAccountWindow(int accountID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewTaskStandardUserAccountWindow)
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

    // Creating an object of StandardUserAccountLogic class
    standardUserAccountLogic = new StandardUserAccountLogic(accountID);

    /* Retrieving category values from the database and assigning it to category combobox */
    bool connectionStatus = trms_dbConnection->openDatebaseConnection();
    if(connectionStatus == true){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery categoryQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        categoryQuery.prepare(QString("SELECT CategoryName FROM Category WHERE aAccountID == :accountID;"));

        categoryQuery.bindValue(":accountID", accountID);

        // Executing sql query and checking the status
        if(!categoryQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << categoryQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
        }
        else{
            QSqlQueryModel *categoryModal = new QSqlQueryModel();
            categoryModal->setQuery(categoryQuery);
            ui->category_comboBox->setModel(categoryModal);
            trms_dbConnection->closeDatebaseConnection();
        }
    }
    else if(connectionStatus == false){
        qWarning() << "Database Connection Error";
    }

}

AddNewTaskStandardUserAccountWindow::~AddNewTaskStandardUserAccountWindow()
{
    delete ui;
}

void AddNewTaskStandardUserAccountWindow::on_addTask_pushButton_clicked()
{
    QString enteredTaskTitle = ui->title_lineEdit->text();
    QString enteredTaskDescription = ui->description_plainTextEdit->toPlainText();
    QString selectedCategoryName = ui->category_comboBox->currentText();

    QString addTaskStatus = standardUserAccountLogic->addNewTask(enteredTaskTitle, enteredTaskDescription, selectedCategoryName);

    if(addTaskStatus == "Execution Successful: Task successfully added"){
        QMessageBox::information(this, "NEW TASK ADDED", "New task has been successfully added");
        this->hide();
    }
    else if(addTaskStatus == "Execution Unsuccessful: (SQL Query Error) Failed to retrieve CategoryID from database"){
        QMessageBox::critical(this, "ERROR", "SQL query execution error, please submit a report.\nApologies for the inconvenience.");
    }
    else if(addTaskStatus == "Execution Unsuccessful: (SQL Query Error) Failed to Insert Task Record"){
        QMessageBox::critical(this, "ERROR", "SQL query execution error, please submit a report.\nApologies for the inconvenience.");
    }
    else if(addTaskStatus == "Execution Unsuccessful: Database Connection Error"){
        QMessageBox::critical(this, "ERROR", "Database connectivity error, please submit a report.\nApologies for the inconvenience.");
    }
}
