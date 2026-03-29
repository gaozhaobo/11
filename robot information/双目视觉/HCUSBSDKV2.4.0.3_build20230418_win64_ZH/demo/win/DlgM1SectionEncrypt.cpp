// DlgM1SectionEncrypt.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1SectionEncrypt.h"
#include "afxdialogex.h"

#define CSTRING_TO_CHARS(str,sz) memcpy((sz),str.GetBuffer(str.GetLength()),str.GetLength())

// CDlgM1SectionEncrypt 对话框

IMPLEMENT_DYNAMIC(CDlgM1SectionEncrypt, CDialogEx)

CDlgM1SectionEncrypt::CDlgM1SectionEncrypt(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgM1SectionEncrypt::IDD, pParent)
    , m_dwSectionID(0)
    , m_csKeyAContent(_T("00 00 00 00 00 00"))
    , m_csNewKeyAContent(_T("00 00 00 00 00 00"))
    , m_csCtrlBits(_T("00 00 00 00"))
    , m_csNewKeyBContent(_T("00 00 00 00 00 00"))
{

}

CDlgM1SectionEncrypt::~CDlgM1SectionEncrypt()
{
}

void CDlgM1SectionEncrypt::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_SECTIONID, m_dwSectionID);
    DDX_Control(pDX, IDC_COMBO_KEYTYPE, m_comKeyType);
    DDX_Control(pDX, IDC_COMBO2, m_comNewKeyType);
    DDX_Text(pDX, IDC_EDIT4, m_csKeyAContent);
    DDX_Text(pDX, IDC_EDIT2, m_csNewKeyAContent);
    DDX_Text(pDX, IDC_EDIT3, m_csCtrlBits);
    DDX_Text(pDX, IDC_EDIT5, m_csNewKeyBContent);
}

BOOL CDlgM1SectionEncrypt::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  在此添加额外的初始化
	if (g_bEnglish)
	{
		m_comKeyType.InsertString(0, _T("0-HIK Encrypt"));
		m_comKeyType.InsertString(1, _T("1-Other Encrypt"));
		m_comNewKeyType.InsertString(0, _T("0-HIK Encrypt"));
		m_comNewKeyType.InsertString(1, _T("1-Other Encrypt"));
	}
	else
	{
		m_comKeyType.InsertString(0, _T("0-海康密钥"));
		m_comKeyType.InsertString(1, _T("1-其它密钥"));
		m_comNewKeyType.InsertString(0, _T("0-海康密钥"));
		m_comNewKeyType.InsertString(1, _T("1-其它密钥"));
	}
    m_comKeyType.SetCurSel(0);
    m_comNewKeyType.SetCurSel(0);

    UpdateData(FALSE);


    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常:  OCX 属性页应返回 FALSE
}


BEGIN_MESSAGE_MAP(CDlgM1SectionEncrypt, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_SEND, &CDlgM1SectionEncrypt::OnBnClickedBtnSend)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgM1SectionEncrypt 消息处理程序


void CDlgM1SectionEncrypt::OnBnClickedBtnSend()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);
    USB_M1_SECTION_ENCRYPT struM1SectionEncrypt = {0};
    struM1SectionEncrypt.dwSize = sizeof(struM1SectionEncrypt);
    struM1SectionEncrypt.bySectionID = (BYTE)m_dwSectionID;
    struM1SectionEncrypt.byKeyType = m_comKeyType.GetCurSel();
    struM1SectionEncrypt.byNewKeyType = m_comNewKeyType.GetCurSel();

    char szKeyA[32] = { 0 };
    char szNewKeyA[32] = { 0 };
    char szNewKeyB[32] = { 0 };
    char szCtrlByte[32] = { 0 };

    CSTRING_TO_CHARS(m_csKeyAContent, szKeyA);
    CSTRING_TO_CHARS(m_csNewKeyAContent, szNewKeyA);
    CSTRING_TO_CHARS(m_csNewKeyBContent, szNewKeyB);
    CSTRING_TO_CHARS(m_csCtrlBits, szCtrlByte);

    DWORD dwDataLen = 0;
    ConvertHexBufToByteBuf(szKeyA, strlen(szKeyA) + 1, struM1SectionEncrypt.byKeyAContent, &dwDataLen);
    ConvertHexBufToByteBuf(szNewKeyA, strlen(szNewKeyA) + 1, struM1SectionEncrypt.byNewKeyAContent, &dwDataLen);
    ConvertHexBufToByteBuf(szNewKeyB, strlen(szNewKeyB) + 1, struM1SectionEncrypt.byNewKeyBContent, &dwDataLen);
    ConvertHexBufToByteBuf(szCtrlByte, strlen(szCtrlByte) + 1, struM1SectionEncrypt.byCtrlBits, &dwDataLen);

    USB_CONFIG_INPUT_INFO struInput = { 0 };
    struInput.dwInBufferSize = sizeof(struM1SectionEncrypt);
    struInput.lpInBuffer = &struM1SectionEncrypt;

    USB_M1_SECTION_ENCRYPT_RES struM1SectionEncryptRes = { 0 };
    struM1SectionEncryptRes.dwSize = sizeof(struM1SectionEncryptRes);

    USB_CONFIG_OUTPUT_INFO struOutput = { 0 };
    struOutput.dwOutBufferSize = sizeof(struM1SectionEncryptRes);
    struOutput.lpOutBuffer = &struM1SectionEncryptRes;

    if (USB_SetDeviceConfig(m_lUserID, USB_SET_M1_SECTION_ENCRYPT, &struInput, &struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_M1_SECTION_ENCRYPT");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_SetDeviceConfig()  Command = USB_SET_M1_SECTION_ENCRYPT");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgM1SectionEncrypt::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_SECTION_ENCRYPT);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_STATIC_BLOCKID);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_STATIC_ENCRYPT);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_STATIC_VERIFY_PWD);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_STATIC_NEW_PWD);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_STATIC_PWDA);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_STATIC_CONTROL);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_STATIC_PWDB);
	SET_CONTROL_LAN(IDD_DLG_M1_SECTION_ENCRYPT, IDC_BTN_SEND);
}