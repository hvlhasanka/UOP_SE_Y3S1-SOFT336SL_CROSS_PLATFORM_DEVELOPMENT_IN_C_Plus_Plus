#include "databaseconnection.h"

DatabaseConnection::DatabaseConnection()
{
    this->setDatabaseName();
    this->setDatabaseDBFilePath();
}

/* Setter Methods */

void DatabaseConnection::setDatabaseName(){
    databaseName = "trms_db";
}

void DatabaseConnection::setDatabaseDBFilePath(){
    databaseDBFilePath = ":/database/assets/database/trms_db.db";
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
    databaseConnection = QSqlDatabase::addDatabase("QSQLITE", databaseName);
    databaseConnection.setDatabaseName(databaseDBFilePath);

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
