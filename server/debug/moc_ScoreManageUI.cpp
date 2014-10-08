/****************************************************************************
** Meta object code from reading C++ file 'ScoreManageUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ScoreManageUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScoreManageUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScoreManageUI_t {
    QByteArrayData data[14];
    char stringdata[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScoreManageUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScoreManageUI_t qt_meta_stringdata_ScoreManageUI = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 11),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 16),
QT_MOC_LITERAL(4, 44, 12),
QT_MOC_LITERAL(5, 57, 10),
QT_MOC_LITERAL(6, 68, 13),
QT_MOC_LITERAL(7, 82, 28),
QT_MOC_LITERAL(8, 111, 27),
QT_MOC_LITERAL(9, 139, 9),
QT_MOC_LITERAL(10, 149, 13),
QT_MOC_LITERAL(11, 163, 11),
QT_MOC_LITERAL(12, 175, 17),
QT_MOC_LITERAL(13, 193, 28)
    },
    "ScoreManageUI\0getCombo_id\0\0getCombo_paperid\0"
    "delete_score\0showPapers\0QList<Paper*>\0"
    "on_pushButton_search_clicked\0"
    "on_pushButton_print_clicked\0showCombo\0"
    "QList<Combo*>\0paperChange\0QTableWidgetItem*\0"
    "on_pushButton_delete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScoreManageUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    2,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   70,    2, 0x0a /* Public */,
       7,    0,   73,    2, 0x0a /* Public */,
       8,    0,   74,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      11,    1,   78,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::LongLong,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,

       0        // eod
};

void ScoreManageUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScoreManageUI *_t = static_cast<ScoreManageUI *>(_o);
        switch (_id) {
        case 0: _t->getCombo_id((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getCombo_paperid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->delete_score((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qlonglong(*)>(_a[2]))); break;
        case 3: _t->showPapers((*reinterpret_cast< QList<Paper*>(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_search_clicked(); break;
        case 5: _t->on_pushButton_print_clicked(); break;
        case 6: _t->showCombo((*reinterpret_cast< QList<Combo*>(*)>(_a[1]))); break;
        case 7: _t->paperChange((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_delete_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScoreManageUI::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScoreManageUI::getCombo_id)) {
                *result = 0;
            }
        }
        {
            typedef void (ScoreManageUI::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScoreManageUI::getCombo_paperid)) {
                *result = 1;
            }
        }
        {
            typedef void (ScoreManageUI::*_t)(int , qlonglong );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScoreManageUI::delete_score)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ScoreManageUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScoreManageUI.data,
      qt_meta_data_ScoreManageUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScoreManageUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScoreManageUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScoreManageUI.stringdata))
        return static_cast<void*>(const_cast< ScoreManageUI*>(this));
    if (!strcmp(_clname, "Ui::ScoreManageUI"))
        return static_cast< Ui::ScoreManageUI*>(const_cast< ScoreManageUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScoreManageUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ScoreManageUI::getCombo_id(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScoreManageUI::getCombo_paperid(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScoreManageUI::delete_score(int _t1, qlonglong _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
