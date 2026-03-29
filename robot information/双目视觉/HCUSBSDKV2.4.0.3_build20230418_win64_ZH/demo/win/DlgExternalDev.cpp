// DlgExternalDev.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgExternalDev.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgExternalDev dialog


CDlgExternalDev::CDlgExternalDev(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExternalDev::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgExternalDev)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    m_csFPModuleSerialNumber=_T("");
    m_csFPModuleSoftVersion=_T("");
    m_csSecurityModuleSerialNumber=_T("");
    m_lUserID=-1;
}


void CDlgExternalDev::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgExternalDev)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
    DDX_Text(pDX,IDC_EDIT_MODULE_VERSION,m_csFPModuleSoftVersion);
    DDX_Text(pDX,IDC_EDIT_MODULE_SERIAL,m_csFPModuleSerialNumber);
    DDX_Text(pDX,IDC_EDIT_SECURITY_SERIAL,m_csSecurityModuleSerialNumber);
}


BEGIN_MESSAGE_MAP(CDlgExternalDev, CDialog)
	//{{AFX_MSG_MAP(CDlgExternalDev)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgExternalDev message handlers

void CDlgExternalDev::OnBtnGet() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    USB_EXTERNAL_DEV_INFO struExternalDev = {0};
    struExternalDev.dwSize = sizeof(struExternalDev);
    
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    
    struConfigOutputInfo.dwOutBufferSize = sizeof(struExternalDev);
    struConfigOutputInfo.lpOutBuffer = &struExternalDev;
    
    if (USB_GetDeviceConfig(m_lUserID, USB_GET_EXTERNAL_DEV_INFO, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command =USB_GET_EXTERNAL_DEV_INFO");
        
        m_csFPModuleSoftVersion = struExternalDev.szFPModuleSoftVersion;
        m_csFPModuleSerialNumber = struExternalDev.szFPModuleSerialNumber;
        m_csSecurityModuleSerialNumber = struExternalDev.szSecurityModuleSerialNumber;
        
        UpdateData(FALSE);
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_EXTERNAL_DEV_INFO");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    
    return;	
}


void CDlgExternalDev::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_EXTERNAL_DEV);
    SET_CONTROL_LAN(IDD_DLG_EXTERNAL_DEV, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_EXTERNAL_DEV, IDC_STATIC2);
    SET_CONTROL_LAN(IDD_DLG_EXTERNAL_DEV, IDC_STATIC3);
    SET_CONTROL_LAN(IDD_DLG_EXTERNAL_DEV, IDC_BTN_GET);
}
