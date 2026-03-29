#ifndef _SAMPLE_8254_8_H
#define _SAMPLE_8254_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "APS168.h"

// version array index
#define IDX_VER1      (0)
#define IDX_VER2   (1)
#define IDX_VER3   (2)
#define IDX_VER4 (3)
#define IDX_VER5      (4)
#define IDX_MAX      (5)

typedef struct
{
	F64 command_position;
	F64 feedback_position;
	F64 target_position;
	F64 error_position;
	F64 command_velocity;
	F64 feedback_velocity;
	I32 motion_io;
	I32 motion_status;
}AXIS_STATUS;



void get_version_info( I32 *Array_size_5, I32 Board_ID );
void get_axis_status_example( I32 Axis_ID, AXIS_STATUS *P_Axis_status ,I32* ret);
void load_parameters_from_file_sample( const char *FilePath );

void home_move_example( I32 Axis_ID );
void deceleration_stop_example( I32 Axis_ID );
void emg_stop_example( I32 Axis_ID );
void jog_move_continuous_mode_example( I32 Axis_ID );
I32 p2p_example( I32 Axis_ID, I32 distance );
void interpolation_2D_line_example( I32 *Axis_ID_Array );
void DIO_sample( I32 Board_ID );
void Compare_trigger_example( I32 Board_ID );
void vel_example( I32 Axis_ID );

#ifdef __cplusplus
}

#endif

#endif

