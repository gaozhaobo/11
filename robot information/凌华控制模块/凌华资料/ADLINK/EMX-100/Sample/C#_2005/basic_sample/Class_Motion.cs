/****************************************************************************/
/*  Copyright (c) 2013, ADLink Technology Inc.  All rights reserved.        */
/*                                                                          */
/*  File Name   :   Class_Motion.cs                                         */
/*  Purpose     :   Basic Sample                                            */
/*  Date        :   2013/9/26                                               */
/*  Programmer  :   Chang Zhi Lin	                                        */
/****************************************************************************/
using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

using APS168_W64;
using APS_Define_W32;

namespace basic_sample
{
    class Class_Motion
    {
        public static Int32 check_motion_done_example(Int32 Axis_ID, ref Int32 Stop_Code)
        {
            Int32 axis_id = Axis_ID;
            Int32 msts = 0;
            Int32 m_stop_code = 0;

            msts = APS168.APS_motion_status(axis_id); // Get motion status
            msts = (msts >> 5) & 1;                   // Get motion done bit
          
            // Get stop code.
            APS168.APS_get_stop_code(Axis_ID, ref Stop_Code);

            if (msts == 1)
            {
                // Check move success or not
                msts = APS168.APS_motion_status(axis_id); // Get motion status
                msts = (msts >> 16) & 1;                  // Get abnormal stop bit
                
                if (msts == 1)
                { // Error handling ...

                    APS168.APS_get_stop_code(axis_id, ref m_stop_code);
                    return -1; //error
                }
                else
                {   // Motion success.
                    return 1;
                }
            }

            return 0; //Now are in motion
        }

        public static void home_move_example(Int32 Axis_ID)
        {
            //This example shows how home move operation
            Int32 axis_id = Axis_ID;
            Int32 return_code = 0;

            // 1. Select home mode and config home parameters 
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_HOME_MODE, 0); // Set home mode
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_HOME_DIR, 1); // Set home direction            
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_HOME_ACC, 1000000); // Set homing acceleration rate
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_HOME_VM, 100000); // Set homing maximum velocity.
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_HOME_VO, 50000); // Set homing VO speed
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_HOME_EZA, 0); // Set EZ signal alignment (yes or no)
            


            //servo on
            if (((APS168.APS_motion_io_status(axis_id) >> (Int32)APS_Define.MIO_SVON) & 1) == 0)
            {
                APS168.APS_set_servo_on(axis_id, 1);
                Thread.Sleep(500); // Wait stable.
            }     
            
            // 2. Start home move
            return_code = APS168.APS_home_move(axis_id); //Start homing 
            if (return_code != (Int32)APS_Define.ERR_NoError)
            { /* Error handling */ }
        }

        public static void velocity_move_example(Int32 Axis_ID)
        {
            Int32 axis_id  = Axis_ID;           
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_ACC, 10000); //Set acceleration rate
            APS168.APS_set_axis_param(axis_id, (Int32)APS_Define.PRA_DEC, 10000); //Set deceleration rate

            //servo on
            if (((APS168.APS_motion_io_status(axis_id) >> (Int32)APS_Define.MIO_SVON) & 1) == 0)
            {
                APS168.APS_set_servo_on(axis_id, 1);
                Thread.Sleep(500); // Wait stable.
            }       
            //go
            APS168.APS_velocity_move(axis_id,10000);
        }

        public static void jog_move_continuous_mode_example(Int32 Axis_ID)
        {
            
            APS168.APS_set_axis_param(Axis_ID, (Int32)APS_Define.PRA_JG_DIR, 0);  // Set jog direction            
            APS168.APS_set_axis_param(Axis_ID, (Int32)APS_Define.PRA_JG_ACC, 1000);
            APS168.APS_set_axis_param(Axis_ID, (Int32)APS_Define.PRA_JG_DEC, 1000);
            APS168.APS_set_axis_param(Axis_ID, (Int32)APS_Define.PRA_JG_VM, 100);

            //servo on
            if (((APS168.APS_motion_io_status(Axis_ID) >> (Int32)APS_Define.MIO_SVON) & 1) == 0)
            {
                APS168.APS_set_servo_on(Axis_ID, 1);
                Thread.Sleep(500); // Wait stable.
            }                       
            APS168.APS_jog_start(Axis_ID, 1);  //Jog ON
        }

        public static void p2p_example(Int32 Axis_ID)
        {
            Int32 ret = 0;
            

            // Config speed profile parameters.
            
            ret = APS168.APS_set_axis_param(Axis_ID, (Int32)APS_Define.PRA_ACC, 10000);
            ret = APS168.APS_set_axis_param(Axis_ID, (Int32)APS_Define.PRA_DEC, 10000);
            ret = APS168.APS_set_axis_param(Axis_ID, (Int32)APS_Define.PRA_VM, 1000);

            //servo on
            if (((APS168.APS_motion_io_status(Axis_ID) >> (Int32)APS_Define.MIO_SVON) & 1) == 0)
            {
                APS168.APS_set_servo_on(Axis_ID, 1);
                Thread.Sleep(500); // Wait stable.
            }

            // Start a relative p to p move
            ret = APS168.APS_relative_move(Axis_ID, 30000, 5000);
        }

        public static void deceleration_stop_example(Int32 Axis_ID)
        {       
            APS168.APS_stop_move(Axis_ID);
        }

        public static void emg_stop_example(Int32 Axis_ID)
        {
            // Stop immediately
            APS168.APS_emg_stop(Axis_ID);
        }
        public static void CMP_Trigger(Int32 Board_ID)
        {
            Int32 ret = 0;
            ret = APS168.APS_set_trigger_param(Board_ID, 0x0, 1); // Set axis 0 to compare encoder or command position
            ret = APS168.APS_set_trigger_param(Board_ID, 0x2, 2); // Set axis 0 compare condition
            ret = APS168.APS_set_trigger_param(Board_ID, 0x4, 100); // Set axis 0 compare value
            ret = APS168.APS_set_trigger_param(Board_ID, 0x6, 5); // Set axis 0 output pulse width
            ret = APS168.APS_set_trigger_param(Board_ID, 0x8, 0); // Set axis 0 output negative pulse
            ret = APS168.APS_set_trigger_param(Board_ID, 0xA, 1); // Enable axis 0 compare trigger function; The output signal is generated via TRG1 pin when compare condition is true
        }

        
        public static void DIO_sample( Int32 Board_ID )
        {           
        	
	        Int32 digital_output_value = 0;
	        Int32 digital_input_value  = 0;   
            	     
	        //****** Read digital output by group *****************************
	        APS168.APS_read_d_output( Board_ID, 0, ref digital_output_value);
            APS168.APS_read_d_output( Board_ID, 1, ref digital_output_value);
            //****** Read digital output by group *****************************
            APS168.APS_read_d_input(Board_ID, 0, ref digital_input_value);
            APS168.APS_read_d_input(Board_ID, 1, ref digital_input_value);
            APS168.APS_read_d_input(Board_ID, 2, ref digital_input_value);
            APS168.APS_read_d_input(Board_ID, 3, ref digital_input_value);

            //************ Write digital output by group examples *************
            APS168.APS_write_d_output(Board_ID, 0, 255);
            APS168.APS_write_d_output(Board_ID, 1, 63);
	        //*******************************************************************

	        
        }

        



    }
}
