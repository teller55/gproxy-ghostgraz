/****************************************************************************
** Meta object code from reading C++ file 'GhostGrazLogininformationDialog.h'
**
** Created: Sun 29. May 13:24:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GhostGrazLogininformationDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GhostGrazLogininformationDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GhostGrazLogininformationDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   32,   32,   32, 0x08,
      42,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GhostGrazLogininformationDialog[] = {
    "GhostGrazLogininformationDialog\0\0"
    "accept()\0reject()\0"
};

const QMetaObject GhostGrazLogininformationDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GhostGrazLogininformationDialog,
      qt_meta_data_GhostGrazLogininformationDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GhostGrazLogininformationDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GhostGrazLogininformationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GhostGrazLogininformationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GhostGrazLogininformationDialog))
        return static_cast<void*>(const_cast< GhostGrazLogininformationDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int GhostGrazLogininformationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: reject(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
