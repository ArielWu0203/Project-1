/****************************************************************************
** Meta object code from reading C++ file 'build.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "build.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'build.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Build_t {
    QByteArrayData data[8];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Build_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Build_t qt_meta_stringdata_Build = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Build"
QT_MOC_LITERAL(1, 6, 12), // "build_health"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "i"
QT_MOC_LITERAL(4, 22, 12), // "check_health"
QT_MOC_LITERAL(5, 35, 17), // "check_be_attacked"
QT_MOC_LITERAL(6, 53, 13), // "add_bullet_up"
QT_MOC_LITERAL(7, 67, 15) // "add_bullet_down"

    },
    "Build\0build_health\0\0i\0check_health\0"
    "check_be_attacked\0add_bullet_up\0"
    "add_bullet_down"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Build[] = {

 // content:
       7,       // revision
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
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Build::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Build *_t = static_cast<Build *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->build_health((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->check_health(); break;
        case 2: _t->check_be_attacked(); break;
        case 3: _t->add_bullet_up(); break;
        case 4: _t->add_bullet_down(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Build::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Build::build_health)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Build::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Build::check_health)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Build::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Build.data,
      qt_meta_data_Build,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Build::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Build::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Build.stringdata0))
        return static_cast<void*>(const_cast< Build*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Build*>(this));
    return QObject::qt_metacast(_clname);
}

int Build::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Build::build_health(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Build::check_health()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
