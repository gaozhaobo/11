#if !defined(AFX_DLGDEVICEREG_H__C4143B11_A527_4C32_8C60_79128877EE45__INCLUDED_)
#define AFX_DLGDEVICEREG_H__C4143B11_A527_4C32_8C60_79128877EE45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDeviceReg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgDeviceReg dialog

class CDlgDeviceReg : public CDialog
{
// Construction
public:
    CDlgDeviceReg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgDeviceReg)
    enum { IDD = IDD_DLG_DEVICE_REG };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    DWORD   m_dwRetLen;
    CString m_csRetData;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgDeviceReg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgDeviceReg)
    afx_msg void OnBtnReg();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDEVICEREG_H__C4143B11_A527_4C32_8C60_79128877EE45__INCLUDED_)
