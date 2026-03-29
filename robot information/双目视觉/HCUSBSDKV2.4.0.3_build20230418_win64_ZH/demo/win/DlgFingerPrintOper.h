#if !defined(AFX_DLGFINGERPRINTOPER_H__A1BFD678_44CD_43CF_A01C_0C99956BF490__INCLUDED_)
#define AFX_DLGFINGERPRINTOPER_H__A1BFD678_44CD_43CF_A01C_0C99956BF490__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFingerPrintOper.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFingerPrintOper dialog

class CDlgFingerPrintOper : public CDialog
{
// Construction
public:
	CDlgFingerPrintOper(CWnd* pParent = NULL);   // standard constructor
    LONG m_lUserID;
// Dialog Data
	//{{AFX_DATA(CDlgFingerPrintOper)
	enum { IDD = IDD_DLG_FINGER_PRINT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFingerPrintOper)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CDlgFingerPrintOper)
	afx_msg void OnBtnSet();
	afx_msg void OnBtnGet();
	afx_msg void OnBtnCapture();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    CComboBox  m_comboFPCompareType;
    CComboBox  m_comboFPCaptureType;
    BYTE  m_byFPCompareTimeout;
    CComboBox m_comboFPCompareMatchLevel;
    CComboBox  m_comboResult;
    BYTE  m_byFPTemplateQuality;
    BYTE  m_byWait;
    CString m_csFPBuffer;
    CComboBox m_FPType;
    CComboBox m_comboCaptureResult;
    BYTE  m_byQulity;
public:
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFINGERPRINTOPER_H__A1BFD678_44CD_43CF_A01C_0C99956BF490__INCLUDED_)
