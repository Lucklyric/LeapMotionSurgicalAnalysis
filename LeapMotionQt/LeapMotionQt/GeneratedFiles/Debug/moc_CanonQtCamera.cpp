/****************************************************************************
** Meta object code from reading C++ file 'CanonQtCamera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Include/CanonQtCamera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CanonQtCamera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CanonQtCamera_t {
    QByteArrayData data[20];
    char stringdata[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanonQtCamera_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanonQtCamera_t qt_meta_stringdata_CanonQtCamera = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CanonQtCamera"
QT_MOC_LITERAL(1, 14, 11), // "startWorker"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "killWorkerTimer"
QT_MOC_LITERAL(4, 43, 17), // "callSynVideoStart"
QT_MOC_LITERAL(5, 61, 6), // "mImage"
QT_MOC_LITERAL(6, 68, 17), // "sendOneVideoFrame"
QT_MOC_LITERAL(7, 86, 16), // "callSynVideoStop"
QT_MOC_LITERAL(8, 103, 11), // "loadedFrame"
QT_MOC_LITERAL(9, 115, 5), // "start"
QT_MOC_LITERAL(10, 121, 3), // "end"
QT_MOC_LITERAL(11, 125, 16), // "setFrameLabelTex"
QT_MOC_LITERAL(12, 142, 7), // "mString"
QT_MOC_LITERAL(13, 150, 12), // "updateCamera"
QT_MOC_LITERAL(14, 163, 15), // "toggleRecording"
QT_MOC_LITERAL(15, 179, 10), // "closeEvent"
QT_MOC_LITERAL(16, 190, 14), // "killWokerTimer"
QT_MOC_LITERAL(17, 205, 11), // "importVideo"
QT_MOC_LITERAL(18, 217, 20), // "changeReaplyingIndex"
QT_MOC_LITERAL(19, 238, 5) // "index"

    },
    "CanonQtCamera\0startWorker\0\0killWorkerTimer\0"
    "callSynVideoStart\0mImage\0sendOneVideoFrame\0"
    "callSynVideoStop\0loadedFrame\0start\0"
    "end\0setFrameLabelTex\0mString\0updateCamera\0"
    "toggleRecording\0closeEvent\0killWokerTimer\0"
    "importVideo\0changeReaplyingIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanonQtCamera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,
       6,    1,   84,    2, 0x06 /* Public */,
       7,    0,   87,    2, 0x06 /* Public */,
       8,    2,   88,    2, 0x06 /* Public */,
      11,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x0a /* Public */,
      16,    0,   99,    2, 0x0a /* Public */,
      17,    0,  100,    2, 0x0a /* Public */,
      18,    1,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void CanonQtCamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CanonQtCamera *_t = static_cast<CanonQtCamera *>(_o);
        switch (_id) {
        case 0: _t->startWorker(); break;
        case 1: _t->killWorkerTimer(); break;
        case 2: _t->callSynVideoStart((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->sendOneVideoFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->callSynVideoStop(); break;
        case 5: _t->loadedFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setFrameLabelTex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->updateCamera(); break;
        case 8: _t->toggleRecording(); break;
        case 9: _t->closeEvent(); break;
        case 10: _t->killWokerTimer(); break;
        case 11: _t->importVideo(); break;
        case 12: _t->changeReaplyingIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CanonQtCamera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanonQtCamera::startWorker)) {
                *result = 0;
            }
        }
        {
            typedef void (CanonQtCamera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanonQtCamera::killWorkerTimer)) {
                *result = 1;
            }
        }
        {
            typedef void (CanonQtCamera::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanonQtCamera::callSynVideoStart)) {
                *result = 2;
            }
        }
        {
            typedef void (CanonQtCamera::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanonQtCamera::sendOneVideoFrame)) {
                *result = 3;
            }
        }
        {
            typedef void (CanonQtCamera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanonQtCamera::callSynVideoStop)) {
                *result = 4;
            }
        }
        {
            typedef void (CanonQtCamera::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanonQtCamera::loadedFrame)) {
                *result = 5;
            }
        }
        {
            typedef void (CanonQtCamera::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanonQtCamera::setFrameLabelTex)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject CanonQtCamera::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_CanonQtCamera.data,
      qt_meta_data_CanonQtCamera,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CanonQtCamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanonQtCamera::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CanonQtCamera.stringdata))
        return static_cast<void*>(const_cast< CanonQtCamera*>(this));
    return QLabel::qt_metacast(_clname);
}

int CanonQtCamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CanonQtCamera::startWorker()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CanonQtCamera::killWorkerTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CanonQtCamera::callSynVideoStart(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CanonQtCamera::sendOneVideoFrame(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CanonQtCamera::callSynVideoStop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CanonQtCamera::loadedFrame(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CanonQtCamera::setFrameLabelTex(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
