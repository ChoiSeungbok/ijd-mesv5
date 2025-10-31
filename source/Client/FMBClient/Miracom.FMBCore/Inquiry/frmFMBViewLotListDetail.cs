
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
//   File Name   : frmFMBViewLotListDetail.vb
//   Description : View Lot List Detail
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
    public class frmFMBViewLotListDetail : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBViewLotListDetail()
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
        internal System.Windows.Forms.Panel pnlCenter;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvOperation;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvFlow;
        internal System.Windows.Forms.Label lblOperation;
        internal System.Windows.Forms.Label lblFlow;
        internal Infragistics.Win.UltraWinEditors.UltraCheckEditor chkZeroQtyLot;
        internal Infragistics.Win.UltraWinEditors.UltraCheckEditor chkTerminatedLot;
        internal Miracom.UI.Controls.MCListView.MCListView lisLotList;
        internal System.Windows.Forms.ColumnHeader ColLotId;
        internal System.Windows.Forms.ColumnHeader ColStatus;
        internal System.Windows.Forms.ColumnHeader ColQty1;
        internal System.Windows.Forms.ColumnHeader ColQty2;
        internal System.Windows.Forms.ColumnHeader ColQty3;
        internal System.Windows.Forms.ColumnHeader ColLotType;
        internal System.Windows.Forms.ColumnHeader ColPriority;
        internal System.Windows.Forms.ColumnHeader ColCreate;
        internal System.Windows.Forms.ColumnHeader ColOwner;
        internal System.Windows.Forms.ColumnHeader ColHoldCode;
        internal System.Windows.Forms.ColumnHeader colSeq;
        internal System.Windows.Forms.ColumnHeader ColMat;
        internal System.Windows.Forms.ColumnHeader ColFlow;
        internal System.Windows.Forms.ColumnHeader ColOper;
        internal System.Windows.Forms.ColumnHeader ColHoldFlag;
        internal System.Windows.Forms.ColumnHeader ColCreateQty1;
        internal System.Windows.Forms.ColumnHeader ColCreateQty2;
        internal System.Windows.Forms.ColumnHeader ColCreateQty3;
        internal System.Windows.Forms.ColumnHeader ColOperQty1;
        internal System.Windows.Forms.ColumnHeader ColOperQty2;
        internal System.Windows.Forms.ColumnHeader ColOperQty3;
        internal System.Windows.Forms.ColumnHeader ColInvFlg;
        internal System.Windows.Forms.ColumnHeader ColTransit;
        internal System.Windows.Forms.ColumnHeader ColUnit;
        internal System.Windows.Forms.ColumnHeader ColInv;
        internal System.Windows.Forms.ColumnHeader ColReworkFlag;
        internal System.Windows.Forms.ColumnHeader ColReworkCode;
        internal System.Windows.Forms.ColumnHeader ColReworkCount;
        internal System.Windows.Forms.ColumnHeader ColReworkReturnFlow;
        internal System.Windows.Forms.ColumnHeader ColReworkReturnOper;
        internal System.Windows.Forms.ColumnHeader ColRewokEndFlow;
        internal System.Windows.Forms.ColumnHeader ColReworkEndOper;
        internal System.Windows.Forms.ColumnHeader ColClearFlag;
        internal System.Windows.Forms.ColumnHeader ColStart;
        internal System.Windows.Forms.ColumnHeader ColStartTime;
        internal System.Windows.Forms.ColumnHeader ColStartRes;
        internal System.Windows.Forms.ColumnHeader ColEnd;
        internal System.Windows.Forms.ColumnHeader ColEndTime;
        internal System.Windows.Forms.ColumnHeader ColEndResID;
        internal System.Windows.Forms.ColumnHeader ColSample;
        internal System.Windows.Forms.ColumnHeader ColSampleWait;
        internal System.Windows.Forms.ColumnHeader ColSampleResult;
        internal System.Windows.Forms.ColumnHeader ColSplitLot;
        internal System.Windows.Forms.ColumnHeader ColShipCode;
        internal System.Windows.Forms.ColumnHeader ColShipTime;
        internal System.Windows.Forms.ColumnHeader ColDue;
        internal System.Windows.Forms.ColumnHeader ColScheduled;
        internal System.Windows.Forms.ColumnHeader ColCreateTime;
        internal System.Windows.Forms.ColumnHeader ColFactoryInTime;
        internal System.Windows.Forms.ColumnHeader ColFlowTime;
        internal System.Windows.Forms.ColumnHeader ColOperIntime;
        internal System.Windows.Forms.ColumnHeader ColReserve;
        internal System.Windows.Forms.ColumnHeader ColBatchID;
        internal System.Windows.Forms.ColumnHeader ColBatchSeq;
        internal System.Windows.Forms.ColumnHeader ColOrder;
        internal System.Windows.Forms.ColumnHeader ColLocation;
        internal System.Windows.Forms.ColumnHeader ColCMF1;
        internal System.Windows.Forms.ColumnHeader ColCMF2;
        internal System.Windows.Forms.ColumnHeader ColCMF3;
        internal System.Windows.Forms.ColumnHeader ColCMF4;
        internal System.Windows.Forms.ColumnHeader ColCMF5;
        internal System.Windows.Forms.ColumnHeader ColCMF6;
        internal System.Windows.Forms.ColumnHeader ColCMF7;
        internal System.Windows.Forms.ColumnHeader ColCMF8;
        internal System.Windows.Forms.ColumnHeader ColCMF9;
        internal System.Windows.Forms.ColumnHeader ColCMF10;
        internal System.Windows.Forms.ColumnHeader ColDelFlag;
        internal System.Windows.Forms.ColumnHeader ColReason;
        internal System.Windows.Forms.ColumnHeader ColDelTime;
        internal System.Windows.Forms.ColumnHeader ColTranCode;
        internal System.Windows.Forms.ColumnHeader ColTranTime;
        internal System.Windows.Forms.ColumnHeader ColComment;
        internal System.Windows.Forms.ColumnHeader ColLastActive;
        internal System.Windows.Forms.ColumnHeader ColLastSeq;
        internal System.Windows.Forms.ColumnHeader ColNstdFlag;
        internal System.Windows.Forms.ColumnHeader ColNstdReturnFlow;
        internal System.Windows.Forms.ColumnHeader ColNstdReturnOper;
        private Miracom.MESCore.Controls.udcMaterial cdvMaterial;
        internal System.Windows.Forms.ColumnHeader ColNstdTime;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnView = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.pnlMainHeader = new System.Windows.Forms.Panel();
            this.grpOption = new System.Windows.Forms.GroupBox();
            this.cdvMaterial = new Miracom.MESCore.Controls.udcMaterial();
            this.chkTerminatedLot = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.chkZeroQtyLot = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.cdvOperation = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvFlow = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblOperation = new System.Windows.Forms.Label();
            this.lblFlow = new System.Windows.Forms.Label();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.lisLotList = new Miracom.UI.Controls.MCListView.MCListView();
            this.colSeq = new System.Windows.Forms.ColumnHeader();
            this.ColLotId = new System.Windows.Forms.ColumnHeader();
            this.ColMat = new System.Windows.Forms.ColumnHeader();
            this.ColFlow = new System.Windows.Forms.ColumnHeader();
            this.ColOper = new System.Windows.Forms.ColumnHeader();
            this.ColQty1 = new System.Windows.Forms.ColumnHeader();
            this.ColQty2 = new System.Windows.Forms.ColumnHeader();
            this.ColQty3 = new System.Windows.Forms.ColumnHeader();
            this.ColLotType = new System.Windows.Forms.ColumnHeader();
            this.ColOwner = new System.Windows.Forms.ColumnHeader();
            this.ColCreate = new System.Windows.Forms.ColumnHeader();
            this.ColPriority = new System.Windows.Forms.ColumnHeader();
            this.ColStatus = new System.Windows.Forms.ColumnHeader();
            this.ColHoldFlag = new System.Windows.Forms.ColumnHeader();
            this.ColHoldCode = new System.Windows.Forms.ColumnHeader();
            this.ColCreateQty1 = new System.Windows.Forms.ColumnHeader();
            this.ColCreateQty2 = new System.Windows.Forms.ColumnHeader();
            this.ColCreateQty3 = new System.Windows.Forms.ColumnHeader();
            this.ColOperQty1 = new System.Windows.Forms.ColumnHeader();
            this.ColOperQty2 = new System.Windows.Forms.ColumnHeader();
            this.ColOperQty3 = new System.Windows.Forms.ColumnHeader();
            this.ColInvFlg = new System.Windows.Forms.ColumnHeader();
            this.ColTransit = new System.Windows.Forms.ColumnHeader();
            this.ColUnit = new System.Windows.Forms.ColumnHeader();
            this.ColInv = new System.Windows.Forms.ColumnHeader();
            this.ColReworkFlag = new System.Windows.Forms.ColumnHeader();
            this.ColReworkCode = new System.Windows.Forms.ColumnHeader();
            this.ColReworkCount = new System.Windows.Forms.ColumnHeader();
            this.ColReworkReturnFlow = new System.Windows.Forms.ColumnHeader();
            this.ColReworkReturnOper = new System.Windows.Forms.ColumnHeader();
            this.ColRewokEndFlow = new System.Windows.Forms.ColumnHeader();
            this.ColReworkEndOper = new System.Windows.Forms.ColumnHeader();
            this.ColClearFlag = new System.Windows.Forms.ColumnHeader();
            this.ColNstdFlag = new System.Windows.Forms.ColumnHeader();
            this.ColNstdReturnFlow = new System.Windows.Forms.ColumnHeader();
            this.ColNstdReturnOper = new System.Windows.Forms.ColumnHeader();
            this.ColNstdTime = new System.Windows.Forms.ColumnHeader();
            this.ColStart = new System.Windows.Forms.ColumnHeader();
            this.ColStartTime = new System.Windows.Forms.ColumnHeader();
            this.ColStartRes = new System.Windows.Forms.ColumnHeader();
            this.ColEnd = new System.Windows.Forms.ColumnHeader();
            this.ColEndTime = new System.Windows.Forms.ColumnHeader();
            this.ColEndResID = new System.Windows.Forms.ColumnHeader();
            this.ColSample = new System.Windows.Forms.ColumnHeader();
            this.ColSampleWait = new System.Windows.Forms.ColumnHeader();
            this.ColSampleResult = new System.Windows.Forms.ColumnHeader();
            this.ColSplitLot = new System.Windows.Forms.ColumnHeader();
            this.ColShipCode = new System.Windows.Forms.ColumnHeader();
            this.ColShipTime = new System.Windows.Forms.ColumnHeader();
            this.ColDue = new System.Windows.Forms.ColumnHeader();
            this.ColScheduled = new System.Windows.Forms.ColumnHeader();
            this.ColCreateTime = new System.Windows.Forms.ColumnHeader();
            this.ColFactoryInTime = new System.Windows.Forms.ColumnHeader();
            this.ColFlowTime = new System.Windows.Forms.ColumnHeader();
            this.ColOperIntime = new System.Windows.Forms.ColumnHeader();
            this.ColReserve = new System.Windows.Forms.ColumnHeader();
            this.ColBatchID = new System.Windows.Forms.ColumnHeader();
            this.ColBatchSeq = new System.Windows.Forms.ColumnHeader();
            this.ColOrder = new System.Windows.Forms.ColumnHeader();
            this.ColLocation = new System.Windows.Forms.ColumnHeader();
            this.ColCMF1 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF2 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF3 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF4 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF5 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF6 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF7 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF8 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF9 = new System.Windows.Forms.ColumnHeader();
            this.ColCMF10 = new System.Windows.Forms.ColumnHeader();
            this.ColDelFlag = new System.Windows.Forms.ColumnHeader();
            this.ColReason = new System.Windows.Forms.ColumnHeader();
            this.ColDelTime = new System.Windows.Forms.ColumnHeader();
            this.ColTranCode = new System.Windows.Forms.ColumnHeader();
            this.ColTranTime = new System.Windows.Forms.ColumnHeader();
            this.ColComment = new System.Windows.Forms.ColumnHeader();
            this.ColLastActive = new System.Windows.Forms.ColumnHeader();
            this.ColLastSeq = new System.Windows.Forms.ColumnHeader();
            this.pnlBottom.SuspendLayout();
            this.pnlMainHeader.SuspendLayout();
            this.grpOption.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOperation)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFlow)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
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
            this.btnView.TabIndex = 2;
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
            this.btnClose.TabIndex = 3;
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
            this.grpOption.Controls.Add(this.cdvMaterial);
            this.grpOption.Controls.Add(this.chkTerminatedLot);
            this.grpOption.Controls.Add(this.chkZeroQtyLot);
            this.grpOption.Controls.Add(this.cdvOperation);
            this.grpOption.Controls.Add(this.cdvFlow);
            this.grpOption.Controls.Add(this.lblOperation);
            this.grpOption.Controls.Add(this.lblFlow);
            this.grpOption.Controls.Add(this.cdvFactory);
            this.grpOption.Controls.Add(this.lblFactory);
            this.grpOption.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpOption.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpOption.Location = new System.Drawing.Point(3, 0);
            this.grpOption.Name = "grpOption";
            this.grpOption.Size = new System.Drawing.Size(736, 92);
            this.grpOption.TabIndex = 0;
            this.grpOption.TabStop = false;
            // 
            // cdvMaterial
            // 
            this.cdvMaterial.AddEmptyRowToLast = false;
            this.cdvMaterial.AddEmptyRowToTop = false;
            this.cdvMaterial.CodeViewBackColor = System.Drawing.SystemColors.Window;
            this.cdvMaterial.DisplaySubItemIndex = 0;
            this.cdvMaterial.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvMaterial.LabelBackColor = System.Drawing.SystemColors.Control;
            this.cdvMaterial.LabelFont = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvMaterial.LabelText = "Material";
            this.cdvMaterial.ListCond_ExtFactory = "";
            this.cdvMaterial.ListCond_StepMaterial = '1';
            this.cdvMaterial.ListCond_StepVersion = '1';
            this.cdvMaterial.Location = new System.Drawing.Point(15, 41);
            this.cdvMaterial.MaterialEnabled = true;
            this.cdvMaterial.MaterialReadOnly = false;
            this.cdvMaterial.Name = "cdvMaterial";
            this.cdvMaterial.SearchSubItemIndex = 0;
            this.cdvMaterial.SelectedDescIndex = -1;
            this.cdvMaterial.SelectedSubItemIndex = 0;
            this.cdvMaterial.Size = new System.Drawing.Size(305, 21);
            this.cdvMaterial.TabIndex = 57;
            this.cdvMaterial.VersionEnabled = true;
            this.cdvMaterial.VersionReadOnly = false;
            this.cdvMaterial.VisibleColumnHeader = false;
            this.cdvMaterial.VisibleDescription = false;
            this.cdvMaterial.VisibleMaterialButton = true;
            this.cdvMaterial.VisibleVersionButton = true;
            this.cdvMaterial.WidthButton = 21;
            this.cdvMaterial.WidthLabel = 105;
            this.cdvMaterial.WidthMaterialAndVersion = 200;
            this.cdvMaterial.WidthVersion = 50;
            // 
            // chkTerminatedLot
            // 
            this.chkTerminatedLot.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkTerminatedLot.Location = new System.Drawing.Point(526, 63);
            this.chkTerminatedLot.Name = "chkTerminatedLot";
            this.chkTerminatedLot.Size = new System.Drawing.Size(196, 14);
            this.chkTerminatedLot.TabIndex = 5;
            this.chkTerminatedLot.Text = "Include Terminated Lot";
            this.chkTerminatedLot.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // chkZeroQtyLot
            // 
            this.chkZeroQtyLot.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkZeroQtyLot.Location = new System.Drawing.Point(526, 42);
            this.chkZeroQtyLot.Name = "chkZeroQtyLot";
            this.chkZeroQtyLot.Size = new System.Drawing.Size(196, 14);
            this.chkZeroQtyLot.TabIndex = 4;
            this.chkZeroQtyLot.Text = "Zero Quantity Lot";
            this.chkZeroQtyLot.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // cdvOperation
            // 
            this.cdvOperation.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvOperation.BorderHotColor = System.Drawing.Color.Black;
            this.cdvOperation.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvOperation.BtnToolTipText = "";
            this.cdvOperation.DescText = "";
            this.cdvOperation.DisplaySubItemIndex = -1;
            this.cdvOperation.DisplayText = "";
            this.cdvOperation.Focusing = null;
            this.cdvOperation.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvOperation.Index = 0;
            this.cdvOperation.IsViewBtnImage = false;
            this.cdvOperation.Location = new System.Drawing.Point(530, 17);
            this.cdvOperation.MaxLength = 10;
            this.cdvOperation.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOperation.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvOperation.Name = "cdvOperation";
            this.cdvOperation.ReadOnly = false;
            this.cdvOperation.SearchSubItemIndex = 0;
            this.cdvOperation.SelectedDescIndex = -1;
            this.cdvOperation.SelectedSubItemIndex = -1;
            this.cdvOperation.SelectionStart = 0;
            this.cdvOperation.Size = new System.Drawing.Size(192, 20);
            this.cdvOperation.SmallImageList = null;
            this.cdvOperation.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvOperation.TabIndex = 1;
            this.cdvOperation.TextBoxToolTipText = "";
            this.cdvOperation.TextBoxWidth = 192;
            this.cdvOperation.VisibleButton = true;
            this.cdvOperation.VisibleColumnHeader = false;
            this.cdvOperation.VisibleDescription = false;
            this.cdvOperation.TextBoxTextChanged += new System.EventHandler(this.cdvOperation_TextBoxTextChanged);
            this.cdvOperation.ButtonPress += new System.EventHandler(this.cdvOperation_ButtonPress);
            this.cdvOperation.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvOperation_SelectedItemChanged);
            // 
            // cdvFlow
            // 
            this.cdvFlow.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvFlow.BorderHotColor = System.Drawing.Color.Black;
            this.cdvFlow.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvFlow.BtnToolTipText = "";
            this.cdvFlow.DescText = "";
            this.cdvFlow.DisplaySubItemIndex = -1;
            this.cdvFlow.DisplayText = "";
            this.cdvFlow.Focusing = null;
            this.cdvFlow.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvFlow.Index = 0;
            this.cdvFlow.IsViewBtnImage = false;
            this.cdvFlow.Location = new System.Drawing.Point(120, 65);
            this.cdvFlow.MaxLength = 20;
            this.cdvFlow.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFlow.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFlow.Name = "cdvFlow";
            this.cdvFlow.ReadOnly = false;
            this.cdvFlow.SearchSubItemIndex = 0;
            this.cdvFlow.SelectedDescIndex = -1;
            this.cdvFlow.SelectedSubItemIndex = -1;
            this.cdvFlow.SelectionStart = 0;
            this.cdvFlow.Size = new System.Drawing.Size(200, 20);
            this.cdvFlow.SmallImageList = null;
            this.cdvFlow.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvFlow.TabIndex = 3;
            this.cdvFlow.TextBoxToolTipText = "";
            this.cdvFlow.TextBoxWidth = 200;
            this.cdvFlow.VisibleButton = true;
            this.cdvFlow.VisibleColumnHeader = false;
            this.cdvFlow.VisibleDescription = false;
            this.cdvFlow.TextBoxTextChanged += new System.EventHandler(this.cdvFlow_TextBoxTextChanged);
            this.cdvFlow.ButtonPress += new System.EventHandler(this.cdvFlow_ButtonPress);
            this.cdvFlow.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvFlow_SelectedItemChanged);
            // 
            // lblOperation
            // 
            this.lblOperation.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblOperation.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOperation.Location = new System.Drawing.Point(426, 20);
            this.lblOperation.Name = "lblOperation";
            this.lblOperation.Size = new System.Drawing.Size(100, 14);
            this.lblOperation.TabIndex = 56;
            this.lblOperation.Text = "Operation";
            this.lblOperation.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblFlow
            // 
            this.lblFlow.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFlow.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFlow.Location = new System.Drawing.Point(15, 68);
            this.lblFlow.Name = "lblFlow";
            this.lblFlow.Size = new System.Drawing.Size(100, 14);
            this.lblFlow.TabIndex = 54;
            this.lblFlow.Text = "Flow";
            this.lblFlow.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
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
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.lisLotList);
            this.pnlCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenter.Location = new System.Drawing.Point(0, 92);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Padding = new System.Windows.Forms.Padding(3, 5, 3, 0);
            this.pnlCenter.Size = new System.Drawing.Size(742, 414);
            this.pnlCenter.TabIndex = 2;
            // 
            // lisLotList
            // 
            this.lisLotList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colSeq,
            this.ColLotId,
            this.ColMat,
            this.ColFlow,
            this.ColOper,
            this.ColQty1,
            this.ColQty2,
            this.ColQty3,
            this.ColLotType,
            this.ColOwner,
            this.ColCreate,
            this.ColPriority,
            this.ColStatus,
            this.ColHoldFlag,
            this.ColHoldCode,
            this.ColCreateQty1,
            this.ColCreateQty2,
            this.ColCreateQty3,
            this.ColOperQty1,
            this.ColOperQty2,
            this.ColOperQty3,
            this.ColInvFlg,
            this.ColTransit,
            this.ColUnit,
            this.ColInv,
            this.ColReworkFlag,
            this.ColReworkCode,
            this.ColReworkCount,
            this.ColReworkReturnFlow,
            this.ColReworkReturnOper,
            this.ColRewokEndFlow,
            this.ColReworkEndOper,
            this.ColClearFlag,
            this.ColNstdFlag,
            this.ColNstdReturnFlow,
            this.ColNstdReturnOper,
            this.ColNstdTime,
            this.ColStart,
            this.ColStartTime,
            this.ColStartRes,
            this.ColEnd,
            this.ColEndTime,
            this.ColEndResID,
            this.ColSample,
            this.ColSampleWait,
            this.ColSampleResult,
            this.ColSplitLot,
            this.ColShipCode,
            this.ColShipTime,
            this.ColDue,
            this.ColScheduled,
            this.ColCreateTime,
            this.ColFactoryInTime,
            this.ColFlowTime,
            this.ColOperIntime,
            this.ColReserve,
            this.ColBatchID,
            this.ColBatchSeq,
            this.ColOrder,
            this.ColLocation,
            this.ColCMF1,
            this.ColCMF2,
            this.ColCMF3,
            this.ColCMF4,
            this.ColCMF5,
            this.ColCMF6,
            this.ColCMF7,
            this.ColCMF8,
            this.ColCMF9,
            this.ColCMF10,
            this.ColDelFlag,
            this.ColReason,
            this.ColDelTime,
            this.ColTranCode,
            this.ColTranTime,
            this.ColComment,
            this.ColLastActive,
            this.ColLastSeq});
            this.lisLotList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisLotList.EnableSort = true;
            this.lisLotList.EnableSortIcon = true;
            this.lisLotList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisLotList.FullRowSelect = true;
            this.lisLotList.Location = new System.Drawing.Point(3, 5);
            this.lisLotList.Name = "lisLotList";
            this.lisLotList.Size = new System.Drawing.Size(736, 409);
            this.lisLotList.TabIndex = 1;
            this.lisLotList.Tag = "True";
            this.lisLotList.UseCompatibleStateImageBehavior = false;
            this.lisLotList.View = System.Windows.Forms.View.Details;
            this.lisLotList.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.lisLotList_ColumnClick);
            // 
            // colSeq
            // 
            this.colSeq.Text = "Seq";
            this.colSeq.Width = 40;
            // 
            // ColLotId
            // 
            this.ColLotId.Text = "Lot ID";
            this.ColLotId.Width = 100;
            // 
            // ColMat
            // 
            this.ColMat.Text = "Material";
            this.ColMat.Width = 100;
            // 
            // ColFlow
            // 
            this.ColFlow.Text = "Flow";
            this.ColFlow.Width = 80;
            // 
            // ColOper
            // 
            this.ColOper.Text = "Operation";
            // 
            // ColQty1
            // 
            this.ColQty1.Text = "Qty1";
            this.ColQty1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColQty1.Width = 80;
            // 
            // ColQty2
            // 
            this.ColQty2.Text = "Qty2";
            this.ColQty2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColQty2.Width = 80;
            // 
            // ColQty3
            // 
            this.ColQty3.Text = "Qty3";
            this.ColQty3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColQty3.Width = 80;
            // 
            // ColLotType
            // 
            this.ColLotType.Text = "Lot Type";
            // 
            // ColOwner
            // 
            this.ColOwner.Text = "Owner Code";
            this.ColOwner.Width = 90;
            // 
            // ColCreate
            // 
            this.ColCreate.Text = "Create Code";
            this.ColCreate.Width = 90;
            // 
            // ColPriority
            // 
            this.ColPriority.Text = "Lot Priority";
            this.ColPriority.Width = 80;
            // 
            // ColStatus
            // 
            this.ColStatus.Text = "Lot Status";
            this.ColStatus.Width = 70;
            // 
            // ColHoldFlag
            // 
            this.ColHoldFlag.Text = "Hold Flag";
            // 
            // ColHoldCode
            // 
            this.ColHoldCode.Text = "Hold Code";
            this.ColHoldCode.Width = 90;
            // 
            // ColCreateQty1
            // 
            this.ColCreateQty1.Text = "Create Qty1";
            this.ColCreateQty1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColCreateQty1.Width = 80;
            // 
            // ColCreateQty2
            // 
            this.ColCreateQty2.Text = "Create Qty2";
            this.ColCreateQty2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColCreateQty2.Width = 80;
            // 
            // ColCreateQty3
            // 
            this.ColCreateQty3.Text = "Create Qty3";
            this.ColCreateQty3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColCreateQty3.Width = 80;
            // 
            // ColOperQty1
            // 
            this.ColOperQty1.Text = "Oper In Qty1";
            this.ColOperQty1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColOperQty1.Width = 80;
            // 
            // ColOperQty2
            // 
            this.ColOperQty2.Text = "Oper In Qty2";
            this.ColOperQty2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColOperQty2.Width = 80;
            // 
            // ColOperQty3
            // 
            this.ColOperQty3.Text = "Oper In Qty3";
            this.ColOperQty3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColOperQty3.Width = 80;
            // 
            // ColInvFlg
            // 
            this.ColInvFlg.Text = "Inventory Flag";
            this.ColInvFlg.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ColInvFlg.Width = 80;
            // 
            // ColTransit
            // 
            this.ColTransit.Text = "Transit Flag";
            this.ColTransit.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ColTransit.Width = 80;
            // 
            // ColUnit
            // 
            this.ColUnit.Text = "Unit Exist Flag";
            this.ColUnit.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ColUnit.Width = 90;
            // 
            // ColInv
            // 
            this.ColInv.Text = "Inv Unit";
            // 
            // ColReworkFlag
            // 
            this.ColReworkFlag.Text = "Rework Flag";
            this.ColReworkFlag.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ColReworkFlag.Width = 80;
            // 
            // ColReworkCode
            // 
            this.ColReworkCode.Text = "Rework Code";
            this.ColReworkCode.Width = 90;
            // 
            // ColReworkCount
            // 
            this.ColReworkCount.Text = "Rework Count";
            this.ColReworkCount.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColReworkCount.Width = 100;
            // 
            // ColReworkReturnFlow
            // 
            this.ColReworkReturnFlow.Text = "Rework Return Flow";
            this.ColReworkReturnFlow.Width = 110;
            // 
            // ColReworkReturnOper
            // 
            this.ColReworkReturnOper.Text = "Rework Return Oper";
            this.ColReworkReturnOper.Width = 110;
            // 
            // ColRewokEndFlow
            // 
            this.ColRewokEndFlow.Text = "Rework End Flow";
            this.ColRewokEndFlow.Width = 100;
            // 
            // ColReworkEndOper
            // 
            this.ColReworkEndOper.Text = "Rework End Oper";
            this.ColReworkEndOper.Width = 100;
            // 
            // ColClearFlag
            // 
            this.ColClearFlag.Text = "Rework Return Clear Flag";
            this.ColClearFlag.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ColClearFlag.Width = 140;
            // 
            // ColNstdFlag
            // 
            this.ColNstdFlag.Text = "NSTD Flag";
            this.ColNstdFlag.Width = 80;
            // 
            // ColNstdReturnFlow
            // 
            this.ColNstdReturnFlow.Text = "NSTD Return Flow";
            this.ColNstdReturnFlow.Width = 120;
            // 
            // ColNstdReturnOper
            // 
            this.ColNstdReturnOper.Text = "NSTD Return Oper";
            this.ColNstdReturnOper.Width = 120;
            // 
            // ColNstdTime
            // 
            this.ColNstdTime.Text = "NSTD Time";
            this.ColNstdTime.Width = 120;
            // 
            // ColStart
            // 
            this.ColStart.Text = "Start Flag";
            this.ColStart.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // ColStartTime
            // 
            this.ColStartTime.Text = "Start Time";
            this.ColStartTime.Width = 120;
            // 
            // ColStartRes
            // 
            this.ColStartRes.Text = "Start Resource ID";
            this.ColStartRes.Width = 100;
            // 
            // ColEnd
            // 
            this.ColEnd.Text = "End Flag";
            // 
            // ColEndTime
            // 
            this.ColEndTime.Text = "End Time";
            this.ColEndTime.Width = 120;
            // 
            // ColEndResID
            // 
            this.ColEndResID.Text = "End Resource ID";
            this.ColEndResID.Width = 100;
            // 
            // ColSample
            // 
            this.ColSample.Text = "Sample Flag";
            this.ColSample.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ColSample.Width = 80;
            // 
            // ColSampleWait
            // 
            this.ColSampleWait.Text = "Sample Wait Flag";
            this.ColSampleWait.Width = 100;
            // 
            // ColSampleResult
            // 
            this.ColSampleResult.Text = "Sample Result";
            this.ColSampleResult.Width = 80;
            // 
            // ColSplitLot
            // 
            this.ColSplitLot.Text = "Split From Lot ID";
            this.ColSplitLot.Width = 100;
            // 
            // ColShipCode
            // 
            this.ColShipCode.Text = "Ship Code";
            this.ColShipCode.Width = 90;
            // 
            // ColShipTime
            // 
            this.ColShipTime.Text = "Ship Time";
            this.ColShipTime.Width = 120;
            // 
            // ColDue
            // 
            this.ColDue.Text = "Original Due Time";
            this.ColDue.Width = 120;
            // 
            // ColScheduled
            // 
            this.ColScheduled.Text = "Scheduled Due Time";
            this.ColScheduled.Width = 120;
            // 
            // ColCreateTime
            // 
            this.ColCreateTime.Text = "Create Time";
            this.ColCreateTime.Width = 120;
            // 
            // ColFactoryInTime
            // 
            this.ColFactoryInTime.Text = "Factory In Time";
            this.ColFactoryInTime.Width = 120;
            // 
            // ColFlowTime
            // 
            this.ColFlowTime.Text = "Flow In Time";
            this.ColFlowTime.Width = 120;
            // 
            // ColOperIntime
            // 
            this.ColOperIntime.Text = "Oper In Time";
            this.ColOperIntime.Width = 120;
            // 
            // ColReserve
            // 
            this.ColReserve.Text = "Reserve Resource ID";
            this.ColReserve.Width = 120;
            // 
            // ColBatchID
            // 
            this.ColBatchID.Text = "Batch ID ";
            this.ColBatchID.Width = 100;
            // 
            // ColBatchSeq
            // 
            this.ColBatchSeq.Text = "Batch Seq";
            this.ColBatchSeq.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColBatchSeq.Width = 70;
            // 
            // ColOrder
            // 
            this.ColOrder.Text = "Order ID";
            this.ColOrder.Width = 100;
            // 
            // ColLocation
            // 
            this.ColLocation.Text = "Lot Location";
            this.ColLocation.Width = 100;
            // 
            // ColCMF1
            // 
            this.ColCMF1.Text = "Lot CMF 1";
            this.ColCMF1.Width = 100;
            // 
            // ColCMF2
            // 
            this.ColCMF2.Text = "Lot CMF 2";
            this.ColCMF2.Width = 100;
            // 
            // ColCMF3
            // 
            this.ColCMF3.Text = "Lot CMF 3";
            this.ColCMF3.Width = 100;
            // 
            // ColCMF4
            // 
            this.ColCMF4.Text = "Lot CMF 4";
            this.ColCMF4.Width = 100;
            // 
            // ColCMF5
            // 
            this.ColCMF5.Text = "Lot CMF 5";
            this.ColCMF5.Width = 100;
            // 
            // ColCMF6
            // 
            this.ColCMF6.Text = "Lot CMF 6";
            this.ColCMF6.Width = 100;
            // 
            // ColCMF7
            // 
            this.ColCMF7.Text = "Lot CMF 7";
            this.ColCMF7.Width = 100;
            // 
            // ColCMF8
            // 
            this.ColCMF8.Text = "Lot CMF 8";
            this.ColCMF8.Width = 100;
            // 
            // ColCMF9
            // 
            this.ColCMF9.Text = "Lot CMF 9";
            this.ColCMF9.Width = 100;
            // 
            // ColCMF10
            // 
            this.ColCMF10.Text = "Lot CMF 10";
            this.ColCMF10.Width = 100;
            // 
            // ColDelFlag
            // 
            this.ColDelFlag.Text = "Lot Delete Flag";
            this.ColDelFlag.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.ColDelFlag.Width = 90;
            // 
            // ColReason
            // 
            this.ColReason.Text = "Lot Delete Reason";
            this.ColReason.Width = 120;
            // 
            // ColDelTime
            // 
            this.ColDelTime.Text = "Lot Delete Time";
            this.ColDelTime.Width = 120;
            // 
            // ColTranCode
            // 
            this.ColTranCode.Text = "Last Tran Code";
            this.ColTranCode.Width = 90;
            // 
            // ColTranTime
            // 
            this.ColTranTime.Text = "Last Tran Time";
            this.ColTranTime.Width = 120;
            // 
            // ColComment
            // 
            this.ColComment.Text = "Last Comment";
            this.ColComment.Width = 150;
            // 
            // ColLastActive
            // 
            this.ColLastActive.Text = "Last Active Hist Seq";
            this.ColLastActive.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColLastActive.Width = 110;
            // 
            // ColLastSeq
            // 
            this.ColLastSeq.Text = "Last Hist Seq";
            this.ColLastSeq.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.ColLastSeq.Width = 80;
            // 
            // frmFMBViewLotListDetail
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 546);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.pnlMainHeader);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBViewLotListDetail";
            this.Tag = "FMB3004";
            this.Text = "View Lot List Detail";
            this.Activated += new System.EventHandler(this.frmFMBViewLotListDetail_Activated);
            this.Load += new System.EventHandler(this.frmFMBViewLotListDetail_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlMainHeader.ResumeLayout(false);
            this.grpOption.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvOperation)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFlow)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
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
                    case "2":
                        
                        if (cdvFactory.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        if (cdvOperation.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvOperation.Focus();
                            return false;
                        }
                        break;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1',null);
                cdvFactory.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFlow_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvFlow.Init();
                MPCF.InitListView(cdvFlow.GetListView);
                cdvFlow.Columns.Add("Flow", 50, HorizontalAlignment.Left);
                cdvFlow.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFlow.SelectedSubItemIndex = 0;
                cdvFlow.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (CheckCondition("1") == false)
                {
                    return;
                }
                if (cdvMaterial.Text == "")
                {
                    WIPLIST.ViewFlowList(cdvFlow.GetListView, '1',"",0,"",null, cdvFactory.Text);
                }
                else
                {
                    WIPLIST.ViewFlowList(cdvFlow.GetListView, '3', cdvMaterial.Text, cdvMaterial.Version,"",null, cdvFactory.Text);
                }
                cdvFlow.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvFlow_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvOperation_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvOperation.Init();
                MPCF.InitListView(cdvOperation.GetListView);
                cdvOperation.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOperation.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOperation.SelectedSubItemIndex = 0;
                cdvOperation.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (CheckCondition("1") == false)
                {
                    return;
                }
                if (cdvMaterial.Text != "" && cdvFlow.Text != "")
                {
                    WIPLIST.ViewOperationList(cdvOperation.GetListView, '4',  cdvMaterial.Text,cdvMaterial.Version, cdvFlow.Text, "",null,cdvFactory.Text);
                }
                else
                {
                    if (cdvFlow.Text == "")
                    {
                        if (cdvMaterial.Text == "")
                        {
                            WIPLIST.ViewOperationList(cdvOperation.GetListView, '1',"", 0, "", "", null, cdvFactory.Text);
                        }
                        else
                        {
                            WIPLIST.ViewOperationList(cdvOperation.GetListView, '3', cdvMaterial.Text, cdvMaterial.Version, "", "", null, cdvFactory.Text);
                        }
                    }
                    else
                    {
                        WIPLIST.ViewOperationList(cdvOperation.GetListView, '2', "", 0, cdvFlow.Text, "", null, cdvFactory.Text);
                    }
                }
                cdvOperation.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvOperation_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvMaterial_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvMaterial_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFlow_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvFlow_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                cdvMaterial.Text = "";
                cdvFlow.Text = "";
                cdvOperation.Text = "";
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvFactory_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBViewLotListDetail_Activated(object sender, System.EventArgs e)
        {
            
            try
            {
                if (b_load_flag == false)
                {
                    MPCF.InitListView(lisLotList);
                    b_load_flag = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.frmFMBViewLotListDetail_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnView_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("2") == false)
                {
                    return;
                }
                modListRoutine.ViewLotListDetail(lisLotList, "1", cdvFactory.Text, cdvMaterial.Text,cdvMaterial.Version, cdvFlow.Text, cdvOperation.Text, chkZeroQtyLot.Checked, chkTerminatedLot.Checked);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.btnView_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvMaterial_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvMaterial_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFlow_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvFlow_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvMaterial.Text = "";
                cdvFlow.Text = "";
                cdvOperation.Text = "";
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvOperation_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvOperation_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvOperation_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.cdvOperation_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void lisLotList_ColumnClick(object sender, System.Windows.Forms.ColumnClickEventArgs e)
        {
            
            try
            {
                if (MPCF.RTrim(lisLotList.Tag.ToString()) == "True")
                {
                    lisLotList.Tag = false;
                }
                else
                {
                    lisLotList.Tag = true;
                }

                this.lisLotList.ListViewItemSorter = new ListViewItemComparer(e.Column, ((bool)lisLotList.Tag == true ? SortOrder.Descending : SortOrder.Ascending), ListViewItemComparer.SORTING_OPTION.STRING_TYPE);
                lisLotList.Sort();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.lisLotList_ColumnClick()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBViewLotListDetail_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                
                FMBCF.CheckAllFactoryOption(cdvFactory);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.frmFMBViewLotListDetail_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
