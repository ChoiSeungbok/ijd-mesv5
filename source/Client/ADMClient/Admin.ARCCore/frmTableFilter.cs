#define _PROJECT
using Microsoft.VisualBasic;
using System.Data;
using System;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;
using System.Drawing;
using Miracom.CliFrx;
using Miracom.SECCore;
using Miracom.MESCore;
using Admin.COMCore;

namespace Admin.ARCCore
{
	public class frmTableFilter : System.Windows.Forms.Form
	{
		
		
		#region " Variable Definition"

        frmARCSetupTableKey obj;
		
		#endregion
		
		#region " Windows Form 디자이너에서 생성한 코드 "

        public frmTableFilter(frmARCSetupTableKey obj)
		{
            this.obj = obj;
			
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
		private System.Windows.Forms.TextBox txtWhere;
		private System.Windows.Forms.Label lblAnd;
		private System.Windows.Forms.ComboBox cboAndOr;
		private System.Windows.Forms.TextBox txtValue2;
		private System.Windows.Forms.TextBox txtValue1;
		private System.Windows.Forms.ComboBox cboComp;
		private System.Windows.Forms.Button btnClear;
		private System.Windows.Forms.Button btnInsert;
		private Miracom.UI.Controls.MCCodeView.MCCodeView cdvField;
		private System.Windows.Forms.Button btnClose;
		private System.Windows.Forms.Button btnOK;
		[System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
		{
            this.txtWhere = new System.Windows.Forms.TextBox();
            this.lblAnd = new System.Windows.Forms.Label();
            this.cboAndOr = new System.Windows.Forms.ComboBox();
            this.txtValue2 = new System.Windows.Forms.TextBox();
            this.txtValue1 = new System.Windows.Forms.TextBox();
            this.cboComp = new System.Windows.Forms.ComboBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnInsert = new System.Windows.Forms.Button();
            this.cdvField = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnOK = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.cdvField)).BeginInit();
            this.SuspendLayout();
            // 
            // txtWhere
            // 
            this.txtWhere.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtWhere.Location = new System.Drawing.Point(5, 80);
            this.txtWhere.Multiline = true;
            this.txtWhere.Name = "txtWhere";
            this.txtWhere.Size = new System.Drawing.Size(460, 320);
            this.txtWhere.TabIndex = 18;
            // 
            // lblAnd
            // 
            this.lblAnd.AutoSize = true;
            this.lblAnd.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnd.Location = new System.Drawing.Point(108, 51);
            this.lblAnd.Name = "lblAnd";
            this.lblAnd.Size = new System.Drawing.Size(30, 13);
            this.lblAnd.TabIndex = 26;
            this.lblAnd.Text = "AND";
            // 
            // cboAndOr
            // 
            this.cboAndOr.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cboAndOr.Items.AddRange(new object[] {
            "AND",
            "OR"});
            this.cboAndOr.Location = new System.Drawing.Point(5, 12);
            this.cboAndOr.Name = "cboAndOr";
            this.cboAndOr.Size = new System.Drawing.Size(92, 21);
            this.cboAndOr.TabIndex = 25;
            // 
            // txtValue2
            // 
            this.txtValue2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtValue2.Location = new System.Drawing.Point(142, 49);
            this.txtValue2.Name = "txtValue2";
            this.txtValue2.Size = new System.Drawing.Size(100, 20);
            this.txtValue2.TabIndex = 24;
            // 
            // txtValue1
            // 
            this.txtValue1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtValue1.Location = new System.Drawing.Point(5, 49);
            this.txtValue1.Name = "txtValue1";
            this.txtValue1.Size = new System.Drawing.Size(100, 20);
            this.txtValue1.TabIndex = 23;
            // 
            // cboComp
            // 
            this.cboComp.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cboComp.Items.AddRange(new object[] {
            "=",
            "<>",
            ">",
            ">=",
            "<",
            "<=",
            "BETWEEN",
            "IS NULL",
            "IS NOT NULL"});
            this.cboComp.Location = new System.Drawing.Point(255, 12);
            this.cboComp.Name = "cboComp";
            this.cboComp.Size = new System.Drawing.Size(121, 21);
            this.cboComp.TabIndex = 22;
            this.cboComp.SelectedIndexChanged += new System.EventHandler(this.cboComp_SelectedIndexChanged);
            // 
            // btnClear
            // 
            this.btnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClear.Location = new System.Drawing.Point(377, 45);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(88, 26);
            this.btnClear.TabIndex = 21;
            this.btnClear.Text = "Clear";
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnInsert
            // 
            this.btnInsert.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnInsert.Location = new System.Drawing.Point(285, 46);
            this.btnInsert.Name = "btnInsert";
            this.btnInsert.Size = new System.Drawing.Size(88, 26);
            this.btnInsert.TabIndex = 20;
            this.btnInsert.Text = "Insert";
            this.btnInsert.Click += new System.EventHandler(this.btnInsert_Click);
            // 
            // cdvField
            // 
            this.cdvField.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvField.BtnToolTipText = "";
            this.cdvField.DescText = "";
            this.cdvField.DisplaySubItemIndex = -1;
            this.cdvField.DisplayText = "";
            this.cdvField.Focusing = null;
            this.cdvField.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvField.Index = 0;
            this.cdvField.IsViewBtnImage = false;
            this.cdvField.Location = new System.Drawing.Point(101, 12);
            this.cdvField.MaxLength = 10;
            this.cdvField.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvField.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvField.Name = "cdvField";
            this.cdvField.ReadOnly = false;
            this.cdvField.SearchSubItemIndex = 0;
            this.cdvField.SelectedDescIndex = -1;
            this.cdvField.SelectedSubItemIndex = -1;
            this.cdvField.SelectionStart = 0;
            this.cdvField.Size = new System.Drawing.Size(150, 20);
            this.cdvField.SmallImageList = null;
            this.cdvField.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvField.TabIndex = 19;
            this.cdvField.TextBoxToolTipText = "";
            this.cdvField.TextBoxWidth = 150;
            this.cdvField.VisibleButton = true;
            this.cdvField.VisibleColumnHeader = false;
            this.cdvField.VisibleDescription = false;
            this.cdvField.ButtonPress += new System.EventHandler(this.cdvField_ButtonPress);
            // 
            // btnClose
            // 
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.Location = new System.Drawing.Point(378, 408);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(88, 26);
            this.btnClose.TabIndex = 28;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnOK
            // 
            this.btnOK.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnOK.Location = new System.Drawing.Point(286, 408);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(88, 26);
            this.btnOK.TabIndex = 27;
            this.btnOK.Text = "OK";
            this.btnOK.Click += new System.EventHandler(this.btnOk_Click);
            // 
            // frmTableFilter
            // 
            this.ClientSize = new System.Drawing.Size(472, 439);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.txtWhere);
            this.Controls.Add(this.lblAnd);
            this.Controls.Add(this.cboAndOr);
            this.Controls.Add(this.txtValue2);
            this.Controls.Add(this.txtValue1);
            this.Controls.Add(this.cboComp);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnInsert);
            this.Controls.Add(this.cdvField);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "frmTableFilter";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Detail Condition";
            this.Load += new System.EventHandler(this.frmTableFilter_Load);
            ((System.ComponentModel.ISupportInitialize)(this.cdvField)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

		}
		
		#endregion
		
		private void btnClear_Click(System.Object sender, System.EventArgs e)
		{
			txtValue1.Text = "";
			txtValue2.Text = "";
			txtWhere.Text = "";
			cdvField.Text = "";
			cboComp.Text = "";
			
		}
		
		private void cdvField_ButtonPress(object sender, System.EventArgs e)
		{
			Miracom.UI.Controls.MCCodeView.MCCodeView cdvTemp;
			
			cdvTemp = (Miracom.UI.Controls.MCCodeView.MCCodeView) sender;
            ADCM.ViewColumnList(cdvTemp.GetListView, '1', MPGV.gsTableName, null);
			
		}
		
		private void cboComp_SelectedIndexChanged(object sender, System.EventArgs e)
		{
			if (cboComp.SelectedIndex == 6)
			{
				txtValue2.Text = "";
				txtValue2.Enabled = true;
				txtValue2.Visible = true;
				lblAnd.Visible = true;
			}
			else if (cboComp.SelectedIndex == 7 || cboComp.SelectedIndex == 8)
			{
				txtValue2.Text = "";
				txtValue2.Enabled = false;
				txtValue2.Visible = false;
				lblAnd.Visible = false;
				txtValue1.Text = "";
				txtValue1.Enabled = false;
				txtValue1.Visible = false;
			}
			else
			{
				txtValue2.Text = "";
				txtValue2.Enabled = false;
				txtValue2.Visible = false;
				lblAnd.Visible = false;
			}
		}
		
		private void btnOk_Click(System.Object sender, System.EventArgs e)
		{
            obj.ARCWhere = txtWhere.Text.Trim();
            this.Close();
		}
		
		private void btnInsert_Click(System.Object sender, System.EventArgs e)
		{
			if (cboComp.SelectedIndex == 6)
			{
				if (txtValue1.Text != "" && txtValue2.Text != "")
				{
                    txtWhere.Text = txtWhere.Text + cboAndOr.Text.Trim() + " " + MPCF.Trim(cdvField.Text) + " " + cboComp.Text.Trim() + " \'" + txtValue1.Text + "\' AND \'" + txtValue2.Text + "\' " + "\r\n";
				}
			}
			else
			{
				if (txtValue1.Text != "")
				{
					if (MPCF.CheckNumeric(txtValue1.Text) == true)
					{
                        txtWhere.Text = txtWhere.Text.Trim() + " " + cboAndOr.Text.Trim() + " " + MPCF.Trim(cdvField.Text) + " " + cboComp.Text.Trim() + " " + txtValue1.Text + "\r\n";
					}
					else
					{
                        txtWhere.Text = txtWhere.Text.Trim() + " " + cboAndOr.Text.Trim() + " " + MPCF.Trim(cdvField.Text) + " " + cboComp.Text.Trim() + " \'" + txtValue1.Text + "\' " + "\r\n";
					}
				}
			}
			txtValue1.Text = "";
			txtValue2.Text = "";
		}
		
		private void btnClose_Click(System.Object sender, System.EventArgs e)
		{
			this.Close();
		}

        private void frmTableFilter_Load(object sender, EventArgs e)
        {
             
            MPCF.ToClientLanguage(this);
            txtWhere.Text = obj.ARCWhere;

            cboAndOr.Focus();
        }
	}
}
