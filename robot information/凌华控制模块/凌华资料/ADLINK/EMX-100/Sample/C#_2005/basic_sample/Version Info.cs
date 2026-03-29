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
    public partial class Version_Info : Form
    {
        /////Global Variable/////////////////////////////////////////////////////////////
        const Int32 YES = 1;
        const Int32 NO  = 0;
        const Int32 ON  = 1;
        const Int32 OFF = 0;

        public Int32 v_card_name         = 0;
        public Int32 v_board_id          = -1;
        public Int32 v_channel           = 0;
        public Int32 v_total_axis        = 0;
        public Int32 v_is_card_initialed = 0;
        //////////////////////////////////////////////////////////////////////////////////

        public Version_Info()
        {
            InitializeComponent();
        }

        private void Version_Info_Load(object sender, EventArgs e)
        {
            this.timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Int32 tmp = 0;

            // Get DLL version 
            tmp = APS168.APS_version();
            textAPS_Dll.Text = tmp.ToString();

            // Get EMX100 software version
            APS168.APS_get_device_info(v_board_id, 0x00, ref tmp);
            textFMAC_SW.Text = Convert.ToString(tmp, 10);

            // Get EMX100 middle ware version
            APS168.APS_get_device_info(v_board_id, 0x01, ref tmp);
            textFMAC_MW.Text = Convert.ToString(tmp, 10);

            // Get EMX100 communication AP version
            APS168.APS_get_device_info(v_board_id, 0x11, ref tmp);
            textFMAC_EXE.Text = Convert.ToString(tmp, 10);

            // Get EMX100 library version
            APS168.APS_get_device_info(v_board_id, 0x100, ref tmp);
            textFMAC_Lib.Text = Convert.ToString(tmp, 10); 
        }

        private void Version_Info_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.timer1.Stop();
        }

        



    }
}