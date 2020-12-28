/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#include "authenticatelogic.h"

// Public default constructor
AuthenticateLogic::AuthenticateLogic()
{

}

/* Setter Methods */

void AuthenticateLogic::setEmailAddress(string emailAddressValue){
    emailAddress = emailAddressValue;
}

void AuthenticateLogic::setPasswordHash(string passwordHashValue){
    passwordHash = passwordHashValue;
}

/* Function Methods */

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



}
