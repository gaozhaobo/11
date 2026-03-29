namespace basic_sample
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button14 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button12 = new System.Windows.Forms.Button();
            this.button13 = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.button15 = new System.Windows.Forms.Button();
            this.button16 = new System.Windows.Forms.Button();
            this.button17 = new System.Windows.Forms.Button();
            this.button18 = new System.Windows.Forms.Button();
            this.button19 = new System.Windows.Forms.Button();
            this.button20 = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.button21 = new System.Windows.Forms.Button();
            this.button22 = new System.Windows.Forms.Button();
            this.button23 = new System.Windows.Forms.Button();
            this.button24 = new System.Windows.Forms.Button();
            this.button25 = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(11, 17);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(92, 26);
            this.button1.TabIndex = 0;
            this.button1.Text = "Initial";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.initial_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(11, 50);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(92, 26);
            this.button2.TabIndex = 1;
            this.button2.Text = "Close";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.Close_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(11, 82);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(92, 26);
            this.button3.TabIndex = 2;
            this.button3.Text = "Get Version";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.Get_Version_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(11, 115);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(92, 26);
            this.button4.TabIndex = 3;
            this.button4.Text = "Axis Monitor";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.Axis_Monitor_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(11, 147);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(92, 26);
            this.button5.TabIndex = 4;
            this.button5.Text = "Load Param";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.Load_Param_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(11, 180);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(92, 26);
            this.button6.TabIndex = 5;
            this.button6.Text = "Motion Done?";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.Motion_Done_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(11, 232);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(92, 20);
            this.textBox1.TabIndex = 6;
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 216);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(104, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Input Target 1st Axis";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.button6);
            this.groupBox1.Controls.Add(this.button5);
            this.groupBox1.Controls.Add(this.button4);
            this.groupBox1.Controls.Add(this.button3);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Location = new System.Drawing.Point(12, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(118, 271);
            this.groupBox1.TabIndex = 8;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Start Here";
            // 
            // button14
            // 
            this.button14.Location = new System.Drawing.Point(15, 22);
            this.button14.Name = "button14";
            this.button14.Size = new System.Drawing.Size(92, 26);
            this.button14.TabIndex = 16;
            this.button14.Text = "2D Line";
            this.button14.UseVisualStyleBackColor = true;
            this.button14.Click += new System.EventHandler(this._2D_Line_Click);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(22, 16);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(92, 26);
            this.button7.TabIndex = 9;
            this.button7.Text = "Homing";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.Homing_Click);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(22, 49);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(92, 26);
            this.button8.TabIndex = 10;
            this.button8.Text = "Velocity Move";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.Velocity_Move_Click);
            // 
            // button9
            // 
            this.button9.Location = new System.Drawing.Point(22, 81);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(92, 26);
            this.button9.TabIndex = 11;
            this.button9.Text = "Jog ON";
            this.button9.UseVisualStyleBackColor = true;
            this.button9.Click += new System.EventHandler(this.Jog_Click);
            // 
            // button10
            // 
            this.button10.Location = new System.Drawing.Point(22, 114);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(92, 26);
            this.button10.TabIndex = 12;
            this.button10.Text = "Jog OFF";
            this.button10.UseVisualStyleBackColor = true;
            this.button10.Click += new System.EventHandler(this.Jog_off_Click);
            // 
            // button11
            // 
            this.button11.Location = new System.Drawing.Point(22, 146);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(92, 26);
            this.button11.TabIndex = 13;
            this.button11.Text = "P2P Move";
            this.button11.UseVisualStyleBackColor = true;
            this.button11.Click += new System.EventHandler(this.P2P_Move_Click);
            // 
            // button12
            // 
            this.button12.Location = new System.Drawing.Point(22, 179);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(92, 26);
            this.button12.TabIndex = 14;
            this.button12.Text = "Stop Move";
            this.button12.UseVisualStyleBackColor = true;
            this.button12.Click += new System.EventHandler(this.Stop_Move_Click);
            // 
            // button13
            // 
            this.button13.Location = new System.Drawing.Point(22, 211);
            this.button13.Name = "button13";
            this.button13.Size = new System.Drawing.Size(92, 26);
            this.button13.TabIndex = 15;
            this.button13.Text = "EMG Stop";
            this.button13.UseVisualStyleBackColor = true;
            this.button13.Click += new System.EventHandler(this.EMG_Stop_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.button13);
            this.groupBox2.Controls.Add(this.button12);
            this.groupBox2.Controls.Add(this.button11);
            this.groupBox2.Controls.Add(this.button10);
            this.groupBox2.Controls.Add(this.button9);
            this.groupBox2.Controls.Add(this.button8);
            this.groupBox2.Controls.Add(this.button7);
            this.groupBox2.Location = new System.Drawing.Point(136, 13);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(132, 271);
            this.groupBox2.TabIndex = 17;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Basic move functions";
            // 
            // button15
            // 
            this.button15.Location = new System.Drawing.Point(15, 54);
            this.button15.Name = "button15";
            this.button15.Size = new System.Drawing.Size(92, 26);
            this.button15.TabIndex = 18;
            this.button15.Text = "2D Arc";
            this.button15.UseVisualStyleBackColor = true;
            this.button15.Click += new System.EventHandler(this._2D_Arc_Click);
            // 
            // button16
            // 
            this.button16.Location = new System.Drawing.Point(15, 87);
            this.button16.Name = "button16";
            this.button16.Size = new System.Drawing.Size(92, 26);
            this.button16.TabIndex = 19;
            this.button16.Text = "3D Arc";
            this.button16.UseVisualStyleBackColor = true;
            this.button16.Click += new System.EventHandler(this._3D_Arc_Click);
            // 
            // button17
            // 
            this.button17.Location = new System.Drawing.Point(15, 119);
            this.button17.Name = "button17";
            this.button17.Size = new System.Drawing.Size(92, 26);
            this.button17.TabIndex = 20;
            this.button17.Text = "3D Spiral";
            this.button17.UseVisualStyleBackColor = true;
            this.button17.Click += new System.EventHandler(this._3D_Helical_Click);
            // 
            // button18
            // 
            this.button18.Location = new System.Drawing.Point(15, 152);
            this.button18.Name = "button18";
            this.button18.Size = new System.Drawing.Size(92, 26);
            this.button18.TabIndex = 21;
            this.button18.Text = "2D Contour";
            this.button18.UseVisualStyleBackColor = true;
            this.button18.Click += new System.EventHandler(this._2D_Contour_Click);
            // 
            // button19
            // 
            this.button19.Location = new System.Drawing.Point(15, 184);
            this.button19.Name = "button19";
            this.button19.Size = new System.Drawing.Size(92, 26);
            this.button19.TabIndex = 22;
            this.button19.Text = "Point Table";
            this.button19.UseVisualStyleBackColor = true;
            this.button19.Click += new System.EventHandler(this.Point_Table_Click);
            // 
            // button20
            // 
            this.button20.Location = new System.Drawing.Point(15, 217);
            this.button20.Name = "button20";
            this.button20.Size = new System.Drawing.Size(92, 26);
            this.button20.TabIndex = 23;
            this.button20.Text = "Gear / Gantry";
            this.button20.UseVisualStyleBackColor = true;
            this.button20.Click += new System.EventHandler(this.Gear_Gantry_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.button20);
            this.groupBox3.Controls.Add(this.button19);
            this.groupBox3.Controls.Add(this.button18);
            this.groupBox3.Controls.Add(this.button17);
            this.groupBox3.Controls.Add(this.button16);
            this.groupBox3.Controls.Add(this.button15);
            this.groupBox3.Controls.Add(this.button14);
            this.groupBox3.Location = new System.Drawing.Point(280, 13);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(127, 271);
            this.groupBox3.TabIndex = 24;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Interpolation";
            // 
            // button21
            // 
            this.button21.Location = new System.Drawing.Point(13, 26);
            this.button21.Name = "button21";
            this.button21.Size = new System.Drawing.Size(92, 26);
            this.button21.TabIndex = 25;
            this.button21.Text = "Interrupt";
            this.button21.UseVisualStyleBackColor = true;
            this.button21.Click += new System.EventHandler(this.Interrupt_Click);
            // 
            // button22
            // 
            this.button22.Location = new System.Drawing.Point(13, 59);
            this.button22.Name = "button22";
            this.button22.Size = new System.Drawing.Size(92, 26);
            this.button22.TabIndex = 26;
            this.button22.Text = "Digital I/O";
            this.button22.UseVisualStyleBackColor = true;
            this.button22.Click += new System.EventHandler(this.DIO_Click);
            // 
            // button23
            // 
            this.button23.Location = new System.Drawing.Point(13, 91);
            this.button23.Name = "button23";
            this.button23.Size = new System.Drawing.Size(92, 26);
            this.button23.TabIndex = 27;
            this.button23.Text = "Analog I/O";
            this.button23.UseVisualStyleBackColor = true;
            this.button23.Click += new System.EventHandler(this.Analog_IO_Click);
            // 
            // button24
            // 
            this.button24.Location = new System.Drawing.Point(13, 124);
            this.button24.Name = "button24";
            this.button24.Size = new System.Drawing.Size(92, 26);
            this.button24.TabIndex = 28;
            this.button24.Text = "CMP Trigger";
            this.button24.UseVisualStyleBackColor = true;
            this.button24.Click += new System.EventHandler(this.CMP_Trigger_Click);
            // 
            // button25
            // 
            this.button25.Location = new System.Drawing.Point(13, 156);
            this.button25.Name = "button25";
            this.button25.Size = new System.Drawing.Size(92, 26);
            this.button25.TabIndex = 29;
            this.button25.Text = "PWM / VAO";
            this.button25.UseVisualStyleBackColor = true;
            this.button25.Click += new System.EventHandler(this.PWM_VAO_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.button25);
            this.groupBox4.Controls.Add(this.button24);
            this.groupBox4.Controls.Add(this.button23);
            this.groupBox4.Controls.Add(this.button22);
            this.groupBox4.Controls.Add(this.button21);
            this.groupBox4.Location = new System.Drawing.Point(413, 14);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(125, 270);
            this.groupBox4.TabIndex = 30;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Aux functions";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(547, 293);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button14;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button button12;
        private System.Windows.Forms.Button button13;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button button15;
        private System.Windows.Forms.Button button16;
        private System.Windows.Forms.Button button17;
        private System.Windows.Forms.Button button18;
        private System.Windows.Forms.Button button19;
        private System.Windows.Forms.Button button20;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button button21;
        private System.Windows.Forms.Button button22;
        private System.Windows.Forms.Button button23;
        private System.Windows.Forms.Button button24;
        private System.Windows.Forms.Button button25;
        private System.Windows.Forms.GroupBox groupBox4;
        
    }
}

