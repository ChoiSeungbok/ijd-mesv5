
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Miracom.CliFrx;
using Miracom.MESCore;
namespace Miracom.FMBCore
{
    public class frmFMBSetupDefaultLayout : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBSetupDefaultLayout()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
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
        internal System.Windows.Forms.Button btnOK;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlFill;
        internal Infragistics.Win.UltraWinEditors.UltraComboEditor cboCategory;
        internal System.Windows.Forms.Label lblCategory;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvLayout;
        internal System.Windows.Forms.Label lblLayout;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal System.Windows.Forms.GroupBox grpDefault;
        internal System.Windows.Forms.Button btnClear;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            Infragistics.Win.ValueListItem ValueListItem1 = new Infragistics.Win.ValueListItem();
            Infragistics.Win.ValueListItem ValueListItem2 = new Infragistics.Win.ValueListItem();
            this.pnlBottom = new System.Windows.Forms.Panel();
            base.Load += new System.EventHandler(frmFMBSetupDefaultLayout_Load);
            this.btnClear = new System.Windows.Forms.Button();
            this.btnClear.Click += new System.EventHandler(btnClear_Click);
            this.btnOK = new System.Windows.Forms.Button();
            this.btnOK.Click += new System.EventHandler(btnOK_Click);
            this.btnClose = new System.Windows.Forms.Button();
            this.btnClose.Click += new System.EventHandler(btnClose_Click);
            this.pnlFill = new System.Windows.Forms.Panel();
            this.grpDefault = new System.Windows.Forms.GroupBox();
            this.cboCategory = new Infragistics.Win.UltraWinEditors.UltraComboEditor();
            this.cboCategory.SelectionChanged += new System.EventHandler(cboCategory_SelectionChanged);
            this.lblCategory = new System.Windows.Forms.Label();
            this.cdvLayout = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvLayout.ButtonPress += new System.EventHandler(cdvLayout_ButtonPress);
            this.lblLayout = new System.Windows.Forms.Label();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvFactory.ButtonPress += new System.EventHandler(cdvFactory_ButtonPress);
            this.lblFactory = new System.Windows.Forms.Label();
            this.pnlBottom.SuspendLayout();
            this.pnlFill.SuspendLayout();
            this.grpDefault.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize) this.cboCategory).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvLayout).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvFactory).BeginInit();
            this.SuspendLayout();
            //
            //pnlBottom
            //
            this.pnlBottom.Controls.Add(this.btnClear);
            this.pnlBottom.Controls.Add(this.btnOK);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.pnlBottom.Location = new System.Drawing.Point(0, 108);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(326, 40);
            this.pnlBottom.TabIndex = 3;
            //
            //btnClear
            //
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnClear.Location = new System.Drawing.Point(168, 9);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(74, 23);
            this.btnClear.TabIndex = 2;
            this.btnClear.Text = "Clear";
            //
            //btnOK
            //
            this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOK.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnOK.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnOK.Location = new System.Drawing.Point(88, 9);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(74, 23);
            this.btnOK.TabIndex = 0;
            this.btnOK.Text = "Save";
            //
            //btnClose
            //
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnClose.Location = new System.Drawing.Point(244, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            //
            //pnlFill
            //
            this.pnlFill.Controls.Add(this.grpDefault);
            this.pnlFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlFill.DockPadding.Left = 3;
            this.pnlFill.DockPadding.Right = 3;
            this.pnlFill.Location = new System.Drawing.Point(0, 0);
            this.pnlFill.Name = "pnlFill";
            this.pnlFill.Size = new System.Drawing.Size(326, 108);
            this.pnlFill.TabIndex = 4;
            //
            //grpDefault
            //
            this.grpDefault.Controls.Add(this.cboCategory);
            this.grpDefault.Controls.Add(this.lblCategory);
            this.grpDefault.Controls.Add(this.cdvLayout);
            this.grpDefault.Controls.Add(this.lblLayout);
            this.grpDefault.Controls.Add(this.cdvFactory);
            this.grpDefault.Controls.Add(this.lblFactory);
            this.grpDefault.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpDefault.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpDefault.Location = new System.Drawing.Point(3, 0);
            this.grpDefault.Name = "grpDefault";
            this.grpDefault.Size = new System.Drawing.Size(320, 108);
            this.grpDefault.TabIndex = 1;
            this.grpDefault.TabStop = false;
            //
            //cboCategory
            //
            this.cboCategory.DropDownStyle = Infragistics.Win.DropDownStyle.DropDownList;
            this.cboCategory.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            ValueListItem1.DataValue = "ValueListItem0";
            ValueListItem1.DisplayText = "Layout";
            ValueListItem2.DataValue = "ValueListItem1";
            ValueListItem2.DisplayText = "User Group";
            this.cboCategory.Items.Add(ValueListItem1);
            this.cboCategory.Items.Add(ValueListItem2);
            this.cboCategory.Location = new System.Drawing.Point(120, 16);
            this.cboCategory.Name = "cboCategory";
            this.cboCategory.Size = new System.Drawing.Size(120, 19);
            this.cboCategory.TabIndex = 62;
            //
            //lblCategory
            //
            this.lblCategory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCategory.Location = new System.Drawing.Point(12, 18);
            this.lblCategory.Name = "lblCategory";
            this.lblCategory.Size = new System.Drawing.Size(75, 14);
            this.lblCategory.TabIndex = 61;
            this.lblCategory.Text = "Category";
            //
            //cdvLayout
            //
            this.cdvLayout.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvLayout.BtnToolTipText = "";
            this.cdvLayout.DescText = "";
            this.cdvLayout.DisplaySubItemIndex = - 1;
            this.cdvLayout.DisplayText = "";
            this.cdvLayout.Focusing = null;
            this.cdvLayout.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.cdvLayout.Index = 0;
            this.cdvLayout.IsViewBtnImage = false;
            this.cdvLayout.Location = new System.Drawing.Point(120, 71);
            this.cdvLayout.MaxLength = 10;
            this.cdvLayout.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvLayout.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvLayout.Name = "cdvLayout";
            this.cdvLayout.ReadOnly = false;
            this.cdvLayout.SearchSubItemIndex = 0;
            this.cdvLayout.SelectedDescIndex = - 1;
            this.cdvLayout.SelectedSubItemIndex = - 1;
            this.cdvLayout.SelectionStart = 0;
            this.cdvLayout.Size = new System.Drawing.Size(168, 20);
            this.cdvLayout.SmallImageList = null;
            this.cdvLayout.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvLayout.TabIndex = 59;
            this.cdvLayout.TextBoxToolTipText = "";
            this.cdvLayout.TextBoxWidth = 168;
            this.cdvLayout.VisibleButton = true;
            this.cdvLayout.VisibleColumnHeader = false;
            this.cdvLayout.VisibleDescription = false;
            //
            //lblLayout
            //
            this.lblLayout.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLayout.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.lblLayout.Location = new System.Drawing.Point(12, 74);
            this.lblLayout.Name = "lblLayout";
            this.lblLayout.Size = new System.Drawing.Size(100, 14);
            this.lblLayout.TabIndex = 60;
            this.lblLayout.Text = "Layout";
            //
            //cdvFactory
            //
            this.cdvFactory.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvFactory.BtnToolTipText = "";
            this.cdvFactory.DescText = "";
            this.cdvFactory.DisplaySubItemIndex = - 1;
            this.cdvFactory.DisplayText = "";
            this.cdvFactory.Focusing = null;
            this.cdvFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.cdvFactory.Index = 0;
            this.cdvFactory.IsViewBtnImage = false;
            this.cdvFactory.Location = new System.Drawing.Point(120, 43);
            this.cdvFactory.MaxLength = 10;
            this.cdvFactory.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.Name = "cdvFactory";
            this.cdvFactory.ReadOnly = false;
            this.cdvFactory.SearchSubItemIndex = 0;
            this.cdvFactory.SelectedDescIndex = - 1;
            this.cdvFactory.SelectedSubItemIndex = - 1;
            this.cdvFactory.SelectionStart = 0;
            this.cdvFactory.Size = new System.Drawing.Size(168, 20);
            this.cdvFactory.SmallImageList = null;
            this.cdvFactory.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvFactory.TabIndex = 57;
            this.cdvFactory.TextBoxToolTipText = "";
            this.cdvFactory.TextBoxWidth = 168;
            this.cdvFactory.VisibleButton = true;
            this.cdvFactory.VisibleColumnHeader = false;
            this.cdvFactory.VisibleDescription = false;
            //
            //lblFactory
            //
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.lblFactory.Location = new System.Drawing.Point(12, 46);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(100, 14);
            this.lblFactory.TabIndex = 58;
            this.lblFactory.Text = "Factory";
            //
            //frmFMBSetupDefaultLayout
            //
            this.AcceptButton = this.btnOK;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btnClose;
            this.ClientSize = new System.Drawing.Size(326, 148);
            this.Controls.Add(this.pnlFill);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFMBSetupDefaultLayout";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Default Layout Setup";
            this.pnlBottom.ResumeLayout(false);
            this.pnlFill.ResumeLayout(false);
            this.grpDefault.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize) this.cboCategory).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvLayout).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvFactory).EndInit();
            this.ResumeLayout(false);
            
        }
        
        #endregion
        
        private void GetLayoutInfo()
        {
            
            try
            {
                string sCategory;
                string sFactory;
                string sLayout;
                sCategory = MPCF.GetRegSetting(Application.ProductName, "DefaultLayout", "Category", "");

                sFactory = MPCF.GetRegSetting(Application.ProductName, "DefaultLayout", "Factory", "");
                sLayout = MPCF.GetRegSetting(Application.ProductName, "DefaultLayout", "Layout", "");
                if (modGlobalVariable.gbAllFactory == false)
                {
                    if (sFactory != MPGV.gsFactory)
                    {
                        return;
                    }
                }
                else
                {
                    if (sCategory == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        if (sFactory != MPGV.gsFactory)
                        {
                            return;
                        }
                    }
                }
                if (sCategory == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    cboCategory.SelectedIndex = 0;
                }
                else if (sCategory == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    cboCategory.SelectedIndex = 1;
                }
                cdvFactory.Text = sFactory;
                cdvLayout.Text = sLayout;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupDefaultLayout.GetLayoutInfo()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBSetupDefaultLayout.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvFactory.Init();
                cdvFactory.Columns.Add("Factory", 100, HorizontalAlignment.Left);
                cdvFactory.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFactory.SelectedSubItemIndex = 0;
                cdvFactory.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1',null);
                cdvFactory.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupDefaultLayout.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvLayout_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                if (cboCategory.SelectedIndex == - 1)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cboCategory.Focus();
                    return;
                }
                cdvLayout.Init();
                cdvLayout.Columns.Add("Layout", 100, HorizontalAlignment.Left);
                cdvLayout.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLayout.SelectedSubItemIndex = 0;
                cdvLayout.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (cboCategory.SelectedIndex == 0)
                {
                    modListRoutine.ViewLayOutList(cdvLayout.GetListView, '1', cdvFactory.Text);
                }
                else if (cboCategory.SelectedIndex == 1)
                {
                    modListRoutine.ViewUDR_GroupList(cdvLayout.GetListView, '1');
                }
                cdvLayout.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupDefaultLayout.cdvLayout_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cboCategory_SelectionChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvFactory.Text = "";
                cdvLayout.Text = "";
                
                if (cboCategory.SelectedIndex == 0)
                {
                    FMBCF.CheckAllFactoryOption(cdvFactory);
                }
                else if (cboCategory.SelectedIndex == 1)
                {
                    cdvFactory.Text = MPGV.gsFactory;
                    cdvFactory.ReadOnly = true;
                    cdvFactory.VisibleButton = false;
                    cdvFactory.BackColor = SystemColors.Control;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBArrangeLayout.frmFMBArrangeLayout_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnOK_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                string sTag = "";
                if (cdvFactory.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cdvFactory.Focus();
                    this.DialogResult = DialogResult.None;
                    return;
                }
                
                if (cdvLayout.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cdvLayout.Focus();
                    this.DialogResult = DialogResult.None;
                    return;
                }
                
                if (cboCategory.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    cboCategory.Focus();
                    this.DialogResult = DialogResult.None;
                    return;
                }
                if (cboCategory.SelectedIndex == 0)
                {
                    sTag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                }
                else if (cboCategory.SelectedIndex == 1)
                {
                    sTag = modGlobalConstant.FMB_CATEGORY_GROUP;
                }

                MPCF.SaveRegSetting(Application.ProductName, "DefaultLayout", "Category", sTag);
                MPCF.SaveRegSetting(Application.ProductName, "DefaultLayout", "Factory", MPCF.RTrim(cdvFactory.Text));
                MPCF.SaveRegSetting(Application.ProductName, "DefaultLayout", "Layout", MPCF.RTrim(cdvLayout.Text));
                
                MPCF.ShowMsgBox(MPCF.GetMessage(4), Application.ProductName, MessageBoxButtons.OK, 1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupDefaultLayout.btnOK_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBSetupDefaultLayout_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                FMBCF.CheckAllFactoryOption(cdvFactory);
                GetLayoutInfo();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupDefaultLayout.frmFMBSetupDefaultLayout_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnClear_Click(System.Object sender, System.EventArgs e)
        {
            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(33), Application.ProductName, MessageBoxButtons.YesNo, 1) == System.Windows.Forms.DialogResult.No)
                {
                    return;
                }
                MPCF.SaveRegSetting(Application.ProductName, "DefaultLayout", "Category", "");
                MPCF.SaveRegSetting(Application.ProductName, "DefaultLayout", "Factory", "");
                MPCF.SaveRegSetting(Application.ProductName, "DefaultLayout", "Layout", "");
                
                MPCF.FieldClear(this, null, null, null, null, null, false);
                this.cboCategory.SelectedIndex = - 1;
                MPCF.ShowMsgBox(MPCF.GetMessage(4), Application.ProductName, MessageBoxButtons.OK, 1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupDefaultLayout.btnClear_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }
        
    }
    
}
