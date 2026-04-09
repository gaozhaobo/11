QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Parameter_table.cpp \
    main.cpp \
    mainwindow.cpp \
    minicamera.cpp \
    mycamera.cpp \
    portcommunicate.cpp \
    quest_robot_api_client.cpp \
    robot_function.cpp

HEADERS += \
    ../../../VS Code/Opencv/Straight_line_fitting/Pro_Line_Fit/Linefit_processing.h\
    ../../../VS Code/Python_dll/pythondll/callpython.h \
    ../../../eigen-3.4.0/Eigen/Dense \
    ../APS_Library/Include/APS168.h \
    ../APS_Library/Include/APS_Define.h \
    ../APS_Library/Include/ErrorCodeDef.h \
    ../APS_Library/Include/type_def.h \
    CameraParams.h \
    Linefit_processing.h \
    MvCameraControl.h \
    MvErrorDefine.h \
    MvISPErrorDefine.h \
    MvObsoleteInterfaces.h \
    MvSdkExport.h \
    ObsoleteCamParams.h \
    Parameter_table.h \
    callpython.h \
    mainwindow.h \
    minicamera.h \
    modbusport.h \
    mycamera.h \
    portcommunicate.h \
    quest_robot_api_client.h \
    robot_function.h\
    modbusport.h\


INCLUDEPATH += D:\eigen-3.4.0

FORMS += \
    mainwindow.ui

INCLUDEPATH += D:\Qt_Project\Robot_Calibration\APS_Library\Include
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../APS_Library_x64/ -lAPS168x64

INCLUDEPATH += $$PWD/../APS_Library_x64
DEPENDPATH += $$PWD/../APS_Library_x64

RESOURCES += \
    images.qrc

INCLUDEPATH += D:/OpenCV4/opencv/build/include/
               D:/OpenCV4/opencv/build/include/opencv/
               D:/OpenCV4/opencv/build/include/opencv2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../OpenCV4/opencv/build/x64/vc16/lib/ -lopencv_world470
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../OpenCV4/opencv/build/x64/vc16/lib/ -lopencv_world470d

INCLUDEPATH += $$PWD/../../../OpenCV4/opencv/build/x64/vc16
DEPENDPATH += $$PWD/../../../OpenCV4/opencv/build/x64/vc16

win32: LIBS += -L$$PWD/../MVS/Lib/ -lMvCameraControl

INCLUDEPATH += $$PWD/../MVS/Lib
DEPENDPATH += $$PWD/../MVS/Lib

#INCLUDEPATH += D:/MATLAB2021/extern/include
#INCLUDEPATH += D:/MATLAB2021/extern/include/win64

#INCLUDEPATH += D:/MATLAB2021/extern/lib/win64/microsoft
#DEPENDPATH += D:/MATLAB2021/extern/lib/win64/microsoft

INCLUDEPATH += D:/MATLAB2020/MATLAB2022A/extern/include
INCLUDEPATH += D:/MATLAB2020/MATLAB2022A/extern/include/win64

INCLUDEPATH += D:/MATLAB2020/MATLAB2022A/extern/lib/win64/microsoft
DEPENDPATH += D:/MATLAB2020/MATLAB2022A/extern/lib/win64/microsoft


INCLUDEPATH += D:/Anaconda/envs/TF2_HLH/include
INCLUDEPATH += D:/VS Code/Opencv/Straight_line_fitting/Pro_Line_Fit
#win32: LIBS += -LD:/MATLAB2021/extern/lib/win64/microsoft/ -llibmex
#win32: LIBS += -LD:/MATLAB2021/extern/lib/win64/microsoft/ -llibmx
#win32: LIBS += -LD:/MATLAB2021/extern/lib/win64/microsoft/ -llibmat
#win32: LIBS += -LD:/MATLAB2021/extern/lib/win64/microsoft/ -llibeng
#win32: LIBS += -LD:/MATLAB2021/extern/lib/win64/microsoft/ -lmclmcr
#win32: LIBS += -LD:/MATLAB2021/extern/lib/win64/microsoft/ -lmclmcrrt
win32: LIBS += -LD:/MATLAB2020/MATLAB2022A/extern/lib/win64/microsoft -lmclmcrrt
#win32: LIBS += -L$$PWD/../../../MATLAB2021/MY_MATLAB/Robot_Tool/Robot_kine/for_redistribution_files_only/ -lRobot_kine

#INCLUDEPATH += $$PWD/../../../MATLAB2021/MY_MATLAB/Robot_Tool/Robot_kine/for_redistribution_files_only
#DEPENDPATH += $$PWD/../../../MATLAB2021/MY_MATLAB/Robot_Tool/Robot_kine/for_redistribution_files_only



CONFIG(release, debug|release){
    LIBS += -L$$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/release/' -lmodbus_dll
    INCLUDEPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Release'
    DEPENDPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Release'
}else{
    LIBS += -L$$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/debug/' -lmodbus_dll
    INCLUDEPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Debug'
    DEPENDPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Debug'
}
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/release/' -lmodbus_dll
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/debug/' -lmodbus_dll

#INCLUDEPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Debug'
#DEPENDPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Debug'

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/release/' -lmodbus_dll
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/debug/' -lmodbus_dll

#INCLUDEPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Release'
#DEPENDPATH += $$PWD/'../../../VS Code/Modbus_dll/modbus_dll/modbus_dll/x64/Release'

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../VS Code/Python_dll/pythondll/x64/release/' -lpythondll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../VS Code/Python_dll/pythondll/x64/debug/' -lpythondll

INCLUDEPATH += $$PWD/'../../../VS Code/Python_dll/pythondll/x64/Release'
DEPENDPATH += $$PWD/'../../../VS Code/Python_dll/pythondll/x64/Release'

win32: LIBS += -L$$PWD/../../../Anaconda/envs/TF2_HLH/libs/ -lpython36

INCLUDEPATH += $$PWD/../../../Anaconda/envs/TF2_HLH/libs
DEPENDPATH += $$PWD/../../../Anaconda/envs/TF2_HLH/libs

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../VS Code/Opencv/Straight_line_fitting/Pro_Line_Fit/x64/release/' -lPro_Line_Fit
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../VS Code/Opencv/Straight_line_fitting/Pro_Line_Fit/x64/debug/' -lPro_Line_Fit

INCLUDEPATH += $$PWD/'../../../VS Code/Opencv/Straight_line_fitting/Pro_Line_Fit/x64/Release'
DEPENDPATH += $$PWD/'../../../VS Code/Opencv/Straight_line_fitting/Pro_Line_Fit/x64/Release'


win32: LIBS += -L$$PWD/'../../../MATLAB2020/MY_MATLAB/Robot_Tool/Robot_kine/for_redistribution_files_only/' -lRobot_kine

INCLUDEPATH += $$PWD/'../../../MATLAB2020/MY_MATLAB/Robot_Tool/Robot_kine/for_redistribution_files_only'
DEPENDPATH += $$PWD/'../../../MATLAB2020/MY_MATLAB/Robot_Tool/Robot_kine/for_redistribution_files_only'
