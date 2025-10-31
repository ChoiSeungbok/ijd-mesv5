namespace CUS_INV
{
    partial class frmTranSplitInvLot
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
            Infragistics.Win.Appearance appearance6 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance7 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance10 = new Infragistics.Win.Appearance();
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
            this.txtOper = new System.Windows.Forms.TextBox();
            this.lblOper = new System.Windows.Forms.Label();
            this.txtMatId = new System.Windows.Forms.TextBox();
            this.lblMatId = new System.Windows.Forms.Label();
            this.lblLastActiveHistSeq = new System.Windows.Forms.Label();
            this.txtLastActiveHistSeq = new System.Windows.Forms.TextBox();
            this.grpHoldInfo = new Infragistics.Win.Misc.UltraGroupBox();
            this.lblOutSpliteLot = new System.Windows.Forms.Label();
            this.txtOutSpliteLot = new System.Windows.Forms.TextBox();
            this.chkDirLot = new System.Windows.Forms.CheckBox();
            this.txtSplitInvLotId = new System.Windows.Forms.TextBox();
            this.lblSplitInvLotId = new System.Windows.Forms.Label();
            this.txtSplitQty = new System.Windows.Forms.TextBox();
            this.lblSplitQty = new System.Windows.Forms.Label();
            this.txtPrintQty = new System.Windows.Forms.TextBox();
            this.lblPrintQty = new System.Windows.Forms.Label();
            this.chkLabel = new System.Windows.Forms.CheckBox();
            this.btnPrint = new Infragistics.Win.Misc.UltraButton();
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
            this.lblFormName.Size = new System.Drawing.Size(135, 30);
            this.lblFormName.Text = "Split Inv Lot";
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(915, 10);
            this.btnView.Visible = false;
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnPrint);
            this.pnlBottom.Controls.Add(this.txtPrintQty);
            this.pnlBottom.Controls.Add(this.lblPrintQty);
            this.pnlBottom.Controls.Add(this.chkLabel);
            this.pnlBottom.Controls.Add(this.btnProcess);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnView, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnProcess, 0);
            this.pnlBottom.Controls.SetChildIndex(this.chkLabel, 0);
            this.pnlBottom.Controls.SetChildIndex(this.lblPrintQty, 0);
            this.pnlBottom.Controls.SetChildIndex(this.txtPrintQty, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnPrint, 0);
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
            this.btnProcess.TabIndex = 251;
            this.btnProcess.Text = "Split";
            this.btnProcess.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnProcess.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnProcess.Click += new System.EventHandler(this.btnProcess_Click);
            // 
            // txtInvLotID
            // 
            this.txtInvLotID.BackColor = System.Drawing.SystemColors.Window;
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
            this.lblInvLotId.Size = new System.Drawing.Size(71, 16);
            this.lblInvLotId.TabIndex = 256;
            this.lblInvLotId.Text = "Inv Lot ID";
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
            this.splitContainer1.Panel2.Controls.Add(this.grpHoldInfo);
            this.splitContainer1.Size = new System.Drawing.Size(1219, 670);
            this.splitContainer1.SplitterDistance = 522;
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
            this.grpInvLotInfo.Controls.Add(this.txtOper);
            this.grpInvLotInfo.Controls.Add(this.lblOper);
            this.grpInvLotInfo.Controls.Add(this.txtMatId);
            this.grpInvLotInfo.Controls.Add(this.lblMatId);
            this.grpInvLotInfo.Controls.Add(this.lblLastActiveHistSeq);
            this.grpInvLotInfo.Controls.Add(this.txtLastActiveHistSeq);
            this.grpInvLotInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpInvLotInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            appearance5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance5.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance5.ForeColor = System.Drawing.Color.White;
            this.grpInvLotInfo.HeaderAppearance = appearance5;
            this.grpInvLotInfo.Location = new System.Drawing.Point(0, 0);
            this.grpInvLotInfo.Margin = new System.Windows.Forms.Padding(5);
            this.grpInvLotInfo.Name = "grpInvLotInfo";
            this.grpInvLotInfo.Size = new System.Drawing.Size(1219, 522);
            this.grpInvLotInfo.TabIndex = 250;
            this.grpInvLotInfo.Text = "Inv Lot Info";
            // 
            // txtOperDesc
            // 
            this.txtOperDesc.BackColor = System.Drawing.SystemColors.Window;
            this.txtOperDesc.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtOperDesc.Location = new System.Drawing.Point(588, 185);
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
            this.lblOperDesc.Location = new System.Drawing.Point(454, 190);
            this.lblOperDesc.Name = "lblOperDesc";
            this.lblOperDesc.Size = new System.Drawing.Size(126, 16);
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
            this.lblSubAreaId.Size = new System.Drawing.Size(83, 16);
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
            this.lblAreaId.Size = new System.Drawing.Size(87, 16);
            this.lblAreaId.TabIndex = 298;
            this.lblAreaId.Text = "Department";
            this.lblAreaId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtInvLotStatus
            // 
            this.txtInvLotStatus.BackColor = System.Drawing.SystemColors.Window;
            this.txtInvLotStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtInvLotStatus.Location = new System.Drawing.Point(588, 299);
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
            this.lblInvLotStatus.Size = new System.Drawing.Size(99, 16);
            this.lblInvLotStatus.TabIndex = 296;
            this.lblInvLotStatus.Text = "Inv Lot Status";
            this.lblInvLotStatus.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtUnit
            // 
            this.txtUnit.BackColor = System.Drawing.SystemColors.Window;
            this.txtUnit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtUnit.Location = new System.Drawing.Point(588, 239);
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
            this.lblUnit.Location = new System.Drawing.Point(454, 244);
            this.lblUnit.Name = "lblUnit";
            this.lblUnit.Size = new System.Drawing.Size(34, 16);
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
            this.lblInvLvlType.Size = new System.Drawing.Size(92, 16);
            this.lblInvLvlType.TabIndex = 292;
            this.lblInvLvlType.Text = "Inv Lot Type";
            this.lblInvLvlType.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtQty
            // 
            this.txtQty.BackColor = System.Drawing.SystemColors.Window;
            this.txtQty.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtQty.Location = new System.Drawing.Point(145, 244);
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
            this.lblQty.Location = new System.Drawing.Point(12, 249);
            this.lblQty.Name = "lblQty";
            this.lblQty.Size = new System.Drawing.Size(30, 16);
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
            this.lblMatDesc.Size = new System.Drawing.Size(72, 16);
            this.lblMatDesc.TabIndex = 288;
            this.lblMatDesc.Text = "Mat Desc";
            this.lblMatDesc.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
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
            this.lblOper.Size = new System.Drawing.Size(86, 16);
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
            this.lblMatId.Size = new System.Drawing.Size(73, 16);
            this.lblMatId.TabIndex = 282;
            this.lblMatId.Text = "Mat Code";
            this.lblMatId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblLastActiveHistSeq
            // 
            this.lblLastActiveHistSeq.AutoSize = true;
            this.lblLastActiveHistSeq.BackColor = System.Drawing.Color.White;
            this.lblLastActiveHistSeq.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastActiveHistSeq.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblLastActiveHistSeq.ForeColor = System.Drawing.Color.Black;
            this.lblLastActiveHistSeq.Location = new System.Drawing.Point(12, 376);
            this.lblLastActiveHistSeq.Name = "lblLastActiveHistSeq";
            this.lblLastActiveHistSeq.Size = new System.Drawing.Size(95, 16);
            this.lblLastActiveHistSeq.TabIndex = 265;
            this.lblLastActiveHistSeq.Text = "Last His Seq";
            this.lblLastActiveHistSeq.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lblLastActiveHistSeq.Visible = false;
            // 
            // txtLastActiveHistSeq
            // 
            this.txtLastActiveHistSeq.BackColor = System.Drawing.SystemColors.Window;
            this.txtLastActiveHistSeq.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtLastActiveHistSeq.Location = new System.Drawing.Point(145, 370);
            this.txtLastActiveHistSeq.Name = "txtLastActiveHistSeq";
            this.txtLastActiveHistSeq.ReadOnly = true;
            this.txtLastActiveHistSeq.Size = new System.Drawing.Size(167, 26);
            this.txtLastActiveHistSeq.TabIndex = 264;
            this.txtLastActiveHistSeq.Visible = false;
            // 
            // grpHoldInfo
            // 
            this.grpHoldInfo.BorderStyle = Infragistics.Win.Misc.GroupBoxBorderStyle.None;
            appearance6.BackColor = System.Drawing.Color.White;
            appearance6.BackColor2 = System.Drawing.Color.White;
            this.grpHoldInfo.ContentAreaAppearance = appearance6;
            this.grpHoldInfo.Controls.Add(this.lblOutSpliteLot);
            this.grpHoldInfo.Controls.Add(this.txtOutSpliteLot);
            this.grpHoldInfo.Controls.Add(this.chkDirLot);
            this.grpHoldInfo.Controls.Add(this.txtSplitInvLotId);
            this.grpHoldInfo.Controls.Add(this.lblSplitInvLotId);
            this.grpHoldInfo.Controls.Add(this.txtSplitQty);
            this.grpHoldInfo.Controls.Add(this.lblSplitQty);
            this.grpHoldInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpHoldInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            appearance7.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance7.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(59)))), ((int)(((byte)(98)))));
            appearance7.ForeColor = System.Drawing.Color.White;
            this.grpHoldInfo.HeaderAppearance = appearance7;
            this.grpHoldInfo.Location = new System.Drawing.Point(0, 0);
            this.grpHoldInfo.Margin = new System.Windows.Forms.Padding(5);
            this.grpHoldInfo.Name = "grpHoldInfo";
            this.grpHoldInfo.Size = new System.Drawing.Size(1219, 144);
            this.grpHoldInfo.TabIndex = 250;
            this.grpHoldInfo.Text = "Split Inv Lot Info";
            // 
            // lblOutSpliteLot
            // 
            this.lblOutSpliteLot.AutoSize = true;
            this.lblOutSpliteLot.BackColor = System.Drawing.Color.White;
            this.lblOutSpliteLot.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblOutSpliteLot.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOutSpliteLot.ForeColor = System.Drawing.Color.Black;
            this.lblOutSpliteLot.Location = new System.Drawing.Point(442, 95);
            this.lblOutSpliteLot.Name = "lblOutSpliteLot";
            this.lblOutSpliteLot.Size = new System.Drawing.Size(113, 16);
            this.lblOutSpliteLot.TabIndex = 314;
            this.lblOutSpliteLot.Text = "splite complete";
            this.lblOutSpliteLot.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtOutSpliteLot
            // 
            this.txtOutSpliteLot.BackColor = System.Drawing.SystemColors.Control;
            this.txtOutSpliteLot.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtOutSpliteLot.Location = new System.Drawing.Point(576, 89);
            this.txtOutSpliteLot.Name = "txtOutSpliteLot";
            this.txtOutSpliteLot.ReadOnly = true;
            this.txtOutSpliteLot.Size = new System.Drawing.Size(221, 26);
            this.txtOutSpliteLot.TabIndex = 313;
            this.txtOutSpliteLot.DoubleClick += new System.EventHandler(this.txtOutSpliteLot_DoubleClick);
            // 
            // chkDirLot
            // 
            this.chkDirLot.AutoSize = true;
            this.chkDirLot.BackColor = System.Drawing.Color.White;
            this.chkDirLot.Cursor = System.Windows.Forms.Cursors.Default;
            this.chkDirLot.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkDirLot.Location = new System.Drawing.Point(803, 58);
            this.chkDirLot.Name = "chkDirLot";
            this.chkDirLot.Size = new System.Drawing.Size(130, 19);
            this.chkDirLot.TabIndex = 312;
            this.chkDirLot.Text = "LOT Direct input";
            this.chkDirLot.UseVisualStyleBackColor = false;
            this.chkDirLot.CheckedChanged += new System.EventHandler(this.chkDirLot_CheckedChanged);
            // 
            // txtSplitInvLotId
            // 
            this.txtSplitInvLotId.BackColor = System.Drawing.SystemColors.Control;
            this.txtSplitInvLotId.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtSplitInvLotId.Location = new System.Drawing.Point(576, 53);
            this.txtSplitInvLotId.Name = "txtSplitInvLotId";
            this.txtSplitInvLotId.ReadOnly = true;
            this.txtSplitInvLotId.Size = new System.Drawing.Size(221, 26);
            this.txtSplitInvLotId.TabIndex = 259;
            // 
            // lblSplitInvLotId
            // 
            this.lblSplitInvLotId.AutoSize = true;
            this.lblSplitInvLotId.BackColor = System.Drawing.Color.White;
            this.lblSplitInvLotId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSplitInvLotId.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSplitInvLotId.ForeColor = System.Drawing.Color.Black;
            this.lblSplitInvLotId.Location = new System.Drawing.Point(442, 58);
            this.lblSplitInvLotId.Name = "lblSplitInvLotId";
            this.lblSplitInvLotId.Size = new System.Drawing.Size(106, 16);
            this.lblSplitInvLotId.TabIndex = 258;
            this.lblSplitInvLotId.Text = "Split Inv Lot ID";
            this.lblSplitInvLotId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtSplitQty
            // 
            this.txtSplitQty.BackColor = System.Drawing.SystemColors.Window;
            this.txtSplitQty.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtSplitQty.Location = new System.Drawing.Point(145, 53);
            this.txtSplitQty.Name = "txtSplitQty";
            this.txtSplitQty.Size = new System.Drawing.Size(167, 26);
            this.txtSplitQty.TabIndex = 257;
            this.txtSplitQty.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtSplitQty_KeyPress);
            // 
            // lblSplitQty
            // 
            this.lblSplitQty.AutoSize = true;
            this.lblSplitQty.BackColor = System.Drawing.Color.White;
            this.lblSplitQty.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSplitQty.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSplitQty.ForeColor = System.Drawing.Color.Black;
            this.lblSplitQty.Location = new System.Drawing.Point(11, 58);
            this.lblSplitQty.Name = "lblSplitQty";
            this.lblSplitQty.Size = new System.Drawing.Size(65, 16);
            this.lblSplitQty.TabIndex = 256;
            this.lblSplitQty.Text = "Split Qty";
            this.lblSplitQty.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtPrintQty
            // 
            this.txtPrintQty.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtPrintQty.Location = new System.Drawing.Point(191, 12);
            this.txtPrintQty.Name = "txtPrintQty";
            this.txtPrintQty.Size = new System.Drawing.Size(80, 26);
            this.txtPrintQty.TabIndex = 259;
            this.txtPrintQty.Visible = false;
            // 
            // lblPrintQty
            // 
            this.lblPrintQty.AutoSize = true;
            this.lblPrintQty.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(232)))), ((int)(((byte)(244)))));
            this.lblPrintQty.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblPrintQty.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.lblPrintQty.ForeColor = System.Drawing.Color.Black;
            this.lblPrintQty.Location = new System.Drawing.Point(123, 17);
            this.lblPrintQty.Name = "lblPrintQty";
            this.lblPrintQty.Size = new System.Drawing.Size(56, 16);
            this.lblPrintQty.TabIndex = 258;
            this.lblPrintQty.Text = "Print Qty";
            this.lblPrintQty.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lblPrintQty.Visible = false;
            // 
            // chkLabel
            // 
            this.chkLabel.AutoSize = true;
            this.chkLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.chkLabel.Location = new System.Drawing.Point(19, 15);
            this.chkLabel.Name = "chkLabel";
            this.chkLabel.Size = new System.Drawing.Size(89, 20);
            this.chkLabel.TabIndex = 257;
            this.chkLabel.Text = "Label Print";
            this.chkLabel.UseVisualStyleBackColor = true;
            this.chkLabel.Visible = false;
            // 
            // btnPrint
            // 
            appearance10.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance10.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance10.FontData.BoldAsString = "True";
            appearance10.ForeColor = System.Drawing.Color.White;
            this.btnPrint.Appearance = appearance10;
            this.btnPrint.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPrint.Location = new System.Drawing.Point(915, 10);
            this.btnPrint.Name = "btnPrint";
            this.btnPrint.Size = new System.Drawing.Size(100, 30);
            this.btnPrint.TabIndex = 264;
            this.btnPrint.Text = "Print";
            this.btnPrint.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnPrint.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnPrint.Click += new System.EventHandler(this.btnPrint_Click);
            // 
            // frmTranSplitInvLot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmTranSplitInvLot";
            this.Text = "Split Inv Lot";
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.pnlBottom.PerformLayout();
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
            this.ResumeLayout(false);

        }

        #endregion

        protected Infragistics.Win.Misc.UltraButton btnProcess;
        public System.Windows.Forms.TextBox txtInvLotID;
        public System.Windows.Forms.Label lblInvLotId;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private Infragistics.Win.Misc.UltraGroupBox grpHoldInfo;
        private Infragistics.Win.Misc.UltraGroupBox grpInvLotInfo;
        public System.Windows.Forms.TextBox txtSplitInvLotId;
        public System.Windows.Forms.Label lblSplitInvLotId;
        public System.Windows.Forms.TextBox txtSplitQty;
        public System.Windows.Forms.Label lblSplitQty;
        private System.Windows.Forms.TextBox txtPrintQty;
        public System.Windows.Forms.Label lblPrintQty;
        private System.Windows.Forms.CheckBox chkLabel;
        public System.Windows.Forms.TextBox txtLastActiveHistSeq;
        public System.Windows.Forms.Label lblLastActiveHistSeq;
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
        public System.Windows.Forms.TextBox txtOper;
        public System.Windows.Forms.Label lblOper;
        public System.Windows.Forms.TextBox txtMatId;
        public System.Windows.Forms.Label lblMatId;
        public System.Windows.Forms.TextBox txtOperDesc;
        public System.Windows.Forms.Label lblOperDesc;
        protected Infragistics.Win.Misc.UltraButton btnPrint;
        private System.Windows.Forms.CheckBox chkDirLot;
        public System.Windows.Forms.Label lblOutSpliteLot;
        public System.Windows.Forms.TextBox txtOutSpliteLot;
    }
}