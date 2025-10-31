using System.Data;
using System;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;
using System.Drawing;
using Miracom.MsgHandler;
using Miracom.CliFrx;
using Miracom.SECCore;
using Miracom.MESCore;
using Miracom.TRSCore;

//-----------------------------------------------------------------------------
//
//   System      : ADMIN
//   File Name   : frmRunMESarchive.vb
//   Description : ADMIN Run archive and view log sreen Client
//
//   ADMIN Version : 4.0.0
//
//   Function List
//       - CheckCondition() : Check valid date
//       - ViewLogData() : View archive general log data
//       - ViewLogHistoryData() : view archive detail log data

//
//   Detail Description
//       -
//
//    History
//    Seq   Date        Developer      Description
//    ---------------------------------------------------------------------------
//    1     2005/07/28  Andy Yun       Create
//
//
//   Copyright(C) 1998-2005 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------



namespace Admin.ADMCore
{
    public class frmADMViewLogHistory : Miracom.MESCore.ViewForm01
	{
		
		#region " Windows Form 디자이너에서 생성한 코드 "
		
		public frmADMViewLogHistory()
		{
			
			//이 호출은 Windows Form 디자이너에 필요합니다.
			InitializeComponent();
			
			//InitializeComponent()를 호출한 다음에 초기화 작업을 추가하십시오.
			
		}
		
		//Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
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

        //Windows Form 디자이너에 필요합니다.
		
		//참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
		//Windows Form 디자이너를 사용하여 수정할 수 있습니다.
		//코드 편집기를 사용하여 수정하지 마십시오.
		private System.Windows.Forms.Panel pnlInfoLeft;
		private System.Windows.Forms.Panel pnlInfoMid;
		private System.Windows.Forms.Splitter sptInfo;
		private System.Windows.Forms.ImageList imlSPIcons;
		private System.Windows.Forms.ContextMenu ctxLotTrace;
		private System.Windows.Forms.MenuItem mnuPtoC;
		private System.Windows.Forms.MenuItem mnuCtoP;
		private System.Windows.Forms.MenuItem mnuLotStatus;
		private System.Windows.Forms.MenuItem mnuLotHistory;
		private System.Windows.Forms.DateTimePicker dtpFrom;
		private System.Windows.Forms.Label lblPeriod;
		private System.Windows.Forms.DateTimePicker dtpTo;
		private System.Windows.Forms.Label lblTo;
		private FarPoint.Win.Spread.FpSpread spdLogList;
		private FarPoint.Win.Spread.SheetView spdLogList_Sheet1;
		private FarPoint.Win.Spread.FpSpread spdLogHistoryList;
		private FarPoint.Win.Spread.SheetView spdLogHistoryList_Sheet1;
		[System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
		{
            this.components = new System.ComponentModel.Container();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer3 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer4 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer1 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer2 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            this.pnlInfoLeft = new System.Windows.Forms.Panel();
            this.spdLogList = new FarPoint.Win.Spread.FpSpread();
            this.spdLogList_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.pnlInfoMid = new System.Windows.Forms.Panel();
            this.spdLogHistoryList = new FarPoint.Win.Spread.FpSpread();
            this.spdLogHistoryList_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.sptInfo = new System.Windows.Forms.Splitter();
            this.imlSPIcons = new System.Windows.Forms.ImageList(this.components);
            this.ctxLotTrace = new System.Windows.Forms.ContextMenu();
            this.mnuPtoC = new System.Windows.Forms.MenuItem();
            this.mnuCtoP = new System.Windows.Forms.MenuItem();
            this.mnuLotStatus = new System.Windows.Forms.MenuItem();
            this.mnuLotHistory = new System.Windows.Forms.MenuItem();
            this.dtpFrom = new System.Windows.Forms.DateTimePicker();
            this.lblPeriod = new System.Windows.Forms.Label();
            this.dtpTo = new System.Windows.Forms.DateTimePicker();
            this.lblTo = new System.Windows.Forms.Label();
            this.pnlViewTop.SuspendLayout();
            this.grpOption.SuspendLayout();
            this.pnlViewMid.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlInfoLeft.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdLogList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLogList_Sheet1)).BeginInit();
            this.pnlInfoMid.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdLogHistoryList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLogHistoryList_Sheet1)).BeginInit();
            this.SuspendLayout();
            // 
            // btnView
            // 
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // btnExcel
            // 
            this.btnExcel.Click += new System.EventHandler(this.btnExcel_Click);
            // 
            // pnlViewTop
            // 
            this.pnlViewTop.Size = new System.Drawing.Size(742, 42);
            // 
            // grpOption
            // 
            this.grpOption.Controls.Add(this.dtpFrom);
            this.grpOption.Controls.Add(this.lblPeriod);
            this.grpOption.Controls.Add(this.dtpTo);
            this.grpOption.Controls.Add(this.lblTo);
            this.grpOption.Size = new System.Drawing.Size(742, 42);
            // 
            // pnlViewMid
            // 
            this.pnlViewMid.Controls.Add(this.sptInfo);
            this.pnlViewMid.Controls.Add(this.pnlInfoMid);
            this.pnlViewMid.Controls.Add(this.pnlInfoLeft);
            this.pnlViewMid.Location = new System.Drawing.Point(0, 42);
            this.pnlViewMid.Size = new System.Drawing.Size(742, 475);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Location = new System.Drawing.Point(0, 517);
            this.pnlBottom.Size = new System.Drawing.Size(742, 36);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(742, 517);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "View Archive Log";
            // 
            // pnlInfoLeft
            // 
            this.pnlInfoLeft.Controls.Add(this.spdLogList);
            this.pnlInfoLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlInfoLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlInfoLeft.Name = "pnlInfoLeft";
            this.pnlInfoLeft.Size = new System.Drawing.Size(380, 475);
            this.pnlInfoLeft.TabIndex = 0;
            // 
            // spdLogList
            // 
            this.spdLogList.AccessibleDescription = "";
            this.spdLogList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdLogList.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdLogList.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLogList.HorizontalScrollBar.Name = "";
            this.spdLogList.HorizontalScrollBar.Renderer = defaultScrollBarRenderer3;
            this.spdLogList.HorizontalScrollBar.TabIndex = 2;
            this.spdLogList.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdLogList.Location = new System.Drawing.Point(0, 0);
            this.spdLogList.Name = "spdLogList";
            this.spdLogList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdLogList_Sheet1});
            this.spdLogList.Size = new System.Drawing.Size(380, 475);
            this.spdLogList.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdLogList.TabIndex = 0;
            this.spdLogList.TabStop = false;
            this.spdLogList.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLogList.VerticalScrollBar.Name = "";
            this.spdLogList.VerticalScrollBar.Renderer = defaultScrollBarRenderer4;
            this.spdLogList.VerticalScrollBar.TabIndex = 3;
            this.spdLogList.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdLogList.CellClick += new FarPoint.Win.Spread.CellClickEventHandler(this.spdLogList_CellClick);
            // 
            // spdLogList_Sheet1
            // 
            this.spdLogList_Sheet1.Reset();
            this.spdLogList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdLogList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdLogList_Sheet1.ColumnCount = 6;
            this.spdLogList_Sheet1.RowCount = 5;
            this.spdLogList_Sheet1.AlternatingRows.Get(1).BackColor = System.Drawing.Color.WhiteSmoke;
            this.spdLogList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Factory";
            this.spdLogList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Module";
            this.spdLogList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Log ID";
            this.spdLogList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Status Flag";
            this.spdLogList_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "Create Time";
            this.spdLogList_Sheet1.ColumnHeader.Cells.Get(0, 5).Value = "End Time";
            this.spdLogList_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdLogList_Sheet1.ColumnHeader.Rows.Get(0).Height = 18F;
            this.spdLogList_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(0).Label = "Factory";
            this.spdLogList_Sheet1.Columns.Get(0).Width = 72F;
            this.spdLogList_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(1).Label = "Module";
            this.spdLogList_Sheet1.Columns.Get(1).Locked = true;
            this.spdLogList_Sheet1.Columns.Get(1).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Restricted;
            this.spdLogList_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(2).Label = "Log ID";
            this.spdLogList_Sheet1.Columns.Get(2).Locked = true;
            this.spdLogList_Sheet1.Columns.Get(2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(2).Width = 150F;
            this.spdLogList_Sheet1.Columns.Get(3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(3).Label = "Status Flag";
            this.spdLogList_Sheet1.Columns.Get(3).Width = 65F;
            this.spdLogList_Sheet1.Columns.Get(4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(4).Label = "Create Time";
            this.spdLogList_Sheet1.Columns.Get(4).Width = 120F;
            this.spdLogList_Sheet1.Columns.Get(5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogList_Sheet1.Columns.Get(5).Label = "End Time";
            this.spdLogList_Sheet1.Columns.Get(5).Width = 120F;
            this.spdLogList_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdLogList_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.SingleSelect;
            this.spdLogList_Sheet1.RowHeader.Columns.Default.Resizable = true;
            this.spdLogList_Sheet1.RowHeader.Columns.Get(0).Width = 23F;
            this.spdLogList_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdLogList_Sheet1.SelectionPolicy = FarPoint.Win.Spread.Model.SelectionPolicy.Single;
            this.spdLogList_Sheet1.SelectionUnit = FarPoint.Win.Spread.Model.SelectionUnit.Row;
            this.spdLogList_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdLogList_Sheet1.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdLogList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // pnlInfoMid
            // 
            this.pnlInfoMid.Controls.Add(this.spdLogHistoryList);
            this.pnlInfoMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlInfoMid.Location = new System.Drawing.Point(380, 0);
            this.pnlInfoMid.Name = "pnlInfoMid";
            this.pnlInfoMid.Padding = new System.Windows.Forms.Padding(3, 0, 0, 0);
            this.pnlInfoMid.Size = new System.Drawing.Size(362, 475);
            this.pnlInfoMid.TabIndex = 1;
            // 
            // spdLogHistoryList
            // 
            this.spdLogHistoryList.AccessibleDescription = "";
            this.spdLogHistoryList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdLogHistoryList.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdLogHistoryList.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLogHistoryList.HorizontalScrollBar.Name = "";
            this.spdLogHistoryList.HorizontalScrollBar.Renderer = defaultScrollBarRenderer1;
            this.spdLogHistoryList.HorizontalScrollBar.TabIndex = 2;
            this.spdLogHistoryList.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdLogHistoryList.Location = new System.Drawing.Point(3, 0);
            this.spdLogHistoryList.Name = "spdLogHistoryList";
            this.spdLogHistoryList.ScrollBarTrackPolicy = FarPoint.Win.Spread.ScrollBarTrackPolicy.Both;
            this.spdLogHistoryList.ScrollTipPolicy = FarPoint.Win.Spread.ScrollTipPolicy.Both;
            this.spdLogHistoryList.SelectionBlockOptions = ((FarPoint.Win.Spread.SelectionBlockOptions)(((FarPoint.Win.Spread.SelectionBlockOptions.Cells | FarPoint.Win.Spread.SelectionBlockOptions.Rows)
                        | FarPoint.Win.Spread.SelectionBlockOptions.Columns)));
            this.spdLogHistoryList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdLogHistoryList_Sheet1});
            this.spdLogHistoryList.Size = new System.Drawing.Size(359, 475);
            this.spdLogHistoryList.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdLogHistoryList.TabIndex = 0;
            this.spdLogHistoryList.TabStop = false;
            this.spdLogHistoryList.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLogHistoryList.VerticalScrollBar.Name = "";
            this.spdLogHistoryList.VerticalScrollBar.Renderer = defaultScrollBarRenderer2;
            this.spdLogHistoryList.VerticalScrollBar.TabIndex = 3;
            this.spdLogHistoryList.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            // 
            // spdLogHistoryList_Sheet1
            // 
            this.spdLogHistoryList_Sheet1.Reset();
            this.spdLogHistoryList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdLogHistoryList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdLogHistoryList_Sheet1.ColumnCount = 4;
            this.spdLogHistoryList_Sheet1.RowCount = 0;
            this.spdLogHistoryList_Sheet1.RowHeader.ColumnCount = 0;
            this.spdLogHistoryList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Seq";
            this.spdLogHistoryList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Content";
            this.spdLogHistoryList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Log Id";
            this.spdLogHistoryList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Created Time";
            this.spdLogHistoryList_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdLogHistoryList_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogHistoryList_Sheet1.Columns.Get(0).Label = "Seq";
            this.spdLogHistoryList_Sheet1.Columns.Get(0).Width = 43F;
            this.spdLogHistoryList_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdLogHistoryList_Sheet1.Columns.Get(1).Label = "Content";
            this.spdLogHistoryList_Sheet1.Columns.Get(1).Width = 419F;
            this.spdLogHistoryList_Sheet1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogHistoryList_Sheet1.Columns.Get(2).Label = "Log Id";
            this.spdLogHistoryList_Sheet1.Columns.Get(2).Width = 164F;
            this.spdLogHistoryList_Sheet1.Columns.Get(3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLogHistoryList_Sheet1.Columns.Get(3).Label = "Created Time";
            this.spdLogHistoryList_Sheet1.Columns.Get(3).Width = 152F;
            this.spdLogHistoryList_Sheet1.FrozenColumnCount = 1;
            this.spdLogHistoryList_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdLogHistoryList_Sheet1.HorizontalGridLine = new FarPoint.Win.Spread.GridLine(FarPoint.Win.Spread.GridLineType.None);
            this.spdLogHistoryList_Sheet1.RowHeader.Columns.Default.Resizable = true;
            this.spdLogHistoryList_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdLogHistoryList_Sheet1.Rows.Default.Height = 16F;
            this.spdLogHistoryList_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdLogHistoryList_Sheet1.VerticalGridLine = new FarPoint.Win.Spread.GridLine(FarPoint.Win.Spread.GridLineType.None);
            this.spdLogHistoryList_Sheet1.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdLogHistoryList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            this.spdLogHistoryList.SetViewportLeftColumn(0, 0, 1);
            this.spdLogHistoryList.SetActiveViewport(0, 1, -1);
            // 
            // sptInfo
            // 
            this.sptInfo.Location = new System.Drawing.Point(380, 0);
            this.sptInfo.Name = "sptInfo";
            this.sptInfo.Size = new System.Drawing.Size(4, 475);
            this.sptInfo.TabIndex = 0;
            this.sptInfo.TabStop = false;
            // 
            // imlSPIcons
            // 
            this.imlSPIcons.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.imlSPIcons.ImageSize = new System.Drawing.Size(9, 9);
            this.imlSPIcons.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // ctxLotTrace
            // 
            this.ctxLotTrace.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnuPtoC,
            this.mnuCtoP,
            this.mnuLotStatus,
            this.mnuLotHistory});
            // 
            // mnuPtoC
            // 
            this.mnuPtoC.Index = 0;
            this.mnuPtoC.Text = "Parent -> Child";
            // 
            // mnuCtoP
            // 
            this.mnuCtoP.Index = 1;
            this.mnuCtoP.Text = "Child -> Parent";
            // 
            // mnuLotStatus
            // 
            this.mnuLotStatus.Index = 2;
            this.mnuLotStatus.Text = "View Lot Status";
            // 
            // mnuLotHistory
            // 
            this.mnuLotHistory.Index = 3;
            this.mnuLotHistory.Text = "View Lot History";
            // 
            // dtpFrom
            // 
            this.dtpFrom.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpFrom.Location = new System.Drawing.Point(89, 14);
            this.dtpFrom.Name = "dtpFrom";
            this.dtpFrom.Size = new System.Drawing.Size(85, 20);
            this.dtpFrom.TabIndex = 0;
            // 
            // lblPeriod
            // 
            this.lblPeriod.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblPeriod.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPeriod.Location = new System.Drawing.Point(17, 17);
            this.lblPeriod.Name = "lblPeriod";
            this.lblPeriod.Size = new System.Drawing.Size(63, 16);
            this.lblPeriod.TabIndex = 0;
            this.lblPeriod.Text = "Period";
            this.lblPeriod.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // dtpTo
            // 
            this.dtpTo.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpTo.Location = new System.Drawing.Point(196, 14);
            this.dtpTo.Name = "dtpTo";
            this.dtpTo.Size = new System.Drawing.Size(85, 20);
            this.dtpTo.TabIndex = 1;
            // 
            // lblTo
            // 
            this.lblTo.Location = new System.Drawing.Point(177, 22);
            this.lblTo.Name = "lblTo";
            this.lblTo.Size = new System.Drawing.Size(12, 9);
            this.lblTo.TabIndex = 32;
            this.lblTo.Text = "~";
            // 
            // frmADMViewLogHistory
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Name = "frmADMViewLogHistory";
            this.Tag = "ADM3001";
            this.Text = "View Archive Log";
            this.Load += new System.EventHandler(this.frmADMViewLogHistory_Load);
            this.Activated += new System.EventHandler(this.frmADMViewLogHistory_Activated);
            this.pnlViewTop.ResumeLayout(false);
            this.grpOption.ResumeLayout(false);
            this.pnlViewMid.ResumeLayout(false);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlInfoLeft.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdLogList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLogList_Sheet1)).EndInit();
            this.pnlInfoMid.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdLogHistoryList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLogHistoryList_Sheet1)).EndInit();
            this.ResumeLayout(false);

		}
		
		#endregion
		
		#region " Constant Definition "
		
		#endregion
		
		#region " Variable Definition "
		
		private bool bLoadFlag;
		
		#endregion
		
		#region " Function Definition "
		
		
		// ViewLogData()
		//       - View Archive General log information
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       - ByVal sFromTime As String :  From date & time
		//       - ByVal sToTime As String :    To date & time
		
		private bool ViewLogData(string sFromTime, string sToTime)
		{
			int i;
            int iLastRow;

            TRSNode in_node = new TRSNode("VIEW_LOG_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_LOG_LIST_OUT");

            try
            {
                MPCF.ClearList(spdLogList);
                MPCF.ClearList(spdLogHistoryList);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("FROM_TRAN_TIME", sFromTime.Trim());
                in_node.AddString("TO_TRAN_TIME", sToTime.Trim());
                in_node.AddString("LOG", "");

                do
                {
                    if (MPCR.CallService("ADM", "ADM_View_Log_List", in_node, ref out_node) == false)
                    {
                    	return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {

                        iLastRow = spdLogList.Sheets[0].RowCount;
                        spdLogList.Sheets[0].RowCount = spdLogList.Sheets[0].RowCount + 1;
                        FarPoint.Win.Spread.SheetView with_1 = spdLogList.Sheets[0];
                        with_1.SetValue(iLastRow, 0, MPCF.Trim(out_node.GetList(0)[i].GetString("FACTORY")));
                        with_1.SetValue(iLastRow, 1, MPCF.Trim(out_node.GetList(0)[i].GetString("MODULE_NAME")));
                        with_1.SetValue(iLastRow, 2, MPCF.Trim(out_node.GetList(0)[i].GetString("LOG")));
                        with_1.SetValue(iLastRow, 3, MPCF.Trim(out_node.GetList(0)[i].GetChar("STATUS_FLAG")));
                        with_1.SetValue(iLastRow, 4, MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("CREATE_TIME")));
                        with_1.SetValue(iLastRow, 5, MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("END_TIME")));
                    }

                    in_node.SetString("LOG", out_node.GetString("NEXT_LOG"));
                } while (!(in_node.GetString("LOG") == ""));

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
		
		}
		
		// ViewLogHistoryData()
		//       - View Archive log's detail history information
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       - ByVal sLog As String :  Log ID
		
		private bool ViewLogHistoryData(string sLog)
		{
			int i;
            int iLastRow;

            TRSNode in_node = new TRSNode("VIEW_LOG_HISTORY_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_LOG_HISTORY_LIST_OUT");

            try
            {
                MPCF.ClearList(spdLogHistoryList);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOG", sLog);
                in_node.AddInt("SEQ_NUM", 0);

                do
                {
                    if (MPCR.CallService("ADM", "ADM_View_Log_History_List", in_node, ref out_node) == false)
                    {
                    	return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        iLastRow = spdLogHistoryList.Sheets[0].RowCount;
                        spdLogHistoryList.Sheets[0].RowCount = spdLogHistoryList.Sheets[0].RowCount + 1;
                        FarPoint.Win.Spread.SheetView with_1 = spdLogHistoryList.Sheets[0];
                        with_1.SetValue(iLastRow, 0, MPCF.Trim(out_node.GetList(0)[i].GetInt("SEQ_NUM")));
                        with_1.SetValue(iLastRow, 1, MPCF.Trim(out_node.GetList(0)[i].GetString("CONTENT")));
                        with_1.SetValue(iLastRow, 2, MPCF.Trim(out_node.GetList(0)[i].GetString("LOG")));
                        with_1.SetValue(iLastRow, 3, MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("CREATE_TIME")));
                    }
                    in_node.SetString("LOG", out_node.GetString("NEXT_LOG"));
                    in_node.SetInt("SEQ_NUM", out_node.GetInt("NEXT_SEQ_NUM"));
                } while (!(in_node.GetString("LOG") == ""));

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }		
		}
		
		// CheckCondition()
		//       - Check the date condition before transaction
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       - ByVal FuncName As String : Function Name
		
		private bool CheckCondition(string FuncName)
		{
			
			switch (FuncName.TrimEnd())
			{
				case "VIEW":
					
					if (dtpFrom.Value > dtpTo.Value)
					{
                        MPCF.ShowMsgBox(MPCF.GetMessage(120));
						return false;
					}
					break;
					
			}
			
			return true;
			
		}
		
		#endregion
		
		
		private void frmADMViewLogHistory_Load(object sender, System.EventArgs e)
		{
			try
			{
                MPCF.ToClientLanguage(this);
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
		}
		
		private void frmADMViewLogHistory_Activated(object sender, System.EventArgs e)
		{
			
			if (bLoadFlag == false)
			{
				MPCF.FieldClear(this);
                MPCF.ClearList(spdLogList);
                MPCF.ClearList(spdLogHistoryList);
				dtpFrom.Value = DateTime.Today;
				dtpTo.Value = DateTime.Today;
                //btnView.Focus();
				bLoadFlag = true;
			}
			
		}
		
		private void btnView_Click(System.Object sender, System.EventArgs e)
		{
			string sFromTime;
			string sToTime;
			
			if (CheckCondition("VIEW") == false)
			{
				return;
			}

            sFromTime = dtpFrom.Value.ToString("yyyyMMdd") + "000000";
            sToTime = dtpTo.Value.ToString("yyyyMMdd") + "235959";
			
			if (ViewLogData(sFromTime, sToTime) == false)
			{
				return;
			}
			
		}
		
		private void btnExcel_Click(System.Object sender, System.EventArgs e)
		{
			string sCond;
			
			sCond = "View Log history";

            if (MPCF.ExportToExcel(spdLogHistoryList, this.Text, sCond) == false)
			{
				return;
			}
			
		}
		
		private void spdLogList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
		{
			string sLog;
			
			if (spdLogList.Sheets[0].Cells[e.Row, 2].Text != "")
			{
				
				sLog = spdLogList.Sheets[0].Cells[e.Row, 2].Text;
				
				if (ViewLogHistoryData(sLog) == false)
				{
					return;
				}
				
			}
		}
		
		
	}
}
