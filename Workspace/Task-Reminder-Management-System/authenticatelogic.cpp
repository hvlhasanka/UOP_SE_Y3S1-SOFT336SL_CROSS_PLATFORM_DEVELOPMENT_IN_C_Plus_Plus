/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#include "authenticatelogic.h"

// Public default constructor
AuthenticateLogic::AuthenticateLogic()
{
    // Creating an object of DatabaseConnection class
    trms_dbConnection = new DatabaseConnection;
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

QString AuthenticateLogic::loginCredentialVerification(QString enteredEmailAddress, QString generatedPasswordHash){

    QString passwordHashDB;
    QString accountStatusDB;
    QString accountTypeDB;

    /* Retrieving the password hash, account status, and account type from the database */

    // Opening database connection
    bool databaseConnection = trms_dbConnection->openDatebaseConnection();

    if(databaseConnection){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery vertificationQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        vertificationQuery.prepare(QString("SELECT l.PasswordHash, acts.AccountStatus, at.AccountType FROM "
                              "Login l INNER JOIN Account a ON l.LoginID = a.lLoginID "
                              "INNER JOIN AccountStatus acts ON acts.AccountStatusID = l.asAccountStatusID "
                              "INNER JOIN AccountType at ON at.AccountTypeID = a.atAccountTypeID "
                              "WHERE EmailAddress=:enteredEmailAddress;"));

        vertificationQuery.bindValue(":enteredEmailAddress", enteredEmailAddress);

        // Executing sql query and checking the status
        if(!vertificationQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << vertificationQuery.lastError();
            return "Verification Unsuccessful: SQL query execution error";
        }
        else{
            while (vertificationQuery.next())
            {
               passwordHashDB = vertificationQuery.value(0).toString();
               accountStatusDB = vertificationQuery.value(1).toString();
               accountTypeDB = vertificationQuery.value(2).toString();
            }
        }
    }
    else{
        qDebug() << "Database Connection Error";
        return "Verification Unsuccessful: Database Connection Error";
    }

    // Closing database connection
    trms_dbConnection->closeDatebaseConnection();


    /* Checking whether the password hash value match */
    if(generatedPasswordHash == passwordHashDB){

        /* Checking account status of the user */
        if(accountStatusDB == "Active"){

            /* Checking account type of the user */
            if(accountTypeDB == "StandardUserAccount" || accountTypeDB == "PremiumUserAccount"){
                return "Verification Successful: Account Type: UserAccount";
            }
            else if(accountTypeDB == "AdminAccount"){
                return "Verification Successful: Account Type: AdminAccount";
            }
        }
        else if(accountStatusDB == "Disabled"){
            return "Verification Unsuccessful: Account Disabled";
        }

    }
    else if(generatedPasswordHash != passwordHashDB){
        return "Verification Unsuccessful: Password Incorrect";
    }

    return "default";
}
