namespace CUS_COM
{
    partial class frmTranForm05
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
            Infragistics.Win.Appearance appearance1 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance15 = new Infragistics.Win.Appearance();
            this.pnlMID = new System.Windows.Forms.Panel();
            this.chkFavorite = new System.Windows.Forms.CheckBox();
            this.lblDirectQuery = new System.Windows.Forms.Label();
            this.pnlStsCond = new System.Windows.Forms.Panel();
            this.pnlStsCond2 = new System.Windows.Forms.Panel();
            this.lblDept = new System.Windows.Forms.Label();
            this.cdvDept = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.pnlStsCond3 = new System.Windows.Forms.Panel();
            this.lblFormName = new System.Windows.Forms.Label();
            this.btnView = new Infragistics.Win.Misc.UltraButton();
            this.btnProcess = new Infragistics.Win.Misc.UltraButton();
            this.btnClose = new Infragistics.Win.Misc.UltraButton();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlMID.SuspendLayout();
            this.pnlStsCond.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(232)))), ((int)(((byte)(244)))));
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnProcess);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Location = new System.Drawing.Point(0, 800);
            this.pnlBottom.Size = new System.Drawing.Size(1239, 40);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.pnlMID);
            this.pnlCenter.Size = new System.Drawing.Size(1239, 800);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "BaseForm03";
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
            this.pnlMID.Size = new System.Drawing.Size(1239, 800);
            this.pnlMID.TabIndex = 7;
            // 
            // chkFavorite
            // 
            this.chkFavorite.AutoSize = true;
            this.chkFavorite.Checked = true;
            this.chkFavorite.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkFavorite.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkFavorite.Location = new System.Drawing.Point(3, 3);
            this.chkFavorite.Name = "chkFavorite";
            this.chkFavorite.Size = new System.Drawing.Size(142, 16);
            this.chkFavorite.TabIndex = 297;
            this.chkFavorite.Text = "즐겨찾기 추가 (Favorite Add)";
            this.chkFavorite.UseVisualStyleBackColor = true;
            // 
            // lblDirectQuery
            // 
            this.lblDirectQuery.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblDirectQuery.AutoSize = true;
            this.lblDirectQuery.Location = new System.Drawing.Point(1184, 30);
            this.lblDirectQuery.Name = "lblDirectQuery";
            this.lblDirectQuery.Size = new System.Drawing.Size(0, 13);
            this.lblDirectQuery.TabIndex = 46;
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.BackColor = System.Drawing.Color.White;
            this.pnlStsCond.Controls.Add(this.pnlStsCond2);
            this.pnlStsCond.Controls.Add(this.lblDept);
            this.pnlStsCond.Controls.Add(this.cdvDept);
            this.pnlStsCond.Controls.Add(this.pnlStsCond3);
            this.pnlStsCond.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlStsCond.Location = new System.Drawing.Point(10, 50);
            this.pnlStsCond.Name = "pnlStsCond";
            this.pnlStsCond.Size = new System.Drawing.Size(1219, 66);
            this.pnlStsCond.TabIndex = 35;
            // 
            // pnlStsCond2
            // 
            this.pnlStsCond2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            this.pnlStsCond2.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlStsCond2.Location = new System.Drawing.Point(0, 0);
            this.pnlStsCond2.Name = "pnlStsCond2";
            this.pnlStsCond2.Size = new System.Drawing.Size(1219, 10);
            this.pnlStsCond2.TabIndex = 160;
            // 
            // lblDept
            // 
            this.lblDept.AutoSize = true;
            this.lblDept.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDept.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDept.ForeColor = System.Drawing.Color.Black;
            this.lblDept.Location = new System.Drawing.Point(11, 24);
            this.lblDept.Name = "lblDept";
            this.lblDept.Size = new System.Drawing.Size(87, 16);
            this.lblDept.TabIndex = 155;
            this.lblDept.Text = "Department";
            this.lblDept.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cdvDept
            // 
            this.cdvDept.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvDept.BorderHotColor = System.Drawing.Color.Black;
            this.cdvDept.BtnFlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cdvDept.BtnToolTipText = "";
            this.cdvDept.ButtonWidth = 30;
            this.cdvDept.DescText = "";
            this.cdvDept.DisplaySubItemIndex = 1;
            this.cdvDept.DisplayText = "";
            this.cdvDept.Focusing = null;
            this.cdvDept.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvDept.Index = 0;
            this.cdvDept.IsViewBtnImage = false;
            this.cdvDept.Location = new System.Drawing.Point(109, 19);
            this.cdvDept.MaxLength = 100;
            this.cdvDept.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvDept.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvDept.MultiSelect = false;
            this.cdvDept.Name = "cdvDept";
            this.cdvDept.ReadOnly = true;
            this.cdvDept.SameWidthHeightOfButton = false;
            this.cdvDept.SearchSubItemIndex = 0;
            this.cdvDept.SelectedDescIndex = 0;
            this.cdvDept.SelectedDescToQueryText = "";
            this.cdvDept.SelectedSubItemIndex = 0;
            this.cdvDept.SelectedValueToQueryText = "";
            this.cdvDept.SelectionStart = 0;
            this.cdvDept.Size = new System.Drawing.Size(140, 26);
            this.cdvDept.SmallImageList = null;
            this.cdvDept.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvDept.TabIndex = 0;
            this.cdvDept.TextBoxToolTipText = "";
            this.cdvDept.TextBoxWidth = 140;
            this.cdvDept.VisibleButton = true;
            this.cdvDept.VisibleColumnHeader = false;
            this.cdvDept.VisibleDescription = false;
            this.cdvDept.ButtonPress += new System.EventHandler(this.cdvDept_ButtonPress);
            // 
            // pnlStsCond3
            // 
            this.pnlStsCond3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(232)))), ((int)(((byte)(244)))));
            this.pnlStsCond3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlStsCond3.Location = new System.Drawing.Point(0, 56);
            this.pnlStsCond3.Name = "pnlStsCond3";
            this.pnlStsCond3.Size = new System.Drawing.Size(1219, 10);
            this.pnlStsCond3.TabIndex = 40;
            // 
            // lblFormName
            // 
            this.lblFormName.AutoSize = true;
            this.lblFormName.Font = new System.Drawing.Font("맑은 고딕", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblFormName.ForeColor = System.Drawing.Color.Black;
            this.lblFormName.Location = new System.Drawing.Point(6, 19);
            this.lblFormName.Name = "lblFormName";
            this.lblFormName.Size = new System.Drawing.Size(134, 30);
            this.lblFormName.TabIndex = 41;
            this.lblFormName.Text = "Fome Name";
            // 
            // btnView
            // 
            appearance17.BackColor = System.Drawing.Color.White;
            appearance17.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance17.FontData.BoldAsString = "True";
            appearance17.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.btnView.Appearance = appearance17;
            this.btnView.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnView.Location = new System.Drawing.Point(915, 5);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(100, 30);
            this.btnView.TabIndex = 3;
            this.btnView.Text = "View";
            this.btnView.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnView.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            // 
            // btnProcess
            // 
            appearance1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance1.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance1.FontData.BoldAsString = "True";
            appearance1.ForeColor = System.Drawing.Color.White;
            this.btnProcess.Appearance = appearance1;
            this.btnProcess.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnProcess.Location = new System.Drawing.Point(1021, 5);
            this.btnProcess.Name = "btnProcess";
            this.btnProcess.Size = new System.Drawing.Size(100, 30);
            this.btnProcess.TabIndex = 4;
            this.btnProcess.Text = "Process";
            this.btnProcess.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnProcess.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            // 
            // btnClose
            // 
            appearance15.BackColor = System.Drawing.Color.White;
            appearance15.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance15.FontData.BoldAsString = "True";
            appearance15.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.btnClose.Appearance = appearance15;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.Location = new System.Drawing.Point(1127, 5);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(100, 30);
            this.btnClose.TabIndex = 5;
            this.btnClose.Text = "Close";
            this.btnClose.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnClose.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // frmTranForm05
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmTranForm05";
            this.Text = "frmTranForm05";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmTranForm05_FormClosing);
            this.Load += new System.EventHandler(this.frmTranForm05_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        protected internal System.Windows.Forms.Panel pnlMID;
        protected System.Windows.Forms.Label lblDirectQuery;
        protected internal System.Windows.Forms.Panel pnlStsCond;
        protected internal System.Windows.Forms.Panel pnlStsCond2;
        public System.Windows.Forms.Label lblDept;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvDept;
        protected internal System.Windows.Forms.Panel pnlStsCond3;
        protected System.Windows.Forms.Label lblFormName;
        protected Infragistics.Win.Misc.UltraButton btnView;
        protected Infragistics.Win.Misc.UltraButton btnProcess;
        protected Infragistics.Win.Misc.UltraButton btnClose;
        private System.Windows.Forms.CheckBox chkFavorite;
    }
}