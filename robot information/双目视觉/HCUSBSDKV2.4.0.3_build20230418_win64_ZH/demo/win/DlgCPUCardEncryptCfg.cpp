// DlgCPUCardEncryptCfg.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgCPUCardEncryptCfg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardEncryptCfg dialog


CDlgCPUCardEncryptCfg::CDlgCPUCardEncryptCfg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCPUCardEncryptCfg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCPUCardEncryptCfg)
	m_csKey = _T("");
	m_dwKeyLength = 0;
	//}}AFX_DATA_INIT
}


void CDlgCPUCardEncryptCfg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCPUCardEncryptCfg)
	DDX_Control(pDX, IDC_COM_CARD_TYPE, m_comCardType);
	DDX_Text(pDX, IDC_EDIT_KEY, m_csKey);
	DDX_Text(pDX, IDC_EDIT_KEY_LENGTH, m_dwKeyLength);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCPUCardEncryptCfg, CDialog)
	//{{AFX_MSG_MAP(CDlgCPUCardEncryptCfg)
	ON_CBN_SELCHANGE(IDC_COM_CARD_TYPE, OnSelchangeComCardType)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardEncryptCfg message handlers

BOOL CDlgCPUCardEncryptCfg::OnInitDialog()
{
    CDialog::OnInitDialog();

    if (g_bEnglish)
    {
        m_comCardType.InsertString(0, _T("invalid"));
        m_comCardType.InsertString(1, _T("white Card"));
        m_comCardType.InsertString(2, _T("hik CPU Card"));
        m_comCardType.InsertString(3, _T("other Encrypted Card"));
    }
    else
    {
        m_comCardType.InsertString(0, _T("无效"));
        m_comCardType.InsertString(1, _T("白卡"));
        m_comCardType.InsertString(2, _T("海康CPU卡"));
        m_comCardType.InsertString(3, _T("其它已加密卡片"));
    }

    m_comCardType.SetCurSel(0);
    OnSelchangeComCardType();
    UpdateData(FALSE);
    
    return TRUE;
}

void CDlgCPUCardEncryptCfg::OnSelchangeComCardType() 
{
	// TODO: Add your control notification handler code here
		if(m_comCardType.GetCurSel() == 3)
	{
		GetDlgItem(IDC_STATIC_KEY_LENGTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_KEY1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_KEY_LENGTH)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_EDIT_KEY)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_STATIC_KEY_LENGTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_KEY1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_KEY_LENGTH)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_EDIT_KEY)->ShowWindow(SW_HIDE);
	}
}

void CDlgCPUCardEncryptCfg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	 if (m_csKey.GetLength() > 16 || m_dwKeyLength > 16)
    {
        MessageBox("密钥不能超过16位字节");
        return;
    }

	USB_CPU_CARD_ENCRYPT struCPUCardEncrypt = {0};
    struCPUCardEncrypt.dwSize = sizeof(struCPUCardEncrypt);
    struCPUCardEncrypt.byCardType = (BYTE)m_comCardType.GetCurSel();
	struCPUCardEncrypt.byKeyLength = (BYTE)m_dwKeyLength;
    memcpy(struCPUCardEncrypt.byKeyContent, m_csKey.GetBuffer(m_csKey.GetLength()), struCPUCardEncrypt.byKeyLength);

    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struCPUCardEncrypt);
    struInput.lpInBuffer = &struCPUCardEncrypt;

    USB_CPU_CARD_ENCRYPT_RES struCPUCardEncryptRes = {0};
    struCPUCardEncryptRes.dwSize = sizeof(struCPUCardEncryptRes);

    USB_CONFIG_OUTPUT_INFO struOutput = {0};
    struOutput.dwOutBufferSize = sizeof(struCPUCardEncryptRes);
    struOutput.lpOutBuffer = &struCPUCardEncryptRes;
	
	if (USB_SetDeviceConfig(m_lUserID, USB_CPU_CARD_ENCRYPT_CFG, &struInput, &struOutput))
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_CPU_CARD_ENCRYPT_CFG");
		LOGIN_INFO->WriteLog(INF_LEVEL, "Set Success = [%d]", struCPUCardEncryptRes.byTryTimes);
	}
	else
	{
		LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_CPU_CARD_ENCRYPT_CFG");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
		//LOGIN_INFO->WriteLog(ERR_LEVEL, "Set Failed, remaining attempts = [%d]", struCPUCardEncryptRes.byTryTimes);
	}

	CDialog::OnOK();
}


void CDlgCPUCardEncryptCfg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_CPU_CARD_ENCRYPT_CFG);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_ENCRYPT_CFG, IDC_STATIC);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_ENCRYPT_CFG, IDC_STATIC_KEY_LENGTH);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_ENCRYPT_CFG, IDC_STATIC_KEY1);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_ENCRYPT_CFG, IDOK);
}
