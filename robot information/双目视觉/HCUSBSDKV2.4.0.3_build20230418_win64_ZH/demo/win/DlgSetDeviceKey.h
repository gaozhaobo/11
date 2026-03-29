#if !defined(AFX_DLGSETDEVICEKEY_H__BD1639CB_A686_4D65_ACA3_375AF5C1D329__INCLUDED_)
#define AFX_DLGSETDEVICEKEY_H__BD1639CB_A686_4D65_ACA3_375AF5C1D329__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSetDeviceKey.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetDeviceKey dialog

class CDlgSetDeviceKey : public CDialog
{
// Construction
public:
    CDlgSetDeviceKey(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgSetDeviceKey)
    enum { IDD = IDD_DLG_SET_DEV_KEY };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    CComboBox m_comKeyLen;

    CString m_csKey;

    CEdit m_edtKey;

    DWORD m_dwKeyLen;


    void PrintData(char* pBuffer, const DWORD dwSize);

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgSetDeviceKey)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgSetDeviceKey)
    afx_msg void OnBtnSetKey();
    afx_msg void OnSelchangeComKeyLen();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETDEVICEKEY_H__BD1639CB_A686_4D65_ACA3_375AF5C1D329__INCLUDED_)
