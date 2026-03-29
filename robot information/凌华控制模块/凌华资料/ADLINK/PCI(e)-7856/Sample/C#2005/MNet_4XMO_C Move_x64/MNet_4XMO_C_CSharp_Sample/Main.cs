using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
//using APS168_W32;
using APS168_W64;
using APS_Define_W32;
using System.Runtime.InteropServices;


namespace MNet_4XMO_C_CSharp_Sample
{
    public partial class Form1 : Form
    {
        Int16 CardID =0;	      //Card number for setting.
        Int16 BusNo  =1;        //Bus number for setting,  Motion Net BusNo is 0.
        Int32 MOD_No =0;		  //Arrcoding switch On Module. 	
        Int32 Start_Axis_ID=0;  //First Axis number in Motion Net bus.
        Int32 AxisID_SingleAxis_ForAbsolute= 0;
        Int32 AxisID_SingleAxis_ForRelative= 1;
        Int32 AxisID_SingleAxis_ForHome= 2;
        Int32 AxisID_FirstAxis_For_PointTable=0;
        Int32 Dimension_For_PointTable=4;
        Int32 [] Axis_ID_Array_For_2Axes_Move=new Int32 [2]{0,1};
        Int32[] Axis_ID_Array_For_2Axes_ArcMove = new Int32[2] { 0, 1 };
        Int32 [] Axis_ID_Array_For_3Axes_Move=new Int32 [3]{0,1,2};
        Int32 [] Axis_ID_Array_For_4Axes_Move=new Int32 [4]{0,1,2,3};
        Int32 [] Axis_ID_Array_For_PointTable=new Int32 [4]{0,1,2,3};

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
            //Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            Int32  DPAC_ID_Bits=0;
            Int32  Info=0;

            if (APS168.APS_initial(ref DPAC_ID_Bits, 0) == 0)
            {      //Initial Card, CardID is assigned by system.
                //Get Card information
                APS168.APS_get_device_info(CardID, 0x10, ref Info);		//Get Driver Version
                Edit_ShowMaster_DriverVer.Text =  Info.ToString() ;

                Edit_ShowMaster_DLLVer.Text =  APS168.APS_version().ToString ();  //Get DLL Version

                APS168.APS_get_device_info(CardID, 0x20, ref Info);		//Get CPLD Version
                Edit_ShowMaster_CPLDVer.Text = Info.ToString() ;

                //Set Motion Net Parameter
                Function_Result(APS168.APS_set_field_bus_param(CardID, BusNo, (Int32)APS_Define.PRF_TRANSFER_RATE, 3));     //Set PRF_TRANSFER_RATE: 3 (12M)
            }
            else
            {
                MessageBox.Show ("Initial Fail, sample close!!");
                APS168.APS_close();
            }   
        }

        private void Btn_BusConnect_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_start_field_bus(CardID, BusNo, Start_Axis_ID));

            if (!FunctionFail)
            {
                //Set Axis Parameter
                for (int AxisNo = Start_Axis_ID; AxisNo < 4; AxisNo++)
                {
                    //IO and Pulse Mode
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_ALM_LOGIC, 0));       //Set PRA_ALM_LOGIC
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PLS_IPT_MODE, 2));    //Set PRA_PLS_IPT_MODE
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PLS_OPT_MODE, 1));    //Set PRA_PLS_OPT_MODE
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_PLS_IPT_LOGIC, 1));   //Set PRA_PLS_IPT_LOGIC
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_FEEDBACK_SRC, 1));   //Select feedback conter


                    //Single Move Parameter
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_CURVE, 0));			  //Set PRA_CURVE  0:T-Curve 1:S-Curve
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_ACC, 10000000));		  //Set PRA_ACC 
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_DEC, 10000000));		  //Set PRA_DEC
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_VS, 0));			  //Set PRA_VS


                    //Home Move Parameter
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_HOME_MODE, 0));		  //Set PRA_HOME_MODE
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_HOME_VM, 10000));	  //Set PRA_HOME_VM
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_HOME_EZA, 0));		  //Set PRA_HOME_EZA 
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_HOME_VO, 100));		  //Set PRA_HOME_VO
                    Function_Result(APS168.APS_set_axis_param(AxisNo, (Int32)APS_Define.PRA_HOME_OFFSET, 500));	  //Set PRA_HOME_OFFSET 
                }

                MessageBox.Show ("Bus Connected!!");
            }
            else
            {
                FunctionFail = false;
                MessageBox.Show ("Connect Fail!!");
            }
        }

        private void Btn_BusDisconnect_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_stop_field_bus(CardID, BusNo));
        }

        private void Btn_GetModuleInfo_Click(object sender, EventArgs e)
        {
            Int32 Info=0;
            Function_Result(APS168.APS_get_field_bus_device_info(CardID,		//Get FPGA Version
                                                         BusNo,
                                                         Int32.Parse (Edit_SetModuleID_ForModuleInfo.Text) ,
                                                         0x21,
                                                         ref Info));
            Edit_ShowModule_FPGAVer.Text = Info.ToString();


            Function_Result(APS168.APS_get_field_bus_device_info(CardID, BusNo, Int32.Parse(Edit_SetModuleID_ForModuleInfo.Text), 0x30, ref Info));   //Get PCB Top Version
            Edit_ShowModule_PCBTopVer.Text =  Info.ToString();

            Function_Result(APS168.APS_get_field_bus_device_info(CardID, BusNo, Int32.Parse(Edit_SetModuleID_ForModuleInfo.Text), 0x31, ref Info));    //Get PCB Bottom Version
            Edit_ShowMaster_PCBBottomVer.Text = Info.ToString();
            
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
            //Others setting like ACC,Dec... are in the initial segmant.

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
            //Others setting like ACC,Dec... are in the initial segmant.

            Function_Result((APS168.APS_relative_move(AxisID_SingleAxis_ForRelative, Distance, Max_Speed)));	
        }

        private void Btn_SingleRelativeMove_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(AxisID_SingleAxis_ForRelative));		
        }

        private void Btn_SingleHomeMove_Backward_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_set_axis_param(AxisID_SingleAxis_ForHome, (Int32)APS_Define.PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
            //Others setting like ACC,Dec... are in the initial segmant.

            Function_Result(APS168.APS_home_move(AxisID_SingleAxis_ForHome));	
        }

        private void Btn_SingleHomeMove_Forward_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_set_axis_param(AxisID_SingleAxis_ForHome, (Int32)APS_Define.PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
            //Others setting like ACC,Dec... are in the initial segmant.

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
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_absolute_linear_move(Dimension,Axis_ID_Array_For_2Axes_Move,Position_Array, Max_Linear_Speed));
        }

        private void Btn_Linear_2Axes_AbsoluteForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension=2;
 	        Int32 [] Position_Array= new Int32 [2]{10000,20000};
 	        Int32 Max_Linear_Speed=50000;
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

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
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed));
        }

        private void Btn_Linear_2Axes_RelateiveForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Position_Array = new Int32[2] { 10000, 20000 };
            Int32 Max_Linear_Speed = 50000;
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed));
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
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
         	Function_Result (APS168.APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move,Position_Array, Max_Linear_Speed ));
        }

        private void Btn_Linear_3Axes_AbsoluteForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 3;
            Int32[] Position_Array = new Int32[3] { 10000, 20000 ,30000 };
            Int32 Max_Linear_Speed = 50000;
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	        Function_Result (APS168.APS_absolute_linear_move( Dimension,Axis_ID_Array_For_3Axes_Move,Position_Array, Max_Linear_Speed ));	
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
            //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed));		
        }

        private void Btn_Linear_3Axes_RelateiveForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 3;
            Int32[] Position_Array = new Int32[3] { 10000, 20000, 30000 };
            Int32 Max_Linear_Speed = 50000;
            //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

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
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed));
        }

        private void Btn_Linear_4Axes_AbsoluteForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 4;
            Int32[] Position_Array = new Int32[4] { 10000,20000, 30000, 40000 };
            Int32 Max_Linear_Speed = 50000;
            //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed));
	
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
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed));		
	
        }

        private void Btn_Linear_4Axes_RelateiveForward_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 4;
            Int32[] Position_Array = new Int32[4] { 10000, 20000, 30000, 40000 };
            Int32 Max_Linear_Speed = 50000;
 	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed));   	
        }

        private void Btn_Linear_4Axes_Relateive_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
        }


        private void Btn_SetPointTable_Click(object sender, EventArgs e)
        {
            Int32 Index = 0;
            Int32 LastIndex = 20;
            POINT_DATA2 PointData = new POINT_DATA2 ();
           

            Function_Result(APS168.APS_set_point_table_mode2(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 0));	//0:Single 1:continue

            for (Index = 0; Index < LastIndex; Index++)
            {
                PointData.i32_pos[0] = (Index + 1) * 1000;	//Position data = Index * 10000;
                PointData.i32_pos[1] = (Index + 1) * 1000;	//Position data = Index * 10000;
                PointData.i32_pos[2] = (Index + 1) * 1000;	//Position data = Index * 10000;
                PointData.i32_pos[3] = (Index + 1) * 1000;	//Position data = Index * 10000;
                

                PointData.i32_maxSpeed = 0;
                if (Index == 0)
                {				//If Index be first or last index, initSpeed be 0.
                    PointData.i32_initSpeed = 0;						// Start velocity	( pulse / s ) 
                    PointData.i32_maxSpeed = 50000;					// Maximum velocity  ( pulse / s ) 	
                    PointData.i32_angle = 0;
                }
                else
                {												//Others index iniSpeed and maxSpeed are the same.
                    PointData.i32_initSpeed = 50000;	// Start velocity	( pulse / s ) 
                    PointData.i32_maxSpeed = 50000;				    // Maximum velocity  ( pulse / s ) 
                }

                if (Index == (LastIndex -1))
                {
                    PointData.i32_opt = 0x21; // Option //0xABCD , D:0 absolute, 1:relative
                }
                else
                {
                    PointData.i32_opt = 0x1; // Option //0xABCD , D:0 absolute, 1:relative
                }
                PointData.u32_dwell = 0;								// Dwell times       ( unit: ms ) 
                

                //Marshal.StructureToPtr(PointData, buffPtr, true);
                Function_Result(APS168.APS_set_point_table2(Dimension_For_PointTable,
                                                        ref Axis_ID_Array_For_PointTable[0],
                                                       Index,
                                                       ref PointData));
                 
                if (FunctionFail)
                {
                    break;
                }
            }

            
            
        }

       
        private void Btn_PointTable_SingleIndexMove_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_point_table_single_move2(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], Int32.Parse (Edit_SetTargetIndex_ForSinglePointMove.Text)));	
        }

        private void Btn_PointTable_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable]));
        }

        private void Btn_PointTable_MoveALL_Click(object sender, EventArgs e)
        {
            Int32  Index = 0;
            Int32 LastIndex = 20;
            POINT_DATA2 PointData = new POINT_DATA2();
            IntPtr buffPtr = new IntPtr(6 * 32 * 8);

            Function_Result(APS168.APS_set_point_table_mode2(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 1));	//0:Single 1:continue

            for (Index = 0; Index < LastIndex; Index++)
            {
                PointData.i32_pos[0] = (Index + 1) * 1000;	//Position data = Index * 10000;
                PointData.i32_pos[1] = (Index + 1) * 1000;	//Position data = Index * 10000;
                PointData.i32_pos[2] = (Index + 1) * 1000;	//Position data = Index * 10000;
                PointData.i32_pos[3] = (Index + 1) * 1000;	//Position data = Index * 10000;

                PointData.i32_maxSpeed = 0;
                if (Index == 0) 
                {				//If Index be first or last index, initSpeed be 0.
                    PointData.i32_initSpeed = 0;						// Start velocity	( pulse / s ) 
                    PointData.i32_maxSpeed = 50000;					// Maximum velocity  ( pulse / s ) 	
                    PointData.i32_angle = 0;
                }
                else
                {												//Others index iniSpeed and maxSpeed are the same.
                    PointData.i32_initSpeed = PointData.i32_maxSpeed;	// Start velocity	( pulse / s ) 
                    PointData.i32_maxSpeed = 50000;				    // Maximum velocity  ( pulse / s ) 
                }

                if (Index == (LastIndex - 1))
                {
                    PointData.i32_opt = 0x21; // Option //0xABCD , D:0 absolute, 1:relative
                }
                else
                {
                    PointData.i32_opt = 0x1; // Option //0xABCD , D:0 absolute, 1:relative
                }
                PointData.u32_dwell = 0;								// Dwell times       ( unit: ms ) 
                //In Continue mode, absolute is useless. 

                //Marshal.StructureToPtr(PointData, buffPtr, true);
                Function_Result(APS168.APS_set_point_table2(Dimension_For_PointTable,
                                                       ref Axis_ID_Array_For_PointTable[0],
                                                       Index,
                                                       ref PointData));
                if (FunctionFail)
                {
                    break;
                }

            }

            Marshal.FreeHGlobal(buffPtr);

            Function_Result(APS168.APS_point_table_continuous_move2(Dimension_For_PointTable, ref Axis_ID_Array_For_PointTable[0]));
        }

        private void Btn_Linear_Compare_Click(object sender, EventArgs e)
        {
            Int32 StartPoint = 5000;
            Int32 RepeatTimes = 100;
            Int32 Interval = 100;
            Int32 LastIndex = 4;

            for (int Index = 0; Index < LastIndex; Index++)
            {
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_CMP0_SRC + Index, 0));		//Compare source is from command counter.
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_CMP0_TYPE + Index, 1));		//Compare type is Linear.
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_TRG0_PWD + Index, 5));		//Trigger Width is 60nS
                Function_Result(APS168.APS_set_field_bus_trigger_linear(CardID, BusNo, MOD_No, Index, StartPoint, RepeatTimes, Interval));   //Set Linear Data
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_CMP0_EN + Index, 1));		//Enable Linear compare
                if (FunctionFail)
                {
                    break;
                }

            }

            Btn_Trigger_Count_Click(sender, e);		//Reset Trigger Counter, it's not nerssery.
            Btn_ResetCounter_Click(sender, e);		//Reset Axis Counter Counter, it's not nerssery.
            Btn_Linear_4Axes_RelateiveForward_Click(sender, e);	

        }

        private void Btn_Table_Compare_Click(object sender, EventArgs e)
        {
            Int32 ArraySize = 100;
            Int32 [] DataArray = new Int32 [ArraySize];
            Int32 LastIndex = 4;

            for (int Index = 0; Index < LastIndex; Index++)
            {
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_CMP0_SRC + Index, 0));		//Compare source is from command counter.
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_CMP0_TYPE + Index, 0));		//Compare type is Table.
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_TRG0_PWD + Index, 5));		//Trigger Width is 60nS

                for (int TableIndex = 0; TableIndex < 100; TableIndex++)
                {														//Create Table Data
                    DataArray[TableIndex] = 5000 + (TableIndex * 100);
                }

                Function_Result(APS168.APS_set_field_bus_trigger_table(CardID, BusNo, MOD_No, Index, ref DataArray[0], ArraySize));		//Set Table Data
                Function_Result(APS168.APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, (Int32)APS_Define.TG_CMP0_EN + Index, 1));		//Enable Linear compare
                if (FunctionFail)
                {
                    break;
                }
            }

            Btn_Trigger_Count_Click(sender,e);		//Reset Trigger Counter, it's not nerssery.
            Btn_ResetCounter_Click(sender, e);		//Reset Axis Counter Counter, it's not nerssery.
            Btn_Linear_4Axes_RelateiveForward_Click(sender, e);	
        }

        private void Btn_Manual_Compare_Click(object sender, EventArgs e)
        {
            Int32 LastIndex = 4;
            for (int TrgCh = 0; TrgCh < LastIndex; TrgCh++)
            {
                Function_Result(APS168.APS_set_field_bus_trigger_manual(CardID, BusNo, MOD_No, TrgCh));
                if (FunctionFail)
                {
                    break;
                }
            }
        }

        private void Btn_Trigger_Count_Click(object sender, EventArgs e)
        {
            Int32 LastIndex = 4;
            for (int TrgCh = 0; TrgCh < LastIndex; TrgCh++)
            {
                Function_Result(APS168.APS_reset_field_bus_trigger_count(CardID, BusNo, MOD_No, TrgCh));
                if (FunctionFail)
                {
                    break;
                }
            }
        }

        private void Btn_ResetCounter_Click(object sender, EventArgs e)
        {
            Int32 LastIndex = 4;
            for (Int32 AxisNo = Start_Axis_ID; AxisNo < LastIndex; AxisNo++)
            {
                Function_Result(APS168.APS_set_command(AxisNo, 0));
                Function_Result(APS168.APS_set_position(AxisNo, 0));
                if (FunctionFail)
                {
                    break;
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Int32 Command=0;
            Int32 Position = 0;
            Int32 MotionSts = 0;
            Int32 IoSts = 0;
            Int32 TrgCnt = 0;
            Int32 CmpVal = 0;
            Int32 EncCnt = 0;
            Int32 RunningPoint = 0;
            Int32 DI_Value = 0, DOData = 0;

            System.Windows.Forms.TextBox[] CommandArray = new TextBox[4] { Edit_ShowAxis_Command_0, Edit_ShowAxis_Command_1, Edit_ShowAxis_Command_2, Edit_ShowAxis_Command_3 };
            System.Windows.Forms.TextBox[] Feedback = new TextBox[4] { _Edit_ShowAxis_Feedback_0, _Edit_ShowAxis_Feedback_1, _Edit_ShowAxis_Feedback_2, _Edit_ShowAxis_Feedback_3 };
            System.Windows.Forms.TextBox[] IOSts = new TextBox[4] { _Edit_ShowAxis_IOSts_0, _Edit_ShowAxis_IOSts_1, _Edit_ShowAxis_IOSts_2, _Edit_ShowAxis_IOSts_3 };
            System.Windows.Forms.TextBox[] MSts = new TextBox[4] { _Edit_ShowAxis_MSts_0, _Edit_ShowAxis_MSts_1, _Edit_ShowAxis_MSts_2, _Edit_ShowAxis_MSts_3 };
            System.Windows.Forms.TextBox[] TriggerCount = new TextBox[4] { _Edit_ShowTriggerCount_0, _Edit_ShowTriggerCount_1, _Edit_ShowTriggerCount_2, _Edit_ShowTriggerCount_3 };
            System.Windows.Forms.TextBox[] TriggerEnc = new TextBox[4] { _Edit_ShowTriggerEnc_0, _Edit_ShowTriggerEnc_1, _Edit_ShowTriggerEnc_2, _Edit_ShowTriggerEnc_3 };
            System.Windows.Forms.TextBox[] TriggerVal = new TextBox[4] { _Edit_ShowTrigger_LinearCMP_LinearCMP_0, _Edit_ShowTrigger_LinearCMP_LinearCMP_1, _Edit_ShowTrigger_LinearCMP_LinearCMP_2, _Edit_ShowTrigger_LinearCMP_LinearCMP_3 };

            for (int index = 0; index < 4; index++)
            {
                //Motion Segment
                APS168.APS_get_command(Start_Axis_ID + index, ref Command);
                CommandArray[index].Text = Command.ToString ();

                APS168.APS_get_position(Start_Axis_ID + index, ref Position);
                Feedback[index].Text = (Position.ToString ());

                IoSts = APS168.APS_motion_io_status(Start_Axis_ID + index);
                IOSts[index].Text = (IoSts.ToString());

                MotionSts = APS168.APS_motion_status(Start_Axis_ID + index);
                MSts[index].Text = (MotionSts.ToString());

                APS168.APS_get_running_point_index2(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], ref RunningPoint);
                Edit_Show_PointTable_CurrIndex.Text = (RunningPoint.ToString());

                //Compare Segment
                APS168.APS_get_field_bus_trigger_count(CardID, BusNo, MOD_No, index, ref TrgCnt);
                TriggerCount[index].Text = (TrgCnt.ToString());

                APS168.APS_get_field_bus_encoder(CardID, BusNo, MOD_No, index, ref EncCnt);
                TriggerEnc[index].Text = (EncCnt.ToString());

                APS168.APS_get_field_bus_trigger_linear_cmp(CardID, BusNo, MOD_No, index, ref CmpVal);
                TriggerVal[index].Text = (CmpVal.ToString());

                //General DIO
                APS168.APS_get_field_bus_d_input( CardID, BusNo, Int32.Parse(Edit_SetModuleID_ForGeneralDIO.Text), ref DI_Value);
                Edit_ShowDIData.Text = DI_Value.ToString ("x");

                APS168.APS_get_field_bus_d_output(CardID, BusNo, Int32.Parse(Edit_SetModuleID_ForGeneralDIO.Text), ref DOData);
                Edit_GetDOData.Text = DOData.ToString("x"); 
            }
	
        }

        private void Btn_Arc_2Axes_Absolute_CCW_Click(object sender, EventArgs e)
        {
            Int32 Dimension=2;
            Int32[] Center_Pos_Array = new Int32[2] { -20000, -20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = 180;
	        //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle));
        }

        private void Btn_Arc_2Axes_Absolute_CW_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Center_Pos_Array = new Int32[2] { 20000, 20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = 180;
            //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle));
        }

        private void Btn_Arc_2Axes_Relative_CCW_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Center_Pos_Array = new Int32[2] { -20000, -20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = 180;
            //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            Function_Result(APS168.APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle));
        }

        private void Btn_Arc_2Axes_Relative_CW_Click(object sender, EventArgs e)
        {
            Int32 Dimension = 2;
            Int32[] Center_Pos_Array = new Int32[2] { 20000, 20000 };
            Int32 Max_Arc_Speed = 50000;
            Int32 Angle = 180;
            //Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

            APS168.APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle);
        }

        private void Btn_Arc_2Axes_Absolute_Stop2_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_2Axes_ArcMove[0]));	
        }

        private void Btn_Arc_2Axes_Relateive_Stop_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_emg_stop(Axis_ID_Array_For_2Axes_ArcMove[0]));	
        }

        private void Btn_Set_DOData_Click(object sender, EventArgs e)
        {
            Function_Result(APS168.APS_set_field_bus_d_output(CardID, BusNo, Int32.Parse(Edit_SetModuleID_ForGeneralDIO.Text), Int32.Parse(Edit_SetDOData.Text)));
        }
    }
}