#if !defined(AFX_DLGCPUCARDENCRYPTCFG_H__BE7D5FCA_CC84_42CF_8CCA_8C0B18FD29F7__INCLUDED_)
#define AFX_DLGCPUCARDENCRYPTCFG_H__BE7D5FCA_CC84_42CF_8CCA_8C0B18FD29F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCPUCardEncryptCfg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardEncryptCfg dialog

class CDlgCPUCardEncryptCfg : public CDialog
{
// Construction
public:
	CDlgCPUCardEncryptCfg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCPUCardEncryptCfg)
	enum { IDD = IDD_DLG_CPU_CARD_ENCRYPT_CFG };
	CComboBox m_comCardType;
	CString	m_csKey;
	DWORD	m_dwKeyLength;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCPUCardEncryptCfg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CDlgCPUCardEncryptCfg)
	virtual void OnOK();
	afx_msg void OnSelchangeComCardType();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	LONG m_lUserID;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCPUCARDENCRYPTCFG_H__BE7D5FCA_CC84_42CF_8CCA_8C0B18FD29F7__INCLUDED_)
