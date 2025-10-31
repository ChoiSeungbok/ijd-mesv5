namespace CUS_WIP
{
    partial class frmTranCreateStartEndTest
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
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer2 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer2 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer1 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle1 = new FarPoint.Win.Spread.NamedStyle("Style4");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType1 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle2 = new FarPoint.Win.Spread.NamedStyle("Style5");
            FarPoint.Win.Spread.NamedStyle namedStyle3 = new FarPoint.Win.Spread.NamedStyle("Style3");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType1 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle4 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType2 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle5 = new FarPoint.Win.Spread.NamedStyle("Style1");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType3 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle6 = new FarPoint.Win.Spread.NamedStyle("FilterBarDefault");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType2 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle7 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle8 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle9 = new FarPoint.Win.Spread.NamedStyle("Style2");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType4 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.SpreadSkin spreadSkin1 = new FarPoint.Win.Spread.SpreadSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer2 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.StatusBarSkin statusBarSkin1 = new FarPoint.Win.Spread.StatusBarSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer3 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.BevelBorder bevelBorder1 = new FarPoint.Win.BevelBorder(FarPoint.Win.BevelBorderType.Lowered);
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType5 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.txtCount = new System.Windows.Forms.TextBox();
            this.btnEnd = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnCreate = new System.Windows.Forms.Button();
            this.spdLotInfo = new FarPoint.Win.Spread.FpSpread();
            this.spdLotInfo_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.btnView = new System.Windows.Forms.Button();
            this.cdvOperation = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.label1 = new System.Windows.Forms.Label();
            this.txtMatid = new System.Windows.Forms.TextBox();
            this.pnlTranTop.SuspendLayout();
            this.pnlTranCenter.SuspendLayout();
            this.grpTranTop.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdLotInfo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLotInfo_Sheet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOperation)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlTranTop
            // 
            this.pnlTranTop.Size = new System.Drawing.Size(734, 62);
            // 
            // pnlTranCenter
            // 
            this.pnlTranCenter.Controls.Add(this.panel1);
            this.pnlTranCenter.Size = new System.Drawing.Size(734, 439);
            // 
            // grpTranTop
            // 
            this.grpTranTop.Controls.Add(this.txtMatid);
            this.grpTranTop.Controls.Add(this.btnView);
            this.grpTranTop.Controls.Add(this.label1);
            this.grpTranTop.Controls.Add(this.cdvOperation);
            this.grpTranTop.Size = new System.Drawing.Size(728, 62);
            // 
            // btnProcess
            // 
            this.btnProcess.Location = new System.Drawing.Point(526, 7);
            this.btnProcess.Visible = false;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(617, 7);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Location = new System.Drawing.Point(0, 501);
            this.pnlBottom.Size = new System.Drawing.Size(734, 40);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(734, 501);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "TranForm02";
            columnHeaderRenderer2.Name = "columnHeaderRenderer2";
            columnHeaderRenderer2.PictureZoomEffect = false;
            columnHeaderRenderer2.TextRotationAngle = 0D;
            columnHeaderRenderer2.ZoomFactor = 1F;
            rowHeaderRenderer2.Name = "rowHeaderRenderer2";
            rowHeaderRenderer2.PictureZoomEffect = false;
            rowHeaderRenderer2.TextRotationAngle = 0D;
            rowHeaderRenderer2.ZoomFactor = 1F;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(3, 3);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(728, 436);
            this.panel1.TabIndex = 1;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.txtCount);
            this.panel2.Controls.Add(this.btnEnd);
            this.panel2.Controls.Add(this.btnStart);
            this.panel2.Controls.Add(this.btnCreate);
            this.panel2.Controls.Add(this.spdLotInfo);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(728, 436);
            this.panel2.TabIndex = 4;
            // 
            // txtCount
            // 
            this.txtCount.Location = new System.Drawing.Point(490, 38);
            this.txtCount.Name = "txtCount";
            this.txtCount.Size = new System.Drawing.Size(47, 20);
            this.txtCount.TabIndex = 7;
            // 
            // btnEnd
            // 
            this.btnEnd.Location = new System.Drawing.Point(409, 93);
            this.btnEnd.Name = "btnEnd";
            this.btnEnd.Size = new System.Drawing.Size(75, 23);
            this.btnEnd.TabIndex = 6;
            this.btnEnd.Text = "End";
            this.btnEnd.UseVisualStyleBackColor = true;
            this.btnEnd.Click += new System.EventHandler(this.btnEnd_Click);
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(409, 64);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(75, 23);
            this.btnStart.TabIndex = 5;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnCreate
            // 
            this.btnCreate.Location = new System.Drawing.Point(409, 35);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(75, 23);
            this.btnCreate.TabIndex = 4;
            this.btnCreate.Text = "Create";
            this.btnCreate.UseVisualStyleBackColor = true;
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // spdLotInfo
            // 
            this.spdLotInfo.AccessibleDescription = "spdMeasureInfo, Sheet1, Row 0, Column 0, ";
            this.spdLotInfo.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.spdLotInfo.Dock = System.Windows.Forms.DockStyle.Left;
            this.spdLotInfo.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdLotInfo.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLotInfo.HorizontalScrollBar.Name = "";
            this.spdLotInfo.HorizontalScrollBar.Renderer = defaultScrollBarRenderer1;
            this.spdLotInfo.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdLotInfo.Location = new System.Drawing.Point(0, 0);
            this.spdLotInfo.Margin = new System.Windows.Forms.Padding(0);
            this.spdLotInfo.Name = "spdLotInfo";
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
            namedStyle3.BackColor = System.Drawing.Color.LightCyan;
            namedStyle3.CellType = generalCellType1;
            namedStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle3.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            namedStyle3.Locked = false;
            namedStyle3.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle3.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle3.Renderer = generalCellType1;
            namedStyle3.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            namedStyle3.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle4.BackColor = System.Drawing.SystemColors.Window;
            namedStyle4.CellType = generalCellType2;
            namedStyle4.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle4.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            namedStyle4.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle4.Renderer = generalCellType2;
            namedStyle4.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            namedStyle4.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(133)))), ((int)(((byte)(219)))));
            namedStyle5.CellType = generalCellType3;
            namedStyle5.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Bold);
            namedStyle5.ForeColor = System.Drawing.SystemColors.Window;
            namedStyle5.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle5.Locked = false;
            namedStyle5.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle5.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle5.Renderer = generalCellType3;
            namedStyle5.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle5.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle6.BackColor = System.Drawing.SystemColors.Control;
            filterBarCellType2.FormatString = "";
            namedStyle6.CellType = filterBarCellType2;
            namedStyle6.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle6.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle6.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle6.Renderer = filterBarCellType2;
            namedStyle6.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle6.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle7.BackColor = System.Drawing.SystemColors.Control;
            namedStyle7.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle7.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle7.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle7.Renderer = columnHeaderRenderer2;
            namedStyle7.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle7.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle8.BackColor = System.Drawing.SystemColors.Control;
            namedStyle8.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle8.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle8.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle8.Renderer = rowHeaderRenderer2;
            namedStyle8.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle8.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle9.BackColor = System.Drawing.SystemColors.Window;
            namedStyle9.CellType = generalCellType4;
            namedStyle9.Font = new System.Drawing.Font("맑은 고딕", 12F);
            namedStyle9.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle9.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            namedStyle9.Locked = false;
            namedStyle9.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle9.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle9.Renderer = generalCellType4;
            namedStyle9.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            namedStyle9.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdLotInfo.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle1,
            namedStyle2,
            namedStyle3,
            namedStyle4,
            namedStyle5,
            namedStyle6,
            namedStyle7,
            namedStyle8,
            namedStyle9});
            this.spdLotInfo.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdLotInfo_Sheet1});
            this.spdLotInfo.Size = new System.Drawing.Size(356, 436);
            spreadSkin1.ColumnFooterDefaultStyle = namedStyle7;
            spreadSkin1.ColumnHeaderDefaultStyle = namedStyle5;
            spreadSkin1.CornerDefaultStyle = namedStyle8;
            spreadSkin1.DefaultStyle = namedStyle9;
            spreadSkin1.FilterBarDefaultStyle = namedStyle6;
            spreadSkin1.FilterBarHeaderDefaultStyle = namedStyle8;
            spreadSkin1.FocusRenderer = defaultFocusIndicatorRenderer1;
            spreadSkin1.Name = "사용1";
            spreadSkin1.RowHeaderDefaultStyle = namedStyle8;
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
            this.spdLotInfo.Skin = spreadSkin1;
            this.spdLotInfo.TabIndex = 3;
            this.spdLotInfo.TabStop = false;
            this.spdLotInfo.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLotInfo.VerticalScrollBar.Name = "";
            this.spdLotInfo.VerticalScrollBar.Renderer = defaultScrollBarRenderer3;
            this.spdLotInfo.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            // 
            // spdLotInfo_Sheet1
            // 
            this.spdLotInfo_Sheet1.Reset();
            this.spdLotInfo_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdLotInfo_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdLotInfo_Sheet1.ColumnCount = 3;
            this.spdLotInfo_Sheet1.RowCount = 0;
            this.spdLotInfo_Sheet1.ActiveColumnIndex = -1;
            this.spdLotInfo_Sheet1.ActiveRowIndex = -1;
            this.spdLotInfo_Sheet1.ColumnFooter.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdLotInfo_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLotInfo_Sheet1.ColumnFooter.DefaultStyle.Parent = "HeaderDefault";
            this.spdLotInfo_Sheet1.ColumnFooter.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdLotInfo_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "순번";
            this.spdLotInfo_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "LOT";
            this.spdLotInfo_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "상태";
            this.spdLotInfo_Sheet1.ColumnHeader.DefaultStyle.Border = bevelBorder1;
            this.spdLotInfo_Sheet1.ColumnHeader.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdLotInfo_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLotInfo_Sheet1.ColumnHeader.DefaultStyle.Parent = "Style1";
            this.spdLotInfo_Sheet1.ColumnHeader.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdLotInfo_Sheet1.ColumnHeader.Rows.Get(0).Height = 30F;
            generalCellType5.ReadOnly = true;
            this.spdLotInfo_Sheet1.Columns.Get(0).CellType = generalCellType5;
            this.spdLotInfo_Sheet1.Columns.Get(0).Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.spdLotInfo_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdLotInfo_Sheet1.Columns.Get(0).Label = "순번";
            this.spdLotInfo_Sheet1.Columns.Get(0).Locked = false;
            this.spdLotInfo_Sheet1.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdLotInfo_Sheet1.Columns.Get(0).Width = 55F;
            this.spdLotInfo_Sheet1.Columns.Get(1).Font = new System.Drawing.Font("맑은 고딕", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.spdLotInfo_Sheet1.Columns.Get(1).Label = "LOT";
            this.spdLotInfo_Sheet1.Columns.Get(1).Locked = false;
            this.spdLotInfo_Sheet1.Columns.Get(1).Width = 120F;
            this.spdLotInfo_Sheet1.Columns.Get(2).Label = "상태";
            this.spdLotInfo_Sheet1.Columns.Get(2).Width = 61F;
            this.spdLotInfo_Sheet1.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdLotInfo_Sheet1.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLotInfo_Sheet1.DefaultStyle.Parent = "Style2";
            this.spdLotInfo_Sheet1.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdLotInfo_Sheet1.EnhancedFilterSortingMode = FarPoint.Win.Spread.EnhancedFilterSortingMode.Text;
            this.spdLotInfo_Sheet1.FilterBar.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdLotInfo_Sheet1.FilterBar.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLotInfo_Sheet1.FilterBar.DefaultStyle.Parent = "FilterBarDefault";
            this.spdLotInfo_Sheet1.FilterBar.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdLotInfo_Sheet1.FilterBarHeaderStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdLotInfo_Sheet1.FilterBarHeaderStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLotInfo_Sheet1.FilterBarHeaderStyle.Parent = "RowHeaderDefault";
            this.spdLotInfo_Sheet1.FilterBarHeaderStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdLotInfo_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdLotInfo_Sheet1.NullBackColor = System.Drawing.Color.White;
            this.spdLotInfo_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdLotInfo_Sheet1.RowHeader.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdLotInfo_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLotInfo_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdLotInfo_Sheet1.RowHeader.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdLotInfo_Sheet1.RowHeader.Visible = false;
            this.spdLotInfo_Sheet1.Rows.Default.Height = 30F;
            this.spdLotInfo_Sheet1.SheetCornerStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdLotInfo_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLotInfo_Sheet1.SheetCornerStyle.Parent = "RowHeaderDefault";
            this.spdLotInfo_Sheet1.SheetCornerStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdLotInfo_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(187, 19);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(75, 23);
            this.btnView.TabIndex = 8;
            this.btnView.Text = "View";
            this.btnView.UseVisualStyleBackColor = true;
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // cdvOperation
            // 
            this.cdvOperation.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvOperation.BorderHotColor = System.Drawing.Color.Black;
            this.cdvOperation.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvOperation.BtnToolTipText = "";
            this.cdvOperation.ButtonWidth = 20;
            this.cdvOperation.DescText = "";
            this.cdvOperation.DisplaySubItemIndex = -1;
            this.cdvOperation.DisplayText = "";
            this.cdvOperation.Focusing = null;
            this.cdvOperation.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvOperation.Index = 0;
            this.cdvOperation.IsViewBtnImage = false;
            this.cdvOperation.Location = new System.Drawing.Point(63, 21);
            this.cdvOperation.MaxLength = 10;
            this.cdvOperation.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOperation.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvOperation.MultiSelect = false;
            this.cdvOperation.Name = "cdvOperation";
            this.cdvOperation.ReadOnly = false;
            this.cdvOperation.SameWidthHeightOfButton = false;
            this.cdvOperation.SearchSubItemIndex = 0;
            this.cdvOperation.SelectedDescIndex = -1;
            this.cdvOperation.SelectedDescToQueryText = "";
            this.cdvOperation.SelectedSubItemIndex = -1;
            this.cdvOperation.SelectedValueToQueryText = "";
            this.cdvOperation.SelectionStart = 0;
            this.cdvOperation.Size = new System.Drawing.Size(102, 20);
            this.cdvOperation.SmallImageList = null;
            this.cdvOperation.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvOperation.TabIndex = 3;
            this.cdvOperation.TextBoxToolTipText = "";
            this.cdvOperation.TextBoxWidth = 102;
            this.cdvOperation.VisibleButton = true;
            this.cdvOperation.VisibleColumnHeader = false;
            this.cdvOperation.VisibleDescription = false;
            this.cdvOperation.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvOperation_SelectedItemChanged);
            this.cdvOperation.ButtonPress += new System.EventHandler(this.cdvOperation_ButtonPress);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(22, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(30, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Oper";
            // 
            // txtMatid
            // 
            this.txtMatid.Location = new System.Drawing.Point(309, 21);
            this.txtMatid.Name = "txtMatid";
            this.txtMatid.ReadOnly = true;
            this.txtMatid.Size = new System.Drawing.Size(70, 20);
            this.txtMatid.TabIndex = 8;
            this.txtMatid.Text = "TDIA001";
            // 
            // frmTranCreateStartEndTest
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(734, 541);
            this.Name = "frmTranCreateStartEndTest";
            this.Text = "frmTranCreateStartEndTest";
            this.Load += new System.EventHandler(this.frmTranCreateStartEndTest_Load);
            this.pnlTranTop.ResumeLayout(false);
            this.pnlTranCenter.ResumeLayout(false);
            this.grpTranTop.ResumeLayout(false);
            this.grpTranTop.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdLotInfo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLotInfo_Sheet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOperation)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private FarPoint.Win.Spread.FpSpread spdLotInfo;
        private FarPoint.Win.Spread.SheetView spdLotInfo_Sheet1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.TextBox txtCount;
        private System.Windows.Forms.Button btnEnd;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnCreate;
        private System.Windows.Forms.Button btnView;
        private System.Windows.Forms.Label label1;
        private Miracom.UI.Controls.MCCodeView.MCCodeView cdvOperation;
        private System.Windows.Forms.TextBox txtMatid;
    }
}