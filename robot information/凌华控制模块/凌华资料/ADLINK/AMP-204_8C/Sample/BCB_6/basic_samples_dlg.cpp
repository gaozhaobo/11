
#include <vcl.h>
#pragma hdrstop

#include "basic_samples_dlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::_CHECK_CARD_INITIAL()
{
        if( v_is_card_initialed == _NOT_INITIAL )
        {
	        ShowMessage( "Card has not be initialed.");
        	return;
        }
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	I32 boardID_InBits = 0;
	//I32 mode           = INIT_AUTO_CARD_ID | INIT_PARAM_IGNORE;
	//I32 mode           = INIT_AUTO_CARD_ID | INIT_PARAM_LOAD_FLASH;
        I32 mode           = 0;
	I32 ret            = 0;
	I32 board_ID       = -1;
	I32 i;
	I32 card_name;

	// UI protection
	if( v_is_card_initialed == _INITIALED )
	{
		ShowMessage( "initial ok");
		return;
	}

        // Card(Board) initial
	//APS_register_virtual_board( 0, 1);
	ret = APS_initial( &boardID_InBits, mode );

	// Search card's ID

	if( ret == ERR_NoError )
	{
		for( i = 0; i < 16; i++ )
		{

			if( ( boardID_InBits >> i ) & 1 )
			{
				APS_get_card_name( i, &card_name );

                                if( ( card_name == DEVICE_NAME_PCI_825458  ) ||
                                    ( card_name == DEVICE_NAME_AMP_20408C )    )
				{
					board_ID = i;
                                        if (card_name == DEVICE_NAME_AMP_20408C )
                                                Button21->Enabled = false;
					break;
				}

			}
		}

		if( board_ID == -1 )
		{
			ShowMessage( "BoardId search error!" );
			return;
		}

		v_is_card_initialed = _INITIALED;
		v_card_id           = board_ID;


		I32 total_axes;
		APS_get_first_axisId( board_ID, &v_first_axis_id, &total_axes );

		v_test_axis_id = v_first_axis_id;

                //Determine numbers of trigger channels
                if     ( total_axes == 4 ) v_channel = 2;
                else if( total_axes == 8 ) v_channel = 4;

                //Display main form Caption text
                if( card_name == DEVICE_NAME_PCI_825458 && total_axes == 4 )
                        this->Caption = "PCI-8254 Basic Sample ";
                if( card_name == DEVICE_NAME_PCI_825458 && total_axes == 8 )
                        this->Caption = "PCI-8258 Basic Sample ";
                if( card_name == DEVICE_NAME_AMP_20408C && total_axes == 4 )
                        this->Caption = "AMP-204C Basic Sample ";
                if( card_name == DEVICE_NAME_AMP_20408C && total_axes == 8 )
                        this->Caption = "AMP-208C Basic Sample ";

		// Setup combol box
                ComboBox1->Items->Clear();
		for( i = 0; i < total_axes; i++ )
		{
                        ComboBox1->Items->Add(IntToStr(i));
		}

		ComboBox1->ItemIndex = 0;

		ShowMessage( "initial ok" );
	}
        else
	{
		ShowMessage("Error code is " + IntToStr(ret));
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        this->Caption = "Basic Sample ";  
	APS_close();
	v_is_card_initialed = _NOT_INITIAL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        if( v_is_card_initialed == _NOT_INITIAL )
        {
                ShowMessage( "Card has not be initialed.");
        	return;
        }

        TForm2 *vision = new TForm2(this);
        vision->v_card_id = v_card_id;
        vision->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	//_CHECK_CARD_INITIAL();
        
        if( v_is_card_initialed == _NOT_INITIAL )
        {
                ShowMessage( "Card has not be initialed.");
        	return;
        }

        TForm3 *vision = new TForm3(this);
        vision->v_card_id = v_card_id;
        vision->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        const char *FilePath;
        if(OpenDialog1->Execute())
        {
           FilePath = OpenDialog1->FileName.c_str();
           load_parameters_from_file_sample( FilePath );
        };
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	_CHECK_CARD_INITIAL();
	v_test_axis_id = v_first_axis_id + ComboBox1->ItemIndex;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	I32 ret;
	I32 stop_code;
	String str;

	ret = check_motion_done_example( v_test_axis_id, &stop_code );

	// Display motion done status
	switch( ret )
	{
	case 0:
		ShowMessage( "In motion" );
		break;
	case 1:
		ShowMessage( "Motion done" );
		break;
	case -1:
                str = "Error stop! stop code: " + IntToStr(stop_code) + " (" + (stop_code_to_string( stop_code )) + ")" ;
		ShowMessage( str );
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();
        
	home_move_example( v_test_axis_id );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();
        
	velocity_move_example( v_test_axis_id );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	jog_move_continuous_mode_example( v_test_axis_id );
	/**** Following are another two samples *********/
	//jog_move_step_mode_example( v_test_axis_id );
	// jog_move_via_DI_example( v_test_axis_id );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	// Create a falling edge.
	APS_jog_start( v_test_axis_id, 1 );
	APS_jog_start( v_test_axis_id, 0 );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	p2p_example( v_test_axis_id );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();
        
	deceleration_stop_example( v_test_axis_id );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();
        
	emg_stop_example( v_test_axis_id );
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button14Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	interpolation_2D_line_example( Axis_ID_Array );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();
        
	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	interpolation_2D_arc_example( Axis_ID_Array );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	I32 Axis_ID_Array[3];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;
	Axis_ID_Array[2] = v_test_axis_id + 2;

	interpolation_3D_arc_example( Axis_ID_Array );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	I32 Axis_ID_Array[3];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;
	Axis_ID_Array[2] = v_test_axis_id + 2;

	interpolation_3D_helical_example( Axis_ID_Array );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	contour_2D_example( Axis_ID_Array );
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button19Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();
	// TODO: Add your control notification handler code here

	if( pWaitInt == NULL )
	{
                I32 g_board_id;
                I32 g_axis_num;
                I32 tmp;
                
		APS_get_axis_info( v_test_axis_id, &g_board_id, &g_axis_num, &tmp, &tmp );
                pWaitInt = new TWaitInt(this);
                pWaitInt->g_board_id = g_board_id;
                pWaitInt->g_axis_num = g_axis_num;
                pWaitInt->Resume() ;
		ShowMessage( "Wait motion done thread is created.\n You can start a \"p2p\" move." );
		//AfxMessageBox( "interrupt occur" );
	}else
	{
		ShowMessage( "Thread already created" );
	}

}
//---------------------------------------------------------------------------
__fastcall TWaitInt::TWaitInt(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TWaitInt::Execute()
{
        //---- Place thread code here ----
	if( interrupt_example( this->g_board_id, this->g_axis_num ) == 0 )
		//AfxMessageBox( "interrupt occur" );
                ShowMessage( "interrupt occur" );

	Form1->pWaitInt = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	DIO_sample( v_card_id );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
	_CHECK_CARD_INITIAL();

	AIO_sample( v_card_id );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        Action = caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
        _CHECK_CARD_INITIAL() ;

	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	point_table_2D_example( v_card_id, Axis_ID_Array );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
        _CHECK_CARD_INITIAL()   ;

	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	gear_example( Axis_ID_Array );

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button24Click(TObject *Sender)
{
        if( v_is_card_initialed == _NOT_INITIAL )
        {
                ShowMessage( "Card has not be initialed.");
        	return;
        }

        TForm4 *p = new TForm4(this);
        p->v_card_id = v_card_id;
        p->v_channel = v_channel;
        p->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button25Click(TObject *Sender)
{
        if( v_is_card_initialed == _NOT_INITIAL )
        {
                ShowMessage( "Card has not be initialed.");
        	return;
        }

        TForm5 *p = new TForm5(this);
        p->v_card_id = v_card_id;
        p->v_channel = v_channel;
        p->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        this->Caption = "Basic Sample ";        
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

