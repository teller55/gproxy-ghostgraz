/****************************************************************************
** Meta object code from reading C++ file 'DownloadThread.h'
**
** Created: Mon 23. Jan 18:27:32 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "thread/DownloadThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DownloadThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      42,   39,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,   82,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadThread[] = {
    "DownloadThread\0\0signal_clearGamelist()\0"
    ",,\0signal_addGame(QString,QString,QString)\0"
    "reply\0downloadFinished(QNetworkReply*)\0"
};

const QMetaObject DownloadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DownloadThread,
      qt_meta_data_DownloadThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadThread))
        return static_cast<void*>(const_cast< DownloadThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DownloadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signal_clearGamelist(); break;
        case 1: signal_addGame((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: downloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DownloadThread::signal_clearGamelist()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DownloadThread::signal_addGame(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
