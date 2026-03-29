#if !defined(AFX_DLGICCARDNO_H__6DE9832B_662B_4923_991A_3CB1C5CBF307__INCLUDED_)
#define AFX_DLGICCARDNO_H__6DE9832B_662B_4923_991A_3CB1C5CBF307__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgICCardNo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgICCardNo dialog

class CDlgICCardNo : public CDialog
{
// Construction
public:
	CDlgICCardNo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgICCardNo)
	enum { IDD = IDD_DLG_IC_CARD_NO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgICCardNo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgICCardNo)
	afx_msg void OnBtnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    CString m_csICCardNo;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGICCARDNO_H__6DE9832B_662B_4923_991A_3CB1C5CBF307__INCLUDED_)
