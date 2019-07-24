/****************************************************************************
** Meta object code from reading C++ file 'imageprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imageprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_imageprocess_t {
    QByteArrayData data[29];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_imageprocess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_imageprocess_t qt_meta_stringdata_imageprocess = {
    {
QT_MOC_LITERAL(0, 0, 12), // "imageprocess"
QT_MOC_LITERAL(1, 13, 15), // "getAndShowImage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "canny_"
QT_MOC_LITERAL(4, 37, 6), // "sobel_"
QT_MOC_LITERAL(5, 44, 10), // "laplacian_"
QT_MOC_LITERAL(6, 55, 6), // "erode_"
QT_MOC_LITERAL(7, 62, 7), // "dilate_"
QT_MOC_LITERAL(8, 70, 10), // "boxFilter_"
QT_MOC_LITERAL(9, 81, 5), // "blur_"
QT_MOC_LITERAL(10, 87, 13), // "GaussianBlur_"
QT_MOC_LITERAL(11, 101, 11), // "medianBlur_"
QT_MOC_LITERAL(12, 113, 16), // "bilateralFilter_"
QT_MOC_LITERAL(13, 130, 2), // "r_"
QT_MOC_LITERAL(14, 133, 7), // "channel"
QT_MOC_LITERAL(15, 141, 9), // "channel_b"
QT_MOC_LITERAL(16, 151, 9), // "channel_g"
QT_MOC_LITERAL(17, 161, 9), // "channel_r"
QT_MOC_LITERAL(18, 171, 2), // "g_"
QT_MOC_LITERAL(19, 174, 2), // "b_"
QT_MOC_LITERAL(20, 177, 5), // "gray_"
QT_MOC_LITERAL(21, 183, 16), // "changeBrightness"
QT_MOC_LITERAL(22, 200, 10), // "brightness"
QT_MOC_LITERAL(23, 211, 14), // "changeContrast"
QT_MOC_LITERAL(24, 226, 8), // "contrast"
QT_MOC_LITERAL(25, 235, 15), // "changeThreshold"
QT_MOC_LITERAL(26, 251, 9), // "threshold"
QT_MOC_LITERAL(27, 261, 10), // "faceDetect"
QT_MOC_LITERAL(28, 272, 5) // "reset"

    },
    "imageprocess\0getAndShowImage\0\0canny_\0"
    "sobel_\0laplacian_\0erode_\0dilate_\0"
    "boxFilter_\0blur_\0GaussianBlur_\0"
    "medianBlur_\0bilateralFilter_\0r_\0channel\0"
    "channel_b\0channel_g\0channel_r\0g_\0b_\0"
    "gray_\0changeBrightness\0brightness\0"
    "changeContrast\0contrast\0changeThreshold\0"
    "threshold\0faceDetect\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_imageprocess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  194,    2, 0x08 /* Private */,
       3,    0,  195,    2, 0x08 /* Private */,
       4,    0,  196,    2, 0x08 /* Private */,
       5,    0,  197,    2, 0x08 /* Private */,
       6,    0,  198,    2, 0x08 /* Private */,
       7,    0,  199,    2, 0x08 /* Private */,
       8,    0,  200,    2, 0x08 /* Private */,
       9,    0,  201,    2, 0x08 /* Private */,
      10,    0,  202,    2, 0x08 /* Private */,
      11,    0,  203,    2, 0x08 /* Private */,
      12,    0,  204,    2, 0x08 /* Private */,
      13,    4,  205,    2, 0x08 /* Private */,
      13,    3,  214,    2, 0x28 /* Private | MethodCloned */,
      13,    2,  221,    2, 0x28 /* Private | MethodCloned */,
      13,    1,  226,    2, 0x28 /* Private | MethodCloned */,
      13,    0,  229,    2, 0x28 /* Private | MethodCloned */,
      18,    4,  230,    2, 0x08 /* Private */,
      18,    3,  239,    2, 0x28 /* Private | MethodCloned */,
      18,    2,  246,    2, 0x28 /* Private | MethodCloned */,
      18,    1,  251,    2, 0x28 /* Private | MethodCloned */,
      18,    0,  254,    2, 0x28 /* Private | MethodCloned */,
      19,    4,  255,    2, 0x08 /* Private */,
      19,    3,  264,    2, 0x28 /* Private | MethodCloned */,
      19,    2,  271,    2, 0x28 /* Private | MethodCloned */,
      19,    1,  276,    2, 0x28 /* Private | MethodCloned */,
      19,    0,  279,    2, 0x28 /* Private | MethodCloned */,
      20,    4,  280,    2, 0x08 /* Private */,
      20,    3,  289,    2, 0x28 /* Private | MethodCloned */,
      20,    2,  296,    2, 0x28 /* Private | MethodCloned */,
      20,    1,  301,    2, 0x28 /* Private | MethodCloned */,
      20,    0,  304,    2, 0x28 /* Private | MethodCloned */,
      21,    1,  305,    2, 0x08 /* Private */,
      23,    1,  308,    2, 0x08 /* Private */,
      25,    1,  311,    2, 0x08 /* Private */,
      27,    0,  314,    2, 0x08 /* Private */,
      28,    0,  315,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void imageprocess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        imageprocess *_t = static_cast<imageprocess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getAndShowImage(); break;
        case 1: _t->canny_(); break;
        case 2: _t->sobel_(); break;
        case 3: _t->laplacian_(); break;
        case 4: _t->erode_(); break;
        case 5: _t->dilate_(); break;
        case 6: _t->boxFilter_(); break;
        case 7: _t->blur_(); break;
        case 8: _t->GaussianBlur_(); break;
        case 9: _t->medianBlur_(); break;
        case 10: _t->bilateralFilter_(); break;
        case 11: _t->r_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 12: _t->r_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 13: _t->r_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 14: _t->r_((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 15: _t->r_(); break;
        case 16: _t->g_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 17: _t->g_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 18: _t->g_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 19: _t->g_((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 20: _t->g_(); break;
        case 21: _t->b_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 22: _t->b_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 23: _t->b_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 24: _t->b_((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 25: _t->b_(); break;
        case 26: _t->gray_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 27: _t->gray_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 28: _t->gray_((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 29: _t->gray_((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 30: _t->gray_(); break;
        case 31: _t->changeBrightness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->changeContrast((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->changeThreshold((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->faceDetect(); break;
        case 35: _t->reset(); break;
        default: ;
        }
    }
}

const QMetaObject imageprocess::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_imageprocess.data,
      qt_meta_data_imageprocess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *imageprocess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *imageprocess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_imageprocess.stringdata0))
        return static_cast<void*>(const_cast< imageprocess*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int imageprocess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
