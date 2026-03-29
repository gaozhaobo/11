// basic_samplesDlg.h : header file
//

#pragma once

#include "APS168.h"
#include "ErrorCodeDef.h"
#include "APS_define.h"

#include "Dialog_version.h"
#include "dialog_axis_monitor.h"
#include "Dialog_cmp_trig.h"
#include "Dialog_pwm_vao.h"


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


private:

    #define NO  (0)
	#define YES (1)

	void Function_Result( I32 Ret );
	void Close_Process();

	int v_is_card_initialed;
	I32 v_card_id;
	I32 v_test_axis_id;
	I32 v_first_axis_id;
	I32 v_card_name;
	I32 v_total_axis;
	I32 v_is_FieldBus_Start;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	
	
	afx_msg void OnBnClickedButton30();


	void UI_Initial();

public:
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
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnBnClickedButton8();
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
	afx_msg void OnBnClickedButton15();
public:
	afx_msg void OnBnClickedButton16();
public:
	afx_msg void OnBnClickedButton17();
public:
	afx_msg void OnBnClickedButton18();
public:
	afx_msg void OnBnClickedButton19();
public:
	afx_msg void OnBnClickedButton20();
public:
	afx_msg void OnBnClickedButton21();
public:
	afx_msg void OnCbnSelchangeCombo1();
public:
	afx_msg void OnBnClickedButton23();
public:
	afx_msg void OnBnClickedButton24();
public:
	afx_msg void OnBnClickedButton25();	

public:
	afx_msg void OnBnClickedButton26();
public:
	afx_msg void OnBnClickedButton27();
public:
	afx_msg void OnBnClickedButton28();
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton22();
};





#define _NOT_INITIAL  (0)
#define _INITIALED    (1)

#define _NOT_START_FIELD_BUS  (0)
#define _START_FIELD_BUS    (1)