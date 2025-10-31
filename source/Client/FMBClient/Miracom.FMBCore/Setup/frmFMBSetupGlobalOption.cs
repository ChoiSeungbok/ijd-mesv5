
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBSetupGlobalOption.vb
//   Description : Update Global Option
//
//   FMB Version : 1.0.0
//
//   Function List
//       - CheckCondition() : Check the conditions before transaction
//       - Update_Environment() : Update Global Option
//       - View_Environment() : View Global Option Information
//       - Update_Event_Color() : Update Resource Color
//       - ViewGlobalOption() : Set Global Options
//
//   Detail Description
//       -
//
//   History
//       - 2005-03-21 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------
namespace Miracom.FMBCore
{
    public class frmFMBSetupGlobalOption : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBSetupGlobalOption()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
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

        private System.ComponentModel.IContainer components;

        //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        
        //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
        //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.GroupBox grpFactory;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Button btnUpdate;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.GroupBox grpCreateInfo;
        internal System.Windows.Forms.Label lblUpdateTime;
        internal System.Windows.Forms.Label lblUpdateUser;
        internal System.Windows.Forms.Label lblCreateTime;
        internal System.Windows.Forms.Label lblCreateUser;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtUpdateTime;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtCreateTime;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtUpdateUser;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtCreateUser;
        internal FarPoint.Win.Spread.FpSpread spdSize;
        internal FarPoint.Win.Spread.SheetView spdSize_Sheet1;
        internal System.Windows.Forms.GroupBox grpSize;
        internal System.Windows.Forms.GroupBox grpOption;
        internal Infragistics.Win.UltraWinEditors.UltraCheckEditor chkEventColor;
        internal System.Windows.Forms.RadioButton rbnControl;
        internal System.Windows.Forms.RadioButton rbnProc;
        internal System.Windows.Forms.GroupBox grpSignal;
        internal System.Windows.Forms.Button btnView;
        internal Infragistics.Win.UltraWinEditors.UltraFontNameEditor ftnFontName;
        internal System.Windows.Forms.Label lblTextFontName;
        internal System.Windows.Forms.ImageList imlOptions;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcTextColor;
        internal System.Windows.Forms.Label lblTextColor;
        internal System.Windows.Forms.Label lblBackColor;
        internal Infragistics.Win.UltraWinEditors.UltraColorPicker utcBackColor;
        internal System.Windows.Forms.Label lblSize;
        internal Infragistics.Win.UltraWinEditors.UltraComboEditor cboBackOpt;
        internal Label lblBackOpt;
        internal Infragistics.Win.UltraWinEditors.UltraComboEditor cboSize;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer1 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer1 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmFMBSetupGlobalOption));
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer2 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer3 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle5 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle6 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle7 = new FarPoint.Win.Spread.NamedStyle("CornerDefault");
            FarPoint.Win.Spread.CellType.CornerRenderer cornerRenderer2 = new FarPoint.Win.Spread.CellType.CornerRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle8 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType2 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer4 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            Infragistics.Win.ValueListItem valueListItem1 = new Infragistics.Win.ValueListItem();
            Infragistics.Win.ValueListItem valueListItem2 = new Infragistics.Win.ValueListItem();
            this.pnlTop = new System.Windows.Forms.Panel();
            this.grpFactory = new System.Windows.Forms.GroupBox();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnView = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpOption = new System.Windows.Forms.GroupBox();
            this.imlOptions = new System.Windows.Forms.ImageList(this.components);
            this.cboSize = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.lblSize = new System.Windows.Forms.Label();
            this.lblBackColor = new System.Windows.Forms.Label();
            this.utcBackColor = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.lblTextColor = new System.Windows.Forms.Label();
            this.utcTextColor = new Infragistics.Win.UltraWinEditors.UltraColorPicker();
            this.lblTextFontName = new System.Windows.Forms.Label();
            this.ftnFontName = new Infragistics.Win.UltraWinEditors.UltraFontNameEditor();
            this.grpSignal = new System.Windows.Forms.GroupBox();
            this.rbnControl = new System.Windows.Forms.RadioButton();
            this.rbnProc = new System.Windows.Forms.RadioButton();
            this.chkEventColor = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.grpSize = new System.Windows.Forms.GroupBox();
            this.spdSize = new FarPoint.Win.Spread.FpSpread();
            this.spdSize_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.grpCreateInfo = new System.Windows.Forms.GroupBox();
            this.lblUpdateTime = new System.Windows.Forms.Label();
            this.lblUpdateUser = new System.Windows.Forms.Label();
            this.lblCreateTime = new System.Windows.Forms.Label();
            this.lblCreateUser = new System.Windows.Forms.Label();
            this.txtUpdateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtUpdateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.cboBackOpt = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.lblBackOpt = new System.Windows.Forms.Label();
            this.pnlTop.SuspendLayout();
            this.grpFactory.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            this.pnlBottom.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.grpOption.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cboSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBackColor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcTextColor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ftnFontName)).BeginInit();
            this.grpSignal.SuspendLayout();
            this.grpSize.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdSize_Sheet1)).BeginInit();
            this.grpCreateInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboBackOpt)).BeginInit();
            this.SuspendLayout();
            columnHeaderRenderer1.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer1.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer1.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer1.Name = "columnHeaderRenderer1";
            columnHeaderRenderer1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer1.TextRotationAngle = 0;
            rowHeaderRenderer1.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer1.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer1.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer1.Name = "rowHeaderRenderer1";
            rowHeaderRenderer1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer1.TextRotationAngle = 0;
            // 
            // pnlTop
            // 
            this.pnlTop.Controls.Add(this.grpFactory);
            this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTop.Location = new System.Drawing.Point(0, 0);
            this.pnlTop.Name = "pnlTop";
            this.pnlTop.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlTop.Size = new System.Drawing.Size(742, 52);
            this.pnlTop.TabIndex = 0;
            // 
            // grpFactory
            // 
            this.grpFactory.Controls.Add(this.cdvFactory);
            this.grpFactory.Controls.Add(this.lblFactory);
            this.grpFactory.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpFactory.Location = new System.Drawing.Point(3, 0);
            this.grpFactory.Name = "grpFactory";
            this.grpFactory.Size = new System.Drawing.Size(736, 52);
            this.grpFactory.TabIndex = 1;
            this.grpFactory.TabStop = false;
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
            this.cdvFactory.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvFactory_SelectedItemChanged);
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
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnUpdate);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 511);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 2;
            // 
            // btnView
            // 
            this.btnView.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnView.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnView.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnView.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnView.Location = new System.Drawing.Point(500, 9);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(74, 23);
            this.btnView.TabIndex = 0;
            this.btnView.Text = "View";
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnUpdate.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnUpdate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnUpdate.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUpdate.Location = new System.Drawing.Point(579, 9);
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
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.grpOption);
            this.pnlMid.Controls.Add(this.grpSize);
            this.pnlMid.Controls.Add(this.grpCreateInfo);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 52);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(742, 459);
            this.pnlMid.TabIndex = 1;
            // 
            // grpOption
            // 
            this.grpOption.Controls.Add(this.cboBackOpt);
            this.grpOption.Controls.Add(this.lblBackOpt);
            this.grpOption.Controls.Add(this.cboSize);
            this.grpOption.Controls.Add(this.lblSize);
            this.grpOption.Controls.Add(this.lblBackColor);
            this.grpOption.Controls.Add(this.utcBackColor);
            this.grpOption.Controls.Add(this.lblTextColor);
            this.grpOption.Controls.Add(this.utcTextColor);
            this.grpOption.Controls.Add(this.lblTextFontName);
            this.grpOption.Controls.Add(this.ftnFontName);
            this.grpOption.Controls.Add(this.grpSignal);
            this.grpOption.Controls.Add(this.chkEventColor);
            this.grpOption.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpOption.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpOption.Location = new System.Drawing.Point(352, 0);
            this.grpOption.Name = "grpOption";
            this.grpOption.Size = new System.Drawing.Size(387, 383);
            this.grpOption.TabIndex = 1;
            this.grpOption.TabStop = false;
            // 
            // imlOptions
            // 
            this.imlOptions.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imlOptions.ImageStream")));
            this.imlOptions.TransparentColor = System.Drawing.Color.Transparent;
            this.imlOptions.Images.SetKeyName(0, "");
            // 
            // cboSize
            // 
            this.cboSize.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboSize.Location = new System.Drawing.Point(116, 171);
            this.cboSize.Name = "cboSize";
            this.cboSize.Size = new System.Drawing.Size(126, 19);
            this.cboSize.TabIndex = 4;
            this.cboSize.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblSize
            // 
            this.lblSize.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSize.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblSize.Location = new System.Drawing.Point(8, 173);
            this.lblSize.Name = "lblSize";
            this.lblSize.Size = new System.Drawing.Size(100, 14);
            this.lblSize.TabIndex = 0;
            this.lblSize.Text = "Text Size";
            // 
            // lblBackColor
            // 
            this.lblBackColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBackColor.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblBackColor.Location = new System.Drawing.Point(8, 220);
            this.lblBackColor.Name = "lblBackColor";
            this.lblBackColor.Size = new System.Drawing.Size(100, 14);
            this.lblBackColor.TabIndex = 9;
            this.lblBackColor.Text = "Back Color";
            // 
            // utcBackColor
            // 
            this.utcBackColor.Location = new System.Drawing.Point(116, 218);
            this.utcBackColor.Name = "utcBackColor";
            this.utcBackColor.Size = new System.Drawing.Size(126, 19);
            this.utcBackColor.TabIndex = 6;
            this.utcBackColor.Text = "Control";
            this.utcBackColor.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblTextColor
            // 
            this.lblTextColor.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTextColor.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblTextColor.Location = new System.Drawing.Point(8, 196);
            this.lblTextColor.Name = "lblTextColor";
            this.lblTextColor.Size = new System.Drawing.Size(100, 14);
            this.lblTextColor.TabIndex = 8;
            this.lblTextColor.Text = "Text Color";
            // 
            // utcTextColor
            // 
            this.utcTextColor.Location = new System.Drawing.Point(116, 194);
            this.utcTextColor.Name = "utcTextColor";
            this.utcTextColor.Size = new System.Drawing.Size(126, 19);
            this.utcTextColor.TabIndex = 5;
            this.utcTextColor.Text = "Control";
            this.utcTextColor.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblTextFontName
            // 
            this.lblTextFontName.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTextFontName.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblTextFontName.Location = new System.Drawing.Point(12, 97);
            this.lblTextFontName.Name = "lblTextFontName";
            this.lblTextFontName.Size = new System.Drawing.Size(100, 14);
            this.lblTextFontName.TabIndex = 11;
            this.lblTextFontName.Text = "Text Font Name";
            // 
            // ftnFontName
            // 
            this.ftnFontName.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.ftnFontName.Location = new System.Drawing.Point(116, 93);
            this.ftnFontName.Name = "ftnFontName";
            this.ftnFontName.Size = new System.Drawing.Size(212, 21);
            this.ftnFontName.TabIndex = 1;
            // 
            // grpSignal
            // 
            this.grpSignal.Controls.Add(this.rbnControl);
            this.grpSignal.Controls.Add(this.rbnProc);
            this.grpSignal.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.grpSignal.Location = new System.Drawing.Point(8, 16);
            this.grpSignal.Name = "grpSignal";
            this.grpSignal.Size = new System.Drawing.Size(204, 68);
            this.grpSignal.TabIndex = 0;
            this.grpSignal.TabStop = false;
            this.grpSignal.Text = "Blue Signal";
            // 
            // rbnControl
            // 
            this.rbnControl.Location = new System.Drawing.Point(8, 44);
            this.rbnControl.Name = "rbnControl";
            this.rbnControl.Size = new System.Drawing.Size(168, 15);
            this.rbnControl.TabIndex = 1;
            this.rbnControl.Text = "Control Mode";
            // 
            // rbnProc
            // 
            this.rbnProc.Location = new System.Drawing.Point(8, 20);
            this.rbnProc.Name = "rbnProc";
            this.rbnProc.Size = new System.Drawing.Size(168, 15);
            this.rbnProc.TabIndex = 0;
            this.rbnProc.Text = "Proc Mode";
            // 
            // chkEventColor
            // 
            this.chkEventColor.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkEventColor.Location = new System.Drawing.Point(8, 127);
            this.chkEventColor.Name = "chkEventColor";
            this.chkEventColor.Size = new System.Drawing.Size(176, 14);
            this.chkEventColor.TabIndex = 2;
            this.chkEventColor.Text = "Changing Resource Color";
            this.chkEventColor.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.chkEventColor.CheckedChanged += new System.EventHandler(this.chkEventColor_CheckedChanged);
            // 
            // grpSize
            // 
            this.grpSize.Controls.Add(this.spdSize);
            this.grpSize.Dock = System.Windows.Forms.DockStyle.Left;
            this.grpSize.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpSize.Location = new System.Drawing.Point(3, 0);
            this.grpSize.Name = "grpSize";
            this.grpSize.Size = new System.Drawing.Size(349, 383);
            this.grpSize.TabIndex = 0;
            this.grpSize.TabStop = false;
            this.grpSize.Text = "Default Size";
            // 
            // spdSize
            // 
            this.spdSize.AccessibleDescription = "spdSize, Sheet1, Row 0, Column 0, ";
            this.spdSize.BackColor = System.Drawing.Color.White;
            this.spdSize.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdSize.FocusRenderer = defaultFocusIndicatorRenderer2;
            this.spdSize.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdSize.HorizontalScrollBar.Name = "";
            this.spdSize.HorizontalScrollBar.Renderer = defaultScrollBarRenderer3;
            this.spdSize.HorizontalScrollBar.TabIndex = 4;
            this.spdSize.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.Never;
            this.spdSize.Location = new System.Drawing.Point(3, 16);
            this.spdSize.Name = "spdSize";
            namedStyle5.BackColor = System.Drawing.SystemColors.Control;
            namedStyle5.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle5.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle5.Renderer = columnHeaderRenderer1;
            namedStyle5.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle6.BackColor = System.Drawing.SystemColors.Control;
            namedStyle6.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle6.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle6.Renderer = rowHeaderRenderer1;
            namedStyle6.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle7.BackColor = System.Drawing.SystemColors.Control;
            namedStyle7.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle7.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle7.Renderer = cornerRenderer2;
            namedStyle7.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle8.BackColor = System.Drawing.SystemColors.Window;
            namedStyle8.CellType = generalCellType2;
            namedStyle8.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle8.Renderer = generalCellType2;
            this.spdSize.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle5,
            namedStyle6,
            namedStyle7,
            namedStyle8});
            this.spdSize.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.spdSize.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdSize_Sheet1});
            this.spdSize.Size = new System.Drawing.Size(343, 364);
            this.spdSize.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdSize.TabIndex = 0;
            this.spdSize.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdSize.VerticalScrollBar.Name = "";
            this.spdSize.VerticalScrollBar.Renderer = defaultScrollBarRenderer4;
            this.spdSize.VerticalScrollBar.TabIndex = 5;
            // 
            // spdSize_Sheet1
            // 
            this.spdSize_Sheet1.Reset();
            this.spdSize_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdSize_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdSize_Sheet1.ColumnCount = 2;
            this.spdSize_Sheet1.RowCount = 15;
            this.spdSize_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Width";
            this.spdSize_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Height";
            this.spdSize_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdSize_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdSize_Sheet1.Columns.Get(0).Label = "Width";
            this.spdSize_Sheet1.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.Columns.Get(0).Width = 100F;
            this.spdSize_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdSize_Sheet1.Columns.Get(1).Label = "Height";
            this.spdSize_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.Columns.Get(1).Width = 100F;
            this.spdSize_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdSize_Sheet1.RowHeader.Cells.Get(0, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(0, 0).Value = "LayOut";
            this.spdSize_Sheet1.RowHeader.Cells.Get(0, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(1, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(1, 0).Value = "UDR Group";
            this.spdSize_Sheet1.RowHeader.Cells.Get(1, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(2, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(2, 0).Value = "Resource";
            this.spdSize_Sheet1.RowHeader.Cells.Get(2, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(3, 0).Value = "Sub Resource";
            this.spdSize_Sheet1.RowHeader.Cells.Get(4, 0).Value = "Port";
            this.spdSize_Sheet1.RowHeader.Cells.Get(5, 0).Value = "Tool";
            this.spdSize_Sheet1.RowHeader.Cells.Get(6, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(6, 0).Value = "Rectangle";
            this.spdSize_Sheet1.RowHeader.Cells.Get(6, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(7, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(7, 0).Value = "Ellipse";
            this.spdSize_Sheet1.RowHeader.Cells.Get(7, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(8, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(8, 0).Value = "Triangle";
            this.spdSize_Sheet1.RowHeader.Cells.Get(8, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(9, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(9, 0).Value = "Vertical Line";
            this.spdSize_Sheet1.RowHeader.Cells.Get(9, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(10, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(10, 0).Value = "Horizontal Line";
            this.spdSize_Sheet1.RowHeader.Cells.Get(10, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(11, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(11, 0).Value = "Pie 1 Type";
            this.spdSize_Sheet1.RowHeader.Cells.Get(11, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(12, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(12, 0).Value = "Pie 2 Type";
            this.spdSize_Sheet1.RowHeader.Cells.Get(12, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(13, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(13, 0).Value = "Pie 3 Type";
            this.spdSize_Sheet1.RowHeader.Cells.Get(13, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(14, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Cells.Get(14, 0).Value = "Pie 4 Type";
            this.spdSize_Sheet1.RowHeader.Cells.Get(14, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdSize_Sheet1.RowHeader.Columns.Default.Resizable = true;
            this.spdSize_Sheet1.RowHeader.Columns.Get(0).Width = 116F;
            this.spdSize_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdSize_Sheet1.Rows.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(0).Label = "LayOut";
            this.spdSize_Sheet1.Rows.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(2).Label = "Resource";
            this.spdSize_Sheet1.Rows.Get(6).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(6).Label = "Rectangle";
            this.spdSize_Sheet1.Rows.Get(7).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(7).Label = "Ellipse";
            this.spdSize_Sheet1.Rows.Get(8).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(8).Label = "Triangle";
            this.spdSize_Sheet1.Rows.Get(9).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(9).Label = "Vertical Line";
            this.spdSize_Sheet1.Rows.Get(10).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(10).Label = "Horizontal Line";
            this.spdSize_Sheet1.Rows.Get(11).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(11).Label = "Pie 1 Type";
            this.spdSize_Sheet1.Rows.Get(12).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(12).Label = "Pie 2 Type";
            this.spdSize_Sheet1.Rows.Get(13).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(13).Label = "Pie 3 Type";
            this.spdSize_Sheet1.Rows.Get(14).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdSize_Sheet1.Rows.Get(14).Label = "Pie 4 Type";
            this.spdSize_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdSize_Sheet1.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdSize_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // grpCreateInfo
            // 
            this.grpCreateInfo.Controls.Add(this.lblUpdateTime);
            this.grpCreateInfo.Controls.Add(this.lblUpdateUser);
            this.grpCreateInfo.Controls.Add(this.lblCreateTime);
            this.grpCreateInfo.Controls.Add(this.lblCreateUser);
            this.grpCreateInfo.Controls.Add(this.txtUpdateTime);
            this.grpCreateInfo.Controls.Add(this.txtCreateTime);
            this.grpCreateInfo.Controls.Add(this.txtUpdateUser);
            this.grpCreateInfo.Controls.Add(this.txtCreateUser);
            this.grpCreateInfo.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.grpCreateInfo.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpCreateInfo.Location = new System.Drawing.Point(3, 383);
            this.grpCreateInfo.Name = "grpCreateInfo";
            this.grpCreateInfo.Size = new System.Drawing.Size(736, 76);
            this.grpCreateInfo.TabIndex = 2;
            this.grpCreateInfo.TabStop = false;
            this.grpCreateInfo.Text = "Create / Update Info";
            // 
            // lblUpdateTime
            // 
            this.lblUpdateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblUpdateTime.Location = new System.Drawing.Point(392, 45);
            this.lblUpdateTime.Name = "lblUpdateTime";
            this.lblUpdateTime.Size = new System.Drawing.Size(100, 14);
            this.lblUpdateTime.TabIndex = 52;
            this.lblUpdateTime.Text = "Update Time";
            // 
            // lblUpdateUser
            // 
            this.lblUpdateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateUser.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblUpdateUser.Location = new System.Drawing.Point(12, 45);
            this.lblUpdateUser.Name = "lblUpdateUser";
            this.lblUpdateUser.Size = new System.Drawing.Size(100, 14);
            this.lblUpdateUser.TabIndex = 50;
            this.lblUpdateUser.Text = "Update User";
            // 
            // lblCreateTime
            // 
            this.lblCreateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateTime.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblCreateTime.Location = new System.Drawing.Point(392, 21);
            this.lblCreateTime.Name = "lblCreateTime";
            this.lblCreateTime.Size = new System.Drawing.Size(100, 14);
            this.lblCreateTime.TabIndex = 48;
            this.lblCreateTime.Text = "Create Time";
            // 
            // lblCreateUser
            // 
            this.lblCreateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateUser.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblCreateUser.Location = new System.Drawing.Point(12, 21);
            this.lblCreateUser.Name = "lblCreateUser";
            this.lblCreateUser.Size = new System.Drawing.Size(100, 14);
            this.lblCreateUser.TabIndex = 46;
            this.lblCreateUser.Text = "Create User";
            // 
            // txtUpdateTime
            // 
            this.txtUpdateTime.Location = new System.Drawing.Point(504, 43);
            this.txtUpdateTime.MaxLength = 20;
            this.txtUpdateTime.Name = "txtUpdateTime";
            this.txtUpdateTime.ReadOnly = true;
            this.txtUpdateTime.Size = new System.Drawing.Size(152, 19);
            this.txtUpdateTime.TabIndex = 3;
            this.txtUpdateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateTime
            // 
            this.txtCreateTime.Location = new System.Drawing.Point(504, 19);
            this.txtCreateTime.MaxLength = 20;
            this.txtCreateTime.Name = "txtCreateTime";
            this.txtCreateTime.ReadOnly = true;
            this.txtCreateTime.Size = new System.Drawing.Size(152, 19);
            this.txtCreateTime.TabIndex = 2;
            this.txtCreateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtUpdateUser
            // 
            this.txtUpdateUser.Location = new System.Drawing.Point(120, 43);
            this.txtUpdateUser.MaxLength = 20;
            this.txtUpdateUser.Name = "txtUpdateUser";
            this.txtUpdateUser.ReadOnly = true;
            this.txtUpdateUser.Size = new System.Drawing.Size(152, 19);
            this.txtUpdateUser.TabIndex = 1;
            this.txtUpdateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateUser
            // 
            this.txtCreateUser.Location = new System.Drawing.Point(120, 19);
            this.txtCreateUser.MaxLength = 20;
            this.txtCreateUser.Name = "txtCreateUser";
            this.txtCreateUser.ReadOnly = true;
            this.txtCreateUser.Size = new System.Drawing.Size(152, 19);
            this.txtCreateUser.TabIndex = 0;
            this.txtCreateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // cboBackOpt
            // 
            this.cboBackOpt.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            valueListItem1.DataValue = "Event";
            valueListItem2.DataValue = "Status";
            this.cboBackOpt.Items.AddRange(new Infragistics.Win.ValueListItem[] {
            valueListItem1,
            valueListItem2});
            this.cboBackOpt.Location = new System.Drawing.Point(116, 148);
            this.cboBackOpt.Name = "cboBackOpt";
            this.cboBackOpt.Size = new System.Drawing.Size(126, 19);
            this.cboBackOpt.TabIndex = 13;
            this.cboBackOpt.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblBackOpt
            // 
            this.lblBackOpt.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblBackOpt.ForeColor = System.Drawing.SystemColors.ControlText;
            this.lblBackOpt.Location = new System.Drawing.Point(8, 150);
            this.lblBackOpt.Name = "lblBackOpt";
            this.lblBackOpt.Size = new System.Drawing.Size(100, 14);
            this.lblBackOpt.TabIndex = 12;
            this.lblBackOpt.Text = "Back Color Property";
            // 
            // frmFMBSetupGlobalOption
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 551);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlBottom);
            this.Controls.Add(this.pnlTop);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBSetupGlobalOption";
            this.Tag = "FMB1001";
            this.Text = "Global Option Setup";
            this.Load += new System.EventHandler(this.frmFMBSetupGlobalOption_Load);
            this.pnlTop.ResumeLayout(false);
            this.grpFactory.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            this.pnlBottom.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.grpOption.ResumeLayout(false);
            this.grpOption.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cboSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcBackColor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.utcTextColor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ftnFontName)).EndInit();
            this.grpSignal.ResumeLayout(false);
            this.grpSize.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdSize_Sheet1)).EndInit();
            this.grpCreateInfo.ResumeLayout(false);
            this.grpCreateInfo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cboBackOpt)).EndInit();
            this.ResumeLayout(false);

        }
        
        #endregion
        
        #region " Constant Definition"
        private const int COL_WIDTH = 0;
        private const int COL_HEIGHT = 1;
        #endregion
        
        #region " Variable Definition"
        #endregion
        
        #region " Function Implementations"
        
        // CheckCondition()
        //       - Check the conditions before transaction
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String  : Step
        //
        private bool CheckCondition(string sStep)
        {
            
            try
            {
                int i;
                int j;
                switch (MPCF.RTrim(sStep))
                {
                    case "1":
                        
                        if (cdvFactory.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        break;
                    case "2":
                        
                        if (cdvFactory.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        for (i = 0; i <= spdSize.Sheets[0].RowCount - 1; i++)
                        {
                            for (j = 0; j <= spdSize.Sheets[0].ColumnCount - 1; j++)
                            {
                                if (System.Convert.ToString(spdSize.Sheets[0].GetValue(i, j)) == "")
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                                    spdSize.Sheets[0].SetActiveCell(i, j);
                                    spdSize.Select();
                                    return false;
                                }
                                else if (System.Convert.ToString(spdSize.Sheets[0].GetValue(i, j)) != "")
                                {
                                    if (MPCF.CheckNumeric(spdSize.Sheets[0].GetValue(i, j).ToString()) == false)
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(17), Application.ProductName, MessageBoxButtons.OK, 1);
                                        spdSize.Sheets[0].SetActiveCell(i, j);
                                        spdSize.Select();
                                        return false;
                                    }
                                }
                            }
                        }
                        if (ftnFontName.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            ftnFontName.Focus();
                            return false;
                        }
                        break;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Update_Environment()
        //       - Update Environment Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //

        private bool Update_Environment()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Update_Environment_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = modGlobalConstant.MP_STEP_UPDATE;
                           
                FarPoint.Win.Spread.SheetView with_1 = spdSize.Sheets[0];
                MPCR.SetInMsg(in_node);
                in_node.AddInt("LAYOUT_WIDTH", MPCF.ToInt(with_1.GetValue(0, COL_WIDTH)));
                in_node.AddInt("LAYOUT_HEIGHT", MPCF.ToInt(with_1.GetValue(0, COL_HEIGHT)));
                in_node.AddInt("UDR_WIDTH", MPCF.ToInt(with_1.GetValue(1, COL_WIDTH)));
                in_node.AddInt("UDR_HEIGHT", MPCF.ToInt(with_1.GetValue(1, COL_HEIGHT)));
                in_node.AddInt("RES_WIDTH", MPCF.ToInt(with_1.GetValue(2, COL_WIDTH)));
                in_node.AddInt("RES_HEIGHT", MPCF.ToInt(with_1.GetValue(2, COL_HEIGHT)));
                in_node.AddInt("SUBRES_WIDTH", MPCF.ToInt(with_1.GetValue(3, COL_WIDTH)));
                in_node.AddInt("SUBRES_HEIGHT", MPCF.ToInt(with_1.GetValue(3, COL_HEIGHT)));
                in_node.AddInt("PORT_WIDTH", MPCF.ToInt(with_1.GetValue(4, COL_WIDTH)));
                in_node.AddInt("PORT_HEIGHT", MPCF.ToInt(with_1.GetValue(4, COL_HEIGHT)));
                in_node.AddInt("TOOL_WIDTH", MPCF.ToInt(with_1.GetValue(5, COL_WIDTH)));
                in_node.AddInt("TOOL_HEIGHT", MPCF.ToInt(with_1.GetValue(5, COL_HEIGHT)));
                in_node.AddInt("RTG_WIDTH", MPCF.ToInt(with_1.GetValue(6, COL_WIDTH)));
                in_node.AddInt("RTG_HEIGHT", MPCF.ToInt(with_1.GetValue(6, COL_HEIGHT)));
                in_node.AddInt("ELP_WIDTH", MPCF.ToInt(with_1.GetValue(7, COL_WIDTH)));
                in_node.AddInt("ELP_HEIGHT", MPCF.ToInt(with_1.GetValue(7, COL_HEIGHT)));
                in_node.AddInt("TRI_WIDTH", MPCF.ToInt(with_1.GetValue(8, COL_WIDTH)));
                in_node.AddInt("TRI_HEIGHT", MPCF.ToInt(with_1.GetValue(8, COL_HEIGHT)));
                in_node.AddInt("VER_WIDTH", MPCF.ToInt(with_1.GetValue(9, COL_WIDTH)));
                in_node.AddInt("VER_HEIGHT", MPCF.ToInt(with_1.GetValue(9, COL_HEIGHT)));
                in_node.AddInt("HOR_WIDTH", MPCF.ToInt(with_1.GetValue(10, COL_WIDTH)));
                in_node.AddInt("HOR_HEIGHT", MPCF.ToInt(with_1.GetValue(10, COL_HEIGHT)));
                in_node.AddInt("PIE1_WIDTH", MPCF.ToInt(with_1.GetValue(11, COL_WIDTH)));
                in_node.AddInt("PIE1_HEIGHT", MPCF.ToInt(with_1.GetValue(11, COL_HEIGHT)));
                in_node.AddInt("PIE2_WIDTH", MPCF.ToInt(with_1.GetValue(12, COL_WIDTH)));
                in_node.AddInt("PIE2_HEIGHT", MPCF.ToInt(with_1.GetValue(12, COL_HEIGHT)));
                in_node.AddInt("PIE3_WIDTH", MPCF.ToInt(with_1.GetValue(13, COL_WIDTH)));
                in_node.AddInt("PIE3_HEIGHT", MPCF.ToInt(with_1.GetValue(13, COL_HEIGHT)));
                in_node.AddInt("PIE4_WIDTH", MPCF.ToInt(with_1.GetValue(14, COL_WIDTH)));
                in_node.AddInt("PIE4_HEIGHT", MPCF.ToInt(with_1.GetValue(14, COL_HEIGHT)));

                in_node.AddChar("EVENT_COLOR_FLAG", (chkEventColor.Checked== true ? 'Y' : ' '));
                in_node.AddChar("SIGNAL_FLAG", (rbnProc.Checked== true ? 'Y' : ' '));
                in_node.AddString("FONT_FAMILY", ftnFontName.Text);
                                    
                if (utcTextColor.Color.IsKnownColor == true)
                {
                    in_node.AddInt("TEXT_COLOR", (int)utcTextColor.Color.ToKnownColor());
                }
                else
                {
                    in_node.AddInt("TEXT_COLOR", utcTextColor.Color.ToArgb());
                }
                if (utcBackColor.Color.IsKnownColor == true)
                {
                    in_node.AddInt("BACK_COLOR", (int)utcBackColor.Color.ToKnownColor());
                }
                else
                {
                    in_node.AddInt("BACK_COLOR", utcBackColor.Color.ToArgb());
                }
                in_node.AddInt("TEXT_SIZE", MPCF.ToInt(cboSize.Text));

                in_node.AddString("BACK_OPT", cboBackOpt.Text);
                if (MPCR.CallService("FMB", "FMB_Update_Environment", in_node, ref out_node) == false)
                {
                    return false;
                }
                
                MPCR.ShowSuccessMsg(out_node);
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.Update_Environment()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // View_Environment()
        //       - View Environment Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool View_Environment()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_Environment_In");
                TRSNode out_node = new TRSNode("View_Environment_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = '1';

                if (MPCR.CallService("FMB", "FMB_View_Environment", in_node, ref out_node) == false)
                {
                    return false;
                }
                
                FarPoint.Win.Spread.SheetView with_1 = spdSize.Sheets[0];
                with_1.SetValue(0, COL_WIDTH, MPCF.ToInt(out_node.GetInt("LAYOUT_WIDTH")));
                with_1.SetValue(0, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("LAYOUT_HEIGHT")));
                with_1.SetValue(1, COL_WIDTH, MPCF.ToInt(out_node.GetInt("UDR_WIDTH")));
                with_1.SetValue(1, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("UDR_HEIGHT")));
                with_1.SetValue(2, COL_WIDTH, MPCF.ToInt(out_node.GetInt("RES_WIDTH")));
                with_1.SetValue(2, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("RES_HEIGHT")));
                with_1.SetValue(3, COL_WIDTH, MPCF.ToInt(out_node.GetInt("SUBRES_WIDTH")));
                with_1.SetValue(3, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("SUBRES_HEIGHT")));
                with_1.SetValue(4, COL_WIDTH, MPCF.ToInt(out_node.GetInt("PORT_WIDTH")));
                with_1.SetValue(4, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("PORT_HEIGHT")));
                with_1.SetValue(5, COL_WIDTH, MPCF.ToInt(out_node.GetInt("TOOL_WIDTH")));
                with_1.SetValue(5, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("TOOL_HEIGHT")));
                with_1.SetValue(6, COL_WIDTH, MPCF.ToInt(out_node.GetInt("RTG_WIDTH")));
                with_1.SetValue(6, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("RTG_HEIGHT")));
                with_1.SetValue(7, COL_WIDTH, MPCF.ToInt(out_node.GetInt("ELP_WIDTH")));
                with_1.SetValue(7, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("ELP_HEIGHT")));
                with_1.SetValue(8, COL_WIDTH, MPCF.ToInt(out_node.GetInt("TRI_WIDTH")));
                with_1.SetValue(8, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("TRI_HEIGHT")));
                with_1.SetValue(9, COL_WIDTH, MPCF.ToInt(out_node.GetInt("VER_WIDTH")));
                with_1.SetValue(9, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("VER_HEIGHT")));
                with_1.SetValue(10, COL_WIDTH, MPCF.ToInt(out_node.GetInt("HOR_WIDTH")));
                with_1.SetValue(10, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("HOR_HEIGHT")));
                with_1.SetValue(11, COL_WIDTH, MPCF.ToInt(out_node.GetInt("PIE1_WIDTH")));
                with_1.SetValue(11, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("PIE1_HEIGHT")));
                with_1.SetValue(12, COL_WIDTH, MPCF.ToInt(out_node.GetInt("PIE2_WIDTH")));
                with_1.SetValue(12, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("PIE2_HEIGHT")));
                with_1.SetValue(13, COL_WIDTH, MPCF.ToInt(out_node.GetInt("PIE3_WIDTH")));
                with_1.SetValue(13, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("PIE3_HEIGHT")));
                with_1.SetValue(14, COL_WIDTH, MPCF.ToInt(out_node.GetInt("PIE4_WIDTH")));
                with_1.SetValue(14, COL_HEIGHT, MPCF.ToInt(out_node.GetInt("PIE4_HEIGHT")));
                chkEventColor.Checked = (MPCF.RTrim(out_node.GetChar("EVENT_COLOR_FLAG")) == "Y") ? true : false;
                if (chkEventColor.Checked == true)
                {
                    cboBackOpt.ReadOnly = false;
                    cboBackOpt.Text = out_node.GetString("BACK_OPT");                    
                }
                else
                {
                    cboBackOpt.SelectedIndex = -1;
                    cboBackOpt.ReadOnly = true;
                }
                if (out_node.GetChar("SIGNAL_FLAG") == 'P')
                {
                    rbnProc.Checked = true;
                }
                else
                {
                    rbnControl.Checked = true;
                }
                
                if (out_node.GetInt("TEXT_COLOR") < 0)
                {
                    utcTextColor.Color = System.Drawing.Color.FromArgb(out_node.GetInt("TEXT_COLOR"));
                }
                else if (out_node.GetInt("TEXT_COLOR") > 0)
                {
                    utcTextColor.Color = System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetInt("TEXT_COLOR"));
                }
                else
                {
                    utcTextColor.Color = SystemColors.Control;
                }
                
                if (out_node.GetInt("BACK_COLOR") < 0)
                {
                    utcBackColor.Color = System.Drawing.Color.FromArgb(out_node.GetInt("BACK_COLOR"));
                }
                else if (out_node.GetInt("BACK_COLOR") > 0)
                {
                    utcBackColor.Color = System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetInt("BACK_COLOR"));
                }
                else
                {
                    utcBackColor.Color = SystemColors.Control;
                }
                cboSize.Text = Convert.ToString(out_node.GetInt("TEXT_SIZE"));

                ftnFontName.Text = MPCF.RTrim(out_node.GetString("FONT_FAMILY"));
                txtCreateUser.Text = MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));
                txtCreateTime.Text = MPCF.MakeDateFormat(out_node.GetString("CREATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtUpdateUser.Text = MPCF.RTrim(out_node.GetString("UPDATE_USER_ID"));
                txtUpdateTime.Text = MPCF.MakeDateFormat(out_node.GetString("UPDATE_TIME"), DATE_TIME_FORMAT.NONE);
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.Update_Environment()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        #endregion
        
        #region " Event Implementations"
        
        private void cdvFactory_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                cdvFactory.Init();
                cdvFactory.Columns.Add("Factory", 100, HorizontalAlignment.Left);
                cdvFactory.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFactory.SelectedSubItemIndex = 0;
                cdvFactory.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1',null);
                cdvFactory.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnUpdate_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("2") == false)
                {
                    return;
                }
                if (Update_Environment() == false)
                {
                    return;
                }
                
                
                if (FMBCF.ViewGlobalOption(cdvFactory.Text) == false)
                {
                    return;
                }
                
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.btnUpdate_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnClose_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                this.Dispose();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void chkEventColor_CheckedChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                //if (MPGV.gcLanguage == '2')
                //{
                //    btnSetting.Text = "설정";
                //}
                //else
                //{
                //    btnSetting.Text = "Setting";
                //}
                
                //if (chkEventColor.Checked == true)
                //{
                //    btnSetting.Visible = true;
                //}
                //else
                //{
                //    btnSetting.Visible = false;
                //    pnlResColorSetting.Visible = false;
                //}
                if (chkEventColor.Checked == true)
                {
                    cboBackOpt.ReadOnly = false;
                }
                else
                {
                    cboBackOpt.SelectedIndex = -1;
                    cboBackOpt.ReadOnly = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.chkEventColor_CheckedChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                spdSize_Sheet1.ClearRange(0, 0, 12, 2, true);
                MPCF.FieldClear(grpOption, null, null, null, null, null, false);
                MPCF.FieldClear(grpCreateInfo, null, null, null, null, null, false);
                rbnProc.Checked = true;
                
                btnView.PerformClick();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.cdvFactory_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnView_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("1") == false)
                {
                    return;
                }
                if (View_Environment() == false)
                {
                    return;
                }
                //if (modListRoutine.ViewEventColorList(lisEvent, '1', MPCF.RTrim(cdvFactory.Text)) == false)
                //{
                //    return;
                //}
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.btnView_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        //private void btnSetting_Click(System.Object sender, System.EventArgs e)
        //{
            
        //    try
        //    {
        //        pnlResColorSetting.Visible = ! pnlResColorSetting.Visible;
                
        //        if (pnlResColorSetting.Visible == true)
        //        {
        //            if (MPGV.gcLanguage == '2')
        //            {
        //                btnSetting.Text = "닫기";
        //            }
        //            else
        //            {
        //                btnSetting.Text = "Close";
        //            }
        //        }
        //        else
        //        {
        //            if (MPGV.gcLanguage == '2')
        //            {
        //                btnSetting.Text = "설정";
        //            }
        //            else
        //            {
        //                btnSetting.Text = "Setting";
        //            }
        //        }
                
        //    }
        //    catch (Exception ex)
        //    {
        //        MPCF.ShowMsgBox("frmFMBSetupGlobalOption.btnSetting_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
        //    }
            
        //}
        
        //private void lisEvent_SelectedIndexChanged(System.Object sender, System.EventArgs e)
        //{
            
        //    try
        //    {
        //        if (lisEvent.SelectedItems.Count < 1)
        //        {
        //            utcBack.Visible = false;
        //            return;
        //        }
                
        //        utcBack.Visible = true;
        //        utcBack.Color = lisEvent.SelectedItems[0].SubItems[0].BackColor;
        //        Rectangle rect = lisEvent.GetItemRect(lisEvent.SelectedItems[0].Index);
                
        //        utcBack.Location = new Point(utcBack.Left, rect.Y - 1);
                
                
        //    }
        //    catch (Exception ex)
        //    {
        //        MPCF.ShowMsgBox("frmFMBSetupGlobalOption.lisEvent_SelectedIndexChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
        //    }
            
        //}
        
        //private void lisEvent_VisibleChanged(System.Object sender, System.EventArgs e)
        //{
            
        //    try
        //    {
        //        if (lisEvent.SelectedItems.Count > 0)
        //        {
        //            utcBack.Visible = true;
        //        }
        //        else
        //        {
        //            utcBack.Visible = false;
        //        }
                
        //    }
        //    catch (Exception ex)
        //    {
        //        MPCF.ShowMsgBox("frmFMBSetupGlobalOption.lisEvent_VisibleChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
        //    }
            
        //}
        
        //private void utcBack_ColorChanged(object sender, System.EventArgs e)
        //{
            
        //    try
        //    {
        //        lisEvent.SelectedItems[0].SubItems[0].BackColor = utcBack.Color;
        //        lisEvent.SelectedItems[0].SubItems[1].Text = utcBack.Text;
                
        //    }
        //    catch (Exception ex)
        //    {
        //        MPCF.ShowMsgBox("frmFMBSetupGlobalOption.utcBack_ColorChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
        //    }
            
        //}
        
        private void cdvFactory_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(grpOption, null, null, null, null, null, false);
                MPCF.FieldClear(grpCreateInfo, null, null, null, null, null, false);
                rbnProc.Checked = true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBSetupGlobalOption_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                FMBCF.SetFontSize(cboSize);
                cboSize.SelectedIndex = 2;
                
                FMBCF.CheckAllFactoryOption(cdvFactory);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.frmFMBSetupGlobalOption_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
