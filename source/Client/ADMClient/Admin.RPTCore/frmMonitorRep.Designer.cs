namespace Admin.RPTCore
{
    partial class frmMonitorRep
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
            this.tabColumns = new System.Windows.Forms.TabControl();
            this.pageConnect = new System.Windows.Forms.TabPage();
            this.GroupBox1 = new System.Windows.Forms.GroupBox();
            this.txtDataSource = new System.Windows.Forms.TextBox();
            this.Label4 = new System.Windows.Forms.Label();
            this.GroupBox2 = new System.Windows.Forms.GroupBox();
            this.rdoTarDB2 = new System.Windows.Forms.RadioButton();
            this.rdoTarOracle = new System.Windows.Forms.RadioButton();
            this.rdoTarMsSql = new System.Windows.Forms.RadioButton();
            this.Label5 = new System.Windows.Forms.Label();
            this.Label6 = new System.Windows.Forms.Label();
            this.Label7 = new System.Windows.Forms.Label();
            this.txtDBName = new System.Windows.Forms.TextBox();
            this.txtUserID = new System.Windows.Forms.TextBox();
            this.txtPassword = new System.Windows.Forms.TextBox();
            this.pageMonitor = new System.Windows.Forms.TabPage();
            this.lisMonitor = new System.Windows.Forms.ListView();
            this.colProc = new System.Windows.Forms.ColumnHeader();
            this.colRecord = new System.Windows.Forms.ColumnHeader();
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.btnConnect = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnView = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.txtRefreshTime = new System.Windows.Forms.TextBox();
            this.timeRefresh = new System.Windows.Forms.Timer(this.components);
            this.btnInit = new System.Windows.Forms.Button();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.tabColumns.SuspendLayout();
            this.pageConnect.SuspendLayout();
            this.GroupBox1.SuspendLayout();
            this.GroupBox2.SuspendLayout();
            this.pageMonitor.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(612, 7);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnInit);
            this.pnlBottom.Controls.Add(this.btnDisconnect);
            this.pnlBottom.Controls.Add(this.btnConnect);
            this.pnlBottom.Controls.Add(this.txtRefreshTime);
            this.pnlBottom.Controls.Add(this.btnStop);
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnRefresh);
            this.pnlBottom.Location = new System.Drawing.Point(0, 504);
            this.pnlBottom.Size = new System.Drawing.Size(734, 40);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnRefresh, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnView, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnStop, 0);
            this.pnlBottom.Controls.SetChildIndex(this.txtRefreshTime, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnConnect, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnDisconnect, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnInit, 0);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.tabColumns);
            this.pnlCenter.Size = new System.Drawing.Size(734, 504);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "BaseForm04";
            // 
            // tabColumns
            // 
            this.tabColumns.Appearance = System.Windows.Forms.TabAppearance.FlatButtons;
            this.tabColumns.Controls.Add(this.pageConnect);
            this.tabColumns.Controls.Add(this.pageMonitor);
            this.tabColumns.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabColumns.HotTrack = true;
            this.tabColumns.ItemSize = new System.Drawing.Size(100, 20);
            this.tabColumns.Location = new System.Drawing.Point(0, 0);
            this.tabColumns.Name = "tabColumns";
            this.tabColumns.SelectedIndex = 0;
            this.tabColumns.Size = new System.Drawing.Size(734, 504);
            this.tabColumns.SizeMode = System.Windows.Forms.TabSizeMode.Fixed;
            this.tabColumns.TabIndex = 2;
            this.tabColumns.SelectedIndexChanged += new System.EventHandler(this.tabColumns_SelectedIndexChanged);
            // 
            // pageConnect
            // 
            this.pageConnect.Controls.Add(this.GroupBox1);
            this.pageConnect.Location = new System.Drawing.Point(4, 24);
            this.pageConnect.Name = "pageConnect";
            this.pageConnect.Size = new System.Drawing.Size(726, 476);
            this.pageConnect.TabIndex = 2;
            this.pageConnect.Text = "Connect";
            this.pageConnect.UseVisualStyleBackColor = true;
            // 
            // GroupBox1
            // 
            this.GroupBox1.Controls.Add(this.txtDataSource);
            this.GroupBox1.Controls.Add(this.Label4);
            this.GroupBox1.Controls.Add(this.GroupBox2);
            this.GroupBox1.Controls.Add(this.Label5);
            this.GroupBox1.Controls.Add(this.Label6);
            this.GroupBox1.Controls.Add(this.Label7);
            this.GroupBox1.Controls.Add(this.txtDBName);
            this.GroupBox1.Controls.Add(this.txtUserID);
            this.GroupBox1.Controls.Add(this.txtPassword);
            this.GroupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.GroupBox1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.GroupBox1.Location = new System.Drawing.Point(0, 0);
            this.GroupBox1.Name = "GroupBox1";
            this.GroupBox1.Size = new System.Drawing.Size(726, 476);
            this.GroupBox1.TabIndex = 2;
            this.GroupBox1.TabStop = false;
            this.GroupBox1.Text = "DB";
            // 
            // txtDataSource
            // 
            this.txtDataSource.Enabled = false;
            this.txtDataSource.Location = new System.Drawing.Point(166, 115);
            this.txtDataSource.Name = "txtDataSource";
            this.txtDataSource.Size = new System.Drawing.Size(144, 20);
            this.txtDataSource.TabIndex = 1;
            // 
            // Label4
            // 
            this.Label4.AutoSize = true;
            this.Label4.Enabled = false;
            this.Label4.Location = new System.Drawing.Point(62, 115);
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
            this.GroupBox2.Location = new System.Drawing.Point(46, 59);
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
            this.Label5.Location = new System.Drawing.Point(62, 211);
            this.Label5.Name = "Label5";
            this.Label5.Size = new System.Drawing.Size(53, 13);
            this.Label5.TabIndex = 6;
            this.Label5.Text = "Password";
            this.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Label6
            // 
            this.Label6.AutoSize = true;
            this.Label6.Location = new System.Drawing.Point(62, 179);
            this.Label6.Name = "Label6";
            this.Label6.Size = new System.Drawing.Size(43, 13);
            this.Label6.TabIndex = 4;
            this.Label6.Text = "User ID";
            this.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Label7
            // 
            this.Label7.AutoSize = true;
            this.Label7.Location = new System.Drawing.Point(62, 147);
            this.Label7.Name = "Label7";
            this.Label7.Size = new System.Drawing.Size(53, 13);
            this.Label7.TabIndex = 2;
            this.Label7.Text = "DB Name";
            this.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtDBName
            // 
            this.txtDBName.Location = new System.Drawing.Point(166, 147);
            this.txtDBName.Name = "txtDBName";
            this.txtDBName.Size = new System.Drawing.Size(144, 20);
            this.txtDBName.TabIndex = 7;
            // 
            // txtUserID
            // 
            this.txtUserID.Location = new System.Drawing.Point(166, 179);
            this.txtUserID.Name = "txtUserID";
            this.txtUserID.Size = new System.Drawing.Size(144, 20);
            this.txtUserID.TabIndex = 8;
            // 
            // txtPassword
            // 
            this.txtPassword.Location = new System.Drawing.Point(166, 211);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '*';
            this.txtPassword.Size = new System.Drawing.Size(144, 20);
            this.txtPassword.TabIndex = 9;
            // 
            // pageMonitor
            // 
            this.pageMonitor.Controls.Add(this.lisMonitor);
            this.pageMonitor.Location = new System.Drawing.Point(4, 24);
            this.pageMonitor.Name = "pageMonitor";
            this.pageMonitor.Size = new System.Drawing.Size(734, 478);
            this.pageMonitor.TabIndex = 0;
            this.pageMonitor.Text = "Monitoring";
            this.pageMonitor.UseVisualStyleBackColor = true;
            // 
            // lisMonitor
            // 
            this.lisMonitor.CheckBoxes = true;
            this.lisMonitor.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colProc,
            this.colRecord});
            this.lisMonitor.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisMonitor.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisMonitor.Location = new System.Drawing.Point(0, 0);
            this.lisMonitor.Name = "lisMonitor";
            this.lisMonitor.Size = new System.Drawing.Size(734, 478);
            this.lisMonitor.TabIndex = 0;
            this.lisMonitor.UseCompatibleStateImageBehavior = false;
            this.lisMonitor.View = System.Windows.Forms.View.Details;
            // 
            // colProc
            // 
            this.colProc.Text = "Process Name";
            this.colProc.Width = 200;
            // 
            // colRecord
            // 
            this.colRecord.Text = "Record count for replication";
            this.colRecord.Width = 300;
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Location = new System.Drawing.Point(536, 7);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(88, 26);
            this.btnDisconnect.TabIndex = 16;
            this.btnDisconnect.Text = "Disconnect";
            this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(443, 7);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(88, 26);
            this.btnConnect.TabIndex = 15;
            this.btnConnect.Text = "Connect";
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(536, 7);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(88, 26);
            this.btnStop.TabIndex = 19;
            this.btnStop.Text = "Stop Proc";
            this.btnStop.Visible = false;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnView
            // 
            this.btnView.Location = new System.Drawing.Point(443, 7);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(88, 26);
            this.btnView.TabIndex = 18;
            this.btnView.Text = "View";
            this.btnView.Visible = false;
            this.btnView.Click += new System.EventHandler(this.btnView_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(69, 8);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(88, 26);
            this.btnRefresh.TabIndex = 17;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.Visible = false;
            this.btnRefresh.Click += new System.EventHandler(this.btnRefresh_Click);
            // 
            // txtRefreshTime
            // 
            this.txtRefreshTime.Location = new System.Drawing.Point(9, 10);
            this.txtRefreshTime.Name = "txtRefreshTime";
            this.txtRefreshTime.Size = new System.Drawing.Size(54, 20);
            this.txtRefreshTime.TabIndex = 20;
            this.txtRefreshTime.Visible = false;
            // 
            // timeRefresh
            // 
            this.timeRefresh.Tick += new System.EventHandler(this.timeRefresh_Tick);
            // 
            // btnInit
            // 
            this.btnInit.Location = new System.Drawing.Point(349, 7);
            this.btnInit.Name = "btnInit";
            this.btnInit.Size = new System.Drawing.Size(88, 26);
            this.btnInit.TabIndex = 21;
            this.btnInit.Text = "Initial";
            this.btnInit.Visible = false;
            this.btnInit.Click += new System.EventHandler(this.btnInit_Click);
            // 
            // frmMonitorRep
            // 
            this.AcceptButton = this.btnConnect;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(734, 544);
            this.Name = "frmMonitorRep";
            this.Text = "Monitoring status of replication";
            this.Load += new System.EventHandler(this.frmMonitorRep_Load);
            this.Activated += new System.EventHandler(this.frmMonitorRep_Activated);
            this.pnlBottom.ResumeLayout(false);
            this.pnlBottom.PerformLayout();
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.tabColumns.ResumeLayout(false);
            this.pageConnect.ResumeLayout(false);
            this.GroupBox1.ResumeLayout(false);
            this.GroupBox1.PerformLayout();
            this.GroupBox2.ResumeLayout(false);
            this.pageMonitor.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        internal System.Windows.Forms.TabControl tabColumns;
        internal System.Windows.Forms.TabPage pageConnect;
        internal System.Windows.Forms.TabPage pageMonitor;
        private System.Windows.Forms.ColumnHeader colProc;
        private System.Windows.Forms.ColumnHeader colRecord;
        internal System.Windows.Forms.GroupBox GroupBox1;
        internal System.Windows.Forms.TextBox txtDataSource;
        internal System.Windows.Forms.Label Label4;
        internal System.Windows.Forms.GroupBox GroupBox2;
        internal System.Windows.Forms.RadioButton rdoTarDB2;
        internal System.Windows.Forms.RadioButton rdoTarOracle;
        internal System.Windows.Forms.RadioButton rdoTarMsSql;
        internal System.Windows.Forms.Label Label5;
        internal System.Windows.Forms.Label Label6;
        internal System.Windows.Forms.Label Label7;
        internal System.Windows.Forms.TextBox txtDBName;
        internal System.Windows.Forms.TextBox txtUserID;
        internal System.Windows.Forms.TextBox txtPassword;
        internal System.Windows.Forms.Button btnDisconnect;
        internal System.Windows.Forms.Button btnConnect;
        internal System.Windows.Forms.Button btnStop;
        internal System.Windows.Forms.Button btnView;
        internal System.Windows.Forms.Button btnRefresh;
        internal System.Windows.Forms.TextBox txtRefreshTime;
        private System.Windows.Forms.Timer timeRefresh;
        internal System.Windows.Forms.Button btnInit;
        internal System.Windows.Forms.ListView lisMonitor;



    }
}