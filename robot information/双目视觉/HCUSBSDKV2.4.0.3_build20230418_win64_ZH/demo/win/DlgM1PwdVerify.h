#if !defined(AFX_DLGM1PWDVERIFY_H__3BBD8CB0_0D2B_4381_9553_9F8623BD16BC__INCLUDED_)
#define AFX_DLGM1PWDVERIFY_H__3BBD8CB0_0D2B_4381_9553_9F8623BD16BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1PwdVerify.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1PwdVerify dialog

class CDlgM1PwdVerify : public CDialog
{
// Construction
public:
    CDlgM1PwdVerify(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1PwdVerify)
    enum { IDD = IDD_DLG_M1_PWD_VERIFY };
        // NOTE: the ClassWizard will add data members here
     CComboBox	m_comPwdType;
    //}}AFX_DATA
     CString m_csPwd;
     DWORD   m_dwSectionNum;



// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1PwdVerify)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    
    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1PwdVerify)
    afx_msg void OnBtnVerify();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGM1PWDVERIFY_H__3BBD8CB0_0D2B_4381_9553_9F8623BD16BC__INCLUDED_)
