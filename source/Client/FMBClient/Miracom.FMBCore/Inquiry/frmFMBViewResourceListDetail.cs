
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;

using Miracom.CliFrx;
using Miracom.MESCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBViewResourceListDetail.vb
//   Description : View Resource List Detail
//
//   FMB Version : 1.0.0
//
//   Function List
//       - CheckCondition() : Check the conditions before transaction
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-17 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------
namespace Miracom.FMBCore
{
    public class frmFMBViewResourceListDetail : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBViewResourceListDetail()
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
        
        //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        private System.ComponentModel.Container components = null;
        
        //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
        //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Button btnView;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlMainHeader;
        internal System.Windows.Forms.GroupBox grpOption;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvAreaID;
        internal System.Windows.Forms.Label lblArea;
        internal System.Windows.Forms.Label lblResType;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvSubAreaID;
        internal System.Windows.Forms.Label lblSubAreaID;
        internal Infragistics.Win.UltraWinEditors.UltraCheckEditor chkIncludeDeleteRes;
        internal System.Windows.Forms.Panel pnlCenter;
        internal Miracom.UI.Controls.MCListView.MCListView lisResourceList;
        internal System.Windows.Forms.ColumnHeader colSeq;
        internal System.Windows.Forms.ColumnHeader colRes;
        internal System.Windows.Forms.ColumnHeader colDesc;
        internal System.Windows.Forms.ColumnHeader colType;
        internal System.Windows.Forms.ColumnHeader colUpDown;
        internal System.Windows.Forms.ColumnHeader colPriSts;
        internal System.Windows.Forms.ColumnHeader colPrt1;
        internal System.Windows.Forms.ColumnHeader colPrt2;
        internal System.Windows.Forms.ColumnHeader colPrt3;
        internal System.Windows.Forms.ColumnHeader colPrt4;
        internal System.Windows.Forms.ColumnHeader colPrt5;
        internal System.Windows.Forms.ColumnHeader colPrt6;
        internal System.Windows.Forms.ColumnHeader colPrt7;
        internal System.Windows.Forms.ColumnHeader colPrt8;
        internal System.Windows.Forms.ColumnHeader colPrt9;
        internal System.Windows.Forms.ColumnHeader colPrt10;
        internal System.Windows.Forms.ColumnHeader colSts1;
        internal System.Windows.Forms.ColumnHeader colSts2;
        internal System.Windows.Forms.ColumnHeader colSts3;
        internal System.Windows.Forms.ColumnHeader colSts4;
        internal System.Windows.Forms.ColumnHeader colSts5;
        internal System.Windows.Forms.ColumnHeader colSts6;
        internal System.Windows.Forms.ColumnHeader colSts7;
        internal System.Windows.Forms.ColumnHeader colSts8;
        internal System.Windows.Forms.ColumnHeader colSts9;
        internal System.Windows.Forms.ColumnHeader colSts10;
        internal System.Windows.Forms.ColumnHeader colUseFac;
        internal System.Windows.Forms.ColumnHeader colLastEvent;
        internal System.Windows.Forms.ColumnHeader colLastEventTime;
        internal System.Windows.Forms.ColumnHeader colLastStartTime;
        internal System.Windows.Forms.ColumnHeader colLastEndTime;
        internal System.Windows.Forms.ColumnHeader colProcCount;
        internal System.Windows.Forms.ColumnHeader colMaxProcCount;
        internal System.Windows.Forms.ColumnHeader colLastActiveHistSeq;
        internal System.Windows.Forms.ColumnHeader colLastHistSeq;
        internal System.Windows.Forms.ColumnHeader colCreateUser;
        internal System.Windows.Forms.ColumnHeader colCreateTime;
        internal System.Windows.Forms.ColumnHeader colUpdateUser;
        internal System.Windows.Forms.ColumnHeader colUpdateTime;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvType;
        internal System.Windows.Forms.ColumnHeader colResTagFlag;
        internal System.Windows.Forms.ColumnHeader colLayOut;
        internal System.Windows.Forms.ColumnHeader colLocX;
        internal System.Windows.Forms.ColumnHeader colLocY;
        internal System.Windows.Forms.ColumnHeader colWidth;
        internal System.Windows.Forms.ColumnHeader colHeight;
        internal System.Windows.Forms.ColumnHeader colText;
        internal System.Windows.Forms.ColumnHeader colTextSize;
        internal System.Windows.Forms.ColumnHeader colTextColor;
        internal System.Windows.Forms.ColumnHeader colTextStyle;
        internal System.Windows.Forms.ColumnHeader colBackColor;
        internal System.Windows.Forms.ColumnHeader colProc;
        internal System.Windows.Forms.ColumnHeader colCtrl;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnView = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.pnlMainHeader = new System.Windows.Forms.Panel();
            this.grpOption = new System.Windows.Forms.GroupBox();
            this.chkIncludeDeleteRes = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.cdvSubAreaID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblSubAreaID = new System.Windows.Forms.Label();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.cdvAreaID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblArea = new System.Windows.Forms.Label();
            this.cdvType = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblResType = new System.Windows.Forms.Label();
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.lisResourceList = new Miracom.UI.Controls.MCListView.MCListView();
            this.colSeq = new System.Windows.Forms.ColumnHeader();
            this.colRes = new System.Windows.Forms.ColumnHeader();
            this.colDesc = new System.Windows.Forms.ColumnHeader();
            this.colType = new System.Windows.Forms.ColumnHeader();
            this.colProc = new System.Windows.Forms.ColumnHeader();
            this.colCtrl = new System.Windows.Forms.ColumnHeader();
            this.colUpDown = new System.Windows.Forms.ColumnHeader();
            this.colPriSts = new System.Windows.Forms.ColumnHeader();
            this.colPrt1 = new System.Windows.Forms.ColumnHeader();
            this.colPrt2 = new System.Windows.Forms.ColumnHeader();
            this.colPrt3 = new System.Windows.Forms.ColumnHeader();
            this.colPrt4 = new System.Windows.Forms.ColumnHeader();
            this.colPrt5 = new System.Windows.Forms.ColumnHeader();
            this.colPrt6 = new System.Windows.Forms.ColumnHeader();
            this.colPrt7 = new System.Windows.Forms.ColumnHeader();
            this.colPrt8 = new System.Windows.Forms.ColumnHeader();
            this.colPrt9 = new System.Windows.Forms.ColumnHeader();
            this.colPrt10 = new System.Windows.Forms.ColumnHeader();
            this.colSts1 = new System.Windows.Forms.ColumnHeader();
            this.colSts2 = new System.Windows.Forms.ColumnHeader();
            this.colSts3 = new System.Windows.Forms.ColumnHeader();
            this.colSts4 = new System.Windows.Forms.ColumnHeader();
            this.colSts5 = new System.Windows.Forms.ColumnHeader();
            this.colSts6 = new System.Windows.Forms.ColumnHeader();
            this.colSts7 = new System.Windows.Forms.ColumnHeader();
            this.colSts8 = new System.Windows.Forms.ColumnHeader();
            this.colSts9 = new System.Windows.Forms.ColumnHeader();
            this.colSts10 = new System.Windows.Forms.ColumnHeader();
            this.colUseFac = new System.Windows.Forms.ColumnHeader();
            this.colLastEvent = new System.Windows.Forms.ColumnHeader();
            this.colLastEventTime = new System.Windows.Forms.ColumnHeader();
            this.colLastStartTime = new System.Windows.Forms.ColumnHeader();
            this.colLastEndTime = new System.Windows.Forms.ColumnHeader();
            this.colProcCount = new System.Windows.Forms.ColumnHeader();
            this.colMaxProcCount = new System.Windows.Forms.ColumnHeader();
            this.colLastActiveHistSeq = new System.Windows.Forms.ColumnHeader();
            this.colLastHistSeq = new System.Windows.Forms.ColumnHeader();
            this.colCreateUser = new System.Windows.Forms.ColumnHeader();
            this.colCreateTime = new System.Windows.Forms.ColumnHeader();
            this.colUpdateUser = new System.Windows.Forms.ColumnHeader();
            this.colUpdateTime = new System.Windows.Forms.ColumnHeader();
            this.colResTagFlag = new System.Windows.Forms.ColumnHeader();
            this.colLayOut = new System.Windows.Forms.ColumnHeader();
            this.colLocX = new System.Windows.Forms.ColumnHeader();
            this.colLocY = new System.Windows.Forms.ColumnHeader();
            this.colWidth = new System.Windows.Forms.ColumnHeader();
            this.colHeight = new System.Windows.Forms.ColumnHeader();
            this.colText = new System.Windows.Forms.ColumnHeader();
            this.colTextSize = new System.Windows.Forms.ColumnHeader();
            this.colTextColor = new System.Windows.Forms.ColumnHeader();
            this.colTextStyle = new System.Windows.Forms.ColumnHeader();
            this.colBackColor = new System.Windows.Forms.ColumnHeader();
            this.pnlBottom.SuspendLayout();
            this.pnlMainHeader.SuspendLayout();
            this.grpOption.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvSubAreaID)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvAreaID)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvType)).BeginInit();
            this.pnlCenter.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 506);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 1;
            // 
            // btnView
            // 
            this.btnView.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnView.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnView.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnView.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnView.Location = new System.Drawing.Point(579, 9);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(74, 23);
            this.btnView.TabIndex = 0;
            this.btnView.Text = "View";
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
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
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // pnlMainHeader
            // 
            this.pnlMainHeader.Controls.Add(this.grpOption);
            this.pnlMainHeader.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlMainHeader.Location = new System.Drawing.Point(0, 0);
            this.pnlMainHeader.Name = "pnlMainHeader";
            this.pnlMainHeader.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMainHeader.Size = new System.Drawing.Size(742, 92);
            this.pnlMainHeader.TabIndex = 0;
            // 
            // grpOption
            // 
            this.grpOption.Controls.Add(this.chkIncludeDeleteRes);
            this.grpOption.Controls.Add(this.cdvSubAreaID);
            this.grpOption.Controls.Add(this.lblSubAreaID);
            this.grpOption.Controls.Add(this.cdvFactory);
            this.grpOption.Controls.Add(this.lblFactory);
            this.grpOption.Controls.Add(this.cdvAreaID);
            this.grpOption.Controls.Add(this.lblArea);
            this.grpOption.Controls.Add(this.cdvType);
            this.grpOption.Controls.Add(this.lblResType);
            this.grpOption.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpOption.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpOption.Location = new System.Drawing.Point(3, 0);
            this.grpOption.Name = "grpOption";
            this.grpOption.Size = new System.Drawing.Size(736, 92);
            this.grpOption.TabIndex = 0;
            this.grpOption.TabStop = false;
            // 
            // chkIncludeDeleteRes
            // 
            this.chkIncludeDeleteRes.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkIncludeDeleteRes.Location = new System.Drawing.Point(526, 67);
            this.chkIncludeDeleteRes.Name = "chkIncludeDeleteRes";
            this.chkIncludeDeleteRes.Size = new System.Drawing.Size(196, 14);
            this.chkIncludeDeleteRes.TabIndex = 4;
            this.chkIncludeDeleteRes.Text = "Include deleted resource";
            this.chkIncludeDeleteRes.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // cdvSubAreaID
            // 
            this.cdvSubAreaID.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvSubAreaID.BorderHotColor = System.Drawing.Color.Black;
            this.cdvSubAreaID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvSubAreaID.BtnToolTipText = "";
            this.cdvSubAreaID.DescText = "";
            this.cdvSubAreaID.DisplaySubItemIndex = -1;
            this.cdvSubAreaID.DisplayText = "";
            this.cdvSubAreaID.Focusing = null;
            this.cdvSubAreaID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvSubAreaID.Index = 0;
            this.cdvSubAreaID.IsViewBtnImage = false;
            this.cdvSubAreaID.Location = new System.Drawing.Point(522, 41);
            this.cdvSubAreaID.MaxLength = 20;
            this.cdvSubAreaID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvSubAreaID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvSubAreaID.Name = "cdvSubAreaID";
            this.cdvSubAreaID.ReadOnly = false;
            this.cdvSubAreaID.SearchSubItemIndex = 0;
            this.cdvSubAreaID.SelectedDescIndex = -1;
            this.cdvSubAreaID.SelectedSubItemIndex = -1;
            this.cdvSubAreaID.SelectionStart = 0;
            this.cdvSubAreaID.Size = new System.Drawing.Size(200, 20);
            this.cdvSubAreaID.SmallImageList = null;
            this.cdvSubAreaID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvSubAreaID.TabIndex = 3;
            this.cdvSubAreaID.TextBoxToolTipText = "";
            this.cdvSubAreaID.TextBoxWidth = 200;
            this.cdvSubAreaID.VisibleButton = true;
            this.cdvSubAreaID.VisibleColumnHeader = false;
            this.cdvSubAreaID.VisibleDescription = false;
            this.cdvSubAreaID.ButtonPress += new System.EventHandler(this.cdvSubAreaID_ButtonPress);
            // 
            // lblSubAreaID
            // 
            this.lblSubAreaID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSubAreaID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSubAreaID.Location = new System.Drawing.Point(418, 44);
            this.lblSubAreaID.Name = "lblSubAreaID";
            this.lblSubAreaID.Size = new System.Drawing.Size(100, 14);
            this.lblSubAreaID.TabIndex = 52;
            this.lblSubAreaID.Text = "Sub Area ID";
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
            this.cdvFactory.Location = new System.Drawing.Point(120, 17);
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
            // cdvAreaID
            // 
            this.cdvAreaID.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvAreaID.BorderHotColor = System.Drawing.Color.Black;
            this.cdvAreaID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvAreaID.BtnToolTipText = "";
            this.cdvAreaID.DescText = "";
            this.cdvAreaID.DisplaySubItemIndex = -1;
            this.cdvAreaID.DisplayText = "";
            this.cdvAreaID.Focusing = null;
            this.cdvAreaID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvAreaID.Index = 0;
            this.cdvAreaID.IsViewBtnImage = false;
            this.cdvAreaID.Location = new System.Drawing.Point(522, 17);
            this.cdvAreaID.MaxLength = 20;
            this.cdvAreaID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvAreaID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvAreaID.Name = "cdvAreaID";
            this.cdvAreaID.ReadOnly = false;
            this.cdvAreaID.SearchSubItemIndex = 0;
            this.cdvAreaID.SelectedDescIndex = -1;
            this.cdvAreaID.SelectedSubItemIndex = -1;
            this.cdvAreaID.SelectionStart = 0;
            this.cdvAreaID.Size = new System.Drawing.Size(200, 20);
            this.cdvAreaID.SmallImageList = null;
            this.cdvAreaID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvAreaID.TabIndex = 2;
            this.cdvAreaID.TextBoxToolTipText = "";
            this.cdvAreaID.TextBoxWidth = 200;
            this.cdvAreaID.VisibleButton = true;
            this.cdvAreaID.VisibleColumnHeader = false;
            this.cdvAreaID.VisibleDescription = false;
            this.cdvAreaID.ButtonPress += new System.EventHandler(this.cdvAreaID_ButtonPress);
            // 
            // lblArea
            // 
            this.lblArea.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblArea.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblArea.Location = new System.Drawing.Point(418, 20);
            this.lblArea.Name = "lblArea";
            this.lblArea.Size = new System.Drawing.Size(100, 14);
            this.lblArea.TabIndex = 2;
            this.lblArea.Text = "Area ID";
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
            this.cdvType.Location = new System.Drawing.Point(120, 41);
            this.cdvType.MaxLength = 20;
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
            this.cdvType.TabIndex = 1;
            this.cdvType.TextBoxToolTipText = "";
            this.cdvType.TextBoxWidth = 200;
            this.cdvType.VisibleButton = true;
            this.cdvType.VisibleColumnHeader = false;
            this.cdvType.VisibleDescription = false;
            this.cdvType.ButtonPress += new System.EventHandler(this.cdvType_ButtonPress);
            // 
            // lblResType
            // 
            this.lblResType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblResType.Location = new System.Drawing.Point(15, 43);
            this.lblResType.Name = "lblResType";
            this.lblResType.Size = new System.Drawing.Size(100, 14);
            this.lblResType.TabIndex = 0;
            this.lblResType.Text = "Resource Type";
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.lisResourceList);
            this.pnlCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenter.Location = new System.Drawing.Point(0, 92);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Padding = new System.Windows.Forms.Padding(3, 5, 3, 0);
            this.pnlCenter.Size = new System.Drawing.Size(742, 414);
            this.pnlCenter.TabIndex = 2;
            // 
            // lisResourceList
            // 
            this.lisResourceList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colSeq,
            this.colRes,
            this.colDesc,
            this.colType,
            this.colProc,
            this.colCtrl,
            this.colUpDown,
            this.colPriSts,
            this.colPrt1,
            this.colPrt2,
            this.colPrt3,
            this.colPrt4,
            this.colPrt5,
            this.colPrt6,
            this.colPrt7,
            this.colPrt8,
            this.colPrt9,
            this.colPrt10,
            this.colSts1,
            this.colSts2,
            this.colSts3,
            this.colSts4,
            this.colSts5,
            this.colSts6,
            this.colSts7,
            this.colSts8,
            this.colSts9,
            this.colSts10,
            this.colUseFac,
            this.colLastEvent,
            this.colLastEventTime,
            this.colLastStartTime,
            this.colLastEndTime,
            this.colProcCount,
            this.colMaxProcCount,
            this.colLastActiveHistSeq,
            this.colLastHistSeq,
            this.colCreateUser,
            this.colCreateTime,
            this.colUpdateUser,
            this.colUpdateTime,
            this.colResTagFlag,
            this.colLayOut,
            this.colLocX,
            this.colLocY,
            this.colWidth,
            this.colHeight,
            this.colText,
            this.colTextSize,
            this.colTextColor,
            this.colTextStyle,
            this.colBackColor});
            this.lisResourceList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisResourceList.EnableSort = true;
            this.lisResourceList.EnableSortIcon = true;
            this.lisResourceList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisResourceList.FullRowSelect = true;
            this.lisResourceList.Location = new System.Drawing.Point(3, 5);
            this.lisResourceList.Name = "lisResourceList";
            this.lisResourceList.Size = new System.Drawing.Size(736, 409);
            this.lisResourceList.TabIndex = 1;
            this.lisResourceList.Tag = "True";
            this.lisResourceList.UseCompatibleStateImageBehavior = false;
            this.lisResourceList.View = System.Windows.Forms.View.Details;
            this.lisResourceList.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.lisResourceList_ColumnClick);
            // 
            // colSeq
            // 
            this.colSeq.Text = "Seq";
            this.colSeq.Width = 50;
            // 
            // colRes
            // 
            this.colRes.Text = "Resource ID";
            this.colRes.Width = 100;
            // 
            // colDesc
            // 
            this.colDesc.Text = "Desc ";
            this.colDesc.Width = 130;
            // 
            // colType
            // 
            this.colType.Text = "Res Type";
            this.colType.Width = 90;
            // 
            // colProc
            // 
            this.colProc.Text = "Proc Mode";
            this.colProc.Width = 100;
            // 
            // colCtrl
            // 
            this.colCtrl.Text = "Control Mode";
            this.colCtrl.Width = 100;
            // 
            // colUpDown
            // 
            this.colUpDown.Text = "Up/Down";
            this.colUpDown.Width = 70;
            // 
            // colPriSts
            // 
            this.colPriSts.Text = "Primary Status";
            this.colPriSts.Width = 120;
            // 
            // colPrt1
            // 
            this.colPrt1.Text = "Status Prompt 1";
            this.colPrt1.Width = 120;
            // 
            // colPrt2
            // 
            this.colPrt2.Text = "Status Prompt 2";
            this.colPrt2.Width = 120;
            // 
            // colPrt3
            // 
            this.colPrt3.Text = "Status Prompt 3";
            this.colPrt3.Width = 120;
            // 
            // colPrt4
            // 
            this.colPrt4.Text = "Status Prompt 4";
            this.colPrt4.Width = 120;
            // 
            // colPrt5
            // 
            this.colPrt5.Text = "Status Prompt 5";
            this.colPrt5.Width = 120;
            // 
            // colPrt6
            // 
            this.colPrt6.Text = "Status Prompt 6";
            this.colPrt6.Width = 120;
            // 
            // colPrt7
            // 
            this.colPrt7.Text = "Status Prompt 7";
            this.colPrt7.Width = 120;
            // 
            // colPrt8
            // 
            this.colPrt8.Text = "Status Prompt 8";
            this.colPrt8.Width = 120;
            // 
            // colPrt9
            // 
            this.colPrt9.Text = "Status Prompt 9";
            this.colPrt9.Width = 120;
            // 
            // colPrt10
            // 
            this.colPrt10.Text = "Status Prompt 10";
            this.colPrt10.Width = 120;
            // 
            // colSts1
            // 
            this.colSts1.Text = "Status 1";
            this.colSts1.Width = 120;
            // 
            // colSts2
            // 
            this.colSts2.Text = "Status 2";
            this.colSts2.Width = 120;
            // 
            // colSts3
            // 
            this.colSts3.Text = "Status 3";
            this.colSts3.Width = 120;
            // 
            // colSts4
            // 
            this.colSts4.Text = "Status 4";
            this.colSts4.Width = 120;
            // 
            // colSts5
            // 
            this.colSts5.Text = "Status 5";
            this.colSts5.Width = 120;
            // 
            // colSts6
            // 
            this.colSts6.Text = "Status 6";
            this.colSts6.Width = 120;
            // 
            // colSts7
            // 
            this.colSts7.Text = "Status 7";
            this.colSts7.Width = 120;
            // 
            // colSts8
            // 
            this.colSts8.Text = "Status 8";
            this.colSts8.Width = 120;
            // 
            // colSts9
            // 
            this.colSts9.Text = "Status 9";
            this.colSts9.Width = 120;
            // 
            // colSts10
            // 
            this.colSts10.Text = "Status 10";
            this.colSts10.Width = 120;
            // 
            // colUseFac
            // 
            this.colUseFac.Text = "Use Fac Prt Flag";
            this.colUseFac.Width = 100;
            // 
            // colLastEvent
            // 
            this.colLastEvent.Text = "Last Event";
            this.colLastEvent.Width = 100;
            // 
            // colLastEventTime
            // 
            this.colLastEventTime.Text = "Last Event Time";
            this.colLastEventTime.Width = 120;
            // 
            // colLastStartTime
            // 
            this.colLastStartTime.Text = "Last Start Time";
            this.colLastStartTime.Width = 120;
            // 
            // colLastEndTime
            // 
            this.colLastEndTime.Text = "Last End Time";
            this.colLastEndTime.Width = 120;
            // 
            // colProcCount
            // 
            this.colProcCount.Text = "Proc Lot Count";
            this.colProcCount.Width = 100;
            // 
            // colMaxProcCount
            // 
            this.colMaxProcCount.Text = "Max Proc Count";
            this.colMaxProcCount.Width = 100;
            // 
            // colLastActiveHistSeq
            // 
            this.colLastActiveHistSeq.Text = "Last Active Hist Seq";
            this.colLastActiveHistSeq.Width = 120;
            // 
            // colLastHistSeq
            // 
            this.colLastHistSeq.Text = "Last Hist Seq";
            this.colLastHistSeq.Width = 100;
            // 
            // colCreateUser
            // 
            this.colCreateUser.Text = "Create User";
            this.colCreateUser.Width = 110;
            // 
            // colCreateTime
            // 
            this.colCreateTime.Text = "Create Time";
            this.colCreateTime.Width = 120;
            // 
            // colUpdateUser
            // 
            this.colUpdateUser.Text = "Update User";
            this.colUpdateUser.Width = 110;
            // 
            // colUpdateTime
            // 
            this.colUpdateTime.Text = "Update Time";
            this.colUpdateTime.Width = 120;
            // 
            // colResTagFlag
            // 
            this.colResTagFlag.Text = "Res Tag Type";
            this.colResTagFlag.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.colResTagFlag.Width = 80;
            // 
            // colLayOut
            // 
            this.colLayOut.Text = "LayOut ID";
            this.colLayOut.Width = 80;
            // 
            // colLocX
            // 
            this.colLocX.Text = "Loc X";
            this.colLocX.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // colLocY
            // 
            this.colLocY.Text = "Loc Y";
            this.colLocY.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // colWidth
            // 
            this.colWidth.Text = "Width";
            this.colWidth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // colHeight
            // 
            this.colHeight.Text = "Height";
            this.colHeight.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // colText
            // 
            this.colText.Text = "Text";
            this.colText.Width = 120;
            // 
            // colTextSize
            // 
            this.colTextSize.Text = "Text Size";
            this.colTextSize.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // colTextColor
            // 
            this.colTextColor.Text = "Text Color";
            this.colTextColor.Width = 120;
            // 
            // colTextStyle
            // 
            this.colTextStyle.Text = "Text Style";
            this.colTextStyle.Width = 100;
            // 
            // colBackColor
            // 
            this.colBackColor.Text = "Back Color";
            this.colBackColor.Width = 120;
            // 
            // frmFMBViewResourceListDetail
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 546);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.pnlMainHeader);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBViewResourceListDetail";
            this.Tag = "FMB3003";
            this.Text = "View Resource List Detail";
            this.Activated += new System.EventHandler(this.frmFMBViewResourceListDetail_Activated);
            this.Load += new System.EventHandler(this.frmFMBViewResourceListDetail_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlMainHeader.ResumeLayout(false);
            this.grpOption.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvSubAreaID)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvAreaID)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvType)).EndInit();
            this.pnlCenter.ResumeLayout(false);
            this.ResumeLayout(false);

        }
        
        #endregion
        
        #region " Variable Definition"
        private bool b_load_flag;
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
                        
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        #endregion
        
        #region " Event Implementations"
        
        private void cdvFactory_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvFactory.Init();
                cdvFactory.Columns.Add("Factory", 100, HorizontalAlignment.Left);
                cdvFactory.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFactory.SelectedSubItemIndex = 0;
                cdvFactory.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1', null);
                cdvFactory.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBViewResourceListDetail_Activated(object sender, System.EventArgs e)
        {
            
            try
            {
                if (b_load_flag == false)
                {
                    b_load_flag = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.frmFMBViewResourceListDetail_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvType_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvType.Init();
                MPCF.InitListView(cdvType.GetListView);
                cdvType.Columns.Add("Type", 50, HorizontalAlignment.Left);
                cdvType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvType.SelectedSubItemIndex = 0;
                cdvType.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (CheckCondition("1") == false)
                {
                    return;
                }
                BASLIST.ViewGCMDataList(cdvType.GetListView, '2', modGlobalConstant.MP_RAS_RES_TYPE, -1, null, cdvFactory.Text, false, -1, -1, null);
                if (cdvType.AddEmptyRow(1) == false)
                {
                    return;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.cdvType_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvAreaID_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvAreaID.Init();
                MPCF.InitListView(cdvAreaID.GetListView);
                cdvAreaID.Columns.Add("AreaID", 50, HorizontalAlignment.Left);
                cdvAreaID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvAreaID.SelectedSubItemIndex = 0;
                cdvAreaID.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (CheckCondition("1") == false)
                {
                    return;
                }
                BASLIST.ViewGCMDataList(cdvAreaID.GetListView, '2', modGlobalConstant.MP_RAS_AREA_CODE,-1,null,cdvFactory.Text );
                if (cdvAreaID.AddEmptyRow(1) == false)
                {
                    return;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.cdvAreaID_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvSubAreaID_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvSubAreaID.Init();
                MPCF.InitListView(cdvSubAreaID.GetListView);
                cdvSubAreaID.Columns.Add("SubAreaID", 50, HorizontalAlignment.Left);
                cdvSubAreaID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvSubAreaID.SelectedSubItemIndex = 0;
                cdvSubAreaID.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (CheckCondition("1") == false)
                {
                    return;
                }
                BASLIST.ViewGCMDataList(cdvSubAreaID.GetListView, '2',  MPGC.MP_RAS_SUBAREA_CODE, -1,null,cdvFactory.Text);
                if (cdvSubAreaID.AddEmptyRow(1) == false)
                {
                    return;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.cdvSubAreaID_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                modListRoutine.ViewResourceListDetail(lisResourceList, cdvType.Text, "", cdvAreaID.Text, cdvSubAreaID.Text, "", chkIncludeDeleteRes.Checked, cdvFactory.Text, false);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.btnView_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                cdvType.Text = "";
                cdvAreaID.Text = "";
                cdvSubAreaID.Text = "";
                lisResourceList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.cdvFactory_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvType.Text = "";
                cdvAreaID.Text = "";
                cdvSubAreaID.Text = "";
                lisResourceList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void lisResourceList_ColumnClick(object sender, System.Windows.Forms.ColumnClickEventArgs e)
        {
            
            try
            {
                if (MPCF.RTrim(lisResourceList.Tag.ToString()) == "True")
                {
                    lisResourceList.Tag = false;
                }
                else
                {
                    lisResourceList.Tag = true;
                }
                
                this.lisResourceList.ListViewItemSorter = new ListViewItemComparer(e.Column, ((bool)lisResourceList.Tag == true ? SortOrder.Descending : SortOrder.Ascending), ListViewItemComparer.SORTING_OPTION.STRING_TYPE);
                lisResourceList.Sort();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.lisResourceList_ColumnClick()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBViewResourceListDetail_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                //MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                FMBCF.CheckAllFactoryOption(cdvFactory);
                MPCF.InitListView(lisResourceList);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewResourceListDetail.frmFMBViewResourceListDetail_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
