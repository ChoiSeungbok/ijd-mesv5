using System.Data;
using System;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;
using System.Drawing;
using Miracom.MsgHandler;
using Miracom.CliFrx;
using FarPoint.Win.Spread;
using Miracom.SECCore;
using Miracom.UTLCore;
using Miracom.TRSCore;
using Miracom.MESCore;

//-----------------------------------------------------------------------------
//
//   System      : ADMIN
//   File Name   : frmADMTaskManager.vb
//   Description : Monitoring process ID, database connection, disk space and table space
//
//   ADMIN Version : 4.0.0
//
//   Function List
//       - View_Status() : View Disk space, process list, DB connection and table space
//       - ViewTableSpaceList() : View table space list
//       - ViewDiskSpaceList() : View Disk Space List
//       - ViewProcessList() : View Server Process List
//       - CheckDBConnect() : Check Database connection
//       - CheckProcess() : Publish Check Message to Server Process
//       - LoadServerList() : Get Server List to Check from MGCMTBLDAT (Table name="SERVER_LIST", Factory="SYSTEM")
//
//   Detail Description
//       -
//
//    History
//    Seq   Date        Developer      Description
//    ---------------------------------------------------------------------------
//    1     2005/08/09  Andy Yun       Modified
//
//
//   Copyright(C) 1998-2005 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------


namespace Admin.ADMCore
{
    public class frmADMTaskManager : Miracom.CliFrx.BaseForm04
    {
		
		
		#region " Windows Form 디자이너에서 생성한 코드 "
		
		public frmADMTaskManager()
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
		private System.Windows.Forms.Panel pnlCenterTop;
		private System.Windows.Forms.Splitter splCenterCenter;
		private System.Windows.Forms.Panel pnlCenterBottom;
		private System.Windows.Forms.Panel pnlCenterBottomLeft;
		private System.Windows.Forms.Splitter splCenterBottom;
		private System.Windows.Forms.Panel pnlCenterBottomRight;
		private System.Windows.Forms.CheckBox chkAutoRefresh;
		private FarPoint.Win.Spread.FpSpread spdTableSpace;
		private FarPoint.Win.Spread.SheetView spdTableSpace_Sheet1;
		private FarPoint.Win.Spread.FpSpread spdProcess;
		private FarPoint.Win.Spread.SheetView spdProcess_Sheet1;
		private System.Windows.Forms.Timer tmrRefresh;
		private System.Windows.Forms.Timer tmrProcess;
		private System.Windows.Forms.ImageList imlSPIcons;
		private System.Windows.Forms.Button btnExpand;
		private System.Windows.Forms.Button btnCollapse;
		private System.Windows.Forms.Panel pnlDBConnected;
		private System.Windows.Forms.Panel pnlDiskSpace;
		private System.Windows.Forms.GroupBox gpbDBConnected;
		private System.Windows.Forms.Button btnReConnect;
		private System.Windows.Forms.Label lblDBConnected;
        private FarPoint.Win.Spread.FpSpread spdDiskSpace;
        private Button btnProcess;
        private CheckBox chkCollapse;
        private ComboBox cboLogLevel;
        private Button btnChgEnv;
        private Button btnPoolInit;
        private System.Windows.Forms.Timer tmrProcessStatus;
        private Panel pnlSessionCnt;
        private GroupBox grpSessionCnt;
        private TextBox txtSessionCnt;
        private TextBox txtIPAddress;
        private Label lblSessionCnt;
        private Label lblIPAddress;
        private Panel pnlDBConnectTop;
		private FarPoint.Win.Spread.SheetView spdDiskSpace_Sheet1;
		[System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
		{
            this.components = new System.ComponentModel.Container();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer3 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer3 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer1 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer1 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer2 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer2 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer4 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer4 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer3 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle5 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle6 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle7 = new FarPoint.Win.Spread.NamedStyle("CornerDefault");
            FarPoint.Win.Spread.CellType.CornerRenderer cornerRenderer2 = new FarPoint.Win.Spread.CellType.CornerRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle8 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType2 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer4 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer7 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle13 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle14 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle15 = new FarPoint.Win.Spread.NamedStyle("CornerDefault");
            FarPoint.Win.Spread.CellType.CornerRenderer cornerRenderer4 = new FarPoint.Win.Spread.CellType.CornerRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle16 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType4 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer8 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.CellType.ProgressCellType progressCellType5 = new FarPoint.Win.Spread.CellType.ProgressCellType();
            FarPoint.Win.Spread.CellType.PercentCellType percentCellType3 = new FarPoint.Win.Spread.CellType.PercentCellType();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer5 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle9 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle10 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle11 = new FarPoint.Win.Spread.NamedStyle("CornerDefault");
            FarPoint.Win.Spread.CellType.CornerRenderer cornerRenderer3 = new FarPoint.Win.Spread.CellType.CornerRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle12 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType3 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer6 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.CellType.ProgressCellType progressCellType6 = new FarPoint.Win.Spread.CellType.ProgressCellType();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmADMTaskManager));
            this.pnlCenterTop = new System.Windows.Forms.Panel();
            this.spdProcess = new FarPoint.Win.Spread.FpSpread();
            this.spdProcess_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.splCenterCenter = new System.Windows.Forms.Splitter();
            this.pnlCenterBottom = new System.Windows.Forms.Panel();
            this.pnlCenterBottomRight = new System.Windows.Forms.Panel();
            this.spdTableSpace = new FarPoint.Win.Spread.FpSpread();
            this.spdTableSpace_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.splCenterBottom = new System.Windows.Forms.Splitter();
            this.pnlCenterBottomLeft = new System.Windows.Forms.Panel();
            this.pnlDiskSpace = new System.Windows.Forms.Panel();
            this.spdDiskSpace = new FarPoint.Win.Spread.FpSpread();
            this.spdDiskSpace_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.pnlDBConnected = new System.Windows.Forms.Panel();
            this.gpbDBConnected = new System.Windows.Forms.GroupBox();
            this.btnReConnect = new System.Windows.Forms.Button();
            this.lblDBConnected = new System.Windows.Forms.Label();
            this.chkAutoRefresh = new System.Windows.Forms.CheckBox();
            this.tmrRefresh = new System.Windows.Forms.Timer(this.components);
            this.tmrProcess = new System.Windows.Forms.Timer(this.components);
            this.imlSPIcons = new System.Windows.Forms.ImageList(this.components);
            this.btnExpand = new System.Windows.Forms.Button();
            this.btnCollapse = new System.Windows.Forms.Button();
            this.btnProcess = new System.Windows.Forms.Button();
            this.chkCollapse = new System.Windows.Forms.CheckBox();
            this.btnChgEnv = new System.Windows.Forms.Button();
            this.cboLogLevel = new System.Windows.Forms.ComboBox();
            this.btnPoolInit = new System.Windows.Forms.Button();
            this.tmrProcessStatus = new System.Windows.Forms.Timer(this.components);
            this.pnlDBConnectTop = new System.Windows.Forms.Panel();
            this.pnlSessionCnt = new System.Windows.Forms.Panel();
            this.grpSessionCnt = new System.Windows.Forms.GroupBox();
            this.lblIPAddress = new System.Windows.Forms.Label();
            this.lblSessionCnt = new System.Windows.Forms.Label();
            this.txtIPAddress = new System.Windows.Forms.TextBox();
            this.txtSessionCnt = new System.Windows.Forms.TextBox();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlCenterTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdProcess)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdProcess_Sheet1)).BeginInit();
            this.pnlCenterBottom.SuspendLayout();
            this.pnlCenterBottomRight.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdTableSpace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdTableSpace_Sheet1)).BeginInit();
            this.pnlCenterBottomLeft.SuspendLayout();
            this.pnlDiskSpace.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdDiskSpace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdDiskSpace_Sheet1)).BeginInit();
            this.pnlDBConnected.SuspendLayout();
            this.gpbDBConnected.SuspendLayout();
            this.pnlDBConnectTop.SuspendLayout();
            this.pnlSessionCnt.SuspendLayout();
            this.grpSessionCnt.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnClose
            // 
            this.btnClose.TabIndex = 8;
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnPoolInit);
            this.pnlBottom.Controls.Add(this.cboLogLevel);
            this.pnlBottom.Controls.Add(this.btnChgEnv);
            this.pnlBottom.Controls.Add(this.btnProcess);
            this.pnlBottom.Controls.Add(this.btnExpand);
            this.pnlBottom.Controls.Add(this.btnCollapse);
            this.pnlBottom.Controls.Add(this.chkAutoRefresh);
            this.pnlBottom.Controls.Add(this.chkCollapse);
            this.pnlBottom.Location = new System.Drawing.Point(0, 513);
            this.pnlBottom.Padding = new System.Windows.Forms.Padding(0, 0, 5, 0);
            this.pnlBottom.TabIndex = 0;
            this.pnlBottom.Controls.SetChildIndex(this.chkCollapse, 0);
            this.pnlBottom.Controls.SetChildIndex(this.chkAutoRefresh, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnCollapse, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnExpand, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnProcess, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnChgEnv, 0);
            this.pnlBottom.Controls.SetChildIndex(this.cboLogLevel, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnPoolInit, 0);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.pnlCenterBottom);
            this.pnlCenter.Controls.Add(this.splCenterCenter);
            this.pnlCenter.Controls.Add(this.pnlCenterTop);
            this.pnlCenter.Size = new System.Drawing.Size(742, 513);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "Task Manager";
            columnHeaderRenderer3.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer3.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer3.Name = "columnHeaderRenderer3";
            columnHeaderRenderer3.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer3.TextRotationAngle = 0D;
            rowHeaderRenderer3.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer3.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer3.Name = "rowHeaderRenderer3";
            rowHeaderRenderer3.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer3.TextRotationAngle = 0D;
            columnHeaderRenderer1.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer1.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer1.Name = "columnHeaderRenderer1";
            columnHeaderRenderer1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer1.TextRotationAngle = 0D;
            rowHeaderRenderer1.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer1.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer1.Name = "rowHeaderRenderer1";
            rowHeaderRenderer1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer1.TextRotationAngle = 0D;
            columnHeaderRenderer2.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer2.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer2.Name = "columnHeaderRenderer2";
            columnHeaderRenderer2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer2.TextRotationAngle = 0D;
            rowHeaderRenderer2.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer2.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer2.Name = "rowHeaderRenderer2";
            rowHeaderRenderer2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer2.TextRotationAngle = 0D;
            columnHeaderRenderer4.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer4.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer4.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer4.Name = "columnHeaderRenderer4";
            columnHeaderRenderer4.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer4.TextRotationAngle = 0D;
            rowHeaderRenderer4.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer4.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer4.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer4.Name = "rowHeaderRenderer4";
            rowHeaderRenderer4.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer4.TextRotationAngle = 0D;
            // 
            // pnlCenterTop
            // 
            this.pnlCenterTop.Controls.Add(this.spdProcess);
            this.pnlCenterTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlCenterTop.Location = new System.Drawing.Point(0, 0);
            this.pnlCenterTop.Name = "pnlCenterTop";
            this.pnlCenterTop.Size = new System.Drawing.Size(742, 246);
            this.pnlCenterTop.TabIndex = 0;
            // 
            // spdProcess
            // 
            this.spdProcess.AccessibleDescription = "spdProcess, Sheet1, Row 0, Column 0, ";
            this.spdProcess.BackColor = System.Drawing.SystemColors.Control;
            this.spdProcess.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdProcess.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdProcess.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdProcess.HorizontalScrollBar.Name = "";
            this.spdProcess.HorizontalScrollBar.Renderer = defaultScrollBarRenderer3;
            this.spdProcess.HorizontalScrollBar.TabIndex = 4;
            this.spdProcess.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdProcess.Location = new System.Drawing.Point(0, 0);
            this.spdProcess.Name = "spdProcess";
            namedStyle5.BackColor = System.Drawing.SystemColors.Control;
            namedStyle5.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle5.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle5.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle5.Renderer = columnHeaderRenderer3;
            namedStyle5.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle6.BackColor = System.Drawing.SystemColors.Control;
            namedStyle6.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle6.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle6.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle6.Renderer = rowHeaderRenderer3;
            namedStyle6.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle7.BackColor = System.Drawing.SystemColors.Control;
            namedStyle7.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle7.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle7.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle7.Renderer = cornerRenderer2;
            namedStyle7.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle8.BackColor = System.Drawing.SystemColors.Window;
            namedStyle8.CellType = generalCellType2;
            namedStyle8.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle8.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle8.Renderer = generalCellType2;
            this.spdProcess.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle5,
            namedStyle6,
            namedStyle7,
            namedStyle8});
            this.spdProcess.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.spdProcess.ScrollBarTrackPolicy = FarPoint.Win.Spread.ScrollBarTrackPolicy.Both;
            this.spdProcess.ScrollTipPolicy = FarPoint.Win.Spread.ScrollTipPolicy.Both;
            this.spdProcess.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdProcess_Sheet1});
            this.spdProcess.Size = new System.Drawing.Size(742, 246);
            this.spdProcess.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdProcess.TabIndex = 0;
            this.spdProcess.TabStop = false;
            this.spdProcess.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdProcess.VerticalScrollBar.Name = "";
            this.spdProcess.VerticalScrollBar.Renderer = defaultScrollBarRenderer4;
            this.spdProcess.VerticalScrollBar.TabIndex = 5;
            this.spdProcess.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdProcess.CellClick += new FarPoint.Win.Spread.CellClickEventHandler(this.spdProcess_CellClick);
            this.spdProcess.SetViewportLeftColumn(0, 0, 3);
            this.spdProcess.SetActiveViewport(0, 0, -1);
            // 
            // spdProcess_Sheet1
            // 
            this.spdProcess_Sheet1.Reset();
            spdProcess_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdProcess_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            spdProcess_Sheet1.ColumnCount = 5;
            spdProcess_Sheet1.RowCount = 5;
            spdProcess_Sheet1.RowHeader.ColumnCount = 0;
            this.spdProcess_Sheet1.AlternatingRows.Get(1).BackColor = System.Drawing.Color.White;
            this.spdProcess_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdProcess_Sheet1.ColumnFooter.DefaultStyle.Parent = "HeaderDefault";
            this.spdProcess_Sheet1.ColumnFooterSheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdProcess_Sheet1.ColumnFooterSheetCornerStyle.Parent = "CornerDefault";
            this.spdProcess_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "_";
            this.spdProcess_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Server Name";
            this.spdProcess_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Total Count";
            this.spdProcess_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Running Count";
            this.spdProcess_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "Init Shared Pool";
            this.spdProcess_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdProcess_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdProcess_Sheet1.ColumnHeader.Rows.Get(0).Height = 18F;
            this.spdProcess_Sheet1.Columns.Get(0).BackColor = System.Drawing.Color.Gainsboro;
            this.spdProcess_Sheet1.Columns.Get(0).Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdProcess_Sheet1.Columns.Get(0).ForeColor = System.Drawing.Color.Black;
            this.spdProcess_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdProcess_Sheet1.Columns.Get(0).Label = "_";
            this.spdProcess_Sheet1.Columns.Get(0).Locked = true;
            this.spdProcess_Sheet1.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdProcess_Sheet1.Columns.Get(0).Width = 23F;
            this.spdProcess_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdProcess_Sheet1.Columns.Get(1).Label = "Server Name";
            this.spdProcess_Sheet1.Columns.Get(1).Locked = true;
            this.spdProcess_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdProcess_Sheet1.Columns.Get(1).Width = 170F;
            this.spdProcess_Sheet1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdProcess_Sheet1.Columns.Get(2).Label = "Total Count";
            this.spdProcess_Sheet1.Columns.Get(2).Locked = true;
            this.spdProcess_Sheet1.Columns.Get(2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdProcess_Sheet1.Columns.Get(2).Width = 303F;
            this.spdProcess_Sheet1.Columns.Get(3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdProcess_Sheet1.Columns.Get(3).Label = "Running Count";
            this.spdProcess_Sheet1.Columns.Get(3).Locked = true;
            this.spdProcess_Sheet1.Columns.Get(3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdProcess_Sheet1.Columns.Get(3).Width = 130F;
            this.spdProcess_Sheet1.Columns.Get(4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdProcess_Sheet1.Columns.Get(4).Label = "Init Shared Pool";
            this.spdProcess_Sheet1.Columns.Get(4).Locked = true;
            this.spdProcess_Sheet1.Columns.Get(4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdProcess_Sheet1.Columns.Get(4).Width = 90F;
            this.spdProcess_Sheet1.FrozenColumnCount = 3;
            this.spdProcess_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdProcess_Sheet1.HorizontalGridLine = new FarPoint.Win.Spread.GridLine(FarPoint.Win.Spread.GridLineType.None);
            this.spdProcess_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.SingleSelect;
            this.spdProcess_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdProcess_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdProcess_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdProcess_Sheet1.SelectionPolicy = FarPoint.Win.Spread.Model.SelectionPolicy.Single;
            this.spdProcess_Sheet1.SelectionUnit = FarPoint.Win.Spread.Model.SelectionUnit.Row;
            this.spdProcess_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdProcess_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdProcess_Sheet1.VerticalGridLine = new FarPoint.Win.Spread.GridLine(FarPoint.Win.Spread.GridLineType.None);
            this.spdProcess_Sheet1.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdProcess_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // splCenterCenter
            // 
            this.splCenterCenter.Dock = System.Windows.Forms.DockStyle.Top;
            this.splCenterCenter.Location = new System.Drawing.Point(0, 246);
            this.splCenterCenter.Name = "splCenterCenter";
            this.splCenterCenter.Size = new System.Drawing.Size(742, 4);
            this.splCenterCenter.TabIndex = 0;
            this.splCenterCenter.TabStop = false;
            // 
            // pnlCenterBottom
            // 
            this.pnlCenterBottom.Controls.Add(this.pnlCenterBottomRight);
            this.pnlCenterBottom.Controls.Add(this.splCenterBottom);
            this.pnlCenterBottom.Controls.Add(this.pnlCenterBottomLeft);
            this.pnlCenterBottom.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenterBottom.Location = new System.Drawing.Point(0, 250);
            this.pnlCenterBottom.Name = "pnlCenterBottom";
            this.pnlCenterBottom.Size = new System.Drawing.Size(742, 263);
            this.pnlCenterBottom.TabIndex = 0;
            // 
            // pnlCenterBottomRight
            // 
            this.pnlCenterBottomRight.Controls.Add(this.spdTableSpace);
            this.pnlCenterBottomRight.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenterBottomRight.Location = new System.Drawing.Point(364, 0);
            this.pnlCenterBottomRight.Name = "pnlCenterBottomRight";
            this.pnlCenterBottomRight.Size = new System.Drawing.Size(378, 263);
            this.pnlCenterBottomRight.TabIndex = 0;
            // 
            // spdTableSpace
            // 
            this.spdTableSpace.AccessibleDescription = "spdTableSpace, Sheet1, Row 0, Column 0, ";
            this.spdTableSpace.BackColor = System.Drawing.SystemColors.Control;
            this.spdTableSpace.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdTableSpace.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdTableSpace.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdTableSpace.HorizontalScrollBar.Name = "";
            this.spdTableSpace.HorizontalScrollBar.Renderer = defaultScrollBarRenderer7;
            this.spdTableSpace.HorizontalScrollBar.TabIndex = 2;
            this.spdTableSpace.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdTableSpace.Location = new System.Drawing.Point(0, 0);
            this.spdTableSpace.Name = "spdTableSpace";
            namedStyle13.BackColor = System.Drawing.SystemColors.Control;
            namedStyle13.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle13.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle13.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle13.Renderer = columnHeaderRenderer1;
            namedStyle13.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle14.BackColor = System.Drawing.SystemColors.Control;
            namedStyle14.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle14.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle14.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle14.Renderer = rowHeaderRenderer1;
            namedStyle14.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle15.BackColor = System.Drawing.SystemColors.Control;
            namedStyle15.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle15.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle15.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle15.Renderer = cornerRenderer4;
            namedStyle15.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle16.BackColor = System.Drawing.SystemColors.Window;
            namedStyle16.CellType = generalCellType4;
            namedStyle16.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle16.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle16.Renderer = generalCellType4;
            this.spdTableSpace.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle13,
            namedStyle14,
            namedStyle15,
            namedStyle16});
            this.spdTableSpace.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.spdTableSpace.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdTableSpace_Sheet1});
            this.spdTableSpace.Size = new System.Drawing.Size(378, 263);
            this.spdTableSpace.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdTableSpace.TabIndex = 0;
            this.spdTableSpace.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdTableSpace.VerticalScrollBar.Name = "";
            this.spdTableSpace.VerticalScrollBar.Renderer = defaultScrollBarRenderer8;
            this.spdTableSpace.VerticalScrollBar.TabIndex = 3;
            this.spdTableSpace.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdTableSpace.SetViewportLeftColumn(0, 0, 1);
            this.spdTableSpace.SetActiveViewport(0, 0, -1);
            // 
            // spdTableSpace_Sheet1
            // 
            this.spdTableSpace_Sheet1.Reset();
            spdTableSpace_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdTableSpace_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            spdTableSpace_Sheet1.ColumnCount = 9;
            spdTableSpace_Sheet1.RowCount = 2;
            this.spdTableSpace_Sheet1.AlternatingRows.Get(1).BackColor = System.Drawing.Color.WhiteSmoke;
            this.spdTableSpace_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdTableSpace_Sheet1.ColumnFooter.DefaultStyle.Parent = "HeaderDefault";
            this.spdTableSpace_Sheet1.ColumnFooterSheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdTableSpace_Sheet1.ColumnFooterSheetCornerStyle.Parent = "CornerDefault";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Table Space";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Total Space";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Used Space";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Used Rate";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "Used Rate";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 5).Value = "File Name";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 5).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 6).Value = "Status";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 7).Value = "Auto Extensible";
            this.spdTableSpace_Sheet1.ColumnHeader.Cells.Get(0, 8).Value = "Increment by";
            this.spdTableSpace_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdTableSpace_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdTableSpace_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdTableSpace_Sheet1.Columns.Get(0).Label = "Table Space";
            this.spdTableSpace_Sheet1.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.Columns.Get(0).Width = 100F;
            this.spdTableSpace_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdTableSpace_Sheet1.Columns.Get(1).Label = "Total Space";
            this.spdTableSpace_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.Columns.Get(1).Width = 110F;
            this.spdTableSpace_Sheet1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdTableSpace_Sheet1.Columns.Get(2).Label = "Used Space";
            this.spdTableSpace_Sheet1.Columns.Get(2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.Columns.Get(2).Width = 110F;
            progressCellType5.ShowText = false;
            this.spdTableSpace_Sheet1.Columns.Get(3).CellType = progressCellType5;
            this.spdTableSpace_Sheet1.Columns.Get(3).Label = "Used Rate";
            this.spdTableSpace_Sheet1.Columns.Get(3).Width = 114F;
            percentCellType3.DecimalPlaces = 2;
            percentCellType3.FixedPoint = true;
            percentCellType3.MaximumValue = 100D;
            percentCellType3.MinimumValue = 0D;
            this.spdTableSpace_Sheet1.Columns.Get(4).CellType = percentCellType3;
            this.spdTableSpace_Sheet1.Columns.Get(4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdTableSpace_Sheet1.Columns.Get(4).Label = "Used Rate";
            this.spdTableSpace_Sheet1.Columns.Get(4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.Columns.Get(4).Width = 62F;
            this.spdTableSpace_Sheet1.Columns.Get(5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdTableSpace_Sheet1.Columns.Get(5).Label = "File Name";
            this.spdTableSpace_Sheet1.Columns.Get(5).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdTableSpace_Sheet1.Columns.Get(5).Width = 300F;
            this.spdTableSpace_Sheet1.Columns.Get(6).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdTableSpace_Sheet1.Columns.Get(6).Label = "Status";
            this.spdTableSpace_Sheet1.Columns.Get(7).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdTableSpace_Sheet1.Columns.Get(7).Label = "Auto Extensible";
            this.spdTableSpace_Sheet1.Columns.Get(7).Width = 100F;
            this.spdTableSpace_Sheet1.Columns.Get(8).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdTableSpace_Sheet1.Columns.Get(8).Label = "Increment by";
            this.spdTableSpace_Sheet1.Columns.Get(8).Width = 80F;
            this.spdTableSpace_Sheet1.FrozenColumnCount = 1;
            this.spdTableSpace_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdTableSpace_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.ReadOnly;
            this.spdTableSpace_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdTableSpace_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdTableSpace_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdTableSpace_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdTableSpace_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdTableSpace_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // splCenterBottom
            // 
            this.splCenterBottom.Location = new System.Drawing.Point(360, 0);
            this.splCenterBottom.Name = "splCenterBottom";
            this.splCenterBottom.Size = new System.Drawing.Size(4, 263);
            this.splCenterBottom.TabIndex = 1;
            this.splCenterBottom.TabStop = false;
            // 
            // pnlCenterBottomLeft
            // 
            this.pnlCenterBottomLeft.Controls.Add(this.pnlDiskSpace);
            this.pnlCenterBottomLeft.Controls.Add(this.pnlDBConnected);
            this.pnlCenterBottomLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlCenterBottomLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlCenterBottomLeft.Name = "pnlCenterBottomLeft";
            this.pnlCenterBottomLeft.Size = new System.Drawing.Size(360, 263);
            this.pnlCenterBottomLeft.TabIndex = 0;
            // 
            // pnlDiskSpace
            // 
            this.pnlDiskSpace.Controls.Add(this.spdDiskSpace);
            this.pnlDiskSpace.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlDiskSpace.Location = new System.Drawing.Point(0, 0);
            this.pnlDiskSpace.Name = "pnlDiskSpace";
            this.pnlDiskSpace.Size = new System.Drawing.Size(360, 159);
            this.pnlDiskSpace.TabIndex = 0;
            // 
            // spdDiskSpace
            // 
            this.spdDiskSpace.AccessibleDescription = "spdDiskSpace, Sheet1, Row 0, Column 0, ";
            this.spdDiskSpace.BackColor = System.Drawing.SystemColors.Control;
            this.spdDiskSpace.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdDiskSpace.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdDiskSpace.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdDiskSpace.HorizontalScrollBar.Name = "";
            this.spdDiskSpace.HorizontalScrollBar.Renderer = defaultScrollBarRenderer5;
            this.spdDiskSpace.HorizontalScrollBar.TabIndex = 4;
            this.spdDiskSpace.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdDiskSpace.Location = new System.Drawing.Point(0, 0);
            this.spdDiskSpace.Name = "spdDiskSpace";
            namedStyle9.BackColor = System.Drawing.SystemColors.Control;
            namedStyle9.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle9.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle9.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle9.Renderer = columnHeaderRenderer4;
            namedStyle9.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle10.BackColor = System.Drawing.SystemColors.Control;
            namedStyle10.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle10.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle10.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle10.Renderer = rowHeaderRenderer4;
            namedStyle10.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle11.BackColor = System.Drawing.SystemColors.Control;
            namedStyle11.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle11.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle11.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle11.Renderer = cornerRenderer3;
            namedStyle11.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle12.BackColor = System.Drawing.SystemColors.Window;
            namedStyle12.CellType = generalCellType3;
            namedStyle12.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle12.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle12.Renderer = generalCellType3;
            this.spdDiskSpace.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle9,
            namedStyle10,
            namedStyle11,
            namedStyle12});
            this.spdDiskSpace.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.spdDiskSpace.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdDiskSpace_Sheet1});
            this.spdDiskSpace.Size = new System.Drawing.Size(360, 159);
            this.spdDiskSpace.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdDiskSpace.TabIndex = 0;
            this.spdDiskSpace.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdDiskSpace.VerticalScrollBar.Name = "";
            this.spdDiskSpace.VerticalScrollBar.Renderer = defaultScrollBarRenderer6;
            this.spdDiskSpace.VerticalScrollBar.TabIndex = 5;
            this.spdDiskSpace.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdDiskSpace.SetViewportLeftColumn(0, 0, 1);
            this.spdDiskSpace.SetActiveViewport(0, 0, -1);
            // 
            // spdDiskSpace_Sheet1
            // 
            this.spdDiskSpace_Sheet1.Reset();
            spdDiskSpace_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdDiskSpace_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            spdDiskSpace_Sheet1.ColumnCount = 5;
            spdDiskSpace_Sheet1.RowCount = 2;
            this.spdDiskSpace_Sheet1.AlternatingRows.Get(1).BackColor = System.Drawing.Color.WhiteSmoke;
            this.spdDiskSpace_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdDiskSpace_Sheet1.ColumnFooter.DefaultStyle.Parent = "HeaderDefault";
            this.spdDiskSpace_Sheet1.ColumnFooterSheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdDiskSpace_Sheet1.ColumnFooterSheetCornerStyle.Parent = "CornerDefault";
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Disk";
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Total Space";
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Used Space";
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Used Rate";
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "Unused Space";
            this.spdDiskSpace_Sheet1.ColumnHeader.Cells.Get(0, 4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdDiskSpace_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdDiskSpace_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdDiskSpace_Sheet1.Columns.Get(0).Label = "Disk";
            this.spdDiskSpace_Sheet1.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.Columns.Get(0).Width = 46F;
            this.spdDiskSpace_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdDiskSpace_Sheet1.Columns.Get(1).Label = "Total Space";
            this.spdDiskSpace_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.Columns.Get(1).Width = 110F;
            this.spdDiskSpace_Sheet1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdDiskSpace_Sheet1.Columns.Get(2).Label = "Used Space";
            this.spdDiskSpace_Sheet1.Columns.Get(2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.Columns.Get(2).Width = 110F;
            this.spdDiskSpace_Sheet1.Columns.Get(3).CellType = progressCellType6;
            this.spdDiskSpace_Sheet1.Columns.Get(3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdDiskSpace_Sheet1.Columns.Get(3).Label = "Used Rate";
            this.spdDiskSpace_Sheet1.Columns.Get(3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.Columns.Get(3).Width = 110F;
            this.spdDiskSpace_Sheet1.Columns.Get(4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdDiskSpace_Sheet1.Columns.Get(4).Label = "Unused Space";
            this.spdDiskSpace_Sheet1.Columns.Get(4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdDiskSpace_Sheet1.Columns.Get(4).Width = 110F;
            this.spdDiskSpace_Sheet1.FrozenColumnCount = 1;
            this.spdDiskSpace_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdDiskSpace_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.ReadOnly;
            this.spdDiskSpace_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdDiskSpace_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdDiskSpace_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdDiskSpace_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdDiskSpace_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdDiskSpace_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // pnlDBConnected
            // 
            this.pnlDBConnected.Controls.Add(this.pnlSessionCnt);
            this.pnlDBConnected.Controls.Add(this.pnlDBConnectTop);
            this.pnlDBConnected.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlDBConnected.Location = new System.Drawing.Point(0, 159);
            this.pnlDBConnected.Name = "pnlDBConnected";
            this.pnlDBConnected.Size = new System.Drawing.Size(360, 104);
            this.pnlDBConnected.TabIndex = 0;
            // 
            // gpbDBConnected
            // 
            this.gpbDBConnected.Controls.Add(this.btnReConnect);
            this.gpbDBConnected.Controls.Add(this.lblDBConnected);
            this.gpbDBConnected.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gpbDBConnected.Location = new System.Drawing.Point(0, 0);
            this.gpbDBConnected.Name = "gpbDBConnected";
            this.gpbDBConnected.Size = new System.Drawing.Size(360, 49);
            this.gpbDBConnected.TabIndex = 0;
            this.gpbDBConnected.TabStop = false;
            this.gpbDBConnected.Text = "DB Connection Status";
            // 
            // btnReConnect
            // 
            this.btnReConnect.Location = new System.Drawing.Point(96, 16);
            this.btnReConnect.Name = "btnReConnect";
            this.btnReConnect.Size = new System.Drawing.Size(72, 28);
            this.btnReConnect.TabIndex = 1;
            this.btnReConnect.Text = "ReConnect";
            this.btnReConnect.Click += new System.EventHandler(this.btnReConnect_Click);
            // 
            // lblDBConnected
            // 
            this.lblDBConnected.AutoSize = true;
            this.lblDBConnected.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDBConnected.ForeColor = System.Drawing.Color.Red;
            this.lblDBConnected.Location = new System.Drawing.Point(46, 23);
            this.lblDBConnected.Name = "lblDBConnected";
            this.lblDBConnected.Size = new System.Drawing.Size(33, 13);
            this.lblDBConnected.TabIndex = 0;
            this.lblDBConnected.Text = "FAIL";
            // 
            // chkAutoRefresh
            // 
            this.chkAutoRefresh.Checked = true;
            this.chkAutoRefresh.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkAutoRefresh.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.chkAutoRefresh.Location = new System.Drawing.Point(12, 12);
            this.chkAutoRefresh.Name = "chkAutoRefresh";
            this.chkAutoRefresh.Size = new System.Drawing.Size(84, 18);
            this.chkAutoRefresh.TabIndex = 0;
            this.chkAutoRefresh.Text = "Auto Refresh";
            this.chkAutoRefresh.CheckedChanged += new System.EventHandler(this.chkAutoRefresh_CheckedChanged);
            // 
            // tmrRefresh
            // 
            this.tmrRefresh.Interval = 60000;
            this.tmrRefresh.Tick += new System.EventHandler(this.tmrRefresh_Tick);
            // 
            // tmrProcess
            // 
            this.tmrProcess.Tick += new System.EventHandler(this.tmrProcess_Tick);
            // 
            // imlSPIcons
            // 
            this.imlSPIcons.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imlSPIcons.ImageStream")));
            this.imlSPIcons.TransparentColor = System.Drawing.Color.Transparent;
            this.imlSPIcons.Images.SetKeyName(0, "");
            this.imlSPIcons.Images.SetKeyName(1, "");
            this.imlSPIcons.Images.SetKeyName(2, "");
            this.imlSPIcons.Images.SetKeyName(3, "");
            // 
            // btnExpand
            // 
            this.btnExpand.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnExpand.Image = ((System.Drawing.Image)(resources.GetObject("btnExpand.Image")));
            this.btnExpand.Location = new System.Drawing.Point(195, 8);
            this.btnExpand.Name = "btnExpand";
            this.btnExpand.Size = new System.Drawing.Size(24, 24);
            this.btnExpand.TabIndex = 3;
            this.btnExpand.Click += new System.EventHandler(this.btnExpand_Click);
            // 
            // btnCollapse
            // 
            this.btnCollapse.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnCollapse.Image = ((System.Drawing.Image)(resources.GetObject("btnCollapse.Image")));
            this.btnCollapse.Location = new System.Drawing.Point(163, 8);
            this.btnCollapse.Name = "btnCollapse";
            this.btnCollapse.Size = new System.Drawing.Size(24, 24);
            this.btnCollapse.TabIndex = 2;
            this.btnCollapse.Click += new System.EventHandler(this.btnCollapse_Click);
            // 
            // btnProcess
            // 
            this.btnProcess.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnProcess.Location = new System.Drawing.Point(555, 7);
            this.btnProcess.Name = "btnProcess";
            this.btnProcess.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.btnProcess.Size = new System.Drawing.Size(88, 26);
            this.btnProcess.TabIndex = 7;
            this.btnProcess.Text = "View";
            this.btnProcess.Click += new System.EventHandler(this.btnProcess_Click);
            // 
            // chkCollapse
            // 
            this.chkCollapse.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.chkCollapse.Location = new System.Drawing.Point(144, 12);
            this.chkCollapse.Name = "chkCollapse";
            this.chkCollapse.Size = new System.Drawing.Size(15, 18);
            this.chkCollapse.TabIndex = 1;
            this.chkCollapse.CheckedChanged += new System.EventHandler(this.chkCollapse_CheckedChanged);
            // 
            // btnChgEnv
            // 
            this.btnChgEnv.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnChgEnv.Location = new System.Drawing.Point(461, 7);
            this.btnChgEnv.Name = "btnChgEnv";
            this.btnChgEnv.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.btnChgEnv.Size = new System.Drawing.Size(88, 26);
            this.btnChgEnv.TabIndex = 6;
            this.btnChgEnv.Text = "CHG Level";
            this.btnChgEnv.Click += new System.EventHandler(this.btnChgEnv_Click);
            // 
            // cboLogLevel
            // 
            this.cboLogLevel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.cboLogLevel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cboLogLevel.FormattingEnabled = true;
            this.cboLogLevel.Items.AddRange(new object[] {
            "1 : Log All",
            "2 : Warning",
            "3 : Error",
            "4 : Time"});
            this.cboLogLevel.Location = new System.Drawing.Point(368, 10);
            this.cboLogLevel.Name = "cboLogLevel";
            this.cboLogLevel.Size = new System.Drawing.Size(90, 21);
            this.cboLogLevel.TabIndex = 5;
            // 
            // btnPoolInit
            // 
            this.btnPoolInit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnPoolInit.Location = new System.Drawing.Point(274, 7);
            this.btnPoolInit.Name = "btnPoolInit";
            this.btnPoolInit.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.btnPoolInit.Size = new System.Drawing.Size(88, 26);
            this.btnPoolInit.TabIndex = 4;
            this.btnPoolInit.Text = "Init Pool";
            this.btnPoolInit.Click += new System.EventHandler(this.btnPoolInit_Click);
            // 
            // tmrProcessStatus
            // 
            this.tmrProcessStatus.Enabled = true;
            this.tmrProcessStatus.Interval = 10000;
            this.tmrProcessStatus.Tick += new System.EventHandler(this.tmrProcessStatus_Tick);
            // 
            // pnlDBConnectTop
            // 
            this.pnlDBConnectTop.Controls.Add(this.gpbDBConnected);
            this.pnlDBConnectTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlDBConnectTop.Location = new System.Drawing.Point(0, 0);
            this.pnlDBConnectTop.Name = "pnlDBConnectTop";
            this.pnlDBConnectTop.Size = new System.Drawing.Size(360, 49);
            this.pnlDBConnectTop.TabIndex = 1;
            // 
            // pnlSessionCnt
            // 
            this.pnlSessionCnt.Controls.Add(this.grpSessionCnt);
            this.pnlSessionCnt.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlSessionCnt.Location = new System.Drawing.Point(0, 49);
            this.pnlSessionCnt.Name = "pnlSessionCnt";
            this.pnlSessionCnt.Size = new System.Drawing.Size(360, 55);
            this.pnlSessionCnt.TabIndex = 2;
            // 
            // grpSessionCnt
            // 
            this.grpSessionCnt.Controls.Add(this.txtSessionCnt);
            this.grpSessionCnt.Controls.Add(this.txtIPAddress);
            this.grpSessionCnt.Controls.Add(this.lblSessionCnt);
            this.grpSessionCnt.Controls.Add(this.lblIPAddress);
            this.grpSessionCnt.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpSessionCnt.Location = new System.Drawing.Point(0, 0);
            this.grpSessionCnt.Name = "grpSessionCnt";
            this.grpSessionCnt.Size = new System.Drawing.Size(360, 55);
            this.grpSessionCnt.TabIndex = 0;
            this.grpSessionCnt.TabStop = false;
            this.grpSessionCnt.Text = "Session Info";
            // 
            // lblIPAddress
            // 
            this.lblIPAddress.AutoSize = true;
            this.lblIPAddress.Location = new System.Drawing.Point(9, 26);
            this.lblIPAddress.Name = "lblIPAddress";
            this.lblIPAddress.Size = new System.Drawing.Size(58, 13);
            this.lblIPAddress.TabIndex = 0;
            this.lblIPAddress.Text = "IP Address";
            // 
            // lblSessionCnt
            // 
            this.lblSessionCnt.AutoSize = true;
            this.lblSessionCnt.Location = new System.Drawing.Point(212, 26);
            this.lblSessionCnt.Name = "lblSessionCnt";
            this.lblSessionCnt.Size = new System.Drawing.Size(75, 13);
            this.lblSessionCnt.TabIndex = 1;
            this.lblSessionCnt.Text = "Session Count";
            // 
            // txtIPAddress
            // 
            this.txtIPAddress.Location = new System.Drawing.Point(73, 23);
            this.txtIPAddress.Name = "txtIPAddress";
            this.txtIPAddress.ReadOnly = true;
            this.txtIPAddress.Size = new System.Drawing.Size(125, 20);
            this.txtIPAddress.TabIndex = 2;
            // 
            // txtSessionCnt
            // 
            this.txtSessionCnt.Location = new System.Drawing.Point(293, 23);
            this.txtSessionCnt.Name = "txtSessionCnt";
            this.txtSessionCnt.ReadOnly = true;
            this.txtSessionCnt.Size = new System.Drawing.Size(57, 20);
            this.txtSessionCnt.TabIndex = 3;
            this.txtSessionCnt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // frmADMTaskManager
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Name = "frmADMTaskManager";
            this.Text = "Task Manager";
            this.Activated += new System.EventHandler(this.frmADMTaskManager_Activated);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmADMTaskManager_FormClosed);
            this.Load += new System.EventHandler(this.frmADMTaskManager_Load);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.frmADMTaskManager_KeyPress);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlCenterTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdProcess)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdProcess_Sheet1)).EndInit();
            this.pnlCenterBottom.ResumeLayout(false);
            this.pnlCenterBottomRight.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdTableSpace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdTableSpace_Sheet1)).EndInit();
            this.pnlCenterBottomLeft.ResumeLayout(false);
            this.pnlDiskSpace.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdDiskSpace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdDiskSpace_Sheet1)).EndInit();
            this.pnlDBConnected.ResumeLayout(false);
            this.gpbDBConnected.ResumeLayout(false);
            this.gpbDBConnected.PerformLayout();
            this.pnlDBConnectTop.ResumeLayout(false);
            this.pnlSessionCnt.ResumeLayout(false);
            this.grpSessionCnt.ResumeLayout(false);
            this.grpSessionCnt.PerformLayout();
            this.ResumeLayout(false);

		}
		
		#endregion
		
		#region "Variable Definition"
		
		private bool bLoadFlag;
        private long iTickCount;
		
		private FarPoint.Win.Spread.CellType.GeneralCellType plusCellType = new FarPoint.Win.Spread.CellType.GeneralCellType();
		private FarPoint.Win.Spread.CellType.GeneralCellType minusCellType = new FarPoint.Win.Spread.CellType.GeneralCellType();
		private FarPoint.Win.Spread.CellType.GeneralCellType ProcessCellType = new FarPoint.Win.Spread.CellType.GeneralCellType();

		#endregion
		
		#region "Constant Definition"
		
		private const int COL_ICON = 0;
		private const int COL_MODULE = 1;
		private const int COL_TOT_CNT = 2;
		private const int COL_RUNNING_CNT = 3;

        private const int COL_PROCESS = 2;
		private const int COL_STATUS = 3;
        private const int COL_INIT_POOL = 4;
		
		#endregion
		
		#region "Enumeration Definition"
		
		private enum CELL_STATUS
		{
			PLUS = 1,
			MINUS = 2,
			EMPTY = 3,
			CHECK = 4
		}
		
		#endregion
		
		#region "Function Definition"
		
		// View_Status()
		//       - View Disk space, process list, DB connection and table space
		// Return Value
		//       -
		// Arguments
		//  procstep = 1 전체 표시, 2=프로세스 리스트 초기화, 3=프로세스 리스트만 다시그림
		private void View_Status(int ProcStep)
		{
			int i;
			
			if (ProcStep == 2)
			{
				
				if (MPGV.gtProcessinfoList != null)
				{
					for (i = 0; i < MPGV.gtProcessinfoList.Length; i++)
					{
						MPGV.gtProcessinfoList[i].process_name = "";
						MPGV.gtProcessinfoList[i].channel = "";
                        MPGV.gtProcessinfoList[i].sub_no = "";
						MPGV.gtProcessinfoList[i].check_seq = 0;
						MPGV.gtProcessinfoList[i].reply_count = 0;
						MPGV.gtProcessinfoList[i].reply_status_1 = MPGC.ADM_IDLE_STATUS;
						MPGV.gtProcessinfoList[i].reply_status_2 = MPGC.ADM_IDLE_STATUS;
                        MPGV.gtProcessinfoList[i].shared_pool_status = MPGC.ADM_IDLE_STATUS;
					}
				}
				
                //각 Server로 확인 Message를 전송한다.
				CheckProcess();
			}

            if (ProcStep == 1 || ProcStep == 2)
            {

                if (CheckDBConnect(1) == false)
                {
                    return;
                }

                if (ViewDiskSpaceList() == false)
                {
                    return;
                }

                if (ViewTableSpaceList() == false)
                {
                    return;
                }
            }

            if (ProcStep == 1 || ProcStep == 2 || ProcStep == 3)
            {
                //확인된 정보를 이용하여 화면에 표시한다.
                if (ViewProcessList() == false)
                {
                    return;
                }
                
                if (ADCGV.SysMessage != null && ADCGV.SysMessage != "")
                {
                    string sIPAddress = ADCGV.SysMessage.Substring(ADCGV.SysMessage.IndexOf("bindAddress"));
                    sIPAddress = sIPAddress.Substring(sIPAddress.IndexOf(':') + 1);
                    sIPAddress = sIPAddress.Substring(0, sIPAddress.IndexOf(','));
                    sIPAddress = sIPAddress.Replace('\"', ' ');

                    txtIPAddress.Text = sIPAddress.Trim();

                    string sSessionCnt = ADCGV.SysMessage.Substring(ADCGV.SysMessage.IndexOf("sessionCount"));
                    sSessionCnt = sSessionCnt.Substring(sSessionCnt.IndexOf(':') + 1);
                    sSessionCnt = sSessionCnt.Substring(0, sSessionCnt.IndexOf('}'));
                    sSessionCnt = sSessionCnt.Replace('\"', ' ');

                    txtSessionCnt.Text = sSessionCnt.Trim();
                }

                ADCGV.SysMessage = string.Empty;
            }
			
		}
		
		// ViewProcessList()
		//       - View Server Process list
		// Return Value
		//       -
		// Arguments
		//       -
		private bool ViewProcessList()
		{
			
			int i;
			int j;
			int iRow;
			int iIndex;
			
			try
			{
                spdProcess.SuspendLayout();

                MPCF.ClearList(spdProcess);
				
				if (MPGV.gtServerInfoList == null || MPGV.gtProcessinfoList == null)
				{
					return true;
				}
				
				for (i = 0; i < MPGV.gtServerInfoList.Length; i++)
				{
					MPGV.gtServerInfoList[i].proc_count = 0;
				}
				
				//각 서버(MESServer, ADMINServer, EISServer) 별로 살아 있는 Process 갯수를 Count 한다.
				for (i = 0; i < MPGV.gtProcessinfoList.Length; i++)
				{
					if (MPGV.gtProcessinfoList[i].reply_status_1 == MPGC.ADM_REPLY_STATUS || MPGV.gtProcessinfoList[i].reply_status_2 == MPGC.ADM_REPLY_STATUS)
					{
						for (j = 0; j < MPGV.gtServerInfoList.Length; j++)
						{
							if (MPGV.gtServerInfoList[j].server_name == MPGV.gtProcessinfoList[i].server_name)
							{
								MPGV.gtServerInfoList[j].proc_count = MPGV.gtServerInfoList[j].proc_count + 1;
								break;
							}
						}
					}
				}

				iIndex = 0;
				
				for (i = 0; i < MPGV.gtServerInfoList.Length; i++)
				{
					iRow = spdProcess.ActiveSheet.RowCount;
					spdProcess.ActiveSheet.RowCount++;
					spdProcess.ActiveSheet.Cells[iRow, COL_MODULE, iRow, spdProcess.ActiveSheet.ColumnCount - 1].Font = new Font(spdProcess.Font.Name, spdProcess.Font.Size, FontStyle.Bold);
					
					spdProcess.ActiveSheet.Cells[iRow, COL_ICON].CellType = minusCellType;
					spdProcess.ActiveSheet.Cells[iRow, COL_ICON].Tag = CELL_STATUS.MINUS;
					
					spdProcess.ActiveSheet.Cells[iRow, COL_MODULE].Value = MPGV.gtServerInfoList[i].server_name;
					spdProcess.ActiveSheet.Cells[iRow, COL_TOT_CNT].Value = MPGV.gtServerInfoList[i].tot_count;
					spdProcess.ActiveSheet.Cells[iRow, COL_RUNNING_CNT].Value = MPGV.gtServerInfoList[i].proc_count;
					spdProcess.ActiveSheet.Cells[iRow, COL_MODULE, iRow, COL_INIT_POOL].BackColor = Color.WhiteSmoke;
					
					for (j = iIndex; j < MPGV.gtProcessinfoList.Length; j++)
					{
						if (MPGV.gtServerInfoList[i].server_name == MPGV.gtProcessinfoList[j].server_name)
						{
							if (MPCF.Trim(MPGV.gtProcessinfoList[j].process_name) != "")
							{
								iRow = spdProcess.ActiveSheet.RowCount;
								spdProcess.ActiveSheet.RowCount++;
								
								//.Cells[iRow, COL_MODULE).Value = gtProcessInfoList(i).server_name
                                spdProcess.ActiveSheet.Cells[iRow, COL_MODULE].Tag = MPGV.gtProcessinfoList[j].channel;

                                spdProcess.ActiveSheet.Cells[iRow, COL_PROCESS].Value = MPGV.gtProcessinfoList[j].process_name;
								if (MPGV.gtProcessinfoList[j].reply_status_1 == MPGC.ADM_REPLY_STATUS || MPGV.gtProcessinfoList[j].reply_status_2 == MPGC.ADM_REPLY_STATUS)
								{
									spdProcess.ActiveSheet.Cells[iRow, COL_STATUS].Value = "Running";
								}
								else
								{
									spdProcess.ActiveSheet.Cells[iRow, COL_STATUS].Value = "Stop";
								}
								//.Cells[iRow, COL_MODULE, iRow, COL_STATUS).BackColor = Color.WhiteSmoke

                                if (MPGV.gtProcessinfoList[j].shared_pool_status == MPGC.ADM_REPLY_STATUS)
                                {
                                    spdProcess.ActiveSheet.Cells[iRow, COL_INIT_POOL].Value = "OK";
                                }
                                else if (MPGV.gtProcessinfoList[j].shared_pool_status == MPGC.ADM_REQUEST_STATUS)
                                {
                                    spdProcess.ActiveSheet.Cells[iRow, COL_INIT_POOL].Value = "Request";
                                }
                                else
                                {
                                    spdProcess.ActiveSheet.Cells[iRow, COL_INIT_POOL].Value = "";
                                }
                            }
						}
						else
						{
							spdProcess.ActiveSheet.Cells[spdProcess.ActiveSheet.RowCount - 1, COL_ICON, spdProcess.ActiveSheet.RowCount - 1, spdProcess.ActiveSheet.ColumnCount - 1].Border = new FarPoint.Win.ComplexBorder(new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.ThinLine));
							iIndex = j;
							break;
						}
					}
				}
				spdProcess.ActiveSheet.Cells[spdProcess.ActiveSheet.RowCount - 1, COL_ICON, spdProcess.ActiveSheet.RowCount - 1, spdProcess.ActiveSheet.ColumnCount - 1].Border = new FarPoint.Win.ComplexBorder(new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.ThinLine));

                spdProcess.ResumeLayout();

                if (chkCollapse.Checked == true)
                {
                    btnCollapse.PerformClick();
                }

				return true;
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
				return false;
			}
			
		}
		
		// ViewTableSpaceList()
		//       - View table space list
		// Return Value
		//       -
		// Arguments
		//       -
		private bool ViewTableSpaceList()
		{
			
            int i;
            int iLastRow;
            double d_percent;

            TRSNode in_node = new TRSNode("VIEW_TABLESPACE_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_TABLESPACE_LIST_OUT");

            try
            {
                MPCF.ClearList(spdTableSpace);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                do
                {

                    if (MPCR.CallService("ADM", "ADM_View_TableSpace_List", in_node, ref out_node) == false)
                    {
                    	return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {

                        iLastRow = spdTableSpace.ActiveSheet.RowCount;
                        spdTableSpace.ActiveSheet.RowCount = spdTableSpace.ActiveSheet.RowCount + 1;

                        d_percent = 0;
                        if (out_node.GetList(0)[i].GetDouble("TOTAL_SPACE") > 0)
                            d_percent = out_node.GetList(0)[i].GetDouble("USED_SPACE") * 100/ out_node.GetList(0)[i].GetDouble("TOTAL_SPACE");

                        if (d_percent > 100)
                            d_percent = 100;
                        else if (d_percent < 0)
                            d_percent = 0;

                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 3, d_percent);
                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 4, d_percent / 100);

                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 0, MPCF.Trim(out_node.GetList(0)[i].GetString("TABLESPACE_NAME")));
                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 1, MPCF.Format("#,##0.00 MB", (out_node.GetList(0)[i].GetDouble("TOTAL_SPACE"))));
                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 2, MPCF.Format("#,##0.00 MB", (out_node.GetList(0)[i].GetDouble("USED_SPACE"))));
                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 5, MPCF.Trim(out_node.GetList(0)[i].GetString("FILE_NAME")));
                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 6, MPCF.Trim(out_node.GetList(0)[i].GetString("STATUS")));
                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 7, MPCF.Trim(out_node.GetList(0)[i].GetString("AUTOEXTENSIBLE")));
                        spdTableSpace.ActiveSheet.SetValue(iLastRow, 8, MPCF.Format("#,##0.00 MB", (out_node.GetList(0)[i].GetDouble("INCREMENT_BY"))));
                        if (out_node.GetList(0)[i].GetDouble("TOTAL_SPACE") > 0)
                        {
                            if ((out_node.GetList(0)[i].GetDouble("USED_SPACE") * 100 / out_node.GetList(0)[i].GetDouble("TOTAL_SPACE")) >= 90)
                            {
                                spdTableSpace.ActiveSheet.Rows[iLastRow].ForeColor = Color.Magenta;
                            }
                        }
                    }

                    in_node.SetString("NEXT_TABLESPACE_NAME", out_node.GetString("NEXT_TABLESPACE_NAME"));
                } while (!(in_node.GetString("NEXT_TABLESPACE_NAME") == ""));

                MPCF.FitColumnHeader(spdTableSpace);
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
		
		}
		
		// ViewDiskSpaceList()
		//       - View Disk Space List
		// Return Value
		//       -
		// Arguments
		//       -
		
		private bool ViewDiskSpaceList()
		{
		
            int i;
            int iLastRow;
            double d_percent;

            TRSNode in_node = new TRSNode("VIEW_DISK_INFO_IN");
            TRSNode out_node = new TRSNode("VIEW_DISK_INFO_OUT");

            try
            {                
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                if (MPCR.CallService("ADM", "ADM_View_Disk_Info", in_node, ref out_node, true) == false)
                {
                	return false;
                }

                MPCF.ClearList(spdDiskSpace);
                for (i = 0; i < out_node.GetList(0).Count; i++)
                {

                    iLastRow = spdDiskSpace.ActiveSheet.RowCount;
                    spdDiskSpace.ActiveSheet.RowCount = spdDiskSpace.ActiveSheet.RowCount + 1;
                    if (MPCF.Trim(out_node.GetList(0)[i].GetString("DISK")) != "" && MPCF.Trim(out_node.GetList(0)[i].GetString("MOUNT_NAME")) != "")
                    {
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 0, (MPCF.RTrim(out_node.GetList(0)[i].GetString("MOUNT_NAME")) + " (" + MPCF.RTrim(out_node.GetList(0)[i].GetString("DISK")) + ")"));
                    }
                    else
                    {
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 0, MPCF.Trim(out_node.GetList(0)[i].GetString("DISK")));
                    }

                    d_percent = 0;
                    if (out_node.GetList(0)[i].GetDouble("TOTAL_SPACE") > 0)
                        d_percent = out_node.GetList(0)[i].GetDouble("USED_SPACE") * 100 / out_node.GetList(0)[i].GetDouble("TOTAL_SPACE");

                    if (d_percent > 100)
                        d_percent = 100;
                    else if (d_percent < 0)
                        d_percent = 0;

                    spdDiskSpace.ActiveSheet.SetValue(iLastRow, 3, d_percent);

                    if (out_node.GetString("UNIT") == "MB")
                    {
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 1, MPCF.Format("#,##0.00 GB", (out_node.GetList(0)[i].GetDouble("TOTAL_SPACE") / 1024)));
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 2, MPCF.Format("#,##0.00 GB", (out_node.GetList(0)[i].GetDouble("USED_SPACE") / 1024)));
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 4, MPCF.Format("#,##0.00 GB", (out_node.GetList(0)[i].GetDouble("UNUSED_SPACE") / 1024)));
                    }
                    else if (out_node.GetString("UNIT") == "KB")
                    {
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 1, MPCF.Format("#,##0 KB", (out_node.GetList(0)[i].GetDouble("TOTAL_SPACE"))));
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 2, MPCF.Format("#,##0 KB", (out_node.GetList(0)[i].GetDouble("USED_SPACE") / 1024)));
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 4, MPCF.Format("#,##0 KB", (out_node.GetList(0)[i].GetDouble("UNUSED_SPACE") / 1024)));
                    }
                    else if (out_node.GetString("UNIT") == "SB")
                    {
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 1, MPCF.Format("#,##0 KB", (out_node.GetList(0)[i].GetDouble("TOTAL_SPACE"))));
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 2, MPCF.Format("#,##0 KB", (out_node.GetList(0)[i].GetDouble("USED_SPACE") )));
                        spdDiskSpace.ActiveSheet.SetValue(iLastRow, 4, MPCF.Format("#,##0 KB", (out_node.GetList(0)[i].GetDouble("UNUSED_SPACE") )));
                    }

                    if ((out_node.GetList(0)[i].GetDouble("USED_SPACE") * 100 / out_node.GetList(0)[i].GetDouble("TOTAL_SPACE")) >= 90)
                    {
                        spdDiskSpace.ActiveSheet.Rows[iLastRow].ForeColor = Color.Magenta;
                    }
                }

                MPCF.FitColumnHeader(spdDiskSpace);
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

			
		}
		
		// CheckDBConnect()
		//       - Check Database connection
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       - Optional ByVal Chacking As Integer = 1 : checking value (1 : checking DB status.  2 : reconneting DB)
		
		private bool CheckDBConnect(int Chacking) // 1 : checking DB status.  2 : reconneting DB
		{
			
			TRSNode in_node = new TRSNode("CHECK_DB_CONNECT_IN");
            TRSNode out_node = new TRSNode("CHECK_DB_CONNECT_OUT");

            try
            {

                MPCR.SetInMsg(in_node);

                if (Chacking == 1)
                {
                    in_node.AddChar("ADM_DB_CHECK", 'C'); // C : checking DB status.  R : reconneting DB);
                }
                else
                {
                    in_node.AddChar("ADM_DB_CHECK", 'R');
                }

                if (MPCR.CallService("ADM", "ADM_Check_DB_Connect", in_node, ref out_node, true) == false)
                {
                	return false;
                }
                    
                if(out_node.StatusValue != MPGC.MP_SUCCESS_STATUS)
                {
                    lblDBConnected.Text = "FAIL";
                    lblDBConnected.ForeColor = Color.Red;
                    btnReConnect.Visible = true;
                    return false;
                }

                lblDBConnected.Text = "SUCCESS";
                lblDBConnected.ForeColor = Color.Green;
                btnReConnect.Visible = false;

                return true;
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
				return false;
			}
			
		}
		
		//
		// LoadServerList()
		//       - Publish Load Server List to monitor
		// Return Value
		//       - Boolean : Return True/False
		// Arguments
		//
		//
		private bool LoadServerList()
		{
			
			
			try
			{
                TRSNode in_node = new TRSNode("VIEW_DATA_LIST_IN");
                TRSNode out_node = new TRSNode("VIEW_DATA_LIST_OUT");

                int i;
                int j;
                int iServercnt;
                int iProcCnt;
                string sAddress;
                string sTmpServer = null;

                MPGV.gtServerInfoList = null;
                MPGV.gtProcessinfoList = null;
                iServercnt = 0;
                iProcCnt = 0;

                sAddress = MPGV.gsRemoteAddress;
                if (sAddress.ToUpper() == MPGC.MP_LOCAL_HOST)
                {
                    sAddress = MPCF.GetHostAddress("LOCALHOST");
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = MPGV.gsCentralFactory;
                in_node.AddString("TABLE_NAME", MPGC.MP_GCM_SERVER_LIST);
                in_node.AddString("NEXT_KEY_1", "");
                in_node.AddString("NEXT_KEY_2", "");

                do
                {
                    if (MPCR.CallService("BAS", "BAS_View_Data_List", in_node, ref out_node) == false)
                    {
                    	return false;
                    }

                    if (out_node.GetList(0).Count == 0)
                    {
                        break;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (sTmpServer == null)
                        {
                            sTmpServer = MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1"));

                            Array.Resize<gtServerInfoTag>(ref MPGV.gtServerInfoList, iServercnt + 1);
                            MPGV.gtServerInfoList[iServercnt] = new gtServerInfoTag();

                            MPGV.gtServerInfoList[iServercnt].server_name = out_node.GetList(0)[i].GetString("KEY_1");

                            if (MPCF.CheckNumeric(out_node.GetList(0)[i].GetString("DATA_2")) == true)
                            {
                                MPGV.gtServerInfoList[iServercnt].tot_count = MPCF.ToInt(out_node.GetList(0)[i].GetString("DATA_2"));

                                if (MPGV.gtProcessinfoList != null)
                                {
                                    iProcCnt = MPGV.gtProcessinfoList.Length;
                                }

                                Array.Resize<gtProcessInfoTag>(ref MPGV.gtProcessinfoList, iProcCnt + MPGV.gtServerInfoList[iServercnt].tot_count);

                                for (j = 0; j < MPGV.gtServerInfoList[iServercnt].tot_count; j++)
                                {
                                    MPGV.gtProcessinfoList[iProcCnt + j] = new gtProcessInfoTag();
                                    MPGV.gtProcessinfoList[iProcCnt + j].server_name = MPGV.gtServerInfoList[iServercnt].server_name;
                                    MPGV.gtProcessinfoList[iProcCnt + j].process_name = "";
                                    MPGV.gtProcessinfoList[iProcCnt + j].channel = "";
                                    MPGV.gtProcessinfoList[iProcCnt + j].sub_no = "";
                                    MPGV.gtProcessinfoList[iProcCnt + j].check_seq = 0;
                                    MPGV.gtProcessinfoList[iProcCnt + j].reply_count = 0;
                                    MPGV.gtProcessinfoList[iProcCnt + j].reply_status_1 = MPGC.ADM_IDLE_STATUS;
                                    MPGV.gtProcessinfoList[iProcCnt + j].reply_status_2 = MPGC.ADM_IDLE_STATUS;
                                    MPGV.gtProcessinfoList[iProcCnt + j].shared_pool_status = MPGC.ADM_IDLE_STATUS;
                                }
                            }
                            else
                            {
                                MPGV.gtServerInfoList[iServercnt].tot_count = 0;
                            }

                            iServercnt++;
                        }
                        else
                        {
                            if (sTmpServer != MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1")))
                            {
                                sTmpServer = MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1"));

                                Array.Resize<gtServerInfoTag>(ref MPGV.gtServerInfoList, iServercnt + 1);
                                MPGV.gtServerInfoList[iServercnt] = new gtServerInfoTag();

                                MPGV.gtServerInfoList[iServercnt].server_name = out_node.GetList(0)[i].GetString("KEY_1");

                                if (MPCF.CheckNumeric(out_node.GetList(0)[i].GetString("DATA_2")) == true)
                                {
                                    if (MPGV.gtProcessinfoList != null)
                                    {
                                        iProcCnt = MPGV.gtProcessinfoList.Length;
                                    }

                                    MPGV.gtServerInfoList[iServercnt].tot_count = MPCF.ToInt(out_node.GetList(0)[i].GetString("DATA_2"));

                                    Array.Resize<gtProcessInfoTag>(ref MPGV.gtProcessinfoList, iProcCnt + MPGV.gtServerInfoList[iServercnt].tot_count);

                                    for (j = 0; j < MPGV.gtServerInfoList[iServercnt].tot_count; j++)
                                    {
                                        MPGV.gtProcessinfoList[iProcCnt + j] = new gtProcessInfoTag();
                                        MPGV.gtProcessinfoList[iProcCnt + j].server_name = MPGV.gtServerInfoList[iServercnt].server_name;
                                        MPGV.gtProcessinfoList[iProcCnt + j].process_name = "";
                                        MPGV.gtProcessinfoList[iProcCnt + j].channel = "";
                                        MPGV.gtProcessinfoList[iProcCnt + j].sub_no = "";
                                        MPGV.gtProcessinfoList[iProcCnt + j].check_seq = 0;
                                        MPGV.gtProcessinfoList[iProcCnt + j].reply_count = 0;
                                        MPGV.gtProcessinfoList[iProcCnt + j].reply_status_1 = MPGC.ADM_IDLE_STATUS;
                                        MPGV.gtProcessinfoList[iProcCnt + j].reply_status_2 = MPGC.ADM_IDLE_STATUS;
                                        MPGV.gtProcessinfoList[iProcCnt + j].shared_pool_status = MPGC.ADM_IDLE_STATUS;
                                    }
                                }
                                else
                                {
                                    MPGV.gtServerInfoList[iServercnt].tot_count = 0;
                                }

                                iServercnt++;
                            }
                        }
                    }

                    in_node.SetString("NEXT_KEY_1", out_node.GetString("NEXT_KEY_1"));
                    in_node.SetString("NEXT_KEY_2", out_node.GetString("NEXT_KEY_2"));
                } while (in_node.GetString("NEXT_KEY_1") != "" || out_node.GetString("NEXT_KEY_2") != "");

                if (iServercnt == 0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
				return false;
			}
			
		}
		
		//
		// CheckProcess()
		//       - Publish Check Process
		// Return Value
		//       - Boolean : Return True/False
		// Arguments
		//
		//
		private bool CheckProcess()
		{
            return ADCGV.TaskMan.CheckProcess();
		}
		
		//
        // InitSharedPool()
		//       - Initial Shared Pool
		// Return Value
		//       - Boolean : Return True/False
		// Arguments
		//
		//
		private bool InitSharedPool(string s_server_name, string s_channel)
		{
            return ADCGV.TaskMan.InitSharedPool(s_server_name, s_channel);
		}


        #endregion
		
		private void frmADMTaskManager_Load(object sender, System.EventArgs e)
		{
			
			try
			{
				MPCF.ToClientLanguage(this);

                plusCellType.BackgroundImage = new FarPoint.Win.Picture(imlSPIcons.Images[MPCF.ToInt(CELL_STATUS.PLUS) - 1], FarPoint.Win.RenderStyle.Normal, Color.White, FarPoint.Win.HorizontalAlignment.Center, FarPoint.Win.VerticalAlignment.Center);
                minusCellType.BackgroundImage = new FarPoint.Win.Picture(imlSPIcons.Images[MPCF.ToInt(CELL_STATUS.MINUS) - 1], FarPoint.Win.RenderStyle.Normal, Color.White, FarPoint.Win.HorizontalAlignment.Center, FarPoint.Win.VerticalAlignment.Center);
				
				btnReConnect.Visible = false;
				lblDBConnected.Text = "";				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}

        private void frmADMTaskManager_Activated(object sender, System.EventArgs e)
        {

            try
            {
                if (bLoadFlag == false)
                {
                    string sCollapse;

                    MPCF.ClearList(spdProcess);
                    MPCF.ClearList(spdDiskSpace);
                    MPCF.ClearList(spdTableSpace);

                    MPGV.giRequestCnt = 0;
                    MPGV.giRequestSeq = 0;
                    iTickCount = 0;

                    if ((sCollapse = MPCF.GetRegSetting(Application.ProductName, "Option", "chkCollapse", "False")) == "True")
                    {
                        chkCollapse.Checked = true;
                    }

                    if (MPGV.giAutoRefreshTime > 0)
                    {
                        chkAutoRefresh.Checked = MPGV.gbAutoRefresh;
                        tmrRefresh.Interval = MPGV.giAutoRefreshTime * 1000 / 8;
                        tmrProcess.Interval = (MPGV.giAutoRefreshTime * 1000) / 4;
                    }
                    else
                    {
                        tmrRefresh.Interval = MPGC.MP_AUTO_REFRESH_TIME * 1000 / 8;
                        tmrProcess.Interval = (MPGC.MP_AUTO_REFRESH_TIME * 1000) / 4;
                    }

                    if (LoadServerList() == false)
                    {
                        return;
                    }

                    if (ADCGV.TaskMan.PublishADMMsgTune() == false)
                    {
                        return;
                    }

                    //Add by J.S. 2016.04.05
                    if (ADCGV.TaskMan.PublishSYSMsgTune() == false)
                    {
                        return;
                    }

                    //tmrProcess.Start();
                    View_Status(2);

                    //tmrProcess_Tick(null, null);

                    tmrRefresh.Start();
                    tmrProcess.Start();

                    bLoadFlag = true;

                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }
        
        private void frmADMTaskManager_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
			
			try
			{
				
				if (!(this.ActiveControl == null))
				{
					if (this.ActiveControl is TextBox)
					{
						if (e.KeyChar == (char)58)
						{
							e.Handled = true;
						}
					}
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
        private void frmADMTaskManager_FormClosed(object sender, FormClosedEventArgs e)
        {
            ADCGV.TaskMan.PublishADMMsgUnTune();
            //Add by J.S. 2016.04.05
            ADCGV.TaskMan.PublishSYSMsgUnTune();
        }
		
		private void tmrRefresh_Tick(System.Object sender, System.EventArgs e)
		{
            try
            {
                if (iTickCount < 11)
                {
                    iTickCount++;
                    View_Status(3);
                }
                else
                {
                    iTickCount = 0;
                    View_Status(1);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


		}
		
		private void tmrProcess_Tick(System.Object sender, System.EventArgs e)
		{
			
			CheckProcess();
			
		}
		
		
		private void btnReConnect_Click(System.Object sender, System.EventArgs e)
		{
			
			if (lblDBConnected.Text == "SUCCESS")
			{
				return;
			}
			
			lblDBConnected.Text = "Connecting...";
			if (CheckDBConnect(2) == false)
			{
				return;
			}

		}
		
		private void btnProcess_Click(System.Object sender, System.EventArgs e)
		{
			
			View_Status(2);
			
		}
		
		private void chkAutoRefresh_CheckedChanged(System.Object sender, System.EventArgs e)
		{
			if (chkAutoRefresh.Checked == true)
			{
				tmrRefresh.Start();
                tmrProcess.Start();
			}
			else
			{
				tmrRefresh.Stop();
                tmrProcess.Stop();
            }
		}
		
		private void spdProcess_CellClick(System.Object sender, FarPoint.Win.Spread.CellClickEventArgs e)
		{
			int i;
			
			if (spdProcess.ActiveSheet.RowCount < 1)
			{
				return;
			}
			if (e.Column != COL_ICON)
			{
				return;
			}
			if (e.Row < 0)
			{
				return;
			}
			if (e.ColumnHeader == true)
			{
				return;
			}
			if (e.RowHeader == true)
			{
				return;
			}
			
			if (System.Convert.ToString(spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].Tag).Trim() == "")
			{
				return;
			}
			
			for (i = e.Row + 1; i < spdProcess.ActiveSheet.RowCount; i++)
			{
				if (System.Convert.ToString(spdProcess.ActiveSheet.Cells[i, COL_ICON].Tag).Trim() != "")
				{
					break;
				}
				
				if (MPCF.ToInt(spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].Tag) == (int)CELL_STATUS.MINUS)
				{
					spdProcess.ActiveSheet.Rows[i].Visible = false;
				}
				else
				{
					spdProcess.ActiveSheet.Rows[i].Visible = true;
				}
			}

            if (MPCF.ToInt(spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].Tag) == (int)CELL_STATUS.MINUS)
			{
				spdProcess.ActiveSheet.Cells[e.Row, COL_ICON, e.Row, spdProcess.ActiveSheet.ColumnCount - 1].Border = new FarPoint.Win.ComplexBorder(new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.ThinLine, Color.LightGray));
				
				spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].CellType = plusCellType;
				spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].Tag = CELL_STATUS.PLUS;
				
			}
            else if (MPCF.ToInt(spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].Tag) == (int)CELL_STATUS.PLUS)
			{
				spdProcess.ActiveSheet.Cells[e.Row, COL_ICON, e.Row, spdProcess.ActiveSheet.ColumnCount - 1].Border = new FarPoint.Win.ComplexBorder(new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None));
				
				spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].CellType = minusCellType;
				spdProcess.ActiveSheet.Cells[e.Row, COL_ICON].Tag = CELL_STATUS.MINUS;
			}
			
		}
		
		private void btnCollapse_Click(System.Object sender, System.EventArgs e)
		{
			int i;

			for (i = 0; i < spdProcess.ActiveSheet.RowCount; i++)
			{
				if (System.Convert.ToString(spdProcess.ActiveSheet.Cells[i, COL_ICON].Tag).Trim() == "")
				{
					spdProcess.ActiveSheet.Rows[i].Visible = false;
				}
				else
				{
					spdProcess.ActiveSheet.Cells[i, COL_ICON, i, spdProcess.ActiveSheet.ColumnCount - 1].Border = new FarPoint.Win.ComplexBorder(new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.ThinLine, Color.LightGray));
					
					if (MPCF.ToInt(spdProcess.ActiveSheet.Cells[i, COL_ICON].Tag) == (int)CELL_STATUS.MINUS)
					{
						spdProcess.ActiveSheet.Cells[i, COL_ICON].CellType = plusCellType;
						spdProcess.ActiveSheet.Cells[i, COL_ICON].Tag = CELL_STATUS.PLUS;
					}
				}
			}
			
		}
		
		private void btnExpand_Click(System.Object sender, System.EventArgs e)
		{
			int i;

			for (i = 0; i < spdProcess.ActiveSheet.RowCount; i++)
			{
				if (System.Convert.ToString(spdProcess.ActiveSheet.Cells[i, COL_ICON].Tag).Trim() == "")
				{
					spdProcess.ActiveSheet.Rows[i].Visible = true;
				}
				else
				{
					spdProcess.ActiveSheet.Cells[i, COL_ICON, i, spdProcess.ActiveSheet.ColumnCount - 1].Border = new FarPoint.Win.ComplexBorder(new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None), new FarPoint.Win.ComplexBorderSide(FarPoint.Win.ComplexBorderSideStyle.None));
					
					if (MPCF.ToInt(spdProcess.ActiveSheet.Cells[i, COL_ICON].Tag) == (int)CELL_STATUS.PLUS)
					{
						spdProcess.ActiveSheet.Cells[i, COL_ICON].CellType = minusCellType;
						spdProcess.ActiveSheet.Cells[i, COL_ICON].Tag = CELL_STATUS.MINUS;
					}
				}
			}
			
		}

        private void chkCollapse_CheckedChanged(object sender, EventArgs e)
        {
            if (chkCollapse.Checked == true)
            {
                btnCollapse.PerformClick();
                MPCF.SaveRegSetting(Application.ProductName, "Option", "chkCollapse", "True");
            }
            else
            {
                MPCF.SaveRegSetting(Application.ProductName, "Option", "chkCollapse", "False");
            }
        }

        private void btnChgEnv_Click(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("CHANGE_ENVVALUES_IN");

            try
            {
                if (MPCF.Trim(cboLogLevel.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    cboLogLevel.Focus();
                    return;
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddInt("LOGLEVEL", MPCF.ToInt(MPCF.Trim(cboLogLevel.Text).Substring(0, 1)));

                ///'H101 Bug ?뚮Ц??
                string sPublishChannel;

                //모든 MES 서버로...
                sPublishChannel = "/*/MESServer";
                   
                if(MPCR.CallService("ADM", "ADM_Change_EnvValues", in_node, sPublishChannel, 0, DeliveryMode.Multicast, false) == false)
                {
                    MPGV.gIMdiForm.SetStatusMessage(MPMH.StatusMessage);
                    return;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPoolInit_Click(object sender, EventArgs e)
        {
            if (spdProcess.ActiveSheet.GetSelections().Length < 1)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(109));
                spdProcess.Focus();
                return;
            }

            string s_server_name = "";
            string s_channel = "";
            int i_row;
            int i;

            i_row = spdProcess.ActiveSheet.ActiveRowIndex;

            for (i = i_row; i >= 0; i--)
            {
                if (MPCF.Trim(spdProcess.ActiveSheet.Cells[i, COL_MODULE].Value) != "")
                {
                    s_server_name = MPCF.Trim(spdProcess.ActiveSheet.Cells[i, COL_MODULE].Value);
                    break;
                }
            }
            for (i = i_row; i < spdProcess.ActiveSheet.RowCount; i++)
            {
                if (MPCF.Trim(spdProcess.ActiveSheet.Cells[i, COL_MODULE].Tag) != "")
                {
                    s_channel = MPCF.Trim(spdProcess.ActiveSheet.Cells[i, COL_MODULE].Tag);
                    break;
                }
            }

            InitSharedPool(s_server_name, s_channel);
            ViewProcessList();
        }

        private void tmrProcessStatus_Tick(object sender, EventArgs e)
        {
            ViewProcessList();
        }
	}
}

