namespace CUS_INV
{
    partial class frmTranReleaseInvLot
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
            Infragistics.Win.Appearance appearance4 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance3 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance5 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance1 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance2 = new Infragistics.Win.Appearance();
            this.btnProcess = new Infragistics.Win.Misc.UltraButton();
            this.txtInvLotID = new System.Windows.Forms.TextBox();
            this.lblInvLotId = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.grpInvLotInfo = new Infragistics.Win.Misc.UltraGroupBox();
            this.txtOperDesc = new System.Windows.Forms.TextBox();
            this.lblOperDesc = new System.Windows.Forms.Label();
            this.txtSubAreaId = new System.Windows.Forms.TextBox();
            this.lblSubAreaId = new System.Windows.Forms.Label();
            this.txtAreaId = new System.Windows.Forms.TextBox();
            this.lblAreaId = new System.Windows.Forms.Label();
            this.txtInvLotStatus = new System.Windows.Forms.TextBox();
            this.lblInvLotStatus = new System.Windows.Forms.Label();
            this.txtUnit = new System.Windows.Forms.TextBox();
            this.lblUnit = new System.Windows.Forms.Label();
            this.txtInvLotType = new System.Windows.Forms.TextBox();
            this.lblInvLvlType = new System.Windows.Forms.Label();
            this.txtQty = new System.Windows.Forms.TextBox();
            this.lblQty = new System.Windows.Forms.Label();
            this.txtMatDesc = new System.Windows.Forms.TextBox();
            this.lblMatDesc = new System.Windows.Forms.Label();
            this.txtHoldFlag = new System.Windows.Forms.TextBox();
            this.lblHoldFlag = new System.Windows.Forms.Label();
            this.txtOper = new System.Windows.Forms.TextBox();
            this.lblOper = new System.Windows.Forms.Label();
            this.txtMatId = new System.Windows.Forms.TextBox();
            this.lblMatId = new System.Windows.Forms.Label();
            this.grpReleaseInfo = new Infragistics.Win.Misc.UltraGroupBox();
            this.lblReleaseCode = new System.Windows.Forms.Label();
            this.cdvReleaseCode = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.txtTranComment = new System.Windows.Forms.TextBox();
            this.lblTranComment = new System.Windows.Forms.Label();
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.grpInvLotInfo)).BeginInit();
            this.grpInvLotInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.grpReleaseInfo)).BeginInit();
            this.grpReleaseInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvReleaseCode)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.Controls.Add(this.txtInvLotID);
            this.pnlStsCond.Controls.Add(this.lblInvLotId);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond3, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond2, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblInvLotId, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.txtInvLotID, 0);
            // 
            // pnlMID
            // 
            this.pnlMID.Controls.Add(this.panel1);
            this.pnlMID.Controls.SetChildIndex(this.lblFormName, 0);
            this.pnlMID.Controls.SetChildIndex(this.pnlStsCond, 0);
            this.pnlMID.Controls.SetChildIndex(this.lblDirectQuery, 0);
            this.pnlMID.Controls.SetChildIndex(this.panel1, 0);
            // 
            // lblFormName
            // 
            this.lblFormName.Size = new System.Drawing.Size(253, 37);
            this.lblFormName.Text = "Release Inventory ";
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(897, 10);
            this.btnView.Visible = false;
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnProcess);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnView, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnProcess, 0);
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
            // btnProcess
            // 
            appearance4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance4.FontData.BoldAsString = "True";
            appearance4.ForeColor = System.Drawing.Color.White;
            this.btnProcess.Appearance = appearance4;
            this.btnProcess.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnProcess.Location = new System.Drawing.Point(1003, 10);
            this.btnProcess.Name = "btnProcess";
            this.btnProcess.Size = new System.Drawing.Size(118, 30);
            this.btnProcess.TabIndex = 251;
            this.btnProcess.Text = "Release Inv Lot";
            this.btnProcess.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnProcess.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnProcess.Click += new System.EventHandler(this.btnProcess_Click);
            // 
            // txtInvLotID
            // 
            this.txtInvLotID.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtInvLotID.Location = new System.Drawing.Point(145, 18);
            this.txtInvLotID.Name = "txtInvLotID";
            this.txtInvLotID.Size = new System.Drawing.Size(167, 26);
            this.txtInvLotID.TabIndex = 257;
            this.txtInvLotID.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtInvLotID_KeyPress);
            // 
            // lblInvLotId
            // 
            this.lblInvLotId.AutoSize = true;
            this.lblInvLotId.BackColor = System.Drawing.Color.White;
            this.lblInvLotId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblInvLotId.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInvLotId.ForeColor = System.Drawing.Color.Black;
            this.lblInvLotId.Location = new System.Drawing.Point(11, 24);
            this.lblInvLotId.Name = "lblInvLotId";
            this.lblInvLotId.Size = new System.Drawing.Size(109, 16);
            this.lblInvLotId.TabIndex = 256;
            this.lblInvLotId.Text = "Hold Inv Lot ID";
            this.lblInvLotId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.splitContainer1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(10, 120);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1219, 670);
            this.panel1.TabIndex = 49;
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.grpInvLotInfo);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.grpReleaseInfo);
            this.splitContainer1.Size = new System.Drawing.Size(1219, 670);
            this.splitContainer1.SplitterDistance = 515;
            this.splitContainer1.TabIndex = 0;
            // 
            // grpInvLotInfo
            // 
            this.grpInvLotInfo.BorderStyle = Infragistics.Win.Misc.GroupBoxBorderStyle.None;
            appearance3.BackColor = System.Drawing.Color.White;
            appearance3.BackColor2 = System.Drawing.Color.White;
            this.grpInvLotInfo.ContentAreaAppearance = appearance3;
            this.grpInvLotInfo.Controls.Add(this.txtOperDesc);
            this.grpInvLotInfo.Controls.Add(this.lblOperDesc);
            this.grpInvLotInfo.Controls.Add(this.txtSubAreaId);
            this.grpInvLotInfo.Controls.Add(this.lblSubAreaId);
            this.grpInvLotInfo.Controls.Add(this.txtAreaId);
            this.grpInvLotInfo.Controls.Add(this.lblAreaId);
            this.grpInvLotInfo.Controls.Add(this.txtInvLotStatus);
            this.grpInvLotInfo.Controls.Add(this.lblInvLotStatus);
            this.grpInvLotInfo.Controls.Add(this.txtUnit);
            this.grpInvLotInfo.Controls.Add(this.lblUnit);
            this.grpInvLotInfo.Controls.Add(this.txtInvLotType);
            this.grpInvLotInfo.Controls.Add(this.lblInvLvlType);
            this.grpInvLotInfo.Controls.Add(this.txtQty);
            this.grpInvLotInfo.Controls.Add(this.lblQty);
            this.grpInvLotInfo.Controls.Add(this.txtMatDesc);
            this.grpInvLotInfo.Controls.Add(this.lblMatDesc);
            this.grpInvLotInfo.Controls.Add(this.txtHoldFlag);
            this.grpInvLotInfo.Controls.Add(this.lblHoldFlag);
            this.grpInvLotInfo.Controls.Add(this.txtOper);
            this.grpInvLotInfo.Controls.Add(this.lblOper);
            this.grpInvLotInfo.Controls.Add(this.txtMatId);
            this.grpInvLotInfo.Controls.Add(this.lblMatId);
            this.grpInvLotInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpInvLotInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            appearance5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance5.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance5.ForeColor = System.Drawing.Color.White;
            this.grpInvLotInfo.HeaderAppearance = appearance5;
            this.grpInvLotInfo.Location = new System.Drawing.Point(0, 0);
            this.grpInvLotInfo.Margin = new System.Windows.Forms.Padding(5);
            this.grpInvLotInfo.Name = "grpInvLotInfo";
            this.grpInvLotInfo.Size = new System.Drawing.Size(1219, 515);
            this.grpInvLotInfo.TabIndex = 250;
            this.grpInvLotInfo.Text = "Hold Inv Lot Info";
            // 
            // txtOperDesc
            // 
            this.txtOperDesc.BackColor = System.Drawing.SystemColors.Window;
            this.txtOperDesc.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtOperDesc.Location = new System.Drawing.Point(588, 180);
            this.txtOperDesc.Name = "txtOperDesc";
            this.txtOperDesc.ReadOnly = true;
            this.txtOperDesc.Size = new System.Drawing.Size(167, 26);
            this.txtOperDesc.TabIndex = 303;
            // 
            // lblOperDesc
            // 
            this.lblOperDesc.AutoSize = true;
            this.lblOperDesc.BackColor = System.Drawing.Color.White;
            this.lblOperDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblOperDesc.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOperDesc.ForeColor = System.Drawing.Color.Black;
            this.lblOperDesc.Location = new System.Drawing.Point(454, 185);
            this.lblOperDesc.Name = "lblOperDesc";
            this.lblOperDesc.Size = new System.Drawing.Size(127, 16);
            this.lblOperDesc.TabIndex = 302;
            this.lblOperDesc.Text = "Warehouse Desc";
            this.lblOperDesc.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtSubAreaId
            // 
            this.txtSubAreaId.BackColor = System.Drawing.SystemColors.Window;
            this.txtSubAreaId.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtSubAreaId.Location = new System.Drawing.Point(588, 119);
            this.txtSubAreaId.Name = "txtSubAreaId";
            this.txtSubAreaId.ReadOnly = true;
            this.txtSubAreaId.Size = new System.Drawing.Size(167, 26);
            this.txtSubAreaId.TabIndex = 301;
            // 
            // lblSubAreaId
            // 
            this.lblSubAreaId.AutoSize = true;
            this.lblSubAreaId.BackColor = System.Drawing.Color.White;
            this.lblSubAreaId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSubAreaId.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSubAreaId.ForeColor = System.Drawing.Color.Black;
            this.lblSubAreaId.Location = new System.Drawing.Point(454, 124);
            this.lblSubAreaId.Name = "lblSubAreaId";
            this.lblSubAreaId.Size = new System.Drawing.Size(84, 16);
            this.lblSubAreaId.TabIndex = 300;
            this.lblSubAreaId.Text = "WorkPlace";
            this.lblSubAreaId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtAreaId
            // 
            this.txtAreaId.BackColor = System.Drawing.SystemColors.Window;
            this.txtAreaId.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtAreaId.Location = new System.Drawing.Point(145, 120);
            this.txtAreaId.Name = "txtAreaId";
            this.txtAreaId.ReadOnly = true;
            this.txtAreaId.Size = new System.Drawing.Size(167, 26);
            this.txtAreaId.TabIndex = 299;
            // 
            // lblAreaId
            // 
            this.lblAreaId.AutoSize = true;
            this.lblAreaId.BackColor = System.Drawing.Color.White;
            this.lblAreaId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblAreaId.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAreaId.ForeColor = System.Drawing.Color.Black;
            this.lblAreaId.Location = new System.Drawing.Point(11, 125);
            this.lblAreaId.Name = "lblAreaId";
            this.lblAreaId.Size = new System.Drawing.Size(88, 16);
            this.lblAreaId.TabIndex = 298;
            this.lblAreaId.Text = "Department";
            this.lblAreaId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtInvLotStatus
            // 
            this.txtInvLotStatus.BackColor = System.Drawing.SystemColors.Window;
            this.txtInvLotStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtInvLotStatus.Location = new System.Drawing.Point(588, 300);
            this.txtInvLotStatus.Name = "txtInvLotStatus";
            this.txtInvLotStatus.ReadOnly = true;
            this.txtInvLotStatus.Size = new System.Drawing.Size(167, 26);
            this.txtInvLotStatus.TabIndex = 297;
            // 
            // lblInvLotStatus
            // 
            this.lblInvLotStatus.AutoSize = true;
            this.lblInvLotStatus.BackColor = System.Drawing.Color.White;
            this.lblInvLotStatus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblInvLotStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInvLotStatus.ForeColor = System.Drawing.Color.Black;
            this.lblInvLotStatus.Location = new System.Drawing.Point(455, 305);
            this.lblInvLotStatus.Name = "lblInvLotStatus";
            this.lblInvLotStatus.Size = new System.Drawing.Size(100, 16);
            this.lblInvLotStatus.TabIndex = 296;
            this.lblInvLotStatus.Text = "Inv Lot Status";
            this.lblInvLotStatus.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtUnit
            // 
            this.txtUnit.BackColor = System.Drawing.SystemColors.Window;
            this.txtUnit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtUnit.Location = new System.Drawing.Point(588, 240);
            this.txtUnit.Name = "txtUnit";
            this.txtUnit.ReadOnly = true;
            this.txtUnit.Size = new System.Drawing.Size(167, 26);
            this.txtUnit.TabIndex = 295;
            // 
            // lblUnit
            // 
            this.lblUnit.AutoSize = true;
            this.lblUnit.BackColor = System.Drawing.Color.White;
            this.lblUnit.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUnit.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUnit.ForeColor = System.Drawing.Color.Black;
            this.lblUnit.Location = new System.Drawing.Point(454, 245);
            this.lblUnit.Name = "lblUnit";
            this.lblUnit.Size = new System.Drawing.Size(35, 16);
            this.lblUnit.TabIndex = 294;
            this.lblUnit.Text = "Unit";
            this.lblUnit.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtInvLotType
            // 
            this.txtInvLotType.BackColor = System.Drawing.SystemColors.Window;
            this.txtInvLotType.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtInvLotType.Location = new System.Drawing.Point(145, 300);
            this.txtInvLotType.Name = "txtInvLotType";
            this.txtInvLotType.ReadOnly = true;
            this.txtInvLotType.Size = new System.Drawing.Size(167, 26);
            this.txtInvLotType.TabIndex = 293;
            // 
            // lblInvLvlType
            // 
            this.lblInvLvlType.AutoSize = true;
            this.lblInvLvlType.BackColor = System.Drawing.Color.White;
            this.lblInvLvlType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblInvLvlType.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInvLvlType.ForeColor = System.Drawing.Color.Black;
            this.lblInvLvlType.Location = new System.Drawing.Point(11, 305);
            this.lblInvLvlType.Name = "lblInvLvlType";
            this.lblInvLvlType.Size = new System.Drawing.Size(93, 16);
            this.lblInvLvlType.TabIndex = 292;
            this.lblInvLvlType.Text = "Inv Lot Type";
            this.lblInvLvlType.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtQty
            // 
            this.txtQty.BackColor = System.Drawing.SystemColors.Window;
            this.txtQty.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtQty.Location = new System.Drawing.Point(145, 240);
            this.txtQty.Name = "txtQty";
            this.txtQty.ReadOnly = true;
            this.txtQty.Size = new System.Drawing.Size(167, 26);
            this.txtQty.TabIndex = 291;
            // 
            // lblQty
            // 
            this.lblQty.AutoSize = true;
            this.lblQty.BackColor = System.Drawing.Color.White;
            this.lblQty.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblQty.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblQty.ForeColor = System.Drawing.Color.Black;
            this.lblQty.Location = new System.Drawing.Point(11, 245);
            this.lblQty.Name = "lblQty";
            this.lblQty.Size = new System.Drawing.Size(31, 16);
            this.lblQty.TabIndex = 290;
            this.lblQty.Text = "Qty";
            this.lblQty.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtMatDesc
            // 
            this.txtMatDesc.BackColor = System.Drawing.SystemColors.Window;
            this.txtMatDesc.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtMatDesc.Location = new System.Drawing.Point(588, 59);
            this.txtMatDesc.Name = "txtMatDesc";
            this.txtMatDesc.ReadOnly = true;
            this.txtMatDesc.Size = new System.Drawing.Size(167, 26);
            this.txtMatDesc.TabIndex = 289;
            // 
            // lblMatDesc
            // 
            this.lblMatDesc.AutoSize = true;
            this.lblMatDesc.BackColor = System.Drawing.Color.White;
            this.lblMatDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblMatDesc.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblMatDesc.ForeColor = System.Drawing.Color.Black;
            this.lblMatDesc.Location = new System.Drawing.Point(455, 65);
            this.lblMatDesc.Name = "lblMatDesc";
            this.lblMatDesc.Size = new System.Drawing.Size(73, 16);
            this.lblMatDesc.TabIndex = 288;
            this.lblMatDesc.Text = "Mat Desc";
            this.lblMatDesc.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtHoldFlag
            // 
            this.txtHoldFlag.BackColor = System.Drawing.SystemColors.Window;
            this.txtHoldFlag.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtHoldFlag.Location = new System.Drawing.Point(145, 356);
            this.txtHoldFlag.Name = "txtHoldFlag";
            this.txtHoldFlag.ReadOnly = true;
            this.txtHoldFlag.Size = new System.Drawing.Size(167, 26);
            this.txtHoldFlag.TabIndex = 287;
            // 
            // lblHoldFlag
            // 
            this.lblHoldFlag.AutoSize = true;
            this.lblHoldFlag.BackColor = System.Drawing.Color.White;
            this.lblHoldFlag.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHoldFlag.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHoldFlag.ForeColor = System.Drawing.Color.Black;
            this.lblHoldFlag.Location = new System.Drawing.Point(11, 361);
            this.lblHoldFlag.Name = "lblHoldFlag";
            this.lblHoldFlag.Size = new System.Drawing.Size(88, 16);
            this.lblHoldFlag.TabIndex = 286;
            this.lblHoldFlag.Text = "Hold Status";
            this.lblHoldFlag.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtOper
            // 
            this.txtOper.BackColor = System.Drawing.SystemColors.Window;
            this.txtOper.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtOper.Location = new System.Drawing.Point(145, 180);
            this.txtOper.Name = "txtOper";
            this.txtOper.ReadOnly = true;
            this.txtOper.Size = new System.Drawing.Size(167, 26);
            this.txtOper.TabIndex = 285;
            // 
            // lblOper
            // 
            this.lblOper.AutoSize = true;
            this.lblOper.BackColor = System.Drawing.Color.White;
            this.lblOper.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblOper.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOper.ForeColor = System.Drawing.Color.Black;
            this.lblOper.Location = new System.Drawing.Point(11, 185);
            this.lblOper.Name = "lblOper";
            this.lblOper.Size = new System.Drawing.Size(87, 16);
            this.lblOper.TabIndex = 284;
            this.lblOper.Text = "Warehouse";
            this.lblOper.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtMatId
            // 
            this.txtMatId.BackColor = System.Drawing.SystemColors.Window;
            this.txtMatId.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtMatId.Location = new System.Drawing.Point(145, 60);
            this.txtMatId.Name = "txtMatId";
            this.txtMatId.ReadOnly = true;
            this.txtMatId.Size = new System.Drawing.Size(167, 26);
            this.txtMatId.TabIndex = 283;
            // 
            // lblMatId
            // 
            this.lblMatId.AutoSize = true;
            this.lblMatId.BackColor = System.Drawing.Color.White;
            this.lblMatId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblMatId.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblMatId.ForeColor = System.Drawing.Color.Black;
            this.lblMatId.Location = new System.Drawing.Point(11, 65);
            this.lblMatId.Name = "lblMatId";
            this.lblMatId.Size = new System.Drawing.Size(74, 16);
            this.lblMatId.TabIndex = 282;
            this.lblMatId.Text = "Mat Code";
            this.lblMatId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // grpReleaseInfo
            // 
            this.grpReleaseInfo.BorderStyle = Infragistics.Win.Misc.GroupBoxBorderStyle.None;
            appearance1.BackColor = System.Drawing.Color.White;
            appearance1.BackColor2 = System.Drawing.Color.White;
            this.grpReleaseInfo.ContentAreaAppearance = appearance1;
            this.grpReleaseInfo.Controls.Add(this.lblReleaseCode);
            this.grpReleaseInfo.Controls.Add(this.cdvReleaseCode);
            this.grpReleaseInfo.Controls.Add(this.txtTranComment);
            this.grpReleaseInfo.Controls.Add(this.lblTranComment);
            this.grpReleaseInfo.Cursor = System.Windows.Forms.Cursors.Default;
            this.grpReleaseInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpReleaseInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            appearance2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance2.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance2.ForeColor = System.Drawing.Color.White;
            this.grpReleaseInfo.HeaderAppearance = appearance2;
            this.grpReleaseInfo.Location = new System.Drawing.Point(0, 0);
            this.grpReleaseInfo.Margin = new System.Windows.Forms.Padding(5);
            this.grpReleaseInfo.Name = "grpReleaseInfo";
            this.grpReleaseInfo.Size = new System.Drawing.Size(1219, 151);
            this.grpReleaseInfo.TabIndex = 250;
            this.grpReleaseInfo.Text = "Inv Release Info";
            // 
            // lblReleaseCode
            // 
            this.lblReleaseCode.AutoSize = true;
            this.lblReleaseCode.BackColor = System.Drawing.Color.White;
            this.lblReleaseCode.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblReleaseCode.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblReleaseCode.ForeColor = System.Drawing.Color.Black;
            this.lblReleaseCode.Location = new System.Drawing.Point(11, 56);
            this.lblReleaseCode.Name = "lblReleaseCode";
            this.lblReleaseCode.Size = new System.Drawing.Size(132, 16);
            this.lblReleaseCode.TabIndex = 257;
            this.lblReleaseCode.Text = "Inv Release Code";
            this.lblReleaseCode.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cdvReleaseCode
            // 
            this.cdvReleaseCode.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvReleaseCode.BorderHotColor = System.Drawing.Color.Black;
            this.cdvReleaseCode.BtnFlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cdvReleaseCode.BtnToolTipText = "";
            this.cdvReleaseCode.ButtonWidth = 30;
            this.cdvReleaseCode.DescText = "";
            this.cdvReleaseCode.DisplaySubItemIndex = 1;
            this.cdvReleaseCode.DisplayText = "";
            this.cdvReleaseCode.Focusing = null;
            this.cdvReleaseCode.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvReleaseCode.Index = 0;
            this.cdvReleaseCode.IsViewBtnImage = false;
            this.cdvReleaseCode.Location = new System.Drawing.Point(145, 51);
            this.cdvReleaseCode.MaxLength = 100;
            this.cdvReleaseCode.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvReleaseCode.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvReleaseCode.MultiSelect = false;
            this.cdvReleaseCode.Name = "cdvReleaseCode";
            this.cdvReleaseCode.ReadOnly = true;
            this.cdvReleaseCode.SameWidthHeightOfButton = false;
            this.cdvReleaseCode.SearchSubItemIndex = 0;
            this.cdvReleaseCode.SelectedDescIndex = 0;
            this.cdvReleaseCode.SelectedDescToQueryText = "";
            this.cdvReleaseCode.SelectedSubItemIndex = 0;
            this.cdvReleaseCode.SelectedValueToQueryText = "";
            this.cdvReleaseCode.SelectionStart = 0;
            this.cdvReleaseCode.Size = new System.Drawing.Size(167, 26);
            this.cdvReleaseCode.SmallImageList = null;
            this.cdvReleaseCode.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvReleaseCode.TabIndex = 256;
            this.cdvReleaseCode.TextBoxToolTipText = "";
            this.cdvReleaseCode.TextBoxWidth = 167;
            this.cdvReleaseCode.VisibleButton = true;
            this.cdvReleaseCode.VisibleColumnHeader = false;
            this.cdvReleaseCode.VisibleDescription = false;
            this.cdvReleaseCode.ButtonPress += new System.EventHandler(this.cdvReleaseCode_ButtonPress);
            // 
            // txtTranComment
            // 
            this.txtTranComment.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtTranComment.Location = new System.Drawing.Point(145, 103);
            this.txtTranComment.Name = "txtTranComment";
            this.txtTranComment.Size = new System.Drawing.Size(598, 26);
            this.txtTranComment.TabIndex = 255;
            // 
            // lblTranComment
            // 
            this.lblTranComment.AutoSize = true;
            this.lblTranComment.BackColor = System.Drawing.Color.White;
            this.lblTranComment.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTranComment.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTranComment.ForeColor = System.Drawing.Color.Black;
            this.lblTranComment.Location = new System.Drawing.Point(11, 108);
            this.lblTranComment.Name = "lblTranComment";
            this.lblTranComment.Size = new System.Drawing.Size(62, 16);
            this.lblTranComment.TabIndex = 254;
            this.lblTranComment.Text = "Remark";
            this.lblTranComment.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // frmTranReleaseInvLot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmTranReleaseInvLot";
            this.Text = "Release Inventory ";
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.grpInvLotInfo)).EndInit();
            this.grpInvLotInfo.ResumeLayout(false);
            this.grpInvLotInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.grpReleaseInfo)).EndInit();
            this.grpReleaseInfo.ResumeLayout(false);
            this.grpReleaseInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvReleaseCode)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        protected Infragistics.Win.Misc.UltraButton btnProcess;
        public System.Windows.Forms.TextBox txtInvLotID;
        public System.Windows.Forms.Label lblInvLotId;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private Infragistics.Win.Misc.UltraGroupBox grpInvLotInfo;
        private Infragistics.Win.Misc.UltraGroupBox grpReleaseInfo;
        public System.Windows.Forms.Label lblReleaseCode;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvReleaseCode;
        public System.Windows.Forms.TextBox txtTranComment;
        public System.Windows.Forms.Label lblTranComment;
        public System.Windows.Forms.TextBox txtSubAreaId;
        public System.Windows.Forms.Label lblSubAreaId;
        public System.Windows.Forms.TextBox txtAreaId;
        public System.Windows.Forms.Label lblAreaId;
        public System.Windows.Forms.TextBox txtInvLotStatus;
        public System.Windows.Forms.Label lblInvLotStatus;
        public System.Windows.Forms.TextBox txtUnit;
        public System.Windows.Forms.Label lblUnit;
        public System.Windows.Forms.TextBox txtInvLotType;
        public System.Windows.Forms.Label lblInvLvlType;
        public System.Windows.Forms.TextBox txtQty;
        public System.Windows.Forms.Label lblQty;
        public System.Windows.Forms.TextBox txtMatDesc;
        public System.Windows.Forms.Label lblMatDesc;
        public System.Windows.Forms.TextBox txtHoldFlag;
        public System.Windows.Forms.Label lblHoldFlag;
        public System.Windows.Forms.TextBox txtOper;
        public System.Windows.Forms.Label lblOper;
        public System.Windows.Forms.TextBox txtMatId;
        public System.Windows.Forms.Label lblMatId;
        public System.Windows.Forms.TextBox txtOperDesc;
        public System.Windows.Forms.Label lblOperDesc;
    }
}