/****************************************************************************
** Meta object code from reading C++ file 'VoiceStickUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VoiceStickUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoiceStickUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VoiceStickUI_t {
    QByteArrayData data[21];
    char stringdata[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VoiceStickUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VoiceStickUI_t qt_meta_stringdata_VoiceStickUI = {
    {
QT_MOC_LITERAL(0, 0, 12), // "VoiceStickUI"
QT_MOC_LITERAL(1, 13, 4), // "open"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "save"
QT_MOC_LITERAL(4, 24, 6), // "saveAs"
QT_MOC_LITERAL(5, 31, 4), // "undo"
QT_MOC_LITERAL(6, 36, 4), // "redo"
QT_MOC_LITERAL(7, 41, 7), // "undoAll"
QT_MOC_LITERAL(8, 49, 10), // "newProfile"
QT_MOC_LITERAL(9, 60, 13), // "deleteProfile"
QT_MOC_LITERAL(10, 74, 17), // "deleteAllProfiles"
QT_MOC_LITERAL(11, 92, 10), // "userManual"
QT_MOC_LITERAL(12, 103, 15), // "aboutVoiceStick"
QT_MOC_LITERAL(13, 119, 7), // "aboutQt"
QT_MOC_LITERAL(14, 127, 4), // "test"
QT_MOC_LITERAL(15, 132, 3), // "run"
QT_MOC_LITERAL(16, 136, 13), // "testTriggered"
QT_MOC_LITERAL(17, 150, 12), // "runTriggered"
QT_MOC_LITERAL(18, 163, 15), // "profileSelected"
QT_MOC_LITERAL(19, 179, 5), // "index"
QT_MOC_LITERAL(20, 185, 25) // "phonemKeySequenceModified"

    },
    "VoiceStickUI\0open\0\0save\0saveAs\0undo\0"
    "redo\0undoAll\0newProfile\0deleteProfile\0"
    "deleteAllProfiles\0userManual\0"
    "aboutVoiceStick\0aboutQt\0test\0run\0"
    "testTriggered\0runTriggered\0profileSelected\0"
    "index\0phonemKeySequenceModified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VoiceStickUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    1,  120,    2, 0x0a /* Public */,
      20,    0,  123,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,

       0        // eod
};

void VoiceStickUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VoiceStickUI *_t = static_cast<VoiceStickUI *>(_o);
        switch (_id) {
        case 0: _t->open(); break;
        case 1: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->undo(); break;
        case 4: _t->redo(); break;
        case 5: _t->undoAll(); break;
        case 6: _t->newProfile(); break;
        case 7: _t->deleteProfile(); break;
        case 8: _t->deleteAllProfiles(); break;
        case 9: _t->userManual(); break;
        case 10: _t->aboutVoiceStick(); break;
        case 11: _t->aboutQt(); break;
        case 12: _t->test(); break;
        case 13: _t->run(); break;
        case 14: _t->testTriggered(); break;
        case 15: _t->runTriggered(); break;
        case 16: _t->profileSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->phonemKeySequenceModified(); break;
        default: ;
        }
    }
}

const QMetaObject VoiceStickUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VoiceStickUI.data,
      qt_meta_data_VoiceStickUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VoiceStickUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoiceStickUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VoiceStickUI.stringdata))
        return static_cast<void*>(const_cast< VoiceStickUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VoiceStickUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
