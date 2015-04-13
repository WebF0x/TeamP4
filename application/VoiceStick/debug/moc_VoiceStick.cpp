/****************************************************************************
** Meta object code from reading C++ file 'VoiceStick.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VoiceStick.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoiceStick.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VoiceStick_t {
    QByteArrayData data[19];
    char stringdata[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoiceStick_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoiceStick_t qt_meta_stringdata_VoiceStick = {
    {
QT_MOC_LITERAL(0, 0, 10), // "VoiceStick"
QT_MOC_LITERAL(1, 11, 4), // "open"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "save"
QT_MOC_LITERAL(4, 22, 6), // "saveAs"
QT_MOC_LITERAL(5, 29, 10), // "closeEvent"
QT_MOC_LITERAL(6, 40, 12), // "QCloseEvent*"
QT_MOC_LITERAL(7, 53, 5), // "event"
QT_MOC_LITERAL(8, 59, 10), // "newProfile"
QT_MOC_LITERAL(9, 70, 13), // "deleteProfile"
QT_MOC_LITERAL(10, 84, 17), // "deleteAllProfiles"
QT_MOC_LITERAL(11, 102, 7), // "aboutQt"
QT_MOC_LITERAL(12, 110, 15), // "profileSelected"
QT_MOC_LITERAL(13, 126, 5), // "index"
QT_MOC_LITERAL(14, 132, 25), // "phonemKeySequenceModified"
QT_MOC_LITERAL(15, 158, 14), // "phonemDetected"
QT_MOC_LITERAL(16, 173, 1), // "n"
QT_MOC_LITERAL(17, 175, 4), // "test"
QT_MOC_LITERAL(18, 180, 3) // "run"

    },
    "VoiceStick\0open\0\0save\0saveAs\0closeEvent\0"
    "QCloseEvent*\0event\0newProfile\0"
    "deleteProfile\0deleteAllProfiles\0aboutQt\0"
    "profileSelected\0index\0phonemKeySequenceModified\0"
    "phonemDetected\0n\0test\0run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoiceStick[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    1,   82,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,
      14,    0,   92,    2, 0x0a /* Public */,
      15,    1,   93,    2, 0x0a /* Public */,
      17,    0,   96,    2, 0x0a /* Public */,
      18,    0,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VoiceStick::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VoiceStick *_t = static_cast<VoiceStick *>(_o);
        switch (_id) {
        case 0: _t->open(); break;
        case 1: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->newProfile(); break;
        case 5: _t->deleteProfile(); break;
        case 6: _t->deleteAllProfiles(); break;
        case 7: _t->aboutQt(); break;
        case 8: _t->profileSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->phonemKeySequenceModified(); break;
        case 10: _t->phonemDetected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->test(); break;
        case 12: _t->run(); break;
        default: ;
        }
    }
}

const QMetaObject VoiceStick::staticMetaObject = {
    { &VoiceStickUI::staticMetaObject, qt_meta_stringdata_VoiceStick.data,
      qt_meta_data_VoiceStick,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VoiceStick::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoiceStick::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VoiceStick.stringdata))
        return static_cast<void*>(const_cast< VoiceStick*>(this));
    return VoiceStickUI::qt_metacast(_clname);
}

int VoiceStick::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VoiceStickUI::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
