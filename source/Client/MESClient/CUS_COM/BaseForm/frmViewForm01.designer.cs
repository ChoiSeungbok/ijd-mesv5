namespace CUS_COM
{
    partial class frmViewForm01
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
            Infragistics.Win.Appearance appearance17 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance15 = new Infragistics.Win.Appearance();
            this.pnlStsCond = new System.Windows.Forms.Panel();
            this.pnlStsCond2 = new System.Windows.Forms.Panel();
            this.pnlStsCond3 = new System.Windows.Forms.Panel();
            this.pnlMID = new System.Windows.Forms.Panel();
            this.chkFavorite = new System.Windows.Forms.CheckBox();
            this.lblDirectQuery = new System.Windows.Forms.Label();
            this.lblFormName = new System.Windows.Forms.Label();
            this.btnView = new Infragistics.Win.Misc.UltraButton();
            this.btnClose = new Infragistics.Win.Misc.UltraButton();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(232)))), ((int)(((byte)(244)))));
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Location = new System.Drawing.Point(0, 790);
            this.pnlBottom.Size = new System.Drawing.Size(1239, 50);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.pnlMID);
            this.pnlCenter.Size = new System.Drawing.Size(1239, 790);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "TranForm02";
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.BackColor = System.Drawing.Color.White;
            this.pnlStsCond.Controls.Add(this.pnlStsCond2);
            this.pnlStsCond.Controls.Add(this.pnlStsCond3);
            this.pnlStsCond.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlStsCond.Location = new System.Drawing.Point(10, 50);
            this.pnlStsCond.Name = "pnlStsCond";
            this.pnlStsCond.Size = new System.Drawing.Size(1219, 70);
            this.pnlStsCond.TabIndex = 35;
            // 
            // pnlStsCond2
            // 
            this.pnlStsCond2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            this.pnlStsCond2.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlStsCond2.Location = new System.Drawing.Point(0, 0);
            this.pnlStsCond2.Name = "pnlStsCond2";
            this.pnlStsCond2.Size = new System.Drawing.Size(1219, 10);
            this.pnlStsCond2.TabIndex = 161;
            // 
            // pnlStsCond3
            // 
            this.pnlStsCond3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(232)))), ((int)(((byte)(244)))));
            this.pnlStsCond3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlStsCond3.Location = new System.Drawing.Point(0, 60);
            this.pnlStsCond3.Name = "pnlStsCond3";
            this.pnlStsCond3.Size = new System.Drawing.Size(1219, 10);
            this.pnlStsCond3.TabIndex = 41;
            // 
            // pnlMID
            // 
            this.pnlMID.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(232)))), ((int)(((byte)(244)))));
            this.pnlMID.Controls.Add(this.chkFavorite);
            this.pnlMID.Controls.Add(this.lblDirectQuery);
            this.pnlMID.Controls.Add(this.pnlStsCond);
            this.pnlMID.Controls.Add(this.lblFormName);
            this.pnlMID.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMID.Location = new System.Drawing.Point(0, 0);
            this.pnlMID.Name = "pnlMID";
            this.pnlMID.Padding = new System.Windows.Forms.Padding(10, 50, 10, 0);
            this.pnlMID.Size = new System.Drawing.Size(1239, 790);
            this.pnlMID.TabIndex = 6;
            // 
            // chkFavorite
            // 
            this.chkFavorite.AutoSize = true;
            this.chkFavorite.Checked = true;
            this.chkFavorite.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkFavorite.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkFavorite.Location = new System.Drawing.Point(10, 3);
            this.chkFavorite.Name = "chkFavorite";
            this.chkFavorite.Size = new System.Drawing.Size(142, 16);
            this.chkFavorite.TabIndex = 298;
            this.chkFavorite.Text = "¡Ò∞‹√£±‚ √ﬂ∞° (Favorite Add)";
            this.chkFavorite.UseVisualStyleBackColor = true;
            // 
            // lblDirectQuery
            // 
            this.lblDirectQuery.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblDirectQuery.AutoSize = true;
            this.lblDirectQuery.Location = new System.Drawing.Point(1184, 30);
            this.lblDirectQuery.Name = "lblDirectQuery";
            this.lblDirectQuery.Size = new System.Drawing.Size(0, 13);
            this.lblDirectQuery.TabIndex = 47;
            // 
            // lblFormName
            // 
            this.lblFormName.AutoSize = true;
            this.lblFormName.Font = new System.Drawing.Font("∏º¿∫ ∞ÌµÒ", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblFormName.ForeColor = System.Drawing.Color.Black;
            this.lblFormName.Location = new System.Drawing.Point(7, 18);
            this.lblFormName.Name = "lblFormName";
            this.lblFormName.Size = new System.Drawing.Size(134, 30);
            this.lblFormName.TabIndex = 43;
            this.lblFormName.Text = "Fome Name";
            this.lblFormName.DoubleClick += new System.EventHandler(this.lblFormName_DoubleClick);
            // 
            // btnView
            // 
            appearance17.BackColor = System.Drawing.Color.White;
            appearance17.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance17.FontData.BoldAsString = "True";
            appearance17.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.btnView.Appearance = appearance17;
            this.btnView.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnView.Location = new System.Drawing.Point(1021, 10);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(100, 30);
            this.btnView.TabIndex = 3;
            this.btnView.Tag = "Ctrl + q";
            this.btnView.Text = "View";
            this.btnView.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnView.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            this.btnView.MouseHover += new System.EventHandler(this.btnView_MouseHover);
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            appearance15.BackColor = System.Drawing.Color.White;
            appearance15.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance15.FontData.BoldAsString = "True";
            appearance15.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.btnClose.Appearance = appearance15;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.Location = new System.Drawing.Point(1127, 10);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(100, 30);
            this.btnClose.TabIndex = 4;
            this.btnClose.Tag = "Ctrl + c";
            this.btnClose.Text = "Close";
            this.btnClose.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnClose.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            this.btnClose.MouseHover += new System.EventHandler(this.btnClose_MouseHover);
            // 
            // frmViewForm01
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(233)))), ((int)(((byte)(234)))), ((int)(((byte)(237)))));
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmViewForm01";
            this.Text = "ViewForm01";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.frmViewForm01_KeyDown);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.frmViewForm01_KeyPress);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.frmViewForm01_KeyUp);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlStsCond.ResumeLayout(false);
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        protected internal System.Windows.Forms.Panel pnlStsCond;
        protected internal System.Windows.Forms.Panel pnlMID;
        protected internal System.Windows.Forms.Panel pnlStsCond3;
        protected System.Windows.Forms.Label lblFormName;
        protected System.Windows.Forms.Label lblDirectQuery;
        protected Infragistics.Win.Misc.UltraButton btnView;
        protected Infragistics.Win.Misc.UltraButton btnClose;
        protected internal System.Windows.Forms.Panel pnlStsCond2;
        public System.Windows.Forms.CheckBox chkFavorite;
    }
}
