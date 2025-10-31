namespace CUS_WIP
{
    partial class frmTranTestForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer2 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer2 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer1 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle1 = new FarPoint.Win.Spread.NamedStyle("Style4");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType1 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle2 = new FarPoint.Win.Spread.NamedStyle("Style5");
            FarPoint.Win.Spread.NamedStyle namedStyle3 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType1 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle4 = new FarPoint.Win.Spread.NamedStyle("Style1");
            FarPoint.Win.BevelBorder bevelBorder1 = new FarPoint.Win.BevelBorder(FarPoint.Win.BevelBorderType.Lowered);
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType2 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle5 = new FarPoint.Win.Spread.NamedStyle("FilterBarDefault");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType2 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle6 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle7 = new FarPoint.Win.Spread.NamedStyle("Style3");
            FarPoint.Win.Spread.NamedStyle namedStyle8 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle9 = new FarPoint.Win.Spread.NamedStyle("Style2");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType3 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.SpreadSkin spreadSkin1 = new FarPoint.Win.Spread.SpreadSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer2 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.StatusBarSkin statusBarSkin1 = new FarPoint.Win.Spread.StatusBarSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer3 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.BevelBorder bevelBorder5 = new FarPoint.Win.BevelBorder(FarPoint.Win.BevelBorderType.Lowered);
            this.spdPackingLotList = new FarPoint.Win.Spread.FpSpread();
            this.spdPackingLotList_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.lblSec = new System.Windows.Forms.Label();
            this.numRefreshSec = new System.Windows.Forms.NumericUpDown();
            this.chkAutoRefresh = new System.Windows.Forms.CheckBox();
            this.tmrTimer = new System.Windows.Forms.Timer(this.components);
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).BeginInit();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdPackingLotList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdPackingLotList_Sheet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numRefreshSec)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.Size = new System.Drawing.Size(1217, 48);
            // 
            // pnlMID
            // 
            this.pnlMID.Controls.Add(this.spdPackingLotList);
            this.pnlMID.Size = new System.Drawing.Size(1237, 618);
            this.pnlMID.Controls.SetChildIndex(this.lblFormName, 0);
            this.pnlMID.Controls.SetChildIndex(this.pnlStsCond, 0);
            this.pnlMID.Controls.SetChildIndex(this.lblDirectQuery, 0);
            this.pnlMID.Controls.SetChildIndex(this.chkFavorite, 0);
            this.pnlMID.Controls.SetChildIndex(this.spdPackingLotList, 0);
            // 
            // pnlStsCond3
            // 
            this.pnlStsCond3.Location = new System.Drawing.Point(0, 38);
            this.pnlStsCond3.Size = new System.Drawing.Size(1217, 10);
            // 
            // lblFormName
            // 
            this.lblFormName.Size = new System.Drawing.Size(279, 30);
            this.lblFormName.Text = "설비 네트워크상태 모니터링";
            // 
            // lblDirectQuery
            // 
            this.lblDirectQuery.Location = new System.Drawing.Point(1174, 30);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(1101, 10);
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // lblOper
            // 
            this.lblOper.Location = new System.Drawing.Point(3, 13);
            this.lblOper.Visible = false;
            // 
            // cdvOper
            // 
            this.cdvOper.Location = new System.Drawing.Point(3, 7);
            this.cdvOper.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOper.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvOper.Size = new System.Drawing.Size(10, 26);
            this.cdvOper.TextBoxWidth = 10;
            this.cdvOper.Visible = false;
            // 
            // lblWorkPlace
            // 
            this.lblWorkPlace.Location = new System.Drawing.Point(3, 13);
            this.lblWorkPlace.Visible = false;
            // 
            // cdvWorkPlace
            // 
            this.cdvWorkPlace.Location = new System.Drawing.Point(3, 7);
            this.cdvWorkPlace.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvWorkPlace.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvWorkPlace.Size = new System.Drawing.Size(10, 26);
            this.cdvWorkPlace.TextBoxWidth = 10;
            this.cdvWorkPlace.Visible = false;
            // 
            // lblDept
            // 
            this.lblDept.Location = new System.Drawing.Point(3, 12);
            this.lblDept.Visible = false;
            // 
            // cdvDept
            // 
            this.cdvDept.Location = new System.Drawing.Point(3, 7);
            this.cdvDept.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvDept.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvDept.Size = new System.Drawing.Size(10, 26);
            this.cdvDept.TextBoxWidth = 10;
            this.cdvDept.Visible = false;
            // 
            // btnView
            // 
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // pnlStsCond2
            // 
            this.pnlStsCond2.Size = new System.Drawing.Size(1217, 10);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.lblSec);
            this.pnlBottom.Controls.Add(this.numRefreshSec);
            this.pnlBottom.Controls.Add(this.chkAutoRefresh);
            this.pnlBottom.Location = new System.Drawing.Point(0, 618);
            this.pnlBottom.Size = new System.Drawing.Size(1237, 50);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnProcess, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnView, 0);
            this.pnlBottom.Controls.SetChildIndex(this.chkAutoRefresh, 0);
            this.pnlBottom.Controls.SetChildIndex(this.numRefreshSec, 0);
            this.pnlBottom.Controls.SetChildIndex(this.lblSec, 0);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(1237, 618);
            // 
            // pnlTop
            // 
            this.pnlTop.Size = new System.Drawing.Size(1239, 0);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Size = new System.Drawing.Size(1235, 0);
            this.lblFormTitle.Text = "frmTranForm02";
            columnHeaderRenderer2.Name = "columnHeaderRenderer2";
            columnHeaderRenderer2.PictureZoomEffect = false;
            columnHeaderRenderer2.TextRotationAngle = 0D;
            columnHeaderRenderer2.ZoomFactor = 1F;
            rowHeaderRenderer2.Name = "rowHeaderRenderer2";
            rowHeaderRenderer2.PictureZoomEffect = false;
            rowHeaderRenderer2.TextRotationAngle = 0D;
            rowHeaderRenderer2.ZoomFactor = 1F;
            // 
            // spdPackingLotList
            // 
            this.spdPackingLotList.AccessibleDescription = "spdPackingLotList, Sheet1, Row 0, Column 0, SERVER";
            this.spdPackingLotList.BackColor = System.Drawing.Color.Transparent;
            this.spdPackingLotList.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.spdPackingLotList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdPackingLotList.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdPackingLotList.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdPackingLotList.HorizontalScrollBar.Name = "";
            this.spdPackingLotList.HorizontalScrollBar.Renderer = defaultScrollBarRenderer1;
            this.spdPackingLotList.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdPackingLotList.Location = new System.Drawing.Point(10, 98);
            this.spdPackingLotList.Margin = new System.Windows.Forms.Padding(0, 0, 0, 5);
            this.spdPackingLotList.Name = "spdPackingLotList";
            namedStyle1.BackColor = System.Drawing.SystemColors.Control;
            filterBarCellType1.FormatString = "";
            namedStyle1.CellType = filterBarCellType1;
            namedStyle1.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle1.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle1.Locked = false;
            namedStyle1.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle1.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle1.Renderer = filterBarCellType1;
            namedStyle1.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle1.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle2.BackColor = System.Drawing.Color.Aqua;
            namedStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle2.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle2.Locked = false;
            namedStyle2.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle2.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle2.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle2.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle3.BackColor = System.Drawing.SystemColors.Window;
            namedStyle3.CellType = generalCellType1;
            namedStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle3.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            namedStyle3.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle3.Renderer = generalCellType1;
            namedStyle3.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            namedStyle3.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            namedStyle4.Border = bevelBorder1;
            namedStyle4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            namedStyle4.ForeColor = System.Drawing.Color.White;
            namedStyle4.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle4.Locked = false;
            namedStyle4.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle4.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle4.Renderer = generalCellType2;
            namedStyle4.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle4.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle5.BackColor = System.Drawing.SystemColors.Control;
            filterBarCellType2.FormatString = "";
            namedStyle5.CellType = filterBarCellType2;
            namedStyle5.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle5.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle5.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle5.Renderer = filterBarCellType2;
            namedStyle5.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle5.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle6.BackColor = System.Drawing.SystemColors.Control;
            namedStyle6.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle6.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle6.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle6.Renderer = columnHeaderRenderer2;
            namedStyle6.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle6.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle7.BackColor = System.Drawing.SystemColors.Control;
            namedStyle7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            namedStyle7.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle7.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle7.Locked = false;
            namedStyle7.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle7.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle7.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle7.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle8.BackColor = System.Drawing.SystemColors.Control;
            namedStyle8.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle8.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle8.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle8.Renderer = rowHeaderRenderer2;
            namedStyle8.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle8.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle9.BackColor = System.Drawing.Color.White;
            namedStyle9.CellType = generalCellType3;
            namedStyle9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            namedStyle9.ForeColor = System.Drawing.Color.Black;
            namedStyle9.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            namedStyle9.Locked = false;
            namedStyle9.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle9.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle9.Renderer = generalCellType3;
            namedStyle9.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            namedStyle9.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdPackingLotList.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle1,
            namedStyle2,
            namedStyle3,
            namedStyle4,
            namedStyle5,
            namedStyle6,
            namedStyle7,
            namedStyle8,
            namedStyle9});
            this.spdPackingLotList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdPackingLotList_Sheet1});
            this.spdPackingLotList.Size = new System.Drawing.Size(1217, 520);
            spreadSkin1.ColumnFooterDefaultStyle = namedStyle6;
            spreadSkin1.ColumnHeaderDefaultStyle = namedStyle4;
            spreadSkin1.CornerDefaultStyle = namedStyle8;
            spreadSkin1.DefaultStyle = namedStyle9;
            spreadSkin1.FilterBarDefaultStyle = namedStyle5;
            spreadSkin1.FilterBarHeaderDefaultStyle = namedStyle8;
            spreadSkin1.FocusRenderer = defaultFocusIndicatorRenderer1;
            spreadSkin1.Name = "사용1";
            spreadSkin1.RowHeaderDefaultStyle = namedStyle7;
            spreadSkin1.ScrollBarRenderer = defaultScrollBarRenderer2;
            spreadSkin1.SelectionRenderer = new FarPoint.Win.Spread.DefaultSelectionRenderer();
            statusBarSkin1.BackColor = System.Drawing.SystemColors.Control;
            statusBarSkin1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            statusBarSkin1.ForeColor = System.Drawing.SystemColors.ControlText;
            statusBarSkin1.Name = "Classic";
            statusBarSkin1.ZoomButtonHoverColor = System.Drawing.SystemColors.ButtonHighlight;
            statusBarSkin1.ZoomSliderColor = System.Drawing.SystemColors.ControlDarkDark;
            statusBarSkin1.ZoomSliderHoverColor = System.Drawing.SystemColors.ControlDark;
            statusBarSkin1.ZoomSliderTrackColor = System.Drawing.SystemColors.ControlDarkDark;
            spreadSkin1.StatusBarSkin = statusBarSkin1;
            this.spdPackingLotList.Skin = spreadSkin1;
            this.spdPackingLotList.TabIndex = 297;
            this.spdPackingLotList.TabStop = false;
            this.spdPackingLotList.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdPackingLotList.VerticalScrollBar.Name = "";
            this.spdPackingLotList.VerticalScrollBar.Renderer = defaultScrollBarRenderer3;
            this.spdPackingLotList.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            // 
            // spdPackingLotList_Sheet1
            // 
            this.spdPackingLotList_Sheet1.Reset();
            this.spdPackingLotList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdPackingLotList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdPackingLotList_Sheet1.ColumnCount = 12;
            this.spdPackingLotList_Sheet1.RowCount = 75;
            this.spdPackingLotList_Sheet1.Cells.Get(0, 0).Value = "SERVER";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 1).Value = "MC Server";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 2).Value = "X";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 3).Value = "X";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 4).Value = "MC 서버";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 5).Value = "X";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 6).Value = "197.200.1.92";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 7).Value = "X";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 8).Value = "X";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 9).Value = "X";
            this.spdPackingLotList_Sheet1.Cells.Get(0, 10).Value = "X";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 2).Value = "DRY-CIP";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 3).Value = "DRY-CIP";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 4).Value = "HM_DRY-CIP #1";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 5).Value = "E3000015";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 6).Value = "197.200.50.107";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 7).Value = "DRY-CIP.Dev.";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 9).Value = "/IDK1/EAP/E3000015";
            this.spdPackingLotList_Sheet1.Cells.Get(1, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 2).Value = "BALL_MILL";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 3).Value = "PLC_1";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 4).Value = "CTM_볼밀  #1";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 5).Value = "E1000054";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 6).Value = "197.200.52.219";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 7).Value = "BALL.PLC_1.";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 9).Value = "/IDK1/EAP/E1000054";
            this.spdPackingLotList_Sheet1.Cells.Get(2, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 2).Value = "BALL_MILL";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 3).Value = "PLC_2";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 4).Value = "CTM_볼밀  #2";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 5).Value = "E1000055";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 6).Value = "197.200.52.219";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 7).Value = "BALL.PLC_2.";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 9).Value = "/IDK1/EAP/E1000055";
            this.spdPackingLotList_Sheet1.Cells.Get(3, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 2).Value = "BALL_MILL";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 3).Value = "PLC_3";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 4).Value = "CTM_볼밀  #3";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 5).Value = "E1000056";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 6).Value = "197.200.52.219";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 7).Value = "BALL.PLC_3.";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 9).Value = "/IDK1/EAP/E1000056";
            this.spdPackingLotList_Sheet1.Cells.Get(4, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 2).Value = "BALL_MILL";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 3).Value = "PLC_4";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 4).Value = "CTM_볼밀  #4";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 5).Value = "E1000057";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 6).Value = "197.200.52.219";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 7).Value = "BALL.PLC_4.";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 9).Value = "/IDK1/EAP/E1000057";
            this.spdPackingLotList_Sheet1.Cells.Get(5, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 2).Value = "BALL_MILL";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 3).Value = "PLC_5";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 4).Value = "CTM_볼밀  #5";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 5).Value = "E1000058";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 6).Value = "197.200.52.219";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 7).Value = "BALL.PLC_5.";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 9).Value = "/IDK1/EAP/E1000058";
            this.spdPackingLotList_Sheet1.Cells.Get(6, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 1).Value = "ERD_MD_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 2).Value = "ERD_MD";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 3).Value = "EDR01";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 4).Value = "HM_EDR압출기 #1";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 5).Value = "E3000001";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 6).Value = "197.200.50.105";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 7).Value = "E_MD.EDR01.";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 9).Value = "/IDK1/EAP/EMG01";
            this.spdPackingLotList_Sheet1.Cells.Get(7, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 1).Value = "ERD_MD_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 2).Value = "ERD_MD";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 3).Value = "EDR02";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 4).Value = "HM_EDR압출기 #2";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 5).Value = "E3000002";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 6).Value = "197.200.50.106";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 7).Value = "E_MD.EDR02.";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 9).Value = "/IDK1/EAP/EMG01";
            this.spdPackingLotList_Sheet1.Cells.Get(8, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 1).Value = "ERD_MD_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 2).Value = "ERD_MD";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 3).Value = "MD2";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 4).Value = "HM_MD압출기 #2";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 5).Value = "E3000008";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 6).Value = "197.200.50.100";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 7).Value = "E_MD.MD2.";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 9).Value = "/IDK1/EAP/EMG01";
            this.spdPackingLotList_Sheet1.Cells.Get(9, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 1).Value = "ERD_MD_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 2).Value = "ERD_MD";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 3).Value = "MD3";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 4).Value = "HM_MD압출기 #3";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 5).Value = "E3000009";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 6).Value = "197.200.50.101";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 7).Value = "E_MD.MD3.";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 9).Value = "/IDK1/EAP/EMG01";
            this.spdPackingLotList_Sheet1.Cells.Get(10, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 1).Value = "ERD_MD_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 2).Value = "ERD_MD";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 3).Value = "MD4";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 4).Value = "HM_MD압출기 #4";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 5).Value = "E3000010";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 6).Value = "197.200.50.102";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 7).Value = "E_MD.MD4.";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 9).Value = "/IDK1/EAP/EMG01";
            this.spdPackingLotList_Sheet1.Cells.Get(11, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 1).Value = "ERD_MD_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 2).Value = "ERD_MD";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 3).Value = "MD5";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 4).Value = "HM_MD압출기 #5";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 5).Value = "E3000011";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 6).Value = "197.200.50.103";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 7).Value = "E_MD.MD5.";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 9).Value = "/IDK1/EAP/EMG01";
            this.spdPackingLotList_Sheet1.Cells.Get(12, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 1).Value = "ERD_MD_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 2).Value = "ERD_MD";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 3).Value = "MD6";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 4).Value = "HM_MD압출기 #6";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 5).Value = "E3000012";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 6).Value = "197.200.50.104";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 7).Value = "MD_6.Dev.";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 9).Value = "/IDK1/EAP/EMG01";
            this.spdPackingLotList_Sheet1.Cells.Get(13, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 1).Value = "PRESS_PG01";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 3).Value = "PRESS_1";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 4).Value = "CTM_5000Ton Press  #1";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 5).Value = "E1000004";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 6).Value = "197.200.52.211";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 7).Value = "PRESS_1.COOLER_IN.";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 9).Value = "/IDK1/EAP/PRESSG01";
            this.spdPackingLotList_Sheet1.Cells.Get(14, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 3).Value = "PRESS01";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 4).Value = "PRESS01 / E1000001_F";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS01";
            this.spdPackingLotList_Sheet1.Cells.Get(15, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 3).Value = "PRESS_2";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 4).Value = "CTM_5000Ton Press #2";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 5).Value = "E1000005";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 6).Value = "197.200.52.212";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 7).Value = "PRESS_2.COOLER_IN.";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(16, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 3).Value = "PRESS02";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 4).Value = "PRESS02 / E1000002_F";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS02";
            this.spdPackingLotList_Sheet1.Cells.Get(17, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 3).Value = "PRESS_3";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 4).Value = "CTM_5000Ton Press #3";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 5).Value = "E1000006";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 6).Value = "197.200.52.213";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 7).Value = "PRESS_3.COOLER_IN.";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(18, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 3).Value = "PRESS03";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 4).Value = "E1000003_F";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS03";
            this.spdPackingLotList_Sheet1.Cells.Get(19, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 3).Value = "PRESS_4";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 4).Value = "CTM_5000Ton Press  #4";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 5).Value = "E1000007";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 6).Value = "197.200.52.214";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 7).Value = "PRESS_4.COOLER_IN.";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(20, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 3).Value = "PRESS04";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 4).Value = "PRESS04 /E1000004_F";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS04";
            this.spdPackingLotList_Sheet1.Cells.Get(21, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 3).Value = "PRESS_5";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 4).Value = "CTM_5000Ton Press  #5";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 5).Value = "E1000008";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 6).Value = "197.200.52.215";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 7).Value = "PRESS_5.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(22, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 3).Value = "PRESS05 ";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 4).Value = "PRESS05 /E1000005_F";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS05";
            this.spdPackingLotList_Sheet1.Cells.Get(23, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 3).Value = "PRESS_6";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 4).Value = "CTM_5000Ton Press  #6";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 5).Value = "E1000009";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 6).Value = "197.200.52.216";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 7).Value = "PRESS_6.COOLER_IN.";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(24, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 3).Value = "PRESS06 ";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 4).Value = "PRESS06 /E1000006_F";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS06";
            this.spdPackingLotList_Sheet1.Cells.Get(25, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 1).Value = "PRESS_PG01";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 3).Value = "PRESS_7";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 4).Value = "CTM_5000Ton Press  #7";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 5).Value = "E1000010";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 6).Value = "197.200.52.217";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 7).Value = "PRESS_7.COOLER_IN.";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 9).Value = "/IDK1/EAP/PRESSG01";
            this.spdPackingLotList_Sheet1.Cells.Get(26, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 1).Value = "FILE 서버 비가동";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 3).Value = "PRESS07 ";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 4).Value = "E1000007_F";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS07";
            this.spdPackingLotList_Sheet1.Cells.Get(27, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 3).Value = "PRESS_8";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 4).Value = "CTM_5000Ton Press  #8";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 5).Value = "E1000011";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 6).Value = "197.200.52.218";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 7).Value = "PRESS_8.COOLER_IN.";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(28, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 3).Value = " PRESS08";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 4).Value = " PRESS08 /E1000008_F";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS08";
            this.spdPackingLotList_Sheet1.Cells.Get(29, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 3).Value = "PRESS_9";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 4).Value = "Grit_5000Ton Press  #9";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 5).Value = "E3000069";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 6).Value = "197.200.50.110";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 7).Value = "PRESS_9.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(30, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 3).Value = " PRESS09 ";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 4).Value = " PRESS09 /E4000219_F";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS08";
            this.spdPackingLotList_Sheet1.Cells.Get(31, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 1).Value = "PRESS_PG01";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 3).Value = "PRESS_10";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 4).Value = "Grit_5000Ton Press  #10";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 5).Value = "E3000070";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 6).Value = "197.200.50.110";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 7).Value = "PRESS_10.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 9).Value = "/IDK1/EAP/PRESSG01";
            this.spdPackingLotList_Sheet1.Cells.Get(32, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 1).Value = "FILE 서버 비가동";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 3).Value = "PRESS10";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 4).Value = " PRESS10 /E4000220_F";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS10";
            this.spdPackingLotList_Sheet1.Cells.Get(33, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 1).Value = "PRESS_PG01";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 3).Value = "PRESS_11";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 4).Value = "CTM_5000Ton Press  #11";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 5).Value = "E1000012";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 6).Value = "197.200.50.112";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 7).Value = "PRESS_11.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 9).Value = "/IDK1/EAP/PRESSG01";
            this.spdPackingLotList_Sheet1.Cells.Get(34, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 1).Value = "FILE 서버 비가동";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 3).Value = " PRESS11 ";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 4).Value = "E4000220_F";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS11";
            this.spdPackingLotList_Sheet1.Cells.Get(35, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 1).Value = "PRESS_PG01";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 3).Value = "PRESS_12";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 4).Value = "Grit_5000Ton Press  #12";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 5).Value = "E3000071";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 6).Value = "197.200.50.112";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 7).Value = "PRESS_12.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 9).Value = "/IDK1/EAP/PRESSG01";
            this.spdPackingLotList_Sheet1.Cells.Get(36, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 1).Value = "FILE 서버 비가동";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 3).Value = " PRESS12";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 4).Value = "E4000221_F";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS12";
            this.spdPackingLotList_Sheet1.Cells.Get(37, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 3).Value = "PRESS_13";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 4).Value = "Grit_5000Ton Press  #13";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 5).Value = "E3000072";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 6).Value = "197.200.50.114";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 7).Value = "PRESS_13.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 9).Value = "/IDK1/EAP/PRESSG01";
            this.spdPackingLotList_Sheet1.Cells.Get(38, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 3).Value = " PRESS13";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 4).Value = "E4000222_F";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS13";
            this.spdPackingLotList_Sheet1.Cells.Get(39, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 1).Value = "PRESS_PG01";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 3).Value = "PRESS_14";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 4).Value = "Grit_5000Ton Press  #14";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 5).Value = "E3000073";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 6).Value = "197.200.50.114";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 7).Value = "PRESS_14.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(40, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 1).Value = "FILE 서버 비가동";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 3).Value = " PRESS14";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 4).Value = "E4000223_F";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS14";
            this.spdPackingLotList_Sheet1.Cells.Get(41, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 1).Value = "PRESS_PG02";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 3).Value = "PRESS_15";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 4).Value = "Grit_5000Ton Press  #15";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 5).Value = "E3000074";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 6).Value = "197.200.50.116";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 7).Value = "PRESS_15.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 9).Value = "/IDK1/EAP/PRESSG02";
            this.spdPackingLotList_Sheet1.Cells.Get(42, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 1).Value = "설비 ID";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 3).Value = " PRESS15";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 4).Value = "E4000224_F";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS15";
            this.spdPackingLotList_Sheet1.Cells.Get(43, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 1).Value = "PRESS_PG01";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 3).Value = "PRESS_16";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 4).Value = "Grit_5000Ton Press  #16";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 5).Value = "E3000075";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 6).Value = "197.200.50.116";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 7).Value = "PRESS_16.PRESS_TEMP.";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 9).Value = "/IDK1/EAP/PRESSG01";
            this.spdPackingLotList_Sheet1.Cells.Get(44, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 0).Value = "FILE ";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 1).Value = "FILE 서버 비가동";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 2).Value = "PRESS";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 3).Value = " PRESS16";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 4).Value = "E4000225_F";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 6).Value = "197.200.54.18";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 7).Value = "E:\\NexplantMCData\\PressDataFile\\PRESS15";
            this.spdPackingLotList_Sheet1.Cells.Get(45, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 3).Value = "LAPPING_1";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 4).Value = "CTM_Ø600 래핑기  #1";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 5).Value = "E1000092";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 6).Value = "197.200.51.201";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 7).Value = "LAPPING_1.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(46, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 3).Value = "LAPPING_2";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 4).Value = "CTM_Ø600 래핑기  #2";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 5).Value = "E1000093";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 6).Value = "197.200.51.202";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 7).Value = "LAPPING_2.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(47, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 3).Value = "LAPPING_3";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 4).Value = "CTM_Ø600 래핑기  #3";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 5).Value = "E1000094";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 6).Value = "197.200.51.203";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 7).Value = "LAPPING_3.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(48, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 3).Value = "LAPPING_4";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 4).Value = "CTM_Ø600 래핑기  #4";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 5).Value = "E1000095";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 6).Value = "197.200.51.204";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 7).Value = "LAPPING_4.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(49, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 3).Value = "LAPPING_5";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 4).Value = "CTM_Ø600 래핑기  #5";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 5).Value = "E1000096";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 6).Value = "197.200.51.205";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 7).Value = "LAPPING_5.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(50, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 3).Value = "LAPPING_6";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 4).Value = "CTM_Ø600 래핑기  #6";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 5).Value = "E1000097";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 6).Value = "197.200.51.206";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 7).Value = "LAPPING_6.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(51, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 3).Value = "LAPPING_7";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 4).Value = "CTM_Ø600 래핑기  #7";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 5).Value = "E1000098";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 6).Value = "197.200.51.207";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 7).Value = "LAPPING_7.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(52, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 3).Value = "LAPPING_8";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 4).Value = "CTM_Ø600 래핑기  #8";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 5).Value = "E1000099";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 6).Value = "197.200.51.208";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 7).Value = "LAPPING_8.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(53, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 3).Value = "LAPPING_9";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 4).Value = "CTM_Ø600 래핑기  #9";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 5).Value = "E1000100";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 6).Value = "197.200.51.209";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 7).Value = "LAPPING_9.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(54, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 3).Value = "LAPPING_10";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 4).Value = "CTM_Ø600 래핑기  #10";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 5).Value = "E1000101";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 6).Value = "197.200.51.210";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 7).Value = "LAPPING_10.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(55, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 3).Value = "LAPPING_11";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 4).Value = "CTM_Ø600 래핑기  #11";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 5).Value = "E1000102";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 6).Value = "197.200.51.211";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 7).Value = "LAPPING_11.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(56, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 3).Value = "LAPPING_12";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 4).Value = "CTM_Ø600 래핑기  #12";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 5).Value = "E1000103";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 6).Value = "197.200.51.212";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 7).Value = "LAPPING_12.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(57, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 3).Value = "LAPPING_13";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 4).Value = "CTM_Ø600 래핑기  #13";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 5).Value = "E1000104";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 6).Value = "197.200.51.213";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 7).Value = "LAPPING_13.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(58, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 1).Value = "LAPPING_GROUP01";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 3).Value = "LAPPING_14";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 4).Value = "CTM_Ø600 래핑기  #14";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 5).Value = "E1000105";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 6).Value = "197.200.51.214";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 7).Value = "LAPPING_14.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 9).Value = "/IDK1/EAP/LPG01";
            this.spdPackingLotList_Sheet1.Cells.Get(59, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 3).Value = "LAPPING_15";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 4).Value = "CTM_Ø600 래핑기  #15";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 5).Value = "E1000106";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 6).Value = "197.200.51.215";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 7).Value = "LAPPING_15.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(60, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 3).Value = "LAPPING_16";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 4).Value = "CTM_Ø600 래핑기  #16";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 5).Value = "E1000107";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 6).Value = "197.200.51.216";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 7).Value = "LAPPING_16.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(61, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 3).Value = "LAPPING_17";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 4).Value = "CTM_Ø600 래핑기  #17";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 5).Value = "E1000108";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 6).Value = "197.200.51.217";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 7).Value = "LAPPING_17.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(62, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 3).Value = "LAPPING_18";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 4).Value = "CTM_Ø600 래핑기  #18";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 5).Value = "E1000109";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 6).Value = "197.200.51.218";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 7).Value = "LAPPING_18.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(63, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 3).Value = "LAPPING_19";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 4).Value = "CTM_Ø600 래핑기  #19";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 5).Value = "E1000110";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 6).Value = "197.200.51.219";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 7).Value = "LAPPING_19.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(64, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 3).Value = "LAPPING_20";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 4).Value = "CTM_Ø600 래핑기  #20";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 5).Value = "E1000111";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 6).Value = "197.200.51.220";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 7).Value = "LAPPING_20.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(65, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 3).Value = "LAPPING_21";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 4).Value = "CTM_Ø600 래핑기  #21";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 5).Value = "E1000112";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 6).Value = "197.200.51.221";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 7).Value = "LAPPING_21.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(66, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 3).Value = "LAPPING_22";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 4).Value = "CTM_Ø600 래핑기  #22";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 5).Value = "E1000113";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 6).Value = "197.200.51.222";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 7).Value = "LAPPING_22.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(67, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 3).Value = "LAPPING_23";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 4).Value = "CTM_Ø600 래핑기  #23";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 5).Value = "E1000114";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 6).Value = "197.200.51.223";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 7).Value = "LAPPING_23.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(68, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 3).Value = "LAPPING_24";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 4).Value = "CTM_Ø600 래핑기  #24";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 5).Value = "E1000115";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 6).Value = "197.200.51.224";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 7).Value = "LAPPING_24.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(69, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 3).Value = "LAPPING_25";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 4).Value = "CTM_Ø600 래핑기  #25";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 5).Value = "E1000116";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 6).Value = "197.200.51.225";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 7).Value = "LAPPING_25.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(70, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 3).Value = "LAPPING_26";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 4).Value = "CTM_Ø600 래핑기  #26";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 5).Value = "E1000117";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 6).Value = "197.200.51.226";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 7).Value = "LAPPING_26.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(71, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 1).Value = "LAPPING_GROUP02";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 3).Value = "LAPPING_27";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 4).Value = "CTM_Ø600 래핑기  #27";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 5).Value = "E1000118";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 6).Value = "197.200.51.227";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 7).Value = "LAPPING_27.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 9).Value = "/IDK1/EAP/LPG02";
            this.spdPackingLotList_Sheet1.Cells.Get(72, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 1).Value = "LAPPING_GROUP03";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 3).Value = "LAPPING_28";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 4).Value = "CTM_Ø1000 래핑기 #1";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 5).Value = "E1000080";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 6).Value = "197.200.51.228";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 7).Value = "LAPPING_28.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 9).Value = "/IDK1/EAP/LPG03";
            this.spdPackingLotList_Sheet1.Cells.Get(73, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 0).Value = "OPC";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 1).Value = "LAPPING_GROUP03";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 2).Value = "LAPPING";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 3).Value = "LAPPING_29";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 4).Value = "CTM_Ø1000 래핑기  #2";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 5).Value = "E1000081";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 6).Value = "197.200.51.229";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 7).Value = "LAPPING_29.TIMER.";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 8).Value = "197.200.1.92:10101";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 9).Value = "/IDK1/EAP/LPG03";
            this.spdPackingLotList_Sheet1.Cells.Get(74, 10).Value = "/IDK1/EISServer";
            this.spdPackingLotList_Sheet1.ColumnFooter.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdPackingLotList_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdPackingLotList_Sheet1.ColumnFooter.DefaultStyle.Parent = "HeaderDefault";
            this.spdPackingLotList_Sheet1.ColumnFooter.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "MC 타입";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "MC 서버";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "설비타입";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Object명";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "실제 설비명";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 5).Value = "변경설비";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 6).Value = "설비IP";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 7).Value = "OPC 디바이스/TCP PORT";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 8).Value = "사용H101 IP";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 9).Value = "Tune Channel";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 10).Value = "Server Name";
            this.spdPackingLotList_Sheet1.ColumnHeader.Cells.Get(0, 11).Value = "Ping Test";
            this.spdPackingLotList_Sheet1.ColumnHeader.DefaultStyle.Border = bevelBorder5;
            this.spdPackingLotList_Sheet1.ColumnHeader.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdPackingLotList_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdPackingLotList_Sheet1.ColumnHeader.DefaultStyle.Parent = "Style1";
            this.spdPackingLotList_Sheet1.ColumnHeader.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdPackingLotList_Sheet1.ColumnHeader.Rows.Get(0).Height = 25F;
            this.spdPackingLotList_Sheet1.Columns.Get(0).Label = "MC 타입";
            this.spdPackingLotList_Sheet1.Columns.Get(0).Width = 174F;
            this.spdPackingLotList_Sheet1.Columns.Get(1).Label = "MC 서버";
            this.spdPackingLotList_Sheet1.Columns.Get(1).Width = 165F;
            this.spdPackingLotList_Sheet1.Columns.Get(2).Label = "설비타입";
            this.spdPackingLotList_Sheet1.Columns.Get(2).Width = 279F;
            this.spdPackingLotList_Sheet1.Columns.Get(3).Label = "Object명";
            this.spdPackingLotList_Sheet1.Columns.Get(3).Width = 180F;
            this.spdPackingLotList_Sheet1.Columns.Get(4).Label = "실제 설비명";
            this.spdPackingLotList_Sheet1.Columns.Get(4).Width = 129F;
            this.spdPackingLotList_Sheet1.Columns.Get(5).Label = "변경설비";
            this.spdPackingLotList_Sheet1.Columns.Get(5).Width = 106F;
            this.spdPackingLotList_Sheet1.Columns.Get(6).Label = "설비IP";
            this.spdPackingLotList_Sheet1.Columns.Get(6).Width = 97F;
            this.spdPackingLotList_Sheet1.Columns.Get(7).Label = "OPC 디바이스/TCP PORT";
            this.spdPackingLotList_Sheet1.Columns.Get(7).Width = 161F;
            this.spdPackingLotList_Sheet1.Columns.Get(8).Label = "사용H101 IP";
            this.spdPackingLotList_Sheet1.Columns.Get(8).Width = 92F;
            this.spdPackingLotList_Sheet1.Columns.Get(9).Label = "Tune Channel";
            this.spdPackingLotList_Sheet1.Columns.Get(9).Width = 127F;
            this.spdPackingLotList_Sheet1.Columns.Get(10).Label = "Server Name";
            this.spdPackingLotList_Sheet1.Columns.Get(10).Width = 113F;
            this.spdPackingLotList_Sheet1.Columns.Get(11).Label = "Ping Test";
            this.spdPackingLotList_Sheet1.Columns.Get(11).Width = 78F;
            this.spdPackingLotList_Sheet1.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdPackingLotList_Sheet1.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdPackingLotList_Sheet1.DefaultStyle.Parent = "Style2";
            this.spdPackingLotList_Sheet1.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdPackingLotList_Sheet1.EnhancedFilterSortingMode = FarPoint.Win.Spread.EnhancedFilterSortingMode.Text;
            this.spdPackingLotList_Sheet1.FilterBar.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdPackingLotList_Sheet1.FilterBar.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdPackingLotList_Sheet1.FilterBar.DefaultStyle.Parent = "FilterBarDefault";
            this.spdPackingLotList_Sheet1.FilterBar.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdPackingLotList_Sheet1.FilterBarHeaderStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdPackingLotList_Sheet1.FilterBarHeaderStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdPackingLotList_Sheet1.FilterBarHeaderStyle.Parent = "RowHeaderDefault";
            this.spdPackingLotList_Sheet1.FilterBarHeaderStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdPackingLotList_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdPackingLotList_Sheet1.NullBackColor = System.Drawing.Color.White;
            this.spdPackingLotList_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdPackingLotList_Sheet1.RowHeader.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdPackingLotList_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdPackingLotList_Sheet1.RowHeader.DefaultStyle.Parent = "Style3";
            this.spdPackingLotList_Sheet1.RowHeader.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdPackingLotList_Sheet1.RowHeader.Visible = false;
            this.spdPackingLotList_Sheet1.Rows.Default.Height = 30F;
            this.spdPackingLotList_Sheet1.SheetCornerStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdPackingLotList_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdPackingLotList_Sheet1.SheetCornerStyle.Parent = "RowHeaderDefault";
            this.spdPackingLotList_Sheet1.SheetCornerStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdPackingLotList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // lblSec
            // 
            this.lblSec.AutoSize = true;
            this.lblSec.Location = new System.Drawing.Point(195, 19);
            this.lblSec.Name = "lblSec";
            this.lblSec.Size = new System.Drawing.Size(26, 13);
            this.lblSec.TabIndex = 11;
            this.lblSec.Text = "Sec";
            // 
            // numRefreshSec
            // 
            this.numRefreshSec.Increment = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.numRefreshSec.Location = new System.Drawing.Point(117, 15);
            this.numRefreshSec.Maximum = new decimal(new int[] {
            6000,
            0,
            0,
            0});
            this.numRefreshSec.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numRefreshSec.Name = "numRefreshSec";
            this.numRefreshSec.Size = new System.Drawing.Size(78, 20);
            this.numRefreshSec.TabIndex = 10;
            this.numRefreshSec.ThousandsSeparator = true;
            this.numRefreshSec.Value = new decimal(new int[] {
            60,
            0,
            0,
            0});
            // 
            // chkAutoRefresh
            // 
            this.chkAutoRefresh.Checked = true;
            this.chkAutoRefresh.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkAutoRefresh.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.chkAutoRefresh.Location = new System.Drawing.Point(16, 16);
            this.chkAutoRefresh.Name = "chkAutoRefresh";
            this.chkAutoRefresh.Size = new System.Drawing.Size(95, 18);
            this.chkAutoRefresh.TabIndex = 9;
            this.chkAutoRefresh.Text = "Auto Refresh";
            // 
            // tmrTimer
            // 
            this.tmrTimer.Interval = 60000;
            this.tmrTimer.Tick += new System.EventHandler(this.tmrTimer_Tick);
            // 
            // frmTranTestForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1237, 668);
            this.Name = "frmTranTestForm";
            this.Text = "설비 네트워크상태 모니터링";
            this.Load += new System.EventHandler(this.frmTranTestForm_Load);
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).EndInit();
            this.pnlBottom.ResumeLayout(false);
            this.pnlBottom.PerformLayout();
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdPackingLotList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdPackingLotList_Sheet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numRefreshSec)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private FarPoint.Win.Spread.FpSpread spdPackingLotList;
        private FarPoint.Win.Spread.SheetView spdPackingLotList_Sheet1;
        private System.Windows.Forms.Label lblSec;
        private System.Windows.Forms.NumericUpDown numRefreshSec;
        private System.Windows.Forms.CheckBox chkAutoRefresh;
        private System.Windows.Forms.Timer tmrTimer;
    }
}