#if !defined(AFX_SUBDLGGENINTERFACE_H__348913B6_9334_4A23_B826_8DEB864D36B6__INCLUDED_)
#define AFX_SUBDLGGENINTERFACE_H__348913B6_9334_4A23_B826_8DEB864D36B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDlgGenInterface.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SubDlgGenInterface dialog

class SubDlgGenInterface : public CDialog
{
// Construction
public:
    SubDlgGenInterface(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(SubDlgGenInterface)
    enum { IDD = IDD_SUBDLG_GEN_INTERFACE };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(SubDlgGenInterface)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(SubDlgGenInterface)
    afx_msg void OnBtnSetCardProto();
    afx_msg void OnBtnActivateCard();
	afx_msg void OnBtnStopCardOper();
	afx_msg void OnPaint();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLGGENINTERFACE_H__348913B6_9334_4A23_B826_8DEB864D36B6__INCLUDED_)
