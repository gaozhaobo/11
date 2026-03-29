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
    public partial class CmpTrig : Form
    {
        /////Main form data/////////////////////////////////////////////////////////////
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

        public CmpTrig()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            System.Windows.Forms.TextBox[] TrigCnt = new TextBox[4] { textBox_CmpTrig_0, textBox_CmpTrig_1, textBox_CmpTrig_2, textBox_CmpTrig_3 };
            System.Windows.Forms.TextBox[] L_Value = new TextBox[2] { L_value_0, L_value_1 };
            System.Windows.Forms.TextBox[] T_Value = new TextBox[2] { T_value_0, T_value_1 };
            System.Windows.Forms.TextBox[] Timer_value = new TextBox[1] { textBox_Timer_Cnt };

            Int32 Board_ID = v_board_id;
            Int32 CH       = 0;
            Int32 CH_num   = v_channel;
            Int32 tmp      = 0;
            Int32 ret      = 0;


            for (CH = 0; CH < CH_num; CH++)
            {
                ret = APS168.APS_get_trigger_count(Board_ID, CH, ref tmp);
                TrigCnt[CH].Text = tmp.ToString();
            }

            for (CH = 0; CH < 2; CH++)
            {
                ret = APS168.APS_get_trigger_linear_cmp(Board_ID, CH, ref tmp);
                L_Value[CH].Text = tmp.ToString();

                ret = APS168.APS_get_trigger_table_cmp(Board_ID, CH, ref tmp);
                T_Value[CH].Text = tmp.ToString();
            }

            ret = APS168.APS_get_timer_counter(Board_ID, 0, ref tmp);
            Timer_value[0].Text = tmp.ToString();
        }

        private void CmpTrig_Load(object sender, EventArgs e)
        {
            this.timer1.Start();
        }

        private void CmpTrig_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.timer1.Stop();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;
            Int32 CH = 0;

            for (CH = 0; CH < v_channel; CH++)
                ret = APS168.APS_reset_trigger_count(Board_ID, CH);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;

            //Stop Timer
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_EN, 0);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;

            //Clear timer
            ret = APS168.APS_set_timer_counter(Board_ID, 0, 0);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;
            Int32 CH = 0;


            // Enable trigger output
            if (v_channel == 2)
                ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0x3);
            else if (v_channel == 4)
                ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0xf);

            //Trigger output TRG0 ~ TRG3 source
            //Bit 0: Manual 
            //Bit 1: Reserved
            //Bit 2: FCMP0 
            //Bit 3: FCMP1 
            //Bit 4: LCMP0 
            //Bit 5: LCMP1
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG0_SRC, 0x1);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG1_SRC, 0x1);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG2_SRC, 0x1);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG3_SRC, 0x1);

            //Start manual trigger
            for (CH = 0; CH < v_channel; CH++)
                ret = APS168.APS_set_trigger_manual(Board_ID, CH);

            // Disable TRG 0 ~ 3
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0);

            //Disable all CMP
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG0_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG1_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG2_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG3_SRC, 0);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;
            Int32 CH = 0;
            Int32 StartPoint = 0;
            Int32 RepeatTimes = 10;
            Int32 Interval = 1000;


            //Stop Timer
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_EN, 0);

            //Clear timer
            ret = APS168.APS_set_timer_counter(Board_ID, 0, 0);

            // Disable TRG 0 ~ 3
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0);

            // Disable all CMP
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG0_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG1_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG2_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG3_SRC, 0);

            //-----------------------------------------------------------

            // Enable TRG 0 ~ 3
            if (v_channel == 2)
                ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0x3);
            else if (v_channel == 4)
                ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0xf);

            //Linear compare source: Timer counter 
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_LCMP0_SRC, 8);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_LCMP1_SRC, 8);

            //Trigger output TRG0 ~ TRG3 source
            //Trigger output 0 source: LCMP0 
            //Trigger output 1 source: LCMP0 
            //Trigger output 2 source: LCMP1 
            //Trigger output 3 source: LCMP1
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG0_SRC, 0x10);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG1_SRC, 0x10);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG2_SRC, 0x20);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG3_SRC, 0x20);

            //Start linear CMP
            for (CH = 0; CH < 2; CH++)
                ret = APS168.APS_set_trigger_linear(Board_ID, CH, StartPoint, RepeatTimes, Interval);

            //Timer Interval: 1ms
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_ITV, 10000);

            //TIMR DIR: Positive count
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_DIR, 0);

            //Start Timer
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_EN, 1);

        }

        private void button6_Click(object sender, EventArgs e)
        {
            Int32 ret      = 0;
	        Int32 Board_ID = v_board_id;
	        Int32 CH       = 0;
	        Int32 i        = 0;

            Int32 ArraySize = 10;
            Int32[] DataArr = new Int32[ArraySize];
            

	        //Stop Timer
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_EN, 0);

	        //Clear timer
            ret = APS168.APS_set_timer_counter(Board_ID, 0, 0);

	        // Disable TRG 0 ~ 3
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0);

	        //Disable all CMP
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG0_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG1_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG2_SRC, 0);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG3_SRC, 0);

	        //------------------------------------------------------------

	        // Enable trigger output
            if (v_channel == 2)
                ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0x3);
            else if (v_channel == 4)
                ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG_EN, 0xf);

	        //Linear compare source: Timer counter 
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TCMP0_SRC, 8);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TCMP1_SRC, 8);

	        //Table compare direction: Bi-direction(No direction)
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TCMP0_DIR, 2);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TCMP1_DIR, 2);

	        //Trigger output TRG0 ~ TRG3 source
	        //Trigger output 0 source: FCMP0 
	        //Trigger output 1 source: FCMP0 
	        //Trigger output 2 source: FCMP1 
	        //Trigger output 3 source: FCMP1
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG0_SRC, 0x4);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG1_SRC, 0x4);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG2_SRC, 0x8);
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TGR_TRG3_SRC, 0x8);

            for( i = 0; i < 10; i++ )
                DataArr[i] = i * 1000;
		       
	        //Start Table CMP
	        for( CH = 0; CH < 2; CH++ )
                ret = APS168.APS_set_trigger_table(Board_ID, CH, DataArr, ArraySize); 

	        //Timer Interval: 1ms
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_ITV, 10000);

	        //TIMR DIR: Positive count
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_DIR, 0);

	        //Start Timer
            ret = APS168.APS_set_trigger_param(Board_ID, (Int32)APS_Define.TIMR_EN, 1);
        }
    }
}