// DlgCertificateAddAddrInfo.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgCertificateAddAddrInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateAddAddrInfo dialog


CDlgCertificateAddAddrInfo::CDlgCertificateAddAddrInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCertificateAddAddrInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCertificateAddAddrInfo)
	m_csAddAddrInfo = _T("");
	//}}AFX_DATA_INIT
}


void CDlgCertificateAddAddrInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCertificateAddAddrInfo)
	DDX_Text(pDX, IDC_EDIT_ADD_ADDR_INFO, m_csAddAddrInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCertificateAddAddrInfo, CDialog)
	//{{AFX_MSG_MAP(CDlgCertificateAddAddrInfo)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateAddAddrInfo message handlers

void CDlgCertificateAddAddrInfo::OnBtnGet() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    
    USB_CERTIFICATE_ADD_ADDR_INFO struCertificateAddAddrInfo = {0};
    struCertificateAddAddrInfo.dwSize = sizeof(struCertificateAddAddrInfo);
    
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    struConfigOutputInfo.dwOutBufferSize = sizeof(struCertificateAddAddrInfo);
    struConfigOutputInfo.lpOutBuffer = &struCertificateAddAddrInfo;
    
    if (!USB_GetDeviceConfig(m_lUserID, USB_GET_CERTIFICATE_ADD_ADDR_INFO, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_ADD_ADDR_INFO");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;        
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_ADD_ADDR_INFO");

    m_csAddAddrInfo = struCertificateAddAddrInfo.byAddAddrInfo;

    UpdateData(FALSE);
}


void CDlgCertificateAddAddrInfo::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_CERTIFICATE_ADD_ADDR_INFO);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_ADD_ADDR_INFO, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_ADD_ADDR_INFO, IDC_BTN_GET);
}
