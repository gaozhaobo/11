/****************************************************************************
** Meta object code from reading C++ file 'mycamera.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Robot_Calibration/mycamera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mycamera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMycamera_t {
    const uint offsetsAndSize[12];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CMycamera_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CMycamera_t qt_meta_stringdata_CMycamera = {
    {
QT_MOC_LITERAL(0, 9), // "CMycamera"
QT_MOC_LITERAL(10, 13), // "Get_a_picture"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 11), // "std::string"
QT_MOC_LITERAL(37, 3), // "str"
QT_MOC_LITERAL(41, 17) // "Stop_get_pictures"

    },
    "CMycamera\0Get_a_picture\0\0std::string\0"
    "str\0Stop_get_pictures"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMycamera[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       5,    0,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3,    4,
    QMetaType::Int,

       0        // eod
};

void CMycamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CMycamera *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->Get_a_picture((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->Stop_get_pictures();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject CMycamera::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CMycamera.offsetsAndSize,
    qt_meta_data_CMycamera,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CMycamera_t
, QtPrivate::TypeAndForceComplete<CMycamera, std::true_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *CMycamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMycamera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMycamera.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CMycamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_Mycamera_Group_t {
    const uint offsetsAndSize[10];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Mycamera_Group_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Mycamera_Group_t qt_meta_stringdata_Mycamera_Group = {
    {
QT_MOC_LITERAL(0, 14), // "Mycamera_Group"
QT_MOC_LITERAL(15, 20), // "Signal_Camera_turnon"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 11), // "std::string"
QT_MOC_LITERAL(49, 3) // "str"

    },
    "Mycamera_Group\0Signal_Camera_turnon\0"
    "\0std::string\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mycamera_Group[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Mycamera_Group::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mycamera_Group *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Signal_Camera_turnon((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mycamera_Group::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mycamera_Group::Signal_Camera_turnon)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Mycamera_Group::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Mycamera_Group.offsetsAndSize,
    qt_meta_data_Mycamera_Group,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Mycamera_Group_t
, QtPrivate::TypeAndForceComplete<Mycamera_Group, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>



>,
    nullptr
} };


const QMetaObject *Mycamera_Group::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mycamera_Group::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mycamera_Group.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mycamera_Group::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Mycamera_Group::Signal_Camera_turnon(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
