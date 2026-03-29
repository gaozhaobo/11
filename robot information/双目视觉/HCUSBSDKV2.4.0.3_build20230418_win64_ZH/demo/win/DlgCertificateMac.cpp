// DlgCertificateMac.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgCertificateMac.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateMac dialog


CDlgCertificateMac::CDlgCertificateMac(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCertificateMac::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCertificateMac)
	m_csCertificateMac = _T("");
	//}}AFX_DATA_INIT
}


void CDlgCertificateMac::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCertificateMac)
	DDX_Text(pDX, IDC_EDIT_CERTIFICATE_MAC, m_csCertificateMac);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCertificateMac, CDialog)
	//{{AFX_MSG_MAP(CDlgCertificateMac)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateMac message handlers

void CDlgCertificateMac::OnBtnGet() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
    USB_CERTIFICATE_MAC struCertificateMac = {0};
    struCertificateMac.dwSize = sizeof(struCertificateMac);
    
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    struConfigOutputInfo.dwOutBufferSize = sizeof(struCertificateMac);
    struConfigOutputInfo.lpOutBuffer = &struCertificateMac;
    
    if (!USB_GetDeviceConfig(m_lUserID, USB_GET_CERTIFICATE_MAC, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_MAC");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;        
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_MAC");

    m_csCertificateMac = struCertificateMac.byMac;

    UpdateData(FALSE);
}


void CDlgCertificateMac::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_CERTIFICATE_MAC);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_MAC, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_MAC, IDC_BTN_GET);
}
