#include "edittaskdetailsstandarduseraccountdialog.h"
#include "ui_edittaskdetailsstandarduseraccountdialog.h"

EditTaskDetailsStandardUserAccountDialog::EditTaskDetailsStandardUserAccountDialog(int accountID, int taskID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTaskDetailsStandardUserAccountDialog)
{
    ui->setupUi(this);

    passedTaskID = taskID;

    passedAccountID = accountID;

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of StandardUserAccountLogic class
    standardUserAccountLogic = new StandardUserAccountLogic();

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix(":/images/TRMS-Logo-Without-Text.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));


    /* Retrieving the task details from the database using the passed taskID */
    bool databaseConnectionStatus = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectionStatus == true){

        /* Retrieving the category names from the database for the accountID */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery categoryQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        categoryQuery.prepare(QString("SELECT CategoryName FROM Category WHERE aAccountID == :accountID;"));

        categoryQuery.bindValue(":accountID", accountID);

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


        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery taskDetailsQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        taskDetailsQuery.prepare(QString("SELECT t.Title, t.TaskDescription, c.CategoryName, t.CreatedDateTime, t.LastEditDateTime FROM "
                                         "Task t INNER JOIN Category c ON c.CategoryID = t.cCategoryID "
                                         "WHERE TaskID = :taskID"));

        taskDetailsQuery.bindValue(":taskID", passedTaskID);

        // Executing sql query and checking the status
        if(!taskDetailsQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << taskDetailsQuery.lastError();
        }
        else{
            if(taskDetailsQuery.next()){
                ui->title_lineEdit->setText(taskDetailsQuery.value(0).toString());
                ui->description_plainTextEdit->setPlainText(taskDetailsQuery.value(1).toString());
                for(int i = 0; i > ui->category_comboBox->count(); i++){
                    if(ui->category_comboBox->itemText(i) == taskDetailsQuery.value(2)){
                        ui->category_comboBox->setCurrentIndex(i);
                    }
                }
                ui->taskCreatedDateTime_label->setText(taskDetailsQuery.value(3).toString());
                ui->taskLastEditedDateTime_label->setText(taskDetailsQuery.value(4).toString());
            }
        }

    }
    else if(databaseConnectionStatus == false){
        qWarning() << "Database Connection Error";
    }
    trms_dbConnection->closeDatebaseConnection();


}

EditTaskDetailsStandardUserAccountDialog::~EditTaskDetailsStandardUserAccountDialog()
{
    delete ui;
}

void EditTaskDetailsStandardUserAccountDialog::on_editTask_pushButton_clicked()
{

    QString enteredTaskTitle = ui->title_lineEdit->text();
    QString enteredTaskDescription = ui->description_plainTextEdit->toPlainText();
    QString selectedCategory = ui->category_comboBox->currentText();

    QString updateTaskDetailsStatus = standardUserAccountLogic->editTaskDetails(passedAccountID, passedTaskID, enteredTaskTitle, enteredTaskDescription, selectedCategory);

    if(updateTaskDetailsStatus == "Execution Successful: Task Details Successfully Updated"){
        QMessageBox::information(this, "TASK DETAILS UPDATED", "Task details successfully updated. Please re-enter task ID and click on 'Show Task Details' button to view updated details.");
        this->hide();
    }
    else if(updateTaskDetailsStatus == "Execution Unsuccessful: (SQL Query Error)"){
        QMessageBox::critical(this, "ERROR", "SQL query execution error, please submit a report.\nApologies for the inconvenience.");
    }
    else if(updateTaskDetailsStatus == "Execution Unsuccessful: Database Connection Error"){
        QMessageBox::critical(this, "ERROR", "Database connectivity error, please submit a report.\nApologies for the inconvenience.");
    }

}
