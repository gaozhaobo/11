// SubDlgCameraControl.cpp : 实现文件
//

#include "stdafx.h"
#include "SubDlgCameraControl.h"
#include "afxdialogex.h"
#include "Language.h"


// CSubDlgCameraControl 对话框

IMPLEMENT_DYNAMIC(CSubDlgCameraControl, CDialog)

CSubDlgCameraControl::CSubDlgCameraControl(CWnd* pParent /*=NULL*/)
	: CDialog(CSubDlgCameraControl::IDD, pParent)
{

}

CSubDlgCameraControl::~CSubDlgCameraControl()
{
}

void CSubDlgCameraControl::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STATIC_PREVIEW, m_PreviewWindow);
}


BEGIN_MESSAGE_MAP(CSubDlgCameraControl, CDialog)
    ON_WM_HSCROLL()
    ON_BN_CLICKED(IDC_BUTTON_GET_VIDEO_CAP, OnBnClickedButtonGetVideoCap)
    ON_BN_CLICKED(IDC_BUTTON_SET_DEFAULT_CAP, OnBnClickedButtonSetDefaultCap)
    ON_BN_CLICKED(IDC_BT_START_PREVIEW, OnBnClickedBtStartPreview)
    ON_BN_CLICKED(IDC_BT_STOP_PREVIEW, OnBnClickedBtStopPreview)
    ON_COMMAND_RANGE(IDC_BT_CHECK_BEGIN, IDC_BT_CHECK_END, OnBnCheckClicked)
	ON_WM_PAINT()
END_MESSAGE_MAP()


BOOL CSubDlgCameraControl::OnInitDialog()
{
    CDialog::OnInitDialog();

    GetDlgItem(IDC_BT_START_PREVIEW)->EnableWindow(TRUE);
    GetDlgItem(IDC_BT_STOP_PREVIEW)->EnableWindow(FALSE);

    m_hVideoWnd = m_PreviewWindow.GetSafeHwnd();

    int x = 20;	//x坐标
    int y = 40;	//y坐标
    int d = 29;	//距离
    int h = 25;	//高度
    int w = 60;	//宽度
    for (int id = IDC_STATIC_BEGIN, i = 0; id <= IDC_STATIC_END; id++, i++)
    {
        if (i == 10)
        {
            x += 290;
            y -= i*d;
        }

        if (g_bEnglish)
        {
            m_cStatic[i].Create(PROPERTY_LIST_EN[i], WS_TABSTOP | WS_VISIBLE | WS_CHILD, CRect(x, y + i * d, x + w, y + h + i * d), this, id);
        }

        else
        {
            m_cStatic[i].Create(PROPERTY_LIST_CN[i], WS_TABSTOP | WS_VISIBLE | WS_CHILD, CRect(x, y + i * d, x + w, y + h + i * d), this, id);
        }
        m_cStatic[i].EnableWindow(FALSE);
        m_cStatic[i].SetFont(GetDlgItem(IDC_STATIC19)->GetFont());
    }

    x = 75;
    y = 40;
    w = 145;

    for (int id = IDC_SLIDER_BEGIN, i = 0; id <= IDC_SLIDER_END; id++, i++)
    {
        if (i == 10)
        {
            x += 295;
            y -= i*d;
        }
        m_cSlider[i].Create(WS_TABSTOP | WS_VISIBLE | WS_CHILD, CRect(x, y + i * d, x + w, y + h + i * d), this, id);
        m_cSlider[i].EnableWindow(FALSE);
    }

    x = 220;
    y = 40;
    h = 20;
    w = 45;
    for (int id = IDC_EDIT_BEGIN, i = 0; id <= IDC_EDIT_END; id++, i++)
    {
        if (i == 10)
        {
            x += 295;
            y -= i*d;
        }
        m_cEdit[i].Create(WS_TABSTOP | WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER, CRect(x, y + i * d, x + w, y + h + i * d), this, id);
        m_cEdit[i].EnableWindow(FALSE);
        m_cEdit[i].SetFont(GetDlgItem(IDC_STATIC19)->GetFont());
    }

    x = 270;
    y = 40;
    w = 20;
    for (int id = IDC_BT_CHECK_BEGIN, i = 0; id <= IDC_BT_CHECK_END; id++, i++)
    {
        if (i == 10)
        {
            x += 295;
            y -= i*d;
        }
        m_cButton[i].Create("", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, CRect(x, y + i * d, x + w, y + h + i * d), this, id);
        m_cButton[i].EnableWindow(FALSE);
    }

    return TRUE;
}


// CSubDlgCameraControl 消息处理程序


void CSubDlgCameraControl::OnBnClickedButtonGetVideoCap()
{
    int index = 0;
    USB_VIDEO_PROPERTY_CAP struVideoPropertyCap = { 0 };
    if (GetPropertyCap(&struVideoPropertyCap) == 0)
    {
        SetSliderState(index++, struVideoPropertyCap.struBrightness.dwMin, struVideoPropertyCap.struBrightness.dwMax, struVideoPropertyCap.struBrightness.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struContrast.dwMin, struVideoPropertyCap.struContrast.dwMax, struVideoPropertyCap.struContrast.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struHue.dwMin, struVideoPropertyCap.struHue.dwMax, struVideoPropertyCap.struHue.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struSaturation.dwMin, struVideoPropertyCap.struSaturation.dwMax, struVideoPropertyCap.struSaturation.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struSharpness.dwMin, struVideoPropertyCap.struSharpness.dwMax, struVideoPropertyCap.struSharpness.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struGamma.dwMin, struVideoPropertyCap.struGamma.dwMax, struVideoPropertyCap.struGamma.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struColorEnable.dwMin, struVideoPropertyCap.struColorEnable.dwMax, struVideoPropertyCap.struColorEnable.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struWhiteBalance.dwMin, struVideoPropertyCap.struWhiteBalance.dwMax, struVideoPropertyCap.struWhiteBalance.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struBacklightCompensation.dwMin, struVideoPropertyCap.struBacklightCompensation.dwMax, struVideoPropertyCap.struBacklightCompensation.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struGain.dwMin, struVideoPropertyCap.struGain.dwMax, struVideoPropertyCap.struGain.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struPowerlineFrequency.dwMin, struVideoPropertyCap.struPowerlineFrequency.dwMax, struVideoPropertyCap.struPowerlineFrequency.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struPan.dwMin, struVideoPropertyCap.struPan.dwMax, struVideoPropertyCap.struPan.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struTilt.dwMin, struVideoPropertyCap.struTilt.dwMax, struVideoPropertyCap.struTilt.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struRoll.dwMin, struVideoPropertyCap.struRoll.dwMax, struVideoPropertyCap.struRoll.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struZoom.dwMin, struVideoPropertyCap.struZoom.dwMax, struVideoPropertyCap.struZoom.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struExposure.dwMin, struVideoPropertyCap.struExposure.dwMax, struVideoPropertyCap.struExposure.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struIris.dwMin, struVideoPropertyCap.struIris.dwMax, struVideoPropertyCap.struIris.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struFocus.dwMin, struVideoPropertyCap.struFocus.dwMax, struVideoPropertyCap.struFocus.byEnabled);

        SetSliderState(index++, struVideoPropertyCap.struLowBrightnessCompensation.dwMin, struVideoPropertyCap.struLowBrightnessCompensation.dwMax, struVideoPropertyCap.struLowBrightnessCompensation.byEnabled);
    }

    //获取音量属性
    SetSliderState(19, 0, 100, 1);
}


void CSubDlgCameraControl::OnBnClickedButtonSetDefaultCap()
{
    USB_VIDEO_PROPERTY_CAP struVideoPropertyCap = { 0 };
    if (GetPropertyCap(&struVideoPropertyCap) == 0)
    {
        if (struVideoPropertyCap.struBrightness.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struBrightness.dwDef, SET_COMMAND_INDEX_LIST[0]) == 0)
        {
            SetSliderPos(0, struVideoPropertyCap.struBrightness.dwDef);
        }
        if (struVideoPropertyCap.struContrast.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struContrast.dwDef, SET_COMMAND_INDEX_LIST[1]) == 0)
        {
            SetSliderPos(1, struVideoPropertyCap.struContrast.dwDef);
        }
        if (struVideoPropertyCap.struHue.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struHue.dwDef, SET_COMMAND_INDEX_LIST[2]) == 0)
        {
            SetSliderPos(2, struVideoPropertyCap.struHue.dwDef);
        }
        if (struVideoPropertyCap.struSaturation.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struSaturation.dwDef, SET_COMMAND_INDEX_LIST[3]))
        {
            SetSliderPos(3, struVideoPropertyCap.struSaturation.dwDef);
        }
        if (struVideoPropertyCap.struSharpness.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struSharpness.dwDef, SET_COMMAND_INDEX_LIST[4]) == 0)
        {
            SetSliderPos(4, struVideoPropertyCap.struSharpness.dwDef);
        }
        if (struVideoPropertyCap.struGamma.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struGamma.dwDef, SET_COMMAND_INDEX_LIST[5]) == 0)
        {
            SetSliderPos(5, struVideoPropertyCap.struGamma.dwDef);
        }
        if (struVideoPropertyCap.struColorEnable.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struColorEnable.dwDef, SET_COMMAND_INDEX_LIST[6]) == 0)
        {
            SetSliderPos(6, struVideoPropertyCap.struColorEnable.dwDef);
        }
        if (struVideoPropertyCap.struWhiteBalance.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struWhiteBalance.dwDef, SET_COMMAND_INDEX_LIST[7]) == 0)
        {
            SetSliderPos(7, struVideoPropertyCap.struWhiteBalance.dwDef);
        }
        if (struVideoPropertyCap.struBacklightCompensation.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struBacklightCompensation.dwDef, SET_COMMAND_INDEX_LIST[8]) == 0)
        {
            SetSliderPos(8, struVideoPropertyCap.struBacklightCompensation.dwDef);
        }
        if (struVideoPropertyCap.struGain.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struGain.dwDef, SET_COMMAND_INDEX_LIST[9]) == 0)
        {
            SetSliderPos(9, struVideoPropertyCap.struGain.dwDef);
        }
        if (struVideoPropertyCap.struPowerlineFrequency.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struPowerlineFrequency.dwDef, SET_COMMAND_INDEX_LIST[10]) == 0)
        {
            SetSliderPos(10, struVideoPropertyCap.struPowerlineFrequency.dwDef);
        }
        if (struVideoPropertyCap.struPan.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struPan.dwDef, SET_COMMAND_INDEX_LIST[11]) == 0)
        {
            SetSliderPos(11, struVideoPropertyCap.struPan.dwDef);
        }
        if (struVideoPropertyCap.struTilt.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struTilt.dwDef, SET_COMMAND_INDEX_LIST[12]) == 0)
        {
            SetSliderPos(12, struVideoPropertyCap.struTilt.dwDef);
        }
        if (struVideoPropertyCap.struRoll.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struRoll.dwDef, SET_COMMAND_INDEX_LIST[13]) == 0)
        {
            SetSliderPos(13, struVideoPropertyCap.struRoll.dwDef);
        }
        if (struVideoPropertyCap.struZoom.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struZoom.dwDef, SET_COMMAND_INDEX_LIST[14]) == 0)
        {
            SetSliderPos(14, struVideoPropertyCap.struZoom.dwDef);
        }
        if (struVideoPropertyCap.struExposure.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struExposure.dwDef, SET_COMMAND_INDEX_LIST[15]) == 0)
        {
            SetSliderPos(15, struVideoPropertyCap.struExposure.dwDef);
        }
        if (struVideoPropertyCap.struIris.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struIris.dwDef, SET_COMMAND_INDEX_LIST[16]) == 0)
        {
            SetSliderPos(16, struVideoPropertyCap.struIris.dwDef);
        }
        if (struVideoPropertyCap.struFocus.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struFocus.dwDef, SET_COMMAND_INDEX_LIST[17]) == 0)
        {
            SetSliderPos(17, struVideoPropertyCap.struFocus.dwDef);
        }
        if (struVideoPropertyCap.struLowBrightnessCompensation.byEnabled > 0 &&
            SetProperty(struVideoPropertyCap.struLowBrightnessCompensation.dwDef, SET_COMMAND_INDEX_LIST[18]) == 0)
        {
            SetSliderPos(18, struVideoPropertyCap.struLowBrightnessCompensation.dwDef);
        }
    }
}


void CSubDlgCameraControl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    CDialog::OnHScroll(nSBCode, nPos, pScrollBar);

    char szUrl[16] = { 0 };
    int nSliderId = pScrollBar->GetDlgCtrlID();

    int n = ((CSliderCtrl*)GetDlgItem(nSliderId))->GetPos();
    sprintf_s(szUrl, sizeof(szUrl), "%d", n);
    m_cEdit[nSliderId - IDC_SLIDER_BEGIN].SetWindowTextA(szUrl);

    SetProperty(n, SET_COMMAND_INDEX_LIST[nSliderId - IDC_SLIDER_BEGIN]);
}

void CSubDlgCameraControl::SetSliderState(UINT index, int min, int max, UINT nCheckEnable)
{
    if (nCheckEnable <= 0)
    {
        return;
    }
    m_cStatic[index].EnableWindow(TRUE);
    m_cSlider[index].EnableWindow(TRUE);
    if (min < 0)
    {
        m_cSlider[index].SetRange(min, max, TRUE);
    }
    else
    {
        m_cSlider[index].SetRange(min, max);
    }
    long lValue = 0;
    if (GetProperty(&lValue, GET_COMMAND_INDEX_LIST[index]) == 0)
    {
        SetSliderPos(index, lValue);
    }
    if (nCheckEnable == 3)
    {
        m_cButton[index].EnableWindow(TRUE);
    }
}

void CSubDlgCameraControl::SetSliderPos(UINT index, int pos)
{
    m_cSlider[index].SetPos(pos);
    m_cEdit[index].SetWindowTextA(to_string(pos).c_str());
}


void CSubDlgCameraControl::OnBnClickedBtStartPreview()
{
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };
    USB_VIDEO_PARAM struVideoParam = { 0 };
    struConfigOutputInfo.lpOutBuffer = &struVideoParam;
    struConfigOutputInfo.dwOutBufferSize = sizeof(struVideoParam);
    //获取设备视频参数
    if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_GET_VIDEO_PARAM failed, USB_GetLastError[%d]", USB_GetLastError());
    }

    //更新需要设置的参数
    struVideoParam.dwVideoFormat = USB_STREAM_MJPEG;
    struVideoParam.dwFramerate = 30;
    struVideoParam.dwWidth = 320;
    struVideoParam.dwHeight = 240;

    memset(&struConfigInputInfo, 0, sizeof(struConfigInputInfo));
    memset(&struConfigOutputInfo, 0, sizeof(struConfigOutputInfo));

    struConfigInputInfo.lpInBuffer = &struVideoParam;
    struConfigInputInfo.dwInBufferSize = sizeof(struVideoParam);

    //设置设备视频参数
    if (!USB_SetDeviceConfig(m_lUserID, USB_SET_VIDEO_PARAM, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SET_VIDEO_PARAM failed, USB_GetLastError[%d]", USB_GetLastError());
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
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SET_SRC_STREAM_TYPE failed, USB_GetLastError[%d]", USB_GetLastError());
        return;
    }

    RECT rc;
    m_PreviewWindow.GetWindowRect(&rc);
    ScreenToClient(&rc);
    m_PreviewWindow.MoveWindow(rc.left, rc.top, 320, 240);

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
        GetDlgItem(IDC_BT_START_PREVIEW)->EnableWindow(FALSE);
        GetDlgItem(IDC_BT_STOP_PREVIEW)->EnableWindow(TRUE);
    }
}


void CSubDlgCameraControl::OnBnClickedBtStopPreview()
{
    if (!USB_StopChannel(m_lUserID, m_lCurChannel))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_StopChannel()");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    else
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_StopChannel()");
    }

    GetDlgItem(IDC_BT_START_PREVIEW)->EnableWindow(TRUE);
    GetDlgItem(IDC_BT_STOP_PREVIEW)->EnableWindow(FALSE);
}

int CSubDlgCameraControl::GetProperty(long *pValue, UINT nCommand)
{
    USB_VIDEO_PROPERTY struPropertyValue = { 0 };
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };

    struConfigOutputInfo.lpOutBuffer = &struPropertyValue;
    struConfigOutputInfo.dwOutBufferSize = sizeof(struPropertyValue);

    //设置设备视频属性
    if (!USB_GetDeviceConfig(m_lUserID, nCommand, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_PROPERTY[%d]", nCommand);
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return -1;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GET_PROPERTY[%d]", nCommand);
    *pValue = struPropertyValue.dwValue;

    return 0;
}

int CSubDlgCameraControl::SetProperty(int nValue, UINT nCommand, UINT nFlag)
{
    USB_VIDEO_PROPERTY struPropertyValue = { 0 };
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };

    struPropertyValue.dwValue = nValue;
    struPropertyValue.byFlag = nFlag;
    struConfigInputInfo.lpInBuffer = &struPropertyValue;
    struConfigInputInfo.dwInBufferSize = sizeof(struPropertyValue);

    //设置设备视频属性
    if (!USB_SetDeviceConfig(m_lUserID, nCommand, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SET_PROPERTY[%d]", nCommand);
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return -1;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SET_PROPERTY[%d]", nCommand);
    return 0;
}

int CSubDlgCameraControl::GetPropertyCap(USB_VIDEO_PROPERTY_CAP *pVideoPropertyCap)
{
    USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = { 0 };

    struConfigOutputInfo.lpOutBuffer = pVideoPropertyCap;
    struConfigOutputInfo.dwOutBufferSize = sizeof(*pVideoPropertyCap);

    //获取设备视频属性能力
    if (!USB_GetDeviceConfig(m_lUserID, USB_GET_VIDEO_PROPERTY_CAP, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GET_VIDEO_PROPERTY_CAP");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return -1;
    }

    return 0;
}

void CSubDlgCameraControl::OnBnCheckClicked(UINT nID)
{
    BOOL bChecked = ((CButton*)GetDlgItem(nID))->GetCheck();
    if (bChecked)
    {
        SetProperty(0, SET_COMMAND_INDEX_LIST[nID - IDC_BT_CHECK_BEGIN], 1);//自动
    }
    else
    {
        long lValue = 0;
        if (0 == GetProperty(&lValue, GET_COMMAND_INDEX_LIST[nID - IDC_BT_CHECK_BEGIN]))
        {
            SetProperty(lValue, SET_COMMAND_INDEX_LIST[nID - IDC_BT_CHECK_BEGIN], 2);//手动
        }
    }
}

void CSubDlgCameraControl::OnPaint()
{
    CPaintDC dc(this);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_BUTTON_GET_VIDEO_CAP);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_BUTTON_SET_DEFAULT_CAP);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_STATIC2);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_BT_START_PREVIEW);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_BT_STOP_PREVIEW);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_STATIC19);
    SET_CONTROL_LAN(IDD_SUBDLG_CAMERA_CONTROL, IDC_STATIC20);
}
