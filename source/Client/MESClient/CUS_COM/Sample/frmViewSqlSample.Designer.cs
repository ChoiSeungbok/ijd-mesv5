namespace CUS_COM
{
    partial class frmViewSqlSample
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
            this.fpSpread1 = new FarPoint.Win.Spread.FpSpread();
            this.fpSpread1_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.label30 = new System.Windows.Forms.Label();
            this.txtLotID = new System.Windows.Forms.TextBox();
            this.btnView2 = new Infragistics.Win.Misc.UltraButton();
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fpSpread1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fpSpread1_Sheet1)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.Controls.Add(this.txtLotID);
            this.pnlStsCond.Controls.Add(this.label30);
            this.pnlStsCond.Size = new System.Drawing.Size(981, 50);
            // 
            // pnlMID
            // 
            this.pnlMID.Controls.Add(this.fpSpread1);
            this.pnlMID.Controls.SetChildIndex(this.pnlStsCond, 0);
            this.pnlMID.Controls.SetChildIndex(this.fpSpread1, 0);
            // 
            // btnView
            // 
            this.btnView.Text = "View1";
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnView2);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnView, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnView2, 0);
            // 
            // pnlTop
            // 
            this.pnlTop.Size = new System.Drawing.Size(981, 0);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Size = new System.Drawing.Size(977, 0);
            this.lblFormTitle.Text = "ViewForm01";
            // 
            // fpSpread1
            // 
            this.fpSpread1.AccessibleDescription = "";
            this.fpSpread1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.fpSpread1.Location = new System.Drawing.Point(0, 50);
            this.fpSpread1.Name = "fpSpread1";
            this.fpSpread1.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.fpSpread1_Sheet1});
            this.fpSpread1.Size = new System.Drawing.Size(981, 562);
            this.fpSpread1.TabIndex = 36;
            // 
            // fpSpread1_Sheet1
            // 
            this.fpSpread1_Sheet1.Reset();
            this.fpSpread1_Sheet1.SheetName = "Sheet1";
            // 
            // label30
            // 
            this.label30.AutoSize = true;
            this.label30.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label30.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label30.ForeColor = System.Drawing.Color.White;
            this.label30.Location = new System.Drawing.Point(15, 11);
            this.label30.Name = "label30";
            this.label30.Size = new System.Drawing.Size(63, 24);
            this.label30.TabIndex = 143;
            this.label30.Text = "Lot ID";
            this.label30.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtLotID
            // 
            this.txtLotID.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.txtLotID.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtLotID.ForeColor = System.Drawing.Color.Navy;
            this.txtLotID.Location = new System.Drawing.Point(105, 8);
            this.txtLotID.Name = "txtLotID";
            this.txtLotID.Size = new System.Drawing.Size(189, 29);
            this.txtLotID.TabIndex = 144;
            // 
            // btnView2
            // 
            appearance17.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(103)))), ((int)(((byte)(193)))), ((int)(((byte)(255)))));
            appearance17.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(51)))), ((int)(((byte)(153)))));
            appearance17.BackGradientStyle = Infragistics.Win.GradientStyle.Vertical;
            appearance17.FontData.BoldAsString = "True";
            appearance17.FontData.SizeInPoints = 12F;
            appearance17.ForeColor = System.Drawing.Color.White;
            this.btnView2.Appearance = appearance17;
            this.btnView2.Font = new System.Drawing.Font("맑은 고딕", 14F, System.Drawing.FontStyle.Bold);
            this.btnView2.Location = new System.Drawing.Point(418, 5);
            this.btnView2.Name = "btnView2";
            this.btnView2.Size = new System.Drawing.Size(145, 40);
            this.btnView2.TabIndex = 234;
            this.btnView2.Text = "View2";
            this.btnView2.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnView2.Click += new System.EventHandler(this.btnView2_Click);
            // 
            // frmViewSqlSample
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(981, 662);
            this.Name = "frmViewSqlSample";
            this.Text = "frmViewSqlSample";
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.fpSpread1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fpSpread1_Sheet1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private FarPoint.Win.Spread.FpSpread fpSpread1;
        private FarPoint.Win.Spread.SheetView fpSpread1_Sheet1;
        private System.Windows.Forms.Label label30;
        private System.Windows.Forms.TextBox txtLotID;
        protected Infragistics.Win.Misc.UltraButton btnView2;
    }
}