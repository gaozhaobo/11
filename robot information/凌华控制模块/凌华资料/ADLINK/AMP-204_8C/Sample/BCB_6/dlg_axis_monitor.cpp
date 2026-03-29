//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlg_axis_monitor.h"
#include "basic_samples_dlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
        // Setup combol box
        ComboBox1->Items->Clear();
        I32 start_axis_id = 0;
        I32 total_axes    = 0;
        I32 i;

        APS_get_first_axisId( v_card_id, &start_axis_id, &total_axes );

        for( i = 0; i < total_axes; i++ )
        {
        ComboBox1->Items->Add(IntToStr(i));
        }
        ComboBox1->ItemIndex = 0;

	v_start_axis_id    = start_axis_id;
	v_total_axes       = total_axes;
	v_selected_axis_id = start_axis_id;


        // Bit map initial
        for (i = 0; i < MAX_MIO_CHECK; i++)
        {
                v_pCheck_motion_io[i] = dynamic_cast<TCheckBox *> (FindComponent("CheckBox"+IntToStr(i+1)));
        }

	v_motion_io_bit_map[DLG_ALM]  = MIO_ALM;
	v_motion_io_bit_map[DLG_PEL]  = MIO_PEL;
	v_motion_io_bit_map[DLG_MEL]  = MIO_MEL;
	v_motion_io_bit_map[DLG_ORG]  = MIO_ORG;
	v_motion_io_bit_map[DLG_EMG]  = MIO_EMG;
	v_motion_io_bit_map[DLG_EZ]   = MIO_EZ;
	v_motion_io_bit_map[DLG_INP]  = MIO_INP;
	v_motion_io_bit_map[DLG_SVON] = MIO_SVON;

        for (i = 0; i < MAX_MSTS_CHECK; i++)
        {
                v_pCheck_motion_status[i] = dynamic_cast<TCheckBox *> (FindComponent("CheckBox"+IntToStr(i+1+8)));
        }

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

        Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ComboBox1Change(TObject *Sender)
{
	v_selected_axis_id = v_start_axis_id + ComboBox1->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	APS_set_servo_on( v_selected_axis_id, 1 );        
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	APS_set_servo_on( v_selected_axis_id, 0 );
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	APS_set_command_f(  v_selected_axis_id, 0.0 );
	APS_set_position_f( v_selected_axis_id, 0.0 );
       
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
	AXIS_STATUS status;

	get_axis_status_example( v_selected_axis_id, &status );

	Label8->Caption = status.command_position;
	Label9->Caption = status.feedback_position;
	Label10->Caption = status.target_position;
	Label11->Caption = status.error_position;
	Label12->Caption = status.command_velocity;
	Label13->Caption = status.feedback_velocity;

	int i;
	for( i = 0; i < MAX_MIO_CHECK; i++ )
		v_pCheck_motion_io[i]->Checked = (( status.motion_io     >> v_motion_io_bit_map[i]     ) & 1 );

	for( i = 0; i < MAX_MSTS_CHECK; i++ )
		v_pCheck_motion_status[i]->Checked = (( status.motion_status >> v_motion_status_bit_map[i] ) & 1 );

}
//---------------------------------------------------------------------------
