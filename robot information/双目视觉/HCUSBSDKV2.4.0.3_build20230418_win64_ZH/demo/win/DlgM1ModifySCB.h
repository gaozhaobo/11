#if !defined(AFX_DLGM1MODIFYSCB_H__CA5CCBCB_F3F1_425D_97DF_4DAE4D7FFBFC__INCLUDED_)
#define AFX_DLGM1MODIFYSCB_H__CA5CCBCB_F3F1_425D_97DF_4DAE4D7FFBFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1ModifySCB.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1ModifySCB dialog

class CDlgM1ModifySCB : public CDialog
{
// Construction
public:
    CDlgM1ModifySCB(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1ModifySCB)
    enum { IDD = IDD_DLG_M1_MODIFY_SCB };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    CString m_csPwdA;
    CString m_csPwdB;
    CString m_csCtrlBytes;

    DWORD m_dwSectionNum;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1ModifySCB)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1ModifySCB)
    afx_msg void OnBtnModify();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGM1MODIFYSCB_H__CA5CCBCB_F3F1_425D_97DF_4DAE4D7FFBFC__INCLUDED_)
