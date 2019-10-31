/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SystemIdentification/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "load_data_fin"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "fft_end"
QT_MOC_LITERAL(4, 34, 14), // "pz_getmodl_fin"
QT_MOC_LITERAL(5, 49, 12), // "pz_getpz_fin"
QT_MOC_LITERAL(6, 62, 12), // "plot_timeres"
QT_MOC_LITERAL(7, 75, 22), // "plot_timeres_autoscale"
QT_MOC_LITERAL(8, 98, 21), // "plot_timeres_setrange"
QT_MOC_LITERAL(9, 120, 8), // "plot_fft"
QT_MOC_LITERAL(10, 129, 18), // "plot_fft_autoscale"
QT_MOC_LITERAL(11, 148, 17), // "plot_fft_setrange"
QT_MOC_LITERAL(12, 166, 7), // "plot_si"
QT_MOC_LITERAL(13, 174, 10), // "stat_start"
QT_MOC_LITERAL(14, 185, 9), // "fft_start"
QT_MOC_LITERAL(15, 195, 12), // "pz_lsm_start"
QT_MOC_LITERAL(16, 208, 9), // "pz_get_pz"
QT_MOC_LITERAL(17, 218, 13), // "set_timetable"
QT_MOC_LITERAL(18, 232, 9), // "save_data"
QT_MOC_LITERAL(19, 242, 9), // "open_data"
QT_MOC_LITERAL(20, 252, 9) // "load_data"

    },
    "MainWindow\0load_data_fin\0\0fft_end\0"
    "pz_getmodl_fin\0pz_getpz_fin\0plot_timeres\0"
    "plot_timeres_autoscale\0plot_timeres_setrange\0"
    "plot_fft\0plot_fft_autoscale\0"
    "plot_fft_setrange\0plot_si\0stat_start\0"
    "fft_start\0pz_lsm_start\0pz_get_pz\0"
    "set_timetable\0save_data\0open_data\0"
    "load_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    0,  110,    2, 0x06 /* Public */,
       4,    0,  111,    2, 0x06 /* Public */,
       5,    0,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  113,    2, 0x0a /* Public */,
       7,    0,  114,    2, 0x0a /* Public */,
       8,    0,  115,    2, 0x0a /* Public */,
       9,    0,  116,    2, 0x0a /* Public */,
      10,    0,  117,    2, 0x0a /* Public */,
      11,    0,  118,    2, 0x0a /* Public */,
      12,    0,  119,    2, 0x0a /* Public */,
      13,    0,  120,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    0,  125,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load_data_fin(); break;
        case 1: _t->fft_end(); break;
        case 2: _t->pz_getmodl_fin(); break;
        case 3: _t->pz_getpz_fin(); break;
        case 4: _t->plot_timeres(); break;
        case 5: _t->plot_timeres_autoscale(); break;
        case 6: _t->plot_timeres_setrange(); break;
        case 7: _t->plot_fft(); break;
        case 8: _t->plot_fft_autoscale(); break;
        case 9: _t->plot_fft_setrange(); break;
        case 10: _t->plot_si(); break;
        case 11: _t->stat_start(); break;
        case 12: _t->fft_start(); break;
        case 13: _t->pz_lsm_start(); break;
        case 14: _t->pz_get_pz(); break;
        case 15: _t->set_timetable(); break;
        case 16: _t->save_data(); break;
        case 17: _t->open_data(); break;
        case 18: _t->load_data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::load_data_fin)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::fft_end)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::pz_getmodl_fin)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::pz_getpz_fin)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::load_data_fin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::fft_end()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::pz_getmodl_fin()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::pz_getpz_fin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
