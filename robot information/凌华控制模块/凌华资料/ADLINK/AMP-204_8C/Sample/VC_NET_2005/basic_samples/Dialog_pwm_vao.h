#pragma once

#include "APS168.h"
#include "APS_define.h"


// Dialog_pwm_vao dialog

class Dialog_pwm_vao : public CDialog
{
	DECLARE_DYNAMIC(Dialog_pwm_vao)

public:
	Dialog_pwm_vao(CWnd* pParent = NULL);   // standard constructor
	virtual ~Dialog_pwm_vao();


    #define YES  (1)
	#define NO   (0)
	#define ON   (1)
	#define OFF  (0)
	I32 v_total_axis;
	I32 v_card_id;
	I32 channel;

	I32 *p_Open;
	I32 *p_Close; 

	CButton *p_bt_PWM_VAO;
	CWnd    *p_show_pwm_freq[4];
	CWnd    *p_show_pwm_width[4];

	void Function_Result(int Ret);
	virtual BOOL OnInitDialog();

	
// Dialog Data
	enum { IDD = IDD_DLG_PWM_VAO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnClose();
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnBnClickedButton3();
};
