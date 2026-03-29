// SubDlgCameraInterface.cpp : 实现文件
//

#include "stdafx.h"
#include "SubDlgCameraInterface.h"
#include "afxdialogex.h"
#include "HCUsbSDK.h"
#include "PlayCtrl/PlayM4.h"
#include "Language.h"

#include <shlwapi.h>
#include <Dbt.h>
#include <direct.h>
#include <io.h>
#pragma comment(lib, "Shlwapi.lib")

BOOL GetVideoStreamTypeName(INT32 nStreamType, char *pName)
{
    if (pName == NULL)
    {
        return FALSE;
    }
    else if (nStreamType == USB_STREAM_MJPEG)
    {
        wsprintf(pName, "%s", "MJPEG");
    }
    else if (nStreamType == USB_STREAM_YUY2)
    {
        wsprintf(pName, "%s", "YUY2");
    }
    else if (nStreamType == USB_STREAM_NV12)
    {
        wsprintf(pName, "%s", "NV12");
    }
    else if (nStreamType == USB_STREAM_H264)
    {
        wsprintf(pName, "%s", "H264");
    }
    else
    {
        wsprintf(pName, "%s", "UNKNOW");
    }
    return TRUE;
}

BOOL GetAudioStreamTypeName(INT32 nStreamType, char *pName)
{
    if (pName == NULL)
    {
        return FALSE;
    }

    if (nStreamType == USB_STREAM_PCM)
    {
        wsprintf(pName, "%s", "PCM");
    }
    else
    {
        wsprintf(pName, "%s", "UNKNOW");
    }
    return TRUE;
}


// SubDlgCameraInterface 对话框

//IMPLEMENT_DYNAMIC(SubDlgCameraInterface, CDialog)

SubDlgCameraInterface::SubDlgCameraInterface(CWnd* pParent /*=NULL*/)
    : CDialog(SubDlgCameraInterface::IDD, pParent)
    , m_handle(-1)
    , m_hVideoWnd(NULL)
    , m_iPreviewChannel(-1)
    , m_iFDChannel(-1)
    , m_dwFrameRate(0)
    , m_dwWidth(0)
    , m_dwHeight(0)
    , m_dwSrcStreamType(0)
    , m_iCallBackChannel(-1)
    , m_iRecordChannel(-1)
    , m_dwRotateAngle(-1)
    , m_nVideoCapCount(0)
    , m_nAudioCapCount(0)
	, m_lPlayPort(-1)
    , m_bSetOSD(FALSE)
{
    memset(&m_CamAudioCap, 0, sizeof(USB_AUDIO_PARAM) * 100);
    memset(&m_CamVideoCap, 0, sizeof(USB_VIDEO_CAPACITY) * 100);
}

// SubDlgCameraInterface::~SubDlgCameraInterface()
// {
// }

void SubDlgCameraInterface::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COM_VIDEO_TYPE, m_cmbVideoType);
    DDX_Control(pDX, IDC_COM_AUDIO_TYPE, m_cmbAudioType);

    DDX_Control(pDX, IDC_COM_FACEDETECT_TYPE, m_cmbFDSnapMode);
    DDX_Control(pDX, IDC_COM_STREAM_TYPE, m_cmbCallBackType);
    DDX_Control(pDX, IDC_COM_PREVIEW_TYPE, m_cmbPreviewType);
    DDX_Control(pDX, IDC_COM_RECORD_TYPE, m_cmbRecordType);
    DDX_Control(pDX, IDC_CHK_PREVIEW_AUDIO, m_btnPreviewAudio);
    DDX_Control(pDX, IDC_STATIC_PREVIEW_WINDOW, m_PreviewWindow);
}


BEGIN_MESSAGE_MAP(SubDlgCameraInterface, CDialog)
    ON_BN_CLICKED(IDC_BTN_START_PREVIEW, &SubDlgCameraInterface::OnBnClickedBtnStartPreview)
    ON_BN_CLICKED(IDC_BTN_START_FACEDETECT, &SubDlgCameraInterface::OnBnClickedBtnStartFacedetect)
    ON_BN_CLICKED(IDC_BTN_START_RECORD, &SubDlgCameraInterface::OnBnClickedBtnStartRecord)
    ON_BN_CLICKED(IDC_BTN_START_STREAMCALLBACK, &SubDlgCameraInterface::OnBnClickedBtnStartStreamcallback)
    ON_BN_CLICKED(IDC_BTN_ENUM_CAP, &SubDlgCameraInterface::OnBnClickedBtnEnumCap)
    ON_BN_CLICKED(IDC_BTN_SET_CONFIG, &SubDlgCameraInterface::OnBnClickedBtnSetConfig)
    ON_BN_CLICKED(IDC_BTN_SET_ROTATE_ANGLE, &SubDlgCameraInterface::OnBnClickedBtnSetRotateAngle)
    ON_BN_CLICKED(IDC_BTN_SNAPSHOT, &SubDlgCameraInterface::OnBnClickedBtnSnapshot)
    ON_BN_CLICKED(IDC_BTN_STOP_PREVIEW, &SubDlgCameraInterface::OnBnClickedBtnStopPreview)
    ON_BN_CLICKED(IDC_BTN_STOP_RECORD, &SubDlgCameraInterface::OnBnClickedBtnStopRecord)
    ON_BN_CLICKED(IDC_BTN_STOP_FACEDETECT, &SubDlgCameraInterface::OnBnClickedBtnStopFacedetect)
    ON_BN_CLICKED(IDC_BTN_STOP_STREAMCALLBACK, &SubDlgCameraInterface::OnBnClickedBtnStopStreamcallback)
    ON_BN_CLICKED(IDC_BTN_EVENTCALLBACK, &SubDlgCameraInterface::OnBnClickedBtnEventcallback)
	ON_WM_PAINT()
    ON_BN_CLICKED(IDC_BUTTON1, &SubDlgCameraInterface::OnBnClickedButton1)
END_MESSAGE_MAP()


// SubDlgCameraInterface 消息处理程序


void SubDlgCameraInterface::OnOK()
{
    // TODO:  在此添加专用代码和/或调用基类

    //CDialog::OnOK();
}


void SubDlgCameraInterface::OnCancel()
{
    // TODO:  在此添加专用代码和/或调用基类

    //CDialog::OnCancel();
}


BOOL SubDlgCameraInterface::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  在此添加额外的初始化
    RECT rc;
    m_PreviewWindow.GetWindowRect(&rc);
    ScreenToClient(&rc);
    m_PreviewWindow.MoveWindow(rc.left, rc.top, 640, 480);

    GetDlgItem(IDC_BTN_START_PREVIEW)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_PREVIEW)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_START_FACEDETECT)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_FACEDETECT)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_START_RECORD)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_RECORD)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_START_STREAMCALLBACK)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_STREAMCALLBACK)->EnableWindow(FALSE);
    if (g_bEnglish)
    {
        m_cmbFDSnapMode.InsertString(0, _T("Disable"));
        m_cmbFDSnapMode.InsertString(1, _T("Auto"));
        m_cmbFDSnapMode.InsertString(2, _T("Manual"));
    }
    else
    {
        m_cmbFDSnapMode.InsertString(0, _T("禁用抓拍"));
        m_cmbFDSnapMode.InsertString(1, _T("自动抓拍"));
        m_cmbFDSnapMode.InsertString(2, _T("手动抓拍"));
    }
    m_cmbFDSnapMode.SetCurSel(1);

    m_cmbPreviewType.InsertString(0, _T("PS_H264"));
    m_cmbPreviewType.InsertString(1, _T("PS_MJPEG"));
    m_cmbPreviewType.InsertString(2, _T("PS_YUY2"));
    m_cmbPreviewType.InsertString(3, _T("PS_NV12"));
    m_cmbPreviewType.SetCurSel(1);

    m_cmbCallBackType.InsertString(0, _T("PS_H264"));
    m_cmbCallBackType.InsertString(1, _T("PS_MJPEG"));
    m_cmbCallBackType.InsertString(2, _T("PS_YUY2"));
    m_cmbCallBackType.InsertString(3, _T("PS_NV12"));
    m_cmbCallBackType.InsertString(4, _T("H264"));
    m_cmbCallBackType.InsertString(5, _T("MJPEG"));
    m_cmbCallBackType.InsertString(6, _T("YUY2"));
    m_cmbCallBackType.InsertString(7, _T("NV12"));
    m_cmbCallBackType.InsertString(8, _T("PCM"));
    m_cmbCallBackType.SetCurSel(1);

    m_cmbRecordType.InsertString(0, _T("PS_H264"));
    m_cmbRecordType.InsertString(1, _T("PS_MJPEG"));
    m_cmbRecordType.InsertString(2, _T("PS_YUY2"));
    m_cmbRecordType.InsertString(3, _T("PS_NV12"));
    m_cmbRecordType.InsertString(4, _T("MP4"));
    m_cmbRecordType.InsertString(5, _T("AVI"));
    m_cmbRecordType.InsertString(6, _T("H264"));
    m_cmbRecordType.InsertString(7, _T("MJPEG"));
    m_cmbRecordType.InsertString(8, _T("YUY2"));
    m_cmbRecordType.InsertString(9, _T("NV12"));
    m_cmbRecordType.InsertString(10, _T("PCM"));
    m_cmbRecordType.SetCurSel(1);

    m_btnPreviewAudio.SetCheck(FALSE);
    UpdateAudio(FALSE);
    m_cmbVideoType.ResetContent();
    m_cmbAudioType.ResetContent();

    m_handle = -1;
    m_hVideoWnd = NULL;
    m_iPreviewChannel = -1;
    m_iFDChannel = -1;
    m_dwFrameRate = 0;
    m_dwWidth = 0;
    m_dwHeight = 0;
    m_dwSrcStreamType = 0;
    m_iCallBackChannel = -1;
    m_iRecordChannel = -1;
    m_dwRotateAngle = -1;
    m_nVideoCapCount = -1;
    m_nAudioCapCount = -1;
    memset(&m_CamAudioCap, 0, sizeof(USB_AUDIO_PARAM) * 100);
    memset(&m_CamVideoCap, 0, sizeof(USB_VIDEO_CAPACITY) * 100);
    return TRUE;  // return TRUE unless you set the focus to a control
}

void SubDlgCameraInterface::UpdateAudio(BOOL bHaveAudio)
{
    if (bHaveAudio)
    {
        m_btnPreviewAudio.EnableWindow(TRUE);
    }
    else
    {
        m_btnPreviewAudio.EnableWindow(FALSE);
    }
}

static void __stdcall EventCallBack(LONG handle, long lEvent, long nParam1, long nParam2, void *pUser)
{
    SubDlgCameraInterface* pThis = (SubDlgCameraInterface*)pUser;
    if (pThis != NULL)
    {
        pThis->OnEventCallBack(handle, lEvent, nParam1, nParam2, pUser);
    }
    return;
}

void __stdcall SubDlgCameraInterface::OnEventCallBack(int handle, long lEvent, long nParam1, long nParam2, void *pUser)
{
    
    char strPrint[256] = { 0 };
    printf(strPrint, "SubDlgCameraInterface::OnEventCallBack:handle[%d], lEvent[%d]", handle, lEvent);
    if (lEvent == USB_EC_DEVICE_LOST)
    {
        if (nParam2 == USB_EVENTTYPE_DEV_REMOVED)
        {
            //::PostMessage(this->m_hWnd, WM_DEVICE_REMOVED, NULL, (LPARAM)handle);
        }
        else if (nParam2 == USB_EVENTTYPE_DEV_ADDED)
        {
            //::PostMessage(this->m_hWnd, WM_DEVICE_ADDED, NULL, (LPARAM)handle);
        }
    }
    OutputDebugString(strPrint);
}

BOOL SubDlgCameraInterface::GetVideoFormat(INT32 &dwSrcStreamType, INT32 &dwFrameRate, INT32 &dwWidth, INT32 &dwHeight)
{
    if (m_CamVideoCap == NULL || m_nVideoCapCount == 0)
    {
        return FALSE;
    }
    INT32 index = 0;
    INT32 count = 0;

    if (m_cmbVideoType.GetCount() == 0)
    {
        return FALSE;
    }
    index = m_cmbVideoType.GetCurSel();
    count = 0;
    for (INT32 i = 0; i < m_nVideoCapCount; i++)
    {
        for (INT32 j = 0; j < m_CamVideoCap[i].lListSize; j++)
        {
            if (count == index)
            {
                dwSrcStreamType = m_CamVideoCap[i].nType;
                dwFrameRate = m_CamVideoCap[i].lFrameRates[j];
                dwWidth = m_CamVideoCap[i].dwWidth;
                dwHeight = m_CamVideoCap[i].dwHeight;
            }
            count++;
        }
    }

    return TRUE;
}

BOOL SubDlgCameraInterface::GetAudioFormat(USB_AUDIO_PARAM* pWF)
{

    INT32 index = 0;
    INT32 count = 0;

    index = m_cmbAudioType.GetCurSel();
    count = 0;
    for (INT32 i = 0; i < m_nAudioCapCount; i++)
    {
        if (count == index)
        {
            *pWF = m_CamAudioCap[i];
        }
        count++;
    }

    return TRUE;
}

void SubDlgCameraInterface::OnCbnSelchangeCamVideo()
{
    // TODO: 在此添加控件通知处理程序代码
    m_cmbVideoType.ResetContent();

    BOOL bSetCurSel = FALSE;
    INT32 nItem = 0;
    char wszFormatItem[128] = { 0 };

    //设备1视频
    for (INT32 i = 0; i < m_nVideoCapCount; i++)
    {
        for (INT32 j = 0; j < m_CamVideoCap[i].lListSize; j++)
        {
            char wszType[64] = { 0 };
            GetVideoStreamTypeName(m_CamVideoCap[i].nType, wszType);
            memset(wszFormatItem, 0, sizeof(wszFormatItem));
            wsprintf(wszFormatItem, _T("[%s][%dw*%dh][%d]fps"),
                wszType,
                m_CamVideoCap[i].dwWidth,
                m_CamVideoCap[i].dwHeight,
                m_CamVideoCap[i].lFrameRates[j]);

            m_cmbVideoType.AddString(wszFormatItem);

            if (!bSetCurSel && m_CamVideoCap[i].dwWidth == 640 && m_CamVideoCap[i].dwHeight == 480
                && m_CamVideoCap[i].lFrameRates[j] == 30 && m_CamVideoCap[i].nType == USB_STREAM_MJPEG)
            {
                m_cmbVideoType.SetCurSel(nItem);
                bSetCurSel = TRUE;
            }
            nItem++;
        }
    }
    if (!bSetCurSel)
    {
        m_cmbVideoType.SetCurSel(0);
    }
}

void SubDlgCameraInterface::OnCbnSelchangeCamAudio()
{
    m_cmbAudioType.ResetContent();

    char wszFormatItem[128] = { 0 };
    //设备1音频
    for (INT32 i = 0; i < m_nAudioCapCount; i++)
    {

        char wszType[64] = { 0 };
        GetAudioStreamTypeName(m_CamAudioCap[i].wFormatTag, wszType);
        memset(wszFormatItem, 0, sizeof(wszFormatItem));
        wsprintf(wszFormatItem, _T("[%s][%dCH][%dHz][%dBPS]"),
            wszType,
            m_CamAudioCap[i].nChannels,
            m_CamAudioCap[i].nSamplesPerSec,
            m_CamAudioCap[i].nAvgBytesPerSec);
        m_cmbAudioType.AddString(wszFormatItem);
    }
    m_cmbAudioType.SetCurSel(0);
}

void SubDlgCameraInterface::GetCamVideoCap()
{
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };

    if (m_handle >= 0)
    {
        memset(&m_CamVideoCap, 0, sizeof(m_CamVideoCap));
        struConfigOutputInfo.lpOutBuffer = m_CamVideoCap;
        struConfigOutputInfo.dwOutBufferSize = sizeof(ULONG);
        m_nVideoCapCount = 0;
        //获取设备支持的视频格式
        if (!USB_GetDeviceConfig(m_handle, USB_GET_VIDEO_CAP, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GET_VIDEO_CAP failed, USB_GetLastError[%d]", USB_GetLastError());
            return;
        }
        LOGIN_INFO->WriteLog(DBG_LEVEL, "USB_GET_VIDEO_CAP success");
        //设备支持的视频格式的个数
        for (int i = 0; m_CamVideoCap[i].lListSize != 0; i++)
        {
            m_nVideoCapCount++;
        }
    }

}

void SubDlgCameraInterface::GetCamAudioCap()
{
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };

    if (m_handle >= 0)
    {
        memset(&m_CamAudioCap, 0, sizeof(m_CamAudioCap));
        m_nAudioCapCount = 0;
        struConfigOutputInfo.lpOutBuffer = m_CamAudioCap;
        struConfigOutputInfo.dwOutBufferSize = sizeof(ULONG);
        //获取设备支持的音频格式
        if (!USB_GetDeviceConfig(m_handle, USB_GET_AUDIO_CAP, &struConfigInputInfo, &struConfigOutputInfo))
        {
            //memset(&m_CamAudioCap, 0, sizeof(m_CamAudioCap));
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GET_AUDIO_CAP failed, USB_GetLastError[%d]", USB_GetLastError());
            return;
        }
        LOGIN_INFO->WriteLog(DBG_LEVEL, "USB_GET_AUDIO_CAP success");
        //设备支持的音频格式的个数
        for (int i = 0; (m_CamAudioCap[i].nAvgBytesPerSec && m_CamAudioCap[i].nChannels); i++)
        {
            m_nAudioCapCount++;
        }
    }

}

void SubDlgCameraInterface::OnBnClickedBtnStartPreview()
{
    // TODO:  在此添加控件通知处理程序代码
    //启动预览
    if (m_hVideoWnd == NULL)
    {
        if (g_bEnglish)
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "Please confirm the configuration information first！");
        }
        else
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "请先确认配置信息！");
        }
    }

    //根据分辨率布局窗口
//     RECT rc;
//     m_PreviewWindow.GetWindowRect(&rc);
//     ScreenToClient(&rc);
//     m_PreviewWindow.MoveWindow(rc.left, rc.top, m_dwWidth, m_dwWidth);

    INT32 nPreviewTypeIndex = m_cmbPreviewType.GetCurSel();
    BOOL bPreviewAudio = m_btnPreviewAudio.GetCheck();
    INT32 nPreviewType = USB_STREAM_PS_H264;
    switch (nPreviewTypeIndex)
    {
    case 0:
        nPreviewType = USB_STREAM_PS_H264;
        break;
    case 1:
        nPreviewType = USB_STREAM_PS_MJPEG;
        break;
    case 2:
        nPreviewType = USB_STREAM_PS_YUY2;
        break;
    case 3:
        nPreviewType = USB_STREAM_PS_NV12;
        break;
    default:
        break;
    }
    
    USB_PREVIEW_PARAM struPreviewParam = { 0 };
    struPreviewParam.dwStreamType = nPreviewType;
    struPreviewParam.bUseAudio = bPreviewAudio;
    struPreviewParam.hWindow = m_hVideoWnd;
    struPreviewParam.dwSize = sizeof(USB_PREVIEW_PARAM);
    m_iPreviewChannel = USB_StartPreview(m_handle, &struPreviewParam);
    if (m_iPreviewChannel < 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_StartPreview failed");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;
    }
    LOGIN_INFO->WriteLog(DBG_LEVEL, "USB_StartPreview success");
    GetDlgItem(IDC_BTN_START_PREVIEW)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_STOP_PREVIEW)->EnableWindow(TRUE);
	//回调和预览复用一个窗口句柄，让他只能开一个
	GetDlgItem(IDC_BTN_START_STREAMCALLBACK)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_STOP_STREAMCALLBACK)->EnableWindow(FALSE);
}

void SubDlgCameraInterface::OnBnClickedBtnStartFacedetect()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_iPreviewChannel < 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "Start preview first！");
        return;
    }
    USB_FACE_DETECT_PARAM struFDParam = { 0 };
    //struFDParam.byEnable = 1;
    //if (nSnapModeIndex == 0)
    //{
    //    struFDParam.bySnapMode = USB_FD_NOCAPTURE;
    //} 
    //else  if (nSnapModeIndex == 1)
    //{
    //    struFDParam.bySnapMode = USB_FD_AUTOCAPTURE;
    //}
    //else
    //{
    //    struFDParam.bySnapMode = USB_FD_MANNUALCAPTURE;
    //}
    //strcpy((char*)struFDParam.szFacePicPath, "C:\\USBSDKLog\\FacePicture1\\001");

    struFDParam.fnFDExtenResultCallBack = FaceDetectExtenResultCallBack;
    struFDParam.pUser = this;
    //启动人脸检测
    m_iFDChannel = USB_StartFaceDetect(m_handle, &struFDParam);
    if (m_iFDChannel < 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_StartFaceDetect failed, USB_GetLastError[%d]", USB_GetLastError());
        return;
    }
    LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_StartFaceDetect success");
    GetDlgItem(IDC_BTN_START_FACEDETECT)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_STOP_FACEDETECT)->EnableWindow(TRUE);
}

void SubDlgCameraInterface::OnBnClickedBtnStartRecord()
{
    // TODO:  在此添加控件通知处理程序代码
    INT32 nRecordTypeIndex = m_cmbRecordType.GetCurSel();
    INT32 nRecordType = USB_RECORDTYPE_PS_H264;
    BOOL bCaptureAudio = m_btnPreviewAudio.GetCheck();
    char szFilePath[128] = { 0 };
    sprintf(szFilePath, "C:\\USBSDKLog\\Record\\");
    if (access(szFilePath, 0)) // 是否有重名文件夹
    {
        mkdir(szFilePath);
    }
    USB_RECORD_PARAM struRecordParam = { 0 };

    switch (nRecordTypeIndex)
    {
    case 0:
        nRecordType = USB_RECORDTYPE_PS_H264;       // 录制PS_H264
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\PS_H264.ps");
        break;
    case 1:
        nRecordType = USB_RECORDTYPE_PS_MJPEG;      // 录制PS_MJPEG
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\PS_MJPEG.ps");
        break;
    case 2:
        nRecordType = USB_RECORDTYPE_PS_YUY2;      // 录制PS_YUY2
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\PS_YUY2.ps");
        break;
    case 3:
        nRecordType = USB_RECORDTYPE_PS_NV12;      // 录制PS_NV12
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\PS_NV12.ps");
        break;
    case 4:
        nRecordType = USB_RECORDTYPE_MP4;           // 录制mp4
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\H264.mp4");
        break;
    case 5:
        nRecordType = USB_RECORDTYPE_AVI;           // 录制AVI
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\record.avi");
        break;
    case 6:
        nRecordType = USB_STREAM_H264;       // 录制H264
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\H264");
        break;
    case 7:
        nRecordType = USB_STREAM_MJPEG;      // 录制MJPEG
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\MJPEG");
        break;
    case 8:
        nRecordType = USB_STREAM_YUY2;      // 录制YUY2
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\YUY2");
        break;
    case 9:
        nRecordType = USB_STREAM_NV12;      // 录制NV12
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\NV12");
        break;
    case 10:
        nRecordType = USB_STREAM_PCM;      // 录制音频
        strcpy((char*)struRecordParam.szFilePath, "C:\\USBSDKLog\\Record\\PCM");
        break;
    default:
        break;
    }

    struRecordParam.dwRecordType = nRecordType;
    struRecordParam.dwSize = sizeof(struRecordParam);
    struRecordParam.bRecordAudio = bCaptureAudio;
    m_iRecordChannel = USB_StartRecord(m_handle, &struRecordParam);
    if (m_iRecordChannel < 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_StartRecord failed");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "USB_StartRecord success");
    GetDlgItem(IDC_BTN_START_RECORD)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_STOP_RECORD)->EnableWindow(TRUE);
}

void SubDlgCameraInterface::OnBnClickedBtnStartStreamcallback()
{
    // TODO:  在此添加控件通知处理程序代码
	if (m_hVideoWnd == NULL)
	{
        if (g_bEnglish)
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "Please confirm the configuration information first！");
        }
        else
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "请先确认配置信息！");
        }
	}

    INT32 nCallBackTypeIndex = m_cmbCallBackType.GetCurSel();
    INT32 nCallBackStreamType = USB_STREAM_PS_H264;
    BOOL bCallBackAudio = m_btnPreviewAudio.GetCheck();
    switch (nCallBackTypeIndex)
    {
    case 0:
        nCallBackStreamType = USB_STREAM_PS_H264;
        break;
    case 1:
        nCallBackStreamType = USB_STREAM_PS_MJPEG;
        break;
    case 2:
        nCallBackStreamType = USB_STREAM_PS_YUY2;
        break;
    case 3:
        nCallBackStreamType = USB_STREAM_PS_NV12;
        break;
    case 4:
        nCallBackStreamType = USB_STREAM_H264;
        break;
    case 5:
        nCallBackStreamType = USB_STREAM_MJPEG;
        break;
    case 6:
        nCallBackStreamType = USB_STREAM_YUY2;
        break;
    case 7:
        nCallBackStreamType = USB_STREAM_NV12;
        break;
    case 8:
        nCallBackStreamType = USB_STREAM_PCM;
        break;
    default:
        break;
    }

	////开启成功后创建播放库句柄后再进行码流回调，如果需要使用回调播放功能，需要先预览一下，加载好播放库在来回调播放
	//if (!PlayM4_GetPort(&m_lPlayPort))//获取播放库未使用的通道号
	//{
	//	LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_GetPort error!"));
	//	return;
	//}

	//if (-1 == m_lPlayPort)
	//{
	//	LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayCtrl handle not exist!"));
	//	return;
	//}

	//if (!PlayM4_SetStreamOpenMode(m_lPlayPort, STREAME_REALTIME))  //设置文件流播放模式，支持倍速
	//{
	//	LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_SetStreamOpenMode error!"));
	//	return;
	//}

    //启动码流回调
    USB_STREAM_CALLBACK_PARAM struDecCbInfo = { 0 };
    struDecCbInfo.dwStreamType = nCallBackStreamType;
    struDecCbInfo.bUseAudio = bCallBackAudio;
    struDecCbInfo.pUser = this;
    struDecCbInfo.funcStreamCallBack = StreamCallBack;
    struDecCbInfo.dwSize = sizeof(struDecCbInfo);
    m_iCallBackChannel = USB_StartStreamCallback(m_handle, &struDecCbInfo);
    if (m_iCallBackChannel < 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_StartStreamCallback failed, USB_GetLastError[%d]", USB_GetLastError());
        return;
    }

	LOGIN_INFO->WriteLog(DBG_LEVEL, "USB_StartStreamCallback success");
    GetDlgItem(IDC_BTN_START_STREAMCALLBACK)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_STOP_STREAMCALLBACK)->EnableWindow(TRUE);

	GetDlgItem(IDC_BTN_START_PREVIEW)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_STOP_PREVIEW)->EnableWindow(FALSE);
}

static void __stdcall StreamCallBack(LONG handle, USB_FRAME_INFO *pFrameInfo, void* pUser)
{
    SubDlgCameraInterface* pThis = (SubDlgCameraInterface*)pUser;
    if (pThis != NULL)
    {
        pThis->StreamCallBackLocal(handle, pFrameInfo, pUser);
    }
    return;
}

void __stdcall SubDlgCameraInterface::StreamCallBackLocal(INT32 handle, USB_FRAME_INFO *pFrameInfo, void* pUser)
{
    char strPrint[256] = { 0 };
    sprintf(strPrint, _T("DecCallBack1:handle[%d], StreamType[%d], FrameLen[%d], RealFrameRate[%d], DataType[%d]\n"),
		handle, pFrameInfo->dwStreamType, pFrameInfo->dwBufSize, pFrameInfo->dwFrameRate, pFrameInfo->dwDataType);
    OutputDebugString(strPrint);
	//TODO调用播放库播放视频，收到码流头开启播放库
	//if (-1 == m_lPlayPort)
	//{
	//	LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayCtrl handle not exist!"));
	//	return;
	//}

	//if (pFrameInfo->dwDataType == 1)  //收到码流头
	//{
	//	if (!PlayM4_OpenStream(m_lPlayPort, pFrameInfo->pBuf, pFrameInfo->dwBufSize, 2 * 1024 * 1024)) //打开流接口
	//	{
	//		LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_OpenStream error!"));
	//		return;
	//	}

	//	if (m_hVideoWnd == NULL)
	//	{
 //           if (g_bEnglish)
 //           {
 //               LOGIN_INFO->WriteLog(ERR_LEVEL, "Please confirm the configuration information first！");
 //           }
 //           else
 //           {
 //               LOGIN_INFO->WriteLog(ERR_LEVEL, "请先确认配置信息！");
 //           }
	//	}

	//	if (!PlayM4_Play(m_lPlayPort, m_hVideoWnd)) //播放开始
	//	{
	//		LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_Play error!"));
	//		return;
	//	}
	//}
	//else
	//{
	//	if (!PlayM4_InputData(m_lPlayPort, pFrameInfo->pBuf, pFrameInfo->dwBufSize))
	//	{
	//		LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_InputData error!"));
	//	}
	//}
}

void SubDlgCameraInterface::OnBnClickedBtnEnumCap()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);
    GetCamVideoCap();
    GetCamAudioCap();
    OnCbnSelchangeCamVideo();
    OnCbnSelchangeCamAudio();
    UpdateData(FALSE);
}

static void __stdcall FaceDetectExtenResultCallBack(long lPort, LPUSB_FD_RESULT_PARAM FDParamInfo, void* pUser)
{
    SubDlgCameraInterface* pThis = (SubDlgCameraInterface*)pUser;
    if (pThis != NULL)
    {
        pThis->FaceDetectExtenResultCallBackLoacl(lPort, FDParamInfo, pUser);
    }
}

void __stdcall SubDlgCameraInterface::FaceDetectExtenResultCallBackLoacl(long lPort, LPUSB_FD_RESULT_PARAM FDParamInfo, void* pUser)
{
    static int dwIndex = 0;
    dwIndex++;

    if (FDParamInfo->dwFaceTotalNum > 0)
    {
        //char szPicName[256] = { 0 };
        //sprintf(szPicName, "C:\\USBSDKLog\\FacePicture\\demo\\RGB_%d_%dw_%dh.nv12", 
        //    dwIndex, FDParamInfo->struMediaData.dwWidth, FDParamInfo->struMediaData.dwHeight);
        //FILE *ff = fopen(szPicName, "wb+");
        //if (ff != NULL)
        //{
        //    fwrite((void*)FDParamInfo->struMediaData.pBuffer, 1, FDParamInfo->struMediaData.dwLen, ff);
        //    fclose(ff);
        //}

        char szJpgPicName[256] = { 0 };
        sprintf(szJpgPicName, "C:\\USBSDKLog\\FacePicture\\demo\\RGB_%d_%dw_%dh.jpg",
            dwIndex, FDParamInfo->struMediaData.dwWidth, FDParamInfo->struMediaData.dwHeight);
        FILE *ff_jpg = fopen(szJpgPicName, "wb+");
        if (ff_jpg != NULL)
        {
            fwrite((void*)FDParamInfo->struMediaData.pJpgBuffer, 1, FDParamInfo->struMediaData.dwJpgLen, ff_jpg);
            fclose(ff_jpg);
        }
    }

    for (int i = 0; i < FDParamInfo->dwFaceTotalNum; i++)
    {
        //设置人脸图片评分阈值，作为最优判断活体
        //char szPicName[256] = { 0 };
        char szJpgPicName[256] = { 0 };
        char strPrint[256] = { 0 };
        if (FDParamInfo->struFaceParam[i].struFaceQualityList.fFaceScore > 0.5 ) //过滤掉评分较低的人脸
        {
            sprintf(strPrint, _T("fFaceScore[%f]\n"), FDParamInfo->struFaceParam[i].struFaceQualityList.fFaceScore);
            OutputDebugString(strPrint);

            //sprintf(szPicName, "C:\\USBSDKLog\\FacePicture\\demo\\SubPic_%d_%dw_%dh.nv12", 
            //    dwIndex, FDParamInfo->struFaceParam[i].struSubFacePic.dwWidth, FDParamInfo->struFaceParam[i].struSubFacePic.dwHeight);
            //FILE *fff = fopen(szPicName, "wb+");
            //if (fff != NULL)
            //{
            //    fwrite((void*)FDParamInfo->struFaceParam[i].struSubFacePic.pSubFacePic, 1, FDParamInfo->struFaceParam[i].struSubFacePic.dwSubFacePicLen, fff);
            //    fclose(fff);
            //}

            sprintf(szJpgPicName, "C:\\USBSDKLog\\FacePicture\\demo\\SubPic_%d_%dw_%dh.jpg",
                dwIndex, FDParamInfo->struFaceParam[i].struSubFacePic.dwWidth, FDParamInfo->struFaceParam[i].struSubFacePic.dwHeight);
            FILE *fff_jpg = fopen(szJpgPicName, "wb+");
            if (fff_jpg != NULL)
            {
                fwrite((void*)FDParamInfo->struFaceParam[i].struSubFacePic.pSubFaceJpgPic, 1, FDParamInfo->struFaceParam[i].struSubFacePic.dwSubFaceJpgPicLen, fff_jpg);
                fclose(fff_jpg);
            }

            sprintf(strPrint, _T("人脸抓拍完成\n"));
            OutputDebugString(strPrint);
            if (g_bEnglish)
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, _T("Face capture completed\n"));
            }
            else
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, _T("人脸抓拍完成\n")); //此处弹框会导致预览卡顿
            }
        }
    }

    return;
}

void SubDlgCameraInterface::OnBnClickedBtnSetConfig()
{
    // TODO:  在此添加控件通知处理程序代码

    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
    INT32 nPreviewTypeIndex = m_cmbPreviewType.GetCurSel();
    INT32 nPreviewType = USB_STREAM_PS_H264;

    BOOL bPreviewAudio = m_btnPreviewAudio.GetCheck();
    if (m_hVideoWnd == NULL)
    {
        m_hVideoWnd = m_PreviewWindow.GetSafeHwnd();
    }

    if (bPreviewAudio)
    {
        USB_AUDIO_PARAM struWF = { 0 };
        //选择音频格式
        GetAudioFormat(&struWF);

        memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
        memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

        struConfigInputInfo.lpInBuffer = &struWF;
        struConfigInputInfo.dwInBufferSize = sizeof(struWF);

        if (!USB_SetDeviceConfig(m_handle, USB_SET_AUDIO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SET_AUDIO_PARAM failed！, USB_GetLastError[%d]", USB_GetLastError()); //此处弹框会导致预览卡顿
            return;
        }
		LOGIN_INFO->WriteLog(INF_LEVEL, _T("USB_SET_AUDIO_PARAM success")); //此处弹框会导致预览卡顿
    }

    GetVideoFormat(m_dwSrcStreamType, m_dwFrameRate, m_dwWidth, m_dwHeight);

    USB_VIDEO_PARAM struVideoParam = { 0 };
    struVideoParam.dwVideoFormat = m_dwSrcStreamType;
    struVideoParam.dwFramerate = m_dwFrameRate;
    struVideoParam.dwWidth = m_dwWidth;
    struVideoParam.dwHeight = m_dwHeight;

    memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
    memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

    struConfigInputInfo.lpInBuffer = &struVideoParam;
    struConfigInputInfo.dwInBufferSize = sizeof(struVideoParam);

    //设置设备视频参数
    if (!USB_SetDeviceConfig(m_handle, USB_SET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SET_VIDEO_PARAM failed！, USB_GetLastError[%d]", USB_GetLastError());
        //return;
    }
	LOGIN_INFO->WriteLog(INF_LEVEL, _T("USB_SET_VIDEO_PARAM success"));

     //更新需要设置的参数
     USB_SRC_STREAM_CFG struSrcStreamCfg = { 0 };
     struSrcStreamCfg.dwStreamType = m_dwSrcStreamType;
     struSrcStreamCfg.bUseAudio = bPreviewAudio;
 
     memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
     memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));
 
     struConfigInputInfo.lpInBuffer = &struSrcStreamCfg;
     struConfigInputInfo.dwInBufferSize = sizeof(struSrcStreamCfg);
 
     //设置设备视频参数
     if (!USB_SetDeviceConfig(m_handle, USB_SET_SRC_STREAM_TYPE, &struConfigInputInfo, &struConfigOutputInfo))
     {
         LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SET_SRC_STREAM_TYPE failed！, USB_GetLastError[%d]", USB_GetLastError());
         return;
     }
     LOGIN_INFO->WriteLog(INF_LEVEL, _T("USB_SET_SRC_STREAM_TYPE success"));
     //m_bConfig = TRUE;
}

void SubDlgCameraInterface::SetOsd(BOOL bOpen)
{
	USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
	USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
	memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
	memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

	USB_OSD struOsd = { 0 };
    struOsd.byEnabled = bOpen; //开启osd

	struOsd.struOsdInfo.wLineNums = 2;  //Osd 行数
	struOsd.struOsdInfo.uiWinWidth = 704;
	struOsd.struOsdInfo.uiWinHeight = 576;


	//第一行osd信息
	sprintf((char*)struOsd.struOsdLineList[0].szOsdString, "aaaaaaaaaaaaaaaa");
	struOsd.struOsdLineList[0].uiOffsetx = 0;
    struOsd.struOsdLineList[0].uiOffsety = 0;

	////第二行osd信息
	sprintf((char*)struOsd.struOsdLineList[1].szOsdString, "bbbbbbbbbbbbbbbb");
	struOsd.struOsdLineList[1].uiOffsetx = 100;
	struOsd.struOsdLineList[1].uiOffsety = 100;

	struConfigInputInfo.lpInBuffer = &struOsd;
	struConfigInputInfo.dwInBufferSize = sizeof(struOsd);

	if (!USB_SetDeviceConfig(m_handle, USB_SET_OSD, &struConfigInputInfo, &struConfigOutputInfo))
	{
        int iRet = USB_GetLastError();
		LOGIN_INFO->WriteLog(ERR_LEVEL, _T("Set OSD fail!"));
		return;
	}
	LOGIN_INFO->WriteLog(INF_LEVEL, _T("set OSD success!"));
}


void SubDlgCameraInterface::OnBnClickedBtnSetRotateAngle()
{
    // TODO:  在此添加控件通知处理程序代码
    //-1(不旋转)  0(向左旋转90度)  1(向右旋转90度)  2(旋转180度)

    switch (m_dwRotateAngle)
    {
    case -1:
        m_dwRotateAngle = 0;
        break;
    case 0:
        m_dwRotateAngle = 2;
        break;
    case 1:
        m_dwRotateAngle = -1;
        break;
    case 2:
        m_dwRotateAngle = 1;
        break;
    default:
        break;
    }

    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
    USB_ROTATE_ANGLE_INFO struRotateAngleInfo = { 0 };
    memset(&struRotateAngleInfo, 0, sizeof(struRotateAngleInfo));
    struRotateAngleInfo.dwType = m_dwRotateAngle;
    struConfigInputInfo.lpInBuffer = &struRotateAngleInfo;
    struConfigInputInfo.dwInBufferSize = sizeof(struRotateAngleInfo);

    //旋转设备
    if (m_handle >= 0)
    {
        if (!USB_SetDeviceConfig(m_handle, USB_SET_ROTATE_ANGLE, &struConfigInputInfo, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SET_ROTATE_ANGLE failed！, USB_GetLastError[%d]", USB_GetLastError()); //此处弹框会导致预览卡顿
            return;
        }
    }
    m_PreviewWindow.Invalidate(FALSE);
    LOGIN_INFO->WriteLog(DBG_LEVEL, _T("USB_SET_ROTATE_ANGLE success")); //此处弹框会导致预览卡顿
}


void SubDlgCameraInterface::OnBnClickedBtnSnapshot()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);
    CHAR szJPGFile[512] = { 0 };
    char szFileName[128] = { 0 };
    int  szLen = MAX_PATH;
    SYSTEMTIME stUTC;
    ::GetLocalTime(&stUTC);

    int nSnapModeIndex = m_cmbFDSnapMode.GetCurSel();

    sprintf(szJPGFile, "C:\\USBSDKLog\\Snapshot\\");
    sprintf(szFileName, "%d-%02d-%02d %02d.%02d.%02d.jpg", stUTC.wYear, stUTC.wMonth, stUTC.wDay, stUTC.wHour, stUTC.wMinute, stUTC.wSecond);
    if (access(szJPGFile, 0)) // 是否有重名文件夹
    {
        mkdir(szJPGFile);
    }
    strcat(szJPGFile, szFileName);

    USB_CAPTURE_PARAM struCapParam = { 0 };
    struCapParam.dwType = 1;
    struCapParam.pBuf = (unsigned char*)malloc(1024 * 1024 * 10);
    struCapParam.dwBufSize = 1024 * 1024 * 10;

    strncpy(struCapParam.szFilePath, szJPGFile, strlen(szJPGFile));
    if (nSnapModeIndex == 2)
    {
        //struCapParam.bCaptureFacePic = TRUE;
    }
    if (!USB_Capture(m_handle, &struCapParam))
    {
        int iRet = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_Capture failed！, USB_GetLastError[%d], error msg [%s]", iRet, USB_GetErrorMsg(iRet));
    }
    else
    {
		LOGIN_INFO->WriteLog(INF_LEVEL, TEXT("USB_Capture success！"));
        if (struCapParam.dwType == 1)
        {
            FILE *ff = fopen(szJPGFile, "wb+");
            if (ff != NULL)
            {
                fwrite((void*)struCapParam.pBuf, 1, struCapParam.dwDataLen, ff);
                fclose(ff);
            }
        }
    }
}

void SubDlgCameraInterface::OnBnClickedBtnStopPreview()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_iPreviewChannel >= 0)
    {
        USB_StopChannel(m_handle, m_iPreviewChannel);
        m_iPreviewChannel = -1;
    }
    m_PreviewWindow.UpdateData(FALSE);
    //根据分辨率布局窗口
    RECT rc;
    m_PreviewWindow.GetWindowRect(&rc);
    ScreenToClient(&rc);
    m_PreviewWindow.MoveWindow(rc.left, rc.top, 640, 480);
    m_PreviewWindow.EnableWindow(FALSE);
    m_PreviewWindow.Invalidate(TRUE);
    m_PreviewWindow.UpdateWindow();
    GetDlgItem(IDC_BTN_START_PREVIEW)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_PREVIEW)->EnableWindow(FALSE);

	//回调和预览复用一个窗口句柄，让他只能开一个
	GetDlgItem(IDC_BTN_START_STREAMCALLBACK)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_STOP_STREAMCALLBACK)->EnableWindow(FALSE);
    UpdateData(FALSE);
}

void SubDlgCameraInterface::OnBnClickedBtnStopRecord()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_iRecordChannel >= 0)
    {
        USB_StopChannel(m_handle, m_iRecordChannel);
        m_iRecordChannel = -1;
    }
    GetDlgItem(IDC_BTN_START_RECORD)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_RECORD)->EnableWindow(FALSE);
}

void SubDlgCameraInterface::OnBnClickedBtnStopFacedetect()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_iFDChannel >= 0)
    {
        USB_StopChannel(m_handle, m_iFDChannel);
        m_iFDChannel = -1;
    }
    GetDlgItem(IDC_BTN_START_FACEDETECT)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_FACEDETECT)->EnableWindow(FALSE);
}

void SubDlgCameraInterface::OnBnClickedBtnStopStreamcallback()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_iCallBackChannel >= 0)
    {
        USB_StopChannel(m_handle, m_iCallBackChannel);
        m_iCallBackChannel = -1;
    }

	if (-1 != m_lPlayPort)
	{
		if (!PlayM4_Stop(m_lPlayPort))
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_Stop error!"));
		}
		if (!PlayM4_CloseStream(m_lPlayPort))
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_CloseStream error!"));
		}
		if (!PlayM4_FreePort(m_lPlayPort))
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, TEXT("PlayM4_FreePort error!"));
		}
	}
	m_lPlayPort = -1;
    GetDlgItem(IDC_BTN_START_STREAMCALLBACK)->EnableWindow(TRUE);
    GetDlgItem(IDC_BTN_STOP_STREAMCALLBACK)->EnableWindow(FALSE);

	GetDlgItem(IDC_BTN_START_PREVIEW)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_STOP_PREVIEW)->EnableWindow(FALSE);
}

void SubDlgCameraInterface::OnBnClickedBtnEventcallback()
{
    // TODO:  在此添加控件通知处理程序代码
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
    //设置事件回调函数
    USB_EVENT_CALLBACK_PARAM struEventCallBack = { 0 };
    struEventCallBack.funcEventCallBack = EventCallBack;
    struEventCallBack.pUser = this;

    struConfigInputInfo.lpInBuffer = &struEventCallBack;
    struConfigInputInfo.dwInBufferSize = sizeof(struEventCallBack);
    if (!USB_SetDeviceConfig(m_handle, USB_SET_EVENT_CALLBACK, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_EVENT_CALLBACK");
        //AfxMessageBox(TEXT("设置Dev事件回调参数失败"));
        return;
    }
	LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_EVENT_CALLBACK");
}

void SubDlgCameraInterface::OnPaint()
{
    CPaintDC dc(this);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_VIDEO1_TYPE);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_AUDIO1_TYPE);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_DEV1_CFG);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_PREVIEW_CFG);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_PRVIEW_STREAM_TYPE);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_CHK_PREVIEW_AUDIO);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_CAPTURE_CFG);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_CAPTURE_STREAM_TYPE);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_FACEDETECT_CFG);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_CAPTURE_CFG2);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_STATIC_CAPTURE_STREAM_TYPE2);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_START_PREVIEW);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_START_FACEDETECT);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_START_RECORD);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_START_STREAMCALLBACK);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_ENUM_CAP);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_SET_CONFIG);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_SET_ROTATE_ANGLE);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_SNAPSHOT);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_STOP_PREVIEW);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_STOP_RECORD);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_STOP_FACEDETECT);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_STOP_STREAMCALLBACK);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_INTERFACE, IDC_BTN_EVENTCALLBACK);
}


void SubDlgCameraInterface::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_bSetOSD)
    {
        SetOsd(FALSE);
        m_bSetOSD = FALSE;
    }
    else
    {
        SetOsd(TRUE);
        m_bSetOSD = TRUE;
    }
}
