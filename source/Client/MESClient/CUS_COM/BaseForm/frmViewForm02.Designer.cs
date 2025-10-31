namespace CUS_COM
{
    partial class frmViewForm02
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
            this.lblWorkPlace = new System.Windows.Forms.Label();
            this.cdvWorkPlace = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblDept = new System.Windows.Forms.Label();
            this.cdvDept = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblOper = new System.Windows.Forms.Label();
            this.cdvOper = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.Controls.Add(this.lblOper);
            this.pnlStsCond.Controls.Add(this.cdvOper);
            this.pnlStsCond.Controls.Add(this.lblWorkPlace);
            this.pnlStsCond.Controls.Add(this.cdvWorkPlace);
            this.pnlStsCond.Controls.Add(this.lblDept);
            this.pnlStsCond.Controls.Add(this.cdvDept);
            this.pnlStsCond.Size = new System.Drawing.Size(1529, 73);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond3, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond2, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvDept, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblDept, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvWorkPlace, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblWorkPlace, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvOper, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblOper, 0);
            // 
            // pnlMID
            // 
            this.pnlMID.Size = new System.Drawing.Size(1549, 1000);
            // 
            // pnlStsCond3
            // 
            this.pnlStsCond3.Location = new System.Drawing.Point(0, 63);
            this.pnlStsCond3.Size = new System.Drawing.Size(1529, 10);
            // 
            // lblFormName
            // 
            this.lblFormName.Font = new System.Drawing.Font("맑은 고딕", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblFormName.Location = new System.Drawing.Point(8, 19);
            this.lblFormName.Size = new System.Drawing.Size(134, 30);
            // 
            // lblDirectQuery
            // 
            this.lblDirectQuery.Location = new System.Drawing.Point(2734, 30);
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(1437, 8);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(2677, 10);
            // 
            // pnlStsCond2
            // 
            this.pnlStsCond2.Size = new System.Drawing.Size(1529, 10);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Location = new System.Drawing.Point(0, 1000);
            this.pnlBottom.Size = new System.Drawing.Size(1549, 50);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(1549, 1000);
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
            // lblWorkPlace
            // 
            this.lblWorkPlace.AutoSize = true;
            this.lblWorkPlace.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblWorkPlace.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWorkPlace.ForeColor = System.Drawing.Color.Black;
            this.lblWorkPlace.Location = new System.Drawing.Point(351, 29);
            this.lblWorkPlace.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblWorkPlace.Name = "lblWorkPlace";
            this.lblWorkPlace.Size = new System.Drawing.Size(83, 16);
            this.lblWorkPlace.TabIndex = 166;
            this.lblWorkPlace.Text = "WorkPlace";
            this.lblWorkPlace.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cdvWorkPlace
            // 
            this.cdvWorkPlace.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvWorkPlace.BorderHotColor = System.Drawing.Color.Black;
            this.cdvWorkPlace.BtnFlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cdvWorkPlace.BtnToolTipText = "";
            this.cdvWorkPlace.ButtonWidth = 30;
            this.cdvWorkPlace.DescText = "";
            this.cdvWorkPlace.DisplaySubItemIndex = 1;
            this.cdvWorkPlace.DisplayText = "";
            this.cdvWorkPlace.Focusing = null;
            this.cdvWorkPlace.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvWorkPlace.Index = 0;
            this.cdvWorkPlace.IsViewBtnImage = false;
            this.cdvWorkPlace.Location = new System.Drawing.Point(474, 23);
            this.cdvWorkPlace.Margin = new System.Windows.Forms.Padding(4);
            this.cdvWorkPlace.MaxLength = 100;
            this.cdvWorkPlace.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvWorkPlace.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvWorkPlace.MultiSelect = false;
            this.cdvWorkPlace.Name = "cdvWorkPlace";
            this.cdvWorkPlace.ReadOnly = true;
            this.cdvWorkPlace.SameWidthHeightOfButton = false;
            this.cdvWorkPlace.SearchSubItemIndex = 0;
            this.cdvWorkPlace.SelectedDescIndex = 0;
            this.cdvWorkPlace.SelectedDescToQueryText = "";
            this.cdvWorkPlace.SelectedSubItemIndex = 0;
            this.cdvWorkPlace.SelectedValueToQueryText = "";
            this.cdvWorkPlace.SelectionStart = 0;
            this.cdvWorkPlace.Size = new System.Drawing.Size(175, 26);
            this.cdvWorkPlace.SmallImageList = null;
            this.cdvWorkPlace.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvWorkPlace.TabIndex = 163;
            this.cdvWorkPlace.TextBoxToolTipText = "";
            this.cdvWorkPlace.TextBoxWidth = 175;
            this.cdvWorkPlace.VisibleButton = true;
            this.cdvWorkPlace.VisibleColumnHeader = false;
            this.cdvWorkPlace.VisibleDescription = false;
            this.cdvWorkPlace.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvWorkPlace_SelectedItemChanged);
            this.cdvWorkPlace.ButtonPress += new System.EventHandler(this.cdvWorkPlace_ButtonPress);
            // 
            // lblDept
            // 
            this.lblDept.AutoSize = true;
            this.lblDept.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDept.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDept.ForeColor = System.Drawing.Color.Black;
            this.lblDept.Location = new System.Drawing.Point(14, 29);
            this.lblDept.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblDept.Name = "lblDept";
            this.lblDept.Size = new System.Drawing.Size(87, 16);
            this.lblDept.TabIndex = 165;
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
            this.cdvDept.Location = new System.Drawing.Point(136, 23);
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
            this.cdvDept.TabIndex = 162;
            this.cdvDept.TextBoxToolTipText = "";
            this.cdvDept.TextBoxWidth = 175;
            this.cdvDept.VisibleButton = true;
            this.cdvDept.VisibleColumnHeader = false;
            this.cdvDept.VisibleDescription = false;
            this.cdvDept.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvDept_SelectedItemChanged);
            this.cdvDept.ButtonPress += new System.EventHandler(this.cdvDept_ButtonPress);
            // 
            // lblOper
            // 
            this.lblOper.AutoSize = true;
            this.lblOper.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblOper.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOper.ForeColor = System.Drawing.Color.Black;
            this.lblOper.Location = new System.Drawing.Point(704, 29);
            this.lblOper.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblOper.Name = "lblOper";
            this.lblOper.Size = new System.Drawing.Size(41, 16);
            this.lblOper.TabIndex = 168;
            this.lblOper.Text = "Oper";
            this.lblOper.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cdvOper
            // 
            this.cdvOper.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvOper.BorderHotColor = System.Drawing.Color.Black;
            this.cdvOper.BtnFlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cdvOper.BtnToolTipText = "";
            this.cdvOper.ButtonWidth = 30;
            this.cdvOper.DescText = "";
            this.cdvOper.DisplaySubItemIndex = 1;
            this.cdvOper.DisplayText = "";
            this.cdvOper.Focusing = null;
            this.cdvOper.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvOper.Index = 0;
            this.cdvOper.IsViewBtnImage = false;
            this.cdvOper.Location = new System.Drawing.Point(775, 23);
            this.cdvOper.Margin = new System.Windows.Forms.Padding(4);
            this.cdvOper.MaxLength = 100;
            this.cdvOper.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOper.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvOper.MultiSelect = false;
            this.cdvOper.Name = "cdvOper";
            this.cdvOper.ReadOnly = true;
            this.cdvOper.SameWidthHeightOfButton = false;
            this.cdvOper.SearchSubItemIndex = 0;
            this.cdvOper.SelectedDescIndex = 0;
            this.cdvOper.SelectedDescToQueryText = "";
            this.cdvOper.SelectedSubItemIndex = 0;
            this.cdvOper.SelectedValueToQueryText = "";
            this.cdvOper.SelectionStart = 0;
            this.cdvOper.Size = new System.Drawing.Size(175, 26);
            this.cdvOper.SmallImageList = null;
            this.cdvOper.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvOper.TabIndex = 167;
            this.cdvOper.TextBoxToolTipText = "";
            this.cdvOper.TextBoxWidth = 175;
            this.cdvOper.VisibleButton = true;
            this.cdvOper.VisibleColumnHeader = false;
            this.cdvOper.VisibleDescription = false;
            this.cdvOper.ButtonPress += new System.EventHandler(this.cdvOper_ButtonPress);
            // 
            // frmViewForm02
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1549, 1050);
            this.Name = "frmViewForm02";
            this.Text = "frmViewForm02";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmViewForm02_FormClosing);
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        public System.Windows.Forms.Label lblWorkPlace;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvWorkPlace;
        public System.Windows.Forms.Label lblDept;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvDept;
        public System.Windows.Forms.Label lblOper;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvOper;
    }
}