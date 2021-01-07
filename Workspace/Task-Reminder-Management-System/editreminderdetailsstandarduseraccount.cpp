#include "editreminderdetailsstandarduseraccount.h"
#include "ui_editreminderdetailsstandarduseraccount.h"

EditReminderDetailsStandardUserAccount::EditReminderDetailsStandardUserAccount(int reminderID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditReminderDetailsStandardUserAccount)
{
    ui->setupUi(this);

    passedReminderID = reminderID;

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix(":/images/TRMS-Logo-Without-Text.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));

    /* Getting reminderDatetime from the database */
    /* Retrieving data from database to show statictcs in the dashboard tab */
    bool databaseConnectionStatus = trms_dbConnection->openDatebaseConnection();
    if(databaseConnectionStatus == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery reminderDateTimeQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        reminderDateTimeQuery.prepare(QString("SELECT ReminderDateTime FROM Reminder WHERE ReminderID = :reminderID;"));

        reminderDateTimeQuery.bindValue(":reminderID", passedReminderID);

        // Executing sql query and checking the status
        if(!reminderDateTimeQuery.exec()){
            qWarning() << "SQL query execution error";
            qWarning() << reminderDateTimeQuery.lastError();
        }
        else{
            if(reminderDateTimeQuery.next()){
                ui->reminderDateTime_dateTimeEdit->setDateTime(QDateTime::fromString(reminderDateTimeQuery.value(0).toString()));
            }
        }
    }
    else if(databaseConnectionStatus == false){
        qWarning() << "Database Connection Error";
    }
    trms_dbConnection->closeDatebaseConnection();

}

EditReminderDetailsStandardUserAccount::~EditReminderDetailsStandardUserAccount()
{
    delete ui;
}

void EditReminderDetailsStandardUserAccount::on_setReminder_pushButton_clicked()
{

}
