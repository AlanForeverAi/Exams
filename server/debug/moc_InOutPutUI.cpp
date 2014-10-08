/****************************************************************************
** Meta object code from reading C++ file 'InOutPutUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InOutPutUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InOutPutUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InOutPutUI_t {
    QByteArrayData data[18];
    char stringdata[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InOutPutUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InOutPutUI_t qt_meta_stringdata_InOutPutUI = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 8),
QT_MOC_LITERAL(4, 32, 9),
QT_MOC_LITERAL(5, 42, 11),
QT_MOC_LITERAL(6, 54, 9),
QT_MOC_LITERAL(7, 64, 7),
QT_MOC_LITERAL(8, 72, 8),
QT_MOC_LITERAL(9, 81, 10),
QT_MOC_LITERAL(10, 92, 28),
QT_MOC_LITERAL(11, 121, 26),
QT_MOC_LITERAL(12, 148, 27),
QT_MOC_LITERAL(13, 176, 29),
QT_MOC_LITERAL(14, 206, 29),
QT_MOC_LITERAL(15, 236, 27),
QT_MOC_LITERAL(16, 264, 28),
QT_MOC_LITERAL(17, 293, 30)
    },
    "InOutPutUI\0outputUser\0\0outputOb\0"
    "outputSub\0outputPaper\0inputUser\0inputOb\0"
    "inputSub\0inputPaper\0on_pushButton_inuser_clicked\0"
    "on_pushButton_inob_clicked\0"
    "on_pushButton_insub_clicked\0"
    "on_pushButton_inpaper_clicked\0"
    "on_pushButton_outuser_clicked\0"
    "on_pushButton_outob_clicked\0"
    "on_pushButton_outsub_clicked\0"
    "on_pushButton_outpaper_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InOutPutUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       7,    1,  101,    2, 0x06 /* Public */,
       8,    1,  104,    2, 0x06 /* Public */,
       9,    1,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  110,    2, 0x0a /* Public */,
      11,    0,  111,    2, 0x0a /* Public */,
      12,    0,  112,    2, 0x0a /* Public */,
      13,    0,  113,    2, 0x0a /* Public */,
      14,    0,  114,    2, 0x0a /* Public */,
      15,    0,  115,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x0a /* Public */,
      17,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InOutPutUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InOutPutUI *_t = static_cast<InOutPutUI *>(_o);
        switch (_id) {
        case 0: _t->outputUser(); break;
        case 1: _t->outputOb(); break;
        case 2: _t->outputSub(); break;
        case 3: _t->outputPaper(); break;
        case 4: _t->inputUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->inputOb((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->inputSub((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->inputPaper((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_inuser_clicked(); break;
        case 9: _t->on_pushButton_inob_clicked(); break;
        case 10: _t->on_pushButton_insub_clicked(); break;
        case 11: _t->on_pushButton_inpaper_clicked(); break;
        case 12: _t->on_pushButton_outuser_clicked(); break;
        case 13: _t->on_pushButton_outob_clicked(); break;
        case 14: _t->on_pushButton_outsub_clicked(); break;
        case 15: _t->on_pushButton_outpaper_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InOutPutUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::outputUser)) {
                *result = 0;
            }
        }
        {
            typedef void (InOutPutUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::outputOb)) {
                *result = 1;
            }
        }
        {
            typedef void (InOutPutUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::outputSub)) {
                *result = 2;
            }
        }
        {
            typedef void (InOutPutUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::outputPaper)) {
                *result = 3;
            }
        }
        {
            typedef void (InOutPutUI::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::inputUser)) {
                *result = 4;
            }
        }
        {
            typedef void (InOutPutUI::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::inputOb)) {
                *result = 5;
            }
        }
        {
            typedef void (InOutPutUI::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::inputSub)) {
                *result = 6;
            }
        }
        {
            typedef void (InOutPutUI::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InOutPutUI::inputPaper)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject InOutPutUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InOutPutUI.data,
      qt_meta_data_InOutPutUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *InOutPutUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InOutPutUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InOutPutUI.stringdata))
        return static_cast<void*>(const_cast< InOutPutUI*>(this));
    if (!strcmp(_clname, "Ui::InOutPutUI"))
        return static_cast< Ui::InOutPutUI*>(const_cast< InOutPutUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int InOutPutUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void InOutPutUI::outputUser()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void InOutPutUI::outputOb()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void InOutPutUI::outputSub()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void InOutPutUI::outputPaper()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void InOutPutUI::inputUser(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void InOutPutUI::inputOb(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void InOutPutUI::inputSub(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void InOutPutUI::inputPaper(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
