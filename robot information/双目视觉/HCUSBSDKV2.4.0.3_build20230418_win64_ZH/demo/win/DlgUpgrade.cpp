// DlgUpgrade.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgUpgrade.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgUpgrade dialog

extern BOOL g_bUpgrade;

CDlgUpgrade::CDlgUpgrade(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUpgrade::IDD, pParent)
    , m_dwModuleID(0)
{
	//{{AFX_DATA_INIT(CDlgUpgrade)
		// NOTE: the ClassWizard will add member initialization here
    //m_nSubProgress   = 0;
    m_nTimeout = 60;
    m_nTotalProgress = 0;
    m_bUpgrade = FALSE;
	//}}AFX_DATA_INIT
}


void CDlgUpgrade::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgUpgrade)
    // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_TIMEOUT, m_nTimeout);
    DDX_Text(pDX, IDC_EDT_FILE_PATH, m_csFilePath);
    DDX_Text(pDX, IDC_STA_UPGRADE_STATE, m_csState);
    //DDX_Text(pDX, IDC_STA_SUB_PROGRESS,  m_csSubProgress);
    DDX_Text(pDX, IDC_STA_TOTAL_PROGRESS, m_csTotalProgress);
    //}}AFX_DATA_MAP
    DDX_Text(pDX, IDC_EDIT_MODULEID, m_dwModuleID);
}


BEGIN_MESSAGE_MAP(CDlgUpgrade, CDialog)
	//{{AFX_MSG_MAP(CDlgUpgrade)
	ON_BN_CLICKED(IDC_BTN_SELECT, OnBtnSelect)
	ON_BN_CLICKED(IDC_BTN_UPGRADE, OnBtnUpgrade)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgUpgrade message handlers

BOOL CDlgUpgrade::OnInitDialog()
{
    CDialog::OnInitDialog();

    //m_pProgCtrlSub = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS_SUB);
    m_pProgCtrlTotal = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS_TOTAL);

    //m_pProgCtrlSub->SetRange(0, 100);//设置进度条范围
    m_pProgCtrlTotal->SetRange(0, 100);//设置进度条范围

    //m_pProgCtrlSub->SetPos(0);
    m_pProgCtrlTotal->SetPos(0);

    //m_csSubProgress = _T("0%");
    m_csTotalProgress = _T("0%");
    m_dwModuleID = 0;
    UpdateData(FALSE);

    return TRUE;
}

void CDlgUpgrade::OnBtnSelect() 
{
	// TODO: Add your control notification handler code here

    UpdateData(TRUE);

	BOOL isOpen = TRUE;		//是否打开(否则为保存)
	CString defaultDir = _T("C:\\");	//默认打开的文件路径
    CString filter = _T("文件 (*.txt; *.dat; *.bin; *.dav)|*.txt;*.dat;*.bin;*.dav||");	//文件过虑的类型

	CFileDialog openFileDlg(isOpen, defaultDir, m_csFilePath, OFN_HIDEREADONLY|OFN_READONLY, filter, NULL);
	//openFileDlg.GetOFN().lpstrInitialDir = _T("");

	INT_PTR result = openFileDlg.DoModal();
    if(result == IDOK)
    {
        m_csFilePath = openFileDlg.GetPathName();
        UpdateData(FALSE);
    }

}

void CDlgUpgrade::OnBtnUpgrade() 
{
	// TODO: Add your control notification handler code here

    if (m_bUpgrade)
    {
        return;
    }

    UpdateData(TRUE);

    if (m_nTimeout < 15 || m_nTimeout > 255)
    {
		if (g_bEnglish)
		{
			MessageBox("Timeout time range should between 15(include) and 255(include)");
		}
		else
		{
			MessageBox("超时时间的范围应该在15(含)到255(含)之间");
		}
        return;
    }
	if (g_bEnglish)
	{
		m_csState = _T("uprgrading...");
	}
	else
	{
		m_csState = _T("正在升级...");
	}

    //m_pProgCtrlSub->SetPos(0);
    m_pProgCtrlTotal->SetPos(0);
      
    //m_csSubProgress = _T("0%");
    m_csTotalProgress = _T("0%");
        
    UpdateData(FALSE);
          
    char szFilePatch[512] = {0};
            
    CSTRING_TO_CHARS(m_csFilePath, szFilePatch);

	if (g_bEnglish)
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "Pre upgrade...");
	}
	else
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "预升级...");
	}

    USB_UPGRADE_COND struUpgradeCond = {0};
    struUpgradeCond.dwSize = sizeof(struUpgradeCond);
    struUpgradeCond.byTimeout = m_nTimeout;
    struUpgradeCond.dwModuleID = m_dwModuleID;
    g_bUpgrade = TRUE;         
    m_lUpgradeHandle = USB_Upgrade(m_lUserID, 0, szFilePatch, &struUpgradeCond, sizeof(struUpgradeCond));

    if (m_lUpgradeHandle == USB_INVALID_UPGRADE_HANDLE)
    {
        g_bUpgrade = FALSE; 
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_Upgrade()");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    else
    {
        m_bUpgrade = TRUE;
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_Upgrade() upgrading...");
		}
		else
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_Upgrade() 正在升级...");
		}
        SetTimer(1, 100, NULL);//设置进度条更新时钟

        GetDlgItem(IDC_BTN_UPGRADE)->EnableWindow(FALSE);
    }
	
}

void CDlgUpgrade::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);

    DWORD dwError = USB_SUCCESS;


    if (!USB_GetUpgradeState(m_lUpgradeHandle, &m_struUpgradeState))
    {
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetUpgradeState() Get upgrade status failed!");
		}
		else
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetUpgradeState() 获取升级状态失败!");
		}
        g_bUpgrade = FALSE;
        m_bUpgrade = FALSE;
        KillTimer(1);
        GetDlgItem(IDC_BTN_UPGRADE)->EnableWindow(TRUE);
        USB_CloseUpgradeHandle(m_lUpgradeHandle);
        m_lUpgradeHandle = USB_INVALID_UPGRADE_HANDLE;
    }
    else
    {
        switch (m_struUpgradeState.byState)
        {
        case USB_UPGRADE_FAILED:
			if (g_bEnglish)
			{
				m_csState = _T("Urgrade failed");
			}
			else
			{
				m_csState = _T("升级失败");
			}
            //m_nSubProgress = 0;
            g_bUpgrade = FALSE;
            m_bUpgrade = FALSE;
            KillTimer(1);
            GetDlgItem(IDC_BTN_UPGRADE)->EnableWindow(TRUE);
			if (g_bEnglish)
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED Upgrade failed!");
			}
			else
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED 升级失败!");
			}
            USB_CloseUpgradeHandle(m_lUpgradeHandle);
            m_lUpgradeHandle = USB_INVALID_UPGRADE_HANDLE;
            break;
        case USB_UPGRADE_SUCCESS:
			if (g_bEnglish)
			{
				m_csState = _T("Upgrade success");
			}
			else
			{
				m_csState = _T("升级成功");
			}
            //m_nSubProgress = 100;
            m_nTotalProgress = 100;
            g_bUpgrade = FALSE;
            m_bUpgrade = FALSE;
            KillTimer(1);
            GetDlgItem(IDC_BTN_UPGRADE)->EnableWindow(TRUE);
			if (g_bEnglish)
			{
				LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS Upgrade success");
				MessageBox("Before operate this device,please enum and login device again");
			}
			else
			{
				LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS 升级成功");
				MessageBox("若要对设备进行操作, 请重新遍历设备, 并登录设备");
			}
            USB_CloseUpgradeHandle(m_lUpgradeHandle);
            m_lUpgradeHandle = USB_INVALID_UPGRADE_HANDLE;
            break;
        case USB_UPGRADE_TRANS:
			if (g_bEnglish)
			{
				m_csState = _T("Upgrade packet transferring...");
			}
			else
			{
				m_csState = _T("正在传输升级包数据...");
			}
            //m_nSubProgress = m_struUpgradeState.byProgress;
            m_nTotalProgress = m_struUpgradeState.byProgress;
            //LOGIN_INFO->WriteLog(INF_LEVEL, "正在传输数据, 进度=%d", m_struUpgradeState.byProgress);
            break;
        case USB_UPGRADE_FLASH_FAILED:
			if (g_bEnglish)
			{
				m_csState = _T("Upgrade write flash failed");
			}
			else
			{
				m_csState = _T("升级写flash失败");
			}
            //m_nSubProgress = 0;
            g_bUpgrade = FALSE;
            m_bUpgrade = FALSE;
            KillTimer(1);
            GetDlgItem(IDC_BTN_UPGRADE)->EnableWindow(TRUE);
			if (g_bEnglish)
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "Upgrade write flash failed");
			}
			else
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "升级写flash失败!");
			}
            USB_CloseUpgradeHandle(m_lUpgradeHandle);
            m_lUpgradeHandle = USB_INVALID_UPGRADE_HANDLE;
            break;
        case USB_UPGRADE_TYPE_UNMATCH:
			if (g_bEnglish)
			{
				m_csState = _T("Upgrade type unmatch");
			}
			else
			{
				m_csState = _T("升级包类型不匹配");
			}
            //m_nSubProgress = 0;
            g_bUpgrade = FALSE;
            m_bUpgrade = FALSE;
            KillTimer(1);
            GetDlgItem(IDC_BTN_UPGRADE)->EnableWindow(TRUE);
			if (g_bEnglish)
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "Upgrade type unmatch");
			}
			else
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "升级包类型不匹配!");
			}
            USB_CloseUpgradeHandle(m_lUpgradeHandle);
            m_lUpgradeHandle = USB_INVALID_UPGRADE_HANDLE;
            break;
        case USB_UPGRADE_WRITE_FLASH:
			if (g_bEnglish)
			{
				m_csState = _T("Upgrade packet writing flash...");
			}
			else
			{
				m_csState = _T("正在写FLASH数据...");
			}
            m_nTotalProgress = m_struUpgradeState.byProgress;
            break;
        default:
			if (g_bEnglish)
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "Error Unknown upgrade status!");
			}
			else
			{
				LOGIN_INFO->WriteLog(ERR_LEVEL, "Error 未知的升级状态!");
			}
            USB_CloseUpgradeHandle(m_lUpgradeHandle);
            m_lUpgradeHandle = USB_INVALID_UPGRADE_HANDLE;
            break;
        }
    }

    //m_pProgCtrlSub->SetPos(m_nSubProgress);
    m_pProgCtrlTotal->SetPos(m_nTotalProgress);

    //m_csSubProgress.Format("%d", m_nSubProgress);
    //m_csSubProgress += _T("%");
    m_csTotalProgress.Format("%d", m_nTotalProgress);
    m_csTotalProgress += _T("%");

    UpdateData(FALSE);
}


void CDlgUpgrade::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_UPGRADE);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_STATIC_TEXT);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_STATIC_TIME);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_STATIC_SECOND);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_STATIC_MODEL_ID);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_STATIC_PATH);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_BTN_SELECT);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_STATIC_STATUS);
	SET_CONTROL_LAN(IDD_DLG_UPGRADE, IDC_STATIC_PROG);
}

