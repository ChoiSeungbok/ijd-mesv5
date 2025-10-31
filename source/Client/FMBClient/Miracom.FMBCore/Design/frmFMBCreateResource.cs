
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
//   File Name   : frmFMBCreateResource.vb
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
    public class frmFMBCreateResource : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBCreateResource()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        public frmFMBCreateResource(char sProcStep)
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
        internal UltraTextEditor txtDesc;
        internal System.Windows.Forms.Label lblDesc;
        internal UltraTextEditor txtProcMode;
        internal System.Windows.Forms.Label lblProcMode;
        internal System.Windows.Forms.Label lblSubArea;
        internal UltraTextEditor txtSubArea;
        internal UltraTextEditor txtArea;
        internal System.Windows.Forms.Label lblArea;
        internal System.Windows.Forms.Label lblUpDown;
        internal UltraTextEditor txtUpDown;
        internal UltraTextEditor txtPriSts;
        internal System.Windows.Forms.Label lblPriSts;
        internal System.Windows.Forms.Label lblEventTime;
        internal UltraTextEditor txtLastEventTime;
        internal UltraTextEditor txtLastEvent;
        internal System.Windows.Forms.Label lblLastEvent;
        internal System.Windows.Forms.Label lblLastEnd;
        internal UltraTextEditor txtLastEnd;
        internal UltraTextEditor txtLastStart;
        internal System.Windows.Forms.Label lblLastStartTime;
        internal UltraTextEditor txtLastDown;
        internal System.Windows.Forms.Label lblDown;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcText;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBack;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtCtrlMode;
        internal System.Windows.Forms.Label lblCtrlMode;
        internal System.Windows.Forms.Label lblImage;
        internal System.Windows.Forms.PictureBox pctImage;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvResID;
        public Infragistics.Win.UltraWinEditors.UltraTextEditor txtFactory;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvLayOut;
        internal System.Windows.Forms.Label lblResTagFlag;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtResTagFlag;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtResourceType;
        internal System.Windows.Forms.Label lblResourceType;
        internal Label lblShape;
        internal Label lblSignalPos;
        internal UltraComboEditor cboSignalPos;
        internal UltraTextEditor txtWIP;
        internal UltraComboEditor cboShape;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            Infragistics.Win.ValueListItem valueListItem1 = new Infragistics.Win.ValueListItem();
            Infragistics.Win.ValueListItem valueListItem2 = new Infragistics.Win.ValueListItem();
            Infragistics.Win.ValueListItem valueListItem3 = new Infragistics.Win.ValueListItem();
            Infragistics.Win.ValueListItem valueListItem4 = new Infragistics.Win.ValueListItem();
            Infragistics.Win.ValueListItem valueListItem5 = new Infragistics.Win.ValueListItem();
            Infragistics.Win.ValueListItem valueListItem6 = new Infragistics.Win.ValueListItem();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnCreate = new System.Windows.Forms.Button();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpInfo = new System.Windows.Forms.GroupBox();
            this.lblSignalPos = new System.Windows.Forms.Label();
            this.cboSignalPos = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.lblShape = new System.Windows.Forms.Label();
            this.cboShape = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
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
            this.txtCtrlMode = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCtrlMode = new System.Windows.Forms.Label();
            this.txtLastDown = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblDown = new System.Windows.Forms.Label();
            this.lblEventTime = new System.Windows.Forms.Label();
            this.txtLastEventTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLastEvent = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLastEvent = new System.Windows.Forms.Label();
            this.lblLastEnd = new System.Windows.Forms.Label();
            this.txtLastEnd = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLastStart = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLastStartTime = new System.Windows.Forms.Label();
            this.lblUpDown = new System.Windows.Forms.Label();
            this.txtUpDown = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtPriSts = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblPriSts = new System.Windows.Forms.Label();
            this.lblSubArea = new System.Windows.Forms.Label();
            this.txtSubArea = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtArea = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblArea = new System.Windows.Forms.Label();
            this.lblProcMode = new System.Windows.Forms.Label();
            this.txtProcMode = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtResourceType = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblResourceType = new System.Windows.Forms.Label();
            this.txtDesc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblDesc = new System.Windows.Forms.Label();
            this.lblResID = new System.Windows.Forms.Label();
            this.cdvResID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.txtWIP = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.pnlBottom.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.grpInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cboSignalPos)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboShape)).BeginInit();
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
            ((System.ComponentModel.ISupportInitialize)(this.txtCtrlMode)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEventTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEvent)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEnd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastStart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpDown)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPriSts)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubArea)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtArea)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcMode)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtResourceType)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvResID)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWIP)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.txtWIP);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Controls.Add(this.btnCreate);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 426);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(458, 40);
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
            this.pnlMid.Controls.Add(this.grpInfo);
            this.pnlMid.Controls.Add(this.grpRes);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(458, 426);
            this.pnlMid.TabIndex = 1;
            // 
            // grpInfo
            // 
            this.grpInfo.Controls.Add(this.lblSignalPos);
            this.grpInfo.Controls.Add(this.cboSignalPos);
            this.grpInfo.Controls.Add(this.lblShape);
            this.grpInfo.Controls.Add(this.cboShape);
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
            this.grpInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpInfo.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpInfo.Location = new System.Drawing.Point(3, 210);
            this.grpInfo.Name = "grpInfo";
            this.grpInfo.Size = new System.Drawing.Size(452, 216);
            this.grpInfo.TabIndex = 1;
            this.grpInfo.TabStop = false;
            // 
            // lblSignalPos
            // 
            this.lblSignalPos.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSignalPos.Location = new System.Drawing.Point(231, 95);
            this.lblSignalPos.Name = "lblSignalPos";
            this.lblSignalPos.Size = new System.Drawing.Size(88, 14);
            this.lblSignalPos.TabIndex = 61;
            this.lblSignalPos.Text = "Signal Position";
            // 
            // cboSignalPos
            // 
            this.cboSignalPos.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            valueListItem1.DataValue = "ValueListItem0";
            valueListItem1.DisplayText = "No Signal";
            valueListItem2.DataValue = "ValueListItem1";
            valueListItem2.DisplayText = "Left";
            valueListItem3.DataValue = "ValueListItem2";
            valueListItem3.DisplayText = "Right";
            valueListItem4.DataValue = "ValueListItem3";
            valueListItem4.DisplayText = "Top";
            valueListItem5.DataValue = "ValueListItem4";
            valueListItem5.DisplayText = "Bottom";
            valueListItem6.DataValue = "Operation Mode";
            this.cboSignalPos.Items.AddRange(new Infragistics.Win.ValueListItem[] {
            valueListItem1,
            valueListItem2,
            valueListItem3,
            valueListItem4,
            valueListItem5,
            valueListItem6});
            this.cboSignalPos.Location = new System.Drawing.Point(323, 93);
            this.cboSignalPos.Name = "cboSignalPos";
            this.cboSignalPos.Size = new System.Drawing.Size(120, 19);
            this.cboSignalPos.TabIndex = 60;
            this.cboSignalPos.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblShape
            // 
            this.lblShape.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblShape.Location = new System.Drawing.Point(12, 97);
            this.lblShape.Name = "lblShape";
            this.lblShape.Size = new System.Drawing.Size(88, 14);
            this.lblShape.TabIndex = 59;
            this.lblShape.Text = "Resource Shape";
            // 
            // cboShape
            // 
            this.cboShape.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboShape.Location = new System.Drawing.Point(104, 93);
            this.cboShape.Name = "cboShape";
            this.cboShape.Size = new System.Drawing.Size(120, 19);
            this.cboShape.TabIndex = 58;
            this.cboShape.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.cboShape.SelectionChanged += new System.EventHandler(this.cboShape_SelectionChanged);
            // 
            // pctImage
            // 
            this.pctImage.Location = new System.Drawing.Point(396, 52);
            this.pctImage.Name = "pctImage";
            this.pctImage.Size = new System.Drawing.Size(32, 32);
            this.pctImage.TabIndex = 55;
            this.pctImage.TabStop = false;
            // 
            // lblImage
            // 
            this.lblImage.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblImage.Location = new System.Drawing.Point(323, 61);
            this.lblImage.Name = "lblImage";
            this.lblImage.Size = new System.Drawing.Size(60, 14);
            this.lblImage.TabIndex = 54;
            this.lblImage.Text = "Image";
            // 
            // utcBack
            // 
            this.utcBack.Location = new System.Drawing.Point(323, 142);
            this.utcBack.Name = "utcBack";
            this.utcBack.Size = new System.Drawing.Size(120, 19);
            this.utcBack.TabIndex = 7;
            this.utcBack.Text = "Control";
            this.utcBack.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // utcText
            // 
            this.utcText.Location = new System.Drawing.Point(104, 142);
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
            this.txtY.Location = new System.Drawing.Point(323, 166);
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
            this.lblY.Location = new System.Drawing.Point(231, 170);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(88, 14);
            this.lblY.TabIndex = 47;
            this.lblY.Text = "Location Y";
            // 
            // txtHeight
            // 
            this.txtHeight.Location = new System.Drawing.Point(323, 190);
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
            this.lblHeight.Location = new System.Drawing.Point(231, 194);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(88, 14);
            this.lblHeight.TabIndex = 45;
            this.lblHeight.Text = "Height";
            // 
            // txtWidth
            // 
            this.txtWidth.Location = new System.Drawing.Point(104, 190);
            this.txtWidth.MaxLength = 6;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(120, 19);
            this.txtWidth.TabIndex = 10;
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtWidth.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtWidth_KeyPress);
            // 
            // txtX
            // 
            this.txtX.Location = new System.Drawing.Point(104, 166);
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
            this.lblWidth.Location = new System.Drawing.Point(12, 194);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(88, 14);
            this.lblWidth.TabIndex = 42;
            this.lblWidth.Text = "Width";
            // 
            // lblX
            // 
            this.lblX.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblX.Location = new System.Drawing.Point(12, 170);
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
            this.txtResTagFlag.Text = "R";
            this.txtResTagFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblBackColor
            // 
            this.lblBackColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBackColor.Location = new System.Drawing.Point(231, 145);
            this.lblBackColor.Name = "lblBackColor";
            this.lblBackColor.Size = new System.Drawing.Size(88, 14);
            this.lblBackColor.TabIndex = 37;
            this.lblBackColor.Text = "Back Color";
            // 
            // cboTextStyle
            // 
            this.cboTextStyle.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboTextStyle.Location = new System.Drawing.Point(323, 117);
            this.cboTextStyle.Name = "cboTextStyle";
            this.cboTextStyle.Size = new System.Drawing.Size(120, 19);
            this.cboTextStyle.TabIndex = 5;
            this.cboTextStyle.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblStyle
            // 
            this.lblStyle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblStyle.Location = new System.Drawing.Point(231, 120);
            this.lblStyle.Name = "lblStyle";
            this.lblStyle.Size = new System.Drawing.Size(88, 14);
            this.lblStyle.TabIndex = 34;
            this.lblStyle.Text = "Text Style";
            // 
            // lblColor
            // 
            this.lblColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblColor.Location = new System.Drawing.Point(12, 145);
            this.lblColor.Name = "lblColor";
            this.lblColor.Size = new System.Drawing.Size(88, 14);
            this.lblColor.TabIndex = 33;
            this.lblColor.Text = "Text Color";
            // 
            // cboSize
            // 
            this.cboSize.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboSize.Location = new System.Drawing.Point(104, 117);
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
            this.txtSize.Location = new System.Drawing.Point(12, 121);
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
            this.grpRes.Controls.Add(this.txtCtrlMode);
            this.grpRes.Controls.Add(this.lblCtrlMode);
            this.grpRes.Controls.Add(this.txtLastDown);
            this.grpRes.Controls.Add(this.lblDown);
            this.grpRes.Controls.Add(this.lblEventTime);
            this.grpRes.Controls.Add(this.txtLastEventTime);
            this.grpRes.Controls.Add(this.txtLastEvent);
            this.grpRes.Controls.Add(this.lblLastEvent);
            this.grpRes.Controls.Add(this.lblLastEnd);
            this.grpRes.Controls.Add(this.txtLastEnd);
            this.grpRes.Controls.Add(this.txtLastStart);
            this.grpRes.Controls.Add(this.lblLastStartTime);
            this.grpRes.Controls.Add(this.lblUpDown);
            this.grpRes.Controls.Add(this.txtUpDown);
            this.grpRes.Controls.Add(this.txtPriSts);
            this.grpRes.Controls.Add(this.lblPriSts);
            this.grpRes.Controls.Add(this.lblSubArea);
            this.grpRes.Controls.Add(this.txtSubArea);
            this.grpRes.Controls.Add(this.txtArea);
            this.grpRes.Controls.Add(this.lblArea);
            this.grpRes.Controls.Add(this.lblProcMode);
            this.grpRes.Controls.Add(this.txtProcMode);
            this.grpRes.Controls.Add(this.txtResourceType);
            this.grpRes.Controls.Add(this.lblResourceType);
            this.grpRes.Controls.Add(this.txtDesc);
            this.grpRes.Controls.Add(this.lblDesc);
            this.grpRes.Controls.Add(this.lblResID);
            this.grpRes.Controls.Add(this.cdvResID);
            this.grpRes.Dock = System.Windows.Forms.DockStyle.Top;
            this.grpRes.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpRes.Location = new System.Drawing.Point(3, 0);
            this.grpRes.Name = "grpRes";
            this.grpRes.Size = new System.Drawing.Size(452, 210);
            this.grpRes.TabIndex = 0;
            this.grpRes.TabStop = false;
            // 
            // txtCtrlMode
            // 
            this.txtCtrlMode.Location = new System.Drawing.Point(323, 136);
            this.txtCtrlMode.MaxLength = 10;
            this.txtCtrlMode.Name = "txtCtrlMode";
            this.txtCtrlMode.ReadOnly = true;
            this.txtCtrlMode.Size = new System.Drawing.Size(120, 19);
            this.txtCtrlMode.TabIndex = 9;
            this.txtCtrlMode.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCtrlMode
            // 
            this.lblCtrlMode.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCtrlMode.Location = new System.Drawing.Point(231, 138);
            this.lblCtrlMode.Name = "lblCtrlMode";
            this.lblCtrlMode.Size = new System.Drawing.Size(88, 14);
            this.lblCtrlMode.TabIndex = 80;
            this.lblCtrlMode.Text = "Control Mode";
            // 
            // txtLastDown
            // 
            this.txtLastDown.Location = new System.Drawing.Point(104, 183);
            this.txtLastDown.MaxLength = 20;
            this.txtLastDown.Name = "txtLastDown";
            this.txtLastDown.ReadOnly = true;
            this.txtLastDown.Size = new System.Drawing.Size(120, 19);
            this.txtLastDown.TabIndex = 12;
            this.txtLastDown.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblDown
            // 
            this.lblDown.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDown.Location = new System.Drawing.Point(8, 187);
            this.lblDown.Name = "lblDown";
            this.lblDown.Size = new System.Drawing.Size(88, 14);
            this.lblDown.TabIndex = 78;
            this.lblDown.Text = "Last Down Time";
            // 
            // lblEventTime
            // 
            this.lblEventTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblEventTime.Location = new System.Drawing.Point(231, 162);
            this.lblEventTime.Name = "lblEventTime";
            this.lblEventTime.Size = new System.Drawing.Size(89, 14);
            this.lblEventTime.TabIndex = 77;
            this.lblEventTime.Text = "Last Event Time";
            // 
            // txtLastEventTime
            // 
            this.txtLastEventTime.Location = new System.Drawing.Point(323, 160);
            this.txtLastEventTime.MaxLength = 20;
            this.txtLastEventTime.Name = "txtLastEventTime";
            this.txtLastEventTime.ReadOnly = true;
            this.txtLastEventTime.Size = new System.Drawing.Size(120, 19);
            this.txtLastEventTime.TabIndex = 11;
            this.txtLastEventTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLastEvent
            // 
            this.txtLastEvent.Location = new System.Drawing.Point(104, 136);
            this.txtLastEvent.MaxLength = 12;
            this.txtLastEvent.Name = "txtLastEvent";
            this.txtLastEvent.ReadOnly = true;
            this.txtLastEvent.Size = new System.Drawing.Size(120, 19);
            this.txtLastEvent.TabIndex = 8;
            this.txtLastEvent.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLastEvent
            // 
            this.lblLastEvent.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastEvent.Location = new System.Drawing.Point(9, 140);
            this.lblLastEvent.Name = "lblLastEvent";
            this.lblLastEvent.Size = new System.Drawing.Size(88, 14);
            this.lblLastEvent.TabIndex = 74;
            this.lblLastEvent.Text = "Last Event";
            // 
            // lblLastEnd
            // 
            this.lblLastEnd.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastEnd.Location = new System.Drawing.Point(231, 185);
            this.lblLastEnd.Name = "lblLastEnd";
            this.lblLastEnd.Size = new System.Drawing.Size(88, 14);
            this.lblLastEnd.TabIndex = 73;
            this.lblLastEnd.Text = "Last End Time";
            // 
            // txtLastEnd
            // 
            this.txtLastEnd.Location = new System.Drawing.Point(323, 183);
            this.txtLastEnd.MaxLength = 20;
            this.txtLastEnd.Name = "txtLastEnd";
            this.txtLastEnd.ReadOnly = true;
            this.txtLastEnd.Size = new System.Drawing.Size(120, 19);
            this.txtLastEnd.TabIndex = 13;
            this.txtLastEnd.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLastStart
            // 
            this.txtLastStart.Location = new System.Drawing.Point(104, 160);
            this.txtLastStart.MaxLength = 20;
            this.txtLastStart.Name = "txtLastStart";
            this.txtLastStart.ReadOnly = true;
            this.txtLastStart.Size = new System.Drawing.Size(120, 19);
            this.txtLastStart.TabIndex = 10;
            this.txtLastStart.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblLastStartTime
            // 
            this.lblLastStartTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLastStartTime.Location = new System.Drawing.Point(9, 164);
            this.lblLastStartTime.Name = "lblLastStartTime";
            this.lblLastStartTime.Size = new System.Drawing.Size(88, 14);
            this.lblLastStartTime.TabIndex = 70;
            this.lblLastStartTime.Text = "Last Start Time";
            // 
            // lblUpDown
            // 
            this.lblUpDown.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpDown.Location = new System.Drawing.Point(231, 68);
            this.lblUpDown.Name = "lblUpDown";
            this.lblUpDown.Size = new System.Drawing.Size(88, 14);
            this.lblUpDown.TabIndex = 69;
            this.lblUpDown.Text = "Up / Down ";
            // 
            // txtUpDown
            // 
            this.txtUpDown.Location = new System.Drawing.Point(323, 65);
            this.txtUpDown.MaxLength = 5;
            this.txtUpDown.Name = "txtUpDown";
            this.txtUpDown.ReadOnly = true;
            this.txtUpDown.Size = new System.Drawing.Size(120, 19);
            this.txtUpDown.TabIndex = 3;
            this.txtUpDown.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtPriSts
            // 
            this.txtPriSts.Location = new System.Drawing.Point(104, 65);
            this.txtPriSts.MaxLength = 30;
            this.txtPriSts.Name = "txtPriSts";
            this.txtPriSts.ReadOnly = true;
            this.txtPriSts.Size = new System.Drawing.Size(120, 19);
            this.txtPriSts.TabIndex = 2;
            this.txtPriSts.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblPriSts
            // 
            this.lblPriSts.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblPriSts.Location = new System.Drawing.Point(9, 68);
            this.lblPriSts.Name = "lblPriSts";
            this.lblPriSts.Size = new System.Drawing.Size(88, 14);
            this.lblPriSts.TabIndex = 66;
            this.lblPriSts.Text = "Primary Status";
            // 
            // lblSubArea
            // 
            this.lblSubArea.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSubArea.Location = new System.Drawing.Point(231, 92);
            this.lblSubArea.Name = "lblSubArea";
            this.lblSubArea.Size = new System.Drawing.Size(88, 14);
            this.lblSubArea.TabIndex = 65;
            this.lblSubArea.Text = "Sub Area ID";
            // 
            // txtSubArea
            // 
            this.txtSubArea.Location = new System.Drawing.Point(323, 89);
            this.txtSubArea.MaxLength = 20;
            this.txtSubArea.Name = "txtSubArea";
            this.txtSubArea.ReadOnly = true;
            this.txtSubArea.Size = new System.Drawing.Size(120, 19);
            this.txtSubArea.TabIndex = 5;
            this.txtSubArea.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtArea
            // 
            this.txtArea.Location = new System.Drawing.Point(104, 89);
            this.txtArea.MaxLength = 20;
            this.txtArea.Name = "txtArea";
            this.txtArea.ReadOnly = true;
            this.txtArea.Size = new System.Drawing.Size(120, 19);
            this.txtArea.TabIndex = 4;
            this.txtArea.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblArea
            // 
            this.lblArea.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblArea.Location = new System.Drawing.Point(9, 92);
            this.lblArea.Name = "lblArea";
            this.lblArea.Size = new System.Drawing.Size(88, 14);
            this.lblArea.TabIndex = 62;
            this.lblArea.Text = "Area ID";
            // 
            // lblProcMode
            // 
            this.lblProcMode.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblProcMode.Location = new System.Drawing.Point(231, 116);
            this.lblProcMode.Name = "lblProcMode";
            this.lblProcMode.Size = new System.Drawing.Size(88, 14);
            this.lblProcMode.TabIndex = 61;
            this.lblProcMode.Text = "Proc Mode";
            // 
            // txtProcMode
            // 
            this.txtProcMode.Location = new System.Drawing.Point(323, 113);
            this.txtProcMode.MaxLength = 10;
            this.txtProcMode.Name = "txtProcMode";
            this.txtProcMode.ReadOnly = true;
            this.txtProcMode.Size = new System.Drawing.Size(120, 19);
            this.txtProcMode.TabIndex = 7;
            this.txtProcMode.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtResourceType
            // 
            this.txtResourceType.Location = new System.Drawing.Point(104, 113);
            this.txtResourceType.MaxLength = 20;
            this.txtResourceType.Name = "txtResourceType";
            this.txtResourceType.ReadOnly = true;
            this.txtResourceType.Size = new System.Drawing.Size(120, 19);
            this.txtResourceType.TabIndex = 6;
            this.txtResourceType.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblResourceType
            // 
            this.lblResourceType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResourceType.Location = new System.Drawing.Point(9, 116);
            this.lblResourceType.Name = "lblResourceType";
            this.lblResourceType.Size = new System.Drawing.Size(88, 14);
            this.lblResourceType.TabIndex = 57;
            this.lblResourceType.Text = "Resource Type";
            // 
            // txtDesc
            // 
            this.txtDesc.Location = new System.Drawing.Point(104, 41);
            this.txtDesc.MaxLength = 50;
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.ReadOnly = true;
            this.txtDesc.Size = new System.Drawing.Size(340, 19);
            this.txtDesc.TabIndex = 1;
            this.txtDesc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblDesc
            // 
            this.lblDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDesc.Location = new System.Drawing.Point(9, 44);
            this.lblDesc.Name = "lblDesc";
            this.lblDesc.Size = new System.Drawing.Size(88, 14);
            this.lblDesc.TabIndex = 55;
            this.lblDesc.Text = "Description";
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
            // txtWIP
            // 
            this.txtWIP.Location = new System.Drawing.Point(12, 11);
            this.txtWIP.MaxLength = 20;
            this.txtWIP.Name = "txtWIP";
            this.txtWIP.ReadOnly = true;
            this.txtWIP.Size = new System.Drawing.Size(120, 19);
            this.txtWIP.TabIndex = 13;
            this.txtWIP.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtWIP.Visible = false;
            // 
            // frmFMBCreateResource
            // 
            this.AcceptButton = this.btnCreate;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btnClose;
            this.ClientSize = new System.Drawing.Size(458, 466);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFMBCreateResource";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Create Resource";
            this.Load += new System.EventHandler(this.frmFMBCreateResource_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlBottom.PerformLayout();
            this.pnlMid.ResumeLayout(false);
            this.grpInfo.ResumeLayout(false);
            this.grpInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cboSignalPos)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboShape)).EndInit();
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
            this.grpRes.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtCtrlMode)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEventTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEvent)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastEnd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLastStart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpDown)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPriSts)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtSubArea)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtArea)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtProcMode)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtResourceType)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvResID)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWIP)).EndInit();
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
                Miracom.FMBUI.Controls.udcCtrlResource ctrlRes = new Miracom.FMBUI.Controls.udcCtrlResource(modGlobalVariable.gimlResource);
                imlRes = ctrlRes.imlResource;
                FMBCF.SetResShapeList(cboShape);
                FMBCF.SetEnumList(cboTextStyle, typeof(FontStyle));
                FMBCF.SetFontSize(cboSize);
                cboSize.Text = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextSize));
                cboTextStyle.SelectedIndex = 0;
                utcText.Color =   (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextColor);
                utcBack.Color = (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultBackColor);
                cboShape.SelectedIndex = 0;
                cboSignalPos.SelectedIndex = 0;
                GetSignalPosition(cboShape.SelectedIndex);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.init()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                    cboShape.ReadOnly = true;
                    cboSignalPos.ReadOnly = true;
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
                    cboShape.ReadOnly = true;
                    cboSignalPos.ReadOnly = true;
                    
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.Set_ReadOnly()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cdvResID.Focus();
                    return false;
                }

                switch (MPCF.RTrim(FuncName))
                {
                    case "CREATE":

                        if (MPCF.ToInt(txtWidth.Text) < modGlobalConstant.CTRL_MININUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(38) + " " + modGlobalConstant.CTRL_MININUM_SIZE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtHeight.Text) < modGlobalConstant.CTRL_MININUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(38) + " " + modGlobalConstant.CTRL_MININUM_SIZE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtWidth.Text) > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(8) + " " + modGlobalConstant.CTRL_MAXIMUM_SIZE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtHeight.Text) > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(8) + " " + modGlobalConstant.CTRL_MAXIMUM_SIZE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtX.Text) < 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(10), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtX.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtY.Text) < 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(10), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtY.Focus();
                            return false;
                        }
                        
                        if (MPCF.CheckNumeric(txtX.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtX.Focus();
                            return false;
                        }

                        if (MPCF.CheckNumeric(txtY.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtY.Focus();
                            return false;
                        }

                        if (MPCF.CheckNumeric(txtWidth.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }

                        if (MPCF.CheckNumeric(txtHeight.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateResource.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                in_node.AddChar("RES_SHAPE", MPCF.ToChar(cboShape.SelectedIndex));

                if (cboSignalPos.SelectedIndex == 0)
                {
                    in_node.AddChar("SIGNAL_FLAG", ' ');
                }
                else
                {
                    in_node.AddChar("SIGNAL_FLAG", MPCF.ToChar(cboSignalPos.SelectedIndex));
                }
                                                
                
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
                in_node.ProcStep = '1';
                in_node.Factory = txtFactory.Text;

                in_node.AddString("NEXT_RES_ID", "");

                
                do
                {
                    out_node = new TRSNode("FMB_View_Resource_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_Resource_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);

                    in_node.SetString("NEXT_RES_ID", out_node.GetString("NEXT_RES_ID"));
                } while (in_node.GetString("NEXT_RES_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'Y')
                            {
                            }
                            else if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'N')
                            {
                                if (out_node.GetList(0)[i].GetChar("UP_DOWN_FLAG") == 'U')
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
                }

                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.ViewResourceList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                TRSNode in_node = new TRSNode("View_Resource_In");
                TRSNode out_node = new TRSNode("View_Resource_Out");

                in_node.Factory = txtFactory.Text;
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddChar("RES_TYPE", ' ');

                if (MPCR.CallService("FMB", "FMB_View_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }
                
                if (sStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    txtDesc.Text = MPCF.RTrim(out_node.GetString("RES_DESC"));
                    txtResourceType.Text = MPCF.RTrim(out_node.GetString("RES_TYPE"));
                    
                    if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")) != "")
                    {
                        if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OL")
                        {
                            txtCtrlMode.Text = "ON LINE";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OR")
                        {
                            txtCtrlMode.Text = "ON LINE REAL";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OF")
                        {
                            txtCtrlMode.Text = "OFF LINE";
                        }
                    }
                    if (MPCF.Trim(out_node.GetString("RES_PROC_MODE")) != "")
                    {
                        if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "M")
                        {
                            txtProcMode.Text = "MANUAL";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "S")
                        {
                            txtProcMode.Text = "SEMI AUTO";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "F")
                        {
                            txtProcMode.Text = "FULL AUTO";
                        }
                    }
                    txtArea.Text = MPCF.RTrim(out_node.GetString("AREA_ID"));
                    txtSubArea.Text = MPCF.RTrim(out_node.GetString("SUB_AREA_ID"));

                    if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "U")
                    {
                        txtUpDown.Text = "UP";
                    }
                    else if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "D")
                    {
                        txtUpDown.Text = "DOWN";
                    }
                    txtPriSts.Text = MPCF.RTrim(out_node.GetString("RES_PRI_STS"));
                    txtLastStart.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_START_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEnd.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_END_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEvent.Text = MPCF.RTrim(out_node.GetString("LAST_EVENT_ID"));
                    txtLastEventTime.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_EVENT_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastDown.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_DOWN_TIME"), DATE_TIME_FORMAT.NONE);
                    txtWIP.Text = MPCF.RTrim(out_node.GetDouble("WIP_RATE"));
                    txtText.Text = cdvResID.Text;
                    
                    if (out_node.GetInt("IMAGE_IDX") != - 1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
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
                    txtDesc.Text = MPCF.RTrim(out_node.GetString("RES_DESC"));
                    txtResourceType.Text = MPCF.RTrim(out_node.GetString("RES_TYPE"));

                    if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")) != "")
                    {
                        if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OL")
                        {
                            txtCtrlMode.Text = "ON LINE";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OR")
                        {
                            txtCtrlMode.Text = "ON LINE REAL";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OF")
                        {
                            txtCtrlMode.Text = "OFF LINE";
                        }
                    }
                    if (MPCF.Trim(out_node.GetString("RES_PROC_MODE")) != "")
                    { 
                        if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "M")
                        {
                            txtProcMode.Text = "MANUAL";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "S")
                        {
                            txtProcMode.Text = "SEMI AUTO";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "F")
                        {
                            txtProcMode.Text = "FULL AUTO";
                        }
                    }
                    txtArea.Text = MPCF.RTrim(out_node.GetString("AREA_ID"));
                    txtSubArea.Text = MPCF.RTrim(out_node.GetString("SUB_AREA_ID"));

                    if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "U")
                    {
                        txtUpDown.Text = "UP";
                    }
                    else if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "D")
                    {
                        txtUpDown.Text = "DOWN";
                    }
                    txtPriSts.Text = MPCF.RTrim(out_node.GetString("RES_PRI_STS"));
                    txtLastStart.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_START_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEnd.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_END_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEvent.Text = MPCF.RTrim(out_node.GetString("LAST_EVENT_ID"));
                    txtLastEventTime.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_EVENT_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastDown.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_DOWN_TIME"), DATE_TIME_FORMAT.NONE);
                    txtWIP.Text = MPCF.RTrim(out_node.GetDouble("WIP_RATE"));

                    cdvLayOut.Text = MPCF.RTrim(out_node.GetString("LAYOUT_ID"));
                    txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));
                    cboSize.Text = MPCF.RTrim(out_node.GetInt("TEXT_SIZE"));
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE"));
                    cboShape.SelectedIndex = MPCF.ToInt(out_node.GetChar("RES_SHAPE"));
                    
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
                        utcText.Color = Color.FromArgb(out_node.GetInt("BACK_COLOR"));
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
                    if (out_node.GetInt("IMAGE_IDX") != - 1 && imlRes.Images.Count > out_node.GetInt("IMAGE_IDX"))
                    {
                        iImageIndex = out_node.GetInt("IMAGE_IDX");
                        pctImage.Image = imlRes.Images[iImageIndex];
                    }
                    else
                    {
                        pctImage.Image = null;
                    }

                    cboSignalPos.SelectedIndex = MPCF.ToInt(out_node.GetChar("SIGNAL_FLAG"));
                                        
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.View_Resource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // ViewUDRResourceList()
        //       - View User Define Resource List
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
                TRSNode in_node = new TRSNode("View_UDR_Resource_List_In");
                TRSNode out_node;

                int i;
                ListViewItem itmX;
                ArrayList a_list = new ArrayList();

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("NEXT_RES_ID", "");
                in_node.AddString("GROUP_ID", cdvLayOut.Text);

                
                do
                {
                    out_node = new TRSNode("View_UDR_Resource_List_Out");

                    if (MPCR.CallService("FMB", "FMB_View_UDR_Resource_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    
                    a_list.Add(out_node);

                    in_node.SetString("NEXT_RES_ID", out_node.GetString("NEXT_RES_ID"));
                } while (in_node.GetString("NEXT_RES_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'Y')
                            {
                            }
                            else if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'N')
                            {
                                if (out_node.GetList(0)[i].GetChar("UP_DOWN_FLAG") == 'U')
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
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.ViewUDRResourceList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                TRSNode in_node = new TRSNode("View_UDR_Resource_In");
                TRSNode out_node = new TRSNode("View_UDR_Resource_Out");
                
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", cdvResID.Text);
                in_node.AddString("GROUP_ID", cdvLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_UDR_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }

                if (sStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    txtDesc.Text = MPCF.RTrim(out_node.GetString("RES_DESC"));
                    txtResourceType.Text = MPCF.RTrim(out_node.GetString("RES_TYPE"));

                    if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")) != "")
                    {
                        if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OL")
                        {
                            txtCtrlMode.Text = "ON LINE";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OR")
                        {
                            txtCtrlMode.Text = "ON LINE REAL";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OF")
                        {
                            txtCtrlMode.Text = "OFF LINE";
                        }
                    }
                    if (MPCF.Trim(out_node.GetString("RES_PROC_MODE")) != "")
                    {
                        if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "M")
                        {
                            txtProcMode.Text = "MANUAL";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "S")
                        {
                            txtProcMode.Text = "SEMI AUTO";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "F")
                        {
                            txtProcMode.Text = "FULL AUTO";
                        }
                    }
                    txtArea.Text = MPCF.RTrim(out_node.GetString("AREA_ID"));
                    txtSubArea.Text = MPCF.RTrim(out_node.GetString("SUB_AREA_ID"));

                    if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "U")
                    {
                        txtUpDown.Text = "UP";
                    }
                    else if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "D")
                    {
                        txtUpDown.Text = "DOWN";
                    }
                    txtPriSts.Text = MPCF.RTrim(out_node.GetString("RES_PRI_STS"));
                    txtLastStart.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_START_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEnd.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_END_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEvent.Text = MPCF.RTrim(out_node.GetString("LAST_EVENT_ID"));
                    txtLastEventTime.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_EVENT_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastDown.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_DOWN_TIME"), DATE_TIME_FORMAT.NONE);
                    txtWIP.Text = MPCF.RTrim(out_node.GetDouble("WIP_RATE"));
                    txtText.Text = cdvResID.Text;

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
                    txtDesc.Text = MPCF.RTrim(out_node.GetString("RES_DESC"));
                    txtResourceType.Text = MPCF.RTrim(out_node.GetString("RES_TYPE"));

                    if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")) != "")
                    {
                        if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OL")
                        {
                            txtCtrlMode.Text = "ON LINE";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OR")
                        {
                            txtCtrlMode.Text = "ON LINE REAL";
                        }
                        else if (MPCF.Trim(out_node.GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OF")
                        {
                            txtCtrlMode.Text = "OFF LINE";
                        }
                    }
                    if (MPCF.Trim(out_node.GetString("RES_PROC_MODE")) != "")
                    {
                        if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "M")
                        {
                            txtProcMode.Text = "MANUAL";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "S")
                        {
                            txtProcMode.Text = "SEMI AUTO";
                        }
                        else if (out_node.GetString("RES_PROC_MODE").Substring(0, 1) == "F")
                        {
                            txtProcMode.Text = "FULL AUTO";
                        }
                    }
                    txtArea.Text = MPCF.RTrim(out_node.GetString("AREA_ID"));
                    txtSubArea.Text = MPCF.RTrim(out_node.GetString("SUB_AREA_ID"));

                    if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "U")
                    {
                        txtUpDown.Text = "UP";
                    }
                    else if (MPCF.RTrim(out_node.GetChar("RES_UP_DOWN_FLAG")) == "D")
                    {
                        txtUpDown.Text = "DOWN";
                    }
                    txtPriSts.Text = MPCF.RTrim(out_node.GetString("RES_PRI_STS"));
                    txtLastStart.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_START_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEnd.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_END_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastEvent.Text = MPCF.RTrim(out_node.GetString("LAST_EVENT_ID"));
                    txtLastEventTime.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_EVENT_TIME"), DATE_TIME_FORMAT.NONE);
                    txtLastDown.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_DOWN_TIME"), DATE_TIME_FORMAT.NONE);
                    txtWIP.Text = MPCF.RTrim(out_node.GetDouble("WIP_RATE"));

                    txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));
                    cboSize.Text = MPCF.Trim( out_node.GetInt("TEXT_SIZE"));
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE"));
                    cboShape.SelectedIndex = MPCF.ToInt(out_node.GetChar("RES_SHAPE"));

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
                        utcText.Color = Color.FromArgb(out_node.GetInt("BACK_COLOR"));
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
                    cboSignalPos.SelectedIndex = MPCF.ToInt(out_node.GetChar("SIGNAL_FLAG"));
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.View_UDR_Resource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                TRSNode in_node = new TRSNode("Update_UDR_ResLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("GROUP_ID", cdvLayOut.Text);

                in_node.AddString("RES_ID", cdvResID.Text);
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
                in_node.AddChar("RES_SHAPE", MPCF.ToChar(cboShape.SelectedIndex));

                if (cboSignalPos.SelectedIndex == 0)
                {
                    in_node.AddChar("SIGNAL_FLAG", ' ');
                }
                else
                {
                    in_node.AddChar("SIGNAL_FLAG", MPCF.ToChar(cboSignalPos.SelectedIndex));
                }
                
                if (sStep != modGlobalConstant.MP_STEP_DELETE)
                {
                    if (View_UDR_Group() == true)
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

                if (MPCR.CallService("FMB", "FMB_Update_UDR_ResLoc", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.ShowSuccessMsg(out_node);
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.Update_UDR_ResLoc()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
        private void GetSignalPosition(int i_shape)
        {
            if (i_shape == 0)
            {
                cboSignalPos.Items.Clear();
                cboSignalPos.Items.Add("No Signal");
                cboSignalPos.Items.Add("Operation Mode");
                cboSignalPos.Items.Add("Left");
                cboSignalPos.Items.Add("Right");
                cboSignalPos.Items.Add("Top");
                cboSignalPos.Items.Add("Bottom");
            }
            else
            {
                cboSignalPos.Items.Clear();
                cboSignalPos.Items.Add("No Signal");
                cboSignalPos.Items.Add("Operation Mode");                
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
                MPCF.ShowMsgBox("frmFMBCreateResource.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                cdvResID.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
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
                MPCF.ShowMsgBox("frmFMBCreateResource.cdvResID_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                            if (FMBFI.gIMdiForm.RefreshDesignList("2", txtFactory.Text, cdvLayOut.Text, cdvResID.Text, "") == false)
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
                            if (FMBFI.gIMdiForm.RefreshDesignList("2", txtFactory.Text, cdvLayOut.Text, cdvResID.Text, "") == false)
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
                MPCF.ShowMsgBox("frmFMBCreateResource.btnCreate_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                        View_Resource(modGlobalConstant.MP_STEP_CREATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        View_UDR_Resource(modGlobalConstant.MP_STEP_CREATE);
                    }
                }
                else
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        View_Resource(modGlobalConstant.MP_STEP_UPDATE);
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        View_UDR_Resource(modGlobalConstant.MP_STEP_UPDATE);
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.cdvResID_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBCreateResource_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                Set_ReadOnly();
                init();
                
                if (cdvResID.Text != "")
                {
                    cdvResID.ReadOnly = true;
                    cdvResID.BackColor = SystemColors.Control;
                    cdvResID.VisibleButton = false;
                    if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            View_Resource(modGlobalConstant.MP_STEP_CREATE);
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            View_UDR_Resource(modGlobalConstant.MP_STEP_CREATE);
                        }
                    }
                    else
                    {
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            View_Resource(modGlobalConstant.MP_STEP_UPDATE);
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            View_UDR_Resource(modGlobalConstant.MP_STEP_UPDATE);
                        }
                    }
                }
                
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Create Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Create Resource by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_UPDATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Update Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Update Resource by User Define Group";
                    }
                    btnCreate.Text = "Update";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Delete Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Delete Resource by User Define Group";
                    }
                    btnCreate.Text = "Delete";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_VIEW)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "View Resource";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "View Resource by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.frmFMBCreateResource_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                cdvLayOut.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    modListRoutine.ViewLayOutList(cdvLayOut.GetListView, '1', txtFactory.Text);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.cdvLayOut_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateResource.txtX_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateResource.txtY_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateResource.txtHeight_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateResource.txtWidth_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion

        private void cboShape_SelectionChanged(object sender, EventArgs e)
        {
            try
            {
                GetSignalPosition(cboShape.SelectedIndex);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.txtWidth_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }
        
    }
    
}
