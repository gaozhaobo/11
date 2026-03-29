// DlgM1BlockMinus.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1BlockMinus.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockMinus dialog


CDlgM1BlockMinus::CDlgM1BlockMinus(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1BlockMinus::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1BlockMinus)
        // NOTE: the ClassWizard will add member initialization here
    m_dwBlockAddr = 0;
    m_dwValue = 0;
    //}}AFX_DATA_INIT
}


void CDlgM1BlockMinus::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1BlockMinus)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_BLOCK_ADDR, m_dwBlockAddr);
    DDX_Text(pDX, IDC_EDT_VALUE, m_dwValue);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1BlockMinus, CDialog)
    //{{AFX_MSG_MAP(CDlgM1BlockMinus)
    ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockMinus message handlers


BOOL CDlgM1BlockMinus::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgM1BlockMinus::OnBtnOk() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    if (m_dwValue < 0 || m_dwValue > 65535)
    {
		if (g_bEnglish)
		{
			MessageBox("Block value range:0(include)-65535(include)");
		}
		else
		{
			MessageBox("块值的范围为0(含)-65535(含)");
		}
        return;
    }
    
	if (m_dwBlockAddr < 0 || m_dwBlockAddr > 65535)
	{
		if (g_bEnglish)
		{
			MessageBox("Block address range:0(include)-65535(include)");
		}
		else
		{
			MessageBox("块地址范围为0(含)-65535(含)");
		}
        return;
    }
    
    USB_M1_BLOCK_OPER struMinusValue = {0};
    struMinusValue.dwSize = sizeof(struMinusValue);
    struMinusValue.wValue = static_cast<WORD>(m_dwValue);
    struMinusValue.wAddr = static_cast<WORD>(m_dwBlockAddr);
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struMinusValue);
    struInput.lpInBuffer = &struMinusValue;
    
    USB_M1_BLOCK_OPER_RES struMinusRes = {0};
    struMinusRes.dwSize = sizeof(struMinusRes);

    USB_CONFIG_OUTPUT_INFO struOutput = {0};
    struOutput.dwOutBufferSize = sizeof(struMinusRes);
    struOutput.lpOutBuffer = &struMinusRes;
    
    CString csInfo;
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_M1_BLOCK_MINUS_VALUE, &struInput, &struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_M1_BLOCK_MINUS_VALUE");
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "Success number = [%d]", struMinusRes.wSuccessNum);
		}
		else
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "成功次数 = [%d]", struMinusRes.wSuccessNum);
		}
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_M1_BLOCK_MINUS_VALUE");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgM1BlockMinus::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_BLOCK_MINUS);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_MINUS, IDC_STATIC_ADDRESS);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_MINUS, IDC_STATIC_DATA);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_MINUS, IDC_BTN_OK);
}