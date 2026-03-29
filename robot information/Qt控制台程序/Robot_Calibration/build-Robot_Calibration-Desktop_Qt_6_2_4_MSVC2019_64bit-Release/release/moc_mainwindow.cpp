/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Robot_Calibration/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[222];
    char stringdata0[2466];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 15), // "Signal_show_pic"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 19), // "Signal_show_pre_pic"
QT_MOC_LITERAL(48, 7), // "cv::Mat"
QT_MOC_LITERAL(56, 3), // "pic"
QT_MOC_LITERAL(60, 7), // "QLabel*"
QT_MOC_LITERAL(68, 5), // "label"
QT_MOC_LITERAL(74, 8), // "show_pic"
QT_MOC_LITERAL(83, 12), // "show_pre_pic"
QT_MOC_LITERAL(96, 22), // "on_robotswitch_toggled"
QT_MOC_LITERAL(119, 7), // "checked"
QT_MOC_LITERAL(127, 21), // "on_pushButton_pressed"
QT_MOC_LITERAL(149, 22), // "on_pushButton_released"
QT_MOC_LITERAL(172, 23), // "on_pushButton_2_pressed"
QT_MOC_LITERAL(196, 24), // "on_pushButton_2_released"
QT_MOC_LITERAL(221, 23), // "on_pushButton_3_pressed"
QT_MOC_LITERAL(245, 24), // "on_pushButton_3_released"
QT_MOC_LITERAL(270, 23), // "on_pushButton_4_pressed"
QT_MOC_LITERAL(294, 24), // "on_pushButton_4_released"
QT_MOC_LITERAL(319, 23), // "on_pushButton_5_pressed"
QT_MOC_LITERAL(343, 24), // "on_pushButton_5_released"
QT_MOC_LITERAL(368, 23), // "on_pushButton_6_pressed"
QT_MOC_LITERAL(392, 24), // "on_pushButton_6_released"
QT_MOC_LITERAL(417, 24), // "on_pushButton_23_pressed"
QT_MOC_LITERAL(442, 25), // "on_pushButton_23_released"
QT_MOC_LITERAL(468, 24), // "on_pushButton_24_pressed"
QT_MOC_LITERAL(493, 25), // "on_pushButton_24_released"
QT_MOC_LITERAL(519, 23), // "on_pushButton_9_pressed"
QT_MOC_LITERAL(543, 24), // "on_pushButton_9_released"
QT_MOC_LITERAL(568, 24), // "on_pushButton_10_pressed"
QT_MOC_LITERAL(593, 25), // "on_pushButton_10_released"
QT_MOC_LITERAL(619, 24), // "on_pushButton_11_pressed"
QT_MOC_LITERAL(644, 25), // "on_pushButton_11_released"
QT_MOC_LITERAL(670, 24), // "on_pushButton_12_pressed"
QT_MOC_LITERAL(695, 25), // "on_pushButton_12_released"
QT_MOC_LITERAL(721, 24), // "on_pushButton_35_pressed"
QT_MOC_LITERAL(746, 25), // "on_pushButton_35_released"
QT_MOC_LITERAL(772, 24), // "on_pushButton_36_pressed"
QT_MOC_LITERAL(797, 25), // "on_pushButton_36_released"
QT_MOC_LITERAL(823, 24), // "on_pushButton_27_pressed"
QT_MOC_LITERAL(848, 25), // "on_pushButton_27_released"
QT_MOC_LITERAL(874, 24), // "on_pushButton_28_pressed"
QT_MOC_LITERAL(899, 25), // "on_pushButton_28_released"
QT_MOC_LITERAL(925, 24), // "on_pushButton_33_pressed"
QT_MOC_LITERAL(950, 25), // "on_pushButton_33_released"
QT_MOC_LITERAL(976, 24), // "on_pushButton_34_pressed"
QT_MOC_LITERAL(1001, 25), // "on_pushButton_34_released"
QT_MOC_LITERAL(1027, 24), // "on_pushButton_25_pressed"
QT_MOC_LITERAL(1052, 25), // "on_pushButton_25_released"
QT_MOC_LITERAL(1078, 24), // "on_pushButton_26_pressed"
QT_MOC_LITERAL(1103, 25), // "on_pushButton_26_released"
QT_MOC_LITERAL(1129, 24), // "on_pushButton_31_pressed"
QT_MOC_LITERAL(1154, 25), // "on_pushButton_31_released"
QT_MOC_LITERAL(1180, 24), // "on_pushButton_32_pressed"
QT_MOC_LITERAL(1205, 25), // "on_pushButton_32_released"
QT_MOC_LITERAL(1231, 24), // "on_pushButton_29_pressed"
QT_MOC_LITERAL(1256, 25), // "on_pushButton_29_released"
QT_MOC_LITERAL(1282, 24), // "on_pushButton_30_pressed"
QT_MOC_LITERAL(1307, 25), // "on_pushButton_30_released"
QT_MOC_LITERAL(1333, 21), // "on_matlabtest_clicked"
QT_MOC_LITERAL(1355, 23), // "on_cameraswitch_toggled"
QT_MOC_LITERAL(1379, 18), // "on_showpic_clicked"
QT_MOC_LITERAL(1398, 22), // "on_getposition_clicked"
QT_MOC_LITERAL(1421, 17), // "on_show2D_clicked"
QT_MOC_LITERAL(1439, 22), // "on_calculate3D_clicked"
QT_MOC_LITERAL(1462, 24), // "on_checkaccuracy_clicked"
QT_MOC_LITERAL(1487, 19), // "on_showtool_clicked"
QT_MOC_LITERAL(1507, 21), // "on_robotkine1_clicked"
QT_MOC_LITERAL(1529, 22), // "on_robotikine1_clicked"
QT_MOC_LITERAL(1552, 22), // "on_port_turnon_clicked"
QT_MOC_LITERAL(1575, 24), // "on_sent_telegram_clicked"
QT_MOC_LITERAL(1600, 22), // "on_stop_button_clicked"
QT_MOC_LITERAL(1623, 21), // "on_robotkine2_clicked"
QT_MOC_LITERAL(1645, 22), // "on_robotikine2_clicked"
QT_MOC_LITERAL(1668, 24), // "on_CalibrateC_R2_clicked"
QT_MOC_LITERAL(1693, 21), // "on_Robot_move_clicked"
QT_MOC_LITERAL(1715, 25), // "on_test_new_robot_clicked"
QT_MOC_LITERAL(1741, 24), // "on_pushButton_38_toggled"
QT_MOC_LITERAL(1766, 24), // "on_pushButton_39_clicked"
QT_MOC_LITERAL(1791, 24), // "on_pushButton_41_clicked"
QT_MOC_LITERAL(1816, 24), // "on_pushButton_42_clicked"
QT_MOC_LITERAL(1841, 24), // "on_stop_button_2_clicked"
QT_MOC_LITERAL(1866, 14), // "Adjust_theta_z"
QT_MOC_LITERAL(1881, 15), // "Adjust_delt_z_y"
QT_MOC_LITERAL(1897, 14), // "Adjust_theta_y"
QT_MOC_LITERAL(1912, 11), // "Operat_tool"
QT_MOC_LITERAL(1924, 5), // "value"
QT_MOC_LITERAL(1930, 5), // "index"
QT_MOC_LITERAL(1936, 33), // "on_horizontalSlider_2_sliderM..."
QT_MOC_LITERAL(1970, 8), // "position"
QT_MOC_LITERAL(1979, 33), // "on_horizontalSlider_1_sliderM..."
QT_MOC_LITERAL(2013, 9), // "extracted"
QT_MOC_LITERAL(2023, 33), // "std::vector<std::vector<doubl..."
QT_MOC_LITERAL(2057, 8), // "vec_V_qF"
QT_MOC_LITERAL(2066, 24), // "on_pushButton_37_clicked"
QT_MOC_LITERAL(2091, 24), // "on_pushButton_43_clicked"
QT_MOC_LITERAL(2116, 24), // "on_pushButton_44_clicked"
QT_MOC_LITERAL(2141, 24), // "on_pushButton_51_clicked"
QT_MOC_LITERAL(2166, 24), // "on_pushButton_45_clicked"
QT_MOC_LITERAL(2191, 24), // "on_pushButton_46_clicked"
QT_MOC_LITERAL(2216, 24), // "on_pushButton_47_clicked"
QT_MOC_LITERAL(2241, 24), // "on_pushButton_48_clicked"
QT_MOC_LITERAL(2266, 24), // "on_pushButton_50_clicked"
QT_MOC_LITERAL(2291, 24), // "on_pushButton_58_clicked"
QT_MOC_LITERAL(2316, 24), // "on_pushButton_52_clicked"
QT_MOC_LITERAL(2341, 24), // "on_pushButton_53_clicked"
QT_MOC_LITERAL(2366, 24), // "on_pushButton_54_clicked"
QT_MOC_LITERAL(2391, 24), // "on_pushButton_55_clicked"
QT_MOC_LITERAL(2416, 24), // "on_pushButton_57_clicked"
QT_MOC_LITERAL(2441, 24) // "on_pushButton_56_clicked"

    },
    "MainWindow\0Signal_show_pic\0\0"
    "Signal_show_pre_pic\0cv::Mat\0pic\0QLabel*\0"
    "label\0show_pic\0show_pre_pic\0"
    "on_robotswitch_toggled\0checked\0"
    "on_pushButton_pressed\0on_pushButton_released\0"
    "on_pushButton_2_pressed\0"
    "on_pushButton_2_released\0"
    "on_pushButton_3_pressed\0"
    "on_pushButton_3_released\0"
    "on_pushButton_4_pressed\0"
    "on_pushButton_4_released\0"
    "on_pushButton_5_pressed\0"
    "on_pushButton_5_released\0"
    "on_pushButton_6_pressed\0"
    "on_pushButton_6_released\0"
    "on_pushButton_23_pressed\0"
    "on_pushButton_23_released\0"
    "on_pushButton_24_pressed\0"
    "on_pushButton_24_released\0"
    "on_pushButton_9_pressed\0"
    "on_pushButton_9_released\0"
    "on_pushButton_10_pressed\0"
    "on_pushButton_10_released\0"
    "on_pushButton_11_pressed\0"
    "on_pushButton_11_released\0"
    "on_pushButton_12_pressed\0"
    "on_pushButton_12_released\0"
    "on_pushButton_35_pressed\0"
    "on_pushButton_35_released\0"
    "on_pushButton_36_pressed\0"
    "on_pushButton_36_released\0"
    "on_pushButton_27_pressed\0"
    "on_pushButton_27_released\0"
    "on_pushButton_28_pressed\0"
    "on_pushButton_28_released\0"
    "on_pushButton_33_pressed\0"
    "on_pushButton_33_released\0"
    "on_pushButton_34_pressed\0"
    "on_pushButton_34_released\0"
    "on_pushButton_25_pressed\0"
    "on_pushButton_25_released\0"
    "on_pushButton_26_pressed\0"
    "on_pushButton_26_released\0"
    "on_pushButton_31_pressed\0"
    "on_pushButton_31_released\0"
    "on_pushButton_32_pressed\0"
    "on_pushButton_32_released\0"
    "on_pushButton_29_pressed\0"
    "on_pushButton_29_released\0"
    "on_pushButton_30_pressed\0"
    "on_pushButton_30_released\0"
    "on_matlabtest_clicked\0on_cameraswitch_toggled\0"
    "on_showpic_clicked\0on_getposition_clicked\0"
    "on_show2D_clicked\0on_calculate3D_clicked\0"
    "on_checkaccuracy_clicked\0on_showtool_clicked\0"
    "on_robotkine1_clicked\0on_robotikine1_clicked\0"
    "on_port_turnon_clicked\0on_sent_telegram_clicked\0"
    "on_stop_button_clicked\0on_robotkine2_clicked\0"
    "on_robotikine2_clicked\0on_CalibrateC_R2_clicked\0"
    "on_Robot_move_clicked\0on_test_new_robot_clicked\0"
    "on_pushButton_38_toggled\0"
    "on_pushButton_39_clicked\0"
    "on_pushButton_41_clicked\0"
    "on_pushButton_42_clicked\0"
    "on_stop_button_2_clicked\0Adjust_theta_z\0"
    "Adjust_delt_z_y\0Adjust_theta_y\0"
    "Operat_tool\0value\0index\0"
    "on_horizontalSlider_2_sliderMoved\0"
    "position\0on_horizontalSlider_1_sliderMoved\0"
    "extracted\0std::vector<std::vector<double>>&\0"
    "vec_V_qF\0on_pushButton_37_clicked\0"
    "on_pushButton_43_clicked\0"
    "on_pushButton_44_clicked\0"
    "on_pushButton_51_clicked\0"
    "on_pushButton_45_clicked\0"
    "on_pushButton_46_clicked\0"
    "on_pushButton_47_clicked\0"
    "on_pushButton_48_clicked\0"
    "on_pushButton_50_clicked\0"
    "on_pushButton_58_clicked\0"
    "on_pushButton_52_clicked\0"
    "on_pushButton_53_clicked\0"
    "on_pushButton_54_clicked\0"
    "on_pushButton_55_clicked\0"
    "on_pushButton_57_clicked\0"
    "on_pushButton_56_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      99,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  608,    2, 0x06,    1 /* Public */,
       3,    2,  609,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  614,    2, 0x08,    5 /* Private */,
       9,    2,  615,    2, 0x08,    6 /* Private */,
      10,    1,  620,    2, 0x08,    9 /* Private */,
      12,    0,  623,    2, 0x08,   11 /* Private */,
      13,    0,  624,    2, 0x08,   12 /* Private */,
      14,    0,  625,    2, 0x08,   13 /* Private */,
      15,    0,  626,    2, 0x08,   14 /* Private */,
      16,    0,  627,    2, 0x08,   15 /* Private */,
      17,    0,  628,    2, 0x08,   16 /* Private */,
      18,    0,  629,    2, 0x08,   17 /* Private */,
      19,    0,  630,    2, 0x08,   18 /* Private */,
      20,    0,  631,    2, 0x08,   19 /* Private */,
      21,    0,  632,    2, 0x08,   20 /* Private */,
      22,    0,  633,    2, 0x08,   21 /* Private */,
      23,    0,  634,    2, 0x08,   22 /* Private */,
      24,    0,  635,    2, 0x08,   23 /* Private */,
      25,    0,  636,    2, 0x08,   24 /* Private */,
      26,    0,  637,    2, 0x08,   25 /* Private */,
      27,    0,  638,    2, 0x08,   26 /* Private */,
      28,    0,  639,    2, 0x08,   27 /* Private */,
      29,    0,  640,    2, 0x08,   28 /* Private */,
      30,    0,  641,    2, 0x08,   29 /* Private */,
      31,    0,  642,    2, 0x08,   30 /* Private */,
      32,    0,  643,    2, 0x08,   31 /* Private */,
      33,    0,  644,    2, 0x08,   32 /* Private */,
      34,    0,  645,    2, 0x08,   33 /* Private */,
      35,    0,  646,    2, 0x08,   34 /* Private */,
      36,    0,  647,    2, 0x08,   35 /* Private */,
      37,    0,  648,    2, 0x08,   36 /* Private */,
      38,    0,  649,    2, 0x08,   37 /* Private */,
      39,    0,  650,    2, 0x08,   38 /* Private */,
      40,    0,  651,    2, 0x08,   39 /* Private */,
      41,    0,  652,    2, 0x08,   40 /* Private */,
      42,    0,  653,    2, 0x08,   41 /* Private */,
      43,    0,  654,    2, 0x08,   42 /* Private */,
      44,    0,  655,    2, 0x08,   43 /* Private */,
      45,    0,  656,    2, 0x08,   44 /* Private */,
      46,    0,  657,    2, 0x08,   45 /* Private */,
      47,    0,  658,    2, 0x08,   46 /* Private */,
      48,    0,  659,    2, 0x08,   47 /* Private */,
      49,    0,  660,    2, 0x08,   48 /* Private */,
      50,    0,  661,    2, 0x08,   49 /* Private */,
      51,    0,  662,    2, 0x08,   50 /* Private */,
      52,    0,  663,    2, 0x08,   51 /* Private */,
      53,    0,  664,    2, 0x08,   52 /* Private */,
      54,    0,  665,    2, 0x08,   53 /* Private */,
      55,    0,  666,    2, 0x08,   54 /* Private */,
      56,    0,  667,    2, 0x08,   55 /* Private */,
      57,    0,  668,    2, 0x08,   56 /* Private */,
      58,    0,  669,    2, 0x08,   57 /* Private */,
      59,    0,  670,    2, 0x08,   58 /* Private */,
      60,    0,  671,    2, 0x08,   59 /* Private */,
      61,    1,  672,    2, 0x08,   60 /* Private */,
      62,    0,  675,    2, 0x08,   62 /* Private */,
      63,    0,  676,    2, 0x08,   63 /* Private */,
      64,    0,  677,    2, 0x08,   64 /* Private */,
      65,    0,  678,    2, 0x08,   65 /* Private */,
      66,    0,  679,    2, 0x08,   66 /* Private */,
      67,    0,  680,    2, 0x08,   67 /* Private */,
      68,    0,  681,    2, 0x08,   68 /* Private */,
      69,    0,  682,    2, 0x08,   69 /* Private */,
      70,    0,  683,    2, 0x08,   70 /* Private */,
      71,    0,  684,    2, 0x08,   71 /* Private */,
      72,    0,  685,    2, 0x08,   72 /* Private */,
      73,    0,  686,    2, 0x08,   73 /* Private */,
      74,    0,  687,    2, 0x08,   74 /* Private */,
      75,    0,  688,    2, 0x08,   75 /* Private */,
      76,    0,  689,    2, 0x08,   76 /* Private */,
      77,    0,  690,    2, 0x08,   77 /* Private */,
      78,    1,  691,    2, 0x08,   78 /* Private */,
      79,    0,  694,    2, 0x08,   80 /* Private */,
      80,    0,  695,    2, 0x08,   81 /* Private */,
      81,    0,  696,    2, 0x08,   82 /* Private */,
      82,    0,  697,    2, 0x08,   83 /* Private */,
      83,    0,  698,    2, 0x08,   84 /* Private */,
      84,    0,  699,    2, 0x08,   85 /* Private */,
      85,    0,  700,    2, 0x08,   86 /* Private */,
      86,    2,  701,    2, 0x08,   87 /* Private */,
      89,    1,  706,    2, 0x08,   90 /* Private */,
      91,    1,  709,    2, 0x08,   92 /* Private */,
      92,    1,  712,    2, 0x08,   94 /* Private */,
      95,    0,  715,    2, 0x08,   96 /* Private */,
      96,    0,  716,    2, 0x08,   97 /* Private */,
      97,    0,  717,    2, 0x08,   98 /* Private */,
      98,    0,  718,    2, 0x08,   99 /* Private */,
      99,    0,  719,    2, 0x08,  100 /* Private */,
     100,    0,  720,    2, 0x08,  101 /* Private */,
     101,    0,  721,    2, 0x08,  102 /* Private */,
     102,    0,  722,    2, 0x08,  103 /* Private */,
     103,    0,  723,    2, 0x08,  104 /* Private */,
     104,    0,  724,    2, 0x08,  105 /* Private */,
     105,    0,  725,    2, 0x08,  106 /* Private */,
     106,    0,  726,    2, 0x08,  107 /* Private */,
     107,    0,  727,    2, 0x08,  108 /* Private */,
     108,    0,  728,    2, 0x08,  109 /* Private */,
     109,    0,  729,    2, 0x08,  110 /* Private */,
     110,    0,  730,    2, 0x08,  111 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::Bool,   11,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   87,   88,
    QMetaType::Void, QMetaType::Int,   90,
    QMetaType::Void, QMetaType::Int,   90,
    QMetaType::Void, 0x80000000 | 93,   94,
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
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Signal_show_pic(); break;
        case 1: _t->Signal_show_pre_pic((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QLabel*>>(_a[2]))); break;
        case 2: _t->show_pic(); break;
        case 3: _t->show_pre_pic((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QLabel*>>(_a[2]))); break;
        case 4: _t->on_robotswitch_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->on_pushButton_pressed(); break;
        case 6: _t->on_pushButton_released(); break;
        case 7: _t->on_pushButton_2_pressed(); break;
        case 8: _t->on_pushButton_2_released(); break;
        case 9: _t->on_pushButton_3_pressed(); break;
        case 10: _t->on_pushButton_3_released(); break;
        case 11: _t->on_pushButton_4_pressed(); break;
        case 12: _t->on_pushButton_4_released(); break;
        case 13: _t->on_pushButton_5_pressed(); break;
        case 14: _t->on_pushButton_5_released(); break;
        case 15: _t->on_pushButton_6_pressed(); break;
        case 16: _t->on_pushButton_6_released(); break;
        case 17: _t->on_pushButton_23_pressed(); break;
        case 18: _t->on_pushButton_23_released(); break;
        case 19: _t->on_pushButton_24_pressed(); break;
        case 20: _t->on_pushButton_24_released(); break;
        case 21: _t->on_pushButton_9_pressed(); break;
        case 22: _t->on_pushButton_9_released(); break;
        case 23: _t->on_pushButton_10_pressed(); break;
        case 24: _t->on_pushButton_10_released(); break;
        case 25: _t->on_pushButton_11_pressed(); break;
        case 26: _t->on_pushButton_11_released(); break;
        case 27: _t->on_pushButton_12_pressed(); break;
        case 28: _t->on_pushButton_12_released(); break;
        case 29: _t->on_pushButton_35_pressed(); break;
        case 30: _t->on_pushButton_35_released(); break;
        case 31: _t->on_pushButton_36_pressed(); break;
        case 32: _t->on_pushButton_36_released(); break;
        case 33: _t->on_pushButton_27_pressed(); break;
        case 34: _t->on_pushButton_27_released(); break;
        case 35: _t->on_pushButton_28_pressed(); break;
        case 36: _t->on_pushButton_28_released(); break;
        case 37: _t->on_pushButton_33_pressed(); break;
        case 38: _t->on_pushButton_33_released(); break;
        case 39: _t->on_pushButton_34_pressed(); break;
        case 40: _t->on_pushButton_34_released(); break;
        case 41: _t->on_pushButton_25_pressed(); break;
        case 42: _t->on_pushButton_25_released(); break;
        case 43: _t->on_pushButton_26_pressed(); break;
        case 44: _t->on_pushButton_26_released(); break;
        case 45: _t->on_pushButton_31_pressed(); break;
        case 46: _t->on_pushButton_31_released(); break;
        case 47: _t->on_pushButton_32_pressed(); break;
        case 48: _t->on_pushButton_32_released(); break;
        case 49: _t->on_pushButton_29_pressed(); break;
        case 50: _t->on_pushButton_29_released(); break;
        case 51: _t->on_pushButton_30_pressed(); break;
        case 52: _t->on_pushButton_30_released(); break;
        case 53: _t->on_matlabtest_clicked(); break;
        case 54: _t->on_cameraswitch_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 55: _t->on_showpic_clicked(); break;
        case 56: _t->on_getposition_clicked(); break;
        case 57: _t->on_show2D_clicked(); break;
        case 58: _t->on_calculate3D_clicked(); break;
        case 59: _t->on_checkaccuracy_clicked(); break;
        case 60: _t->on_showtool_clicked(); break;
        case 61: _t->on_robotkine1_clicked(); break;
        case 62: _t->on_robotikine1_clicked(); break;
        case 63: _t->on_port_turnon_clicked(); break;
        case 64: _t->on_sent_telegram_clicked(); break;
        case 65: _t->on_stop_button_clicked(); break;
        case 66: _t->on_robotkine2_clicked(); break;
        case 67: _t->on_robotikine2_clicked(); break;
        case 68: _t->on_CalibrateC_R2_clicked(); break;
        case 69: _t->on_Robot_move_clicked(); break;
        case 70: _t->on_test_new_robot_clicked(); break;
        case 71: _t->on_pushButton_38_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 72: _t->on_pushButton_39_clicked(); break;
        case 73: _t->on_pushButton_41_clicked(); break;
        case 74: _t->on_pushButton_42_clicked(); break;
        case 75: _t->on_stop_button_2_clicked(); break;
        case 76: { bool _r = _t->Adjust_theta_z();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 77: { bool _r = _t->Adjust_delt_z_y();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 78: { bool _r = _t->Adjust_theta_y();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 79: _t->Operat_tool((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 80: _t->on_horizontalSlider_2_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 81: _t->on_horizontalSlider_1_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 82: _t->extracted((*reinterpret_cast< std::add_pointer_t<std::vector<std::vector<double>>&>>(_a[1]))); break;
        case 83: _t->on_pushButton_37_clicked(); break;
        case 84: _t->on_pushButton_43_clicked(); break;
        case 85: _t->on_pushButton_44_clicked(); break;
        case 86: _t->on_pushButton_51_clicked(); break;
        case 87: _t->on_pushButton_45_clicked(); break;
        case 88: _t->on_pushButton_46_clicked(); break;
        case 89: _t->on_pushButton_47_clicked(); break;
        case 90: _t->on_pushButton_48_clicked(); break;
        case 91: _t->on_pushButton_50_clicked(); break;
        case 92: _t->on_pushButton_58_clicked(); break;
        case 93: _t->on_pushButton_52_clicked(); break;
        case 94: _t->on_pushButton_53_clicked(); break;
        case 95: _t->on_pushButton_54_clicked(); break;
        case 96: _t->on_pushButton_55_clicked(); break;
        case 97: _t->on_pushButton_57_clicked(); break;
        case 98: _t->on_pushButton_56_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::Signal_show_pic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(cv::Mat , QLabel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::Signal_show_pre_pic)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>, QtPrivate::TypeAndForceComplete<QLabel *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>, QtPrivate::TypeAndForceComplete<QLabel *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::vector<double>> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 99)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 99;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 99)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 99;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::Signal_show_pic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::Signal_show_pre_pic(cv::Mat _t1, QLabel * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
