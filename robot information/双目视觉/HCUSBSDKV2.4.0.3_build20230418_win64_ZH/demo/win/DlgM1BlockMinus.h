#if !defined(AFX_DLGM1BLOCKMINUS_H__7C3CB9CB_A9A5_4AD6_85A6_FE94CFC96CF8__INCLUDED_)
#define AFX_DLGM1BLOCKMINUS_H__7C3CB9CB_A9A5_4AD6_85A6_FE94CFC96CF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1BlockMinus.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockMinus dialog

class CDlgM1BlockMinus : public CDialog
{
// Construction
public:
    CDlgM1BlockMinus(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1BlockMinus)
    enum { IDD = IDD_DLG_M1_BLOCK_MINUS };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    DWORD       m_dwBlockAddr;
    DWORD       m_dwValue;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1BlockMinus)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1BlockMinus)
    afx_msg void OnBtnOk();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGM1BLOCKMINUS_H__7C3CB9CB_A9A5_4AD6_85A6_FE94CFC96CF8__INCLUDED_)
