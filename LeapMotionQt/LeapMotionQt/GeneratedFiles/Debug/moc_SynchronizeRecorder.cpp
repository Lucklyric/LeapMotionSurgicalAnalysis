/****************************************************************************
** Meta object code from reading C++ file 'SynchronizeRecorder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Include/SynchronizeRecorder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SynchronizeRecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SynchronizeRecorder_t {
    QByteArrayData data[11];
    char stringdata[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SynchronizeRecorder_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SynchronizeRecorder_t qt_meta_stringdata_SynchronizeRecorder = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SynchronizeRecorder"
QT_MOC_LITERAL(1, 20, 27), // "startExportingVideoSequence"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 16), // "QVector<QImage>*"
QT_MOC_LITERAL(4, 66, 19), // "parseOneMotionFrame"
QT_MOC_LITERAL(5, 86, 11), // "Leap::Frame"
QT_MOC_LITERAL(6, 98, 6), // "mFrame"
QT_MOC_LITERAL(7, 105, 18), // "parseOneVideoFrame"
QT_MOC_LITERAL(8, 124, 6), // "mImage"
QT_MOC_LITERAL(9, 131, 13), // "stopRecording"
QT_MOC_LITERAL(10, 145, 19) // "startVideoRecording"

    },
    "SynchronizeRecorder\0startExportingVideoSequence\0"
    "\0QVector<QImage>*\0parseOneMotionFrame\0"
    "Leap::Frame\0mFrame\0parseOneVideoFrame\0"
    "mImage\0stopRecording\0startVideoRecording"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SynchronizeRecorder[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,
       9,    0,   48,    2, 0x0a /* Public */,
      10,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QImage,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    8,

       0        // eod
};

void SynchronizeRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SynchronizeRecorder *_t = static_cast<SynchronizeRecorder *>(_o);
        switch (_id) {
        case 0: _t->startExportingVideoSequence((*reinterpret_cast< QVector<QImage>*(*)>(_a[1]))); break;
        case 1: _t->parseOneMotionFrame((*reinterpret_cast< Leap::Frame(*)>(_a[1]))); break;
        case 2: _t->parseOneVideoFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->stopRecording(); break;
        case 4: _t->startVideoRecording((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SynchronizeRecorder::*_t)(QVector<QImage> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SynchronizeRecorder::startExportingVideoSequence)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SynchronizeRecorder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SynchronizeRecorder.data,
      qt_meta_data_SynchronizeRecorder,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SynchronizeRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SynchronizeRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SynchronizeRecorder.stringdata))
        return static_cast<void*>(const_cast< SynchronizeRecorder*>(this));
    return QObject::qt_metacast(_clname);
}

int SynchronizeRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SynchronizeRecorder::startExportingVideoSequence(QVector<QImage> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
