// Axis_Monitor.cpp : implementation file
//

#include "stdafx.h"
#include "basic_sample.h"
#include "Axis_Monitor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAxis_Monitor dialog


CAxis_Monitor::CAxis_Monitor(CWnd* pParent /*=NULL*/)
	: CDialog(CAxis_Monitor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAxis_Monitor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAxis_Monitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAxis_Monitor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAxis_Monitor, CDialog)
	//{{AFX_MSG_MAP(CAxis_Monitor)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, servo_on)
	ON_BN_CLICKED(IDC_BUTTON2, servo_off)
	ON_BN_CLICKED(IDC_BUTTON3, reset_counter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAxis_Monitor message handlers

int CAxis_Monitor::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	SetTimer( 0, 1, NULL );
	
	return 0;
}

void CAxis_Monitor::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	KillTimer(0);
	
	CDialog::OnClose();
}

void CAxis_Monitor::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	I32 Axis_ID = 0;
    F64 tmp = 0;
    I32 sts = 0;
	CString str;


	for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
    {
		APS_get_command_f(Axis_ID, &tmp);
		str.Format( "%f", tmp );
        SetDlgItemText( EDIT_cmd_0 + Axis_ID, str );
                
        APS_get_position_f(Axis_ID, &tmp);
		str.Format( "%f", tmp );
        SetDlgItemText( EDIT_fb_0 + Axis_ID, str );
                
        APS_get_target_position_f(Axis_ID, &tmp);
		str.Format( "%f", tmp );
        SetDlgItemText( EDIT_tg_0 + Axis_ID, str );
                
        APS_get_error_position_f(Axis_ID, &tmp);
		str.Format( "%f", tmp );
        SetDlgItemText( EDIT_err_0 + Axis_ID, str );
                
        APS_get_command_velocity_f(Axis_ID, &tmp);
		str.Format( "%f", tmp );
        SetDlgItemText( EDIT_cv_0 + Axis_ID, str );
                
        APS_get_feedback_velocity_f(Axis_ID, &tmp);
		str.Format( "%f", tmp );
        SetDlgItemText( EDIT_fv_0 + Axis_ID, str );
                
        sts = APS_motion_io_status(Axis_ID);
		str.Format( "0x%x", sts );
        SetDlgItemText( EDIT_mio_0 + Axis_ID, str );
                
        sts = APS_motion_status(Axis_ID);
		str.Format( "0x%x", sts );
        SetDlgItemText( EDIT_msts_0 + Axis_ID, str );
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CAxis_Monitor::servo_on() 
{
	// TODO: Add your control notification handler code here
	 I32 Axis_ID = 0;

     for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
		 APS_set_servo_on(Axis_ID, ON);
}

void CAxis_Monitor::servo_off() 
{
	// TODO: Add your control notification handler code here

	 I32 Axis_ID = 0;

     for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
		 APS_set_servo_on(Axis_ID, OFF);
}

void CAxis_Monitor::reset_counter() 
{
	// TODO: Add your control notification handler code here

	I32 Axis_ID = 0;

    for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
    {
		APS_set_command_f(Axis_ID, 0.0);
        APS_set_position_f(Axis_ID, 0.0);
    }	
}
