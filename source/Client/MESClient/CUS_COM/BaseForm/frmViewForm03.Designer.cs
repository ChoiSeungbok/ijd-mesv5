namespace CUS_COM
{
    partial class frmViewForm03
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
            this.lblDept = new System.Windows.Forms.Label();
            this.cdvDept = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.Controls.Add(this.lblDept);
            this.pnlStsCond.Controls.Add(this.cdvDept);
            this.pnlStsCond.Size = new System.Drawing.Size(1219, 73);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond3, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond2, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvDept, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblDept, 0);
            // 
            // pnlStsCond3
            // 
            this.pnlStsCond3.Location = new System.Drawing.Point(0, 61);
            this.pnlStsCond3.Size = new System.Drawing.Size(1219, 12);
            // 
            // lblDirectQuery
            // 
            this.lblDirectQuery.Location = new System.Drawing.Point(550, 38);
            // 
            // btnView
            // 
            this.btnView.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            // 
            // pnlStsCond2
            // 
            this.pnlStsCond2.Size = new System.Drawing.Size(1219, 12);
            // 
            // pnlTop
            // 
            this.pnlTop.Size = new System.Drawing.Size(1239, 0);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Size = new System.Drawing.Size(1235, 0);
            this.lblFormTitle.Text = "ViewForm01";
            // 
            // lblDept
            // 
            this.lblDept.AutoSize = true;
            this.lblDept.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDept.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDept.ForeColor = System.Drawing.Color.Black;
            this.lblDept.Location = new System.Drawing.Point(10, 26);
            this.lblDept.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblDept.Name = "lblDept";
            this.lblDept.Size = new System.Drawing.Size(87, 16);
            this.lblDept.TabIndex = 167;
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
            this.cdvDept.Location = new System.Drawing.Point(132, 23);
            this.cdvDept.Margin = new System.Windows.Forms.Padding(4);
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
            this.cdvDept.Size = new System.Drawing.Size(175, 26);
            this.cdvDept.SmallImageList = null;
            this.cdvDept.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvDept.TabIndex = 166;
            this.cdvDept.TextBoxToolTipText = "";
            this.cdvDept.TextBoxWidth = 175;
            this.cdvDept.VisibleButton = true;
            this.cdvDept.VisibleColumnHeader = false;
            this.cdvDept.VisibleDescription = false;
            this.cdvDept.ButtonPress += new System.EventHandler(this.cdvDept_ButtonPress);
            // 
            // frmViewForm03
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmViewForm03";
            this.Text = "frmViewForm03";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmViewForm03_FormClosing);
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.Label lblDept;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvDept;
    }
}