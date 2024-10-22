/***********************************************
**
**  Source Code Developed By: H.V.L.Hasanka
**
***********************************************/

#include "loginwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Splash Screen and Opening Login Screen Source Code */
    // Assign image of splash screen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/Splash-Screen.jpg"));
    splash->show();
    // Setting timer of splash screen

    // Declaration of an object of LoginWindow class
    LoginWindow LoginScreen;

    // Setting timer for splash screen to close after 2 seconds
    QTimer::singleShot(2000, splash, SLOT(close()));

    // Setting timer for login screen to show after 2 seconds
    QTimer::singleShot(2000, &LoginScreen, SLOT(show()));

    //LoginScreen.show();
    return a.exec();
}
