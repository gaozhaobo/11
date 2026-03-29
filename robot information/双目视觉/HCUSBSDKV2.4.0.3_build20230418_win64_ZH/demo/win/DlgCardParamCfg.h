#if !defined(AFX_DLGCARDPARAMCFG_H__1BF027EC_0247_4D78_8B63_3C299BC65228__INCLUDED_)
#define AFX_DLGCARDPARAMCFG_H__1BF027EC_0247_4D78_8B63_3C299BC65228__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCardParamCfg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCardParamCfg dialog

class CDlgCardParamCfg : public CDialog
{
// Construction
public:
    CDlgCardParamCfg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgCardParamCfg)
    enum { IDD = IDD_DLG_CARD_PARAM_CFG };
        // NOTE: the ClassWizard will add data members here
    CComboBox m_comCardType;
    CComboBox m_comCardProtoType;

    DWORD m_dwDelay;
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgCardParamCfg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgCardParamCfg)
    afx_msg void OnBtnSet();
	afx_msg void OnSelchangeComCardType();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
        
public:
    LONG m_lUserID;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCARDPARAMCFG_H__1BF027EC_0247_4D78_8B63_3C299BC65228__INCLUDED_)
