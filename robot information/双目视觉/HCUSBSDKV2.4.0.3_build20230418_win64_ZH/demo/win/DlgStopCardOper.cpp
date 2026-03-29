// DlgStopCardOper.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgStopCardOper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgStopCardOper dialog


CDlgStopCardOper::CDlgStopCardOper(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgStopCardOper::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgStopCardOper)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void CDlgStopCardOper::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgStopCardOper)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgStopCardOper, CDialog)
    //{{AFX_MSG_MAP(CDlgStopCardOper)
    ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgStopCardOper message handlers

void CDlgStopCardOper::OnBtnStop() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    CString csInfo;
    if (USB_Control(m_lUserID, USB_CTRL_STOP_CARD_OPER, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_Control()  Command = USB_CTRL_STOP_CARD_OPER");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_Control()  Command = USB_CTRL_STOP_CARD_OPER");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgStopCardOper::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_STOP_CARD_OPER);
	SET_CONTROL_LAN(IDD_DLG_STOP_CARD_OPER, IDC_BTN_STOP);
}
