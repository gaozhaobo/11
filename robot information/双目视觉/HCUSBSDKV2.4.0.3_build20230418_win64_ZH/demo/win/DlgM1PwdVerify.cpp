// DlgM1PwdVerify.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1PwdVerify.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CSTRING_TO_CHARS(str,sz) memcpy((sz),str.GetBuffer(str.GetLength()),str.GetLength())

/////////////////////////////////////////////////////////////////////////////
// CDlgM1PwdVerify dialog


CDlgM1PwdVerify::CDlgM1PwdVerify(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1PwdVerify::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1PwdVerify)
        // NOTE: the ClassWizard will add member initialization here
    m_dwSectionNum = 0;
    m_csPwd = _T("00 00 00 00 00 00");
    //}}AFX_DATA_INIT
}


void CDlgM1PwdVerify::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1PwdVerify)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_COM_PWD_TYPE, m_comPwdType);

    DDX_Text(pDX, IDC_EDT_PWD, m_csPwd);
    DDX_Text(pDX, IDC_EDT_SECTION_NUM, m_dwSectionNum);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1PwdVerify, CDialog)
    //{{AFX_MSG_MAP(CDlgM1PwdVerify)
    ON_BN_CLICKED(IDC_BTN_VERIFY, OnBtnVerify)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1PwdVerify message handlers

BOOL CDlgM1PwdVerify::OnInitDialog()
{
    CDialog::OnInitDialog();

    m_comPwdType.InsertString(0, _T("0-KeyA"));
    m_comPwdType.InsertString(1, _T("1-KeyB"));
    m_comPwdType.SetCurSel(0);
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgM1PwdVerify::OnBtnVerify() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    if (m_dwSectionNum < 0)
    {
		if (g_bEnglish)
		{
			MessageBox("Section number must >=0");
		}
		else
		{
			MessageBox("扇区号应>=0");
		}
        return;
    }
    
    if (m_csPwd.GetLength() < 17 )
    {
		if (g_bEnglish)
		{
			MessageBox("Password A should 6 Hex");
		}
		else
		{
			MessageBox("密码A应为6个16进制数");
		}
        return;
    }
    
    BYTE byPwdType = m_comPwdType.GetCurSel();

    USB_M1_PWD_VERIFY_INFO struPwdVerify = {0};
    struPwdVerify.dwSize = sizeof(struPwdVerify);
    struPwdVerify.bySectionNum = static_cast<BYTE>(m_dwSectionNum);
    struPwdVerify.byPasswordType = byPwdType;


    char szPwd[32] = {0};
    CSTRING_TO_CHARS(m_csPwd, szPwd);
    DWORD dwDataLen = 0;
    if (!ConvertHexBufToByteBuf(szPwd, strlen(szPwd)+1, struPwdVerify.byPassword, &dwDataLen))
    {
		if (g_bEnglish)
		{
			MessageBox("Password error!Please ensure 6 Hex.");
		}
		else
		{
			MessageBox("输入的密码数据有误! 请确认为6个16进制数, 每个数为2位.");
		}
        return;
    }

    if (dwDataLen != 6)
    {
		if (g_bEnglish)
		{
			MessageBox("Password should 6 Byte!");
		}
		else
		{
			MessageBox("密码应为6Byte!");
		}
        return;
    }
    
        
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struPwdVerify);
    struInput.lpInBuffer = &struPwdVerify;
    
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_M1_PWD_VERIFY, &struInput, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_M1_PWD_VERIFY");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_M1_PWD_VERIFY");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }	
}

void CDlgM1PwdVerify::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_PWD_VERIFY);
	SET_CONTROL_LAN(IDD_DLG_M1_PWD_VERIFY, IDC_STATIC_PWD_TYPE);
	SET_CONTROL_LAN(IDD_DLG_M1_PWD_VERIFY, IDC_STATIC_BLOCK_ID);
	SET_CONTROL_LAN(IDD_DLG_M1_PWD_VERIFY, IDC_STATIC_PWD);
	SET_CONTROL_LAN(IDD_DLG_M1_PWD_VERIFY, IDC_BTN_VERIFY);
}