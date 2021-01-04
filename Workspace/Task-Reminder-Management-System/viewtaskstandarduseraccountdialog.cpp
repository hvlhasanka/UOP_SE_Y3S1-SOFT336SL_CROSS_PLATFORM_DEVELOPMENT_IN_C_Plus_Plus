#include "viewtaskstandarduseraccountdialog.h"
#include "ui_viewtaskstandarduseraccountdialog.h"

ViewTaskStandardUserAccountDialog::ViewTaskStandardUserAccountDialog(int taskID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTaskStandardUserAccountDialog)
{
    ui->setupUi(this);


    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of SetNewReminderStandardUserAccountDialog class
    setNewReminderStandardUserAccountDialogForm = new SetNewReminderStandardUserAccountDialog(taskID);

    /* Retrieving the relevant details from the database */
    bool databaseConnection = trms_dbConnection->openDatebaseConnection();

    if(databaseConnection == true){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery taskDetailsQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        taskDetailsQuery.prepare(QString("SELECT t.Title, t.TaskDescription, cc.HexColourCode, c.CategoryName, t.createdDateTime, t.lastEditDateTime FROM "
                                         "Task t INNER JOIN Category c ON t.cCategoryID = c.CategoryID "
                                         "INNER JOIN CategoryColour cc ON cc.ColourID = c.ccColourID "
                                         "WHERE t.TaskID = :taskID;"));

        taskDetailsQuery.bindValue(":taskID", taskID);

        // Executing sql query and checking the status
        if(!taskDetailsQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << taskDetailsQuery.lastError();
            trms_dbConnection->closeDatebaseConnection();
        }
        else{
            if(taskDetailsQuery.next()){
                ui->taskTitle_label->setText(taskDetailsQuery.value(0).toString());
                ui->taskDescription_plainTextEdit->setPlainText(taskDetailsQuery.value(1).toString());
                ui->color_label->setStyleSheet("background-color: '"+ taskDetailsQuery.value(2).toString() +"'");
                ui->categoryName_label->setText(taskDetailsQuery.value(3).toString());
                ui->taskCreatedDateTime_label->setText(taskDetailsQuery.value(4).toString());
                ui->taskLastEditedDateTime_label->setText(taskDetailsQuery.value(5).toString());
            }
            else{
                qWarning() << "Task Details Successfully retrieved from Database";
            }
            trms_dbConnection->closeDatebaseConnection();
        }
    }
    else{
        qWarning() << "Database Connection Error";
        trms_dbConnection->closeDatebaseConnection();
    }


}

ViewTaskStandardUserAccountDialog::~ViewTaskStandardUserAccountDialog()
{
    delete ui;
}

void ViewTaskStandardUserAccountDialog::on_setReminder_pushButton_clicked()
{

    setNewReminderStandardUserAccountDialogForm->show();

}
