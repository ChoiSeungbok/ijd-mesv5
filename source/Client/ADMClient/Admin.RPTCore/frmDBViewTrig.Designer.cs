namespace Admin.RPTCore
{
    partial class frmDBViewTrig
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
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

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlGenInfo = new System.Windows.Forms.Panel();
            this.grpGenInfo = new System.Windows.Forms.GroupBox();
            this.txtViewName = new System.Windows.Forms.TextBox();
            this.txtViewPrefix = new System.Windows.Forms.TextBox();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.txtLogTable = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.btnExecute = new System.Windows.Forms.Button();
            this.btnCodeGen = new System.Windows.Forms.Button();
            this.lblInterval = new System.Windows.Forms.Label();
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.grbCenter = new System.Windows.Forms.GroupBox();
            this.tabColumns = new System.Windows.Forms.TabControl();
            this.pageConnect = new System.Windows.Forms.TabPage();
            this.btnExit = new System.Windows.Forms.Button();
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.btnConnect = new System.Windows.Forms.Button();
            this.GroupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.txtDBLink = new System.Windows.Forms.TextBox();
            this.Label8 = new System.Windows.Forms.Label();
            this.txtPrefix = new System.Windows.Forms.TextBox();
            this.Label9 = new System.Windows.Forms.Label();
            this.txtViewTablespace = new System.Windows.Forms.TextBox();
            this.Label2 = new System.Windows.Forms.Label();
            this.txtTarDataSource = new System.Windows.Forms.TextBox();
            this.Label4 = new System.Windows.Forms.Label();
            this.GroupBox2 = new System.Windows.Forms.GroupBox();
            this.rdoTarDB2 = new System.Windows.Forms.RadioButton();
            this.rdoTarOracle = new System.Windows.Forms.RadioButton();
            this.rdoTarMsSql = new System.Windows.Forms.RadioButton();
            this.Label5 = new System.Windows.Forms.Label();
            this.Label6 = new System.Windows.Forms.Label();
            this.Label7 = new System.Windows.Forms.Label();
            this.txtTarDBName = new System.Windows.Forms.TextBox();
            this.txtTarUserID = new System.Windows.Forms.TextBox();
            this.txtTarPassword = new System.Windows.Forms.TextBox();
            this.grbConnect = new System.Windows.Forms.GroupBox();
            this.txtLogTablespace = new System.Windows.Forms.TextBox();
            this.Label1 = new System.Windows.Forms.Label();
            this.txtSrcDataSource = new System.Windows.Forms.TextBox();
            this.lblDataSource = new System.Windows.Forms.Label();
            this.grbDBType = new System.Windows.Forms.GroupBox();
            this.rdoSrcDB2 = new System.Windows.Forms.RadioButton();
            this.rdoSrcOracle = new System.Windows.Forms.RadioButton();
            this.rdoSrcMsSql = new System.Windows.Forms.RadioButton();
            this.lblPassword = new System.Windows.Forms.Label();
            this.lblUserID = new System.Windows.Forms.Label();
            this.lblDBName = new System.Windows.Forms.Label();
            this.txtSrcDBName = new System.Windows.Forms.TextBox();
            this.txtSrcUserID = new System.Windows.Forms.TextBox();
            this.txtSrcPassword = new System.Windows.Forms.TextBox();
            this.pageColList = new System.Windows.Forms.TabPage();
            this.label12 = new System.Windows.Forms.Label();
            this.txtWhere = new System.Windows.Forms.TextBox();
            this.spdViewCol = new FarPoint.Win.Spread.FpSpread();
            this.spdViewCol_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.pageCode = new System.Windows.Forms.TabPage();
            this.pnlCodeFill = new System.Windows.Forms.Panel();
            this.pnlScript = new System.Windows.Forms.Panel();
            this.txtScript = new System.Windows.Forms.RichTextBox();
            this.pnlGap2 = new System.Windows.Forms.Panel();
            this.pnlSQLSave = new System.Windows.Forms.Panel();
            this.grbSave = new System.Windows.Forms.GroupBox();
            this.btnSave = new System.Windows.Forms.Button();
            this.txtFileName = new System.Windows.Forms.TextBox();
            this.lblFileName = new System.Windows.Forms.Label();
            this.pnlSQLSaveRight = new System.Windows.Forms.Panel();
            this.pnlSQLSaveLeft = new System.Windows.Forms.Panel();
            this.pnlSQLSaveBottom = new System.Windows.Forms.Panel();
            this.pnlSQLSaveTop = new System.Windows.Forms.Panel();
            this.colNo = new System.Windows.Forms.ColumnHeader();
            this.colFieldName = new System.Windows.Forms.ColumnHeader();
            this.colPK = new System.Windows.Forms.ColumnHeader();
            this.colNumericScale = new System.Windows.Forms.ColumnHeader();
            this.colDataType = new System.Windows.Forms.ColumnHeader();
            this.colSize = new System.Windows.Forms.ColumnHeader();
            this.colNull = new System.Windows.Forms.ColumnHeader();
            this.rbView = new System.Windows.Forms.RadioButton();
            this.splMain = new System.Windows.Forms.Splitter();
            this.rbTable = new System.Windows.Forms.RadioButton();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.gbColumnList = new System.Windows.Forms.GroupBox();
            this.spdColList = new FarPoint.Win.Spread.FpSpread();
            this.spdColList_Sheet1 = new FarPoint.Win.Spread.SheetView();
            this.grbTableList = new System.Windows.Forms.GroupBox();
            this.grpColumnList = new System.Windows.Forms.GroupBox();
            this.listView1 = new System.Windows.Forms.ListView();
            this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.lisTable = new System.Windows.Forms.ListView();
            this.ColumnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.pnlViewType = new System.Windows.Forms.Panel();
            this.grpDBViewType = new System.Windows.Forms.GroupBox();
            this.pnlTop = new System.Windows.Forms.Panel();
            this.colPrecision = new System.Windows.Forms.ColumnHeader();
            this.pnlGenInfo.SuspendLayout();
            this.grpGenInfo.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.grbCenter.SuspendLayout();
            this.tabColumns.SuspendLayout();
            this.pageConnect.SuspendLayout();
            this.GroupBox1.SuspendLayout();
            this.GroupBox2.SuspendLayout();
            this.grbConnect.SuspendLayout();
            this.grbDBType.SuspendLayout();
            this.pageColList.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdViewCol)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdViewCol_Sheet1)).BeginInit();
            this.pageCode.SuspendLayout();
            this.pnlCodeFill.SuspendLayout();
            this.pnlScript.SuspendLayout();
            this.pnlSQLSave.SuspendLayout();
            this.grbSave.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.gbColumnList.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdColList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdColList_Sheet1)).BeginInit();
            this.grbTableList.SuspendLayout();
            this.grpColumnList.SuspendLayout();
            this.pnlViewType.SuspendLayout();
            this.grpDBViewType.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlGenInfo
            // 
            this.pnlGenInfo.Controls.Add(this.grpGenInfo);
            this.pnlGenInfo.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlGenInfo.Location = new System.Drawing.Point(0, 462);
            this.pnlGenInfo.Name = "pnlGenInfo";
            this.pnlGenInfo.Size = new System.Drawing.Size(594, 77);
            this.pnlGenInfo.TabIndex = 1;
            // 
            // grpGenInfo
            // 
            this.grpGenInfo.Controls.Add(this.txtViewName);
            this.grpGenInfo.Controls.Add(this.txtViewPrefix);
            this.grpGenInfo.Controls.Add(this.btnDelete);
            this.grpGenInfo.Controls.Add(this.btnClose);
            this.grpGenInfo.Controls.Add(this.txtLogTable);
            this.grpGenInfo.Controls.Add(this.label3);
            this.grpGenInfo.Controls.Add(this.btnExecute);
            this.grpGenInfo.Controls.Add(this.btnCodeGen);
            this.grpGenInfo.Controls.Add(this.lblInterval);
            this.grpGenInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpGenInfo.Location = new System.Drawing.Point(0, 0);
            this.grpGenInfo.Name = "grpGenInfo";
            this.grpGenInfo.Size = new System.Drawing.Size(594, 77);
            this.grpGenInfo.TabIndex = 9;
            this.grpGenInfo.TabStop = false;
            // 
            // txtViewName
            // 
            this.txtViewName.Location = new System.Drawing.Point(109, 13);
            this.txtViewName.Name = "txtViewName";
            this.txtViewName.Size = new System.Drawing.Size(157, 20);
            this.txtViewName.TabIndex = 4;
            // 
            // txtViewPrefix
            // 
            this.txtViewPrefix.Enabled = false;
            this.txtViewPrefix.Location = new System.Drawing.Point(78, 13);
            this.txtViewPrefix.Name = "txtViewPrefix";
            this.txtViewPrefix.Size = new System.Drawing.Size(34, 20);
            this.txtViewPrefix.TabIndex = 9;
            this.txtViewPrefix.Text = "MPL_";
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(445, 47);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(70, 24);
            this.btnDelete.TabIndex = 8;
            this.btnDelete.Text = "Delete";
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(521, 47);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(70, 24);
            this.btnClose.TabIndex = 7;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // txtLogTable
            // 
            this.txtLogTable.Location = new System.Drawing.Point(103, 45);
            this.txtLogTable.Name = "txtLogTable";
            this.txtLogTable.Size = new System.Drawing.Size(163, 20);
            this.txtLogTable.TabIndex = 6;
            this.txtLogTable.Text = "MPPDB_LOG_DATA";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(11, 49);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(86, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Log Table Name";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnExecute
            // 
            this.btnExecute.Location = new System.Drawing.Point(369, 47);
            this.btnExecute.Name = "btnExecute";
            this.btnExecute.Size = new System.Drawing.Size(70, 24);
            this.btnExecute.TabIndex = 3;
            this.btnExecute.Text = "Execute";
            this.btnExecute.Click += new System.EventHandler(this.btnExecute_Click);
            // 
            // btnCodeGen
            // 
            this.btnCodeGen.Location = new System.Drawing.Point(293, 47);
            this.btnCodeGen.Name = "btnCodeGen";
            this.btnCodeGen.Size = new System.Drawing.Size(70, 24);
            this.btnCodeGen.TabIndex = 3;
            this.btnCodeGen.Text = "Generate";
            this.btnCodeGen.Click += new System.EventHandler(this.btnCodeGen_Click);
            // 
            // lblInterval
            // 
            this.lblInterval.AutoSize = true;
            this.lblInterval.Location = new System.Drawing.Point(11, 16);
            this.lblInterval.Name = "lblInterval";
            this.lblInterval.Size = new System.Drawing.Size(61, 13);
            this.lblInterval.TabIndex = 2;
            this.lblInterval.Text = "View Name";
            this.lblInterval.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.grbCenter);
            this.pnlCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenter.Location = new System.Drawing.Point(265, 8);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Padding = new System.Windows.Forms.Padding(0, 0, 5, 5);
            this.pnlCenter.Size = new System.Drawing.Size(613, 591);
            this.pnlCenter.TabIndex = 27;
            // 
            // grbCenter
            // 
            this.grbCenter.Controls.Add(this.tabColumns);
            this.grbCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grbCenter.Location = new System.Drawing.Point(0, 0);
            this.grbCenter.Name = "grbCenter";
            this.grbCenter.Size = new System.Drawing.Size(608, 586);
            this.grbCenter.TabIndex = 0;
            this.grbCenter.TabStop = false;
            // 
            // tabColumns
            // 
            this.tabColumns.Appearance = System.Windows.Forms.TabAppearance.FlatButtons;
            this.tabColumns.Controls.Add(this.pageConnect);
            this.tabColumns.Controls.Add(this.pageColList);
            this.tabColumns.Controls.Add(this.pageCode);
            this.tabColumns.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabColumns.HotTrack = true;
            this.tabColumns.ItemSize = new System.Drawing.Size(100, 20);
            this.tabColumns.Location = new System.Drawing.Point(3, 16);
            this.tabColumns.Name = "tabColumns";
            this.tabColumns.SelectedIndex = 0;
            this.tabColumns.Size = new System.Drawing.Size(602, 567);
            this.tabColumns.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabColumns.TabIndex = 0;
            this.tabColumns.SelectedIndexChanged += new System.EventHandler(this.tabColumns_SelectedIndexChanged);
            // 
            // pageConnect
            // 
            this.pageConnect.Controls.Add(this.btnExit);
            this.pageConnect.Controls.Add(this.btnDisconnect);
            this.pageConnect.Controls.Add(this.btnConnect);
            this.pageConnect.Controls.Add(this.GroupBox1);
            this.pageConnect.Controls.Add(this.grbConnect);
            this.pageConnect.Location = new System.Drawing.Point(4, 24);
            this.pageConnect.Name = "pageConnect";
            this.pageConnect.Size = new System.Drawing.Size(594, 539);
            this.pageConnect.TabIndex = 2;
            this.pageConnect.Text = "Connect";
            this.pageConnect.UseVisualStyleBackColor = true;
            // 
            // btnExit
            // 
            this.btnExit.ForeColor = System.Drawing.Color.Red;
            this.btnExit.Location = new System.Drawing.Point(403, 512);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(88, 24);
            this.btnExit.TabIndex = 15;
            this.btnExit.Text = "Exit";
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Location = new System.Drawing.Point(256, 512);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(88, 24);
            this.btnDisconnect.TabIndex = 14;
            this.btnDisconnect.Text = "Disconnect";
            this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(109, 512);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(88, 24);
            this.btnConnect.TabIndex = 13;
            this.btnConnect.Text = "Connect";
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // GroupBox1
            // 
            this.GroupBox1.Controls.Add(this.textBox2);
            this.GroupBox1.Controls.Add(this.label11);
            this.GroupBox1.Controls.Add(this.textBox1);
            this.GroupBox1.Controls.Add(this.label10);
            this.GroupBox1.Controls.Add(this.txtDBLink);
            this.GroupBox1.Controls.Add(this.Label8);
            this.GroupBox1.Controls.Add(this.txtPrefix);
            this.GroupBox1.Controls.Add(this.Label9);
            this.GroupBox1.Controls.Add(this.txtViewTablespace);
            this.GroupBox1.Controls.Add(this.Label2);
            this.GroupBox1.Controls.Add(this.txtTarDataSource);
            this.GroupBox1.Controls.Add(this.Label4);
            this.GroupBox1.Controls.Add(this.GroupBox2);
            this.GroupBox1.Controls.Add(this.Label5);
            this.GroupBox1.Controls.Add(this.Label6);
            this.GroupBox1.Controls.Add(this.Label7);
            this.GroupBox1.Controls.Add(this.txtTarDBName);
            this.GroupBox1.Controls.Add(this.txtTarUserID);
            this.GroupBox1.Controls.Add(this.txtTarPassword);
            this.GroupBox1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.GroupBox1.Location = new System.Drawing.Point(1, 17);
            this.GroupBox1.Name = "GroupBox1";
            this.GroupBox1.Size = new System.Drawing.Size(292, 479);
            this.GroupBox1.TabIndex = 1;
            this.GroupBox1.TabStop = false;
            this.GroupBox1.Text = "DB";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(25, 392);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(246, 20);
            this.textBox2.TabIndex = 16;
            this.textBox2.Visible = false;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(23, 370);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(89, 13);
            this.label11.TabIndex = 15;
            this.label11.Text = "View Tablespace";
            this.label11.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label11.Visible = false;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(25, 335);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(246, 20);
            this.textBox1.TabIndex = 14;
            this.textBox1.Visible = false;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(23, 313);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(89, 13);
            this.label10.TabIndex = 13;
            this.label10.Text = "View Tablespace";
            this.label10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label10.Visible = false;
            // 
            // txtDBLink
            // 
            this.txtDBLink.Location = new System.Drawing.Point(26, 225);
            this.txtDBLink.Name = "txtDBLink";
            this.txtDBLink.Size = new System.Drawing.Size(246, 20);
            this.txtDBLink.TabIndex = 10;
            this.txtDBLink.Visible = false;
            // 
            // Label8
            // 
            this.Label8.AutoSize = true;
            this.Label8.Location = new System.Drawing.Point(24, 203);
            this.Label8.Name = "Label8";
            this.Label8.Size = new System.Drawing.Size(45, 13);
            this.Label8.TabIndex = 9;
            this.Label8.Text = "DB Link";
            this.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.Label8.Visible = false;
            // 
            // txtPrefix
            // 
            this.txtPrefix.Location = new System.Drawing.Point(25, 447);
            this.txtPrefix.MaxLength = 4;
            this.txtPrefix.Name = "txtPrefix";
            this.txtPrefix.Size = new System.Drawing.Size(246, 20);
            this.txtPrefix.TabIndex = 12;
            this.txtPrefix.Text = "MV_";
            this.txtPrefix.Visible = false;
            // 
            // Label9
            // 
            this.Label9.AutoSize = true;
            this.Label9.Location = new System.Drawing.Point(23, 425);
            this.Label9.Name = "Label9";
            this.Label9.Size = new System.Drawing.Size(63, 13);
            this.Label9.TabIndex = 9;
            this.Label9.Text = "Table Prefix";
            this.Label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.Label9.Visible = false;
            // 
            // txtViewTablespace
            // 
            this.txtViewTablespace.Location = new System.Drawing.Point(25, 279);
            this.txtViewTablespace.Name = "txtViewTablespace";
            this.txtViewTablespace.Size = new System.Drawing.Size(246, 20);
            this.txtViewTablespace.TabIndex = 11;
            this.txtViewTablespace.Visible = false;
            // 
            // Label2
            // 
            this.Label2.AutoSize = true;
            this.Label2.Location = new System.Drawing.Point(23, 257);
            this.Label2.Name = "Label2";
            this.Label2.Size = new System.Drawing.Size(89, 13);
            this.Label2.TabIndex = 9;
            this.Label2.Text = "View Tablespace";
            this.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.Label2.Visible = false;
            // 
            // txtTarDataSource
            // 
            this.txtTarDataSource.Enabled = false;
            this.txtTarDataSource.Location = new System.Drawing.Point(128, 72);
            this.txtTarDataSource.Name = "txtTarDataSource";
            this.txtTarDataSource.Size = new System.Drawing.Size(144, 20);
            this.txtTarDataSource.TabIndex = 1;
            // 
            // Label4
            // 
            this.Label4.AutoSize = true;
            this.Label4.Enabled = false;
            this.Label4.Location = new System.Drawing.Point(24, 72);
            this.Label4.Name = "Label4";
            this.Label4.Size = new System.Drawing.Size(67, 13);
            this.Label4.TabIndex = 0;
            this.Label4.Text = "Data Source";
            this.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // GroupBox2
            // 
            this.GroupBox2.Controls.Add(this.rdoTarDB2);
            this.GroupBox2.Controls.Add(this.rdoTarOracle);
            this.GroupBox2.Controls.Add(this.rdoTarMsSql);
            this.GroupBox2.Location = new System.Drawing.Point(8, 16);
            this.GroupBox2.Name = "GroupBox2";
            this.GroupBox2.Size = new System.Drawing.Size(275, 48);
            this.GroupBox2.TabIndex = 17;
            this.GroupBox2.TabStop = false;
            this.GroupBox2.Text = "DB Type";
            // 
            // rdoTarDB2
            // 
            this.rdoTarDB2.Enabled = false;
            this.rdoTarDB2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdoTarDB2.Location = new System.Drawing.Point(205, 18);
            this.rdoTarDB2.Name = "rdoTarDB2";
            this.rdoTarDB2.Size = new System.Drawing.Size(56, 24);
            this.rdoTarDB2.TabIndex = 2;
            this.rdoTarDB2.Text = "DB2";
            // 
            // rdoTarOracle
            // 
            this.rdoTarOracle.Checked = true;
            this.rdoTarOracle.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdoTarOracle.Location = new System.Drawing.Point(117, 18);
            this.rdoTarOracle.Name = "rdoTarOracle";
            this.rdoTarOracle.Size = new System.Drawing.Size(64, 24);
            this.rdoTarOracle.TabIndex = 17;
            this.rdoTarOracle.TabStop = true;
            this.rdoTarOracle.Text = "Oracle";
            // 
            // rdoTarMsSql
            // 
            this.rdoTarMsSql.Enabled = false;
            this.rdoTarMsSql.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdoTarMsSql.Location = new System.Drawing.Point(21, 18);
            this.rdoTarMsSql.Name = "rdoTarMsSql";
            this.rdoTarMsSql.Size = new System.Drawing.Size(72, 24);
            this.rdoTarMsSql.TabIndex = 0;
            this.rdoTarMsSql.Text = "MS SQL";
            // 
            // Label5
            // 
            this.Label5.AutoSize = true;
            this.Label5.Location = new System.Drawing.Point(24, 168);
            this.Label5.Name = "Label5";
            this.Label5.Size = new System.Drawing.Size(53, 13);
            this.Label5.TabIndex = 6;
            this.Label5.Text = "Password";
            this.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Label6
            // 
            this.Label6.AutoSize = true;
            this.Label6.Location = new System.Drawing.Point(24, 136);
            this.Label6.Name = "Label6";
            this.Label6.Size = new System.Drawing.Size(43, 13);
            this.Label6.TabIndex = 4;
            this.Label6.Text = "User ID";
            this.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Label7
            // 
            this.Label7.AutoSize = true;
            this.Label7.Location = new System.Drawing.Point(24, 104);
            this.Label7.Name = "Label7";
            this.Label7.Size = new System.Drawing.Size(53, 13);
            this.Label7.TabIndex = 2;
            this.Label7.Text = "DB Name";
            this.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtTarDBName
            // 
            this.txtTarDBName.Location = new System.Drawing.Point(128, 104);
            this.txtTarDBName.Name = "txtTarDBName";
            this.txtTarDBName.Size = new System.Drawing.Size(144, 20);
            this.txtTarDBName.TabIndex = 7;
            // 
            // txtTarUserID
            // 
            this.txtTarUserID.Location = new System.Drawing.Point(128, 136);
            this.txtTarUserID.Name = "txtTarUserID";
            this.txtTarUserID.Size = new System.Drawing.Size(144, 20);
            this.txtTarUserID.TabIndex = 8;
            // 
            // txtTarPassword
            // 
            this.txtTarPassword.Location = new System.Drawing.Point(128, 168);
            this.txtTarPassword.Name = "txtTarPassword";
            this.txtTarPassword.PasswordChar = '*';
            this.txtTarPassword.Size = new System.Drawing.Size(144, 20);
            this.txtTarPassword.TabIndex = 9;
            // 
            // grbConnect
            // 
            this.grbConnect.Controls.Add(this.txtLogTablespace);
            this.grbConnect.Controls.Add(this.Label1);
            this.grbConnect.Controls.Add(this.txtSrcDataSource);
            this.grbConnect.Controls.Add(this.lblDataSource);
            this.grbConnect.Controls.Add(this.grbDBType);
            this.grbConnect.Controls.Add(this.lblPassword);
            this.grbConnect.Controls.Add(this.lblUserID);
            this.grbConnect.Controls.Add(this.lblDBName);
            this.grbConnect.Controls.Add(this.txtSrcDBName);
            this.grbConnect.Controls.Add(this.txtSrcUserID);
            this.grbConnect.Controls.Add(this.txtSrcPassword);
            this.grbConnect.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grbConnect.Location = new System.Drawing.Point(299, 17);
            this.grbConnect.Name = "grbConnect";
            this.grbConnect.Size = new System.Drawing.Size(292, 479);
            this.grbConnect.TabIndex = 1;
            this.grbConnect.TabStop = false;
            this.grbConnect.Text = "Source DB";
            this.grbConnect.Visible = false;
            // 
            // txtLogTablespace
            // 
            this.txtLogTablespace.Location = new System.Drawing.Point(26, 225);
            this.txtLogTablespace.Name = "txtLogTablespace";
            this.txtLogTablespace.Size = new System.Drawing.Size(246, 20);
            this.txtLogTablespace.TabIndex = 6;
            // 
            // Label1
            // 
            this.Label1.AutoSize = true;
            this.Label1.Location = new System.Drawing.Point(24, 203);
            this.Label1.Name = "Label1";
            this.Label1.Size = new System.Drawing.Size(84, 13);
            this.Label1.TabIndex = 9;
            this.Label1.Text = "Log Tablespace";
            this.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtSrcDataSource
            // 
            this.txtSrcDataSource.Enabled = false;
            this.txtSrcDataSource.Location = new System.Drawing.Point(128, 72);
            this.txtSrcDataSource.Name = "txtSrcDataSource";
            this.txtSrcDataSource.Size = new System.Drawing.Size(144, 20);
            this.txtSrcDataSource.TabIndex = 1;
            // 
            // lblDataSource
            // 
            this.lblDataSource.AutoSize = true;
            this.lblDataSource.Enabled = false;
            this.lblDataSource.Location = new System.Drawing.Point(24, 72);
            this.lblDataSource.Name = "lblDataSource";
            this.lblDataSource.Size = new System.Drawing.Size(67, 13);
            this.lblDataSource.TabIndex = 0;
            this.lblDataSource.Text = "Data Source";
            this.lblDataSource.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // grbDBType
            // 
            this.grbDBType.Controls.Add(this.rdoSrcDB2);
            this.grbDBType.Controls.Add(this.rdoSrcOracle);
            this.grbDBType.Controls.Add(this.rdoSrcMsSql);
            this.grbDBType.Location = new System.Drawing.Point(8, 16);
            this.grbDBType.Name = "grbDBType";
            this.grbDBType.Size = new System.Drawing.Size(275, 48);
            this.grbDBType.TabIndex = 8;
            this.grbDBType.TabStop = false;
            this.grbDBType.Text = "DB Type";
            // 
            // rdoSrcDB2
            // 
            this.rdoSrcDB2.Enabled = false;
            this.rdoSrcDB2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdoSrcDB2.Location = new System.Drawing.Point(205, 18);
            this.rdoSrcDB2.Name = "rdoSrcDB2";
            this.rdoSrcDB2.Size = new System.Drawing.Size(56, 24);
            this.rdoSrcDB2.TabIndex = 2;
            this.rdoSrcDB2.Text = "DB2";
            // 
            // rdoSrcOracle
            // 
            this.rdoSrcOracle.Checked = true;
            this.rdoSrcOracle.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdoSrcOracle.Location = new System.Drawing.Point(117, 18);
            this.rdoSrcOracle.Name = "rdoSrcOracle";
            this.rdoSrcOracle.Size = new System.Drawing.Size(64, 24);
            this.rdoSrcOracle.TabIndex = 16;
            this.rdoSrcOracle.TabStop = true;
            this.rdoSrcOracle.Text = "Oracle";
            // 
            // rdoSrcMsSql
            // 
            this.rdoSrcMsSql.Enabled = false;
            this.rdoSrcMsSql.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdoSrcMsSql.Location = new System.Drawing.Point(21, 18);
            this.rdoSrcMsSql.Name = "rdoSrcMsSql";
            this.rdoSrcMsSql.Size = new System.Drawing.Size(72, 24);
            this.rdoSrcMsSql.TabIndex = 0;
            this.rdoSrcMsSql.Text = "MS SQL";
            // 
            // lblPassword
            // 
            this.lblPassword.AutoSize = true;
            this.lblPassword.Location = new System.Drawing.Point(24, 168);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(53, 13);
            this.lblPassword.TabIndex = 6;
            this.lblPassword.Text = "Password";
            this.lblPassword.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblUserID
            // 
            this.lblUserID.AutoSize = true;
            this.lblUserID.Location = new System.Drawing.Point(24, 136);
            this.lblUserID.Name = "lblUserID";
            this.lblUserID.Size = new System.Drawing.Size(43, 13);
            this.lblUserID.TabIndex = 4;
            this.lblUserID.Text = "User ID";
            this.lblUserID.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblDBName
            // 
            this.lblDBName.AutoSize = true;
            this.lblDBName.Location = new System.Drawing.Point(24, 104);
            this.lblDBName.Name = "lblDBName";
            this.lblDBName.Size = new System.Drawing.Size(53, 13);
            this.lblDBName.TabIndex = 2;
            this.lblDBName.Text = "DB Name";
            this.lblDBName.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtSrcDBName
            // 
            this.txtSrcDBName.Location = new System.Drawing.Point(128, 104);
            this.txtSrcDBName.Name = "txtSrcDBName";
            this.txtSrcDBName.Size = new System.Drawing.Size(144, 20);
            this.txtSrcDBName.TabIndex = 3;
            // 
            // txtSrcUserID
            // 
            this.txtSrcUserID.Location = new System.Drawing.Point(128, 136);
            this.txtSrcUserID.Name = "txtSrcUserID";
            this.txtSrcUserID.Size = new System.Drawing.Size(144, 20);
            this.txtSrcUserID.TabIndex = 4;
            // 
            // txtSrcPassword
            // 
            this.txtSrcPassword.Location = new System.Drawing.Point(128, 168);
            this.txtSrcPassword.Name = "txtSrcPassword";
            this.txtSrcPassword.PasswordChar = '*';
            this.txtSrcPassword.Size = new System.Drawing.Size(144, 20);
            this.txtSrcPassword.TabIndex = 5;
            // 
            // pageColList
            // 
            this.pageColList.Controls.Add(this.label12);
            this.pageColList.Controls.Add(this.txtWhere);
            this.pageColList.Controls.Add(this.spdViewCol);
            this.pageColList.Controls.Add(this.pnlGenInfo);
            this.pageColList.Location = new System.Drawing.Point(4, 24);
            this.pageColList.Name = "pageColList";
            this.pageColList.Size = new System.Drawing.Size(594, 539);
            this.pageColList.TabIndex = 0;
            this.pageColList.Text = "Columns";
            this.pageColList.UseVisualStyleBackColor = true;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(3, 369);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(48, 13);
            this.label12.TabIndex = 6;
            this.label12.Text = "WHERE";
            this.label12.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtWhere
            // 
            this.txtWhere.Location = new System.Drawing.Point(57, 366);
            this.txtWhere.Multiline = true;
            this.txtWhere.Name = "txtWhere";
            this.txtWhere.Size = new System.Drawing.Size(524, 96);
            this.txtWhere.TabIndex = 5;
            // 
            // spdViewCol
            // 
            this.spdViewCol.AccessibleDescription = "spdViewCol, Sheet1, Row 0, Column 0, ";
            this.spdViewCol.AllowRowMove = true;
            this.spdViewCol.BackColor = System.Drawing.SystemColors.Control;
            this.spdViewCol.EditModeReplace = true;
            this.spdViewCol.Location = new System.Drawing.Point(5, 17);
            this.spdViewCol.Name = "spdViewCol";
            this.spdViewCol.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.spdViewCol.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdViewCol_Sheet1});
            this.spdViewCol.Size = new System.Drawing.Size(586, 342);
            this.spdViewCol.TabIndex = 4;
            this.spdViewCol.Change += new FarPoint.Win.Spread.ChangeEventHandler(this.spdViewCol_Change);
            // 
            // spdViewCol_Sheet1
            // 
            this.spdViewCol_Sheet1.Reset();
            this.spdViewCol_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdViewCol_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdViewCol_Sheet1.ColumnCount = 2;
            this.spdViewCol_Sheet1.Cells.Get(0, 0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdViewCol_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "View Column Name";
            this.spdViewCol_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Source Column Name / Function";
            this.spdViewCol_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdViewCol_Sheet1.Columns.Get(0).Label = "View Column Name";
            this.spdViewCol_Sheet1.Columns.Get(0).Width = 146F;
            this.spdViewCol_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdViewCol_Sheet1.Columns.Get(1).Label = "Source Column Name / Function";
            this.spdViewCol_Sheet1.Columns.Get(1).Width = 383F;
            this.spdViewCol_Sheet1.RowHeader.Columns.Default.Resizable = true;
            this.spdViewCol_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // pageCode
            // 
            this.pageCode.Controls.Add(this.pnlCodeFill);
            this.pageCode.Controls.Add(this.pnlGap2);
            this.pageCode.Controls.Add(this.pnlSQLSave);
            this.pageCode.Location = new System.Drawing.Point(4, 24);
            this.pageCode.Name = "pageCode";
            this.pageCode.Size = new System.Drawing.Size(594, 539);
            this.pageCode.TabIndex = 1;
            this.pageCode.Text = "Code Output";
            this.pageCode.UseVisualStyleBackColor = true;
            // 
            // pnlCodeFill
            // 
            this.pnlCodeFill.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlCodeFill.Controls.Add(this.pnlScript);
            this.pnlCodeFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCodeFill.Location = new System.Drawing.Point(0, 0);
            this.pnlCodeFill.Name = "pnlCodeFill";
            this.pnlCodeFill.Size = new System.Drawing.Size(594, 471);
            this.pnlCodeFill.TabIndex = 6;
            // 
            // pnlScript
            // 
            this.pnlScript.Controls.Add(this.txtScript);
            this.pnlScript.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlScript.Location = new System.Drawing.Point(0, 0);
            this.pnlScript.Name = "pnlScript";
            this.pnlScript.Padding = new System.Windows.Forms.Padding(0, 2, 0, 0);
            this.pnlScript.Size = new System.Drawing.Size(592, 469);
            this.pnlScript.TabIndex = 2;
            // 
            // txtScript
            // 
            this.txtScript.AutoWordSelection = true;
            this.txtScript.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtScript.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.txtScript.Location = new System.Drawing.Point(0, 2);
            this.txtScript.Name = "txtScript";
            this.txtScript.Size = new System.Drawing.Size(592, 467);
            this.txtScript.TabIndex = 0;
            this.txtScript.Text = "";
            this.txtScript.WordWrap = false;
            // 
            // pnlGap2
            // 
            this.pnlGap2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlGap2.Location = new System.Drawing.Point(0, 471);
            this.pnlGap2.Name = "pnlGap2";
            this.pnlGap2.Size = new System.Drawing.Size(594, 4);
            this.pnlGap2.TabIndex = 5;
            // 
            // pnlSQLSave
            // 
            this.pnlSQLSave.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlSQLSave.Controls.Add(this.grbSave);
            this.pnlSQLSave.Controls.Add(this.pnlSQLSaveRight);
            this.pnlSQLSave.Controls.Add(this.pnlSQLSaveLeft);
            this.pnlSQLSave.Controls.Add(this.pnlSQLSaveBottom);
            this.pnlSQLSave.Controls.Add(this.pnlSQLSaveTop);
            this.pnlSQLSave.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlSQLSave.Location = new System.Drawing.Point(0, 475);
            this.pnlSQLSave.Name = "pnlSQLSave";
            this.pnlSQLSave.Size = new System.Drawing.Size(594, 64);
            this.pnlSQLSave.TabIndex = 4;
            // 
            // grbSave
            // 
            this.grbSave.Controls.Add(this.btnSave);
            this.grbSave.Controls.Add(this.txtFileName);
            this.grbSave.Controls.Add(this.lblFileName);
            this.grbSave.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grbSave.Location = new System.Drawing.Point(6, 6);
            this.grbSave.Name = "grbSave";
            this.grbSave.Size = new System.Drawing.Size(580, 50);
            this.grbSave.TabIndex = 4;
            this.grbSave.TabStop = false;
            this.grbSave.Text = "SQL Save";
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(496, 17);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(80, 24);
            this.btnSave.TabIndex = 4;
            this.btnSave.Text = "Save";
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // txtFileName
            // 
            this.txtFileName.Location = new System.Drawing.Point(96, 16);
            this.txtFileName.Name = "txtFileName";
            this.txtFileName.Size = new System.Drawing.Size(368, 20);
            this.txtFileName.TabIndex = 3;
            // 
            // lblFileName
            // 
            this.lblFileName.AutoSize = true;
            this.lblFileName.Location = new System.Drawing.Point(15, 21);
            this.lblFileName.Name = "lblFileName";
            this.lblFileName.Size = new System.Drawing.Size(54, 13);
            this.lblFileName.TabIndex = 2;
            this.lblFileName.Text = "File Name";
            this.lblFileName.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pnlSQLSaveRight
            // 
            this.pnlSQLSaveRight.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlSQLSaveRight.Location = new System.Drawing.Point(586, 6);
            this.pnlSQLSaveRight.Name = "pnlSQLSaveRight";
            this.pnlSQLSaveRight.Size = new System.Drawing.Size(6, 50);
            this.pnlSQLSaveRight.TabIndex = 3;
            // 
            // pnlSQLSaveLeft
            // 
            this.pnlSQLSaveLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlSQLSaveLeft.Location = new System.Drawing.Point(0, 6);
            this.pnlSQLSaveLeft.Name = "pnlSQLSaveLeft";
            this.pnlSQLSaveLeft.Size = new System.Drawing.Size(6, 50);
            this.pnlSQLSaveLeft.TabIndex = 2;
            // 
            // pnlSQLSaveBottom
            // 
            this.pnlSQLSaveBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlSQLSaveBottom.Location = new System.Drawing.Point(0, 56);
            this.pnlSQLSaveBottom.Name = "pnlSQLSaveBottom";
            this.pnlSQLSaveBottom.Size = new System.Drawing.Size(592, 6);
            this.pnlSQLSaveBottom.TabIndex = 1;
            // 
            // pnlSQLSaveTop
            // 
            this.pnlSQLSaveTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlSQLSaveTop.Location = new System.Drawing.Point(0, 0);
            this.pnlSQLSaveTop.Name = "pnlSQLSaveTop";
            this.pnlSQLSaveTop.Size = new System.Drawing.Size(592, 6);
            this.pnlSQLSaveTop.TabIndex = 0;
            // 
            // colNo
            // 
            this.colNo.Text = "No.";
            this.colNo.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colNo.Width = 39;
            // 
            // colFieldName
            // 
            this.colFieldName.Text = "Field Name";
            this.colFieldName.Width = 166;
            // 
            // colPK
            // 
            this.colPK.Text = "PK";
            this.colPK.Width = 47;
            // 
            // colNumericScale
            // 
            this.colNumericScale.Text = "Numeric Scale";
            this.colNumericScale.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colNumericScale.Width = 97;
            // 
            // colDataType
            // 
            this.colDataType.Text = "Data Type";
            this.colDataType.Width = 77;
            // 
            // colSize
            // 
            this.colSize.Text = "Size";
            this.colSize.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colSize.Width = 53;
            // 
            // colNull
            // 
            this.colNull.Text = "Null?";
            this.colNull.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.colNull.Width = 42;
            // 
            // rbView
            // 
            this.rbView.Location = new System.Drawing.Point(126, 16);
            this.rbView.Name = "rbView";
            this.rbView.Size = new System.Drawing.Size(62, 17);
            this.rbView.TabIndex = 7;
            this.rbView.Text = "View";
            this.rbView.CheckedChanged += new System.EventHandler(this.rbView_CheckedChanged);
            // 
            // splMain
            // 
            this.splMain.Location = new System.Drawing.Point(261, 8);
            this.splMain.Name = "splMain";
            this.splMain.Size = new System.Drawing.Size(4, 591);
            this.splMain.TabIndex = 26;
            this.splMain.TabStop = false;
            // 
            // rbTable
            // 
            this.rbTable.Checked = true;
            this.rbTable.Location = new System.Drawing.Point(30, 16);
            this.rbTable.Name = "rbTable";
            this.rbTable.Size = new System.Drawing.Size(90, 17);
            this.rbTable.TabIndex = 6;
            this.rbTable.TabStop = true;
            this.rbTable.Text = "Table";
            this.rbTable.CheckedChanged += new System.EventHandler(this.rbTable_CheckedChanged);
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.gbColumnList);
            this.pnlLeft.Controls.Add(this.grbTableList);
            this.pnlLeft.Controls.Add(this.pnlViewType);
            this.pnlLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLeft.Location = new System.Drawing.Point(0, 8);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Padding = new System.Windows.Forms.Padding(5, 0, 0, 5);
            this.pnlLeft.Size = new System.Drawing.Size(261, 591);
            this.pnlLeft.TabIndex = 25;
            // 
            // gbColumnList
            // 
            this.gbColumnList.Controls.Add(this.spdColList);
            this.gbColumnList.Location = new System.Drawing.Point(5, 305);
            this.gbColumnList.Name = "gbColumnList";
            this.gbColumnList.Size = new System.Drawing.Size(250, 281);
            this.gbColumnList.TabIndex = 5;
            this.gbColumnList.TabStop = false;
            this.gbColumnList.Text = "Column List";
            // 
            // spdColList
            // 
            this.spdColList.AccessibleDescription = "spdColList, Sheet1, Row 0, Column 0, ";
            this.spdColList.AllowUserZoom = false;
            this.spdColList.BackColor = System.Drawing.SystemColors.Control;
            this.spdColList.Location = new System.Drawing.Point(3, 19);
            this.spdColList.Name = "spdColList";
            this.spdColList.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.spdColList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdColList_Sheet1});
            this.spdColList.Size = new System.Drawing.Size(245, 256);
            this.spdColList.TabIndex = 0;
            // 
            // spdColList_Sheet1
            // 
            this.spdColList_Sheet1.Reset();
            this.spdColList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdColList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdColList_Sheet1.ColumnCount = 2;
            this.spdColList_Sheet1.Cells.Get(0, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(1, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(2, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(3, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(4, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(5, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(6, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(7, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(8, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(9, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(10, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(11, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(12, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(13, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(14, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(15, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(16, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(17, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(18, 0).Locked = false;
            this.spdColList_Sheet1.Cells.Get(19, 0).Locked = false;
            this.spdColList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Column Name";
            this.spdColList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "DataType";
            this.spdColList_Sheet1.Columns.Get(0).Label = "Column Name";
            this.spdColList_Sheet1.Columns.Get(0).Locked = true;
            this.spdColList_Sheet1.Columns.Get(0).Width = 118F;
            this.spdColList_Sheet1.Columns.Get(1).Label = "DataType";
            this.spdColList_Sheet1.Columns.Get(1).Width = 68F;
            this.spdColList_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.ReadOnly;
            this.spdColList_Sheet1.RowHeader.Columns.Default.Resizable = true;
            this.spdColList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;
            // 
            // grbTableList
            // 
            this.grbTableList.Controls.Add(this.grpColumnList);
            this.grbTableList.Controls.Add(this.lisTable);
            this.grbTableList.Location = new System.Drawing.Point(5, 41);
            this.grbTableList.Name = "grbTableList";
            this.grbTableList.Size = new System.Drawing.Size(251, 263);
            this.grbTableList.TabIndex = 4;
            this.grbTableList.TabStop = false;
            this.grbTableList.Text = "Table List";
            // 
            // grpColumnList
            // 
            this.grpColumnList.Controls.Add(this.listView1);
            this.grpColumnList.Location = new System.Drawing.Point(0, 269);
            this.grpColumnList.Name = "grpColumnList";
            this.grpColumnList.Size = new System.Drawing.Size(251, 276);
            this.grpColumnList.TabIndex = 5;
            this.grpColumnList.TabStop = false;
            this.grpColumnList.Text = "Column List";
            // 
            // listView1
            // 
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader4});
            this.listView1.FullRowSelect = true;
            this.listView1.HideSelection = false;
            this.listView1.Location = new System.Drawing.Point(3, 16);
            this.listView1.MultiSelect = false;
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(245, 263);
            this.listView1.TabIndex = 1;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Table Name";
            this.columnHeader1.Width = 139;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Type";
            this.columnHeader4.Width = 77;
            // 
            // lisTable
            // 
            this.lisTable.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader2,
            this.ColumnHeader3});
            this.lisTable.HideSelection = false;
            this.lisTable.Location = new System.Drawing.Point(3, 16);
            this.lisTable.Name = "lisTable";
            this.lisTable.Size = new System.Drawing.Size(245, 242);
            this.lisTable.TabIndex = 1;
            this.lisTable.UseCompatibleStateImageBehavior = false;
            this.lisTable.View = System.Windows.Forms.View.Details;
            this.lisTable.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.lisTable_ColumnClick);
            this.lisTable.Click += new System.EventHandler(this.lisTable_Click);
            // 
            // ColumnHeader2
            // 
            this.ColumnHeader2.Text = "Table Name";
            this.ColumnHeader2.Width = 139;
            // 
            // ColumnHeader3
            // 
            this.ColumnHeader3.Text = "Type";
            this.ColumnHeader3.Width = 77;
            // 
            // pnlViewType
            // 
            this.pnlViewType.Controls.Add(this.grpDBViewType);
            this.pnlViewType.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlViewType.Location = new System.Drawing.Point(5, 0);
            this.pnlViewType.Name = "pnlViewType";
            this.pnlViewType.Size = new System.Drawing.Size(256, 41);
            this.pnlViewType.TabIndex = 3;
            // 
            // grpDBViewType
            // 
            this.grpDBViewType.Controls.Add(this.rbView);
            this.grpDBViewType.Controls.Add(this.rbTable);
            this.grpDBViewType.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpDBViewType.Location = new System.Drawing.Point(0, 0);
            this.grpDBViewType.Name = "grpDBViewType";
            this.grpDBViewType.Size = new System.Drawing.Size(256, 41);
            this.grpDBViewType.TabIndex = 3;
            this.grpDBViewType.TabStop = false;
            this.grpDBViewType.Text = "List View Type";
            // 
            // pnlTop
            // 
            this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTop.Location = new System.Drawing.Point(0, 0);
            this.pnlTop.Name = "pnlTop";
            this.pnlTop.Padding = new System.Windows.Forms.Padding(5, 3, 5, 5);
            this.pnlTop.Size = new System.Drawing.Size(878, 8);
            this.pnlTop.TabIndex = 24;
            // 
            // colPrecision
            // 
            this.colPrecision.Text = "Precision";
            this.colPrecision.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.colPrecision.Width = 69;
            // 
            // frmDBViewTrig
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(878, 599);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.splMain);
            this.Controls.Add(this.pnlLeft);
            this.Controls.Add(this.pnlTop);
            this.MinimumSize = new System.Drawing.Size(644, 626);
            this.Name = "frmDBViewTrig";
            this.Text = "Create View Trigger";
            this.Activated += new System.EventHandler(this.frmDBViewTrig_Activated);
            this.Load += new System.EventHandler(this.frmDBViewTrig_Load);
            this.pnlGenInfo.ResumeLayout(false);
            this.grpGenInfo.ResumeLayout(false);
            this.grpGenInfo.PerformLayout();
            this.pnlCenter.ResumeLayout(false);
            this.grbCenter.ResumeLayout(false);
            this.tabColumns.ResumeLayout(false);
            this.pageConnect.ResumeLayout(false);
            this.GroupBox1.ResumeLayout(false);
            this.GroupBox1.PerformLayout();
            this.GroupBox2.ResumeLayout(false);
            this.grbConnect.ResumeLayout(false);
            this.grbConnect.PerformLayout();
            this.grbDBType.ResumeLayout(false);
            this.pageColList.ResumeLayout(false);
            this.pageColList.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spdViewCol)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdViewCol_Sheet1)).EndInit();
            this.pageCode.ResumeLayout(false);
            this.pnlCodeFill.ResumeLayout(false);
            this.pnlScript.ResumeLayout(false);
            this.pnlSQLSave.ResumeLayout(false);
            this.grbSave.ResumeLayout(false);
            this.grbSave.PerformLayout();
            this.pnlLeft.ResumeLayout(false);
            this.gbColumnList.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.spdColList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spdColList_Sheet1)).EndInit();
            this.grbTableList.ResumeLayout(false);
            this.grpColumnList.ResumeLayout(false);
            this.pnlViewType.ResumeLayout(false);
            this.grpDBViewType.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        internal System.Windows.Forms.Panel pnlGenInfo;
        internal System.Windows.Forms.GroupBox grpGenInfo;
        internal System.Windows.Forms.TextBox txtViewName;
        internal System.Windows.Forms.Button btnExecute;
        internal System.Windows.Forms.Button btnCodeGen;
        internal System.Windows.Forms.Label lblInterval;
        internal System.Windows.Forms.Panel pnlCenter;
        internal System.Windows.Forms.GroupBox grbCenter;
        internal System.Windows.Forms.TabControl tabColumns;
        internal System.Windows.Forms.TabPage pageConnect;
        internal System.Windows.Forms.Button btnExit;
        internal System.Windows.Forms.Button btnDisconnect;
        internal System.Windows.Forms.Button btnConnect;
        internal System.Windows.Forms.GroupBox GroupBox1;
        internal System.Windows.Forms.TextBox txtDBLink;
        internal System.Windows.Forms.Label Label8;
        internal System.Windows.Forms.TextBox txtPrefix;
        internal System.Windows.Forms.Label Label9;
        internal System.Windows.Forms.TextBox txtViewTablespace;
        internal System.Windows.Forms.Label Label2;
        internal System.Windows.Forms.TextBox txtTarDataSource;
        internal System.Windows.Forms.Label Label4;
        internal System.Windows.Forms.GroupBox GroupBox2;
        internal System.Windows.Forms.RadioButton rdoTarDB2;
        internal System.Windows.Forms.RadioButton rdoTarOracle;
        internal System.Windows.Forms.RadioButton rdoTarMsSql;
        internal System.Windows.Forms.Label Label5;
        internal System.Windows.Forms.Label Label6;
        internal System.Windows.Forms.Label Label7;
        internal System.Windows.Forms.TextBox txtTarDBName;
        internal System.Windows.Forms.TextBox txtTarUserID;
        internal System.Windows.Forms.TextBox txtTarPassword;
        internal System.Windows.Forms.GroupBox grbConnect;
        internal System.Windows.Forms.TextBox txtLogTablespace;
        internal System.Windows.Forms.Label Label1;
        internal System.Windows.Forms.TextBox txtSrcDataSource;
        internal System.Windows.Forms.Label lblDataSource;
        internal System.Windows.Forms.GroupBox grbDBType;
        internal System.Windows.Forms.RadioButton rdoSrcDB2;
        internal System.Windows.Forms.RadioButton rdoSrcOracle;
        internal System.Windows.Forms.RadioButton rdoSrcMsSql;
        internal System.Windows.Forms.Label lblPassword;
        internal System.Windows.Forms.Label lblUserID;
        internal System.Windows.Forms.Label lblDBName;
        internal System.Windows.Forms.TextBox txtSrcDBName;
        internal System.Windows.Forms.TextBox txtSrcUserID;
        internal System.Windows.Forms.TextBox txtSrcPassword;
        internal System.Windows.Forms.TabPage pageColList;
        internal System.Windows.Forms.TabPage pageCode;
        internal System.Windows.Forms.Panel pnlCodeFill;
        internal System.Windows.Forms.Panel pnlScript;
        internal System.Windows.Forms.RichTextBox txtScript;
        internal System.Windows.Forms.Panel pnlGap2;
        internal System.Windows.Forms.Panel pnlSQLSave;
        internal System.Windows.Forms.GroupBox grbSave;
        internal System.Windows.Forms.Button btnSave;
        internal System.Windows.Forms.TextBox txtFileName;
        internal System.Windows.Forms.Label lblFileName;
        internal System.Windows.Forms.Panel pnlSQLSaveRight;
        internal System.Windows.Forms.Panel pnlSQLSaveLeft;
        internal System.Windows.Forms.Panel pnlSQLSaveBottom;
        internal System.Windows.Forms.Panel pnlSQLSaveTop;
        internal System.Windows.Forms.ColumnHeader colNo;
        internal System.Windows.Forms.ColumnHeader colFieldName;
        internal System.Windows.Forms.ColumnHeader colPK;
        internal System.Windows.Forms.ColumnHeader colNumericScale;
        internal System.Windows.Forms.ColumnHeader colDataType;
        internal System.Windows.Forms.ColumnHeader colSize;
        internal System.Windows.Forms.ColumnHeader colNull;
        internal System.Windows.Forms.RadioButton rbView;
        internal System.Windows.Forms.Splitter splMain;
        internal System.Windows.Forms.RadioButton rbTable;
        internal System.Windows.Forms.Panel pnlLeft;
        internal System.Windows.Forms.GroupBox grbTableList;
        internal System.Windows.Forms.ListView lisTable;
        internal System.Windows.Forms.ColumnHeader ColumnHeader2;
        internal System.Windows.Forms.ColumnHeader ColumnHeader3;
        internal System.Windows.Forms.Panel pnlViewType;
        internal System.Windows.Forms.GroupBox grpDBViewType;
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.ColumnHeader colPrecision;
        internal System.Windows.Forms.TextBox textBox2;
        internal System.Windows.Forms.Label label11;
        internal System.Windows.Forms.TextBox textBox1;
        internal System.Windows.Forms.Label label10;
        internal System.Windows.Forms.TextBox txtLogTable;
        internal System.Windows.Forms.Label label3;
        internal System.Windows.Forms.GroupBox grpColumnList;
        internal System.Windows.Forms.ListView listView1;
        internal System.Windows.Forms.ColumnHeader columnHeader1;
        internal System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.GroupBox gbColumnList;
        private FarPoint.Win.Spread.FpSpread spdViewCol;
        private FarPoint.Win.Spread.SheetView spdViewCol_Sheet1;
        private FarPoint.Win.Spread.FpSpread spdColList;
        private FarPoint.Win.Spread.SheetView spdColList_Sheet1;
        internal System.Windows.Forms.Button btnDelete;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.TextBox txtViewPrefix;
        internal System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox txtWhere;
    }
}