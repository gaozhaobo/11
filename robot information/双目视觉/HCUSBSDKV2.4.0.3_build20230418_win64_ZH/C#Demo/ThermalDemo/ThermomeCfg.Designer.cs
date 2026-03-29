namespace ThermalDemo
{
    partial class ThermomeCfg
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
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.checkBoxComPensation = new System.Windows.Forms.CheckBox();
            this.textEnvironmentalTemperature = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.textCompensationValue = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.comboBoxTemperatureMode = new System.Windows.Forms.ComboBox();
            this.label10 = new System.Windows.Forms.Label();
            this.comboBoxCurveSensitivityLevel = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.comboBoxType = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.btnget = new System.Windows.Forms.Button();
            this.btnset = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textCentrePointY = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.textCentrePointX = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxDistance = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxEmissivity = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.checkBoxBlack = new System.Windows.Forms.CheckBox();
            this.buttonGet = new System.Windows.Forms.Button();
            this.buttonSet = new System.Windows.Forms.Button();
            this.txtTemperature = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.checkBoxComPensation);
            this.groupBox2.Controls.Add(this.textEnvironmentalTemperature);
            this.groupBox2.Controls.Add(this.label12);
            this.groupBox2.Controls.Add(this.textCompensationValue);
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Controls.Add(this.comboBoxTemperatureMode);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.comboBoxCurveSensitivityLevel);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.comboBoxType);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.btnget);
            this.groupBox2.Controls.Add(this.btnset);
            this.groupBox2.Location = new System.Drawing.Point(394, 22);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(337, 243);
            this.groupBox2.TabIndex = 17;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "体温补偿参数";
            // 
            // checkBoxComPensation
            // 
            this.checkBoxComPensation.AutoSize = true;
            this.checkBoxComPensation.Location = new System.Drawing.Point(19, 33);
            this.checkBoxComPensation.Name = "checkBoxComPensation";
            this.checkBoxComPensation.Size = new System.Drawing.Size(48, 16);
            this.checkBoxComPensation.TabIndex = 27;
            this.checkBoxComPensation.Text = "开启";
            this.checkBoxComPensation.UseVisualStyleBackColor = true;
            // 
            // textEnvironmentalTemperature
            // 
            this.textEnvironmentalTemperature.Location = new System.Drawing.Point(244, 144);
            this.textEnvironmentalTemperature.MaxLength = 100;
            this.textEnvironmentalTemperature.Name = "textEnvironmentalTemperature";
            this.textEnvironmentalTemperature.Size = new System.Drawing.Size(87, 21);
            this.textEnvironmentalTemperature.TabIndex = 26;
            // 
            // label12
            // 
            this.label12.Location = new System.Drawing.Point(162, 150);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(81, 15);
            this.label12.TabIndex = 25;
            this.label12.Text = "环境温度:";
            this.label12.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // textCompensationValue
            // 
            this.textCompensationValue.Location = new System.Drawing.Point(246, 106);
            this.textCompensationValue.MaxLength = 100;
            this.textCompensationValue.Name = "textCompensationValue";
            this.textCompensationValue.Size = new System.Drawing.Size(85, 21);
            this.textCompensationValue.TabIndex = 24;
            // 
            // label11
            // 
            this.label11.Location = new System.Drawing.Point(164, 112);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(81, 15);
            this.label11.TabIndex = 23;
            this.label11.Text = "补偿温度:";
            this.label11.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // comboBoxTemperatureMode
            // 
            this.comboBoxTemperatureMode.FormattingEnabled = true;
            this.comboBoxTemperatureMode.Items.AddRange(new object[] {
            "自动模式",
            "手动模式"});
            this.comboBoxTemperatureMode.Location = new System.Drawing.Point(246, 70);
            this.comboBoxTemperatureMode.Name = "comboBoxTemperatureMode";
            this.comboBoxTemperatureMode.Size = new System.Drawing.Size(85, 20);
            this.comboBoxTemperatureMode.TabIndex = 22;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(187, 74);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(53, 12);
            this.label10.TabIndex = 21;
            this.label10.Text = "温度模式";
            // 
            // comboBoxCurveSensitivityLevel
            // 
            this.comboBoxCurveSensitivityLevel.FormattingEnabled = true;
            this.comboBoxCurveSensitivityLevel.Items.AddRange(new object[] {
            "低",
            "中",
            "高"});
            this.comboBoxCurveSensitivityLevel.Location = new System.Drawing.Point(76, 107);
            this.comboBoxCurveSensitivityLevel.Name = "comboBoxCurveSensitivityLevel";
            this.comboBoxCurveSensitivityLevel.Size = new System.Drawing.Size(82, 20);
            this.comboBoxCurveSensitivityLevel.TabIndex = 18;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(17, 111);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(65, 12);
            this.label8.TabIndex = 17;
            this.label8.Text = "灵敏度等级";
            // 
            // comboBoxType
            // 
            this.comboBoxType.FormattingEnabled = true;
            this.comboBoxType.Items.AddRange(new object[] {
            "手动补偿",
            "自动补偿"});
            this.comboBoxType.Location = new System.Drawing.Point(76, 70);
            this.comboBoxType.Name = "comboBoxType";
            this.comboBoxType.Size = new System.Drawing.Size(84, 20);
            this.comboBoxType.TabIndex = 16;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(17, 74);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 15;
            this.label7.Text = "补偿方式";
            // 
            // btnget
            // 
            this.btnget.Location = new System.Drawing.Point(109, 204);
            this.btnget.Name = "btnget";
            this.btnget.Size = new System.Drawing.Size(51, 23);
            this.btnget.TabIndex = 14;
            this.btnget.Text = "获取";
            this.btnget.UseVisualStyleBackColor = true;
            this.btnget.Click += new System.EventHandler(this.btnget_Click);
            // 
            // btnset
            // 
            this.btnset.Location = new System.Drawing.Point(191, 204);
            this.btnset.Name = "btnset";
            this.btnset.Size = new System.Drawing.Size(51, 23);
            this.btnset.TabIndex = 13;
            this.btnset.Text = "设置";
            this.btnset.UseVisualStyleBackColor = true;
            this.btnset.Click += new System.EventHandler(this.btnset_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textCentrePointY);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.textCentrePointX);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.textBoxDistance);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.textBoxEmissivity);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.checkBoxBlack);
            this.groupBox1.Controls.Add(this.buttonGet);
            this.groupBox1.Controls.Add(this.buttonSet);
            this.groupBox1.Controls.Add(this.txtTemperature);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(12, 22);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(328, 243);
            this.groupBox1.TabIndex = 16;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "黑体参数";
            // 
            // textCentrePointY
            // 
            this.textCentrePointY.Location = new System.Drawing.Point(228, 132);
            this.textCentrePointY.MaxLength = 100;
            this.textCentrePointY.Name = "textCentrePointY";
            this.textCentrePointY.Size = new System.Drawing.Size(66, 21);
            this.textCentrePointY.TabIndex = 26;
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(164, 137);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(70, 15);
            this.label6.TabIndex = 25;
            this.label6.Text = "Y：";
            this.label6.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // textCentrePointX
            // 
            this.textCentrePointX.Location = new System.Drawing.Point(73, 132);
            this.textCentrePointX.MaxLength = 100;
            this.textCentrePointX.Name = "textCentrePointX";
            this.textCentrePointX.Size = new System.Drawing.Size(66, 21);
            this.textCentrePointX.TabIndex = 24;
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(9, 137);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(70, 15);
            this.label5.TabIndex = 23;
            this.label5.Text = "X：";
            this.label5.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // textBoxDistance
            // 
            this.textBoxDistance.Location = new System.Drawing.Point(73, 93);
            this.textBoxDistance.MaxLength = 100;
            this.textBoxDistance.Name = "textBoxDistance";
            this.textBoxDistance.Size = new System.Drawing.Size(66, 21);
            this.textBoxDistance.TabIndex = 22;
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(9, 98);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(70, 15);
            this.label4.TabIndex = 21;
            this.label4.Text = "距离：";
            this.label4.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // textBoxEmissivity
            // 
            this.textBoxEmissivity.Location = new System.Drawing.Point(228, 53);
            this.textBoxEmissivity.MaxLength = 100;
            this.textBoxEmissivity.Name = "textBoxEmissivity";
            this.textBoxEmissivity.Size = new System.Drawing.Size(66, 21);
            this.textBoxEmissivity.TabIndex = 20;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(164, 58);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(70, 15);
            this.label3.TabIndex = 19;
            this.label3.Text = "发射率：";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // checkBoxBlack
            // 
            this.checkBoxBlack.AutoSize = true;
            this.checkBoxBlack.Location = new System.Drawing.Point(31, 53);
            this.checkBoxBlack.Name = "checkBoxBlack";
            this.checkBoxBlack.Size = new System.Drawing.Size(48, 16);
            this.checkBoxBlack.TabIndex = 18;
            this.checkBoxBlack.Text = "开启";
            this.checkBoxBlack.UseVisualStyleBackColor = true;
            // 
            // buttonGet
            // 
            this.buttonGet.Location = new System.Drawing.Point(63, 204);
            this.buttonGet.Name = "buttonGet";
            this.buttonGet.Size = new System.Drawing.Size(51, 23);
            this.buttonGet.TabIndex = 14;
            this.buttonGet.Text = "获取";
            this.buttonGet.UseVisualStyleBackColor = true;
            this.buttonGet.Click += new System.EventHandler(this.buttonGet_Click);
            // 
            // buttonSet
            // 
            this.buttonSet.Location = new System.Drawing.Point(141, 204);
            this.buttonSet.Name = "buttonSet";
            this.buttonSet.Size = new System.Drawing.Size(51, 23);
            this.buttonSet.TabIndex = 13;
            this.buttonSet.Text = "设置";
            this.buttonSet.UseVisualStyleBackColor = true;
            this.buttonSet.Click += new System.EventHandler(this.buttonSet_Click);
            // 
            // txtTemperature
            // 
            this.txtTemperature.Location = new System.Drawing.Point(228, 92);
            this.txtTemperature.MaxLength = 100;
            this.txtTemperature.Name = "txtTemperature";
            this.txtTemperature.Size = new System.Drawing.Size(66, 21);
            this.txtTemperature.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(164, 97);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(70, 15);
            this.label1.TabIndex = 5;
            this.label1.Text = "温度：";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // ThermomeCfg
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(794, 302);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "ThermomeCfg";
            this.Text = "ThermomeCfg";
            this.Load += new System.EventHandler(this.ThermomeCfg_Load);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnget;
        private System.Windows.Forms.Button btnset;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textCentrePointY;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textCentrePointX;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxDistance;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxEmissivity;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox checkBoxBlack;
        private System.Windows.Forms.Button buttonGet;
        private System.Windows.Forms.Button buttonSet;
        private System.Windows.Forms.TextBox txtTemperature;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox checkBoxComPensation;
        private System.Windows.Forms.TextBox textEnvironmentalTemperature;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox textCompensationValue;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.ComboBox comboBoxTemperatureMode;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.ComboBox comboBoxCurveSensitivityLevel;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox comboBoxType;
        private System.Windows.Forms.Label label7;
    }
}