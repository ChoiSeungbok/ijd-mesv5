namespace Miracom.MESCore.Controls
{
    partial class udcLossCode
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer1 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer2 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.CellType.ButtonCellType buttonCellType1 = new FarPoint.Win.Spread.CellType.ButtonCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType1 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType2 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType3 = new FarPoint.Win.Spread.CellType.NumberCellType();
            this.cdvCode = new Miracom.UI.Controls.MCCodeView.MCSPCodeView();
            this.spdLossList = new FarPoint.Win.Spread.FpSpread();
            this.spdLossList_Sheet1 = new FarPoint.Win.Spread.SheetView();
            ((System.ComponentModel.ISupportInitialize)(this.cdvCode)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLossList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLossList_Sheet1)).BeginInit();
            this.SuspendLayout();
            // 
            // cdvCode
            // 
            this.cdvCode.BackColor = System.Drawing.Color.PaleTurquoise;
            this.cdvCode.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvCode.BorderHotColor = System.Drawing.Color.Black;
            this.cdvCode.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.cdvCode.Location = new System.Drawing.Point(312, 17);
            this.cdvCode.MCViewStyle.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvCode.MCViewStyle.BorderHotColor = System.Drawing.Color.Black;
            this.cdvCode.Name = "cdvGrade";
            this.cdvCode.Size = new System.Drawing.Size(20, 20);
            this.cdvCode.SmallImageList = null;
            this.cdvCode.TabIndex = 0;
            this.cdvCode.TabStop = false;
            this.cdvCode.ViewPosition = new System.Drawing.Point(0, 0);
            this.cdvCode.Visible = false;
            this.cdvCode.VisibleColumnHeader = false;
            this.cdvCode.SelectedItemChanged += new Miracom.UI.MCSSCodeViewSelChangedHandler(this.cdvCode_SelectedItemChanged);
            // 
            // spdLossList
            // 
            this.spdLossList.AccessibleDescription = "spdLossList, Sheet1, Row 0, Column 0, ";
            this.spdLossList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdLossList.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdLossList.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLossList.HorizontalScrollBar.Name = "";
            this.spdLossList.HorizontalScrollBar.Renderer = defaultScrollBarRenderer1;
            this.spdLossList.HorizontalScrollBar.TabIndex = 4;
            this.spdLossList.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdLossList.Location = new System.Drawing.Point(0, 0);
            this.spdLossList.Name = "spdLossList";
            this.spdLossList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdLossList_Sheet1});
            this.spdLossList.Size = new System.Drawing.Size(400, 100);
            this.spdLossList.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdLossList.TabIndex = 3;
            this.spdLossList.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdLossList.VerticalScrollBar.Name = "";
            this.spdLossList.VerticalScrollBar.Renderer = defaultScrollBarRenderer2;
            this.spdLossList.VerticalScrollBar.TabIndex = 3;
            this.spdLossList.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdLossList.EditModeOff += new System.EventHandler(this.spdLossList_EditModeOff);
            this.spdLossList.ButtonClicked += new FarPoint.Win.Spread.EditorNotifyEventHandler(this.spdLossList_ButtonClicked);
            // 
            // spdLossList_Sheet1
            // 
            this.spdLossList_Sheet1.Reset();
            spdLossList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdLossList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            spdLossList_Sheet1.ColumnCount = 6;
            spdLossList_Sheet1.RowCount = 1;
            this.spdLossList_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLossList_Sheet1.ColumnFooter.DefaultStyle.Parent = "HeaderDefault";
            this.spdLossList_Sheet1.ColumnFooterSheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLossList_Sheet1.ColumnFooterSheetCornerStyle.Parent = "CornerDefault";
            this.spdLossList_Sheet1.ColumnHeader.Cells.Get(0, 0).ColumnSpan = 2;
            this.spdLossList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Loss Code";
            this.spdLossList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = " ";
            this.spdLossList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Desc";
            this.spdLossList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "Qty 1";
            this.spdLossList_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "Qty 2";
            this.spdLossList_Sheet1.ColumnHeader.Cells.Get(0, 5).Value = "Qty 3";
            this.spdLossList_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLossList_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdLossList_Sheet1.Columns.Get(0).Label = "Loss Code";
            this.spdLossList_Sheet1.Columns.Get(0).Width = 80F;
            buttonCellType1.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
            this.spdLossList_Sheet1.Columns.Get(1).CellType = buttonCellType1;
            this.spdLossList_Sheet1.Columns.Get(1).Label = " ";
            this.spdLossList_Sheet1.Columns.Get(1).Width = 21F;
            this.spdLossList_Sheet1.Columns.Get(2).Label = "Desc";
            this.spdLossList_Sheet1.Columns.Get(2).Width = 160F;
            this.spdLossList_Sheet1.Columns.Get(3).CellType = numberCellType1;
            this.spdLossList_Sheet1.Columns.Get(3).Label = "Qty 1";
            this.spdLossList_Sheet1.Columns.Get(4).CellType = numberCellType2;
            this.spdLossList_Sheet1.Columns.Get(4).Label = "Qty 2";
            this.spdLossList_Sheet1.Columns.Get(5).CellType = numberCellType3;
            this.spdLossList_Sheet1.Columns.Get(5).Label = "Qty 3";
            this.spdLossList_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdLossList_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdLossList_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLossList_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdLossList_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdLossList_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdLossList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // udcLossCode
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.Controls.Add(this.spdLossList);
            this.Name = "udcLossCode";
            this.Size = new System.Drawing.Size(400, 100);
            this.FontChanged += new System.EventHandler(this.udcLossCode_FontChanged);
            ((System.ComponentModel.ISupportInitialize)(this.cdvCode)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLossList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdLossList_Sheet1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Miracom.UI.Controls.MCCodeView.MCSPCodeView cdvCode;
        private FarPoint.Win.Spread.FpSpread spdLossList;
        private FarPoint.Win.Spread.SheetView spdLossList_Sheet1;
    }
}
