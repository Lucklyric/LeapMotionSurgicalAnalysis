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
    QByteArrayData data[24];
    char stringdata[274];
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
QT_MOC_LITERAL(6, 65, 11), // "loadedFrame"
QT_MOC_LITERAL(7, 77, 5), // "start"
QT_MOC_LITERAL(8, 83, 3), // "end"
QT_MOC_LITERAL(9, 87, 18), // "buttonChangedFrame"
QT_MOC_LITERAL(10, 106, 5), // "index"
QT_MOC_LITERAL(11, 112, 17), // "changeCameraIndex"
QT_MOC_LITERAL(12, 130, 16), // "setFrameLabelTex"
QT_MOC_LITERAL(13, 147, 7), // "mString"
QT_MOC_LITERAL(14, 155, 14), // "startRecording"
QT_MOC_LITERAL(15, 170, 10), // "importFile"
QT_MOC_LITERAL(16, 181, 9), // "lastFrame"
QT_MOC_LITERAL(17, 191, 9), // "nextFrame"
QT_MOC_LITERAL(18, 201, 11), // "convertFile"
QT_MOC_LITERAL(19, 213, 13), // "changeToFrame"
QT_MOC_LITERAL(20, 227, 11), // "synchroMode"
QT_MOC_LITERAL(21, 239, 4), // "flag"
QT_MOC_LITERAL(22, 244, 12), // "autoPlayMode"
QT_MOC_LITERAL(23, 257, 16) // "reOutPutDataFile"

    },
    "LeapQtGl\0callCameraUpdate\0\0"
    "sendOneMotionFrame\0Leap::Frame\0mFrame\0"
    "loadedFrame\0start\0end\0buttonChangedFrame\0"
    "index\0changeCameraIndex\0setFrameLabelTex\0"
    "mString\0startRecording\0importFile\0"
    "lastFrame\0nextFrame\0convertFile\0"
    "changeToFrame\0synchroMode\0flag\0"
    "autoPlayMode\0reOutPutDataFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeapQtGl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,
       6,    2,   93,    2, 0x06 /* Public */,
       9,    1,   98,    2, 0x06 /* Public */,
      11,    1,  101,    2, 0x06 /* Public */,
      12,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,
      19,    1,  112,    2, 0x0a /* Public */,
      20,    1,  115,    2, 0x0a /* Public */,
      22,    0,  118,    2, 0x0a /* Public */,
      23,    0,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   21,
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
        case 2: _t->loadedFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->buttonChangedFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeCameraIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setFrameLabelTex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->startRecording(); break;
        case 7: _t->importFile(); break;
        case 8: _t->lastFrame(); break;
        case 9: _t->nextFrame(); break;
        case 10: _t->convertFile(); break;
        case 11: _t->changeToFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->synchroMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->autoPlayMode(); break;
        case 14: _t->reOutPutDataFile(); break;
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
        {
            typedef void (LeapQtGl::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeapQtGl::loadedFrame)) {
                *result = 2;
            }
        }
        {
            typedef void (LeapQtGl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeapQtGl::buttonChangedFrame)) {
                *result = 3;
            }
        }
        {
            typedef void (LeapQtGl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeapQtGl::changeCameraIndex)) {
                *result = 4;
            }
        }
        {
            typedef void (LeapQtGl::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LeapQtGl::setFrameLabelTex)) {
                *result = 5;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
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

// SIGNAL 2
void LeapQtGl::loadedFrame(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LeapQtGl::buttonChangedFrame(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LeapQtGl::changeCameraIndex(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LeapQtGl::setFrameLabelTex(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
