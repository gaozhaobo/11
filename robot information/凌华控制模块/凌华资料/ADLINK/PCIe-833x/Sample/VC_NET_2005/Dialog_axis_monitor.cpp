// Dialog_axis_monitor.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "Dialog_axis_monitor.h"
#include "dialogDataExchange.h"
#include "APS168.h"
#include "APS_define.h"
#include "sample_main.h"

// CDialog_axis_monitor dialog

IMPLEMENT_DYNAMIC(CDialog_axis_monitor, CDialog)

CDialog_axis_monitor::CDialog_axis_monitor(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_axis_monitor::IDD, pParent)
{
	//v_pParentPoint = NULL;
}

CDialog_axis_monitor::~CDialog_axis_monitor()
{
}

void CDialog_axis_monitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog_axis_monitor, CDialog)
//	ON_WM_CREATE()
ON_CBN_SELCHANGE(IDC_COMBO1, &CDialog_axis_monitor::OnCbnSelchangeCombo1)
ON_WM_TIMER()
//ON_WM_DESTROY()
//ON_WM_NCDESTROY()
//ON_WM_CREATE()
//ON_WM_SHOWWINDOW()
ON_BN_CLICKED(IDC_BUTTON1, &CDialog_axis_monitor::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CDialog_axis_monitor::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CDialog_axis_monitor::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDialog_axis_monitor message handlers




BOOL CDialog_axis_monitor::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	
	pCombo_select_axis = NULL;
	CComboBox *pComb = (CComboBox *)this->GetDlgItem( IDC_COMBO1 );
	if( pComb == NULL )
	{
		MessageBox( "CComboBox init err" );
		return TRUE;
	}

	// Find axis ID and initial combobox

	pComb->ResetContent();

	I32 start_axis_id = 0;
	I32 total_axes    = 0;
	I32 ret;
	CString str;
	I32 i;

	ret = APS_get_first_axisId( v_card_id, &start_axis_id, &total_axes );

	for( i = 0; i < total_axes; i++ )
	{
		str.Format( "%d", i + start_axis_id );
		pComb->AddString( str );
	}

	pComb->SetCurSel( 0 );

	v_start_axis_id    = start_axis_id;
	v_total_axes       = total_axes;
	v_selected_axis_id = start_axis_id;
	pCombo_select_axis = pComb;

	// initial status check box
	for( i = 0; i < MAX_MIO_CHECK; i++ )
		v_pCheck_motion_io[i] = (CButton *)this->GetDlgItem( IDC_CHECK1 + i );

	// Bit map initial
	v_motion_io_bit_map[DLG_ALM]  = MIO_ALM;
	v_motion_io_bit_map[DLG_PEL]  = MIO_PEL;
	v_motion_io_bit_map[DLG_MEL]  = MIO_MEL;
	v_motion_io_bit_map[DLG_ORG]  = MIO_ORG;
	v_motion_io_bit_map[DLG_EMG]  = MIO_EMG;
	v_motion_io_bit_map[DLG_EZ]   = MIO_EZ;
	v_motion_io_bit_map[DLG_INP]  = MIO_INP;
	v_motion_io_bit_map[DLG_SVON] = MIO_SVON;


	for( i = 0; i < MAX_MSTS_CHECK; i++ )
		v_pCheck_motion_status[i] = (CButton *)this->GetDlgItem( IDC_CHECK17 + i );


	v_motion_status_bit_map[DLG_CSTP]  = MTS_CSTP;
	v_motion_status_bit_map[DLG_VM]    = MTS_VM;
	v_motion_status_bit_map[DLG_ACC]   = MTS_ACC;
	v_motion_status_bit_map[DLG_DEC]   = MTS_DEC;
	v_motion_status_bit_map[DLG_DIR]   = MTS_DIR;
	v_motion_status_bit_map[DLG_MDN]   = MTS_NSTP;
	v_motion_status_bit_map[DLG_HMV]   = MTS_HMV;
	v_motion_status_bit_map[DLG_WAIT]  = 10;
	v_motion_status_bit_map[DLG_PTB]   = 11;
	v_motion_status_bit_map[DLG_JOG]   = MTS_JOG;
	v_motion_status_bit_map[DLG_ASTP]  = MTS_ASTP;
	v_motion_status_bit_map[DLG_BLD]   = 17;
	v_motion_status_bit_map[DLG_PRED]  = 18;
	v_motion_status_bit_map[DLG_POSTD] = 19;
	v_motion_status_bit_map[DLG_GER]   = 28;
	

	this->SetTimer( 0, 500, 0 );

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDialog_axis_monitor::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	
	if( pCombo_select_axis == NULL )
	{
		MessageBox( "CComboBox init err" );
		return;
	}

	v_selected_axis_id = v_start_axis_id + pCombo_select_axis->GetCurSel();
}

void CDialog_axis_monitor::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	AXIS_STATUS status;

	get_axis_status_example( v_selected_axis_id, &status );

	SetF64( this, IDC_EDIT1, status.command_position );
	SetF64( this, IDC_EDIT2, status.feedback_position );
	SetF64( this, IDC_EDIT3, status.target_position );
	SetF64( this, IDC_EDIT4, status.error_position  );
	SetF64( this, IDC_EDIT5, status.command_velocity );
	SetF64( this, IDC_EDIT6, status.feedback_velocity );

	int i;
	for( i = 0; i < MAX_MIO_CHECK; i++ )
		v_pCheck_motion_io[i]->SetCheck( 
			( status.motion_io     >> v_motion_io_bit_map[i]     ) & 1 );
	
	for( i = 0; i < MAX_MSTS_CHECK; i++ )
		v_pCheck_motion_status[i]->SetCheck( 
			( status.motion_status >> v_motion_status_bit_map[i] ) & 1 );
	

	CDialog::OnTimer(nIDEvent);
}


void CDialog_axis_monitor::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	CDialog::PostNcDestroy();
	//*this->v_pParentPoint = NULL;
	delete this;
}

void CDialog_axis_monitor::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	CDialog::OnCancel();
	this->DestroyWindow();
}


void CDialog_axis_monitor::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	APS_set_command_f(  v_selected_axis_id, 0.0 );
	APS_set_position_f( v_selected_axis_id, 0.0 );
}

void CDialog_axis_monitor::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	APS_set_servo_on( v_selected_axis_id, 1 );
}

void CDialog_axis_monitor::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	APS_set_servo_on( v_selected_axis_id, 0 );
}
