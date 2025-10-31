
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
//using FMBUI.Enums;
using Infragistics.Win.UltraWinEditors;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.TRSCore;
using Miracom.MESCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBCreateTag.vb
//   Description : Create/Update/Delete Tag
//
//   FMB Version : 1.0.0
//
//   Function List
//       - init() : Initialize Controls
//       - Set_ReadOnly() : Set Controls ReadOnly
//       - CheckCondition() : Check the conditions before transaction
//       - Update_Resource_Location() : Create/Update/Delete Resource Location
//       - View_Resource() : View Resource Information
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
    public class frmFMBCreateTag : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBCreateTag()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        public frmFMBCreateTag(char sProcStep)
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
        internal System.Windows.Forms.Button btnCreate;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.GroupBox grpInfo;
        internal UltraTextEditor txtFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal UltraTextEditor txtLayOut;
        internal System.Windows.Forms.Label lblLayOut;
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
        internal System.Windows.Forms.Label lblTagID;
        internal UltraTextEditor txtTagID;
        internal System.Windows.Forms.Label lblShape;
        internal UltraComboEditor cboShape;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcText;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBack;
        internal Infragistics.Win.UltraWinEditors.UltraCheckEditor chkNoMouseEvent;
        internal System.Windows.Forms.Label lblNoMouseEvent;
        internal System.Windows.Forms.Label lblResTagFlag;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtResTagFlag;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            base.Load += new System.EventHandler(frmFMBCreateTag_Load);
            this.btnCreate = new System.Windows.Forms.Button();
            this.btnCreate.Click += new System.EventHandler(btnCreate_Click);
            this.btnClose = new System.Windows.Forms.Button();
            this.btnClose.Click += new System.EventHandler(btnClose_Click);
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpInfo = new System.Windows.Forms.GroupBox();
            this.lblNoMouseEvent = new System.Windows.Forms.Label();
            this.chkNoMouseEvent = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.utcBack = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.utcText = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.txtFactory = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblFactory = new System.Windows.Forms.Label();
            this.txtLayOut = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblLayOut = new System.Windows.Forms.Label();
            this.txtY = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtY.KeyPress += new System.Windows.Forms.KeyPressEventHandler(txtY_KeyPress);
            this.lblY = new System.Windows.Forms.Label();
            this.txtHeight = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtHeight.KeyPress += new System.Windows.Forms.KeyPressEventHandler(txtHeight_KeyPress);
            this.lblHeight = new System.Windows.Forms.Label();
            this.txtWidth = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtWidth.KeyPress += new System.Windows.Forms.KeyPressEventHandler(txtWidth_KeyPress);
            this.txtX = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtX.KeyPress += new System.Windows.Forms.KeyPressEventHandler(txtX_KeyPress);
            this.lblWidth = new System.Windows.Forms.Label();
            this.lblX = new System.Windows.Forms.Label();
            this.lblBackColor = new System.Windows.Forms.Label();
            this.cboTextStyle = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.lblStyle = new System.Windows.Forms.Label();
            this.lblColor = new System.Windows.Forms.Label();
            this.cboSize = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.txtText = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtSize = new System.Windows.Forms.Label();
            this.lblText = new System.Windows.Forms.Label();
            this.lblTagID = new System.Windows.Forms.Label();
            this.txtTagID = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblResTagFlag = new System.Windows.Forms.Label();
            this.txtResTagFlag = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblShape = new System.Windows.Forms.Label();
            this.cboShape = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.cboShape.SelectionChanged += new System.EventHandler(cboShape_SelectionChanged);
            this.pnlBottom.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.grpInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize) this.utcBack).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.utcText).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtFactory).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtLayOut).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtY).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtHeight).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtWidth).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtX).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cboTextStyle).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cboSize).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtText).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtTagID).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtResTagFlag).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cboShape).BeginInit();
            this.SuspendLayout();
            //
            //pnlBottom
            //
            this.pnlBottom.Controls.Add(this.btnCreate);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.pnlBottom.Location = new System.Drawing.Point(0, 220);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(458, 40);
            this.pnlBottom.TabIndex = 1;
            //
            //btnCreate
            //
            this.btnCreate.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnCreate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnCreate.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnCreate.Location = new System.Drawing.Point(294, 9);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(74, 23);
            this.btnCreate.TabIndex = 0;
            this.btnCreate.Text = "Create";
            //
            //btnClose
            //
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnClose.Location = new System.Drawing.Point(374, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            //
            //pnlMid
            //
            this.pnlMid.Controls.Add(this.grpInfo);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.DockPadding.Left = 3;
            this.pnlMid.DockPadding.Right = 3;
            this.pnlMid.Location = new System.Drawing.Point(0, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Size = new System.Drawing.Size(458, 220);
            this.pnlMid.TabIndex = 0;
            //
            //grpInfo
            //
            this.grpInfo.Controls.Add(this.lblNoMouseEvent);
            this.grpInfo.Controls.Add(this.chkNoMouseEvent);
            this.grpInfo.Controls.Add(this.utcBack);
            this.grpInfo.Controls.Add(this.utcText);
            this.grpInfo.Controls.Add(this.txtFactory);
            this.grpInfo.Controls.Add(this.lblFactory);
            this.grpInfo.Controls.Add(this.txtLayOut);
            this.grpInfo.Controls.Add(this.lblLayOut);
            this.grpInfo.Controls.Add(this.txtY);
            this.grpInfo.Controls.Add(this.lblY);
            this.grpInfo.Controls.Add(this.txtHeight);
            this.grpInfo.Controls.Add(this.lblHeight);
            this.grpInfo.Controls.Add(this.txtWidth);
            this.grpInfo.Controls.Add(this.txtX);
            this.grpInfo.Controls.Add(this.lblWidth);
            this.grpInfo.Controls.Add(this.lblX);
            this.grpInfo.Controls.Add(this.lblBackColor);
            this.grpInfo.Controls.Add(this.cboTextStyle);
            this.grpInfo.Controls.Add(this.lblStyle);
            this.grpInfo.Controls.Add(this.lblColor);
            this.grpInfo.Controls.Add(this.cboSize);
            this.grpInfo.Controls.Add(this.txtText);
            this.grpInfo.Controls.Add(this.txtSize);
            this.grpInfo.Controls.Add(this.lblText);
            this.grpInfo.Controls.Add(this.lblTagID);
            this.grpInfo.Controls.Add(this.txtTagID);
            this.grpInfo.Controls.Add(this.lblResTagFlag);
            this.grpInfo.Controls.Add(this.txtResTagFlag);
            this.grpInfo.Controls.Add(this.lblShape);
            this.grpInfo.Controls.Add(this.cboShape);
            this.grpInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpInfo.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpInfo.Location = new System.Drawing.Point(3, 0);
            this.grpInfo.Name = "grpInfo";
            this.grpInfo.Size = new System.Drawing.Size(452, 220);
            this.grpInfo.TabIndex = 0;
            this.grpInfo.TabStop = false;
            //
            //lblNoMouseEvent
            //
            this.lblNoMouseEvent.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblNoMouseEvent.Location = new System.Drawing.Point(343, 22);
            this.lblNoMouseEvent.Name = "lblNoMouseEvent";
            this.lblNoMouseEvent.Size = new System.Drawing.Size(88, 14);
            this.lblNoMouseEvent.TabIndex = 55;
            this.lblNoMouseEvent.Text = "No Mouse Event";
            //
            //chkNoMouseEvent
            //
            this.chkNoMouseEvent.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.chkNoMouseEvent.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkNoMouseEvent.Location = new System.Drawing.Point(323, 22);
            this.chkNoMouseEvent.Name = "chkNoMouseEvent";
            this.chkNoMouseEvent.Size = new System.Drawing.Size(117, 14);
            this.chkNoMouseEvent.TabIndex = 54;
            //
            //utcBack
            //
            this.utcBack.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.utcBack.Location = new System.Drawing.Point(323, 141);
            this.utcBack.Name = "utcBack";
            this.utcBack.Size = new System.Drawing.Size(120, 19);
            this.utcBack.TabIndex = 9;
            this.utcBack.Text = "Control";
            //
            //utcText
            //
            this.utcText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.utcText.Location = new System.Drawing.Point(104, 141);
            this.utcText.Name = "utcText";
            this.utcText.Size = new System.Drawing.Size(120, 19);
            this.utcText.TabIndex = 8;
            this.utcText.Text = "Control";
            //
            //txtFactory
            //
            this.txtFactory.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtFactory.Location = new System.Drawing.Point(104, 44);
            this.txtFactory.MaxLength = 10;
            this.txtFactory.Name = "txtFactory";
            this.txtFactory.ReadOnly = true;
            this.txtFactory.Size = new System.Drawing.Size(120, 19);
            this.txtFactory.TabIndex = 1;
            //
            //lblFactory
            //
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Location = new System.Drawing.Point(12, 48);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(88, 14);
            this.lblFactory.TabIndex = 53;
            this.lblFactory.Text = "Factory";
            //
            //txtLayOut
            //
            this.txtLayOut.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtLayOut.Location = new System.Drawing.Point(323, 44);
            this.txtLayOut.MaxLength = 20;
            this.txtLayOut.Name = "txtLayOut";
            this.txtLayOut.ReadOnly = true;
            this.txtLayOut.Size = new System.Drawing.Size(120, 19);
            this.txtLayOut.TabIndex = 2;
            //
            //lblLayOut
            //
            this.lblLayOut.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLayOut.Location = new System.Drawing.Point(231, 48);
            this.lblLayOut.Name = "lblLayOut";
            this.lblLayOut.Size = new System.Drawing.Size(88, 14);
            this.lblLayOut.TabIndex = 51;
            this.lblLayOut.Text = "LayOut ID";
            //
            //txtY
            //
            this.txtY.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtY.Location = new System.Drawing.Point(323, 164);
            this.txtY.MaxLength = 6;
            this.txtY.Name = "txtY";
            this.txtY.Size = new System.Drawing.Size(120, 19);
            this.txtY.TabIndex = 11;
            //
            //lblY
            //
            this.lblY.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblY.Location = new System.Drawing.Point(231, 168);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(88, 14);
            this.lblY.TabIndex = 47;
            this.lblY.Text = "Location Y";
            //
            //txtHeight
            //
            this.txtHeight.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtHeight.Location = new System.Drawing.Point(323, 188);
            this.txtHeight.MaxLength = 6;
            this.txtHeight.Name = "txtHeight";
            this.txtHeight.Size = new System.Drawing.Size(120, 19);
            this.txtHeight.TabIndex = 13;
            //
            //lblHeight
            //
            this.lblHeight.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHeight.Location = new System.Drawing.Point(231, 192);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(88, 14);
            this.lblHeight.TabIndex = 45;
            this.lblHeight.Text = "Height";
            //
            //txtWidth
            //
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtWidth.Location = new System.Drawing.Point(104, 188);
            this.txtWidth.MaxLength = 6;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(120, 19);
            this.txtWidth.TabIndex = 12;
            //
            //txtX
            //
            this.txtX.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtX.Location = new System.Drawing.Point(104, 164);
            this.txtX.MaxLength = 6;
            this.txtX.Name = "txtX";
            this.txtX.Size = new System.Drawing.Size(120, 19);
            this.txtX.TabIndex = 10;
            //
            //lblWidth
            //
            this.lblWidth.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblWidth.Location = new System.Drawing.Point(12, 192);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(88, 14);
            this.lblWidth.TabIndex = 42;
            this.lblWidth.Text = "Width";
            //
            //lblX
            //
            this.lblX.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblX.Location = new System.Drawing.Point(12, 168);
            this.lblX.Name = "lblX";
            this.lblX.Size = new System.Drawing.Size(88, 14);
            this.lblX.TabIndex = 41;
            this.lblX.Text = "Location X ";
            //
            //lblBackColor
            //
            this.lblBackColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBackColor.Location = new System.Drawing.Point(231, 144);
            this.lblBackColor.Name = "lblBackColor";
            this.lblBackColor.Size = new System.Drawing.Size(88, 14);
            this.lblBackColor.TabIndex = 37;
            this.lblBackColor.Text = "Back Color";
            //
            //cboTextStyle
            //
            this.cboTextStyle.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboTextStyle.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.cboTextStyle.Location = new System.Drawing.Point(323, 116);
            this.cboTextStyle.Name = "cboTextStyle";
            this.cboTextStyle.Size = new System.Drawing.Size(120, 19);
            this.cboTextStyle.TabIndex = 7;
            //
            //lblStyle
            //
            this.lblStyle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblStyle.Location = new System.Drawing.Point(231, 120);
            this.lblStyle.Name = "lblStyle";
            this.lblStyle.Size = new System.Drawing.Size(88, 14);
            this.lblStyle.TabIndex = 34;
            this.lblStyle.Text = "Text Style";
            //
            //lblColor
            //
            this.lblColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblColor.Location = new System.Drawing.Point(12, 144);
            this.lblColor.Name = "lblColor";
            this.lblColor.Size = new System.Drawing.Size(88, 14);
            this.lblColor.TabIndex = 33;
            this.lblColor.Text = "Text Color";
            //
            //cboSize
            //
            this.cboSize.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboSize.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.cboSize.Location = new System.Drawing.Point(104, 116);
            this.cboSize.Name = "cboSize";
            this.cboSize.Size = new System.Drawing.Size(120, 19);
            this.cboSize.TabIndex = 6;
            //
            //txtText
            //
            this.txtText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtText.Location = new System.Drawing.Point(104, 68);
            this.txtText.MaxLength = 40;
            this.txtText.Name = "txtText";
            this.txtText.Size = new System.Drawing.Size(200, 19);
            this.txtText.TabIndex = 3;
            //
            //txtSize
            //
            this.txtSize.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.txtSize.Location = new System.Drawing.Point(12, 120);
            this.txtSize.Name = "txtSize";
            this.txtSize.Size = new System.Drawing.Size(88, 14);
            this.txtSize.TabIndex = 30;
            this.txtSize.Text = "Text Font Size";
            //
            //lblText
            //
            this.lblText.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblText.Location = new System.Drawing.Point(12, 72);
            this.lblText.Name = "lblText";
            this.lblText.Size = new System.Drawing.Size(88, 14);
            this.lblText.TabIndex = 29;
            this.lblText.Text = "Text";
            //
            //lblTagID
            //
            this.lblTagID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTagID.Location = new System.Drawing.Point(12, 23);
            this.lblTagID.Name = "lblTagID";
            this.lblTagID.Size = new System.Drawing.Size(88, 14);
            this.lblTagID.TabIndex = 28;
            this.lblTagID.Text = "Tag ID";
            //
            //txtTagID
            //
            this.txtTagID.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtTagID.Location = new System.Drawing.Point(104, 20);
            this.txtTagID.MaxLength = 20;
            this.txtTagID.Name = "txtTagID";
            this.txtTagID.Size = new System.Drawing.Size(200, 19);
            this.txtTagID.TabIndex = 0;
            //
            //lblResTagFlag
            //
            this.lblResTagFlag.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResTagFlag.Location = new System.Drawing.Point(12, 95);
            this.lblResTagFlag.Name = "lblResTagFlag";
            this.lblResTagFlag.Size = new System.Drawing.Size(88, 14);
            this.lblResTagFlag.TabIndex = 42;
            this.lblResTagFlag.Text = "Type";
            //
            //txtResTagFlag
            //
            this.txtResTagFlag.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtResTagFlag.Location = new System.Drawing.Point(104, 92);
            this.txtResTagFlag.Name = "txtResTagFlag";
            this.txtResTagFlag.ReadOnly = true;
            this.txtResTagFlag.Size = new System.Drawing.Size(120, 19);
            this.txtResTagFlag.TabIndex = 4;
            this.txtResTagFlag.Text = "T";
            //
            //lblShape
            //
            this.lblShape.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblShape.Location = new System.Drawing.Point(231, 96);
            this.lblShape.Name = "lblShape";
            this.lblShape.Size = new System.Drawing.Size(88, 14);
            this.lblShape.TabIndex = 38;
            this.lblShape.Text = "Shape";
            //
            //cboShape
            //
            this.cboShape.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboShape.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.cboShape.Location = new System.Drawing.Point(323, 92);
            this.cboShape.Name = "cboShape";
            this.cboShape.Size = new System.Drawing.Size(120, 19);
            this.cboShape.TabIndex = 5;
            //
            //frmFMBCreateTag
            //
            this.AcceptButton = this.btnCreate;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btnClose;
            this.ClientSize = new System.Drawing.Size(458, 260);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFMBCreateTag";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Create Tag";
            this.pnlBottom.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.grpInfo.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize) this.utcBack).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.utcText).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtFactory).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtLayOut).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtY).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtHeight).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtWidth).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtX).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cboTextStyle).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cboSize).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtText).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtTagID).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtResTagFlag).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cboShape).EndInit();
            this.ResumeLayout(false);
            
        }
        
        #endregion
        
        #region " Variable Definition"
        
        private int giWidth = 0;
        private int giHeight = 0;
        
        #endregion
        
        #region " Property Implements"
        
        private char m_sProcStep = ' ';
        private int m_iSelectedShapeIndex = - 1;
        
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
        
        public int SelectedShapeIndex
        {
            get
            {
                return m_iSelectedShapeIndex;
            }
            set
            {

                if (m_iSelectedShapeIndex.Equals(value) == false)
                {
                    m_iSelectedShapeIndex = value;
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
                FMBCF.SetEnumList(cboTextStyle, typeof(FontStyle));
                FMBCF.SetTagTypeList(cboShape);
                FMBCF.SetFontSize(cboSize);
                cboSize.Text = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextSize));
                cboTextStyle.SelectedIndex = 0;
                cboShape.SelectedIndex = 0;
                utcText.Color = (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextColor);
                utcBack.Color = (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultBackColor);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.init()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                    
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_UPDATE)
                {
                    txtTagID.ReadOnly = true;
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    txtTagID.ReadOnly = true;
                    txtLayOut.ReadOnly = true;
                    txtText.ReadOnly = true;
                    cboShape.ReadOnly = true;
                    cboSize.ReadOnly = true;
                    cboTextStyle.ReadOnly = true;
                    utcText.ReadOnly = true;
                    utcBack.ReadOnly = true;
                    txtX.ReadOnly = true;
                    txtY.ReadOnly = true;
                    txtWidth.ReadOnly = true;
                    txtHeight.ReadOnly = true;
                    chkNoMouseEvent.Enabled = false;
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_VIEW)
                {
                    txtTagID.ReadOnly = true;
                    txtLayOut.ReadOnly = true;
                    txtText.ReadOnly = true;
                    cboShape.ReadOnly = true;
                    cboSize.ReadOnly = true;
                    cboTextStyle.ReadOnly = true;
                    utcText.ReadOnly = true;
                    utcBack.ReadOnly = true;
                    txtX.ReadOnly = true;
                    txtY.ReadOnly = true;
                    txtWidth.ReadOnly = true;
                    txtHeight.ReadOnly = true;
                    btnCreate.Visible = false;
                    chkNoMouseEvent.Enabled = false;
                }
                
                if (SelectedShapeIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1 || SelectedShapeIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.HorizontalLine) - 1)
                {
                    cboTextStyle.Enabled = false;
                    cboSize.Enabled = false;
                    utcText.Enabled = false;
                    cboTextStyle.Text = "";
                    cboSize.Text = "";
                    utcText.Text = "";
                    lblWidth.Text = "Length";
                    lblHeight.Text = "Thickness";
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.Set_ReadOnly()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                if (txtTagID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    txtTagID.Focus();
                    return false;
                }

                switch (MPCF.RTrim(FuncName))
                {
                    case "CREATE":
                        
                        if (this.cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.TextType) - 1)
                        {
                            if (FMBCF.CheckValue(txtText, 1, false, false, "", "", "") == false)
                            {
                                return false;
                            }
                        }
                        if (MPCF.ToInt(txtWidth.Text) < modGlobalConstant.CTRL_MININUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(38) + " " + Convert.ToString(MPCF.ToInt(modGlobalConstant.CTRL_MININUM_SIZE) - 1), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }
                        if (this.cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1 || this.cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.HorizontalLine) - 1)
                        {
                            if (MPCF.ToInt(txtHeight.Text) < modGlobalConstant.LINE_MININUM_SIZE)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(38) + " " + Convert.ToString(MPCF.ToInt(modGlobalConstant.LINE_MININUM_SIZE) - 1), Application.ProductName, MessageBoxButtons.OK, 1);
                                txtHeight.Focus();
                                return false;
                            }
                        }
                        else
                        {
                            if (MPCF.ToInt(txtHeight.Text) < modGlobalConstant.CTRL_MININUM_SIZE)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(38) + " " + Convert.ToString(MPCF.ToInt(modGlobalConstant.CTRL_MININUM_SIZE) - 1), Application.ProductName, MessageBoxButtons.OK, 1);
                                txtHeight.Focus();
                                return false;
                            }
                        }
                        if (this.cboShape.SelectedIndex != MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1 && this.cboShape.SelectedIndex != MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.HorizontalLine) - 1)
                        {
                            if (MPCF.ToInt(txtWidth.Text) > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(8) + " " + modGlobalConstant.CTRL_MAXIMUM_SIZE + 1, Application.ProductName, MessageBoxButtons.OK, 1);
                                txtWidth.Focus();
                                return false;
                            }
                        }
                        if (MPCF.ToInt(txtHeight.Text) > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(8) + " " + modGlobalConstant.CTRL_MAXIMUM_SIZE + 1, Application.ProductName, MessageBoxButtons.OK, 1);
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
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                string sFactory;
                string sLayoutID;
                string sTagID;
                char sResType;
                string sText;
                int iTagType;
                int iTextSize;
                char sTextStyle;
                int iTextColor;
                int iBackColor;
                int iLocX;
                int iLocY;
                int iLocWidth;
                int iLocHeight;
                char sNoMouseEvent;
                
                sFactory = txtFactory.Text;
                sTagID = txtTagID.Text;
                sResType = txtResTagFlag.Text[0];
                sText = txtText.Text;
                iTagType = MPCF.ToInt(cboShape.SelectedIndex + 1);
                if (utcText.Color.IsSystemColor == true || utcText.Color.IsKnownColor == true)
                {
                    iTextColor = MPCF.ToInt(utcText.Color.ToKnownColor());
                }
                else
                {
                    iTextColor = utcText.Color.ToArgb();
                }
                if (cboSize.Text == "")
                {
                    iTextSize = 0;
                }
                else
                {
                    iTextSize = MPCF.ToInt(cboSize.Text);
                }
                if (cboTextStyle.SelectedIndex == - 1)
                {
                    sTextStyle = '0';
                }
                else
                {
                    sTextStyle = Convert.ToChar(cboTextStyle.SelectedIndex + '0');
                }
                if (utcBack.Color.IsSystemColor == true || utcBack.Color.IsKnownColor == true)
                {
                    iBackColor = MPCF.ToInt(utcBack.Color.ToKnownColor());
                }
                else
                {
                    iBackColor = utcBack.Color.ToArgb();
                }
                sLayoutID = txtLayOut.Text;
                iLocX = MPCF.ToInt(txtX.Text);
                iLocY = MPCF.ToInt(txtY.Text);
                if (cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1)
                {
                    iLocWidth = MPCF.ToInt(txtHeight.Text);
                    iLocHeight = MPCF.ToInt(txtWidth.Text);
                }
                else
                {
                    iLocWidth = MPCF.ToInt(txtWidth.Text);
                    iLocHeight = MPCF.ToInt(txtHeight.Text);
                }
                if (chkNoMouseEvent.Checked == true)
                {
                    sNoMouseEvent = 'Y';
                }
                else
                {
                    sNoMouseEvent = ' ';
                }
                if (sStep != modGlobalConstant.MP_STEP_DELETE)
                {
                    if (FMBCF.ViewLayOut(sFactory, sLayoutID, ref giWidth, ref giHeight) == true)
                    {
                        if (cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1)
                        {
                            if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtHeight.Text) > giWidth)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(20), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocX = giWidth - MPCF.ToInt(txtHeight.Text);
                                    txtX.Text = System.Convert.ToString(giWidth - MPCF.ToInt(txtHeight.Text));
                                }
                                else
                                {
                                    iLocX = MPCF.ToInt(txtX.Text);
                                }
                            }
                            if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtWidth.Text) > giHeight)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(21), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocY = giHeight - MPCF.ToInt(txtWidth.Text);
                                    txtY.Text = System.Convert.ToString(giHeight - MPCF.ToInt(txtWidth.Text));
                                }
                                else
                                {
                                    iLocY = MPCF.ToInt(txtY.Text);
                                }
                            }
                        }
                        else
                        {
                            if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtWidth.Text) > giWidth)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(20), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocX = giWidth - MPCF.ToInt(txtWidth.Text);
                                    txtX.Text = System.Convert.ToString(giWidth - MPCF.ToInt(txtWidth.Text));
                                }
                                else
                                {
                                    iLocX = MPCF.ToInt(txtX.Text);
                                }
                            }
                            if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtHeight.Text) > giHeight)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(21), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocY = giHeight - MPCF.ToInt(txtHeight.Text);
                                    txtY.Text = System.Convert.ToString(giHeight - MPCF.ToInt(txtHeight.Text));
                                }
                                else
                                {
                                    iLocY = MPCF.ToInt(txtY.Text);
                                }
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                
                if (FMBCF.UpdateResourceLocation(sStep, sFactory, sLayoutID, sTagID, sResType, sText, iTagType, iTextSize, sTextStyle, iTextColor, iBackColor, iLocX, iLocY, iLocWidth, iLocHeight, sNoMouseEvent, ' ') == false)
                {
                    return false;
                }

               
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.Update_Resource_Location()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
        private bool View_Resource()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_Resource_In");
                TRSNode out_node = new TRSNode("View_Resource_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = txtFactory.Text;
                in_node.ProcStep = '3';
                in_node.AddString("RES_ID", txtTagID.Text);
                in_node.AddChar("RES_TYPE", txtResTagFlag.Text[0]);
                in_node.AddString("LAYOUT_ID", txtLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }

                txtLayOut.Text = MPCF.RTrim(out_node.GetString("LAYOUT_ID"));

                cboShape.SelectedIndex = MPCF.ToInt(out_node.GetInt("TAG_TYPE")) -1;


                if (out_node.GetInt("TEXT_SIZE") == 0)
                {
                    cboSize.Text = "";
                }
                else
                {
                    cboSize.Text = MPCF.Trim(out_node.GetInt("TEXT_SIZE"));
                }

                if (MPCF.RTrim(out_node.GetChar("TEXT_STYLE")) == "")
                {
                    cboTextStyle.SelectedIndex = - 1;
                }
                else
                {
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE"));
                }


                txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));
                
                if (out_node.GetInt("TEXT_COLOR") < 0)
                {
                    utcText.Color = Color.FromArgb(out_node.GetInt("TEXT_COLOR"));
                }
                else if (out_node.GetInt("TEXT_COLOR") > 0)
                {
                    utcText.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("TEXT_COLOR"));
                }
                else if (out_node.GetInt("TEXT_COLOR") == 0)
                {
                    utcText.Text = "";
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

                if (out_node.GetChar("NO_MOUSE_EVENT") == 'Y')
                {
                    chkNoMouseEvent.Checked = true;
                }
                else
                {
                    chkNoMouseEvent.Checked = false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.View_Resource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
        private bool View_UDR_Resource()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_UDR_Resource_In");
                TRSNode out_node = new TRSNode("View_UDR_Resource_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';
                in_node.AddString("RES_ID", txtTagID.Text);
                in_node.AddChar("RES_TYPE", txtResTagFlag.Text[0]);
                in_node.AddString("GROUP_ID", txtLayOut.Text);

                if (MPCR.CallService("FMB", "FMB_View_UDR_Resource", in_node, ref out_node) == false)
                {
                    return false;
                }

                txtLayOut.Text = MPCF.RTrim(out_node.GetString("GROUP_ID"));
                txtText.Text = MPCF.RTrim(out_node.GetString("TEXT"));

                cboShape.SelectedIndex = MPCF.ToInt(out_node.GetInt("TAG_TYPE")) -1;


                if (out_node.GetInt("TEXT_SIZE") == 0)
                {
                    cboSize.Text = "";
                }
                else
                {
                    cboSize.Text = MPCF.Trim(out_node.GetInt("TEXT_SIZE"));
                }

                if (MPCF.RTrim(out_node.GetChar("TEXT_STYLE")) == "")
                {
                    cboTextStyle.SelectedIndex = - 1;
                }
                else
                {
                    cboTextStyle.SelectedIndex = MPCF.ToInt(out_node.GetChar("TEXT_STYLE").ToString());
                }
                
                
                if (out_node.GetInt("TEXT_COLOR") < 0)
                {
                    utcText.Color = Color.FromArgb(out_node.GetInt("TEXT_COLOR"));
                }
                else if (out_node.GetInt("TEXT_COLOR") > 0)
                {
                    utcText.Color = Color.FromKnownColor((KnownColor)out_node.GetInt("TEXT_COLOR"));
                }
                else if (out_node.GetInt("TEXT_COLOR") == 0)
                {
                    utcText.Text = "";
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

                if (out_node.GetChar("NO_MOUSE_EVENT") == 'Y')
                {
                    chkNoMouseEvent.Checked = true;
                }
                else
                {
                    chkNoMouseEvent.Checked = false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.View_UDR_Resource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
        private bool Update_UDR_ResLoc(char sStep)
        {
            
            try
            {
                string sFactory;
                string sLayoutID;
                string sTagID;
                char sResType;
                string sText;
                int iTagType;
                int iTextSize;
                char sTextStyle;
                int iTextColor;
                int iBackColor;
                int iLocX;
                int iLocY;
                int iLocWidth;
                int iLocHeight;
                char sNoMouseEvent;
                
                sFactory = MPGV.gsFactory;
                sLayoutID = txtLayOut.Text;
                sTagID = txtTagID.Text;
                sResType = txtResTagFlag.Text[0];
                sText = txtText.Text;
                
                if (utcText.Color.IsSystemColor == true || utcText.Color.IsKnownColor == true)
                {
                    iTextColor = MPCF.ToInt(utcText.Color.ToKnownColor());
                }
                else
                {
                    iTextColor = utcText.Color.ToArgb();
                }
                iTagType = MPCF.ToInt(cboShape.SelectedIndex + 1);
                if (cboSize.Text == "")
                {
                    iTextSize = 0;
                }
                else
                {
                    iTextSize = MPCF.ToInt(cboSize.Text);
                }
                if (cboTextStyle.SelectedIndex == - 1)
                {
                    sTextStyle = '0';
                }
                else
                {
                    sTextStyle = Convert.ToChar(cboTextStyle.SelectedIndex + '0');
                }
                if (utcBack.Color.IsSystemColor == true || utcBack.Color.IsKnownColor == true)
                {
                    iBackColor = MPCF.ToInt(utcBack.Color.ToKnownColor());
                }
                else
                {
                    iBackColor = utcBack.Color.ToArgb();
                }
                iLocX = MPCF.ToInt(txtX.Text);
                iLocY = MPCF.ToInt(txtY.Text);
                if (cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1)
                {
                    iLocWidth = MPCF.ToInt(txtHeight.Text);
                    iLocHeight = MPCF.ToInt(txtWidth.Text);
                }
                else
                {
                    iLocWidth = MPCF.ToInt(txtWidth.Text);
                    iLocHeight = MPCF.ToInt(txtHeight.Text);
                }
                
                if (chkNoMouseEvent.Checked == true)
                {
                    sNoMouseEvent = 'Y';
                }
                else
                {
                    sNoMouseEvent = ' ';
                }
                
                if (sStep != modGlobalConstant.MP_STEP_DELETE)
                {
                    if (FMBCF.ViewUDRGroup(sLayoutID, ref giWidth, ref giHeight) == true)
                    {
                        if (cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1)
                        {
                            if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtHeight.Text) > giWidth)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(20), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocX = giWidth - MPCF.ToInt(txtHeight.Text);
                                    txtX.Text = System.Convert.ToString(giWidth - MPCF.ToInt(txtHeight.Text));
                                }
                                else
                                {
                                    iLocX = MPCF.ToInt(txtX.Text);
                                }
                            }
                            if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtWidth.Text) > giHeight)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(21), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocY = giHeight - MPCF.ToInt(txtWidth.Text);
                                    txtY.Text = System.Convert.ToString(giHeight - MPCF.ToInt(txtWidth.Text));
                                }
                                else
                                {
                                    iLocY = MPCF.ToInt(txtY.Text);
                                }
                            }
                        }
                        else
                        {
                            if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtWidth.Text) > giWidth)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(20), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocX = giWidth - MPCF.ToInt(txtWidth.Text);
                                    txtX.Text = System.Convert.ToString(giWidth - MPCF.ToInt(txtWidth.Text));
                                }
                                else
                                {
                                    iLocX = MPCF.ToInt(txtX.Text);
                                }
                            }
                            if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtHeight.Text) > giHeight)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(21), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    iLocY = giHeight - MPCF.ToInt(txtHeight.Text);
                                    txtY.Text = System.Convert.ToString(giHeight - MPCF.ToInt(txtHeight.Text));
                                }
                                else
                                {
                                    iLocY = MPCF.ToInt(txtY.Text);
                                }
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                
                if (FMBCF.UpdateUDRResourceLocation(sStep, sFactory, sLayoutID, sTagID, sResType, sText, iTagType, iTextSize, sTextStyle, iTextColor, iBackColor, iLocX, iLocY, iLocWidth, iLocHeight, sNoMouseEvent, ' ') == false)
                {
                    return false;
                }

                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.Update_UDR_ResLoc()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateTag.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            if (Update_UDR_ResLoc(modGlobalConstant.MP_STEP_CREATE) == false)
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
                            if (Update_UDR_ResLoc(modGlobalConstant.MP_STEP_UPDATE) == false)
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
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            if (Update_UDR_ResLoc(modGlobalConstant.MP_STEP_DELETE) == false)
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
                MPCF.ShowMsgBox("frmFMBCreateTag.btnCreate_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBCreateTag_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                init();
                Set_ReadOnly();
                if (txtTagID.Text != "")
                {
                    if (ProcStep != modGlobalConstant.MP_STEP_CREATE)
                    {
                        txtTagID.ReadOnly = true;
                        if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            View_Resource();
                        }
                        else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            View_UDR_Resource();
                        }
                    }
                }
                if (ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    if (SelectedShapeIndex > - 1)
                    {
                        this.cboShape.SelectedIndex = SelectedShapeIndex;
                    }
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Create Tag";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Create Tag by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_UPDATE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Update Tag";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Update Tag by User Define Group";
                    }
                    btnCreate.Text = "Update";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "Delete Tag";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "Delete Tag by User Define Group";
                    }
                    btnCreate.Text = "Delete";
                }
                else if (ProcStep == modGlobalConstant.MP_STEP_VIEW)
                {
                    if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        this.Text = "View Tag";
                    }
                    else if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        this.Text = "View Tag by User Define Group";
                    }
                    btnCreate.Text = "Create";
                }
                
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.frmFMBCreateTag_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cboShape_SelectionChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                if (cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1 || cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.HorizontalLine) - 1)
                {
                    cboTextStyle.Enabled = false;
                    cboSize.Enabled = false;
                    utcText.Enabled = false;
                    cboTextStyle.Text = "";
                    cboSize.Text = "";
                    utcText.Text = "";
                    lblWidth.Text = "Length";
                    lblHeight.Text = "Thickness";
                    lblText.Font = new Font(lblText.Font, FontStyle.Regular);
                    utcBack.Enabled = true;
                }
                else if (cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.TextType) - 1)
                {
                    lblText.Font = new Font(lblText.Font, FontStyle.Bold);
                    utcBack.Color = Color.White;
                }
                else
                {
                    lblText.Font = new Font(lblText.Font, FontStyle.Regular);
                    cboTextStyle.Enabled = true;
                    cboSize.Enabled = true;
                    utcText.Enabled = true;
                    cboSize.Text = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextSize));
                    cboTextStyle.SelectedIndex = 0;
                    utcText.Color = (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultTextColor);
                    utcBack.Color = (System.Drawing.Color)modGlobalVariable.gGlobalOptions.GetOptions(txtFactory.Text, clsOptionData.Options.DefaultBackColor);
                    lblWidth.Text = "Width";
                    lblHeight.Text = "Height";
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateTag.cboShape_SelectionChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
        
    }
    
}
