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

