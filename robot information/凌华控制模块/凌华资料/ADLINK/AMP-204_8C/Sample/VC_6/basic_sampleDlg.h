// basic_sampleDlg.h : header file
//

#if !defined(AFX_BASIC_SAMPLEDLG_H__19C0F219_EACD_4F71_BFCA_821366AA39F9__INCLUDED_)
#define AFX_BASIC_SAMPLEDLG_H__19C0F219_EACD_4F71_BFCA_821366AA39F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



//Adlink head file////////
#include "APS168.h"
#include "ErrorCodeDef.h"
#include "APS_define.h"
#include "type_def.h"
//////////////////////////

//Form head file//////////
#include "Get_Version.h"
#include "Axis_Monitor.h"
#include "CmpTrig.h"
#include "PWM_VAO.h"
//////////////////////////




/////////////////////////////////////////////////////////////////////////////
// CBasic_sampleDlg dialog

class CBasic_sampleDlg : public CDialog
{
// Construction
public:
	CBasic_sampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBasic_sampleDlg)
	enum { IDD = IDD_BASIC_SAMPLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasic_sampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBasic_sampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Initial();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void Close();
	afx_msg void Get_Version();
	afx_msg void Axis_Monitor();
	afx_msg void Load_Param();
	afx_msg void motion_done();
	afx_msg void homing();
	afx_msg void velocity_move();
	afx_msg void Jog();
	afx_msg void Jog_off();
	afx_msg void p2p();
	afx_msg void stop_move();
	afx_msg void EMG_stop();
	afx_msg void Line_2D();
	afx_msg void Arc_2D();
	afx_msg void Arc_3D();
	afx_msg void Helical_3D();
	afx_msg void Contour_2D();
	afx_msg void Point_table();
	afx_msg void Gear_Gantry();
	afx_msg void Interrupt();
	afx_msg void Digital_IO();
	afx_msg void Analog_IO();
	afx_msg void CMP_Trigger();
	afx_msg void pwm_vao();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


public:
    ////Main form data/////////////////////////////////////////////////////////////
    #define YES (1)
    #define NO  (0)
    #define ON  (1)
    #define OFF (0)

    I32 v_card_name;
    I32 v_board_id;         
    I32 v_channel;           
    I32 v_total_axis;        
    I32 v_is_card_initialed;
    //////////////////////////////////////////////////////////////////////////////////
	I32 Is_thread_creat;

	void Function_Result( I32 Ret );
	I32 Is_CARD_INITIAL(void);
	I32 Is_axis_err(I32 Axis_ID);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASIC_SAMPLEDLG_H__19C0F219_EACD_4F71_BFCA_821366AA39F9__INCLUDED_)
