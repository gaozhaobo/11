// SubDlgThermalInterface.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "SubDlgThermalInterface.h"
#include "afxdialogex.h"
#include "DlgUpgrade.h"
#include <direct.h>
#include <io.h>
// SubDlgThermalInterface 对话框

//IMPLEMENT_DYNAMIC(SubDlgThermalInterface, CDialog)

SubDlgThermalInterface::SubDlgThermalInterface(CWnd* pParent /*=NULL*/)
	: CDialog(SubDlgThermalInterface::IDD, pParent)
    , m_lUserID(USB_INVALID_USERID)
    , m_csFilePath(_T(""))
    , m_csFileName(_T(""))
    , m_iCallBackChannel(-1)
    , m_iStreamType(0)
{
}

//SubDlgThermalInterface::~SubDlgThermalInterface()
//{
//}

void SubDlgThermalInterface::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_CONFIG, m_cbConfig);
    DDX_Text(pDX, IDC_EDIT_FILE, m_csFilePath);
    DDX_Control(pDX, IDC_STATIC_PREVIEW, m_PreviewWindow);
    DDX_Control(pDX, IDC_COMBO_DECODE_TYPE, m_combDecodeType);
}


BEGIN_MESSAGE_MAP(SubDlgThermalInterface, CDialog)
    ON_BN_CLICKED(IDC_BUTTON_CONFIG, &SubDlgThermalInterface::OnBnClickedButtonConfig)
    ON_BN_CLICKED(IDC_BUTTON_SELECT, &SubDlgThermalInterface::OnBnClickedButtonSelect)
    ON_BN_CLICKED(IDC_BUTTON_START_PREVIEW, &SubDlgThermalInterface::OnBnClickedButtonStartPreview)
    ON_BN_CLICKED(IDC_BUTTON_STOP_PREVIEW, &SubDlgThermalInterface::OnBnClickedButtonStopPreview)
    ON_WM_PAINT()
    ON_BN_CLICKED(IDC_BUTTON_CONFIG_STATE, &SubDlgThermalInterface::OnBnClickedButtonConfigState)
END_MESSAGE_MAP()


// SubDlgThermalInterface 消息处理程序


BOOL SubDlgThermalInterface::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  在此添加额外的初始化

    if (g_bEnglish)
    {
        m_combDecodeType.InsertString(0, _T("inside"));
        m_combDecodeType.InsertString(1, _T("external"));
    }
    else
    {
        m_combDecodeType.InsertString(0, _T("内部解码"));
        m_combDecodeType.InsertString(1, _T("外部解码"));
    }
    m_combDecodeType.SetCurSel(0);


    if (g_bEnglish)
    {
        //初始化 配置下拉列表     每一个配置功能一个Item
        m_cbConfig.InsertString(0, _T("Get video capability set"));
        m_cbConfig.InsertString(1, _T("Set event callback parameters")); //之前为获取音频能力
        m_cbConfig.InsertString(2, _T("Get video parameter"));
        m_cbConfig.InsertString(3, _T("Set video parameters"));
        m_cbConfig.InsertString(4, _T("Get audio parameters"));
        m_cbConfig.InsertString(5, _T("Set audio parameters"));
        m_cbConfig.InsertString(6, _T(""/*获取分辨率*/));
        m_cbConfig.InsertString(7, _T(""/*设置分辨率*/));
        m_cbConfig.InsertString(8, _T(""/*获取帧率*/));
        m_cbConfig.InsertString(9, _T(""/*设置帧率*/));
        m_cbConfig.InsertString(10, _T("Get device information"));
        m_cbConfig.InsertString(11, _T("Reboot device"));
        m_cbConfig.InsertString(12, _T("Restore to default parameters"));
        m_cbConfig.InsertString(13, _T("Get hardware service parameters"));
        m_cbConfig.InsertString(14, _T("Set hardware service parameters"));
        m_cbConfig.InsertString(15, _T("Get system time"));
        m_cbConfig.InsertString(16, _T("Set system time"));
        m_cbConfig.InsertString(17, _T("Get image brightness parameters"));
        m_cbConfig.InsertString(18, _T("Set image brightness parameters"));
        m_cbConfig.InsertString(19, _T("Get image contrast parameters"));
        m_cbConfig.InsertString(20, _T("Set image contrast parameters"));
        m_cbConfig.InsertString(21, _T("Upgrade"));
        m_cbConfig.InsertString(22, _T("Quick background correction"));
        m_cbConfig.InsertString(23, _T("Get system diagnosis data"));
        m_cbConfig.InsertString(24, _T("Quick manual correction"));
        m_cbConfig.InsertString(25, _T("Get image enhancement parameters"));
        m_cbConfig.InsertString(26, _T("Set image enhancement parameters"));
        m_cbConfig.InsertString(27, _T("Get video adjustment parameters"));
        m_cbConfig.InsertString(28, _T("Set video adjustment parameters"));
        m_cbConfig.InsertString(29, _T("Get basic thermography parameters"));
        m_cbConfig.InsertString(30, _T("Set basic thermography parameters"));
        m_cbConfig.InsertString(31, _T("Get thermography mode"));
        m_cbConfig.InsertString(32, _T("Set thermography mode"));
        m_cbConfig.InsertString(33, _T("Get thermography rules"));
        m_cbConfig.InsertString(34, _T("Set thermography rules"));
        m_cbConfig.InsertString(35, _T("Get thermography algorithm version"));
        m_cbConfig.InsertString(36, _T("Set thermography algorithm version"));
        m_cbConfig.InsertString(37, _T("Get the stream parameters of thermal imaging"));
        m_cbConfig.InsertString(38, _T("Set the streaming parameters of thermal imaging"));
        m_cbConfig.InsertString(39, _T("Get thermography correction parameters"));
        m_cbConfig.InsertString(40, _T("Set thermography correction parameters"));
        m_cbConfig.InsertString(41, _T("Get blackbody parameters"));
        m_cbConfig.InsertString(42, _T("Set blackbody parameters"));
        m_cbConfig.InsertString(43, _T("Get body temperature compensation parameters"));
        m_cbConfig.InsertString(44, _T("Set body temperature compensation parameters"));
        m_cbConfig.InsertString(45, _T("Get thermal graph"));
        m_cbConfig.InsertString(46, _T("Get the highest temperature in full screen temperature"));
        m_cbConfig.InsertString(47, _T("Get full screen temperature parameters"));
        m_cbConfig.InsertString(48, _T("Set full screen temperature parameters"));
        m_cbConfig.InsertString(49, _T(""/*双光校准（无效）*/));
        m_cbConfig.InsertString(50, _T(""/*双光校准*/));
        m_cbConfig.InsertString(51, _T(""/*获取双光校准坐标控制参数*/));
        m_cbConfig.InsertString(52, _T(""/*设置双光校准坐标控制参数*/));
        m_cbConfig.InsertString(53, _T("Get thermography calibration file"));
        m_cbConfig.InsertString(54, _T("Import thermography calibration file"));
        m_cbConfig.InsertString(55, _T("Get expert thermography rule parameters"));
        m_cbConfig.InsertString(56, _T("Set expert thermography rule parameters"));
        m_cbConfig.InsertString(57, _T("Get expert thermography correction parameters"));
        m_cbConfig.InsertString(58, _T("Set expert thermography correction parameters"));
        m_cbConfig.InsertString(59, _T("Start expert thermography correction"));
        m_cbConfig.InsertString(60, _T("Get thermography rise parameters"));
        m_cbConfig.InsertString(61, _T("Set thermography rise parameters"));
        m_cbConfig.InsertString(62, _T("Get envirotemperature correction"));
        m_cbConfig.InsertString(63, _T("Set envirotemperature correction"));
    }
    else
    {
        //初始化 配置下拉列表     每一个配置功能一个Item
        m_cbConfig.InsertString(0, _T("获取视频能力"));
        m_cbConfig.InsertString(1, _T("设置插拔事件回调")); //之前为获取音频能力
        m_cbConfig.InsertString(2, _T("获取视频格式"));
        m_cbConfig.InsertString(3, _T("设置视频格式"));
        m_cbConfig.InsertString(4, _T("获取音频格式"));
        m_cbConfig.InsertString(5, _T("设置音频格式"));
        m_cbConfig.InsertString(6, _T("获取分辨率"));
        m_cbConfig.InsertString(7, _T("设置分辨率"));
        m_cbConfig.InsertString(8, _T("获取帧率"));
        m_cbConfig.InsertString(9, _T("设置帧率"));
        m_cbConfig.InsertString(10, _T("获取设备信息"));
        m_cbConfig.InsertString(11, _T("设备重启"));
        m_cbConfig.InsertString(12, _T("恢复默认"));
        m_cbConfig.InsertString(13, _T("获取硬件服务参数"));
        m_cbConfig.InsertString(14, _T("设置硬件服务参数"));
        m_cbConfig.InsertString(15, _T("获取系统本地时间"));
        m_cbConfig.InsertString(16, _T("设置系统本地时间"));
        m_cbConfig.InsertString(17, _T("获取图像亮度参数"));
        m_cbConfig.InsertString(18, _T("设置图像亮度参数"));
        m_cbConfig.InsertString(19, _T("获取图像对比度参数"));
        m_cbConfig.InsertString(20, _T("设置图像对比度参数"));
        m_cbConfig.InsertString(21, _T("设备升级"));
        m_cbConfig.InsertString(22, _T("一键背景校正"));
        m_cbConfig.InsertString(23, _T("诊断信息导出"));
        m_cbConfig.InsertString(24, _T("一键手动校正"));
        m_cbConfig.InsertString(25, _T("获取图像增强参数"));
        m_cbConfig.InsertString(26, _T("设置图像增强参数"));
        m_cbConfig.InsertString(27, _T("获取视频调整参数"));
        m_cbConfig.InsertString(28, _T("设置视频调整参数"));
        m_cbConfig.InsertString(29, _T("获取测温基本参数"));
        m_cbConfig.InsertString(30, _T("设置测温基本参数"));
        m_cbConfig.InsertString(31, _T("获取测温模式"));
        m_cbConfig.InsertString(32, _T("设置测温模式"));
        m_cbConfig.InsertString(33, _T("获取测温规则参数"));
        m_cbConfig.InsertString(34, _T("设置测温规则参数"));
        m_cbConfig.InsertString(35, _T("获取热成像相关算法版本信息"));
        m_cbConfig.InsertString(36, _T("设置热成像相关算法版本信息"));
        m_cbConfig.InsertString(37, _T("获取热成像码流参数"));
        m_cbConfig.InsertString(38, _T("设置热成像码流参数"));
        m_cbConfig.InsertString(39, _T("获取测温修正参数"));
        m_cbConfig.InsertString(40, _T("设置测温修正参数"));
        m_cbConfig.InsertString(41, _T("获取黑体参数"));
        m_cbConfig.InsertString(42, _T("设置黑体参数"));
        m_cbConfig.InsertString(43, _T("获取体温补偿参数"));
        m_cbConfig.InsertString(44, _T("设置体温补偿参数"));
        m_cbConfig.InsertString(45, _T("获取热图"));
        m_cbConfig.InsertString(46, _T("区域最高温信息查询"));
        m_cbConfig.InsertString(47, _T("获取全屏测温参数"));
        m_cbConfig.InsertString(48, _T("设置全屏测温参数"));
        m_cbConfig.InsertString(49, _T("双光校准（无效）"));
        m_cbConfig.InsertString(50, _T("双光校准"));
        m_cbConfig.InsertString(51, _T("获取双光校准坐标控制参数"));
        m_cbConfig.InsertString(52, _T("设置双光校准坐标控制参数"));
        m_cbConfig.InsertString(53, _T("测温标定文件导出"));
        m_cbConfig.InsertString(54, _T("测温标定文件导入"));
        m_cbConfig.InsertString(55, _T("获取专家测温区域"));
        m_cbConfig.InsertString(56, _T("设置专家测温区域"));
        m_cbConfig.InsertString(57, _T("获取专家测温矫正参数"));
        m_cbConfig.InsertString(58, _T("设置专家测温矫正参数"));
        m_cbConfig.InsertString(59, _T("开启专家侧温矫正"));
        m_cbConfig.InsertString(60, _T("获取温升配置参数"));
        m_cbConfig.InsertString(61, _T("设置温升配置参数"));
        m_cbConfig.InsertString(62, _T("获取环境温度校正参数"));
        m_cbConfig.InsertString(63, _T("设置环境温度校正参数"));
    }
    m_cbConfig.SetCurSel(0);


//     CClientDemoDlg* pDlg = (CClientDemoDlg*)GetParent();
//     m_lUserID = pDlg->m_lUserID;

    m_hVideoWnd = m_PreviewWindow.GetSafeHwnd();

    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常:  OCX 属性页应返回 FALSE
}

#define BUFFER_LEN 1024 * 1024 

void SubDlgThermalInterface::OnBnClickedButtonConfig()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);

    USB_VIDEO_CAPACITY struVideoCap[32] = { 0 };
    USB_VIDEO_PARAM struVideoParam = { 0 };
    USB_CONTROL_INPUT_INFO struControlInputInfo = { 0 };
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
    USB_COMMON_COND struCond = { 0 };
    USB_SYSTEM_DEVICE_INFO struSysDevInfo = { 0 };
    USB_SYSTEM_HARDWARE_SERVER struHardware = { 0 };
    USB_SYSTEM_LOCALTIME struSysTime = { 0 };
    USB_IMAGE_BRIGHTNESS struImageBrightness = { 0 };
    USB_IMAGE_CONTRAST struImageContrast = { 0 };
    USB_SYSTEM_DIAGNOSED_DATA_COND struSysDiagnosedDataCond = { 0 };
    USB_SYSTEM_DIAGNOSED_DATA struSysDiagnosedData = { 0 };
    USB_IMAGE_ENHANCEMENT struImageEnhancement = { 0 };
    USB_IMAGE_VIDEO_ADJUST struImageVideoAdjuse = { 0 };
    USB_THERMOMETRY_BASIC_PARAM struThermometryBasicParam = { 0 };
    USB_THERMOMETRY_MODE struThermometryMode = { 0 };
    USB_THERMOMETRY_REGIONS struThermometryRegions = { 0 };
    USB_THERMAL_ALG_VERSION struThermalAlgVersion = { 0 };
    USB_THERMAL_STREAM_PARAM struThermalStreamParam = { 0 };
    USB_TEMPERATURE_CORRECT struTemperatureCorrect = { 0 };
    USB_BLACK_BODY struBlackBody = { 0 };
    USB_BODYTEMP_COMPENSATION struBodytempCompensation = { 0 };
    USB_JPEGPIC_WITH_APPENDDATA struJpegpicWithAppendData = { 0 };
    USB_ROI_MAX_TEMPERATURE_SEARCH struRoiMaxTemperatureSearch = { 0 };
    USB_ROI_MAX_TEMPERATURE_SEARCH_RESULT struRoiMaxTemperatureSearchResult = { 0 };
    USB_P2P_PARAM struP2pParam = { 0 };
    USB_DOUBLE_LIGHTS_CORRECT struDoubleLightsCorrect = { 0 };
    USB_DOUBLE_LIGHTS_CORRECT_RESULT struDoubleLightsCorrectResult = { 0 };
    USB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL struDoubleLightsCorrectPointsCtrl = { 0 };
    USB_THERMOMETRY_CALIBRATION_FILE struThermometryCalibrationFile = { 0 };
    USB_THERMOMETRY_EXPERT_REGIONS struExpertRegion = { 0 };
    USB_THERMOMETRY_EXPERT_CORRECTION_PARAM struCorrectionParam = { 0 };
    USB_THERMOMETRY_RISE_SETTINGS struRiseSettings = { 0 };
    USB_ENVIROTEMPERATURE_CORRECT struEnvirotemperatureCorrect = { 0 };
    USB_EVENT_CALLBACK_PARAM struEventCallBack = { 0 };

    int iReadSize = 0;

    int iIndex = m_cbConfig.GetCurSel();
    //转化为命令码
    iIndex = USB_THERMAL_BASE + iIndex + 1;

    BYTE *pData = new BYTE[BUFFER_LEN];
    BYTE *pData2 = new BYTE[BUFFER_LEN];
	char szFilePath[128] = { 0 };
    //while (1)
    //{
    //    memset(&struVideoCap, 0, sizeof(struVideoCap));
    //    struConfigOutputInfo.lpOutBuffer = struVideoCap;
    //    struConfigOutputInfo.dwOutBufferSize = sizeof(struVideoCap);
    //    //获取设备支持的视频格式
    //    USB_GetDeviceConfig(m_lUserID, USB_GET_VIDEO_CAP, &struConfigInputInfo, &struConfigOutputInfo);

    //    struVideoParam.dwVideoFormat = USB_STREAM_MJPEG;
    //    struVideoParam.dwWidth = 240;
    //    struVideoParam.dwHeight = 320;
    //    struVideoParam.dwFramerate = 30;

    //    memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
    //    memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

    //    struConfigInputInfo.lpInBuffer = &struVideoParam;
    //    struConfigInputInfo.dwInBufferSize = sizeof(struVideoParam);

    //    //设置设备视频参数
    //    USB_SetDeviceConfig(m_lUserID, USB_SET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo);
    //    struConfigOutputInfo.lpOutBuffer = &struVideoParam;
    //    struConfigOutputInfo.dwOutBufferSize = sizeof(struVideoParam);

    //    USB_GetDeviceConfig(m_lUserID, USB_GET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo);

    //    Sleep(3000);
    //}

    FILE *fd;
    switch (iIndex)
    {
    case 2001://获取视频能力     用于测试前端设备
        memset(&struVideoCap, 0, sizeof(struVideoCap));
        struConfigOutputInfo.lpOutBuffer = struVideoCap;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struVideoCap);
        //获取设备支持的视频格式
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VIDEO_CAP, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_SYSTEM_DEVICE_INFO");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VIDEO_CAP   byDeviceTypenType[%d] ", struVideoCap->nType);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VIDEO_CAP   byEncoderVersion[%d] ", struVideoCap->dwWidth);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VIDEO_CAP   byFirmwareVersion[%d] ", struVideoCap->dwHeight);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VIDEO_CAP   byHardwareVersion[%d] ", struVideoCap->lFrameRates[0]);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VIDEO_CAP   byHardwareVersion[%d] ", struVideoCap->lListSize);
        }
        break;
    case 2002:
        //设置事件回调函数
        struEventCallBack.funcEventCallBack = (fnEventCallBack)SubDlgThermalInterface::OnEventCallBack;
        struEventCallBack.pUser = this;

        struConfigInputInfo.lpInBuffer = &struEventCallBack;
        struConfigInputInfo.dwInBufferSize = sizeof(struEventCallBack);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_EVENT_CALLBACK, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_EVENT_CALLBACK");
        }
        LOGIN_INFO->WriteLog(ERR_LEVEL, "SUCCESS  USB_SET_EVENT_CALLBACK");
        break;
    case 2004://设置视频参数     用于测试前端设备
        struVideoParam.dwVideoFormat = USB_STREAM_MJPEG;
        struVideoParam.dwWidth = 240;
        struVideoParam.dwHeight = 320;
        struVideoParam.dwFramerate = 30;

        memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
        memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

        struConfigInputInfo.lpInBuffer = &struVideoParam;
        struConfigInputInfo.dwInBufferSize = sizeof(struVideoParam);

        //设置设备视频参数
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_SYSTEM_DEVICE_INFO");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VIDEO_PARAM   dwVideoFormat[%d] ", struVideoParam.dwVideoFormat);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VIDEO_PARAM   dwWidth[%d] ", struVideoParam.dwWidth);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VIDEO_PARAM   dwHeight[%d] ", struVideoParam.dwHeight);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VIDEO_PARAM   dwFramerate[%d] ", struVideoParam.dwFramerate);
        }
        break;
    case USB_GET_SYSTEM_DEVICE_INFO://获取设备信息
        struSysDevInfo.dwSize = sizeof(struSysDevInfo);
        struConfigOutputInfo.lpOutBuffer = &struSysDevInfo;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struSysDevInfo);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_DEVICE_INFO, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_SYSTEM_DEVICE_INFO");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   byDeviceType[%s] ", struSysDevInfo.byDeviceType);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   byEncoderVersion[%s] ", struSysDevInfo.byEncoderVersion);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   byFirmwareVersion[%s] ", struSysDevInfo.byFirmwareVersion);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   byHardwareVersion[%s] ", struSysDevInfo.byHardwareVersion);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   byProtocolVersion[%s] ", struSysDevInfo.byProtocolVersion);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   bySerialNumber[%s] ", struSysDevInfo.bySerialNumber);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   bySecondHardwareVersion[%s] ", struSysDevInfo.bySecondHardwareVersion);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   byModuleID[%s] ", struSysDevInfo.byModuleID);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_SYSTEM_DEVICE_INFO   byDeviceID[%s] ", struSysDevInfo.byDeviceID);
        }
        break;
    case USB_SET_SYSTEM_REBOOT:
        if (!USB_Control(m_lUserID, USB_SET_SYSTEM_REBOOT, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_SYSTEM_REBOOT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_SYSTEM_REBOOT");
        }
        break;
    case USB_SET_SYSTEM_RESET: //恢复默认
        if (!USB_Control(m_lUserID, USB_SET_SYSTEM_RESET, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_SYSTEM_RESET");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_SYSTEM_RESET");
        }
        break;
    case USB_GET_SYSTEM_HARDWARE_SERVER: //获取硬件服务参数
        struHardware.dwSize = sizeof(struHardware);
        struConfigOutputInfo.lpOutBuffer = &struHardware;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struHardware);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_HARDWARE_SERVER, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_SYSTEM_HARDWARE_SERVER");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_HARDWARE_SERVER  byUsbMode[%d] ", struHardware.byUsbMode);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_HARDWARE_SERVER  byDeviceInitialStatus[%d] ", struHardware.byDeviceInitialStatus);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_HARDWARE_SERVER  byDeviceWorkingStatus[%d] ", struHardware.byDeviceWorkingStatus);
        }
        break;
    case USB_SET_SYSTEM_HARDWARE_SERVER: //设置硬件服务参数
        struHardware.dwSize = sizeof(struHardware);
        struHardware.byUsbMode = 1; //设置为uvc模式
        struConfigInputInfo.lpInBuffer = &struHardware;
        struConfigInputInfo.dwInBufferSize = sizeof(struHardware);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_SYSTEM_HARDWARE_SERVER, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_SYSTEM_HARDWARE_SERVER");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_SYSTEM_HARDWARE_SERVER  byUsbMode[%d] ", struHardware.byUsbMode);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_HARDWARE_SERVER  byDeviceInitialStatus[%d] ", struHardware.byDeviceInitialStatus);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_HARDWARE_SERVER  byDeviceWorkingStatus[%d] ", struHardware.byDeviceWorkingStatus);
        }
        break;
    case USB_GET_SYSTEM_LOCALTIME: //获取系统本地时间
        struSysTime.dwSize = sizeof(struSysTime);
        struConfigOutputInfo.lpOutBuffer = &struSysTime;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struSysTime);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_LOCALTIME, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_SYSTEM_LOCALTIME");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_LOCALTIME  time[%d-%d-%d %d:%d:%d.%d] ",
                struSysTime.wYear, struSysTime.byMonth, struSysTime.byDay, struSysTime.byHour, struSysTime.byMinute,
                struSysTime.bySecond, struSysTime.wMillisecond);
        }
        break;
    case USB_SET_SYSTEM_LOCALTIME: //设置系统本地时间
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        struSysTime.wYear = sys.wYear;
        struSysTime.byMonth = sys.wMonth;
        struSysTime.byDay = sys.wDay;
        struSysTime.byHour = sys.wHour;
        struSysTime.byMinute = sys.wMinute;
        struSysTime.bySecond = sys.wSecond;
        struSysTime.wMillisecond = sys.wMilliseconds;
        struSysTime.byExternalTimeSourceEnabled = 0; //关闭外部校时
        struSysTime.dwSize = sizeof(struSysTime);
        struConfigInputInfo.lpInBuffer = &struSysTime;
        struConfigInputInfo.dwInBufferSize = sizeof(struSysTime);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_SYSTEM_LOCALTIME, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_SYSTEM_LOCALTIME");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_SYSTEM_LOCALTIME  time[%d-%d-%d %d:%d:%d.%d] ",
                struSysTime.wYear, struSysTime.byMonth, struSysTime.byDay, struSysTime.byHour, struSysTime.byMinute, struSysTime.bySecond, struSysTime.wMillisecond);
        }
        break;
    case USB_GET_IMAGE_BRIGHTNESS: //获取图像亮度参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struConfigOutputInfo.lpOutBuffer = &struImageBrightness;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struImageBrightness);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_BRIGHTNESS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_IMAGE_BRIGHTNESS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_IMAGE_BRIGHTNESS  dwBrightness[%d] ", struImageBrightness.dwBrightness);
        }
        break;
    case USB_SET_IMAGE_BRIGHTNESS: //设置图像亮度参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struImageBrightness.dwBrightness = 40; //亮度50
        struConfigInputInfo.lpInBuffer = &struImageBrightness;
        struConfigInputInfo.dwInBufferSize = sizeof(struImageBrightness);
        if (!USB_GetDeviceConfig(m_lUserID, USB_SET_IMAGE_BRIGHTNESS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_IMAGE_BRIGHTNESS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_IMAGE_BRIGHTNESS  dwBrightness[%d] ", struImageBrightness.dwBrightness);
        }
        break;
    case USB_GET_IMAGE_CONTRAST: //获取图像对比度参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struConfigOutputInfo.lpOutBuffer = &struImageContrast;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struImageContrast);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_CONTRAST, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_IMAGE_CONTRAST");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_IMAGE_CONTRAST  dwContrast[%d] ", struImageContrast.dwContrast);
        }
        break;
    case USB_SET_IMAGE_CONTRAST: //设置图像对比度参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struImageContrast.dwContrast = 50; //对比度50
        struConfigInputInfo.lpInBuffer = &struImageContrast;
        struConfigInputInfo.dwInBufferSize = sizeof(struImageContrast);
        if (!USB_GetDeviceConfig(m_lUserID, USB_SET_IMAGE_CONTRAST, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_IMAGE_CONTRAST");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_IMAGE_CONTRAST  dwContrast[%d] ", struImageContrast.dwContrast);
        }
        break;
    case USB_SET_SYSTEM_UPDATE_FIRMWARE: //设备升级
    {
        CDlgUpgrade  dlg;
        dlg.m_lUserID = m_lUserID;
        dlg.DoModal();
        break;
    }
    case USB_SET_IMAGE_BACKGROUND_CORRECT: //一键背景校正
        struCond.byChannelID = 1;
        struControlInputInfo.lpCondBuffer = &struCond;
        struControlInputInfo.dwCondBufferSize = sizeof(struCond);

        if (!USB_Control(m_lUserID, USB_SET_IMAGE_BACKGROUND_CORRECT, &struControlInputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_IMAGE_BACKGROUND_CORRECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_IMAGE_BACKGROUND_CORRECT");
        }
        break;
    case USB_GET_SYSTEM_DIAGNOSED_DATA: //诊断信息导出
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struSysDiagnosedData;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struSysDiagnosedData);

        struSysDiagnosedData.pDiagnosedData = pData;
        struSysDiagnosedData.dwDataLenth = BUFFER_LEN;

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_DIAGNOSED_DATA, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_SYSTEM_DIAGNOSED_DATA");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            if (struSysDiagnosedData.dwDataLenth > 0)
            {
                FILE *fd;
                fd = fopen("C:\\USBSDKLog\\diagnosefile", "wb");
                fwrite((void *)struSysDiagnosedData.pDiagnosedData, 1, struSysDiagnosedData.dwDataLenth, fd);
                fclose(fd);
            }
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_DIAGNOSED_DATA dwDataLenth[%d]", struSysDiagnosedData.dwDataLenth);
        }
        break;
    case USB_GET_SYSTEM_DIAGNOSED_DATA_EX://带参数条件诊断信息导出
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struSysDiagnosedDataCond.byDataType = 1; //1-PSRAM, 2-FLASH
        struSysDiagnosedDataCond.dwAddress = 0xaabb;
        struSysDiagnosedDataCond.dwLength = 50 * 1024;//50k
        //条件参数输入
        struConfigInputInfo.lpInBuffer = &struSysDiagnosedDataCond;
        struConfigInputInfo.dwInBufferSize = sizeof(struSysDiagnosedDataCond);

        struSysDiagnosedData.pDiagnosedData = pData;
        struSysDiagnosedData.dwDataLenth = BUFFER_LEN;
        //诊断文件输出
        struConfigOutputInfo.lpOutBuffer = &struSysDiagnosedData;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struSysDiagnosedData);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_DIAGNOSED_DATA_EX, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_SYSTEM_DIAGNOSED_DATA_EX");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            if (struSysDiagnosedData.dwDataLenth > 0)
            {
                FILE *fd;
                fd = fopen("C:\\USBSDKLog\\diagnosefile", "wb");
                fwrite((void *)struSysDiagnosedData.pDiagnosedData, 1, struSysDiagnosedData.dwDataLenth, fd);
                fclose(fd);
            }
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_SYSTEM_DIAGNOSED_DATA_EX dwDataLenth[%d]", struSysDiagnosedData.dwDataLenth);
        }

        break;
    case USB_SET_IMAGE_MANUAL_CORRECT: //一键手动校正
        struCond.byChannelID = 1;
        struControlInputInfo.lpCondBuffer = &struCond;
        struControlInputInfo.dwCondBufferSize = sizeof(struCond);

        if (!USB_Control(m_lUserID, USB_SET_IMAGE_MANUAL_CORRECT, &struControlInputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_IMAGE_MANUAL_CORRECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_IMAGE_MANUAL_CORRECT");
        }
        break;
    case USB_GET_IMAGE_ENHANCEMENT: //获取图像增强参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struImageEnhancement;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struImageEnhancement);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_ENHANCEMENT, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_IMAGE_ENHANCEMENT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_IMAGE_ENHANCEMENT byNoiseReduceMode[%d] dwGeneralLevel[%d] dwFrameNoiseReduceLevel[%d] dwInterFrameNoiseReduceLevel[%d] byPaletteMode[%d] byLSEDetailEnabled[%d] dwLSEDetailLevel[%d]",
                struImageEnhancement.byNoiseReduceMode, struImageEnhancement.dwGeneralLevel, struImageEnhancement.dwFrameNoiseReduceLevel, struImageEnhancement.dwInterFrameNoiseReduceLevel, struImageEnhancement.byPaletteMode, struImageEnhancement.byLSEDetailEnabled, struImageEnhancement.dwLSEDetailLevel);
        }
        break;
    case USB_SET_IMAGE_ENHANCEMENT: //设置图像增强参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);


        struImageEnhancement.byNoiseReduceMode = 2; // 专家模式
        struImageEnhancement.dwGeneralLevel = 50;
        struImageEnhancement.dwFrameNoiseReduceLevel = 50;
        struImageEnhancement.dwInterFrameNoiseReduceLevel = 50;
        struImageEnhancement.byPaletteMode = 1;
        struImageEnhancement.byLSEDetailEnabled = 1;
        struImageEnhancement.dwLSEDetailLevel = 50;
        struConfigInputInfo.lpInBuffer = &struImageEnhancement;
        struConfigInputInfo.dwInBufferSize = sizeof(struImageEnhancement);

        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_IMAGE_ENHANCEMENT, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_IMAGE_ENHANCEMENT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_IMAGE_ENHANCEMENT byNoiseReduceMode[%d] dwGeneralLevel[%d] dwFrameNoiseReduceLevel[%d] dwInterFrameNoiseReduceLevel[%d] byPaletteMode[%d] byLSEDetailEnabled[%d] dwLSEDetailLevel[%d]",
                struImageEnhancement.byNoiseReduceMode, struImageEnhancement.dwGeneralLevel, struImageEnhancement.dwFrameNoiseReduceLevel, struImageEnhancement.dwInterFrameNoiseReduceLevel, struImageEnhancement.byPaletteMode, struImageEnhancement.byLSEDetailEnabled, struImageEnhancement.dwLSEDetailLevel);
        }
        break;
    case USB_GET_IMAGE_VIDEO_ADJUST: //获取视频调整参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struImageVideoAdjuse;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struImageVideoAdjuse);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_VIDEO_ADJUST, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_IMAGE_VIDEO_ADJUST");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_IMAGE_VIDEO_ADJUST byImageFlipStyle[%d] byPowerLineFrequencyMode[%d] byCorridor[%d] ",
                struImageVideoAdjuse.byImageFlipStyle, struImageVideoAdjuse.byPowerLineFrequencyMode, struImageVideoAdjuse.byCorridor);
        }
        break;
    case USB_SET_IMAGE_VIDEO_ADJUST: //设置视频调整参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struImageVideoAdjuse.byImageFlipStyle = 1;
        struImageVideoAdjuse.byPowerLineFrequencyMode = 1;
        struImageVideoAdjuse.byCorridor = 1;
        struConfigInputInfo.lpInBuffer = &struImageVideoAdjuse;
        struConfigInputInfo.dwInBufferSize = sizeof(struImageVideoAdjuse);

        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_IMAGE_VIDEO_ADJUST, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_IMAGE_VIDEO_ADJUST");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_IMAGE_VIDEO_ADJUST byImageFlipStyle[%d] byPowerLineFrequencyMode[%d] byCorridor[%d] ",
                struImageVideoAdjuse.byImageFlipStyle, struImageVideoAdjuse.byPowerLineFrequencyMode, struImageVideoAdjuse.byCorridor);
        }
        break;
    case USB_GET_THERMOMETRY_BASIC_PARAM: //获取测温基本参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struThermometryBasicParam;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryBasicParam);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_BASIC_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_BASIC_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMOMETRY_BASIC_PARAM byImageFlipStyle[%d] byDisplayMaxTemperatureEnabled[%d] byDisplayMinTemperatureEnabled[%d] dwAlert[%d] dwAlarm[%d] dwExternalOpticsTransmit[%d]",
                struThermometryBasicParam.byEnabled, struThermometryBasicParam.byDisplayMaxTemperatureEnabled, struThermometryBasicParam.byDisplayMinTemperatureEnabled, struThermometryBasicParam.dwAlert, struThermometryBasicParam.dwAlarm,
                struThermometryBasicParam.dwExternalOpticsTransmit);
        }
        break;
    case USB_SET_THERMOMETRY_BASIC_PARAM: //设置测温基本参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struThermometryBasicParam;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryBasicParam);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_BASIC_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_BASIC_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struThermometryBasicParam.byEnabled = 0;
            struThermometryBasicParam.byDisplayMaxTemperatureEnabled = 0;
            struThermometryBasicParam.byDisplayMinTemperatureEnabled = 0;
            struThermometryBasicParam.byDisplayAverageTemperatureEnabled = 0;
            struThermometryBasicParam.byTemperatureUnit = 1;
            struThermometryBasicParam.byTemperatureRange = 1;
            struThermometryBasicParam.byCalibrationCoefficientEnabled = 1;
            struThermometryBasicParam.dwCalibrationCoefficient = 2;
            struThermometryBasicParam.dwExternalOpticsWindowCorrection = 980;
            struThermometryBasicParam.dwEmissivity = 95;
            struThermometryBasicParam.byDistanceUnit = 2;
            struThermometryBasicParam.dwDistance = 1;
            struThermometryBasicParam.byReflectiveEnable = 1;
            struThermometryBasicParam.dwReflectiveTemperature = 980;
            struThermometryBasicParam.byShowAlarmColorEnabled = 1;
            struConfigInputInfo.lpInBuffer = &struThermometryBasicParam;
            struConfigInputInfo.dwInBufferSize = sizeof(struThermometryBasicParam);
            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_BASIC_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_THERMOMETRY_BASIC_PARAM");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMOMETRY_BASIC_PARAM byImageFlipStyle[%d] byDisplayMaxTemperatureEnabled[%d] byDisplayMinTemperatureEnabled[%d] ",
                    struThermometryBasicParam.byEnabled, struThermometryBasicParam.byDisplayMaxTemperatureEnabled, struThermometryBasicParam.byDisplayMinTemperatureEnabled);
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMOMETRY_BASIC_PARAM byShowAlarmColorEnabled[%d]", struThermometryBasicParam.byShowAlarmColorEnabled);
            }
        }
        break;
    case USB_GET_THERMOMETRY_MODE: //获取测温模式
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struThermometryMode;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryMode);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_MODE, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_MODE");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMOMETRY_MODE byThermometryMode[%d] byThermometryROIEnabled[%d]",
                struThermometryMode.byThermometryMode, struThermometryMode.byThermometryROIEnabled);
        }
        break;
    case USB_SET_THERMOMETRY_MODE: //设置测温模式
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struThermometryMode.byThermometryMode = 2;//专家
        struThermometryMode.byThermometryROIEnabled = 1;
        struConfigInputInfo.lpInBuffer = &struThermometryMode;
        struConfigInputInfo.dwInBufferSize = sizeof(struThermometryMode);

        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_MODE, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_THERMOMETRY_MODE");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMOMETRY_MODE byThermometryMode[%d] byThermometryROIEnabled[%d]",
                struThermometryMode.byThermometryMode, struThermometryMode.byThermometryROIEnabled);
        }
        break;
    case USB_GET_THERMOMETRY_REGIONS: //获取测温规则参数
        struCond.byChannelID = 1;
        struCond.bySID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struThermometryRegions;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryRegions);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_REGIONS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_REGIONS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMOMETRY_REGIONS bySID[%d] byRegionNum[%d]",
                struCond.bySID, struThermometryRegions.byRegionNum);
        }
        break;
    case USB_SET_THERMOMETRY_REGIONS: //设置测温规则参数
        struCond.byChannelID = 1;
        struCond.bySID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struThermometryRegions;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryRegions);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_REGIONS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_REGIONS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struThermometryRegions.dwSize = sizeof(struThermometryRegions);
            struThermometryRegions.byRegionNum = 1;
            struThermometryRegions.struRegion[0].byRegionID = 1;
            struThermometryRegions.struRegion[0].byRegionEnabled = 1;
            struThermometryRegions.struRegion[0].dwRegionX = 11;
            struThermometryRegions.struRegion[0].dwRegionY = 10;
            struThermometryRegions.struRegion[0].dwRegionWidth = 10;
            struThermometryRegions.struRegion[0].dwRegionHeight = 10;

            struConfigInputInfo.lpInBuffer = &struThermometryRegions;
            struConfigInputInfo.dwInBufferSize = sizeof(struThermometryRegions);

            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_REGIONS, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_THERMOMETRY_REGIONS");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMOMETRY_REGIONS bySID[%d] byRegionNum[%d]",
                    struCond.bySID, struThermometryRegions.byRegionNum);
            }
        }
        break;
    case USB_GET_THERMAL_ALG_VERSION: //获取热成像相关算法版本信息
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struThermalAlgVersion;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermalAlgVersion);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMAL_ALG_VERSION, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_REGIONS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMOMETRY_REGIONS dwSize[%d] byThermometryAlgName[%s]",
                struThermalAlgVersion.dwSize, struThermalAlgVersion.byThermometryAlgName);
        }
        break;
    case USB_GET_THERMAL_STREAM_PARAM: //获取热成像码流参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struThermalStreamParam;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermalStreamParam);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMAL_STREAM_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMAL_STREAM_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMAL_STREAM_PARAM dwSize[%d] byVideoCodingType[%d]",
                struThermalStreamParam.dwSize, struThermalStreamParam.byVideoCodingType);
        }
        break;
    case USB_SET_THERMAL_STREAM_PARAM: //设置热成像码流参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struThermalStreamParam.byVideoCodingType = 2;//全屏测温数据
        struConfigInputInfo.lpInBuffer = &struThermalStreamParam;
        struConfigInputInfo.dwInBufferSize = sizeof(struThermalStreamParam);

        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMAL_STREAM_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_THERMAL_STREAM_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMAL_STREAM_PARAM dwSize[%d] byVideoCodingType[%d]",
                struThermalStreamParam.dwSize, struThermalStreamParam.byVideoCodingType);
        }
        break;
    case USB_GET_TEMPERATURE_CORRECT: //获取测温修正参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struTemperatureCorrect;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struTemperatureCorrect);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_TEMPERATURE_CORRECT, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_TEMPERATURE_CORRECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_TEMPERATURE_CORRECT dwSize[%d] byEnabled[%d]",
                struTemperatureCorrect.dwSize, struTemperatureCorrect.byEnabled);
        }
        break;
    case USB_SET_TEMPERATURE_CORRECT: //设置测温修正参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struTemperatureCorrect;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struTemperatureCorrect);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_TEMPERATURE_CORRECT, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_TEMPERATURE_CORRECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struConfigInputInfo.lpInBuffer = &struTemperatureCorrect;
            struConfigInputInfo.dwInBufferSize = sizeof(struTemperatureCorrect);

            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_TEMPERATURE_CORRECT, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_TEMPERATURE_CORRECT");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_TEMPERATURE_CORRECT dwSize[%d] byEnabled[%d]",
                    struTemperatureCorrect.dwSize, struTemperatureCorrect.byEnabled);
            }
        }
        break;
    case USB_GET_BLACK_BODY: //获取黑体参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struBlackBody;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struBlackBody);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BLACK_BODY, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_BLACK_BODY");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_BLACK_BODY dwSize[%d] byEnabled[%d]",
                struBlackBody.dwSize, struBlackBody.byEnabled);
        }
        break;
    case USB_SET_BLACK_BODY: //获取黑体参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struBlackBody;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struBlackBody);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BLACK_BODY, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_BLACK_BODY");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struConfigInputInfo.lpInBuffer = &struBlackBody;
            struConfigInputInfo.dwInBufferSize = sizeof(struBlackBody);

            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_BLACK_BODY, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_BLACK_BODY");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_BLACK_BODY dwSize[%d] byEnabled[%d]",
                    struBlackBody.dwSize, struBlackBody.byEnabled);
            }
        }
        break;
    case USB_GET_BODYTEMP_COMPENSATION: //获取体温补偿参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struBodytempCompensation;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struBodytempCompensation);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BODYTEMP_COMPENSATION, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_BODYTEMP_COMPENSATION");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_BODYTEMP_COMPENSATION dwSize[%d] byEnabled[%d]",
                struBodytempCompensation.dwSize, struBodytempCompensation.byEnabled);
        }
        break;
    case USB_SET_BODYTEMP_COMPENSATION: //设置体温补偿参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struBodytempCompensation;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struBodytempCompensation);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BODYTEMP_COMPENSATION, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_BODYTEMP_COMPENSATION");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struConfigInputInfo.lpInBuffer = &struBodytempCompensation;
            struConfigInputInfo.dwInBufferSize = sizeof(struBodytempCompensation);

            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_BODYTEMP_COMPENSATION, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_BODYTEMP_COMPENSATION");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_BODYTEMP_COMPENSATION dwSize[%d] byEnabled[%d]",
                    struBodytempCompensation.dwSize, struBodytempCompensation.byEnabled);
            }
        }
        break;
    case USB_GET_JPEGPIC_WITH_APPENDDATA: //获取热图
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struJpegpicWithAppendData.pP2pData = pData;
        struJpegpicWithAppendData.dwP2pDataLen = BUFFER_LEN;
        struJpegpicWithAppendData.pJpegPic = pData2;
        struJpegpicWithAppendData.dwJpegPicLen = BUFFER_LEN;
        struConfigOutputInfo.lpOutBuffer = &struJpegpicWithAppendData;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struJpegpicWithAppendData);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_JPEGPIC_WITH_APPENDDATA, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_JPEGPIC_WITH_APPENDDATA");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            if (struJpegpicWithAppendData.dwJpegPicLen > 0)
            {
                FILE *fd;
                fd = fopen("C:\\USBSDKLog\\append.jpg", "wb");
                fwrite((void *)struJpegpicWithAppendData.pJpegPic, 1, struJpegpicWithAppendData.dwJpegPicLen, fd);
                fclose(fd);
            }

            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_JPEGPIC_WITH_APPENDDATA dwSize[%d] dwJpegPicLen[%d]",
                struJpegpicWithAppendData.dwSize, struJpegpicWithAppendData.dwJpegPicLen);
        }
        break;

    case USB_GET_ROI_MAX_TEMPERATURE_SEARCH: //ROI最高温信息查询
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        GetLocalTime(&sys);
        struRoiMaxTemperatureSearch.wYear = sys.wYear;
        struRoiMaxTemperatureSearch.byMonth = sys.wMonth;
        struRoiMaxTemperatureSearch.byDay = sys.wDay;
        struRoiMaxTemperatureSearch.byHour = sys.wHour;
        struRoiMaxTemperatureSearch.byMinute = sys.wMinute;
        struRoiMaxTemperatureSearch.bySecond = sys.wSecond;
        struRoiMaxTemperatureSearch.wMillisecond = sys.wMilliseconds;

        struRoiMaxTemperatureSearch.byJpegPicEnabled = 1;
        struRoiMaxTemperatureSearch.byMaxTemperatureOverlay = 1;
        struRoiMaxTemperatureSearch.byRegionsOverlay = 1;
        struRoiMaxTemperatureSearch.byROIRegionNum = 2;
        struRoiMaxTemperatureSearch.struThermalROIRegion[0].byROIRegionID = 1;
        struRoiMaxTemperatureSearch.struThermalROIRegion[0].byROIRegionEnabled = 1;
        struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionX = 0;
        struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionY = 0;
        struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionHeight = 50;
        struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionWidth = 150;
        struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwDistance = 50;

        struRoiMaxTemperatureSearch.struThermalROIRegion[1].byROIRegionID = 2;
        struRoiMaxTemperatureSearch.struThermalROIRegion[1].byROIRegionEnabled = 1;
        struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionX = 70;
        struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionY = 110;
        struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionHeight = 10;
        struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionWidth = 10;
        struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwDistance = 100;

        //查询参数
        struConfigInputInfo.lpInBuffer = &struRoiMaxTemperatureSearch;
        struConfigInputInfo.dwInBufferSize = sizeof(struRoiMaxTemperatureSearch);


        struRoiMaxTemperatureSearchResult.pJpegPic = pData;
        struRoiMaxTemperatureSearchResult.dwJpegPicLen = BUFFER_LEN;
        //查询结果
        struConfigOutputInfo.lpOutBuffer = &struRoiMaxTemperatureSearchResult;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struRoiMaxTemperatureSearchResult);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_ROI_MAX_TEMPERATURE_SEARCH, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_ROI_MAX_TEMPERATURE_SEARCH");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            if (struRoiMaxTemperatureSearchResult.dwJpegPicLen > 0)
            {
                FILE *fd;
                fd = fopen("C:\\USBSDKLog\\roimax.jpg", "wb");
                fwrite((void *)struRoiMaxTemperatureSearchResult.pJpegPic, 1, struRoiMaxTemperatureSearchResult.dwJpegPicLen, fd);
                fclose(fd);
            }

            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_ROI_MAX_TEMPERATURE_SEARCH dwSize[%d] dwJpegPicLen[%d]",
                struRoiMaxTemperatureSearchResult.dwSize, struRoiMaxTemperatureSearchResult.dwJpegPicLen);
        }
        break;
    case USB_GET_P2P_PARAM: //获取全屏测温参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        //查询结果
        struConfigOutputInfo.lpOutBuffer = &struP2pParam;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struP2pParam);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_P2P_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_P2P_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            //if (struRoiMaxTemperatureSearchResult.dwJpegPicLen > 0)
            //{
            //    FILE *fd;
            //    fd = fopen("C:\\USBSDKLog\\roimax.jpeg", "r");
            //    fwrite((void *)struRoiMaxTemperatureSearchResult.pJpegPic, 1, struRoiMaxTemperatureSearchResult.dwJpegPicLen, fd);
            //    fclose(fd);
            //}

            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_P2P_PARAM dwSize[%d] byJpegPicEnabled[%d]",
                struP2pParam.dwSize, struP2pParam.byJpegPicEnabled);
        }
        break;
    case USB_SET_P2P_PARAM: //设置全屏测温参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struP2pParam.byJpegPicEnabled = 1;
        struConfigInputInfo.lpInBuffer = &struP2pParam;
        struConfigInputInfo.dwInBufferSize = sizeof(struP2pParam);

        //查询结果
        //struConfigOutputInfo.lpOutBuffer = &struP2pParam;
        //struConfigOutputInfo.dwOutBufferSize = sizeof(struP2pParam);

        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_P2P_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_P2P_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            //if (struRoiMaxTemperatureSearchResult.dwJpegPicLen > 0)
            //{
            //    FILE *fd;
            //    fd = fopen("C:\\USBSDKLog\\roimax.jpeg", "r");
            //    fwrite((void *)struRoiMaxTemperatureSearchResult.pJpegPic, 1, struRoiMaxTemperatureSearchResult.dwJpegPicLen, fd);
            //    fclose(fd);
            //}

            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_P2P_PARAM dwSize[%d] byJpegPicEnabled[%d]",
                struP2pParam.dwSize, struP2pParam.byJpegPicEnabled);
        }
        break;
    //case USB_POST_DOUBLE_LIGHTS_CORRECT: //双光校准
    //    struCond.byChannelID = 1;
    //    struConfigInputInfo.lpCondBuffer = &struCond;
    //    struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

    //    //可见光图片
    //    FILE *fd;
    //    fd = fopen("C:\\USBSDKLog\\1080p.jpg", "rb");
    //    fseek(fd, 0, SEEK_END);
    //    iReadSize = ftell(fd);
    //    fseek(fd, 0, SEEK_SET);
    //    fread(pData, 1, iReadSize, fd);

    //    struDoubleLightsCorrect.pVisiblePic = pData;
    //    struDoubleLightsCorrect.dwVisiblePicLen = iReadSize;

    //    fclose(fd);
    //    //其他参数赋值
    //    //struDoubleLightsCorrect.byVisiblePicHorizontalScale = 12;//配准裁剪可见光图像水平缩放系数，单位归一化128，[12,128]
    //    //struDoubleLightsCorrect.byVisiblePicVerticalScale = 12;//配准裁剪可见光图像垂直缩放系数，单位归一化128，[12,128]
    //    //struDoubleLightsCorrect.wHorizontalCalibrationOffset = 500;//水平标定偏差，该数值为标定时计算获得，单位归一化1000，[0,1000]
    //    //struDoubleLightsCorrect.wVerticalCalibrationOffset = 500;//垂直标定偏差，该数值为标定时计算获得，单位归一化1000，[0,1000]
    //    //struDoubleLightsCorrect.dwVisibleFocusDistance = ;//可见光镜头焦距，单位毫米
    //    //struDoubleLightsCorrect.dwVisiblePixelInterval;//可见光探测器像元尺寸，单位微米
    //    //struDoubleLightsCorrect.dwHorizontalCenterDistance;//可见光和热成像中心点水平距离，单位毫米
    //    //struDoubleLightsCorrect.dwVerticalCenterDistance;//可见光和热成像中心点垂直距离，单位毫米
    //    //struDoubleLightsCorrect.dwCalibrationDistance;//标定距离[0.3,2]m,协议传输时统一使用cm为单位

    //    struDoubleLightsCorrect.byVisiblePicHorizontalScale = 20;
    //    struDoubleLightsCorrect.byVisiblePicVerticalScale = 118;
    //    struDoubleLightsCorrect.wHorizontalCalibrationOffset = 1;
    //    struDoubleLightsCorrect.wVerticalCalibrationOffset = 1;
    //    struDoubleLightsCorrect.dwVisibleFocusDistance = 4;
    //    struDoubleLightsCorrect.dwVisiblePixelInterval = 2;
    //    struDoubleLightsCorrect.dwHorizontalCenterDistance = 50;
    //    struDoubleLightsCorrect.dwVerticalCenterDistance = 15;
    //    struDoubleLightsCorrect.dwCalibrationDistance = 100;

    //    struConfigInputInfo.lpInBuffer = &struDoubleLightsCorrect;
    //    struConfigInputInfo.dwInBufferSize = sizeof(struDoubleLightsCorrect);

    //    struConfigOutputInfo.lpOutBuffer = &struDoubleLightsCorrectResult;
    //    struConfigOutputInfo.dwOutBufferSize = sizeof(struDoubleLightsCorrectResult);
    //    struDoubleLightsCorrectResult.pJpegPic = pData;
    //    struDoubleLightsCorrectResult.dwJpegPicLen = BUFFER_LEN;


    //    if (!USB_GetDeviceConfig(m_lUserID, USB_POST_DOUBLE_LIGHTS_CORRECT, &struConfigInputInfo, &struConfigOutputInfo))
    //    {
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_POST_DOUBLE_LIGHTS_CORRECT");
    //        DWORD dwError = USB_GetLastError();
    //        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //    }
    //    else
    //    {
    //        if (struDoubleLightsCorrectResult.dwJpegPicLen > 0)
    //        {
    //            FILE *fd;
    //            fd = fopen("C:\\USBSDKLog\\double.jpg", "wb");
    //            fwrite((void *)struDoubleLightsCorrectResult.pJpegPic, 1, struDoubleLightsCorrectResult.dwJpegPicLen, fd);
    //            fclose(fd);
    //        }

    //        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_POST_DOUBLE_LIGHTS_CORRECT dwSize[%d] dwJpegPicLen[%d]",
    //            struDoubleLightsCorrectResult.dwSize, struDoubleLightsCorrectResult.dwJpegPicLen);
    //    }
    //    break;
    //case USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL: //获取双光校准坐标控制参数
    //    struCond.byChannelID = 1;
    //    struConfigInputInfo.lpCondBuffer = &struCond;
    //    struConfigInputInfo.dwCondBufferSize = sizeof(struCond);


    //    //struConfigInputInfo.lpInBuffer = &struDoubleLightsCorrect;
    //    //struConfigInputInfo.dwInBufferSize = sizeof(struDoubleLightsCorrect);

    //    struConfigOutputInfo.lpOutBuffer = &struDoubleLightsCorrectPointsCtrl;
    //    struConfigOutputInfo.dwOutBufferSize = sizeof(struDoubleLightsCorrectPointsCtrl);

    //    if (!USB_GetDeviceConfig(m_lUserID, USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL, &struConfigInputInfo, &struConfigOutputInfo))
    //    {
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL");
    //        DWORD dwError = USB_GetLastError();
    //        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //    }
    //    else
    //    {
    //        //if (struDoubleLightsCorrectResult.dwJpegPicLen > 0)
    //        //{
    //        //    FILE *fd;
    //        //    fd = fopen("C:\\USBSDKLog\\double.jpeg", "wb");
    //        //    fwrite((void *)struDoubleLightsCorrectResult.pJpegPic, 1, struDoubleLightsCorrectResult.dwJpegPicLen, fd);
    //        //    fclose(fd);
    //        //}

    //        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL dwSize[%d] byDoubleLightsCorrectPointsEnabled[%d]",
    //            struDoubleLightsCorrectPointsCtrl.dwSize, struDoubleLightsCorrectPointsCtrl.byDoubleLightsCorrectPointsEnabled);
    //    }
    //    break;
    //case USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL: //设置双光校准坐标控制参数
    //    struCond.byChannelID = 1;
    //    struConfigInputInfo.lpCondBuffer = &struCond;
    //    struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

    //    struDoubleLightsCorrectPointsCtrl.byDoubleLightsCorrectPointsEnabled = 1;
    //    struConfigInputInfo.lpInBuffer = &struDoubleLightsCorrectPointsCtrl;
    //    struConfigInputInfo.dwInBufferSize = sizeof(struDoubleLightsCorrectPointsCtrl);

    //    //struConfigOutputInfo.lpOutBuffer = &struDoubleLightsCorrectPointsCtrl;
    //    //struConfigOutputInfo.dwOutBufferSize = sizeof(struDoubleLightsCorrectPointsCtrl);

    //    if (!USB_SetDeviceConfig(m_lUserID, USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL, &struConfigInputInfo, &struConfigOutputInfo))
    //    {
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL");
    //        DWORD dwError = USB_GetLastError();
    //        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //    }
    //    else
    //    {
    //        //if (struDoubleLightsCorrectResult.dwJpegPicLen > 0)
    //        //{
    //        //    FILE *fd;
    //        //    fd = fopen("C:\\USBSDKLog\\double.jpeg", "wb");
    //        //    fwrite((void *)struDoubleLightsCorrectResult.pJpegPic, 1, struDoubleLightsCorrectResult.dwJpegPicLen, fd);
    //        //    fclose(fd);
    //        //}

    //        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL dwSize[%d] byDoubleLightsCorrectPointsEnabled[%d]",
    //            struDoubleLightsCorrectPointsCtrl.dwSize, struDoubleLightsCorrectPointsCtrl.byDoubleLightsCorrectPointsEnabled);
    //    }
    //    break;
    case USB_GET_THERMOMETRY_CALIBRATION_FILE: //测温标定文件导出
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        //struConfigInputInfo.lpInBuffer = &struThermometryCalibrationFile;
        //struConfigInputInfo.dwInBufferSize = sizeof(struThermometryCalibrationFile);

        struConfigOutputInfo.lpOutBuffer = &struThermometryCalibrationFile;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryCalibrationFile);

        struThermometryCalibrationFile.pCalibrationFile = pData;
        struThermometryCalibrationFile.dwFileLenth = BUFFER_LEN;

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_CALIBRATION_FILE, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_CALIBRATION_FILE");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            if (struThermometryCalibrationFile.dwFileLenth > 0)
            {
                CString file_name;
                file_name.Format("C:\\USBSDKLog\\%s.dat", struThermometryCalibrationFile.byFileName);
                FILE *fd;
                fd = fopen(file_name, "wb");
                fwrite((void *)struThermometryCalibrationFile.pCalibrationFile, 1, struThermometryCalibrationFile.dwFileLenth, fd);
                fclose(fd);
            }

            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMOMETRY_CALIBRATION_FILE dwSize[%d] dwFileLenth[%d]",
                struThermometryCalibrationFile.dwSize, struThermometryCalibrationFile.dwFileLenth);
        }
        break;
    case USB_SET_THERMOMETRY_CALIBRATION_FILE: //测温标定文件导入
    {
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        if (m_csFilePath.GetLength() == 0)
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SET_THERMOMETRY_CALIBRATION_FILE failed, No file!");
            break;
        }

        fd = fopen(m_csFilePath, "rb");
        fseek(fd, 0, SEEK_END);
        iReadSize = ftell(fd);
        fseek(fd, 0, SEEK_SET);
        fread(pData, 1, iReadSize, fd);
        fclose(fd);

        // int idx = m_csFilePath.ReverseFind('\\');
        // CString file_name = m_csFilePath.Right(m_csFilePath.GetLength() - idx - 2);
        struThermometryCalibrationFile.pCalibrationFile = pData;
        struThermometryCalibrationFile.dwFileLenth = iReadSize;
        sprintf((char *)struThermometryCalibrationFile.byFileName, m_csFileName);
        struConfigInputInfo.lpInBuffer = &struThermometryCalibrationFile;
        struConfigInputInfo.dwInBufferSize = sizeof(struThermometryCalibrationFile);

        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_CALIBRATION_FILE, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_THERMOMETRY_CALIBRATION_FILE");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMOMETRY_CALIBRATION_FILE dwSize[%d] dwFileLenth[%d]",
                struThermometryCalibrationFile.dwSize, struThermometryCalibrationFile.dwFileLenth);
        }
    }
    break;
    case USB_GET_THERMOMETRY_EXPERT_REGIONS:   //获取专家测温规则
        struCond.byChannelID = 1;
        struCond.bySID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struExpertRegion;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struExpertRegion);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_EXPERT_REGIONS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_EXPERT_REGIONS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMOMETRY_EXPERT_REGIONS dwSize[%d]",
                struExpertRegion.dwSize);
        }
        break;
    case USB_SET_THERMOMETRY_EXPERT_REGIONS:       //设置专家测温区域
        struCond.byChannelID = 1;
        struCond.bySID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

        struConfigOutputInfo.lpOutBuffer = &struExpertRegion;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struExpertRegion);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_EXPERT_REGIONS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_EXPERT_REGIONS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struConfigInputInfo.lpInBuffer = &struExpertRegion;
            struConfigInputInfo.dwInBufferSize = sizeof(struExpertRegion);

            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_EXPERT_REGIONS, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_THERMOMETRY_EXPERT_REGIONS");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMOMETRY_EXPERT_REGIONS dwSize[%d]",
                    struExpertRegion.dwSize);
            }
        }
        break;
    case USB_GET_EXPERT_CORRECTION_PARAM:     //获取专家测温校正参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struConfigOutputInfo.lpOutBuffer = &struCorrectionParam;
        struCorrectionParam.dwSize = sizeof(struCorrectionParam);
        struConfigOutputInfo.dwOutBufferSize = sizeof(struCorrectionParam);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_EXPERT_CORRECTION_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_EXPERT_CORRECTION_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_EXPERT_CORRECTION_PARAM dwSize[%d] dwDistance[%d]",
                struCorrectionParam.dwSize, struCorrectionParam.dwDistance);
        }
        break;
    case USB_SET_EXPERT_CORRECTION_PARAM:       //设置专家测温校正参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struCorrectionParam.dwSize = sizeof(struCorrectionParam);
        struConfigOutputInfo.lpOutBuffer = &struCorrectionParam;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struCorrectionParam);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_EXPERT_CORRECTION_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_EXPERT_CORRECTION_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struConfigInputInfo.lpInBuffer = &struCorrectionParam;
            struConfigInputInfo.dwInBufferSize = sizeof(struCorrectionParam);
            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_EXPERT_CORRECTION_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_EXPERT_CORRECTION_PARAM");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_EXPERT_CORRECTION_PARAM dwSize[%d]",
                    struCorrectionParam.dwSize);
            }
        }
        break;
    case USB_START_EXPERT_CORRECTION:      //开始专家测温校正
        struCond.byChannelID = 1;
        struControlInputInfo.lpCondBuffer = &struCond;
        struControlInputInfo.dwCondBufferSize = sizeof(struCond);

        if (!USB_Control(m_lUserID, USB_START_EXPERT_CORRECTION, &struControlInputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_START_EXPERT_CORRECTION");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_START_EXPERT_CORRECTION");
        }
        break;
    case USB_GET_THERMOMETRY_RISE_SETTINGS:       //获取温升配置
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struConfigOutputInfo.lpOutBuffer = &struRiseSettings;
        struRiseSettings.dwSize = sizeof(struRiseSettings);
        struConfigOutputInfo.dwOutBufferSize = sizeof(struRiseSettings);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_RISE_SETTINGS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_RISE_SETTINGS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMOMETRY_RISE_SETTINGS dwSize[%d] byEnabled[%d] byType[%d] byResult[%d]",
                struRiseSettings.dwSize, struRiseSettings.byEnabled, struRiseSettings.byType, struRiseSettings.byResult);
        }
        break;
    case USB_SET_THERMOMETRY_RISE_SETTINGS:        //设置温升配置
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struRiseSettings.dwSize = sizeof(struRiseSettings);
        struConfigOutputInfo.lpOutBuffer = &struRiseSettings;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struRiseSettings);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_RISE_SETTINGS, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMOMETRY_RISE_SETTINGS");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struConfigInputInfo.lpInBuffer = &struRiseSettings;
            struConfigInputInfo.dwInBufferSize = sizeof(struRiseSettings);
            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_RISE_SETTINGS, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_THERMOMETRY_RISE_SETTINGS");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_THERMOMETRY_RISE_SETTINGS dwSize[%d]",
                    struRiseSettings.dwSize);
            }
        }
        break;
    case USB_GET_ENVIROTEMPERATURE_CORRECT:    //获取环境温度校正参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struConfigOutputInfo.lpOutBuffer = &struEnvirotemperatureCorrect;
        struEnvirotemperatureCorrect.dwSize = sizeof(struEnvirotemperatureCorrect);
        struConfigOutputInfo.dwOutBufferSize = sizeof(struEnvirotemperatureCorrect);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_ENVIROTEMPERATURE_CORRECT, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_ENVIROTEMPERATURE_CORRECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_ENVIROTEMPERATURE_CORRECT dwSize[%d] byEnabled[%d] byCorrectEnabled[%d] dwEnviroTemperature[%d] dwCalibrationTemperature[%d]",
                struEnvirotemperatureCorrect.dwSize, struEnvirotemperatureCorrect.byEnabled, struEnvirotemperatureCorrect.byCorrectEnabled,
                struEnvirotemperatureCorrect.dwEnviroTemperature, struEnvirotemperatureCorrect.dwCalibrationTemperature);
        }
        break;
    case USB_SET_ENVIROTEMPERATURE_CORRECT:   //设置环境温度校正参数
        struCond.byChannelID = 1;
        struConfigInputInfo.lpCondBuffer = &struCond;
        struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
        struEnvirotemperatureCorrect.dwSize = sizeof(struEnvirotemperatureCorrect);
        struConfigOutputInfo.lpOutBuffer = &struEnvirotemperatureCorrect;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struEnvirotemperatureCorrect);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_ENVIROTEMPERATURE_CORRECT, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_ENVIROTEMPERATURE_CORRECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            struConfigInputInfo.lpInBuffer = &struEnvirotemperatureCorrect;
            struConfigInputInfo.dwInBufferSize = sizeof(struEnvirotemperatureCorrect);
            if (!USB_SetDeviceConfig(m_lUserID, USB_SET_ENVIROTEMPERATURE_CORRECT, &struConfigInputInfo, &struConfigOutputInfo))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_SET_ENVIROTEMPERATURE_CORRECT");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_SET_ENVIROTEMPERATURE_CORRECT dwSize[%d]",
                    struEnvirotemperatureCorrect.dwSize);
            }
        }
        break;
    default:
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED Unsupported");
        break;
    }

    delete[] pData;
    delete[] pData2;
    return;

}

void SubDlgThermalInterface::OnBnClickedButtonConfigState()
{
    // TODO:  在此添加控件通知处理程序代码
    USB_COMMAND_STATE struCommandState = { 0 };
    struCommandState.dwSize = sizeof(USB_COMMAND_STATE);

    if (!USB_GetCommandState(m_lUserID, &struCommandState))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GetCommandState");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    else
    {
        //#define  USB_ERROR_NO_ERROR                                0x00    // No error: The request succeeded
        //#define  USB_ERROR_DEVICE_REQUEST_NOT_COMPLETE             0x01    // Not Ready: Previous request has not completed
        //#define  USB_ERROR_DEVICE_WRONG_STATE                      0x02    // Wrong State: In a state that disallows the specific request
        //#define  USB_ERROR_DEVICE_MODE_ERROR                       0x03    // Power: Current power mode is not sufficient to complete the request
        //#define  USB_ERROR_SET_PARAM_OVERLIMIT                     0x04    // Out of Range: SET_CUR over limits
        //#define  USB_ERROR_UNITID_NOT_SUPPORT                      0x05    // Invalid Unit: Unit ID not supported
        //#define  USB_ERROR_CSID_NOT_SUPPORT                        0x06    // Invalid Control: CS ID not supported
        //#define  USB_ERROR_REQUEST_TYPE_NOT_SUPPORT                0x07    // Invalid Request: request type not supported
        //#define  USB_ERROR_SET_PARAM_INVALID                       0x08    // Invalid value with range: SET_CUR invalid value with range
        //#define  USB_ERROR_SUBFUNCTION_NOT_SUPPORT                 0x09    // Custom: Sub-function not supported
        //#define  USB_ERROR_DEVICE_EXECUTE_EXCEPTION                0x0a    // Custom: Device inner executing exceptions
        //#define  USB_ERROR_DEVICE_PROTOCOL_EXCEPTION               0x0b    // Custom: Device inner processing protocol exceptions
        //#define  USB_ERROR_BULK_DATA_EXCEPTION                     0x0c    // Custom: Bulk data transfer process exceptions
        //#define  USB_ERROR_UNKNOWN                                 0xff    // Unknown: Unknown
        switch (struCommandState.byState)
        {
        case USB_ERROR_NO_ERROR:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  No error: The request succeeded");
            break;
        case USB_ERROR_DEVICE_REQUEST_NOT_COMPLETE:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Not Ready: Previous request has not completed");
            break;
        case USB_ERROR_DEVICE_WRONG_STATE:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Wrong State: In a state that disallows the specific request");
            break;
        case USB_ERROR_DEVICE_MODE_ERROR:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Power: Current power mode is not sufficient to complete the request");
            break;
        case USB_ERROR_SET_PARAM_OVERLIMIT:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Out of Range: SET_CUR over limits");
            break;
        case USB_ERROR_UNITID_NOT_SUPPORT:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Invalid Unit: Unit ID not supported");
            break;
        case USB_ERROR_CSID_NOT_SUPPORT:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Invalid Control: CS ID not supported");
            break;
        case USB_ERROR_REQUEST_TYPE_NOT_SUPPORT:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Invalid Request: request type not supported");
            break;
        case USB_ERROR_SET_PARAM_INVALID:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Invalid value with range: SET_CUR invalid value with range");
            break;
        case USB_ERROR_SUBFUNCTION_NOT_SUPPORT:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Custom: Sub-function not supported");
            break;
        case USB_ERROR_DEVICE_EXECUTE_EXCEPTION:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Custom: Device inner executing exceptions");
            break;
        case USB_ERROR_DEVICE_PROTOCOL_EXCEPTION:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Custom: Device inner processing protocol exceptionsd");
            break;
        case USB_ERROR_BULK_DATA_EXCEPTION:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  Custom: Bulk data transfer process exceptions");
            break;
        case USB_ERROR_UNKNOWN:
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GetCommandState:  No error: The request succeeded");
            break;
        default:
            break;
        }
    }
    
}

void SubDlgThermalInterface::OnBnClickedButtonSelect()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);

    BOOL isOpen = TRUE;		//是否打开(否则为保存)
    CString defaultDir = _T("C:\\");	//默认打开的文件路径
    CString filter = _T("文件 (*.txt; *.dat; 所有文件)|*.txt;*.dat;*.*||");	//文件过虑的类型

    CFileDialog openFileDlg(isOpen, defaultDir, m_csFilePath, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);

    INT_PTR result = openFileDlg.DoModal();
    if (result == IDOK)
    {
        m_csFilePath = openFileDlg.GetPathName();
        m_csFileName = openFileDlg.GetFileName();
        UpdateData(FALSE);
    }

}


void SubDlgThermalInterface::OnOK()
{
    // TODO:  在此添加专用代码和/或调用基类

    //CDialog::OnOK();
}


void SubDlgThermalInterface::OnCancel()
{
    // TODO:  在此添加专用代码和/或调用基类

    //CDialog::OnCancel();
}

static void __stdcall StreamCallBack(LONG handle, USB_FRAME_INFO *pFrameInfo, void* pUser)
{
    SubDlgThermalInterface* pThis = (SubDlgThermalInterface*)pUser;
    if (pThis->m_iStreamType == 2)//全屏测温实时流
    {
        USB_THERMAL_STREAM_TEMP_S *struTempS = (USB_THERMAL_STREAM_TEMP_S*)(pFrameInfo->pBuf);
        //*=====全屏测温数据获取示例=====*//
        char *pStreamData = (char *)pFrameInfo->pBuf + struTempS->dwHeadLen;
        /*if (pStreamData != NULL)
        {
        HANDLE hFile;
        DWORD dwReturn;
        SYSTEMTIME t;
        GetLocalTime(&t);
        char chTime[128];
        sprintf(chTime, "%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d%3.3d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds);
        char cFileName[128] = { 0 };
        sprintf(cFileName, "C:\\USBSDKLog\\StreamData", chTime);
        if (GetFileAttributes(cFileName) != FILE_ATTRIBUTE_DIRECTORY)
        {
        CreateDirectory(cFileName, NULL);
        }
        sprintf(cFileName, "%s\\Stream_S[%s]", cFileName, chTime);
        hFile = CreateFile(cFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
        return;
        }
        WriteFile(hFile, pStreamData, struTempS->dwStreamLen, &dwReturn, NULL);
        CloseHandle(hFile);
        hFile = NULL;
        }*/

        LOGIN_INFO->WriteLog(INF_LEVEL, _T("Get stream-2 succ, dwMagicNo[0x%x], dwHeadLen[%d], dwStreamLen[%d], pStreamData[0x%x]"),
            struTempS->dwMagicNo, struTempS->dwHeadLen, struTempS->dwStreamLen, pStreamData);
    }
    else if (pThis->m_iStreamType == 4)//热图实时流
    {
        USB_THERMAL_STREAM_TEMP_HOT *struTempHot = (USB_THERMAL_STREAM_TEMP_HOT *)(pFrameInfo->pBuf);
        //*=====全屏测温数据获取示例=====*//
        char *pStreamData = (char *)pFrameInfo->pBuf + struTempHot->dwHeadLen;
        /*if (pStreamData != NULL)
        {
        HANDLE hFile;
        DWORD dwReturn;
        SYSTEMTIME t;
        GetLocalTime(&t);
        char chTime[128];
        sprintf(chTime, "%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d%3.3d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds);
        char cFileName[128] = { 0 };
        sprintf(cFileName, "C:\\USBSDKLog\\StreamData", chTime);
        if (GetFileAttributes(cFileName) != FILE_ATTRIBUTE_DIRECTORY)
        {
        CreateDirectory(cFileName, NULL);
        }
        sprintf(cFileName, "%s\\Stream_Hot[%s]", cFileName, chTime);
        hFile = CreateFile(cFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
        return;
        }
        WriteFile(hFile, pStreamData, struTempHot->dwStreamLen, &dwReturn, NULL);
        CloseHandle(hFile);
        hFile = NULL;
        }*/

        //*=====JPEG图片数据获取示例=====*//
        char *pJpegData = (char *)pFrameInfo->pBuf + struTempHot->dwHeadLen + struTempHot->dwStreamLen;
        /*if (pJpegData != NULL)
        {
        HANDLE hFile;
        DWORD dwReturn;
        SYSTEMTIME t;
        GetLocalTime(&t);
        char chTime[128];
        sprintf(chTime, "%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d%3.3d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds);

        char cFileName[128] = { 0 };
        sprintf(cFileName, "C:\\USBSDKLog\\StreamData", chTime);
        if (GetFileAttributes(cFileName) != FILE_ATTRIBUTE_DIRECTORY)
        {
        CreateDirectory(cFileName, NULL);
        }
        sprintf(cFileName, "%s\\HotPic[%s].jpg", cFileName, chTime);
        hFile = CreateFile(cFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
        return;
        }
        WriteFile(hFile, pJpegData, struTempHot->struRTJpegDataInfo.dwJpegLen, &dwReturn, NULL);
        CloseHandle(hFile);
        hFile = NULL;
        }*/

        LOGIN_INFO->WriteLog(INF_LEVEL, _T("Get stream-4 succ, dwMagicNo[0x%x], dwHeadLen[%d], dwStreamLen[%d], dwIRFJpg[%d], pStreamData[0x%x], pJpegData[0x%x]"),
            struTempHot->dwMagicNo, struTempHot->dwHeadLen, struTempHot->dwStreamLen, struTempHot->dwIRFJpg, pStreamData, pJpegData);
    }
    else//其他类型数据不做解析
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, _T("Get stream succ"));
    }
}

void SubDlgThermalInterface::SetOsd()
{
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
    memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
    memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

    USB_OSD struOsd = { 0 };
    struOsd.byEnabled = 1; //开启osd

    struOsd.struOsdInfo.wLineNums = 2;  //Osd 行数
    struOsd.struOsdInfo.uiWinWidth = 704;
    struOsd.struOsdInfo.uiWinHeight = 576;


    //第一行osd信息
    sprintf((char*)struOsd.struOsdLineList[0].szOsdString, "aaaaaaaaaaaaaaaa");
    struOsd.struOsdLineList[0].uiOffsetx = 0;
    struOsd.struOsdLineList[0].uiOffsety = 0;

    ////第二行osd信息
    //sprintf((char*)struOsd.struOsdLineList[1].szOsdString, "bbbbbbbbbbbbbbbb");
    //struOsd.struOsdLineList[1].uiOffsetx = 100;
    //struOsd.struOsdLineList[1].uiOffsety = 100;

    struConfigInputInfo.lpInBuffer = &struOsd;
    struConfigInputInfo.dwInBufferSize = sizeof(struOsd);

    if (!USB_SetDeviceConfig(m_lUserID, USB_SET_OSD, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, _T("Set OSD fail!"));
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, _T("set OSD success!"));
}


void SubDlgThermalInterface::OnBnClickedButtonStartPreview()
{
    if (m_combDecodeType.GetCurSel() == 0)//内部解码方式
    {
        USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
        USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
        USB_VIDEO_PARAM struVideoParam = { 0 };
        memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));
        struConfigOutputInfo.lpOutBuffer = &struVideoParam;
        struConfigOutputInfo.dwOutBufferSize = sizeof(struVideoParam);
        //获取设备视频参数
        SetOsd();
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            if (g_bEnglish)
            {
                AfxMessageBox(_T("Get video param failed"));
            }
            else
            {
                AfxMessageBox(_T("获取设备视频参数失败"));
            }
            return;
        }


        //更新需要设置的参数
        struVideoParam.dwVideoFormat = USB_STREAM_MJPEG;
        struVideoParam.dwFramerate = 30;
        struVideoParam.dwWidth = 240;
        struVideoParam.dwHeight = 320;

        memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
        memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

        struConfigInputInfo.lpInBuffer = &struVideoParam;
        struConfigInputInfo.dwInBufferSize = sizeof(struVideoParam);

        //设置设备视频参数
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            if (g_bEnglish)
            {
                AfxMessageBox(_T("Set video param failed"));
            }
            else
            {
                AfxMessageBox(_T("设置设备视频参数失败"));
            }
            //return;
        }

        //更新需要设置的参数
        USB_SRC_STREAM_CFG struSrcStreamCfg = { 0 };
        struSrcStreamCfg.dwStreamType = USB_STREAM_MJPEG;
        struSrcStreamCfg.bUseAudio = FALSE;

        memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
        memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

        struConfigInputInfo.lpInBuffer = &struSrcStreamCfg;
        struConfigInputInfo.dwInBufferSize = sizeof(struSrcStreamCfg);

        //设置设备视频参数
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_SRC_STREAM_TYPE, &struConfigInputInfo, &struConfigOutputInfo))
        {
            if (g_bEnglish)
            {
                AfxMessageBox(_T("Set src stream failed"));
            }
            else
            {
                AfxMessageBox(_T("设置设备原始码流类型失败"));
            }
            //return;
        }

        RECT rc;
        m_PreviewWindow.GetWindowRect(&rc);
        ScreenToClient(&rc);
        m_PreviewWindow.MoveWindow(rc.left, rc.top, 320, 240);

        // TODO:  在此添加控件通知处理程序代码
        USB_PREVIEW_PARAM struPreviewParam = { 0 };
        struPreviewParam.dwSize = sizeof(USB_PREVIEW_PARAM);
        struPreviewParam.hWindow = m_hVideoWnd;
        struPreviewParam.dwStreamType = USB_STREAM_PS_MJPEG;
        struPreviewParam.bUseAudio = 0;
        m_lCurChannel = USB_StartPreview(m_lUserID, &struPreviewParam);
        if (m_lCurChannel == -1)
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_StartPreview()");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_StartPreview()");
        }
    }
    else if (m_combDecodeType.GetCurSel() == 1)//外部解码方式，即码流回调自行解码
    {
        //先获取码流类型，用于码流解析
        USB_CONFIG_INPUT_INFO struCfgInputInfo = { 0 };
        USB_CONFIG_OUTPUT_INFO struCfgOutputInfo = { 0 };
        USB_COMMON_COND struCond = { 0 };
        USB_THERMAL_STREAM_PARAM struThermalStreamParam = { 0 };
        struCond.byChannelID = 1;
        struCfgInputInfo.lpCondBuffer = &struCond;
        struCfgInputInfo.dwCondBufferSize = sizeof(struCond);

        struCfgOutputInfo.lpOutBuffer = &struThermalStreamParam;
        struCfgOutputInfo.dwOutBufferSize = sizeof(struThermalStreamParam);

        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMAL_STREAM_PARAM, &struCfgInputInfo, &struCfgOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_GET_THERMAL_STREAM_PARAM");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            m_iStreamType = struThermalStreamParam.byVideoCodingType;
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS  USB_GET_THERMAL_STREAM_PARAM dwSize[%d] byVideoCodingType[%d]",
                struThermalStreamParam.dwSize, struThermalStreamParam.byVideoCodingType);
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
//         USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
//         //设置视频参数
//         USB_VIDEO_PARAM struVideoParam = { 0 };
//         struVideoParam.dwVideoFormat = USB_STREAM_MJPEG;
//         struVideoParam.dwWidth = 240;
//         struVideoParam.dwHeight = 320;
//         struVideoParam.dwFramerate = 30;
// 
//         struConfigInputInfo.lpInBuffer = &struVideoParam;
//         struConfigInputInfo.dwInBufferSize = sizeof(struVideoParam);
// 
//         if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
//         {
//             LOGIN_INFO->WriteLog(ERR_LEVEL, _T("设置设备视频参数失败"));
//         }
//         LOGIN_INFO->WriteLog(INF_LEVEL, _T("设置设备视频参数成功"));
// 
//         //开启码流回调
//         USB_STREAM_CALLBACK_PARAM struDecCbInfo = { 0 };
//         struDecCbInfo.dwStreamType = USB_STREAM_MJPEG;
//         struDecCbInfo.pUser = this;
//         struDecCbInfo.funcStreamCallBack = StreamCallBack;
//         struDecCbInfo.dwSize = sizeof(struDecCbInfo);
// 
//         m_iCallBackChannel = USB_StartStreamCallback(m_lUserID, &struDecCbInfo);
//         if (m_iCallBackChannel < 0)
//         {
//             LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("设置Dev1码流回调参数失败"));
//             return;
//         }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////
        USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
        USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
        //设置视频参数
        USB_VIDEO_PARAM struVideoParam = { 0 };
        struVideoParam.dwVideoFormat = USB_STREAM_MJPEG;
        struVideoParam.dwWidth = 240;
        struVideoParam.dwHeight = 320;
        struVideoParam.dwFramerate = 30;

        struConfigInputInfo.lpInBuffer = &struVideoParam;
        struConfigInputInfo.dwInBufferSize = sizeof(struVideoParam);

        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, _T("设置设备视频参数失败"));
        }
        LOGIN_INFO->WriteLog(INF_LEVEL, _T("设置设备视频参数成功"));

        //开启码流回调
        USB_STREAM_CALLBACK_PARAM struDecCbInfo = { 0 };
        struDecCbInfo.dwStreamType = USB_STREAM_MJPEG;
        struDecCbInfo.pUser = this;
        struDecCbInfo.funcStreamCallBack = StreamCallBack;
        struDecCbInfo.dwSize = sizeof(struDecCbInfo);

        m_iCallBackChannel = USB_StartStreamCallback(m_lUserID, &struDecCbInfo);
        if (m_iCallBackChannel < 0)
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("设置Dev1码流回调参数失败"));
            return;
        }
    }
    
}


void SubDlgThermalInterface::OnBnClickedButtonStopPreview()
{
    BOOL bRes = false;
    if (m_combDecodeType.GetCurSel() == 0)
    {
        bRes = USB_StopChannel(m_lUserID, m_lCurChannel);
    }
    else if (m_combDecodeType.GetCurSel() == 1)
    {
        bRes = USB_StopChannel(m_lUserID, m_iCallBackChannel);
    }
    if (!bRes)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_StopChannel()");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    else
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_StopChannel()");
    }
}

void SubDlgThermalInterface::OnEventCallBack(int handle, long lEvent, long nParam1, long nParam2, void *pUser)
{
    //CThermalDemoDlg* pThis = (CThermalDemoDlg*)pUser;
    WCHAR strPrint[256] = { 0 };
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS OnEventCallBack() : handle[%d], lEvent[%d]", handle, lEvent);
    //swprintf(strPrint, _T("CThermalDemoDlg::OnEventCallBack:handle[%d], lEvent[%d]"), handle, lEvent);
    if (lEvent == USB_EC_DEVICE_LOST)
    {
        if (nParam2 == USB_EVENTTYPE_DEV_REMOVED)
        {
            //::PostMessage(pThis->m_hWnd, WM_DEVICE_REMOVED, NULL, (LPARAM)handle);
        }
        else if (nParam2 == USB_EVENTTYPE_DEV_ADDED)
        {
            //::PostMessage(pThis->m_hWnd, WM_DEVICE_ADDED, NULL, (LPARAM)handle);
        }
    }
}


void SubDlgThermalInterface::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_STATIC2);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_STATIC3);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_STATIC4);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_STATIC5);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_BUTTON_SELECT);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_BUTTON_CONFIG);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_BUTTON_STOP_PREVIEW);
    SET_CONTROL_LAN(IDD_SUBDLG_THERMAL_INTERFACE, IDC_BUTTON_START_PREVIEW);
}


