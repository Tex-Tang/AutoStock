/****************************************************************************
** Meta object code from reading C++ file 'datasystemworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoStock/datasystemworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datasystemworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataSystemWorker_t {
    QByteArrayData data[13];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataSystemWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataSystemWorker_t qt_meta_stringdata_DataSystemWorker = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DataSystemWorker"
QT_MOC_LITERAL(1, 17, 9), // "subscribe"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "StockBox*"
QT_MOC_LITERAL(4, 38, 8), // "stockBox"
QT_MOC_LITERAL(5, 47, 4), // "code"
QT_MOC_LITERAL(6, 52, 11), // "unsubscribe"
QT_MOC_LITERAL(7, 64, 6), // "update"
QT_MOC_LITERAL(8, 71, 9), // "StockData"
QT_MOC_LITERAL(9, 81, 4), // "data"
QT_MOC_LITERAL(10, 86, 3), // "log"
QT_MOC_LITERAL(11, 90, 3), // "msg"
QT_MOC_LITERAL(12, 94, 4) // "init"

    },
    "DataSystemWorker\0subscribe\0\0StockBox*\0"
    "stockBox\0code\0unsubscribe\0update\0"
    "StockData\0data\0log\0msg\0init"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataSystemWorker[] = {

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
       1,    2,   39,    2, 0x06 /* Public */,
       6,    2,   44,    2, 0x06 /* Public */,
       7,    2,   49,    2, 0x06 /* Public */,
      10,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    5,    9,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DataSystemWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataSystemWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->subscribe((*reinterpret_cast< StockBox*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->unsubscribe((*reinterpret_cast< StockBox*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->update((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< StockData(*)>(_a[2]))); break;
        case 3: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->init(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataSystemWorker::*)(StockBox * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataSystemWorker::subscribe)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataSystemWorker::*)(StockBox * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataSystemWorker::unsubscribe)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataSystemWorker::*)(QString , StockData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataSystemWorker::update)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataSystemWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataSystemWorker::log)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataSystemWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataSystemWorker.data,
    qt_meta_data_DataSystemWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataSystemWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataSystemWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataSystemWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataSystemWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DataSystemWorker::subscribe(StockBox * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataSystemWorker::unsubscribe(StockBox * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataSystemWorker::update(QString _t1, StockData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataSystemWorker::log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
