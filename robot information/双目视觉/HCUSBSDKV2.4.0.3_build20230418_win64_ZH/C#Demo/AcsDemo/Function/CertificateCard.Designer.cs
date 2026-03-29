namespace AcsDemo_USB
{
    partial class CertificateCard
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
            this.listViewCertificateCard = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.groupBoxPicture = new System.Windows.Forms.GroupBox();
            this.pictureBoxCertificate = new System.Windows.Forms.PictureBox();
            this.btnAcquire = new System.Windows.Forms.Button();
            this.groupBoxPicture.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxCertificate)).BeginInit();
            this.SuspendLayout();
            // 
            // listViewCertificateCard
            // 
            this.listViewCertificateCard.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader4});
            this.listViewCertificateCard.GridLines = true;
            this.listViewCertificateCard.Location = new System.Drawing.Point(2, 24);
            this.listViewCertificateCard.Name = "listViewCertificateCard";
            this.listViewCertificateCard.Size = new System.Drawing.Size(368, 194);
            this.listViewCertificateCard.TabIndex = 0;
            this.listViewCertificateCard.UseCompatibleStateImageBehavior = false;
            this.listViewCertificateCard.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "No.";
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Item Name";
            this.columnHeader2.Width = 100;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Info";
            this.columnHeader4.Width = 382;
            // 
            // groupBoxPicture
            // 
            this.groupBoxPicture.Controls.Add(this.pictureBoxCertificate);
            this.groupBoxPicture.Location = new System.Drawing.Point(389, 24);
            this.groupBoxPicture.Name = "groupBoxPicture";
            this.groupBoxPicture.Size = new System.Drawing.Size(124, 160);
            this.groupBoxPicture.TabIndex = 1;
            this.groupBoxPicture.TabStop = false;
            this.groupBoxPicture.Text = "图片";
            // 
            // pictureBoxCertificate
            // 
            this.pictureBoxCertificate.Location = new System.Drawing.Point(6, 20);
            this.pictureBoxCertificate.Name = "pictureBoxCertificate";
            this.pictureBoxCertificate.Size = new System.Drawing.Size(116, 140);
            this.pictureBoxCertificate.TabIndex = 0;
            this.pictureBoxCertificate.TabStop = false;
            // 
            // btnAcquire
            // 
            this.btnAcquire.Location = new System.Drawing.Point(406, 204);
            this.btnAcquire.Name = "btnAcquire";
            this.btnAcquire.Size = new System.Drawing.Size(75, 23);
            this.btnAcquire.TabIndex = 2;
            this.btnAcquire.Text = "获取";
            this.btnAcquire.UseVisualStyleBackColor = true;
            this.btnAcquire.Click += new System.EventHandler(this.btnAcquire_Click);
            // 
            // CertificateCard
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(516, 231);
            this.Controls.Add(this.btnAcquire);
            this.Controls.Add(this.groupBoxPicture);
            this.Controls.Add(this.listViewCertificateCard);
            this.Name = "CertificateCard";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "获取身份证信息";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.CertificateCard_FormClosed);
            this.Load += new System.EventHandler(this.CertificateCard_Load);
            this.groupBoxPicture.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxCertificate)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.GroupBox groupBoxPicture;
        private System.Windows.Forms.Button btnAcquire;
        public System.Windows.Forms.ListView listViewCertificateCard;
        public System.Windows.Forms.PictureBox pictureBoxCertificate;
    }
}