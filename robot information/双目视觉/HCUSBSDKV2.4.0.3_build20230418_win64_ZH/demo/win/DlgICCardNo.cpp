// DlgICCardNo.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgICCardNo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgICCardNo dialog


CDlgICCardNo::CDlgICCardNo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgICCardNo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgICCardNo)
	m_csICCardNo = _T("");
	//}}AFX_DATA_INIT
}


void CDlgICCardNo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgICCardNo)
	DDX_Text(pDX, IDC_EDIT_IC_CARD_NO, m_csICCardNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgICCardNo, CDialog)
	//{{AFX_MSG_MAP(CDlgICCardNo)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgICCardNo message handlers

void CDlgICCardNo::OnBtnGet() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    USB_IC_CARD_NO struICCardNo = {0};
    struICCardNo.dwSize = sizeof(struICCardNo);
    
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    struConfigOutputInfo.dwOutBufferSize = sizeof(struICCardNo);
    struConfigOutputInfo.lpOutBuffer = &struICCardNo;
    
    if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IC_CARD_NO, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_IC_CARD_NO");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;        
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_IC_CARD_NO");
    
    m_csICCardNo = struICCardNo.byCardNo;
    
    UpdateData(FALSE);
}


void CDlgICCardNo::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_IC_CARD_NO);
    SET_CONTROL_LAN(IDD_DLG_IC_CARD_NO, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_IC_CARD_NO, IDC_BTN_GET);
}
