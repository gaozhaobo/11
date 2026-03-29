// ClientDemoDlg.h : header file
//

#if !defined(AFX_ClientDemoDLG_H__B90AFDB8_9478_4141_A21C_5312D9040A3D__INCLUDED_)
#define AFX_ClientDemoDLG_H__B90AFDB8_9478_4141_A21C_5312D9040A3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Dbt.h>
#include <map>
#include <vector>

#include "HCUsbSDK.h"

#include "SubDlgDevInterface.h"
#include "SubDlgGenInterface.h"
#include "SubDlgM1CardInterface.h"
#include "SubDlgCpuPsamCardInterface.h"
#include "SubDlgCertificateInfoInterface.h"
#include "SubDlgThermalInterface.h"
#include "SubDlgCameraInterface.h"
#include "SubDlgCameraControl.h"
#include "SubDlgTransmissionInterface.h"
#include "afxwin.h"

#define MAX_USB_DEV_LEN 64


/////////////////////////////////////////////////////////////////////////////
// CClientDemoDlg dialog

class CClientDemoDlg : public CDialog
{
// Construction
public:
    CClientDemoDlg(CWnd* pParent = NULL);	// standard constructor
    ~CClientDemoDlg();


    void AddNewDevInfo(USB_DEVICE_INFO *lpUsbDevInfo);
    BOOL isSame(USB_DEVICE_INFO *pDevceInfo);
    void UpdateUserID();

    BOOL isLogon(USB_DEVICE_INFO *pDevceInfo);
    DWORD GetActiveStatus(USB_DEVICE_INFO *pDevceInfo);

    LRESULT OnWMAddLog(WPARAM wParam, LPARAM lParam);

// Dialog Data
    //{{AFX_DATA(CClientDemoDlg)
    enum { IDD = IDD_DLG_CLIENT_DEMO };
        // NOTE: the ClassWizard will add data members here
    CTabCtrl   m_tabMain;
    CListCtrl* m_pListHidDev;
    //CEdit      m_edtInfo;
    CListCtrl* m_pListLog;

    CString m_csSDKVersion;
    CString m_csDemoVersion;

    CString m_csDeviceName;
    CString m_csSerialNumber;

    CString m_csUserName;
    CString m_csPassword;

    SubDlgDevInterface     m_dlgDev;
    SubDlgGenInterface     m_dlgGen;
    SubDlgM1CardInterface  m_dlgM1Card;
    CSubDlgCpuPsamCardInterface m_dlgCpuPsamCard;
    CSubDlgCertificateInfoInterface m_dlgCertificateInfo; 
    SubDlgThermalInterface m_dlgThermal;
    SubDlgCameraInterface m_dlgCamera;
	CSubDlgCameraControl m_dlgCameraControl;
    SubDlgTransmissionInterface m_dlgTransmission;
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CClientDemoDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;

    HDEVNOTIFY m_hDeviceNotify; 

    void GetVersionInfor();


    // Generated message map functions
    //{{AFX_MSG(CClientDemoDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnBtnEnumHid();
    afx_msg void OnBtnLogin();
    afx_msg void OnBtnLogout();
    afx_msg void OnDestroy();
    afx_msg void OnItemchangedLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnClickLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnBtnSetUserData();
    afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD_PTR dwData);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()


private:
    int  m_nHidIndex;

    DWORD m_lUserID;
    int m_nLogIndex;

    USB_USER_LOGIN_INFO m_struCurUsbLoginInfo;
    USB_DEVICE_INFO     m_struCurDeviceInfo;
    std::map<DWORD, USB_DEVICE_INFO> m_mLogonDev;
    std::vector<DWORD> m_LogonIdx;
    int  m_nHidDevNum;
    USB_DEVICE_INFO m_aHidDevInfo[MAX_USB_DEV_LEN];
public:
    afx_msg void OnBnClickedBtnActive();
    CComboBox m_combLoginMode;
	CButton m_btnIncludeAll;
	CButton m_btnSeparate;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ClientDemoDLG_H__B90AFDB8_9478_4141_A21C_5312D9040A3D__INCLUDED_)
