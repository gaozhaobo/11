namespace AcsDemo_USB
{
    partial class M1ModifySCB
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.txtBSCBNo = new System.Windows.Forms.TextBox();
            this.txtBPwdA = new System.Windows.Forms.TextBox();
            this.txtBCtlBlock = new System.Windows.Forms.TextBox();
            this.txtBPwdB = new System.Windows.Forms.TextBox();
            this.btnModify = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(104, 52);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(152, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "扇区号[0-15]:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(7, 93);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(249, 21);
            this.label2.TabIndex = 1;
            this.label2.Text = "6Byte密码A(16进制以空格分割):";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(3, 131);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(253, 38);
            this.label3.TabIndex = 2;
            this.label3.Text = "4Byte控制位(16进制以空格分割):";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(3, 172);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(253, 21);
            this.label4.TabIndex = 3;
            this.label4.Text = "6Byte密码B(16进制以空格分割):";
            this.label4.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // txtBSCBNo
            // 
            this.txtBSCBNo.Location = new System.Drawing.Point(252, 48);
            this.txtBSCBNo.MaxLength = 1;
            this.txtBSCBNo.Name = "txtBSCBNo";
            this.txtBSCBNo.Size = new System.Drawing.Size(195, 21);
            this.txtBSCBNo.TabIndex = 4;
            // 
            // txtBPwdA
            // 
            this.txtBPwdA.Location = new System.Drawing.Point(252, 93);
            this.txtBPwdA.MaxLength = 17;
            this.txtBPwdA.Name = "txtBPwdA";
            this.txtBPwdA.Size = new System.Drawing.Size(195, 21);
            this.txtBPwdA.TabIndex = 5;
            // 
            // txtBCtlBlock
            // 
            this.txtBCtlBlock.Location = new System.Drawing.Point(252, 131);
            this.txtBCtlBlock.MaxLength = 11;
            this.txtBCtlBlock.Name = "txtBCtlBlock";
            this.txtBCtlBlock.Size = new System.Drawing.Size(195, 21);
            this.txtBCtlBlock.TabIndex = 6;
            // 
            // txtBPwdB
            // 
            this.txtBPwdB.Location = new System.Drawing.Point(252, 172);
            this.txtBPwdB.MaxLength = 17;
            this.txtBPwdB.Name = "txtBPwdB";
            this.txtBPwdB.Size = new System.Drawing.Size(195, 21);
            this.txtBPwdB.TabIndex = 7;
            // 
            // btnModify
            // 
            this.btnModify.Location = new System.Drawing.Point(197, 212);
            this.btnModify.Name = "btnModify";
            this.btnModify.Size = new System.Drawing.Size(75, 23);
            this.btnModify.TabIndex = 8;
            this.btnModify.Text = "修改";
            this.btnModify.UseVisualStyleBackColor = true;
            this.btnModify.Click += new System.EventHandler(this.btnModify_Click);
            // 
            // M1ModifySCB
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(487, 259);
            this.Controls.Add(this.btnModify);
            this.Controls.Add(this.txtBPwdB);
            this.Controls.Add(this.txtBCtlBlock);
            this.Controls.Add(this.txtBPwdA);
            this.Controls.Add(this.txtBSCBNo);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "M1ModifySCB";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "M1ModifySCB";
            this.Load += new System.EventHandler(this.M1ModifySCB_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtBSCBNo;
        private System.Windows.Forms.TextBox txtBPwdA;
        private System.Windows.Forms.TextBox txtBCtlBlock;
        private System.Windows.Forms.TextBox txtBPwdB;
        private System.Windows.Forms.Button btnModify;
    }
}