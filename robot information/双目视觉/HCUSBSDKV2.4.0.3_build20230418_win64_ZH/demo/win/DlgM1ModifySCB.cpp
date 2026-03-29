// DlgM1ModifySCB.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1ModifySCB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CSTRING_TO_CHARS(str,sz) memcpy((sz),str.GetBuffer(str.GetLength()),str.GetLength())

/////////////////////////////////////////////////////////////////////////////
// CDlgM1ModifySCB dialog


CDlgM1ModifySCB::CDlgM1ModifySCB(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1ModifySCB::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1ModifySCB)
        // NOTE: the ClassWizard will add member initialization here
    
    m_dwSectionNum = 0;

    m_csPwdA = _T("00 00 00 00 00 00");
    m_csPwdB = _T("00 00 00 00 00 00");
    m_csCtrlBytes = _T("00 00 00 00");

    //}}AFX_DATA_INIT
}


void CDlgM1ModifySCB::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1ModifySCB)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_SECTION_NUM, m_dwSectionNum);
    DDX_Text(pDX, IDC_EDT_PWD_A, m_csPwdA);
    DDX_Text(pDX, IDC_EDT_CTRL_BYTES, m_csCtrlBytes);
    DDX_Text(pDX, IDC_EDT_PWD_B, m_csPwdB);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1ModifySCB, CDialog)
    //{{AFX_MSG_MAP(CDlgM1ModifySCB)
    ON_BN_CLICKED(IDC_BTN_MODIFY, OnBtnModify)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1ModifySCB message handlers

BOOL CDlgM1ModifySCB::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgM1ModifySCB::OnBtnModify() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    if (m_dwSectionNum < 0)
    {
		if (g_bEnglish)
		{
			MessageBox("扇区号应>=0");
		}
		else
		{
			MessageBox("Block ID need >=0");
		}
        return;
    }

    if (m_csPwdA.GetLength() < 17)
    {
		if (g_bEnglish)
		{
			MessageBox("密码A应为6个16进制数");
		}
		else
		{
			MessageBox("Password A should be 6 hexadecimal digits.");
		}
        return;
    }

    if (m_csPwdB.GetLength() < 17)
    {
		if (g_bEnglish)
		{
			MessageBox("密码B应为6个16进制数");
		}
		else
		{
			MessageBox("Password B should be 6 hexadecimal digits.");
		}
        return;
    }

    if (m_csCtrlBytes.GetLength() < 11)
    {
		if (g_bEnglish)
		{
			MessageBox("控制位应为4个16进制数");
		}
		else
		{
			MessageBox("Control bits should be 4 hexadecimal digits.");
		}
        return;
    }

    char szPwdA[32] = {0};
    char szPwdB[32] = {0};
    char szCtrlByte[32] = {0};

    CSTRING_TO_CHARS(m_csPwdA, szPwdA);
    CSTRING_TO_CHARS(m_csPwdB, szPwdB);
    CSTRING_TO_CHARS(m_csCtrlBytes, szCtrlByte);
    
    USB_M1_MODIFY_SCB struModifySCB = {0};
    struModifySCB.dwSize = sizeof(struModifySCB);
    struModifySCB.bySectionNum = (BYTE)m_dwSectionNum;

    DWORD dwDataLen = 0;
    if (!ConvertHexBufToByteBuf(szPwdA, strlen(szPwdA)+1, struModifySCB.byPasswordA, &dwDataLen))
    {
		if (g_bEnglish)
		{
			MessageBox("输入的密码A数据有误! 请确认为6个16进制数, 每个数为2位.");
		}
		else
		{
			MessageBox("Wrong password A data.");
		}
        return;
    }
    
    if (dwDataLen != 6)
    {
		if (g_bEnglish)
		{
			MessageBox("密码A应为6Byte!");
		}
		else
		{
			MessageBox("Password A should be 6Byte!");
		}
        return;
    }

    dwDataLen = 0;
    if (!ConvertHexBufToByteBuf(szPwdB, strlen(szPwdB)+1, struModifySCB.byPasswordB, &dwDataLen))
    {
		if (g_bEnglish)
		{
			MessageBox("输入的密码B数据有误! 请确认为6个16进制数, 每个数为2位.");
		}
		else
		{
			MessageBox("Wrong password B data.");
		}
        return;
    }
    
    if (dwDataLen != 6)
    {
		if (g_bEnglish)
		{
			MessageBox("密码B应为6Byte!");
		}
		else
		{
			MessageBox("Password B should be 6Byte!");
		}
        return;
    }

    dwDataLen = 0;
    if (!ConvertHexBufToByteBuf(szCtrlByte, strlen(szCtrlByte)+1, struModifySCB.byCtrlBits, &dwDataLen))
    {
		if (g_bEnglish)
		{
			MessageBox("输入的控制位数据有误! 请确认为4个16进制数, 每个数为2位.");
		}
		else
		{
			MessageBox("Control bit data error!");
		}
        return;
    }
    
    if (dwDataLen != 4)
    {
		if (g_bEnglish)
		{
			MessageBox("控制位应为4Byte!");
		}
		else
		{
			MessageBox("Control bits should be 4Byte!");
		}
        return;
    }

        
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struModifySCB);
    struInput.lpInBuffer = &struModifySCB;
    
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_M1_MODIFY_SCB, &struInput, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_M1_MODIFY_SCB");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SetDeviceConfig()  Command = USB_SET_M1_MODIFY_SCB");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    
}

void CDlgM1ModifySCB::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_MODIFY_SCB);
	SET_CONTROL_LAN(IDD_DLG_M1_MODIFY_SCB, IDC_STATIC_BLOCK_NO);
	SET_CONTROL_LAN(IDD_DLG_M1_MODIFY_SCB, IDC_STATIC_PWDA);
	SET_CONTROL_LAN(IDD_DLG_M1_MODIFY_SCB, IDC_STATIC_CONTROL);
	SET_CONTROL_LAN(IDD_DLG_M1_MODIFY_SCB, IDC_STATIC_PWDB);
	SET_CONTROL_LAN(IDD_DLG_M1_MODIFY_SCB, IDC_BTN_MODIFY);
}
