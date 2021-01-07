#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QtSql>

using namespace std;

class DatabaseConnection
{
public:
    // Default constructor
    DatabaseConnection();
    // Setter Methods
    void setDatabaseName(QString databaseName);
    void setDatabaseDBFilePath(QString databaseDBFilePath);
    // Getter Methods
    QString getDatabaseName();
    QString getDatabaseDBFilePath();
    // Function Methods
    bool openDatebaseConnection();
    void closeDatebaseConnection();

private:
    // Public variables declaration
    QString databaseName;
    QString databaseDBFilePath;
    // Object Declaration
    QSqlDatabase databaseConnection;

};

#endif // DATABASECONNECTION_H
