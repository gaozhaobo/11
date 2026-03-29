/****************************************************************************/
/*  Copyright (c) 2013, ADLink Technology Inc.  All rights reserved.        */
/*                                                                          */
/*  File Name   :   Form1.cs                                                */
/*  Purpose     :   Basic Sample                                            */
/*  Date        :   2018/9/17                                               */
/*  Programmer  :   Johnny      	                                        */
/****************************************************************************/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using APS168_W64;
using APS_Define_W32;
using System.Security.Principal;


namespace basic_sample
{
    public partial class Form1 : Form
    {
        /////Main form data/////////////////////////////////////////////////////////////
        const Int32 YES = 1;
        const Int32 NO  = 0;
        const Int32 ON  = 1;
        const Int32 OFF = 0;
        const UInt32 BCM_SETSHIELD = 0x160C;

        Int32 v_card_name         = 0;
        Int32 v_board_id          = -1;
        Int32 v_channel           = 0;
        Int32 v_total_axis        = 0; 
        Int32 v_is_card_initialed = 0;        
        Int32 v_StartAxisID       = 0;
        Int32 v_CurrentAxisIDIndex = 0;
        Int32 CurrentAxisID = 0;
        Int32 RepeMoveRet = 0;
        bool bClosethread = false;
        //////////////////////////////////////////////////////////////////////////////////
        



        public Form1()
        {            
            InitializeComponent();
        }

        public void Function_Result(Int32 Ret)
        {
            if (Ret != 0)
            {
                MessageBox.Show("Function Fail, ErrorCode:  " + Ret.ToString());
            }
        }

        public Int32 Is_CARD_INITIAL()
        {
            if (v_is_card_initialed == NO)
            {
                MessageBox.Show("Not initialed.");
                return NO;
            }
            else
            {
                return YES;
            }
        }
        
        private void initial_Click(object sender, EventArgs e)
        {
            Int32 boardID_InBits = 0;
            Int32           mode = 0;
            Int32            ret = 0;
            Int32 i            = 0,j = 0;
            Int32 card_name    = 0;
            Int32 tamp         = 0;
            Int32 StartAxisID  = 0;
            Int32 TotalAxisNum = 0;

            //APS168.SendMessage(button1.Handle, BCM_SETSHIELD, 0, (IntPtr)1);
            
            // UI protection
            if (v_is_card_initialed == YES)
            {
                MessageBox.Show("Initial ok !");
                return;
            }

            // Card(Board) initial
            ret = APS168.APS_register_emx(1, 0);

            ret = APS168.APS_initial(ref boardID_InBits, mode);

            if( ret == 0 )
            {
                for (i = 0; i < 16; i++)
                {
                    tamp = (boardID_InBits >> i) & 1;

                    if( tamp == 1 )
                    {
                        ret = APS168.APS_get_card_name(i, ref card_name);

                        if (card_name == (Int32)APS_Define.DEVICE_NAME_ENET_EMX100)
                        {
                            ret =  APS168.APS_get_first_axisId(i, ref  StartAxisID, ref  TotalAxisNum);

                            //----------------------------------------------------
                            v_card_name         = card_name;
                            v_board_id          = i;
                            v_total_axis        = TotalAxisNum;
                            v_is_card_initialed = YES;
                            v_StartAxisID = StartAxisID;
                            for (j = 0; j < TotalAxisNum;j++ )
                            {
                                comboBox_Axis.Items.Add(j+StartAxisID);
                            }
                            comboBox_Axis.SelectedIndex = 0;
                            

                            v_channel = 2;
                            
                            //----------------------------------------------------
                            
                            MessageBox.Show("Initial ok !");

                            //Show main form title text
                            if (card_name == (Int32)APS_Define.DEVICE_NAME_ENET_EMX100) this.Text = "EMX-100 Basic Sample";
                                                       

                            break;
                        }
                    }
                }

                if (v_board_id == -1)
                {
                    v_is_card_initialed = NO;
                    MessageBox.Show("Board Id search error !");
                }

                for (i = 0; i < 4; i++ )
                {
                    ret = APS168.APS_set_axis_param(v_StartAxisID + i, (Int32)APS_Define.PRA_EL_LOGIC, 1);
                    ret = APS168.APS_set_axis_param(v_StartAxisID + i, (Int32)APS_Define.PRA_ORG_LOGIC, 1);
                    ret = APS168.APS_set_axis_param(v_StartAxisID + i, (Int32)APS_Define.PRA_EL_MODE, 1);
                    ret = APS168.APS_set_axis_param(v_StartAxisID + i, (Int32)APS_Define.PRA_ALM_LOGIC, 1);
                }
            }
            else
            {
                v_is_card_initialed = NO;
                MessageBox.Show("Initial fail");
                Function_Result(ret);
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Int32 Axis_ID  = 0;
            Int32 Servo_On = OFF;
            Int32 ret      = 0;

            if (v_is_card_initialed == YES)
            {
                for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
                {
                    ret = APS168.APS_set_servo_on(Axis_ID, Servo_On);
                }

                APS168.APS_close();
            }
        }

        private void Close_Click(object sender, EventArgs e)
        {
            APS168.APS_close();
            v_is_card_initialed = NO;
            btnRepeatMove.Enabled = true;
            bClosethread = true;
            MessageBox.Show("Close OK");
            this.Text = "Basic Sample";
            comboBox_Axis.Items.Clear();
        }

        private void Get_Version_Click(object sender, EventArgs e)
        {
            if( Is_CARD_INITIAL() == NO ) return; 
           
            //Pass data from main form to sub form
            Version_Info p = new Version_Info();
            p.v_card_name         = v_card_name;
            p.v_board_id          = v_board_id;
            p.v_channel           = v_channel;
            p.v_total_axis        = v_total_axis;
            p.v_is_card_initialed = v_is_card_initialed;

            //Note:
            //p.Show();         //Can't lock main Dialog when sub form opend.
            //p.ShowDialog();   //Can lock main Dialog when sub form opend.
            p.ShowDialog();
        }

        private void Axis_Monitor_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;
            
            //Pass data from main form to sub form
            Axis_Monitor p = new Axis_Monitor();
            p.v_card_name = v_card_name;
            p.v_board_id = v_board_id;
            p.v_channel = v_channel;
            p.v_total_axis = v_total_axis;
            p.v_is_card_initialed = v_is_card_initialed;
            p.v_StartAxisID = v_StartAxisID;
            p.v_CurrentAxisIDIndex = v_CurrentAxisIDIndex;
            //Note:
            //p.Show();         //Can't lock main Dialog when sub form opend.
            
            p.Show();
        }

        

        public Int32 Is_axis_err(Int32 Axis_ID)
        {
            if (Axis_ID < 0 || Axis_ID >= (v_StartAxisID+v_total_axis))
            {
                MessageBox.Show("User Input Axis_ID Error !");
                return YES; 
            }
            else
                return NO; 
        }

        private void Motion_Done_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;            
            Int32 ret        = 0;
            
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
      
            Int32 Stop_Code  = 0;

            if (Is_axis_err(Axis_ID) == YES) return;

            ret = Class_Motion.check_motion_done_example(Axis_ID, ref Stop_Code);

            // Display motion done status
            switch (ret)
            {
                case 0:
                    MessageBox.Show("In Motion at Axis:  " + Axis_ID.ToString());
                    break;
                case 1:
                    MessageBox.Show("Motion done at Axis:  " + Axis_ID.ToString());
                    break;
                case -1:
                    MessageBox.Show("Error stop at Axis:  "  + Axis_ID.ToString());
                    break;
            }


        }

        private void Homing_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;            
            
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.home_move_example(Axis_ID);
        }

        private void Velocity_Move_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;            
            
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
            if (Is_axis_err(Axis_ID) == YES) return;

           Class_Motion. velocity_move_example( Axis_ID);
        }

        private void Jog_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;        
            
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.jog_move_continuous_mode_example(Axis_ID);
        }

        private void Jog_off_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;           
            
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
            if (Is_axis_err(Axis_ID) == YES) return;            
            APS168.APS_jog_start(Axis_ID, 0);
        }

        private void P2P_Move_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;
            
            
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.p2p_example(Axis_ID);
        }

        private void Stop_Move_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;
            
            
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
            if (Is_axis_err(Axis_ID) == YES) return;
            btnRepeatMove.Enabled = true;
            bClosethread = true;
            Class_Motion.deceleration_stop_example( Axis_ID);
            
        }

        private void EMG_Stop_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;
            
            //Int32 Axis_ID = Int32.Parse(textBox1.Text);
            Int32 Axis_ID = comboBox_Axis.SelectedIndex + v_StartAxisID;
            btnRepeatMove.Enabled = true;
            bClosethread = true;
            if (Is_axis_err(Axis_ID) == YES) return;
            Class_Motion.emg_stop_example(Axis_ID);
            
        }   
              
        
                
        private void DIO_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;
            Class_Motion.DIO_sample(v_board_id);
        }     
              

        

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "Basic Sample";        
        }

        

        private void Load_Parameter(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;            
            string p = null;
            Int32 ret;
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "XML File (*.xml)|*.xml|All Files (*.*)|*.*";
            dialog.InitialDirectory = "C:";
            dialog.Title = "Select a XML File";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                p = dialog.FileName;
                ret = APS168.APS_load_param_from_file(p);

                if (ret == 0)
                    MessageBox.Show("Load XML File OK !");
                else
                    Function_Result(ret);
            }
        }

        

        private void comboBox_Axis_SelectedIndexChanged(object sender, EventArgs e)
        {
            v_CurrentAxisIDIndex = comboBox_Axis.SelectedIndex;
        }

        private void Compare_trigger(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;
            Class_Motion.CMP_Trigger(v_board_id);            
        }

        private void RepeatMove(object sender, EventArgs e)
        {
            Int32 delayTime = 0;
            delayTime = Int32.Parse(textBoxDelayTime.Text);
            if (delayTime < 1)
            {
                MessageBox.Show("Delay time must be >= 1 ms");
                return;
            }
                        
            btnRepeatMove.Enabled = false;
            bClosethread = false;
            CurrentAxisID= comboBox_Axis.SelectedIndex + v_StartAxisID;
            Thread DelayTime = new Thread(RepeatMoveProcess);
            DelayTime.Start();
        }



        private void RepeatMoveProcess()
        {
            Int32 ret = 0, delayTime = 0;
            bool bEven = false;
            delayTime = Int32.Parse(textBoxDelayTime.Text);
            while(true)
            {
                if (bClosethread)
                    break;
                ret = APS168.APS_motion_status(CurrentAxisID);
                if (ret < 0)
                {
                    break;
                }
                else if (((ret >> (Int32)APS_Define.NSTP) & 1) == 1)
                {
                    bEven = !bEven;

                    if (bEven == true)
                    {
                        ret = APS168.APS_relative_move(CurrentAxisID, 10000, 20000);
                    }
                    else
                    {
                        ret = APS168.APS_relative_move(CurrentAxisID, -10000, 20000);
                    }
                    Thread.Sleep(delayTime);
                    if (ret < 0)
                    {
                        APS168.APS_emg_stop(CurrentAxisID);
                        RepeMoveRet = ret;
                        MessageBox.Show("APS_relative_Move -912 ");
                        btnRepeatMove.Enabled = true;
                        break;
                    }                    
                }
                else
                {
                    ;
                }
            }
        }
        
        

    }
}

