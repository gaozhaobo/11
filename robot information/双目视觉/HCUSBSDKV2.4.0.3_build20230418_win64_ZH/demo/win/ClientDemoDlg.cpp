// ClientDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "ClientDemoDlg.h"
#include "GlobalCtrl.h"
#include <initguid.h>
#include<algorithm>
#include "Language.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

DEFINE_GUID(GUID_DEVINTERFACE_USB_HUB,    0xf18a0e88, 0xc30c, 0x11d0, 0x88, 0x15, 0x00, \
            0xa0, 0xc9, 0x06, 0xbe, 0xd8);

/* A5DCBF10-6530-11D2-901F-00C04FB951ED */
DEFINE_GUID(GUID_DEVINTERFACE_USB_DEVICE, 0xA5DCBF10, 0x6530, 0x11D2, 0x90, 0x1F, 0x00, \
            0xC0, 0x4F, 0xB9, 0x51, 0xED);

/* 3ABF6F2D-71C4-462a-8A92-1E6861E6AF27 */
DEFINE_GUID(GUID_DEVINTERFACE_USB_HOST_CONTROLLER, 0x3abf6f2d, 0x71c4, 0x462a, 0x8a, 0x92, 0x1e, \
            0x68, 0x61, 0xe6, 0xaf, 0x27);

/* 4E623B20-CB14-11D1-B331-00A0C959BBD2 */
DEFINE_GUID(GUID_USB_WMI_STD_DATA, 0x4E623B20L, 0xCB14, 0x11D1, 0xB3, 0x31, 0x00,\
            0xA0, 0xC9, 0x59, 0xBB, 0xD2);

/* 4E623B20-CB14-11D1-B331-00A0C959BBD2 */
DEFINE_GUID(GUID_USB_WMI_STD_NOTIFICATION, 0x4E623B20L, 0xCB14, 0x11D1, 0xB3, 0x31, 0x00,\
            0xA0, 0xC9, 0x59, 0xBB, 0xD2);        


#define GUID_CLASS_USBHUB               GUID_DEVINTERFACE_USB_HUB
#define GUID_CLASS_USB_DEVICE           GUID_DEVINTERFACE_USB_DEVICE
#define GUID_CLASS_USB_HOST_CONTROLLER  GUID_DEVINTERFACE_USB_HOST_CONTROLLER

#define DEVICE_NOTIFY_ALL_INTERFACE_CLASSES    0x00000004

DLL_DECLARE(WINAPI, VOID, HidD_GetHidGuid, (LPGUID));

//CRITICAL_SECTION g_cs;

HANDLE g_mutex;

int g_nEnumDevIndex = 1;
BOOL g_bUpgrade = FALSE;

#define CSTRING_TO_CHARS(str,sz) memcpy((sz),str.GetBuffer(str.GetLength()),str.GetLength())


void CALLBACK OnEnumDeviceCallBack(USB_DEVICE_INFO *pDevceInfo, void *pUser)
{
    //FIXME:Check
    CClientDemoDlg *pDialog = (CClientDemoDlg*)pUser;
    
    CString strDeviceInfo;
    strDeviceInfo.Format("%d", g_nEnumDevIndex);

	if (g_bEnglish)
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "Enum Device: [Index=%d] [VID=0x%04X] [PID=0x%04X] [Manufacturer=%s] [DevName=%s] [SerialNum=%s]",
			g_nEnumDevIndex,
			pDevceInfo->dwVID,
			pDevceInfo->dwPID,
			pDevceInfo->szManufacturer,
			pDevceInfo->szDeviceName,
			pDevceInfo->szSerialNumber);
	}
	else
	{

		LOGIN_INFO->WriteLog(INF_LEVEL, "枚举到设备: [Index=%d] [VID=0x%04X] [PID=0x%04X] [Manufacturer=%s] [DevName=%s] [SerialNum=%s]",
			g_nEnumDevIndex,
			pDevceInfo->dwVID,
			pDevceInfo->dwPID,
			pDevceInfo->szManufacturer,
			pDevceInfo->szDeviceName,
			pDevceInfo->szSerialNumber);
	}
    
    
    int nRow = pDialog->m_pListHidDev->InsertItem(g_nEnumDevIndex-1, strDeviceInfo);//插入行

    strDeviceInfo.Format("0x%04X", pDevceInfo->dwVID);
    pDialog->m_pListHidDev->SetItemText(nRow, 1, strDeviceInfo);//显示VID

    strDeviceInfo.Format("0x%04X", pDevceInfo->dwPID);
    pDialog->m_pListHidDev->SetItemText(nRow, 2, strDeviceInfo);//显示PID

    strDeviceInfo.Format("%s", pDevceInfo->szManufacturer);
    pDialog->m_pListHidDev->SetItemText(nRow, 3, strDeviceInfo);//显示制造商

    strDeviceInfo.Format("%s", pDevceInfo->szDeviceName);
    pDialog->m_pListHidDev->SetItemText(nRow, 4, strDeviceInfo);//显示设备名称

    strDeviceInfo.Format("%s", pDevceInfo->szSerialNumber);
    pDialog->m_pListHidDev->SetItemText(nRow, 5, strDeviceInfo);//显示序列号
    
    if (pDialog->isLogon(pDevceInfo))
    {
        pDialog->m_pListHidDev->SetItemText(nRow, 6, "yes");   //登陆状态
        pDialog->m_pListHidDev->SetItemText(nRow, 7, "yes");   //激活状态
    }
    else
    {
        pDialog->m_pListHidDev->SetItemText(nRow, 6, "no");   //登陆状态
        pDialog->m_pListHidDev->SetItemText(nRow, 7, "/");    //激活状态
    }

    DWORD dwStatus = pDialog->GetActiveStatus(pDevceInfo);
    if (dwStatus == 1)
    {
        pDialog->m_pListHidDev->SetItemText(nRow, 7, "yes");   //激活状态
    }
    else if (dwStatus == 2)
    {
        pDialog->m_pListHidDev->SetItemText(nRow, 7, "no");   //未激活状态
    }

	strDeviceInfo.Format("%s", pDevceInfo->szDevicePath);
	pDialog->m_pListHidDev->SetItemText(nRow, 8, strDeviceInfo);//显示设备路径

    pDialog->AddNewDevInfo(pDevceInfo);
      
    g_nEnumDevIndex++;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
    CAboutDlg();

// Dialog Data
    //{{AFX_DATA(CAboutDlg)
    enum { IDD = IDD_ABOUTBOX };
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
    //{{AFX_DATA_INIT(CAboutDlg)
    //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAboutDlg)
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
    //{{AFX_MSG_MAP(CAboutDlg)
        // No message handlers
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDemoDlg dialog

CClientDemoDlg::CClientDemoDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CClientDemoDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CClientDemoDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    m_nHidIndex = -1;
    m_lUserID = USB_INVALID_USERID;
    m_nHidDevNum = 0;

    m_nLogIndex = 0;

    //InitializeCriticalSection(&g_cs);
    g_mutex = ::CreateMutex(NULL, FALSE, NULL);

    m_csUserName = _T("admin");
    m_csPassword = _T("12345");

    m_hDeviceNotify = NULL;

    memset(m_aHidDevInfo, 0, sizeof(m_aHidDevInfo));

    memset(&m_struCurUsbLoginInfo, 0, sizeof(m_struCurUsbLoginInfo));
    memset(&m_struCurDeviceInfo, 0, sizeof(m_struCurDeviceInfo));
}

CClientDemoDlg::~CClientDemoDlg()
{
    //DeleteCriticalSection(&g_cs);
    ::CloseHandle(g_mutex);
    LogInfo::Destroy();
}

void CClientDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CClientDemoDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here

    DDX_Control(pDX, IDC_TAB_MAIN, m_tabMain);

    DDX_Text(pDX, IDC_STA_SDK_VER, m_csSDKVersion);
    //DDX_Text(pDX, IDC_STA_SDK_BUILDER_VER, m_csDemoVersion);

    DDX_Text(pDX, IDC_STA_DEV_NAME, m_csDeviceName);
    DDX_Text(pDX, IDC_STA_SERIAL_NUMBER, m_csSerialNumber);

    DDX_Text(pDX, IDC_EDT_USER_NAME, m_csUserName);
    DDX_Text(pDX, IDC_EDT_PASSWORD, m_csPassword);

    //}}AFX_DATA_MAP
    DDX_Control(pDX, IDC_COMBO1, m_combLoginMode);
	DDX_Control(pDX, IDC_CHK_INCLUDE_ALL, m_btnIncludeAll);
	DDX_Control(pDX, IDC_CHK_SEPARATE, m_btnSeparate);
}

BEGIN_MESSAGE_MAP(CClientDemoDlg, CDialog)
    //{{AFX_MSG_MAP(CClientDemoDlg)
    ON_BN_CLICKED(IDC_BTN_ENUM_HID, OnBtnEnumHid)
    ON_BN_CLICKED(IDC_BTN_LOGIN, OnBtnLogin)
    ON_BN_CLICKED(IDC_BTN_LOGOUT, OnBtnLogout)
    ON_WM_DESTROY()
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LST_HID_DEV_INFO, OnItemchangedLstHidDevInfo)
    ON_NOTIFY(NM_CLICK, IDC_LST_HID_DEV_INFO, OnClickLstHidDevInfo)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, OnSelchangeTabMain)
    ON_WM_CANCELMODE()
    ON_BN_CLICKED(IDC_BTN_SET_USER_DATA, OnBtnSetUserData)
    ON_WM_DEVICECHANGE() //此消息就是处理设备添加删除
    ON_MESSAGE(WM_ADD_LOG, OnWMAddLog)
    //}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BTN_ACTIVE, &CClientDemoDlg::OnBnClickedBtnActive)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDemoDlg message handlers


BOOL CClientDemoDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    
    // Add "About..." menu item to system menu.

    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        CString strAboutMenu;
        strAboutMenu.LoadString(IDS_ABOUTBOX);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon
    
    // TODO: Add extra initialization here

    DLL_LOAD(hid.dll, HidD_GetHidGuid, FALSE);

	////设置一下库的加载路径
	//USB_LOCAL_LOAD_PATH sslPath;
 //   sslPath.emType = ENUM_DLL_SSL_PATH;
	//strcpy((char*)sslPath.byLoadPath, "E:\\USB动态库\\SSL\\ssleay32.dll");
 //   if (!USB_SetSDKLocalCfg(ENUM_LOCAL_CFG_TYPE_LOAD_PATH, &sslPath))
 //   {
 //       LOGIN_INFO->WriteLog(INF_LEVEL, "设置日志目录为 [%s]", sslPath);
 //   }

	//USB_LOCAL_LOAD_PATH cryptoPath;
 //   cryptoPath.emType = ENUM_DLL_CRYPTO_PATH;
 //   strcpy((char*)cryptoPath.byLoadPath, "E:\\USB动态库\\SSL\\libeay32.dll");
 //   if (!USB_SetSDKLocalCfg(ENUM_LOCAL_CFG_TYPE_LOAD_PATH, &cryptoPath))
 //   {
 //       LOGIN_INFO->WriteLog(INF_LEVEL, "[%s]", cryptoPath);
 //   }

	USB_LOCAL_LOAD_PATH playctrlPath;
    playctrlPath.emType = ENUM_DLL_PLAYCTRL_PATH;
    strcpy((char*)playctrlPath.byLoadPath, "E:\\USB动态库\\PlayCtrl\\PlayCtrl.dll");
    if (!USB_SetSDKLocalCfg(ENUM_LOCAL_CFG_TYPE_LOAD_PATH, &playctrlPath))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "[%s]", playctrlPath);
    }

	USB_LOCAL_LOAD_PATH libUSBPath;
    libUSBPath.emType = ENUM_DLL_LIBUSB_PATH;
    strcpy((char*)libUSBPath.byLoadPath, "E:\\USB动态库\\libusb-1.0.dll");
    if (!USB_SetSDKLocalCfg(ENUM_LOCAL_CFG_TYPE_LOAD_PATH, &libUSBPath))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "[%s]", libUSBPath);
    }
    USB_Init();

    char* szLogPath = "C:/USBSDKLog/";
    USB_SetLogToFile(ENUM_INFO_LEVEL, szLogPath, TRUE);

    m_pListHidDev = (CListCtrl*)GetDlgItem(IDC_LST_HID_DEV_INFO);
    m_pListLog    = (CListCtrl*)GetDlgItem(IDC_LST_LOG);

    LOGIN_INFO->s_pListLog = m_pListLog;
    LOGIN_INFO->s_pDlg     = this;
    
    LONG lStyle;
    lStyle = GetWindowLong(m_pListHidDev->m_hWnd, GWL_STYLE);//获取当前窗口style
    lStyle &= ~LVS_TYPEMASK; //清除显示方式位
    lStyle |= LVS_REPORT;    //设置style
    SetWindowLong(m_pListHidDev->m_hWnd, GWL_STYLE, lStyle);//设置style
    SetWindowLong(m_pListLog->m_hWnd, GWL_STYLE, lStyle);//设置style
    
    DWORD dwStyle = m_pListHidDev->GetExtendedStyle();
    dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
    dwStyle |= LVS_EX_GRIDLINES;    //网格线（只适用与report风格的listctrl）
    m_pListHidDev->SetExtendedStyle(dwStyle); //设置扩展风格
    m_pListLog->SetExtendedStyle(dwStyle); //设置扩展风格
    
	if (g_bEnglish)
	{
		m_pListHidDev->InsertColumn(0, "Idx", LVCFMT_LEFT, 40);//插入列
		m_pListHidDev->InsertColumn(1, "VID", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(2, "PID", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(3, "Manufacturer", LVCFMT_LEFT, 100);//插入列
		m_pListHidDev->InsertColumn(4, "Device Name", LVCFMT_LEFT, 120);//插入列
		m_pListHidDev->InsertColumn(5, "Device Serial No", LVCFMT_LEFT, 120);//插入列
		m_pListHidDev->InsertColumn(6, "Logged", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(7, "Actived", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(8, "Device Path", LVCFMT_LEFT, 150);//插入列
	}
	else
	{
		m_pListHidDev->InsertColumn(0, "Idx", LVCFMT_LEFT, 40);//插入列
		m_pListHidDev->InsertColumn(1, "VID", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(2, "PID", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(3, "制造商", LVCFMT_LEFT, 120);//插入列
		m_pListHidDev->InsertColumn(4, "设备名称", LVCFMT_LEFT, 120);//插入列
		m_pListHidDev->InsertColumn(5, "设备序列号", LVCFMT_LEFT, 120);//插入列
		m_pListHidDev->InsertColumn(6, "已登陆", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(7, "已激活", LVCFMT_LEFT, 50);//插入列
		m_pListHidDev->InsertColumn(8, "设备路径", LVCFMT_LEFT, 150);//插入列
	}

    m_pListLog->InsertColumn(0, "Index", LVCFMT_LEFT, 50);//插入列
    m_pListLog->InsertColumn(1, "Time", LVCFMT_LEFT, 100);//插入列
    m_pListLog->InsertColumn(2, "Level", LVCFMT_LEFT, 50);//插入列
    m_pListLog->InsertColumn(3, "Info", LVCFMT_LEFT, 500);//插入列
    
    GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
    GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
    GetDlgItem(IDC_CHK_INCLUDE_ALL)->ShowWindow(FALSE);
    GetDlgItem(IDC_CHK_SEPARATE)->ShowWindow(FALSE);

	if (g_bEnglish)
	{
		//m_tabMain.InsertItem(0, " G ");  //添加选项卡
		//m_tabMain.InsertItem(1, " D ");  //添加选项卡
		//m_tabMain.InsertItem(2, " M ");  //添加选项卡
		//m_tabMain.InsertItem(3, " C ");  //添加选项卡
		//m_tabMain.InsertItem(4, " A ");  //添加选项卡
		//m_tabMain.InsertItem(5, " T ");  //添加选项卡
		//m_tabMain.InsertItem(6, " U ");  //添加选项卡
		//m_tabMain.InsertItem(7, " C ");  //添加选项卡
		//m_tabMain.InsertItem(8, " Transmission Control ");  //添加选项卡

		m_tabMain.InsertItem(0, " General Interface ");  //添加选项卡
		m_tabMain.InsertItem(1, " Device Interface ");  //添加选项卡
		m_tabMain.InsertItem(2, " M1 Card Interface ");  //添加选项卡
		m_tabMain.InsertItem(3, " CPU//PSAM Card Interface ");  //添加选项卡
		m_tabMain.InsertItem(4, " Access Control Interface ");  //添加选项卡
		m_tabMain.InsertItem(5, " Thermal Camera ");  //添加选项卡
		m_tabMain.InsertItem(6, " USB Camera ");  //添加选项卡
		m_tabMain.InsertItem(7, " Camera Control ");  //添加选项卡
		m_tabMain.InsertItem(8, " Transmission Control ");  //添加选项卡
	}
	else
	{
		m_tabMain.InsertItem(0, " 通用接口 ");  //添加选项卡
		m_tabMain.InsertItem(1, " 设备接口 ");  //添加选项卡
		m_tabMain.InsertItem(2, " M1卡接口 ");  //添加选项卡
		m_tabMain.InsertItem(3, " CPU//PSAM卡接口 ");  //添加选项卡
		m_tabMain.InsertItem(4, " 门禁相关接口 ");  //添加选项卡
		m_tabMain.InsertItem(5, " 热成像相关接口 ");  //添加选项卡
		m_tabMain.InsertItem(6, " 前端相关接口 ");  //添加选项卡
		m_tabMain.InsertItem(7, " 相机控制 ");  //添加选项卡
		m_tabMain.InsertItem(8, " 传显相关接口 ");  //添加选项卡
	}
    if (g_bEnglish)
    {
        ((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString(_T("Authen"));
        ((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString(_T("Default"));
    }
    else
    {
        ((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString(_T("安全"));
        ((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString(_T("默认"));
    }

    m_combLoginMode.SetCurSel(0);

    //获得IDC_TAB_MAIN客户区大小 
    CRect rs;
    m_tabMain.GetClientRect(&rs); 
    //调整子对话框在父窗口中的位置 
    rs.top    +=20; 
    rs.bottom -=20; 
    rs.left   +=10; 
    rs.right  -=10; 

    m_dlgDev.Create(IDD_SUBDLG_DEV_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgDev.MoveWindow(&rs);
    m_dlgDev.ShowWindow(SW_SHOW);

    m_dlgGen.Create(IDD_SUBDLG_GEN_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgGen.MoveWindow(&rs);
    m_dlgGen.ShowWindow(SW_HIDE);

    m_dlgM1Card.Create(IDD_SUBDLG_M1_CARD_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgM1Card.MoveWindow(&rs);
    m_dlgM1Card.ShowWindow(SW_HIDE);

    m_dlgCpuPsamCard.Create(IDD_SUBDLG_CPU_PSAM_CARD_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgCpuPsamCard.MoveWindow(&rs);
    m_dlgCpuPsamCard.ShowWindow(SW_HIDE);

    m_dlgCertificateInfo.Create(IDD_SUBDLG_CERTIFICATE_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgCertificateInfo.MoveWindow(&rs);
    m_dlgCertificateInfo.ShowWindow(SW_HIDE);

    m_dlgThermal.Create(IDD_SUBDLG_THERMAL_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgThermal.MoveWindow(&rs);
    m_dlgThermal.ShowWindow(SW_HIDE);
    
    m_dlgCamera.Create(IDD_SUBDLG_CAMERA_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgCamera.MoveWindow(&rs);
    m_dlgCamera.ShowWindow(SW_HIDE);

	m_dlgCameraControl.Create(IDD_SUBDLG_CAMERA_CONTROL, GetDlgItem(IDC_TAB_MAIN));
	m_dlgCameraControl.MoveWindow(&rs);
	m_dlgCameraControl.ShowWindow(SW_HIDE);

    m_dlgTransmission.Create(IDD_SUBDLG_TRANSMISSION_INTERFACE, GetDlgItem(IDC_TAB_MAIN));
    m_dlgTransmission.MoveWindow(&rs);
    m_dlgTransmission.ShowWindow(SW_HIDE);

    m_tabMain.SetCurSel(0);

	if (g_bEnglish)
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "Set Log Path [%s]", szLogPath);
	}
	else
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "设置日志目录为 [%s]", szLogPath);
	}

    DWORD dwVersion = USB_GetSDKVersion();
    m_csSDKVersion.Format("HCUsbSDK V%d.%d.%d.%d", (0xff000000 & dwVersion)>>24, (0x00ff0000 & dwVersion)>>16,\
        (0x0000ff00 & dwVersion)>>8, (0x000000ff & dwVersion));//%.d,0x0000ff & dwVersion,build NO. do not expose
    
	if (g_bEnglish)
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "Get SDK Version USB_GetSDKVersion() Return = [0x%08X]", dwVersion);
	}
	else
	{
		LOGIN_INFO->WriteLog(INF_LEVEL, "获取SDK版本 USB_GetSDKVersion() 返回值 = [0x%08X]", dwVersion);
	}

    GetVersionInfor();

    //注册HID设备事件监听 
    DEV_BROADCAST_DEVICEINTERFACE Filter = {0};
    Filter.dbcc_size = sizeof(Filter);   // size gets set to 29 with 1-byte packing or 32 with 4- or 8-byte packing  
    Filter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;  
    //memcpy( &(Filter.dbcc_classguid), &(GUID_CLASS_USB_DEVICE), sizeof(struct _GUID));
    
    GUID struHidGUID = {0};
    HidD_GetHidGuid(&struHidGUID);
    memcpy(&(Filter.dbcc_classguid), &(struHidGUID), sizeof(struct _GUID));
    
    m_hDeviceNotify = RegisterDeviceNotification(this->m_hWnd, &Filter, DEVICE_NOTIFY_ALL_INTERFACE_CLASSES);  
    if(m_hDeviceNotify == NULL) 
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "Failed RegisterDeviceNotification()");
    }

    UpdateData(FALSE);
    
    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialog::OnSysCommand(nID, lParam);
    }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDemoDlg::OnPaint() 
{

	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_V1);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_SDKV);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_USERINFO);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_USER_NAME);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_PW);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_CHK_INCLUDE_ALL);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_BTN_ENUM_HID);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_CHK_SEPARATE);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_BTN_LOGIN);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_BTN_LOGOUT);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_BTN_ACTIVE);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_BTN_SET_USER_DATA);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_DEVICE_INFO);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_DEVICE_NAME);
	SET_CONTROL_LAN(IDD_DLG_CLIENT_DEMO, IDC_STATIC_DEVICE_SERIAL);

    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialog::OnPaint();
    }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDemoDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CClientDemoDlg::AddNewDevInfo(USB_DEVICE_INFO *lpUsbDevInfo)
{
    //memcpy(&m_aHidDevInfo[m_nHidDevNum], lpUsbDevInfo, sizeof(USB_DEVICE_INFO));
    //m_nHidDevNum++;
}

BOOL CClientDemoDlg::isLogon(USB_DEVICE_INFO *pDevceInfo)
{
    for (auto dev:m_mLogonDev)
    {
        USB_DEVICE_INFO struDev = dev.second;
        if (struDev.dwPID == pDevceInfo->dwPID &&
            struDev.dwVID == pDevceInfo->dwVID &&
            !strcmp(struDev.szSerialNumber, pDevceInfo->szSerialNumber) &&
            !strcmp(struDev.szDeviceName, pDevceInfo->szDeviceName))
        {
            return TRUE;
        }
    }

    return FALSE;
}

BOOL CClientDemoDlg::isSame(USB_DEVICE_INFO *pDevceInfo)
{
    if (m_struCurDeviceInfo.dwPID == pDevceInfo->dwPID &&
        m_struCurDeviceInfo.dwVID == pDevceInfo->dwVID &&
        !strcmp(m_struCurDeviceInfo.szSerialNumber, pDevceInfo->szSerialNumber) &&
        !strcmp(m_struCurDeviceInfo.szDeviceName, pDevceInfo->szDeviceName))
    {
        return TRUE;
    }

    return FALSE;
}

void CClientDemoDlg::OnBtnEnumHid() 
{
	// TODO: Add your control notification handler code here

	//增加设置vid PId的代码
	USB_LOCAL_GUID guid = {0};
	guid.ulPID = 0x017F;
	guid.ulVID = 0x2BDF;
	guid.struGuid = { 0x9A1e7291, 0x6843, 0x4683, { 0x6d, 0x92, 0x39, 0xbc, 0x79, 0x06, 0xEE, 0x49 } };
	USB_SetSDKLocalCfg(ENUM_LOCAL_CFG_TYPE_GUID, &guid);

	USB_LOCAL_GUID guid1 = { 0 };
    guid1.ulPID = 0x5842;
    guid1.ulVID = 0x0BDA;
    guid1.struGuid = { 0x9A1e7211, 0x6813, 0x4683, { 0x6d, 0x92, 0x39, 0xbc, 0x79, 0x06, 0xEE, 0x49 } };
    USB_SetSDKLocalCfg(ENUM_LOCAL_CFG_TYPE_GUID, &guid1);

    m_nHidDevNum = 0;
    memset(m_aHidDevInfo, 0, sizeof(m_aHidDevInfo));

    // 先清空List
    g_nEnumDevIndex = 1;
    m_pListHidDev->DeleteAllItems();

    m_nHidDevNum = USB_GetDeviceCount();
    /*USB_GET_DEVICE_COUNT_INFO struGetDeivceCountInfo = { 0 };
    struGetDeivceCountInfo.byIncludeAll = m_btnIncludeAll.GetCheck();
    struGetDeivceCountInfo.bySeparate = m_btnSeparate.GetCheck();
    m_nHidDevNum = USB_GetDeviceCountEx(&struGetDeivceCountInfo);*/
    if (m_nHidDevNum > 0)
    {
        if (USB_EnumDevices(m_nHidDevNum, &m_aHidDevInfo[0]))
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_EnumDevices()");
        }
        else
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_EnumDevices()");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceCountEx()");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }

    for (int i = 0; i < m_nHidDevNum; i++)
    {
        OnEnumDeviceCallBack(&m_aHidDevInfo[i], this);
    }
}

void CClientDemoDlg::OnBtnLogin() 
{
    // TODO: Add your control notification handler code here
    
    UpdateData(TRUE);

    if (m_csUserName.GetLength() > MAX_USERNAME_LEN)
    {
        if (g_bEnglish)
        {
            MessageBox("User Name Len Cannot Exceed 32 Bits!");
        }
        else
        {
            MessageBox("用户名长度不可超过32位!");
        }
        return;
    }

    if (m_csPassword.GetLength() > MAX_PASSWORD_LEN)
    {
        if (g_bEnglish)
        {
            MessageBox("Password Len Cannot Exceed 16 Bits!");
        }
        else
        {
            MessageBox("密码长度不可超过16位!");
        }
        return;
    }

    char szUserName[MAX_USERNAME_LEN] = {0};
    char szPassword[MAX_PASSWORD_LEN] = {0};

    CSTRING_TO_CHARS(m_csUserName, szUserName);
    CSTRING_TO_CHARS(m_csPassword, szPassword);

    USB_DEVICE_INFO struUsbDeviceInfo = {0};
    struUsbDeviceInfo.dwSize = sizeof(USB_DEVICE_INFO);
    memcpy(&struUsbDeviceInfo, &m_aHidDevInfo[m_nHidIndex], sizeof(USB_DEVICE_INFO));

    memset(&m_struCurUsbLoginInfo, 0, sizeof(m_struCurUsbLoginInfo));
    m_struCurUsbLoginInfo.dwSize = sizeof(USB_USER_LOGIN_INFO);
    m_struCurUsbLoginInfo.dwTimeout = 5000;//登录超时时间(5秒)
    m_struCurUsbLoginInfo.dwVID = struUsbDeviceInfo.dwVID;
    m_struCurUsbLoginInfo.dwPID = struUsbDeviceInfo.dwPID;

    memcpy(m_struCurUsbLoginInfo.szSerialNumber, struUsbDeviceInfo.szSerialNumber, MAX_SERIAL_NUMBER_LEN);
    memcpy(m_struCurUsbLoginInfo.szUserName, szUserName, strlen(szUserName));
    memcpy(m_struCurUsbLoginInfo.szPassword, szPassword, strlen(szPassword));

    //memcpy(m_struCurUsbLoginInfo.szUserName, "admin", strlen("admin"));
    //memcpy(m_struCurUsbLoginInfo.szPassword, "12345", strlen("12345"));

    m_struCurUsbLoginInfo.byLoginMode = m_combLoginMode.GetCurSel();
    m_struCurUsbLoginInfo.dwDevIndex = struUsbDeviceInfo.dwIndex;

    USB_DEVICE_REG_RES struDeviceRegRes = {0};
    struDeviceRegRes.dwSize = sizeof(struDeviceRegRes);

    LONG lUserIDTemp = m_lUserID;

    m_lUserID = USB_Login(&m_struCurUsbLoginInfo, &struDeviceRegRes);

    CString csInfo;
    DWORD dwErrorCode = USB_SUCCESS;
    if (m_lUserID == USB_INVALID_USERID)
    {
        dwErrorCode = USB_GetLastError();
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "Login Device Failed! ErrorCode = [%d], ErrorMsg = [%s]", dwErrorCode, USB_GetErrorMsg(dwErrorCode));
		}
		else
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "登录设备失败! ErrorCode = [%d], ErrorMsg = [%s]", dwErrorCode, USB_GetErrorMsg(dwErrorCode));
		}

        char szLan[1024] = { 0 };
		if (dwErrorCode == USB_ERROR_INACTIVED)
		{
			if (g_bEnglish)
			{
				AfxMessageBox("LOGIN ERROR：Please active the device");
			}
			else
			{
				AfxMessageBox("登陆错误：请先激活设备");
			}
            m_pListHidDev->SetItemText(m_nHidIndex, 7, "no");   //激活状态
        }

        if (dwErrorCode == USB_ERROR_DEV_PASSWORD_ERROR)
        {
			if (g_bEnglish)
			{
				sprintf(szLan, "user name or password error!Remain %d try times", struDeviceRegRes.byRetryLoginTimes);
				AfxMessageBox(szLan);
			}
			else
			{
				sprintf(szLan, "用户名密码错误!还剩%d尝试机会", struDeviceRegRes.byRetryLoginTimes);
				AfxMessageBox(szLan);
			}
        }

        if (dwErrorCode == USB_ERROR_DEV_USER_LOCKED)
        {
			if (g_bEnglish)
			{
				sprintf(szLan, "User locked, keep locked time:%d second", struDeviceRegRes.dwSurplusLockTime);
				AfxMessageBox(szLan);
			}
			else
			{
				sprintf(szLan, "用户被锁定，剩余锁定时间%d秒", struDeviceRegRes.dwSurplusLockTime);
				AfxMessageBox(szLan);
			}
        }

        GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(TRUE);
        GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);

        memset(&m_struCurUsbLoginInfo, 0, sizeof(m_struCurUsbLoginInfo));
        memset(&m_struCurDeviceInfo, 0, sizeof(m_struCurDeviceInfo));

        m_lUserID = lUserIDTemp; // 解决重复登录时，导致的UserID无效问题
    }
    else
    {
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "Login Device Success! UserID = [%d]", m_lUserID);
		}
		else
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "登录设备成功! UserID = [%d]", m_lUserID);
		}
        GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
        GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(TRUE);

        DWORD dwMajor = ((struDeviceRegRes.dwSoftwareVersion & 0xff000000) >> 24);
        DWORD dwMinor = ((struDeviceRegRes.dwSoftwareVersion & 0x00ff0000) >> 16);
        DWORD dwRevise = (struDeviceRegRes.dwSoftwareVersion & 0x0000ffff);

		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "Device Register Info:\r\n Device Name:%s\r\n Device Serial No:%s\r\n Software Version:0x%X V%d.%d.%d_build%04d%02d%02d",
				struDeviceRegRes.szDeviceName,
				struDeviceRegRes.szSerialNumber,
				struDeviceRegRes.dwSoftwareVersion,
				dwMajor,
				dwMinor,
				dwRevise,
				struDeviceRegRes.wYear,
				struDeviceRegRes.byMonth,
				struDeviceRegRes.byDay);
		}
		else
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "设备注册信息:\r\n 设备名称:%s\r\n 设备序列号:%s\r\n 软件版本号:0x%X V%d.%d.%d_build%04d%02d%02d",
				struDeviceRegRes.szDeviceName,
				struDeviceRegRes.szSerialNumber,
				struDeviceRegRes.dwSoftwareVersion,
				dwMajor,
				dwMinor,
				dwRevise,
				struDeviceRegRes.wYear,
				struDeviceRegRes.byMonth,
				struDeviceRegRes.byDay);
		}


        UpdateUserID();
        memcpy(&m_struCurDeviceInfo, &(m_aHidDevInfo[m_nHidIndex]), sizeof(m_struCurDeviceInfo));

        m_mLogonDev.insert(std::make_pair(m_lUserID, m_struCurDeviceInfo));
        m_LogonIdx.push_back(m_lUserID);

        m_pListHidDev->SetItemText(m_nHidIndex, 6, "yes");   //登陆状态
        m_pListHidDev->SetItemText(m_nHidIndex, 7, "yes");   //激活状态

    }	
}

void CClientDemoDlg::UpdateUserID()
{
    m_dlgDev.m_lUserID = m_lUserID;
    m_dlgGen.m_lUserID = m_lUserID;
    m_dlgM1Card.m_lUserID = m_lUserID;
    m_dlgCpuPsamCard.m_lUserID = m_lUserID;
    m_dlgCertificateInfo.m_lUserID = m_lUserID;
    m_dlgThermal.m_lUserID = m_lUserID;
    m_dlgCamera.m_handle = m_lUserID;
    m_dlgCamera.UpdateAudio(TRUE);
	m_dlgCameraControl.m_lUserID = m_lUserID;
    m_dlgTransmission.m_lUserID = m_lUserID;
}


void CClientDemoDlg::OnBtnLogout() 
{
    // TODO: Add your control notification handler code here
    for (auto it = m_LogonIdx.begin(); it != m_LogonIdx.end();)
    {
        if (*it == m_lUserID)
            it = m_LogonIdx.erase(it);
        else
            it++;
    }
    m_mLogonDev.erase(m_lUserID);

    if (USB_Logout(m_lUserID))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_Logout()");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_Logout()");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }   
    m_pListHidDev->SetItemText(m_nHidIndex, 6, "no");   //登陆状态
}

void CClientDemoDlg::OnDestroy() 
{
    CDialog::OnDestroy();
    
    // TODO: Add your message handler code here
    USB_Cleanup();
    
}

void CClientDemoDlg::OnItemchangedLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
    NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
    // TODO: Add your control notification handler code here
    
    *pResult = 0;
}

void CClientDemoDlg::OnClickLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult) 
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
                GetDlgItem(IDC_BTN_ACTIVE)->EnableWindow(TRUE);
                m_csDeviceName   = m_aHidDevInfo[m_nHidIndex].szDeviceName;
                m_csSerialNumber = m_aHidDevInfo[m_nHidIndex].szSerialNumber;
                m_pListHidDev->SetSelectionMark(m_nHidIndex);
                std::for_each(m_LogonIdx.begin(), m_LogonIdx.end(), [this](DWORD dwUserID){
                    auto itr = m_mLogonDev.find(dwUserID);
                    if (itr != m_mLogonDev.end())
                    {
                        m_struCurDeviceInfo = itr->second;
                        if (isSame(&m_aHidDevInfo[m_nHidIndex]))
                        {
                            m_lUserID = dwUserID;
                            m_pListHidDev->SetItemText(m_nHidIndex, 6, "yes");   //登陆状态
                            m_pListHidDev->SetItemText(m_nHidIndex, 7, "yes");   //激活状态
                            UpdateUserID();
                            return;
                        }
                    }
                });
                m_struCurDeviceInfo = m_aHidDevInfo[m_nHidIndex];
            }
        }
        else
        {
            GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
            GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
            GetDlgItem(IDC_BTN_ACTIVE)->EnableWindow(FALSE);
            m_csDeviceName   = _T("");
            m_csSerialNumber = _T("");
        }
    }
    else
    {
        GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
        GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
        GetDlgItem(IDC_BTN_ACTIVE)->EnableWindow(FALSE);
        m_csDeviceName   = _T("");
        m_csSerialNumber = _T("");
    }

    UpdateData(FALSE);
    
    *pResult = 0;
}


void CClientDemoDlg::OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult)
{
    // TODO: Add your control notification handler code here
    //得到新的页面索引
    DWORD dwCurSel = m_tabMain.GetCurSel();
    if (dwCurSel == 0)
    {
        m_dlgDev.ShowWindow(SW_SHOW);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 1)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_SHOW);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 2)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_SHOW);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 3)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_SHOW);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 4)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_SHOW);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 5)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_SHOW);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 6)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_SHOW);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 7)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_SHOW);
        m_dlgTransmission.ShowWindow(SW_HIDE);
    }
    else if (dwCurSel == 8)
    {
        m_dlgDev.ShowWindow(SW_HIDE);
        m_dlgGen.ShowWindow(SW_HIDE);
        m_dlgM1Card.ShowWindow(SW_HIDE);
        m_dlgCpuPsamCard.ShowWindow(SW_HIDE);
        m_dlgCertificateInfo.ShowWindow(SW_HIDE);
        m_dlgThermal.ShowWindow(SW_HIDE);
        m_dlgCamera.ShowWindow(SW_HIDE);
        m_dlgCameraControl.ShowWindow(SW_HIDE);
        m_dlgTransmission.ShowWindow(SW_SHOW);
    }
    *pResult = 0;
}

void CClientDemoDlg::OnBtnSetUserData() 
{
    // TODO: Add your control notification handler code here

    UpdateData(TRUE);	
}


typedef DWORD (WINAPI *VGetFileVersionInfoSize)(LPSTR lptstrFilename, LPDWORD lpdwHandle);  
typedef BOOL (WINAPI *VGetFileVersionInfo)(LPSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData);
typedef BOOL(WINAPI *VVerQueryValue)(const LPVOID pBlock,LPSTR lpSubBlock,LPVOID * lplpBuffer, PUINT puLen);
VGetFileVersionInfoSize vgetsize;
VGetFileVersionInfo vfileinfo;
VVerQueryValue vqureyvalue;

void CClientDemoDlg::GetVersionInfor()
{
    DWORD m_dwSize = 0;
    HMODULE handle = LoadLibrary("version.dll"); //there is no this library on win2000

    if (handle == NULL)
    {
        return;
    }

    vgetsize = (VGetFileVersionInfoSize)GetProcAddress(handle, "GetFileVersionInfoSizeA");
    m_dwSize = GetLastError();
    vfileinfo = (VGetFileVersionInfo)GetProcAddress(handle, "GetFileVersionInfoA");
    vqureyvalue = (VVerQueryValue)GetProcAddress(handle, "VerQueryValueA");

    char szInfo[128] = {0};
    m_dwSize = vgetsize("HCUSBSDK.dll", NULL);
    char * m_lpBuffer = NULL;

    CString szBuild;

    if (m_dwSize > 0)
    {
        m_lpBuffer = new char[m_dwSize];
        char *lpSDKVersion = NULL;    
        //Get   the   versioninformation   block   
        BOOL bRet = vfileinfo("HCUSBSDK.dll", 0, m_dwSize, m_lpBuffer);   
        
        struct LANGANDCODEPAGE {
            WORD wLanguage;
            WORD wCodePage;
        } *lpTranslate;
        DWORD cbTranslate = 0;
        vqureyvalue(m_lpBuffer, 
            TEXT("\\VarFileInfo\\Translation"),
            (LPVOID*)&lpTranslate,
            (PUINT)&cbTranslate);
        wsprintf(szInfo, TEXT( "\\StringFileInfo\\%04x%04x\\FileVersion"), 
            lpTranslate-> wLanguage, 
            lpTranslate-> wCodePage); 
        
        bRet = vqureyvalue(m_lpBuffer,   
            szInfo,   
            (void **) &lpSDKVersion,   
            NULL); 
        char * m_lpSDKBuild = NULL;
        wsprintf(szInfo, TEXT( "\\StringFileInfo\\%04x%04x\\FileDescription"), 
            lpTranslate-> wLanguage, 
            lpTranslate-> wCodePage); 
        bRet = vqureyvalue(m_lpBuffer,   
            szInfo,  
            (void **) &m_lpSDKBuild,   
            NULL);   

        szBuild.Format("V%s %s", lpSDKVersion, m_lpSDKBuild);
        GetDlgItem(IDC_STA_SDK_BUILDER_VER)->SetWindowText(szBuild);
        
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "HCUsbSDK Builder Info = [%s]", szBuild);
		}
		else
		{
			LOGIN_INFO->WriteLog(INF_LEVEL, "HCUsbSDK Builder信息 = [%s]", szBuild);
		}

    }
    else
    {
        m_dwSize = GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "获取HCUsbSDK Builder信息失败!");
    }

    if (m_lpBuffer != NULL)
    {
        delete[] m_lpBuffer;
        m_lpBuffer = NULL;
    }
    FreeLibrary(handle);
}

DWORD g_dwStartTime = 0;
DWORD g_dwEndTime   = 0;

BOOL CClientDemoDlg::OnDeviceChange(UINT nEventType, DWORD_PTR dwData)
{
    g_dwEndTime = GetTickCount();

    if (g_bUpgrade)
    {
        return FALSE;
    }

	switch (nEventType)  
	{  
    case DBT_DEVICEREMOVECOMPLETE://移除设备
        //if ((g_dwEndTime - g_dwStartTime) > 1000)
        {
            g_dwStartTime = g_dwEndTime;
			if (g_bEnglish)
			{
				LOGIN_INFO->WriteLog(INF_LEVEL, "Device has been removed!");
			}
			else
			{
				LOGIN_INFO->WriteLog(INF_LEVEL, "有设备移除!");
			}
            OnBtnEnumHid();
            int i = 0;
            for (i = 0; i < m_nHidDevNum; i++)
            {
                if (m_struCurDeviceInfo.dwVID == m_aHidDevInfo[i].dwVID && m_struCurDeviceInfo.dwPID == m_aHidDevInfo[i].dwPID)
                {
                    if (strcmp(m_struCurDeviceInfo.szSerialNumber, m_aHidDevInfo[i].szSerialNumber) == 0)
                    {
                        m_nHidIndex = i;
                        break;
                    }                 
                }
            }
            if (i == m_nHidDevNum && m_lUserID != USB_INVALID_USERID)
            {
                USB_Logout(m_lUserID);
                m_lUserID = USB_INVALID_USERID;
                m_nHidIndex = -1; 
				if (g_bEnglish)
				{
					LOGIN_INFO->WriteLog(INF_LEVEL, "Logout this device!");
				}
				else
				{
					LOGIN_INFO->WriteLog(INF_LEVEL, "注销该设备!");
				}
                break;
            }        
        }
        
	    break;
    case DBT_DEVICEARRIVAL://添加设备
        //if ((g_dwEndTime - g_dwStartTime) > 1000)
        {
            g_dwStartTime = g_dwEndTime;
			if (g_bEnglish)
			{
				LOGIN_INFO->WriteLog(INF_LEVEL, "Device has been inserted!");
			}
			else
			{
				LOGIN_INFO->WriteLog(INF_LEVEL, "有设备接入!");
			}
            OnBtnEnumHid();
        }
            
	    break; 
    default:  
	    break;  
    }

	return FALSE;  
}

LRESULT CClientDemoDlg::OnWMAddLog(WPARAM wParam, LPARAM lParam)
{
    //EnterCriticalSection(&g_cs);

    WaitForSingleObject(g_mutex, INFINITE);

    if (m_pListLog->GetItemCount() >= 1024)
    {
        m_pListLog->DeleteAllItems();
	}

    LPLOCAL_LOG_INFO pLogInfo = LPLOCAL_LOG_INFO(lParam);
    if (NULL == pLogInfo)
    {
        //LeaveCriticalSection(&g_cs);
        ::ReleaseMutex(g_mutex);

        return 0;
	}

    CString csInfoTemp;

    csInfoTemp.Format("%d", m_nLogIndex);

    int nRow = m_pListLog->InsertItem(m_nLogIndex, csInfoTemp);//插入行

    csInfoTemp = pLogInfo->szTime;

    m_pListLog->SetItemText(nRow, 1, csInfoTemp);
    
    csInfoTemp = gLEVEL_TEXT[pLogInfo->iLogType];
    m_pListLog->SetItemText(nRow, 2, csInfoTemp);
    
    csInfoTemp = pLogInfo->szLogInfo;
    m_pListLog->SetItemText(nRow, 3, csInfoTemp);
    
    int nCount = m_pListLog->GetItemCount();
    if (nCount > 0)
    {
        m_pListLog->EnsureVisible(nCount-1, FALSE); 
    }

    if (pLogInfo != NULL)
    {
        delete pLogInfo;
        pLogInfo = NULL;
    }

    m_nLogIndex++;

    //LeaveCriticalSection(&g_cs);
    ::ReleaseMutex(g_mutex);

	return 0;
}



void CClientDemoDlg::OnBnClickedBtnActive()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);
    char szUserName[MAX_USERNAME_LEN] = { 0 };
    char szPassword[MAX_PASSWORD_LEN] = { 0 };

    CSTRING_TO_CHARS(m_csUserName, szUserName);
    CSTRING_TO_CHARS(m_csPassword, szPassword);

    USB_DEVICE_INFO struUsbDeviceInfo = { 0 };
    struUsbDeviceInfo.dwSize = sizeof(USB_DEVICE_INFO);
    memcpy(&struUsbDeviceInfo, &m_aHidDevInfo[m_nHidIndex], sizeof(USB_DEVICE_INFO));

    memset(&m_struCurUsbLoginInfo, 0, sizeof(m_struCurUsbLoginInfo));
    m_struCurUsbLoginInfo.dwSize = sizeof(USB_USER_LOGIN_INFO);
    m_struCurUsbLoginInfo.dwTimeout = 5000;//登录超时时间(5秒)
    m_struCurUsbLoginInfo.dwVID = struUsbDeviceInfo.dwVID;
    m_struCurUsbLoginInfo.dwPID = struUsbDeviceInfo.dwPID;

    memcpy(m_struCurUsbLoginInfo.szSerialNumber, struUsbDeviceInfo.szSerialNumber, MAX_SERIAL_NUMBER_LEN);
    memcpy(m_struCurUsbLoginInfo.szUserName, szUserName, MAX_USERNAME_LEN);
    memcpy(m_struCurUsbLoginInfo.szPassword, szPassword, MAX_PASSWORD_LEN);

    USB_DEVICE_REG_RES struDeviceRegRes = { 0 };
    struDeviceRegRes.dwSize = sizeof(struDeviceRegRes);

    BOOL bRet = USB_Active(&m_struCurUsbLoginInfo);
    DWORD dwErrorCode = USB_SUCCESS;
    if (!bRet)
    {
        dwErrorCode = USB_GetLastError();
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "Active Device Failed! ErrorCode = [%d], ErrorMsg = [%s]", dwErrorCode, USB_GetErrorMsg(dwErrorCode));
		}
		else
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "激活设备失败! ErrorCode = [%d], ErrorMsg = [%s]", dwErrorCode, USB_GetErrorMsg(dwErrorCode));
		}
        m_pListHidDev->SetItemText(m_nHidIndex, 7, "no");   //激活状态
        return;
    }

    m_pListHidDev->SetItemText(m_nHidIndex, 7, "yes");   //激活状态
    return;
}

DWORD CClientDemoDlg::GetActiveStatus(USB_DEVICE_INFO *pDevceInfo)
{
    UpdateData(TRUE);

    USB_USER_LOGIN_INFO struCurUsbLoginInfo = { 0 };
    memset(&struCurUsbLoginInfo, 0, sizeof(struCurUsbLoginInfo));
    struCurUsbLoginInfo.dwSize = sizeof(USB_USER_LOGIN_INFO);
    struCurUsbLoginInfo.dwTimeout = 5000;//登录超时时间(5秒)
    struCurUsbLoginInfo.dwVID = pDevceInfo->dwVID;
    struCurUsbLoginInfo.dwPID = pDevceInfo->dwPID;

    memcpy(struCurUsbLoginInfo.szSerialNumber, pDevceInfo->szSerialNumber, MAX_SERIAL_NUMBER_LEN);

    USB_ACTIVE_STATUS struStatus = { 0 };
    struStatus.dwSize = sizeof(struStatus);

    BOOL bRet = USB_GetActiveStatus(&struCurUsbLoginInfo, &struStatus);
    DWORD dwErrorCode = USB_SUCCESS;
    if (!bRet)
    {
        dwErrorCode = USB_GetLastError();
		if (g_bEnglish)
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "Get Active Status Failed! ErrorCode = [%d], ErrorMsg = [%s]", dwErrorCode, USB_GetErrorMsg(dwErrorCode));
		}
		else
		{
			LOGIN_INFO->WriteLog(ERR_LEVEL, "获取激活状态失败! ErrorCode = [%d], ErrorMsg = [%s]", dwErrorCode, USB_GetErrorMsg(dwErrorCode));
		}
        return 0;
    }

    return (struStatus.byState + 1);
}


