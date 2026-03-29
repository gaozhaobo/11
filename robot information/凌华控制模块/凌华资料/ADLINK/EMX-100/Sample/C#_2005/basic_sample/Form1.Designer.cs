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
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button28 = new System.Windows.Forms.Button();
            this.comboBox_Axis = new System.Windows.Forms.ComboBox();
            this.btnRepeatMove = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button12 = new System.Windows.Forms.Button();
            this.button13 = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxDelayTime = new System.Windows.Forms.TextBox();
            this.button22 = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.CMP_Trigger = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.button1.Location = new System.Drawing.Point(11, 15);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(92, 24);
            this.button1.TabIndex = 0;
            this.button1.Text = "Initial";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.initial_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(11, 45);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(92, 24);
            this.button2.TabIndex = 1;
            this.button2.Text = "Close";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.Close_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(11, 75);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(92, 24);
            this.button3.TabIndex = 2;
            this.button3.Text = "Get Version";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.Get_Version_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(11, 105);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(92, 24);
            this.button4.TabIndex = 3;
            this.button4.Text = "Axis Monitor";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.Axis_Monitor_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 171);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(103, 12);
            this.label1.TabIndex = 7;
            this.label1.Text = "Input Target 1st Axis";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button28);
            this.groupBox1.Controls.Add(this.comboBox_Axis);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.button4);
            this.groupBox1.Controls.Add(this.button3);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(125, 283);
            this.groupBox1.TabIndex = 8;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Start Here";
            // 
            // button28
            // 
            this.button28.Location = new System.Drawing.Point(11, 135);
            this.button28.Name = "button28";
            this.button28.Size = new System.Drawing.Size(92, 24);
            this.button28.TabIndex = 11;
            this.button28.Text = "Load Parameter";
            this.button28.UseVisualStyleBackColor = true;
            this.button28.Click += new System.EventHandler(this.Load_Parameter);
            // 
            // comboBox_Axis
            // 
            this.comboBox_Axis.FormattingEnabled = true;
            this.comboBox_Axis.Location = new System.Drawing.Point(11, 195);
            this.comboBox_Axis.Name = "comboBox_Axis";
            this.comboBox_Axis.Size = new System.Drawing.Size(92, 20);
            this.comboBox_Axis.TabIndex = 8;
            this.comboBox_Axis.SelectedIndexChanged += new System.EventHandler(this.comboBox_Axis_SelectedIndexChanged);
            // 
            // btnRepeatMove
            // 
            this.btnRepeatMove.Location = new System.Drawing.Point(15, 15);
            this.btnRepeatMove.Name = "btnRepeatMove";
            this.btnRepeatMove.Size = new System.Drawing.Size(92, 24);
            this.btnRepeatMove.TabIndex = 16;
            this.btnRepeatMove.Text = "Repeat Move";
            this.btnRepeatMove.UseVisualStyleBackColor = true;
            this.btnRepeatMove.Click += new System.EventHandler(this.RepeatMove);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(22, 14);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(92, 24);
            this.button7.TabIndex = 9;
            this.button7.Text = "Homing";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.Homing_Click);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(22, 44);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(92, 24);
            this.button8.TabIndex = 10;
            this.button8.Text = "Velocity Move";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.Velocity_Move_Click);
            // 
            // button9
            // 
            this.button9.Location = new System.Drawing.Point(22, 74);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(92, 24);
            this.button9.TabIndex = 11;
            this.button9.Text = "Jog ON";
            this.button9.UseVisualStyleBackColor = true;
            this.button9.Click += new System.EventHandler(this.Jog_Click);
            // 
            // button10
            // 
            this.button10.Location = new System.Drawing.Point(22, 104);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(92, 24);
            this.button10.TabIndex = 12;
            this.button10.Text = "Jog OFF";
            this.button10.UseVisualStyleBackColor = true;
            this.button10.Click += new System.EventHandler(this.Jog_off_Click);
            // 
            // button11
            // 
            this.button11.Location = new System.Drawing.Point(22, 134);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(92, 24);
            this.button11.TabIndex = 13;
            this.button11.Text = "P2P Move";
            this.button11.UseVisualStyleBackColor = true;
            this.button11.Click += new System.EventHandler(this.P2P_Move_Click);
            // 
            // button12
            // 
            this.button12.Location = new System.Drawing.Point(22, 164);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(92, 24);
            this.button12.TabIndex = 14;
            this.button12.Text = "Stop Move";
            this.button12.UseVisualStyleBackColor = true;
            this.button12.Click += new System.EventHandler(this.Stop_Move_Click);
            // 
            // button13
            // 
            this.button13.Location = new System.Drawing.Point(22, 194);
            this.button13.Name = "button13";
            this.button13.Size = new System.Drawing.Size(92, 24);
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
            this.groupBox2.Location = new System.Drawing.Point(142, 13);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(125, 282);
            this.groupBox2.TabIndex = 17;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Basic move functions";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.textBoxDelayTime);
            this.groupBox3.Controls.Add(this.btnRepeatMove);
            this.groupBox3.Location = new System.Drawing.Point(272, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(125, 282);
            this.groupBox3.TabIndex = 24;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Advanced";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 51);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 12);
            this.label2.TabIndex = 18;
            this.label2.Text = "Delay (ms)";
            // 
            // textBoxDelayTime
            // 
            this.textBoxDelayTime.Location = new System.Drawing.Point(15, 75);
            this.textBoxDelayTime.Name = "textBoxDelayTime";
            this.textBoxDelayTime.Size = new System.Drawing.Size(92, 22);
            this.textBoxDelayTime.TabIndex = 17;
            this.textBoxDelayTime.Text = "1000";
            // 
            // button22
            // 
            this.button22.Location = new System.Drawing.Point(13, 14);
            this.button22.Name = "button22";
            this.button22.Size = new System.Drawing.Size(92, 24);
            this.button22.TabIndex = 26;
            this.button22.Text = "Digital I/O";
            this.button22.UseVisualStyleBackColor = true;
            this.button22.Click += new System.EventHandler(this.DIO_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.CMP_Trigger);
            this.groupBox4.Controls.Add(this.button22);
            this.groupBox4.Location = new System.Drawing.Point(402, 13);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(125, 282);
            this.groupBox4.TabIndex = 30;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Aux functions";
            // 
            // CMP_Trigger
            // 
            this.CMP_Trigger.Location = new System.Drawing.Point(13, 44);
            this.CMP_Trigger.Name = "CMP_Trigger";
            this.CMP_Trigger.Size = new System.Drawing.Size(92, 24);
            this.CMP_Trigger.TabIndex = 28;
            this.CMP_Trigger.Text = "CMP Trigger";
            this.CMP_Trigger.UseVisualStyleBackColor = true;
            this.CMP_Trigger.Click += new System.EventHandler(this.Compare_trigger);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(540, 312);
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
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnRepeatMove;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button button12;
        private System.Windows.Forms.Button button13;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button button22;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ComboBox comboBox_Axis;
        private System.Windows.Forms.Button button28;
        private System.Windows.Forms.Button CMP_Trigger;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxDelayTime;
        
    }
}

