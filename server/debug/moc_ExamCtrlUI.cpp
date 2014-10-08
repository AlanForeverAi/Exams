/****************************************************************************
** Meta object code from reading C++ file 'ExamCtrlUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ExamCtrlUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExamCtrlUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExamCtrlUI_t {
    QByteArrayData data[16];
    char stringdata[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExamCtrlUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExamCtrlUI_t qt_meta_stringdata_ExamCtrlUI = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 7),
QT_MOC_LITERAL(4, 30, 13),
QT_MOC_LITERAL(5, 44, 8),
QT_MOC_LITERAL(6, 53, 10),
QT_MOC_LITERAL(7, 64, 13),
QT_MOC_LITERAL(8, 78, 26),
QT_MOC_LITERAL(9, 105, 27),
QT_MOC_LITERAL(10, 133, 15),
QT_MOC_LITERAL(11, 149, 14),
QT_MOC_LITERAL(12, 164, 15),
QT_MOC_LITERAL(13, 180, 12),
QT_MOC_LITERAL(14, 193, 25),
QT_MOC_LITERAL(15, 219, 19)
    },
    "ExamCtrlUI\0sendPaper\0\0endExam\0"
    "sendPaperTime\0sendInfo\0showPapers\0"
    "QList<Paper*>\0on_pushButton_send_clicked\0"
    "on_pushButton_begin_clicked\0counttimeUpdate\0"
    "datetimeUpdate\0updateUserTable\0"
    "QList<User*>\0on_pushButton_end_clicked\0"
    "getcurrentPaperTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExamCtrlUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    2,   78,    2, 0x06 /* Public */,
       5,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   86,    2, 0x08 /* Private */,
       8,    0,   89,    2, 0x08 /* Private */,
       9,    0,   90,    2, 0x08 /* Private */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    1,   93,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void ExamCtrlUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExamCtrlUI *_t = static_cast<ExamCtrlUI *>(_o);
        switch (_id) {
        case 0: _t->sendPaper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->endExam(); break;
        case 2: _t->sendPaperTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sendInfo((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->showPapers((*reinterpret_cast< QList<Paper*>(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_send_clicked(); break;
        case 6: _t->on_pushButton_begin_clicked(); break;
        case 7: _t->counttimeUpdate(); break;
        case 8: _t->datetimeUpdate(); break;
        case 9: _t->updateUserTable((*reinterpret_cast< QList<User*>(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_end_clicked(); break;
        case 11: _t->getcurrentPaperTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExamCtrlUI::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExamCtrlUI::sendPaper)) {
                *result = 0;
            }
        }
        {
            typedef void (ExamCtrlUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExamCtrlUI::endExam)) {
                *result = 1;
            }
        }
        {
            typedef void (ExamCtrlUI::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExamCtrlUI::sendPaperTime)) {
                *result = 2;
            }
        }
        {
            typedef void (ExamCtrlUI::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExamCtrlUI::sendInfo)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ExamCtrlUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ExamCtrlUI.data,
      qt_meta_data_ExamCtrlUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *ExamCtrlUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExamCtrlUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExamCtrlUI.stringdata))
        return static_cast<void*>(const_cast< ExamCtrlUI*>(this));
    if (!strcmp(_clname, "Ui::ExamCtrlUI"))
        return static_cast< Ui::ExamCtrlUI*>(const_cast< ExamCtrlUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int ExamCtrlUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ExamCtrlUI::sendPaper(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExamCtrlUI::endExam()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ExamCtrlUI::sendPaperTime(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ExamCtrlUI::sendInfo(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
