/****************************************************************************
** Meta object code from reading C++ file 'TrainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TrainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TrainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrainWidget_t {
    QByteArrayData data[14];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrainWidget_t qt_meta_stringdata_TrainWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TrainWidget"
QT_MOC_LITERAL(1, 12, 8), // "Train_OK"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(4, 55, 5), // "value"
QT_MOC_LITERAL(5, 61, 22), // "on_m_btn_Image_clicked"
QT_MOC_LITERAL(6, 84, 22), // "on_m_btn_Model_clicked"
QT_MOC_LITERAL(7, 107, 22), // "on_m_btn_Reset_clicked"
QT_MOC_LITERAL(8, 130, 20), // "on_m_btn_Run_clicked"
QT_MOC_LITERAL(9, 151, 27), // "on_m_btn_ImageReset_clicked"
QT_MOC_LITERAL(10, 179, 27), // "on_m_btn_ModelReset_clicked"
QT_MOC_LITERAL(11, 207, 12), // "newConnected"
QT_MOC_LITERAL(12, 220, 8), // "recvData"
QT_MOC_LITERAL(13, 229, 24) // "on_m_btn_Display_clicked"

    },
    "TrainWidget\0Train_OK\0\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_m_btn_Image_clicked\0on_m_btn_Model_clicked\0"
    "on_m_btn_Reset_clicked\0on_m_btn_Run_clicked\0"
    "on_m_btn_ImageReset_clicked\0"
    "on_m_btn_ModelReset_clicked\0newConnected\0"
    "recvData\0on_m_btn_Display_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    0,   73,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
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

void TrainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrainWidget *_t = static_cast<TrainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Train_OK(); break;
        case 1: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_m_btn_Image_clicked(); break;
        case 3: _t->on_m_btn_Model_clicked(); break;
        case 4: _t->on_m_btn_Reset_clicked(); break;
        case 5: _t->on_m_btn_Run_clicked(); break;
        case 6: _t->on_m_btn_ImageReset_clicked(); break;
        case 7: _t->on_m_btn_ModelReset_clicked(); break;
        case 8: _t->newConnected(); break;
        case 9: _t->recvData(); break;
        case 10: _t->on_m_btn_Display_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject TrainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrainWidget.data,
      qt_meta_data_TrainWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TrainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrainWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TrainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
