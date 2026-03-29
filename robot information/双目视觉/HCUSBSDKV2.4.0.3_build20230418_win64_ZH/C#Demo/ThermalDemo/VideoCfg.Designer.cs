namespace ThermalDemo
{
    partial class VideoCfg
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
            this.btnSet = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnGet = new System.Windows.Forms.Button();
            this.textBoxPowerLineFrequencyMode = new System.Windows.Forms.TextBox();
            this.comboBoxCorridor = new System.Windows.Forms.ComboBox();
            this.comboBoxImageFlipStyle = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnSet
            // 
            this.btnSet.Location = new System.Drawing.Point(243, 79);
            this.btnSet.Name = "btnSet";
            this.btnSet.Size = new System.Drawing.Size(48, 23);
            this.btnSet.TabIndex = 12;
            this.btnSet.Text = "设置";
            this.btnSet.UseVisualStyleBackColor = true;
            this.btnSet.Click += new System.EventHandler(this.btnSet_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(14, 41);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 4;
            this.label3.Text = "镜像模式";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(163, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 6;
            this.label2.Text = "视频制式";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnGet);
            this.groupBox2.Controls.Add(this.textBoxPowerLineFrequencyMode);
            this.groupBox2.Controls.Add(this.comboBoxCorridor);
            this.groupBox2.Controls.Add(this.btnSet);
            this.groupBox2.Controls.Add(this.comboBoxImageFlipStyle);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Location = new System.Drawing.Point(12, 22);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(298, 119);
            this.groupBox2.TabIndex = 13;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "视频调整参数";
            // 
            // btnGet
            // 
            this.btnGet.Location = new System.Drawing.Point(174, 79);
            this.btnGet.Name = "btnGet";
            this.btnGet.Size = new System.Drawing.Size(51, 23);
            this.btnGet.TabIndex = 14;
            this.btnGet.Text = "获取";
            this.btnGet.UseVisualStyleBackColor = true;
            this.btnGet.Click += new System.EventHandler(this.btnGet_Click);
            // 
            // textBoxPowerLineFrequencyMode
            // 
            this.textBoxPowerLineFrequencyMode.Location = new System.Drawing.Point(222, 38);
            this.textBoxPowerLineFrequencyMode.MaxLength = 100;
            this.textBoxPowerLineFrequencyMode.Name = "textBoxPowerLineFrequencyMode";
            this.textBoxPowerLineFrequencyMode.Size = new System.Drawing.Size(69, 21);
            this.textBoxPowerLineFrequencyMode.TabIndex = 26;
            this.textBoxPowerLineFrequencyMode.Text = "PAL";
            // 
            // comboBoxCorridor
            // 
            this.comboBoxCorridor.FormattingEnabled = true;
            this.comboBoxCorridor.Items.AddRange(new object[] {
            "关闭",
            "开启"});
            this.comboBoxCorridor.Location = new System.Drawing.Point(71, 79);
            this.comboBoxCorridor.Name = "comboBoxCorridor";
            this.comboBoxCorridor.Size = new System.Drawing.Size(86, 20);
            this.comboBoxCorridor.TabIndex = 10;
            // 
            // comboBoxImageFlipStyle
            // 
            this.comboBoxImageFlipStyle.FormattingEnabled = true;
            this.comboBoxImageFlipStyle.Items.AddRange(new object[] {
            "关闭",
            "中心",
            "左右",
            "上下"});
            this.comboBoxImageFlipStyle.Location = new System.Drawing.Point(71, 37);
            this.comboBoxImageFlipStyle.Name = "comboBoxImageFlipStyle";
            this.comboBoxImageFlipStyle.Size = new System.Drawing.Size(86, 20);
            this.comboBoxImageFlipStyle.TabIndex = 9;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 82);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 8;
            this.label1.Text = "走廊模式";
            // 
            // VideoCfg
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(328, 147);
            this.Controls.Add(this.groupBox2);
            this.Name = "VideoCfg";
            this.Text = "VideoCfg";
            this.Load += new System.EventHandler(this.VideoCfg_Load);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnSet;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnGet;
        private System.Windows.Forms.ComboBox comboBoxCorridor;
        private System.Windows.Forms.ComboBox comboBoxImageFlipStyle;
        private System.Windows.Forms.TextBox textBoxPowerLineFrequencyMode;
    }
}