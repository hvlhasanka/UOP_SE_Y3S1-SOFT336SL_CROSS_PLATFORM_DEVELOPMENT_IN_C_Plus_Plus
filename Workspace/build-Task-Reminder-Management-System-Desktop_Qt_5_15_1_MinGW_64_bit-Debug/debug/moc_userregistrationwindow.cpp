/****************************************************************************
** Meta object code from reading C++ file 'userregistrationwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Task-Reminder-Management-System/userregistrationwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userregistrationwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserRegistrationWindow_t {
    QByteArrayData data[12];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserRegistrationWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserRegistrationWindow_t qt_meta_stringdata_UserRegistrationWindow = {
    {
QT_MOC_LITERAL(0, 0, 22), // "UserRegistrationWindow"
QT_MOC_LITERAL(1, 23, 44), // "on_viewPasswordGuidelines_pus..."
QT_MOC_LITERAL(2, 68, 0), // ""
QT_MOC_LITERAL(3, 69, 33), // "on_firstName_lineEdit_textCha..."
QT_MOC_LITERAL(4, 103, 4), // "arg1"
QT_MOC_LITERAL(5, 108, 43), // "on_termsAndConditions_checkBo..."
QT_MOC_LITERAL(6, 152, 34), // "on_middleName_lineEdit_textCh..."
QT_MOC_LITERAL(7, 187, 36), // "on_emailAddress_lineEdit_text..."
QT_MOC_LITERAL(8, 224, 32), // "on_password_lineEdit_textChanged"
QT_MOC_LITERAL(9, 257, 32), // "on_lastName_lineEdit_textChanged"
QT_MOC_LITERAL(10, 290, 39), // "on_confirmPassword_lineEdit_t..."
QT_MOC_LITERAL(11, 330, 30) // "on_register_pushButton_clicked"

    },
    "UserRegistrationWindow\0"
    "on_viewPasswordGuidelines_pushButton_clicked\0"
    "\0on_firstName_lineEdit_textChanged\0"
    "arg1\0on_termsAndConditions_checkBox_stateChanged\0"
    "on_middleName_lineEdit_textChanged\0"
    "on_emailAddress_lineEdit_textChanged\0"
    "on_password_lineEdit_textChanged\0"
    "on_lastName_lineEdit_textChanged\0"
    "on_confirmPassword_lineEdit_textChanged\0"
    "on_register_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserRegistrationWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    1,   66,    2, 0x08 /* Private */,
       7,    1,   69,    2, 0x08 /* Private */,
       8,    1,   72,    2, 0x08 /* Private */,
       9,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void UserRegistrationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserRegistrationWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_viewPasswordGuidelines_pushButton_clicked(); break;
        case 1: _t->on_firstName_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_termsAndConditions_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_middleName_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_emailAddress_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_password_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lastName_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_confirmPassword_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_register_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserRegistrationWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_UserRegistrationWindow.data,
    qt_meta_data_UserRegistrationWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserRegistrationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserRegistrationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserRegistrationWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserRegistrationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
