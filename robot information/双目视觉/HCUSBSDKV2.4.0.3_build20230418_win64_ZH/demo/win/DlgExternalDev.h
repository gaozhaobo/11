#if !defined(AFX_DLGEXTERNALDEV_H__AB9FE381_4C3F_4E39_A878_537CC534BAAB__INCLUDED_)
#define AFX_DLGEXTERNALDEV_H__AB9FE381_4C3F_4E39_A878_537CC534BAAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgExternalDev.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgExternalDev dialog

class CDlgExternalDev : public CDialog
{
// Construction
public:
	CDlgExternalDev(CWnd* pParent = NULL);   // standard constructor
    LONG    m_lUserID;

// Dialog Data
	//{{AFX_DATA(CDlgExternalDev)
	enum { IDD = IDD_DLG_EXTERNAL_DEV };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgExternalDev)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgExternalDev)
	afx_msg void OnBtnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    CString m_csFPModuleSoftVersion;
    CString m_csFPModuleSerialNumber;
    CString m_csSecurityModuleSerialNumber;
public:
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEXTERNALDEV_H__AB9FE381_4C3F_4E39_A878_537CC534BAAB__INCLUDED_)
