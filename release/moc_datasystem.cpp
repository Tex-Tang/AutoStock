/****************************************************************************
** Meta object code from reading C++ file 'datasystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoStock/datasystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datasystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataSystem_t {
    QByteArrayData data[15];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataSystem_t qt_meta_stringdata_DataSystem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DataSystem"
QT_MOC_LITERAL(1, 11, 3), // "log"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "msg"
QT_MOC_LITERAL(4, 20, 6), // "update"
QT_MOC_LITERAL(5, 27, 4), // "code"
QT_MOC_LITERAL(6, 32, 9), // "StockData"
QT_MOC_LITERAL(7, 42, 4), // "data"
QT_MOC_LITERAL(8, 47, 9), // "subscribe"
QT_MOC_LITERAL(9, 57, 9), // "StockBox*"
QT_MOC_LITERAL(10, 67, 8), // "stockBox"
QT_MOC_LITERAL(11, 76, 11), // "unsubscribe"
QT_MOC_LITERAL(12, 88, 11), // "receiveData"
QT_MOC_LITERAL(13, 100, 4), // "item"
QT_MOC_LITERAL(14, 105, 5) // "value"

    },
    "DataSystem\0log\0\0msg\0update\0code\0"
    "StockData\0data\0subscribe\0StockBox*\0"
    "stockBox\0unsubscribe\0receiveData\0item\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   47,    2, 0x0a /* Public */,
      11,    2,   52,    2, 0x0a /* Public */,
      12,    3,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,    5,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,   13,   14,

       0        // eod
};

void DataSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->update((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< StockData(*)>(_a[2]))); break;
        case 2: _t->subscribe((*reinterpret_cast< StockBox*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->unsubscribe((*reinterpret_cast< StockBox*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->receiveData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StockBox* >(); break;
            }
            break;
        case 3:
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
            using _t = void (DataSystem::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataSystem::log)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataSystem::*)(QString , StockData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataSystem::update)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataSystem.data,
    qt_meta_data_DataSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataSystem.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DataSystem::log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataSystem::update(QString _t1, StockData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
