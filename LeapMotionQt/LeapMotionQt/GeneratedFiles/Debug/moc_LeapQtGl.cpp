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
    QByteArrayData data[7];
    char stringdata[73];
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
QT_MOC_LITERAL(3, 27, 14), // "startRecording"
QT_MOC_LITERAL(4, 42, 10), // "importFile"
QT_MOC_LITERAL(5, 53, 9), // "lastFrame"
QT_MOC_LITERAL(6, 63, 9) // "nextFrame"

    },
    "LeapQtGl\0callCameraUpdate\0\0startRecording\0"
    "importFile\0lastFrame\0nextFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeapQtGl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

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
        case 1: _t->startRecording(); break;
        case 2: _t->importFile(); break;
        case 3: _t->lastFrame(); break;
        case 4: _t->nextFrame(); break;
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
    }
    Q_UNUSED(_a);
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
void LeapQtGl::callCameraUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
