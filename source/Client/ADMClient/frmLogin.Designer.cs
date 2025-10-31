namespace ADMINClient
{
    partial class frmLogin
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
            this.lblTitle = new System.Windows.Forms.Label();
            this.pnlMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlMain
            // 
            this.pnlMain.Controls.Add(this.lblTitle);
            this.pnlMain.Controls.SetChildIndex(this.btnOption, 0);
            this.pnlMain.Controls.SetChildIndex(this.btnOK, 0);
            this.pnlMain.Controls.SetChildIndex(this.btnExit, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblFactory, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblUserID, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblPassword, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtFactory, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtUserID, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtPassword, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblVersion, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblSiteID, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtSiteID, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblTitle, 0);
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.BackColor = System.Drawing.Color.Transparent;
            this.lblTitle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(10, 195);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(168, 16);
            this.lblTitle.TabIndex = 8;
            this.lblTitle.Text = "MESplus Administrator ";
            // 
            // frmLogin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(456, 344);
            this.Name = "frmLogin";
            this.Text = "Administrator - Login";
            this.Load += new System.EventHandler(this.frmLogin_Load);
            this.pnlMain.ResumeLayout(false);
            this.pnlMain.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
    }
}