/****************************************************************************
** Meta object code from reading C++ file 'LeapQtGl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Include/LeapQtGl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LeapQtGl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LeapQtGl_t {
    QByteArrayData data[10];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LeapQtGl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LeapQtGl_t qt_meta_stringdata_LeapQtGl = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LeapQtGl"
QT_MOC_LITERAL(1, 9, 16), // "callCameraUpdate"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "sendOneMotionFrame"
QT_MOC_LITERAL(4, 46, 11), // "Leap::Frame"
QT_MOC_LITERAL(5, 58, 6), // "mFrame"
QT_MOC_LITERAL(6, 65, 14), // "startRecording"
QT_MOC_LITERAL(7, 80, 10), // "importFile"
QT_MOC_LITERAL(8, 91, 9), // "lastFrame"
QT_MOC_LITERAL(9, 101, 9) // "nextFrame"

    },
    "LeapQtGl\0callCameraUpdate\0\0"
    "sendOneMotionFrame\0Leap::Frame\0mFrame\0"
    "startRecording\0importFile\0lastFrame\0"
    "nextFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeapQtGl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LeapQtGl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LeapQtGl *_t = static_cast<LeapQtGl *>(_o);
        switch (_id) {
        case 0: _t->callCameraUpdate(); break;
        case 1: _t->sendOneMotionFrame((*reinterpret_cast< Leap::Frame(*)>(_a[1]))); break;
        case 2: _t->startRecording(); break;
        case 3: _t->importFile(); break;
        case 4: _t->lastFrame(); break;
        case 5: _t->nextFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LeapQtGl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeapQtGl::callCameraUpdate)) {
                *result = 0;
            }
        }
        {
            typedef void (LeapQtGl::*_t)(Leap::Frame );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeapQtGl::sendOneMotionFrame)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject LeapQtGl::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_LeapQtGl.data,
      qt_meta_data_LeapQtGl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LeapQtGl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LeapQtGl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LeapQtGl.stringdata))
        return static_cast<void*>(const_cast< LeapQtGl*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int LeapQtGl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LeapQtGl::callCameraUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LeapQtGl::sendOneMotionFrame(Leap::Frame _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
