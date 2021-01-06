#include "viewtaskstandarduseraccountdialog.h"
#include "ui_viewtaskstandarduseraccountdialog.h"

ViewTaskStandardUserAccountDialog::ViewTaskStandardUserAccountDialog(int accountID, int taskID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTaskStandardUserAccountDialog)
{
    ui->setupUi(this);

    passedTaskID = taskID;

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of SetNewReminderStandardUserAccountDialog class
    setNewReminderStandardUserAccountDialogForm = new SetNewReminderStandardUserAccountDialog(passedTaskID, this);

    // Creating an object of EditTaskDetailsStandardUserAccountDialog class
    editTaskDetailsStandardUserAccountDialogForm = new EditTaskDetailsStandardUserAccountDialog(accountID, passedTaskID, this);

    // Creating an object of AccountLogic class
    account = new AccountLogic();

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

        taskDetailsQuery.bindValue(":taskID", passedTaskID);

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

void ViewTaskStandardUserAccountDialog::on_editTaskDetails_pushButton_clicked()
{

    editTaskDetailsStandardUserAccountDialogForm->show();

}

void ViewTaskStandardUserAccountDialog::on_removeTask_pushButton_clicked()
{

    QString removeTaskStatus = account->removeTask(passedTaskID);

    if(removeTaskStatus == "Task Removal Successful"){
        QMessageBox::information(this, "TASK REMOVED", "Task has been successfully removed.");
        this->hide();
    }
    else if(removeTaskStatus == "Execution Unsuccessful: Reminders are available for this task"){
        QMessageBox::critical(this, "TASK REMOVAL ERROR", "Unable to remove task due to connected reminders. Please remove the connected reminders and try again.");
    }
    else if(removeTaskStatus == "Execution Unsuccessful: SQL query execution error"){
        QMessageBox::critical(this, "ERROR", "SQL query execution error, please submit a report.\nApologies for the inconvenience.");
    }
    else if(removeTaskStatus == "Execution Unsuccessful: Database Connection Error"){
        QMessageBox::critical(this, "ERROR", "Database connectivity error, please submit a report.\nApologies for the inconvenience.");
    }

}
