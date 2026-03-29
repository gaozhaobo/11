/****************************************************************************/
/*  Copyright (c) 2013, ADLink Technology Inc.  All rights reserved.        */
/*                                                                          */
/*  File Name   :   Form1.cs                                                */
/*  Purpose     :   Basic Sample                                            */
/*  Date        :   2013/9/25                                               */
/*  Programmer  :   Chang Zhi Lin	                                        */
/****************************************************************************/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;

using APS168_W32;
using APS_Define_W32;



namespace basic_sample
{
    public partial class Form1 : Form
    {
        /////Main form data/////////////////////////////////////////////////////////////
        const Int32 YES = 1;
        const Int32 NO  = 0;
        const Int32 ON  = 1;
        const Int32 OFF = 0;

        Int32 v_card_name         = 0;
        Int32 v_board_id          = -1;
        Int32 v_channel           = 0;
        Int32 v_total_axis        = 0; 
        Int32 v_is_card_initialed = 0;
        //////////////////////////////////////////////////////////////////////////////////
        Int32 Is_Creat = NO;



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
            Int32 i            = 0;
            Int32 card_name    = 0;
            Int32 tamp         = 0;
            Int32 StartAxisID  = 0;
            Int32 TotalAxisNum = 0;



            // UI protection
            if (v_is_card_initialed == YES)
            {
                MessageBox.Show("Initial ok !");
                return;
            }

            // Card(Board) initial
            ret = APS168.APS_initial(ref boardID_InBits, mode);

            if( ret == 0 )
            {
                for (i = 0; i < 16; i++)
                {
                    tamp = (boardID_InBits >> i) & 1;

                    if( tamp == 1 )
                    {
                        ret = APS168.APS_get_card_name(i, ref card_name);

                        if (   card_name == (Int32)APS_Define.DEVICE_NAME_PCI_825458 
                            || card_name == (Int32)APS_Define.DEVICE_NAME_AMP_20408C )
                        {
                            ret =  APS168.APS_get_first_axisId(i, ref  StartAxisID, ref  TotalAxisNum);

                            //----------------------------------------------------
                            v_card_name         = card_name;
                            v_board_id          = i;
                            v_total_axis        = TotalAxisNum;
                            v_is_card_initialed = YES;

                            textBox1.Text = "0";

                            if      (v_total_axis == 4) v_channel = 2;
                            else if (v_total_axis == 8) v_channel = 4;
                            //----------------------------------------------------
                            Is_Creat = NO;
                            MessageBox.Show("Initial ok !");

                            //Show main form title text
                            if (card_name == (Int32)APS_Define.DEVICE_NAME_PCI_825458 && TotalAxisNum  == 8 ) this.Text = "PCI-8258 Basic Sample";
                            if (card_name == (Int32)APS_Define.DEVICE_NAME_PCI_825458 && TotalAxisNum  == 4 ) this.Text = "PCI-8254 Basic Sample";
                            if (card_name == (Int32)APS_Define.DEVICE_NAME_AMP_20408C && TotalAxisNum == 8 ) this.Text = "AMP-208C Basic Sample";
                            if (card_name == (Int32)APS_Define.DEVICE_NAME_AMP_20408C && TotalAxisNum == 4 ) this.Text = "AMP-204C Basic Sample";

                            break;
                        }
                    }
                }

                if (v_board_id == -1)
                {
                    v_is_card_initialed = NO;
                    MessageBox.Show("Board Id search error !");
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
            MessageBox.Show("Close OK");
            this.Text = "Basic Sample";
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

            //Note:
            //p.Show();         //Can't lock main Dialog when sub form opend.
            //p.ShowDialog();   //Can lock main Dialog when sub form opend.
            p.Show();
        }

        private void Load_Param_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            string p = null;
            Int32 ret = 0;


            OpenFileDialog dialog = new OpenFileDialog();

            dialog.Filter = "XML File (*.xml)|*.xml|All Files (*.*)|*.*";

            dialog.InitialDirectory = "C:";

            dialog.Title = "Select a XML File";

            if (dialog.ShowDialog() == DialogResult.OK)
            {
                p = dialog.FileName;
                ret = APS168.APS_load_param_from_file( p );

                if(ret==0)
                    MessageBox.Show("Load XML File OK !");
                else
                    Function_Result(ret);
            }
        }

        public Int32 Is_axis_err(Int32 Axis_ID)
        {
            if (Axis_ID < 0 || Axis_ID >= v_total_axis)
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
            Int32 Axis_ID    = Int32.Parse(textBox1.Text);
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

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.home_move_example(Axis_ID);
        }

        private void Velocity_Move_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

           Class_Motion. velocity_move_example( Axis_ID);
        }

        private void Jog_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.jog_move_continuous_mode_example(Axis_ID);
        }

        private void Jog_off_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            APS168.APS_jog_start(Axis_ID, 1);
            APS168.APS_jog_start(Axis_ID, 0);
        }

        private void P2P_Move_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.p2p_example(Axis_ID);
        }

        private void Stop_Move_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.deceleration_stop_example( Axis_ID);
        }

        private void EMG_Stop_Click(object sender, EventArgs e)
        {
             if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Class_Motion.emg_stop_example(Axis_ID);
        }

        private void _2D_Line_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Int32[] Axis_ID_Array = new Int32[2];

            if (Axis_ID == 7)
            {
                Axis_ID_Array[0] = 7;
                Axis_ID_Array[1] = 0;
            }
            else
            {
                Axis_ID_Array[0] = Axis_ID;
                Axis_ID_Array[1] = Axis_ID+1;
            }
           
            Class_Motion.interpolation_2D_line_example(Axis_ID_Array);
        }

        private void _2D_Arc_Click(object sender, EventArgs e)
        {
             if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Int32[] Axis_ID_Array = new Int32[2];

            if (Axis_ID == 7)
            {
                Axis_ID_Array[0] = 7;
                Axis_ID_Array[1] = 0;
            }
            else
            {
                Axis_ID_Array[0] = Axis_ID;
                Axis_ID_Array[1] = Axis_ID+1;
            }

            Class_Motion. interpolation_2D_arc_example(  Axis_ID_Array );
        }

        private void _3D_Arc_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Int32[] Axis_ID_Array = new Int32[3];

            if (Axis_ID == 7)
            {
                Axis_ID_Array[0] = 7;
                Axis_ID_Array[1] = 0;
                Axis_ID_Array[2] = 1;
            }
            else
            {
                Axis_ID_Array[0] = Axis_ID;
                Axis_ID_Array[1] = Axis_ID + 1;
                Axis_ID_Array[2] = Axis_ID + 2;
            }

            Class_Motion. interpolation_3D_arc_example(  Axis_ID_Array );
        }

        private void _3D_Helical_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Int32[] Axis_ID_Array = new Int32[3];

            if (Axis_ID == 7)
            {
                Axis_ID_Array[0] = 7;
                Axis_ID_Array[1] = 0;
                Axis_ID_Array[2] = 1;
            }
            else
            {
                Axis_ID_Array[0] = Axis_ID;
                Axis_ID_Array[1] = Axis_ID + 1;
                Axis_ID_Array[2] = Axis_ID + 2;
            }

            Class_Motion.  interpolation_3D_helical_example(  Axis_ID_Array );
        }

        private void _2D_Contour_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Int32[] Axis_ID_Array = new Int32[2];

            if (Axis_ID == 7)
            {
                Axis_ID_Array[0] = 7;
                Axis_ID_Array[1] = 0;
            }
            else
            {
                Axis_ID_Array[0] = Axis_ID;
                Axis_ID_Array[1] = Axis_ID+1;
            }

            Class_Motion. contour_2D_example(  Axis_ID_Array );
        }

        private void Point_Table_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Int32[] Axis_ID_Array = new Int32[2];

            if (Axis_ID == 7)
            {
                Axis_ID_Array[0] = 7;
                Axis_ID_Array[1] = 0;
            }
            else
            {
                Axis_ID_Array[0] = Axis_ID;
                Axis_ID_Array[1] = Axis_ID+1;
            }

            Class_Motion.point_table_2D_example(v_board_id, Axis_ID_Array);
        }

        private void Gear_Gantry_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            Int32 Axis_ID = Int32.Parse(textBox1.Text);
            if (Is_axis_err(Axis_ID) == YES) return;

            Int32[] Axis_ID_Array = new Int32[2];

            if (Axis_ID == 7)
            {
                Axis_ID_Array[0] = 7;
                Axis_ID_Array[1] = 0;
            }
            else
            {
                Axis_ID_Array[0] = Axis_ID;
                Axis_ID_Array[1] = Axis_ID + 1;
            }

            Class_Motion. gear_example( Axis_ID_Array );
        }


        public void DoWork()
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;
            Int32 Axis_num = Int32.Parse(textBox1.Text);

            if (Is_axis_err(Axis_num) == YES) return;

            ret = Class_Motion.interrupt_example(Board_ID, Axis_num);

            if (ret == 0)
            {
                Is_Creat = NO;
                MessageBox.Show("Interrupt Occur !");
            } 
        }

        private void Interrupt_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            if (Is_Creat == NO)
            {
                Thread thread = new Thread(new ThreadStart(DoWork));
                thread.Start();

                Is_Creat = YES;
                MessageBox.Show("Thread already created !");
                MessageBox.Show("Wait motion done thread is created.\n You can start a \"p2p\" move.");
            }
            else
                MessageBox.Show("Thread already created !");
        }

        private void DIO_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;
            Class_Motion.DIO_sample(v_board_id);
        }

        private void Analog_IO_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            if( v_card_name == (Int32)APS_Define.DEVICE_NAME_PCI_825458  || 
                v_card_name == (Int32)APS_Define.DEVICE_NAME_PCI_V8258 ||
                v_card_name == (Int32)APS_Define.DEVICE_NAME_PCI_V8254    )
            {
                Class_Motion.AIO_sample(v_board_id);
            }
            else if( v_card_name == (Int32)APS_Define.DEVICE_NAME_AMP_20408C )
            {
                MessageBox.Show("Function not support !");
            }
        }

        private void CMP_Trigger_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            //Pass data from main form to sub form
            CmpTrig p = new CmpTrig();
            p.v_card_name = v_card_name;
            p.v_board_id = v_board_id;
            p.v_channel = v_channel;
            p.v_total_axis = v_total_axis;
            p.v_is_card_initialed = v_is_card_initialed;

            //Note:
            //p.Show();         //Can't lock main Dialog when sub form opend.
            //p.ShowDialog();   //Can lock main Dialog when sub form opend.
            p.ShowDialog();
        }

        private void PWM_VAO_Click(object sender, EventArgs e)
        {
            if (Is_CARD_INITIAL() == NO) return;

            //Pass data from main form to sub form
            PWM_VAO p = new PWM_VAO();
            p.v_card_name = v_card_name;
            p.v_board_id = v_board_id;
            p.v_channel = v_channel;
            p.v_total_axis = v_total_axis;
            p.v_is_card_initialed = v_is_card_initialed;

            //Note:
            //p.Show();         //Can't lock main Dialog when sub form opend.
            //p.ShowDialog();   //Can lock main Dialog when sub form opend.
            p.ShowDialog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "Basic Sample";
        }

        

        
 




        

















    }
}