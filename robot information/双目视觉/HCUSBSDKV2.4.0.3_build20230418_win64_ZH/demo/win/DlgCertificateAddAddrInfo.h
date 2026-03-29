#if !defined(AFX_DLGCERTIFICATEADDADDRINFO_H__40AC9A48_18C3_427D_B202_C6AD276CF327__INCLUDED_)
#define AFX_DLGCERTIFICATEADDADDRINFO_H__40AC9A48_18C3_427D_B202_C6AD276CF327__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCertificateAddAddrInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateAddAddrInfo dialog

class CDlgCertificateAddAddrInfo : public CDialog
{
// Construction
public:
	CDlgCertificateAddAddrInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCertificateAddAddrInfo)
	enum { IDD = IDD_DLG_CERTIFICATE_ADD_ADDR_INFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCertificateAddAddrInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCertificateAddAddrInfo)
	afx_msg void OnBtnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    CString m_csAddAddrInfo;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCERTIFICATEADDADDRINFO_H__40AC9A48_18C3_427D_B202_C6AD276CF327__INCLUDED_)
