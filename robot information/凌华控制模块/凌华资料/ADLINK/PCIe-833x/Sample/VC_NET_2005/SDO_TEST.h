#pragma once




#include "basic_samplesDlg.h"

// SDO_TEST dialog

class SDO_TEST : public CDialog
{
	DECLARE_DYNAMIC(SDO_TEST)

public:
	SDO_TEST(CWnd* pParent = NULL);   // standard constructor
	virtual ~SDO_TEST();

	Cbasic_samplesDlg *pMainForm;

// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	int v_is_card_initialed;
	I32 v_is_FieldBus_Start;

	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton29();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
