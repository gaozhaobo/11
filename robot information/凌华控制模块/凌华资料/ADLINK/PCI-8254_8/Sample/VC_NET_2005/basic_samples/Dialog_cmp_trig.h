#pragma once

#include "APS168.h"
#include "APS_define.h"


// Dialog_cmp_trig dialog

class Dialog_cmp_trig : public CDialog
{
	DECLARE_DYNAMIC(Dialog_cmp_trig)

public:
	Dialog_cmp_trig(CWnd* pParent = NULL);   // standard constructor
	virtual ~Dialog_cmp_trig();

    

    virtual BOOL OnInitDialog();

	#define NO  (0)
	#define YES (1)

	CButton *p_bt_CmpTrig;
	CWnd    *p_ShowTrigCnt[4];
	I32 v_card_id;
	I32 v_card_name;
	I32 v_total_axis;
	I32 channel;
	
	I32 *p_Open;
	I32 *p_Close; 
	

// Dialog Data
	enum { IDD = IDD_DLG_CmpTrig };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnBnClickedButton3();
public:
	afx_msg void OnBnClickedButton5();
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnClose();
};
