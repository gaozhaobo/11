#if !defined(AFX_DLGUPGRADE_H__82AA07D3_54C0_4D80_814C_BBA5340E3DDF__INCLUDED_)
#define AFX_DLGUPGRADE_H__82AA07D3_54C0_4D80_814C_BBA5340E3DDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgUpgrade.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgUpgrade dialog

class CDlgUpgrade : public CDialog
{
// Construction
public:
	CDlgUpgrade(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgUpgrade)
	enum { IDD = IDD_DLG_UPGRADE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

    //CProgressCtrl *m_pProgCtrlSub;
    CProgressCtrl *m_pProgCtrlTotal;

    CString m_csFilePath;
    CString m_csState;

    int     m_nTimeout;

    //int     m_nSubProgress;
    int     m_nTotalProgress;

    //CString m_csSubProgress;
    CString m_csTotalProgress;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgUpgrade)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

    BOOL m_bUpgrade;

    BOOL OnInitDialog();

	// Generated message map functions
	//{{AFX_MSG(CDlgUpgrade)
	afx_msg void OnBtnSelect();
	afx_msg void OnBtnUpgrade();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    LONG m_lUpgradeHandle;
    USB_UPGRADE_STATE_INFO m_struUpgradeState;
    DWORD m_dwModuleID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGUPGRADE_H__82AA07D3_54C0_4D80_814C_BBA5340E3DDF__INCLUDED_)
