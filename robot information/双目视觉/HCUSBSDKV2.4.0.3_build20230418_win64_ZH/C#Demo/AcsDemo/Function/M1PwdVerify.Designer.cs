namespace AcsDemo_USB
{
    partial class M1PwdVerify
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
            this.M1PwdType = new System.Windows.Forms.Label();
            this.M1SCBNoToVerify = new System.Windows.Forms.Label();
            this.M1Pwd = new System.Windows.Forms.Label();
            this.btnVerify = new System.Windows.Forms.Button();
            this.combM1PwdType = new System.Windows.Forms.ComboBox();
            this.txtBSCBNoToVerify = new System.Windows.Forms.TextBox();
            this.txtBM1Pwd = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // M1PwdType
            // 
            this.M1PwdType.Location = new System.Drawing.Point(26, 37);
            this.M1PwdType.Name = "M1PwdType";
            this.M1PwdType.Size = new System.Drawing.Size(179, 18);
            this.M1PwdType.TabIndex = 0;
            this.M1PwdType.Text = "密码类型:";
            this.M1PwdType.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // M1SCBNoToVerify
            // 
            this.M1SCBNoToVerify.Location = new System.Drawing.Point(26, 73);
            this.M1SCBNoToVerify.Name = "M1SCBNoToVerify";
            this.M1SCBNoToVerify.Size = new System.Drawing.Size(179, 12);
            this.M1SCBNoToVerify.TabIndex = 1;
            this.M1SCBNoToVerify.Text = "要验证密码的扇区号:";
            this.M1SCBNoToVerify.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // M1Pwd
            // 
            this.M1Pwd.Location = new System.Drawing.Point(24, 116);
            this.M1Pwd.Name = "M1Pwd";
            this.M1Pwd.Size = new System.Drawing.Size(181, 36);
            this.M1Pwd.TabIndex = 2;
            this.M1Pwd.Text = "6Byte密码(16进制以空格分割):";
            this.M1Pwd.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // btnVerify
            // 
            this.btnVerify.Location = new System.Drawing.Point(173, 169);
            this.btnVerify.Name = "btnVerify";
            this.btnVerify.Size = new System.Drawing.Size(89, 30);
            this.btnVerify.TabIndex = 3;
            this.btnVerify.Text = "验证";
            this.btnVerify.UseVisualStyleBackColor = true;
            this.btnVerify.Click += new System.EventHandler(this.btnVerify_Click);
            // 
            // combM1PwdType
            // 
            this.combM1PwdType.FormattingEnabled = true;
            this.combM1PwdType.Items.AddRange(new object[] {
            "0-KeyA",
            "1-KeyB"});
            this.combM1PwdType.Location = new System.Drawing.Point(211, 35);
            this.combM1PwdType.Name = "combM1PwdType";
            this.combM1PwdType.Size = new System.Drawing.Size(172, 20);
            this.combM1PwdType.TabIndex = 4;
            // 
            // txtBSCBNoToVerify
            // 
            this.txtBSCBNoToVerify.Location = new System.Drawing.Point(211, 69);
            this.txtBSCBNoToVerify.MaxLength = 1;
            this.txtBSCBNoToVerify.Name = "txtBSCBNoToVerify";
            this.txtBSCBNoToVerify.Size = new System.Drawing.Size(172, 21);
            this.txtBSCBNoToVerify.TabIndex = 5;
            // 
            // txtBM1Pwd
            // 
            this.txtBM1Pwd.Location = new System.Drawing.Point(211, 116);
            this.txtBM1Pwd.MaxLength = 17;
            this.txtBM1Pwd.Name = "txtBM1Pwd";
            this.txtBM1Pwd.Size = new System.Drawing.Size(172, 21);
            this.txtBM1Pwd.TabIndex = 6;
            // 
            // M1PwdVerify
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(435, 221);
            this.Controls.Add(this.txtBM1Pwd);
            this.Controls.Add(this.txtBSCBNoToVerify);
            this.Controls.Add(this.combM1PwdType);
            this.Controls.Add(this.btnVerify);
            this.Controls.Add(this.M1Pwd);
            this.Controls.Add(this.M1SCBNoToVerify);
            this.Controls.Add(this.M1PwdType);
            this.Name = "M1PwdVerify";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "M1PwdVerify";
            this.Load += new System.EventHandler(this.M1PwdVerify_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label M1PwdType;
        private System.Windows.Forms.Label M1SCBNoToVerify;
        private System.Windows.Forms.Label M1Pwd;
        private System.Windows.Forms.Button btnVerify;
        private System.Windows.Forms.ComboBox combM1PwdType;
        private System.Windows.Forms.TextBox txtBSCBNoToVerify;
        private System.Windows.Forms.TextBox txtBM1Pwd;
    }
}