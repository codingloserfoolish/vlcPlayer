/****************************************************************************
** Meta object code from reading C++ file 'VideoControlWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../VideoControlWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoControlWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SwitchLabel_t {
    QByteArrayData data[4];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwitchLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwitchLabel_t qt_meta_stringdata_SwitchLabel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SwitchLabel"
QT_MOC_LITERAL(1, 12, 8), // "switched"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8) // "isOrigin"

    },
    "SwitchLabel\0switched\0\0isOrigin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwitchLabel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void SwitchLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SwitchLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switched((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SwitchLabel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SwitchLabel::switched)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SwitchLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_SwitchLabel.data,
    qt_meta_data_SwitchLabel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SwitchLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwitchLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SwitchLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int SwitchLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SwitchLabel::switched(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_VideoControlWidget_t {
    QByteArrayData data[16];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoControlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoControlWidget_t qt_meta_stringdata_VideoControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "VideoControlWidget"
QT_MOC_LITERAL(1, 19, 21), // "slot_onVideoStartPlay"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 3), // "pos"
QT_MOC_LITERAL(4, 46, 6), // "second"
QT_MOC_LITERAL(5, 53, 6), // "volume"
QT_MOC_LITERAL(6, 60, 20), // "slot_onSliderPressed"
QT_MOC_LITERAL(7, 81, 21), // "slot_onSliderReleased"
QT_MOC_LITERAL(8, 103, 24), // "slot_onSliderTimeChanged"
QT_MOC_LITERAL(9, 128, 5), // "value"
QT_MOC_LITERAL(10, 134, 27), // "slot_onVideoSwitchedChanged"
QT_MOC_LITERAL(11, 162, 27), // "slot_onAudioSwitchedChanged"
QT_MOC_LITERAL(12, 190, 24), // "slot_onAudioValueChanged"
QT_MOC_LITERAL(13, 215, 17), // "slot_onPopCtxMenu"
QT_MOC_LITERAL(14, 233, 22), // "slot_onDealMenuSignals"
QT_MOC_LITERAL(15, 256, 4) // "type"

    },
    "VideoControlWidget\0slot_onVideoStartPlay\0"
    "\0pos\0second\0volume\0slot_onSliderPressed\0"
    "slot_onSliderReleased\0slot_onSliderTimeChanged\0"
    "value\0slot_onVideoSwitchedChanged\0"
    "slot_onAudioSwitchedChanged\0"
    "slot_onAudioValueChanged\0slot_onPopCtxMenu\0"
    "slot_onDealMenuSignals\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoControlWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a /* Public */,
       6,    0,   66,    2, 0x0a /* Public */,
       7,    0,   67,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      13,    0,   80,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void VideoControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoControlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_onVideoStartPlay((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->slot_onSliderPressed(); break;
        case 2: _t->slot_onSliderReleased(); break;
        case 3: _t->slot_onSliderTimeChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->slot_onVideoSwitchedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slot_onAudioSwitchedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slot_onAudioValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slot_onPopCtxMenu(); break;
        case 8: _t->slot_onDealMenuSignals((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoControlWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_VideoControlWidget.data,
    qt_meta_data_VideoControlWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoControlWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VideoControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
