namespace AcsDemo_USB
{
    partial class AcsDemo_USB
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
            this.groupBoxLogin = new System.Windows.Forms.GroupBox();
            this.comboBoxLanguage = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.textBoxPassWord = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxUserName = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBoxDeviceInfo = new System.Windows.Forms.GroupBox();
            this.btnLogOutDevice = new System.Windows.Forms.Button();
            this.btnLoginDevice = new System.Windows.Forms.Button();
            this.btnTraverse = new System.Windows.Forms.Button();
            this.listViewDeviceInfo = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.listView1 = new System.Windows.Forms.ListView();
            this.groupBoxInfo = new System.Windows.Forms.GroupBox();
            this.listViewInfo = new System.Windows.Forms.ListView();
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader10 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.btnCertificateConfig = new System.Windows.Forms.Button();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.btnGetCardNo = new System.Windows.Forms.Button();
            this.btnM1ModifySCB = new System.Windows.Forms.Button();
            this.btnM1PwdVerify = new System.Windows.Forms.Button();
            this.btnActivateCard = new System.Windows.Forms.Button();
            this.tabControCertificate_cardInterface = new System.Windows.Forms.TabControl();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBoxVerInfo = new System.Windows.Forms.GroupBox();
            this.groupBoxLogin.SuspendLayout();
            this.groupBoxDeviceInfo.SuspendLayout();
            this.groupBoxInfo.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabControCertificate_cardInterface.SuspendLayout();
            this.groupBoxVerInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxLogin
            // 
            this.groupBoxLogin.Controls.Add(this.comboBoxLanguage);
            this.groupBoxLogin.Controls.Add(this.label7);
            this.groupBoxLogin.Controls.Add(this.textBoxPassWord);
            this.groupBoxLogin.Controls.Add(this.label6);
            this.groupBoxLogin.Controls.Add(this.textBoxUserName);
            this.groupBoxLogin.Controls.Add(this.label5);
            this.groupBoxLogin.Location = new System.Drawing.Point(327, 12);
            this.groupBoxLogin.Name = "groupBoxLogin";
            this.groupBoxLogin.Size = new System.Drawing.Size(439, 83);
            this.groupBoxLogin.TabIndex = 1;
            this.groupBoxLogin.TabStop = false;
            this.groupBoxLogin.Text = "登录信息";
            // 
            // comboBoxLanguage
            // 
            this.comboBoxLanguage.FormattingEnabled = true;
            this.comboBoxLanguage.Items.AddRange(new object[] {
            "English",
            "Chinese"});
            this.comboBoxLanguage.Location = new System.Drawing.Point(79, 57);
            this.comboBoxLanguage.Name = "comboBoxLanguage";
            this.comboBoxLanguage.Size = new System.Drawing.Size(100, 20);
            this.comboBoxLanguage.TabIndex = 6;
            this.comboBoxLanguage.Text = "Chinese";
            this.comboBoxLanguage.SelectedIndexChanged += new System.EventHandler(this.comboBoxLanguage_SelectedIndexChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 58);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 5;
            this.label7.Text = "Language";
            // 
            // textBoxPassWord
            // 
            this.textBoxPassWord.Location = new System.Drawing.Point(292, 25);
            this.textBoxPassWord.Name = "textBoxPassWord";
            this.textBoxPassWord.Size = new System.Drawing.Size(100, 21);
            this.textBoxPassWord.TabIndex = 3;
            this.textBoxPassWord.Text = "12345";
            this.textBoxPassWord.UseSystemPasswordChar = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(232, 28);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(29, 12);
            this.label6.TabIndex = 2;
            this.label6.Text = "密码";
            // 
            // textBoxUserName
            // 
            this.textBoxUserName.Location = new System.Drawing.Point(79, 25);
            this.textBoxUserName.Name = "textBoxUserName";
            this.textBoxUserName.Size = new System.Drawing.Size(100, 21);
            this.textBoxUserName.TabIndex = 1;
            this.textBoxUserName.Text = "admin";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 28);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(41, 12);
            this.label5.TabIndex = 0;
            this.label5.Text = "用户名";
            // 
            // groupBoxDeviceInfo
            // 
            this.groupBoxDeviceInfo.Controls.Add(this.btnLogOutDevice);
            this.groupBoxDeviceInfo.Controls.Add(this.btnLoginDevice);
            this.groupBoxDeviceInfo.Controls.Add(this.btnTraverse);
            this.groupBoxDeviceInfo.Controls.Add(this.listViewDeviceInfo);
            this.groupBoxDeviceInfo.Controls.Add(this.listView1);
            this.groupBoxDeviceInfo.Location = new System.Drawing.Point(12, 101);
            this.groupBoxDeviceInfo.Name = "groupBoxDeviceInfo";
            this.groupBoxDeviceInfo.Size = new System.Drawing.Size(754, 152);
            this.groupBoxDeviceInfo.TabIndex = 2;
            this.groupBoxDeviceInfo.TabStop = false;
            this.groupBoxDeviceInfo.Text = "设备信息";
            // 
            // btnLogOutDevice
            // 
            this.btnLogOutDevice.Location = new System.Drawing.Point(620, 78);
            this.btnLogOutDevice.Name = "btnLogOutDevice";
            this.btnLogOutDevice.Size = new System.Drawing.Size(75, 23);
            this.btnLogOutDevice.TabIndex = 4;
            this.btnLogOutDevice.Text = "注销设备";
            this.btnLogOutDevice.UseVisualStyleBackColor = true;
            this.btnLogOutDevice.Click += new System.EventHandler(this.btnLogOutDevice_Click);
            // 
            // btnLoginDevice
            // 
            this.btnLoginDevice.Location = new System.Drawing.Point(620, 49);
            this.btnLoginDevice.Name = "btnLoginDevice";
            this.btnLoginDevice.Size = new System.Drawing.Size(75, 23);
            this.btnLoginDevice.TabIndex = 3;
            this.btnLoginDevice.Text = "登录设备";
            this.btnLoginDevice.UseVisualStyleBackColor = true;
            this.btnLoginDevice.Click += new System.EventHandler(this.btnLoginDevice_Click);
            // 
            // btnTraverse
            // 
            this.btnTraverse.Location = new System.Drawing.Point(620, 20);
            this.btnTraverse.Name = "btnTraverse";
            this.btnTraverse.Size = new System.Drawing.Size(75, 23);
            this.btnTraverse.TabIndex = 2;
            this.btnTraverse.Text = "遍历设备";
            this.btnTraverse.UseVisualStyleBackColor = true;
            this.btnTraverse.Click += new System.EventHandler(this.btnTraverse_Click);
            // 
            // listViewDeviceInfo
            // 
            this.listViewDeviceInfo.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6});
            this.listViewDeviceInfo.FullRowSelect = true;
            this.listViewDeviceInfo.GridLines = true;
            this.listViewDeviceInfo.Location = new System.Drawing.Point(10, 20);
            this.listViewDeviceInfo.MultiSelect = false;
            this.listViewDeviceInfo.Name = "listViewDeviceInfo";
            this.listViewDeviceInfo.Size = new System.Drawing.Size(566, 126);
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
            this.columnHeader4.Text = "Manufacturer";
            this.columnHeader4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader4.Width = 120;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Device Name";
            this.columnHeader5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader5.Width = 140;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Device Serial Number";
            this.columnHeader6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.columnHeader6.Width = 140;
            // 
            // listView1
            // 
            this.listView1.Location = new System.Drawing.Point(10, 20);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(566, 97);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // groupBoxInfo
            // 
            this.groupBoxInfo.Controls.Add(this.listViewInfo);
            this.groupBoxInfo.Location = new System.Drawing.Point(12, 377);
            this.groupBoxInfo.Name = "groupBoxInfo";
            this.groupBoxInfo.Size = new System.Drawing.Size(750, 255);
            this.groupBoxInfo.TabIndex = 4;
            this.groupBoxInfo.TabStop = false;
            this.groupBoxInfo.Text = "信息";
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
            this.listViewInfo.Location = new System.Drawing.Point(0, 20);
            this.listViewInfo.Name = "listViewInfo";
            this.listViewInfo.Size = new System.Drawing.Size(750, 235);
            this.listViewInfo.TabIndex = 0;
            this.listViewInfo.UseCompatibleStateImageBehavior = false;
            this.listViewInfo.View = System.Windows.Forms.View.Details;
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
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.btnCertificateConfig);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(746, 75);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "身份证信息接口";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // btnCertificateConfig
            // 
            this.btnCertificateConfig.Location = new System.Drawing.Point(6, 18);
            this.btnCertificateConfig.Name = "btnCertificateConfig";
            this.btnCertificateConfig.Size = new System.Drawing.Size(135, 23);
            this.btnCertificateConfig.TabIndex = 0;
            this.btnCertificateConfig.Text = "身份证信息配置";
            this.btnCertificateConfig.UseVisualStyleBackColor = true;
            this.btnCertificateConfig.Click += new System.EventHandler(this.btnCertificateConfig_Click);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.btnGetCardNo);
            this.tabPage1.Controls.Add(this.btnM1ModifySCB);
            this.tabPage1.Controls.Add(this.btnM1PwdVerify);
            this.tabPage1.Controls.Add(this.btnActivateCard);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(746, 75);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "设备接口";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // btnGetCardNo
            // 
            this.btnGetCardNo.Location = new System.Drawing.Point(350, 20);
            this.btnGetCardNo.Name = "btnGetCardNo";
            this.btnGetCardNo.Size = new System.Drawing.Size(85, 23);
            this.btnGetCardNo.TabIndex = 3;
            this.btnGetCardNo.Text = "获取卡号";
            this.btnGetCardNo.UseVisualStyleBackColor = true;
            this.btnGetCardNo.Click += new System.EventHandler(this.btnGetCardNo_Click);
            // 
            // btnM1ModifySCB
            // 
            this.btnM1ModifySCB.Location = new System.Drawing.Point(224, 20);
            this.btnM1ModifySCB.Name = "btnM1ModifySCB";
            this.btnM1ModifySCB.Size = new System.Drawing.Size(105, 23);
            this.btnM1ModifySCB.TabIndex = 2;
            this.btnM1ModifySCB.Text = "指定扇区控制块修改";
            this.btnM1ModifySCB.UseVisualStyleBackColor = true;
            this.btnM1ModifySCB.Click += new System.EventHandler(this.btnM1ModifySCB_Click);
            // 
            // btnM1PwdVerify
            // 
            this.btnM1PwdVerify.Location = new System.Drawing.Point(105, 20);
            this.btnM1PwdVerify.Name = "btnM1PwdVerify";
            this.btnM1PwdVerify.Size = new System.Drawing.Size(105, 23);
            this.btnM1PwdVerify.TabIndex = 1;
            this.btnM1PwdVerify.Text = "扇区带密码验证";
            this.btnM1PwdVerify.UseVisualStyleBackColor = true;
            this.btnM1PwdVerify.Click += new System.EventHandler(this.btnM1PwdVerify_Click);
            // 
            // btnActivateCard
            // 
            this.btnActivateCard.Location = new System.Drawing.Point(4, 20);
            this.btnActivateCard.Name = "btnActivateCard";
            this.btnActivateCard.Size = new System.Drawing.Size(95, 23);
            this.btnActivateCard.TabIndex = 0;
            this.btnActivateCard.Text = "激活卡";
            this.btnActivateCard.UseVisualStyleBackColor = true;
            this.btnActivateCard.Click += new System.EventHandler(this.btnActivateCard_Click);
            // 
            // tabControCertificate_cardInterface
            // 
            this.tabControCertificate_cardInterface.Controls.Add(this.tabPage1);
            this.tabControCertificate_cardInterface.Controls.Add(this.tabPage2);
            this.tabControCertificate_cardInterface.Location = new System.Drawing.Point(12, 274);
            this.tabControCertificate_cardInterface.Name = "tabControCertificate_cardInterface";
            this.tabControCertificate_cardInterface.SelectedIndex = 0;
            this.tabControCertificate_cardInterface.Size = new System.Drawing.Size(754, 101);
            this.tabControCertificate_cardInterface.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "Build";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(68, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "20181017";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 58);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "SDK版本:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(131, 58);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 12);
            this.label4.TabIndex = 3;
            // 
            // groupBoxVerInfo
            // 
            this.groupBoxVerInfo.Controls.Add(this.label4);
            this.groupBoxVerInfo.Controls.Add(this.label3);
            this.groupBoxVerInfo.Controls.Add(this.label2);
            this.groupBoxVerInfo.Controls.Add(this.label1);
            this.groupBoxVerInfo.Location = new System.Drawing.Point(12, 12);
            this.groupBoxVerInfo.Name = "groupBoxVerInfo";
            this.groupBoxVerInfo.Size = new System.Drawing.Size(754, 83);
            this.groupBoxVerInfo.TabIndex = 0;
            this.groupBoxVerInfo.TabStop = false;
            this.groupBoxVerInfo.Text = "版本信息";
            // 
            // AcsDemo_USB
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(778, 634);
            this.Controls.Add(this.groupBoxInfo);
            this.Controls.Add(this.tabControCertificate_cardInterface);
            this.Controls.Add(this.groupBoxDeviceInfo);
            this.Controls.Add(this.groupBoxLogin);
            this.Controls.Add(this.groupBoxVerInfo);
            this.Name = "AcsDemo_USB";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AcsDemo_USB";
            this.groupBoxLogin.ResumeLayout(false);
            this.groupBoxLogin.PerformLayout();
            this.groupBoxDeviceInfo.ResumeLayout(false);
            this.groupBoxInfo.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabControCertificate_cardInterface.ResumeLayout(false);
            this.groupBoxVerInfo.ResumeLayout(false);
            this.groupBoxVerInfo.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxLogin;
        private System.Windows.Forms.TextBox textBoxPassWord;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBoxUserName;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBoxDeviceInfo;
        private System.Windows.Forms.ListView listViewDeviceInfo;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.Button btnLogOutDevice;
        private System.Windows.Forms.Button btnLoginDevice;
        private System.Windows.Forms.Button btnTraverse;
        private System.Windows.Forms.GroupBox groupBoxInfo;
        private System.Windows.Forms.ListView listViewInfo;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.ColumnHeader columnHeader10;
        private System.Windows.Forms.ComboBox comboBoxLanguage;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Button btnCertificateConfig;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button btnGetCardNo;
        private System.Windows.Forms.Button btnM1ModifySCB;
        private System.Windows.Forms.Button btnM1PwdVerify;
        private System.Windows.Forms.Button btnActivateCard;
        private System.Windows.Forms.TabControl tabControCertificate_cardInterface;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBoxVerInfo;

    }
}

