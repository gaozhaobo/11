#if !defined(AFX_SUBDLGCERTIFICATEINFOINTERFACE_H__A935E406_809B_44F6_B477_A8ECB9098CF2__INCLUDED_)
#define AFX_SUBDLGCERTIFICATEINFOINTERFACE_H__A935E406_809B_44F6_B477_A8ECB9098CF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDlgCertificateInfoInterface.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubDlgCertificateInfoInterface dialog

class CSubDlgCertificateInfoInterface : public CDialog
{
// Construction
public:
	CSubDlgCertificateInfoInterface(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubDlgCertificateInfoInterface)
	enum { IDD = IDD_SUBDLG_CERTIFICATE_INTERFACE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubDlgCertificateInfoInterface)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubDlgCertificateInfoInterface)
	afx_msg void OnBtnGetCertificateInfo();
	afx_msg void OnBtnGetCertificateAddAddrInfo();
	afx_msg void OnBtnGetCertificateMac();
	afx_msg void OnBtnGetIcCardNo();
	afx_msg void OnBtnDetectCard();
	afx_msg void OnBtnGetExternalDevInfo();
	afx_msg void OnBtnFingerCfg();
	//afx_msg void OnBtnStateSecretPublish();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

    LONG m_lUserID;
    afx_msg void OnBnClickedBtnIsapiTransconfig();
    afx_msg void OnBnClickedBtnOnlinecollection();
    afx_msg void OnBnClickedBtnOfflinecollection2();
    afx_msg void OnPaint();
    afx_msg void OnBnClickedBtnHealthCode();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLGCERTIFICATEINFOINTERFACE_H__A935E406_809B_44F6_B477_A8ECB9098CF2__INCLUDED_)
