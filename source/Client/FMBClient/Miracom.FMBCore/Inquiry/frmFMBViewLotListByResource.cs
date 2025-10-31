
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;

using Miracom.CliFrx;
using Miracom.MESCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBViewLotListByResource.vb
//   Description : View Lot List by Resource
//
//   FMB Version : 1.0.0
//
//   Function List
//       - CheckCondition() : Check the conditions before transaction
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-17 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------
namespace Miracom.FMBCore
{
    public class frmFMBViewLotListByResource : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBViewLotListByResource()
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
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.GroupBox grpTop;
        internal System.Windows.Forms.Panel pnlCenter;
        internal Miracom.UI.Controls.MCListView.MCListView lisLotList;
        internal System.Windows.Forms.ColumnHeader ColumnHeader1;
        internal System.Windows.Forms.ColumnHeader ColumnHeader2;
        internal System.Windows.Forms.ColumnHeader ColumnHeader3;
        internal System.Windows.Forms.ColumnHeader ColumnHeader4;
        internal System.Windows.Forms.ColumnHeader ColumnHeader5;
        internal System.Windows.Forms.ColumnHeader ColumnHeader6;
        internal System.Windows.Forms.ColumnHeader ColumnHeader7;
        internal System.Windows.Forms.ColumnHeader ColumnHeader8;
        internal System.Windows.Forms.ColumnHeader ColumnHeader9;
        internal System.Windows.Forms.ColumnHeader ColumnHeader10;
        internal System.Windows.Forms.ColumnHeader ColumnHeader11;
        internal System.Windows.Forms.ColumnHeader ColumnHeader12;
        internal System.Windows.Forms.ColumnHeader ColumnHeader13;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvResID;
        internal System.Windows.Forms.Label lblResID;
        internal System.Windows.Forms.Label lblOper;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvOper;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal System.Windows.Forms.Button btnView;
        internal System.Windows.Forms.Button btnClose;
        internal Infragistics.Win.UltraWinEditors.UltraCheckEditor chkOnlyProcLot;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlTop = new System.Windows.Forms.Panel();
            base.Activated += new System.EventHandler(frmFMBViewLotListByResource_Activated);
            base.Load += new System.EventHandler(frmFMBViewLotListByResource_Load);
            this.grpTop = new System.Windows.Forms.GroupBox();
            this.chkOnlyProcLot = new Infragistics.Win.UltraWinEditors.UltraCheckEditor();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvFactory.ButtonPress += new System.EventHandler(cdvFactory_ButtonPress);
            this.cdvFactory.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(cdvFactory_SelectedItemChanged);
            this.cdvFactory.TextBoxTextChanged += new System.EventHandler(cdvFactory_TextBoxTextChanged);
            this.lblFactory = new System.Windows.Forms.Label();
            this.cdvResID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvResID.ButtonPress += new System.EventHandler(cdvResID_ButtonPress);
            this.cdvResID.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(cdvResID_SelectedItemChanged);
            this.cdvResID.TextBoxTextChanged += new System.EventHandler(cdvResID_TextBoxTextChanged);
            this.lblResID = new System.Windows.Forms.Label();
            this.lblOper = new System.Windows.Forms.Label();
            this.cdvOper = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvOper.ButtonPress += new System.EventHandler(cdvOper_ButtonPress);
            this.cdvOper.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(cdvOper_SelectedItemChanged);
            this.cdvOper.TextBoxTextChanged += new System.EventHandler(cdvOper_TextBoxTextChanged);
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnView = new System.Windows.Forms.Button();
            this.btnView.Click += new System.EventHandler(btnView_Click);
            this.btnClose = new System.Windows.Forms.Button();
            this.btnClose.Click += new System.EventHandler(btnClose_Click);
            this.pnlCenter = new System.Windows.Forms.Panel();
            this.lisLotList = new Miracom.UI.Controls.MCListView.MCListView();
            this.lisLotList.ColumnClick += new System.Windows.Forms.ColumnClickEventHandler(lisLotList_ColumnClick);
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader7 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader9 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader10 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader11 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader12 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader13 = new System.Windows.Forms.ColumnHeader();
            this.pnlTop.SuspendLayout();
            this.grpTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize) this.cdvFactory).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvResID).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvOper).BeginInit();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.SuspendLayout();
            //
            //pnlTop
            //
            this.pnlTop.Controls.Add(this.grpTop);
            this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTop.DockPadding.Left = 3;
            this.pnlTop.DockPadding.Right = 3;
            this.pnlTop.Location = new System.Drawing.Point(0, 0);
            this.pnlTop.Name = "pnlTop";
            this.pnlTop.Size = new System.Drawing.Size(742, 71);
            this.pnlTop.TabIndex = 0;
            //
            //grpTop
            //
            this.grpTop.Controls.Add(this.chkOnlyProcLot);
            this.grpTop.Controls.Add(this.cdvFactory);
            this.grpTop.Controls.Add(this.lblFactory);
            this.grpTop.Controls.Add(this.cdvResID);
            this.grpTop.Controls.Add(this.lblResID);
            this.grpTop.Controls.Add(this.lblOper);
            this.grpTop.Controls.Add(this.cdvOper);
            this.grpTop.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpTop.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpTop.Location = new System.Drawing.Point(3, 0);
            this.grpTop.Name = "grpTop";
            this.grpTop.Size = new System.Drawing.Size(736, 71);
            this.grpTop.TabIndex = 0;
            this.grpTop.TabStop = false;
            //
            //chkOnlyProcLot
            //
            this.chkOnlyProcLot.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.chkOnlyProcLot.ForeColor = System.Drawing.SystemColors.ControlText;
            this.chkOnlyProcLot.Location = new System.Drawing.Point(527, 43);
            this.chkOnlyProcLot.Name = "chkOnlyProcLot";
            this.chkOnlyProcLot.Size = new System.Drawing.Size(196, 14);
            this.chkOnlyProcLot.TabIndex = 3;
            this.chkOnlyProcLot.Text = "Only Proc Lot";
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
            this.cdvFactory.Location = new System.Drawing.Point(118, 17);
            this.cdvFactory.MaxLength = 10;
            this.cdvFactory.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.Name = "cdvFactory";
            this.cdvFactory.ReadOnly = false;
            this.cdvFactory.SearchSubItemIndex = 0;
            this.cdvFactory.SelectedDescIndex = - 1;
            this.cdvFactory.SelectedSubItemIndex = - 1;
            this.cdvFactory.SelectionStart = 0;
            this.cdvFactory.Size = new System.Drawing.Size(200, 20);
            this.cdvFactory.SmallImageList = null;
            this.cdvFactory.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvFactory.TabIndex = 0;
            this.cdvFactory.TextBoxToolTipText = "";
            this.cdvFactory.TextBoxWidth = 200;
            this.cdvFactory.VisibleButton = true;
            this.cdvFactory.VisibleColumnHeader = false;
            this.cdvFactory.VisibleDescription = false;
            //
            //lblFactory
            //
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.lblFactory.Location = new System.Drawing.Point(13, 20);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(100, 14);
            this.lblFactory.TabIndex = 50;
            this.lblFactory.Text = "Factory";
            //
            //cdvResID
            //
            this.cdvResID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvResID.BtnToolTipText = "";
            this.cdvResID.DescText = "";
            this.cdvResID.DisplaySubItemIndex = - 1;
            this.cdvResID.DisplayText = "";
            this.cdvResID.Focusing = null;
            this.cdvResID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.cdvResID.Index = 0;
            this.cdvResID.IsViewBtnImage = false;
            this.cdvResID.Location = new System.Drawing.Point(118, 41);
            this.cdvResID.MaxLength = 20;
            this.cdvResID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvResID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvResID.Name = "cdvResID";
            this.cdvResID.ReadOnly = false;
            this.cdvResID.SearchSubItemIndex = 0;
            this.cdvResID.SelectedDescIndex = - 1;
            this.cdvResID.SelectedSubItemIndex = - 1;
            this.cdvResID.SelectionStart = 0;
            this.cdvResID.Size = new System.Drawing.Size(200, 20);
            this.cdvResID.SmallImageList = null;
            this.cdvResID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvResID.TabIndex = 1;
            this.cdvResID.TextBoxToolTipText = "";
            this.cdvResID.TextBoxWidth = 200;
            this.cdvResID.VisibleButton = true;
            this.cdvResID.VisibleColumnHeader = false;
            this.cdvResID.VisibleDescription = false;
            //
            //lblResID
            //
            this.lblResID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.lblResID.Location = new System.Drawing.Point(13, 44);
            this.lblResID.Name = "lblResID";
            this.lblResID.Size = new System.Drawing.Size(100, 14);
            this.lblResID.TabIndex = 4;
            this.lblResID.Text = "Resource ID";
            //
            //lblOper
            //
            this.lblOper.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblOper.Location = new System.Drawing.Point(418, 20);
            this.lblOper.Name = "lblOper";
            this.lblOper.Size = new System.Drawing.Size(100, 14);
            this.lblOper.TabIndex = 6;
            this.lblOper.Text = "Operation";
            //
            //cdvOper
            //
            this.cdvOper.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvOper.BtnToolTipText = "";
            this.cdvOper.DescText = "";
            this.cdvOper.DisplaySubItemIndex = - 1;
            this.cdvOper.DisplayText = "";
            this.cdvOper.Focusing = null;
            this.cdvOper.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.cdvOper.Index = 0;
            this.cdvOper.IsViewBtnImage = false;
            this.cdvOper.Location = new System.Drawing.Point(523, 17);
            this.cdvOper.MaxLength = 10;
            this.cdvOper.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOper.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvOper.Name = "cdvOper";
            this.cdvOper.ReadOnly = false;
            this.cdvOper.SearchSubItemIndex = 0;
            this.cdvOper.SelectedDescIndex = - 1;
            this.cdvOper.SelectedSubItemIndex = - 1;
            this.cdvOper.SelectionStart = 0;
            this.cdvOper.Size = new System.Drawing.Size(200, 20);
            this.cdvOper.SmallImageList = null;
            this.cdvOper.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvOper.TabIndex = 2;
            this.cdvOper.TextBoxToolTipText = "";
            this.cdvOper.TextBoxWidth = 200;
            this.cdvOper.VisibleButton = true;
            this.cdvOper.VisibleColumnHeader = false;
            this.cdvOper.VisibleDescription = false;
            //
            //pnlBottom
            //
            this.pnlBottom.Controls.Add(this.btnView);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 506);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 1;
            //
            //btnView
            //
            this.btnView.Anchor = (System.Windows.Forms.AnchorStyles) (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
            this.btnView.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnView.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnView.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnView.Location = new System.Drawing.Point(579, 9);
            this.btnView.Name = "btnView";
            this.btnView.Size = new System.Drawing.Size(74, 23);
            this.btnView.TabIndex = 0;
            this.btnView.Text = "View";
            //
            //btnClose
            //
            this.btnClose.Anchor = (System.Windows.Forms.AnchorStyles) (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnClose.Location = new System.Drawing.Point(659, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            //
            //pnlCenter
            //
            this.pnlCenter.Controls.Add(this.lisLotList);
            this.pnlCenter.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCenter.DockPadding.Left = 3;
            this.pnlCenter.DockPadding.Right = 3;
            this.pnlCenter.DockPadding.Top = 5;
            this.pnlCenter.Location = new System.Drawing.Point(0, 71);
            this.pnlCenter.Name = "pnlCenter";
            this.pnlCenter.Size = new System.Drawing.Size(742, 435);
            this.pnlCenter.TabIndex = 2;
            //
            //lisLotList
            //
            this.lisLotList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] { this.ColumnHeader1, this.ColumnHeader2, this.ColumnHeader3, this.ColumnHeader4, this.ColumnHeader5, this.ColumnHeader6, this.ColumnHeader7, this.ColumnHeader8, this.ColumnHeader9, this.ColumnHeader10, this.ColumnHeader11, this.ColumnHeader12, this.ColumnHeader13 });
            this.lisLotList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisLotList.EnableSort = true;
            this.lisLotList.EnableSortIcon = true;
            this.lisLotList.FullRowSelect = true;
            this.lisLotList.Location = new System.Drawing.Point(3, 5);
            this.lisLotList.Name = "lisLotList";
            this.lisLotList.Size = new System.Drawing.Size(736, 430);
            this.lisLotList.TabIndex = 1;
            this.lisLotList.Tag = "True";
            this.lisLotList.View = System.Windows.Forms.View.Details;
            //
            //ColumnHeader1
            //
            this.ColumnHeader1.Text = "Lot ID";
            this.ColumnHeader1.Width = 100;
            //
            //ColumnHeader2
            //
            this.ColumnHeader2.Text = "Lot Status";
            this.ColumnHeader2.Width = 70;
            //
            //ColumnHeader3
            //
            this.ColumnHeader3.Text = "Material ID";
            this.ColumnHeader3.Width = 115;
            //
            //ColumnHeader4
            //
            this.ColumnHeader4.Text = "Flow";
            this.ColumnHeader4.Width = 80;
            //
            //ColumnHeader5
            //
            this.ColumnHeader5.Text = "Operation";
            this.ColumnHeader5.Width = 80;
            //
            //ColumnHeader6
            //
            this.ColumnHeader6.Text = "Qty1";
            this.ColumnHeader6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //ColumnHeader7
            //
            this.ColumnHeader7.Text = "Qty2";
            this.ColumnHeader7.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //ColumnHeader8
            //
            this.ColumnHeader8.Text = "Qty3";
            this.ColumnHeader8.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            //
            //ColumnHeader9
            //
            this.ColumnHeader9.Text = "Lot Type";
            //
            //ColumnHeader10
            //
            this.ColumnHeader10.Text = "Lot Priority";
            this.ColumnHeader10.Width = 70;
            //
            //ColumnHeader11
            //
            this.ColumnHeader11.Text = "Create Code";
            this.ColumnHeader11.Width = 90;
            //
            //ColumnHeader12
            //
            this.ColumnHeader12.Text = "Owner Code";
            this.ColumnHeader12.Width = 90;
            //
            //ColumnHeader13
            //
            this.ColumnHeader13.Text = "Hold Code";
            this.ColumnHeader13.Width = 90;
            //
            //frmFMBViewLotListByResource
            //
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 546);
            this.Controls.Add(this.pnlCenter);
            this.Controls.Add(this.pnlTop);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBViewLotListByResource";
            this.Tag = "FMB3005";
            this.Text = "View Lot List by Resource";
            this.pnlTop.ResumeLayout(false);
            this.grpTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize) this.cdvFactory).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvResID).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvOper).EndInit();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.ResumeLayout(false);
            
        }
        
        #endregion
        
        #region " Variable Definition"
        private bool b_load_flag;
        #endregion
        
        #region " Function Implementations"
        
        // CheckCondition()
        //       - Check the conditions before transaction
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String  : Step
        //
        private bool CheckCondition(string sStep)
        {
            
            try
            {
                switch (MPCF.RTrim(sStep))
                {
                    case "1":
                        
                        if (cdvFactory.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        break;
                    case "2":
                        
                        if (cdvFactory.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        if (cdvResID.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvResID.Focus();
                            return false;
                        }
                        break;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        #endregion
        
        #region " Event Implementations"
        
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
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvResID_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                cdvResID.Init();
                cdvResID.Columns.Add("ResID", 50, HorizontalAlignment.Left);
                cdvResID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResID.SelectedSubItemIndex = 0;
                cdvResID.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                if (CheckCondition("1") == false)
                {
                    return;
                }
                RASLIST.ViewResourceList(cdvResID.GetListView, '2',"","","","","",0,"","",' ',"",false,null, cdvFactory.Text);
                cdvResID.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvResID_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvOper_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("1") == false)
                {
                    cdvOper.IsPopup = false;
                    return;
                }
                cdvOper.Init();
                cdvOper.Columns.Add("Oper", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewOperationList(cdvOper.GetListView, '1');
                cdvOper.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvOper_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnClose_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                this.Dispose();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnView_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("2") == false)
                {
                    return;
                }
                if (chkOnlyProcLot.Checked == false)
                {
                    if (modListRoutine.ViewLotByResList(lisLotList, '1', cdvResID.Text, cdvOper.Text, cdvFactory.Text) == false)
                    {
                        return;
                    }
                }
                else if (chkOnlyProcLot.Checked == true)
                {
                    if (modListRoutine.ViewResLotList(lisLotList, '1', cdvResID.Text, cdvFactory.Text, cdvOper.Text, true) == false)
                    {
                        return;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.btnView_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                cdvResID.Text = "";
                cdvOper.Text = "";
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvFactory_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvResID_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvResID_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvResID.Text = "";
                cdvOper.Text = "";
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvResID_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvResID_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBViewLotListByResource_Activated(object sender, System.EventArgs e)
        {
            
            try
            {
                if (b_load_flag == false)
                {
                    MPCF.InitListView(lisLotList);
                    b_load_flag = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.frmFMBViewLotListByResource_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvOper_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvOper_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvOper_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                lisLotList.Items.Clear();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.cdvOper_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void lisLotList_ColumnClick(object sender, System.Windows.Forms.ColumnClickEventArgs e)
        {
            
            try
            {
                if (MPCF.RTrim(lisLotList.Tag.ToString()) == "True")
                {
                    lisLotList.Tag = false;
                }
                else
                {
                    lisLotList.Tag = true;
                }

                this.lisLotList.ListViewItemSorter = new ListViewItemComparer(e.Column, ((bool)lisLotList.Tag == true ? SortOrder.Descending : SortOrder.Ascending), ListViewItemComparer.SORTING_OPTION.STRING_TYPE);
                lisLotList.Sort();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.lisLotList_ColumnClick()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBViewLotListByResource_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                
                FMBCF.CheckAllFactoryOption(cdvFactory);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListByResource.frmFMBViewLotListByResource_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
