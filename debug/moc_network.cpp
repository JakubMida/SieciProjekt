/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../network.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSNetworkENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSNetworkENDCLASS = QtMocHelpers::stringData(
    "Network",
    "connected",
    "",
    "address",
    "port",
    "disconecetd",
    "connectionFailed",
    "error",
    "clientConnectedFrom",
    "clientDisconnected",
    "wartoscSterowaniaOtrzymana",
    "wartosc",
    "czas",
    "wartoscZadana",
    "wartoscRegulowaniaOtrzymana",
    "resetSygnalOtrzymany",
    "stanArxOtrzymany",
    "arxStan",
    "stanSymulacjiOtrzymany",
    "symulacjaStan",
    "symStan",
    "trybTaktowaniaOtrzymany",
    "interwal",
    "clientConnected",
    "slotNewClient",
    "slotClientDisconected",
    "daneGotowe",
    "wyslacWartoscRegulowania",
    "wyslacWartoscSterowania",
    "wartoscSterowania",
    "wyslacResetSygnal",
    "wyslacStanArx",
    "wyslacStanSymulacji",
    "wyslacTrybTaktowania"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNetworkENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  140,    2, 0x06,    1 /* Public */,
       5,    0,  145,    2, 0x06,    4 /* Public */,
       6,    1,  146,    2, 0x06,    5 /* Public */,
       8,    1,  149,    2, 0x06,    7 /* Public */,
       9,    0,  152,    2, 0x06,    9 /* Public */,
      10,    3,  153,    2, 0x06,   10 /* Public */,
      14,    1,  160,    2, 0x06,   14 /* Public */,
      15,    0,  163,    2, 0x06,   16 /* Public */,
      16,    1,  164,    2, 0x06,   17 /* Public */,
      18,    1,  167,    2, 0x06,   19 /* Public */,
      21,    1,  170,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      23,    0,  173,    2, 0x08,   23 /* Private */,
      24,    0,  174,    2, 0x08,   24 /* Private */,
      25,    0,  175,    2, 0x08,   25 /* Private */,
      26,    0,  176,    2, 0x08,   26 /* Private */,
      27,    1,  177,    2, 0x0a,   27 /* Public */,
      28,    3,  180,    2, 0x0a,   29 /* Public */,
      30,    0,  187,    2, 0x0a,   33 /* Public */,
      31,    1,  188,    2, 0x0a,   34 /* Public */,
      32,    1,  191,    2, 0x0a,   36 /* Public */,
      33,    1,  194,    2, 0x0a,   38 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   11,   12,   13,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::Int,   22,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   11,   12,   29,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

Q_CONSTINIT const QMetaObject Network::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSNetworkENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNetworkENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNetworkENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Network, std::true_type>,
        // method 'connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'disconecetd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clientConnectedFrom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clientDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wartoscSterowaniaOtrzymana'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'wartoscRegulowaniaOtrzymana'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'resetSygnalOtrzymany'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stanArxOtrzymany'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const arxStan &, std::false_type>,
        // method 'stanSymulacjiOtrzymany'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const symulacjaStan &, std::false_type>,
        // method 'trybTaktowaniaOtrzymany'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clientConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotNewClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotClientDisconected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'daneGotowe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wyslacWartoscRegulowania'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'wyslacWartoscSterowania'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'wyslacResetSygnal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wyslacStanArx'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<arxStan, std::false_type>,
        // method 'wyslacStanSymulacji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<symulacjaStan, std::false_type>,
        // method 'wyslacTrybTaktowania'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Network *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->disconecetd(); break;
        case 2: _t->connectionFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->clientConnectedFrom((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->clientDisconnected(); break;
        case 5: _t->wartoscSterowaniaOtrzymana((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 6: _t->wartoscRegulowaniaOtrzymana((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->resetSygnalOtrzymany(); break;
        case 8: _t->stanArxOtrzymany((*reinterpret_cast< std::add_pointer_t<arxStan>>(_a[1]))); break;
        case 9: _t->stanSymulacjiOtrzymany((*reinterpret_cast< std::add_pointer_t<symulacjaStan>>(_a[1]))); break;
        case 10: _t->trybTaktowaniaOtrzymany((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->clientConnected(); break;
        case 12: _t->slotNewClient(); break;
        case 13: _t->slotClientDisconected(); break;
        case 14: _t->daneGotowe(); break;
        case 15: _t->wyslacWartoscRegulowania((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 16: _t->wyslacWartoscSterowania((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 17: _t->wyslacResetSygnal(); break;
        case 18: _t->wyslacStanArx((*reinterpret_cast< std::add_pointer_t<arxStan>>(_a[1]))); break;
        case 19: _t->wyslacStanSymulacji((*reinterpret_cast< std::add_pointer_t<symulacjaStan>>(_a[1]))); break;
        case 20: _t->wyslacTrybTaktowania((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Network::*)(QString , int );
            if (_t _q_method = &Network::connected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Network::*)();
            if (_t _q_method = &Network::disconecetd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Network::*)(QString );
            if (_t _q_method = &Network::connectionFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Network::*)(QString );
            if (_t _q_method = &Network::clientConnectedFrom; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Network::*)();
            if (_t _q_method = &Network::clientDisconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Network::*)(double , double , double );
            if (_t _q_method = &Network::wartoscSterowaniaOtrzymana; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Network::*)(double );
            if (_t _q_method = &Network::wartoscRegulowaniaOtrzymana; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Network::*)();
            if (_t _q_method = &Network::resetSygnalOtrzymany; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Network::*)(const arxStan & );
            if (_t _q_method = &Network::stanArxOtrzymany; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Network::*)(const symulacjaStan & );
            if (_t _q_method = &Network::stanSymulacjiOtrzymany; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Network::*)(int );
            if (_t _q_method = &Network::trybTaktowaniaOtrzymany; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject *Network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Network::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNetworkENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Network::connected(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Network::disconecetd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Network::connectionFailed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Network::clientConnectedFrom(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Network::clientDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Network::wartoscSterowaniaOtrzymana(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Network::wartoscRegulowaniaOtrzymana(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Network::resetSygnalOtrzymany()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Network::stanArxOtrzymany(const arxStan & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Network::stanSymulacjiOtrzymany(const symulacjaStan & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Network::trybTaktowaniaOtrzymany(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
