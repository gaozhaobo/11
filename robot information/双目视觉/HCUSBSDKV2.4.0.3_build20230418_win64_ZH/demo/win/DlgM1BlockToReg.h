#if !defined(AFX_DlgM1BlockToReg_H__97E0817C_BCEF_4F54_B54A_AF63EBFB9E68__INCLUDED_)
#define AFX_DlgM1BlockToReg_H__97E0817C_BCEF_4F54_B54A_AF63EBFB9E68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1BlockToReg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1BlockToReg dialog

class CDlgM1BlockToReg : public CDialog
{
// Construction
public:
    CDlgM1BlockToReg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1BlockToReg)
    enum { IDD = IDD_DLG_M1_EEPROM_2_REG };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    DWORD       m_dwBlockAddr;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1BlockToReg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1BlockMinus)
    afx_msg void OnBtnOk();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
        
        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgM1BlockToReg_H__97E0817C_BCEF_4F54_B54A_AF63EBFB9E68__INCLUDED_)
