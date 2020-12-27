/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#ifndef AUTHENTICATELOGIC_H
#define AUTHENTICATELOGIC_H

#include <string>
#include <regex>
#include <QDebug>

using namespace std;

class AuthenticateLogic
{
public:
    // Default constructor
    AuthenticateLogic();
    // Setter Methods
    void setEmailAddress(string emailAddressValue);
    void setPasswordHash(string passwordHashValue);
    // Function Methods


private:
    // Private string variables
    string emailAddress;
    string passwordHash;
    // Private methods


};

#endif // AUTHENTICATELOGIC_H
