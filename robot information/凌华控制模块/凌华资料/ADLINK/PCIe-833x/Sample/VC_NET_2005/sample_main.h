#ifndef _SAMPLE_8254_8_H
#define _SAMPLE_8254_8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "APS168.h"

// version array index
#define IDX_DLL      (0)
#define IDX_DRIVER   (1)
#define IDX_KERNEL   (2)
#define IDX_FIRMWARE (3)
#define IDX_PCB      (4)
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
void get_axis_status_example( I32 Axis_ID, AXIS_STATUS *P_Axis_status );
void load_parameters_from_file_sample( const char *FilePath );

void home_move_example( I32 Axis_ID );

int  check_motion_done_example( I32 Axis_ID, I32 *Stop_Code );
const char *stop_code_to_string( I32 Stop_Code );

void velocity_move_example( I32 Axis_ID );

void deceleration_stop_example( I32 Axis_ID );
void emg_stop_example( I32 Axis_ID );

void jog_move_continuous_mode_example( I32 Axis_ID );
void jog_move_step_mode_example( I32 Axis_ID );
void jog_move_via_DI_example( I32 Axis_ID );

void p2p_example( I32 Axis_ID );

void interpolation_2D_line_example( I32 *Axis_ID_Array );
void interpolation_2D_arc_example( I32 *Axis_ID_Array );
void interpolation_3D_arc_example( I32 *Axis_ID_Array );
void interpolation_3D_helical_example( I32 *Axis_ID_Array );

void contour_2D_example( I32 *Axis_ID_Array );

I32  interrupt_example( I32 Board_ID, I32 Axis_num );
void interrupt_with_win32_handle_example( I32 Board_ID, I32 Axis_num );

void DIO_sample( I32 Board_ID );
void AIO_sample( I32 Board_ID );

void point_table_2D_example( I32 Board_ID, I32 *Axis_ID_Array );
void gear_example( I32 *Axis_ID_Array );

#ifdef __cplusplus
}
#endif

#endif

