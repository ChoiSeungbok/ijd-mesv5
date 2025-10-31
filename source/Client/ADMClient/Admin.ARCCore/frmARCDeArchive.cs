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
//   System      : ADMINClient
//   File Name   : frmARCDeArchive.cs
//   Description : Dearchive
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
//     1     2008/02/12    James Kwon     Create
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Admin.ARCCore
{
	public class frmARCDeArchive : Miracom.MESCore.TranForm01
	{
		
		
		#region " Windows Form 디자이너에서 생성한 코드 "
		
		public frmARCDeArchive()
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
        private System.Windows.Forms.Panel pnlKey;
        private System.Windows.Forms.ColumnHeader ColumnHeader8;
        protected Panel pnlLeft;
        private Panel pnlCols;
        private ListView lisCols;
        private ColumnHeader ColumnHeader3;
        private ColumnHeader ColumnHeader4;
        private ColumnHeader ColumnHeader5;
        private Panel panel1;
        private Panel pnlKeyField;
        private GroupBox grpKey;
        private TextBox txtKeyField3;
        private TextBox txtKeyField2;
        private TextBox txtKeyField1;
        private TextBox txtKeyField5;
        private TextBox txtKeyField4;
        private Label lblKeyField5;
        private Label lblKeyField4;
        private Label lblKeyField3;
        private Label lblKeyField2;
        private Label lblKeyField1;
        protected Panel pnlRight;
		[System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
		{
            this.lisTable = new System.Windows.Forms.ListView();
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.txtTable = new System.Windows.Forms.TextBox();
            this.pnlKey = new System.Windows.Forms.Panel();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.pnlRight = new System.Windows.Forms.Panel();
            this.pnlCols = new System.Windows.Forms.Panel();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pnlKeyField = new System.Windows.Forms.Panel();
            this.grpKey = new System.Windows.Forms.GroupBox();
            this.txtKeyField5 = new System.Windows.Forms.TextBox();
            this.txtKeyField4 = new System.Windows.Forms.TextBox();
            this.lblKeyField5 = new System.Windows.Forms.Label();
            this.lblKeyField4 = new System.Windows.Forms.Label();
            this.lblKeyField3 = new System.Windows.Forms.Label();
            this.lblKeyField2 = new System.Windows.Forms.Label();
            this.lblKeyField1 = new System.Windows.Forms.Label();
            this.txtKeyField3 = new System.Windows.Forms.TextBox();
            this.txtKeyField2 = new System.Windows.Forms.TextBox();
            this.txtKeyField1 = new System.Windows.Forms.TextBox();
            this.lisCols = new System.Windows.Forms.ListView();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.pnlRight.SuspendLayout();
            this.pnlCols.SuspendLayout();
            this.panel1.SuspendLayout();
            this.pnlKeyField.SuspendLayout();
            this.grpKey.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnProcess
            // 
            this.btnProcess.Click += new System.EventHandler(this.btnProcess_Click);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Location = new System.Drawing.Point(0, 513);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Controls.Add(this.pnlRight);
            this.pnlCenter.Controls.Add(this.pnlLeft);
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
            this.txtTable.Size = new System.Drawing.Size(100, 21);
            this.txtTable.TabIndex = 5;
            this.txtTable.Visible = false;
            // 
            // pnlKey
            // 
            this.pnlKey.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlKey.Location = new System.Drawing.Point(0, 0);
            this.pnlKey.Name = "pnlKey";
            this.pnlKey.Size = new System.Drawing.Size(506, 513);
            this.pnlKey.TabIndex = 1;
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.lisTable);
            this.pnlLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Size = new System.Drawing.Size(232, 513);
            this.pnlLeft.TabIndex = 5;
            // 
            // pnlRight
            // 
            this.pnlRight.Controls.Add(this.pnlCols);
            this.pnlRight.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlRight.Location = new System.Drawing.Point(232, 0);
            this.pnlRight.Name = "pnlRight";
            this.pnlRight.Size = new System.Drawing.Size(510, 513);
            this.pnlRight.TabIndex = 6;
            // 
            // pnlCols
            // 
            this.pnlCols.Controls.Add(this.panel1);
            this.pnlCols.Controls.Add(this.lisCols);
            this.pnlCols.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCols.Location = new System.Drawing.Point(0, 0);
            this.pnlCols.Name = "pnlCols";
            this.pnlCols.Size = new System.Drawing.Size(510, 513);
            this.pnlCols.TabIndex = 1;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.pnlKeyField);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel1.Location = new System.Drawing.Point(264, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(246, 513);
            this.panel1.TabIndex = 2;
            // 
            // pnlKeyField
            // 
            this.pnlKeyField.Controls.Add(this.grpKey);
            this.pnlKeyField.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlKeyField.Location = new System.Drawing.Point(0, 0);
            this.pnlKeyField.Name = "pnlKeyField";
            this.pnlKeyField.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlKeyField.Size = new System.Drawing.Size(246, 513);
            this.pnlKeyField.TabIndex = 1;
            // 
            // grpKey
            // 
            this.grpKey.Controls.Add(this.txtKeyField5);
            this.grpKey.Controls.Add(this.txtKeyField4);
            this.grpKey.Controls.Add(this.lblKeyField5);
            this.grpKey.Controls.Add(this.lblKeyField4);
            this.grpKey.Controls.Add(this.lblKeyField3);
            this.grpKey.Controls.Add(this.lblKeyField2);
            this.grpKey.Controls.Add(this.lblKeyField1);
            this.grpKey.Controls.Add(this.txtKeyField3);
            this.grpKey.Controls.Add(this.txtKeyField2);
            this.grpKey.Controls.Add(this.txtKeyField1);
            this.grpKey.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpKey.Location = new System.Drawing.Point(3, 0);
            this.grpKey.Name = "grpKey";
            this.grpKey.Size = new System.Drawing.Size(240, 513);
            this.grpKey.TabIndex = 0;
            this.grpKey.TabStop = false;
            // 
            // txtKeyField5
            // 
            this.txtKeyField5.Location = new System.Drawing.Point(26, 366);
            this.txtKeyField5.Name = "txtKeyField5";
            this.txtKeyField5.Size = new System.Drawing.Size(195, 20);
            this.txtKeyField5.TabIndex = 12;
            this.txtKeyField5.Visible = false;
            // 
            // txtKeyField4
            // 
            this.txtKeyField4.Location = new System.Drawing.Point(26, 291);
            this.txtKeyField4.Name = "txtKeyField4";
            this.txtKeyField4.Size = new System.Drawing.Size(195, 20);
            this.txtKeyField4.TabIndex = 11;
            this.txtKeyField4.Visible = false;
            // 
            // lblKeyField5
            // 
            this.lblKeyField5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblKeyField5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKeyField5.Location = new System.Drawing.Point(23, 348);
            this.lblKeyField5.Name = "lblKeyField5";
            this.lblKeyField5.Size = new System.Drawing.Size(82, 15);
            this.lblKeyField5.TabIndex = 10;
            this.lblKeyField5.Text = "Module";
            this.lblKeyField5.Visible = false;
            // 
            // lblKeyField4
            // 
            this.lblKeyField4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblKeyField4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKeyField4.Location = new System.Drawing.Point(23, 273);
            this.lblKeyField4.Name = "lblKeyField4";
            this.lblKeyField4.Size = new System.Drawing.Size(82, 15);
            this.lblKeyField4.TabIndex = 9;
            this.lblKeyField4.Text = "Module";
            this.lblKeyField4.Visible = false;
            // 
            // lblKeyField3
            // 
            this.lblKeyField3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblKeyField3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKeyField3.Location = new System.Drawing.Point(23, 198);
            this.lblKeyField3.Name = "lblKeyField3";
            this.lblKeyField3.Size = new System.Drawing.Size(82, 15);
            this.lblKeyField3.TabIndex = 8;
            this.lblKeyField3.Text = "Module";
            this.lblKeyField3.Visible = false;
            // 
            // lblKeyField2
            // 
            this.lblKeyField2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblKeyField2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKeyField2.Location = new System.Drawing.Point(23, 118);
            this.lblKeyField2.Name = "lblKeyField2";
            this.lblKeyField2.Size = new System.Drawing.Size(82, 15);
            this.lblKeyField2.TabIndex = 7;
            this.lblKeyField2.Text = "Module";
            this.lblKeyField2.Visible = false;
            // 
            // lblKeyField1
            // 
            this.lblKeyField1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblKeyField1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblKeyField1.Location = new System.Drawing.Point(23, 49);
            this.lblKeyField1.Name = "lblKeyField1";
            this.lblKeyField1.Size = new System.Drawing.Size(82, 15);
            this.lblKeyField1.TabIndex = 6;
            this.lblKeyField1.Text = "Module";
            this.lblKeyField1.Visible = false;
            // 
            // txtKeyField3
            // 
            this.txtKeyField3.Location = new System.Drawing.Point(26, 216);
            this.txtKeyField3.Name = "txtKeyField3";
            this.txtKeyField3.Size = new System.Drawing.Size(195, 20);
            this.txtKeyField3.TabIndex = 5;
            this.txtKeyField3.Visible = false;
            // 
            // txtKeyField2
            // 
            this.txtKeyField2.Location = new System.Drawing.Point(26, 136);
            this.txtKeyField2.Name = "txtKeyField2";
            this.txtKeyField2.Size = new System.Drawing.Size(195, 20);
            this.txtKeyField2.TabIndex = 3;
            this.txtKeyField2.Visible = false;
            // 
            // txtKeyField1
            // 
            this.txtKeyField1.Location = new System.Drawing.Point(26, 67);
            this.txtKeyField1.Name = "txtKeyField1";
            this.txtKeyField1.Size = new System.Drawing.Size(195, 20);
            this.txtKeyField1.TabIndex = 1;
            this.txtKeyField1.Visible = false;
            // 
            // lisCols
            // 
            this.lisCols.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader3,
            this.ColumnHeader4,
            this.ColumnHeader5});
            this.lisCols.Dock = System.Windows.Forms.DockStyle.Left;
            this.lisCols.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisCols.FullRowSelect = true;
            this.lisCols.HideSelection = false;
            this.lisCols.Location = new System.Drawing.Point(0, 0);
            this.lisCols.MultiSelect = false;
            this.lisCols.Name = "lisCols";
            this.lisCols.Size = new System.Drawing.Size(261, 513);
            this.lisCols.TabIndex = 0;
            this.lisCols.UseCompatibleStateImageBehavior = false;
            this.lisCols.View = System.Windows.Forms.View.Details;
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
            // frmARCDeArchive
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Name = "frmARCDeArchive";
            this.Text = "Dearchive";
            this.Load += new System.EventHandler(this.frmARCDeArchive_Load);
            this.Activated += new System.EventHandler(this.frmARCDeArchive_Activated);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlLeft.ResumeLayout(false);
            this.pnlRight.ResumeLayout(false);
            this.pnlCols.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.pnlKeyField.ResumeLayout(false);
            this.grpKey.ResumeLayout(false);
            this.grpKey.PerformLayout();
            this.ResumeLayout(false);

		}
		
		#endregion
		
		#region " Variable Definition"
		
		bool LoadFlag;
		
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
		
		private void ClearData()
		{
			
			try
			{

                txtKeyField1.Text = "";
                txtKeyField2.Text = "";
                txtKeyField3.Text = "";
                txtKeyField4.Text = "";
                txtKeyField5.Text = "";

                lblKeyField1.Text = "";
                lblKeyField2.Text = "";
                lblKeyField3.Text = "";
                lblKeyField4.Text = "";
                lblKeyField5.Text = "";

                txtKeyField1.Visible = false;
                txtKeyField2.Visible = false;
                txtKeyField3.Visible = false;
                txtKeyField4.Visible = false;
                txtKeyField5.Visible = false;

                lblKeyField1.Visible = false;
                lblKeyField2.Visible = false;
                lblKeyField3.Visible = false;
                lblKeyField4.Visible = false;
                lblKeyField5.Visible = false;
            }
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}
	
		private bool View_Archive_Table_Detail(char sStep)
		{
            TRSNode in_node = new TRSNode("VIEW_ARCHIVE_TABLE_DETAIL_IN");
            TRSNode out_node = new TRSNode("VIEW_ARCHIVE_TABLE_DETAIL_OUT");

            MPCR.SetInMsg(in_node);

            in_node.AddString("TBL_NAME", lisTable.SelectedItems[0].Text);
            in_node.ProcStep = sStep;

            if (MPCR.CallService("ARC", "ARC_View_Archive_Table_Detail", in_node, ref out_node) == false)
            {
                return false;
            }

            if (MPCF.Trim(out_node.GetString("KEY_FIELD1")) != "")
            {
                txtKeyField1.Visible = true;
                lblKeyField1.Visible = true;

                lblKeyField1.Text = MPCF.Trim(out_node.GetString("KEY_FIELD1"));
            }

            if (MPCF.Trim(out_node.GetString("KEY_FIELD2")) != "")
            {
                txtKeyField2.Visible = true;
                lblKeyField2.Visible = true;

                lblKeyField2.Text = MPCF.Trim(out_node.GetString("KEY_FIELD2"));
            }

            if (MPCF.Trim(out_node.GetString("KEY_FIELD3")) != "")
            {
                txtKeyField3.Visible = true;
                lblKeyField3.Visible = true;

                lblKeyField3.Text = MPCF.Trim(out_node.GetString("KEY_FIELD3"));
            }

            if (MPCF.Trim(out_node.GetString("KEY_FIELD4")) != "")
            {
                txtKeyField4.Visible = true;
                lblKeyField4.Visible = true;

                lblKeyField4.Text = MPCF.Trim(out_node.GetString("KEY_FIELD4"));
            }

            if (MPCF.Trim(out_node.GetString("KEY_FIELD5")) != "")
            {
                txtKeyField5.Visible = true;
                lblKeyField5.Visible = true;

                lblKeyField5.Text = MPCF.Trim(out_node.GetString("KEY_FIELD5"));
            }

            return true;

		}
		
		// CheckCondition()
		//       -   Check the conditions before transaction
		// Return Value
		//       - Boolean : True or False
		// Arguments
		//       - ByVal FuncName As String : create/update/delete Function name
		private bool CheckCondition(char FuncName)
		{
			switch (FuncName)
			{
                case MPGC.MP_STEP_UPDATE:
                    if (lisTable.SelectedItems.Count <= 0)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        lisTable.Focus();
                        return false;
                    }

                    if (lblKeyField1.Visible == true)
                    {
                        if (MPCF.CheckValue(txtKeyField1, 1) == false)
                        {
                            return false;
                        }
                    }

                    if (lblKeyField2.Visible == true)
                    {
                        if (MPCF.CheckValue(txtKeyField2, 1) == false)
                        {
                            return false;
                        }
                    }

                    if (lblKeyField3.Visible == true)
                    {
                        if (MPCF.CheckValue(txtKeyField3, 1) == false)
                        {
                            return false;
                        }
                    }

                    if (lblKeyField4.Visible == true)
                    {
                        if (MPCF.CheckValue(txtKeyField4, 1) == false)
                        {
                            return false;
                        }
                    }

                    if (lblKeyField5.Visible == true)
                    {
                        if (MPCF.CheckValue(txtKeyField5, 1) == false)
                        {
                            return false;
                        }
                    }

					break;
			}
			
			return true;
		}
		
		private bool Update_DeArchive_Table(char ProcStep, string ModName, string sTableName)
		{

            TRSNode in_node = new TRSNode("UPDATE_DEARCHIVE_TABLE_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");


            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;

                in_node.AddString("MODULE_NAME", ModName);
                in_node.AddString("TBL_NAME", sTableName);

                if (txtKeyField1.Visible == true)
                {
                    in_node.AddString("KEY_FIELD1", lblKeyField1.Text.Trim());
                    in_node.AddString("KEY_DATA1", txtKeyField1.Text.Trim());
                }

                if (txtKeyField2.Visible == true)
                {
                    in_node.AddString("KEY_FIELD2", lblKeyField2.Text.Trim());
                    in_node.AddString("KEY_DATA2", txtKeyField2.Text.Trim());
                }

                if (txtKeyField3.Visible == true)
                {
                    in_node.AddString("KEY_FIELD3", lblKeyField3.Text.Trim());
                    in_node.AddString("KEY_DATA3", txtKeyField3.Text.Trim());
                }

                if (txtKeyField4.Visible == true)
                {
                    in_node.AddString("KEY_FIELD4", lblKeyField4.Text.Trim());
                    in_node.AddString("KEY_DATA4", txtKeyField4.Text.Trim());
                }

                if (txtKeyField5.Visible == true)
                {
                    in_node.AddString("KEY_FIELD5", lblKeyField5.Text.Trim());
                    in_node.AddString("KEY_DATA5", txtKeyField5.Text.Trim());
                }

                if (MPCR.CallService("ARC", "ARC_Dearchive_Table", in_node, ref out_node) == false)
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;

			
		}
		
		#endregion
		
		private void frmARCDeArchive_Load(object sender, System.EventArgs e)
		{
			
			try
			{
				 
                MPCF.ToClientLanguage(this);

                MPCF.InitListView(lisTable);
                MPCF.InitListView(lisCols);
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}

		private void frmARCDeArchive_Activated(object sender, System.EventArgs e)
		{
			
			try
			{
				if (LoadFlag == false)
				{
                    if (ADCM.ViewTableList(lisTable, '2', null) == true)
					{
						if (lisTable.Items.Count > 0)
						{
							lisTable.Items[0].Selected = true;
						}
					}
					else
					{
						return;
					}
					
					LoadFlag = true;
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}

        private void lisTable_SelectedIndexChanged(object sender, System.EventArgs e)
		{
			bool iRet;
            string sTableName = null;
			
			try
			{
				ClearData();
                lisCols.Sorting = SortOrder.None;

				if (lisTable.SelectedItems.Count > 0)
				{
                    sTableName = lisTable.SelectedItems[0].Text;
                    iRet = ADCM.ViewColumnList(lisCols, '1', sTableName, null);
					if (iRet == false)
					{
						return;
					}
					
					if (MPCF.Trim(lisTable.SelectedItems[0].SubItems[1].Text) != "")
					{
						View_Archive_Table_Detail('1');
					}
				}
				
			}
			catch (Exception ex)
			{
                MPCF.ShowMsgBox(ex.Message);
			}
			
		}

        private void lisTable_Click(object sender, System.EventArgs e)
		{
			lisTable_SelectedIndexChanged(null, null);
		}

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(MPGC.MP_STEP_UPDATE) == true)
                {
                    if (Update_DeArchive_Table(MPGC.MP_STEP_UPDATE, lisTable.SelectedItems[0].SubItems[1].Text, lisTable.SelectedItems[0].Text) == false)
                    {
                        return;
                    }

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
	}
}
