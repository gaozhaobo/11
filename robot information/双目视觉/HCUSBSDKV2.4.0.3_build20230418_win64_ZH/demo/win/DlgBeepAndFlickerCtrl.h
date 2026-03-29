#if !defined(AFX_DLGBEEPANDFLICKERCTRL_H__4F5B27FF_2D83_458B_8C9F_1A3D500744A9__INCLUDED_)
#define AFX_DLGBEEPANDFLICKERCTRL_H__4F5B27FF_2D83_458B_8C9F_1A3D500744A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBeepAndFlickerCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBeepAndFlickerCtrl dialog

class CDlgBeepAndFlickerCtrl : public CDialog
{
// Construction
public:
    CDlgBeepAndFlickerCtrl(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgBeepAndFlickerCtrl)
    enum { IDD = IDD_DLG_BEEP_AND_FLICKER };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA
    CComboBox	m_comBeepType;
    CComboBox	m_comFlickerType;

    DWORD       m_dwBeepCount;
    DWORD       m_dwFlickerCount;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgBeepAndFlickerCtrl)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgBeepAndFlickerCtrl)
    afx_msg void OnBtnCfg();
	afx_msg void OnSelchangeComBeepType();
	afx_msg void OnSelchangeComFlickerType();
	afx_msg void OnPaint();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBEEPANDFLICKERCTRL_H__4F5B27FF_2D83_458B_8C9F_1A3D500744A9__INCLUDED_)
