#define _SPCTYPE
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Infragistics.Win.UltraWinEditors;
//using FMBUI.Enums;
//using FMBUI.Controls;
using Miracom.CliFrx;
using Miracom.TRSCore;
using Miracom.MESCore;
using Miracom.MsgHandler;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBCreateTool.vb
//   Description : Create/Update/Delete Resource Location
//
//   FMB Version : 1.0.0
//
//   Function List
//       - init() : Initialize Controls
//       - Set_ReadOnly() : Set Controls ReadOnly
//       - CheckCondition() : Check the conditions before transaction
//       - View_LayOut() : View Layout Information
//       - View_UDR_Group() : View User Define Resource Group Information
//       - Update_Resource_Location() : Create/Update/Delete Resource Location
//       - ViewResourceList() : View Resource List
//       - View_Resource() : View Resource Information
//       - ViewUDRResourceList() : View User Define Resource List
//       - View_UDR_Resource() : View User Define Resource Information
//       - Update_UDR_ResLoc() : Create/Update/Delete User Define Resource Information
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-02 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public class frmFMBCreateTool : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBCreateTool()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        public frmFMBCreateTool(char sProcStep)
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            ProcStep = sProcStep;
            
        }
        
        //Form? Dispose瑜??ъ젙?섑븯??援ъ꽦 ?붿냼 紐⑸줉???뺣━?⑸땲??
        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                if (!(components == null))
                {
                    components.Dispose();
                }
            }
            base.Dispose(disposing);
        }
        
        //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        private System.ComponentModel.Container components = null;
        
        //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
        //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.GroupBox grpInfo;
        internal UltraTextEditor txtY;
        internal System.Windows.Forms.Label lblY;
        internal UltraTextEditor txtHeight;
        internal System.Windows.Forms.Label lblHeight;
        internal UltraTextEditor txtWidth;
        internal UltraTextEditor txtX;
        internal System.Windows.Forms.Label lblWidth;
        internal System.Windows.Forms.Label lblX;
        internal System.Windows.Forms.Label lblBackColor;
        internal UltraComboEditor cboTextStyle;
        internal System.Windows.Forms.Label lblStyle;
        internal System.Windows.Forms.Label lblColor;
        internal UltraComboEditor cboSize;
        internal UltraTextEditor txtText;
        internal System.Windows.Forms.Label txtSize;
        internal System.Windows.Forms.Label lblText;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Button btnCreate;
        internal System.Windows.Forms.Label lblLayOut;
        internal System.Windows.Forms.Label lblFactory;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcText;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBack;
        internal System.Windows.Forms.Label lblImage;
        internal System.Windows.Forms.PictureBox pctImage;
        public Infragistics.Win.UltraWinEditors.UltraTextEditor txtFactory;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvLayOut;
        internal System.Windows.Forms.Label lblResTagFlag;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtResTagFlag;
        private GroupBox grpSubRes;
        internal Label lblToolID;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvToolID;
        internal UltraTextEditor txtToolDesc;
        internal Label lblToolDesc;
        public TextBox txtToolType;
        private Label lblToolType;
        internal UltraTextEditor txtToolLoc;
        internal Label lblToolLoc;
        internal UltraTextEditor txtDeleteFlag;
        internal Label lblDeleteFlag;
        internal Label lblToolEvent;
        internal UltraTextEditor txtLastToolEvent;
        internal UltraTextEditor txtToolStatus;
        internal Label lblToolStatus;
        internal Label lblLastTranTime;
        internal UltraTextEditor txtLastTranTime;
        internal UltraTextEditor txtToolSetLoc;
        internal Label lblToolSetLoc;
        internal Label lblToolSetID;
        internal UltraTextEditor txtToolSetID;
        internal Label lblCreateUser;
        public  TextBox txtCreateUser;
        internal UltraTextEditor txtUpdateUser;
        internal Label lblUpdateUser;
        internal Label lblUpdateTime;
        internal UltraTextEditor txtUpdateTime;
        internal Label lblCreateTime;
        public TextBox txtCreateTime;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnCreate = new System.Windows.Forms.Button();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpSubRes = new System.Windows.Forms.GroupBox();
            this.lblCreateTime = new System.Windows.Forms.Label();
            this.txtCreateTime = new System.Windows.Forms.TextBox();
            this.txtUpdateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblUpdateUser = new System.Windows.Forms.Label();
            this.lblUpdateTime = new System.Windows.Forms.Label();
            this.txtUpdateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCreateUser = new System.Windows.Forms.Label();
            this.txtCreateUser = new System.Windows.Forms.TextBox();
            this.lblToolSetID = new System.Windows.Forms.Label();
            this.txtToolSetID = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtToolLoc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblToolLoc = new System.Windows.Forms.Label();
            this.txtDeleteFlag = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblDeleteFlag = new System.Windows.Forms.Label();
            this.lblToolEvent = new System.Windows.Forms.Label();
            this.txtLastToolEvent = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtToolStatus = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblToolStatus = new System.Windows.Forms.Label();
            this.lblLastTranTime = new System.Windows.Forms.Label();
            this.txtLastTranTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtToolSetLoc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblToolSetLoc = new System.Windows.Forms.Label();
            this.txtToolType = new System.Windows.Forms.TextBox();
            this.lblToolType = new System.Windows.Forms.Label();
            this.txtToolDesc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblToolDesc = new System.Windows.Forms.Label();
            this.lblToolID = new System.Windows.Forms.Label();
            this.cdvToolID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.grpInfo = new System.Windows.Forms.GroupBox();
            this.pctImage = new System.Windows.Forms.PictureBox();
            this.lblImage = new System.Windows.Forms.Label();
            this.utcBack = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.utcText = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.cdvLayOut = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.txtFactory = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblFactory = new System.Windows.Forms.Label();
            this.lblLayOut = new System.Windows.Forms.Label();
            this.txtY = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblY = new System.Windows.Forms.Label();
            this.txtHeight = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblHeight = new System.Windows.Forms.Label();
            this.txtWidth = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtX = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblWidth = new System.Windows.Forms.Label();
            this.lblX = new System.Windows.Forms.Label();
            this.lblResTagFlag = new System.Windows.Forms.Label();
            this.txtResTagFlag = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblBackColor = new System.Windows.Forms.Label();
            this.cboTextStyle = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.lblStyle = new System.Windows.Forms.Label();
            this.lblColor = new System.Windows.Forms.Label();
            this.cboSize = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.txtText = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSize = new System.Windows.Forms.Label();
            this.lblText = new System.Windows.Forms.Label();
            this.pnlBottom.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.grpSubRes.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolSetID)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolLoc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDeleteFlag)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastToolEvent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolStatus)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastTranTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolSetLoc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolDesc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvToolID)).BeginInit();
            this.grpInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pctImage)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBack)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcText)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvLayOut)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtFactory)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtResTagFlag)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboTextStyle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtText)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Controls.Add(this.btnCreate);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 434);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(457, 37);
            this.pnlBottom.TabIndex = 3;
            // 
            // btnClose
            // 
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Location = new System.Drawing.Point(374, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnCreate
            // 
            this.btnCreate.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnCreate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnCreate.Location = new System.Drawing.Point(294, 9);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(74, 23);
            this.btnCreate.TabIndex = 0;
            this.btnCreate.Text = "Create";
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.grpSubRes);
            this.pnlMid.Controls.Add(this.grpInfo);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(457, 434);
            this.pnlMid.TabIndex = 1;
            // 
            // grpSubRes
            // 
            this.grpSubRes.Controls.Add(this.lblCreateTime);
            this.grpSubRes.Controls.Add(this.txtCreateTime);
            this.grpSubRes.Controls.Add(this.txtUpdateUser);
            this.grpSubRes.Controls.Add(this.lblUpdateUser);
            this.grpSubRes.Controls.Add(this.lblUpdateTime);
            this.grpSubRes.Controls.Add(this.txtUpdateTime);
            this.grpSubRes.Controls.Add(this.lblCreateUser);
            this.grpSubRes.Controls.Add(this.txtCreateUser);
            this.grpSubRes.Controls.Add(this.lblToolSetID);
            this.grpSubRes.Controls.Add(this.txtToolSetID);
            this.grpSubRes.Controls.Add(this.txtToolLoc);
            this.grpSubRes.Controls.Add(this.lblToolLoc);
            this.grpSubRes.Controls.Add(this.txtDeleteFlag);
            this.grpSubRes.Controls.Add(this.lblDeleteFlag);
            this.grpSubRes.Controls.Add(this.lblToolEvent);
            this.grpSubRes.Controls.Add(this.txtLastToolEvent);
            this.grpSubRes.Controls.Add(this.txtToolStatus);
            this.grpSubRes.Controls.Add(this.lblToolStatus);
            this.grpSubRes.Controls.Add(this.lblLastTranTime);
            this.grpSubRes.Controls.Add(this.txtLastTranTime);
            this.grpSubRes.Controls.Add(this.txtToolSetLoc);
            this.grpSubRes.Controls.Add(this.lblToolSetLoc);
            this.grpSubRes.Controls.Add(this.txtToolType);
            this.grpSubRes.Controls.Add(this.lblToolType);
            this.grpSubRes.Controls.Add(this.txtToolDesc);
            this.grpSubRes.Controls.Add(this.lblToolDesc);
            this.grpSubRes.Controls.Add(this.lblToolID);
            this.grpSubRes.Controls.Add(this.cdvToolID);
            this.grpSubRes.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpSubRes.Location = new System.Drawing.Point(3, 0);
            this.grpSubRes.Name = "grpSubRes";
            this.grpSubRes.Size = new System.Drawing.Size(451, 224);
            this.grpSubRes.TabIndex = 2;
            this.grpSubRes.TabStop = false;
            // 
            // lblCreateTime
            // 
            this.lblCreateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateTime.Location = new System.Drawing.Point(239, 170);
            this.lblCreateTime.Name = "lblCreateTime";
            this.lblCreateTime.Size = new System.Drawing.Size(74, 14);
            this.lblCreateTime.TabIndex = 106;
            this.lblCreateTime.Text = "Create Time";
            // 
            // txtCreateTime
            // 
            this.txtCreateTime.Location = new System.Drawing.Point(323, 166);
            this.txtCreateTime.Name = "txtCreateTime";
            this.txtCreateTime.ReadOnly = true;
            this.txtCreateTime.Size = new System.Drawing.Size(120, 20);
            this.txtCreateTime.TabIndex = 105;
            // 
            // txtUpdateUser
            // 
            this.txtUpdateUser.Location = new System.Drawing.Point(104, 191);
            this.txtUpdateUser.MaxLength = 20;
            this.txtUpdateUser.Name = "txtUpdateUser";
            this.txtUpdateUser.ReadOnly = true;
            this.txtUpdateUser.Size = new System.Drawing.Size(120, 19);
            this.txtUpdateUser.TabIndex = 101;
            this.txtUpdateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblUpdateUser
            // 
            this.lblUpdateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateUser.Location = new System.Drawing.Point(10, 193);
            this.lblUpdateUser.Name = "lblUpdateUser";
            this.lblUpdateUser.Size = new System.Drawing.Size(88, 14);
            this.lblUpdateUser.TabIndex = 104;
            this.lblUpdateUser.Text = "Update User";
            // 
            // lblUpdateTime
            // 
            this.lblUpdateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateTime.Location = new System.Drawing.Point(239, 194);
            this.lblUpdateTime.Name = "lblUpdateTime";
            this.lblUpdateTime.Size = new System.Drawing.Size(74, 14);
            this.lblUpdateTime.TabIndex = 103;
            this.lblUpdateTime.Text = "Update Time";
            // 
            // txtUpdateTime
            // 
            this.txtUpdateTime.Location = new System.Drawing.Point(323, 193);
            this.txtUpdateTime.MaxLength = 20;
            this.txtUpdateTime.Name = "txtUpdateTime";
            this.txtUpdateTime.ReadOnly = true;
            this.txtUpdateTime.Size = new System.Drawing.Size(120, 19);
            this.txtUpdateTime.TabIndex = 102;
            this.txtUpdateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCreateUser
            // 
            this.lblCreateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateUser.Location = new System.Drawing.Point(10, 168);
            this.lblCreateUser.Name = "lblCreateUser";
            this.lblCreateUser.Size = new System.Drawing.Size(88, 14);
            this.lblCreateUser.TabIndex = 100;
            this.lblCreateUser.Text = "Create User";
            // 
            // txtCreateUser
            // 
            this.txtCreateUser.Location = new System.Drawing.Point(104, 165);
            this.txtCreateUser.Name = "txtCreateUser";
            this.txtCreateUser.ReadOnly = true;
            this.txtCreateUser.Size = new System.Drawing.Size(120, 20);
            this.txtCreateUser.TabIndex = 99;
            // 
            // lblToolSetID
            // 
            this.lblToolSetID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToolSetID.Location = new System.Drawing.Point(239, 69);
            this.lblToolSetID.Name = "lblToolSetID";
            this.lblToolSetID.Size = new System.Drawing.Size(65, 14);
            this.lblToolSetID.TabIndex = 98;
            this.lblToolSetID.Text = "Tool Set ID";
            // 
            // txtToolSetID
            // 
            this.txtToolSetID.Location = new System.Drawing.Point(323, 66);
            this.txtToolSetID.MaxLength = 5;
            this.txtToolSetID.Name = "txtToolSetID";
            this.txtToolSetID.ReadOnly = true;
            this.txtToolSetID.Size = new System.Drawing.Size(120, 19);
            this.txtToolSetID.TabIndex = 97;
            this.txtToolSetID.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtToolLoc
            // 
            this.txtToolLoc.Location = new System.Drawing.Point(323, 92);
            this.txtToolLoc.MaxLength = 10;
            this.txtToolLoc.Name = "txtToolLoc";
            this.txtToolLoc.ReadOnly = true;
            this.txtToolLoc.Size = new System.Drawing.Size(120, 19);
            this.txtToolLoc.TabIndex = 82;
            this.txtToolLoc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblToolLoc
            // 
            this.lblToolLoc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToolLoc.Location = new System.Drawing.Point(239, 93);
            this.lblToolLoc.Name = "lblToolLoc";
            this.lblToolLoc.Size = new System.Drawing.Size(74, 14);
            this.lblToolLoc.TabIndex = 92;
            this.lblToolLoc.Text = "Tool Location";
            // 
            // txtDeleteFlag
            // 
            this.txtDeleteFlag.Location = new System.Drawing.Point(104, 140);
            this.txtDeleteFlag.MaxLength = 20;
            this.txtDeleteFlag.Name = "txtDeleteFlag";
            this.txtDeleteFlag.ReadOnly = true;
            this.txtDeleteFlag.Size = new System.Drawing.Size(120, 19);
            this.txtDeleteFlag.TabIndex = 85;
            this.txtDeleteFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblDeleteFlag
            // 
            this.lblDeleteFlag.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDeleteFlag.Location = new System.Drawing.Point(10, 143);
            this.lblDeleteFlag.Name = "lblDeleteFlag";
            this.lblDeleteFlag.Size = new System.Drawing.Size(88, 14);
            this.lblDeleteFlag.TabIndex = 91;
            this.lblDeleteFlag.Text = "Delete Flag";
            // 
            // lblToolEvent
            // 
            this.lblToolEvent.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToolEvent.Location = new System.Drawing.Point(239, 120);
            this.lblToolEvent.Name = "lblToolEvent";
            this.lblToolEvent.Size = new System.Drawing.Size(80, 14);
            this.lblToolEvent.TabIndex = 90;
            this.lblToolEvent.Text = "Last Tool Event";
            // 
            // txtLastToolEvent
            // 
            this.txtLastToolEvent.Location = new System.Drawing.Point(323, 119);
            this.txtLastToolEvent.MaxLength = 20;
            this.txtLastToolEvent.Name = "txtLastToolEvent";
            this.txtLastToolEvent.ReadOnly = true;
            this.txtLastToolEvent.Size = new System.Drawing.Size(120, 19);
            this.txtLastToolEvent.TabIndex = 84;
            this.txtLastToolEvent.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtToolStatus
            // 
            this.txtToolStatus.Location = new System.Drawing.Point(104, 90);
            this.txtToolStatus.MaxLength = 12;
            this.txtToolStatus.Name = "txtToolStatus";
            this.txtToolStatus.ReadOnly = true;
            this.txtToolStatus.Size = new System.Drawing.Size(120, 19);
            this.txtToolStatus.TabIndex = 81;
            this.txtToolStatus.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblToolStatus
            // 
            this.lblToolStatus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToolStatus.Location = new System.Drawing.Point(10, 93);
            this.lblToolStatus.Name = "lblToolStatus";
            this.lblToolStatus.Size = new System.Drawing.Size(88, 14);
            this.lblToolStatus.TabIndex = 89;
            this.lblToolStatus.Text = "Tool Status";
            // 
            // lblLastTranTime
            // 
            this.lblLastTranTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastTranTime.Location = new System.Drawing.Point(239, 144);
            this.lblLastTranTime.Name = "lblLastTranTime";
            this.lblLastTranTime.Size = new System.Drawing.Size(78, 14);
            this.lblLastTranTime.TabIndex = 88;
            this.lblLastTranTime.Text = "Last Tran Time";
            // 
            // txtLastTranTime
            // 
            this.txtLastTranTime.Location = new System.Drawing.Point(323, 141);
            this.txtLastTranTime.MaxLength = 20;
            this.txtLastTranTime.Name = "txtLastTranTime";
            this.txtLastTranTime.ReadOnly = true;
            this.txtLastTranTime.Size = new System.Drawing.Size(120, 19);
            this.txtLastTranTime.TabIndex = 86;
            this.txtLastTranTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtToolSetLoc
            // 
            this.txtToolSetLoc.Location = new System.Drawing.Point(104, 115);
            this.txtToolSetLoc.MaxLength = 20;
            this.txtToolSetLoc.Name = "txtToolSetLoc";
            this.txtToolSetLoc.ReadOnly = true;
            this.txtToolSetLoc.Size = new System.Drawing.Size(120, 19);
            this.txtToolSetLoc.TabIndex = 83;
            this.txtToolSetLoc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblToolSetLoc
            // 
            this.lblToolSetLoc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToolSetLoc.Location = new System.Drawing.Point(10, 118);
            this.lblToolSetLoc.Name = "lblToolSetLoc";
            this.lblToolSetLoc.Size = new System.Drawing.Size(88, 14);
            this.lblToolSetLoc.TabIndex = 87;
            this.lblToolSetLoc.Text = "Tool Set Location";
            // 
            // txtToolType
            // 
            this.txtToolType.Location = new System.Drawing.Point(104, 66);
            this.txtToolType.Name = "txtToolType";
            this.txtToolType.ReadOnly = true;
            this.txtToolType.Size = new System.Drawing.Size(120, 20);
            this.txtToolType.TabIndex = 60;
            // 
            // lblToolType
            // 
            this.lblToolType.AutoSize = true;
            this.lblToolType.Location = new System.Drawing.Point(10, 70);
            this.lblToolType.Name = "lblToolType";
            this.lblToolType.Size = new System.Drawing.Size(55, 13);
            this.lblToolType.TabIndex = 58;
            this.lblToolType.Text = "Tool Type";
            // 
            // txtToolDesc
            // 
            this.txtToolDesc.Location = new System.Drawing.Point(104, 37);
            this.txtToolDesc.MaxLength = 50;
            this.txtToolDesc.Name = "txtToolDesc";
            this.txtToolDesc.ReadOnly = true;
            this.txtToolDesc.Size = new System.Drawing.Size(340, 19);
            this.txtToolDesc.TabIndex = 56;
            this.txtToolDesc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblToolDesc
            // 
            this.lblToolDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToolDesc.Location = new System.Drawing.Point(10, 40);
            this.lblToolDesc.Name = "lblToolDesc";
            this.lblToolDesc.Size = new System.Drawing.Size(88, 14);
            this.lblToolDesc.TabIndex = 57;
            this.lblToolDesc.Text = "Description";
            // 
            // lblToolID
            // 
            this.lblToolID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToolID.Location = new System.Drawing.Point(10, 16);
            this.lblToolID.Name = "lblToolID";
            this.lblToolID.Size = new System.Drawing.Size(88, 14);
            this.lblToolID.TabIndex = 30;
            this.lblToolID.Text = "Tool ID";
            // 
            // cdvToolID
            // 
            this.cdvToolID.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvToolID.BorderHotColor = System.Drawing.Color.Black;
            this.cdvToolID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvToolID.BtnToolTipText = "";
            this.cdvToolID.DescText = "";
            this.cdvToolID.DisplaySubItemIndex = -1;
            this.cdvToolID.DisplayText = "";
            this.cdvToolID.Focusing = null;
            this.cdvToolID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvToolID.Index = 0;
            this.cdvToolID.IsViewBtnImage = false;
            this.cdvToolID.Location = new System.Drawing.Point(104, 13);
            this.cdvToolID.MaxLength = 20;
            this.cdvToolID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvToolID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvToolID.Name = "cdvToolID";
            this.cdvToolID.ReadOnly = false;
            this.cdvToolID.SearchSubItemIndex = 0;
            this.cdvToolID.SelectedDescIndex = -1;
            this.cdvToolID.SelectedSubItemIndex = -1;
            this.cdvToolID.SelectionStart = 0;
            this.cdvToolID.Size = new System.Drawing.Size(200, 20);
            this.cdvToolID.SmallImageList = null;
            this.cdvToolID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvToolID.TabIndex = 29;
            this.cdvToolID.TextBoxToolTipText = "";
            this.cdvToolID.TextBoxWidth = 200;
            this.cdvToolID.VisibleButton = true;
            this.cdvToolID.VisibleColumnHeader = false;
            this.cdvToolID.VisibleDescription = false;
            this.cdvToolID.ButtonPress += new System.EventHandler(this.cdvToolID_ButtonPress);
            this.cdvToolID.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvToolID_SelectedItemChanged);
            // 
            // grpInfo
            // 
            this.grpInfo.Controls.Add(this.pctImage);
            this.grpInfo.Controls.Add(this.lblImage);
            this.grpInfo.Controls.Add(this.utcBack);
            this.grpInfo.Controls.Add(this.utcText);
            this.grpInfo.Controls.Add(this.cdvLayOut);
            this.grpInfo.Controls.Add(this.txtFactory);
            this.grpInfo.Controls.Add(this.lblFactory);
            this.grpInfo.Controls.Add(this.lblLayOut);
            this.grpInfo.Controls.Add(this.txtY);
            this.grpInfo.Controls.Add(this.lblY);
            this.grpInfo.Controls.Add(this.txtHeight);
            this.grpInfo.Controls.Add(this.lblHeight);
            this.grpInfo.Controls.Add(this.txtWidth);
            this.grpInfo.Controls.Add(this.txtX);
            this.grpInfo.Controls.Add(this.lblWidth);
            this.grpInfo.Controls.Add(this.lblX);
            this.grpInfo.Controls.Add(this.lblResTagFlag);
            this.grpInfo.Controls.Add(this.txtResTagFlag);
            this.grpInfo.Controls.Add(this.lblBackColor);
            this.grpInfo.Controls.Add(this.cboTextStyle);
            this.grpInfo.Controls.Add(this.lblStyle);
            this.grpInfo.Controls.Add(this.lblColor);
            this.grpInfo.Controls.Add(this.cboSize);
            this.grpInfo.Controls.Add(this.txtText);
            this.grpInfo.Controls.Add(this.txtSize);
            this.grpInfo.Controls.Add(this.lblText);
            this.grpInfo.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.grpInfo.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpInfo.Location = new System.Drawing.Point(3, 224);
            this.grpInfo.Name = "grpInfo";
            this.grpInfo.Size = new System.Drawing.Size(451, 210);
            this.grpInfo.TabIndex = 1;
            this.grpInfo.TabStop = false;
            // 
            // pctImage
            // 
            this.pctImage.Location = new System.Drawing.Point(396, 68);
            this.pctImage.Name = "pctImage";
            this.pctImage.Size = new System.Drawing.Size(32, 32);
            this.pctImage.TabIndex = 55;
            this.pctImage.TabStop = false;
            // 
            // lblImage
            // 
            this.lblImage.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblImage.Location = new System.Drawing.Point(323, 70);
            this.lblImage.Name = "lblImage";
            this.lblImage.Size = new System.Drawing.Size(60, 14);
            this.lblImage.TabIndex = 54;
            this.lblImage.Text = "Image";
            // 
            // utcBack
            // 
            this.utcBack.Location = new System.Drawing.Point(323, 131);
            this.utcBack.Name = "utcBack";
            this.utcBack.Size = new System.Drawing.Size(120, 19);
            this.utcBack.TabIndex = 7;
            this.utcBack.Text = "Control";
            this.utcBack.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // utcText
            // 
            this.utcText.Location = new System.Drawing.Point(104, 131);
            this.utcText.Name = "utcText";
            this.utcText.Size = new System.Drawing.Size(120, 19);
            this.utcText.TabIndex = 6;
            this.utcText.Text = "Control";
            this.utcText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // cdvLayOut
            // 
            this.cdvLayOut.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvLayOut.BorderHotColor = System.Drawing.Color.Black;
            this.cdvLayOut.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvLayOut.BtnToolTipText = "";
            this.cdvLayOut.DescText = "";
            this.cdvLayOut.DisplaySubItemIndex = -1;
            this.cdvLayOut.DisplayText = "";
            this.cdvLayOut.Focusing = null;
            this.cdvLayOut.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvLayOut.Index = 0;
            this.cdvLayOut.IsViewBtnImage = false;
            this.cdvLayOut.Location = new System.Drawing.Point(323, 20);
            this.cdvLayOut.MaxLength = 20;
            this.cdvLayOut.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvLayOut.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvLayOut.Name = "cdvLayOut";
            this.cdvLayOut.ReadOnly = false;
            this.cdvLayOut.SearchSubItemIndex = 0;
            this.cdvLayOut.SelectedDescIndex = -1;
            this.cdvLayOut.SelectedSubItemIndex = -1;
            this.cdvLayOut.SelectionStart = 0;
            this.cdvLayOut.Size = new System.Drawing.Size(120, 20);
            this.cdvLayOut.SmallImageList = null;
            this.cdvLayOut.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvLayOut.TabIndex = 1;
            this.cdvLayOut.TextBoxToolTipText = "";
            this.cdvLayOut.TextBoxWidth = 120;
            this.cdvLayOut.VisibleButton = true;
            this.cdvLayOut.VisibleColumnHeader = false;
            this.cdvLayOut.VisibleDescription = false;
            this.cdvLayOut.ButtonPress += new System.EventHandler(this.cdvLayOut_ButtonPress);
            // 
            // txtFactory
            // 
            this.txtFactory.Location = new System.Drawing.Point(104, 20);
            this.txtFactory.MaxLength = 10;
            this.txtFactory.Name = "txtFactory";
            this.txtFactory.ReadOnly = true;
            this.txtFactory.Size = new System.Drawing.Size(120, 19);
            this.txtFactory.TabIndex = 0;
            this.txtFactory.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblFactory
            // 
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Location = new System.Drawing.Point(12, 23);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(88, 14);
            this.lblFactory.TabIndex = 53;
            this.lblFactory.Text = "Factory";
            // 
            // lblLayOut
            // 
            this.lblLayOut.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLayOut.Location = new System.Drawing.Point(231, 23);
            this.lblLayOut.Name = "lblLayOut";
            this.lblLayOut.Size = new System.Drawing.Size(88, 14);
            this.lblLayOut.TabIndex = 51;
            this.lblLayOut.Text = "LayOut ID";
            // 
            // txtY
            // 
            this.txtY.Location = new System.Drawing.Point(323, 155);
            this.txtY.MaxLength = 6;
            this.txtY.Name = "txtY";
            this.txtY.Size = new System.Drawing.Size(120, 19);
            this.txtY.TabIndex = 9;
            this.txtY.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtY.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtY_KeyPress);
            // 
            // lblY
            // 
            this.lblY.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblY.Location = new System.Drawing.Point(231, 159);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(88, 14);
            this.lblY.TabIndex = 47;
            this.lblY.Text = "Location Y";
            // 
            // txtHeight
            // 
            this.txtHeight.Location = new System.Drawing.Point(323, 179);
            this.txtHeight.MaxLength = 6;
            this.txtHeight.Name = "txtHeight";
            this.txtHeight.Size = new System.Drawing.Size(120, 19);
            this.txtHeight.TabIndex = 11;
            this.txtHeight.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtHeight.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtHeight_KeyPress);
            // 
            // lblHeight
            // 
            this.lblHeight.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHeight.Location = new System.Drawing.Point(231, 183);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(88, 14);
            this.lblHeight.TabIndex = 45;
            this.lblHeight.Text = "Height";
            // 
            // txtWidth
            // 
            this.txtWidth.Location = new System.Drawing.Point(104, 179);
            this.txtWidth.MaxLength = 6;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(120, 19);
            this.txtWidth.TabIndex = 10;
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtWidth.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtWidth_KeyPress);
            // 
            // txtX
            // 
            this.txtX.Location = new System.Drawing.Point(104, 155);
            this.txtX.MaxLength = 6;
            this.txtX.Name = "txtX";
            this.txtX.Size = new System.Drawing.Size(120, 19);
            this.txtX.TabIndex = 8;
            this.txtX.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtX.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtX_KeyPress);
            // 
            // lblWidth
            // 
            this.lblWidth.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblWidth.Location = new System.Drawing.Point(12, 183);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(88, 14);
            this.lblWidth.TabIndex = 42;
            this.lblWidth.Text = "Width";
            // 
            // lblX
            // 
            this.lblX.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblX.Location = new System.Drawing.Point(12, 159);
            this.lblX.Name = "lblX";
            this.lblX.Size = new System.Drawing.Size(88, 14);
            this.lblX.TabIndex = 41;
            this.lblX.Text = "Location X ";
            // 
            // lblResTagFlag
            // 
            this.lblResTagFlag.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResTagFlag.Location = new System.Drawing.Point(12, 48);
            this.lblResTagFlag.Name = "lblResTagFlag";
            this.lblResTagFlag.Size = new System.Drawing.Size(88, 14);
            this.lblResTagFlag.TabIndex = 40;
            this.lblResTagFlag.Text = "Type";
            // 
            // txtResTagFlag
            // 
            this.txtResTagFlag.Location = new System.Drawing.Point(104, 44);
            this.txtResTagFlag.Name = "txtResTagFlag";
            this.txtResTagFlag.ReadOnly = true;
            this.txtResTagFlag.Size = new System.Drawing.Size(120, 19);
            this.txtResTagFlag.TabIndex = 2;
            this.txtResTagFlag.Text = "L";
            this.txtResTagFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblBackColor
            // 
            this.lblBackColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBackColor.Location = new System.Drawing.Point(231, 134);
            this.lblBackColor.Name = "lblBackColor";
            this.lblBackColor.Size = new System.Drawing.Size(88, 14);
            this.lblBackColor.TabIndex = 37;
            this.lblBackColor.Text = "Back Color";
            // 
            // cboTextStyle
            // 
            this.cboTextStyle.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboTextStyle.Location = new System.Drawing.Point(323, 106);
            this.cboTextStyle.Name = "cboTextStyle";
            this.cboTextStyle.Size = new System.Drawing.Size(120, 19);
            this.cboTextStyle.TabIndex = 5;
            this.cboTextStyle.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblStyle
            // 
            this.lblStyle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblStyle.Location = new System.Drawing.Point(231, 109);
            this.lblStyle.Name = "lblStyle";
            this.lblStyle.Size = new System.Drawing.Size(88, 14);
            this.lblStyle.TabIndex = 34;
            this.lblStyle.Text = "Text Style";
            // 
            // lblColor
            // 
            this.lblColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblColor.Location = new System.Drawing.Point(12, 134);
            this.lblColor.Name = "lblColor";
            this.lblColor.Size = new System.Drawing.Size(88, 14);
            this.lblColor.TabIndex = 33;
            this.lblColor.Text = "Text Color";
            // 
            // cboSize
            // 
            this.cboSize.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboSize.Location = new System.Drawing.Point(104, 106);
            this.cboSize.Name = "cboSize";
            this.cboSize.Size = new System.Drawing.Size(120, 19);
            this.cboSize.TabIndex = 4;
            this.cboSize.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtText
            // 
            this.txtText.Location = new System.Drawing.Point(104, 68);
            this.txtText.MaxLength = 40;
            this.txtText.Name = "txtText";
            this.txtText.Size = new System.Drawing.Size(200, 19);
            this.txtText.TabIndex = 3;
            this.txtText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSize
            // 
            this.txtSize.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.txtSize.Location = new System.Drawing.Point(12, 110);
            this.txtSize.Name = "txtSize";
            this.txtSize.Size = new System.Drawing.Size(88, 14);
            this.txtSize.TabIndex = 30;
            this.txtSize.Text = "Text Font Size";
            // 
            // lblText
            // 
            this.lblText.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblText.Location = new System.Drawing.Point(12, 72);
            this.lblText.Name = "lblText";
            this.lblText.Size = new System.Drawing.Size(88, 14);
            this.lblText.TabIndex = 29;
            this.lblText.Text = "Text";
            // 
            // frmFMBCreateTool
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(457, 471);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFMBCreateTool";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Create Tool";
            this.Load += new System.EventHandler(this.frmFMBCreateTool_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.grpSubRes.ResumeLayout(false);
            this.grpSubRes.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolSetID)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolLoc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDeleteFlag)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastToolEvent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolStatus)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastTranTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolSetLoc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtToolDesc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvToolID)).EndInit();
            this.grpInfo.ResumeLayout(false);
            this.grpInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pctImage)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBack)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcText)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvLayOut)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtFactory)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtResTagFlag)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboTextStyle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtText)).EndInit();
            this.ResumeLayout(false);

        }
        
        #endregion
        
        #region " Variable Definition"
        private ImageList imlRes;
        public int iImageIndex = - 1;
        private int sWidth = 0;
        private int sHeight = 0;
        #endregion
        
        #region " Property Implements"
        
        private char m_sProcStep = ' ';
        
        public char ProcStep
        {
            get
            {
                return m_sProcStep;
            }
            set
            {

                if (m_sProcStep.Equals(value) == false)
                {
                    m_sProcStep = value;
                }
            }
        }
        
        #endregion
        
        #region " Function Implementations"
        
        // init()
        //       - Initialize Controls
        // Return Value
        //       -
        // Arguments
        //       -
        //
        private void init()
        {
            
            try
            {
                Miracom.FMBUI.Controls.udcCtrlTool ctrlTool = new Miracom.FMBUI.Controls.udcCtrlTool(modGlobalVariable.gimlResource);
                imlRes = ctrlTool.imlResource;
                
                FMBCF.SetEnumList(cboTextStyle, typeof(FontStyle));
                FMBCF.SetFontSize(cboSize);
                cboSize.Text = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextSize));
                cboTextStyle.SelectedIndex = 0;
                utcText.Color =   (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextColor);
                utcBack.Color = (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultBackColor);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.init()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        // Set_ReadOnly()
        //       - Set Controls ReadOnly
        // Return Value
        //       -
        // Arguments
        //       -
        //
        private void Set_ReadOnly()
        {
            
            try
            {
                if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    lblLayOut.Text = "LayOut ID";
                }
                else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    lblLayOut.Text = "Group ID";
                }
                
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    cdvLayOut.ReadOnly = true;
                    cdvLayOut.BackColor = SystemColors.Control;
                    cdvLayOut.VisibleButton = false;
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_UPDATE)
                {
                    cdvToolID.ReadOnly = true;
                    cdvToolID.BackColor = SystemColors.Control;
                    cdvToolID.VisibleButton = false;
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                    }
                    else
                    {
                        cdvLayOut.ReadOnly = true;
                        cdvLayOut.BackColor = SystemColors.Control;
                        cdvLayOut.VisibleButton = false;
                    }
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    cdvToolID.ReadOnly = true;
                    cdvToolID.BackColor = SystemColors.Control;
                    cdvToolID.VisibleButton = false;
                    
                    cdvLayOut.ReadOnly = true;
                    cdvLayOut.BackColor = SystemColors.Control;
                    cdvLayOut.VisibleButton = false;
                    
                    txtText.ReadOnly = true;
                    cboSize.ReadOnly = true;
                    cboTextStyle.ReadOnly = true;
                    utcText.ReadOnly = true;
                    utcBack.ReadOnly = true;
                    txtX.ReadOnly = true;
                    txtY.ReadOnly = true;
                    txtWidth.ReadOnly = true;
                    txtHeight.ReadOnly = true;
                    
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_VIEW)
                {
                    cdvToolID.ReadOnly = true;
                    cdvToolID.BackColor = SystemColors.Control;
                    cdvToolID.VisibleButton = false;
                    
                    cdvLayOut.ReadOnly = true;
                    cdvLayOut.BackColor = SystemColors.Control;
                    cdvLayOut.VisibleButton = false;
                    
                    txtText.ReadOnly = true;
                    cboSize.ReadOnly = true;
                    cboTextStyle.ReadOnly = true;
                    utcText.ReadOnly = true;
                    utcBack.ReadOnly = true;
                    txtX.ReadOnly = true;
                    txtY.ReadOnly = true;
                    txtWidth.ReadOnly = true;
                    txtHeight.ReadOnly = true;
                    btnCreate.Visible = false;
                    
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.Set_ReadOnly()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        // CheckCondition()
        //       - Check the conditions before transaction
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - FuncName as String  : Fuction Name
        //
        private bool CheckCondition(string FuncName)
        {
            
            try
            {
                if (cdvToolID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), "FMB Client", MessageBoxButtons.OK, 1);
                    cdvToolID.Focus();
                    return false;
                }

                switch (MPCF.RTrim(FuncName))
                {
                    case "CREATE":

                        if (MPCF.ToInt(txtWidth.Text) < modGlobalConstant.CTRL_MININUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(38) + " " + modGlobalConstant.CTRL_MININUM_SIZE, "FMB Client", MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtHeight.Text) < modGlobalConstant.CTRL_MININUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(38) + " " + modGlobalConstant.CTRL_MININUM_SIZE, "FMB Client", MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtWidth.Text) > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(8) + " " + modGlobalConstant.CTRL_MAXIMUM_SIZE, "FMB Client", MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtHeight.Text) > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(8) + " " + modGlobalConstant.CTRL_MAXIMUM_SIZE, "FMB Client", MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtX.Text) < 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(10), "FMB Client", MessageBoxButtons.OK, 1);
                            txtX.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtY.Text) < 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(10), "FMB Client", MessageBoxButtons.OK, 1);
                            txtY.Focus();
                            return false;
                        }
                        
                        if (MPCF.CheckNumeric(txtX.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), "FMB Client", MessageBoxButtons.OK, 1);
                            txtX.Focus();
                            return false;
                        }

                        if (MPCF.CheckNumeric(txtY.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), "FMB Client", MessageBoxButtons.OK, 1);
                            txtY.Focus();
                            return false;
                        }

                        if (MPCF.CheckNumeric(txtWidth.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), "FMB Client", MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }

                        if (MPCF.CheckNumeric(txtHeight.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), "FMB Client", MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        break;
                        
                        
                    case "DELETE":
                        
                        break;
                        
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.CheckCondition()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Update_Resource_Location()
        //       - Create/Update/Delete Resource Location
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String  : Proc Step
        //
        private bool Update_Resource_Location(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("Update_ResLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = txtFactory.Text;
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", txtCreateUser.Text);
                in_node.AddString("TOOL_ID", cdvToolID.Text);
                in_node.AddChar("RES_TYPE", txtResTagFlag.Text[0]);
                in_node.AddString("TEXT", txtText.Text);
                in_node.AddChar("NO_MOUSE_EVENT", ' ');
                in_node.AddInt("IMAGE_IDX", 0);
                
                if (utcText.Color.IsSystemColor == true || utcText.Color.IsKnownColor == true)
                {
                    in_node.AddInt("TEXT_COLOR", MPCF.ToInt(utcText.Color.ToKnownColor()));
                }
                else
                {
                    in_node.AddInt("TEXT_COLOR", utcText.Color.ToArgb());
                }

                in_node.AddInt("TEXT_SIZE", MPCF.ToInt(cboSize.Text));
                in_node.AddChar("TEXT_STYLE", Convert.ToChar(cboTextStyle.SelectedIndex + '0'));

                if (utcBack.Color.IsSystemColor == true || utcBack.Color.IsKnownColor == true)
                {
                    in_node.AddInt("BACK_COLOR", MPCF.ToInt(utcBack.Color.ToKnownColor()));
                }
                else
                {
                    in_node.AddInt("BACK_COLOR", utcBack.Color.ToArgb());
                }

                in_node.AddString("LAYOUT_ID", cdvLayOut.Text);
                in_node.AddInt("LOC_X", MPCF.ToInt(txtX.Text));
                in_node.AddInt("LOC_Y", MPCF.ToInt(txtY.Text));
                in_node.AddInt("LOC_WIDTH", MPCF.ToInt(txtWidth.Text));
                in_node.AddInt("LOC_HEIGHT", MPCF.ToInt(txtHeight.Text));
                in_node.AddInt("TAG_TYPE", MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Resource));
                in_node.AddChar("SIGNAL_FLAG", ' ');


                if (sStep != modGlobalConstant.MP_STEP_DELETE)
                {
                    if (View_LayOut() == true)
                    {
                        if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtWidth.Text) > sWidth)
                        {
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(20), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                in_node.AddInt("LOC_X", sWidth - MPCF.ToInt(txtWidth.Text));
                                txtX.Text = System.Convert.ToString(sWidth - MPCF.ToInt(txtWidth.Text));
                            }
                            else
                            {
                                in_node.AddInt("LOC_X", MPCF.ToInt(txtX.Text));
                            }
                        }
                        if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtHeight.Text) > sHeight)
                        {
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(21), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                in_node.AddInt("LOC_Y", sHeight - MPCF.ToInt(txtHeight.Text));
                                txtY.Text = System.Convert.ToString(sHeight - MPCF.ToInt(txtHeight.Text));
                            }
                            else
                            {
                                in_node.AddInt("LOC_Y", MPCF.ToInt(txtY.Text));
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                if (MPCR.CallService("FMB", "FMB_Update_Resource_Location", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.ShowSuccessMsg(out_node);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.Update_Resource_Location()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }     

        // ViewToolList()
        //       - View Tool List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - control as Control : Control
        //       - sStep as String    : Proc Step
        //

        private bool ViewToolList(Control control, string sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_TOOL_LIST_IN");
                TRSNode out_node = new TRSNode("VIEW_TOOL_LIST_OUT");

                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = txtFactory.Text;
                in_node.AddString("NEXT_TOOL_ID", "");
              
                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_Tool_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {

                        if (control is ListView)
                        {
                            if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'Y')
                            {
                            }
                            else if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'N')
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_TOOL));

                                if (((ListView)control).Columns.Count > 1)
                                {
                                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_DESC")));
                                }
                                ((ListView)control).Items.Add(itmX);
                            }
                        }
                    }

                    in_node.SetString("NEXT_TOOL_ID", out_node.GetString("NEXT_TOOL_ID"));
                } while (string.IsNullOrEmpty(out_node.GetString("NEXT_TOOL_ID")) == false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.ViewToolList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }


        // ViewUDRToolList()
        //       - View UDR Tool List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - control as Control : Control
        //       - sStep as String    : Proc Step
        //

        private bool ViewUDRToolList(Control control, string sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_UDR_TOOL_LIST_IN");
                TRSNode out_node = new TRSNode("VIEW_UDR_TOOL_LIST_OUT");

                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("NEXT_TOOL_ID", "");
                in_node.AddString("GROUP_ID", cdvLayOut.Text);
                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_UDR_Tool_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {

                        if (control is ListView)
                        {
                            if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'Y')
                            {
                            }
                            else if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'N')
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_TOOL));

                                if (((ListView)control).Columns.Count > 1)
                                {
                                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_DESC")));
                                }
                                ((ListView)control).Items.Add(itmX);
                            }
                        }
                    }

                    in_node.SetString("NEXT_TOOL_ID", out_node.GetString("NEXT_TOOL_ID"));
                } while (string.IsNullOrEmpty(out_node.GetString("NEXT_TOOL_ID")) == false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.ViewToolList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }



        // View_Tool()
        //       - View Tool Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //
        private bool View_Tool(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_TOOL_IN");
                TRSNode out_node = new TRSNode("VIEW_TOOL_OUT");


                MPCR.SetInMsg(in_node);
                in_node.Factory = txtFactory.Text;
                in_node.ProcStep = sStep;
                in_node.AddString("TOOL_ID", cdvToolID.Text);
                in_node.AddString("LAYOUT_ID", cdvLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_Tool", in_node, ref out_node) == false)
                {
                    return false;
                }

                if (sStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    txtToolDesc.Text = MPCF.RTrim(out_node.GetString("TOOL_DESC"));
                    txtToolType.Text = MPCF.RTrim(out_node.GetString("TOOL_TYPE"));
                    txtToolSetID.Text = MPCF.RTrim(out_node.GetString("TOOL_SET_ID"));
                    txtToolStatus.Text = MPCF.RTrim(out_node.GetString("TOOL_STATUS"));
                    txtToolLoc.Text = MPCF.RTrim(out_node.GetString("TOOL_LOCATION"));
                    txtToolSetLoc.Text = MPCF.RTrim(out_node.GetString("TOOL_SET_LOCATION"));
                    txtLastToolEvent.Text = MPCF.RTrim(out_node.GetString("LAST_TOOL_EVENT_ID"));
                    txtDeleteFlag.Text = MPCF.RTrim(out_node.GetChar("DELETE_FLAG"));
                    txtLastTranTime.Text = MPCF.RTrim(out_node.GetString("LAST_TRAN_TIME"));
                    txtCreateUser.Text = MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));
                    txtCreateTime.Text = MPCF.RTrim(out_node.GetString("CREATE_TIME"));
                    txtUpdateUser.Text = MPCF.RTrim(out_node.GetString("UPDATE_USER_ID"));
                    txtUpdateTime.Text = MPCF.RTrim(out_node.GetString("UPDATE_TIME"));

                    txtText.Text = cdvToolID.Text;

                    if (out_node.GetInt("IMAGE_IDX") != -1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
                    {
                        iImageIndex = out_node.GetInt("IMAGE_IDX");
                        pctImage.Image = imlRes.Images[iImageIndex];
                    }
                    else
                    {
                        pctImage.Image = null;
                    }
                }
                else
                {
                    txtToolDesc.Text = MPCF.RTrim(out_node.GetString("TOOL_DESC"));
                    txtToolType.Text = MPCF.RTrim(out_node.GetString("TOOL_TYPE"));
                    txtToolSetID.Text = MPCF.RTrim(out_node.GetString("TOOL_SET_ID"));
                    txtToolStatus.Text = MPCF.RTrim(out_node.GetString("TOOL_STATUS"));
                    txtToolLoc.Text = MPCF.RTrim(out_node.GetString("TOOL_LOCATION"));
                    txtToolSetLoc.Text = MPCF.RTrim(out_node.GetString("TOOL_SET_LOCATION"));
                    txtLastToolEvent.Text = MPCF.RTrim(out_node.GetString("LAST_TOOL_EVENT_ID"));
                    txtDeleteFlag.Text = MPCF.RTrim(out_node.GetChar("DELETE_FLAG"));
                    txtLastTranTime.Text = MPCF.RTrim(out_node.GetString("LAST_TRAN_TIME"));
                    txtCreateUser.Text = MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));
                    txtCreateTime.Text = MPCF.RTrim(out_node.GetString("CREATE_TIME"));
                    txtUpdateUser.Text = MPCF.RTrim(out_node.GetString("UPDATE_USER_ID"));
                    txtUpdateTime.Text = MPCF.RTrim(out_node.GetString("UPDATE_TIME"));

                    txtText.Text = cdvToolID.Text;


                    cdvLayOut.Text = MPCF.RTrim(out_node.GetString("LAYOUT_ID"));
                    txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));
                    cboSize.Text = MPCF.Trim(out_node.GetInt("TEXT_SIZE"));
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString());

                    if (out_node.GetInt("TEXT_COLOR") < 0)
                    {
                        utcText.Color = Color.FromArgb(out_node.GetInt("TEXT_COLOR"));

                    }
                    else if (out_node.GetInt("TEXT_COLOR") > 0)
                    {
                        utcText.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("TEXT_COLOR"));
                    }
                    else
                    {
                        utcText.Color = SystemColors.Control;
                    }
                    if (out_node.GetInt("BACK_COLOR") < 0)
                    {
                        //utcBack.Color = utcBack.Color.FromArgb(out_node.Get("BACK_COLOR"));
                        utcBack.Color = Color.FromArgb(out_node.GetInt("BACK_COLOR"));
                    }
                    else if (out_node.GetInt("BACK_COLOR") > 0)
                    {
                        //utcBack.Color = utcBack.Color.FromKnownColor((KnownColor)out_node.GetInt("BACK_COLOR"));
                        utcBack.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("BACK_COLOR"));
                    }
                    else
                    {
                        utcBack.Color = SystemColors.Control;
                    }
                    if (out_node.GetInt("IMAGE_IDX") != -1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
                    {
                        iImageIndex = out_node.GetInt("IMAGE_IDX");
                        pctImage.Image = imlRes.Images[iImageIndex];
                    }
                    else
                    {
                        pctImage.Image = null;
                    }
                    
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.View_Resource()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }



        // View_UDR_Tool()
        //       - View UDR Tool Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //
        private bool View_UDR_Tool(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_UDR_TOOL_IN");
                TRSNode out_node = new TRSNode("VIEW_UDR_TOOL_OUT");


                MPCR.SetInMsg(in_node);
                in_node.Factory = txtFactory.Text;
                in_node.ProcStep = sStep;
                in_node.AddString("TOOL_ID", cdvToolID.Text);
                in_node.AddString("GROUP_ID", cdvLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_UDR_Tool", in_node, ref out_node) == false)
                {
                    return false;
                }

                if (sStep == modGlobalConstant.MP_STEP_CREATE)
                {

                    txtToolDesc.Text = MPCF.RTrim(out_node.GetString("TOOL_DESC"));
                    txtToolType.Text = MPCF.RTrim(out_node.GetString("TOOL_TYPE"));
                    txtToolSetID.Text = MPCF.RTrim(out_node.GetString("TOOL_SET_ID"));
                    txtToolStatus.Text = MPCF.RTrim(out_node.GetString("TOOL_STATUS"));
                    txtLastToolEvent.Text = MPCF.RTrim(out_node.GetString("LAST_TOOL_EVENT_ID"));
                    txtDeleteFlag.Text = MPCF.RTrim(out_node.GetChar("DELETE_FLAG"));
                    txtLastTranTime.Text = MPCF.RTrim(out_node.GetString("LAST_TRAN_TIME"));
                    txtCreateUser.Text = MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));
                    txtCreateTime.Text = MPCF.RTrim(out_node.GetString("CREATE_TIME"));
                    txtUpdateUser.Text = MPCF.RTrim(out_node.GetString("UPDATE_USER_ID"));
                    txtUpdateTime.Text = MPCF.RTrim(out_node.GetString("UPDATE_TIME"));

                    txtText.Text = cdvToolID.Text;
                    txtCreateUser.Text = MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));

                    txtToolDesc.Text = MPCF.RTrim(out_node.GetString("TOOL_DESC"));
                    txtToolType.Text = MPCF.RTrim(out_node.GetString("TOOL_TYPE"));
                    txtToolSetLoc.Text = MPCF.RTrim(out_node.GetString("TOOL_SET_LOCATION"));

                    txtText.Text = cdvToolID.Text;

                    if (out_node.GetInt("IMAGE_IDX") != -1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
                    {
                        iImageIndex = out_node.GetInt("IMAGE_IDX");
                        pctImage.Image = imlRes.Images[iImageIndex];
                    }
                    else
                    {
                        pctImage.Image = null;
                    }
                }
                else
                {
                    txtToolDesc.Text = MPCF.RTrim(out_node.GetString("TOOL_DESC"));
                    txtToolType.Text = MPCF.RTrim(out_node.GetString("TOOL_TYPE"));
                    txtToolStatus.Text = MPCF.RTrim(out_node.GetString("TOOL_STATUS"));
                    txtLastToolEvent.Text = MPCF.RTrim(out_node.GetString("LAST_TOOL_EVENT_ID"));
                    txtDeleteFlag.Text = MPCF.RTrim(out_node.GetChar("DELETE_FLAG"));
                    txtLastTranTime.Text = MPCF.RTrim(out_node.GetString("LAST_TRAN_TIME"));
                    txtCreateUser.Text = MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));
                    txtCreateTime.Text = MPCF.RTrim(out_node.GetString("CREATE_TIME"));
                    txtUpdateUser.Text = MPCF.RTrim(out_node.GetString("UPDATE_USER_ID"));
                    txtUpdateTime.Text = MPCF.RTrim(out_node.GetString("UPDATE_TIME"));


                    cdvLayOut.Text = MPCF.RTrim(out_node.GetString("GROUP_ID"));
                    txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));
                    cboSize.Text = MPCF.Trim(out_node.GetInt("TEXT_SIZE"));
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString());

                    if (out_node.GetInt("TEXT_COLOR") < 0)
                    {
                        utcText.Color = Color.FromArgb(out_node.GetInt("TEXT_COLOR"));

                    }
                    else if (out_node.GetInt("TEXT_COLOR") > 0)
                    {
                        utcText.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("TEXT_COLOR"));
                    }
                    else
                    {
                        utcText.Color = SystemColors.Control;
                    }
                    if (out_node.GetInt("BACK_COLOR") < 0)
                    {
                        //utcBack.Color = utcBack.Color.FromArgb(out_node.GetInt("BACK_COLOR"));
                        utcBack.Color = Color.FromArgb(out_node.GetInt("BACK_COLOR"));
                    }
                    else if (out_node.GetInt("BACK_COLOR") > 0)
                    {
                        //utcBack.Color = utcBack.Color.FromKnownColor((KnownColor)out_node.GetInt("BACK_COLOR"));
                        utcBack.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("BACK_COLOR"));
                    }
                    else
                    {
                        utcBack.Color = SystemColors.Control;
                    }
                    if (out_node.GetInt("IMAGE_IDX") != -1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
                    {
                        iImageIndex = out_node.GetInt("IMAGE_IDX");
                        pctImage.Image = imlRes.Images[iImageIndex];
                    }
                    else
                    {
                        pctImage.Image = null;
                    }

                    
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.View_Resource()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }



         // Update_UDR_ResLoc()
        //       - Create/Update/Delete User Define Resource Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //
        private object Update_UDR_ResLoc(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("UPDATE_UDR_RESLOC_IN");
                TRSNode out_node = new TRSNode("CMN_OUT");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("GROUP_ID", cdvLayOut.Text);

                in_node.AddString("RES_ID", txtCreateUser.Text);
                in_node.AddString("TOOL_ID", cdvToolID.Text);
                in_node.AddChar("RES_TYPE", txtResTagFlag.Text[0]);
                in_node.AddString("TEXT", txtText.Text);

                if (utcText.Color.IsSystemColor == true || utcText.Color.IsKnownColor == true)
                {
                    in_node.AddInt("TEXT_COLOR", MPCF.ToInt(utcText.Color.ToKnownColor()));
                }
                else
                {
                    in_node.AddInt("TEXT_COLOR", utcText.Color.ToArgb());
                }

                in_node.AddInt("TEXT_SIZE", MPCF.ToInt(cboSize.Text));
                in_node.AddChar("TEXT_STYLE", Convert.ToChar(cboTextStyle.SelectedIndex + '0'));

                if (utcBack.Color.IsSystemColor == true || utcBack.Color.IsKnownColor == true)
                {
                    in_node.AddInt("BACK_COLOR", MPCF.ToInt(utcBack.Color.ToKnownColor()));
                }
                else
                {
                    in_node.AddInt("BACK_COLOR", utcBack.Color.ToArgb());
                }
                in_node.AddInt("LOC_X", MPCF.ToInt(txtX.Text));
                in_node.AddInt("LOC_Y", MPCF.ToInt(txtY.Text));
                in_node.AddInt("LOC_WIDTH", MPCF.ToInt(txtWidth.Text));
                in_node.AddInt("LOC_HEIGHT", MPCF.ToInt(txtHeight.Text));
                in_node.AddInt("TAG_TYPE", MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Resource));
                in_node.AddChar("SIGNAL_FLAG", ' ');

                if (sStep != modGlobalConstant.MP_STEP_DELETE)
                {
                    if (View_UDR_Group() == true)
                    {
                        if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtWidth.Text) > sWidth)
                        {
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(20), "FMB Client", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                in_node.AddInt("LOC_X", sWidth - MPCF.ToInt(txtWidth.Text));
                                txtX.Text = System.Convert.ToString(sWidth - MPCF.ToInt(txtWidth.Text));
                            }
                            else
                            {
                                in_node.AddInt("LOC_X", MPCF.ToInt(txtX.Text));
                            }
                        }
                        if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtHeight.Text) > sHeight)
                        {
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(21), "FMB Client", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                in_node.AddInt("LOC_Y", sHeight - MPCF.ToInt(txtHeight.Text));
                                txtY.Text = System.Convert.ToString(sHeight - MPCF.ToInt(txtHeight.Text));
                            }
                            else
                            {
                                in_node.AddInt("LOC_Y", MPCF.ToInt(txtY.Text));
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }

                if (MPCR.CallService("FMB", "FMB_Update_UDR_ResLoc", in_node, ref out_node) == false)
                {
                    return false;
                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.Update_UDR_ResLoc()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }

        
        // View_LayOut()
        //       - View Layout Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool View_LayOut()
        {

            try
            {
                TRSNode in_node = new TRSNode("View_LayOut_In");
                TRSNode out_node = new TRSNode("View_LayOut_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = txtFactory.Text;
                in_node.ProcStep = '1';
                in_node.AddString("LAYOUT_ID", cdvLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_LayOut", in_node, ref out_node) == false)
                {
                    return false;
                }

                sWidth = out_node.GetInt("WIDTH");
                sHeight = out_node.GetInt("HEIGHT");

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.View_LayOut()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }
        
        // View_UDR_Group()
        //       - View User Define Resource Group Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool View_UDR_Group()
        {

            try
            {
                TRSNode in_node = new TRSNode("View_UDR_Group_In");
                TRSNode out_node = new TRSNode("View_UDR_Group_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("GROUP_ID", cdvLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_UDR_Group", in_node, ref out_node) == false)
                {
                    return false;
                }

                sWidth = out_node.GetInt("WIDTH");
                sHeight = out_node.GetInt("HEIGHT");

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.View_UDR_Group()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }
        
        #endregion
        
        #region " Event Implementations"
        
        private void btnClose_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                this.Dispose(true);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.btnClose_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        

        private void btnCreate_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (CheckCondition("CREATE") == false)
                    {
                        this.DialogResult = DialogResult.None;
                        return;
                    }
                    else
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            if (Update_Resource_Location(modGlobalConstant.MP_STEP_CREATE) == false)
                            {
                                this.DialogResult = DialogResult.None;
                                return;
                            }
                            if (FMBFI.gIMdiForm.RefreshDesignList("2", txtFactory.Text, cdvLayOut.Text, cdvToolID.Text, "") == false)
                            {
                                return;
                            }
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            if ((bool)Update_UDR_ResLoc(modGlobalConstant.MP_STEP_CREATE) == false)
                            {
                                this.DialogResult = DialogResult.None;
                                return;
                            }
                        }
                    }
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_UPDATE)
                {
                    if (CheckCondition("CREATE") == false)
                    {
                        this.DialogResult = DialogResult.None;
                        return;
                    }
                    else
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            if (Update_Resource_Location(modGlobalConstant.MP_STEP_UPDATE) == false)
                            {
                                this.DialogResult = DialogResult.None;
                                return;
                            }
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            if ((bool)Update_UDR_ResLoc(modGlobalConstant.MP_STEP_UPDATE) == false)
                            {
                                this.DialogResult = DialogResult.None;
                                return;
                            }
                        }
                    }
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    if (CheckCondition("DELETE") == false)
                    {
                        this.DialogResult = DialogResult.None;
                        return;
                    }
                    else
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            if (Update_Resource_Location(modGlobalConstant.MP_STEP_DELETE) == false)
                            {
                                this.DialogResult = DialogResult.None;
                                return;
                            }
                            if (FMBFI.gIMdiForm.RefreshDesignList("2", txtFactory.Text, cdvLayOut.Text, cdvToolID.Text, "") == false)
                            {
                                return;
                            }
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            if ((bool)Update_UDR_ResLoc(modGlobalConstant.MP_STEP_DELETE) == false)
                            {
                                this.DialogResult = DialogResult.None;
                                return;
                            }
                        }
                    }
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_NOTHING)
                {
                    this.DialogResult = DialogResult.None;
                    return;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.btnCreate_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
                
        private void frmFMBCreateTool_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                Set_ReadOnly();
                init();
                
                if (cdvToolID.Text != "")
                {
                    cdvToolID.ReadOnly = true;
                    cdvToolID.BackColor = SystemColors.Control;
                    cdvToolID.VisibleButton = false;
                    if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            View_Tool(modGlobalConstant.MP_STEP_CREATE);
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            View_UDR_Tool(modGlobalConstant.MP_STEP_CREATE);
                        }
                    }
                    else
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            View_Tool(modGlobalConstant.MP_STEP_UPDATE);
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            View_UDR_Tool(modGlobalConstant.MP_STEP_UPDATE);
                        }
                    }
                }
                
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Create Tool";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Create Tool by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_UPDATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Update Tool";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Update Tool by User Define Group";
                    }
                    btnCreate.Text = "Update";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Delete Tool";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Delete Tool by User Define Group";
                    }
                    btnCreate.Text = "Delete";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_VIEW)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "View Tool";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "View Tool by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.frmFMBCreateTool_Load()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvLayOut_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                cdvLayOut.Init();
                cdvLayOut.Columns.Add("LayoutID", 100, HorizontalAlignment.Left);
                cdvLayOut.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLayOut.SelectedSubItemIndex = 0;
                cdvLayOut.SmallImageList = MPGV.gIMdiForm.GetSmallIconList();
                if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    modListRoutine.ViewLayOutList(cdvLayOut.GetListView, '1', txtFactory.Text);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.cdvLayOut_ButtonPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void txtX_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
                {
                    if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
                    {
                        e.Handled = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.txtX_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void txtY_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
                {
                    if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
                    {
                        e.Handled = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.txtY_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void txtHeight_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
                {
                    if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
                    {
                        e.Handled = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.txtHeight_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void txtWidth_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
                {
                    if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
                    {
                        e.Handled = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.txtWidth_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion

        private void cdvToolID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

            try
            {
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        View_Tool(modGlobalConstant.MP_STEP_CREATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        View_UDR_Tool(modGlobalConstant.MP_STEP_CREATE);
                    }
                }
                else
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        View_Tool(modGlobalConstant.MP_STEP_UPDATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        View_UDR_Tool(modGlobalConstant.MP_STEP_UPDATE);
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.cdvToolID_SelectedItemChanged()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }

        private void cdvToolID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvToolID.Init();
                cdvToolID.Columns.Add("ToolID", 100, HorizontalAlignment.Left);
                cdvToolID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolID.SelectedSubItemIndex = 0;
                cdvToolID.SmallImageList = MPGV.gIMdiForm.GetSmallIconList();
                if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    ViewToolList(cdvToolID.GetListView, "1");
                }
                else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    ViewUDRToolList(cdvToolID.GetListView, "1");
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTool.cdvResID_ButtonPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }
        
    }
    
}
