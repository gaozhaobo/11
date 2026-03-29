// DlgBeepAndFlickerCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgBeepAndFlickerCtrl.h"
#include "Language.h"

#include "GlobalCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBeepAndFlickerCtrl dialog


CDlgBeepAndFlickerCtrl::CDlgBeepAndFlickerCtrl(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgBeepAndFlickerCtrl::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgBeepAndFlickerCtrl)
        // NOTE: the ClassWizard will add member initialization here
    m_dwBeepCount = 0;
    m_dwFlickerCount = 0;
    //}}AFX_DATA_INIT
}


void CDlgBeepAndFlickerCtrl::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgBeepAndFlickerCtrl)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_COM_BEEP_TYPE, m_comBeepType);
    DDX_Control(pDX, IDC_COM_FLICKER_TYPE, m_comFlickerType);
    DDX_Text(pDX, IDC_EDT_BEEP_COUNT, m_dwBeepCount);
    DDX_Text(pDX, IDC_EDT_FLICKER_COUNT, m_dwFlickerCount);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgBeepAndFlickerCtrl, CDialog)
    //{{AFX_MSG_MAP(CDlgBeepAndFlickerCtrl)
    ON_BN_CLICKED(IDC_BTN_CFG, OnBtnCfg)
	ON_CBN_SELCHANGE(IDC_COM_BEEP_TYPE, OnSelchangeComBeepType)
	ON_CBN_SELCHANGE(IDC_COM_FLICKER_TYPE, OnSelchangeComFlickerType)
	//}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBeepAndFlickerCtrl message handlers

BOOL CDlgBeepAndFlickerCtrl::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (g_bEnglish)
	{
		m_comBeepType.InsertString(0, _T("0-invalid"));
		m_comBeepType.InsertString(1, _T("1-continuous"));
		m_comBeepType.InsertString(2, _T("2-slow beep"));
		m_comBeepType.InsertString(3, _T("3-fast beep"));
		m_comBeepType.InsertString(4, _T("4-stop"));
	}
	else
	{
		m_comBeepType.InsertString(0, _T("0-无效"));
		m_comBeepType.InsertString(1, _T("1-连续"));
		m_comBeepType.InsertString(2, _T("2-慢鸣"));
		m_comBeepType.InsertString(3, _T("3-快鸣"));
		m_comBeepType.InsertString(4, _T("4-停止"));
	}

    m_comBeepType.SetCurSel(0);
    (CEdit*)GetDlgItem(IDC_EDT_BEEP_COUNT)->EnableWindow(FALSE);

	if (g_bEnglish)
	{
		m_comFlickerType.InsertString(0, _T("0-invalid"));
		m_comFlickerType.InsertString(1, _T("1-continuous"));
		m_comFlickerType.InsertString(2, _T("2-wrong"));
		m_comFlickerType.InsertString(3, _T("3-right"));
		m_comFlickerType.InsertString(4, _T("4-stop"));
	}
	else
	{
		m_comFlickerType.InsertString(0, _T("0-无效"));
		m_comFlickerType.InsertString(1, _T("1-连续"));
		m_comFlickerType.InsertString(2, _T("2-错误"));
		m_comFlickerType.InsertString(3, _T("3-正确"));
		m_comFlickerType.InsertString(4, _T("4-停止"));
	}

    m_comFlickerType.SetCurSel(0);
    (CEdit*)GetDlgItem(IDC_EDT_FLICKER_COUNT)->EnableWindow(FALSE);

    UpdateData(FALSE);

    return TRUE;
}

void CDlgBeepAndFlickerCtrl::OnBtnCfg() 
{
    // TODO: Add your control notification handler code here

    UpdateData(TRUE);

    USB_BEEP_AND_FLICKER struBeepAndFlicker = {0};
    struBeepAndFlicker.dwSize = sizeof(USB_BEEP_AND_FLICKER);
    struBeepAndFlicker.byBeepType = m_comBeepType.GetCurSel();
    struBeepAndFlicker.byBeepCount = static_cast<BYTE>(m_dwBeepCount);
    struBeepAndFlicker.byFlickerType = m_comFlickerType.GetCurSel();
    struBeepAndFlicker.byFlickerCount = static_cast<BYTE>(m_dwFlickerCount);

    if (struBeepAndFlicker.byBeepType == 2 || struBeepAndFlicker.byBeepType == 3)
    {
        if (m_dwBeepCount <= 0 || m_dwBeepCount > 255)
        {
			if (g_bEnglish)
			{
				MessageBox("slow beep and fast beep's times must between 0(not include) and 255(include)");
			}
			else
			{
				MessageBox("慢鸣和快鸣的鸣叫次数必须在0(不含)-255(含)之间");
			}
            return;
        }
    }

    if (struBeepAndFlicker.byFlickerType == 2 || struBeepAndFlicker.byFlickerType == 3)
    {
        if (m_dwFlickerCount <= 0 || m_dwFlickerCount > 255)
        {
			if (g_bEnglish)
			{
				MessageBox("wrong and right's times must between 0(not include) and 255(include)");
			}
			else
			{
				MessageBox("错误和正确的鸣叫次数必须在0(不含)-255(含)之间");
			}
            return;
        }
    }

    USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};

    struConfigInputInfo.dwCondBufferSize = 0;
    struConfigInputInfo.lpCondBuffer = NULL;
    struConfigInputInfo.dwInBufferSize = sizeof(struBeepAndFlicker);
    struConfigInputInfo.lpInBuffer = &struBeepAndFlicker;

    if (USB_SetDeviceConfig(m_lUserID, USB_SET_BEEP_AND_FLICKER, &struConfigInputInfo, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_BEEP_AND_FLICKER");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_BEEP_AND_FLICKER");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgBeepAndFlickerCtrl::OnSelchangeComBeepType() 
{
	// TODO: Add your control notification handler code here
    switch (m_comBeepType.GetCurSel())
    {
    case 0:
    case 1:
         (CEdit*)GetDlgItem(IDC_EDT_BEEP_COUNT)->EnableWindow(FALSE);
        break;
    case 2:
    case 3:
        (CEdit*)GetDlgItem(IDC_EDT_BEEP_COUNT)->EnableWindow(TRUE);
        break;
    case 4:
        (CEdit*)GetDlgItem(IDC_EDT_BEEP_COUNT)->EnableWindow(FALSE);
        break;
    default:
        (CEdit*)GetDlgItem(IDC_EDT_BEEP_COUNT)->EnableWindow(FALSE);
        break;
    }	
}

void CDlgBeepAndFlickerCtrl::OnSelchangeComFlickerType() 
{
	// TODO: Add your control notification handler code here
    switch (m_comFlickerType.GetCurSel())
    {
    case 0:
    case 1:
        (CEdit*)GetDlgItem(IDC_EDT_FLICKER_COUNT)->EnableWindow(FALSE);
        break;
    case 2:
    case 3:
        (CEdit*)GetDlgItem(IDC_EDT_FLICKER_COUNT)->EnableWindow(TRUE);
        break;
    case 4:
        (CEdit*)GetDlgItem(IDC_EDT_FLICKER_COUNT)->EnableWindow(FALSE);
        break;
    default:
        (CEdit*)GetDlgItem(IDC_EDT_FLICKER_COUNT)->EnableWindow(FALSE);
        break;
    }
}

void CDlgBeepAndFlickerCtrl::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_BEEP_AND_FLICKER);
	SET_CONTROL_LAN(IDD_DLG_BEEP_AND_FLICKER, IDC_STATIC_BEEP_TYPE);
	SET_CONTROL_LAN(IDD_DLG_BEEP_AND_FLICKER, IDC_STATIC_FILCKER_TYPE);
	SET_CONTROL_LAN(IDD_DLG_BEEP_AND_FLICKER, IDC_STATIC_BEEP_COUNT);
	SET_CONTROL_LAN(IDD_DLG_BEEP_AND_FLICKER, IDC_STATIC_FLICKER_COUNT);
	SET_CONTROL_LAN(IDD_DLG_BEEP_AND_FLICKER, IDC_BTN_CFG);
}
