namespace Admin.RPTCore
{
    partial class frmDBReplicator
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
            this.btnClose = new System.Windows.Forms.Button();
            this.btnCreateView = new System.Windows.Forms.Button();
            this.btnCodeGen = new System.Windows.Forms.Button();
            this.cbMView = new System.Windows.Forms.CheckBox();
            this.rbOracleJob = new System.Windows.Forms.RadioButton();
            this.rbOnDemand = new System.Windows.Forms.RadioButton();
            this.txtInterval = new System.Windows.Forms.TextBox();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnExecute = new System.Windows.Forms.Button();
            this.Label3 = new System.Windows.Forms.Label();
            this.lblInterval = new System.Windows.Forms.Label();
            this.cbRTable = new System.Windows.Forms.CheckBox();
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.grbCenter = new System.Windows.Forms.GroupBox();
            this.tabColumns = new System.Windows.Forms.TabControl();
            this.pageConnect = new System.Windows.Forms.TabPage();
            this.btnExit = new System.Windows.Forms.Button();
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.btnConnect = new System.Windows.Forms.Button();
            this.GroupBox1 = new System.Windows.Forms.GroupBox();
            this.txtRepIdxTablespace = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.txtRepTblTablespace = new System.Windows.Forms.TextBox();
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
            this.label12 = new System.Windows.Forms.Label();
            this.txtSchema = new System.Windows.Forms.TextBox();
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
            this.lisColList = new System.Windows.Forms.ListView();
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader7 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader9 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader52 = new System.Windows.Forms.ColumnHeader();
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
            this.rbTarget = new System.Windows.Forms.RadioButton();
            this.splMain = new System.Windows.Forms.Splitter();
            this.rbSource = new System.Windows.Forms.RadioButton();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.grbTableList = new System.Windows.Forms.GroupBox();
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
            this.pageCode.SuspendLayout();
            this.pnlCodeFill.SuspendLayout();
            this.pnlScript.SuspendLayout();
            this.pnlSQLSave.SuspendLayout();
            this.grbSave.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.grbTableList.SuspendLayout();
            this.pnlViewType.SuspendLayout();
            this.grpDBViewType.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlGenInfo
            // 
            this.pnlGenInfo.Controls.Add(this.grpGenInfo);
            this.pnlGenInfo.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlGenInfo.Location = new System.Drawing.Point(0, 404);
            this.pnlGenInfo.Name = "pnlGenInfo";
            this.pnlGenInfo.Size = new System.Drawing.Size(599, 134);
            this.pnlGenInfo.TabIndex = 1;
            // 
            // grpGenInfo
            // 
            this.grpGenInfo.Controls.Add(this.btnClose);
            this.grpGenInfo.Controls.Add(this.btnCreateView);
            this.grpGenInfo.Controls.Add(this.btnCodeGen);
            this.grpGenInfo.Controls.Add(this.cbMView);
            this.grpGenInfo.Controls.Add(this.rbOracleJob);
            this.grpGenInfo.Controls.Add(this.rbOnDemand);
            this.grpGenInfo.Controls.Add(this.txtInterval);
            this.grpGenInfo.Controls.Add(this.btnDelete);
            this.grpGenInfo.Controls.Add(this.btnExecute);
            this.grpGenInfo.Controls.Add(this.Label3);
            this.grpGenInfo.Controls.Add(this.lblInterval);
            this.grpGenInfo.Controls.Add(this.cbRTable);
            this.grpGenInfo.Location = new System.Drawing.Point(1, 3);
            this.grpGenInfo.Name = "grpGenInfo";
            this.grpGenInfo.Size = new System.Drawing.Size(595, 128);
            this.grpGenInfo.TabIndex = 9;
            this.grpGenInfo.TabStop = false;
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(519, 98);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(70, 24);
            this.btnClose.TabIndex = 10;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnCreateView
            // 
            this.btnCreateView.Location = new System.Drawing.Point(6, 98);
            this.btnCreateView.Name = "btnCreateView";
            this.btnCreateView.Size = new System.Drawing.Size(78, 24);
            this.btnCreateView.TabIndex = 9;
            this.btnCreateView.Text = "Create View";
            this.btnCreateView.Click += new System.EventHandler(this.btnCreateView_Click);
            // 
            // btnCodeGen
            // 
            this.btnCodeGen.Location = new System.Drawing.Point(291, 98);
            this.btnCodeGen.Name = "btnCodeGen";
            this.btnCodeGen.Size = new System.Drawing.Size(70, 24);
            this.btnCodeGen.TabIndex = 3;
            this.btnCodeGen.Text = "Generate";
            this.btnCodeGen.Click += new System.EventHandler(this.btnCodeGen_Click);
            // 
            // cbMView
            // 
            this.cbMView.AutoSize = true;
            this.cbMView.Checked = true;
            this.cbMView.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbMView.Enabled = false;
            this.cbMView.Location = new System.Drawing.Point(7, 41);
            this.cbMView.Name = "cbMView";
            this.cbMView.Size = new System.Drawing.Size(142, 17);
            this.cbMView.TabIndex = 7;
            this.cbMView.Text = "Create Materialized View";
            this.cbMView.UseVisualStyleBackColor = true;
            // 
            // rbOracleJob
            // 
            this.rbOracleJob.Checked = true;
            this.rbOracleJob.Location = new System.Drawing.Point(114, 16);
            this.rbOracleJob.Name = "rbOracleJob";
            this.rbOracleJob.Size = new System.Drawing.Size(116, 20);
            this.rbOracleJob.TabIndex = 6;
            this.rbOracleJob.TabStop = true;
            this.rbOracleJob.Text = "Job Scheduler";
            this.rbOracleJob.CheckedChanged += new System.EventHandler(this.rbClass_CheckedChanged);
            // 
            // rbOnDemand
            // 
            this.rbOnDemand.Location = new System.Drawing.Point(6, 16);
            this.rbOnDemand.Name = "rbOnDemand";
            this.rbOnDemand.Size = new System.Drawing.Size(102, 20);
            this.rbOnDemand.TabIndex = 5;
            this.rbOnDemand.Text = "On Demand";
            this.rbOnDemand.CheckedChanged += new System.EventHandler(this.rbClass_CheckedChanged);
            // 
            // txtInterval
            // 
            this.txtInterval.Location = new System.Drawing.Point(310, 16);
            this.txtInterval.Name = "txtInterval";
            this.txtInterval.Size = new System.Drawing.Size(68, 20);
            this.txtInterval.TabIndex = 4;
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(443, 98);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(70, 24);
            this.btnDelete.TabIndex = 3;
            this.btnDelete.Text = "Delete";
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnExecute
            // 
            this.btnExecute.Location = new System.Drawing.Point(367, 98);
            this.btnExecute.Name = "btnExecute";
            this.btnExecute.Size = new System.Drawing.Size(70, 24);
            this.btnExecute.TabIndex = 3;
            this.btnExecute.Text = "Execute";
            this.btnExecute.Click += new System.EventHandler(this.btnExecute_Click);
            // 
            // Label3
            // 
            this.Label3.AutoSize = true;
            this.Label3.Location = new System.Drawing.Point(384, 20);
            this.Label3.Name = "Label3";
            this.Label3.Size = new System.Drawing.Size(26, 13);
            this.Label3.TabIndex = 2;
            this.Label3.Text = "Sec";
            this.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblInterval
            // 
            this.lblInterval.AutoSize = true;
            this.lblInterval.Location = new System.Drawing.Point(236, 20);
            this.lblInterval.Name = "lblInterval";
            this.lblInterval.Size = new System.Drawing.Size(68, 13);
            this.lblInterval.TabIndex = 2;
            this.lblInterval.Text = "Time Interval";
            this.lblInterval.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // cbRTable
            // 
            this.cbRTable.AutoSize = true;
            this.cbRTable.Checked = true;
            this.cbRTable.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbRTable.Location = new System.Drawing.Point(7, 64);
            this.cbRTable.Name = "cbRTable";
            this.cbRTable.Size = new System.Drawing.Size(354, 17);
            this.cbRTable.TabIndex = 8;
            this.cbRTable.Text = "Replication Table and Trigger to populate data from Materialized View";
            this.cbRTable.UseVisualStyleBackColor = true;
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.grbCenter);
            this.pnlCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenter.Location = new System.Drawing.Point(260, 8);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Padding = new System.Windows.Forms.Padding(0, 0, 5, 5);
            this.pnlCenter.Size = new System.Drawing.Size(618, 591);
            this.pnlCenter.TabIndex = 0;
            // 
            // grbCenter
            // 
            this.grbCenter.Controls.Add(this.tabColumns);
            this.grbCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grbCenter.Location = new System.Drawing.Point(0, 0);
            this.grbCenter.Name = "grbCenter";
            this.grbCenter.Size = new System.Drawing.Size(613, 586);
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
            this.tabColumns.Size = new System.Drawing.Size(607, 567);
            this.tabColumns.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabColumns.TabIndex = 23;
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
            this.pageConnect.Size = new System.Drawing.Size(599, 539);
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
            this.btnExit.TabIndex = 17;
            this.btnExit.Text = "Exit";
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Location = new System.Drawing.Point(256, 512);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(88, 24);
            this.btnDisconnect.TabIndex = 16;
            this.btnDisconnect.Text = "Disconnect";
            this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(109, 512);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(88, 24);
            this.btnConnect.TabIndex = 15;
            this.btnConnect.Text = "Connect";
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // GroupBox1
            // 
            this.GroupBox1.Controls.Add(this.txtRepIdxTablespace);
            this.GroupBox1.Controls.Add(this.label11);
            this.GroupBox1.Controls.Add(this.txtRepTblTablespace);
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
            this.GroupBox1.Location = new System.Drawing.Point(302, 17);
            this.GroupBox1.Name = "GroupBox1";
            this.GroupBox1.Size = new System.Drawing.Size(292, 479);
            this.GroupBox1.TabIndex = 1;
            this.GroupBox1.TabStop = false;
            this.GroupBox1.Text = "Target DB";
            // 
            // txtRepIdxTablespace
            // 
            this.txtRepIdxTablespace.Location = new System.Drawing.Point(25, 398);
            this.txtRepIdxTablespace.Name = "txtRepIdxTablespace";
            this.txtRepIdxTablespace.Size = new System.Drawing.Size(246, 20);
            this.txtRepIdxTablespace.TabIndex = 7;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(23, 380);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(142, 13);
            this.label11.TabIndex = 15;
            this.label11.Text = "Relication Index Tablespace";
            this.label11.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtRepTblTablespace
            // 
            this.txtRepTblTablespace.Location = new System.Drawing.Point(25, 347);
            this.txtRepTblTablespace.Name = "txtRepTblTablespace";
            this.txtRepTblTablespace.Size = new System.Drawing.Size(246, 20);
            this.txtRepTblTablespace.TabIndex = 6;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(23, 329);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(149, 13);
            this.label10.TabIndex = 13;
            this.label10.Text = "Replication Table Tablespace";
            this.label10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtDBLink
            // 
            this.txtDBLink.Location = new System.Drawing.Point(26, 246);
            this.txtDBLink.Name = "txtDBLink";
            this.txtDBLink.Size = new System.Drawing.Size(246, 20);
            this.txtDBLink.TabIndex = 4;
            // 
            // Label8
            // 
            this.Label8.AutoSize = true;
            this.Label8.Location = new System.Drawing.Point(24, 228);
            this.Label8.Name = "Label8";
            this.Label8.Size = new System.Drawing.Size(45, 13);
            this.Label8.TabIndex = 9;
            this.Label8.Text = "DB Link";
            this.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtPrefix
            // 
            this.txtPrefix.Location = new System.Drawing.Point(25, 447);
            this.txtPrefix.MaxLength = 4;
            this.txtPrefix.Name = "txtPrefix";
            this.txtPrefix.Size = new System.Drawing.Size(246, 20);
            this.txtPrefix.TabIndex = 8;
            this.txtPrefix.Text = "MV_";
            // 
            // Label9
            // 
            this.Label9.AutoSize = true;
            this.Label9.Location = new System.Drawing.Point(23, 429);
            this.Label9.Name = "Label9";
            this.Label9.Size = new System.Drawing.Size(63, 13);
            this.Label9.TabIndex = 9;
            this.Label9.Text = "Table Prefix";
            this.Label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtViewTablespace
            // 
            this.txtViewTablespace.Location = new System.Drawing.Point(25, 298);
            this.txtViewTablespace.Name = "txtViewTablespace";
            this.txtViewTablespace.Size = new System.Drawing.Size(246, 20);
            this.txtViewTablespace.TabIndex = 5;
            // 
            // Label2
            // 
            this.Label2.AutoSize = true;
            this.Label2.Location = new System.Drawing.Point(23, 280);
            this.Label2.Name = "Label2";
            this.Label2.Size = new System.Drawing.Size(148, 13);
            this.Label2.TabIndex = 9;
            this.Label2.Text = "Materialized View Tablespace";
            this.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtTarDataSource
            // 
            this.txtTarDataSource.Enabled = false;
            this.txtTarDataSource.Location = new System.Drawing.Point(128, 72);
            this.txtTarDataSource.Name = "txtTarDataSource";
            this.txtTarDataSource.Size = new System.Drawing.Size(144, 20);
            this.txtTarDataSource.TabIndex = 0;
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
            this.GroupBox2.TabIndex = 18;
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
            this.Label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label5.Location = new System.Drawing.Point(24, 168);
            this.Label5.Name = "Label5";
            this.Label5.Size = new System.Drawing.Size(61, 13);
            this.Label5.TabIndex = 6;
            this.Label5.Text = "Password";
            this.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Label6
            // 
            this.Label6.AutoSize = true;
            this.Label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label6.Location = new System.Drawing.Point(24, 136);
            this.Label6.Name = "Label6";
            this.Label6.Size = new System.Drawing.Size(50, 13);
            this.Label6.TabIndex = 4;
            this.Label6.Text = "User ID";
            this.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Label7
            // 
            this.Label7.AutoSize = true;
            this.Label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Label7.Location = new System.Drawing.Point(24, 104);
            this.Label7.Name = "Label7";
            this.Label7.Size = new System.Drawing.Size(60, 13);
            this.Label7.TabIndex = 2;
            this.Label7.Text = "DB Name";
            this.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtTarDBName
            // 
            this.txtTarDBName.Location = new System.Drawing.Point(128, 104);
            this.txtTarDBName.Name = "txtTarDBName";
            this.txtTarDBName.Size = new System.Drawing.Size(144, 20);
            this.txtTarDBName.TabIndex = 1;
            // 
            // txtTarUserID
            // 
            this.txtTarUserID.Location = new System.Drawing.Point(128, 136);
            this.txtTarUserID.Name = "txtTarUserID";
            this.txtTarUserID.Size = new System.Drawing.Size(144, 20);
            this.txtTarUserID.TabIndex = 2;
            // 
            // txtTarPassword
            // 
            this.txtTarPassword.Location = new System.Drawing.Point(128, 168);
            this.txtTarPassword.Name = "txtTarPassword";
            this.txtTarPassword.PasswordChar = '*';
            this.txtTarPassword.Size = new System.Drawing.Size(144, 20);
            this.txtTarPassword.TabIndex = 3;
            // 
            // grbConnect
            // 
            this.grbConnect.Controls.Add(this.label12);
            this.grbConnect.Controls.Add(this.txtSchema);
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
            this.grbConnect.Location = new System.Drawing.Point(6, 17);
            this.grbConnect.Name = "grbConnect";
            this.grbConnect.Size = new System.Drawing.Size(292, 479);
            this.grbConnect.TabIndex = 0;
            this.grbConnect.TabStop = false;
            this.grbConnect.Text = "Source DB";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(23, 200);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(79, 13);
            this.label12.TabIndex = 22;
            this.label12.Text = "Table Owner";
            this.label12.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtSchema
            // 
            this.txtSchema.Location = new System.Drawing.Point(127, 200);
            this.txtSchema.Name = "txtSchema";
            this.txtSchema.Size = new System.Drawing.Size(144, 20);
            this.txtSchema.TabIndex = 3;
            // 
            // txtLogTablespace
            // 
            this.txtLogTablespace.Location = new System.Drawing.Point(26, 279);
            this.txtLogTablespace.Name = "txtLogTablespace";
            this.txtLogTablespace.Size = new System.Drawing.Size(246, 20);
            this.txtLogTablespace.TabIndex = 4;
            // 
            // Label1
            // 
            this.Label1.AutoSize = true;
            this.Label1.Location = new System.Drawing.Point(24, 257);
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
            this.txtSrcDataSource.TabIndex = 5;
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
            this.grbDBType.TabIndex = 20;
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
            this.rdoSrcDB2.TabIndex = 22;
            this.rdoSrcDB2.Text = "DB2";
            // 
            // rdoSrcOracle
            // 
            this.rdoSrcOracle.Checked = true;
            this.rdoSrcOracle.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.rdoSrcOracle.Location = new System.Drawing.Point(117, 18);
            this.rdoSrcOracle.Name = "rdoSrcOracle";
            this.rdoSrcOracle.Size = new System.Drawing.Size(64, 24);
            this.rdoSrcOracle.TabIndex = 21;
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
            this.rdoSrcMsSql.TabIndex = 20;
            this.rdoSrcMsSql.Text = "MS SQL";
            // 
            // lblPassword
            // 
            this.lblPassword.AutoSize = true;
            this.lblPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPassword.Location = new System.Drawing.Point(24, 168);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(61, 13);
            this.lblPassword.TabIndex = 6;
            this.lblPassword.Text = "Password";
            this.lblPassword.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblUserID
            // 
            this.lblUserID.AutoSize = true;
            this.lblUserID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUserID.Location = new System.Drawing.Point(24, 136);
            this.lblUserID.Name = "lblUserID";
            this.lblUserID.Size = new System.Drawing.Size(50, 13);
            this.lblUserID.TabIndex = 4;
            this.lblUserID.Text = "User ID";
            this.lblUserID.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblDBName
            // 
            this.lblDBName.AutoSize = true;
            this.lblDBName.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDBName.Location = new System.Drawing.Point(24, 104);
            this.lblDBName.Name = "lblDBName";
            this.lblDBName.Size = new System.Drawing.Size(60, 13);
            this.lblDBName.TabIndex = 2;
            this.lblDBName.Text = "DB Name";
            this.lblDBName.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtSrcDBName
            // 
            this.txtSrcDBName.Location = new System.Drawing.Point(128, 104);
            this.txtSrcDBName.Name = "txtSrcDBName";
            this.txtSrcDBName.Size = new System.Drawing.Size(144, 20);
            this.txtSrcDBName.TabIndex = 0;
            // 
            // txtSrcUserID
            // 
            this.txtSrcUserID.Location = new System.Drawing.Point(128, 136);
            this.txtSrcUserID.Name = "txtSrcUserID";
            this.txtSrcUserID.Size = new System.Drawing.Size(144, 20);
            this.txtSrcUserID.TabIndex = 1;
            // 
            // txtSrcPassword
            // 
            this.txtSrcPassword.Location = new System.Drawing.Point(128, 168);
            this.txtSrcPassword.Name = "txtSrcPassword";
            this.txtSrcPassword.PasswordChar = '*';
            this.txtSrcPassword.Size = new System.Drawing.Size(144, 20);
            this.txtSrcPassword.TabIndex = 2;
            // 
            // pageColList
            // 
            this.pageColList.Controls.Add(this.lisColList);
            this.pageColList.Controls.Add(this.pnlGenInfo);
            this.pageColList.Location = new System.Drawing.Point(4, 24);
            this.pageColList.Name = "pageColList";
            this.pageColList.Size = new System.Drawing.Size(599, 538);
            this.pageColList.TabIndex = 0;
            this.pageColList.Text = "Columns";
            this.pageColList.UseVisualStyleBackColor = true;
            // 
            // lisColList
            // 
            this.lisColList.CheckBoxes = true;
            this.lisColList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader1,
            this.ColumnHeader4,
            this.ColumnHeader5,
            this.ColumnHeader6,
            this.ColumnHeader8,
            this.ColumnHeader7,
            this.ColumnHeader9,
            this.ColumnHeader52});
            this.lisColList.FullRowSelect = true;
            this.lisColList.Location = new System.Drawing.Point(0, 0);
            this.lisColList.Name = "lisColList";
            this.lisColList.Size = new System.Drawing.Size(598, 399);
            this.lisColList.TabIndex = 3;
            this.lisColList.UseCompatibleStateImageBehavior = false;
            this.lisColList.View = System.Windows.Forms.View.Details;
            this.lisColList.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler(this.lisColList_ItemCheck);
            // 
            // ColumnHeader1
            // 
            this.ColumnHeader1.Text = "PK";
            this.ColumnHeader1.Width = 30;
            // 
            // ColumnHeader4
            // 
            this.ColumnHeader4.Text = "No.";
            this.ColumnHeader4.Width = 34;
            // 
            // ColumnHeader5
            // 
            this.ColumnHeader5.Text = "Field Name";
            this.ColumnHeader5.Width = 139;
            // 
            // ColumnHeader6
            // 
            this.ColumnHeader6.Text = "Data Type";
            this.ColumnHeader6.Width = 79;
            // 
            // ColumnHeader8
            // 
            this.ColumnHeader8.Text = "Null?";
            this.ColumnHeader8.Width = 46;
            // 
            // ColumnHeader7
            // 
            this.ColumnHeader7.Text = "Size";
            this.ColumnHeader7.Width = 55;
            // 
            // ColumnHeader9
            // 
            this.ColumnHeader9.Text = "Numeric Scale";
            this.ColumnHeader9.Width = 104;
            // 
            // ColumnHeader52
            // 
            this.ColumnHeader52.Text = "Precesion";
            this.ColumnHeader52.Width = 72;
            // 
            // pageCode
            // 
            this.pageCode.Controls.Add(this.pnlCodeFill);
            this.pageCode.Controls.Add(this.pnlGap2);
            this.pageCode.Controls.Add(this.pnlSQLSave);
            this.pageCode.Location = new System.Drawing.Point(4, 24);
            this.pageCode.Name = "pageCode";
            this.pageCode.Size = new System.Drawing.Size(599, 538);
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
            this.pnlCodeFill.Size = new System.Drawing.Size(599, 470);
            this.pnlCodeFill.TabIndex = 6;
            // 
            // pnlScript
            // 
            this.pnlScript.Controls.Add(this.txtScript);
            this.pnlScript.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlScript.Location = new System.Drawing.Point(0, 0);
            this.pnlScript.Name = "pnlScript";
            this.pnlScript.Padding = new System.Windows.Forms.Padding(0, 2, 0, 0);
            this.pnlScript.Size = new System.Drawing.Size(597, 468);
            this.pnlScript.TabIndex = 2;
            // 
            // txtScript
            // 
            this.txtScript.AutoWordSelection = true;
            this.txtScript.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtScript.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.txtScript.Location = new System.Drawing.Point(0, 2);
            this.txtScript.Name = "txtScript";
            this.txtScript.Size = new System.Drawing.Size(597, 466);
            this.txtScript.TabIndex = 0;
            this.txtScript.Text = "";
            this.txtScript.WordWrap = false;
            // 
            // pnlGap2
            // 
            this.pnlGap2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlGap2.Location = new System.Drawing.Point(0, 470);
            this.pnlGap2.Name = "pnlGap2";
            this.pnlGap2.Size = new System.Drawing.Size(599, 4);
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
            this.pnlSQLSave.Location = new System.Drawing.Point(0, 474);
            this.pnlSQLSave.Name = "pnlSQLSave";
            this.pnlSQLSave.Size = new System.Drawing.Size(599, 64);
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
            this.grbSave.Size = new System.Drawing.Size(585, 50);
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
            this.pnlSQLSaveRight.Location = new System.Drawing.Point(591, 6);
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
            this.pnlSQLSaveBottom.Size = new System.Drawing.Size(597, 6);
            this.pnlSQLSaveBottom.TabIndex = 1;
            // 
            // pnlSQLSaveTop
            // 
            this.pnlSQLSaveTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlSQLSaveTop.Location = new System.Drawing.Point(0, 0);
            this.pnlSQLSaveTop.Name = "pnlSQLSaveTop";
            this.pnlSQLSaveTop.Size = new System.Drawing.Size(597, 6);
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
            // rbTarget
            // 
            this.rbTarget.Location = new System.Drawing.Point(126, 16);
            this.rbTarget.Name = "rbTarget";
            this.rbTarget.Size = new System.Drawing.Size(62, 17);
            this.rbTarget.TabIndex = 20;
            this.rbTarget.Text = "Target";
            this.rbTarget.CheckedChanged += new System.EventHandler(this.rbView_CheckedChanged);
            // 
            // splMain
            // 
            this.splMain.Location = new System.Drawing.Point(256, 8);
            this.splMain.Name = "splMain";
            this.splMain.Size = new System.Drawing.Size(4, 591);
            this.splMain.TabIndex = 26;
            this.splMain.TabStop = false;
            // 
            // rbSource
            // 
            this.rbSource.Checked = true;
            this.rbSource.Location = new System.Drawing.Point(30, 16);
            this.rbSource.Name = "rbSource";
            this.rbSource.Size = new System.Drawing.Size(90, 17);
            this.rbSource.TabIndex = 20;
            this.rbSource.TabStop = true;
            this.rbSource.Text = "Source";
            this.rbSource.CheckedChanged += new System.EventHandler(this.rbTable_CheckedChanged);
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.grbTableList);
            this.pnlLeft.Controls.Add(this.pnlViewType);
            this.pnlLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLeft.Location = new System.Drawing.Point(0, 8);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Padding = new System.Windows.Forms.Padding(5, 0, 0, 5);
            this.pnlLeft.Size = new System.Drawing.Size(256, 591);
            this.pnlLeft.TabIndex = 25;
            // 
            // grbTableList
            // 
            this.grbTableList.Controls.Add(this.lisTable);
            this.grbTableList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grbTableList.Location = new System.Drawing.Point(5, 41);
            this.grbTableList.Name = "grbTableList";
            this.grbTableList.Size = new System.Drawing.Size(251, 545);
            this.grbTableList.TabIndex = 4;
            this.grbTableList.TabStop = false;
            this.grbTableList.Text = "Table List";
            // 
            // lisTable
            // 
            this.lisTable.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader2,
            this.ColumnHeader3});
            this.lisTable.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisTable.FullRowSelect = true;
            this.lisTable.HideSelection = false;
            this.lisTable.Location = new System.Drawing.Point(3, 16);
            this.lisTable.MultiSelect = false;
            this.lisTable.Name = "lisTable";
            this.lisTable.Size = new System.Drawing.Size(245, 526);
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
            this.pnlViewType.Size = new System.Drawing.Size(251, 41);
            this.pnlViewType.TabIndex = 3;
            // 
            // grpDBViewType
            // 
            this.grpDBViewType.Controls.Add(this.rbTarget);
            this.grpDBViewType.Controls.Add(this.rbSource);
            this.grpDBViewType.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpDBViewType.Location = new System.Drawing.Point(0, 0);
            this.grpDBViewType.Name = "grpDBViewType";
            this.grpDBViewType.Size = new System.Drawing.Size(251, 41);
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
            // frmDBReplicator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(878, 599);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.splMain);
            this.Controls.Add(this.pnlLeft);
            this.Controls.Add(this.pnlTop);
            this.MinimumSize = new System.Drawing.Size(644, 626);
            this.Name = "frmDBReplicator";
            this.Text = "Replication Database";
            this.Load += new System.EventHandler(this.frmDBReplicator_Load);
            this.Activated += new System.EventHandler(this.frmDBReplicator_Activated);
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
            this.pageCode.ResumeLayout(false);
            this.pnlCodeFill.ResumeLayout(false);
            this.pnlScript.ResumeLayout(false);
            this.pnlSQLSave.ResumeLayout(false);
            this.grbSave.ResumeLayout(false);
            this.grbSave.PerformLayout();
            this.pnlLeft.ResumeLayout(false);
            this.grbTableList.ResumeLayout(false);
            this.pnlViewType.ResumeLayout(false);
            this.grpDBViewType.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        internal System.Windows.Forms.Panel pnlGenInfo;
        internal System.Windows.Forms.GroupBox grpGenInfo;
        internal System.Windows.Forms.RadioButton rbOracleJob;
        internal System.Windows.Forms.RadioButton rbOnDemand;
        internal System.Windows.Forms.TextBox txtInterval;
        internal System.Windows.Forms.Button btnDelete;
        internal System.Windows.Forms.Button btnExecute;
        internal System.Windows.Forms.Button btnCodeGen;
        internal System.Windows.Forms.Label Label3;
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
        internal System.Windows.Forms.ListView lisColList;
        internal System.Windows.Forms.ColumnHeader ColumnHeader1;
        internal System.Windows.Forms.ColumnHeader ColumnHeader4;
        internal System.Windows.Forms.ColumnHeader ColumnHeader5;
        internal System.Windows.Forms.ColumnHeader ColumnHeader6;
        internal System.Windows.Forms.ColumnHeader ColumnHeader8;
        internal System.Windows.Forms.ColumnHeader ColumnHeader7;
        internal System.Windows.Forms.ColumnHeader ColumnHeader9;
        internal System.Windows.Forms.ColumnHeader ColumnHeader52;
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
        internal System.Windows.Forms.RadioButton rbTarget;
        internal System.Windows.Forms.Splitter splMain;
        internal System.Windows.Forms.RadioButton rbSource;
        internal System.Windows.Forms.Panel pnlLeft;
        internal System.Windows.Forms.GroupBox grbTableList;
        internal System.Windows.Forms.ListView lisTable;
        internal System.Windows.Forms.ColumnHeader ColumnHeader2;
        internal System.Windows.Forms.ColumnHeader ColumnHeader3;
        internal System.Windows.Forms.Panel pnlViewType;
        internal System.Windows.Forms.GroupBox grpDBViewType;
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.ColumnHeader colPrecision;
        internal System.Windows.Forms.TextBox txtRepIdxTablespace;
        internal System.Windows.Forms.Label label11;
        internal System.Windows.Forms.TextBox txtRepTblTablespace;
        internal System.Windows.Forms.Label label10;
        private System.Windows.Forms.CheckBox cbRTable;
        private System.Windows.Forms.CheckBox cbMView;
        internal System.Windows.Forms.Button btnCreateView;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Label label12;
        internal System.Windows.Forms.TextBox txtSchema;
    }
}