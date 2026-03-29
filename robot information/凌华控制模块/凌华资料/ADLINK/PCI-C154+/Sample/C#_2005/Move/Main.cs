using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using APS168_W64;
using APS_Define_W32;
using System.Runtime.InteropServices;


namespace CSharp_Sample
{
    public partial class Form1 : Form
    {
        Int16 CardID =0;	      //Card number for setting.
       
        
        Int32 Start_Axis_ID=0;  //First Axis number in Motion Net bus.
        Int32 TotalCard=0;

        Int32 AxisID_SingleAxis_ForAbsolute= 0;
        Int32 AxisID_SingleAxis_ForRelative= 0;
        Int32 AxisID_SingleAxis_ForHome= 0;

        Int32[] Axis_ID_Array_For_2Axes_Move = new Int32[2] {0,1};
        Int32[] Axis_ID_Array_For_2Axes_ArcMove = new Int32[2] {0,1};
        Int32[] Axis_ID_Array_For_3Axes_Move = new Int32[3] {0,1,2};
        Int32[] Axis_ID_Array_For_4Axes_Move = new Int32[4] {0,1,2,3};         
       
        bool FunctionFail=false;

        public Form1()
        {
            InitializeComponent();
        }


        public void Function_Result(Int32 Ret)
        {
            if (Ret != 0)
            {
                MessageBox.Show("Function Fail, ErrorCode  " + Ret.ToString());
                FunctionFail = true;
            }
            else
            {
                FunctionFail = false ;
            }
	    }
        private void Form1_Load(object sender, EventArgs e)
        {
            CardID = 0;            //Card number for setting.
            Start_Axis_ID = 0;     //First Axis number in Motion Net bus.
            Int32 DPAC_ID_Bits = 0;
            Int32 Info = 0;
            Int32 AxisNo = 0;
            Int32 i = 0, ret = 0, card_name = 0;

            AxisID_SingleAxis_ForAbsolute= Start_Axis_ID;
            AxisID_SingleAxis_ForRelative= Start_Axis_ID;
            AxisID_SingleAxis_ForHome= Start_Axis_ID;

            Axis_ID_Array_For_2Axes_Move[0] = Start_Axis_ID;
            Axis_ID_Array_For_2Axes_Move[1] = Start_Axis_ID + 1;
                            
            Axis_ID_Array_For_2Axes_ArcMove[0] = Start_Axis_ID;
            Axis_ID_Array_For_2Axes_ArcMove[1] = Start_Axis_ID + 1;

            Axis_ID_Array_For_3Axes_Move[0] = Start_Axis_ID;
            Axis_ID_Array_For_3Axes_Move[1] = Start_Axis_ID + 1;
            Axis_ID_Array_For_3Axes_Move[2] = Start_Axis_ID + 2;

            Axis_ID_Array_For_4Axes_Move[0] = Start_Axis_ID;
            Axis_ID_Array_For_4Axes_Move[1] = Start_Axis_ID + 1;
            Axis_ID_Array_For_4Axes_Move[2] = Start_Axis_ID + 2;
            Axis_ID_Array_For_4Axes_Move[3] = Start_Axis_ID + 3;
            
            //Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            
            if (APS168.APS_initial(ref DPAC_ID_Bits, 0) == 0)
            {
                for (i = 0; i < 16; i++)
                {
                    if ((DPAC_ID_Bits & (1 << i)) == 1)
                    {
                        ret = APS168.APS_get_card_name(i, ref card_name);
                        if (card_name == (Int32)APS_Define.DEVICE_NAME_PCI_C154_PLUS)
                        {
                            TotalCard = TotalCard + 1;
                            break;
                        }
                    }                 
                }
                //Get Card information

                APS168.APS_get_device_info(CardID, 0x10, ref Info);		//Get Driver Version
                Edit_ShowMaster_DriverVer.Text =  Info.ToString() ;
                Edit_ShowMaster_DLLVer.Text =  APS168.APS_version().ToString ();  //Get DLL Version

                APS168.APS_get_device_info(CardID, 0x20, ref Info);		//Get CPLD Version
                Edit_ShowMaster_CPLDVer.Text = Info.ToString() ;                
                //////////Set Axis Parameters//////////////////////////////////////////////////////////////////////////////
                for (AxisNo = 0; AxisNo < (4 * TotalCard); AxisNo++)
                {
                    Function_Result (APS168.APS_set_servo_on(AxisNo, 1));                  //servo ON            
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 0, 0));             //PEL/MEL input logic
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 4, 0));             //Set PRA_ALM_LOGIC           
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 128, 3));           //Set PRA_PLS_IPT_MODE(The user must make change based on actual conditions)
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 129, 4));           //Set PRA_PLS_OPT_MODE(The user must make change based on actual conditions)
                        
                    //Set Single Move Parameter
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 33, 1000000));      //Set Acceleration rate
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 34, 1000000));      //Set Deceleration rate
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 35, 0));            //Set Start velocity
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 32, 1));            //Set S-Curve
                        
                    //Set Home Move Parameter
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 16, 0));             //Set Home mode (Home search 1st mode)
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 21, 10000));         //Set Homing maximum Velocity (Unit:pulse/sec)            
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 25, 152));           //Set Homing leave home Velocity (Unit:pulse/sec)           
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 24, 0));             //Set Specify the EZ count up Value          
                    Function_Result (APS168.APS_set_axis_param(AxisNo, 26, 100));           //Set Homing leave home distance.Specify ORG Offset (Unit:pulse)
                      
                    //Set EMG logic
                    Function_Result(APS168.APS_set_axis_param(AxisNo, 561, 0));   //Select gpio input

                    //Set Pulser Parameter
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PSR_IPT_MODE, 0));       // 0 A B phase.
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PSR_IPT_DIR, 0));        // No inverse
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PSR_PDV, 0));            //Set PDV 0
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PSR_PMG, 0));            //Set PMG 0
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PSR_HOME_TYPE, 1));      //Home move type
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PSR_HOME_SPD, 5000));      //Home move maximum velocity
                  
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                MessageBox.Show(" Initial Success !! ");                
            }
            else
            {
                MessageBox.Show ("Initial Fail, Sample be Closed !!");
                Function_Result(APS168.APS_close());
            }   
        }          

        private void Btn_SingleAbsoluteMove_Backward_Click(object sender, EventArgs e)
        {
            Int32 Position = -10000;
            Int32 Max_Speed = 50000;
            //Others setting like ACC,Dec... are in the initial segmant.

            Function_Result((APS168.APS_absolute_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed)));
        }

        private void Btn_SingleAbsoluteMove_Forward_Click(object sender, EventArgs e)
        {
            Int32 Position = 10000;
            Int32 Max_Speed = 50000;            
            Function_Result((APS168.APS_absolute_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed)));	
        }

        private void Btn_SingleAbsoluteMove_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(AxisID_SingleAxis_ForAbsolute));	
        }

        private void Btn_SingleRelativeMove_Backward_Click(object sender, EventArgs e)
        {
            Int32 Distance = -10000;
            Int32 Max_Speed = 50000;
            //Others setting like ACC,Dec... are  in the initial segmant.

            Function_Result((APS168.APS_relative_move(AxisID_SingleAxis_ForRelative, Distance, Max_Speed)));
        }

        private void Btn_SingleRelativeMove_Forward_Click(object sender, EventArgs e)
        {
            Int32 Distance = 10000;
            Int32 Max_Speed = 50000;            
            Function_Result((APS168.APS_relative_move(AxisID_SingleAxis_ForRelative, Distance, Max_Speed)));	
        }

        private void Btn_SingleRelativeMove_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(AxisID_SingleAxis_ForRelative));		
        }

        private void Btn_SingleHomeMove_Backward_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_set_axis_param(AxisID_SingleAxis_ForHome, (Int32)APS_Define.PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
            Function_Result(APS168.APS_home_move(AxisID_SingleAxis_ForHome));	
        }

        private void Btn_SingleHomeMove_Forward_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_set_axis_param(AxisID_SingleAxis_ForHome, (Int32)APS_Define.PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
            Function_Result(APS168.APS_home_move(AxisID_SingleAxis_ForHome));		
        }

        private void Btn_SingleHomeMove_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(AxisID_SingleAxis_ForHome));		
        }

        private void Btn_Linear_2Axes_AbsoluteBackward_Click(object sender, EventArgs e)
        {
    	    Int32 Dimension=2;
 	        Int32 [] Position_Array= new Int32 [2]{-10000,-20000};
 	        Int32 Max_Linear_Speed=50000;
            Function_Result(APS168.APS_absolute_linear_move(Dimension,Axis_ID_Array_For_2Axes_Move,Position_Array, Max_Linear_Speed));
        }

        private void Btn_Linear_2Axes_AbsoluteForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension=2;
 	        Int32 [] Position_Array= new Int32 [2]{10000,20000};
 	        Int32 Max_Linear_Speed=50000;
            Function_Result((APS168.APS_absolute_linear_move(Dimension,Axis_ID_Array_For_2Axes_Move,Position_Array, Max_Linear_Speed)));
        }

        private void Btn_Linear_2Axes_AbsoluteStop_Click(object sender, EventArgs e)
        {
            Function_Result((APS168.APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0])));	
        }

        private void Btn_Linear_2Axes_RelateiveBackward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Position_Array = new Int32[2] { -10000, -20000 };
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed));
        }

        private void Btn_Linear_2Axes_RelateiveForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Position_Array = new Int32[2] { 10000, 20000 };
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_relative_linear_move(Dimension,  Axis_ID_Array_For_2Axes_Move,  Position_Array, Max_Linear_Speed));
        }

        private void Btn_Linear_2Axes_Relateive_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0]));
        }

        private void Btn_Linear_3Axes_AbsoluteBackward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 3;
            Int32[] Position_Array = new Int32[3] { -10000, -20000, -30000 };
            Int32 Max_Linear_Speed = 50000;
         	Function_Result (APS168.APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move,Position_Array, Max_Linear_Speed ));
        }

        private void Btn_Linear_3Axes_AbsoluteForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 3;
            Int32[] Position_Array = new Int32[3] { 10000, 20000 ,30000 };
            Int32 Max_Linear_Speed = 50000;
 	        Function_Result (APS168.APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move,Position_Array, Max_Linear_Speed ));	
        }

        private void Btn_Linear_3Axes_AbsoluteStop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
        }

        private void Btn_Linear_3Axes_RelateiveBackward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 3;
            Int32[] Position_Array = new Int32[3] { -10000, -20000, -30000 };
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed));		
        }

        private void Btn_Linear_3Axes_RelateiveForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 3;
            Int32[] Position_Array = new Int32[3] { 10000, 20000, 30000 };
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed));	
        }

        private void Btn_Linear_3Axes_Relateive_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
        }

        private void Btn_Linear_4Axes_AbsoluteBackward_Click(object sender, EventArgs e)
        {
	        Int32 Dimension=4;
 	        Int32 [] Position_Array=new Int32[4]{-10000,-20000,-30000,-40000};
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move,Position_Array, Max_Linear_Speed));
        }

        private void Btn_Linear_4Axes_AbsoluteForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 4;
            Int32[] Position_Array = new Int32[4] { 10000,20000, 30000, 40000 };
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_absolute_linear_move(Dimension,  Axis_ID_Array_For_4Axes_Move,  Position_Array, Max_Linear_Speed));
	
        }

        private void Btn_Linear_4Axes_AbsoluteStop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
        }

        private void Btn_Linear_4Axes_RelateiveBackward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 4;
            Int32[] Position_Array = new Int32[4] {-10000,-20000, -30000, -40000 };
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_relative_linear_move(Dimension,  Axis_ID_Array_For_4Axes_Move,  Position_Array, Max_Linear_Speed));		
	
        }

        private void Btn_Linear_4Axes_RelateiveForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 4;
            Int32[] Position_Array = new Int32[4] { 10000, 20000, 30000, 40000 };
            Int32 Max_Linear_Speed = 50000;
            Function_Result(APS168.APS_relative_linear_move(Dimension,  Axis_ID_Array_For_4Axes_Move,  Position_Array, Max_Linear_Speed));   	
        }

        private void Btn_Linear_4Axes_Relateive_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
        }
            
        private void Btn_ResetCounter_Click(object sender, EventArgs e)
        {
            Int32 AxisNo = 0;
            for (AxisNo=Start_Axis_ID; AxisNo<=(Start_Axis_ID+3); AxisNo++)
            {
                Function_Result(APS168.APS_set_command(AxisNo, 0));
                Function_Result(APS168.APS_set_position(AxisNo, 0));
                Function_Result(APS168.APS_emg_stop(AxisNo));
                if (FunctionFail)
                {
                    MessageBox.Show("Reset Counter Fail !!");
                }
            }
        }




        private void timer1_Tick(object sender, EventArgs e)
        {
            Int32 Command=0;
            Int32 Position = 0;
            Int32 MotionSts = 0;
            Int32 IoSts = 0;
            Int32 index = 0;        
          
            System.Windows.Forms.TextBox[] CommandArray = new TextBox[4] { Edit_ShowAxis_Command_0, Edit_ShowAxis_Command_1, Edit_ShowAxis_Command_2, Edit_ShowAxis_Command_3 };
            System.Windows.Forms.TextBox[] Feedback = new TextBox[4] { _Edit_ShowAxis_Feedback_0, _Edit_ShowAxis_Feedback_1, _Edit_ShowAxis_Feedback_2, _Edit_ShowAxis_Feedback_3 };
            System.Windows.Forms.TextBox[] IOSts = new TextBox[4] { _Edit_ShowAxis_IOSts_0, _Edit_ShowAxis_IOSts_1, _Edit_ShowAxis_IOSts_2, _Edit_ShowAxis_IOSts_3 };
            System.Windows.Forms.TextBox[] MSts = new TextBox[4] { _Edit_ShowAxis_MSts_0, _Edit_ShowAxis_MSts_1, _Edit_ShowAxis_MSts_2, _Edit_ShowAxis_MSts_3 };
            
            
            for (index = 0; index < 4; index++)
            {
                
               APS168.APS_get_command(Start_Axis_ID + index, ref Command);
               CommandArray[index].Text = Command.ToString();
              
               APS168.APS_get_position(Start_Axis_ID + index, ref Position);
               Feedback[index].Text = (Position.ToString());
              
               IoSts = APS168.APS_motion_io_status(Start_Axis_ID + index);
               IOSts[index].Text = Convert.ToString(IoSts, 16);   //轉16進制

               MotionSts = APS168.APS_motion_status(Start_Axis_ID + index);
               MSts[index].Text = Convert.ToString(MotionSts, 16);   //轉16進制             
               
            }	
        }
        
        private void Btn_Arc_2Axes_Absolute_CCW_Click(object sender, EventArgs e)
        {
            Int32 Dimension=2;
            Int32[] Center_Pos_Array = new Int32[2] { 20000, 20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = 180;
            Function_Result(APS168.APS_absolute_arc_move(Dimension,  Axis_ID_Array_For_2Axes_ArcMove,  Center_Pos_Array, Max_Arc_Speed, Angle));
        }

        private void Btn_Arc_2Axes_Absolute_CW_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Center_Pos_Array = new Int32[2] { 20000, 20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = (-180);
            Function_Result(APS168.APS_absolute_arc_move(Dimension,  Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle));
        }

        private void Btn_Arc_2Axes_Relative_CCW_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Center_Pos_Array = new Int32[2] { 20000, 20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = 180;
            Function_Result(APS168.APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle));
        }

        private void Btn_Arc_2Axes_Relative_CW_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Center_Pos_Array = new Int32[2] { 20000, 20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = (-180);
            APS168.APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle);
        }

        private void Btn_Arc_2Axes_Absolute_Stop2_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_2Axes_ArcMove[0]));	
        }

        private void Btn_Arc_2Axes_Relateive_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_2Axes_ArcMove[0]));	
        }

        private void button1_Click(object sender, EventArgs e)
        {
            CardID = Int16.Parse(textBox1.Text);

            if (CardID >= TotalCard)
            { MessageBox.Show("The CardID is not exit !!"); }
            else
            {
                Start_Axis_ID = CardID * 4;

                AxisID_SingleAxis_ForAbsolute = Start_Axis_ID;
                AxisID_SingleAxis_ForRelative = Start_Axis_ID;
                AxisID_SingleAxis_ForHome = Start_Axis_ID;

                Axis_ID_Array_For_2Axes_Move[0] = Start_Axis_ID;
                Axis_ID_Array_For_2Axes_Move[1] = Start_Axis_ID + 1;

                Axis_ID_Array_For_2Axes_ArcMove[0] = Start_Axis_ID;
                Axis_ID_Array_For_2Axes_ArcMove[1] = Start_Axis_ID + 1;

                Axis_ID_Array_For_3Axes_Move[0] = Start_Axis_ID;
                Axis_ID_Array_For_3Axes_Move[1] = Start_Axis_ID + 1;
                Axis_ID_Array_For_3Axes_Move[2] = Start_Axis_ID + 2;

                Axis_ID_Array_For_4Axes_Move[0] = Start_Axis_ID;
                Axis_ID_Array_For_4Axes_Move[1] = Start_Axis_ID + 1;
                Axis_ID_Array_For_4Axes_Move[2] = Start_Axis_ID + 2;
                Axis_ID_Array_For_4Axes_Move[3] = Start_Axis_ID + 3;

                MessageBox.Show("Set CardID = " + CardID.ToString());
            }
        }

        private void PulserEanble_Click(object sender, EventArgs e)
        {
            

            Function_Result(APS168.APS_manual_pulser_start(0,Int16.Parse(PulserEnableAxis.Text)));	
            
        }

        private void PulserRlativeMove_Click(object sender, EventArgs e)
        {

            Function_Result(APS168.APS_manual_pulser_relative_move(Int16.Parse(PulserRelativeAixs.Text), Int16.Parse(PulserRelativeDistance.Text), Int16.Parse(PulserRelativeMaxV.Text)));
        }

        private void PulserVelocityMove_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_manual_pulser_velocity_move(Int16.Parse(PulserVelocityAixs.Text), Int16.Parse(PulserVelocityMaxV.Text)));
        }

        private void PulserHomeMove_Click(object sender, EventArgs e)
        {

            Function_Result(APS168.APS_manual_pulser_home_move(Int16.Parse(PulserHomeAixs.Text)));
            
        }   
        
    }
}