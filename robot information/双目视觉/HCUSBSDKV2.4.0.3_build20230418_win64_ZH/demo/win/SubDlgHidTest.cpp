// SubDlgHidTest.cpp : implementation file
//

#include "stdafx.h"


#include "UsbDemo.h"
#include "SubDlgHidTest.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


int g_nEnumDevIndex = 1;

/////////////////////////////////////////////////////////////////////////////
// CSubDlgHidTest dialog


DLL_DECLARE(WINAPI, BOOL,  USB_SDK_Init, (VOID));
DLL_DECLARE(WINAPI, BOOL,  USB_SDK_Cleanup, (VOID));
DLL_DECLARE(WINAPI, DWORD, USB_SDK_GetLastError, (VOID));
DLL_DECLARE(WINAPI, char*, USB_SDK_GetErrorMsg, (DWORD));
DLL_DECLARE(WINAPI, char*, USB_SDK_EnumDevice, (fEnumDeviceCallBack, void*));
DLL_DECLARE(WINAPI, LONG,  USB_SDK_Login, (LPUSB_USER_LOGIN_INFO, LPUSB_DEVICE_INFO));
DLL_DECLARE(WINAPI, BOOL,  USB_SDK_Logout, (LONG));
//DLL_DECLARE(WINAPI, BOOL,  USB_SDK_SetDeviceConfig, (LONG, PVOID, DWORD, PVOID, DWORD, PVOID, DWORD));
//DLL_DECLARE(WINAPI, BOOL,  USB_SDK_GetDeviceConfig, (LONG, PVOID, DWORD, PVOID, DWORD, PVOID, DWORD*));
//DLL_DECLARE(WINAPI, BOOL,  USB_SDK_ControlDevice, (LONG, PVOID, DWORD, PVOID, DWORD, PVOID, DWORD));


void CALLBACK OnEnumDeviceCallBack(USB_DEVICE_INFO *pDevceInfo, void *pUser)
{
	//FIXME:Check
	CSubDlgHidTest *pDialog = (CSubDlgHidTest*)pUser;

	CString strDeviceInfo;
    strDeviceInfo.Format("%d", g_nEnumDevIndex);

	CString strDebugInfo;
	strDebugInfo.Format("枚举到HID设备: Index=%d VID=0x%04X PID=0x%04X DevName=%s SerialNum=%s Status=%d", g_nEnumDevIndex, 
						pDevceInfo->dwVID, 
						pDevceInfo->dwPID,
						pDevceInfo->sDeviceName,
						pDevceInfo->sSerialNumber,
						pDevceInfo->dwStatus);
	pDialog->PrintInfo(strDebugInfo);
    
    int nRow = pDialog->m_pListHidDev->InsertItem(g_nEnumDevIndex-1, strDeviceInfo);//插入行
	strDeviceInfo.Format("0x%04X", pDevceInfo->dwVID);
    pDialog->m_pListHidDev->SetItemText(nRow, 1, strDeviceInfo);//显示VID
	strDeviceInfo.Format("0x%04X", pDevceInfo->dwPID);
    pDialog->m_pListHidDev->SetItemText(nRow, 2, strDeviceInfo);//显示PID
	strDeviceInfo.Format("%s", pDevceInfo->sDeviceName);
    pDialog->m_pListHidDev->SetItemText(nRow, 3, strDeviceInfo);//显示设备名称
	strDeviceInfo.Format("%s", pDevceInfo->sSerialNumber);
    pDialog->m_pListHidDev->SetItemText(nRow, 4, strDeviceInfo);//显示序列号
	strDeviceInfo.Format("%d", pDevceInfo->dwStatus);
    pDialog->m_pListHidDev->SetItemText(nRow, 5, strDeviceInfo);//显示状态

	pDialog->AddNewDevInfo(pDevceInfo);


	g_nEnumDevIndex++;
}

void CALLBACK OnRecvDeviceMessage(void* lpBuffer, DWORD dwSize, void* pUser)
{
	//FIXME:Check
	CString strDebugInfo;
	CSubDlgHidTest *pDialog = (CSubDlgHidTest*)pUser;
	if (lpBuffer == NULL)
	{
		strDebugInfo = _T("SDK传递的Buffer为空!");
		pDialog->PrintInfo(strDebugInfo);
	}
	else
	{
		strDebugInfo = _T("接收到设备发送过来的数据!");
		pDialog->PrintInfo(strDebugInfo);
		pDialog->PrintData((char*)lpBuffer, dwSize);
	}
}


CSubDlgHidTest::CSubDlgHidTest(CWnd* pParent /*=NULL*/)
	: CDialog(CSubDlgHidTest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubDlgHidTest)
		// NOTE: the ClassWizard will add member initialization here
	m_nHidIndex = -1;
	m_lHidID = INVALID_USB_USER_ID;
	m_nHidDevNum = 0;
	memset(m_aHidDevInfo, 0, sizeof(m_aHidDevInfo));
	//}}AFX_DATA_INIT
}


void CSubDlgHidTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubDlgHidTest)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX, IDC_EDT_INFO, m_edtInfo);

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubDlgHidTest, CDialog)
	//{{AFX_MSG_MAP(CSubDlgHidTest)
	ON_BN_CLICKED(IDC_BTN_ENUM_HID, OnBtnEnumHid)
	ON_BN_CLICKED(IDC_BTN_WRITE, OnBtnWrite)
	ON_BN_CLICKED(IDC_BTN_LOGIN, OnBtnLogin)
	ON_BN_CLICKED(IDC_BTN_LOGOUT, OnBtnLogout)
	ON_WM_DESTROY()
	ON_WM_CANCELMODE()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LST_HID_DEV_INFO, OnItemchangedLstHidDevInfo)
	ON_NOTIFY(NM_CLICK, IDC_LST_HID_DEV_INFO, OnClickLstHidDevInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubDlgHidTest message handlers


BOOL CSubDlgHidTest::OnInitDialog()
{
	CDialog::OnInitDialog();

	DLL_LOAD(UsbSDK.dll, USB_SDK_Init, TRUE);
    DLL_LOAD(UsbSDK.dll, USB_SDK_Cleanup, TRUE);
    DLL_LOAD(UsbSDK.dll, USB_SDK_GetLastError, TRUE);
    DLL_LOAD(UsbSDK.dll, USB_SDK_GetErrorMsg, TRUE);
	DLL_LOAD(UsbSDK.dll, USB_SDK_EnumDevice, TRUE);
    DLL_LOAD(UsbSDK.dll, USB_SDK_Login, TRUE);
	DLL_LOAD(UsbSDK.dll, USB_SDK_Logout, TRUE);
	//DLL_LOAD(UsbSDK.dll, USB_SDK_SetDeviceConfig, TRUE);
	//DLL_LOAD(UsbSDK.dll, USB_SDK_GetDeviceConfig, TRUE);
	//DLL_LOAD(UsbSDK.dll, USB_SDK_ControlDevice, TRUE);


	USB_SDK_Init();

	m_pListHidDev = (CListCtrl*)GetDlgItem(IDC_LST_HID_DEV_INFO);

	LONG lStyle;
    lStyle = GetWindowLong(m_pListHidDev->m_hWnd, GWL_STYLE);//获取当前窗口style
    lStyle &= ~LVS_TYPEMASK; //清除显示方式位
    lStyle |= LVS_REPORT;    //设置style
    SetWindowLong(m_pListHidDev->m_hWnd, GWL_STYLE, lStyle);//设置style
    
    DWORD dwStyle = m_pListHidDev->GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
    dwStyle |= LVS_EX_GRIDLINES;    //网格线（只适用与report风格的listctrl）
    m_pListHidDev->SetExtendedStyle(dwStyle); //设置扩展风格
	
    m_pListHidDev->InsertColumn(0, "Index", LVCFMT_LEFT, 50);//插入列
	m_pListHidDev->InsertColumn(1, "VID", LVCFMT_LEFT, 50);//插入列
	m_pListHidDev->InsertColumn(2, "PID", LVCFMT_LEFT, 50);//插入列
	m_pListHidDev->InsertColumn(3, "名称", LVCFMT_LEFT, 120);//插入列
	m_pListHidDev->InsertColumn(4, "序列号", LVCFMT_LEFT, 120);//插入列
	m_pListHidDev->InsertColumn(5, "状态", LVCFMT_LEFT, 60);//插入列

	GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_WRITE)->EnableWindow(FALSE);

	UpdateData(FALSE);

	return TRUE;
}

void CSubDlgHidTest::AddNewDevInfo(USB_DEVICE_INFO *lpUsbDevInfo)
{
	memcpy(&m_aHidDevInfo[m_nHidDevNum], lpUsbDevInfo, sizeof(USB_DEVICE_INFO));
	m_nHidDevNum++;
}

void CSubDlgHidTest::OnBtnEnumHid() 
{
	// TODO: Add your control notification handler code here

	m_nHidDevNum = 0;
	memset(m_aHidDevInfo, 0, sizeof(m_aHidDevInfo));

	// 先清空List
	g_nEnumDevIndex = 1;
	m_pListHidDev->DeleteAllItems();
	PrintInfo(_T("枚举HID设备"));

	//USB_SDK_EnumDevice(NULL, OnEnumDeviceCallBack, this);
	USB_SDK_EnumDevice(OnEnumDeviceCallBack, this);
}


void CSubDlgHidTest::OnBtnLogin() 
{
	// TODO: Add your control notification handler code here
	USB_USER_LOGIN_INFO struUsbLoginInfo = {0};
	struUsbLoginInfo.dwTimeout = 5000;
	sprintf(struUsbLoginInfo.sUserName, "%s", "admin");
	sprintf(struUsbLoginInfo.sPassword, "%s", "1234");

	USB_DEVICE_INFO struUsbDeviceInfo = {0};
	memcpy(&struUsbDeviceInfo, &m_aHidDevInfo[m_nHidIndex], sizeof(USB_DEVICE_INFO));
	m_lHidID = USB_SDK_Login(&struUsbLoginInfo, &struUsbDeviceInfo);

	CString csInfo;
	DWORD dwErrorCode = USB_SUCCESS;
	if (m_lHidID == INVALID_USB_USER_ID)
	{
		dwErrorCode = USB_SDK_GetLastError();
#ifdef SWITCH_ENGLISH_US
        
        csInfo.Format("Login Device Failed! ErrorCode=%d ErrorMsg=%s", dwErrorCode, USB_SDK_GetErrorMsg(dwErrorCode));
        
#else
        
        csInfo.Format("登录设备失败! ErrorCode=%d ErrorMsg=%s", dwErrorCode, USB_SDK_GetErrorMsg(dwErrorCode));
        
#endif

		GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_WRITE)->EnableWindow(FALSE);
		PrintInfo(csInfo);
	}
	else
	{		
#ifdef SWITCH_ENGLISH_US
        
        csInfo.Format("Login Device Success! UserID=%d", m_lHidID);
        
#else
        
        csInfo.Format("登录设备成功! UserID=%d", m_lHidID);
        
#endif
		GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_WRITE)->EnableWindow(TRUE);
		PrintInfo(csInfo);

		//注册读回调
	}	
}

void CSubDlgHidTest::OnBtnLogout() 
{
	// TODO: Add your control notification handler code here
	
}

void CSubDlgHidTest::OnBtnWrite()
{
	// TODO: Add your control notification handler code here
	char szBuf[254] = {0};
	int i = 0;

	szBuf[253] = 20;
	//szBuf[254] = 0;
	//szBuf[254] = 3;

	
}


void CSubDlgHidTest::PrintData(char* lpBuffer, const DWORD dwSize)
{
	CString csTemp;
	CString csInfo;

	csInfo.Format("数据长度: %d 字节, 数据如下:\r\n", dwSize);
	m_edtInfo.SetSel(-1);
    m_edtInfo.ReplaceSel(csInfo);

	csInfo = _T("");

	for (int i = 1; i < dwSize+1; i++)
	{
		csTemp.Format("%02X", (unsigned char)lpBuffer[i-1]);
		if (i % 16 == 0)
		{
			csInfo += csTemp + _T("     ");
		}
		else if(i % 8 == 0)
		{
			csInfo += csTemp + _T("   ");
		}
		else if(i % 4 == 0)
		{
			csInfo += csTemp + _T("  ");
		}
		else
		{
			csInfo += csTemp + _T(" ");
		}
		
		if (i % 32 == 0)
		{
			csInfo += _T("\r\n");
			m_edtInfo.SetSel(-1);
			m_edtInfo.ReplaceSel(csInfo);
			csInfo = _T("");
		}
	}
	if (csInfo.GetLength() != 0)
	{
		csInfo += _T("\r\n");
		m_edtInfo.SetSel(-1);
		m_edtInfo.ReplaceSel(csInfo);
		csInfo = _T("");
	}

}

void CSubDlgHidTest::PrintInfo(CString csInfo)
{
	CString strOutput;
	SYSTEMTIME ti;
    ::GetLocalTime(&ti);
    strOutput.Format("[%02d:%02d:%02d.%03d]", ti.wHour, ti.wMinute, ti.wSecond, ti.wMilliseconds);
	strOutput += csInfo;
	strOutput += _T("\r\n");
	m_edtInfo.SetSel(-1);
	m_edtInfo.ReplaceSel(strOutput);
}


void CSubDlgHidTest::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	USB_SDK_Cleanup();
	
}

void CSubDlgHidTest::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CSubDlgHidTest::OnItemchangedLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CSubDlgHidTest::OnClickLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    if(pNMListView->iItem != -1)
    {
         //判断Item状态，是否为选中状态
		if(m_pListHidDev->GetItemState(pNMListView->iItem, LVIS_SELECTED) == LVIS_SELECTED)
		{
			if (pNMListView->iItem < m_nHidDevNum)
			{
				m_nHidIndex = pNMListView->iItem;
				GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(TRUE);
				GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(TRUE);
				GetDlgItem(IDC_BTN_WRITE)->EnableWindow(FALSE);
			}
		}
		else
		{
			GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_WRITE)->EnableWindow(FALSE);
		}
    }
	else
	{
		GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_WRITE)->EnableWindow(FALSE);
	}
			
	*pResult = 0;
}


