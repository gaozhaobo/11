#include <windows.h>
#include <math.h>
#include "sample_emx100.h"

#include "APS168.h"
#include "APS_define.h"
#include "ErrorCodeDef.h"


void get_version_info( I32 *Array_size_5, I32 Board_ID )
{
  // Get DLL Version
  Array_size_5[IDX_VER1] = APS_version();

  // Get EMX100 software version
  APS_get_device_info( Board_ID, 0x00, &Array_size_5[IDX_VER2] );
  
  // Get EMX100 middleware version
  APS_get_device_info( Board_ID, 0x01, &Array_size_5[IDX_VER3] ); 
  
  // Get EMX100 communication AP version
  APS_get_device_info( Board_ID, 0x11, &Array_size_5[IDX_VER4] );

  // Get EMX100 library version
  APS_get_device_info( Board_ID, 0x100, &Array_size_5[IDX_VER5] );
}

void get_axis_status_example( I32 Axis_ID, AXIS_STATUS *P_Axis_status,I32* error_code )
{
	I32 ret = 0;
	I32 cmd, pos, tar, err;
	I32 vell;

	ret=APS_get_command(Axis_ID, &cmd );
	if (ret == 0) P_Axis_status->command_position = cmd;
	else 
	{
		*error_code = ret;
		return;
	}
	ret=APS_get_position(Axis_ID, &pos  );
	if (ret == 0) P_Axis_status->feedback_position = pos;
	else 
	{
		  *error_code = ret;
		return;
	}
	ret=APS_get_target_position(Axis_ID, &tar );
	if (ret == 0) P_Axis_status->target_position = tar;
	else 
	{
		*error_code = ret;
		return;
	}
	ret=APS_get_error_position( Axis_ID, &err  );
	if (ret == 0) P_Axis_status->error_position = err;
	else 
	{
		*error_code = ret;
		return;
	}
	
	ret=APS_get_command_velocity( Axis_ID, &vell  );
	P_Axis_status->command_velocity = vell;
	P_Axis_status->feedback_velocity = 0;


	ret= APS_motion_io_status( Axis_ID );
	if (ret>=0) 
		P_Axis_status->motion_io =ret;

	    
	ret = APS_motion_status( Axis_ID );
	if (ret>=0) P_Axis_status->motion_status=ret;

}

void load_parameters_from_file_sample( const char *FilePath )
{
	APS_load_param_from_file( FilePath );
}

void home_move_example( I32 Axis_ID )
{
  //This example shows how home move operation
  I32 axis_id = Axis_ID;
  I32 return_code;

  // 1. Select home mode and config home parameters 
  APS_set_axis_param( axis_id, PRA_HOME_MODE,      0 ); // Set home mode
  APS_set_axis_param( axis_id, PRA_HOME_DIR,       1 ); // Set home direction
  APS_set_axis_param( axis_id, PRA_HOME_ACC, 1000000 ); // Set homing acceleration rate
  APS_set_axis_param( axis_id, PRA_HOME_VM,   100000 ); // Set homing maximum velocity.
  APS_set_axis_param( axis_id, PRA_HOME_VO,    50000 ); // Set homing VO speed
  APS_set_axis_param( axis_id, PRA_HOME_EZA,       0 ); // Set EZ signal alignment (yes or no)
  

  //Check servo on or not
  if( !( ( APS_motion_io_status( axis_id ) >> MIO_SVON ) & 1 ) )  
  {
	 APS_set_servo_on( axis_id, 1 ); 
	 Sleep( 500 ); // Wait stable.
  }

  // 2. Start home move
  return_code = APS_home_move( axis_id ); //Start homing 
  if( return_code != ERR_NoError )
  { /* Error handling */ }

}


void deceleration_stop_example( I32 Axis_ID )
{
	APS_stop_move( Axis_ID );
}

void emg_stop_example( I32 Axis_ID )
{
	// Stop immediately

	APS_emg_stop( Axis_ID );

}

void jog_move_continuous_mode_example( I32 Axis_ID )
{
	APS_set_axis_param( Axis_ID, PRA_JG_DIR,  0 );  // Set jog direction

	APS_set_axis_param( Axis_ID, PRA_JG_ACC, 1000 );
	APS_set_axis_param( Axis_ID, PRA_JG_DEC, 1000 );
	APS_set_axis_param( Axis_ID, PRA_JG_VM,  100  );

	//Check servo on or not
	if( !( ( APS_motion_io_status( Axis_ID ) >> MIO_SVON ) & 1 ) )  
	{
		APS_set_servo_on( Axis_ID, 1 ); 
		Sleep( 500 ); // Wait stable.
	}

	// Create a rising edge.
	//APS_jog_start( Axis_ID, 0 );  //Jog Off
	APS_jog_start( Axis_ID, 1 );  //Jog ON

	// Sleep( 200 );

	// APS_jog_start( I32 Axis_ID, I32 On ); // Jog off
}




I32 p2p_example( I32 Axis_ID, I32 distance )
{
	I32 ret = 0;
	
	// Config speed profile parameters.
	ret = APS_set_axis_param( Axis_ID, PRA_SF, 5      );
	ret = APS_set_axis_param( Axis_ID, PRA_ACC, 10000 );
	ret = APS_set_axis_param( Axis_ID, PRA_DEC, 10000 );

	//Check servo on or not
	if( !( ( APS_motion_io_status( Axis_ID ) >> MIO_SVON ) & 1 ) )  
	{
		ret = APS_set_servo_on( Axis_ID, 1 ); 
		Sleep( 500 ); // Wait stable.
	}

	// Start a relative p to p move
	ret = APS_relative_move( Axis_ID, distance, 5000 );

	//ret = APS_absolute_move( Axis_ID, 10000, 1000 );

	return ret;
}

void interpolation_2D_line_example( I32 *Axis_ID_Array )
{
	I32 PositionArray[2] = {1000.0 , 2000.0 };
	
	// config speed profile
	APS_set_axis_param( Axis_ID_Array[0], PRA_SF,  5     );
	APS_set_axis_param( Axis_ID_Array[0], PRA_ACC, 10000 );
	APS_set_axis_param( Axis_ID_Array[0], PRA_DEC, 10000 );
	APS_set_axis_param( Axis_ID_Array[0], PRA_VM,  1000  );

	//Check servo on or not
	if( !( ( APS_motion_io_status( Axis_ID_Array[0] ) >> MIO_SVON ) & 1 ) )  
	{
		APS_set_servo_on( Axis_ID_Array[0], 1 ); 
		Sleep( 500 ); // Wait stable.
	}

	//Check servo on or not
	if( !( ( APS_motion_io_status( Axis_ID_Array[1] ) >> MIO_SVON ) & 1 ) )  
	{
		APS_set_servo_on( Axis_ID_Array[1], 1 ); 
		Sleep( 500 ); // Wait stable.
	}

	//APS_absolute_linear_move( 2, Axis_ID_Array, PositionArray, 1000 );
	APS_relative_linear_move( 2, Axis_ID_Array, PositionArray, 1000 );
}




#define __MAX_DO_CH (14)
#define __MAX_DI_CH (32)
void DIO_sample( I32 Board_ID )
{
	/*
	I32 digital_output_value = 0;
	I32 digital_input_value  = 0;
	I32 do_ch[__MAX_DO_CH];
	I32 di_ch[__MAX_DI_CH];
	int i;*/

	I32 Ch_No = 2 ;
	I32 DO_Value ;
	I32 DO_Data;
	I32 DI_Data;
	I32 ret = 0;

	int i;
	APS_read_d_output(Board_ID,0, &DO_Data);
	APS_read_d_output(Board_ID,1, &DO_Data);
	APS_read_d_input(Board_ID,0, &DI_Data);
	APS_read_d_input(Board_ID,1, &DI_Data);
	APS_read_d_input(Board_ID,2, &DI_Data);
	APS_read_d_input(Board_ID,3, &DI_Data);
	Sleep(2000);
	APS_write_d_output(Board_ID,0, 255);
APS_write_d_output(Board_ID,1, 63);



	//****** Read digital output channels *****************************
/*
	APS_read_d_output( Board_ID
		, 0                     // I32 DO_Group
		, &digital_output_value // I32 *DO_Data
	);

	for( i = 0; i < __MAX_DO_CH; i++ )
		do_ch[i] = ( ( digital_output_value >> i ) & 1 );
*/
	//************ Write digital output channels examples *************
/*
	do_ch[0] = 1;  // set 0 or 1
	do_ch[2] = 1;  // set 0 or 1
	do_ch[4] = 1;  // set 0 or 1

	digital_output_value = 0;
	for( i = 0; i < __MAX_DO_CH; i++ )
		digital_output_value |= ( do_ch[i] << i );

	
	APS_write_d_output( Board_ID
		, 0                     // I32 DO_Group
		, digital_output_value  // I32 DO_Data
	);*/
	//*******************************************************************

	//**** Read digital input channels **********************************
/*
	APS_read_d_input( Board_ID
		, 0                    // I32 DI_Group
		, &digital_input_value // I32 *DI_Data
	);

	//for( i = 0; i < __MAX_DI_CH; i++ )
	for( i = 0; i < __MAX_DO_CH; i++ )
		di_ch[i] = ( ( digital_input_value >> i ) & 1 );
		*/
	//********************************************************************
}


void Compare_trigger_example( I32 Board_ID )
{
	I32 ret = 0;
	
	ret = APS_set_trigger_param( Board_ID, 0x0, 1 ); // Set axis 0 to compare encoder or command position
	ret = APS_set_trigger_param( Board_ID, 0x2, 2 ); // Set axis 0 compare condition
	ret = APS_set_trigger_param( Board_ID, 0x4, 100 ); // Set axis 0 compare value
	ret = APS_set_trigger_param( Board_ID, 0x6, 5 ); // Set axis 0 output pulse wdith
	ret = APS_set_trigger_param( Board_ID, 0x8, 0 ); // Set axis 0 output negative pulse
	ret = APS_set_trigger_param( Board_ID, 0xA, 1 ); // Enable axis 0 compare trigger function; The output signal is generated via TRG1 pin when compare condition is TRUE 
}


void vel_example( I32 Axis_ID )
{
	I32 ret = 0;

	ret = APS_velocity_move(Axis_ID, 1000);
}