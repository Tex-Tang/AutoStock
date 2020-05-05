/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "initDataSystem"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "initOrderSystem"
QT_MOC_LITERAL(4, 43, 10), // "initLogger"
QT_MOC_LITERAL(5, 54, 17), // "changeRakutenInfo"
QT_MOC_LITERAL(6, 72, 11), // "RakutenInfo"
QT_MOC_LITERAL(7, 84, 4), // "info"
QT_MOC_LITERAL(8, 89, 3), // "log"
QT_MOC_LITERAL(9, 93, 3), // "msg"
QT_MOC_LITERAL(10, 97, 11), // "autoArrange"
QT_MOC_LITERAL(11, 109, 11), // "addStockBox"
QT_MOC_LITERAL(12, 121, 14), // "removeStockBox"
QT_MOC_LITERAL(13, 136, 9), // "StockBox*"
QT_MOC_LITERAL(14, 146, 8), // "stockBox"
QT_MOC_LITERAL(15, 155, 8), // "loadJson"
QT_MOC_LITERAL(16, 164, 8), // "saveJson"
QT_MOC_LITERAL(17, 173, 14), // "connectRakuten"
QT_MOC_LITERAL(18, 188, 14), // "startAllBuying"
QT_MOC_LITERAL(19, 203, 13), // "stopAllBuying"
QT_MOC_LITERAL(20, 217, 15), // "startAllSelling"
QT_MOC_LITERAL(21, 233, 14) // "stopAllSelling"

    },
    "MainWindow\0initDataSystem\0\0initOrderSystem\0"
    "initLogger\0changeRakutenInfo\0RakutenInfo\0"
    "info\0log\0msg\0autoArrange\0addStockBox\0"
    "removeStockBox\0StockBox*\0stockBox\0"
    "loadJson\0saveJson\0connectRakuten\0"
    "startAllBuying\0stopAllBuying\0"
    "startAllSelling\0stopAllSelling"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    1,   92,    2, 0x06 /* Public */,
       8,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    1,  100,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,
      18,    0,  106,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,
      20,    0,  108,    2, 0x0a /* Public */,
      21,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initDataSystem(); break;
        case 1: _t->initOrderSystem(); break;
        case 2: _t->initLogger(); break;
        case 3: _t->changeRakutenInfo((*reinterpret_cast< RakutenInfo(*)>(_a[1]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->autoArrange(); break;
        case 6: _t->addStockBox(); break;
        case 7: _t->removeStockBox((*reinterpret_cast< StockBox*(*)>(_a[1]))); break;
        case 8: _t->loadJson(); break;
        case 9: _t->saveJson(); break;
        case 10: _t->connectRakuten(); break;
        case 11: _t->startAllBuying(); break;
        case 12: _t->stopAllBuying(); break;
        case 13: _t->startAllSelling(); break;
        case 14: _t->stopAllSelling(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
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
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initDataSystem)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initOrderSystem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initLogger)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(RakutenInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::changeRakutenInfo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::log)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::initDataSystem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::initOrderSystem()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::initLogger()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::changeRakutenInfo(RakutenInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
