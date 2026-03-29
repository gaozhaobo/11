#if !defined(AFX_DlgGetCardIssueVer_H__BA120E67_CC0B_44DB_9FBA_470A0E80A771__INCLUDED_)
#define AFX_DlgGetCardIssueVer_H__BA120E67_CC0B_44DB_9FBA_470A0E80A771__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGetCardIssueVer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgGetCardIssueVer dialog

class CDlgGetCardIssueVer : public CDialog
{
// Construction
public:
    CDlgGetCardIssueVer(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgGetCardIssueVer)
    enum { IDD = IDD_DLG_GET_CARD_ISSUE_VER };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    CString m_csDevName;
    CString m_csSerialNO;
    CString m_csSoftwareVer;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgGetCardIssueVer)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

     BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgGetCardIssueVer)
    afx_msg void OnBtnGet();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgGetCardIssueVer_H__BA120E67_CC0B_44DB_9FBA_470A0E80A771__INCLUDED_)
