namespace Miracom.MESCore.Controls
{
    partial class udcAttachFile
    {
        /// <summary> 
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region 구성 요소 디자이너에서 생성한 코드

        /// <summary> 
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer1 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer1 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer2 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer2 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer3 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer3 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer4 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer4 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer5 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer5 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer6 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer6 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer7 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer7 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer1 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle1 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle2 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle3 = new FarPoint.Win.Spread.NamedStyle("CornerDefault");
            FarPoint.Win.Spread.CellType.CornerRenderer cornerRenderer1 = new FarPoint.Win.Spread.CellType.CornerRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle4 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType1 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer2 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.CellType.ButtonCellType buttonCellType1 = new FarPoint.Win.Spread.CellType.ButtonCellType();
            this.pnlAttachTop = new System.Windows.Forms.Panel();
            this.cdvAttachType = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblDocType = new System.Windows.Forms.Label();
            this.txtAttachD = new System.Windows.Forms.TextBox();
            this.btnDel = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.cdvTransType = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblType = new System.Windows.Forms.Label();
            this.pnlAttachBottom = new System.Windows.Forms.Panel();
            this.grpFileAttach = new System.Windows.Forms.GroupBox();
            this.spdFileAttachList = new FarPoint.Win.Spread.FpSpread();
            this.spdFileAttachList_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.folderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
            this.pnlAttachTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvAttachType)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvTransType)).BeginInit();
            this.pnlAttachBottom.SuspendLayout();
            this.grpFileAttach.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdFileAttachList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdFileAttachList_Sheet1)).BeginInit();
            this.SuspendLayout();
            columnHeaderRenderer1.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer1.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer1.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer1.Name = "columnHeaderRenderer1";
            columnHeaderRenderer1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer1.TextRotationAngle = 0D;
            rowHeaderRenderer1.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer1.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer1.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer1.Name = "rowHeaderRenderer1";
            rowHeaderRenderer1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer1.TextRotationAngle = 0D;
            columnHeaderRenderer2.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer2.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer2.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer2.Name = "columnHeaderRenderer2";
            columnHeaderRenderer2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer2.TextRotationAngle = 0D;
            rowHeaderRenderer2.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer2.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer2.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer2.Name = "rowHeaderRenderer2";
            rowHeaderRenderer2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer2.TextRotationAngle = 0D;
            columnHeaderRenderer3.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer3.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer3.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer3.Name = "columnHeaderRenderer3";
            columnHeaderRenderer3.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer3.TextRotationAngle = 0D;
            rowHeaderRenderer3.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer3.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer3.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer3.Name = "rowHeaderRenderer3";
            rowHeaderRenderer3.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer3.TextRotationAngle = 0D;
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
            columnHeaderRenderer5.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer5.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer5.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer5.Name = "columnHeaderRenderer5";
            columnHeaderRenderer5.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer5.TextRotationAngle = 0D;
            rowHeaderRenderer5.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer5.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer5.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer5.Name = "rowHeaderRenderer5";
            rowHeaderRenderer5.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer5.TextRotationAngle = 0D;
            columnHeaderRenderer6.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer6.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer6.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer6.Name = "columnHeaderRenderer6";
            columnHeaderRenderer6.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer6.TextRotationAngle = 0D;
            rowHeaderRenderer6.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer6.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer6.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer6.Name = "rowHeaderRenderer6";
            rowHeaderRenderer6.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer6.TextRotationAngle = 0D;
            columnHeaderRenderer7.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer7.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer7.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer7.Name = "columnHeaderRenderer7";
            columnHeaderRenderer7.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer7.TextRotationAngle = 0D;
            rowHeaderRenderer7.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer7.Font = new System.Drawing.Font("Gulim", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer7.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer7.Name = "rowHeaderRenderer7";
            rowHeaderRenderer7.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer7.TextRotationAngle = 0D;
            // 
            // pnlAttachTop
            // 
            this.pnlAttachTop.Controls.Add(this.cdvAttachType);
            this.pnlAttachTop.Controls.Add(this.lblDocType);
            this.pnlAttachTop.Controls.Add(this.txtAttachD);
            this.pnlAttachTop.Controls.Add(this.btnDel);
            this.pnlAttachTop.Controls.Add(this.btnAdd);
            this.pnlAttachTop.Controls.Add(this.cdvTransType);
            this.pnlAttachTop.Controls.Add(this.lblType);
            this.pnlAttachTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlAttachTop.Location = new System.Drawing.Point(0, 0);
            this.pnlAttachTop.Name = "pnlAttachTop";
            this.pnlAttachTop.Padding = new System.Windows.Forms.Padding(3);
            this.pnlAttachTop.Size = new System.Drawing.Size(600, 31);
            this.pnlAttachTop.TabIndex = 6;
            // 
            // cdvAttachType
            // 
            this.cdvAttachType.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvAttachType.BorderHotColor = System.Drawing.Color.Black;
            this.cdvAttachType.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvAttachType.BtnToolTipText = "";
            this.cdvAttachType.DescText = "";
            this.cdvAttachType.DisplaySubItemIndex = -1;
            this.cdvAttachType.DisplayText = "";
            this.cdvAttachType.Focusing = null;
            this.cdvAttachType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvAttachType.Index = 0;
            this.cdvAttachType.IsViewBtnImage = false;
            this.cdvAttachType.Location = new System.Drawing.Point(249, 4);
            this.cdvAttachType.MaxLength = 10;
            this.cdvAttachType.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvAttachType.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvAttachType.Name = "cdvAttachType";
            this.cdvAttachType.ReadOnly = false;
            this.cdvAttachType.SearchSubItemIndex = 0;
            this.cdvAttachType.SelectedDescIndex = -1;
            this.cdvAttachType.SelectedSubItemIndex = -1;
            this.cdvAttachType.SelectionStart = 0;
            this.cdvAttachType.Size = new System.Drawing.Size(80, 20);
            this.cdvAttachType.SmallImageList = null;
            this.cdvAttachType.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvAttachType.TabIndex = 70;
            this.cdvAttachType.TextBoxToolTipText = "";
            this.cdvAttachType.TextBoxWidth = 80;
            this.cdvAttachType.VisibleButton = true;
            this.cdvAttachType.VisibleColumnHeader = false;
            this.cdvAttachType.VisibleDescription = false;
            this.cdvAttachType.ButtonPress += new System.EventHandler(this.cdvAttachType_ButtonPress);
            // 
            // lblDocType
            // 
            this.lblDocType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDocType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDocType.Location = new System.Drawing.Point(183, 7);
            this.lblDocType.Name = "lblDocType";
            this.lblDocType.Size = new System.Drawing.Size(60, 14);
            this.lblDocType.TabIndex = 71;
            this.lblDocType.Text = "Attach ID";
            this.lblDocType.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtAttachD
            // 
            this.txtAttachD.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtAttachD.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtAttachD.ImeMode = System.Windows.Forms.ImeMode.Disable;
            this.txtAttachD.Location = new System.Drawing.Point(335, 4);
            this.txtAttachD.MaxLength = 30;
            this.txtAttachD.Name = "txtAttachD";
            this.txtAttachD.ReadOnly = true;
            this.txtAttachD.Size = new System.Drawing.Size(100, 21);
            this.txtAttachD.TabIndex = 69;
            // 
            // btnDel
            // 
            this.btnDel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnDel.Location = new System.Drawing.Point(549, 5);
            this.btnDel.Name = "btnDel";
            this.btnDel.Size = new System.Drawing.Size(45, 20);
            this.btnDel.TabIndex = 67;
            this.btnDel.Text = "DEL";
            this.btnDel.UseVisualStyleBackColor = true;
            this.btnDel.Click += new System.EventHandler(this.btnDel_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnAdd.Location = new System.Drawing.Point(500, 5);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(45, 20);
            this.btnAdd.TabIndex = 66;
            this.btnAdd.Text = "ADD";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // cdvTransType
            // 
            this.cdvTransType.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvTransType.BorderHotColor = System.Drawing.Color.Black;
            this.cdvTransType.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvTransType.BtnToolTipText = "";
            this.cdvTransType.DescText = "";
            this.cdvTransType.DisplaySubItemIndex = -1;
            this.cdvTransType.DisplayText = "";
            this.cdvTransType.Focusing = null;
            this.cdvTransType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvTransType.Index = 0;
            this.cdvTransType.IsViewBtnImage = false;
            this.cdvTransType.Location = new System.Drawing.Point(81, 4);
            this.cdvTransType.MaxLength = 10;
            this.cdvTransType.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvTransType.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvTransType.Name = "cdvTransType";
            this.cdvTransType.ReadOnly = false;
            this.cdvTransType.SearchSubItemIndex = 0;
            this.cdvTransType.SelectedDescIndex = -1;
            this.cdvTransType.SelectedSubItemIndex = -1;
            this.cdvTransType.SelectionStart = 0;
            this.cdvTransType.Size = new System.Drawing.Size(80, 20);
            this.cdvTransType.SmallImageList = null;
            this.cdvTransType.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvTransType.TabIndex = 51;
            this.cdvTransType.TextBoxToolTipText = "";
            this.cdvTransType.TextBoxWidth = 80;
            this.cdvTransType.VisibleButton = true;
            this.cdvTransType.VisibleColumnHeader = false;
            this.cdvTransType.VisibleDescription = false;
            this.cdvTransType.ButtonPress += new System.EventHandler(this.cdvTransType_ButtonPress);
            // 
            // lblType
            // 
            this.lblType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblType.Location = new System.Drawing.Point(15, 7);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(60, 14);
            this.lblType.TabIndex = 52;
            this.lblType.Text = "Trans Type";
            this.lblType.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // pnlAttachBottom
            // 
            this.pnlAttachBottom.Controls.Add(this.grpFileAttach);
            this.pnlAttachBottom.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlAttachBottom.Location = new System.Drawing.Point(0, 31);
            this.pnlAttachBottom.Name = "pnlAttachBottom";
            this.pnlAttachBottom.Padding = new System.Windows.Forms.Padding(3);
            this.pnlAttachBottom.Size = new System.Drawing.Size(600, 149);
            this.pnlAttachBottom.TabIndex = 7;
            // 
            // grpFileAttach
            // 
            this.grpFileAttach.Controls.Add(this.spdFileAttachList);
            this.grpFileAttach.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpFileAttach.Location = new System.Drawing.Point(3, 3);
            this.grpFileAttach.Name = "grpFileAttach";
            this.grpFileAttach.Size = new System.Drawing.Size(594, 143);
            this.grpFileAttach.TabIndex = 0;
            this.grpFileAttach.TabStop = false;
            this.grpFileAttach.Text = "File Attatch List";
            // 
            // spdFileAttachList
            // 
            this.spdFileAttachList.AccessibleDescription = "spdFileAttachList, Sheet1, Row 0, Column 0, ";
            this.spdFileAttachList.BackColor = System.Drawing.SystemColors.Control;
            this.spdFileAttachList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdFileAttachList.EditModeReplace = true;
            this.spdFileAttachList.FocusRenderer = defaultFocusIndicatorRenderer1;
            this.spdFileAttachList.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdFileAttachList.HorizontalScrollBar.Name = "";
            this.spdFileAttachList.HorizontalScrollBar.Renderer = defaultScrollBarRenderer1;
            this.spdFileAttachList.HorizontalScrollBar.TabIndex = 62;
            this.spdFileAttachList.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdFileAttachList.Location = new System.Drawing.Point(3, 17);
            this.spdFileAttachList.Name = "spdFileAttachList";
            namedStyle1.BackColor = System.Drawing.SystemColors.Control;
            namedStyle1.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle1.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle1.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle1.Renderer = columnHeaderRenderer7;
            namedStyle1.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle2.BackColor = System.Drawing.SystemColors.Control;
            namedStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle2.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle2.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle2.Renderer = rowHeaderRenderer7;
            namedStyle2.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle3.BackColor = System.Drawing.SystemColors.Control;
            namedStyle3.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle3.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle3.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle3.Renderer = cornerRenderer1;
            namedStyle3.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle4.BackColor = System.Drawing.SystemColors.Window;
            namedStyle4.CellType = generalCellType1;
            namedStyle4.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle4.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle4.Renderer = generalCellType1;
            this.spdFileAttachList.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle1,
            namedStyle2,
            namedStyle3,
            namedStyle4});
            this.spdFileAttachList.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.spdFileAttachList.ScrollBarTrackPolicy = FarPoint.Win.Spread.ScrollBarTrackPolicy.Both;
            this.spdFileAttachList.ScrollTipPolicy = FarPoint.Win.Spread.ScrollTipPolicy.Both;
            this.spdFileAttachList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdFileAttachList_Sheet1});
            this.spdFileAttachList.Size = new System.Drawing.Size(588, 123);
            this.spdFileAttachList.Skin = FarPoint.Win.Spread.DefaultSpreadSkins.Classic;
            this.spdFileAttachList.TabIndex = 3;
            this.spdFileAttachList.TabStop = false;
            this.spdFileAttachList.TextTipDelay = 200;
            this.spdFileAttachList.TextTipPolicy = FarPoint.Win.Spread.TextTipPolicy.Floating;
            this.spdFileAttachList.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdFileAttachList.VerticalScrollBar.Name = "";
            this.spdFileAttachList.VerticalScrollBar.Renderer = defaultScrollBarRenderer2;
            this.spdFileAttachList.VerticalScrollBar.TabIndex = 63;
            this.spdFileAttachList.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdFileAttachList.CellDoubleClick += new FarPoint.Win.Spread.CellClickEventHandler(this.spdFileAttachList_CellDoubleClick);
            this.spdFileAttachList.ButtonClicked += new FarPoint.Win.Spread.EditorNotifyEventHandler(this.spdFileAttachList_ButtonClicked);
            this.spdFileAttachList.SetActiveViewport(0, -1, -1);
            // 
            // spdFileAttachList_Sheet1
            // 
            this.spdFileAttachList_Sheet1.Reset();
            spdFileAttachList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdFileAttachList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            spdFileAttachList_Sheet1.ColumnCount = 4;
            spdFileAttachList_Sheet1.RowCount = 0;
            this.spdFileAttachList_Sheet1.ActiveColumnIndex = -1;
            this.spdFileAttachList_Sheet1.ActiveRowIndex = -1;
            this.spdFileAttachList_Sheet1.AlternatingRows.Get(1).BackColor = System.Drawing.Color.WhiteSmoke;
            this.spdFileAttachList_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdFileAttachList_Sheet1.ColumnFooter.DefaultStyle.Parent = "HeaderDefault";
            this.spdFileAttachList_Sheet1.ColumnFooterSheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdFileAttachList_Sheet1.ColumnFooterSheetCornerStyle.Parent = "CornerDefault";
            this.spdFileAttachList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Type";
            this.spdFileAttachList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "File Name";
            this.spdFileAttachList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Down";
            this.spdFileAttachList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "File Path";
            this.spdFileAttachList_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdFileAttachList_Sheet1.ColumnHeader.DefaultStyle.Parent = "HeaderDefault";
            this.spdFileAttachList_Sheet1.ColumnHeader.Rows.Get(0).Height = 18F;
            this.spdFileAttachList_Sheet1.Columns.Get(0).Label = "Type";
            this.spdFileAttachList_Sheet1.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdFileAttachList_Sheet1.Columns.Get(0).Width = 100F;
            this.spdFileAttachList_Sheet1.Columns.Get(1).Label = "File Name";
            this.spdFileAttachList_Sheet1.Columns.Get(1).Locked = true;
            this.spdFileAttachList_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdFileAttachList_Sheet1.Columns.Get(1).Width = 160F;
            buttonCellType1.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
            buttonCellType1.Text = "Down";
            this.spdFileAttachList_Sheet1.Columns.Get(2).CellType = buttonCellType1;
            this.spdFileAttachList_Sheet1.Columns.Get(2).Label = "Down";
            this.spdFileAttachList_Sheet1.Columns.Get(3).Label = "File Path";
            this.spdFileAttachList_Sheet1.Columns.Get(3).Locked = true;
            this.spdFileAttachList_Sheet1.Columns.Get(3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdFileAttachList_Sheet1.Columns.Get(3).Width = 350F;
            this.spdFileAttachList_Sheet1.GrayAreaBackColor = System.Drawing.Color.White;
            this.spdFileAttachList_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdFileAttachList_Sheet1.RowHeader.Columns.Get(0).Width = 27F;
            this.spdFileAttachList_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdFileAttachList_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefault";
            this.spdFileAttachList_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdFileAttachList_Sheet1.SheetCornerStyle.Parent = "CornerDefault";
            this.spdFileAttachList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // openFileDialog
            // 
            this.openFileDialog.Multiselect = true;
            // 
            // udcAttachFile
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.Controls.Add(this.pnlAttachBottom);
            this.Controls.Add(this.pnlAttachTop);
            this.Name = "udcAttachFile";
            this.Size = new System.Drawing.Size(600, 180);
            this.pnlAttachTop.ResumeLayout(false);
            this.pnlAttachTop.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvAttachType)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvTransType)).EndInit();
            this.pnlAttachBottom.ResumeLayout(false);
            this.grpFileAttach.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdFileAttachList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdFileAttachList_Sheet1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlAttachTop;
        private System.Windows.Forms.Label lblType;
        private System.Windows.Forms.Panel pnlAttachBottom;
        private System.Windows.Forms.GroupBox grpFileAttach;
        private FarPoint.Win.Spread.SheetView spdFileAttachList_Sheet1;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        public FarPoint.Win.Spread.FpSpread spdFileAttachList;
        public System.Windows.Forms.Button btnDel;
        public System.Windows.Forms.Button btnAdd;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvTransType;
        protected System.Windows.Forms.TextBox txtAttachD;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog;
        public UI.Controls.MCCodeView.MCCodeView cdvAttachType;
        private System.Windows.Forms.Label lblDocType;
    }
}
