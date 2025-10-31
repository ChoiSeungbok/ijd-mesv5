using System.Data;
using System;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;
using System.Drawing;
using Miracom.CliFrx;
using Miracom.UI.Controls.MCCodeView;
using Miracom.SECCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using Admin.COMCore;

//-----------------------------------------------------------------------------
//
//   System      : ADMIN
//   File Name   : frmARCViewOptionList.vb
//   Description : View archive option list and Run archive program remotely
//
//   ADMIN Version : 4.0.0
//
//   Function List
//       - ViewArchiveOptionList() : View Archive option list
//       - RunArchive() : Run Archive program remotely
//       - Insert_Data_List() : Insert archvie conditions with factory and module information
//       - CheckCondition() : Check selecting condition
//
//   Detail Description
//       -
//
//    History
//    Seq   Date        Developer      Description
//    ---------------------------------------------------------------------------
//    1     2005/08/03  Andy Yun       Create
//
//
//   Copyright(C) 1998-2005 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------


namespace Admin.ARCCore
{
    public class frmARCViewOptionList : Miracom.MESCore.ViewForm01
    {


        #region " Windows Form 디자이너에서 생성한 코드 "

        public frmARCViewOptionList()
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
		
		//Windows Form 디자이너에 필요합니다.
		private System.ComponentModel.Container components = null;
		
		//참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
		//Windows Form 디자이너를 사용하여 수정할 수 있습니다.
		//코드 편집기를 사용하여 수정하지 마십시오.
		private System.Windows.Forms.Label lblFactory;
		private Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        private System.Windows.Forms.Button btnRun;
		private FarPoint.Win.Spread.FpSpread spdList;
		private FarPoint.Win.Spread.SheetView spdList_Sheet1;
		private FarPoint.Win.Spread.FpSpread FpSpread1;
        private CheckBox chkSelectAll;
        private Button btnSelectModule;
		private FarPoint.Win.Spread.SheetView SheetView1;
		[System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
		{
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer1 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.TipAppearance tipAppearance1 = new FarPoint.Win.Spread.TipAppearance();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer2 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType1 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType2 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            FarPoint.Win.Spread.TipAppearance tipAppearance2 = new FarPoint.Win.Spread.TipAppearance();
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType3 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType4 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            this.lblFactory = new System.Windows.Forms.Label();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.btnRun = new System.Windows.Forms.Button();
            this.spdList = new FarPoint.Win.Spread.FpSpread();
            this.spdList_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.FpSpread1 = new FarPoint.Win.Spread.FpSpread();
            this.SheetView1 = new FarPoint.Win.Spread.SheetView();
            this.chkSelectAll = new System.Windows.Forms.CheckBox();
            this.btnSelectModule = new System.Windows.Forms.Button();
            this.pnlViewTop.SuspendLayout();
            this.grpOption.SuspendLayout();
            this.pnlViewMid.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdList_Sheet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.FpSpread1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.SheetView1)).BeginInit();
            this.SuspendLayout();
            // 
            // btnExcel
            // 
            this.btnExcel.Click += new System.EventHandler(this.btnExcel_Click);
            // 
            // pnlViewTop
            // 
            this.pnlViewTop.Size = new System.Drawing.Size(742, 51);
            // 
            // grpOption
            // 
            this.grpOption.Controls.Add(this.lblFactory);
            this.grpOption.Controls.Add(this.cdvFactory);
            this.grpOption.Controls.Add(this.btnSelectModule);
            this.grpOption.Controls.Add(this.btnRun);
            this.grpOption.Size = new System.Drawing.Size(742, 51);
            // 
            // pnlViewMid
            // 
            this.pnlViewMid.Controls.Add(this.spdList);
            this.pnlViewMid.Controls.Add(this.FpSpread1);
            this.pnlViewMid.Location = new System.Drawing.Point(0, 51);
            this.pnlViewMid.Size = new System.Drawing.Size(742, 463);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.chkSelectAll);
            this.pnlBottom.Location = new System.Drawing.Point(0, 514);
            this.pnlBottom.Size = new System.Drawing.Size(742, 39);
            this.pnlBottom.Controls.SetChildIndex(this.chkSelectAll, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnView, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnExcel, 0);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(742, 514);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "Run Archive && View Archive Option List";
            // 
            // lblFactory
            // 
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Location = new System.Drawing.Point(20, 23);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(60, 14);
            this.lblFactory.TabIndex = 0;
            this.lblFactory.Text = "Factory";
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
            this.cdvFactory.Location = new System.Drawing.Point(96, 19);
            this.cdvFactory.MaxLength = 10;
            this.cdvFactory.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.Name = "cdvFactory";
            this.cdvFactory.ReadOnly = false;
            this.cdvFactory.SearchSubItemIndex = 0;
            this.cdvFactory.SelectedDescIndex = -1;
            this.cdvFactory.SelectedSubItemIndex = -1;
            this.cdvFactory.SelectionStart = 0;
            this.cdvFactory.Size = new System.Drawing.Size(150, 20);
            this.cdvFactory.SmallImageList = null;
            this.cdvFactory.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvFactory.TabIndex = 1;
            this.cdvFactory.TextBoxToolTipText = "";
            this.cdvFactory.TextBoxWidth = 150;
            this.cdvFactory.VisibleButton = true;
            this.cdvFactory.VisibleColumnHeader = false;
            this.cdvFactory.VisibleDescription = false;
            this.cdvFactory.ButtonPress += new System.EventHandler(this.cdvFactory_ButtonPress);
            this.cdvFactory.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvFactory_SelectedItemChanged);
            // 
            // btnRun
            // 
            this.btnRun.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnRun.Location = new System.Drawing.Point(629, 18);
            this.btnRun.Name = "btnRun";
            this.btnRun.Size = new System.Drawing.Size(92, 24);
            this.btnRun.TabIndex = 3;
            this.btnRun.Text = "Run Archive";
            this.btnRun.Click += new System.EventHandler(this.btnRun_Click);
            // 
            // spdList
            // 
            this.spdList.AccessibleDescription = "";
            this.spdList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdList.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdList.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdList.HorizontalScrollBar.Name = "";
            this.spdList.HorizontalScrollBar.Renderer = defaultScrollBarRenderer1;
            this.spdList.HorizontalScrollBar.TabIndex = 2;
            this.spdList.Location = new System.Drawing.Point(0, 0);
            this.spdList.Name = "spdList";
            this.spdList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdList_Sheet1});
            this.spdList.Size = new System.Drawing.Size(742, 463);
            this.spdList.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdList.TabIndex = 0;
            tipAppearance1.BackColor = System.Drawing.SystemColors.Info;
            tipAppearance1.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            tipAppearance1.ForeColor = System.Drawing.SystemColors.InfoText;
            this.spdList.TextTipAppearance = tipAppearance1;
            this.spdList.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdList.VerticalScrollBar.Name = "";
            this.spdList.VerticalScrollBar.Renderer = defaultScrollBarRenderer2;
            this.spdList.VerticalScrollBar.TabIndex = 3;
            this.spdList.CellClick += new FarPoint.Win.Spread.CellClickEventHandler(this.spdList_CellClick);
            // 
            // spdList_Sheet1
            // 
            this.spdList_Sheet1.Reset();
            this.spdList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdList_Sheet1.ColumnCount = 10;
            this.spdList_Sheet1.RowCount = 0;
            this.spdList_Sheet1.AlternatingRows.Get(1).BackColor = System.Drawing.Color.WhiteSmoke;
            checkBoxCellType1.Caption = "Select";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 0).CellType = checkBoxCellType1;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 0).Locked = false;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "False";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Factory";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Module";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Term";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "Days";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 5).Value = "Archive Speed";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 5).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 6).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 6).Value = "Archive Deletion";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 6).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 7).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 7).Value = "Backup Type";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 7).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 8).Value = "Rollback Segment";
            this.spdList_Sheet1.ColumnHeader.Cells.Get(0, 9).Value = "Master Table Deletion";
            this.spdList_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdList_Sheet1.ColumnHeader.Rows.Get(0).Height = 18F;
            this.spdList_Sheet1.Columns.Get(0).CellType = checkBoxCellType2;
            this.spdList_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(0).Label = "False";
            this.spdList_Sheet1.Columns.Get(0).Width = 75F;
            this.spdList_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdList_Sheet1.Columns.Get(1).Label = "Factory";
            this.spdList_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(1).Width = 103F;
            this.spdList_Sheet1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdList_Sheet1.Columns.Get(2).Label = "Module";
            this.spdList_Sheet1.Columns.Get(2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(2).Width = 126F;
            this.spdList_Sheet1.Columns.Get(3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdList_Sheet1.Columns.Get(3).Label = "Term";
            this.spdList_Sheet1.Columns.Get(3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(3).Width = 68F;
            this.spdList_Sheet1.Columns.Get(4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdList_Sheet1.Columns.Get(4).Label = "Days";
            this.spdList_Sheet1.Columns.Get(4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(4).Width = 68F;
            this.spdList_Sheet1.Columns.Get(5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdList_Sheet1.Columns.Get(5).Label = "Archive Speed";
            this.spdList_Sheet1.Columns.Get(5).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(5).Width = 96F;
            this.spdList_Sheet1.Columns.Get(6).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdList_Sheet1.Columns.Get(6).Label = "Archive Deletion";
            this.spdList_Sheet1.Columns.Get(6).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(6).Width = 126F;
            this.spdList_Sheet1.Columns.Get(7).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdList_Sheet1.Columns.Get(7).Label = "Backup Type";
            this.spdList_Sheet1.Columns.Get(7).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(7).Width = 146F;
            this.spdList_Sheet1.Columns.Get(8).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdList_Sheet1.Columns.Get(8).Label = "Rollback Segment";
            this.spdList_Sheet1.Columns.Get(8).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(8).Width = 124F;
            this.spdList_Sheet1.Columns.Get(9).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(9).Label = "Master Table Deletion";
            this.spdList_Sheet1.Columns.Get(9).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdList_Sheet1.Columns.Get(9).Width = 124F;
            this.spdList_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdList_Sheet1.RowHeader.Columns.Default.Resizable = true;
            this.spdList_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdList_Sheet1.SelectionPolicy = FarPoint.Win.Spread.Model.SelectionPolicy.Single;
            this.spdList_Sheet1.SelectionUnit = FarPoint.Win.Spread.Model.SelectionUnit.Row;
            this.spdList_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdList_Sheet1.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            this.spdList.SetActiveViewport(0, 1, 0);
            // 
            // FpSpread1
            // 
            this.FpSpread1.AccessibleDescription = "";
            this.FpSpread1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.FpSpread1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FpSpread1.Location = new System.Drawing.Point(0, 0);
            this.FpSpread1.Name = "FpSpread1";
            this.FpSpread1.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.SheetView1});
            this.FpSpread1.Size = new System.Drawing.Size(742, 463);
            this.FpSpread1.TabIndex = 1;
            tipAppearance2.BackColor = System.Drawing.SystemColors.Info;
            tipAppearance2.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            tipAppearance2.ForeColor = System.Drawing.SystemColors.InfoText;
            this.FpSpread1.TextTipAppearance = tipAppearance2;
            // 
            // SheetView1
            // 
            this.SheetView1.Reset();
            this.SheetView1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.SheetView1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.SheetView1.ColumnCount = 10;
            this.SheetView1.RowCount = 0;
            this.SheetView1.AlternatingRows.Get(1).BackColor = System.Drawing.Color.WhiteSmoke;
            checkBoxCellType3.Caption = "Select";
            this.SheetView1.ColumnHeader.Cells.Get(0, 0).CellType = checkBoxCellType3;
            this.SheetView1.ColumnHeader.Cells.Get(0, 0).Locked = false;
            this.SheetView1.ColumnHeader.Cells.Get(0, 0).Value = "Select";
            this.SheetView1.ColumnHeader.Cells.Get(0, 1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 1).Value = "Factory";
            this.SheetView1.ColumnHeader.Cells.Get(0, 1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 2).Value = "Module";
            this.SheetView1.ColumnHeader.Cells.Get(0, 2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 3).Value = "Term";
            this.SheetView1.ColumnHeader.Cells.Get(0, 3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 4).Value = "Days";
            this.SheetView1.ColumnHeader.Cells.Get(0, 4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 5).Value = "Archive Speed";
            this.SheetView1.ColumnHeader.Cells.Get(0, 5).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 6).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 6).Value = "Archive Deletion";
            this.SheetView1.ColumnHeader.Cells.Get(0, 6).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 7).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 7).Value = "Backup Type";
            this.SheetView1.ColumnHeader.Cells.Get(0, 7).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.ColumnHeader.Cells.Get(0, 8).Value = "Rollback Segment";
            this.SheetView1.ColumnHeader.Cells.Get(0, 9).Value = "Master Table Deletion";
            this.SheetView1.ColumnHeader.Rows.Get(0).Height = 18F;
            this.SheetView1.Columns.Get(0).CellType = checkBoxCellType4;
            this.SheetView1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.Columns.Get(0).Label = "Select";
            this.SheetView1.Columns.Get(0).Width = 75F;
            this.SheetView1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.SheetView1.Columns.Get(1).Label = "Factory";
            this.SheetView1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(1).Width = 103F;
            this.SheetView1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.SheetView1.Columns.Get(2).Label = "Module";
            this.SheetView1.Columns.Get(2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(2).Width = 126F;
            this.SheetView1.Columns.Get(3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.SheetView1.Columns.Get(3).Label = "Term";
            this.SheetView1.Columns.Get(3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(3).Width = 68F;
            this.SheetView1.Columns.Get(4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.SheetView1.Columns.Get(4).Label = "Days";
            this.SheetView1.Columns.Get(4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(4).Width = 68F;
            this.SheetView1.Columns.Get(5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.SheetView1.Columns.Get(5).Label = "Archive Speed";
            this.SheetView1.Columns.Get(5).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(5).Width = 96F;
            this.SheetView1.Columns.Get(6).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.SheetView1.Columns.Get(6).Label = "Archive Deletion";
            this.SheetView1.Columns.Get(6).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(6).Width = 126F;
            this.SheetView1.Columns.Get(7).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.SheetView1.Columns.Get(7).Label = "Backup Type";
            this.SheetView1.Columns.Get(7).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(7).Width = 146F;
            this.SheetView1.Columns.Get(8).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.SheetView1.Columns.Get(8).Label = "Rollback Segment";
            this.SheetView1.Columns.Get(8).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(8).Width = 124F;
            this.SheetView1.Columns.Get(9).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.SheetView1.Columns.Get(9).Label = "Master Table Deletion";
            this.SheetView1.Columns.Get(9).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.SheetView1.Columns.Get(9).Width = 124F;
            this.SheetView1.GrayAreaBackColor = System.Drawing.Color.White;
            this.SheetView1.RowHeader.Columns.Default.Resizable = true;
            this.SheetView1.SelectionPolicy = FarPoint.Win.Spread.Model.SelectionPolicy.Single;
            this.SheetView1.SelectionUnit = FarPoint.Win.Spread.Model.SelectionUnit.Row;
            this.SheetView1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            this.FpSpread1.SetActiveViewport(0, 1, 0);
            // 
            // chkSelectAll
            // 
            this.chkSelectAll.AutoSize = true;
            this.chkSelectAll.Location = new System.Drawing.Point(42, 13);
            this.chkSelectAll.Name = "chkSelectAll";
            this.chkSelectAll.Size = new System.Drawing.Size(70, 17);
            this.chkSelectAll.TabIndex = 3;
            this.chkSelectAll.Text = "Select All";
            this.chkSelectAll.UseVisualStyleBackColor = true;
            this.chkSelectAll.CheckedChanged += new System.EventHandler(this.chkSelectAll_CheckedChanged);
            // 
            // btnSelectModule
            // 
            this.btnSelectModule.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnSelectModule.Location = new System.Drawing.Point(507, 18);
            this.btnSelectModule.Name = "btnSelectModule";
            this.btnSelectModule.Size = new System.Drawing.Size(92, 24);
            this.btnSelectModule.TabIndex = 2;
            this.btnSelectModule.Text = "Set Module";
            this.btnSelectModule.Visible = false;
            this.btnSelectModule.Click += new System.EventHandler(this.btnSelectModule_Click);
            // 
            // frmARCViewOptionList
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Name = "frmARCViewOptionList";
            this.Tag = "ADM1003";
            this.Text = "Run Archive & View Archive Option List";
            this.Load += new System.EventHandler(this.frmARCViewOptionList_Load);
            this.Activated += new System.EventHandler(this.frmARCViewOptionList_Activated);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmARCViewOptionList_FormClosed);
            this.pnlViewTop.ResumeLayout(false);
            this.grpOption.ResumeLayout(false);
            this.pnlViewMid.ResumeLayout(false);
            this.pnlBottom.ResumeLayout(false);
            this.pnlBottom.PerformLayout();
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdList_Sheet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.FpSpread1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.SheetView1)).EndInit();
            this.ResumeLayout(false);

		}
		
		#endregion
		
		#region "Variable Definition"
		
		private bool bLoadFlag;
		
		#endregion
		
		#region "Function Definition"
		
		// ViewArchiveOptionList()
		//       - View Archive option list
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       -
		
		private bool ViewArchiveOptionList()
		{
			
			int i;
            int iLastRow;

            TRSNode in_node = new TRSNode("VIEW_ARCHIVE_OPT_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ARCHIVE_OPT_LIST_OUT");

            try
            {
                MPCF.ClearList(spdList);
                spdList.ActiveSheet.ColumnHeader.Cells[0, 0].Value = false;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("TARGET_FACTORY", MPCF.Trim(cdvFactory.Text));
                in_node.AddString("MODULE_NAME", "");

                do
                {
                    if (MPCR.CallService("ARC", "ARC_View_Archive_Opt_List", in_node, ref out_node) == false)
                    {
                    	return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {

                        iLastRow = spdList.Sheets[0].RowCount;
                        spdList.Sheets[0].RowCount = spdList.Sheets[0].RowCount + 1;
                        FarPoint.Win.Spread.SheetView with_1 = spdList.Sheets[0];
                        with_1.SetValue(iLastRow, 1, MPCF.Trim(out_node.GetList(0)[i].GetString("FACTORY")));
                        with_1.SetValue(iLastRow, 2, MPCF.Trim(out_node.GetList(0)[i].GetString("MODULE_NAME")));
                        with_1.SetValue(iLastRow, 3, MPCF.Trim(out_node.GetList(0)[i].GetInt("TERM")));
                        with_1.SetValue(iLastRow, 4, MPCF.Trim(out_node.GetList(0)[i].GetInt("DAYS")));
                        with_1.SetValue(iLastRow, 5, MPCF.Trim(out_node.GetList(0)[i].GetInt("SPD_TIME")));

                        if (out_node.GetList(0)[i].GetChar("MOD_TYPE").ToString() == MPGC.ARC_SOURCE_DELETE)
                        {
                            with_1.SetValue(iLastRow, 6, "Delete");
                        }
                        else
                        {
                            with_1.SetValue(iLastRow, 6, "Not Delete");
                        }

                        if (out_node.GetList(0)[i].GetChar("MED_TYPE").ToString() == MPGC.ARC_BACKUP_DB)
                        {
                            with_1.SetValue(iLastRow, 7, "Only Database");
                        }
                        else if (out_node.GetList(0)[i].GetChar("MED_TYPE").ToString() == MPGC.ARC_BACKUP_FILE)
                        {
                            with_1.SetValue(iLastRow, 7, "Only File");
                        }
                        else
                        {
                            with_1.SetValue(iLastRow, 7, "Database And File Both");
                        }

                        if (out_node.GetList(0)[i].GetChar("ROL_FLAG").ToString() == MPGC.ARC_ROLLBACK_USE)
                        {
                            with_1.SetValue(iLastRow, 8, "Use");
                        }
                        else
                        {
                            with_1.SetValue(iLastRow, 8, "Not Use");
                        }

                        with_1.SetValue(iLastRow, 9, out_node.GetList(0)[i].GetChar("MAS_DEL_FLAG"));

                        if (MPCF.Trim(out_node.GetList(0)[i].GetString("RUN_VALUE")) == MPGC.ARC_RUNNING)
                        {
                            with_1.SetValue(iLastRow, 0, true);
                        }

                    }

                    in_node.SetString("MODULE_NAME", out_node.GetString("NEXT_MODULE_NAME"));

                } while (!(in_node.GetString("MODULE_NAME") == ""));

                MPCF.FitColumnHeader(spdList);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }		
		}
		
		// RunArchive()
		//       - Run Archive program remotely
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       -
		
		private bool RunArchive()
		{

            TRSNode in_node = new TRSNode("ADM_RUN_MESARCHIVE_IN");
            TRSNode out_node = new TRSNode("ADM_RUN_MESARCHIVE_OUT");

            try
            {
                MPCR.SetInMsg(in_node);

                in_node.Factory = MPCF.Trim(cdvFactory.Text);
                in_node.ProcStep = '1';

                if (MPCR.CallService("ADM", "ADM_Run_MESarchive", in_node, ref out_node) == false)
                {
                    return false;
                }
                //MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }			
		}
		
		// Insert_Data_List()
		//       - Insert archvie conditions with factory and module information
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       - ByVal ProcStep As String : Process Step
		
		private bool Insert_Data_List(char ProcStep)
		{
            int i = 0;

            TRSNode in_node = new TRSNode("INSERT_DATA_LIST_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            TRSNode list_item;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.Factory = MPCF.Trim(cdvFactory.Text);
                in_node.ProcStep = ProcStep;

                for (i = 0; i < spdList.Sheets[0].RowCount; i++)
                {
                    if (Convert.ToBoolean(spdList.Sheets[0].GetValue(i, 0)) == true)
                    {
                        list_item = in_node.AddNode("ARCHIVE_LIST");

                        list_item.AddString("FACTORY", MPCF.RTrim(spdList.Sheets[0].GetValue(i, 1)));
                        list_item.AddString("MODULE_NAME", MPCF.RTrim(spdList.Sheets[0].GetValue(i, 2)));

                    }
                }

                if (MPCR.CallService("ARC", "ARC_Insert_Archive_Running_List", in_node, ref out_node, true) == false)
                {
                    return false;
                }

                //MPCR.ShowSuccessMsg(out_node);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;			
		}
		
		
		// CheckCondition()
		//       -   Check selecting condition
		// Return Value
		//       -
		// Arguments
		//       -
		private bool CheckCondition()
		{
			int i = 0;
			int iChkCnt = 0;
			
			try
			{
				for (i = 0; i < spdList.Sheets[0].RowCount; i++)
				{
					if (Convert.ToBoolean(spdList.Sheets[0].GetValue(i, 0)) == true)
					{
						iChkCnt++;
					}
				}
				
				if (iChkCnt == 0)
				{
                    MPCF.ShowMsgBox(MPCF.GetMessage(133));
					spdList.Select();
					return false;
				}
				
				return true;
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
				return false;
			}
		}
		
		#endregion
		
		private void frmARCViewOptionList_Load(object sender, System.EventArgs e)
		{
			
			 
            MPCF.ToClientLanguage(this);
			
		}
		
		private void frmARCViewOptionList_Activated(object sender, System.EventArgs e)
		{
			
			if (bLoadFlag == false)
			{
                MPCF.ClearList(spdList);
                MPCF.FitColumnHeader(spdList);

                MPCF.FieldClear(this);
				bLoadFlag = true;
			}
			
		}
		
		private void cdvFactory_ButtonPress(object sender, System.EventArgs e)
		{
			Miracom.UI.Controls.MCCodeView.MCCodeView cdvTemp;
			
			cdvTemp = (Miracom.UI.Controls.MCCodeView.MCCodeView) sender;
            ADCM.ViewFactoryList(cdvTemp.GetListView, '1', null);
		}
		
		private void btnView_Click(System.Object sender, System.EventArgs e)
		{
			
			if (ViewArchiveOptionList() == false)
			{
				return;
			}
			
		}
		
		private void btnExcel_Click(System.Object sender, System.EventArgs e)
		{
			string sCond;
			
			sCond = "Factory : " + MPCF.RTrim(cdvFactory.Text);
			MPCF.ExportToExcel(spdList, this.Text, sCond);
			
		}
		
		private void btnRun_Click(System.Object sender, System.EventArgs e)
		{
			
			try
			{
                
                if (MPGV.gsFactory != cdvFactory.Text && MPGV.gsFactory != MPGV.gsCentralFactory)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(245));
                    return;
                }

                if (spdList.Sheets[0].RowCount == 0)
				{
					return;
				}
				
                if (MPCF.ShowMsgBox(MPCF.GetMessage(246), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes) return;
				
				if (CheckCondition() == false)
				{
					return;
				}
				
				if (Insert_Data_List(MPGC.MP_STEP_UPDATE) == false)
				{
					return;
				}
				
				if (RunArchive() == false)
				{
					return;
				}
				
				if (ViewArchiveOptionList() == false)
				{
					return;
				}

                MPCF.ShowMsgBox(MPCF.GetMessage(60));
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void btnSelectModule_Click(System.Object sender, System.EventArgs e)
		{
            if (MPGV.gsFactory != cdvFactory.Text && MPGV.gsFactory != MPGV.gsCentralFactory)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(245));
                return;
            }

			if (Insert_Data_List(MPGC.MP_STEP_UPDATE) == false)
			{
				return;
			}
			
			if (ViewArchiveOptionList() == false)
			{
				return;
			}
			
		}
		
		private void spdList_CellClick(System.Object sender, FarPoint.Win.Spread.CellClickEventArgs e)
		{
			int i;
			
			try
			{
				if (e.ColumnHeader == true && e.Column == 0)
				{
					spdList.ActiveSheet.SelectionUnit = FarPoint.Win.Spread.Model.SelectionUnit.Cell;
					if (Convert.ToBoolean(spdList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value) == true)
					{
						spdList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value = false;
						for (i = 0; i < spdList.Sheets[0].RowCount; i++)
						{
							spdList.Sheets[0].SetValue(i, 0, false);
						}
					}
					else
					{
						spdList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value = true;
						for (i = 0; i < spdList.Sheets[0].RowCount; i++)
						{
							spdList.Sheets[0].SetValue(i, 0, true);
						}
					}
				}
				else
				{
					spdList.ActiveSheet.SelectionUnit = FarPoint.Win.Spread.Model.SelectionUnit.Row;
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}

        private void frmARCViewOptionList_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.Dispose();
        }

        private void cdvFactory_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (ViewArchiveOptionList() == false)
            {
                return;
            }
        }

        private void chkSelectAll_CheckedChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < spdList.Sheets[0].RowCount; i++)
            {
                if (chkSelectAll.Checked == true)
                {
                    spdList.Sheets[0].SetValue(i, 0, true);
                }
                else
                {
                    spdList.Sheets[0].SetValue(i, 0, false);
                }
            }
        }
	}
}
