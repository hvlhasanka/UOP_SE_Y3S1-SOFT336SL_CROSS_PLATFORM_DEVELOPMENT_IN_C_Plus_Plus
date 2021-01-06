QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    accountlogic.cpp \
    addnewtaskpremiumuseraccountwindow.cpp \
    addnewtaskstandarduseraccountwindow.cpp \
    adminaccountlogic.cpp \
    adminaccountwindow.cpp \
    authenticatelogic.cpp \
    databaseconnection.cpp \
    editreminderdetailsstandarduseraccount.cpp \
    main.cpp \
    loginwindow.cpp \
    premiumuseraccountlogic.cpp \
    reportsubmissionwindow.cpp \
    setnewreminderstandarduseraccountdialog.cpp \
    standarduseraccountlogic.cpp \
    useraccountwindow.cpp \
    userregistrationwindow.cpp \
    viewfeedbackreportdialog.cpp \
    viewtaskstandarduseraccountdialog.cpp \
    viewtermsandconditionsdialog.cpp

HEADERS += \
    aboutdialog.h \
    accountlogic.h \
    addnewtaskpremiumuseraccountwindow.h \
    addnewtaskstandarduseraccountwindow.h \
    adminaccountlogic.h \
    adminaccountwindow.h \
    authenticatelogic.h \
    databaseconnection.h \
    editreminderdetailsstandarduseraccount.h \
    loginwindow.h \
    premiumuseraccountlogic.h \
    reportsubmissionwindow.h \
    setnewreminderstandarduseraccountdialog.h \
    standarduseraccountlogic.h \
    useraccountwindow.h \
    userregistrationwindow.h \
    viewfeedbackreportdialog.h \
    viewtaskstandarduseraccountdialog.h \
    viewtermsandconditionsdialog.h

FORMS += \
    aboutdialog.ui \
    adminaccountwindow.ui \
    addnewtaskpremiumuseraccountwindow.ui \
    addnewtaskstandarduseraccountwindow.ui \
    editreminderdetailsstandarduseraccount.ui \
    loginwindow.ui \
    reportsubmissionwindow.ui \
    setnewreminderstandarduseraccountdialog.ui \
    useraccountwindow.ui \
    userregistrationwindow.ui \
    viewfeedbackreportdialog.ui \
    viewtaskstandarduseraccountdialog.ui \
    viewtermsandconditionsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
