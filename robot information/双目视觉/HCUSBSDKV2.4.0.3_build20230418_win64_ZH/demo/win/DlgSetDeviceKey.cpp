// DlgSetDeviceKey.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgSetDeviceKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CSTRING_TO_CHARS(str,sz) memcpy((sz),str.GetBuffer(str.GetLength()),str.GetLength())

/////////////////////////////////////////////////////////////////////////////
// CDlgSetDeviceKey dialog


CDlgSetDeviceKey::CDlgSetDeviceKey(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgSetDeviceKey::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgSetDeviceKey)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void CDlgSetDeviceKey::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgSetDeviceKey)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_COM_KEY_LEN, m_comKeyLen);
    DDX_Control(pDX, IDC_EDT_DEV_KEY, m_edtKey);	
    DDX_Text(pDX, IDC_EDT_DEV_KEY, m_csKey);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetDeviceKey, CDialog)
    //{{AFX_MSG_MAP(CDlgSetDeviceKey)
    ON_BN_CLICKED(IDC_BTN_SET_KEY, OnBtnSetKey)
    ON_CBN_SELCHANGE(IDC_COM_KEY_LEN, OnSelchangeComKeyLen)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetDeviceKey message handlers


BOOL CDlgSetDeviceKey::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    m_comKeyLen.InsertString(0, _T("AES128"));
    m_comKeyLen.InsertString(1, _T("AES192"));
    m_comKeyLen.InsertString(2, _T("AES256"));
    m_comKeyLen.SetCurSel(0);

    OnSelchangeComKeyLen();

    //UpdateData(FALSE);
    
    return TRUE;
}

void CDlgSetDeviceKey::OnBtnSetKey() 
{
    // TODO: Add your control notification handler code here

    UpdateData(TRUE);
}

void CDlgSetDeviceKey::OnSelchangeComKeyLen() 
{
    // TODO: Add your control notification handler code here
    BYTE byType = m_comKeyLen.GetCurSel();
    char szBuffer[32] = {0};
    if (byType == 0)
    {
        m_dwKeyLen = 16;
        PrintData(szBuffer, 16);
    }
    else if (byType == 1)
    {
        m_dwKeyLen = 24;
        PrintData(szBuffer, 24);
    }
    else if (byType == 2)
    {
        m_dwKeyLen = 32;
        PrintData(szBuffer, 32);
    }	
}

void CDlgSetDeviceKey::PrintData(char* pBuffer, const DWORD dwSize)
{
    m_csKey = _T("");
    UpdateData(FALSE);

    {
        CString csTemp;
        CString csInfo;
        
        csInfo = _T("");
        
        for (DWORD i = 1; i < dwSize+1; i++)
        {
            csTemp.Format("%02X", (unsigned char)pBuffer[i-1]);

            if(i % 8 == 0)
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
            
            if (i % 16 == 0)
            {
                csInfo += _T("\r\n");
                m_edtKey.SetSel(-1);
                m_edtKey.ReplaceSel(csInfo);
                csInfo = _T("");
            }
        }
        if (csInfo.GetLength() != 0)
        {
            csInfo += _T("\r\n");
            m_edtKey.SetSel(-1);
            m_edtKey.ReplaceSel(csInfo);
            csInfo = _T("");
        }
    }
}

void CDlgSetDeviceKey::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_SET_DEV_KEY);
	SET_CONTROL_LAN(IDD_DLG_SET_DEV_KEY, IDC_STATIC_KEY_LEN);
	SET_CONTROL_LAN(IDD_DLG_SET_DEV_KEY, IDC_STATIC_KEY);
	SET_CONTROL_LAN(IDD_DLG_SET_DEV_KEY, IDC_BTN_SET_KEY);
}
