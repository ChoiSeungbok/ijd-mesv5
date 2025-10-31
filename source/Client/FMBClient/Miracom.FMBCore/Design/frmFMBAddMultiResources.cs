
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.MsgHandler;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBAddMultiResources.vb
//   Description : Add Multi Resources to Layout
//
//   FMB Version : 1.0.0
//
//   Function List
//       - ViewResourceList() : View Resource List
//       - ViewUDRResourceList() : View User Define Group Resource List
//       - View_Resource() : View Resource Information
//       - Save_Resource() : Save Resource Information
//       - Init() : Initialize form
//       - Update_Resource_List() : Update Resource Llst
//       - Update_UDRRes_List() : Update User Define Resource Liset
//
//   Detail Description
//       - 2005-11-15 : Created by H.K.Kim
//
//   History
//       -
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public class frmFMBAddMultiResources : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBAddMultiResources()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        public frmFMBAddMultiResources(string sFactory, string sGroupID, string sLayOut)
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            sSelectFactory = sFactory;
            sSelectGroup = sGroupID;
            sSelectLayOut = sLayOut;
            
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
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Button btnOK;
        internal System.Windows.Forms.Panel pnlCenter;
        internal System.Windows.Forms.Panel pnlDesign;
        internal System.Windows.Forms.GroupBox grpInfo;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBack;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcText;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtY;
        internal System.Windows.Forms.Label lblY;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtHeight;
        internal System.Windows.Forms.Label lblHeight;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtWidth;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtX;
        internal System.Windows.Forms.Label lblWidth;
        internal System.Windows.Forms.Label lblX;
        internal System.Windows.Forms.Label lblBackColor;
        internal Infragistics.Win.UltraWinEditors.UltraComboEditor cboTextStyle;
        internal System.Windows.Forms.Label lblStyle;
        internal System.Windows.Forms.Label lblColor;
        internal Infragistics.Win.UltraWinEditors.UltraComboEditor cboSize;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtText;
        internal System.Windows.Forms.Label txtSize;
        internal System.Windows.Forms.Label lblText;
        internal System.Windows.Forms.Panel pnlResource;
        internal Miracom.UI.Controls.MCListView.MCListView lisResourceList;
        internal System.Windows.Forms.ColumnHeader colRes;
        internal System.Windows.Forms.ColumnHeader colDesc;
        internal System.Windows.Forms.ColumnHeader colLocX;
        internal System.Windows.Forms.ColumnHeader colLocY;
        internal System.Windows.Forms.ColumnHeader colWidth;
        internal System.Windows.Forms.ColumnHeader colHeight;
        internal System.Windows.Forms.ColumnHeader colText;
        internal System.Windows.Forms.ColumnHeader colTextSize;
        internal System.Windows.Forms.ColumnHeader colTextColor;
        internal System.Windows.Forms.ColumnHeader colTextStyle;
        internal System.Windows.Forms.ColumnHeader colBackColor;
        internal System.Windows.Forms.Button btnSave;
        internal System.Windows.Forms.ColumnHeader colLastEvent;
        internal System.Windows.Forms.ColumnHeader colPriSts;
        internal System.Windows.Forms.ColumnHeader colProc;
        internal System.Windows.Forms.ColumnHeader colCtrl;
        internal System.Windows.Forms.ColumnHeader colUpDown;
        internal System.Windows.Forms.ColumnHeader colResType;
        internal System.Windows.Forms.Button btnSelect;
        internal System.Windows.Forms.ColumnHeader colArea;
        internal System.Windows.Forms.ColumnHeader colSubArea;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            base.Load += new System.EventHandler(frmFMBAddMultiResources_Load);
            this.btnSelect = new System.Windows.Forms.Button();
            this.btnSelect.Click += new System.EventHandler(btnSelect_Click);
            this.btnClose = new System.Windows.Forms.Button();
            this.btnClose.Click += new System.EventHandler(btnClose_Click);
            this.btnOK = new System.Windows.Forms.Button();
            this.btnOK.Click += new System.EventHandler(btnOK_Click);
            this.btnSave = new System.Windows.Forms.Button();
            this.btnSave.Click += new System.EventHandler(btnSave_Click);
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.pnlResource = new System.Windows.Forms.Panel();
            this.lisResourceList = new Miracom.UI.Controls.MCListView.MCListView();
            this.lisResourceList.SelectedIndexChanged += new System.EventHandler(lisResourceList_SelectedIndexChanged);
            this.colRes = new System.Windows.Forms.ColumnHeader();
            this.colDesc = new System.Windows.Forms.ColumnHeader();
            this.colText = new System.Windows.Forms.ColumnHeader();
            this.colTextColor = new System.Windows.Forms.ColumnHeader();
            this.colBackColor = new System.Windows.Forms.ColumnHeader();
            this.colTextSize = new System.Windows.Forms.ColumnHeader();
            this.colTextStyle = new System.Windows.Forms.ColumnHeader();
            this.colWidth = new System.Windows.Forms.ColumnHeader();
            this.colHeight = new System.Windows.Forms.ColumnHeader();
            this.colLocX = new System.Windows.Forms.ColumnHeader();
            this.colLocY = new System.Windows.Forms.ColumnHeader();
            this.colLastEvent = new System.Windows.Forms.ColumnHeader();
            this.colPriSts = new System.Windows.Forms.ColumnHeader();
            this.colProc = new System.Windows.Forms.ColumnHeader();
            this.colCtrl = new System.Windows.Forms.ColumnHeader();
            this.colUpDown = new System.Windows.Forms.ColumnHeader();
            this.colResType = new System.Windows.Forms.ColumnHeader();
            this.pnlDesign = new System.Windows.Forms.Panel();
            this.grpInfo = new System.Windows.Forms.GroupBox();
            this.utcBack = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.utcText = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.txtY = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblY = new System.Windows.Forms.Label();
            this.txtHeight = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblHeight = new System.Windows.Forms.Label();
            this.txtWidth = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtX = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
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
            this.colArea = new System.Windows.Forms.ColumnHeader();
            this.colSubArea = new System.Windows.Forms.ColumnHeader();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlResource.SuspendLayout();
            this.pnlDesign.SuspendLayout();
            this.grpInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize) this.utcBack).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.utcText).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtY).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtHeight).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtWidth).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtX).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cboTextStyle).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cboSize).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.txtText).BeginInit();
            this.SuspendLayout();
            //
            //pnlBottom
            //
            this.pnlBottom.Controls.Add(this.btnSelect);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Controls.Add(this.btnOK);
            this.pnlBottom.Controls.Add(this.btnSave);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 342);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(677, 40);
            this.pnlBottom.TabIndex = 1;
            //
            //btnSelect
            //
            this.btnSelect.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnSelect.Location = new System.Drawing.Point(8, 9);
            this.btnSelect.Name = "btnSelect";
            this.btnSelect.Size = new System.Drawing.Size(74, 23);
            this.btnSelect.TabIndex = 3;
            this.btnSelect.Tag = "S";
            this.btnSelect.Text = "Select All";
            //
            //btnClose
            //
            this.btnClose.Anchor = (System.Windows.Forms.AnchorStyles) (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Location = new System.Drawing.Point(593, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 2;
            this.btnClose.Text = "Close";
            //
            //btnOK
            //
            this.btnOK.Anchor = (System.Windows.Forms.AnchorStyles) (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
            this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOK.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnOK.Location = new System.Drawing.Point(513, 9);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(74, 23);
            this.btnOK.TabIndex = 1;
            this.btnOK.Text = "OK";
            //
            //btnSave
            //
            this.btnSave.Anchor = (System.Windows.Forms.AnchorStyles) (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
            this.btnSave.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnSave.Location = new System.Drawing.Point(433, 9);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(74, 23);
            this.btnSave.TabIndex = 0;
            this.btnSave.Text = "Save";
            //
            //pnlCenter
            //
            this.pnlCenter.Controls.Add(this.pnlResource);
            this.pnlCenter.Controls.Add(this.pnlDesign);
            this.pnlCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenter.Location = new System.Drawing.Point(0, 0);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Size = new System.Drawing.Size(677, 342);
            this.pnlCenter.TabIndex = 0;
            //
            //pnlResource
            //
            this.pnlResource.Controls.Add(this.lisResourceList);
            this.pnlResource.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlResource.DockPadding.Left = 3;
            this.pnlResource.DockPadding.Right = 3;
            this.pnlResource.DockPadding.Top = 3;
            this.pnlResource.Location = new System.Drawing.Point(0, 0);
            this.pnlResource.Name = "pnlResource";
            this.pnlResource.Size = new System.Drawing.Size(677, 246);
            this.pnlResource.TabIndex = 0;
            //
            //lisResourceList
            //
            this.lisResourceList.CheckBoxes = true;
            this.lisResourceList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] { this.colRes, this.colDesc, this.colArea, this.colSubArea, this.colText, this.colTextColor, this.colBackColor, this.colTextSize, this.colTextStyle, this.colWidth, this.colHeight, this.colLocX, this.colLocY, this.colLastEvent, this.colPriSts, this.colProc, this.colCtrl, this.colUpDown, this.colResType });
            this.lisResourceList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisResourceList.EnableSort = true;
            this.lisResourceList.EnableSortIcon = true;
            this.lisResourceList.FullRowSelect = true;
            this.lisResourceList.Location = new System.Drawing.Point(3, 3);
            this.lisResourceList.Name = "lisResourceList";
            this.lisResourceList.Size = new System.Drawing.Size(671, 243);
            this.lisResourceList.TabIndex = 2;
            this.lisResourceList.View = System.Windows.Forms.View.Details;
            //
            //colRes
            //
            this.colRes.Text = "Resource ID";
            this.colRes.Width = 100;
            //
            //colDesc
            //
            this.colDesc.Text = "Desc ";
            this.colDesc.Width = 115;
            //
            //colText
            //
            this.colText.Text = "Text";
            this.colText.Width = 120;
            //
            //colTextColor
            //
            this.colTextColor.Text = "Text Color";
            this.colTextColor.Width = 120;
            //
            //colBackColor
            //
            this.colBackColor.Text = "Back Color";
            this.colBackColor.Width = 120;
            //
            //colTextSize
            //
            this.colTextSize.Text = "Text Size";
            this.colTextSize.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //colTextStyle
            //
            this.colTextStyle.Text = "Text Style";
            this.colTextStyle.Width = 100;
            //
            //colWidth
            //
            this.colWidth.Text = "Width";
            this.colWidth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //colHeight
            //
            this.colHeight.Text = "Height";
            this.colHeight.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //colLocX
            //
            this.colLocX.Text = "Loc X";
            this.colLocX.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //colLocY
            //
            this.colLocY.Text = "Loc Y";
            this.colLocY.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //colLastEvent
            //
            this.colLastEvent.Width = 0;
            //
            //colPriSts
            //
            this.colPriSts.Width = 0;
            //
            //colProc
            //
            this.colProc.Width = 0;
            //
            //colCtrl
            //
            this.colCtrl.Width = 0;
            //
            //colUpDown
            //
            this.colUpDown.Width = 0;
            //
            //colResType
            //
            this.colResType.Width = 0;
            //
            //pnlDesign
            //
            this.pnlDesign.Controls.Add(this.grpInfo);
            this.pnlDesign.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlDesign.DockPadding.Left = 3;
            this.pnlDesign.DockPadding.Right = 3;
            this.pnlDesign.Location = new System.Drawing.Point(0, 246);
            this.pnlDesign.Name = "pnlDesign";
            this.pnlDesign.Size = new System.Drawing.Size(677, 96);
            this.pnlDesign.TabIndex = 0;
            //
            //grpInfo
            //
            this.grpInfo.Controls.Add(this.utcBack);
            this.grpInfo.Controls.Add(this.utcText);
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
            this.grpInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpInfo.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpInfo.Location = new System.Drawing.Point(3, 0);
            this.grpInfo.Name = "grpInfo";
            this.grpInfo.Size = new System.Drawing.Size(671, 96);
            this.grpInfo.TabIndex = 2;
            this.grpInfo.TabStop = false;
            //
            //utcBack
            //
            this.utcBack.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.utcBack.Location = new System.Drawing.Point(544, 16);
            this.utcBack.Name = "utcBack";
            this.utcBack.Size = new System.Drawing.Size(120, 19);
            this.utcBack.TabIndex = 2;
            this.utcBack.Text = "Control";
            //
            //utcText
            //
            this.utcText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.utcText.Location = new System.Drawing.Point(323, 16);
            this.utcText.Name = "utcText";
            this.utcText.Size = new System.Drawing.Size(120, 19);
            this.utcText.TabIndex = 1;
            this.utcText.Text = "Control";
            //
            //txtY
            //
            this.txtY.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtY.Location = new System.Drawing.Point(323, 66);
            this.txtY.MaxLength = 6;
            this.txtY.Name = "txtY";
            this.txtY.Size = new System.Drawing.Size(120, 19);
            this.txtY.TabIndex = 7;
            //
            //lblY
            //
            this.lblY.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblY.Location = new System.Drawing.Point(231, 68);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(88, 14);
            this.lblY.TabIndex = 47;
            this.lblY.Text = "Location Y";
            //
            //txtHeight
            //
            this.txtHeight.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtHeight.Location = new System.Drawing.Point(544, 66);
            this.txtHeight.MaxLength = 6;
            this.txtHeight.Name = "txtHeight";
            this.txtHeight.Size = new System.Drawing.Size(120, 19);
            this.txtHeight.TabIndex = 8;
            //
            //lblHeight
            //
            this.lblHeight.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHeight.Location = new System.Drawing.Point(452, 68);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(88, 14);
            this.lblHeight.TabIndex = 45;
            this.lblHeight.Text = "Height";
            //
            //txtWidth
            //
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtWidth.Location = new System.Drawing.Point(544, 40);
            this.txtWidth.MaxLength = 6;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(120, 19);
            this.txtWidth.TabIndex = 5;
            //
            //txtX
            //
            this.txtX.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtX.Location = new System.Drawing.Point(104, 66);
            this.txtX.MaxLength = 6;
            this.txtX.Name = "txtX";
            this.txtX.Size = new System.Drawing.Size(120, 19);
            this.txtX.TabIndex = 6;
            //
            //lblWidth
            //
            this.lblWidth.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblWidth.Location = new System.Drawing.Point(452, 42);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(88, 14);
            this.lblWidth.TabIndex = 42;
            this.lblWidth.Text = "Width";
            //
            //lblX
            //
            this.lblX.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblX.Location = new System.Drawing.Point(12, 68);
            this.lblX.Name = "lblX";
            this.lblX.Size = new System.Drawing.Size(88, 14);
            this.lblX.TabIndex = 41;
            this.lblX.Text = "Location X ";
            //
            //lblBackColor
            //
            this.lblBackColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBackColor.Location = new System.Drawing.Point(452, 18);
            this.lblBackColor.Name = "lblBackColor";
            this.lblBackColor.Size = new System.Drawing.Size(88, 14);
            this.lblBackColor.TabIndex = 37;
            this.lblBackColor.Text = "Back Color";
            //
            //cboTextStyle
            //
            this.cboTextStyle.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboTextStyle.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.cboTextStyle.Location = new System.Drawing.Point(323, 40);
            this.cboTextStyle.Name = "cboTextStyle";
            this.cboTextStyle.Size = new System.Drawing.Size(120, 19);
            this.cboTextStyle.TabIndex = 4;
            //
            //lblStyle
            //
            this.lblStyle.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblStyle.Location = new System.Drawing.Point(231, 44);
            this.lblStyle.Name = "lblStyle";
            this.lblStyle.Size = new System.Drawing.Size(88, 14);
            this.lblStyle.TabIndex = 34;
            this.lblStyle.Text = "Text Style";
            //
            //lblColor
            //
            this.lblColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblColor.Location = new System.Drawing.Point(231, 18);
            this.lblColor.Name = "lblColor";
            this.lblColor.Size = new System.Drawing.Size(88, 14);
            this.lblColor.TabIndex = 33;
            this.lblColor.Text = "Text Color";
            //
            //cboSize
            //
            this.cboSize.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboSize.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.cboSize.Location = new System.Drawing.Point(104, 40);
            this.cboSize.Name = "cboSize";
            this.cboSize.Size = new System.Drawing.Size(120, 19);
            this.cboSize.TabIndex = 3;
            //
            //txtText
            //
            this.txtText.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtText.Location = new System.Drawing.Point(104, 16);
            this.txtText.MaxLength = 40;
            this.txtText.Name = "txtText";
            this.txtText.Size = new System.Drawing.Size(120, 19);
            this.txtText.TabIndex = 0;
            //
            //txtSize
            //
            this.txtSize.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.txtSize.Location = new System.Drawing.Point(12, 44);
            this.txtSize.Name = "txtSize";
            this.txtSize.Size = new System.Drawing.Size(88, 14);
            this.txtSize.TabIndex = 30;
            this.txtSize.Text = "Text Font Size";
            //
            //lblText
            //
            this.lblText.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblText.Location = new System.Drawing.Point(12, 20);
            this.lblText.Name = "lblText";
            this.lblText.Size = new System.Drawing.Size(88, 14);
            this.lblText.TabIndex = 29;
            this.lblText.Text = "Text";
            //
            //colArea
            //
            this.colArea.Text = "Area ID";
            this.colArea.Width = 100;
            //
            //colSubArea
            //
            this.colSubArea.Text = "Sub Area ID";
            this.colSubArea.Width = 100;
            //
            //frmFMBAddMultiResources
            //
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(677, 382);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFMBAddMultiResources";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Add Multi Resources";
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlResource.ResumeLayout(false);
            this.pnlDesign.ResumeLayout(false);
            this.grpInfo.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize) this.utcBack).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.utcText).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtY).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtHeight).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtWidth).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtX).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cboTextStyle).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cboSize).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.txtText).EndInit();
            this.ResumeLayout(false);
            
        }
        
        #endregion
        
        #region " Constant Definition"
        
        private const int MAX_UPDATE_COUNT = 500;
        
        #endregion
        
        #region " Variable Definition"
        
        private string sSelectFactory = "";
        private string sSelectGroup = "";
        private string sSelectLayOut = "";
        
        #endregion
        
        #region " Function Implementations"
        
        // ViewResourceList()
        //       - View Resource List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - control as Control : Control
        //       - sStep as String    : Proc Step
        //
        private bool ViewResourceList(Control control, char sStep)
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_Resource_List_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();
                  int i;
                string sColorName;
                ListViewItem itmX;
                
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.Factory = sSelectFactory;

                in_node.AddString("NEXT_RES_ID", "");

                do
                {
                    out_node = new TRSNode("View_Resource_List_Out");

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
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")));
                                if (((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextColor)).IsKnownColor == true)
                                {
                                    itmX.SubItems.Add(((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextColor)).Name);
                                }
                                else
                                {
                                    sColorName = FMBCF.ConvertColorToString((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextColor));
                                    itmX.SubItems.Add(sColorName);
                                }
                                if (((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultBackColor)).IsKnownColor == true)
                                {
                                    itmX.SubItems.Add(((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultBackColor)).Name);
                                }
                                else
                                {
                                    sColorName = FMBCF.ConvertColorToString((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultBackColor));
                                    itmX.SubItems.Add(sColorName);
                                }
                                itmX.SubItems.Add(MPCF.ToInt(modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextSize)).ToString());
                                itmX.SubItems.Add(FontStyle.Regular.ToString());
                                itmX.SubItems.Add(((Size)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultResourceSize)).Width.ToString());
                                itmX.SubItems.Add(((Size)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultResourceSize)).Height.ToString());
                                itmX.SubItems.Add("10");
                                itmX.SubItems.Add("10");
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PRI_STS")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("UP_DOWN_FLAG")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("IMAGE_IDX")));

                                ((ListView)control).Items.Add(itmX);
                            }
                        }
                    }
                }
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.ViewResourceList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
        private bool ViewUDRResourceList(Control control, char sStep)
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_UDR_Resource_List_In");
                TRSNode out_node;

                  int i;
                ListViewItem itmX;
                string sColorName;
                ArrayList a_list = new ArrayList();
                
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("NEXT_RES_ID", "");
                in_node.AddString("GROUP_ID", MPCF.RTrim(sSelectGroup));
                
                do
                {
                    out_node = new TRSNode("FMB_View_Resource_List_Out");

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
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")));
                                if (((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextColor)).IsKnownColor == true)
                                {
                                    itmX.SubItems.Add(((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextColor)).Name);
                                }
                                else
                                {
                                    sColorName = FMBCF.ConvertColorToString((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextColor));
                                    itmX.SubItems.Add(sColorName);
                                }
                                if (((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultBackColor)).IsKnownColor == true)
                                {
                                    itmX.SubItems.Add(((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultBackColor)).Name);
                                }
                                else
                                {
                                    sColorName = FMBCF.ConvertColorToString((Color)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultBackColor));
                                    itmX.SubItems.Add(sColorName);
                                }
                                itmX.SubItems.Add(MPCF.ToInt(modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultTextSize)).ToString());
                                itmX.SubItems.Add(FontStyle.Regular.ToString());
                                itmX.SubItems.Add(((Size)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultResourceSize)).Width.ToString());
                                itmX.SubItems.Add(((Size)modGlobalVariable.gGlobalOptions.GetOptions(sSelectFactory, clsOptionData.Options.DefaultResourceSize)).Height.ToString());
                                itmX.SubItems.Add("10");
                                itmX.SubItems.Add("10");
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PRI_STS")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("IMAGE_IDX")));

                                ((ListView)control).Items.Add(itmX);
                            }
                        }
                    }
                }

                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.ViewUDRResourceList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // View_Resource()
        //       - View Resource Information
        // Return Value
        //       -
        // Arguments
        //       - ByVal idx As Integer
        //
        private void View_Resource(int idx)
        {
            
            try
            {
                
                txtText.Text = MPCF.Trim(lisResourceList.Items[idx].SubItems[4].Text);
                
                if (Color.FromName(lisResourceList.Items[idx].SubItems[5].Text).ToKnownColor() > 0)
                {
                    utcText.Color = Color.FromName(lisResourceList.Items[idx].SubItems[5].Text);
                }
                else
                {
                    utcText.Color = Color.FromArgb(FMBCF.ConvertStringToColor(lisResourceList.Items[idx].SubItems[5].Text));
                }
                if (Color.FromName(lisResourceList.Items[idx].SubItems[6].Text).ToKnownColor() > 0)
                {
                    utcBack.Color = Color.FromName(lisResourceList.Items[idx].SubItems[6].Text);
                }
                else
                {
                    utcBack.Color = Color.FromArgb(FMBCF.ConvertStringToColor(lisResourceList.Items[idx].SubItems[6].Text));
                }
                
                cboSize.Text = MPCF.Trim(lisResourceList.Items[idx].SubItems[7].Text);
                cboTextStyle.Text = MPCF.Trim(lisResourceList.Items[idx].SubItems[8].Text);
                txtWidth.Text = MPCF.Trim(lisResourceList.Items[idx].SubItems[9].Text);
                txtHeight.Text = MPCF.Trim(lisResourceList.Items[idx].SubItems[10].Text);
                txtX.Text = MPCF.Trim(lisResourceList.Items[idx].SubItems[11].Text);
                txtY.Text = MPCF.Trim(lisResourceList.Items[idx].SubItems[12].Text);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.View_Resource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        // Save_Resource()
        //       - Save Resource Information
        // Return Value
        //       -
        // Arguments
        //       - ByVal idx As Integer
        //
        private void Save_Resource()
        {
            
            try
            {
                int i;
                for (i = 0; i <= lisResourceList.SelectedItems.Count - 1; i++)
                {
                    lisResourceList.SelectedItems[i].Checked = true;
                    
                    if (lisResourceList.SelectedItems.Count == 1)
                    {
                        lisResourceList.SelectedItems[i].SubItems[4].Text = txtText.Text;
                    }
                    
                    if (utcText.Color.IsKnownColor == true)
                    {
                        lisResourceList.SelectedItems[i].SubItems[5].Text = utcText.Color.Name;
                    }
                    else
                    {
                        lisResourceList.SelectedItems[i].SubItems[5].Text = FMBCF.ConvertColorToString(utcText.Color);
                    }
                    
                    if (utcBack.Color.IsKnownColor == true)
                    {
                        lisResourceList.SelectedItems[i].SubItems[6].Text = utcBack.Color.Name;
                    }
                    else
                    {
                        lisResourceList.SelectedItems[i].SubItems[6].Text = FMBCF.ConvertColorToString(utcBack.Color);
                    }
                    lisResourceList.SelectedItems[i].SubItems[7].Text = cboSize.Text;
                    lisResourceList.SelectedItems[i].SubItems[8].Text = cboTextStyle.Text;
                    if (MPCF.RTrim(txtWidth.Text) != "")
                    {
                        lisResourceList.SelectedItems[i].SubItems[9].Text = txtWidth.Text;
                    }
                    if (MPCF.RTrim(txtHeight.Text) != "")
                    {
                        lisResourceList.SelectedItems[i].SubItems[10].Text = txtHeight.Text;
                    }
                    if (MPCF.RTrim(txtX.Text) != "")
                    {
                        lisResourceList.SelectedItems[i].SubItems[11].Text = txtX.Text;
                    }
                    if (MPCF.RTrim(txtY.Text) != "")
                    {
                        lisResourceList.SelectedItems[i].SubItems[12].Text = txtY.Text;
                    }
                    int iWidth = new int();
                    int iHeight = new int();
                    if (this.Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        if (FMBCF.ViewLayOut(sSelectFactory, sSelectLayOut, ref iWidth, ref iHeight) == true)
                        {
                            if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtWidth.Text) > iWidth)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(20), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    lisResourceList.SelectedItems[i].SubItems[11].Text = System.Convert.ToString(iWidth - System.Convert.ToDouble(txtWidth.Text));
                                    txtX.Text = System.Convert.ToString(iWidth - System.Convert.ToDouble(txtWidth.Text));
                                }
                                else
                                {
                                    lisResourceList.SelectedItems[i].SubItems[11].Text = txtX.Text;
                                }
                            }
                            if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtHeight.Text) > iHeight)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(21), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    lisResourceList.SelectedItems[i].SubItems[12].Text = System.Convert.ToString(iHeight - System.Convert.ToDouble(txtHeight.Text));
                                    txtY.Text = System.Convert.ToString(iHeight - System.Convert.ToDouble(txtHeight.Text));
                                }
                                else
                                {
                                    lisResourceList.SelectedItems[i].SubItems[12].Text = txtY.Text;
                                }
                            }
                        }
                    }
                    else if (this.Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        if (FMBCF.ViewUDRGroup(sSelectGroup, ref iWidth, ref iHeight) == true)
                        {
                            if (MPCF.ToInt(txtX.Text) + MPCF.ToInt(txtWidth.Text) > iWidth)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(20), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    lisResourceList.SelectedItems[i].SubItems[11].Text = System.Convert.ToString(iWidth - System.Convert.ToDouble(txtWidth.Text));
                                    txtX.Text = System.Convert.ToString(iWidth - System.Convert.ToDouble(txtWidth.Text));
                                }
                                else
                                {
                                    lisResourceList.SelectedItems[i].SubItems[11].Text = txtX.Text;
                                }
                            }
                            if (MPCF.ToInt(txtY.Text) + MPCF.ToInt(txtHeight.Text) > iHeight)
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(21), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                                {
                                    lisResourceList.SelectedItems[i].SubItems[12].Text = System.Convert.ToString(iHeight - System.Convert.ToDouble(txtHeight.Text));
                                    txtY.Text = System.Convert.ToString(iHeight - System.Convert.ToDouble(txtHeight.Text));
                                }
                                else
                                {
                                    lisResourceList.SelectedItems[i].SubItems[12].Text = txtY.Text;
                                }
                            }
                        }
                    }
                }
                
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.Save_Resource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        // Init()
        //       - Initialize form
        // Return Value
        //       -
        // Arguments
        //       -
        //
        private void Init()
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                FMBCF.SetEnumList(cboTextStyle, typeof(FontStyle));
                FMBCF.SetFontSize(cboSize);
                cboTextStyle.SelectedIndex = 0;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.Init()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        // Update_Resource_List()
        //       - Create/Update/Delete Resource Location
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool Update_Resource_List()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Update_ResLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");
                TRSNode list;

                int i;
                int j;
                int k;
    
                MPCR.SetInMsg(in_node);
                in_node.Factory = sSelectFactory;
                in_node.ProcStep = modGlobalConstant.MP_STEP_CREATE;

                j = 0;
                do
                {
                    k = lisResourceList.CheckedItems.Count -(MAX_UPDATE_COUNT +(MAX_UPDATE_COUNT * j));
                    if (k > 0)
                    {
                        k = 0;
                    }
                    for (i = MAX_UPDATE_COUNT * j; i <= (MAX_UPDATE_COUNT +(MAX_UPDATE_COUNT * j) + k) - 1; i++)
                    {
                        list = in_node.AddNode("RES_LIST");
                        
                        list.AddString("RES_ID", lisResourceList.CheckedItems[i].Text);
                        list.AddString("TEXT", lisResourceList.CheckedItems[i].SubItems[4].Text);
                        list.AddChar("RES_TYPE", 'R');

                           if (Color.FromName(lisResourceList.CheckedItems[i].SubItems[5].Text).ToKnownColor() > 0)
                        {
                            list.AddInt("TEXT_COLOR", MPCF.ToInt(Color.FromName(lisResourceList.CheckedItems[i].SubItems[5].Text).ToKnownColor()));
                        }
                        else
                        {
                            list.AddInt("TEXT_COLOR", FMBCF.ConvertStringToColor(lisResourceList.CheckedItems[i].SubItems[5].Text));
                        }
                        
                        if (Color.FromName(lisResourceList.CheckedItems[i].SubItems[6].Text).ToKnownColor() > 0)
                        {
                            list.AddInt("BACK_COLOR", MPCF.ToInt(Color.FromName(lisResourceList.CheckedItems[i].SubItems[6].Text).ToKnownColor()));
                        }
                        else
                        {
                            list.AddInt("BACK_COLOR", FMBCF.ConvertStringToColor(lisResourceList.CheckedItems[i].SubItems[6].Text));
                        }
                        list.AddInt("TEXT_SIZE", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[7].Text));
                        list.AddChar("TEXT_STYLE", MPCF.ToChar(MPCF.ToInt(@Enum.Parse(typeof(FontStyle), MPCF.Trim(lisResourceList.CheckedItems[i].SubItems[8].Text)))));

                        list.AddInt("LOC_WIDTH", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[9].Text));
                        list.AddInt("LOC_HEIGHT", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[10].Text));
                        list.AddInt("LOC_X", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[11].Text));
                        list.AddInt("LOC_Y", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[12].Text));
                        list.AddInt("TAG_TYPE", MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Resource));
                        list.AddChar("SIGNAL_FLAG", '1');
                    }

                    in_node.SetString("LAYOUT_ID", sSelectLayOut);

                    if (MPCR.CallService("FMB", "FMB_Update_ResLoc_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    
                    j++;
                } while (!(k < 0));
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.Update_Resource_Location()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Update_UDRRes_List()
        //       - Create/Update/Delete Resource Location
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool Update_UDRRes_List()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Update_UDRLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");
                TRSNode list;

                int i;
                int j;
                int k;
                
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = modGlobalConstant.MP_STEP_CREATE;
                in_node.AddString("GROUP_ID", sSelectGroup);
                
                j = 0;
                do
                {
                    k = lisResourceList.CheckedItems.Count -(MAX_UPDATE_COUNT +(MAX_UPDATE_COUNT * j));
                    if (k > 0)
                    {
                        k = 0;
                    }
                    
                    for (i = MAX_UPDATE_COUNT * j; i <= (MAX_UPDATE_COUNT +(MAX_UPDATE_COUNT * j) + k) - 1; i++)
                    {
                        list = in_node.AddNode("RES_LIST");
                        
                        list.AddString("RES_ID", lisResourceList.CheckedItems[i].Text);
                        list.AddString("TEXT", lisResourceList.CheckedItems[i].SubItems[4].Text);
                        list.AddChar("RES_TYPE", 'R');

                        if (Color.FromName(lisResourceList.CheckedItems[i].SubItems[5].Text).ToKnownColor() > 0)
                        {
                            list.AddInt("TEXT_COLOR", MPCF.ToInt(Color.FromName(lisResourceList.CheckedItems[i].SubItems[5].Text).ToKnownColor()));
                        }
                        else
                        {
                            list.AddInt("TEXT_COLOR", FMBCF.ConvertStringToColor(lisResourceList.CheckedItems[i].SubItems[5].Text));
                        }
                        
                        if (Color.FromName(lisResourceList.CheckedItems[i].SubItems[6].Text).ToKnownColor() > 0)
                        {
                            list.AddInt("BACK_COLOR", MPCF.ToInt(Color.FromName(lisResourceList.CheckedItems[i].SubItems[6].Text).ToKnownColor()));
                        }
                        else
                        {
                            list.AddInt("BACK_COLOR", FMBCF.ConvertStringToColor(lisResourceList.CheckedItems[i].SubItems[6].Text));
                        }
                        list.AddInt("TEXT_SIZE", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[7].Text));
                        list.AddChar("TEXT_STYLE", MPCF.ToChar(MPCF.ToInt(@Enum.Parse(typeof(FontStyle), MPCF.Trim(lisResourceList.CheckedItems[i].SubItems[8].Text)))));

                        list.AddInt("LOC_WIDTH", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[9].Text));
                        list.AddInt("LOC_HEIGHT", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[10].Text));
                        list.AddInt("LOC_X", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[11].Text));
                        list.AddInt("LOC_Y", MPCF.ToInt(lisResourceList.CheckedItems[i].SubItems[12].Text));
                        list.AddInt("TAG_TYPE", MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Resource));
                        list.AddChar("SIGNAL_FLAG", '1');
                    }

                    if (MPCR.CallService("FMB", "FMB_Update_UDRLoc_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    j++;
                } while (!(k < 0));
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.Update_UDRRes_List()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        #endregion
        
        #region " Event Implementations"
        
        private void frmFMBAddMultiResources_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                Init();
                if (this.Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    ViewResourceList(lisResourceList, '4');
                }
                else if (this.Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    ViewUDRResourceList(lisResourceList, '4');
                }
                
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.frmFMBAddMultiResources_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void lisResourceList_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                if (lisResourceList.SelectedItems.Count == 0)
                {
                    return;
                }
                
                View_Resource(lisResourceList.SelectedItems[0].Index);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.lisResourceList_SelectedIndexChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnSave_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                //int i;
                if (lisResourceList.SelectedItems.Count == 0)
                {
                    return;
                }
                Save_Resource();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.btnSave_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnOK_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                if (lisResourceList.CheckedItems.Count == 0 || lisResourceList.Items.Count == 0)
                {
                    return;
                }
                if (this.Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    Update_Resource_List();
                }
                else if (this.Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    Update_UDRRes_List();
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.btnOK_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnSelect_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                int i;
                if (lisResourceList.Items.Count == 0)
                {
                    return;
                }
                if (btnSelect.Tag.ToString() == "S")
                {
                    for (i = 0; i <= lisResourceList.Items.Count - 1; i++)
                    {
                        lisResourceList.Items[i].Checked = true;
                    }
                    btnSelect.Text = MPCF.FindLanguage("Deselect All", 1);
                    btnSelect.Tag = "D";
                }
                else if (btnSelect.Tag.ToString() == "D")
                {
                    for (i = 0; i <= lisResourceList.Items.Count - 1; i++)
                    {
                        lisResourceList.Items[i].Checked = false;
                    }
                    btnSelect.Text = MPCF.FindLanguage("Select All", 1);
                    btnSelect.Tag = "S";
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.btnSelect_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnClose_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                //Me.Dispose(False)
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBAddMultiResources.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
