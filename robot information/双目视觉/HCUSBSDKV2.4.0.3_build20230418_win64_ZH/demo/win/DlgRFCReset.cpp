// DlgRFCReset.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgRFCReset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRFCReset dialog


CDlgRFCReset::CDlgRFCReset(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgRFCReset::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgRFCReset)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void CDlgRFCReset::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgRFCReset)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRFCReset, CDialog)
    //{{AFX_MSG_MAP(CDlgRFCReset)
    ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRFCReset message handlers

BOOL CDlgRFCReset::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;
}

void CDlgRFCReset::OnBtnSet() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    if (USB_Control(m_lUserID, USB_CTRL_RESET_RFC, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_Control()  Command = USB_CTRL_RESET_RFC");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_Control()  Command = USB_CTRL_RESET_RFC");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgRFCReset::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_RFC_RESET);
	SET_CONTROL_LAN(IDD_DLG_RFC_RESET, IDC_BTN_SET);
}
