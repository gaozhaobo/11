#if !defined(AFX_DLGM1BLOCKADD_H__7A0E0727_4000_41FC_9682_6CCDE5A0560A__INCLUDED_)
#define AFX_DLGM1BLOCKADD_H__7A0E0727_4000_41FC_9682_6CCDE5A0560A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1BlockAdd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockAdd dialog

class CDlgM1BlockAdd : public CDialog
{
// Construction
public:
    CDlgM1BlockAdd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1BlockAdd)
    enum { IDD = IDD_DLG_M1_BLOCK_ADD };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    DWORD       m_dwBlockAddr;
    DWORD       m_dwValue;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1BlockAdd)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1BlockAdd)
    afx_msg void OnBtnOk();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGM1BLOCKADD_H__7A0E0727_4000_41FC_9682_6CCDE5A0560A__INCLUDED_)
