#if !defined(AFX_DLGDETECTCARD_H__65ED1CF9_5C66_4861_8E9F_93FF64B8D9CD__INCLUDED_)
#define AFX_DLGDETECTCARD_H__65ED1CF9_5C66_4861_8E9F_93FF64B8D9CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDetectCard.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDetectCard dialog

class CDlgDetectCard : public CDialog
{
// Construction
public:
	CDlgDetectCard(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDetectCard)
	enum { IDD = IDD_DLG_DETECT_CARD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDetectCard)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDetectCard)
	afx_msg void OnBtnDetect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    DWORD m_dwWaitSecond;
    CString m_csResult;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDETECTCARD_H__65ED1CF9_5C66_4861_8E9F_93FF64B8D9CD__INCLUDED_)
