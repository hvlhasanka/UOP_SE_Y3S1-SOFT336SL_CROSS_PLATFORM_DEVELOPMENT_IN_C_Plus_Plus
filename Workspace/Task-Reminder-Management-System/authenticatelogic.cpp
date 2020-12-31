/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#include "authenticatelogic.h"

// Public default constructor
AuthenticateLogic::AuthenticateLogic()
{
    databaseConnection = QSqlDatabase::addDatabase("QSQLITE", "trms_db");
    databaseConnection.setDatabaseName("C:/Users/Lucas.L.H.H/Documents/GitHub/UOP_SE_Y3S1-SOFT336SL_CROSS_PLATFORM_DEVELOPMENT_IN_C_Plus_Plus/Workspace/Database/trms_db.db");

    if(!databaseConnection.open()){
       qDebug() << "doesnot work";
    }

    if (databaseConnection.open()){
        qDebug() << databaseConnection.lastError();
    }
}

/* Setter Methods */

void AuthenticateLogic::setEmailAddress(string emailAddressValue){
    emailAddress = emailAddressValue;
}

void AuthenticateLogic::setPasswordHash(string passwordHashValue){
    passwordHash = passwordHashValue;
}

/* Function Methods */

bool AuthenticateLogic::validateEnteredEmailAddress(QString enteredEmailAddressValue){
    // Checking whether the entered email address is under the required regular expression
    QRegularExpression re("^[A-Za-z0-9_]+@[a-zA-Z_]+?.[a-zA-Z]{2,3}+");
    QRegularExpressionMatch validationCheck = re.match(enteredEmailAddressValue);
    bool validationResponse = validationCheck.hasMatch();
    return validationResponse;
}

bool AuthenticateLogic::validateEnteredPassword(QString enteredPasswordValue){
    // Checking whether the entered password is under the required regular expression
    // Password Guidelines:
    //  Minimum of seven (7) characters
    //  Maximum of twenty (20) characters
    //  Atleast one uppercase letter
    //  Atleast one lowercase letter
    //  Atleast one numeric character
    //  Atleast one special character
    QRegularExpression re("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#[\\$%[\\^&[\\*])(?=.{7,20})");
    QRegularExpressionMatch validationCheck = re.match(enteredPasswordValue);
    bool validationResponse = validationCheck.hasMatch();
    return validationResponse;
}

string AuthenticateLogic::generatePasswordHash(string passwordValue){
    // Declaring a new object
    hash<string> generateHash;
    // Generating the hash value from the passed passwordValue
    // (generateHash(passwordValue)) - returns a long value, this will be converted to a string
    std::string hashValue = std::to_string((generateHash(passwordValue)));
    // Returning the generated hash value to the called command
    return hashValue;
}

string AuthenticateLogic::loginCredentialVerification(string enteredEmailAddress, string enteredPasswordHash){

    QSqlQuery query(QSqlDatabase::database("trms_db"));

    query.prepare(QString("SELECT l.EmailAddress, l.PasswordHash, acts.AccountStatus, at.AccountType FROM "
                          "Login l INNER JOIN Account a ON l.LoginID = a.lLoginID "
                          "INNER JOIN AccountStatus acts ON acts.AccountStatusID = l.asAccountStatusID "
                          "INNER JOIN AccountType at ON at.AccountTypeID = a.atAccountTypeID "
                          "WHERE EmailAddress='mchatte@toplist.cz';"));

    if(!query.exec()){
        qDebug() << "jj";
    }

    int idName = query.record().indexOf("EmailAddress");
    while (query.next())
    {
       QString name = query.value(idName).toString();
       qDebug() << name;
    }

    databaseConnection.close();
    databaseConnection.removeDatabase(QSqlDatabase::defaultConnection);





  //  QSqlDatabase * db = new QSqlDatabase;
   // qDebug() << db->drivers();
}
