#if !defined(AFX_DLGM1WRITEBLOCK_H__78C82226_5A45_4186_9D13_3298B1795BF3__INCLUDED_)
#define AFX_DLGM1WRITEBLOCK_H__78C82226_5A45_4186_9D13_3298B1795BF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1WriteBlock.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1WriteBlock dialog

class CDlgM1WriteBlock : public CDialog
{
// Construction
public:
    CDlgM1WriteBlock(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1WriteBlock)
    enum { IDD = IDD_DLG_M1_WRITE_BLOCK };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    DWORD m_dwBlockAddr;

    CEdit m_edtData;
    CString m_csData;      //这是显示用的数据
    char    m_szData[512]; //这是真正的数据
    int     m_nDataLen;    //真正的数据长度

    BOOL m_bHex;


    void PrintData(char* pBuffer, const DWORD dwSize);


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1WriteBlock)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1WriteBlock)
    afx_msg void OnBtnWrite();
    afx_msg void OnBtnHex();
    afx_msg void OnBtnText();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGM1WRITEBLOCK_H__78C82226_5A45_4186_9D13_3298B1795BF3__INCLUDED_)
