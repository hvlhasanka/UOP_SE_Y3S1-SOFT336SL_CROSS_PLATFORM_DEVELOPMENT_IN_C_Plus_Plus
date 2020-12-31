#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QtSql>

using namespace std;

class DatabaseConnection
{
public:
    // Default constructor
    DatabaseConnection();
    // Function Methods
    bool openDatebaseConnection();
    void closeDatebaseConnection();
    // Setter Methods
    void setDatabaseName();
    void setDatabaseDBFilePath();
    // Getter Methods
    QString getDatabaseName();
    QString getDatabaseDBFilePath();

private:
    // Object Declaration
    QSqlDatabase databaseConnection;
    // Public variables declaration
    QString databaseName;
    QString databaseDBFilePath;
};

#endif // DATABASECONNECTION_H
