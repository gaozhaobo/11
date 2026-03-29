namespace CameraDemo
{
    partial class CameraDemo
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.btnEnumDevice = new System.Windows.Forms.Button();
            this.PreviewPanel1 = new System.Windows.Forms.Panel();
            this.Snap = new System.Windows.Forms.Button();
            this.PreviewPanel2 = new System.Windows.Forms.Panel();
            this.groupBoxVerInfo = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBoxLogin = new System.Windows.Forms.GroupBox();
            this.checkBoxEnable1 = new System.Windows.Forms.CheckBox();
            this.comboBoxVideo1Param = new System.Windows.Forms.ComboBox();
            this.textDevice1Name = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.checkBoxEnable2 = new System.Windows.Forms.CheckBox();
            this.comboBoxVideo2Param = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textDevice2Name = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btStopPreview = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.checkBoxEnableFD = new System.Windows.Forms.CheckBox();
            this.groupBoxVerInfo.SuspendLayout();
            this.groupBoxLogin.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnEnumDevice
            // 
            this.btnEnumDevice.Location = new System.Drawing.Point(904, 29);
            this.btnEnumDevice.Name = "btnEnumDevice";
            this.btnEnumDevice.Size = new System.Drawing.Size(75, 23);
            this.btnEnumDevice.TabIndex = 4;
            this.btnEnumDevice.Text = "开始预览";
            this.btnEnumDevice.Click += new System.EventHandler(this.btnEnumDevice_Click);
            // 
            // PreviewPanel1
            // 
            this.PreviewPanel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PreviewPanel1.Location = new System.Drawing.Point(20, 122);
            this.PreviewPanel1.Name = "PreviewPanel1";
            this.PreviewPanel1.Size = new System.Drawing.Size(465, 392);
            this.PreviewPanel1.TabIndex = 2;
            // 
            // Snap
            // 
            this.Snap.Location = new System.Drawing.Point(720, 82);
            this.Snap.Name = "Snap";
            this.Snap.Size = new System.Drawing.Size(75, 23);
            this.Snap.TabIndex = 5;
            this.Snap.Text = "抓图";
            this.Snap.Click += new System.EventHandler(this.Snap_Click);
            // 
            // PreviewPanel2
            // 
            this.PreviewPanel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PreviewPanel2.Location = new System.Drawing.Point(508, 122);
            this.PreviewPanel2.Name = "PreviewPanel2";
            this.PreviewPanel2.Size = new System.Drawing.Size(497, 392);
            this.PreviewPanel2.TabIndex = 3;
            // 
            // groupBoxVerInfo
            // 
            this.groupBoxVerInfo.Controls.Add(this.label2);
            this.groupBoxVerInfo.Location = new System.Drawing.Point(20, 6);
            this.groupBoxVerInfo.Name = "groupBoxVerInfo";
            this.groupBoxVerInfo.Size = new System.Drawing.Size(157, 46);
            this.groupBoxVerInfo.TabIndex = 7;
            this.groupBoxVerInfo.TabStop = false;
            this.groupBoxVerInfo.Text = "版本信息";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(30, 25);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(107, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "HCUsbSDK V2.0.0.5";
            // 
            // groupBoxLogin
            // 
            this.groupBoxLogin.Controls.Add(this.checkBoxEnable1);
            this.groupBoxLogin.Controls.Add(this.comboBoxVideo1Param);
            this.groupBoxLogin.Controls.Add(this.textDevice1Name);
            this.groupBoxLogin.Controls.Add(this.label7);
            this.groupBoxLogin.Controls.Add(this.label5);
            this.groupBoxLogin.Location = new System.Drawing.Point(199, 8);
            this.groupBoxLogin.Name = "groupBoxLogin";
            this.groupBoxLogin.Size = new System.Drawing.Size(502, 40);
            this.groupBoxLogin.TabIndex = 8;
            this.groupBoxLogin.TabStop = false;
            this.groupBoxLogin.Text = "设备1";
            // 
            // checkBoxEnable1
            // 
            this.checkBoxEnable1.AutoSize = true;
            this.checkBoxEnable1.Location = new System.Drawing.Point(4, 16);
            this.checkBoxEnable1.Name = "checkBoxEnable1";
            this.checkBoxEnable1.Size = new System.Drawing.Size(48, 16);
            this.checkBoxEnable1.TabIndex = 13;
            this.checkBoxEnable1.Text = "开启";
            this.checkBoxEnable1.UseVisualStyleBackColor = true;
            // 
            // comboBoxVideo1Param
            // 
            this.comboBoxVideo1Param.FormattingEnabled = true;
            this.comboBoxVideo1Param.Location = new System.Drawing.Point(309, 15);
            this.comboBoxVideo1Param.Name = "comboBoxVideo1Param";
            this.comboBoxVideo1Param.Size = new System.Drawing.Size(176, 20);
            this.comboBoxVideo1Param.TabIndex = 12;
            // 
            // textDevice1Name
            // 
            this.textDevice1Name.Location = new System.Drawing.Point(116, 13);
            this.textDevice1Name.Name = "textDevice1Name";
            this.textDevice1Name.Size = new System.Drawing.Size(100, 21);
            this.textDevice1Name.TabIndex = 2;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(247, 16);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(65, 12);
            this.label7.TabIndex = 11;
            this.label7.Text = "视频参数：";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(58, 17);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(65, 12);
            this.label5.TabIndex = 0;
            this.label5.Text = "设备名称：";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.checkBoxEnable2);
            this.groupBox1.Controls.Add(this.comboBoxVideo2Param);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.textDevice2Name);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(199, 54);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(502, 40);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "设备2";
            // 
            // checkBoxEnable2
            // 
            this.checkBoxEnable2.AutoSize = true;
            this.checkBoxEnable2.Location = new System.Drawing.Point(5, 17);
            this.checkBoxEnable2.Name = "checkBoxEnable2";
            this.checkBoxEnable2.Size = new System.Drawing.Size(48, 16);
            this.checkBoxEnable2.TabIndex = 14;
            this.checkBoxEnable2.Text = "开启";
            this.checkBoxEnable2.UseVisualStyleBackColor = true;
            // 
            // comboBoxVideo2Param
            // 
            this.comboBoxVideo2Param.FormattingEnabled = true;
            this.comboBoxVideo2Param.Location = new System.Drawing.Point(309, 14);
            this.comboBoxVideo2Param.Name = "comboBoxVideo2Param";
            this.comboBoxVideo2Param.Size = new System.Drawing.Size(176, 20);
            this.comboBoxVideo2Param.TabIndex = 14;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(247, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 13;
            this.label3.Text = "视频参数：";
            // 
            // textDevice2Name
            // 
            this.textDevice2Name.Location = new System.Drawing.Point(116, 13);
            this.textDevice2Name.Name = "textDevice2Name";
            this.textDevice2Name.Size = new System.Drawing.Size(100, 21);
            this.textDevice2Name.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(58, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "设备名称：";
            // 
            // btStopPreview
            // 
            this.btStopPreview.Location = new System.Drawing.Point(904, 77);
            this.btStopPreview.Name = "btStopPreview";
            this.btStopPreview.Size = new System.Drawing.Size(75, 23);
            this.btStopPreview.TabIndex = 11;
            this.btStopPreview.Text = "停止预览";
            this.btStopPreview.Click += new System.EventHandler(this.btStopPreview_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.checkBoxEnableFD);
            this.groupBox2.Location = new System.Drawing.Point(720, 21);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(157, 46);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "人脸";
            // 
            // checkBoxEnableFD
            // 
            this.checkBoxEnableFD.AutoSize = true;
            this.checkBoxEnableFD.Location = new System.Drawing.Point(20, 20);
            this.checkBoxEnableFD.Name = "checkBoxEnableFD";
            this.checkBoxEnableFD.Size = new System.Drawing.Size(96, 16);
            this.checkBoxEnableFD.TabIndex = 14;
            this.checkBoxEnableFD.Text = "开启人脸识别";
            this.checkBoxEnableFD.UseVisualStyleBackColor = true;
            this.checkBoxEnableFD.CheckedChanged += new System.EventHandler(this.checkBoxEnableFD_CheckedChanged);
            // 
            // CameraDemo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1010, 526);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.btStopPreview);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBoxLogin);
            this.Controls.Add(this.groupBoxVerInfo);
            this.Controls.Add(this.PreviewPanel2);
            this.Controls.Add(this.Snap);
            this.Controls.Add(this.PreviewPanel1);
            this.Controls.Add(this.btnEnumDevice);
            this.Name = "CameraDemo";
            this.Text = "CameraDemo";
            this.Load += new System.EventHandler(this.CameraDemo_Load);
            this.groupBoxVerInfo.ResumeLayout(false);
            this.groupBoxVerInfo.PerformLayout();
            this.groupBoxLogin.ResumeLayout(false);
            this.groupBoxLogin.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnEnumDevice;
        private System.Windows.Forms.Panel PreviewPanel1;
        private System.Windows.Forms.Button Snap;
        private System.Windows.Forms.Panel PreviewPanel2;
        private System.Windows.Forms.GroupBox groupBoxVerInfo;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBoxLogin;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textDevice1Name;
        private System.Windows.Forms.TextBox textDevice2Name;
        private System.Windows.Forms.ComboBox comboBoxVideo1Param;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox comboBoxVideo2Param;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox checkBoxEnable1;
        private System.Windows.Forms.CheckBox checkBoxEnable2;
        private System.Windows.Forms.Button btStopPreview;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox checkBoxEnableFD;
    }
}

