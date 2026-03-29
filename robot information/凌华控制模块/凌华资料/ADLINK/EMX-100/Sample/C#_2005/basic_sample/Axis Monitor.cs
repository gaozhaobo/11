using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using APS168_W64;
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
        const Int32 MAX_MIO_CHECK = 9;
        const Int32 MAX_MSTS_CHECK = 10;
        public Int32 v_card_name = 0;
        public Int32 v_board_id = -1;
        public Int32 v_channel = 0;
        public Int32 v_total_axis = 0;
        public Int32 v_is_card_initialed = 0;
        public Int32 v_StartAxisID = 0;
        public Int32 v_CurrentAxisIDIndex = 0;
        public Int32 v_CurrentAxisID = 0;
        public Int32[] MIO_Bit = { (Int32)APS_Define.MIO_ALM, (Int32)APS_Define.MIO_PEL, (Int32)APS_Define.MIO_MEL, (Int32)APS_Define.MIO_ORG, (Int32)APS_Define.MIO_EMG, (Int32)APS_Define.MIO_EZ, (Int32)APS_Define.MIO_INP, (Int32)APS_Define.MIO_SVON, (Int32)APS_Define.MIO_RDY };
        public Int32[] MSTS_Bit = { (Int32)APS_Define.NSTP, (Int32)APS_Define.MTS_EMGS, (Int32)APS_Define.MTS_ALMS, (Int32)APS_Define.MTS_PELS, (Int32)APS_Define.MTS_MELS, (Int32)APS_Define.MTS_SPELS, (Int32)APS_Define.MTS_SMELS, (Int32)APS_Define.MTS_EZS, (Int32)APS_Define.MTS_HMES, (Int32)APS_Define.MTS_ORGS };
        public CheckBox[] MIO;
        public CheckBox[] MSTS;
        //////////////////////////////////////////////////////////////////////////////////
        
        public Axis_Monitor()
        {
            InitializeComponent();
        }

        private void Axis_Monitor_Load(object sender, EventArgs e)
        {
            Int32 j = 0;
            this.timer1.Start();
            for (j = 0; j < v_total_axis; j++)
            {
                comboBoxAixsID.Items.Add(j + v_StartAxisID);
            }
            comboBoxAixsID.SelectedIndex = v_CurrentAxisIDIndex;
            v_CurrentAxisID = v_StartAxisID + v_CurrentAxisIDIndex;

            MIO = new CheckBox[MAX_MIO_CHECK] { cbALM, cBPEL, cBMEL, cBORG, cBEMG, cBEZ, cBINP, cBSVON, cBRDY };
            MSTS = new CheckBox[MAX_MSTS_CHECK] { cBMDN, cBEMGS, cBALMS, cBPELS, cBMELS, cBSPELS, cBSMELS, cBEZS,cBHMES, cBORGS};
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Int32 Axis_ID = v_CurrentAxisID;
            Int32 tmp = 0;
            Int32 IOsts = 0,MOsts=0,i = 0 ,ret = 0;            
            
            ret = APS168.APS_get_command(Axis_ID, ref tmp);
            show_cmd_0.Text = tmp.ToString();

            ret = APS168.APS_get_position(Axis_ID, ref tmp);
            show_fb_0.Text = tmp.ToString();

            ret = APS168.APS_get_target_position(Axis_ID, ref tmp);
            show_target_0.Text = tmp.ToString();

            ret = APS168.APS_get_error_position(Axis_ID, ref tmp);
            show_err_0.Text = tmp.ToString();

            ret = APS168.APS_get_command_velocity(Axis_ID, ref tmp);
            show_cv_0.Text = tmp.ToString();            

            ret = APS168.APS_get_feedback_velocity(Axis_ID, ref tmp);
            show_fv_0.Text = tmp.ToString();            

            IOsts = APS168.APS_motion_io_status(Axis_ID);
            show_mio_0.Text = Convert.ToString(IOsts, 16);
            for (i = 0; i < MAX_MIO_CHECK; i++)
            {
                MIO[i].Checked = (((IOsts >> MIO_Bit[i]) & 1)==1)?true:false;                
            }
            MOsts =  APS168.APS_motion_status(Axis_ID);
            show_msts_0.Text = Convert.ToString(MOsts, 16);
            
            for (i = 0; i < MAX_MSTS_CHECK; i++)
            {
                MSTS[i].Checked = (((MOsts >> MSTS_Bit[i]) & 1) == 1) ? true : false;
            }             
            
        }

        private void Axis_Monitor_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.timer1.Stop();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Int32 Axis_ID = v_CurrentAxisID;           
            APS168.APS_set_servo_on(Axis_ID, ON);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Int32 Axis_ID = v_CurrentAxisID;           
            APS168.APS_set_servo_on(Axis_ID, OFF);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Int32 Axis_ID = v_CurrentAxisID;            
            APS168.APS_set_command(Axis_ID, 0);
            APS168.APS_set_position(Axis_ID, 0);
            
        }

        private void comboBoxAixsID_SelectedIndexChanged(object sender, EventArgs e)
        {
            v_CurrentAxisIDIndex = comboBoxAixsID.SelectedIndex;
            v_CurrentAxisID = v_StartAxisID + v_CurrentAxisIDIndex; 
        }

        

        
    }
}