/****************************************************************************
** Meta object code from reading C++ file 'ordersystemworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoStock/ordersystemworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ordersystemworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrderSystemWorker_t {
    QByteArrayData data[19];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderSystemWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderSystemWorker_t qt_meta_stringdata_OrderSystemWorker = {
    {
QT_MOC_LITERAL(0, 0, 17), // "OrderSystemWorker"
QT_MOC_LITERAL(1, 18, 12), // "receiveOrder"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "action"
QT_MOC_LITERAL(4, 39, 2), // "id"
QT_MOC_LITERAL(5, 42, 4), // "code"
QT_MOC_LITERAL(6, 47, 4), // "name"
QT_MOC_LITERAL(7, 52, 3), // "qty"
QT_MOC_LITERAL(8, 56, 5), // "price"
QT_MOC_LITERAL(9, 62, 11), // "triggerSize"
QT_MOC_LITERAL(10, 74, 15), // "sendOrderResult"
QT_MOC_LITERAL(11, 90, 11), // "OrderResult"
QT_MOC_LITERAL(12, 102, 6), // "result"
QT_MOC_LITERAL(13, 109, 17), // "changeRakutenInfo"
QT_MOC_LITERAL(14, 127, 11), // "RakutenInfo"
QT_MOC_LITERAL(15, 139, 4), // "info"
QT_MOC_LITERAL(16, 144, 3), // "log"
QT_MOC_LITERAL(17, 148, 3), // "msg"
QT_MOC_LITERAL(18, 152, 4) // "init"

    },
    "OrderSystemWorker\0receiveOrder\0\0action\0"
    "id\0code\0name\0qty\0price\0triggerSize\0"
    "sendOrderResult\0OrderResult\0result\0"
    "changeRakutenInfo\0RakutenInfo\0info\0"
    "log\0msg\0init"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderSystemWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   39,    2, 0x06 /* Public */,
      10,    1,   54,    2, 0x06 /* Public */,
      13,    1,   57,    2, 0x06 /* Public */,
      16,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QString,   17,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void OrderSystemWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrderSystemWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveOrder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 1: _t->sendOrderResult((*reinterpret_cast< OrderResult(*)>(_a[1]))); break;
        case 2: _t->changeRakutenInfo((*reinterpret_cast< RakutenInfo(*)>(_a[1]))); break;
        case 3: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->init(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OrderSystemWorker::*)(QString , int , QString , QString , int , double , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderSystemWorker::receiveOrder)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OrderSystemWorker::*)(OrderResult );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderSystemWorker::sendOrderResult)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OrderSystemWorker::*)(RakutenInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderSystemWorker::changeRakutenInfo)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (OrderSystemWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OrderSystemWorker::log)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrderSystemWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_OrderSystemWorker.data,
    qt_meta_data_OrderSystemWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OrderSystemWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderSystemWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderSystemWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OrderSystemWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void OrderSystemWorker::receiveOrder(QString _t1, int _t2, QString _t3, QString _t4, int _t5, double _t6, int _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OrderSystemWorker::sendOrderResult(OrderResult _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OrderSystemWorker::changeRakutenInfo(RakutenInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void OrderSystemWorker::log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
