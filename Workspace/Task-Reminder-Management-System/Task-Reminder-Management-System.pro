QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountlogic.cpp \
    addnewtaskpremiumuseraccountwindow.cpp \
    addnewtaskstandarduseraccountwindow.cpp \
    adminaccountwindow.cpp \
    authenticatelogic.cpp \
    databaseconnection.cpp \
    main.cpp \
    loginwindow.cpp \
    premiumuseraccountlogic.cpp \
    reportsubmissionwindow.cpp \
    standarduseraccountlogic.cpp \
    useraccountwindow.cpp \
    userregistrationwindow.cpp

HEADERS += \
    accountlogic.h \
    addnewtaskpremiumuseraccountwindow.h \
    addnewtaskstandarduseraccountwindow.h \
    adminaccountwindow.h \
    authenticatelogic.h \
    databaseconnection.h \
    loginwindow.h \
    premiumuseraccountlogic.h \
    reportsubmissionwindow.h \
    standarduseraccountlogic.h \
    useraccountwindow.h \
    userregistrationwindow.h

FORMS += \
    adminaccountwindow.ui \
    addnewtaskpremiumuseraccountwindow.ui \
    addnewtaskstandarduseraccountwindow.ui \
    loginwindow.ui \
    reportsubmissionwindow.ui \
    useraccountwindow.ui \
    userregistrationwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
