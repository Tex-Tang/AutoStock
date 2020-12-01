/****************************************************************************
** Meta object code from reading C++ file 'ddecomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoStock/ddecomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ddecomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DdeComm_t {
    QByteArrayData data[20];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DdeComm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DdeComm_t qt_meta_stringdata_DdeComm = {
    {
QT_MOC_LITERAL(0, 0, 7), // "DdeComm"
QT_MOC_LITERAL(1, 8, 9), // "requested"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "conversation"
QT_MOC_LITERAL(4, 32, 5), // "topic"
QT_MOC_LITERAL(5, 38, 4), // "item"
QT_MOC_LITERAL(6, 43, 4), // "text"
QT_MOC_LITERAL(7, 48, 5), // "poked"
QT_MOC_LITERAL(8, 54, 8), // "executed"
QT_MOC_LITERAL(9, 63, 7), // "command"
QT_MOC_LITERAL(10, 71, 6), // "opened"
QT_MOC_LITERAL(11, 78, 11), // "application"
QT_MOC_LITERAL(12, 90, 6), // "closed"
QT_MOC_LITERAL(13, 97, 7), // "advised"
QT_MOC_LITERAL(14, 105, 4), // "code"
QT_MOC_LITERAL(15, 110, 5), // "value"
QT_MOC_LITERAL(16, 116, 13), // "adviceUpdated"
QT_MOC_LITERAL(17, 130, 7), // "started"
QT_MOC_LITERAL(18, 138, 3), // "log"
QT_MOC_LITERAL(19, 142, 3) // "msg"

    },
    "DdeComm\0requested\0\0conversation\0topic\0"
    "item\0text\0poked\0executed\0command\0"
    "opened\0application\0closed\0advised\0"
    "code\0value\0adviceUpdated\0started\0log\0"
    "msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DdeComm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,
       7,    4,   63,    2, 0x06 /* Public */,
       8,    3,   72,    2, 0x06 /* Public */,
      10,    3,   79,    2, 0x06 /* Public */,
      12,    1,   86,    2, 0x06 /* Public */,
      13,    3,   89,    2, 0x06 /* Public */,
      16,    3,   96,    2, 0x06 /* Public */,
      18,    1,  103,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString, QMetaType::QString,    3,    4,    9,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString, QMetaType::QString,    3,   11,    4,
    QMetaType::Void, QMetaType::ULongLong,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,    5,   15,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString, QMetaType::Bool,    3,    5,   17,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

void DdeComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DdeComm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requested((*reinterpret_cast< unsigned long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->poked((*reinterpret_cast< unsigned long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->executed((*reinterpret_cast< unsigned long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->opened((*reinterpret_cast< unsigned long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->closed((*reinterpret_cast< unsigned long long(*)>(_a[1]))); break;
        case 5: _t->advised((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->adviceUpdated((*reinterpret_cast< unsigned long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DdeComm::*)(unsigned long long , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::requested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DdeComm::*)(unsigned long long , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::poked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DdeComm::*)(unsigned long long , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::executed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DdeComm::*)(unsigned long long , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::opened)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DdeComm::*)(unsigned long long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::closed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DdeComm::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::advised)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DdeComm::*)(unsigned long long , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::adviceUpdated)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DdeComm::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DdeComm::log)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DdeComm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DdeComm.data,
    qt_meta_data_DdeComm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DdeComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DdeComm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DdeComm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DdeComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DdeComm::requested(unsigned long long _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DdeComm::poked(unsigned long long _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DdeComm::executed(unsigned long long _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DdeComm::opened(unsigned long long _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DdeComm::closed(unsigned long long _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DdeComm::advised(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DdeComm::adviceUpdated(unsigned long long _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DdeComm::log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
