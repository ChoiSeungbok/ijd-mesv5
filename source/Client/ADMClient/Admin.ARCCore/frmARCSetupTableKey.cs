using System.Data;
using System;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;
using System.Drawing;
using Miracom.MsgHandler;
using Miracom.CliFrx;
using Miracom.SECCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using Admin.COMCore;

//-----------------------------------------------------------------------------
//
//   System      : ADMINClient
//   File Name   : frmARCSetupTableKey.vb
//   Description : Archive Table Key Setup
//
//   ADMIN Version : 1.0.0
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
	public class frmARCSetupTableKey : Miracom.MESCore.SetupForm02
	{
		
		
		#region " Windows Form 디자이너에서 생성한 코드 "
		
		public frmARCSetupTableKey()
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
		private System.Windows.Forms.ListView lisTable;
		private System.Windows.Forms.ColumnHeader ColumnHeader1;
		private System.Windows.Forms.ColumnHeader ColumnHeader2;
		private System.Windows.Forms.TextBox txtTable;
//        private System.Windows.Forms.Panel pnlMstSlv;
//        private Miracom.UI.Controls.MCCodeView.MCCodeView cdvModule;
		private System.Windows.Forms.Panel pnlBottom2;
		private System.Windows.Forms.Panel pnlKey;
		private System.Windows.Forms.Panel pnlCols;
		private System.Windows.Forms.ListView lisCols;
		private System.Windows.Forms.ColumnHeader ColumnHeader3;
		private System.Windows.Forms.ColumnHeader ColumnHeader4;
		private System.Windows.Forms.ColumnHeader ColumnHeader5;
		private System.Windows.Forms.GroupBox grpBottom2;
		private System.Windows.Forms.TextBox txtMTable;
		private System.Windows.Forms.TextBox txtSTable;
		private System.Windows.Forms.TextBox txtSField1;
		private System.Windows.Forms.TextBox txtMField1;
		private System.Windows.Forms.TextBox txtSField3;
		private System.Windows.Forms.TextBox txtMField3;
		private System.Windows.Forms.TextBox txtSField2;
		private System.Windows.Forms.TextBox txtMField2;
		private System.Windows.Forms.Panel pnlModule;
		private System.Windows.Forms.Panel pnlKeyField;
		private System.Windows.Forms.GroupBox grpKey;
		private System.Windows.Forms.CheckBox relChk;
		private System.Windows.Forms.TextBox txtWhere;
		private System.Windows.Forms.Button btnWhere;
		private System.Windows.Forms.GroupBox grpModule;
		private System.Windows.Forms.Label lblARCModule;
		private Miracom.UI.Controls.MCCodeView.MCCodeView cdvARCModule;
		private System.Windows.Forms.Label Label1;
		private System.Windows.Forms.Label Label2;
		private System.Windows.Forms.Label Label3;
		private System.Windows.Forms.Label Label4;
		private System.Windows.Forms.Label Label5;
		private System.Windows.Forms.Label Label6;
		private System.Windows.Forms.Button btnClear;
		private System.Windows.Forms.ColumnHeader ColumnHeader8;
		private System.Windows.Forms.TextBox txtTermField;
		private System.Windows.Forms.TextBox txtKeyField3;
		private System.Windows.Forms.TextBox txtKeyField2;
		private System.Windows.Forms.TextBox txtKeyField1;
		private System.Windows.Forms.RadioButton rbnTermField;
		private System.Windows.Forms.RadioButton rbnKeyField3;
		private System.Windows.Forms.RadioButton rbnKeyField2;
		private System.Windows.Forms.RadioButton rbnKeyField1;
		[System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
		{
            this.lisTable = new System.Windows.Forms.ListView();
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.txtTable = new System.Windows.Forms.TextBox();
            this.pnlBottom2 = new System.Windows.Forms.Panel();
            this.grpBottom2 = new System.Windows.Forms.GroupBox();
            this.Label6 = new System.Windows.Forms.Label();
            this.Label5 = new System.Windows.Forms.Label();
            this.Label4 = new System.Windows.Forms.Label();
            this.Label3 = new System.Windows.Forms.Label();
            this.Label2 = new System.Windows.Forms.Label();
            this.Label1 = new System.Windows.Forms.Label();
            this.txtSField2 = new System.Windows.Forms.TextBox();
            this.txtMField2 = new System.Windows.Forms.TextBox();
            this.txtSField3 = new System.Windows.Forms.TextBox();
            this.txtMField3 = new System.Windows.Forms.TextBox();
            this.txtSField1 = new System.Windows.Forms.TextBox();
            this.txtMField1 = new System.Windows.Forms.TextBox();
            this.txtSTable = new System.Windows.Forms.TextBox();
            this.txtMTable = new System.Windows.Forms.TextBox();
            this.pnlKey = new System.Windows.Forms.Panel();
            this.pnlKeyField = new System.Windows.Forms.Panel();
            this.grpKey = new System.Windows.Forms.GroupBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.relChk = new System.Windows.Forms.CheckBox();
            this.txtWhere = new System.Windows.Forms.TextBox();
            this.btnWhere = new System.Windows.Forms.Button();
            this.txtTermField = new System.Windows.Forms.TextBox();
            this.rbnTermField = new System.Windows.Forms.RadioButton();
            this.txtKeyField3 = new System.Windows.Forms.TextBox();
            this.txtKeyField2 = new System.Windows.Forms.TextBox();
            this.txtKeyField1 = new System.Windows.Forms.TextBox();
            this.rbnKeyField3 = new System.Windows.Forms.RadioButton();
            this.rbnKeyField2 = new System.Windows.Forms.RadioButton();
            this.rbnKeyField1 = new System.Windows.Forms.RadioButton();
            this.pnlModule = new System.Windows.Forms.Panel();
            this.grpModule = new System.Windows.Forms.GroupBox();
            this.lblARCModule = new System.Windows.Forms.Label();
            this.cdvARCModule = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.pnlCols = new System.Windows.Forms.Panel();
            this.lisCols = new System.Windows.Forms.ListView();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.pnlFind.SuspendLayout();
            this.pnlRight.SuspendLayout();
            this.pnlFilter.SuspendLayout();
            this.grpFilter.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlBottom2.SuspendLayout();
            this.grpBottom2.SuspendLayout();
            this.pnlKey.SuspendLayout();
            this.pnlKeyField.SuspendLayout();
            this.grpKey.SuspendLayout();
            this.pnlModule.SuspendLayout();
            this.grpModule.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvARCModule)).BeginInit();
            this.pnlCols.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnExcel
            // 
            this.btnExcel.Click += new System.EventHandler(this.btnExcel_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Click += new System.EventHandler(this.btnRefresh_Click);
            // 
            // btnNext
            // 
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // txtFind
            // 
            this.txtFind.TextChanged += new System.EventHandler(this.txtFind_TextChanged);
            // 
            // splMain
            // 
            this.splMain.Size = new System.Drawing.Size(4, 513);
            // 
            // pnlRight
            // 
            this.pnlRight.Controls.Add(this.pnlCols);
            this.pnlRight.Controls.Add(this.pnlKey);
            this.pnlRight.Controls.Add(this.pnlBottom2);
            this.pnlRight.Size = new System.Drawing.Size(506, 513);
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.lisTable);
            this.pnlLeft.Controls.Add(this.txtTable);
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
            // pnlTop
            // 
            this.pnlTop.Visible = true;
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "Archive Table Key Setup";
            // 
            // lisTable
            // 
            this.lisTable.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader1,
            this.ColumnHeader2,
            this.ColumnHeader8});
            this.lisTable.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisTable.FullRowSelect = true;
            this.lisTable.HideSelection = false;
            this.lisTable.Location = new System.Drawing.Point(0, 0);
            this.lisTable.MultiSelect = false;
            this.lisTable.Name = "lisTable";
            this.lisTable.Size = new System.Drawing.Size(232, 513);
            this.lisTable.TabIndex = 1;
            this.lisTable.UseCompatibleStateImageBehavior = false;
            this.lisTable.View = System.Windows.Forms.View.Details;
            this.lisTable.SelectedIndexChanged += new System.EventHandler(this.lisTable_SelectedIndexChanged);
            this.lisTable.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.lisTable_ColumnClick);
            this.lisTable.Click += new System.EventHandler(this.lisTable_Click);
            // 
            // ColumnHeader1
            // 
            this.ColumnHeader1.Text = "Table Name";
            this.ColumnHeader1.Width = 130;
            // 
            // ColumnHeader2
            // 
            this.ColumnHeader2.Text = "Module";
            this.ColumnHeader2.Width = 100;
            // 
            // ColumnHeader8
            // 
            this.ColumnHeader8.Text = "Type";
            // 
            // txtTable
            // 
            this.txtTable.Location = new System.Drawing.Point(122, 470);
            this.txtTable.Name = "txtTable";
            this.txtTable.Size = new System.Drawing.Size(100, 20);
            this.txtTable.TabIndex = 5;
            this.txtTable.Visible = false;
            // 
            // pnlBottom2
            // 
            this.pnlBottom2.Controls.Add(this.grpBottom2);
            this.pnlBottom2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom2.Location = new System.Drawing.Point(0, 413);
            this.pnlBottom2.Name = "pnlBottom2";
            this.pnlBottom2.Padding = new System.Windows.Forms.Padding(0, 0, 3, 0);
            this.pnlBottom2.Size = new System.Drawing.Size(506, 100);
            this.pnlBottom2.TabIndex = 2;
            // 
            // grpBottom2
            // 
            this.grpBottom2.Controls.Add(this.Label6);
            this.grpBottom2.Controls.Add(this.Label5);
            this.grpBottom2.Controls.Add(this.Label4);
            this.grpBottom2.Controls.Add(this.Label3);
            this.grpBottom2.Controls.Add(this.Label2);
            this.grpBottom2.Controls.Add(this.Label1);
            this.grpBottom2.Controls.Add(this.txtSField2);
            this.grpBottom2.Controls.Add(this.txtMField2);
            this.grpBottom2.Controls.Add(this.txtSField3);
            this.grpBottom2.Controls.Add(this.txtMField3);
            this.grpBottom2.Controls.Add(this.txtSField1);
            this.grpBottom2.Controls.Add(this.txtMField1);
            this.grpBottom2.Controls.Add(this.txtSTable);
            this.grpBottom2.Controls.Add(this.txtMTable);
            this.grpBottom2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpBottom2.Location = new System.Drawing.Point(0, 0);
            this.grpBottom2.Name = "grpBottom2";
            this.grpBottom2.Size = new System.Drawing.Size(503, 100);
            this.grpBottom2.TabIndex = 0;
            this.grpBottom2.TabStop = false;
            // 
            // Label6
            // 
            this.Label6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.Label6.Location = new System.Drawing.Point(395, 21);
            this.Label6.Name = "Label6";
            this.Label6.Size = new System.Drawing.Size(90, 14);
            this.Label6.TabIndex = 3;
            this.Label6.Text = "Key Field3";
            // 
            // Label5
            // 
            this.Label5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.Label5.Location = new System.Drawing.Point(295, 21);
            this.Label5.Name = "Label5";
            this.Label5.Size = new System.Drawing.Size(90, 14);
            this.Label5.TabIndex = 2;
            this.Label5.Text = "Key Field2";
            // 
            // Label4
            // 
            this.Label4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.Label4.Location = new System.Drawing.Point(195, 21);
            this.Label4.Name = "Label4";
            this.Label4.Size = new System.Drawing.Size(90, 14);
            this.Label4.TabIndex = 1;
            this.Label4.Text = "Key Field1";
            // 
            // Label3
            // 
            this.Label3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.Label3.Location = new System.Drawing.Point(92, 21);
            this.Label3.Name = "Label3";
            this.Label3.Size = new System.Drawing.Size(90, 14);
            this.Label3.TabIndex = 0;
            this.Label3.Text = "Table Name";
            // 
            // Label2
            // 
            this.Label2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.Label2.Location = new System.Drawing.Point(8, 72);
            this.Label2.Name = "Label2";
            this.Label2.Size = new System.Drawing.Size(80, 14);
            this.Label2.TabIndex = 9;
            this.Label2.Text = "Slave Table";
            // 
            // Label1
            // 
            this.Label1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.Label1.Location = new System.Drawing.Point(8, 47);
            this.Label1.Name = "Label1";
            this.Label1.Size = new System.Drawing.Size(80, 14);
            this.Label1.TabIndex = 4;
            this.Label1.Text = "Master Table";
            // 
            // txtSField2
            // 
            this.txtSField2.Location = new System.Drawing.Point(295, 69);
            this.txtSField2.Name = "txtSField2";
            this.txtSField2.ReadOnly = true;
            this.txtSField2.Size = new System.Drawing.Size(100, 20);
            this.txtSField2.TabIndex = 12;
            // 
            // txtMField2
            // 
            this.txtMField2.Location = new System.Drawing.Point(295, 44);
            this.txtMField2.Name = "txtMField2";
            this.txtMField2.ReadOnly = true;
            this.txtMField2.Size = new System.Drawing.Size(100, 20);
            this.txtMField2.TabIndex = 7;
            // 
            // txtSField3
            // 
            this.txtSField3.Location = new System.Drawing.Point(395, 69);
            this.txtSField3.Name = "txtSField3";
            this.txtSField3.ReadOnly = true;
            this.txtSField3.Size = new System.Drawing.Size(100, 20);
            this.txtSField3.TabIndex = 13;
            // 
            // txtMField3
            // 
            this.txtMField3.Location = new System.Drawing.Point(395, 44);
            this.txtMField3.Name = "txtMField3";
            this.txtMField3.ReadOnly = true;
            this.txtMField3.Size = new System.Drawing.Size(100, 20);
            this.txtMField3.TabIndex = 8;
            // 
            // txtSField1
            // 
            this.txtSField1.Location = new System.Drawing.Point(195, 69);
            this.txtSField1.Name = "txtSField1";
            this.txtSField1.ReadOnly = true;
            this.txtSField1.Size = new System.Drawing.Size(100, 20);
            this.txtSField1.TabIndex = 11;
            // 
            // txtMField1
            // 
            this.txtMField1.Location = new System.Drawing.Point(195, 44);
            this.txtMField1.Name = "txtMField1";
            this.txtMField1.ReadOnly = true;
            this.txtMField1.Size = new System.Drawing.Size(100, 20);
            this.txtMField1.TabIndex = 6;
            // 
            // txtSTable
            // 
            this.txtSTable.Location = new System.Drawing.Point(92, 69);
            this.txtSTable.Name = "txtSTable";
            this.txtSTable.Size = new System.Drawing.Size(100, 20);
            this.txtSTable.TabIndex = 10;
            // 
            // txtMTable
            // 
            this.txtMTable.Location = new System.Drawing.Point(92, 44);
            this.txtMTable.Name = "txtMTable";
            this.txtMTable.Size = new System.Drawing.Size(100, 20);
            this.txtMTable.TabIndex = 5;
            // 
            // pnlKey
            // 
            this.pnlKey.Controls.Add(this.pnlKeyField);
            this.pnlKey.Controls.Add(this.pnlModule);
            this.pnlKey.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlKey.Location = new System.Drawing.Point(260, 0);
            this.pnlKey.Name = "pnlKey";
            this.pnlKey.Size = new System.Drawing.Size(246, 413);
            this.pnlKey.TabIndex = 1;
            // 
            // pnlKeyField
            // 
            this.pnlKeyField.Controls.Add(this.grpKey);
            this.pnlKeyField.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlKeyField.Location = new System.Drawing.Point(0, 52);
            this.pnlKeyField.Name = "pnlKeyField";
            this.pnlKeyField.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlKeyField.Size = new System.Drawing.Size(246, 361);
            this.pnlKeyField.TabIndex = 1;
            // 
            // grpKey
            // 
            this.grpKey.Controls.Add(this.btnClear);
            this.grpKey.Controls.Add(this.relChk);
            this.grpKey.Controls.Add(this.txtWhere);
            this.grpKey.Controls.Add(this.btnWhere);
            this.grpKey.Controls.Add(this.txtTermField);
            this.grpKey.Controls.Add(this.rbnTermField);
            this.grpKey.Controls.Add(this.txtKeyField3);
            this.grpKey.Controls.Add(this.txtKeyField2);
            this.grpKey.Controls.Add(this.txtKeyField1);
            this.grpKey.Controls.Add(this.rbnKeyField3);
            this.grpKey.Controls.Add(this.rbnKeyField2);
            this.grpKey.Controls.Add(this.rbnKeyField1);
            this.grpKey.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpKey.Location = new System.Drawing.Point(3, 0);
            this.grpKey.Name = "grpKey";
            this.grpKey.Size = new System.Drawing.Size(240, 361);
            this.grpKey.TabIndex = 0;
            this.grpKey.TabStop = false;
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(157, 322);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 11;
            this.btnClear.Text = "Clear";
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // relChk
            // 
            this.relChk.Location = new System.Drawing.Point(12, 321);
            this.relChk.Name = "relChk";
            this.relChk.Size = new System.Drawing.Size(144, 24);
            this.relChk.TabIndex = 10;
            this.relChk.Text = "Dependent on Master";
            this.relChk.CheckedChanged += new System.EventHandler(this.relChk_CheckedChanged);
            // 
            // txtWhere
            // 
            this.txtWhere.Location = new System.Drawing.Point(10, 206);
            this.txtWhere.Multiline = true;
            this.txtWhere.Name = "txtWhere";
            this.txtWhere.Size = new System.Drawing.Size(223, 108);
            this.txtWhere.TabIndex = 9;
            // 
            // btnWhere
            // 
            this.btnWhere.Location = new System.Drawing.Point(10, 176);
            this.btnWhere.Name = "btnWhere";
            this.btnWhere.Size = new System.Drawing.Size(223, 23);
            this.btnWhere.TabIndex = 8;
            this.btnWhere.Text = "Detail Condition";
            this.btnWhere.Click += new System.EventHandler(this.btnWhere_Click);
            // 
            // txtTermField
            // 
            this.txtTermField.Location = new System.Drawing.Point(87, 142);
            this.txtTermField.Name = "txtTermField";
            this.txtTermField.Size = new System.Drawing.Size(145, 20);
            this.txtTermField.TabIndex = 7;
            // 
            // rbnTermField
            // 
            this.rbnTermField.Location = new System.Drawing.Point(10, 140);
            this.rbnTermField.Name = "rbnTermField";
            this.rbnTermField.Size = new System.Drawing.Size(76, 24);
            this.rbnTermField.TabIndex = 6;
            this.rbnTermField.Text = "Term Field";
            // 
            // txtKeyField3
            // 
            this.txtKeyField3.Location = new System.Drawing.Point(87, 78);
            this.txtKeyField3.Name = "txtKeyField3";
            this.txtKeyField3.Size = new System.Drawing.Size(145, 20);
            this.txtKeyField3.TabIndex = 5;
            // 
            // txtKeyField2
            // 
            this.txtKeyField2.Location = new System.Drawing.Point(87, 54);
            this.txtKeyField2.Name = "txtKeyField2";
            this.txtKeyField2.Size = new System.Drawing.Size(145, 20);
            this.txtKeyField2.TabIndex = 3;
            // 
            // txtKeyField1
            // 
            this.txtKeyField1.Location = new System.Drawing.Point(87, 30);
            this.txtKeyField1.Name = "txtKeyField1";
            this.txtKeyField1.Size = new System.Drawing.Size(145, 20);
            this.txtKeyField1.TabIndex = 1;
            // 
            // rbnKeyField3
            // 
            this.rbnKeyField3.Location = new System.Drawing.Point(10, 76);
            this.rbnKeyField3.Name = "rbnKeyField3";
            this.rbnKeyField3.Size = new System.Drawing.Size(76, 24);
            this.rbnKeyField3.TabIndex = 4;
            this.rbnKeyField3.Text = "Key Field3";
            // 
            // rbnKeyField2
            // 
            this.rbnKeyField2.Location = new System.Drawing.Point(10, 52);
            this.rbnKeyField2.Name = "rbnKeyField2";
            this.rbnKeyField2.Size = new System.Drawing.Size(76, 24);
            this.rbnKeyField2.TabIndex = 2;
            this.rbnKeyField2.Text = "Key Field2";
            // 
            // rbnKeyField1
            // 
            this.rbnKeyField1.Checked = true;
            this.rbnKeyField1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbnKeyField1.Location = new System.Drawing.Point(10, 28);
            this.rbnKeyField1.Name = "rbnKeyField1";
            this.rbnKeyField1.Size = new System.Drawing.Size(76, 24);
            this.rbnKeyField1.TabIndex = 0;
            this.rbnKeyField1.TabStop = true;
            this.rbnKeyField1.Text = "Key Field1";
            // 
            // pnlModule
            // 
            this.pnlModule.Controls.Add(this.grpModule);
            this.pnlModule.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlModule.Location = new System.Drawing.Point(0, 0);
            this.pnlModule.Name = "pnlModule";
            this.pnlModule.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlModule.Size = new System.Drawing.Size(246, 52);
            this.pnlModule.TabIndex = 0;
            // 
            // grpModule
            // 
            this.grpModule.Controls.Add(this.lblARCModule);
            this.grpModule.Controls.Add(this.cdvARCModule);
            this.grpModule.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpModule.Location = new System.Drawing.Point(3, 0);
            this.grpModule.Name = "grpModule";
            this.grpModule.Size = new System.Drawing.Size(240, 52);
            this.grpModule.TabIndex = 0;
            this.grpModule.TabStop = false;
            // 
            // lblARCModule
            // 
            this.lblARCModule.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblARCModule.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblARCModule.Location = new System.Drawing.Point(10, 23);
            this.lblARCModule.Name = "lblARCModule";
            this.lblARCModule.Size = new System.Drawing.Size(60, 14);
            this.lblARCModule.TabIndex = 0;
            this.lblARCModule.Text = "Module";
            // 
            // cdvARCModule
            // 
            this.cdvARCModule.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvARCModule.BtnToolTipText = "";
            this.cdvARCModule.DescText = "";
            this.cdvARCModule.DisplaySubItemIndex = -1;
            this.cdvARCModule.DisplayText = "";
            this.cdvARCModule.Focusing = null;
            this.cdvARCModule.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvARCModule.Index = 0;
            this.cdvARCModule.IsViewBtnImage = false;
            this.cdvARCModule.Location = new System.Drawing.Point(87, 20);
            this.cdvARCModule.MaxLength = 10;
            this.cdvARCModule.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvARCModule.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvARCModule.Name = "cdvARCModule";
            this.cdvARCModule.ReadOnly = false;
            this.cdvARCModule.SearchSubItemIndex = 0;
            this.cdvARCModule.SelectedDescIndex = -1;
            this.cdvARCModule.SelectedSubItemIndex = -1;
            this.cdvARCModule.SelectionStart = 0;
            this.cdvARCModule.Size = new System.Drawing.Size(145, 20);
            this.cdvARCModule.SmallImageList = null;
            this.cdvARCModule.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvARCModule.TabIndex = 1;
            this.cdvARCModule.TextBoxToolTipText = "";
            this.cdvARCModule.TextBoxWidth = 145;
            this.cdvARCModule.VisibleButton = true;
            this.cdvARCModule.VisibleColumnHeader = false;
            this.cdvARCModule.VisibleDescription = false;
            this.cdvARCModule.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvARCModule_SelectedItemChanged);
            // 
            // pnlCols
            // 
            this.pnlCols.Controls.Add(this.lisCols);
            this.pnlCols.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCols.Location = new System.Drawing.Point(0, 0);
            this.pnlCols.Name = "pnlCols";
            this.pnlCols.Size = new System.Drawing.Size(260, 413);
            this.pnlCols.TabIndex = 0;
            // 
            // lisCols
            // 
            this.lisCols.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader3,
            this.ColumnHeader4,
            this.ColumnHeader5});
            this.lisCols.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisCols.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisCols.FullRowSelect = true;
            this.lisCols.HideSelection = false;
            this.lisCols.Location = new System.Drawing.Point(0, 0);
            this.lisCols.MultiSelect = false;
            this.lisCols.Name = "lisCols";
            this.lisCols.Size = new System.Drawing.Size(260, 413);
            this.lisCols.TabIndex = 0;
            this.lisCols.UseCompatibleStateImageBehavior = false;
            this.lisCols.View = System.Windows.Forms.View.Details;
            this.lisCols.SelectedIndexChanged += new System.EventHandler(this.lisCols_SelectedIndexChanged);
            this.lisCols.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(this.lisCols_ColumnClick);
            // 
            // ColumnHeader3
            // 
            this.ColumnHeader3.Text = "Column Name";
            this.ColumnHeader3.Width = 150;
            // 
            // ColumnHeader4
            // 
            this.ColumnHeader4.Text = "Data Type";
            this.ColumnHeader4.Width = 150;
            // 
            // ColumnHeader5
            // 
            this.ColumnHeader5.Text = "Index";
            // 
            // frmARCSetupTableKey
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Name = "frmARCSetupTableKey";
            this.Text = "Archive Table Key Setup";
            this.Load += new System.EventHandler(this.frmARCSetupTableKey_Load);
            this.Activated += new System.EventHandler(this.frmARCSetupTableKey_Activated);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.frmARCSetupTableKey_KeyPress);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.frmARCSetupTableKey_KeyUp);
            this.pnlFind.ResumeLayout(false);
            this.pnlFind.PerformLayout();
            this.pnlRight.ResumeLayout(false);
            this.pnlFilter.ResumeLayout(false);
            this.grpFilter.ResumeLayout(false);
            this.grpFilter.PerformLayout();
            this.pnlLeft.ResumeLayout(false);
            this.pnlLeft.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlBottom2.ResumeLayout(false);
            this.grpBottom2.ResumeLayout(false);
            this.grpBottom2.PerformLayout();
            this.pnlKey.ResumeLayout(false);
            this.pnlKeyField.ResumeLayout(false);
            this.grpKey.ResumeLayout(false);
            this.grpKey.PerformLayout();
            this.pnlModule.ResumeLayout(false);
            this.grpModule.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvARCModule)).EndInit();
            this.pnlCols.ResumeLayout(false);
            this.ResumeLayout(false);

		}
		
		#endregion
		
		#region " Variable Definition"
		
		bool LoadFlag;
        bool TableSort = false;
        bool ColumnSort = false;
		
		#endregion
		
		#region " Property Definition"
		
		private string nWhere;
		
		public string ARCWhere
		{
			get
			{
				return nWhere;
			}
			set
			{
				nWhere = value;
				txtWhere.Text = nWhere;
			}
		}
		
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
				
				if (ProcStep == "1")
				{
                    //MPCF.FieldClear(this.pnlRight);
				}
				else if (ProcStep == "2")
				{
					txtKeyField1.Text = "";
					txtKeyField2.Text = "";
					txtKeyField3.Text = "";
					txtTermField.Text = "";
					txtWhere.Text = "";
                    MPCF.FieldClear(this.pnlBottom2);
					txtWhere.Enabled = true;
					btnWhere.Enabled = true;
					relChk.Enabled = true;
					relChk.Checked = false;
				}
				else if (ProcStep == "3")
				{
					rbnKeyField1.Checked = true;
					txtKeyField1.Text = "";
					txtKeyField2.Text = "";
					txtKeyField3.Text = "";
					txtTermField.Text = "";
					txtWhere.Text = "";
					txtSTable.Text = "";
					txtSField1.Text = "";
					txtSField2.Text = "";
					txtSField3.Text = "";
				}
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}

        private bool Get_Archive_Table_Data(TRSNode in_node, ref TRSNode out_node)
		{
            bool returnValue;

            returnValue = false;

            MPCR.SetInMsg(in_node);

            if (MPCR.CallService("ARC", "ARC_View_Archive_Table_Detail", in_node, ref out_node) == false)
            {
                return false;
            }
            else
            {
                returnValue = true;
            }

            return returnValue;
		}
		
		private bool Get_Archive_Module_Data(string sModule)
		{
			int i;
            int j;

            TRSNode in_node = new TRSNode("VIEW_ARCHIVE_TABLE_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ARCHIVE_TABLE_LIST_OUT");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            if (sModule.Trim() != "")
            {
                in_node.AddString("MODULE_NAME", sModule.Trim());
            }
            else
            {
                in_node.AddString("MODULE_NAME", MPCF.Trim(cdvARCModule.Text));
            }

            do
            {
                if (MPCR.CallService("ARC", "ARC_View_Archive_Table_List", in_node, ref out_node) == false)
                {
                	return false;
                }

                for (j = 0; j < out_node.GetList(0).Count; j++)
                {

                    if (MPCF.Trim(out_node.GetList(0)[j].GetString("MODULE_NAME")) == MPCF.Trim(cdvARCModule.Text) && out_node.GetList(0)[j].GetChar("TBL_TYPE") == 'M')
                    {
                        txtMTable.Text = out_node.GetList(0)[j].GetString("TBL_NAME");
                        txtMField1.Text = out_node.GetList(0)[j].GetString("KEY_FIELD1");
                        txtMField2.Text = out_node.GetList(0)[j].GetString("KEY_FIELD2");
                        txtMField3.Text = out_node.GetList(0)[j].GetString("KEY_FIELD3");
                        if (txtTable.Text.Trim() != MPCF.Trim(out_node.GetList(0)[j].GetString("TBL_NAME")))
                        {
                            if (relChk.Enabled == true)
                            {
                                relChk.Checked = true;
                                relChk.Enabled = false;
                            }
                        }
                    }

                    for (i = 0; i < lisTable.Items.Count; i++)
                    {
                        if (MPCF.Trim(lisTable.Items[i].Text) == MPCF.Trim(out_node.GetList(0)[j].GetString("TBL_NAME")))
                        {
                            lisTable.Items[i].SubItems[1].Text = out_node.GetList(0)[j].GetString("MODULE_NAME");
                            if (MPCF.Trim(out_node.GetList(0)[j].GetChar("TBL_TYPE")) == "M")
                            {

                                lisTable.Items[i].ForeColor = Color.Red;
                                //'lisTable.Items(i).Font.Bold = True
                                lisTable.Items[i].ImageIndex = (int)SMALLICON_INDEX.IDX_COL_SET;

                            }
                            else if (MPCF.Trim(out_node.GetList(0)[j].GetChar("TBL_TYPE")) == "S")
                            {
                                lisTable.Items[i].ImageIndex = (int)SMALLICON_INDEX.IDX_COL_SET_VERSION;
                            }
                        }
                    }
                }

                in_node.SetString("TBL_NAME", out_node.GetString("NEXT_TBL_NAME"));
            } while (!(in_node.GetString("TBL_NAME") == ""));

            return true;

		}
		
		private bool GetMasterTable(string sModule, ref string sMaster)
		{
            TRSNode in_node = new TRSNode("VIEW_ARCHIVE_TABLE_DETAIL_IN");
            TRSNode out_node = new TRSNode("VIEW_ARCHIVE_TABLE_DETAIL_OUT");

            in_node.AddString("MODULE_NAME", sModule);
            in_node.AddChar("TBL_TYPE", 'M');
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '2';

            if (Get_Archive_Table_Data(in_node, ref out_node) != true)
            {
                return false;
            }

            sMaster = out_node.GetString("TBL_NAME").Trim();

            return true;
		}
		
		private bool View_Archive_Table_Detail(char sStep)
		{
            TRSNode in_node = new TRSNode("VIEW_ARCHIVE_TABLE_DETAIL_IN");
            TRSNode out_node = new TRSNode("VIEW_ARCHIVE_TABLE_DETAIL_OUT");

            relChk.Enabled = true;
            
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = sStep;
            in_node.AddString("TBL_NAME", lisTable.SelectedItems[0].Text);

            if (Get_Archive_Table_Data(in_node, ref out_node) != true)
            {
                return false;
            }

            cdvARCModule.Text = out_node.GetString("MODULE_NAME");
            txtKeyField1.Text = out_node.GetString("KEY_FIELD1");
            txtKeyField2.Text = out_node.GetString("KEY_FIELD2");
            txtKeyField3.Text = out_node.GetString("KEY_FIELD3");
            txtTermField.Text = out_node.GetString("TERM_FIELD");
            txtWhere.Text = out_node.GetString("WHERE_CND");

            relChk.Checked = (out_node.GetChar("TBL_TYPE") == 'M') ? false : true;

            if (out_node.GetChar("TBL_TYPE") == 'S')
            {
                txtSTable.Text = out_node.GetString("TBL_NAME");
                txtSField1.Text = out_node.GetString("KEY_FIELD1");
                txtSField2.Text = out_node.GetString("KEY_FIELD2");
                txtSField3.Text = out_node.GetString("KEY_FIELD3");
            }
            else
            {
                txtMTable.Text = out_node.GetString("TBL_NAME");
                txtMField1.Text = out_node.GetString("KEY_FIELD1");
                txtMField2.Text = out_node.GetString("KEY_FIELD2");
                txtMField3.Text = out_node.GetString("KEY_FIELD3");
            }

            return true;
		}
		
		// CheckCondition()
		//       -   Check the conditions before transaction
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       - ByVal FuncName As String : create/update/delete Function name
		private bool CheckCondition(string FuncName)
		{
			string tMasterTable = null;
			
			if (MPCF.CheckValue(cdvARCModule, 1) == false)
			{
				return false;
			}
			
			switch (FuncName.TrimEnd())
			{
				case "I":
					
					if (relChk.Checked == true)
					{
						if (GetMasterTable(cdvARCModule.Text, ref tMasterTable) != true)
						{
                            MPCF.ShowMsgBox(MPCF.GetMessage(247));
							return false;
						}
						if (txtKeyField1.Text.Trim() == "")
						{
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
							txtKeyField1.Focus();
							return false;
						}
					}
					else
					{
						if (GetMasterTable(cdvARCModule.Text, ref tMasterTable) == true)
						{
                            MPCF.ShowMsgBox(MPCF.GetMessage(250));
							return false;
						}
						
						if (txtKeyField1.Text == "")
						{
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
							txtKeyField1.Focus();
							return false;
						}

                        if (txtTermField.Text.Trim() == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            txtTermField.Focus();
                            return false;
                        }
                    }
					break;
					
				case "U":
					
					if (relChk.Checked == true)
					{
						if (txtKeyField1.Text.Trim() == "")
						{
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
							txtKeyField1.Focus();
							return false;
						}
					}
					else
					{
						if (GetMasterTable(cdvARCModule.Text, ref tMasterTable) == true)
						{
                            if (lisTable.SelectedItems[0].Text != tMasterTable)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(250));
                                return false;
                            }
						}
						
						if (txtKeyField1.Text == "")
						{
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
							txtKeyField1.Focus();
							return false;
						}

                        if (txtTermField.Text.Trim() == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            txtTermField.Focus();
                            return false;
                        }
                    }
					break;
			}
			
			return true;
		}
		
		private bool Update_Archive_Table(char ProcStep)
		{

            TRSNode in_node = new TRSNode("UPDATE_ARCHIVE_TABLE_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            string ArcModule = null;
            string sWhere;
            int i;

            try
            {
                sWhere = txtWhere.Text.Trim();
                if (MPCF.Trim(sWhere) != "" && MPCF.Trim(sWhere).Length >= 4)
                {
                    if (sWhere.Substring(0, 4).ToUpper() == "AND ")
                        sWhere = sWhere.Substring(4);
                    else if (sWhere.Substring(0, 3).ToUpper() == "OR ")
                        sWhere = sWhere.Substring(3);
                }

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = ProcStep;

                in_node.AddString("MODULE_NAME", MPCF.Trim(cdvARCModule.Text));
                in_node.AddString("TBL_NAME", txtTable.Text.Trim());
                in_node.AddChar("TBL_TYPE", relChk.Checked == true ? 'S' : 'M');
                in_node.AddString("TERM_FIELD", txtTermField.Text.Trim());
                in_node.AddString("WHERE_CND", sWhere.Trim());
                in_node.AddString("KEY_FIELD1", txtKeyField1.Text.Trim());
                in_node.AddString("KEY_FIELD2", txtKeyField2.Text.Trim());
                in_node.AddString("KEY_FIELD3", txtKeyField3.Text.Trim());

                if (MPCR.CallService("ARC", "ARC_Update_Archive_Table", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.ShowSuccessMsg(out_node);

                if (ProcStep == MPGC.MP_STEP_DELETE)
                {
                    if (MPCF.FindListItem(lisTable, txtTable.Text.TrimEnd(), false) == true)
                    {
                        if (lisTable.SelectedItems[0].ForeColor == Color.Red)
                        {
                            ArcModule = lisTable.SelectedItems[0].SubItems[1].Text;

                            for (i = 0; i < lisTable.Items.Count - 1; i++)
                            {
                                if (ArcModule == lisTable.Items[i].SubItems[1].Text)
                                {
                                    lisTable.Items[i].SubItems[1].Text = "";
                                    lisTable.Items[i].ForeColor = Color.Black;
                                    lisTable.Items[i].ImageIndex = (int)SMALLICON_INDEX.IDX_CODE_TABLE;
                                }
                            }
                        }
                        else
                        {
                            lisTable.SelectedItems[0].SubItems[1].Text = "";
                            lisTable.SelectedItems[0].ForeColor = Color.Black;
                            lisTable.SelectedItems[0].ImageIndex = (int)SMALLICON_INDEX.IDX_CODE_TABLE;
                        }

                        ClearData("3");
                    }
                }

                if (MPGV.gbListAutoRefresh == false)
                {
                    Get_Archive_Module_Data("");
                    if (ProcStep == MPGC.MP_STEP_CREATE || ProcStep == MPGC.MP_STEP_UPDATE)
                    {
                        if (MPCF.FindListItem(lisTable, txtTable.Text.TrimEnd(), false) == true)
                        {
                            //'lisTable.SelectedItems(0).SubItems(1).Text = RTrim(txtFlowDesc.Text)
                        }
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
		
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
			
			//Initialize Module List
			cdvARCModule.Init();
			MPCF.InitListView(cdvARCModule.GetListView);
			cdvARCModule.Columns.Add("Module", 50, HorizontalAlignment.Left);
			cdvARCModule.Columns.Add("Desc", 100, HorizontalAlignment.Left);
			cdvARCModule.SelectedSubItemIndex = 0;
            ADCM.ViewGCMDataList(cdvARCModule.GetListView, '1', MPGC.MP_ARCHIVE_MODULE, (int)SMALLICON_INDEX.IDX_CODE_DATA, null, "", true, -1, -1, null);
			
		}
		
		#endregion
		
		private void frmARCSetupTableKey_Load(object sender, System.EventArgs e)
		{
			
			try
			{
				
				 
                MPCF.ToClientLanguage(this);
				
				MPCF.InitListView(lisTable);
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void frmARCSetupTableKey_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
		{
			
			try
			{
				
				if (!(this.ActiveControl == null))
				{
					if (this.ActiveControl is TextBox)
					{
						if (e.KeyChar == (char)58)
						{
							e.Handled = true;
						}
					}
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
		}
		
		private void frmARCSetupTableKey_Activated(object sender, System.EventArgs e)
		{
			
			try
			{
				if (LoadFlag == false)
				{
                    //lblDataCount.Text = "";
                    if (ADCM.ViewTableList(lisTable, '1', null) == true)
					{
                        //lblDataCount.Text = lisTable.Items.Count;
						if (lisTable.Items.Count > 0)
						{
							lisTable.Items[0].Selected = true;
						}
					}
					else
					{
						return;
					}
					
					initCodeView();
					
					LoadFlag = true;
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void frmARCSetupTableKey_KeyUp(object sender, System.Windows.Forms.KeyEventArgs e)
		{
			
			try
			{
				if (!(this.ActiveControl == null))
				{
					if (this.ActiveControl is TextBox)
					{
						if (e.KeyValue != 13 && e.KeyValue != 8)
						{
							if (MPCF.CheckMaxLength(this.ActiveControl, 0) == false)
							{
								e.Handled = true;
							}
						}
					}
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void btnRefresh_Click(System.Object sender, System.EventArgs e)
		{
			
			try
			{
                //lblDataCount.Text = "";
                if (ADCM.ViewTableList(lisTable, '1', null) == false)
				{
					return;
				}
                //lblDataCount.Text = lisTable.Items.Count.ToString();
				if (lisTable.Items.Count > 0)
				{
					MPCF.FindListItem(lisTable, txtTable.Text.Trim(), false);
				}
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void btnCreate_Click(System.Object sender, System.EventArgs e)
		{
			
			try
			{
				if (CheckCondition(MPGC.MP_STEP_CREATE.ToString()) == true)
				{
                    if (Update_Archive_Table(MPGC.MP_STEP_CREATE) == false)
					{
						return;
					}
                    //MPCF.ShowMsgBox(MPCF.GetMessage(52));
					if (MPGV.gbListAutoRefresh == true)
					{
                        //btnRefresh.PerformClick();
					}
					Get_Archive_Module_Data("");
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void btnUpdate_Click(System.Object sender, System.EventArgs e)
		{
			
			try
			{
				
				if (CheckCondition(MPGC.MP_STEP_UPDATE.ToString()) == true)
				{
					if (Update_Archive_Table(MPGC.MP_STEP_UPDATE) == false)
					{
						return;
					}
                    //MPCF.ShowMsgBox(MPCF.GetMessage(52));
					if (MPGV.gbListAutoRefresh == true)
					{
                        //btnRefresh.PerformClick();
					}
					Get_Archive_Module_Data("");
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void btnDelete_Click(System.Object sender, System.EventArgs e)
		{
			
			try
			{
				if (relChk.Checked == true)
				{
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(54), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                    {
						return;
					}
				}
				else
				{
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(248), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
					{
						return;
					}
				}
				
				if (CheckCondition(MPGC.MP_STEP_DELETE.ToString()) == true)
				{
                    if (Update_Archive_Table(MPGC.MP_STEP_DELETE) == false)
					{
						return;
					}
                    //MPCF.ShowMsgBox(MPCF.GetMessage(52)); ;
                    //MPCF.FieldClear(this.pnlRight);
                    //btnRefresh.PerformClick();
				}
				Get_Archive_Module_Data("");
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void lisTable_SelectedIndexChanged(object sender, System.EventArgs e)
		{
			bool iRet;
			
			try
			{
				ClearData("3");
                lisCols.Sorting = SortOrder.None;

				if (lisTable.SelectedItems.Count > 0)
				{
					txtTable.Text = lisTable.SelectedItems[0].Text;
					MPGV.gsTableName = txtTable.Text.Trim();
                    iRet = ADCM.ViewColumnList(lisCols, '1', txtTable.Text, null);
					if (iRet == false)
					{
						return;
					}
					
					if (MPCF.Trim(lisTable.SelectedItems[0].SubItems[1].Text) != "")
					{
						View_Archive_Table_Detail('1');
					}
                    if (MPCF.Trim(lisTable.SelectedItems[0].SubItems[1].Text) != "" || MPCF.Trim(cdvARCModule.Text) != "")
					{
						Get_Archive_Module_Data(lisTable.SelectedItems[0].SubItems[1].Text);
					}
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void btnExcel_Click(System.Object sender, System.EventArgs e)
		{
			
			try
			{
				MPCF.ExportToExcel(lisTable, this.Text, "");
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
		
		private void btnNext_Click(System.Object sender, System.EventArgs e)
		{

            //MPCF.FindListItemNextPartial(lisTable, MPCF.Trim(txtFind.Text));
			
		}
		
		private void txtFind_TextChanged(System.Object sender, System.EventArgs e)
		{

            //MPCF.FindListItemPartial(lisTable, MPCF.Trim(txtFind.Text));
			
		}
		
		private void lisTable_Click(object sender, System.EventArgs e)
		{
			lisTable_SelectedIndexChanged(null, null);
		}
		
		private void btnClear_Click(System.Object sender, System.EventArgs e)
		{
			MPCF.FieldClear(this.pnlKey);
			rbnKeyField1.Checked = true;
			relChk.Enabled = true;
			MPCF.FieldClear(this.pnlBottom2);
		}
		
		private void relChk_CheckedChanged(System.Object sender, System.EventArgs e)
		{
			string tMasterTable = null;

            if (MPCF.Trim(cdvARCModule.Text) == "")
			{
				return;
			}
			
			if (relChk.Checked == true)
			{
				
				if (GetMasterTable(cdvARCModule.Text, ref tMasterTable) == true)
				{
                    if (tMasterTable != null)
                    {
                        if (tMasterTable.Trim() == MPCF.Trim(lisTable.SelectedItems[0].Text))
                        {
                            relChk.Checked = false;
                            return;
                        }
                    }
				}
				
				txtWhere.Enabled = false;
				btnWhere.Enabled = false;
				txtSTable.Text = lisTable.SelectedItems[0].Text;
				txtSField1.Text = txtKeyField1.Text;
				txtSField2.Text = txtKeyField2.Text;
				txtSField3.Text = txtKeyField3.Text;
			}
			else
			{
				
				Get_Archive_Module_Data("");
				
				txtWhere.Enabled = true;
				btnWhere.Enabled = true;
				txtMTable.Text = lisTable.SelectedItems[0].Text;
				txtMField1.Text = txtKeyField1.Text;
				txtMField2.Text = txtKeyField2.Text;
				txtMField3.Text = txtKeyField3.Text;
				
			}
		}
		
		private void cdvARCModule_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
		{
			ClearData("2");
			Get_Archive_Module_Data("");
		}
		
		private void lisCols_SelectedIndexChanged(System.Object sender, System.EventArgs e)
		{
			try
			{
				
				if (lisCols.Items.Count == 0)
				{
					return;
				}

                if (MPCF.Trim(cdvARCModule.Text) == "")
				{
                    MPCF.ShowMsgBox(MPCF.GetMessage(107));
					cdvARCModule.Focus();
					return;
				}
				
				if (rbnTermField.Checked == true)
				{
					txtTermField.Text = lisCols.SelectedItems[0].Text;
					return;
				}
				
				if (relChk.Checked == false)
				{
					txtMTable.Text = lisTable.SelectedItems[0].Text;
				}
				else
				{
					txtSTable.Text = lisTable.SelectedItems[0].Text;
				}
				
				if (rbnKeyField1.Checked == true)
				{
					
					txtKeyField1.Text = lisCols.SelectedItems[0].Text;
					
					if (relChk.Checked == false)
					{
						txtMField1.Text = lisCols.SelectedItems[0].Text;
					}
					else
					{
						if (txtMField1.Text.Trim() != "")
						{
							txtSField1.Text = lisCols.SelectedItems[0].Text;
						}
					}
					
				}
				else if (rbnKeyField2.Checked == true)
				{
                    if (txtKeyField1.Text.Trim() == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        txtKeyField1.Focus();
                        return;
                    }

                    if (relChk.Checked == false)
					{
						txtMField2.Text = lisCols.SelectedItems[0].Text;
						txtKeyField2.Text = lisCols.SelectedItems[0].Text;
					}
					else
					{
						if (txtMField2.Text.Trim() != "")
						{
							txtSField2.Text = lisCols.SelectedItems[0].Text;
							txtKeyField2.Text = lisCols.SelectedItems[0].Text;
						}
					}
					
					if (txtKeyField2.Text == txtKeyField1.Text)
					{
						txtKeyField2.Text = "";
						if (relChk.Checked == false)
						{
							txtMField2.Text = "";
						}
						if (relChk.Checked == true)
						{
							txtSField2.Text = "";
						}
                        MPCF.ShowMsgBox(MPCF.GetMessage(249));
						return;
					}
					
				}
				else if (rbnKeyField3.Checked == true)
				{
                    if (txtKeyField1.Text.Trim() == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        txtKeyField1.Focus();
                        return;
                    }

                    if (txtKeyField2.Text.Trim() == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        txtKeyField2.Focus();
                        return;
                    }

                    if (relChk.Checked == false)
					{
						txtMField3.Text = lisCols.SelectedItems[0].Text;
						txtKeyField3.Text = lisCols.SelectedItems[0].Text;
					}
					else
					{
						if (txtMField3.Text.Trim() != "")
						{
							txtSField3.Text = lisCols.SelectedItems[0].Text;
							txtKeyField3.Text = lisCols.SelectedItems[0].Text;
						}
					}
					
					if (txtKeyField2.Text == txtKeyField3.Text || txtKeyField1.Text == txtKeyField3.Text)
					{
						txtKeyField3.Text = "";
						if (relChk.Checked == false)
						{
							txtMField3.Text = "";
						}
						if (relChk.Checked == true)
						{
							txtSField3.Text = "";
						}
                        MPCF.ShowMsgBox(MPCF.GetMessage(249));
						return;
					}
					
				}
				else
				{
					if (relChk.Checked == false)
					{
						txtTermField.Text = lisCols.SelectedItems[0].Text;
					}
				}
				
			}
			catch (Exception)
			{
				//'ShowMsgBox(ex.Message, ADM_CLIENT_CAPTION)
			}
		}
		
		private void btnWhere_Click(System.Object sender, System.EventArgs e)
		{
            frmTableFilter frm2 = new frmTableFilter(this);
			
            this.ARCWhere = txtWhere.Text.Trim();
			
			frm2.ShowDialog();
        }

        private void lisTable_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            if (TableSort == true)
            {
                lisTable.Sorting = SortOrder.Descending;
                TableSort = false;
            }
            else
            {
                lisTable.Sorting = SortOrder.Ascending;
                TableSort = true;
            }
        }

        private void lisCols_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            if (ColumnSort == true)
            {
                lisCols.Sorting = SortOrder.Ascending;
                ColumnSort = false;
            }
            else
            {
                lisCols.Sorting = SortOrder.Descending;
                ColumnSort = true;
            }
        }
	}
}
