// STI_SAMPLE.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "STI_SAMPLE.h"

#include "APS168.h"
#include "APS_define.h"
#include "dialogDataExchange.h"
#include "TimeMeasure.h"
// STI_SAMPLE dialog

IMPLEMENT_DYNAMIC(STI_SAMPLE, CDialog)

STI_SAMPLE::STI_SAMPLE(CWnd* pParent /*=NULL*/)
	: CDialog(STI_SAMPLE::IDD, pParent)
{

}

STI_SAMPLE::~STI_SAMPLE()
{
}

void STI_SAMPLE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(STI_SAMPLE, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &STI_SAMPLE::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &STI_SAMPLE::OnBnClickedButton1)
END_MESSAGE_MAP()


// STI_SAMPLE message handlers

void STI_SAMPLE::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnCancel();
	this->DestroyWindow();
}

void STI_SAMPLE::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::PostNcDestroy();
	delete this;
}

BOOL STI_SAMPLE::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	J_initial_tm();

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

	SetI32( this, IDC_EDIT1,  0 );  // S
	SetI32( this, IDC_EDIT2,  320000000  );  // acc
	SetI32( this, IDC_EDIT3,  320000000  );  // dec
	SetI32( this, IDC_EDIT4,  3300000    );  // mv
	SetI32( this, IDC_EDIT5,  43690      );  // distance
	SetI32( this, IDC_EDIT6,  100        );  // delay time

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void STI_SAMPLE::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here

	if( pCombo_select_axis == NULL )
	{
		MessageBox( "CComboBox init err" );
		return;
	}

	v_selected_axis_id = v_start_axis_id + pCombo_select_axis->GetCurSel();
}

void STI_SAMPLE::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	I32 Axis_ID = v_selected_axis_id;

	// Config speed profile parameters.
	APS_set_axis_param_f( Axis_ID, PRA_SF,  GetF64( this, IDC_EDIT1 ) );
	APS_set_axis_param_f( Axis_ID, PRA_ACC, GetF64( this, IDC_EDIT2 ) );
	APS_set_axis_param_f( Axis_ID, PRA_DEC, GetF64( this, IDC_EDIT3 ) );
	APS_set_axis_param_f( Axis_ID, PRA_VM,  GetF64( this, IDC_EDIT4 ) );

	//Check servo on or not
	if( !( ( APS_motion_io_status( Axis_ID ) >> MIO_SVON ) & 1 ) )  
	{
		APS_set_servo_on( Axis_ID, 1 ); 
		Sleep( 500 ); // Wait stable.
	}

	F64 dist = GetF64( this, IDC_EDIT5 );
	I32 msts;

	// Start a relative p to p move
	APS_ptp( Axis_ID, OPT_RELATIVE, dist , 0 );
	J_start_measure();
	
	do{
		Sleep(0);
		msts = ( APS_motion_status( Axis_ID ) >> MTS_NSTP ) & 1;// Get motion status
	}while( !msts );
	J_end_measure();

	SetF64( this, IDC_EDIT7, J_get_duration() ); //ms 


	/*
	if( g_is_thread_created == 0 )
	{
		I32 tmp;
		g_is_thread_created = 1;
		APS_get_axis_info( v_test_axis_id, &g_board_id, &g_axis_num, &tmp, &tmp );
		CreateThread( 0, 0, wait_interrupt_thread, 0, 0, &id );
		MessageBox( "Wait motion done thread is created.\n You can start a \"p2p\" move." );
	}else
	{
		MessageBox( "Thread already created" );
	}
	*/
}
