#if !defined(AFX_DLGM1READBLOCK_H__E1AAA057_AAA9_4E8C_88F0_B969AF744D2F__INCLUDED_)
#define AFX_DLGM1READBLOCK_H__E1AAA057_AAA9_4E8C_88F0_B969AF744D2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1ReadBlock.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1ReadBlock dialog

class CDlgM1ReadBlock : public CDialog
{
// Construction
public:
    CDlgM1ReadBlock(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1ReadBlock)
    enum { IDD = IDD_DLG_M1_READ_BLOCK };
        // NOTE: the ClassWizard will add data members here
    CEdit  m_edtBlockData;
    //}}AFX_DATA

    DWORD m_dwBlockAddr;
    CEdit m_edtData;
    CString m_csData;
    char    m_szData[512]; //这是真正的数据
    int     m_nDataLen;    //真正的数据长度

    BOOL m_bHex;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1ReadBlock)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1ReadBlock)
    afx_msg void OnBtnRead();
    afx_msg void OnBtnHex();
    afx_msg void OnBtnText();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:

    void PrintData(char* pBuffer, const DWORD dwSize);

    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGM1READBLOCK_H__E1AAA057_AAA9_4E8C_88F0_B969AF744D2F__INCLUDED_)
