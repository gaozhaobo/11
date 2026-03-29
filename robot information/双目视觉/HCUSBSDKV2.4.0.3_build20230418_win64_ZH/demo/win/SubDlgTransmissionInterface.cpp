// SubDlgTransmissionInterface.cpp : 实现文件
//

#include "stdafx.h"
#include "SubDlgTransmissionInterface.h"
#include "afxdialogex.h"
#include "DlgUpgrade.h"
#include "Language.h"
#include "DlgFileTransfer.h"


// SubDlgTransmissionInterface 对话框

IMPLEMENT_DYNAMIC(SubDlgTransmissionInterface, CDialog)

SubDlgTransmissionInterface::SubDlgTransmissionInterface(CWnd* pParent /*=NULL*/)
	: CDialog(SubDlgTransmissionInterface::IDD, pParent)
{

}

SubDlgTransmissionInterface::~SubDlgTransmissionInterface()
{
}

void SubDlgTransmissionInterface::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_COMMAND, m_cbCommand);
}


BEGIN_MESSAGE_MAP(SubDlgTransmissionInterface, CDialog)
    ON_BN_CLICKED(IDOK, &SubDlgTransmissionInterface::OnBnClickedOk)
    ON_CBN_SELCHANGE(IDC_COMBO_COMMAND, &SubDlgTransmissionInterface::OnCbnSelchangeComboCommand)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL SubDlgTransmissionInterface::OnInitDialog()
{
    CDialog::OnInitDialog();

    // 初始化命令下拉列表
    int index = 0;
    if (g_bEnglish)
    {
        m_cbCommand.InsertString(index++, "GET_VCA_SWITCH");
        m_cbCommand.InsertString(index++, "SET_VCA_SWITCH");
        m_cbCommand.InsertString(index++, "GET_VCA_SNAPSHOT");
        m_cbCommand.InsertString(index++, "GET_VCA_FACE_THRESHOLD");
        m_cbCommand.InsertString(index++, "SET_VCA_FACE_THRESHOLD");
        m_cbCommand.InsertString(index++, "GET_VCA_FACE_ATTRIBUTES");
        m_cbCommand.InsertString(index++, "SET_VCA_FACE_ATTRIBUTES");
        m_cbCommand.InsertString(index++, "GET_VCA_FACE_DETECT_RULE");
        m_cbCommand.InsertString(index++, "SET_VCA_FACE_DETECT_RULE");
        m_cbCommand.InsertString(index++, "GET_VCA_FACE_QUALITY");
        m_cbCommand.InsertString(index++, "SET_VCA_FACE_QUALITY");
        m_cbCommand.InsertString(index++, "SET_VCA_PIC_DOWNLOAD");
        m_cbCommand.InsertString(index++, "GET_VCA_FACE_BASE_DATA_CFG");
        m_cbCommand.InsertString(index++, "SET_VCA_FACE_BASE_DATA_CFG");
        m_cbCommand.InsertString(index++, "GET_VCA_ELECTRONICSIGNAGE_CFG");
        m_cbCommand.InsertString(index++, "SET_VCA_ELECTRONICSIGNAGE_CFG");
        m_cbCommand.InsertString(index++, "GET_VCA_FACE_DETECT");
        m_cbCommand.InsertString(index++, "SET_VCA_FACE_DETECT");
        m_cbCommand.InsertString(index++, "GET_VCA_FACE_CONTRAST");
        m_cbCommand.InsertString(index++, "SET_VCA_FACE_CONTRAST");
        m_cbCommand.InsertString(index++, "UPGRADE");
        m_cbCommand.InsertString(index++, "UPLOAD_FILE");
        m_cbCommand.InsertString(index++, "DOWNLOAD_FILE");
        m_cbCommand.InsertString(index++, "RESET_DEVICE");
        m_cbCommand.InsertString(index++, "GET_DEVICE_VERSION");
        m_cbCommand.InsertString(index++, "DEVICE_ENCRYPTION");
    }
    else
    {
        m_cbCommand.InsertString(index++, "智能功能开关获取");
        m_cbCommand.InsertString(index++, "智能功能开关设置");
        m_cbCommand.InsertString(index++, "智能抓图获取");
        m_cbCommand.InsertString(index++, "智能人脸识别相似度阈值获取");
        m_cbCommand.InsertString(index++, "智能人脸识别相似度阈值设置");
        m_cbCommand.InsertString(index++, "智能人脸识别属性获取");
        m_cbCommand.InsertString(index++, "智能人脸识别属性设置");
        m_cbCommand.InsertString(index++, "智能人脸检测规则获取");
        m_cbCommand.InsertString(index++, "智能人脸检测规则设置");
        m_cbCommand.InsertString(index++, "智能人脸检测质量获取");
        m_cbCommand.InsertString(index++, "智能人脸检测质量设置");
        m_cbCommand.InsertString(index++, "图片下载建模");
        m_cbCommand.InsertString(index++, "人脸底库配置获取");
        m_cbCommand.InsertString(index++, "人脸底库配置设置");
        m_cbCommand.InsertString(index++, "电子铭牌配置获取");
        m_cbCommand.InsertString(index++, "电子铭牌配置设置");
        m_cbCommand.InsertString(index++, "智能人脸检测信息获取");
        m_cbCommand.InsertString(index++, "智能人脸检测信息设置");
        m_cbCommand.InsertString(index++, "智能人脸比对信息获取");
        m_cbCommand.InsertString(index++, "智能人脸比对信息设置");
        m_cbCommand.InsertString(index++, "设备升级");
        m_cbCommand.InsertString(index++, "文件导入");
        m_cbCommand.InsertString(index++, "文件导出");
        m_cbCommand.InsertString(index++, "重置设备");
        m_cbCommand.InsertString(index++, "获取设备版本号");
        m_cbCommand.InsertString(index++, "设备加密");
    }

    m_cbCommand.SetCurSel(0);
    OnCbnSelchangeComboCommand();

    return TRUE;
}

// SubDlgTransmissionInterface 消息处理程序


void SubDlgTransmissionInterface::OnBnClickedOk()
{
    // TODO:  在此添加控件通知处理程序代码
    USB_VCA_SWITCH struSwitch = { 0 };
    USB_VCA_SNAPSHOT struSnapshot = { 0 };
    USB_VCA_FACE_THRESHOLD struFaceThreshold = { 0 };
    USB_VCA_FACE_ATTRIBUTES struFaceAttributes = { 0 };
    USB_VCA_FACE_DETECT_RULE struFaceDetectRule = { 0 };
    USB_VCA_FACE_QUALITY struFaceQulity = { 0 };
    USB_VCA_PIC_DOWNLOAD struPicDownload = { 0 };
    USB_VCA_FACE_BASE_DATA_CFG struFaceBaseDataCfg = { 0 };
    USB_VCA_ELECTRONICSIGNAGE_CFG struElectronicsignageCfg = { 0 };
    USB_VCA_FACE_DETECT struFaceDetect = { 0 };
    USB_VCA_FACE_CONTRAST struFaceContrast = { 0 };
    USB_CONFIG_INPUT_INFO struInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struOutputInfo = { 0 };
    USB_DEVICE_VERSION struDevVer = { 0 };
    USB_FILE_TRANSFER_INFO struFileTransferInfo = { 0 };
    USB_FILE_TRANSFER_PROGRESS_INFO struProgressInfo = { 0 };

    int iCmd = 0;
    switch (m_cbCommand.GetCurSel())
    {
    case 0:
        iCmd = USB_GET_VCA_SWITCH;
        break;
    case 1:
        iCmd = USB_SET_VCA_SWITCH;
        break;
    case 2:
        iCmd = USB_GET_VCA_SNAPSHOT;
        break;
    case 3:
        iCmd = USB_GET_VCA_FACE_THRESHOLD;
        break;
    case 4:
        iCmd = USB_SET_VCA_FACE_THRESHOLD;
        break;
    case 5:
        iCmd = USB_GET_VCA_FACE_ATTRIBUTES;
        break;
    case 6:
        iCmd = USB_SET_VCA_FACE_ATTRIBUTES;
        break;
    case 7:
        iCmd = USB_GET_VCA_FACE_DETECT_RULE;
        break;
    case 8:
        iCmd = USB_SET_VCA_FACE_DETECT_RULE;
        break;
    case 9:
        iCmd = USB_GET_VCA_FACE_QUALITY;
        break;
    case 10:
        iCmd = USB_SET_VCA_FACE_QUALITY;
        break;
    case 11:
        iCmd = USB_SET_VCA_PIC_DOWNLOAD;
        break;
    case 12:
        iCmd = USB_GET_VCA_FACE_BASE_DATA_CFG;
        break;
    case 13:
        iCmd = USB_SET_VCA_FACE_BASE_DATA_CFG;
        break;
    case 14:
        iCmd = USB_GET_VCA_ELECTRONICSIGNAGE_CFG;
        break;
    case 15:
        iCmd = USB_SET_VCA_ELECTRONICSIGNAGE_CFG;
        break;
    case 16:
        iCmd = USB_GET_VCA_FACE_DETECT;
        break;
    case 17:
        iCmd = USB_SET_VCA_FACE_DETECT;
        break;
    case 18:
        iCmd = USB_GET_VCA_FACE_CONTRAST;
        break;
    case 19:
        iCmd = USB_SET_VCA_FACE_CONTRAST;
        break;
    case 20:
        iCmd = 0;
        break;
    case 21:
        iCmd = USB_TRANS_FILE_UPLOAD_START;
        break;
    case 22:
        iCmd = USB_TRANS_FILE_DOWNLOAD_START;
        break;
    case 23:
        iCmd = USB_CTRL_RESET_DEVICE;
        break;
    case 24:
        iCmd = USB_GET_DEVICE_VERSION;
        break;
    case 25:
        iCmd = USB_TRANS_DEVICE_ENCRYPTION_START;
        break;
    default:
        break;
    }

    char szPath[MAX_PATH_LENGTH] = { 0 };
    switch (iCmd)
    {
    case USB_GET_VCA_SWITCH:    //获取智能功能开关
        memset(&struSwitch, 0, sizeof(struSwitch));
        struOutputInfo.lpOutBuffer = &struSwitch;
        struOutputInfo.dwOutBufferSize = sizeof(struSwitch);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_SWITCH, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_SWITCH");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struSwitch.byChannelID);
            SetByteToEdit(1, struSwitch.byDetectEnabled);
            SetByteToEdit(2, struSwitch.byIdentifyEnabled);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_SWITCH");
        }
        break;
    case USB_SET_VCA_SWITCH:    //设置智能功能开关
        memset(&struSwitch, 0, sizeof(struSwitch));
        GetByteFromEdit(0, struSwitch.byChannelID);
        GetByteFromEdit(1, struSwitch.byDetectEnabled);
        GetByteFromEdit(2, struSwitch.byIdentifyEnabled);
        struInputInfo.lpInBuffer = &struSwitch;
        struInputInfo.dwInBufferSize = sizeof(struSwitch);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_SWITCH, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_SWITCH");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_SWITCH");
        }
        break;
    case USB_GET_VCA_SNAPSHOT:  //获取智能抓图
        memset(&struSnapshot, 0, sizeof(struSnapshot));
        struOutputInfo.lpOutBuffer = &struSnapshot;
        struOutputInfo.dwOutBufferSize = sizeof(struSnapshot);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_SNAPSHOT, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_SNAPSHOT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            return;
        }
        GetByteArrayFromEdit(3, (BYTE*)szPath, MAX_PATH_LENGTH);
        if (-1 == USB_FileTransfer(m_lUserID, USB_GET_VCA_SNAPSHOT, szPath))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_SNAPSHOT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struSnapshot.byChannelID);
            SetByteToEdit(1, struSnapshot.bySnapshotMode);
            SetByteToEdit(2, struSnapshot.byCaptureInterval);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_SNAPSHOT");
        }
        break;
    case USB_GET_VCA_FACE_THRESHOLD:    //获取智能人脸识别的相似度阈值
        memset(&struFaceThreshold, 0, sizeof(struFaceThreshold));
        struOutputInfo.lpOutBuffer = &struFaceThreshold;
        struOutputInfo.dwOutBufferSize = sizeof(struFaceThreshold);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_SNAPSHOT, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_FACE_THRESHOLD");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struFaceThreshold.byChannelID);
            SetByteToEdit(1, struFaceThreshold.byThresholdValue);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_FACE_THRESHOLD");
        }
        break;
    case USB_SET_VCA_FACE_THRESHOLD:    //设置智能人脸识别的相似度阈值
        memset(&struFaceThreshold, 0, sizeof(struFaceThreshold));
        GetByteFromEdit(0, struFaceThreshold.byChannelID);
        GetByteFromEdit(1, struFaceThreshold.byThresholdValue);
        struInputInfo.lpInBuffer = &struFaceThreshold;
        struInputInfo.dwInBufferSize = sizeof(struFaceThreshold);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_FACE_THRESHOLD, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_FACE_THRESHOLD");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_FACE_THRESHOLD");
        }
        break;
    case USB_GET_VCA_FACE_ATTRIBUTES:   //获取智能人脸识别的属性
        memset(&struFaceAttributes, 0, sizeof(struFaceAttributes));
        struOutputInfo.lpOutBuffer = &struFaceAttributes;
        struOutputInfo.dwOutBufferSize = sizeof(struFaceAttributes);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_FACE_ATTRIBUTES, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_FACE_ATTRIBUTES");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struFaceAttributes.byChannelID);
            SetByteToEdit(1, struFaceAttributes.byEnabled);
            SetByteToEdit(2, struFaceAttributes.byFaceExpression);
            SetByteToEdit(3, struFaceAttributes.byAge);
            SetByteToEdit(4, struFaceAttributes.byGender);
            SetByteToEdit(5, struFaceAttributes.byGlass);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_FACE_ATTRIBUTES");
        }
        break;
    case USB_SET_VCA_FACE_ATTRIBUTES:   //设置智能人脸识别的属性
        memset(&struFaceAttributes, 0, sizeof(struFaceAttributes));
        GetByteFromEdit(0, struFaceAttributes.byChannelID);
        GetByteFromEdit(1, struFaceAttributes.byEnabled);
        GetByteFromEdit(2, struFaceAttributes.byFaceExpression);
        GetByteFromEdit(3, struFaceAttributes.byAge);
        GetByteFromEdit(4, struFaceAttributes.byGender);
        GetByteFromEdit(5, struFaceAttributes.byGlass);
        struInputInfo.lpInBuffer = &struFaceAttributes;
        struInputInfo.dwInBufferSize = sizeof(struFaceAttributes);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_FACE_ATTRIBUTES, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_FACE_ATTRIBUTES");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_FACE_ATTRIBUTES");
        }
        break;
    case USB_GET_VCA_FACE_DETECT_RULE:  //获取智能人脸检测的规则
        memset(&struFaceDetectRule, 0, sizeof(struFaceDetectRule));
        struOutputInfo.lpOutBuffer = &struFaceDetectRule;
        struOutputInfo.dwOutBufferSize = sizeof(struFaceDetectRule);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_FACE_DETECT_RULE, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_FACE_DETECT_RULE");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struFaceDetectRule.byChannelID);
            SetByteToEdit(1, struFaceDetectRule.bySensitivity);
            SetByteToEdit(2, struFaceDetectRule.byObjGenerateRate);
            SetDwordToEdit(3, struFaceDetectRule.dwRegionX);
            SetDwordToEdit(4, struFaceDetectRule.dwRegionY);
            SetDwordToEdit(5, struFaceDetectRule.dwRegionWidth);
            SetDwordToEdit(6, struFaceDetectRule.dwRegionHeight);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_FACE_DETECT_RULE");
        }
        break;
    case USB_SET_VCA_FACE_DETECT_RULE:  //设置智能人脸检测的规则
        memset(&struFaceDetectRule, 0, sizeof(struFaceDetectRule));
        GetByteFromEdit(0, struFaceDetectRule.byChannelID);
        GetByteFromEdit(1, struFaceDetectRule.bySensitivity);
        GetByteFromEdit(2, struFaceDetectRule.byObjGenerateRate);
        GetDwordFromEdit(3, struFaceDetectRule.dwRegionX);
        GetDwordFromEdit(4, struFaceDetectRule.dwRegionY);
        GetDwordFromEdit(5, struFaceDetectRule.dwRegionWidth);
        GetDwordFromEdit(6, struFaceDetectRule.dwRegionHeight);
        struInputInfo.lpInBuffer = &struFaceDetectRule;
        struInputInfo.dwInBufferSize = sizeof(struFaceDetectRule);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_FACE_DETECT_RULE, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_FACE_DETECT_RULE");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_FACE_DETECT_RULE");
        }
        break;
    case USB_GET_VCA_FACE_QUALITY:      //获取智能人脸检测质量评估
        memset(&struFaceQulity, 0, sizeof(struFaceQulity));
        struOutputInfo.lpOutBuffer = &struFaceQulity;
        struOutputInfo.dwOutBufferSize = sizeof(struFaceQulity);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_FACE_QUALITY, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_FACE_QUALITY");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struFaceQulity.byChannelID);
            SetByteToEdit(1, struFaceQulity.byLeftAngle);
            SetByteToEdit(2, struFaceQulity.byRightAngle);
            SetByteToEdit(3, struFaceQulity.byUpAngle);
            SetByteToEdit(4, struFaceQulity.byDownAngle);
            SetByteToEdit(5, struFaceQulity.byPupilDistance);
            SetByteToEdit(6, struFaceQulity.byScore);
            SetByteToEdit(7, struFaceQulity.byShelterType);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_FACE_QUALITY");
        }
        break;
    case USB_SET_VCA_FACE_QUALITY:      //设置智能人脸检测质量评估
        memset(&struFaceQulity, 0, sizeof(struFaceQulity));
        GetByteFromEdit(0, struFaceQulity.byChannelID);
        GetByteFromEdit(1, struFaceQulity.byLeftAngle);
        GetByteFromEdit(2, struFaceQulity.byRightAngle);
        GetByteFromEdit(3, struFaceQulity.byUpAngle);
        GetByteFromEdit(4, struFaceQulity.byDownAngle);
        GetByteFromEdit(5, struFaceQulity.byPupilDistance);
        GetByteFromEdit(6, struFaceQulity.byScore);
        GetByteFromEdit(7, struFaceQulity.byShelterType);
        struInputInfo.lpInBuffer = &struFaceQulity;
        struInputInfo.dwInBufferSize = sizeof(struFaceQulity);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_FACE_QUALITY, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_FACE_QUALITY");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_FACE_QUALITY");
        }
        break;
    case USB_SET_VCA_PIC_DOWNLOAD:      //图片下载建模（图片通过大文件传输）
        memset(&struPicDownload, 0, sizeof(struPicDownload));
        GetByteFromEdit(0, struPicDownload.byId);
        GetByteFromEdit(1, struPicDownload.byType);
        GetByteFromEdit(2, struPicDownload.byPicWidth);
        GetByteFromEdit(3, struPicDownload.byPicHeight);
        GetByteFromEdit(4, struPicDownload.byPicSize);
        GetByteArrayFromEdit(5, struPicDownload.byName, MAX_NAME_LENGTH);
        GetByteArrayFromEdit(6, struPicDownload.byPost, MAX_NAME_LENGTH);
        GetByteArrayFromEdit(7, (BYTE*)szPath, MAX_PATH_LENGTH);
        if (strstr(szPath, ".jpg") == NULL)
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "The file type is not jpg");
            return;
        }

        struInputInfo.lpInBuffer = &struPicDownload;
        struInputInfo.dwInBufferSize = sizeof(struPicDownload);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_PIC_DOWNLOAD, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_PIC_DOWNLOAD");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            return;
        }
        if (-1 == USB_FileTransfer(m_lUserID, USB_SET_VCA_PIC_DOWNLOAD, szPath))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_PIC_DOWNLOAD");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_PIC_DOWNLOAD [%s]", szPath);
        }
        break;
    case USB_GET_VCA_FACE_BASE_DATA_CFG:    //获取人脸底库配置
        memset(&struFaceBaseDataCfg, 0, sizeof(struFaceBaseDataCfg));
        struOutputInfo.lpOutBuffer = &struFaceBaseDataCfg;
        struOutputInfo.dwOutBufferSize = sizeof(struFaceBaseDataCfg);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_FACE_BASE_DATA_CFG, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_FACE_BASE_DATA_CFG");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struFaceBaseDataCfg.byId);
            SetByteToEdit(1, struFaceBaseDataCfg.byOperateType);
            SetByteArrayToEdit(2, struFaceBaseDataCfg.byName);
            SetByteArrayToEdit(3, struFaceBaseDataCfg.byPost);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_FACE_BASE_DATA_CFG");
        }
        break;
    case USB_SET_VCA_FACE_BASE_DATA_CFG:    //设置人脸底库配置
        memset(&struFaceBaseDataCfg, 0, sizeof(struFaceBaseDataCfg));
        GetByteFromEdit(0, struFaceBaseDataCfg.byId);
        GetByteFromEdit(1, struFaceBaseDataCfg.byOperateType);
        GetByteArrayFromEdit(2, struFaceBaseDataCfg.byName, MAX_NAME_LENGTH);
        GetByteArrayFromEdit(3, struFaceBaseDataCfg.byPost, MAX_NAME_LENGTH);
        struInputInfo.lpInBuffer = &struFaceBaseDataCfg;
        struInputInfo.dwInBufferSize = sizeof(struFaceBaseDataCfg);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_FACE_BASE_DATA_CFG, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_FACE_BASE_DATA_CFG");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_FACE_BASE_DATA_CFG");
        }
        break;
    case USB_GET_VCA_ELECTRONICSIGNAGE_CFG: //获取电子铭牌配置
        memset(&struElectronicsignageCfg, 0, sizeof(struElectronicsignageCfg));
        struOutputInfo.lpOutBuffer = &struElectronicsignageCfg;
        struOutputInfo.dwOutBufferSize = sizeof(struElectronicsignageCfg);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_ELECTRONICSIGNAGE_CFG, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_ELECTRONICSIGNAGE_CFG");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struElectronicsignageCfg.byChannelID);
            SetByteToEdit(1, struElectronicsignageCfg.byEnabled);
            SetByteToEdit(2, struElectronicsignageCfg.byFontColor);
            SetByteToEdit(3, struElectronicsignageCfg.byFontType);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_ELECTRONICSIGNAGE_CFG");
        }
        break;
    case USB_SET_VCA_ELECTRONICSIGNAGE_CFG: //设置电子铭牌配置
        memset(&struElectronicsignageCfg, 0, sizeof(struElectronicsignageCfg));
        GetByteFromEdit(0, struElectronicsignageCfg.byChannelID);
        GetByteFromEdit(1, struElectronicsignageCfg.byEnabled);
        GetByteFromEdit(2, struElectronicsignageCfg.byFontColor);
        GetByteFromEdit(3, struElectronicsignageCfg.byFontType);
        struInputInfo.lpInBuffer = &struElectronicsignageCfg;
        struInputInfo.dwInBufferSize = sizeof(struElectronicsignageCfg);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_ELECTRONICSIGNAGE_CFG, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_ELECTRONICSIGNAGE_CFG");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_ELECTRONICSIGNAGE_CFG");
        }
        break;
    case USB_GET_VCA_FACE_DETECT:           //获取智能人脸检测信息
        memset(&struFaceDetect, 0, sizeof(struFaceDetect));
        struOutputInfo.lpOutBuffer = &struFaceDetect;
        struOutputInfo.dwOutBufferSize = sizeof(struFaceDetect);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_FACE_DETECT, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_FACE_DETECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struFaceDetect.byChannelID);
            SetByteToEdit(1, struFaceDetect.byDetFaceNum);
            SetDwordToEdit(2, struFaceDetect.struFaceInfo[0].dwRegionX);
            SetDwordToEdit(3, struFaceDetect.struFaceInfo[0].dwRegionY);
            SetDwordToEdit(4, struFaceDetect.struFaceInfo[0].dwRegionWidth);
            SetDwordToEdit(5, struFaceDetect.struFaceInfo[0].dwRegionHeight);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_FACE_DETECT");
        }
        break;
    case USB_SET_VCA_FACE_DETECT:           //设置智能人脸检测信息
        memset(&struFaceDetect, 0, sizeof(struFaceDetect));
        GetByteFromEdit(0, struFaceDetect.byChannelID);
        GetByteFromEdit(1, struFaceDetect.byDetFaceNum);
        GetDwordFromEdit(2, struFaceDetect.struFaceInfo[0].dwRegionX);
        GetDwordFromEdit(3, struFaceDetect.struFaceInfo[0].dwRegionY);
        GetDwordFromEdit(4, struFaceDetect.struFaceInfo[0].dwRegionWidth);
        GetDwordFromEdit(5, struFaceDetect.struFaceInfo[0].dwRegionHeight);
        struInputInfo.lpInBuffer = &struFaceDetect;
        struInputInfo.dwInBufferSize = sizeof(struFaceDetect);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_FACE_DETECT, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_FACE_DETECT");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_FACE_DETECT");
        }
        break;
    case USB_GET_VCA_FACE_CONTRAST:         //获取智能人脸比对信息
        memset(&struFaceContrast, 0, sizeof(struFaceContrast));
        struOutputInfo.lpOutBuffer = &struFaceContrast;
        struOutputInfo.dwOutBufferSize = sizeof(struFaceContrast);
        if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VCA_FACE_CONTRAST, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VCA_FACE_CONTRAST");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            SetByteToEdit(0, struFaceContrast.byChannelID);
            SetByteToEdit(1, struFaceContrast.byId);
            SetByteToEdit(2, struFaceContrast.byFPID);
            SetByteArrayToEdit(3, struFaceContrast.byName);
            SetByteArrayToEdit(4, struFaceContrast.byPost);
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_VCA_FACE_CONTRAST");
        }
        break;
    case USB_SET_VCA_FACE_CONTRAST:         //设置智能人脸比对信息
        memset(&struFaceContrast, 0, sizeof(struFaceContrast));
        GetByteFromEdit(0, struFaceContrast.byChannelID);
        GetByteFromEdit(1, struFaceContrast.byId);
        GetByteFromEdit(2, struFaceContrast.byFPID);
        GetByteArrayFromEdit(3, struFaceContrast.byName, MAX_NAME_LENGTH);
        GetByteArrayFromEdit(4, struFaceContrast.byPost, MAX_NAME_LENGTH);
        struInputInfo.lpInBuffer = &struFaceContrast;
        struInputInfo.dwInBufferSize = sizeof(struFaceContrast);
        if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VCA_FACE_CONTRAST, &struInputInfo, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_VCA_FACE_CONTRAST");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_VCA_FACE_CONTRAST");
        }
        break;
    case USB_SET_VCA_FACE_CONTRAST + 1:     //设备升级
    {
        CDlgUpgrade  dlg;
        dlg.m_lUserID = m_lUserID;
        dlg.DoModal();
        break;
    }
    case USB_CTRL_RESET_DEVICE:         //重置设备
        if (!USB_Control(m_lUserID, USB_CTRL_RESET_DEVICE, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_CTRL_RESET_DEVICE");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_CTRL_RESET_DEVICE");
        }
        break;
    case USB_GET_DEVICE_VERSION:         //获取设备版本
        struOutputInfo.dwOutBufferSize = sizeof(struDevVer);
        struOutputInfo.lpOutBuffer = &struDevVer;

        if (USB_GetDeviceConfig(m_lUserID, USB_GET_DEVICE_VERSION, NULL, &struOutputInfo))
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "USB_GET_DEVICE_VERSION DeviceName[%s] SerialNumber[%s] SoftwareVersion[%s]", struDevVer.byDeviceName, struDevVer.bySerialNumber, struDevVer.bySoftwareVersion);
        }
        else
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_DEVICE_VERSION");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        break;
    case USB_TRANS_FILE_UPLOAD_START:         //文件导入
    case USB_TRANS_FILE_DOWNLOAD_START:         //文件导出
    case USB_TRANS_DEVICE_ENCRYPTION_START:         //设备加密
    {
        CDlgFileTransfer dlg;
        dlg.m_lUserID = m_lUserID;
        dlg.DoModal();
        break;
    }
    //memcpy(struFileTransferInfo.byLocalFileName, m_csFilePath.GetBuffer(m_csFilePath.GetLength()), m_csFilePath.GetLength());
    //memcpy(struFileTransferInfo.byRemoteFileName, "/data/test.txt", strlen("/data/test.txt"));

    //if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_UPLOAD_START, &struFileTransferInfo, &struProgressInfo))
    //{
    //    LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_UPLOAD_START");
    //    DWORD dwError = USB_GetLastError();
    //    LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //}
    //else
    //{
    //    while (true)
    //    {
    //        if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_UPLOAD_PROGRESS, NULL, &struProgressInfo))
    //        {
    //            DWORD dwError = USB_GetLastError();
    //            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_TRANS_FILE_UPLOAD_PROGRESS  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //            break;
    //        }

    //        //状态判断
    //        if (struProgressInfo.byState == USB_FILE_TRANSFER_FAIL)
    //        {
    //            DWORD dwError = USB_GetLastError();
    //            LOGIN_INFO->WriteLog(ERR_LEVEL, "Upload failed  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //            break;
    //        }

    //        //传输中，打印进度
    //        LOGIN_INFO->WriteLog(INF_LEVEL, "Upload Progress[%d]", struProgressInfo.byProgress);
    //        Sleep(5000);

    //        //完成判断
    //        if (struProgressInfo.byState == USB_FILE_TRANSFER_SUCC || struProgressInfo.byProgress == 100)
    //        {
    //            break;
    //        }
    //    }

    //    //关闭加密
    //    if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_UPLOAD_STOP, NULL, NULL))
    //    {
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_UPLOAD_STOP");
    //        DWORD dwError = USB_GetLastError();
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //    }
    //}
    //break;
    //case USB_TRANS_FILE_DOWNLOAD_START:         //文件导出

    //    memcpy(struFileTransferInfo.byLocalFileName, "C:\\USBSDKLog\\test.txt", strlen("C:\\USBSDKLog\\test.txt"));
    //    memcpy(struFileTransferInfo.byRemoteFileName, "/data/test.txt", strlen("/data/test.txt"));

    //    if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_DOWNLOAD_START, &struFileTransferInfo, &struProgressInfo))
    //    {
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_DOWNLOAD_START");
    //        DWORD dwError = USB_GetLastError();
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //    }
    //    else
    //    {
    //        while (true)
    //        {
    //            if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_DOWNLOAD_PROGRESS, NULL, &struProgressInfo))
    //            {
    //                DWORD dwError = USB_GetLastError();
    //                LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_TRANS_FILE_DOWNLOAD_PROGRESS  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //                break;
    //            }

    //            //状态判断
    //            if (struProgressInfo.byState == USB_FILE_TRANSFER_FAIL)
    //            {
    //                DWORD dwError = USB_GetLastError();
    //                LOGIN_INFO->WriteLog(ERR_LEVEL, "Download failed  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //                break;
    //            }

    //            //传输中，打印进度
    //            LOGIN_INFO->WriteLog(INF_LEVEL, "Download Progress[%d]", struProgressInfo.byProgress);
    //            Sleep(5000);

    //            //完成判断
    //            if (struProgressInfo.byState == USB_FILE_TRANSFER_SUCC || struProgressInfo.byProgress == 100)
    //            {
    //                break;
    //            }
    //        }

    //        //关闭加密
    //        if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_DOWNLOAD_STOP, NULL, NULL))
    //        {
    //            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_DOWNLOAD_STOP");
    //            DWORD dwError = USB_GetLastError();
    //            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //        }
    //    }
    //    break;
    //case USB_TRANS_DEVICE_ENCRYPTION_START:         //设备加密
    //    memcpy(struFileTransferInfo.byLocalFileName, m_csFilePath.GetBuffer(m_csFilePath.GetLength()), m_csFilePath.GetLength());

    //    if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_DEVICE_ENCRYPTION_START, &struFileTransferInfo, &struProgressInfo))
    //    {
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_DEVICE_ENCRYPTION");
    //        DWORD dwError = USB_GetLastError();
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //    }
    //    else
    //    {
    //        while (true)
    //        {
    //            if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_DEVICE_ENCRYPTION_PROGRESS, NULL, &struProgressInfo))
    //            {
    //                DWORD dwError = USB_GetLastError();
    //                LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_TRANS_DEVICE_ENCRYPTION_PROGRESS  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //                break;
    //            }

    //            //状态判断
    //            if (struProgressInfo.byState == USB_FILE_TRANSFER_FAIL)
    //            {
    //                DWORD dwError = USB_GetLastError();
    //                LOGIN_INFO->WriteLog(ERR_LEVEL, "Dev Encrypt failed  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //                break;
    //            }

    //            //传输中，打印进度
    //            LOGIN_INFO->WriteLog(INF_LEVEL, "Dev Encrypt Progress[%d]", struProgressInfo.byProgress);
    //            Sleep(5000);

    //            //完成判断
    //            if (struProgressInfo.byState == USB_FILE_TRANSFER_SUCC || struProgressInfo.byProgress == 100)
    //            {
    //                break;
    //            }
    //        }

    //        //关闭加密
    //        if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_DEVICE_ENCRYPTION_STOP, NULL, NULL))
    //        {
    //            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_DEVICE_ENCRYPTION_STOP");
    //            DWORD dwError = USB_GetLastError();
    //            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    //        }
    //    }
    //    break;
    default:
        break;
    }
}


void SubDlgTransmissionInterface::OnCbnSelchangeComboCommand()
{
    // TODO:  在此添加控件通知处理程序代码
    int index = m_cbCommand.GetCurSel() + USB_TRANSMISSION_BASE + 101;
    CreateControl(PROPERTY_MAP[index]);
}

void SubDlgTransmissionInterface::CreateControl(vector<string> captionList)
{
    int x = 350;    //x坐标
    int y = 40;     //y坐标
    int d = 29;     //距离
    int h = 20;     //高度
    int w = 100;    //宽度

    for (int i = 0; i <= IDC_STATIC_END - IDC_STATIC_BEGIN; i++)
    {
        m_cStatic[i].DestroyWindow();
        m_cEdit[i].DestroyWindow();
    }

    for (unsigned int i = 0; i < captionList.size(); i++)
    {
        if (captionList[i].length() <= 0) break;
        //char szCaption
        m_cStatic[i].Create(captionList[i].c_str(), WS_TABSTOP | WS_VISIBLE | WS_CHILD, CRect(x, y + i * d, x + w, y + h + i * d), this, IDC_STATIC_BEGIN + i);
        m_cStatic[i].EnableWindow(TRUE);
        m_cStatic[i].SetFont(GetDlgItem(IDC_STATIC)->GetFont());
        //value
        m_cEdit[i].Create(WS_TABSTOP | WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, CRect(x + 100, y + i * d-2, x + 100 + w + 100, y + h + i * d-2), this, IDC_EDIT_BEGIN + i);
        m_cEdit[i].EnableWindow(TRUE);
        m_cEdit[i].SetFont(GetDlgItem(IDC_STATIC)->GetFont());
        m_cEdit[i].SetLimitText(MAX_PATH_LENGTH);
    }

}

void SubDlgTransmissionInterface::GetByteFromEdit(int index, BYTE& target)
{
    CString sValue;
    m_cEdit[index].GetWindowTextA(sValue);
    target = atoi(sValue);
}

void SubDlgTransmissionInterface::GetDwordFromEdit(int index, DWORD& target)
{
    CString sValue;
    m_cEdit[index].GetWindowTextA(sValue);
    target = atoi(sValue);
}

void SubDlgTransmissionInterface::GetByteArrayFromEdit(int index, BYTE* target, int len)
{
    CString sValue;
    m_cEdit[index].GetWindowTextA(sValue);
    memcpy(target, sValue, len);
    //sprintf_s((char*)target, len, "%s", sValue);
}

void SubDlgTransmissionInterface::SetByteToEdit(int index, BYTE value)
{
    char szValue[32];
    sprintf_s(szValue, sizeof(szValue), "%d", value);
    m_cEdit[index].SetWindowTextA(szValue);
}

void SubDlgTransmissionInterface::SetDwordToEdit(int index, DWORD value)
{
    char szValue[32];
    sprintf_s(szValue, sizeof(szValue), "%d", value);
    m_cEdit[index].SetWindowTextA(szValue);
}

void SubDlgTransmissionInterface::SetByteArrayToEdit(int index, BYTE* value)
{
    char szValue[32];
    sprintf_s(szValue, sizeof(szValue), "%s", value);
    m_cEdit[index].SetWindowTextA(szValue);
}

void SubDlgTransmissionInterface::OnPaint()
{
    CPaintDC dc(this);
    SET_CONTROL_LAN(IDD_SUBDLG_TRANSMISSION_INTERFACE, IDOK);
    SET_CONTROL_LAN(IDD_SUBDLG_TRANSMISSION_INTERFACE, IDC_STATIC);
}
