/****************************************************************************
** Meta object code from reading C++ file 'symulacja.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../symulacja.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symulacja.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSsymulacjaENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSsymulacjaENDCLASS = QtMocHelpers::stringData(
    "symulacja",
    "noweDaneSymulacji",
    "",
    "wyslacWartoscZmierzona",
    "wartosc",
    "wyslacWartoscSterowania",
    "wyslacResetSygnal",
    "wyslacStanSymulacji",
    "symulacjaStan",
    "symStan",
    "resetWykresy",
    "onSiecZmierzona",
    "onSiecSterowania",
    "wykonajKrok",
    "onSiecSymulacjaStan",
    "onResetSygnal"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSsymulacjaENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    1,   81,    2, 0x06,    2 /* Public */,
       5,    1,   84,    2, 0x06,    4 /* Public */,
       6,    0,   87,    2, 0x06,    6 /* Public */,
       7,    1,   88,    2, 0x06,    7 /* Public */,
      10,    0,   91,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,   92,    2, 0x0a,   10 /* Public */,
      12,    1,   95,    2, 0x0a,   12 /* Public */,
      13,    0,   98,    2, 0x0a,   14 /* Public */,
      14,    1,   99,    2, 0x0a,   15 /* Public */,
      15,    0,  102,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject symulacja::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSsymulacjaENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSsymulacjaENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSsymulacjaENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<symulacja, std::true_type>,
        // method 'noweDaneSymulacji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wyslacWartoscZmierzona'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'wyslacWartoscSterowania'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'wyslacResetSygnal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wyslacStanSymulacji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<symulacjaStan, std::false_type>,
        // method 'resetWykresy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSiecZmierzona'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'onSiecSterowania'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'wykonajKrok'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSiecSymulacjaStan'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<symulacjaStan, std::false_type>,
        // method 'onResetSygnal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void symulacja::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<symulacja *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->noweDaneSymulacji(); break;
        case 1: _t->wyslacWartoscZmierzona((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->wyslacWartoscSterowania((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->wyslacResetSygnal(); break;
        case 4: _t->wyslacStanSymulacji((*reinterpret_cast< std::add_pointer_t<symulacjaStan>>(_a[1]))); break;
        case 5: _t->resetWykresy(); break;
        case 6: _t->onSiecZmierzona((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->onSiecSterowania((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->wykonajKrok(); break;
        case 9: _t->onSiecSymulacjaStan((*reinterpret_cast< std::add_pointer_t<symulacjaStan>>(_a[1]))); break;
        case 10: _t->onResetSygnal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (symulacja::*)();
            if (_t _q_method = &symulacja::noweDaneSymulacji; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (symulacja::*)(double );
            if (_t _q_method = &symulacja::wyslacWartoscZmierzona; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (symulacja::*)(double );
            if (_t _q_method = &symulacja::wyslacWartoscSterowania; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (symulacja::*)();
            if (_t _q_method = &symulacja::wyslacResetSygnal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (symulacja::*)(symulacjaStan );
            if (_t _q_method = &symulacja::wyslacStanSymulacji; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (symulacja::*)();
            if (_t _q_method = &symulacja::resetWykresy; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *symulacja::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *symulacja::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSsymulacjaENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int symulacja::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void symulacja::noweDaneSymulacji()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void symulacja::wyslacWartoscZmierzona(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void symulacja::wyslacWartoscSterowania(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void symulacja::wyslacResetSygnal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void symulacja::wyslacStanSymulacji(symulacjaStan _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void symulacja::resetWykresy()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
