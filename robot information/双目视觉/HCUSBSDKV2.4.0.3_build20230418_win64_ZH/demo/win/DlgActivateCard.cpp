// DlgActivateCard.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgActivateCard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgActivateCard dialog

#ifdef SWITCH_ENGLISH_US
const char* aCardProto[] = {"0-TypeA M1 Card", "1-TypeA CPU Card", "2-TypeB", "3-125KHz ID Card", "4-Felica Card", "5-Desfire Card"};
#else
const char* aCardProto[] = { "0-TypeA M1卡", "1-TypeA CPU卡", "2-TypeB", "3-125KHz ID卡", "4-Felica卡", "5-Desfire卡" };
#endif

CDlgActivateCard::CDlgActivateCard(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgActivateCard::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgActivateCard)
        // NOTE: the ClassWizard will add member initialization here
    m_dwWaitSecond = 5;
    m_dwSerialLen = 0;
    m_dwSelVerifyLen = 0;
    m_handle = 0;
    m_iStopButton = 0;
    memset(&m_struWaitSecond, 0, sizeof(m_struWaitSecond));
    memset(&m_struActivateRes, 0, sizeof(m_struActivateRes));
    memset(&m_struInput, 0, sizeof(m_struInput));
    memset(&m_struOutput, 0, sizeof(m_struOutput));
    //}}AFX_DATA_INIT
}


void CDlgActivateCard::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgActivateCard)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_WAIT_SECOND, m_dwWaitSecond);
    DDX_Text(pDX, IDC_STA_CARD_PROTO, m_csCardProto);
    DDX_Text(pDX, IDC_STA_SERIAL_LEN, m_dwSerialLen);
    DDX_Text(pDX, IDC_STA_SERIAL, m_csSerial);
    DDX_Text(pDX, IDC_STA_SEL_VERIFY_LEN, m_dwSelVerifyLen);
    DDX_Text(pDX, IDC_STA_SEL_VERIFY, m_csSelVerify);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgActivateCard, CDialog)
    //{{AFX_MSG_MAP(CDlgActivateCard)
    ON_BN_CLICKED(IDC_BTN_ACTIVATE, OnBtnActivate)
	ON_BN_CLICKED(IDC_BTN_ACTIVATE2, OnBtnActivate2)
	ON_BN_CLICKED(IDC_BTN_STOP_ACTIVATE, OnBtnStopActivate)
	//}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgActivateCard message handlers

BOOL CDlgActivateCard::OnInitDialog()
{
    CDialog::OnInitDialog(); 
    
    UpdateData(FALSE);
    
    return TRUE;
    
}

void CDlgActivateCard::OnBtnActivate() 
{
    // TODO: Add your control notification handler code here

    //for (int i = 0; i < 128; i++)
    
    {

    UpdateData(TRUE);

    if (m_dwWaitSecond < 0 || m_dwWaitSecond > 255)
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("operate timeout range:0(include)-255(include), 0 present wait until read card");        
#else
        MessageBox("操作等待时间的范围为0(含)-255(含), 0表示一直执行，直到有卡响应");        
#endif
        return;
    }

    USB_WAIT_SECOND struWaitSecond = {0};
    struWaitSecond.dwSize = sizeof(USB_WAIT_SECOND);
    struWaitSecond.byWait = (BYTE)m_dwWaitSecond;

    USB_ACTIVATE_CARD_RES struActivateRes = {0};
    struActivateRes.dwSize = sizeof(USB_ACTIVATE_CARD_RES);
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struWaitSecond);
    struInput.lpInBuffer = &struWaitSecond;
    
    USB_CONFIG_OUTPUT_INFO struOutput = {0};
    struOutput.dwOutBufferSize = sizeof(struActivateRes);
    struOutput.lpOutBuffer = &struActivateRes;

    if (USB_GetDeviceConfig(m_lUserID, USB_GET_ACTIVATE_CARD, &struInput, &struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_ACTIVATE_CARD");
        {
            //LOGIN_INFO->WriteLog(INF_LEVEL, "激活卡成功!");
            //卡类型
            m_csCardProto.Format("%s", aCardProto[struActivateRes.byCardType]);

            //序列号
            m_dwSerialLen = struActivateRes.bySerialLen;
            CString csTemp;
            m_csSerial = _T("");
            for (DWORD i = 0; i < m_dwSerialLen; i++)
            {
                csTemp.Format("%02X", (unsigned char)struActivateRes.bySerial[i]);
                m_csSerial += csTemp + _T(" ");
            }

            m_dwSelVerifyLen = struActivateRes.bySelectVerifyLen;

            m_csSelVerify.Format("%2X  %2X  %2X", struActivateRes.bySelectVerify[0], 
                                                       struActivateRes.bySelectVerify[1],
                                                       struActivateRes.bySelectVerify[2]);

            UpdateData(FALSE);
        }
    }
    else
    {
        CString csInfo;
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_ACTIVATE_CARD");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    }
}

void CDlgActivateCard::OnBtnActivate2() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    if (m_dwWaitSecond < 0 || m_dwWaitSecond > 255)
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("operate timeout range:0(include)-255(include), 0 present wait until read card");        
#else
        MessageBox("操作等待时间的范围为0(含)-255(含), 0表示一直执行，直到有卡响应");        
#endif
        return;
    }

    if (m_handle > 0)
    {
#ifdef SWITCH_ENGLISH_US
        LOGIN_INFO->WriteLog(INF_LEVEL, "Please stop circulate activate first!");        
#else
        LOGIN_INFO->WriteLog(INF_LEVEL, "请先停止循环激活操作!");        
#endif        
        return;
    }
    
    memset(&m_struWaitSecond, 0, sizeof(m_struWaitSecond));
    memset(&m_struActivateRes, 0, sizeof(m_struActivateRes));
    memset(&m_struInput, 0, sizeof(m_struInput));
    memset(&m_struOutput, 0, sizeof(m_struOutput));

    m_struWaitSecond.dwSize = sizeof(USB_WAIT_SECOND);
    m_struWaitSecond.byWait = (BYTE)m_dwWaitSecond;
    
    m_struActivateRes.dwSize = sizeof(USB_ACTIVATE_CARD_RES);
    
    m_struInput.dwInBufferSize = sizeof(m_struWaitSecond);
    m_struInput.lpInBuffer = &m_struWaitSecond;
    
    m_struOutput.dwOutBufferSize = sizeof(m_struActivateRes);
    m_struOutput.lpOutBuffer = &m_struActivateRes;
    
    if (USB_GetDeviceConfig(m_lUserID, USB_GET_ACTIVATE_CARD, &m_struInput, &m_struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_ACTIVATE_CARD");
        {
            //LOGIN_INFO->WriteLog(INF_LEVEL, "激活卡成功!");
            //卡类型
            m_csCardProto.Format("%s", aCardProto[m_struActivateRes.byCardType]);
                
            //序列号
            m_dwSerialLen = m_struActivateRes.bySerialLen;
            CString csTemp;
            m_csSerial = _T("");
            for (DWORD i = 0; i < m_dwSerialLen; i++)
            {
                csTemp.Format("%02X", (unsigned char)m_struActivateRes.bySerial[i]);
                m_csSerial += csTemp + _T(" ");
            }
                
            m_dwSelVerifyLen = m_struActivateRes.bySelectVerifyLen;
                
            m_csSelVerify.Format("%2X  %2X  %2X", m_struActivateRes.bySelectVerify[0], 
                m_struActivateRes.bySelectVerify[1],
                m_struActivateRes.bySelectVerify[2]);
                
            UpdateData(FALSE);
        }
    }
    else
    {
        CString csInfo;
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_ACTIVATE_CARD");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }

    m_iStopButton = 0;
    m_handle = (HANDLE)CreateThread(NULL, 0, CircleActivateThread, (LPVOID)this, 0, NULL);
}

void CDlgActivateCard::OnBtnStopActivate() 
{
	// TODO: Add your control notification handler code here
    m_iStopButton = 1;
    
    CloseHandle(m_handle);
    m_handle = 0;
	return;
}

// 子线程：循环激活
DWORD WINAPI CDlgActivateCard::CircleActivateThread(LPVOID pM)
{
    CDlgActivateCard *pActivate = (CDlgActivateCard *)pM;
    
    int iErrorNo = 0;
    
    while (pActivate->m_iStopButton == 0)
    {
        USB_WAIT_SECOND struWaitSecond = { 0 };
        struWaitSecond.dwSize = sizeof(USB_WAIT_SECOND);
        struWaitSecond.byWait = 5;

        USB_ACTIVATE_CARD_RES struActivateRes = { 0 };
        struActivateRes.dwSize = sizeof(USB_ACTIVATE_CARD_RES);

        USB_CONFIG_INPUT_INFO struInput = { 0 };
        struInput.dwInBufferSize = sizeof(struWaitSecond);
        struInput.lpInBuffer = &struWaitSecond;

        USB_CONFIG_OUTPUT_INFO struOutput = { 0 };
        struOutput.dwOutBufferSize = sizeof(struActivateRes);
        struOutput.lpOutBuffer = &struActivateRes;

        if (USB_GetDeviceConfig(pActivate->m_lUserID, USB_GET_ACTIVATE_CARD, &struInput, &struOutput))
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "Error Times[%d] SUCCESS USB_GetDeviceConfig()  Command = USB_GET_ACTIVATE_CARD", iErrorNo);
        }
        else
        {
            if (USB_GetLastError() == USB_ERROR_RECV_PACK_TIMEOUT)
            {
                iErrorNo++;
            }
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_ACTIVATE_CARD");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }


        USB_CERTIFICATE_INFO struCertificateInfo = {0};
        struCertificateInfo.dwSize = sizeof(struCertificateInfo);
        
        USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
        struConfigOutputInfo.dwOutBufferSize = sizeof(struCertificateInfo);
        struConfigOutputInfo.lpOutBuffer = &struCertificateInfo;
        
        if (USB_GetDeviceConfig(pActivate->m_lUserID, USB_GET_CERTIFICATE_INFO, NULL, &struConfigOutputInfo))
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "Error Times[%d] SUCCESS USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_INFO", iErrorNo);
        }
        else
        {
            if (USB_GetLastError() == USB_ERROR_RECV_PACK_TIMEOUT)
            {
                iErrorNo++;
            }
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_INFO");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }


        USB_BEEP_AND_FLICKER struBeepAndFlicker = { 0 };
        struBeepAndFlicker.dwSize = sizeof(USB_BEEP_AND_FLICKER);
        struBeepAndFlicker.byBeepType = 0;
        struBeepAndFlicker.byBeepCount = 0;
        struBeepAndFlicker.byFlickerType = 0;
        struBeepAndFlicker.byFlickerCount = 0;

        USB_CONFIG_INPUT_INFO struConfigInputInfo = { 0 };

        struConfigInputInfo.dwCondBufferSize = 0;
        struConfigInputInfo.lpCondBuffer = NULL;
        struConfigInputInfo.dwInBufferSize = sizeof(struBeepAndFlicker);
        struConfigInputInfo.lpInBuffer = &struBeepAndFlicker;

        if (USB_SetDeviceConfig(pActivate->m_lUserID, USB_SET_BEEP_AND_FLICKER, &struConfigInputInfo, NULL))
        {
            LOGIN_INFO->WriteLog(INF_LEVEL, "Error Times[%d] SUCCESS USB_SetDeviceConfig()  Command = USB_SET_BEEP_AND_FLICKER", iErrorNo);
        }
        else
        {
            if (USB_GetLastError() == USB_ERROR_RECV_PACK_TIMEOUT)
            {
                iErrorNo++;
            }
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_BEEP_AND_FLICKER");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
    }
    //Sleep(1000);
    
    return 0;
}


void CDlgActivateCard::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_ACTIVATE_CARD);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_WAIT_TIME);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_SEC);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_BTN_ACTIVATE);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_RSP);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_PRO_TYPE);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_SER_LEN);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_SERIAL);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_SELECT_LEN);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_STATIC_SELECT);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_BTN_ACTIVATE2);
	SET_CONTROL_LAN(IDD_DLG_ACTIVATE_CARD, IDC_BTN_STOP_ACTIVATE);
}
