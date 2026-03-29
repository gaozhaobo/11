// PCI_8144_DIODlg.h : header file
//

#if !defined(AFX_PCI_8144_DIODLG_H__56A10DA4_1E51_4887_8CBC_0FF85FF0314C__INCLUDED_)
#define AFX_PCI_8144_DIODLG_H__56A10DA4_1E51_4887_8CBC_0FF85FF0314C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPCI_8144_DIODlg dialog

class CPCI_8144_DIODlg : public CDialog
{
// Construction
public:
	CPCI_8144_DIODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPCI_8144_DIODlg)
	enum { IDD = IDD_PCI_8144_DIO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCI_8144_DIODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPCI_8144_DIODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnGetDI();
	afx_msg void OnBtnSetDO();
	afx_msg void OnBtnExit();
	afx_msg void OnBtnGetDO();
	
	//}}AFX_MSG 
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCI_8144_DIODLG_H__56A10DA4_1E51_4887_8CBC_0FF85FF0314C__INCLUDED_)
