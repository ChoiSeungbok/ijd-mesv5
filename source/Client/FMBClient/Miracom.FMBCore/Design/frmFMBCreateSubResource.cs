#define _SPCTYPE
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Infragistics.Win.UltraWinEditors;
using Miracom.CliFrx;
using Miracom.TRSCore;
using Miracom.MESCore;
using Miracom.MsgHandler;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBCreateSubResource.vb
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
    public class frmFMBCreateSubResource : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBCreateSubResource()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        public frmFMBCreateSubResource(char sProcStep)
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
        internal System.Windows.Forms.GroupBox grpRes;
        internal System.Windows.Forms.Label lblResID;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Button btnCreate;
        internal System.Windows.Forms.Label lblLayOut;
        internal System.Windows.Forms.Label lblFactory;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcText;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBack;
        internal System.Windows.Forms.Label lblImage;
        internal System.Windows.Forms.PictureBox pctImage;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvResID;
        public Infragistics.Win.UltraWinEditors.UltraTextEditor txtFactory;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvLayOut;
        internal System.Windows.Forms.Label lblResTagFlag;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtResTagFlag;
        private GroupBox grpSubRes;
        internal Label lblSubResID;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvSubResID;
        internal UltraTextEditor txtSubDesc;
        internal Label lblSubDesc;
        internal UltraTextEditor txtUpdateTime;
        internal Label lblUpdateTime;
        internal Label lblEventTime;
        internal UltraTextEditor txtLastEventTime;
        internal UltraTextEditor txtUpdateUser;
        internal Label lblUpdateUser;
        internal UltraTextEditor txtLastEvent;
        internal Label lblLastStartTime;
        internal Label lblUpDown;
        internal UltraTextEditor txtUpDown;
        internal UltraTextEditor txtSubResType;
        internal Label lblSubResType;
        internal Label lblPriSts;
        internal UltraTextEditor txtPriSts;
        internal UltraTextEditor txtUseFacPrt;
        internal Label lblUseFacPrt;
        internal Label lblCreateTime;
        internal UltraTextEditor txtCreateTime;
        internal UltraTextEditor txtCreateUser;
        internal Label lblResourceType;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnCreate = new System.Windows.Forms.Button();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpSubRes = new System.Windows.Forms.GroupBox();
            this.txtUpdateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblUpdateTime = new System.Windows.Forms.Label();
            this.lblEventTime = new System.Windows.Forms.Label();
            this.txtLastEventTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtUpdateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblUpdateUser = new System.Windows.Forms.Label();
            this.txtLastEvent = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLastStartTime = new System.Windows.Forms.Label();
            this.lblUpDown = new System.Windows.Forms.Label();
            this.txtUpDown = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSubResType = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblSubResType = new System.Windows.Forms.Label();
            this.lblPriSts = new System.Windows.Forms.Label();
            this.txtPriSts = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtUseFacPrt = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblUseFacPrt = new System.Windows.Forms.Label();
            this.lblCreateTime = new System.Windows.Forms.Label();
            this.txtCreateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblResourceType = new System.Windows.Forms.Label();
            this.txtSubDesc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblSubDesc = new System.Windows.Forms.Label();
            this.lblSubResID = new System.Windows.Forms.Label();
            this.cdvSubResID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
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
            this.grpRes = new System.Windows.Forms.GroupBox();
            this.lblResID = new System.Windows.Forms.Label();
            this.cdvResID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.pnlBottom.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.grpSubRes.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEventTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEvent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubResType)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPriSts)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUseFacPrt)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubDesc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvSubResID)).BeginInit();
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
            this.grpRes.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvResID)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Controls.Add(this.btnCreate);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 462);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(467, 40);
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
            this.pnlMid.Controls.Add(this.grpRes);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(467, 462);
            this.pnlMid.TabIndex = 1;
            // 
            // grpSubRes
            // 
            this.grpSubRes.Controls.Add(this.txtUpdateTime);
            this.grpSubRes.Controls.Add(this.lblUpdateTime);
            this.grpSubRes.Controls.Add(this.lblEventTime);
            this.grpSubRes.Controls.Add(this.txtLastEventTime);
            this.grpSubRes.Controls.Add(this.txtUpdateUser);
            this.grpSubRes.Controls.Add(this.lblUpdateUser);
            this.grpSubRes.Controls.Add(this.txtLastEvent);
            this.grpSubRes.Controls.Add(this.lblLastStartTime);
            this.grpSubRes.Controls.Add(this.lblUpDown);
            this.grpSubRes.Controls.Add(this.txtUpDown);
            this.grpSubRes.Controls.Add(this.txtSubResType);
            this.grpSubRes.Controls.Add(this.lblSubResType);
            this.grpSubRes.Controls.Add(this.lblPriSts);
            this.grpSubRes.Controls.Add(this.txtPriSts);
            this.grpSubRes.Controls.Add(this.txtUseFacPrt);
            this.grpSubRes.Controls.Add(this.lblUseFacPrt);
            this.grpSubRes.Controls.Add(this.lblCreateTime);
            this.grpSubRes.Controls.Add(this.txtCreateTime);
            this.grpSubRes.Controls.Add(this.txtCreateUser);
            this.grpSubRes.Controls.Add(this.lblResourceType);
            this.grpSubRes.Controls.Add(this.txtSubDesc);
            this.grpSubRes.Controls.Add(this.lblSubDesc);
            this.grpSubRes.Controls.Add(this.lblSubResID);
            this.grpSubRes.Controls.Add(this.cdvSubResID);
            this.grpSubRes.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpSubRes.Location = new System.Drawing.Point(3, 59);
            this.grpSubRes.Name = "grpSubRes";
            this.grpSubRes.Size = new System.Drawing.Size(461, 182);
            this.grpSubRes.TabIndex = 2;
            this.grpSubRes.TabStop = false;
            // 
            // txtUpdateTime
            // 
            this.txtUpdateTime.Location = new System.Drawing.Point(323, 133);
            this.txtUpdateTime.MaxLength = 10;
            this.txtUpdateTime.Name = "txtUpdateTime";
            this.txtUpdateTime.ReadOnly = true;
            this.txtUpdateTime.Size = new System.Drawing.Size(120, 19);
            this.txtUpdateTime.TabIndex = 88;
            this.txtUpdateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblUpdateTime
            // 
            this.lblUpdateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateTime.Location = new System.Drawing.Point(231, 135);
            this.lblUpdateTime.Name = "lblUpdateTime";
            this.lblUpdateTime.Size = new System.Drawing.Size(88, 14);
            this.lblUpdateTime.TabIndex = 104;
            this.lblUpdateTime.Text = "Update Time";
            // 
            // lblEventTime
            // 
            this.lblEventTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblEventTime.Location = new System.Drawing.Point(231, 159);
            this.lblEventTime.Name = "lblEventTime";
            this.lblEventTime.Size = new System.Drawing.Size(89, 14);
            this.lblEventTime.TabIndex = 102;
            this.lblEventTime.Text = "Last Event Time";
            // 
            // txtLastEventTime
            // 
            this.txtLastEventTime.Location = new System.Drawing.Point(323, 157);
            this.txtLastEventTime.MaxLength = 20;
            this.txtLastEventTime.Name = "txtLastEventTime";
            this.txtLastEventTime.ReadOnly = true;
            this.txtLastEventTime.Size = new System.Drawing.Size(120, 19);
            this.txtLastEventTime.TabIndex = 90;
            this.txtLastEventTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtUpdateUser
            // 
            this.txtUpdateUser.Location = new System.Drawing.Point(104, 133);
            this.txtUpdateUser.MaxLength = 12;
            this.txtUpdateUser.Name = "txtUpdateUser";
            this.txtUpdateUser.ReadOnly = true;
            this.txtUpdateUser.Size = new System.Drawing.Size(120, 19);
            this.txtUpdateUser.TabIndex = 87;
            this.txtUpdateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblUpdateUser
            // 
            this.lblUpdateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateUser.Location = new System.Drawing.Point(9, 137);
            this.lblUpdateUser.Name = "lblUpdateUser";
            this.lblUpdateUser.Size = new System.Drawing.Size(88, 14);
            this.lblUpdateUser.TabIndex = 101;
            this.lblUpdateUser.Text = "Update User";
            // 
            // txtLastEvent
            // 
            this.txtLastEvent.Location = new System.Drawing.Point(104, 157);
            this.txtLastEvent.MaxLength = 20;
            this.txtLastEvent.Name = "txtLastEvent";
            this.txtLastEvent.ReadOnly = true;
            this.txtLastEvent.Size = new System.Drawing.Size(120, 19);
            this.txtLastEvent.TabIndex = 89;
            this.txtLastEvent.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLastStartTime
            // 
            this.lblLastStartTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastStartTime.Location = new System.Drawing.Point(9, 161);
            this.lblLastStartTime.Name = "lblLastStartTime";
            this.lblLastStartTime.Size = new System.Drawing.Size(88, 14);
            this.lblLastStartTime.TabIndex = 99;
            this.lblLastStartTime.Text = "Last Event ID";
            // 
            // lblUpDown
            // 
            this.lblUpDown.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpDown.Location = new System.Drawing.Point(231, 65);
            this.lblUpDown.Name = "lblUpDown";
            this.lblUpDown.Size = new System.Drawing.Size(88, 14);
            this.lblUpDown.TabIndex = 98;
            this.lblUpDown.Text = "Up / Down";
            // 
            // txtUpDown
            // 
            this.txtUpDown.Location = new System.Drawing.Point(323, 62);
            this.txtUpDown.MaxLength = 5;
            this.txtUpDown.Name = "txtUpDown";
            this.txtUpDown.ReadOnly = true;
            this.txtUpDown.Size = new System.Drawing.Size(120, 19);
            this.txtUpDown.TabIndex = 82;
            this.txtUpDown.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtSubResType
            // 
            this.txtSubResType.Location = new System.Drawing.Point(104, 62);
            this.txtSubResType.MaxLength = 30;
            this.txtSubResType.Name = "txtSubResType";
            this.txtSubResType.ReadOnly = true;
            this.txtSubResType.Size = new System.Drawing.Size(120, 19);
            this.txtSubResType.TabIndex = 81;
            this.txtSubResType.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblSubResType
            // 
            this.lblSubResType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSubResType.Location = new System.Drawing.Point(9, 65);
            this.lblSubResType.Name = "lblSubResType";
            this.lblSubResType.Size = new System.Drawing.Size(88, 14);
            this.lblSubResType.TabIndex = 97;
            this.lblSubResType.Text = "Sub Res Type";
            // 
            // lblPriSts
            // 
            this.lblPriSts.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblPriSts.Location = new System.Drawing.Point(231, 89);
            this.lblPriSts.Name = "lblPriSts";
            this.lblPriSts.Size = new System.Drawing.Size(88, 14);
            this.lblPriSts.TabIndex = 96;
            this.lblPriSts.Text = "Primary Status";
            // 
            // txtPriSts
            // 
            this.txtPriSts.Location = new System.Drawing.Point(323, 86);
            this.txtPriSts.MaxLength = 20;
            this.txtPriSts.Name = "txtPriSts";
            this.txtPriSts.ReadOnly = true;
            this.txtPriSts.Size = new System.Drawing.Size(120, 19);
            this.txtPriSts.TabIndex = 84;
            this.txtPriSts.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtUseFacPrt
            // 
            this.txtUseFacPrt.Location = new System.Drawing.Point(104, 86);
            this.txtUseFacPrt.MaxLength = 20;
            this.txtUseFacPrt.Name = "txtUseFacPrt";
            this.txtUseFacPrt.ReadOnly = true;
            this.txtUseFacPrt.Size = new System.Drawing.Size(120, 19);
            this.txtUseFacPrt.TabIndex = 83;
            this.txtUseFacPrt.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblUseFacPrt
            // 
            this.lblUseFacPrt.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUseFacPrt.Location = new System.Drawing.Point(9, 89);
            this.lblUseFacPrt.Name = "lblUseFacPrt";
            this.lblUseFacPrt.Size = new System.Drawing.Size(88, 14);
            this.lblUseFacPrt.TabIndex = 95;
            this.lblUseFacPrt.Text = "Use Factory Prt";
            // 
            // lblCreateTime
            // 
            this.lblCreateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateTime.Location = new System.Drawing.Point(231, 113);
            this.lblCreateTime.Name = "lblCreateTime";
            this.lblCreateTime.Size = new System.Drawing.Size(88, 14);
            this.lblCreateTime.TabIndex = 94;
            this.lblCreateTime.Text = "Create Time";
            // 
            // txtCreateTime
            // 
            this.txtCreateTime.Location = new System.Drawing.Point(323, 110);
            this.txtCreateTime.MaxLength = 10;
            this.txtCreateTime.Name = "txtCreateTime";
            this.txtCreateTime.ReadOnly = true;
            this.txtCreateTime.Size = new System.Drawing.Size(120, 19);
            this.txtCreateTime.TabIndex = 86;
            this.txtCreateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateUser
            // 
            this.txtCreateUser.Location = new System.Drawing.Point(104, 110);
            this.txtCreateUser.MaxLength = 20;
            this.txtCreateUser.Name = "txtCreateUser";
            this.txtCreateUser.ReadOnly = true;
            this.txtCreateUser.Size = new System.Drawing.Size(120, 19);
            this.txtCreateUser.TabIndex = 85;
            this.txtCreateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblResourceType
            // 
            this.lblResourceType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResourceType.Location = new System.Drawing.Point(9, 113);
            this.lblResourceType.Name = "lblResourceType";
            this.lblResourceType.Size = new System.Drawing.Size(88, 14);
            this.lblResourceType.TabIndex = 93;
            this.lblResourceType.Text = "Create User";
            // 
            // txtSubDesc
            // 
            this.txtSubDesc.Location = new System.Drawing.Point(104, 37);
            this.txtSubDesc.MaxLength = 50;
            this.txtSubDesc.Name = "txtSubDesc";
            this.txtSubDesc.ReadOnly = true;
            this.txtSubDesc.Size = new System.Drawing.Size(340, 19);
            this.txtSubDesc.TabIndex = 56;
            this.txtSubDesc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblSubDesc
            // 
            this.lblSubDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSubDesc.Location = new System.Drawing.Point(9, 40);
            this.lblSubDesc.Name = "lblSubDesc";
            this.lblSubDesc.Size = new System.Drawing.Size(88, 14);
            this.lblSubDesc.TabIndex = 57;
            this.lblSubDesc.Text = "Description";
            // 
            // lblSubResID
            // 
            this.lblSubResID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSubResID.Location = new System.Drawing.Point(9, 16);
            this.lblSubResID.Name = "lblSubResID";
            this.lblSubResID.Size = new System.Drawing.Size(88, 14);
            this.lblSubResID.TabIndex = 30;
            this.lblSubResID.Text = "Sub Resource ID";
            // 
            // cdvSubResID
            // 
            this.cdvSubResID.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvSubResID.BorderHotColor = System.Drawing.Color.Black;
            this.cdvSubResID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvSubResID.BtnToolTipText = "";
            this.cdvSubResID.DescText = "";
            this.cdvSubResID.DisplaySubItemIndex = -1;
            this.cdvSubResID.DisplayText = "";
            this.cdvSubResID.Focusing = null;
            this.cdvSubResID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvSubResID.Index = 0;
            this.cdvSubResID.IsViewBtnImage = false;
            this.cdvSubResID.Location = new System.Drawing.Point(104, 13);
            this.cdvSubResID.MaxLength = 20;
            this.cdvSubResID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvSubResID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvSubResID.Name = "cdvSubResID";
            this.cdvSubResID.ReadOnly = false;
            this.cdvSubResID.SearchSubItemIndex = 0;
            this.cdvSubResID.SelectedDescIndex = -1;
            this.cdvSubResID.SelectedSubItemIndex = -1;
            this.cdvSubResID.SelectionStart = 0;
            this.cdvSubResID.Size = new System.Drawing.Size(200, 20);
            this.cdvSubResID.SmallImageList = null;
            this.cdvSubResID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvSubResID.TabIndex = 29;
            this.cdvSubResID.TextBoxToolTipText = "";
            this.cdvSubResID.TextBoxWidth = 200;
            this.cdvSubResID.VisibleButton = true;
            this.cdvSubResID.VisibleColumnHeader = false;
            this.cdvSubResID.VisibleDescription = false;
            this.cdvSubResID.ButtonPress += new System.EventHandler(this.cdvSubResID_ButtonPress);
            this.cdvSubResID.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvSubResID_SelectedItemChanged);
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
            this.grpInfo.Location = new System.Drawing.Point(3, 241);
            this.grpInfo.Name = "grpInfo";
            this.grpInfo.Size = new System.Drawing.Size(461, 221);
            this.grpInfo.TabIndex = 1;
            this.grpInfo.TabStop = false;
            // 
            // pctImage
            // 
            this.pctImage.Location = new System.Drawing.Point(396, 66);
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
            this.utcBack.Location = new System.Drawing.Point(323, 125);
            this.utcBack.Name = "utcBack";
            this.utcBack.Size = new System.Drawing.Size(120, 19);
            this.utcBack.TabIndex = 7;
            this.utcBack.Text = "Control";
            this.utcBack.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // utcText
            // 
            this.utcText.Location = new System.Drawing.Point(104, 125);
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
            this.txtY.Location = new System.Drawing.Point(323, 149);
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
            this.lblY.Location = new System.Drawing.Point(231, 153);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(88, 14);
            this.lblY.TabIndex = 47;
            this.lblY.Text = "Location Y";
            // 
            // txtHeight
            // 
            this.txtHeight.Location = new System.Drawing.Point(323, 173);
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
            this.lblHeight.Location = new System.Drawing.Point(231, 177);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(88, 14);
            this.lblHeight.TabIndex = 45;
            this.lblHeight.Text = "Height";
            // 
            // txtWidth
            // 
            this.txtWidth.Location = new System.Drawing.Point(104, 173);
            this.txtWidth.MaxLength = 6;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(120, 19);
            this.txtWidth.TabIndex = 10;
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtWidth.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtWidth_KeyPress);
            // 
            // txtX
            // 
            this.txtX.Location = new System.Drawing.Point(104, 149);
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
            this.lblWidth.Location = new System.Drawing.Point(12, 177);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(88, 14);
            this.lblWidth.TabIndex = 42;
            this.lblWidth.Text = "Width";
            // 
            // lblX
            // 
            this.lblX.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblX.Location = new System.Drawing.Point(12, 153);
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
            this.txtResTagFlag.Text = "S";
            this.txtResTagFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblBackColor
            // 
            this.lblBackColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBackColor.Location = new System.Drawing.Point(231, 128);
            this.lblBackColor.Name = "lblBackColor";
            this.lblBackColor.Size = new System.Drawing.Size(88, 14);
            this.lblBackColor.TabIndex = 37;
            this.lblBackColor.Text = "Back Color";
            // 
            // cboTextStyle
            // 
            this.cboTextStyle.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboTextStyle.Location = new System.Drawing.Point(323, 100);
            this.cboTextStyle.Name = "cboTextStyle";
            this.cboTextStyle.Size = new System.Drawing.Size(120, 19);
            this.cboTextStyle.TabIndex = 5;
            this.cboTextStyle.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblStyle
            // 
            this.lblStyle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblStyle.Location = new System.Drawing.Point(231, 103);
            this.lblStyle.Name = "lblStyle";
            this.lblStyle.Size = new System.Drawing.Size(88, 14);
            this.lblStyle.TabIndex = 34;
            this.lblStyle.Text = "Text Style";
            // 
            // lblColor
            // 
            this.lblColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblColor.Location = new System.Drawing.Point(12, 128);
            this.lblColor.Name = "lblColor";
            this.lblColor.Size = new System.Drawing.Size(88, 14);
            this.lblColor.TabIndex = 33;
            this.lblColor.Text = "Text Color";
            // 
            // cboSize
            // 
            this.cboSize.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboSize.Location = new System.Drawing.Point(104, 100);
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
            this.txtSize.Location = new System.Drawing.Point(12, 104);
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
            // grpRes
            // 
            this.grpRes.Controls.Add(this.lblResID);
            this.grpRes.Controls.Add(this.cdvResID);
            this.grpRes.Dock = System.Windows.Forms.DockStyle.Top;
            this.grpRes.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpRes.Location = new System.Drawing.Point(3, 0);
            this.grpRes.Name = "grpRes";
            this.grpRes.Size = new System.Drawing.Size(461, 59);
            this.grpRes.TabIndex = 0;
            this.grpRes.TabStop = false;
            // 
            // lblResID
            // 
            this.lblResID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResID.Location = new System.Drawing.Point(9, 20);
            this.lblResID.Name = "lblResID";
            this.lblResID.Size = new System.Drawing.Size(88, 14);
            this.lblResID.TabIndex = 28;
            this.lblResID.Text = "Resource ID";
            // 
            // cdvResID
            // 
            this.cdvResID.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvResID.BorderHotColor = System.Drawing.Color.Black;
            this.cdvResID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvResID.BtnToolTipText = "";
            this.cdvResID.DescText = "";
            this.cdvResID.DisplaySubItemIndex = -1;
            this.cdvResID.DisplayText = "";
            this.cdvResID.Focusing = null;
            this.cdvResID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvResID.Index = 0;
            this.cdvResID.IsViewBtnImage = false;
            this.cdvResID.Location = new System.Drawing.Point(104, 17);
            this.cdvResID.MaxLength = 20;
            this.cdvResID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvResID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvResID.Name = "cdvResID";
            this.cdvResID.ReadOnly = false;
            this.cdvResID.SearchSubItemIndex = 0;
            this.cdvResID.SelectedDescIndex = -1;
            this.cdvResID.SelectedSubItemIndex = -1;
            this.cdvResID.SelectionStart = 0;
            this.cdvResID.Size = new System.Drawing.Size(200, 20);
            this.cdvResID.SmallImageList = null;
            this.cdvResID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvResID.TabIndex = 0;
            this.cdvResID.TextBoxToolTipText = "";
            this.cdvResID.TextBoxWidth = 200;
            this.cdvResID.VisibleButton = true;
            this.cdvResID.VisibleColumnHeader = false;
            this.cdvResID.VisibleDescription = false;
            this.cdvResID.ButtonPress += new System.EventHandler(this.cdvResID_ButtonPress);
            this.cdvResID.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvResID_SelectedItemChanged);
            // 
            // frmFMBCreateSubResource
            // 
            this.AcceptButton = this.btnCreate;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btnClose;
            this.ClientSize = new System.Drawing.Size(467, 502);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFMBCreateSubResource";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Create Sub Resource";
            this.Load += new System.EventHandler(this.frmFMBCreateSubResource_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.grpSubRes.ResumeLayout(false);
            this.grpSubRes.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEventTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEvent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubResType)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPriSts)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUseFacPrt)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubDesc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvSubResID)).EndInit();
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
            this.grpRes.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvResID)).EndInit();
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
                Miracom.FMBUI.Controls.udcCtrlSubResource ctrlSubResource = new Miracom.FMBUI.Controls.udcCtrlSubResource(modGlobalVariable.gimlResource);
                imlRes = ctrlSubResource.imlResource;
                
                FMBCF.SetEnumList(cboTextStyle, typeof(FontStyle));
                FMBCF.SetFontSize(cboSize);
                cboSize.Text = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextSize));
                cboTextStyle.SelectedIndex = 0;
                utcText.Color =   (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextColor);
                utcBack.Color = (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultBackColor);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.init()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                    cdvResID.ReadOnly = true;
                    cdvResID.BackColor = SystemColors.Control;
                    cdvResID.VisibleButton = false;
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
                    cdvResID.ReadOnly = true;
                    cdvResID.BackColor = SystemColors.Control;
                    cdvResID.VisibleButton = false;
                    
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
                    cdvResID.ReadOnly = true;
                    cdvResID.BackColor = SystemColors.Control;
                    cdvResID.VisibleButton = false;
                    
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.Set_ReadOnly()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                if (cdvResID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), "FMB Client", MessageBoxButtons.OK, 1);
                    cdvResID.Focus();
                    return false;
                }
                if (cdvSubResID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), "FMB Client", MessageBoxButtons.OK, 1);
                    cdvSubResID.Focus();
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.CheckCondition()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("SUBRES_ID", MPCF.Trim(cdvSubResID.Text));
                in_node.AddChar("RES_TYPE", txtResTagFlag.Text[0]);
                in_node.AddString("TEXT", txtText.Text);
                in_node.AddChar("NO_MOUSE_EVENT", ' ');
                in_node.AddInt("IMAGE_IDX", 0);
                //in_node.Add("RES_TYPE", 'S');

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
        
        // ViewResourceList()
        //       - View Resource List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - control as Control : Control
        //       - sStep as String    : Proc Step
        //
        private bool ViewResourceList(Control control, string sStep)
        {
            
            try
            {
                TRSNode in_node = new TRSNode("FMB_View_Resource_List_In");
                TRSNode out_node;
                  
                int i;
                ListViewItem itmX;
                ArrayList a_list = new ArrayList();
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '6';
                in_node.Factory = txtFactory.Text;
                in_node.AddString("LAYOUT_ID", cdvLayOut.Text);
                in_node.AddString("NEXT_SUBRES_ID", "");
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("SUBRES_ID", cdvSubResID.Text);
                
                do
                {
                    out_node = new TRSNode("FMB_View_Resource_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_Sub_Resource_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);

                    in_node.SetString("NEXT_SUBRES_ID", out_node.GetString("NEXT_SUBRES_ID"));
                } while (in_node.GetString("NEXT_SUBRES_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            if (out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG") == 'U')
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE));
                            }
                            else
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE_DOWN));
                            }
                            if (((ListView)control).Columns.Count > 1)
                            {
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_DESC")));
                            }
                            ((ListView)control).Items.Add(itmX);
                        }
                    }
                }

                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.ViewResourceList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }


        private bool ViewSubResourceList(Control control, string sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_SUB_RESOURCE_LIST_IN");
                TRSNode out_node = new TRSNode("VIEW_SUB_RESOURCE_LIST_OUT");

                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = txtFactory.Text;
                in_node.AddString("NEXT_SUBRES_ID", "");
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("SUBRES_ID", cdvSubResID.Text);
                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_Sub_Resource_List", in_node, ref out_node) == false)
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
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_SUB_EQUIP));

                                if (((ListView)control).Columns.Count > 1)
                                {
                                    if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")) == MPCF.Trim(cdvResID.Text))
                                    {
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_DESC")));

                                    }
                                }
                                ((ListView)control).Items.Add(itmX);
                            }
                        }
                    }

                    in_node.SetString("NEXT_SUBRES_ID", out_node.GetString("NEXT_SUBRES_ID"));
                } while (string.IsNullOrEmpty(out_node.GetString("NEXT_SUBRES_ID")) == false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.ViewResourceList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }


        // ViewUDRSubResourceList()
        //       - View Resource Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //

        private bool ViewUDRSubResourceList(Control control, string sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_UDR_SUB_RESOURCE_LIST_IN");
                TRSNode out_node = new TRSNode("VIEW_UDR_SUB_RESOURCE_LIST_OUT");

                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("NEXT_SUBRES_ID", "");
                in_node.AddString("GROUP_ID", cdvLayOut.Text);
                in_node.AddString("RES_ID", cdvResID.Text);

                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_UDR_Sub_Resource_List", in_node, ref out_node) == false)
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
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_SUB_EQUIP));

                                if (((ListView)control).Columns.Count > 1)
                                {
                                    if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")) == MPCF.Trim(cdvResID.Text))
                                    {
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_DESC")));

                                    }
                                }
                                ((ListView)control).Items.Add(itmX);
                            }
                        }
                    }

                    in_node.SetString("NEXT_SUBRES_ID", out_node.GetString("NEXT_SUBRES_ID"));
                } while (string.IsNullOrEmpty(out_node.GetString("NEXT_SUBRES_ID")) == false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.ViewResourceList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }



        // View_Resource()
        //       - View Resource Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //
        private bool View_Resource(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_RESOURCE_IN");
                TRSNode out_node = new TRSNode("VIEW_RESOURCE_OUT");

                MPCR.SetInMsg(in_node);
                in_node.Passport = MPGV.gsPassport;
                in_node.Language = MPGV.gcLanguage;
                in_node.Factory = txtFactory.Text;
                in_node.UserID = MPGV.gsUserID;
                in_node.Password = MPGV.gsPassword;
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddChar("RES_TYPE", ' ');

                if (MPCR.CallService("FMB", "FMB_View_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }
                if (sStep != modGlobalConstant.MP_STEP_CREATE)
                {
                    cdvLayOut.Text = MPCF.RTrim(out_node.GetString("LAYOUT_ID"));

                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.View_Resource()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }



        // View Sub Resource()
        //       - View Sub Resource Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //
        private void View_Sub_Resource(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_SUB_RESOURCE_IN");
                TRSNode out_node = new TRSNode("VIEW_SUB_RESOURCE_OUT");

                MPCR.SetInMsg(in_node);
                in_node.Factory = txtFactory.Text;
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("SUBRES_ID", cdvSubResID.Text);
                in_node.AddString("LAYOUT_ID", cdvLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_Sub_Resource", in_node, ref out_node) == false)
                {
                	return;
                }
                if (sStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    cdvSubResID.Text = out_node.GetString("SUBRES_ID");
                    txtSubDesc.Text = out_node.GetString("SUBRES_DESC");
                    txtSubResType.Text = out_node.GetString("SUBRES_TYPE");
                    txtCreateUser.Text = out_node.GetString("CREATE_USER_ID");
                    txtCreateTime.Text = out_node.GetString("CREATE_TIME");
                    txtUpdateUser.Text = out_node.GetString("UPDATE_USER_ID");
                    txtUpdateTime.Text = out_node.GetString("UPDATE_TIME");
                    txtLastEvent.Text  = out_node.GetString("LAST_EVENT_ID");
                    txtLastEventTime.Text = out_node.GetString("LAST_EVENT_TIME");
                    txtText.Text = cdvSubResID.Text;
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString());
                    txtPriSts.Text = out_node.GetString("SUBRES_PRI_STS");

                    if (out_node.GetInt("IMAGE_IDX") != -1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
                    {
                        iImageIndex = out_node.GetInt("IMAGE_IDX");
                        pctImage.Image = imlRes.Images[iImageIndex];
                    }
                    else
                    {
                        pctImage.Image = null;
                    }

                    if (MPCF.RTrim(out_node.GetChar("SUBRES_UP_DOWN_FLAG")) == "U")
                    {
                        txtUpDown.Text = "UP";
                    }
                    else if (MPCF.RTrim(out_node.GetChar("SUBRES_UP_DOWN_FLAG")) == "D")
                    {
                        txtUpDown.Text = "DOWN";
                    }

                }
                else
                {
                    cdvResID.Text = out_node.GetString("RES_ID");
                    cdvSubResID.Text = out_node.GetString("SUBRES_ID");
                    txtSubDesc.Text = out_node.GetString("SUBRES_DESC");
                    cdvLayOut.Text = MPCF.RTrim(out_node.GetString("LAYOUT_ID"));
                    txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString());
                    txtSubResType.Text = out_node.GetString("SUBRES_TYPE");
                    txtCreateUser.Text = out_node.GetString("CREATE_USER_ID");
                    txtCreateTime.Text = out_node.GetString("CREATE_TIME");
                    txtUpdateUser.Text = out_node.GetString("UPDATE_USER_ID");
                    txtUpdateTime.Text = out_node.GetString("UPDATE_TIME");
                    txtLastEvent.Text = out_node.GetString("LAST_EVENT_ID");
                    txtLastEventTime.Text = out_node.GetString("LAST_EVENT_TIME");
                    txtPriSts.Text = out_node.GetString("SUBRES_PRI_STS");


                    if (out_node.GetInt("TEXT_SIZE") < 4 || out_node.GetInt("TEXT_SIZE") > 20)
                    {
                        cboSize.Text = "8";
                    }
                    else
                    {
                        cboSize.Text = MPCF.Trim(out_node.GetInt("TEXT_SIZE"));
                    }
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
                        //utcBack.Color = utcBack.Color.FromArgb(View_Resource_Out.back_color);
                        utcBack.Color = Color.FromArgb(out_node.GetInt("BACK_COLOR"));
                    }
                    else if (out_node.GetInt("BACK_COLOR") > 0)
                    {
                        //utcBack.Color = utcBack.Color.FromKnownColor((KnownColor)View_Resource_Out.back_color);
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

                if (MPCF.RTrim(out_node.GetChar("SUBRES_UP_DOWN_FLAG")) == "U")
                {
                    txtUpDown.Text = "UP";
                }
                else if (MPCF.RTrim(out_node.GetChar("SUBRES_UP_DOWN_FLAG")) == "D")
                {
                    txtUpDown.Text = "DOWN";
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.View_Resource()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }

        }


        // ViewUDRResourceList()
        //       - View Resource List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - control as Control : Control
        //       - sStep as String    : Proc Step
        //
        private bool ViewUDRResourceList(Control control, string sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_UDR_SUB_RESOURCE_LIST_IN");
                TRSNode out_node = new TRSNode("VIEW_UDR_SUB_RESOURCE_LIST_OUT");

                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '6';
                in_node.Factory = txtFactory.Text;
                in_node.AddString("GROUP_ID", cdvLayOut.Text);
                in_node.AddString("NEXT_SUBRES_ID", "");
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("SUBRES_ID", cdvSubResID.Text);

                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_UDR_Sub_Resource_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {

                        if (control is ListView)
                        {
                            if (out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG") == 'U')
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE));
                            }
                            else
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE_DOWN));
                            }
                            if (((ListView)control).Columns.Count > 1)
                            {
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_DESC")));
                            }
                            ((ListView)control).Items.Add(itmX);

                        }
                    }

                    in_node.SetString("NEXT_SUBRES_ID", out_node.GetString("NEXT_SUBRES_ID"));
                } while (string.IsNullOrEmpty(out_node.GetString("NEXT_SUBRES_ID")) == false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.ViewUDRResourceList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }

        
        // View_UDR_Resource()
        //       - View User Define Resource Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //
        private bool View_UDR_Resource(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_UDR_RESOURCE_IN");
                TRSNode out_node = new TRSNode("VIEW_UDR_RESOURCE_OUT");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("GROUP_ID", cdvLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_UDR_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.View_UDR_Resource()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }



        // View_UDR_Sub_Resource()
        //       - View User Define Resource Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //
        private bool View_UDR_Sub_Resource(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_UDR_SUB_RESOURCE_IN");
                TRSNode out_node = new TRSNode("VIEW_UDR_SUB_RESOURCE_OUT");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("SUBRES_ID", cdvSubResID.Text);
                in_node.AddString("GROUP_ID", cdvLayOut.Text);


                if (MPCR.CallService("FMB", "FMB_View_UDR_Sub_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }
                if (sStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    cdvSubResID.Text = out_node.GetString("SUBRES_ID");
                    txtSubDesc.Text = out_node.GetString("SUBRES_DESC");
                    txtSubResType.Text = out_node.GetString("SUBRES_TYPE");
                    if (out_node.GetChar("SUBRES_UP_DOWN_FLAG") == 'U')
                    {
                        txtUpDown.Text = "UP";
                    }
                    else if (out_node.GetChar("SUBRES_UP_DOWN_FLAG") == 'D')
                    {
                        txtUpDown.Text = "Down";
                    }
                    txtUseFacPrt.Text = out_node.GetChar("USE_FAC_PRT_FLAG").ToString();
                    txtPriSts.Text = out_node.GetString("SUBRES_PRI_STS");
                    txtCreateUser.Text = out_node.GetString("CREATE_USER_ID");
                    txtCreateTime.Text = out_node.GetString("CREATE_TIME");
                    txtUpdateUser.Text = out_node.GetString("UPDATE_USER_ID");
                    txtUpdateTime.Text = out_node.GetString("UPDATE_TIME");
                    txtLastEventTime.Text = out_node.GetString("LAST_EVENT_TIME");
                    txtLastEvent.Text = out_node.GetString("LAST_EVENT_ID");
                    txtText.Text = cdvSubResID.Text;
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString());

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


                    cdvResID.Text = out_node.GetString("RES_ID");
                    txtSubDesc.Text = out_node.GetString("SUBRES_DESC");
                    cdvSubResID.Text = out_node.GetString("SUBRES_ID");
                    txtSubDesc.Text = out_node.GetString("SUBRES_DESC");
                    cdvLayOut.Text = MPCF.RTrim(out_node.GetString("GROUP_ID"));
                    txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString());
                    txtSubResType.Text = out_node.GetString("SUBRES_TYPE");
                    txtCreateUser.Text = out_node.GetString("CREATE_USER_ID");
                    txtCreateTime.Text = out_node.GetString("CREATE_TIME");
                    txtUpdateUser.Text = out_node.GetString("UPDATE_USER_ID");
                    txtUpdateTime.Text = out_node.GetString("UPDATE_TIME");
                    txtLastEvent.Text = out_node.GetString("LAST_EVENT_ID");
                    txtLastEventTime.Text = out_node.GetString("LAST_EVENT_TIME");
                    txtText.Text = cdvSubResID.Text;
                    txtPriSts.Text = out_node.GetString("SUBRES_PRI_STS");


                    if (out_node.GetInt("TEXT_SIZE") < 4 || out_node.GetInt("TEXT_SIZE") > 20)
                    {
                        cboSize.Text = "8";
                    }
                    else
                    {
                        cboSize.Text = MPCF.Trim(out_node.GetInt("TEXT_SIZE"));
                    }
                    if (MPCF.RTrim(out_node.GetChar("SUBRES_UP_DOWN_FLAG")) == "U")
                    {
                        txtUpDown.Text = "UP";
                    }
                    else if (MPCF.RTrim(out_node.GetChar("SUBRES_UP_DOWN_FLAG")) == "D")
                    {
                        txtUpDown.Text = "DOWN";
                    }
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
                        utcBack.Color = Color.FromArgb(out_node.GetInt("BACK_COLOR"));
                    }
                    else if (out_node.GetInt("BACK_COLOR") > 0)
                    {
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.View_UDR_Resource()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddChar("RES_TYPE", txtResTagFlag.Text[0]);
                in_node.AddString("SUBRES_ID", MPCF.Trim(cdvSubResID.Text));
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.Update_UDR_ResLoc()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.btnClose_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvResID_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                cdvResID.Init();
                cdvResID.Columns.Add("ResID", 100, HorizontalAlignment.Left);
                cdvResID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResID.SelectedSubItemIndex = 0;
                cdvResID.SmallImageList = MPGV.gIMdiForm.GetSmallIconList();
                if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    ViewResourceList(cdvResID.GetListView, "1");
                }
                else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    ViewUDRResourceList(cdvResID.GetListView, "1");
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.cdvResID_ButtonPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                            if (FMBFI.gIMdiForm.RefreshDesignList("2", txtFactory.Text, cdvLayOut.Text, cdvSubResID.Text, cdvResID.Text, "") == false)
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
                            if (FMBFI.gIMdiForm.RefreshDesignList("2", txtFactory.Text, cdvLayOut.Text, cdvSubResID.Text,cdvResID.Text,  "") == false)
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.btnCreate_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvSubResID_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        View_Sub_Resource(modGlobalConstant.MP_STEP_CREATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        View_UDR_Sub_Resource(modGlobalConstant.MP_STEP_CREATE);
                    }
                }
                else
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        View_Sub_Resource(modGlobalConstant.MP_STEP_UPDATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        View_UDR_Sub_Resource(modGlobalConstant.MP_STEP_UPDATE);
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.cdvResID_SelectedItemChanged()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }

        private void cdvResID_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

            try
            {
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                       // View_Resource(modGlobalConstant.MP_STEP_CREATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                       // View_UDR_Resource(modGlobalConstant.MP_STEP_CREATE);
                    }
                }
                else
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        //View_Resource(modGlobalConstant.MP_STEP_UPDATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        //View_UDR_Resource(modGlobalConstant.MP_STEP_UPDATE);
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.cdvResID_SelectedItemChanged()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }

        }
        
        private void frmFMBCreateSubResource_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                Set_ReadOnly();
                init();
                
                if (cdvSubResID.Text != "")
                {
                    cdvResID.ReadOnly = true;
                    cdvResID.BackColor = SystemColors.Control;
                    cdvResID.VisibleButton = false;
                    cdvSubResID.ReadOnly = true;
                    cdvSubResID.BackColor = SystemColors.Control;
                    cdvSubResID.VisibleButton = false;
                    if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            View_Sub_Resource(modGlobalConstant.MP_STEP_CREATE);
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            View_UDR_Sub_Resource(modGlobalConstant.MP_STEP_CREATE);
                        }
                    }
                    else
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            View_Sub_Resource(modGlobalConstant.MP_STEP_UPDATE);
                            View_Resource(modGlobalConstant.MP_STEP_CREATE);
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            View_UDR_Sub_Resource(modGlobalConstant.MP_STEP_UPDATE);
                        }
                    }
                }
                
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Create Sub Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Create Sub Resource by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_UPDATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Update Sub Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Update Sub Resource by User Define Group";
                    }
                    btnCreate.Text = "Update";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Delete Sub Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Delete Sub Resource by User Define Group";
                    }
                    btnCreate.Text = "Delete";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_VIEW)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "View Sub Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "View Sub Resource by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.frmFMBCreateSubResource_Load()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.cdvLayOut_ButtonPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.txtX_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.txtY_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.txtHeight_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateSubResource.txtWidth_KeyPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion

        private void cdvSubResID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvSubResID.Init();
                cdvSubResID.Columns.Add("SubResID", 100, HorizontalAlignment.Left);
                cdvSubResID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvSubResID.SelectedSubItemIndex = 0;
                cdvSubResID.SmallImageList = MPGV.gIMdiForm.GetSmallIconList();
                if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    ViewSubResourceList(cdvSubResID.GetListView, "1");
                }
                else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    ViewUDRSubResourceList(cdvSubResID.GetListView, "1");
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateSubResource.cdvResID_ButtonPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }

       
        
    }
    
}
