/****************************************************************************
** Meta object code from reading C++ file 'GUI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GUI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
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
struct qt_meta_stringdata_CLASSAdminGUIENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSAdminGUIENDCLASS = QtMocHelpers::stringData(
    "AdminGUI",
    "addMovieSlot",
    "",
    "deleteMovieSlot",
    "updateMovieSlot"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAdminGUIENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    0,   33,    2, 0x0a,    2 /* Public */,
       4,    0,   34,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AdminGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAdminGUIENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAdminGUIENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAdminGUIENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AdminGUI, std::true_type>,
        // method 'addMovieSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteMovieSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateMovieSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AdminGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addMovieSlot(); break;
        case 1: _t->deleteMovieSlot(); break;
        case 2: _t->updateMovieSlot(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *AdminGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAdminGUIENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUserGUIENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUserGUIENDCLASS = QtMocHelpers::stringData(
    "UserGUI",
    "filterByGenreSlot",
    "",
    "deleteSlot",
    "addMovieSlot",
    "nextSlot",
    "exportWatchlistSlot",
    "watchlistTypeSlot",
    "likeAndDeleteSlot"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserGUIENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    0,   58,    2, 0x0a,    3 /* Public */,
       5,    0,   59,    2, 0x0a,    4 /* Public */,
       6,    0,   60,    2, 0x0a,    5 /* Public */,
       7,    0,   61,    2, 0x0a,    6 /* Public */,
       8,    0,   62,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UserGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserGUIENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserGUIENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserGUIENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UserGUI, std::true_type>,
        // method 'filterByGenreSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addMovieSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportWatchlistSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'watchlistTypeSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'likeAndDeleteSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UserGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->filterByGenreSlot(); break;
        case 1: _t->deleteSlot(); break;
        case 2: _t->addMovieSlot(); break;
        case 3: _t->nextSlot(); break;
        case 4: _t->exportWatchlistSlot(); break;
        case 5: _t->watchlistTypeSlot(); break;
        case 6: _t->likeAndDeleteSlot(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *UserGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserGUIENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
