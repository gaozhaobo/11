#if !defined(AFX_DLGCERTIFICATEMAC_H__BD9EFFFB_4769_4B99_9D8A_38F054BF8B59__INCLUDED_)
#define AFX_DLGCERTIFICATEMAC_H__BD9EFFFB_4769_4B99_9D8A_38F054BF8B59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCertificateMac.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateMac dialog

class CDlgCertificateMac : public CDialog
{
// Construction
public:
	CDlgCertificateMac(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCertificateMac)
	enum { IDD = IDD_DLG_CERTIFICATE_MAC };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCertificateMac)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCertificateMac)
	afx_msg void OnBtnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    CString m_csCertificateMac;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCERTIFICATEMAC_H__BD9EFFFB_4769_4B99_9D8A_38F054BF8B59__INCLUDED_)
