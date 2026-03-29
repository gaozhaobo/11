namespace ThermalDemo
{
    partial class ImageCfg
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.buttonGet = new System.Windows.Forms.Button();
            this.buttonSet = new System.Windows.Forms.Button();
            this.txtBrightness = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnget = new System.Windows.Forms.Button();
            this.btnset = new System.Windows.Forms.Button();
            this.textBoxContrast = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonGet);
            this.groupBox1.Controls.Add(this.buttonSet);
            this.groupBox1.Controls.Add(this.txtBrightness);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(165, 114);
            this.groupBox1.TabIndex = 12;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "图像亮度参数";
            // 
            // buttonGet
            // 
            this.buttonGet.Location = new System.Drawing.Point(10, 78);
            this.buttonGet.Name = "buttonGet";
            this.buttonGet.Size = new System.Drawing.Size(51, 23);
            this.buttonGet.TabIndex = 14;
            this.buttonGet.Text = "获取";
            this.buttonGet.UseVisualStyleBackColor = true;
            this.buttonGet.Click += new System.EventHandler(this.buttonGet_Click);
            // 
            // buttonSet
            // 
            this.buttonSet.Location = new System.Drawing.Point(88, 78);
            this.buttonSet.Name = "buttonSet";
            this.buttonSet.Size = new System.Drawing.Size(51, 23);
            this.buttonSet.TabIndex = 13;
            this.buttonSet.Text = "设置";
            this.buttonSet.UseVisualStyleBackColor = true;
            this.buttonSet.Click += new System.EventHandler(this.buttonSet_Click);
            // 
            // txtBrightness
            // 
            this.txtBrightness.Location = new System.Drawing.Point(73, 30);
            this.txtBrightness.MaxLength = 100;
            this.txtBrightness.Name = "txtBrightness";
            this.txtBrightness.Size = new System.Drawing.Size(66, 21);
            this.txtBrightness.TabIndex = 26;
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(9, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(70, 15);
            this.label1.TabIndex = 5;
            this.label1.Text = "图像亮度:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnget);
            this.groupBox2.Controls.Add(this.btnset);
            this.groupBox2.Controls.Add(this.textBoxContrast);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Location = new System.Drawing.Point(196, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(165, 114);
            this.groupBox2.TabIndex = 15;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "图像对比度参数";
            // 
            // btnget
            // 
            this.btnget.Location = new System.Drawing.Point(10, 78);
            this.btnget.Name = "btnget";
            this.btnget.Size = new System.Drawing.Size(51, 23);
            this.btnget.TabIndex = 14;
            this.btnget.Text = "获取";
            this.btnget.UseVisualStyleBackColor = true;
            this.btnget.Click += new System.EventHandler(this.btnget_Click);
            // 
            // btnset
            // 
            this.btnset.Location = new System.Drawing.Point(92, 78);
            this.btnset.Name = "btnset";
            this.btnset.Size = new System.Drawing.Size(51, 23);
            this.btnset.TabIndex = 13;
            this.btnset.Text = "设置";
            this.btnset.UseVisualStyleBackColor = true;
            this.btnset.Click += new System.EventHandler(this.btnset_Click);
            // 
            // textBoxContrast
            // 
            this.textBoxContrast.Location = new System.Drawing.Point(88, 29);
            this.textBoxContrast.MaxLength = 100;
            this.textBoxContrast.Name = "textBoxContrast";
            this.textBoxContrast.Size = new System.Drawing.Size(66, 21);
            this.textBoxContrast.TabIndex = 26;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(6, 35);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(81, 15);
            this.label2.TabIndex = 5;
            this.label2.Text = "图像对比度:";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // ImageCfg
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(426, 162);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "ImageCfg";
            this.Text = "ImageCfg";
            this.Load += new System.EventHandler(this.ImageCfg_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonGet;
        private System.Windows.Forms.Button buttonSet;
        private System.Windows.Forms.TextBox txtBrightness;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnget;
        private System.Windows.Forms.Button btnset;
        private System.Windows.Forms.TextBox textBoxContrast;
        private System.Windows.Forms.Label label2;
    }
}