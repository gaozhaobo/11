#if !defined(AFX_DlgStopCardOper_H__CB9004D0_A6D4_42E7_82B9_5876FD48E963__INCLUDED_)
#define AFX_DlgStopCardOper_H__CB9004D0_A6D4_42E7_82B9_5876FD48E963__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgStopCardOper.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgStopCardOper dialog

class CDlgStopCardOper : public CDialog
{
// Construction
public:
    CDlgStopCardOper(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgStopCardOper)
    enum { IDD = IDD_DLG_STOP_CARD_OPER };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgStopCardOper)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CDlgStopCardOper)
    afx_msg void OnBtnStop();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgStopCardOper_H__CB9004D0_A6D4_42E7_82B9_5876FD48E963__INCLUDED_)
