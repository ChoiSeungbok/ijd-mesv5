namespace Miracom.FMBCore
{
    partial class frmFMBSetupResourceColor
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.pnlTop = new System.Windows.Forms.Panel();
            this.grpFactory = new System.Windows.Forms.GroupBox();
            this.cdvType = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblType = new System.Windows.Forms.Label();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.lisResource = new Miracom.UI.Controls.MCListView.MCListView();
            this.columnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.pnlFill = new System.Windows.Forms.Panel();
            this.grpColor = new System.Windows.Forms.GroupBox();
            this.cdvStatus = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblColor = new System.Windows.Forms.Label();
            this.utcBack = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.lblStatus = new System.Windows.Forms.Label();
            this.pnlBottom.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.grpFactory.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvType)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            this.pnlLeft.SuspendLayout();
            this.pnlFill.SuspendLayout();
            this.grpColor.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvStatus)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBack)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnDelete);
            this.pnlBottom.Controls.Add(this.btnUpdate);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 513);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 3;
            // 
            // btnDelete
            // 
            this.btnDelete.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnDelete.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnDelete.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnDelete.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDelete.Location = new System.Drawing.Point(581, 9);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(74, 23);
            this.btnDelete.TabIndex = 3;
            this.btnDelete.Text = "Delete";
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnUpdate.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnUpdate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnUpdate.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUpdate.Location = new System.Drawing.Point(501, 9);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(74, 23);
            this.btnUpdate.TabIndex = 1;
            this.btnUpdate.Text = "Update";
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.Location = new System.Drawing.Point(659, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 2;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // pnlTop
            // 
            this.pnlTop.Controls.Add(this.grpFactory);
            this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTop.Location = new System.Drawing.Point(0, 0);
            this.pnlTop.Name = "pnlTop";
            this.pnlTop.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlTop.Size = new System.Drawing.Size(742, 54);
            this.pnlTop.TabIndex = 4;
            // 
            // grpFactory
            // 
            this.grpFactory.Controls.Add(this.cdvType);
            this.grpFactory.Controls.Add(this.lblType);
            this.grpFactory.Controls.Add(this.cdvFactory);
            this.grpFactory.Controls.Add(this.lblFactory);
            this.grpFactory.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpFactory.Location = new System.Drawing.Point(3, 0);
            this.grpFactory.Name = "grpFactory";
            this.grpFactory.Size = new System.Drawing.Size(736, 54);
            this.grpFactory.TabIndex = 1;
            this.grpFactory.TabStop = false;
            // 
            // cdvType
            // 
            this.cdvType.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvType.BorderHotColor = System.Drawing.Color.Black;
            this.cdvType.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvType.BtnToolTipText = "";
            this.cdvType.DescText = "";
            this.cdvType.DisplaySubItemIndex = -1;
            this.cdvType.DisplayText = "";
            this.cdvType.Focusing = null;
            this.cdvType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvType.Index = 0;
            this.cdvType.IsViewBtnImage = false;
            this.cdvType.Location = new System.Drawing.Point(527, 17);
            this.cdvType.MaxLength = 10;
            this.cdvType.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvType.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvType.Name = "cdvType";
            this.cdvType.ReadOnly = false;
            this.cdvType.SearchSubItemIndex = 0;
            this.cdvType.SelectedDescIndex = -1;
            this.cdvType.SelectedSubItemIndex = -1;
            this.cdvType.SelectionStart = 0;
            this.cdvType.Size = new System.Drawing.Size(200, 20);
            this.cdvType.SmallImageList = null;
            this.cdvType.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvType.TabIndex = 53;
            this.cdvType.TextBoxToolTipText = "";
            this.cdvType.TextBoxWidth = 200;
            this.cdvType.VisibleButton = true;
            this.cdvType.VisibleColumnHeader = false;
            this.cdvType.VisibleDescription = false;
            this.cdvType.TextBoxTextChanged += new System.EventHandler(this.cdvType_TextBoxTextChanged);
            this.cdvType.ButtonPress += new System.EventHandler(this.cdvType_ButtonPress);
            this.cdvType.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvType_SelectedItemChanged);
            // 
            // lblType
            // 
            this.lblType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblType.Location = new System.Drawing.Point(426, 20);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(100, 14);
            this.lblType.TabIndex = 54;
            this.lblType.Text = "Type";
            // 
            // cdvFactory
            // 
            this.cdvFactory.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvFactory.BorderHotColor = System.Drawing.Color.Black;
            this.cdvFactory.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvFactory.BtnToolTipText = "";
            this.cdvFactory.DescText = "";
            this.cdvFactory.DisplaySubItemIndex = -1;
            this.cdvFactory.DisplayText = "";
            this.cdvFactory.Focusing = null;
            this.cdvFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvFactory.Index = 0;
            this.cdvFactory.IsViewBtnImage = false;
            this.cdvFactory.Location = new System.Drawing.Point(116, 17);
            this.cdvFactory.MaxLength = 10;
            this.cdvFactory.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.Name = "cdvFactory";
            this.cdvFactory.ReadOnly = false;
            this.cdvFactory.SearchSubItemIndex = 0;
            this.cdvFactory.SelectedDescIndex = -1;
            this.cdvFactory.SelectedSubItemIndex = -1;
            this.cdvFactory.SelectionStart = 0;
            this.cdvFactory.Size = new System.Drawing.Size(200, 20);
            this.cdvFactory.SmallImageList = null;
            this.cdvFactory.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvFactory.TabIndex = 0;
            this.cdvFactory.TextBoxToolTipText = "";
            this.cdvFactory.TextBoxWidth = 200;
            this.cdvFactory.VisibleButton = true;
            this.cdvFactory.VisibleColumnHeader = false;
            this.cdvFactory.VisibleDescription = false;
            this.cdvFactory.TextBoxTextChanged += new System.EventHandler(this.cdvFactory_TextBoxTextChanged);
            this.cdvFactory.ButtonPress += new System.EventHandler(this.cdvFactory_ButtonPress);
            // 
            // lblFactory
            // 
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFactory.Location = new System.Drawing.Point(15, 20);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(100, 14);
            this.lblFactory.TabIndex = 50;
            this.lblFactory.Text = "Factory";
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.lisResource);
            this.pnlLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLeft.Location = new System.Drawing.Point(0, 54);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Padding = new System.Windows.Forms.Padding(3, 3, 3, 0);
            this.pnlLeft.Size = new System.Drawing.Size(226, 459);
            this.pnlLeft.TabIndex = 5;
            // 
            // lisResource
            // 
            this.lisResource.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader5,
            this.columnHeader6});
            this.lisResource.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisResource.EnableSort = true;
            this.lisResource.EnableSortIcon = true;
            this.lisResource.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisResource.FullRowSelect = true;
            this.lisResource.Location = new System.Drawing.Point(3, 3);
            this.lisResource.MultiSelect = false;
            this.lisResource.Name = "lisResource";
            this.lisResource.Size = new System.Drawing.Size(220, 456);
            this.lisResource.TabIndex = 4;
            this.lisResource.UseCompatibleStateImageBehavior = false;
            this.lisResource.View = System.Windows.Forms.View.Details;
            this.lisResource.SelectedIndexChanged += new System.EventHandler(this.lisResource_SelectedIndexChanged);
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Status";
            this.columnHeader5.Width = 102;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Color";
            this.columnHeader6.Width = 257;
            // 
            // pnlFill
            // 
            this.pnlFill.Controls.Add(this.grpColor);
            this.pnlFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlFill.Location = new System.Drawing.Point(226, 54);
            this.pnlFill.Name = "pnlFill";
            this.pnlFill.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlFill.Size = new System.Drawing.Size(516, 459);
            this.pnlFill.TabIndex = 6;
            // 
            // grpColor
            // 
            this.grpColor.Controls.Add(this.cdvStatus);
            this.grpColor.Controls.Add(this.lblColor);
            this.grpColor.Controls.Add(this.utcBack);
            this.grpColor.Controls.Add(this.lblStatus);
            this.grpColor.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpColor.Location = new System.Drawing.Point(3, 0);
            this.grpColor.Name = "grpColor";
            this.grpColor.Size = new System.Drawing.Size(510, 459);
            this.grpColor.TabIndex = 0;
            this.grpColor.TabStop = false;
            // 
            // cdvStatus
            // 
            this.cdvStatus.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvStatus.BorderHotColor = System.Drawing.Color.Black;
            this.cdvStatus.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvStatus.BtnToolTipText = "";
            this.cdvStatus.DescText = "";
            this.cdvStatus.DisplaySubItemIndex = -1;
            this.cdvStatus.DisplayText = "";
            this.cdvStatus.Focusing = null;
            this.cdvStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvStatus.Index = 0;
            this.cdvStatus.IsViewBtnImage = false;
            this.cdvStatus.Location = new System.Drawing.Point(104, 19);
            this.cdvStatus.MaxLength = 10;
            this.cdvStatus.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvStatus.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvStatus.Name = "cdvStatus";
            this.cdvStatus.ReadOnly = false;
            this.cdvStatus.SearchSubItemIndex = 0;
            this.cdvStatus.SelectedDescIndex = -1;
            this.cdvStatus.SelectedSubItemIndex = -1;
            this.cdvStatus.SelectionStart = 0;
            this.cdvStatus.Size = new System.Drawing.Size(200, 20);
            this.cdvStatus.SmallImageList = null;
            this.cdvStatus.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvStatus.TabIndex = 54;
            this.cdvStatus.TextBoxToolTipText = "";
            this.cdvStatus.TextBoxWidth = 200;
            this.cdvStatus.VisibleButton = true;
            this.cdvStatus.VisibleColumnHeader = false;
            this.cdvStatus.VisibleDescription = false;
            this.cdvStatus.ButtonPress += new System.EventHandler(this.cdvStatus_ButtonPress);
            this.cdvStatus.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvStatus_SelectedItemChanged);
            // 
            // lblColor
            // 
            this.lblColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblColor.Location = new System.Drawing.Point(10, 47);
            this.lblColor.Name = "lblColor";
            this.lblColor.Size = new System.Drawing.Size(88, 14);
            this.lblColor.TabIndex = 8;
            this.lblColor.Text = "Back Color";
            // 
            // utcBack
            // 
            this.utcBack.Location = new System.Drawing.Point(104, 45);
            this.utcBack.Name = "utcBack";
            this.utcBack.Size = new System.Drawing.Size(163, 19);
            this.utcBack.TabIndex = 7;
            this.utcBack.Text = "Control";
            this.utcBack.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblStatus
            // 
            this.lblStatus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblStatus.Location = new System.Drawing.Point(10, 22);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(88, 14);
            this.lblStatus.TabIndex = 6;
            this.lblStatus.Text = "Resource Status";
            // 
            // frmFMBSetupResourceColor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Controls.Add(this.pnlFill);
            this.Controls.Add(this.pnlLeft);
            this.Controls.Add(this.pnlTop);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBSetupResourceColor";
            this.Text = "Resource Color Setup";
            this.Load += new System.EventHandler(this.frmFMBSetupResourceColor_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.grpFactory.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvType)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            this.pnlLeft.ResumeLayout(false);
            this.pnlFill.ResumeLayout(false);
            this.grpColor.ResumeLayout(false);
            this.grpColor.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvStatus)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBack)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Button btnDelete;
        internal System.Windows.Forms.Button btnUpdate;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.GroupBox grpFactory;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvType;
        internal System.Windows.Forms.Label lblType;
        private System.Windows.Forms.Panel pnlLeft;
        internal Miracom.UI.Controls.MCListView.MCListView lisResource;
        internal System.Windows.Forms.ColumnHeader columnHeader5;
        internal System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.Panel pnlFill;
        private System.Windows.Forms.GroupBox grpColor;
        internal System.Windows.Forms.Label lblStatus;
        internal System.Windows.Forms.Label lblColor;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBack;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvStatus;
    }
}