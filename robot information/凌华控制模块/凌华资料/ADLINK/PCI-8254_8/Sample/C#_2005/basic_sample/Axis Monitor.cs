using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using APS168_W32;
using APS_Define_W32;

namespace basic_sample
{
    public partial class Axis_Monitor : Form
    {
        /////Global Variable/////////////////////////////////////////////////////////////
        const Int32 YES = 1;
        const Int32 NO = 0;
        const Int32 ON = 1;
        const Int32 OFF = 0;

        public Int32 v_card_name = 0;
        public Int32 v_board_id = -1;
        public Int32 v_channel = 0;
        public Int32 v_total_axis = 0;
        public Int32 v_is_card_initialed = 0;
        //////////////////////////////////////////////////////////////////////////////////

        public Axis_Monitor()
        {
            InitializeComponent();
        }

        private void Axis_Monitor_Load(object sender, EventArgs e)
        {
            this.timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Int32 Axis_ID = 0;
            Double tmp = 0;
            Int32 sts = 0;

            System.Windows.Forms.TextBox[] cmd = new TextBox[8] { show_cmd_0, show_cmd_1, show_cmd_2, show_cmd_3, show_cmd_4, show_cmd_5, show_cmd_6, show_cmd_7 };
            System.Windows.Forms.TextBox[] fb = new TextBox[8] { show_fb_0, show_fb_1, show_fb_2, show_fb_3, show_fb_4, show_fb_5, show_fb_6, show_fb_7 };
            System.Windows.Forms.TextBox[] tg = new TextBox[8] { show_target_0, show_target_1, show_target_2, show_target_3, show_target_4, show_target_5, show_target_6, show_target_7 };
            System.Windows.Forms.TextBox[] err = new TextBox[8] { show_err_0, show_err_1, show_err_2, show_err_3, show_err_4, show_err_5, show_err_6, show_err_7 };
            System.Windows.Forms.TextBox[] cv = new TextBox[8] { show_cv_0, show_cv_1, show_cv_2, show_cv_3, show_cv_4, show_cv_5, show_cv_6, show_cv_7 };
            System.Windows.Forms.TextBox[] fv = new TextBox[8] { show_fv_0, show_fv_1, show_fv_2, show_fv_3, show_fv_4, show_fv_5, show_fv_6, show_fv_7 };
            System.Windows.Forms.TextBox[] mio = new TextBox[8] { show_mio_0, show_mio_1, show_mio_2, show_mio_3, show_mio_4, show_mio_5, show_mio_6, show_mio_7 };
            System.Windows.Forms.TextBox[] msts = new TextBox[8] { show_msts_0, show_msts_1, show_msts_2, show_msts_3, show_msts_4, show_msts_5, show_msts_6, show_msts_7 };

            for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
            {
                APS168.APS_get_command_f(Axis_ID, ref tmp);
                cmd[Axis_ID].Text = tmp.ToString();

                APS168.APS_get_position_f(Axis_ID, ref tmp);
                fb[Axis_ID].Text = tmp.ToString();

                APS168.APS_get_target_position_f(Axis_ID, ref tmp);
                tg[Axis_ID].Text = tmp.ToString();

                APS168.APS_get_error_position_f(Axis_ID, ref tmp);
                err[Axis_ID].Text = tmp.ToString();

                APS168.APS_get_command_velocity_f(Axis_ID, ref tmp);
                cv[Axis_ID].Text = tmp.ToString();

                APS168.APS_get_feedback_velocity_f(Axis_ID, ref tmp);
                fv[Axis_ID].Text = tmp.ToString();

                sts = APS168.APS_motion_io_status(Axis_ID);
                mio[Axis_ID].Text = Convert.ToString(sts, 16);

                sts =  APS168.APS_motion_status(Axis_ID);
                msts[Axis_ID].Text = Convert.ToString(sts, 16);
            }
        }

        private void Axis_Monitor_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.timer1.Stop();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Int32 Axis_ID = 0;

            for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
                APS168.APS_set_servo_on(Axis_ID, ON);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Int32 Axis_ID = 0;

            for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
                APS168.APS_set_servo_on(Axis_ID, OFF);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Int32 Axis_ID = 0;

            for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
            {
                APS168.APS_set_command_f(Axis_ID, 0.0);
                APS168.APS_set_position_f(Axis_ID, 0.0);
            }
        }
    }
}