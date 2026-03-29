#if !defined(AFX_DLGCERTIFICATEINFO_H__56FD51F1_AB1B_40AC_8C62_E1DC04846EF7__INCLUDED_)
#define AFX_DLGCERTIFICATEINFO_H__56FD51F1_AB1B_40AC_8C62_E1DC04846EF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCertificateInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateInfo dialog

class CDlgCertificateInfo : public CDialog
{
// Construction
public:
	CDlgCertificateInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCertificateInfo)
	enum { IDD = IDD_DLG_CERTIFICATE_INFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCertificateInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCertificateInfo)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    CString m_csWordInfo;
    CString m_csPicInfo;
    CString m_csFingerPrintInfo;
    CComboBox m_comboCertificateType;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCERTIFICATEINFO_H__56FD51F1_AB1B_40AC_8C62_E1DC04846EF7__INCLUDED_)
