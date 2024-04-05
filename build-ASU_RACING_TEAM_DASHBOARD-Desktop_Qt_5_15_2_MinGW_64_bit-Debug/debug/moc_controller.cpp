/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[46];
    char stringdata0[575];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 12), // "speedChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "RPMChanged"
QT_MOC_LITERAL(4, 36, 11), // "gearChanged"
QT_MOC_LITERAL(5, 48, 14), // "batteryChanged"
QT_MOC_LITERAL(6, 63, 19), // "DRWheelSpeedChanged"
QT_MOC_LITERAL(7, 83, 19), // "DLWheelSpeedChanged"
QT_MOC_LITERAL(8, 103, 19), // "URWheelSpeedChanged"
QT_MOC_LITERAL(9, 123, 19), // "ULWheelSpeedChanged"
QT_MOC_LITERAL(10, 143, 20), // "SpeedThrottleChanged"
QT_MOC_LITERAL(11, 164, 20), // "SteeringWheelChanged"
QT_MOC_LITERAL(12, 185, 18), // "XtoYDiagramChanged"
QT_MOC_LITERAL(13, 204, 18), // "YtoXDiagramChanged"
QT_MOC_LITERAL(14, 223, 10), // "ECTChanged"
QT_MOC_LITERAL(15, 234, 15), // "URTravelChanged"
QT_MOC_LITERAL(16, 250, 15), // "ULTravelChanged"
QT_MOC_LITERAL(17, 266, 15), // "DRTravelChanged"
QT_MOC_LITERAL(18, 282, 15), // "DLTravelChanged"
QT_MOC_LITERAL(19, 298, 15), // "breakingChanged"
QT_MOC_LITERAL(20, 314, 14), // "SlipingChanged"
QT_MOC_LITERAL(21, 329, 11), // "fuelChanged"
QT_MOC_LITERAL(22, 341, 14), // "processMessage"
QT_MOC_LITERAL(23, 356, 1), // "s"
QT_MOC_LITERAL(24, 358, 12), // "processError"
QT_MOC_LITERAL(25, 371, 14), // "processTimeout"
QT_MOC_LITERAL(26, 386, 5), // "speed"
QT_MOC_LITERAL(27, 392, 3), // "RPM"
QT_MOC_LITERAL(28, 396, 4), // "gear"
QT_MOC_LITERAL(29, 401, 7), // "battery"
QT_MOC_LITERAL(30, 409, 12), // "DRWheelSpeed"
QT_MOC_LITERAL(31, 422, 12), // "DLWheelSpeed"
QT_MOC_LITERAL(32, 435, 12), // "URWheelSpeed"
QT_MOC_LITERAL(33, 448, 12), // "ULWheelSpeed"
QT_MOC_LITERAL(34, 461, 13), // "SpeedThrottle"
QT_MOC_LITERAL(35, 475, 13), // "SteeringWheel"
QT_MOC_LITERAL(36, 489, 11), // "XtoYDiagram"
QT_MOC_LITERAL(37, 501, 11), // "YtoXDiagram"
QT_MOC_LITERAL(38, 513, 3), // "ECT"
QT_MOC_LITERAL(39, 517, 8), // "URTravel"
QT_MOC_LITERAL(40, 526, 8), // "ULTravel"
QT_MOC_LITERAL(41, 535, 8), // "DRTravel"
QT_MOC_LITERAL(42, 544, 8), // "DLTravel"
QT_MOC_LITERAL(43, 553, 8), // "breaking"
QT_MOC_LITERAL(44, 562, 7), // "Sliping"
QT_MOC_LITERAL(45, 570, 4) // "fuel"

    },
    "Controller\0speedChanged\0\0RPMChanged\0"
    "gearChanged\0batteryChanged\0"
    "DRWheelSpeedChanged\0DLWheelSpeedChanged\0"
    "URWheelSpeedChanged\0ULWheelSpeedChanged\0"
    "SpeedThrottleChanged\0SteeringWheelChanged\0"
    "XtoYDiagramChanged\0YtoXDiagramChanged\0"
    "ECTChanged\0URTravelChanged\0ULTravelChanged\0"
    "DRTravelChanged\0DLTravelChanged\0"
    "breakingChanged\0SlipingChanged\0"
    "fuelChanged\0processMessage\0s\0processError\0"
    "processTimeout\0speed\0RPM\0gear\0battery\0"
    "DRWheelSpeed\0DLWheelSpeed\0URWheelSpeed\0"
    "ULWheelSpeed\0SpeedThrottle\0SteeringWheel\0"
    "XtoYDiagram\0YtoXDiagram\0ECT\0URTravel\0"
    "ULTravel\0DRTravel\0DLTravel\0breaking\0"
    "Sliping\0fuel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
      20,  198, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,
       3,    1,  132,    2, 0x06 /* Public */,
       4,    1,  135,    2, 0x06 /* Public */,
       5,    1,  138,    2, 0x06 /* Public */,
       6,    1,  141,    2, 0x06 /* Public */,
       7,    1,  144,    2, 0x06 /* Public */,
       8,    1,  147,    2, 0x06 /* Public */,
       9,    1,  150,    2, 0x06 /* Public */,
      10,    1,  153,    2, 0x06 /* Public */,
      11,    1,  156,    2, 0x06 /* Public */,
      12,    1,  159,    2, 0x06 /* Public */,
      13,    1,  162,    2, 0x06 /* Public */,
      14,    1,  165,    2, 0x06 /* Public */,
      15,    1,  168,    2, 0x06 /* Public */,
      16,    1,  171,    2, 0x06 /* Public */,
      17,    1,  174,    2, 0x06 /* Public */,
      18,    1,  177,    2, 0x06 /* Public */,
      19,    1,  180,    2, 0x06 /* Public */,
      20,    1,  183,    2, 0x06 /* Public */,
      21,    1,  186,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    1,  189,    2, 0x08 /* Private */,
      24,    1,  192,    2, 0x08 /* Private */,
      25,    1,  195,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,

 // properties: name, type, flags
      26, QMetaType::UShort, 0x00495103,
      27, QMetaType::UShort, 0x00495103,
      28, QMetaType::UChar, 0x00495103,
      29, QMetaType::UShort, 0x00495103,
      30, QMetaType::UShort, 0x00495103,
      31, QMetaType::UShort, 0x00495103,
      32, QMetaType::UShort, 0x00495103,
      33, QMetaType::UShort, 0x00495103,
      34, QMetaType::UChar, 0x00495103,
      35, QMetaType::UShort, 0x00495103,
      36, QMetaType::UShort, 0x00495103,
      37, QMetaType::UShort, 0x00495103,
      38, QMetaType::UChar, 0x00495103,
      39, QMetaType::UChar, 0x00495103,
      40, QMetaType::UChar, 0x00495103,
      41, QMetaType::UChar, 0x00495103,
      42, QMetaType::UChar, 0x00495103,
      43, QMetaType::UChar, 0x00495103,
      44, QMetaType::UChar, 0x00495103,
      45, QMetaType::UChar, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
      17,
      18,
      19,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speedChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 1: _t->RPMChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 2: _t->gearChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 3: _t->batteryChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 4: _t->DRWheelSpeedChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 5: _t->DLWheelSpeedChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 6: _t->URWheelSpeedChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 7: _t->ULWheelSpeedChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 8: _t->SpeedThrottleChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 9: _t->SteeringWheelChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 10: _t->XtoYDiagramChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 11: _t->YtoXDiagramChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 12: _t->ECTChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 13: _t->URTravelChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 14: _t->ULTravelChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 15: _t->DRTravelChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 16: _t->DLTravelChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 17: _t->breakingChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 18: _t->SlipingChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 19: _t->fuelChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 20: _t->processMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->processError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->processTimeout((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::speedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::RPMChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::gearChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::batteryChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::DRWheelSpeedChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::DLWheelSpeedChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::URWheelSpeedChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::ULWheelSpeedChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::SpeedThrottleChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::SteeringWheelChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::XtoYDiagramChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::YtoXDiagramChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::ECTChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::URTravelChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::ULTravelChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::DRTravelChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::DLTravelChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::breakingChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::SlipingChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (Controller::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::fuelChanged)) {
                *result = 19;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< quint16*>(_v) = _t->speed(); break;
        case 1: *reinterpret_cast< quint16*>(_v) = _t->RPM(); break;
        case 2: *reinterpret_cast< quint8*>(_v) = _t->gear(); break;
        case 3: *reinterpret_cast< quint16*>(_v) = _t->battery(); break;
        case 4: *reinterpret_cast< quint16*>(_v) = _t->DRWheelSpeed(); break;
        case 5: *reinterpret_cast< quint16*>(_v) = _t->DLWheelSpeed(); break;
        case 6: *reinterpret_cast< quint16*>(_v) = _t->URWheelSpeed(); break;
        case 7: *reinterpret_cast< quint16*>(_v) = _t->ULWheelSpeed(); break;
        case 8: *reinterpret_cast< quint8*>(_v) = _t->SpeedThrottle(); break;
        case 9: *reinterpret_cast< quint16*>(_v) = _t->SteeringWheel(); break;
        case 10: *reinterpret_cast< quint16*>(_v) = _t->XtoYDiagram(); break;
        case 11: *reinterpret_cast< quint16*>(_v) = _t->YtoXDiagram(); break;
        case 12: *reinterpret_cast< quint8*>(_v) = _t->ECT(); break;
        case 13: *reinterpret_cast< quint8*>(_v) = _t->URTravel(); break;
        case 14: *reinterpret_cast< quint8*>(_v) = _t->ULTravel(); break;
        case 15: *reinterpret_cast< quint8*>(_v) = _t->DRTravel(); break;
        case 16: *reinterpret_cast< quint8*>(_v) = _t->DLTravel(); break;
        case 17: *reinterpret_cast< quint8*>(_v) = _t->breaking(); break;
        case 18: *reinterpret_cast< quint8*>(_v) = _t->Sliping(); break;
        case 19: *reinterpret_cast< quint8*>(_v) = _t->fuel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeed(*reinterpret_cast< quint16*>(_v)); break;
        case 1: _t->setRPM(*reinterpret_cast< quint16*>(_v)); break;
        case 2: _t->setGear(*reinterpret_cast< quint8*>(_v)); break;
        case 3: _t->setBattery(*reinterpret_cast< quint16*>(_v)); break;
        case 4: _t->setDRWheelSpeed(*reinterpret_cast< quint16*>(_v)); break;
        case 5: _t->setDLWheelSpeed(*reinterpret_cast< quint16*>(_v)); break;
        case 6: _t->setURWheelSpeed(*reinterpret_cast< quint16*>(_v)); break;
        case 7: _t->setULWheelSpeed(*reinterpret_cast< quint16*>(_v)); break;
        case 8: _t->setSpeedThrottle(*reinterpret_cast< quint8*>(_v)); break;
        case 9: _t->setSteeringWheel(*reinterpret_cast< quint16*>(_v)); break;
        case 10: _t->setXtoYDiagram(*reinterpret_cast< quint16*>(_v)); break;
        case 11: _t->setYtoXDiagram(*reinterpret_cast< quint16*>(_v)); break;
        case 12: _t->setECT(*reinterpret_cast< quint8*>(_v)); break;
        case 13: _t->setURTravel(*reinterpret_cast< quint8*>(_v)); break;
        case 14: _t->setULTravel(*reinterpret_cast< quint8*>(_v)); break;
        case 15: _t->setDRTravel(*reinterpret_cast< quint8*>(_v)); break;
        case 16: _t->setDLTravel(*reinterpret_cast< quint8*>(_v)); break;
        case 17: _t->setBreaking(*reinterpret_cast< quint8*>(_v)); break;
        case 18: _t->setSliping(*reinterpret_cast< quint8*>(_v)); break;
        case 19: _t->setFuel(*reinterpret_cast< quint8*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 20;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Controller::speedChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::RPMChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::gearChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::batteryChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::DRWheelSpeedChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Controller::DLWheelSpeedChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Controller::URWheelSpeedChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Controller::ULWheelSpeedChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Controller::SpeedThrottleChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Controller::SteeringWheelChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Controller::XtoYDiagramChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Controller::YtoXDiagramChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Controller::ECTChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Controller::URTravelChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Controller::ULTravelChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Controller::DRTravelChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Controller::DLTravelChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Controller::breakingChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Controller::SlipingChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Controller::fuelChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
