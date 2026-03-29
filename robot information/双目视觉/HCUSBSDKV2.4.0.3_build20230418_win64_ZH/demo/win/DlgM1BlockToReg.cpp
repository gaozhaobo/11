// DlgM1BlockToReg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1BlockToReg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockToReg dialog


CDlgM1BlockToReg::CDlgM1BlockToReg(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1BlockToReg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1BlockToReg)
        // NOTE: the ClassWizard will add member initialization here
        m_dwBlockAddr = 0;
    //}}AFX_DATA_INIT
}


void CDlgM1BlockToReg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1BlockToReg)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_BLOCK_ADDR, m_dwBlockAddr);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1BlockToReg, CDialog)
    //{{AFX_MSG_MAP(CDlgM1BlockToReg)
    ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockToReg message handlers


BOOL CDlgM1BlockToReg::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgM1BlockToReg::OnBtnOk() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    if (m_dwBlockAddr < 0 || m_dwBlockAddr > 65535)
    {
		if (g_bEnglish)
		{
			MessageBox("Block address range:0(include)-65535(include)");
		}
		else
		{
			MessageBox("¿éµØÖ··¶Î§Îª0(º¬)-65535(º¬)");
		}
        return;
    }
    
    USB_M1_BLOCK_ADDR struBlockAddr = {0};
    struBlockAddr.dwSize = sizeof(struBlockAddr);
    struBlockAddr.wAddr  = static_cast<WORD>(m_dwBlockAddr);
    
    USB_CONTROL_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struBlockAddr);
    struInput.lpInBuffer = &struBlockAddr;
    
    CString csInfo;
    if (USB_Control(m_lUserID, USB_CTRL_M1_BLOCK_TO_REG, &struInput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_CTRL_M1_BLOCK_TO_REG");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_CTRL_M1_BLOCK_TO_REG");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgM1BlockToReg::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_BLOCK_TO_REG);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_TO_REG, IDC_STATIC_ADDRESS);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_TO_REG, IDC_BTN_OK);
}