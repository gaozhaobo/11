#if !defined(AFX_SUBDLGHIDTEST_H__AB186439_9E62_47E6_933C_5AF341401B76__INCLUDED_)
#define AFX_SUBDLGHIDTEST_H__AB186439_9E62_47E6_933C_5AF341401B76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDlgHidTest.h : header file


#include "UsbSDK.h"

//
/////////////////////////////////////////////////////////////////////////////
// CSubDlgHidTest dialog

#define MAX_USB_DEV_LEN 64

class CSubDlgHidTest : public CDialog
{
// Construction
public:
	CSubDlgHidTest(CWnd* pParent = NULL);   // standard constructor
	void PrintData(char* lpBuffer, const DWORD dwSize);
	void PrintInfo(CString csInfo);
	void AddNewDevInfo(USB_DEVICE_INFO *lpUsbDevInfo);

// Dialog Data
	//{{AFX_DATA(CSubDlgHidTest)
	enum { IDD = IDD_SUBDLG_HID_TEST };
		// NOTE: the ClassWizard will add data members here
	CListCtrl* m_pListHidDev;
	CEdit      m_edtInfo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubDlgHidTest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation


protected:

	BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CSubDlgHidTest)
	afx_msg void OnBtnEnumHid();
	afx_msg void OnBtnWrite();
	afx_msg void OnBtnLogin();
	afx_msg void OnBtnLogout();
	afx_msg void OnDestroy();
	afx_msg void OnCancelMode();
	afx_msg void OnItemchangedLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickLstHidDevInfo(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


private:

	int  m_nHidIndex;
	LONG m_lHidID;

	int  m_nHidDevNum;
	USB_DEVICE_INFO m_aHidDevInfo[MAX_USB_DEV_LEN];

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLGHIDTEST_H__AB186439_9E62_47E6_933C_5AF341401B76__INCLUDED_)
