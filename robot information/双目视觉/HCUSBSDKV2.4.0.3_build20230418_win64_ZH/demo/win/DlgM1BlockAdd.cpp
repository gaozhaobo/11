// DlgM1BlockAdd.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1BlockAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockAdd dialog


CDlgM1BlockAdd::CDlgM1BlockAdd(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1BlockAdd::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1BlockAdd)
        // NOTE: the ClassWizard will add member initialization here
    m_dwBlockAddr = 0;
    m_dwValue = 0;
    //}}AFX_DATA_INIT
}


void CDlgM1BlockAdd::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1BlockAdd)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_BLOCK_ADDR, m_dwBlockAddr);
    DDX_Text(pDX, IDC_EDT_VALUE, m_dwValue);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1BlockAdd, CDialog)
    //{{AFX_MSG_MAP(CDlgM1BlockAdd)
    ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)

    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockAdd message handlers

BOOL CDlgM1BlockAdd::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgM1BlockAdd::OnBtnOk() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

	if (m_dwValue < 0 || m_dwValue > 65535)
	{
		if (g_bEnglish)
		{
			MessageBox("block value range:0(include)-65535(include)");
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
			MessageBox("block address range:0(include)-65535(include)");
		}
		else
		{
			MessageBox("块地址范围为0(含)-65535(含)");
		}
        return;
    }
    
    USB_M1_BLOCK_OPER struAddValue = {0};
    struAddValue.dwSize = sizeof(struAddValue);
    struAddValue.wValue = static_cast<WORD>(m_dwValue);
    struAddValue.wAddr  = static_cast<WORD>(m_dwBlockAddr);
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struAddValue);
    struInput.lpInBuffer = &struAddValue;

    USB_M1_BLOCK_OPER_RES struAddRes = {0};
    struAddRes.dwSize = sizeof(struAddRes);

    USB_CONFIG_OUTPUT_INFO struOutput = {0};
    struOutput.dwOutBufferSize = sizeof(struAddRes);
    struOutput.lpOutBuffer = &struAddRes;

    CString csInfo;
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_M1_BLOCK_ADD_VALUE, &struInput, &struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_M1_BLOCK_ADD_VALUE");
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "Success Number = [%d]", struAddRes.wSuccessNum);
		}
		else
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "成功次数 = [%d]", struAddRes.wSuccessNum);
		}
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_M1_BLOCK_ADD_VALUE");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgM1BlockAdd::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_BLOCK_ADD);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_ADD, IDC_STATIC_ADDRESS);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_ADD, IDC_STATIC_DATA);
	SET_CONTROL_LAN(IDD_DLG_M1_BLOCK_ADD, IDC_BTN_OK);
}