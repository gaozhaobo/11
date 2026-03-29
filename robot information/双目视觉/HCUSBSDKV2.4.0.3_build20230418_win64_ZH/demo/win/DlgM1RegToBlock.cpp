// DlgM1RegToBlock.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1RegToBlock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgM1RegToBlock dialog


CDlgM1RegToBlock::CDlgM1RegToBlock(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1RegToBlock::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1RegToBlock)
        // NOTE: the ClassWizard will add member initialization here
    m_dwBlockAddr = 0;
    //}}AFX_DATA_INIT
}


void CDlgM1RegToBlock::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1RegToBlock)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_BLOCK_ADDR, m_dwBlockAddr);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1RegToBlock, CDialog)
    //{{AFX_MSG_MAP(CDlgM1RegToBlock)
    ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1RegToBlock message handlers

BOOL CDlgM1RegToBlock::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgM1RegToBlock::OnBtnOk() 
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
    struBlockAddr.wAddr = static_cast<WORD>(m_dwBlockAddr);
    
    USB_CONTROL_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struBlockAddr);
    struInput.lpInBuffer = &struBlockAddr;
    
    CString csInfo;
    if (USB_Control(m_lUserID, USB_CTRL_M1_REG_TO_BLOCK, &struInput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_Control()  Command = USB_CTRL_M1_REG_TO_BLOCK");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_Control()  Command = USB_CTRL_M1_REG_TO_BLOCK");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgM1RegToBlock::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_REG_TO_BLOCK);
	SET_CONTROL_LAN(IDD_DLG_M1_REG_TO_BLOCK, IDC_STATIC_ADDRESS);
	SET_CONTROL_LAN(IDD_DLG_M1_REG_TO_BLOCK, IDC_BTN_OK);
}