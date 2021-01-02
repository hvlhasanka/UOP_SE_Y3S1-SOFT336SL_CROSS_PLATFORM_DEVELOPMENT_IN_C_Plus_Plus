#include "databaseconnection.h"

DatabaseConnection::DatabaseConnection()
{
    this->setDatabaseName("trms_db");
    this->setDatabaseDBFilePath("C:/Users/Lucas.L.H.H/Documents/GitHub/UOP_SE_Y3S1-SOFT336SL_CROSS_PLATFORM_DEVELOPMENT_IN_C_Plus_Plus/Workspace/Task-Reminder-Management-System/database/trms_db.db");
}

/* Setter Methods */

void DatabaseConnection::setDatabaseName(QString databaseName){
    this->databaseName = databaseName;
}

void DatabaseConnection::setDatabaseDBFilePath(QString databaseDBFilePath){
    this->databaseDBFilePath = databaseDBFilePath;
}

/* Getter Methods */

QString DatabaseConnection::getDatabaseName(){
    return databaseName;
}

QString DatabaseConnection::getDatabaseDBFilePath(){
    return databaseDBFilePath;
}

/* Function Methods */
// Function to open database connection
bool DatabaseConnection::openDatebaseConnection(){

    // Assigning database configuration
    databaseConnection = QSqlDatabase::addDatabase("QSQLITE", this->databaseName);
    databaseConnection.setDatabaseName(this->databaseDBFilePath);

    // Establishing database connection and checking connection status
    if (!databaseConnection.open()){
        qDebug() << "Database Connection Error";
        qDebug() << databaseConnection.lastError();
        return false;
    }
    else{
        qDebug() << "Database Connection Open";
        return true;
    }

}

// Function to close database connection
void DatabaseConnection::closeDatebaseConnection(){

    // Closing established database connection
    databaseConnection.close();
    databaseConnection.removeDatabase(QSqlDatabase::defaultConnection);
    qDebug() << "Database Connection Closed";

}
