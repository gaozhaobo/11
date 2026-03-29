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
    public partial class PWM_VAO : Form
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
        public Int32 Is_CreatThread_PWM = NO;



        public PWM_VAO()
        {
            InitializeComponent();
        }

        private void PWM_VAO_Load(object sender, EventArgs e)
        {
            Is_CreatThread_PWM = NO;
            this.timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;
            Int32 CH = 0;         //Range is from 0 to 1
            Int32 Frequency = 0;  //Unit: Hz. Range is from 3 to 50000000.
            Int32 Width = 0;      //Unit: ns. Range is from 20 to 335544300.
            Int32 Status = 0;
            Int32 tmp = 0;

            System.Windows.Forms.TextBox[] freq  = new TextBox[4] { pwm_freq_0, pwm_freq_1, pwm_freq_2, pwm_freq_3 };
            System.Windows.Forms.TextBox[] width = new TextBox[4] { pwm_width_0, pwm_width_1, pwm_width_2, pwm_width_3 };
            System.Windows.Forms.TextBox[] vao = new TextBox[1] { textBox1 };
            System.Windows.Forms.TextBox[] TrigCnt = new TextBox[4] { TrigCnt_0, TrigCnt_1, TrigCnt_2, TrigCnt_3 };



            for (CH = 0; CH < v_channel; CH++)
            {
               ret = APS168.APS_get_pwm_frequency(Board_ID, CH, ref Frequency);
                freq[CH].Text = Frequency.ToString();

                ret = APS168.APS_get_pwm_width(Board_ID, CH, ref Width);
                width[CH].Text = Width.ToString();

                ret = APS168.APS_get_trigger_count(Board_ID, CH, ref tmp);
                TrigCnt[CH].Text = tmp.ToString();
            }

            //---------------------------
            // Get VAO status by bit
            //
            // Bit 0~7: Table 0~7 is active.   
            // Bit 8~15: Reserved 
            // Bit 16: PWM 0 is enabling. 
            // Bit 17: PWM 1 is enabling. 
            // Bit 18~: Reserved
            //---------------------------
            ret = APS168.APS_get_vao_status(Board_ID, ref Status);
            vao[0].Text = Convert.ToString(Status, 16);
        }

        private void PWM_VAO_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.timer1.Stop();
        }

        public void DoWork()
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;
            Int32 CH = 0; 
            Int32 Frequency = 1000; //Unit: Hz. Range is from 3 to 50000000.
            Int32 Width = 1000;     //Unit: ns. Range is from 20 to 335544300. 


            //Disable all PWM signals. 
            for (CH = 0; CH < 4; CH++)
              ret = APS168.APS_set_pwm_on(Board_ID, CH, OFF);

            //Set PWM parameters
            for (CH = 0; CH < v_channel; CH++)
            {
                ret = APS168.APS_set_pwm_frequency(Board_ID, CH, Frequency);
                ret = APS168.APS_set_pwm_width(Board_ID, CH, Width);
            }

            //Wait for stable
            Thread.Sleep(1);

            /*
            Note:
               The PWM output (TG) is used by two function APIs, that are APS_set_pwm_on() and APS_start_vao(). 
               Don't use them at the same time.
               Be sure that only one of them is enabled, specified PWM channel could rightly work. 
            */

            //start output PWM signal.
            for (CH = 0; CH < v_channel; CH++)
                ret = APS168.APS_set_pwm_on(Board_ID, CH, ON);

            //Wait about 1 sec to show PWM signal (about 1000 periods).
            Thread.Sleep(1000);

            //Disable all PWM signals. 
            for (CH = 0; CH < v_channel; CH++)
                 ret = APS168.APS_set_pwm_on(Board_ID, CH, OFF);

            Is_CreatThread_PWM = NO;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (Is_CreatThread_PWM == NO)
            {
                Thread thread = new Thread(new ThreadStart(DoWork));
                MessageBox.Show("Thread already created, PWM will output !");
                thread.Start();
                Is_CreatThread_PWM = YES;  
            }
            else
                MessageBox.Show("Thread already created !");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Int32 ret = 0;
            Int32 Board_ID = v_board_id;
            Int32 CH = 0;

            for (CH = 0; CH < v_channel; CH++)
                ret = APS168.APS_reset_trigger_count(Board_ID, CH);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Int32 Board_ID = v_board_id;

	        //VAO table number. Range is 0 ~ 7.
	        Int32 Table_No = 0;

	        //Minimum linear speed
	        Int32 MinVelocity = 1000;

	        //Minimum linear speed
	        Int32 VelInterval = 1000;

	        //Total points. Range is 1 ~ 32
	        Int32 TotalPoints = 2;

	        //Output data array
	        // 500  -> 25% duty
	        // 1000 -> 50% duty
	        Int32[] MappingDataArray = new Int32[] {500,1000};

	        Int32 Status = 0;

	        //****************************************************************
	        // Set output type of Table[0]
	        //
	        // 0: output voltage.(reserved)
	        // 1: Fix frequency, change duty ratio.  
	        // 2: Fix pulse width, change frequency. 
	        // 3: Fix duty ratio, change frequency.  
	        //****************************************************************
	        APS168.APS_set_vao_param(  Board_ID, 0x0, 1 );

            //****************************************************************
	        // Set input reference of Table[0]
	        //
	        // 0: feedback speed. 
	        // 1: command speed.  
	        //****************************************************************
	        APS168.APS_set_vao_param(  Board_ID, 0x1, 1 );

            //****************************************************************
	        // Configure PWM according to output type in Table[0]. 
	        //
	        // If you set output type as voltage mode.(output type = 0)
	        //		This value is don't care.
	        //
	        // If output type = 1 (Fix frequency, change duty ratio.  )
	        //      frequency Range: 3 ~ 50M Hz
	        //      
	        // If output type = 2 (Fix pulse width, change frequency. )
	        //		pulse width Range: 20 ~ 335544300 ns
	        //
	        // If output type = 3 (Fix duty ratio, change frequency.  )
	        //		duty cycle Range:   1 ~ 2000 (0%~100%)
	        //
	        //****************************************************************
	        APS168.APS_set_vao_param(  Board_ID, 0x10, 1000 );

	        //Specify axisID for VAO Table[0].
	        APS168.APS_set_vao_param(  Board_ID, 0x20, 0x1 );


	        //set Table[0] parameters
	        APS168.APS_set_vao_table(  Board_ID,  Table_No,  MinVelocity,  VelInterval,  TotalPoints, MappingDataArray );

	        //check parameters of VAO Table[0]
	        APS168.APS_check_vao_param(  Board_ID, Table_No, ref Status );

	        if( Status == 0 )
                MessageBox.Show("VAO Setting Ok");
	        else
                MessageBox.Show("VAO Setting Failed");


	        //Specify which table be executed
	        //if Table_No = -1 that disable all tables.
	        APS168.APS_switch_vao_table(  Board_ID,  Table_No  );

	        //Enable outputs 
	        APS168.APS_start_vao(  Board_ID, 0, ON );
	        APS168.APS_start_vao(  Board_ID, 1, ON );	
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Int32 Board_ID = v_board_id;

            //VAO table number. Range is 0 ~ 7.
            Int32 Table_No = -1;


            //Disable all tables.
            APS168.APS_switch_vao_table(Board_ID, Table_No);

            //Disable outputs
            APS168.APS_start_vao(Board_ID, 0, OFF);
            APS168.APS_start_vao(Board_ID, 1, OFF);

            MessageBox.Show("VAO off");
        }
    }
}