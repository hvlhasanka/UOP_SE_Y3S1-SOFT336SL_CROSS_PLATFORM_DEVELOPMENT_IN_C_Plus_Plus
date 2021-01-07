#include "setnewreminderstandarduseraccountdialog.h"
#include "ui_setnewreminderstandarduseraccountdialog.h"

SetNewReminderStandardUserAccountDialog::SetNewReminderStandardUserAccountDialog(int taskID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetNewReminderStandardUserAccountDialog)
{
    ui->setupUi(this);

    passedTaskID = taskID;

    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection();

    // Creating an object of StandardUserAccountLogic class
    standardUserAccountLogic = new StandardUserAccountLogic();

    /* Logo Image Implementation Source Code */
    // Getting the logo image
    QPixmap logoImagePix(":/images/TRMS-Logo-WithBackground.jpg");
    // Getting the width of the logo_label
    int logoLabelWidth = ui->logo_label->width();
    // Getting the height of the logo_label
    int logoLabelHeight = ui->logo_label->height();
    // Setting the cover image of the logo_label
    ui->logo_label->setPixmap(logoImagePix.scaled(logoLabelWidth, logoLabelHeight, Qt::KeepAspectRatio));

    /* Getting the current datetime timestamp from the localhost */
    QDateTime currentDateTimeTimeStamp = QDateTime::currentDateTime();

    ui->reminderDateTime_dateTimeEdit->setDateTime(currentDateTimeTimeStamp);

}

SetNewReminderStandardUserAccountDialog::~SetNewReminderStandardUserAccountDialog()
{
    delete ui;
}

void SetNewReminderStandardUserAccountDialog::on_setReminder_pushButton_clicked()
{

    // Getting the user selected reminder date time
    QDateTime reminderDateTimeTimeStamp = ui->reminderDateTime_dateTimeEdit->dateTime();
    // Reformatting datetime timestamp
    QString reminderDateTime = reminderDateTimeTimeStamp.toString("yyyy-MM-dd hh:mm:ss");

    QString setReminderStatus = standardUserAccountLogic->setNewReminder(passedTaskID, reminderDateTime);

    if(setReminderStatus == "Execution Successful: Reminder successfully added"){
        QMessageBox::information(this, "NEW Reminder is Placed", "New task has been successfully added");
        this->hide();
    }
    else if(setReminderStatus == "Execution Unsuccessful: (SQL Query Error) Failed to Insert Task Record"){
        QMessageBox::critical(this, "ERROR", "SQL query execution error, please submit a report.\nApologies for the inconvenience.");
    }
    else if(setReminderStatus == "Execution Unsuccessful: Database Connection Error"){
        QMessageBox::critical(this, "ERROR", "Database connectivity error, please submit a report.\nApologies for the inconvenience.");
    }

}
