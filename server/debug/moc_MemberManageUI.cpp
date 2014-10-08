/****************************************************************************
** Meta object code from reading C++ file 'MemberManageUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MemberManageUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MemberManageUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MemberManageUI_t {
    QByteArrayData data[16];
    char stringdata[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MemberManageUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MemberManageUI_t qt_meta_stringdata_MemberManageUI = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 7),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 5),
QT_MOC_LITERAL(4, 30, 10),
QT_MOC_LITERAL(5, 41, 8),
QT_MOC_LITERAL(6, 50, 12),
QT_MOC_LITERAL(7, 63, 15),
QT_MOC_LITERAL(8, 79, 30),
QT_MOC_LITERAL(9, 110, 33),
QT_MOC_LITERAL(10, 144, 28),
QT_MOC_LITERAL(11, 173, 25),
QT_MOC_LITERAL(12, 199, 8),
QT_MOC_LITERAL(13, 208, 12),
QT_MOC_LITERAL(14, 221, 15),
QT_MOC_LITERAL(15, 237, 9)
    },
    "MemberManageUI\0addUser\0\0User*\0addManager\0"
    "Manager*\0deleteUserId\0deleteManagerId\0"
    "on_pushButton_add_user_clicked\0"
    "on_pushButton_delete_user_clicked\0"
    "on_pushButton_search_clicked\0"
    "on_pushButton_all_clicked\0showUser\0"
    "QList<User*>\0QList<Manager*>\0textClear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MemberManageUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       7,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    2,   80,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 14,    2,    2,
    QMetaType::Void,

       0        // eod
};

void MemberManageUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MemberManageUI *_t = static_cast<MemberManageUI *>(_o);
        switch (_id) {
        case 0: _t->addUser((*reinterpret_cast< User*(*)>(_a[1]))); break;
        case 1: _t->addManager((*reinterpret_cast< Manager*(*)>(_a[1]))); break;
        case 2: _t->deleteUserId((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->deleteManagerId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_add_user_clicked(); break;
        case 5: _t->on_pushButton_delete_user_clicked(); break;
        case 6: _t->on_pushButton_search_clicked(); break;
        case 7: _t->on_pushButton_all_clicked(); break;
        case 8: _t->showUser((*reinterpret_cast< QList<User*>(*)>(_a[1])),(*reinterpret_cast< QList<Manager*>(*)>(_a[2]))); break;
        case 9: _t->textClear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MemberManageUI::*_t)(User * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MemberManageUI::addUser)) {
                *result = 0;
            }
        }
        {
            typedef void (MemberManageUI::*_t)(Manager * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MemberManageUI::addManager)) {
                *result = 1;
            }
        }
        {
            typedef void (MemberManageUI::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MemberManageUI::deleteUserId)) {
                *result = 2;
            }
        }
        {
            typedef void (MemberManageUI::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MemberManageUI::deleteManagerId)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MemberManageUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MemberManageUI.data,
      qt_meta_data_MemberManageUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *MemberManageUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MemberManageUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MemberManageUI.stringdata))
        return static_cast<void*>(const_cast< MemberManageUI*>(this));
    if (!strcmp(_clname, "Ui::MemberManageUI"))
        return static_cast< Ui::MemberManageUI*>(const_cast< MemberManageUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int MemberManageUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MemberManageUI::addUser(User * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MemberManageUI::addManager(Manager * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MemberManageUI::deleteUserId(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MemberManageUI::deleteManagerId(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
