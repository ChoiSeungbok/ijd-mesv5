namespace Miracom.FMBCore
{
    partial class frmFMBOptionCore
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
            this.grpAllFactory = new System.Windows.Forms.GroupBox();
            this.rbnAllNo = new System.Windows.Forms.RadioButton();
            this.rbnAllYes = new System.Windows.Forms.RadioButton();
            this.grpStyle = new System.Windows.Forms.GroupBox();
            this.rbn3D = new System.Windows.Forms.RadioButton();
            this.rbnFlat = new System.Windows.Forms.RadioButton();
            this.pnlBottom.SuspendLayout();
            this.grpSystem.SuspendLayout();
            this.pnlMainLeft.SuspendLayout();
            this.grpAutoRefresh.SuspendLayout();
            this.grpUseGrid.SuspendLayout();
            this.pnlMainRight.SuspendLayout();
            this.grpListRefresh.SuspendLayout();
            this.grpAllFactory.SuspendLayout();
            this.grpStyle.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnOK
            // 
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // pnlMainLeft
            // 
            this.pnlMainLeft.Controls.Add(this.grpAllFactory);
            this.pnlMainLeft.Controls.SetChildIndex(this.grpUseGrid, 0);
            this.pnlMainLeft.Controls.SetChildIndex(this.grpAutoRefresh, 0);
            this.pnlMainLeft.Controls.SetChildIndex(this.grpAllFactory, 0);
            // 
            // pnlMainRight
            // 
            this.pnlMainRight.Controls.Add(this.grpStyle);
            this.pnlMainRight.Controls.SetChildIndex(this.grpListRefresh, 0);
            this.pnlMainRight.Controls.SetChildIndex(this.grpStyle, 0);
            // 
            // grpListRefresh
            // 
            this.grpListRefresh.Location = new System.Drawing.Point(2, 73);
            // 
            // grpAllFactory
            // 
            this.grpAllFactory.Controls.Add(this.rbnAllNo);
            this.grpAllFactory.Controls.Add(this.rbnAllYes);
            this.grpAllFactory.Dock = System.Windows.Forms.DockStyle.Top;
            this.grpAllFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpAllFactory.Location = new System.Drawing.Point(0, 130);
            this.grpAllFactory.Name = "grpAllFactory";
            this.grpAllFactory.Size = new System.Drawing.Size(252, 56);
            this.grpAllFactory.TabIndex = 3;
            this.grpAllFactory.TabStop = false;
            this.grpAllFactory.Text = "All Factory";
            // 
            // rbnAllNo
            // 
            this.rbnAllNo.Location = new System.Drawing.Point(144, 19);
            this.rbnAllNo.Name = "rbnAllNo";
            this.rbnAllNo.Size = new System.Drawing.Size(76, 17);
            this.rbnAllNo.TabIndex = 1;
            this.rbnAllNo.Text = "No";
            // 
            // rbnAllYes
            // 
            this.rbnAllYes.Location = new System.Drawing.Point(30, 19);
            this.rbnAllYes.Name = "rbnAllYes";
            this.rbnAllYes.Size = new System.Drawing.Size(76, 17);
            this.rbnAllYes.TabIndex = 0;
            this.rbnAllYes.Text = "Yes";
            // 
            // grpStyle
            // 
            this.grpStyle.Controls.Add(this.rbn3D);
            this.grpStyle.Controls.Add(this.rbnFlat);
            this.grpStyle.Dock = System.Windows.Forms.DockStyle.Top;
            this.grpStyle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpStyle.Location = new System.Drawing.Point(2, 129);
            this.grpStyle.Name = "grpStyle";
            this.grpStyle.Size = new System.Drawing.Size(238, 56);
            this.grpStyle.TabIndex = 3;
            this.grpStyle.TabStop = false;
            this.grpStyle.Text = "Style";
            // 
            // rbn3D
            // 
            this.rbn3D.Location = new System.Drawing.Point(144, 19);
            this.rbn3D.Name = "rbn3D";
            this.rbn3D.Size = new System.Drawing.Size(76, 17);
            this.rbn3D.TabIndex = 1;
            this.rbn3D.Text = "3D";
            // 
            // rbnFlat
            // 
            this.rbnFlat.Location = new System.Drawing.Point(32, 19);
            this.rbnFlat.Name = "rbnFlat";
            this.rbnFlat.Size = new System.Drawing.Size(76, 17);
            this.rbnFlat.TabIndex = 0;
            this.rbnFlat.Text = "Flat";
            // 
            // frmFMBOptionCore
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(514, 318);
            this.Name = "frmFMBOptionCore";
            this.Text = "frmFMBOptionCore";
            this.Activated += new System.EventHandler(this.frmOption_Activated);
            this.pnlBottom.ResumeLayout(false);
            this.grpSystem.ResumeLayout(false);
            this.grpSystem.PerformLayout();
            this.pnlMainLeft.ResumeLayout(false);
            this.grpAutoRefresh.ResumeLayout(false);
            this.grpAutoRefresh.PerformLayout();
            this.grpUseGrid.ResumeLayout(false);
            this.pnlMainRight.ResumeLayout(false);
            this.grpListRefresh.ResumeLayout(false);
            this.grpAllFactory.ResumeLayout(false);
            this.grpStyle.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        protected System.Windows.Forms.GroupBox grpAllFactory;
        protected System.Windows.Forms.RadioButton rbnAllNo;
        protected System.Windows.Forms.RadioButton rbnAllYes;
        internal System.Windows.Forms.GroupBox grpStyle;
        internal System.Windows.Forms.RadioButton rbn3D;
        internal System.Windows.Forms.RadioButton rbnFlat;
    }
}