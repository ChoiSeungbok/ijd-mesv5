namespace CUS_INV
{
    partial class frmTranHoldInvLot
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
            this.grpHoldInfo = new Infragistics.Win.Misc.UltraGroupBox();
            this.lblHoldCode = new System.Windows.Forms.Label();
            this.cdvHoldCode = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.txtTranComment = new System.Windows.Forms.TextBox();
            this.lblTranComment = new System.Windows.Forms.Label();
            this.txtInvLotID = new System.Windows.Forms.TextBox();
            this.lblInvLotId = new System.Windows.Forms.Label();
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
            ((System.ComponentModel.ISupportInitialize)(this.grpHoldInfo)).BeginInit();
            this.grpHoldInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvHoldCode)).BeginInit();
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
            this.lblFormName.Size = new System.Drawing.Size(171, 30);
            this.lblFormName.Text = "Hold Inventory ";
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(915, 10);
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
            this.btnProcess.Location = new System.Drawing.Point(1021, 10);
            this.btnProcess.Name = "btnProcess";
            this.btnProcess.Size = new System.Drawing.Size(100, 30);
            this.btnProcess.TabIndex = 250;
            this.btnProcess.Text = "Hold";
            this.btnProcess.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnProcess.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnProcess.Click += new System.EventHandler(this.btnProcess_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.splitContainer1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(10, 120);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1219, 670);
            this.panel1.TabIndex = 48;
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
            this.splitContainer1.Panel2.Controls.Add(this.grpHoldInfo);
            this.splitContainer1.Size = new System.Drawing.Size(1219, 670);
            this.splitContainer1.SplitterDistance = 516;
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
            this.grpInvLotInfo.Size = new System.Drawing.Size(1219, 516);
            this.grpInvLotInfo.TabIndex = 250;
            this.grpInvLotInfo.Text = "Inv Lot Info";
            // 
            // txtOperDesc
            // 
            this.txtOperDesc.BackColor = System.Drawing.SystemColors.Window;
            this.txtOperDesc.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtOperDesc.Location = new System.Drawing.Point(588, 180);
            this.txtOperDesc.Name = "txtOperDesc";
            this.txtOperDesc.ReadOnly = true;
            this.txtOperDesc.Size = new System.Drawing.Size(167, 26);
            this.txtOperDesc.TabIndex = 283;
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
            this.lblOperDesc.Size = new System.Drawing.Size(126, 16);
            this.lblOperDesc.TabIndex = 282;
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
            this.txtSubAreaId.TabIndex = 281;
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
            this.lblSubAreaId.Size = new System.Drawing.Size(83, 16);
            this.lblSubAreaId.TabIndex = 280;
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
            this.txtAreaId.TabIndex = 279;
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
            this.lblAreaId.Size = new System.Drawing.Size(87, 16);
            this.lblAreaId.TabIndex = 278;
            this.lblAreaId.Text = "Department";
            this.lblAreaId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtInvLotStatus
            // 
            this.txtInvLotStatus.BackColor = System.Drawing.SystemColors.Window;
            this.txtInvLotStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtInvLotStatus.Location = new System.Drawing.Point(144, 350);
            this.txtInvLotStatus.Name = "txtInvLotStatus";
            this.txtInvLotStatus.ReadOnly = true;
            this.txtInvLotStatus.Size = new System.Drawing.Size(167, 26);
            this.txtInvLotStatus.TabIndex = 273;
            // 
            // lblInvLotStatus
            // 
            this.lblInvLotStatus.AutoSize = true;
            this.lblInvLotStatus.BackColor = System.Drawing.Color.White;
            this.lblInvLotStatus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblInvLotStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInvLotStatus.ForeColor = System.Drawing.Color.Black;
            this.lblInvLotStatus.Location = new System.Drawing.Point(11, 356);
            this.lblInvLotStatus.Name = "lblInvLotStatus";
            this.lblInvLotStatus.Size = new System.Drawing.Size(99, 16);
            this.lblInvLotStatus.TabIndex = 272;
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
            this.txtUnit.TabIndex = 269;
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
            this.lblUnit.Size = new System.Drawing.Size(34, 16);
            this.lblUnit.TabIndex = 268;
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
            this.txtInvLotType.TabIndex = 267;
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
            this.lblInvLvlType.Size = new System.Drawing.Size(92, 16);
            this.lblInvLvlType.TabIndex = 266;
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
            this.txtQty.TabIndex = 263;
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
            this.lblQty.Size = new System.Drawing.Size(30, 16);
            this.lblQty.TabIndex = 262;
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
            this.txtMatDesc.TabIndex = 261;
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
            this.lblMatDesc.Size = new System.Drawing.Size(72, 16);
            this.lblMatDesc.TabIndex = 260;
            this.lblMatDesc.Text = "Mat Desc";
            this.lblMatDesc.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtHoldFlag
            // 
            this.txtHoldFlag.BackColor = System.Drawing.SystemColors.Window;
            this.txtHoldFlag.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtHoldFlag.Location = new System.Drawing.Point(588, 300);
            this.txtHoldFlag.Name = "txtHoldFlag";
            this.txtHoldFlag.ReadOnly = true;
            this.txtHoldFlag.Size = new System.Drawing.Size(167, 26);
            this.txtHoldFlag.TabIndex = 259;
            // 
            // lblHoldFlag
            // 
            this.lblHoldFlag.AutoSize = true;
            this.lblHoldFlag.BackColor = System.Drawing.Color.White;
            this.lblHoldFlag.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHoldFlag.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHoldFlag.ForeColor = System.Drawing.Color.Black;
            this.lblHoldFlag.Location = new System.Drawing.Point(454, 305);
            this.lblHoldFlag.Name = "lblHoldFlag";
            this.lblHoldFlag.Size = new System.Drawing.Size(87, 16);
            this.lblHoldFlag.TabIndex = 258;
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
            this.txtOper.TabIndex = 257;
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
            this.lblOper.Size = new System.Drawing.Size(86, 16);
            this.lblOper.TabIndex = 256;
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
            this.txtMatId.TabIndex = 255;
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
            this.lblMatId.Size = new System.Drawing.Size(73, 16);
            this.lblMatId.TabIndex = 254;
            this.lblMatId.Text = "Mat Code";
            this.lblMatId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // grpHoldInfo
            // 
            this.grpHoldInfo.BorderStyle = Infragistics.Win.Misc.GroupBoxBorderStyle.None;
            appearance1.BackColor = System.Drawing.Color.White;
            appearance1.BackColor2 = System.Drawing.Color.White;
            this.grpHoldInfo.ContentAreaAppearance = appearance1;
            this.grpHoldInfo.Controls.Add(this.lblHoldCode);
            this.grpHoldInfo.Controls.Add(this.cdvHoldCode);
            this.grpHoldInfo.Controls.Add(this.txtTranComment);
            this.grpHoldInfo.Controls.Add(this.lblTranComment);
            this.grpHoldInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpHoldInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            appearance2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance2.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance2.ForeColor = System.Drawing.Color.White;
            this.grpHoldInfo.HeaderAppearance = appearance2;
            this.grpHoldInfo.Location = new System.Drawing.Point(0, 0);
            this.grpHoldInfo.Margin = new System.Windows.Forms.Padding(5);
            this.grpHoldInfo.Name = "grpHoldInfo";
            this.grpHoldInfo.Size = new System.Drawing.Size(1219, 150);
            this.grpHoldInfo.TabIndex = 250;
            this.grpHoldInfo.Text = "Inv Hold Info";
            // 
            // lblHoldCode
            // 
            this.lblHoldCode.AutoSize = true;
            this.lblHoldCode.BackColor = System.Drawing.Color.White;
            this.lblHoldCode.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHoldCode.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHoldCode.ForeColor = System.Drawing.Color.Black;
            this.lblHoldCode.Location = new System.Drawing.Point(11, 56);
            this.lblHoldCode.Name = "lblHoldCode";
            this.lblHoldCode.Size = new System.Drawing.Size(105, 16);
            this.lblHoldCode.TabIndex = 257;
            this.lblHoldCode.Text = "Inv Hold Code";
            this.lblHoldCode.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // cdvHoldCode
            // 
            this.cdvHoldCode.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvHoldCode.BorderHotColor = System.Drawing.Color.Black;
            this.cdvHoldCode.BtnFlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cdvHoldCode.BtnToolTipText = "";
            this.cdvHoldCode.ButtonWidth = 30;
            this.cdvHoldCode.DescText = "";
            this.cdvHoldCode.DisplaySubItemIndex = 1;
            this.cdvHoldCode.DisplayText = "";
            this.cdvHoldCode.Focusing = null;
            this.cdvHoldCode.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvHoldCode.Index = 0;
            this.cdvHoldCode.IsViewBtnImage = false;
            this.cdvHoldCode.Location = new System.Drawing.Point(145, 51);
            this.cdvHoldCode.MaxLength = 100;
            this.cdvHoldCode.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvHoldCode.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvHoldCode.MultiSelect = false;
            this.cdvHoldCode.Name = "cdvHoldCode";
            this.cdvHoldCode.ReadOnly = true;
            this.cdvHoldCode.SameWidthHeightOfButton = false;
            this.cdvHoldCode.SearchSubItemIndex = 0;
            this.cdvHoldCode.SelectedDescIndex = 0;
            this.cdvHoldCode.SelectedDescToQueryText = "";
            this.cdvHoldCode.SelectedSubItemIndex = 0;
            this.cdvHoldCode.SelectedValueToQueryText = "";
            this.cdvHoldCode.SelectionStart = 0;
            this.cdvHoldCode.Size = new System.Drawing.Size(167, 26);
            this.cdvHoldCode.SmallImageList = null;
            this.cdvHoldCode.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvHoldCode.TabIndex = 256;
            this.cdvHoldCode.TextBoxToolTipText = "";
            this.cdvHoldCode.TextBoxWidth = 167;
            this.cdvHoldCode.VisibleButton = true;
            this.cdvHoldCode.VisibleColumnHeader = false;
            this.cdvHoldCode.VisibleDescription = false;
            this.cdvHoldCode.ButtonPress += new System.EventHandler(this.cdvHoldCode_ButtonPress);
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
            this.lblTranComment.Size = new System.Drawing.Size(61, 16);
            this.lblTranComment.TabIndex = 254;
            this.lblTranComment.Text = "Remark";
            this.lblTranComment.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtInvLotID
            // 
            this.txtInvLotID.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtInvLotID.Location = new System.Drawing.Point(145, 18);
            this.txtInvLotID.Name = "txtInvLotID";
            this.txtInvLotID.Size = new System.Drawing.Size(167, 26);
            this.txtInvLotID.TabIndex = 255;
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
            this.lblInvLotId.Size = new System.Drawing.Size(71, 16);
            this.lblInvLotId.TabIndex = 254;
            this.lblInvLotId.Text = "Inv Lot ID";
            this.lblInvLotId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // frmTranHoldInvLot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmTranHoldInvLot";
            this.Text = "Hold Inventory ";
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
            ((System.ComponentModel.ISupportInitialize)(this.grpHoldInfo)).EndInit();
            this.grpHoldInfo.ResumeLayout(false);
            this.grpHoldInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvHoldCode)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        protected Infragistics.Win.Misc.UltraButton btnProcess;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        public System.Windows.Forms.TextBox txtInvLotID;
        public System.Windows.Forms.Label lblInvLotId;
        private Infragistics.Win.Misc.UltraGroupBox grpInvLotInfo;
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
        private Infragistics.Win.Misc.UltraGroupBox grpHoldInfo;
        public System.Windows.Forms.Label lblHoldCode;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvHoldCode;
        public System.Windows.Forms.TextBox txtTranComment;
        public System.Windows.Forms.Label lblTranComment;
        public System.Windows.Forms.TextBox txtInvLotStatus;
        public System.Windows.Forms.Label lblInvLotStatus;
        public System.Windows.Forms.TextBox txtUnit;
        public System.Windows.Forms.Label lblUnit;
        public System.Windows.Forms.TextBox txtInvLotType;
        public System.Windows.Forms.Label lblInvLvlType;
        public System.Windows.Forms.TextBox txtSubAreaId;
        public System.Windows.Forms.Label lblSubAreaId;
        public System.Windows.Forms.TextBox txtAreaId;
        public System.Windows.Forms.Label lblAreaId;
        public System.Windows.Forms.TextBox txtOperDesc;
        public System.Windows.Forms.Label lblOperDesc;
    }
}