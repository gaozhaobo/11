#if !defined(AFX_DLGM1MIFAREPACK_H__1F05D6F2_9B88_4D26_8D5F_4C86E9A9C193__INCLUDED_)
#define AFX_DLGM1MIFAREPACK_H__1F05D6F2_9B88_4D26_8D5F_4C86E9A9C193__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1MifarePack.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1MifarePack dialog

class CDlgM1MifarePack : public CDialog
{
// Construction
public:
    CDlgM1MifarePack(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1MifarePack)
    enum { IDD = IDD_DLG_M1_MIFARE_PACK };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    char m_szBuf[1024];

    DWORD m_dwDataLen;
    DWORD m_dwDelay;

    CEdit m_edtData;
    CString m_csData;

    BOOL m_bChange;

    void PrintData(BYTE* pBuffer, const DWORD dwSize);
    BOOL CheckIsNum(char c);

    char ConvertKey(int nKey);
    
    BOOL PreTranslateMessage(MSG* pMsg);
     
    BOOL DoNumberInput(int cKey);
    BOOL DoCtrlV();


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1MifarePack)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();

    // Generated message map functions
    //{{AFX_MSG(CDlgM1MifarePack)
    afx_msg void OnBtnGet();
    afx_msg void OnBtnSet();
    afx_msg void OnKillfocusEdtDataLen();
	afx_msg void OnPaint();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGM1MIFAREPACK_H__1F05D6F2_9B88_4D26_8D5F_4C86E9A9C193__INCLUDED_)
