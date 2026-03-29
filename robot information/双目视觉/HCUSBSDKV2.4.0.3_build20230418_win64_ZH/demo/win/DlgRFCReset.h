#if !defined(AFX_DLGRFCRESET_H__0B743F4F_14D7_4BD0_8391_6A002C0ACF3D__INCLUDED_)
#define AFX_DLGRFCRESET_H__0B743F4F_14D7_4BD0_8391_6A002C0ACF3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRFCReset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRFCReset dialog

class CDlgRFCReset : public CDialog
{
// Construction
public:
    CDlgRFCReset(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgRFCReset)
    enum { IDD = IDD_DLG_RFC_RESET };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgRFCReset)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgRFCReset)
    afx_msg void OnBtnSet();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRFCRESET_H__0B743F4F_14D7_4BD0_8391_6A002C0ACF3D__INCLUDED_)
