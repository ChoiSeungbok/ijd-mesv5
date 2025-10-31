namespace CUS_COM
{
    partial class frmTranForm03
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
            this.lblOrder = new System.Windows.Forms.Label();
            this.cdvOrder = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblResource = new System.Windows.Forms.Label();
            this.cdvResource = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).BeginInit();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOrder)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvResource)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.Controls.Add(this.lblResource);
            this.pnlStsCond.Controls.Add(this.cdvResource);
            this.pnlStsCond.Controls.Add(this.lblOrder);
            this.pnlStsCond.Controls.Add(this.cdvOrder);
            this.pnlStsCond.Size = new System.Drawing.Size(1219, 98);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond2, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond3, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvDept, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblDept, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvWorkPlace, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblWorkPlace, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvOper, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblOper, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvOrder, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblOrder, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvResource, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblResource, 0);
            // 
            // pnlStsCond3
            // 
            this.pnlStsCond3.Location = new System.Drawing.Point(0, 88);
            // 
            // lblFormName
            // 
            this.lblFormName.Location = new System.Drawing.Point(3, 21);
            // 
            // cdvOper
            // 
            this.cdvOper.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOper.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvOper.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.Base_SelectedItemChanged);
            // 
            // cdvWorkPlace
            // 
            this.cdvWorkPlace.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvWorkPlace.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvWorkPlace.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.Base_SelectedItemChanged);
            // 
            // cdvDept
            // 
            this.cdvDept.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvDept.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvDept.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.Base_SelectedItemChanged);
            // 
            // pnlTop
            // 
            this.pnlTop.Size = new System.Drawing.Size(1239, 0);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Size = new System.Drawing.Size(1235, 0);
            this.lblFormTitle.Text = "TranForm01";
            // 
            // lblOrder
            // 
            this.lblOrder.AutoSize = true;
            this.lblOrder.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblOrder.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOrder.ForeColor = System.Drawing.Color.Black;
            this.lblOrder.Location = new System.Drawing.Point(792, 19);
            this.lblOrder.Name = "lblOrder";
            this.lblOrder.Size = new System.Drawing.Size(86, 16);
            this.lblOrder.TabIndex = 161;
            this.lblOrder.Text = "Work Order";
            this.lblOrder.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cdvOrder
            // 
            this.cdvOrder.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvOrder.BorderHotColor = System.Drawing.Color.Black;
            this.cdvOrder.BtnFlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cdvOrder.BtnToolTipText = "";
            this.cdvOrder.ButtonWidth = 30;
            this.cdvOrder.DescText = "";
            this.cdvOrder.DisplaySubItemIndex = 0;
            this.cdvOrder.DisplayText = "";
            this.cdvOrder.Focusing = null;
            this.cdvOrder.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvOrder.Index = 0;
            this.cdvOrder.IsViewBtnImage = false;
            this.cdvOrder.Location = new System.Drawing.Point(896, 13);
            this.cdvOrder.MaxLength = 100;
            this.cdvOrder.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOrder.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvOrder.MultiSelect = false;
            this.cdvOrder.Name = "cdvOrder";
            this.cdvOrder.ReadOnly = false;
            this.cdvOrder.SameWidthHeightOfButton = false;
            this.cdvOrder.SearchSubItemIndex = 0;
            this.cdvOrder.SelectedDescIndex = 0;
            this.cdvOrder.SelectedDescToQueryText = "";
            this.cdvOrder.SelectedSubItemIndex = 0;
            this.cdvOrder.SelectedValueToQueryText = "";
            this.cdvOrder.SelectionStart = 0;
            this.cdvOrder.Size = new System.Drawing.Size(140, 26);
            this.cdvOrder.SmallImageList = null;
            this.cdvOrder.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvOrder.TabIndex = 3;
            this.cdvOrder.TextBoxToolTipText = "";
            this.cdvOrder.TextBoxWidth = 140;
            this.cdvOrder.VisibleButton = true;
            this.cdvOrder.VisibleColumnHeader = false;
            this.cdvOrder.VisibleDescription = false;
            this.cdvOrder.ButtonPress += new System.EventHandler(this.cdvOrder_ButtonPress);
            // 
            // lblResource
            // 
            this.lblResource.AutoSize = true;
            this.lblResource.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResource.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblResource.ForeColor = System.Drawing.Color.Black;
            this.lblResource.Location = new System.Drawing.Point(11, 51);
            this.lblResource.Name = "lblResource";
            this.lblResource.Size = new System.Drawing.Size(74, 16);
            this.lblResource.TabIndex = 163;
            this.lblResource.Text = "Resource";
            this.lblResource.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cdvResource
            // 
            this.cdvResource.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvResource.BorderHotColor = System.Drawing.Color.Black;
            this.cdvResource.BtnFlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cdvResource.BtnToolTipText = "";
            this.cdvResource.ButtonWidth = 30;
            this.cdvResource.DescText = "";
            this.cdvResource.DisplaySubItemIndex = 1;
            this.cdvResource.DisplayText = "";
            this.cdvResource.Focusing = null;
            this.cdvResource.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvResource.Index = 0;
            this.cdvResource.IsViewBtnImage = false;
            this.cdvResource.Location = new System.Drawing.Point(109, 45);
            this.cdvResource.MaxLength = 100;
            this.cdvResource.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvResource.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvResource.MultiSelect = false;
            this.cdvResource.Name = "cdvResource";
            this.cdvResource.ReadOnly = true;
            this.cdvResource.SameWidthHeightOfButton = false;
            this.cdvResource.SearchSubItemIndex = 0;
            this.cdvResource.SelectedDescIndex = 0;
            this.cdvResource.SelectedDescToQueryText = "";
            this.cdvResource.SelectedSubItemIndex = 0;
            this.cdvResource.SelectedValueToQueryText = "";
            this.cdvResource.SelectionStart = 0;
            this.cdvResource.Size = new System.Drawing.Size(140, 26);
            this.cdvResource.SmallImageList = null;
            this.cdvResource.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvResource.TabIndex = 4;
            this.cdvResource.TextBoxToolTipText = "";
            this.cdvResource.TextBoxWidth = 140;
            this.cdvResource.VisibleButton = true;
            this.cdvResource.VisibleColumnHeader = false;
            this.cdvResource.VisibleDescription = false;
            this.cdvResource.ButtonPress += new System.EventHandler(this.cdvResource_ButtonPress);
            // 
            // frmTranForm03
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmTranForm03";
            this.Text = "frmTranForm03";
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).EndInit();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvOrder)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvResource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.Label lblOrder;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvOrder;
        public System.Windows.Forms.Label lblResource;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvResource;
    }
}