// DlgM1ReadBlock.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1ReadBlock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgM1ReadBlock dialog


CDlgM1ReadBlock::CDlgM1ReadBlock(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1ReadBlock::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1ReadBlock)
        // NOTE: the ClassWizard will add member initialization here
    m_dwBlockAddr = 0;
    m_nDataLen = 0;
    memset(m_szData, 0, sizeof(m_szData)); //这是真正的数据
    m_bHex = FALSE;
    //}}AFX_DATA_INIT
}


void CDlgM1ReadBlock::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1ReadBlock)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_EDT_BLOCK_ADDR, m_dwBlockAddr);
    DDX_Control(pDX, IDC_EDT_BLOCK_DATA, m_edtData);
    DDX_Text(pDX, IDC_EDT_BLOCK_DATA, m_csData);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1ReadBlock, CDialog)
    //{{AFX_MSG_MAP(CDlgM1ReadBlock)
    ON_BN_CLICKED(IDC_BTN_READ, OnBtnRead)
    ON_BN_CLICKED(IDC_RAD_HEX, OnBtnHex)
    ON_BN_CLICKED(IDC_RAD_TEXT, OnBtnText)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1ReadBlock message handlers


BOOL CDlgM1ReadBlock::OnInitDialog()
{
    CDialog::OnInitDialog();

    ((CButton *)GetDlgItem(IDC_RAD_TEXT))->SetCheck(TRUE);
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgM1ReadBlock::OnBtnHex()
{
    char    szDataShow[512] = {0}; //这是真正的数据
    DWORD   dwDataShowLen = 0;
    
    if (!m_bHex)
    {
        UpdateData(TRUE);
        memset(m_szData, 0, sizeof(m_szData));
        CSTRING_TO_CHARS(m_csData, m_szData);
        m_nDataLen = strlen(m_szData); 
    }
    
    m_bHex = TRUE;
    
    //十六进制显示
    if(!ConvertTextToHex(m_szData, m_nDataLen, szDataShow, &dwDataShowLen))
    {
		if (g_bEnglish)
		{
			MessageBox("Error in hex present，parameter error!");
		}
		else
		{
			MessageBox("以十六进制显示时出错，传递的参数有误!");
		}
    }
    else
    {
        m_csData = szDataShow;
        UpdateData(FALSE);
    }
}

void CDlgM1ReadBlock::OnBtnText()
{
    m_bHex = FALSE;
    
    //文本显示
    m_csData = m_szData;
    UpdateData(FALSE);
}


void CDlgM1ReadBlock::OnBtnRead() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    if (m_dwBlockAddr < 0 || m_dwBlockAddr > 65535)
    {
		if (g_bEnglish)
		{
			MessageBox("Addr range:0(include)-65535(include)");
		}
		else
		{
			MessageBox("块地址范围为0(含)-65535(含)");
		}
        return;
    }
    
    USB_M1_BLOCK_ADDR struBlockAddr = {0};
    struBlockAddr.dwSize = sizeof(struBlockAddr);
    struBlockAddr.wAddr = static_cast<WORD>(m_dwBlockAddr);
    
    USB_M1_BLOCK_DATA struBlockData = {0};
    struBlockData.dwSize = sizeof(struBlockData);
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struBlockAddr);
    struInput.lpInBuffer = &struBlockAddr;
    
    USB_CONFIG_OUTPUT_INFO struOutput = {0};
    struOutput.dwOutBufferSize = sizeof(struBlockData);
    struOutput.lpOutBuffer = &struBlockData;
    
    if (USB_GetDeviceConfig(m_lUserID, USB_GET_M1_READ_BLOCK, &struInput, &struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_M1_READ_BLOCK");
        {
            memset(m_szData, 0, sizeof(m_szData));

            if (((CButton *)GetDlgItem(IDC_RAD_HEX))->GetCheck())
            {
                PrintData((char*)struBlockData.byData, 16);
            }
            else
            {
                m_csData = m_szData;
            }
            
            UpdateData(TRUE);
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_M1_READ_BLOCK");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgM1ReadBlock::PrintData(char* pBuffer, const DWORD dwSize)
{
    m_csData = _T("");
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
                m_edtData.SetSel(-1);
                m_edtData.ReplaceSel(csInfo);
                csInfo = _T("");
            }
        }
        if (csInfo.GetLength() != 0)
        {
            csInfo += _T("\r\n");
            m_edtData.SetSel(-1);
            m_edtData.ReplaceSel(csInfo);
            csInfo = _T("");
        }
    }
}

void CDlgM1ReadBlock::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_READ_BLOCK);
	SET_CONTROL_LAN(IDD_DLG_M1_READ_BLOCK, IDC_STATIC_BLOCK_ADDRESS);
	SET_CONTROL_LAN(IDD_DLG_M1_READ_BLOCK, IDC_RAD_HEX);
	SET_CONTROL_LAN(IDD_DLG_M1_READ_BLOCK, IDC_RAD_TEXT);
	SET_CONTROL_LAN(IDD_DLG_M1_READ_BLOCK, IDC_STATIC_BLOCK_DATA);
	SET_CONTROL_LAN(IDD_DLG_M1_READ_BLOCK, IDC_BTN_READ);
}

