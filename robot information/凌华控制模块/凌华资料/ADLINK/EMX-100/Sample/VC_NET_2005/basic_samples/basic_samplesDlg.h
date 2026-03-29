// basic_samplesDlg.h : header file
//

#pragma once

#include "APS168.h"
#include "ErrorCodeDef.h"
#include "APS_define.h"

#include "Dialog_version.h"
#include "dialog_axis_monitor.h"



#define MAX_AXIS_MON_DLG  (8)
// Cbasic_samplesDlg dialog
class Cbasic_samplesDlg : public CDialog
{
// Construction
public:
	Cbasic_samplesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BASIC_SAMPLES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

DWORD  WINAPI thread_p2p2( LPVOID lpParameter );
private:

    #define NO  (0)
	#define YES (1)

	void Function_Result( I32 Ret );
	void Close_Process();

	int v_is_card_initialed;
	I32 v_card_id;
	//I32 v_test_axis_id;
	I32 v_first_axis_id;
	I32 v_card_name;
	I32 v_total_axis;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	void UI_Initial();


public:
		void updateUI();
	I32 v_test_axis_id;
	I32 Is_Open_CmpTrig;
	I32 Is_Open_PWM_VAO;

	I32 Is_Close_CmpTrig;
	I32 Is_Close_PWM_VAO;

public:
	CButton *p_bt_CmpTrig;
	CButton *p_bt_PWM_VAO;


public:
	//CDialog_axis_monitor *v_dlg_axis_mon[MAX_AXIS_MON_DLG];
public:
	afx_msg void OnBnClickedButton5();
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton9();
public:
	afx_msg void OnBnClickedButton10();
public:
	afx_msg void OnBnClickedButton12();
public:
	afx_msg void OnBnClickedButton11();
public:
	afx_msg void OnBnClickedButton13();
public:
	afx_msg void OnBnClickedButton14();
public:
	afx_msg void OnBnClickedButton20();
public:
	afx_msg void OnCbnSelchangeCombo1();
public:
	afx_msg void OnBnClickedButton25();	
public:
	afx_msg void OnBnClickedButton7();
};





#define _NOT_INITIAL  (0)
#define _INITIALED    (1)