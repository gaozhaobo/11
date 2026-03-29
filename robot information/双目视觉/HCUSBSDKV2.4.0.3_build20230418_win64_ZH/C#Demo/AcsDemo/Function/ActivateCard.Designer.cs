namespace AcsDemo_USB
{
    partial class ActivateCard
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
            this.labWaitSecond = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnActivate = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.textBoxCardProtocol = new System.Windows.Forms.TextBox();
            this.textBoxSerialLength = new System.Windows.Forms.TextBox();
            this.textBoxSerialNumber = new System.Windows.Forms.TextBox();
            this.textBoxSelected_Verify_Length = new System.Windows.Forms.TextBox();
            this.textBoxSelect_Verify = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "操作等待时间";
            // 
            // labWaitSecond
            // 
            this.labWaitSecond.AutoSize = true;
            this.labWaitSecond.Location = new System.Drawing.Point(110, 13);
            this.labWaitSecond.Name = "labWaitSecond";
            this.labWaitSecond.Size = new System.Drawing.Size(11, 12);
            this.labWaitSecond.TabIndex = 1;
            this.labWaitSecond.Text = "5";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(143, 13);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(17, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "秒";
            // 
            // btnActivate
            // 
            this.btnActivate.Location = new System.Drawing.Point(218, 8);
            this.btnActivate.Name = "btnActivate";
            this.btnActivate.Size = new System.Drawing.Size(75, 23);
            this.btnActivate.TabIndex = 3;
            this.btnActivate.Text = "激活";
            this.btnActivate.UseVisualStyleBackColor = true;
            this.btnActivate.Click += new System.EventHandler(this.btnActivate_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 52);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 12);
            this.label4.TabIndex = 4;
            this.label4.Text = "设备应答";
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(13, 81);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(118, 18);
            this.label5.TabIndex = 5;
            this.label5.Text = "卡协议类型";
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(13, 107);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(118, 18);
            this.label6.TabIndex = 6;
            this.label6.Text = "序列号长度";
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(13, 133);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(93, 18);
            this.label7.TabIndex = 7;
            this.label7.Text = "序列号";
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(13, 159);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(118, 18);
            this.label8.TabIndex = 8;
            this.label8.Text = "选择确认长度";
            // 
            // label9
            // 
            this.label9.Location = new System.Drawing.Point(13, 185);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(93, 18);
            this.label9.TabIndex = 9;
            this.label9.Text = "选择确认";
            // 
            // textBoxCardProtocol
            // 
            this.textBoxCardProtocol.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.textBoxCardProtocol.Location = new System.Drawing.Point(125, 78);
            this.textBoxCardProtocol.Name = "textBoxCardProtocol";
            this.textBoxCardProtocol.Size = new System.Drawing.Size(184, 21);
            this.textBoxCardProtocol.TabIndex = 10;
            // 
            // textBoxSerialLength
            // 
            this.textBoxSerialLength.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.textBoxSerialLength.Location = new System.Drawing.Point(125, 104);
            this.textBoxSerialLength.Name = "textBoxSerialLength";
            this.textBoxSerialLength.Size = new System.Drawing.Size(184, 21);
            this.textBoxSerialLength.TabIndex = 11;
            // 
            // textBoxSerialNumber
            // 
            this.textBoxSerialNumber.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.textBoxSerialNumber.Location = new System.Drawing.Point(125, 130);
            this.textBoxSerialNumber.Name = "textBoxSerialNumber";
            this.textBoxSerialNumber.Size = new System.Drawing.Size(184, 21);
            this.textBoxSerialNumber.TabIndex = 12;
            // 
            // textBoxSelected_Verify_Length
            // 
            this.textBoxSelected_Verify_Length.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.textBoxSelected_Verify_Length.Location = new System.Drawing.Point(125, 156);
            this.textBoxSelected_Verify_Length.Name = "textBoxSelected_Verify_Length";
            this.textBoxSelected_Verify_Length.Size = new System.Drawing.Size(184, 21);
            this.textBoxSelected_Verify_Length.TabIndex = 13;
            // 
            // textBoxSelect_Verify
            // 
            this.textBoxSelect_Verify.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.textBoxSelect_Verify.Location = new System.Drawing.Point(125, 182);
            this.textBoxSelect_Verify.Name = "textBoxSelect_Verify";
            this.textBoxSelect_Verify.Size = new System.Drawing.Size(184, 21);
            this.textBoxSelect_Verify.TabIndex = 14;
            // 
            // ActivateCard
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(504, 271);
            this.Controls.Add(this.textBoxSelect_Verify);
            this.Controls.Add(this.textBoxSelected_Verify_Length);
            this.Controls.Add(this.textBoxSerialNumber);
            this.Controls.Add(this.textBoxSerialLength);
            this.Controls.Add(this.textBoxCardProtocol);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btnActivate);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.labWaitSecond);
            this.Controls.Add(this.label1);
            this.Name = "ActivateCard";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "激活";
            this.Load += new System.EventHandler(this.ActivateCard_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labWaitSecond;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnActivate;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBoxCardProtocol;
        private System.Windows.Forms.TextBox textBoxSerialLength;
        private System.Windows.Forms.TextBox textBoxSerialNumber;
        private System.Windows.Forms.TextBox textBoxSelected_Verify_Length;
        private System.Windows.Forms.TextBox textBoxSelect_Verify;
    }
}