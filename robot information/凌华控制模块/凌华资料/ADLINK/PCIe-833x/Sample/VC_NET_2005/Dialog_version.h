#pragma once


// CDialog_version dialog

class CDialog_version : public CDialog
{
	DECLARE_DYNAMIC(CDialog_version)

public:
	CDialog_version(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_version();

// Dialog Data
	enum { IDD = IDD_DLG_VERSION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

	int v_card_id;
};
