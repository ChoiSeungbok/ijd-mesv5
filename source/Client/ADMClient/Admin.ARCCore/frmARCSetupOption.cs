using System.Data;
using System;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;
using System.Drawing;
using Miracom.CliFrx;
using Miracom.SECCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using Admin.COMCore;

//-----------------------------------------------------------------------------
//
//   System      : Admin.RPTCore
//   File Name   : frmARCSetupOption.vb
//   Description : Archive Option Setup
//
//   ADMIN Version : 4.0.0
//
//   Function List
//       - ClearData : Initalize form fields
//       - CheckCondition : Check the conditions before transaction
//       - Resource_Event : Event Transaction
//       - View_Resource : View Resource Information
//       - View_Event : View Event Information
//       - View_Factory_ResStatus : View Factory Resource Status Prompt
//       - ChangeStatusClear : Clear Controls
//       - ChangeFieldVisible : Change Field Visible
//
//   Detail Description
//       -
//
//   History
//   Seq     Date          Developer      Description
// ---------------------------------------------------------------------------
//     1     2005/08/30    HS Kim         Create
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

//Imports

namespace Admin.ARCCore
{
	public class frmARCSetupOption : Miracom.MESCore.SetupForm01
	{
		
		
		#region " Windows Form 디자이너에서 생성한 코드 "
		
		public frmARCSetupOption()
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
		private System.Windows.Forms.Panel pnlMid;
		private System.Windows.Forms.Panel pnlMidTop;
		private System.Windows.Forms.Panel pnlSleepTime;
		private System.Windows.Forms.Panel pnlTargetTime;
		private System.Windows.Forms.Panel pnlRollback;
		private System.Windows.Forms.Panel pnlDeletion;
		private System.Windows.Forms.Panel pnlBackup;
		private System.Windows.Forms.Panel pnlMaster;
		private System.Windows.Forms.Label lblModule;
		private Miracom.UI.Controls.MCCodeView.MCCodeView cdvModule;
		private System.Windows.Forms.Label lblFactory;
		private Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
		private System.Windows.Forms.Label lblMSec;
		private System.Windows.Forms.Label lblSec;
		private System.Windows.Forms.Label lblMin;
		private System.Windows.Forms.TextBox txtMSec;
		private System.Windows.Forms.TextBox txtSec;
		private System.Windows.Forms.TextBox txtMin;
		private System.Windows.Forms.Label lblExplain;
		private System.Windows.Forms.Label lblSlash;
		private System.Windows.Forms.TextBox txtDays;
		private System.Windows.Forms.TextBox txtTerm;
		private System.Windows.Forms.RadioButton rbnNRollbackSeg;
		private System.Windows.Forms.RadioButton rbnURollbackSeg;
		private System.Windows.Forms.RadioButton rbnNArchiveData;
		private System.Windows.Forms.RadioButton rbnDArchiveData;
		private System.Windows.Forms.RadioButton rbnBBackup;
		private System.Windows.Forms.RadioButton rbnFBackup;
		private System.Windows.Forms.RadioButton rbnDBackup;
		private System.Windows.Forms.GroupBox grpSleepTime;
		private System.Windows.Forms.GroupBox grpTargetTime;
		private System.Windows.Forms.GroupBox grpRollback;
		private System.Windows.Forms.GroupBox grpDeletion;
		private System.Windows.Forms.GroupBox grpBackup;
		private System.Windows.Forms.GroupBox grpMaster;
		private System.Windows.Forms.Panel pnlMidMid;
		private System.Windows.Forms.RadioButton rbnNBackup;
		private System.Windows.Forms.RadioButton rbnMasNone;
		private System.Windows.Forms.RadioButton rbnMasDel;
		private System.Windows.Forms.GroupBox grpOption;
		[System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
		{
            this.pnlMid = new System.Windows.Forms.Panel();
            this.pnlMidMid = new System.Windows.Forms.Panel();
            this.pnlMaster = new System.Windows.Forms.Panel();
            this.grpMaster = new System.Windows.Forms.GroupBox();
            this.rbnMasNone = new System.Windows.Forms.RadioButton();
            this.rbnMasDel = new System.Windows.Forms.RadioButton();
            this.pnlBackup = new System.Windows.Forms.Panel();
            this.grpBackup = new System.Windows.Forms.GroupBox();
            this.rbnNBackup = new System.Windows.Forms.RadioButton();
            this.rbnBBackup = new System.Windows.Forms.RadioButton();
            this.rbnFBackup = new System.Windows.Forms.RadioButton();
            this.rbnDBackup = new System.Windows.Forms.RadioButton();
            this.pnlDeletion = new System.Windows.Forms.Panel();
            this.grpDeletion = new System.Windows.Forms.GroupBox();
            this.rbnNArchiveData = new System.Windows.Forms.RadioButton();
            this.rbnDArchiveData = new System.Windows.Forms.RadioButton();
            this.pnlRollback = new System.Windows.Forms.Panel();
            this.grpRollback = new System.Windows.Forms.GroupBox();
            this.rbnNRollbackSeg = new System.Windows.Forms.RadioButton();
            this.rbnURollbackSeg = new System.Windows.Forms.RadioButton();
            this.pnlTargetTime = new System.Windows.Forms.Panel();
            this.grpTargetTime = new System.Windows.Forms.GroupBox();
            this.lblExplain = new System.Windows.Forms.Label();
            this.lblSlash = new System.Windows.Forms.Label();
            this.txtDays = new System.Windows.Forms.TextBox();
            this.txtTerm = new System.Windows.Forms.TextBox();
            this.pnlSleepTime = new System.Windows.Forms.Panel();
            this.grpSleepTime = new System.Windows.Forms.GroupBox();
            this.lblMSec = new System.Windows.Forms.Label();
            this.lblSec = new System.Windows.Forms.Label();
            this.lblMin = new System.Windows.Forms.Label();
            this.txtMSec = new System.Windows.Forms.TextBox();
            this.txtSec = new System.Windows.Forms.TextBox();
            this.txtMin = new System.Windows.Forms.TextBox();
            this.pnlMidTop = new System.Windows.Forms.Panel();
            this.grpOption = new System.Windows.Forms.GroupBox();
            this.lblModule = new System.Windows.Forms.Label();
            this.cdvModule = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.pnlBottom.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.pnlMidMid.SuspendLayout();
            this.pnlMaster.SuspendLayout();
            this.grpMaster.SuspendLayout();
            this.pnlBackup.SuspendLayout();
            this.grpBackup.SuspendLayout();
            this.pnlDeletion.SuspendLayout();
            this.grpDeletion.SuspendLayout();
            this.pnlRollback.SuspendLayout();
            this.grpRollback.SuspendLayout();
            this.pnlTargetTime.SuspendLayout();
            this.grpTargetTime.SuspendLayout();
            this.pnlSleepTime.SuspendLayout();
            this.grpSleepTime.SuspendLayout();
            this.pnlMidTop.SuspendLayout();
            this.grpOption.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvModule)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            this.SuspendLayout();
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
            this.pnlBottom.Location = new System.Drawing.Point(0, 517);
            this.pnlBottom.Size = new System.Drawing.Size(742, 36);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(742, 517);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "SetupForm01";
            // 
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.pnlMidMid);
            this.pnlMid.Controls.Add(this.pnlMidTop);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(742, 517);
            this.pnlMid.TabIndex = 0;
            // 
            // pnlMidMid
            // 
            this.pnlMidMid.Controls.Add(this.pnlMaster);
            this.pnlMidMid.Controls.Add(this.pnlBackup);
            this.pnlMidMid.Controls.Add(this.pnlDeletion);
            this.pnlMidMid.Controls.Add(this.pnlRollback);
            this.pnlMidMid.Controls.Add(this.pnlTargetTime);
            this.pnlMidMid.Controls.Add(this.pnlSleepTime);
            this.pnlMidMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMidMid.Location = new System.Drawing.Point(3, 64);
            this.pnlMidMid.Name = "pnlMidMid";
            this.pnlMidMid.Size = new System.Drawing.Size(736, 453);
            this.pnlMidMid.TabIndex = 1;
            // 
            // pnlMaster
            // 
            this.pnlMaster.Controls.Add(this.grpMaster);
            this.pnlMaster.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMaster.Location = new System.Drawing.Point(0, 355);
            this.pnlMaster.Name = "pnlMaster";
            this.pnlMaster.Padding = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.pnlMaster.Size = new System.Drawing.Size(736, 98);
            this.pnlMaster.TabIndex = 5;
            // 
            // grpMaster
            // 
            this.grpMaster.Controls.Add(this.rbnMasNone);
            this.grpMaster.Controls.Add(this.rbnMasDel);
            this.grpMaster.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpMaster.Location = new System.Drawing.Point(0, 3);
            this.grpMaster.Name = "grpMaster";
            this.grpMaster.Size = new System.Drawing.Size(736, 92);
            this.grpMaster.TabIndex = 0;
            this.grpMaster.TabStop = false;
            this.grpMaster.Text = "Master Table Deletion";
            // 
            // rbnMasNone
            // 
            this.rbnMasNone.Location = new System.Drawing.Point(472, 24);
            this.rbnMasNone.Name = "rbnMasNone";
            this.rbnMasNone.Size = new System.Drawing.Size(200, 24);
            this.rbnMasNone.TabIndex = 1;
            this.rbnMasNone.Text = "Keep Master Table";
            // 
            // rbnMasDel
            // 
            this.rbnMasDel.Checked = true;
            this.rbnMasDel.Location = new System.Drawing.Point(52, 24);
            this.rbnMasDel.Name = "rbnMasDel";
            this.rbnMasDel.Size = new System.Drawing.Size(200, 24);
            this.rbnMasDel.TabIndex = 0;
            this.rbnMasDel.TabStop = true;
            this.rbnMasDel.Text = "Delete Master Table";
            // 
            // pnlBackup
            // 
            this.pnlBackup.Controls.Add(this.grpBackup);
            this.pnlBackup.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlBackup.Location = new System.Drawing.Point(0, 260);
            this.pnlBackup.Name = "pnlBackup";
            this.pnlBackup.Padding = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.pnlBackup.Size = new System.Drawing.Size(736, 95);
            this.pnlBackup.TabIndex = 4;
            // 
            // grpBackup
            // 
            this.grpBackup.Controls.Add(this.rbnNBackup);
            this.grpBackup.Controls.Add(this.rbnBBackup);
            this.grpBackup.Controls.Add(this.rbnFBackup);
            this.grpBackup.Controls.Add(this.rbnDBackup);
            this.grpBackup.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpBackup.Location = new System.Drawing.Point(0, 3);
            this.grpBackup.Name = "grpBackup";
            this.grpBackup.Size = new System.Drawing.Size(736, 89);
            this.grpBackup.TabIndex = 0;
            this.grpBackup.TabStop = false;
            this.grpBackup.Text = "Archive Backup Type";
            // 
            // rbnNBackup
            // 
            this.rbnNBackup.Location = new System.Drawing.Point(472, 54);
            this.rbnNBackup.Name = "rbnNBackup";
            this.rbnNBackup.Size = new System.Drawing.Size(200, 24);
            this.rbnNBackup.TabIndex = 3;
            this.rbnNBackup.Text = "None Backup";
            // 
            // rbnBBackup
            // 
            this.rbnBBackup.Location = new System.Drawing.Point(52, 54);
            this.rbnBBackup.Name = "rbnBBackup";
            this.rbnBBackup.Size = new System.Drawing.Size(200, 24);
            this.rbnBBackup.TabIndex = 2;
            this.rbnBBackup.Text = "Database + File Backup";
            // 
            // rbnFBackup
            // 
            this.rbnFBackup.Location = new System.Drawing.Point(472, 22);
            this.rbnFBackup.Name = "rbnFBackup";
            this.rbnFBackup.Size = new System.Drawing.Size(200, 24);
            this.rbnFBackup.TabIndex = 1;
            this.rbnFBackup.Text = "File Backup";
            // 
            // rbnDBackup
            // 
            this.rbnDBackup.Checked = true;
            this.rbnDBackup.Location = new System.Drawing.Point(52, 22);
            this.rbnDBackup.Name = "rbnDBackup";
            this.rbnDBackup.Size = new System.Drawing.Size(200, 24);
            this.rbnDBackup.TabIndex = 0;
            this.rbnDBackup.TabStop = true;
            this.rbnDBackup.Text = "Database Backup";
            // 
            // pnlDeletion
            // 
            this.pnlDeletion.Controls.Add(this.grpDeletion);
            this.pnlDeletion.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlDeletion.Location = new System.Drawing.Point(0, 195);
            this.pnlDeletion.Name = "pnlDeletion";
            this.pnlDeletion.Padding = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.pnlDeletion.Size = new System.Drawing.Size(736, 65);
            this.pnlDeletion.TabIndex = 3;
            // 
            // grpDeletion
            // 
            this.grpDeletion.Controls.Add(this.rbnNArchiveData);
            this.grpDeletion.Controls.Add(this.rbnDArchiveData);
            this.grpDeletion.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpDeletion.Location = new System.Drawing.Point(0, 3);
            this.grpDeletion.Name = "grpDeletion";
            this.grpDeletion.Size = new System.Drawing.Size(736, 59);
            this.grpDeletion.TabIndex = 0;
            this.grpDeletion.TabStop = false;
            this.grpDeletion.Text = "Archive Data Deletion";
            // 
            // rbnNArchiveData
            // 
            this.rbnNArchiveData.Location = new System.Drawing.Point(472, 22);
            this.rbnNArchiveData.Name = "rbnNArchiveData";
            this.rbnNArchiveData.Size = new System.Drawing.Size(188, 24);
            this.rbnNArchiveData.TabIndex = 1;
            this.rbnNArchiveData.Text = "Keep Archive Data";
            // 
            // rbnDArchiveData
            // 
            this.rbnDArchiveData.Checked = true;
            this.rbnDArchiveData.Location = new System.Drawing.Point(52, 22);
            this.rbnDArchiveData.Name = "rbnDArchiveData";
            this.rbnDArchiveData.Size = new System.Drawing.Size(152, 24);
            this.rbnDArchiveData.TabIndex = 0;
            this.rbnDArchiveData.TabStop = true;
            this.rbnDArchiveData.Text = "Delete Archive Data";
            // 
            // pnlRollback
            // 
            this.pnlRollback.Controls.Add(this.grpRollback);
            this.pnlRollback.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlRollback.Location = new System.Drawing.Point(0, 130);
            this.pnlRollback.Name = "pnlRollback";
            this.pnlRollback.Padding = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.pnlRollback.Size = new System.Drawing.Size(736, 65);
            this.pnlRollback.TabIndex = 2;
            // 
            // grpRollback
            // 
            this.grpRollback.Controls.Add(this.rbnNRollbackSeg);
            this.grpRollback.Controls.Add(this.rbnURollbackSeg);
            this.grpRollback.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpRollback.Location = new System.Drawing.Point(0, 3);
            this.grpRollback.Name = "grpRollback";
            this.grpRollback.Size = new System.Drawing.Size(736, 59);
            this.grpRollback.TabIndex = 0;
            this.grpRollback.TabStop = false;
            this.grpRollback.Text = "Rollback Segment Usage";
            // 
            // rbnNRollbackSeg
            // 
            this.rbnNRollbackSeg.Checked = true;
            this.rbnNRollbackSeg.Location = new System.Drawing.Point(52, 22);
            this.rbnNRollbackSeg.Name = "rbnNRollbackSeg";
            this.rbnNRollbackSeg.Size = new System.Drawing.Size(184, 24);
            this.rbnNRollbackSeg.TabIndex = 0;
            this.rbnNRollbackSeg.TabStop = true;
            this.rbnNRollbackSeg.Text = "Not Use Rollback Segment";
            // 
            // rbnURollbackSeg
            // 
            this.rbnURollbackSeg.Location = new System.Drawing.Point(472, 22);
            this.rbnURollbackSeg.Name = "rbnURollbackSeg";
            this.rbnURollbackSeg.Size = new System.Drawing.Size(152, 24);
            this.rbnURollbackSeg.TabIndex = 1;
            this.rbnURollbackSeg.Text = "Use Rollback Segment";
            // 
            // pnlTargetTime
            // 
            this.pnlTargetTime.Controls.Add(this.grpTargetTime);
            this.pnlTargetTime.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTargetTime.Location = new System.Drawing.Point(0, 65);
            this.pnlTargetTime.Name = "pnlTargetTime";
            this.pnlTargetTime.Padding = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.pnlTargetTime.Size = new System.Drawing.Size(736, 65);
            this.pnlTargetTime.TabIndex = 1;
            // 
            // grpTargetTime
            // 
            this.grpTargetTime.Controls.Add(this.lblExplain);
            this.grpTargetTime.Controls.Add(this.lblSlash);
            this.grpTargetTime.Controls.Add(this.txtDays);
            this.grpTargetTime.Controls.Add(this.txtTerm);
            this.grpTargetTime.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpTargetTime.Location = new System.Drawing.Point(0, 3);
            this.grpTargetTime.Name = "grpTargetTime";
            this.grpTargetTime.Size = new System.Drawing.Size(736, 59);
            this.grpTargetTime.TabIndex = 0;
            this.grpTargetTime.TabStop = false;
            this.grpTargetTime.Text = "Archive Target Period";
            // 
            // lblExplain
            // 
            this.lblExplain.AutoSize = true;
            this.lblExplain.Location = new System.Drawing.Point(312, 25);
            this.lblExplain.Name = "lblExplain";
            this.lblExplain.Size = new System.Drawing.Size(361, 13);
            this.lblExplain.TabIndex = 3;
            this.lblExplain.Text = "Ex) 30 / 365 => Archive Data which 30 days passed among 1 year passed.";
            // 
            // lblSlash
            // 
            this.lblSlash.AutoSize = true;
            this.lblSlash.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSlash.Location = new System.Drawing.Point(145, 24);
            this.lblSlash.Name = "lblSlash";
            this.lblSlash.Size = new System.Drawing.Size(13, 16);
            this.lblSlash.TabIndex = 2;
            this.lblSlash.Text = "/";
            // 
            // txtDays
            // 
            this.txtDays.Location = new System.Drawing.Point(52, 23);
            this.txtDays.Name = "txtDays";
            this.txtDays.Size = new System.Drawing.Size(72, 20);
            this.txtDays.TabIndex = 0;
            this.txtDays.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtDays.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtDay_KeyPress);
            // 
            // txtTerm
            // 
            this.txtTerm.Location = new System.Drawing.Point(175, 23);
            this.txtTerm.Name = "txtTerm";
            this.txtTerm.Size = new System.Drawing.Size(69, 20);
            this.txtTerm.TabIndex = 1;
            this.txtTerm.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtTerm.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtTerm_KeyPress);
            // 
            // pnlSleepTime
            // 
            this.pnlSleepTime.Controls.Add(this.grpSleepTime);
            this.pnlSleepTime.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlSleepTime.Location = new System.Drawing.Point(0, 0);
            this.pnlSleepTime.Name = "pnlSleepTime";
            this.pnlSleepTime.Padding = new System.Windows.Forms.Padding(0, 3, 0, 3);
            this.pnlSleepTime.Size = new System.Drawing.Size(736, 65);
            this.pnlSleepTime.TabIndex = 0;
            // 
            // grpSleepTime
            // 
            this.grpSleepTime.Controls.Add(this.lblMSec);
            this.grpSleepTime.Controls.Add(this.lblSec);
            this.grpSleepTime.Controls.Add(this.lblMin);
            this.grpSleepTime.Controls.Add(this.txtMSec);
            this.grpSleepTime.Controls.Add(this.txtSec);
            this.grpSleepTime.Controls.Add(this.txtMin);
            this.grpSleepTime.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpSleepTime.Location = new System.Drawing.Point(0, 3);
            this.grpSleepTime.Name = "grpSleepTime";
            this.grpSleepTime.Size = new System.Drawing.Size(736, 59);
            this.grpSleepTime.TabIndex = 0;
            this.grpSleepTime.TabStop = false;
            this.grpSleepTime.Text = "Archive Speed";
            // 
            // lblMSec
            // 
            this.lblMSec.AutoSize = true;
            this.lblMSec.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblMSec.Location = new System.Drawing.Point(607, 29);
            this.lblMSec.Name = "lblMSec";
            this.lblMSec.Size = new System.Drawing.Size(41, 13);
            this.lblMSec.TabIndex = 5;
            this.lblMSec.Text = "MiliSec";
            // 
            // lblSec
            // 
            this.lblSec.AutoSize = true;
            this.lblSec.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblSec.Location = new System.Drawing.Point(381, 29);
            this.lblSec.Name = "lblSec";
            this.lblSec.Size = new System.Drawing.Size(26, 13);
            this.lblSec.TabIndex = 3;
            this.lblSec.Text = "Sec";
            // 
            // lblMin
            // 
            this.lblMin.AutoSize = true;
            this.lblMin.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblMin.Location = new System.Drawing.Point(155, 29);
            this.lblMin.Name = "lblMin";
            this.lblMin.Size = new System.Drawing.Size(24, 13);
            this.lblMin.TabIndex = 1;
            this.lblMin.Text = "Min";
            // 
            // txtMSec
            // 
            this.txtMSec.Location = new System.Drawing.Point(504, 22);
            this.txtMSec.Name = "txtMSec";
            this.txtMSec.Size = new System.Drawing.Size(100, 20);
            this.txtMSec.TabIndex = 4;
            this.txtMSec.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtMSec.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtMSec_KeyPress);
            // 
            // txtSec
            // 
            this.txtSec.Location = new System.Drawing.Point(278, 22);
            this.txtSec.Name = "txtSec";
            this.txtSec.Size = new System.Drawing.Size(100, 20);
            this.txtSec.TabIndex = 2;
            this.txtSec.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtSec.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtSec_KeyPress);
            // 
            // txtMin
            // 
            this.txtMin.Location = new System.Drawing.Point(52, 22);
            this.txtMin.Name = "txtMin";
            this.txtMin.Size = new System.Drawing.Size(100, 20);
            this.txtMin.TabIndex = 0;
            this.txtMin.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtMin.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtMin_KeyPress);
            // 
            // pnlMidTop
            // 
            this.pnlMidTop.Controls.Add(this.grpOption);
            this.pnlMidTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlMidTop.Location = new System.Drawing.Point(3, 0);
            this.pnlMidTop.Name = "pnlMidTop";
            this.pnlMidTop.Padding = new System.Windows.Forms.Padding(0, 0, 0, 3);
            this.pnlMidTop.Size = new System.Drawing.Size(736, 64);
            this.pnlMidTop.TabIndex = 0;
            // 
            // grpOption
            // 
            this.grpOption.Controls.Add(this.lblModule);
            this.grpOption.Controls.Add(this.cdvModule);
            this.grpOption.Controls.Add(this.lblFactory);
            this.grpOption.Controls.Add(this.cdvFactory);
            this.grpOption.Dock = System.Windows.Forms.DockStyle.Top;
            this.grpOption.Location = new System.Drawing.Point(0, 0);
            this.grpOption.Name = "grpOption";
            this.grpOption.Size = new System.Drawing.Size(736, 64);
            this.grpOption.TabIndex = 0;
            this.grpOption.TabStop = false;
            // 
            // lblModule
            // 
            this.lblModule.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblModule.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblModule.Location = new System.Drawing.Point(428, 28);
            this.lblModule.Name = "lblModule";
            this.lblModule.Size = new System.Drawing.Size(60, 14);
            this.lblModule.TabIndex = 2;
            this.lblModule.Text = "Module";
            // 
            // cdvModule
            // 
            this.cdvModule.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvModule.BtnToolTipText = "";
            this.cdvModule.DescText = "";
            this.cdvModule.DisplaySubItemIndex = -1;
            this.cdvModule.DisplayText = "";
            this.cdvModule.Focusing = null;
            this.cdvModule.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvModule.Index = 0;
            this.cdvModule.IsViewBtnImage = false;
            this.cdvModule.Location = new System.Drawing.Point(504, 24);
            this.cdvModule.MaxLength = 10;
            this.cdvModule.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvModule.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvModule.Name = "cdvModule";
            this.cdvModule.ReadOnly = false;
            this.cdvModule.SearchSubItemIndex = 0;
            this.cdvModule.SelectedDescIndex = -1;
            this.cdvModule.SelectedSubItemIndex = -1;
            this.cdvModule.SelectionStart = 0;
            this.cdvModule.Size = new System.Drawing.Size(150, 20);
            this.cdvModule.SmallImageList = null;
            this.cdvModule.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvModule.TabIndex = 3;
            this.cdvModule.TextBoxToolTipText = "";
            this.cdvModule.TextBoxWidth = 150;
            this.cdvModule.VisibleButton = true;
            this.cdvModule.VisibleColumnHeader = false;
            this.cdvModule.VisibleDescription = false;
            this.cdvModule.ButtonPress += new System.EventHandler(this.cdvModule_ButtonPress);
            this.cdvModule.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvModule_SelectedItemChanged);
            // 
            // lblFactory
            // 
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFactory.Location = new System.Drawing.Point(24, 28);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(60, 14);
            this.lblFactory.TabIndex = 0;
            this.lblFactory.Text = "Factory";
            // 
            // cdvFactory
            // 
            this.cdvFactory.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvFactory.BtnToolTipText = "";
            this.cdvFactory.DescText = "";
            this.cdvFactory.DisplaySubItemIndex = -1;
            this.cdvFactory.DisplayText = "";
            this.cdvFactory.Focusing = null;
            this.cdvFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvFactory.Index = 0;
            this.cdvFactory.IsViewBtnImage = false;
            this.cdvFactory.Location = new System.Drawing.Point(100, 24);
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
            // 
            // frmARCSetupOption
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Controls.Add(this.pnlMid);
            this.Name = "frmARCSetupOption";
            this.Text = "Archive Option Setup";
            this.Load += new System.EventHandler(this.frmARCSetupOption_Load);
            this.Activated += new System.EventHandler(this.frmARCSetupOption_Activated);
            this.Controls.SetChildIndex(this.pnlBottom, 0);
            this.Controls.SetChildIndex(this.pnlCenter, 0);
            this.Controls.SetChildIndex(this.pnlMid, 0);
            this.Controls.SetChildIndex(this.pnlTop, 0);
            this.pnlBottom.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.pnlMidMid.ResumeLayout(false);
            this.pnlMaster.ResumeLayout(false);
            this.grpMaster.ResumeLayout(false);
            this.pnlBackup.ResumeLayout(false);
            this.grpBackup.ResumeLayout(false);
            this.pnlDeletion.ResumeLayout(false);
            this.grpDeletion.ResumeLayout(false);
            this.pnlRollback.ResumeLayout(false);
            this.grpRollback.ResumeLayout(false);
            this.pnlTargetTime.ResumeLayout(false);
            this.grpTargetTime.ResumeLayout(false);
            this.grpTargetTime.PerformLayout();
            this.pnlSleepTime.ResumeLayout(false);
            this.grpSleepTime.ResumeLayout(false);
            this.grpSleepTime.PerformLayout();
            this.pnlMidTop.ResumeLayout(false);
            this.grpOption.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvModule)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            this.ResumeLayout(false);

		}
		
		#endregion
		
		#region " Variable Definition "
		
		private bool bLoadFlag;
		
		#endregion
		
		#region " Function Definition"
		//
		// ClearData()
		//       - Initalize form fields
		// Return Value
		//       -
		// Arguments
		//       - Optional ByVal ProcStep As String ("1", "2", "3")
		//
		
		private void ClearData(string ProcStep)
		{			
			try
			{				
				txtMin.Text = "";
				txtSec.Text = "";
				txtMSec.Text = "";
				txtTerm.Text = "";
				txtDays.Text = "";
				rbnDArchiveData.Checked = true;
				rbnNRollbackSeg.Checked = true;
				rbnDBackup.Checked = true;
                rbnMasDel.Checked = true;
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}			
		}
		
		// CheckCondition()
		//       -   Check update factory condition
		// Return Value
		//       -
		// Arguments
		//       -
		private bool CheckCondition(string sFunc)
		{
			
			if (MPCF.CheckValue(cdvFactory, 1) == false)
			{
				return false;
			}
            if (MPCF.CheckValue(cdvModule, 1) == false)
			{
				return false;
			}
			
			switch (sFunc)
			{
				case "CREATE":
					if (txtTerm.Text.Trim() == "")
					{
						txtTerm.Text = "";
                        MPCF.ShowMsgBox(MPCF.GetMessage(107));
						txtTerm.Focus();
						return false;
					}
					break;
					
					
				case "UPDATE":
					
					if (txtTerm.Text.Trim() == "")
					{
						txtTerm.Text = "";
                        MPCF.ShowMsgBox(MPCF.GetMessage(107));
						txtTerm.Focus();
						return false;
					}
					break;
					
				case "FACTORY_DELETE":
					
					break;
					
			}
			
			return true;
			
		}
		
		// Update_Archive_Option()
		//       - Update Archive Option
		// Return Value
		//       - boolean : True / False
		// Arguments
		//		- ByVal sStep As String : MP_STEP_CREATE/UPDATE/DELETE
		private bool Update_Archive_Option(char sStep)
		{
            TRSNode in_node = new TRSNode("UPDATE_ARCHIVE_OPT_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = sStep;

            in_node.AddString("ARCHIVE_FACTORY", MPCF.Trim(cdvFactory.Text));
            in_node.AddString("MODULE_NAME", MPCF.Trim(cdvModule.Text));

            if (MPCF.CheckNumeric(txtMin.Text) == false)
            {
                txtMin.Text = "0";
            }
            if (MPCF.CheckNumeric(txtSec.Text) == false)
            {
                txtSec.Text = "0";
            }
            if (MPCF.CheckNumeric(txtMSec.Text) == false)
            {
                txtMSec.Text = "0";
            }

            if (MPCF.CheckNumeric(txtTerm.Text) == false)
            {
                txtTerm.Text = "365";
            }
            if (MPCF.CheckNumeric(txtDays.Text) == false)
            {
                txtDays.Text = "1";
            }

            in_node.AddInt("SPD_TIME", System.Convert.ToInt32(txtMin.Text) * 60000 + System.Convert.ToInt32(txtSec.Text) * 1000 + System.Convert.ToInt32(txtMSec.Text));
            in_node.AddInt("TERM", System.Convert.ToInt32(txtTerm.Text));
            in_node.AddInt("DAYS", System.Convert.ToInt32(txtDays.Text));

            if (rbnDArchiveData.Checked == true)
            {
                in_node.AddChar("MOD_TYPE", MPCF.ToChar(MPGC.ARC_SOURCE_DELETE));
            }
            else
            {
                in_node.AddChar("MOD_TYPE", MPCF.ToChar(MPGC.ARC_SOURCE_UNDELETE));
            }

            if (rbnURollbackSeg.Checked == true)
            {
                in_node.AddChar("ROL_FLAG", MPCF.ToChar(MPGC.ARC_ROLLBACK_USE));
            }
            else
            {
                in_node.AddChar("ROL_FLAG", MPCF.ToChar(MPGC.ARC_ROLLBACK_NOTUSE));
            }

            if (rbnDBackup.Checked == true)
            {
                in_node.AddChar("MED_TYPE", MPCF.ToChar(MPGC.ARC_BACKUP_DB));
            }
            else if (rbnFBackup.Checked == true)
            {
                in_node.AddChar("MED_TYPE", MPCF.ToChar(MPGC.ARC_BACKUP_FILE));
            }
            else if (rbnBBackup.Checked == true)
            {
                in_node.AddChar("MED_TYPE", MPCF.ToChar(MPGC.ARC_BACKUP_FILE_DB));
            }

            in_node.AddChar("MAS_DEL_FLAG", rbnMasDel.Checked == true ? 'Y' : 'N');

            if (MPCR.CallService("ARC", "ARC_Update_Archive_Opt", in_node, ref out_node) == false)
            {
                return false;
            }

            MPCR.ShowSuccessMsg(out_node);

            return true;
		}
		
		private void ViewArchiveOption(string sFactory, string sModule)
		{
            TRSNode in_node = new TRSNode("VIEW_ARCHIVE_OPT_DETAIL_IN");
            TRSNode out_node = new TRSNode("VIEW_ARCHIVE_OPT_DETAIL_OUT");

            MPCR.SetInMsg(in_node);

            in_node.AddString("TARGET_FACTORY", sFactory.Trim());

            in_node.AddString("MODULE_NAME", sModule.Trim());

            if (MPCR.CallService("ARC", "ARC_View_Archive_Opt_Detail", in_node, ref out_node) == false)
            {
                return;
            }

            if (out_node.GetInt("SPD_TIME") > 0)
            {
                txtMin.Text = Convert.ToString(MPCF.ToInt(out_node.GetInt("SPD_TIME") / 60000));
                txtSec.Text = Convert.ToString(MPCF.ToInt((out_node.GetInt("SPD_TIME") - MPCF.ToInt(MPCF.ToInt(txtMin.Text) * 60000)) / 1000));
                txtMSec.Text = Convert.ToString(MPCF.ToInt(out_node.GetInt("SPD_TIME") % 1000));
            }
            else
            {
                txtMin.Text = "0";
                txtSec.Text = "0";
                txtMSec.Text = "0";
            }

            txtTerm.Text = out_node.GetInt("TERM").ToString();
            txtDays.Text = out_node.GetInt("DAYS").ToString();

            if (out_node.GetChar("MOD_TYPE").ToString() == MPGC.ARC_SOURCE_DELETE)
            {
                rbnDArchiveData.Checked = true;
            }
            else if (out_node.GetChar("MOD_TYPE").ToString() == MPGC.ARC_SOURCE_UNDELETE)
            {
                rbnNArchiveData.Checked = true;
            }

            if (out_node.GetChar("ROL_FLAG").ToString() == MPGC.ARC_ROLLBACK_USE)
            {
                rbnURollbackSeg.Checked = true;
            }
            else if (out_node.GetChar("ROL_FLAG").ToString() == MPGC.ARC_ROLLBACK_NOTUSE)
            {
                rbnNRollbackSeg.Checked = true;
            }

            if (out_node.GetChar("MED_TYPE").ToString() == MPGC.ARC_BACKUP_DB)
            {
                rbnDBackup.Checked = true;
            }
            else if (out_node.GetChar("MED_TYPE").ToString() == MPGC.ARC_BACKUP_FILE)
            {
                rbnFBackup.Checked = true;
            }
            else if (out_node.GetChar("MED_TYPE").ToString() == MPGC.ARC_BACKUP_FILE_DB)
            {
                rbnBBackup.Checked = true;
            }
            else
            {
                rbnNBackup.Checked = true;
            }

            if (out_node.GetChar("MAS_DEL_FLAG") == 'Y')
            {
                rbnMasDel.Checked = true;
            }
            else
            {
                rbnMasNone.Checked = true;
            }
		}
		
		//
		// initCodeView()
		//       - initial CodeView Control
		// Return Value
		//       -
		// Arguments
		//		-
		//
		private void initCodeView()
		{
			cdvFactory.Init();
			MPCF.InitListView(cdvFactory.GetListView);
			cdvFactory.Columns.Add("Type", 50, HorizontalAlignment.Left);
			cdvFactory.Columns.Add("Desc", 100, HorizontalAlignment.Left);
			cdvFactory.SelectedSubItemIndex = 0;
            ADCM.ViewFactoryList(cdvFactory.GetListView, '1', null);
		}
		
		#endregion
		
		private void frmARCSetupOption_Load(object sender, System.EventArgs e)
		{
			try
			{
				 
                MPCF.ToClientLanguage(this);
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
		}
		
		private void frmARCSetupOption_Activated(object sender, System.EventArgs e)
		{
			if (bLoadFlag == false)
			{
				initCodeView();
				bLoadFlag = true;
			}
		}
		
		
		private void cdvModule_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
		{
			ClearData("1");
			ViewArchiveOption(cdvFactory.Text, cdvModule.Text);
		}
		
		private void txtMin_KeyPress(System.Object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
			if (e.KeyChar != (char)8)
			{
				if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
				{
					e.Handled = true;
				}
			}
		}
		
		private void txtSec_KeyPress(System.Object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
			if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
			{
				if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
				{
					e.Handled = true;
				}
			}
		}
		
		private void txtMSec_KeyPress(System.Object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
            if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
			{
                if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
				{
					e.Handled = true;
				}
			}
		}
		
		private void txtDay_KeyPress(System.Object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
            if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
			{
				if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
				{
					e.Handled = true;
				}
			}
		}
		
		private void txtTerm_KeyPress(System.Object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
			if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
			{
                if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
				{
					e.Handled = true;
				}
			}
		}
		
		private void btnCreate_Click(System.Object sender, System.EventArgs e)
		{

            if (MPGV.gsFactory != cdvFactory.Text && MPGV.gsFactory != MPGV.gsCentralFactory)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(245));
                return;
            }

            if (CheckCondition("CREATE") == false)
			{
				return;
			}
			Update_Archive_Option(MPGC.MP_STEP_CREATE);
			
			ViewArchiveOption(cdvFactory.Text, cdvModule.Text);
			
		}
		
		private void btnUpdate_Click(System.Object sender, System.EventArgs e)
		{
            if (MPGV.gsFactory != cdvFactory.Text && MPGV.gsFactory != MPGV.gsCentralFactory)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(245));
                return;
            }

			if (CheckCondition("UPDATE") == false)
			{
				return;
			}
            Update_Archive_Option(MPGC.MP_STEP_UPDATE);
			
			ViewArchiveOption(cdvFactory.Text, cdvModule.Text);
			
		}
		
		private void btnDelete_Click(System.Object sender, System.EventArgs e)
		{

            if (MPGV.gsFactory != cdvFactory.Text && MPGV.gsFactory != MPGV.gsCentralFactory)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(245));
                return;
            }

            if (CheckCondition("DELETE") == false)
			{
				return;
			}
            Update_Archive_Option(MPGC.MP_STEP_DELETE);
			
			ClearData("1");
			
		}
		
		private void cdvModule_ButtonPress(System.Object sender, System.EventArgs e)
		{
			cdvModule.Init();
			MPCF.InitListView(cdvModule.GetListView);
			cdvModule.Columns.Add("Type", 50, HorizontalAlignment.Left);
			cdvModule.Columns.Add("Desc", 100, HorizontalAlignment.Left);
			cdvModule.SelectedSubItemIndex = 0;
            ADCM.ViewGCMDataList(cdvModule.GetListView, '1', MPGC.MP_ARCHIVE_MODULE, (int)SMALLICON_INDEX.IDX_CODE_DATA, null, cdvFactory.Text, true, -1, -1, null);
		}

        private void cdvFactory_ButtonPress(object sender, EventArgs e)
        {
            Miracom.UI.Controls.MCCodeView.MCCodeView cdvTemp;

            cdvTemp = (Miracom.UI.Controls.MCCodeView.MCCodeView)sender;
            ADCM.ViewFactoryList(cdvTemp.GetListView, '1', null);
        }
		
	}
	
}
