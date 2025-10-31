
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using System.IO;
using Miracom.CliFrx;
namespace Miracom.FMBCore
{
    public class frmFMBSaveLayout : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBSaveLayout()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        public frmFMBSaveLayout(Form MDIForm)
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            fMDIForm = MDIForm;
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        //Form? Dispose瑜??ъ젙?섑븯??援ъ꽦 ?붿냼 紐⑸줉???뺣━?⑸땲??
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
        
        //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        private System.ComponentModel.Container components = null;
        
        //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
        //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Button btnSave;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.GroupBox grpFile;
        internal System.Windows.Forms.Label lblFile;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtFileName;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            base.Load += new System.EventHandler(frmFMBSaveLayout_Load);
            this.btnSave = new System.Windows.Forms.Button();
            this.btnSave.Click += new System.EventHandler(btnSave_Click);
            this.btnClose = new System.Windows.Forms.Button();
            this.btnClose.Click += new System.EventHandler(btnClose_Click);
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpFile = new System.Windows.Forms.GroupBox();
            this.lblFile = new System.Windows.Forms.Label();
            this.txtFileName = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.pnlBottom.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.grpFile.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize) this.txtFileName).BeginInit();
            this.SuspendLayout();
            //
            //pnlBottom
            //
            this.pnlBottom.Controls.Add(this.btnSave);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.pnlBottom.Location = new System.Drawing.Point(0, 64);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(294, 40);
            this.pnlBottom.TabIndex = 2;
            //
            //btnSave
            //
            this.btnSave.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnSave.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnSave.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnSave.Location = new System.Drawing.Point(135, 9);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(74, 23);
            this.btnSave.TabIndex = 0;
            this.btnSave.Text = "Save";
            //
            //btnClose
            //
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnClose.Location = new System.Drawing.Point(213, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            //
            //pnlMid
            //
            this.pnlMid.Controls.Add(this.grpFile);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.DockPadding.Left = 3;
            this.pnlMid.DockPadding.Right = 3;
            this.pnlMid.Location = new System.Drawing.Point(0, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Size = new System.Drawing.Size(294, 64);
            this.pnlMid.TabIndex = 3;
            //
            //grpFile
            //
            this.grpFile.Controls.Add(this.lblFile);
            this.grpFile.Controls.Add(this.txtFileName);
            this.grpFile.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpFile.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpFile.Location = new System.Drawing.Point(3, 0);
            this.grpFile.Name = "grpFile";
            this.grpFile.Size = new System.Drawing.Size(288, 64);
            this.grpFile.TabIndex = 0;
            this.grpFile.TabStop = false;
            //
            //lblFile
            //
            this.lblFile.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFile.Location = new System.Drawing.Point(12, 26);
            this.lblFile.Name = "lblFile";
            this.lblFile.Size = new System.Drawing.Size(75, 14);
            this.lblFile.TabIndex = 32;
            this.lblFile.Text = "File Name";
            //
            //txtFileName
            //
            this.txtFileName.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtFileName.Location = new System.Drawing.Point(99, 23);
            this.txtFileName.MaxLength = 20;
            this.txtFileName.Name = "txtFileName";
            this.txtFileName.Size = new System.Drawing.Size(179, 19);
            this.txtFileName.TabIndex = 31;
            //
            //frmFMBSaveLayout
            //
            this.AcceptButton = this.btnSave;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btnClose;
            this.ClientSize = new System.Drawing.Size(294, 104);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(300, 150);
            this.Name = "frmFMBSaveLayout";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Save Layout Configuration";
            this.pnlBottom.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.grpFile.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize) this.txtFileName).EndInit();
            this.ResumeLayout(false);
            
        }
        
        #endregion
        
        #region " Variable Definition"
        Form fMDIForm = null;
        #endregion
        
        #region " Function Implementations"
        
        // CheckCondition()
        //       - Check the conditions before transaction
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - FuncName as String  : Fuction Name
        //
        private bool CheckCondition()
        {
            
            try
            {
                if (txtFileName.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    txtFileName.Focus();
                    return false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // SaveSystemMenu()
        //       - Save System Menu
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        public bool SaveLayOut()
        {
            
            string sfilename;
            Form form;
            object[] fLoc = null;
            int i = 0;
            int iCount = 0;
            string sLoc = "";
            string sFactory= "";
            try
            {
                
                sfilename = Application.StartupPath + "\\" + MPCF.RTrim(txtFileName.Text);
                if (MPCF.RTrim(txtFileName.Text).Length > 4)
                {
                    if (MPCF.RTrim(txtFileName.Text).Substring((MPCF.RTrim(txtFileName.Text).Length - 3) - 1, 4).ToUpper() != ".FMB")
                    {
                        sfilename += ".fmb";
                    }
                }
                else
                {
                    sfilename += ".fmb";
                }
                if (File.Exists(sfilename) == true)
                {
                    if (MPCF.ShowMsgBox(sfilename + " " + MPCF.GetMessage(31), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.No)
                    {
                        this.DialogResult = DialogResult.None;
                        return false;
                    }
                }
                
                FileStream fs = new FileStream(sfilename, FileMode.Create);
                StreamWriter sw = new StreamWriter(fs);
                
                if (fMDIForm == null)
                {
                    return false;
                }
                iCount = 0;
                foreach (Form tempLoopVar_form in fMDIForm.MdiChildren)
                {
                    form = tempLoopVar_form;
                    if (form is frmFMBDesign)
                    {
                        iCount++;
                    }
                }
                fLoc = new object[iCount];
                foreach (Form tempLoopVar_form in fMDIForm.MdiChildren)
                {
                    form = tempLoopVar_form;
                    if (form is frmFMBDesign)
                    {
                        if (System.Convert.ToString(((frmFMBDesign)form).Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            sFactory = FMBCF.GetStringBySeperator(((frmFMBDesign) form).Name, ":", 1);
                        }
                        else if (System.Convert.ToString(((frmFMBDesign)form).Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            sFactory = MPGV.gsFactory;
                        }
                        fLoc[i] = ((frmFMBDesign) form).Name + "/" + ((frmFMBDesign) form).Location.X + "/" + ((frmFMBDesign) form).Location.Y + "/" + ((frmFMBDesign) form).Size.Width + "/" + ((frmFMBDesign) form).Size.Height + "/" + ((frmFMBDesign) form).Tag + "/" + sFactory;
                        i++;
                    }
                }
                iCount = i;
                if (iCount > 0)
                {
                    for (i = fLoc.Length - 1; i >= 0; i--)
                    {
                        if (MPCF.Trim(fLoc[i]) != "")
                        {
                            sLoc += fLoc[i] + "\r\n";
                        }
                    }
                    sw.WriteLine(iCount.ToString());
                    sw.WriteLine(sLoc);
                }
                sw.Close();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
            return true;
            
        }
        
        private void btnSave_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition() == false)
                {
                    this.DialogResult = DialogResult.None;
                    return;
                }
                if (SaveLayOut() == true)
                {
                    if (FMBFI.gIMdiForm.RefreshFileList() == false)
                    {
                        return;
                    }
                    MPCF.ShowMsgBox(MPCF.GetMessage(4), Application.ProductName, MessageBoxButtons.OK, 1);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSaveLayout.btnSave_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnClose_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                this.Dispose(true);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSaveLayout.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
        
        private void frmFMBSaveLayout_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSaveLayout.frmFMBSaveLayout_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
    }
    
}
