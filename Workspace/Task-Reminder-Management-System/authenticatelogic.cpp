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
    trms_dbConnection = new DatabaseConnection();
}

/* Setter Methods */

void AuthenticateLogic::setEmailAddress(QString emailAddressValue){
    emailAddress = emailAddressValue;
}

void AuthenticateLogic::setPasswordHash(QString passwordHashValue){
    generatedPasswordHash = passwordHashValue;
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

QString AuthenticateLogic::loginCredentialVerification(){

    QString passwordHashDB;
    QString accountStatusDB;
    QString accountTypeDB;

    /* Retrieving the password hash, account status, and account type from the database */

    // Opening database connection
    bool databaseConnection = trms_dbConnection->openDatebaseConnection();

    if(databaseConnection == true){
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery vertificationQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        vertificationQuery.prepare(QString("SELECT l.PasswordHash, acts.AccountStatus, at.AccountType FROM "
                              "Login l INNER JOIN Account a ON l.LoginID = a.lLoginID "
                              "INNER JOIN AccountStatus acts ON acts.AccountStatusID = l.asAccountStatusID "
                              "INNER JOIN AccountType at ON at.AccountTypeID = a.atAccountTypeID "
                              "WHERE EmailAddress=:enteredEmailAddress;"));

        vertificationQuery.bindValue(":enteredEmailAddress", emailAddress);

        // Executing sql query and checking the status
        if(!vertificationQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << vertificationQuery.lastError();
            return "Verification Unsuccessful: SQL query execution error";
        }
        else{
            if(vertificationQuery.next()){
               passwordHashDB = vertificationQuery.value(0).toString();
               accountStatusDB = vertificationQuery.value(1).toString();
               accountTypeDB = vertificationQuery.value(2).toString();
            }
            else{
                return "Verification Unsuccessful: No Account Available with Entered Email Address";
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
            if(accountTypeDB == "Standard User Account" || accountTypeDB == "Premium User Account"){
                return "Verification Successful: Account Type: UserAccount";
            }
            else if(accountTypeDB == "Admin Account"){
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


QString AuthenticateLogic::checkEmailAddressAvailability(QString enteredEmailAddress){
    bool databaseConnection = trms_dbConnection->openDatebaseConnection();
    if(databaseConnection == true){

        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery emailAddressAvailabilityQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        emailAddressAvailabilityQuery.prepare(QString("SELECT * FROM Login WHERE EmailAddress=:enteredEmailAddress;"));

        emailAddressAvailabilityQuery.bindValue(":enteredEmailAddress", enteredEmailAddress);

        // Executing sql query and checking the status
        if(!emailAddressAvailabilityQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << emailAddressAvailabilityQuery.lastError();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            if(emailAddressAvailabilityQuery.next()){
                return "Account Available with Entered Email Address";
             }
            else{
                return "Account Unavailable with Entered Email Address";
            }
        }

    }
    else if(databaseConnection == false){
        qDebug() << "Database Connection Error";
        return "Execution Unsuccessful: Database Connection Error";
    }
    trms_dbConnection->closeDatebaseConnection();
    return "default";
}


QString AuthenticateLogic::registerNewUser(QString enteredFirstName, QString enteredMiddleName,
                                           QString enteredLastName, QString enteredEmailAddress,
                                           QString generatedConfirmPasswordHash, QString selectedAccountType){

    bool databaseConnection = trms_dbConnection->openDatebaseConnection();
    if(databaseConnection == true){

        int successfulQueryExecutions = 0;

        /* Inserting record into the 'Login' relation (table)  */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery loginQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        loginQuery.prepare(QString("INSERT INTO Login(EmailAddress, PasswordHash, asAccountStatusID) VALUES "
                                              "(:enteredEmailAddress, :generatedConfirmPasswordHash, 1);"));

        loginQuery.bindValue(":enteredEmailAddress", enteredEmailAddress);
        loginQuery.bindValue(":generatedConfirmPasswordHash", generatedConfirmPasswordHash);

        // Executing sql query and checking the status
        if(!loginQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << loginQuery.lastError();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            successfulQueryExecutions++;
        }

        /* Retrieving the 'LoginID' from the 'Login' relation (table) of the newly added record */
        QString loginIDDB;
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery loginIDQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        loginIDQuery.prepare(QString("SELECT LoginID FROM Login WHERE EmailAddress=:enteredEmailAddress;"));

        loginIDQuery.bindValue(":enteredEmailAddress", enteredEmailAddress);

        // Executing sql query and checking the status
        if(!loginIDQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << loginIDQuery.lastError();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            if(loginIDQuery.next()){
                loginIDDB = loginIDQuery.value(0).toString();
            }
            successfulQueryExecutions++;
        }

        /* Retrieving the 'AccountTypeID' from the 'AccountType' relation (table) for the user selected account type */
        QString accountTypeIDDB;
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery accountTypeIDQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        accountTypeIDQuery.prepare(QString("SELECT AccountTypeID FROM AccountType WHERE AccountType=:selectedAccountType"));

        accountTypeIDQuery.bindValue(":selectedAccountType", selectedAccountType);

        // Executing sql query and checking the status
        if(!accountTypeIDQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << accountTypeIDQuery.lastError();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            if(accountTypeIDQuery.next()){
                accountTypeIDDB = accountTypeIDQuery.value(0).toString();
            }
            successfulQueryExecutions++;
        }

        /* Inserting record into the 'Account' relation (table)  */
        // Declaring new QSqlQuery object by passing the database name
        QSqlQuery accountQuery(QSqlDatabase::database(trms_dbConnection->getDatabaseName()));

        // Preparing sql query for execution
        accountQuery.prepare(QString("INSERT INTO Account(FirstName, MiddleName, LastName, atAccountTypeID, dvDoNotDistrubBooleanValueID, lLoginID) VALUES "
                                              "(:enteredFirstName, :enteredMiddleName, :enteredLastName, :selectedAccountTypeID, 2, :generatedLoginID);"));

        accountQuery.bindValue(":enteredFirstName", enteredFirstName);
        accountQuery.bindValue(":enteredMiddleName", enteredMiddleName);
        accountQuery.bindValue(":enteredLastName", enteredLastName);
        accountQuery.bindValue(":selectedAccountTypeID", accountTypeIDDB);
        accountQuery.bindValue(":generatedLoginID", loginIDDB);

        // Executing sql query and checking the status
        if(!accountQuery.exec()){
            qDebug() << "SQL query execution error";
            qDebug() << accountQuery.lastError();
            return "Execution Unsuccessful: SQL query execution error";
        }
        else{
            successfulQueryExecutions++;
        }

        if(successfulQueryExecutions == 4){
            return "New Account Successfully Created";
        }
        else{
            return "New Account Creation Error";
        }

    }
    else if(databaseConnection == false){
        qDebug() << "Database Connection Error";
        return "Execution Unsuccessful: Database Connection Error";
    }

    trms_dbConnection->closeDatebaseConnection();
    return "default";
}
