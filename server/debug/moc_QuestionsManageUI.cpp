/****************************************************************************
** Meta object code from reading C++ file 'QuestionsManageUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QuestionsManageUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QuestionsManageUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuestionsManageUI_t {
    QByteArrayData data[23];
    char stringdata[381];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuestionsManageUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuestionsManageUI_t qt_meta_stringdata_QuestionsManageUI = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 15),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 13),
QT_MOC_LITERAL(4, 49, 16),
QT_MOC_LITERAL(5, 66, 14),
QT_MOC_LITERAL(6, 81, 18),
QT_MOC_LITERAL(7, 100, 19),
QT_MOC_LITERAL(8, 120, 18),
QT_MOC_LITERAL(9, 139, 19),
QT_MOC_LITERAL(10, 159, 14),
QT_MOC_LITERAL(11, 174, 3),
QT_MOC_LITERAL(12, 178, 24),
QT_MOC_LITERAL(13, 203, 6),
QT_MOC_LITERAL(14, 210, 22),
QT_MOC_LITERAL(15, 233, 21),
QT_MOC_LITERAL(16, 255, 25),
QT_MOC_LITERAL(17, 281, 14),
QT_MOC_LITERAL(18, 296, 17),
QT_MOC_LITERAL(19, 314, 9),
QT_MOC_LITERAL(20, 324, 13),
QT_MOC_LITERAL(21, 338, 20),
QT_MOC_LITERAL(22, 359, 21)
    },
    "QuestionsManageUI\0addOb_Questoins\0\0"
    "Ob_questions*\0addSub_Questoins\0"
    "Sub_questions*\0modifyOb_Questoins\0"
    "modifySub_Questoins\0deleteOb_Questoins\0"
    "deleteSub_Questoins\0return_clicked\0"
    "add\0on_Button_delete_clicked\0modify\0"
    "on_Button_Save_clicked\0on_Button_new_clicked\0"
    "on_Button_addtype_clicked\0showCurrentQue\0"
    "QTableWidgetItem*\0textClear\0showQuestions\0"
    "QList<Ob_questions*>\0QList<Sub_questions*>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuestionsManageUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       6,    1,  100,    2, 0x06 /* Public */,
       7,    1,  103,    2, 0x06 /* Public */,
       8,    1,  106,    2, 0x06 /* Public */,
       9,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    1,  119,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    2,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21, 0x80000000 | 22,    2,    2,

       0        // eod
};

void QuestionsManageUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuestionsManageUI *_t = static_cast<QuestionsManageUI *>(_o);
        switch (_id) {
        case 0: _t->addOb_Questoins((*reinterpret_cast< Ob_questions*(*)>(_a[1]))); break;
        case 1: _t->addSub_Questoins((*reinterpret_cast< Sub_questions*(*)>(_a[1]))); break;
        case 2: _t->modifyOb_Questoins((*reinterpret_cast< Ob_questions*(*)>(_a[1]))); break;
        case 3: _t->modifySub_Questoins((*reinterpret_cast< Sub_questions*(*)>(_a[1]))); break;
        case 4: _t->deleteOb_Questoins((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->deleteSub_Questoins((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->return_clicked(); break;
        case 7: _t->add(); break;
        case 8: _t->on_Button_delete_clicked(); break;
        case 9: _t->modify(); break;
        case 10: _t->on_Button_Save_clicked(); break;
        case 11: _t->on_Button_new_clicked(); break;
        case 12: _t->on_Button_addtype_clicked(); break;
        case 13: _t->showCurrentQue((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->textClear(); break;
        case 15: _t->showQuestions((*reinterpret_cast< QList<Ob_questions*>(*)>(_a[1])),(*reinterpret_cast< QList<Sub_questions*>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QuestionsManageUI::*_t)(Ob_questions * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuestionsManageUI::addOb_Questoins)) {
                *result = 0;
            }
        }
        {
            typedef void (QuestionsManageUI::*_t)(Sub_questions * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuestionsManageUI::addSub_Questoins)) {
                *result = 1;
            }
        }
        {
            typedef void (QuestionsManageUI::*_t)(Ob_questions * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuestionsManageUI::modifyOb_Questoins)) {
                *result = 2;
            }
        }
        {
            typedef void (QuestionsManageUI::*_t)(Sub_questions * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuestionsManageUI::modifySub_Questoins)) {
                *result = 3;
            }
        }
        {
            typedef void (QuestionsManageUI::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuestionsManageUI::deleteOb_Questoins)) {
                *result = 4;
            }
        }
        {
            typedef void (QuestionsManageUI::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QuestionsManageUI::deleteSub_Questoins)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject QuestionsManageUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QuestionsManageUI.data,
      qt_meta_data_QuestionsManageUI,  qt_static_metacall, 0, 0}
};


const QMetaObject *QuestionsManageUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuestionsManageUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QuestionsManageUI.stringdata))
        return static_cast<void*>(const_cast< QuestionsManageUI*>(this));
    if (!strcmp(_clname, "Ui::QuestionsManageUI"))
        return static_cast< Ui::QuestionsManageUI*>(const_cast< QuestionsManageUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int QuestionsManageUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QuestionsManageUI::addOb_Questoins(Ob_questions * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QuestionsManageUI::addSub_Questoins(Sub_questions * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QuestionsManageUI::modifyOb_Questoins(Ob_questions * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QuestionsManageUI::modifySub_Questoins(Sub_questions * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QuestionsManageUI::deleteOb_Questoins(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QuestionsManageUI::deleteSub_Questoins(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
