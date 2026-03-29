namespace ThermalDemo
{
    partial class ThermalDemo
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
            this.groupBoxInfo = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBoxVerInfo = new System.Windows.Forms.GroupBox();
            this.groupBoxLogin = new System.Windows.Forms.GroupBox();
            this.buttonReboot = new System.Windows.Forms.Button();
            this.btnLogout = new System.Windows.Forms.Button();
            this.btnLogin = new System.Windows.Forms.Button();
            this.btnEnum = new System.Windows.Forms.Button();
            this.listViewDeviceInfo = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader11 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader12 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.groupBoxDeviceInfo = new System.Windows.Forms.GroupBox();
            this.listView1 = new System.Windows.Forms.ListView();
            this.PreviewPanel = new System.Windows.Forms.Panel();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.buttonAppendData = new System.Windows.Forms.Button();
            this.btnThermomeCfg = new System.Windows.Forms.Button();
            this.btnImageCfg = new System.Windows.Forms.Button();
            this.buttonVideoCfg = new System.Windows.Forms.Button();
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader10 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.listViewInfo = new System.Windows.Forms.ListView();
            this.groupBoxInfo.SuspendLayout();
            this.groupBoxVerInfo.SuspendLayout();
            this.groupBoxLogin.SuspendLayout();
            this.groupBoxDeviceInfo.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxInfo
            // 
            this.groupBoxInfo.Controls.Add(this.listViewInfo);
            this.groupBoxInfo.Location = new System.Drawing.Point(10, 457);
            this.groupBoxInfo.Name = "groupBoxInfo";
            this.groupBoxInfo.Size = new System.Drawing.Size(750, 269);
            this.groupBoxInfo.TabIndex = 5;
            this.groupBoxInfo.TabStop = false;
            this.groupBoxInfo.Text = "日志";
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
            // groupBoxVerInfo
            // 
            this.groupBoxVerInfo.Controls.Add(this.label2);
            this.groupBoxVerInfo.Location = new System.Drawing.Point(6, 12);
            this.groupBoxVerInfo.Name = "groupBoxVerInfo";
            this.groupBoxVerInfo.Size = new System.Drawing.Size(190, 46);
            this.groupBoxVerInfo.TabIndex = 6;
            this.groupBoxVerInfo.TabStop = false;
            this.groupBoxVerInfo.Text = "版本信息";
            // 
            // groupBoxLogin
            // 
            this.groupBoxLogin.Controls.Add(this.buttonReboot);
            this.groupBoxLogin.Controls.Add(this.btnLogout);
            this.groupBoxLogin.Controls.Add(this.btnLogin);
            this.groupBoxLogin.Controls.Add(this.btnEnum);
            this.groupBoxLogin.Location = new System.Drawing.Point(214, 12);
            this.groupBoxLogin.Name = "groupBoxLogin";
            this.groupBoxLogin.Size = new System.Drawing.Size(558, 46);
            this.groupBoxLogin.TabIndex = 7;
            this.groupBoxLogin.TabStop = false;
            this.groupBoxLogin.Text = "设备操作";
            // 
            // buttonReboot
            // 
            this.buttonReboot.Enabled = false;
            this.buttonReboot.Location = new System.Drawing.Point(445, 17);
            this.buttonReboot.Name = "buttonReboot";
            this.buttonReboot.Size = new System.Drawing.Size(75, 23);
            this.buttonReboot.TabIndex = 11;
            this.buttonReboot.Text = "重启";
            this.buttonReboot.UseVisualStyleBackColor = true;
            this.buttonReboot.Click += new System.EventHandler(this.buttonReboot_Click);
            // 
            // btnLogout
            // 
            this.btnLogout.Enabled = false;
            this.btnLogout.Location = new System.Drawing.Point(321, 17);
            this.btnLogout.Name = "btnLogout";
            this.btnLogout.Size = new System.Drawing.Size(75, 23);
            this.btnLogout.TabIndex = 10;
            this.btnLogout.Text = "注销";
            this.btnLogout.UseVisualStyleBackColor = true;
            this.btnLogout.Click += new System.EventHandler(this.btnLogout_Click);
            // 
            // btnLogin
            // 
            this.btnLogin.Enabled = false;
            this.btnLogin.Location = new System.Drawing.Point(185, 17);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(75, 23);
            this.btnLogin.TabIndex = 9;
            this.btnLogin.Text = "登录";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.btnLogin_Click);
            // 
            // btnEnum
            // 
            this.btnEnum.Location = new System.Drawing.Point(57, 17);
            this.btnEnum.Name = "btnEnum";
            this.btnEnum.Size = new System.Drawing.Size(75, 23);
            this.btnEnum.TabIndex = 8;
            this.btnEnum.Text = "枚举";
            this.btnEnum.UseVisualStyleBackColor = true;
            this.btnEnum.Click += new System.EventHandler(this.btnEnum_Click);
            // 
            // listViewDeviceInfo
            // 
            this.listViewDeviceInfo.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader11,
            this.columnHeader12});
            this.listViewDeviceInfo.FullRowSelect = true;
            this.listViewDeviceInfo.GridLines = true;
            this.listViewDeviceInfo.Location = new System.Drawing.Point(10, 16);
            this.listViewDeviceInfo.MultiSelect = false;
            this.listViewDeviceInfo.Name = "listViewDeviceInfo";
            this.listViewDeviceInfo.Size = new System.Drawing.Size(737, 126);
            this.listViewDeviceInfo.TabIndex = 1;
            this.listViewDeviceInfo.UseCompatibleStateImageBehavior = false;
            this.listViewDeviceInfo.View = System.Windows.Forms.View.Details;
            this.listViewDeviceInfo.SelectedIndexChanged += new System.EventHandler(this.listViewDeviceInfo_SelectedIndexChanged);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Index";
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "VID";
            this.columnHeader2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "PID";
            this.columnHeader3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "制造商";
            this.columnHeader4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader4.Width = 120;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "设备名称";
            this.columnHeader5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader5.Width = 140;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "设备序列号";
            this.columnHeader6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader6.Width = 140;
            // 
            // columnHeader11
            // 
            this.columnHeader11.Text = "已登录";
            // 
            // columnHeader12
            // 
            this.columnHeader12.Text = "已激活";
            this.columnHeader12.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // groupBoxDeviceInfo
            // 
            this.groupBoxDeviceInfo.Controls.Add(this.listViewDeviceInfo);
            this.groupBoxDeviceInfo.Controls.Add(this.listView1);
            this.groupBoxDeviceInfo.Location = new System.Drawing.Point(6, 69);
            this.groupBoxDeviceInfo.Name = "groupBoxDeviceInfo";
            this.groupBoxDeviceInfo.Size = new System.Drawing.Size(754, 152);
            this.groupBoxDeviceInfo.TabIndex = 8;
            this.groupBoxDeviceInfo.TabStop = false;
            this.groupBoxDeviceInfo.Text = "设备列表";
            // 
            // listView1
            // 
            this.listView1.Location = new System.Drawing.Point(10, 20);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(566, 97);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // PreviewPanel
            // 
            this.PreviewPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.PreviewPanel.Location = new System.Drawing.Point(97, 227);
            this.PreviewPanel.Name = "PreviewPanel";
            this.PreviewPanel.Size = new System.Drawing.Size(362, 233);
            this.PreviewPanel.TabIndex = 9;
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(10, 268);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(75, 23);
            this.btnStart.TabIndex = 11;
            this.btnStart.Text = "开始预览";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(10, 358);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(75, 23);
            this.btnStop.TabIndex = 12;
            this.btnStop.Text = "停止预览";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonAppendData);
            this.groupBox1.Controls.Add(this.btnThermomeCfg);
            this.groupBox1.Controls.Add(this.btnImageCfg);
            this.groupBox1.Controls.Add(this.buttonVideoCfg);
            this.groupBox1.Location = new System.Drawing.Point(476, 227);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(278, 233);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "配置操作";
            // 
            // buttonAppendData
            // 
            this.buttonAppendData.Location = new System.Drawing.Point(207, 41);
            this.buttonAppendData.Name = "buttonAppendData";
            this.buttonAppendData.Size = new System.Drawing.Size(51, 23);
            this.buttonAppendData.TabIndex = 14;
            this.buttonAppendData.Text = "热图";
            this.buttonAppendData.UseVisualStyleBackColor = true;
            this.buttonAppendData.Click += new System.EventHandler(this.buttonAppendData_Click);
            // 
            // btnThermomeCfg
            // 
            this.btnThermomeCfg.Location = new System.Drawing.Point(17, 86);
            this.btnThermomeCfg.Name = "btnThermomeCfg";
            this.btnThermomeCfg.Size = new System.Drawing.Size(75, 23);
            this.btnThermomeCfg.TabIndex = 13;
            this.btnThermomeCfg.Text = "测温参数";
            this.btnThermomeCfg.UseVisualStyleBackColor = true;
            this.btnThermomeCfg.Click += new System.EventHandler(this.btnThermomeCfg_Click);
            // 
            // btnImageCfg
            // 
            this.btnImageCfg.Location = new System.Drawing.Point(110, 41);
            this.btnImageCfg.Name = "btnImageCfg";
            this.btnImageCfg.Size = new System.Drawing.Size(75, 23);
            this.btnImageCfg.TabIndex = 12;
            this.btnImageCfg.Text = "图像参数";
            this.btnImageCfg.UseVisualStyleBackColor = true;
            this.btnImageCfg.Click += new System.EventHandler(this.btnImageCfg_Click);
            // 
            // buttonVideoCfg
            // 
            this.buttonVideoCfg.Location = new System.Drawing.Point(17, 41);
            this.buttonVideoCfg.Name = "buttonVideoCfg";
            this.buttonVideoCfg.Size = new System.Drawing.Size(75, 23);
            this.buttonVideoCfg.TabIndex = 11;
            this.buttonVideoCfg.Text = "视频参数";
            this.buttonVideoCfg.UseVisualStyleBackColor = true;
            this.buttonVideoCfg.Click += new System.EventHandler(this.buttonVideoCfg_Click);
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "Index";
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "Time";
            this.columnHeader8.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader8.Width = 130;
            // 
            // columnHeader9
            // 
            this.columnHeader9.Text = "Level";
            this.columnHeader9.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader9.Width = 80;
            // 
            // columnHeader10
            // 
            this.columnHeader10.Text = "Info";
            this.columnHeader10.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader10.Width = 600;
            // 
            // listViewInfo
            // 
            this.listViewInfo.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader7,
            this.columnHeader8,
            this.columnHeader9,
            this.columnHeader10});
            this.listViewInfo.FullRowSelect = true;
            this.listViewInfo.GridLines = true;
            this.listViewInfo.Location = new System.Drawing.Point(2, 20);
            this.listViewInfo.Name = "listViewInfo";
            this.listViewInfo.Size = new System.Drawing.Size(750, 235);
            this.listViewInfo.TabIndex = 0;
            this.listViewInfo.UseCompatibleStateImageBehavior = false;
            this.listViewInfo.View = System.Windows.Forms.View.Details;
            // 
            // ThermalDemo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(765, 729);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.PreviewPanel);
            this.Controls.Add(this.groupBoxDeviceInfo);
            this.Controls.Add(this.groupBoxVerInfo);
            this.Controls.Add(this.groupBoxLogin);
            this.Controls.Add(this.groupBoxInfo);
            this.Name = "ThermalDemo";
            this.Text = "ThermalDemo";
            this.Load += new System.EventHandler(this.ThermalDemo_Load);
            this.groupBoxInfo.ResumeLayout(false);
            this.groupBoxVerInfo.ResumeLayout(false);
            this.groupBoxVerInfo.PerformLayout();
            this.groupBoxLogin.ResumeLayout(false);
            this.groupBoxDeviceInfo.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxInfo;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBoxVerInfo;
        private System.Windows.Forms.GroupBox groupBoxLogin;
        private System.Windows.Forms.Button btnLogout;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.Button btnEnum;
        private System.Windows.Forms.ListView listViewDeviceInfo;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.GroupBox groupBoxDeviceInfo;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.Panel PreviewPanel;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.ColumnHeader columnHeader11;
        private System.Windows.Forms.ColumnHeader columnHeader12;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonVideoCfg;
        private System.Windows.Forms.Button btnThermomeCfg;
        private System.Windows.Forms.Button btnImageCfg;
        private System.Windows.Forms.Button buttonAppendData;
        private System.Windows.Forms.Button buttonReboot;
        private System.Windows.Forms.ListView listViewInfo;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.ColumnHeader columnHeader10;
    }
}

