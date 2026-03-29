#if !defined(AFX_DLGCARDPROTOCFG_H__0890EAA9_8AF8_4AA1_9C19_BA997E8AAAAF__INCLUDED_)
#define AFX_DLGCARDPROTOCFG_H__0890EAA9_8AF8_4AA1_9C19_BA997E8AAAAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCardProtoCfg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCardProtoCfg dialog

class CDlgCardProtoCfg : public CDialog
{
// Construction
public:
    CDlgCardProtoCfg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgCardProtoCfg)
    enum { IDD = IDD_DLG_SET_CARD_PROTO };
        // NOTE: the ClassWizard will add data members here
        CComboBox	m_comCardProto;
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgCardProtoCfg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();

    // Generated message map functions
    //{{AFX_MSG(CDlgCardProtoCfg)
    afx_msg void OnBtnSet();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCARDPROTOCFG_H__0890EAA9_8AF8_4AA1_9C19_BA997E8AAAAF__INCLUDED_)
