namespace Admin.ADMCore
{
    partial class frmADMBatchJob
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

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.lisDirectory = new System.Windows.Forms.ListView();
            this.columnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.txtDrive = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.lisBinary = new System.Windows.Forms.ListView();
            this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.lblStartTime = new System.Windows.Forms.Label();
            this.dtpStart = new System.Windows.Forms.DateTimePicker();
            this.txtPassword = new System.Windows.Forms.TextBox();
            this.lblPassword = new System.Windows.Forms.Label();
            this.txtUser = new System.Windows.Forms.TextBox();
            this.lblUser = new System.Windows.Forms.Label();
            this.txtJobName = new System.Windows.Forms.TextBox();
            this.lblJobName = new System.Windows.Forms.Label();
            this.grpTime = new System.Windows.Forms.GroupBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtDayWeek = new System.Windows.Forms.TextBox();
            this.txtMonth = new System.Windows.Forms.TextBox();
            this.txtDayMonth = new System.Windows.Forms.TextBox();
            this.txtHour = new System.Windows.Forms.TextBox();
            this.txtMin = new System.Windows.Forms.TextBox();
            this.txtBinary = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.grpBatchJob = new System.Windows.Forms.GroupBox();
            this.lisBatchJob = new System.Windows.Forms.ListView();
            this.pnlFind.SuspendLayout();
            this.pnlRight.SuspendLayout();
            this.pnlFilter.SuspendLayout();
            this.grpFilter.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.grpTime.SuspendLayout();
            this.grpBatchJob.SuspendLayout();
            this.SuspendLayout();
            // 
            // splMain
            // 
            this.splMain.Size = new System.Drawing.Size(4, 513);
            // 
            // pnlRight
            // 
            this.pnlRight.Controls.Add(this.groupBox4);
            this.pnlRight.Controls.Add(this.grpBatchJob);
            this.pnlRight.Size = new System.Drawing.Size(506, 513);
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.groupBox2);
            this.pnlLeft.Controls.Add(this.groupBox1);
            this.pnlLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlLeft.Size = new System.Drawing.Size(232, 513);
            // 
            // btnCreate
            // 
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Location = new System.Drawing.Point(0, 513);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(742, 513);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "SetupForm02";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.groupBox6);
            this.groupBox1.Controls.Add(this.groupBox5);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(232, 220);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Directory";
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.lisDirectory);
            this.groupBox6.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox6.Location = new System.Drawing.Point(3, 63);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(226, 154);
            this.groupBox6.TabIndex = 2;
            this.groupBox6.TabStop = false;
            // 
            // lisDirectory
            // 
            this.lisDirectory.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader3});
            this.lisDirectory.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisDirectory.Location = new System.Drawing.Point(3, 16);
            this.lisDirectory.Name = "lisDirectory";
            this.lisDirectory.Size = new System.Drawing.Size(220, 135);
            this.lisDirectory.TabIndex = 1;
            this.lisDirectory.UseCompatibleStateImageBehavior = false;
            this.lisDirectory.DoubleClick += new System.EventHandler(this.lisDirectory_DoubleClick);
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Directory";
            this.columnHeader3.Width = 230;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.txtDrive);
            this.groupBox5.Controls.Add(this.label7);
            this.groupBox5.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox5.Location = new System.Drawing.Point(3, 16);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(226, 47);
            this.groupBox5.TabIndex = 1;
            this.groupBox5.TabStop = false;
            // 
            // txtDrive
            // 
            this.txtDrive.Location = new System.Drawing.Point(45, 17);
            this.txtDrive.Name = "txtDrive";
            this.txtDrive.Size = new System.Drawing.Size(175, 20);
            this.txtDrive.TabIndex = 10;
            this.txtDrive.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtDrive_KeyPress);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label7.Location = new System.Drawing.Point(9, 20);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(41, 13);
            this.label7.TabIndex = 9;
            this.label7.Text = "Drive : ";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.lisBinary);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point(0, 220);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(232, 293);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Binary";
            // 
            // lisBinary
            // 
            this.lisBinary.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2});
            this.lisBinary.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisBinary.Location = new System.Drawing.Point(3, 16);
            this.lisBinary.Name = "lisBinary";
            this.lisBinary.Size = new System.Drawing.Size(226, 274);
            this.lisBinary.TabIndex = 0;
            this.lisBinary.UseCompatibleStateImageBehavior = false;
            this.lisBinary.Click += new System.EventHandler(this.lisBinary_Click);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "File";
            this.columnHeader1.Width = 150;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Size";
            this.columnHeader2.Width = 80;
            // 
            // groupBox4
            // 
            this.groupBox4.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox4.Controls.Add(this.lblStartTime);
            this.groupBox4.Controls.Add(this.dtpStart);
            this.groupBox4.Controls.Add(this.txtPassword);
            this.groupBox4.Controls.Add(this.lblPassword);
            this.groupBox4.Controls.Add(this.txtUser);
            this.groupBox4.Controls.Add(this.lblUser);
            this.groupBox4.Controls.Add(this.txtJobName);
            this.groupBox4.Controls.Add(this.lblJobName);
            this.groupBox4.Controls.Add(this.grpTime);
            this.groupBox4.Controls.Add(this.txtBinary);
            this.groupBox4.Controls.Add(this.label1);
            this.groupBox4.Location = new System.Drawing.Point(0, 362);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(506, 147);
            this.groupBox4.TabIndex = 3;
            this.groupBox4.TabStop = false;
            // 
            // lblStartTime
            // 
            this.lblStartTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblStartTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblStartTime.Location = new System.Drawing.Point(319, 48);
            this.lblStartTime.Name = "lblStartTime";
            this.lblStartTime.Size = new System.Drawing.Size(74, 14);
            this.lblStartTime.TabIndex = 18;
            this.lblStartTime.Text = "Start Time :";
            // 
            // dtpStart
            // 
            this.dtpStart.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dtpStart.Location = new System.Drawing.Point(399, 45);
            this.dtpStart.Name = "dtpStart";
            this.dtpStart.Size = new System.Drawing.Size(97, 20);
            this.dtpStart.TabIndex = 17;
            // 
            // txtPassword
            // 
            this.txtPassword.Location = new System.Drawing.Point(398, 71);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '*';
            this.txtPassword.Size = new System.Drawing.Size(98, 20);
            this.txtPassword.TabIndex = 16;
            // 
            // lblPassword
            // 
            this.lblPassword.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblPassword.Location = new System.Drawing.Point(319, 74);
            this.lblPassword.Name = "lblPassword";
            this.lblPassword.Size = new System.Drawing.Size(73, 14);
            this.lblPassword.TabIndex = 15;
            this.lblPassword.Text = "Password :";
            // 
            // txtUser
            // 
            this.txtUser.Location = new System.Drawing.Point(111, 71);
            this.txtUser.Name = "txtUser";
            this.txtUser.Size = new System.Drawing.Size(98, 20);
            this.txtUser.TabIndex = 14;
            // 
            // lblUser
            // 
            this.lblUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUser.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUser.Location = new System.Drawing.Point(13, 74);
            this.lblUser.Name = "lblUser";
            this.lblUser.Size = new System.Drawing.Size(90, 14);
            this.lblUser.TabIndex = 13;
            this.lblUser.Text = "User Name :";
            // 
            // txtJobName
            // 
            this.txtJobName.Location = new System.Drawing.Point(111, 45);
            this.txtJobName.Name = "txtJobName";
            this.txtJobName.Size = new System.Drawing.Size(182, 20);
            this.txtJobName.TabIndex = 12;
            // 
            // lblJobName
            // 
            this.lblJobName.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblJobName.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblJobName.Location = new System.Drawing.Point(13, 48);
            this.lblJobName.Name = "lblJobName";
            this.lblJobName.Size = new System.Drawing.Size(90, 14);
            this.lblJobName.TabIndex = 11;
            this.lblJobName.Text = "Job Name :";
            // 
            // grpTime
            // 
            this.grpTime.Controls.Add(this.label6);
            this.grpTime.Controls.Add(this.label5);
            this.grpTime.Controls.Add(this.label4);
            this.grpTime.Controls.Add(this.label3);
            this.grpTime.Controls.Add(this.label2);
            this.grpTime.Controls.Add(this.txtDayWeek);
            this.grpTime.Controls.Add(this.txtMonth);
            this.grpTime.Controls.Add(this.txtDayMonth);
            this.grpTime.Controls.Add(this.txtHour);
            this.grpTime.Controls.Add(this.txtMin);
            this.grpTime.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.grpTime.Location = new System.Drawing.Point(3, 90);
            this.grpTime.Name = "grpTime";
            this.grpTime.Size = new System.Drawing.Size(500, 54);
            this.grpTime.TabIndex = 10;
            this.grpTime.TabStop = false;
            this.grpTime.Text = "Time";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label6.Location = new System.Drawing.Point(385, 25);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(66, 13);
            this.label6.TabIndex = 12;
            this.label6.Text = "Day/Week :";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label5.Location = new System.Drawing.Point(296, 25);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(43, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Month :";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label4.Location = new System.Drawing.Point(181, 25);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(67, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Day/Month :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label3.Location = new System.Drawing.Point(87, 25);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(45, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "HOUR :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label2.Location = new System.Drawing.Point(6, 25);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(33, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "MIN :";
            // 
            // txtDayWeek
            // 
            this.txtDayWeek.Location = new System.Drawing.Point(453, 22);
            this.txtDayWeek.Name = "txtDayWeek";
            this.txtDayWeek.Size = new System.Drawing.Size(40, 20);
            this.txtDayWeek.TabIndex = 4;
            this.txtDayWeek.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // txtMonth
            // 
            this.txtMonth.Location = new System.Drawing.Point(340, 22);
            this.txtMonth.Name = "txtMonth";
            this.txtMonth.Size = new System.Drawing.Size(40, 20);
            this.txtMonth.TabIndex = 3;
            this.txtMonth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // txtDayMonth
            // 
            this.txtDayMonth.Location = new System.Drawing.Point(248, 22);
            this.txtDayMonth.Name = "txtDayMonth";
            this.txtDayMonth.Size = new System.Drawing.Size(40, 20);
            this.txtDayMonth.TabIndex = 2;
            this.txtDayMonth.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // txtHour
            // 
            this.txtHour.Location = new System.Drawing.Point(137, 22);
            this.txtHour.Name = "txtHour";
            this.txtHour.Size = new System.Drawing.Size(40, 20);
            this.txtHour.TabIndex = 1;
            this.txtHour.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // txtMin
            // 
            this.txtMin.Location = new System.Drawing.Point(41, 22);
            this.txtMin.Name = "txtMin";
            this.txtMin.Size = new System.Drawing.Size(40, 20);
            this.txtMin.TabIndex = 0;
            this.txtMin.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // txtBinary
            // 
            this.txtBinary.Location = new System.Drawing.Point(111, 19);
            this.txtBinary.Name = "txtBinary";
            this.txtBinary.Size = new System.Drawing.Size(385, 20);
            this.txtBinary.TabIndex = 8;
            // 
            // label1
            // 
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(15, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(90, 14);
            this.label1.TabIndex = 6;
            this.label1.Text = "Command :";
            // 
            // grpBatchJob
            // 
            this.grpBatchJob.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.grpBatchJob.Controls.Add(this.lisBatchJob);
            this.grpBatchJob.Location = new System.Drawing.Point(0, 3);
            this.grpBatchJob.Name = "grpBatchJob";
            this.grpBatchJob.Size = new System.Drawing.Size(506, 359);
            this.grpBatchJob.TabIndex = 2;
            this.grpBatchJob.TabStop = false;
            this.grpBatchJob.Text = "Batch Job";
            // 
            // lisBatchJob
            // 
            this.lisBatchJob.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisBatchJob.Location = new System.Drawing.Point(3, 16);
            this.lisBatchJob.Name = "lisBatchJob";
            this.lisBatchJob.Size = new System.Drawing.Size(500, 340);
            this.lisBatchJob.TabIndex = 0;
            this.lisBatchJob.UseCompatibleStateImageBehavior = false;
            this.lisBatchJob.Click += new System.EventHandler(this.lisBatchJob_Click);
            // 
            // frmADMBatchJob
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Name = "frmADMBatchJob";
            this.Text = "Setup Batch Job";
            this.Load += new System.EventHandler(this.frmADMBatchJob_Load);
            this.Activated += new System.EventHandler(this.frmADMBatchJob_Activated);
            this.pnlFind.ResumeLayout(false);
            this.pnlFind.PerformLayout();
            this.pnlRight.ResumeLayout(false);
            this.pnlFilter.ResumeLayout(false);
            this.grpFilter.ResumeLayout(false);
            this.grpFilter.PerformLayout();
            this.pnlLeft.ResumeLayout(false);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.grpTime.ResumeLayout(false);
            this.grpTime.PerformLayout();
            this.grpBatchJob.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ListView lisBinary;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.ListView lisDirectory;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtDrive;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label lblStartTime;
        private System.Windows.Forms.DateTimePicker dtpStart;
        private System.Windows.Forms.TextBox txtPassword;
        private System.Windows.Forms.Label lblPassword;
        private System.Windows.Forms.TextBox txtUser;
        private System.Windows.Forms.Label lblUser;
        private System.Windows.Forms.TextBox txtJobName;
        private System.Windows.Forms.Label lblJobName;
        private System.Windows.Forms.GroupBox grpTime;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtDayWeek;
        private System.Windows.Forms.TextBox txtMonth;
        private System.Windows.Forms.TextBox txtDayMonth;
        private System.Windows.Forms.TextBox txtHour;
        private System.Windows.Forms.TextBox txtMin;
        private System.Windows.Forms.TextBox txtBinary;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox grpBatchJob;
        private System.Windows.Forms.ListView lisBatchJob;
    }
}