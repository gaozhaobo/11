// DlgCardProtoCfg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgCardProtoCfg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCardProtoCfg dialog


CDlgCardProtoCfg::CDlgCardProtoCfg(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgCardProtoCfg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgCardProtoCfg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void CDlgCardProtoCfg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgCardProtoCfg)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_COM_CARD_PROTO, m_comCardProto);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCardProtoCfg, CDialog)
    //{{AFX_MSG_MAP(CDlgCardProtoCfg)
    ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCardProtoCfg message handlers


BOOL CDlgCardProtoCfg::OnInitDialog()
{
    CDialog::OnInitDialog();
    
	if (g_bEnglish)
	{
		m_comCardProto.InsertString(0, _T("0-TypeA"));
		m_comCardProto.InsertString(1, _T("1-TypeB"));
		m_comCardProto.InsertString(2, _T("2-TypeAB"));
		m_comCardProto.InsertString(3, _T("3-125kHz"));
		m_comCardProto.InsertString(4, _T("255-All"));
	}
	else
	{
		m_comCardProto.InsertString(0, _T("0-TypeA"));
		m_comCardProto.InsertString(1, _T("1-TypeB"));
		m_comCardProto.InsertString(2, _T("2-TypeAB"));
		m_comCardProto.InsertString(3, _T("3-125kHz"));
		m_comCardProto.InsertString(4, _T("255-Ыљга"));
	}
    m_comCardProto.SetCurSel(0);
    
    UpdateData(FALSE);
    
    return TRUE;
}

void CDlgCardProtoCfg::OnBtnSet() 
{
    // TODO: Add your control notification handler code here

    UpdateData(TRUE);

    BYTE byProto = m_comCardProto.GetCurSel();
    if (byProto == 4)
    {
        byProto = 255;
    }

    USB_CARD_PROTO struCardProto = {0};
    struCardProto.dwSize = sizeof(struCardProto);
    struCardProto.byProto = byProto;
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struCardProto);
    struInput.lpInBuffer = &struCardProto;

    if (USB_SetDeviceConfig(m_lUserID, USB_SET_CARD_PROTO, &struInput, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_CARD_PROTO");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_CARD_PROTO");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }	
}

void CDlgCardProtoCfg::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_SET_CARD_PROTO);
	SET_CONTROL_LAN(IDD_DLG_SET_CARD_PROTO, IDC_STATIC_TYPE);
	SET_CONTROL_LAN(IDD_DLG_SET_CARD_PROTO, IDC_BTN_SET);
}