/****************************************************************************
** Meta object code from reading C++ file 'stockbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../stockbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StockBox_t {
    QByteArrayData data[28];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockBox_t qt_meta_stringdata_StockBox = {
    {
QT_MOC_LITERAL(0, 0, 8), // "StockBox"
QT_MOC_LITERAL(1, 9, 14), // "removeStockBox"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "StockBox*"
QT_MOC_LITERAL(4, 35, 4), // "self"
QT_MOC_LITERAL(5, 40, 9), // "subscribe"
QT_MOC_LITERAL(6, 50, 4), // "code"
QT_MOC_LITERAL(7, 55, 11), // "unsubscribe"
QT_MOC_LITERAL(8, 67, 9), // "sendOrder"
QT_MOC_LITERAL(9, 77, 6), // "action"
QT_MOC_LITERAL(10, 84, 2), // "id"
QT_MOC_LITERAL(11, 87, 4), // "name"
QT_MOC_LITERAL(12, 92, 3), // "qty"
QT_MOC_LITERAL(13, 96, 5), // "price"
QT_MOC_LITERAL(14, 102, 10), // "changeCode"
QT_MOC_LITERAL(15, 113, 7), // "request"
QT_MOC_LITERAL(16, 121, 12), // "StockBoxData"
QT_MOC_LITERAL(17, 134, 6), // "update"
QT_MOC_LITERAL(18, 141, 9), // "StockData"
QT_MOC_LITERAL(19, 151, 4), // "data"
QT_MOC_LITERAL(20, 156, 7), // "copyAsk"
QT_MOC_LITERAL(21, 164, 7), // "copyBid"
QT_MOC_LITERAL(22, 172, 24), // "startBuyingButtonPressed"
QT_MOC_LITERAL(23, 197, 25), // "startSellingButtonPressed"
QT_MOC_LITERAL(24, 223, 26), // "startMatchingButtonPressed"
QT_MOC_LITERAL(25, 250, 31), // "startInverseBuyingButtonPressed"
QT_MOC_LITERAL(26, 282, 32), // "startInverseSellingButtonPressed"
QT_MOC_LITERAL(27, 315, 33) // "startInverseMatchingButtonPre..."

    },
    "StockBox\0removeStockBox\0\0StockBox*\0"
    "self\0subscribe\0code\0unsubscribe\0"
    "sendOrder\0action\0id\0name\0qty\0price\0"
    "changeCode\0request\0StockBoxData\0update\0"
    "StockData\0data\0copyAsk\0copyBid\0"
    "startBuyingButtonPressed\0"
    "startSellingButtonPressed\0"
    "startMatchingButtonPressed\0"
    "startInverseBuyingButtonPressed\0"
    "startInverseSellingButtonPressed\0"
    "startInverseMatchingButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,
       7,    2,   97,    2, 0x06 /* Public */,
       8,    6,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  115,    2, 0x0a /* Public */,
      15,    1,  116,    2, 0x0a /* Public */,
      17,    2,  119,    2, 0x0a /* Public */,
      20,    0,  124,    2, 0x0a /* Public */,
      21,    0,  125,    2, 0x0a /* Public */,
      22,    0,  126,    2, 0x0a /* Public */,
      23,    0,  127,    2, 0x0a /* Public */,
      24,    0,  128,    2, 0x0a /* Public */,
      25,    0,  129,    2, 0x0a /* Public */,
      26,    0,  130,    2, 0x0a /* Public */,
      27,    0,  131,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Double,    9,   10,    6,   11,   12,   13,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 16, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,    6,   19,
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

void StockBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StockBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeStockBox((*reinterpret_cast< StockBox*(*)>(_a[1]))); break;
        case 1: _t->subscribe((*reinterpret_cast< StockBox*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->unsubscribe((*reinterpret_cast< StockBox*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sendOrder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 4: _t->changeCode(); break;
        case 5: { StockBoxData _r = _t->request((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< StockBoxData*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->update((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< StockData(*)>(_a[2]))); break;
        case 7: _t->copyAsk(); break;
        case 8: _t->copyBid(); break;
        case 9: _t->startBuyingButtonPressed(); break;
        case 10: _t->startSellingButtonPressed(); break;
        case 11: _t->startMatchingButtonPressed(); break;
        case 12: _t->startInverseBuyingButtonPressed(); break;
        case 13: _t->startInverseSellingButtonPressed(); break;
        case 14: _t->startInverseMatchingButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StockBox* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StockBox* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StockBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StockBox::*)(StockBox * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockBox::removeStockBox)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StockBox::*)(StockBox * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockBox::subscribe)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (StockBox::*)(StockBox * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockBox::unsubscribe)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (StockBox::*)(QString , int , QString , QString , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StockBox::sendOrder)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StockBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_StockBox.data,
    qt_meta_data_StockBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StockBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StockBox.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StockBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void StockBox::removeStockBox(StockBox * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StockBox::subscribe(StockBox * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StockBox::unsubscribe(StockBox * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StockBox::sendOrder(QString _t1, int _t2, QString _t3, QString _t4, int _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
