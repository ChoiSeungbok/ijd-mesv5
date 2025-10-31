
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Infragistics.Win.UltraWinEditors;
using Miracom.CliFrx;
using Miracom.TRSCore;
using Miracom.MESCore;
using Miracom.MsgHandler;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBCreateLayOut.vb
//   Description : Create/Update/Delete LayOut
//
//   FMB Version : 1.0.0
//
//   Function List
//       - CheckCondition() : Check the conditions before transaction
//       - View_LayOut() : View Layout Information
//       - Update_LayOut() : Create/Update/Delete Layout
//       - Exist_Control_LayOut() : Check Exist Control Out of the LayOut
//       - Move_Controls_LayOut() : Move Controls by Force
//
//   Detail Description
//       - 2005-02-11 : Created by H.K.Kim
//
//   History
//       -
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public class frmFMBCreateLayOut : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBCreateLayOut()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        public frmFMBCreateLayOut(string sLayout)
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
            sSelectedLayout = sLayout;
            
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
        internal System.Windows.Forms.Panel pnlList;
        internal System.Windows.Forms.Panel pnlBottom;
        internal Miracom.UI.Controls.MCListView.MCListView lisLayOutList;
        internal System.Windows.Forms.ColumnHeader ColumnHeader1;
        internal System.Windows.Forms.ColumnHeader ColumnHeader2;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.GroupBox grpLayOut;
        internal UltraTextEditor txtLayOutID;
        internal UltraTextEditor txtDesc;
        internal System.Windows.Forms.Label lblLayOutID;
        internal System.Windows.Forms.Label lblDesc;
        internal System.Windows.Forms.Label lblUpdateUser;
        internal System.Windows.Forms.Label lblCreateUser;
        internal System.Windows.Forms.Label lblUpdateTime;
        internal UltraTextEditor txtCreateTime;
        internal System.Windows.Forms.Label lblCreateTime;
        internal System.Windows.Forms.Button btnUpdate;
        internal System.Windows.Forms.Button btnCreate;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Button btnDelete;
        internal UltraTextEditor txtUpdateUser;
        internal UltraTextEditor txtCreateUser;
        internal UltraTextEditor txtUpdateTime;
        internal System.Windows.Forms.Label lblHeight;
        internal UltraTextEditor txtHeight;
        internal UltraTextEditor txtWidth;
        internal System.Windows.Forms.Label lblWidth;
        internal System.Windows.Forms.ColumnHeader ColumnHeader3;
        internal System.Windows.Forms.ColumnHeader ColumnHeader4;
        internal System.Windows.Forms.Label lblFactory;
        public Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlList = new System.Windows.Forms.Panel();
            this.lisLayOutList = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnCreate = new System.Windows.Forms.Button();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpLayOut = new System.Windows.Forms.GroupBox();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.lblHeight = new System.Windows.Forms.Label();
            this.txtHeight = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtWidth = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblWidth = new System.Windows.Forms.Label();
            this.lblUpdateUser = new System.Windows.Forms.Label();
            this.txtUpdateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateUser = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCreateUser = new System.Windows.Forms.Label();
            this.lblUpdateTime = new System.Windows.Forms.Label();
            this.txtUpdateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCreateTime = new System.Windows.Forms.Label();
            this.lblDesc = new System.Windows.Forms.Label();
            this.lblLayOutID = new System.Windows.Forms.Label();
            this.txtDesc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtLayOutID = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.pnlList.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.grpLayOut.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLayOutID)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlList
            // 
            this.pnlList.Controls.Add(this.lisLayOutList);
            this.pnlList.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlList.Location = new System.Drawing.Point(0, 0);
            this.pnlList.Name = "pnlList";
            this.pnlList.Padding = new System.Windows.Forms.Padding(3, 3, 3, 0);
            this.pnlList.Size = new System.Drawing.Size(458, 144);
            this.pnlList.TabIndex = 0;
            // 
            // lisLayOutList
            // 
            this.lisLayOutList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader1,
            this.ColumnHeader2,
            this.ColumnHeader3,
            this.ColumnHeader4});
            this.lisLayOutList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisLayOutList.EnableSort = true;
            this.lisLayOutList.EnableSortIcon = true;
            this.lisLayOutList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisLayOutList.FullRowSelect = true;
            this.lisLayOutList.Location = new System.Drawing.Point(3, 3);
            this.lisLayOutList.MultiSelect = false;
            this.lisLayOutList.Name = "lisLayOutList";
            this.lisLayOutList.Size = new System.Drawing.Size(452, 141);
            this.lisLayOutList.TabIndex = 0;
            this.lisLayOutList.UseCompatibleStateImageBehavior = false;
            this.lisLayOutList.View = System.Windows.Forms.View.Details;
            this.lisLayOutList.SelectedIndexChanged += new System.EventHandler(this.lisLayOutList_SelectedIndexChanged);
            // 
            // ColumnHeader1
            // 
            this.ColumnHeader1.Text = "LayOut ID";
            this.ColumnHeader1.Width = 170;
            // 
            // ColumnHeader2
            // 
            this.ColumnHeader2.Text = "Description";
            this.ColumnHeader2.Width = 170;
            // 
            // ColumnHeader3
            // 
            this.ColumnHeader3.Text = "Width";
            this.ColumnHeader3.Width = 45;
            // 
            // ColumnHeader4
            // 
            this.ColumnHeader4.Text = "Height";
            this.ColumnHeader4.Width = 45;
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Controls.Add(this.btnDelete);
            this.pnlBottom.Controls.Add(this.btnUpdate);
            this.pnlBottom.Controls.Add(this.btnCreate);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 312);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(458, 40);
            this.pnlBottom.TabIndex = 3;
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Location = new System.Drawing.Point(374, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 3;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnDelete.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnDelete.Location = new System.Drawing.Point(294, 9);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(74, 23);
            this.btnDelete.TabIndex = 2;
            this.btnDelete.Text = "Delete";
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnUpdate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnUpdate.Location = new System.Drawing.Point(214, 9);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(74, 23);
            this.btnUpdate.TabIndex = 1;
            this.btnUpdate.Text = "Update";
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            this.btnUpdate.GotFocus += new System.EventHandler(this.btnUpdate_GotFocus);
            // 
            // btnCreate
            // 
            this.btnCreate.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCreate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnCreate.Location = new System.Drawing.Point(134, 9);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(74, 23);
            this.btnCreate.TabIndex = 0;
            this.btnCreate.Text = "Create";
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            this.btnCreate.GotFocus += new System.EventHandler(this.btnCreate_GotFocus);
            // 
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.grpLayOut);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 144);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(458, 168);
            this.pnlMid.TabIndex = 1;
            // 
            // grpLayOut
            // 
            this.grpLayOut.Controls.Add(this.cdvFactory);
            this.grpLayOut.Controls.Add(this.lblFactory);
            this.grpLayOut.Controls.Add(this.lblHeight);
            this.grpLayOut.Controls.Add(this.txtHeight);
            this.grpLayOut.Controls.Add(this.txtWidth);
            this.grpLayOut.Controls.Add(this.lblWidth);
            this.grpLayOut.Controls.Add(this.lblUpdateUser);
            this.grpLayOut.Controls.Add(this.txtUpdateUser);
            this.grpLayOut.Controls.Add(this.txtCreateUser);
            this.grpLayOut.Controls.Add(this.lblCreateUser);
            this.grpLayOut.Controls.Add(this.lblUpdateTime);
            this.grpLayOut.Controls.Add(this.txtUpdateTime);
            this.grpLayOut.Controls.Add(this.txtCreateTime);
            this.grpLayOut.Controls.Add(this.lblCreateTime);
            this.grpLayOut.Controls.Add(this.lblDesc);
            this.grpLayOut.Controls.Add(this.lblLayOutID);
            this.grpLayOut.Controls.Add(this.txtDesc);
            this.grpLayOut.Controls.Add(this.txtLayOutID);
            this.grpLayOut.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpLayOut.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpLayOut.Location = new System.Drawing.Point(3, 0);
            this.grpLayOut.Name = "grpLayOut";
            this.grpLayOut.Size = new System.Drawing.Size(452, 168);
            this.grpLayOut.TabIndex = 0;
            this.grpLayOut.TabStop = false;
            // 
            // cdvFactory
            // 
            this.cdvFactory.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvFactory.BorderHotColor = System.Drawing.Color.Black;
            this.cdvFactory.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvFactory.BtnToolTipText = "";
            this.cdvFactory.DescText = "";
            this.cdvFactory.DisplaySubItemIndex = -1;
            this.cdvFactory.DisplayText = "";
            this.cdvFactory.Focusing = null;
            this.cdvFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvFactory.Index = 0;
            this.cdvFactory.IsViewBtnImage = false;
            this.cdvFactory.Location = new System.Drawing.Point(103, 17);
            this.cdvFactory.MaxLength = 10;
            this.cdvFactory.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.Name = "cdvFactory";
            this.cdvFactory.ReadOnly = false;
            this.cdvFactory.SearchSubItemIndex = 0;
            this.cdvFactory.SelectedDescIndex = -1;
            this.cdvFactory.SelectedSubItemIndex = -1;
            this.cdvFactory.SelectionStart = 0;
            this.cdvFactory.Size = new System.Drawing.Size(136, 20);
            this.cdvFactory.SmallImageList = null;
            this.cdvFactory.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvFactory.TabIndex = 0;
            this.cdvFactory.TextBoxToolTipText = "";
            this.cdvFactory.TextBoxWidth = 136;
            this.cdvFactory.VisibleButton = true;
            this.cdvFactory.VisibleColumnHeader = false;
            this.cdvFactory.VisibleDescription = false;
            this.cdvFactory.ButtonPress += new System.EventHandler(this.cdvFactory_ButtonPress);
            this.cdvFactory.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvFactory_SelectedItemChanged);
            // 
            // lblFactory
            // 
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Location = new System.Drawing.Point(9, 20);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(88, 14);
            this.lblFactory.TabIndex = 78;
            this.lblFactory.Text = "Factory";
            // 
            // lblHeight
            // 
            this.lblHeight.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHeight.Location = new System.Drawing.Point(231, 93);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(88, 14);
            this.lblHeight.TabIndex = 77;
            this.lblHeight.Text = "Height";
            // 
            // txtHeight
            // 
            this.txtHeight.Location = new System.Drawing.Point(323, 89);
            this.txtHeight.MaxLength = 5;
            this.txtHeight.Name = "txtHeight";
            this.txtHeight.Size = new System.Drawing.Size(120, 19);
            this.txtHeight.TabIndex = 4;
            this.txtHeight.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtHeight.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtHeight_KeyPress);
            // 
            // txtWidth
            // 
            this.txtWidth.Location = new System.Drawing.Point(103, 89);
            this.txtWidth.MaxLength = 5;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(120, 19);
            this.txtWidth.TabIndex = 3;
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.txtWidth.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtWidth_KeyPress);
            // 
            // lblWidth
            // 
            this.lblWidth.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblWidth.Location = new System.Drawing.Point(8, 93);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(88, 14);
            this.lblWidth.TabIndex = 74;
            this.lblWidth.Text = "Width";
            // 
            // lblUpdateUser
            // 
            this.lblUpdateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateUser.Location = new System.Drawing.Point(231, 117);
            this.lblUpdateUser.Name = "lblUpdateUser";
            this.lblUpdateUser.Size = new System.Drawing.Size(88, 14);
            this.lblUpdateUser.TabIndex = 73;
            this.lblUpdateUser.Text = "Update User ID";
            // 
            // txtUpdateUser
            // 
            this.txtUpdateUser.Location = new System.Drawing.Point(323, 113);
            this.txtUpdateUser.MaxLength = 20;
            this.txtUpdateUser.Name = "txtUpdateUser";
            this.txtUpdateUser.ReadOnly = true;
            this.txtUpdateUser.Size = new System.Drawing.Size(120, 19);
            this.txtUpdateUser.TabIndex = 6;
            this.txtUpdateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateUser
            // 
            this.txtCreateUser.Location = new System.Drawing.Point(103, 113);
            this.txtCreateUser.MaxLength = 20;
            this.txtCreateUser.Name = "txtCreateUser";
            this.txtCreateUser.ReadOnly = true;
            this.txtCreateUser.Size = new System.Drawing.Size(120, 19);
            this.txtCreateUser.TabIndex = 5;
            this.txtCreateUser.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCreateUser
            // 
            this.lblCreateUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateUser.Location = new System.Drawing.Point(8, 117);
            this.lblCreateUser.Name = "lblCreateUser";
            this.lblCreateUser.Size = new System.Drawing.Size(88, 14);
            this.lblCreateUser.TabIndex = 70;
            this.lblCreateUser.Text = "Create User ID";
            // 
            // lblUpdateTime
            // 
            this.lblUpdateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateTime.Location = new System.Drawing.Point(231, 141);
            this.lblUpdateTime.Name = "lblUpdateTime";
            this.lblUpdateTime.Size = new System.Drawing.Size(88, 14);
            this.lblUpdateTime.TabIndex = 69;
            this.lblUpdateTime.Text = "Update Time";
            // 
            // txtUpdateTime
            // 
            this.txtUpdateTime.Location = new System.Drawing.Point(323, 137);
            this.txtUpdateTime.MaxLength = 20;
            this.txtUpdateTime.Name = "txtUpdateTime";
            this.txtUpdateTime.ReadOnly = true;
            this.txtUpdateTime.Size = new System.Drawing.Size(120, 19);
            this.txtUpdateTime.TabIndex = 8;
            this.txtUpdateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateTime
            // 
            this.txtCreateTime.Location = new System.Drawing.Point(103, 137);
            this.txtCreateTime.MaxLength = 20;
            this.txtCreateTime.Name = "txtCreateTime";
            this.txtCreateTime.ReadOnly = true;
            this.txtCreateTime.Size = new System.Drawing.Size(120, 19);
            this.txtCreateTime.TabIndex = 7;
            this.txtCreateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCreateTime
            // 
            this.lblCreateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateTime.Location = new System.Drawing.Point(8, 141);
            this.lblCreateTime.Name = "lblCreateTime";
            this.lblCreateTime.Size = new System.Drawing.Size(88, 14);
            this.lblCreateTime.TabIndex = 66;
            this.lblCreateTime.Text = "Create Time";
            // 
            // lblDesc
            // 
            this.lblDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDesc.Location = new System.Drawing.Point(9, 68);
            this.lblDesc.Name = "lblDesc";
            this.lblDesc.Size = new System.Drawing.Size(88, 14);
            this.lblDesc.TabIndex = 5;
            this.lblDesc.Text = "Description";
            // 
            // lblLayOutID
            // 
            this.lblLayOutID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLayOutID.Location = new System.Drawing.Point(9, 44);
            this.lblLayOutID.Name = "lblLayOutID";
            this.lblLayOutID.Size = new System.Drawing.Size(88, 14);
            this.lblLayOutID.TabIndex = 4;
            this.lblLayOutID.Text = "LayOut ID";
            // 
            // txtDesc
            // 
            this.txtDesc.Location = new System.Drawing.Point(103, 65);
            this.txtDesc.MaxLength = 50;
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.Size = new System.Drawing.Size(341, 19);
            this.txtDesc.TabIndex = 2;
            this.txtDesc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtLayOutID
            // 
            this.txtLayOutID.Location = new System.Drawing.Point(103, 41);
            this.txtLayOutID.MaxLength = 20;
            this.txtLayOutID.Name = "txtLayOutID";
            this.txtLayOutID.Size = new System.Drawing.Size(136, 19);
            this.txtLayOutID.TabIndex = 1;
            this.txtLayOutID.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // frmFMBCreateLayOut
            // 
            this.AcceptButton = this.btnCreate;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(458, 352);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlList);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmFMBCreateLayOut";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Tag = "FMB4001";
            this.Text = "Create LayOut";
            this.Load += new System.EventHandler(this.frmFMBCreateLayOut_Load);
            this.Activated += new System.EventHandler(this.frmFMBCreateLayOut_Activated);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.frmFMBCreateLayOut_KeyPress);
            this.pnlList.ResumeLayout(false);
            this.pnlBottom.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.grpLayOut.ResumeLayout(false);
            this.grpLayOut.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateUser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtLayOutID)).EndInit();
            this.ResumeLayout(false);

        }
        
        #endregion
        
        #region " Variable Definition"
        private bool b_load_flag = false;
        private string sExistFlag = "";
        private string sSelectedLayout = "";
        #endregion
        
        #region " Function Implementations"
        
        // CheckCondition()
        //       - Check the conditions before transaction
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - FuncName as String  : Fuction Name
        //
        private bool CheckCondition(string FuncName)
        {
            
            try
            {
                if (txtLayOutID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    txtLayOutID.Focus();
                    return false;
                }
                switch (MPCF.RTrim(FuncName))
                {
                    case "CREATE":
                        
                        if (MPCF.ToInt(txtWidth.Text) < modGlobalConstant.MIN_VALUE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(38) + modGlobalConstant.MIN_VALUE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtHeight.Text) < modGlobalConstant.MIN_VALUE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(38) + modGlobalConstant.MIN_VALUE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtWidth.Text) > modGlobalConstant.MAX_VALUE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(8) + modGlobalConstant.MAX_VALUE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }
                        if (MPCF.ToInt(txtHeight.Text) > modGlobalConstant.MAX_VALUE)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(8) + modGlobalConstant.MAX_VALUE, Application.ProductName, MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        if (MPCF.CheckNumeric(txtWidth.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtWidth.Focus();
                            return false;
                        }

                        if (MPCF.CheckNumeric(txtHeight.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(17), Application.ProductName, MessageBoxButtons.OK, 1);
                            txtHeight.Focus();
                            return false;
                        }
                        break;
                        
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // View_LayOut()
        //       - View Layout Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool View_LayOut()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_LayOut_In");
                TRSNode out_node = new TRSNode("View_LayOut_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = '1';
                in_node.AddString("LAYOUT_ID", lisLayOutList.SelectedItems[0].Text);

                if (MPCR.CallService("FMB", "FMB_View_LayOut", in_node, ref out_node) == false)
                {
                    return false;
                }
                txtLayOutID.Text = MPCF.RTrim(out_node.GetString("LAYOUT_ID"));
                txtDesc.Text = MPCF.RTrim(out_node.GetString("LAYOUT_DESC"));
                txtCreateUser.Text = MPCF.RTrim(out_node.GetString("CREATE_USER_ID"));
                txtCreateTime.Text = MPCF.MakeDateFormat(out_node.GetString("CREATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtUpdateUser.Text = MPCF.RTrim(out_node.GetString("UPDATE_USER_ID"));
                txtUpdateTime.Text = MPCF.MakeDateFormat(out_node.GetString("UPDATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtWidth.Text = System.Convert.ToString(out_node.GetInt("WIDTH"));
                txtHeight.Text = System.Convert.ToString(out_node.GetInt("HEIGHT"));
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.View_LayOut()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Update_LayOut()
        //       - Create/Update/Delete Layout
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep   : Process Step
        //
        private bool Update_LayOut(char sStep)
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Update_LayOut_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = sStep;
                in_node.AddString("LAYOUT_ID", txtLayOutID.Text);
                in_node.AddString("LAYOUT_DESC", txtDesc.Text);

                in_node.AddInt("WIDTH", MPCF.ToInt(txtWidth.Text));
                in_node.AddInt("HEIGHT", MPCF.ToInt(txtHeight.Text));

                if (MPCR.CallService("FMB", "FMB_Update_LayOut", in_node, ref out_node) == false)
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.Update_LayOut()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Exist_Control_LayOut()
        //       - Check Exist Control Out of the LayOut
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        public bool Exist_Control_LayOut()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Exist_Control_In");
                TRSNode out_node = new TRSNode("Exist_Control_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = cdvFactory.Text;
                in_node.AddChar("LAYOUT_GROUP_FLAG", 'L');
                in_node.AddString("LAYOUT_ID", txtLayOutID.Text);
                in_node.AddInt("WIDTH", MPCF.ToInt(txtWidth.Text));
                in_node.AddInt("HEIGHT", MPCF.ToInt(txtHeight.Text));

                if (MPCR.CallService("FMB", "FMB_Exist_Control", in_node, ref out_node) == false)
                {
                    return false;
                }
                
                if (out_node.GetChar("EXIST_FLAG") == 'Y')
                {
                    sExistFlag = "Y";
                }
                else
                {
                    sExistFlag = "";
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.Exist_Control_LayOut()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Move_Controls_LayOut()
        //       - Move Controls by Force
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        public bool Move_Controls_LayOut()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Moving_by_Force_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = cdvFactory.Text;
                in_node.AddChar("LAYOUT_GROUP_FLAG", 'L');
                in_node.AddString("LAYOUT_ID", txtLayOutID.Text);
                in_node.AddInt("WIDTH", MPCF.ToInt(txtWidth.Text));
                in_node.AddInt("HEIGHT", MPCF.ToInt(txtHeight.Text));

                if (MPCR.CallService("FMB", "FMB_Moving_by_Force", in_node, ref out_node) == false)
                {
                    return false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.Move_Controls_LayOut()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        #endregion
        
        #region " Event Implementations"
        
        private void frmFMBCreateLayOut_Activated(object sender, System.EventArgs e)
        {
            
            try
            {
                if (b_load_flag == false)
                {
                    if (cdvFactory.Text == "")
                    {
                        cdvFactory.Text = MPGV.gsFactory;
                    }
                    lisLayOutList.Focus();
                    if (modListRoutine.ViewLayOutList(lisLayOutList, '1', cdvFactory.Text) == true)
                    {
                        if (lisLayOutList.Items.Count > 0)
                        {
                            if (sSelectedLayout == "")
                            {
                                lisLayOutList.Items[0].Selected = true;
                            }
                            else
                            {
                                MPCF.FindListItem(lisLayOutList, sSelectedLayout, false);
                            }
                        }
                    }
                    else
                    {
                        return;
                    }
                    b_load_flag = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.frmFMBCreateLayOut_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBCreateLayOut_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                MPCF.InitListView(lisLayOutList);
                
                FMBCF.CheckAllFactoryOption(cdvFactory);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.frmFMBCreateLayOut_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void lisLayOutList_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(grpLayOut, cdvFactory, null, null, null, null, false);
                if (lisLayOutList.SelectedItems.Count > 0)
                {
                    txtLayOutID.Text = lisLayOutList.SelectedItems[0].Text;
                    View_LayOut();
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.lisLayOutList_SelectedIndexChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnCreate_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("CREATE") == true)
                {
                    if (Update_LayOut(modGlobalConstant.MP_STEP_CREATE) == false)
                    {
                        return;
                    }
                    if (FMBFI.gIMdiForm.RefreshDesignList("6", cdvFactory.Text, txtLayOutID.Text, "", "") == false)
                    {
                        return;
                    }
                    if (modListRoutine.ViewLayOutList(lisLayOutList, '1', cdvFactory.Text) == false)
                    {
                        return;
                    }
                    if (lisLayOutList.Items.Count > 0)
                    {
                        MPCF.FindListItem(lisLayOutList, MPCF.RTrim(txtLayOutID.Text), false);
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.btnCreate_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnUpdate_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                System.Windows.Forms.Form frmChild;
                string sDeletedFormName = "";
                DialogResult result;
                if (CheckCondition("CREATE") == true)
                {
                    //蹂寃쏀븯?ㅻ뒗 LayOut??Width? Height 諛뽰쑝濡?而⑦듃濡ㅼ씠 議댁옱?섎㈃ 媛뺤젣濡??대룞 ?쒗궗寃껋씤吏 臾쇱뼱蹂몃떎.
                    if (Exist_Control_LayOut() == false)
                    {
                        return;
                    }
                    if (sExistFlag == "Y")
                    {
                        result = MPCF.ShowMsgBox(MPCF.GetMessage(37), Application.ProductName, MessageBoxButtons.YesNoCancel, 1);
                        //媛뺤젣 ?대룞
                        if (result == DialogResult.Yes)
                        {
                            if (Move_Controls_LayOut() == false)
                            {
                                return;
                            }
                            if (Update_LayOut(modGlobalConstant.MP_STEP_UPDATE) == false)
                            {
                                return;
                            }
                            sDeletedFormName = cdvFactory.Text + ":" + txtLayOutID.Text;
                            foreach (System.Windows.Forms.Form tempLoopVar_frmChild in MPGV.gfrmMDI.MdiChildren)
                            {
                                frmChild = tempLoopVar_frmChild;
                                if (frmChild.Name == sDeletedFormName)
                                {
                                    ((frmFMBDesign) frmChild).OriginalDesignSize = new Size(MPCF.ToInt(txtWidth.Text) + 20, MPCF.ToInt(txtHeight.Text) + 20);
                                    double dScale = FMBCF.GetScale(((frmFMBDesign) frmChild).ZoomScale);
                                    ((frmFMBDesign) frmChild).DesignSize = new Size(MPCF.ToInt(((frmFMBDesign) frmChild).OriginalDesignSize.Width * dScale), MPCF.ToInt(((frmFMBDesign) frmChild).OriginalDesignSize.Height * dScale));
                                    if (((frmFMBDesign) frmChild).RefreshResourceListDetail() == false)
                                    {
                                        return;
                                    }
                                    goto endOfForLoop;
                                }
                            }
endOfForLoop:

                            if (modListRoutine.ViewLayOutList(lisLayOutList, '1', cdvFactory.Text) == false)
                            {
                                return;
                            }
                            if (lisLayOutList.Items.Count > 0)
                            {
                                MPCF.FindListItem(lisLayOutList, MPCF.RTrim(txtLayOutID.Text), false);
                            }
                            //媛뺤젣濡??대룞?쒗궎吏 ?딄퀬 ?낅젰??媛믪쑝濡?Update
                        }
                        else if (result == DialogResult.No)
                        {
                            if (Update_LayOut(modGlobalConstant.MP_STEP_UPDATE) == false)
                            {
                                return;
                            }
                            sDeletedFormName = cdvFactory.Text + ":" + txtLayOutID.Text;
                            foreach (System.Windows.Forms.Form tempLoopVar_frmChild in MPGV.gfrmMDI.MdiChildren)
                            {
                                frmChild = tempLoopVar_frmChild;
                                if (frmChild.Name == sDeletedFormName)
                                {
                                    ((frmFMBDesign) frmChild).OriginalDesignSize = new Size(MPCF.ToInt(txtWidth.Text) + 20, MPCF.ToInt(txtHeight.Text) + 20);
                                    double dScale = FMBCF.GetScale(((frmFMBDesign) frmChild).ZoomScale);
                                    ((frmFMBDesign) frmChild).DesignSize = new Size(MPCF.ToInt(((frmFMBDesign) frmChild).OriginalDesignSize.Width * dScale), MPCF.ToInt(((frmFMBDesign) frmChild).OriginalDesignSize.Height * dScale));
                                    goto endOfForLoop1;
                                }
                            }
endOfForLoop1:
                            
                            if (modListRoutine.ViewLayOutList(lisLayOutList, '1', cdvFactory.Text) == false)
                            {
                                return;
                            }
                            if (lisLayOutList.Items.Count > 0)
                            {
                                MPCF.FindListItem(lisLayOutList, MPCF.RTrim(txtLayOutID.Text), false);
                            }
                            //Update Cancle -> Do Nothihg
                        }
                        else if (result == DialogResult.Cancel)
                        {
                            View_LayOut();
                            return;
                        }
                        
                        //蹂寃쏀븯?ㅻ뒗 LayOut??Width? Height 諛뽰쑝濡?而⑦듃濡ㅼ씠 議댁옱?섏? ?딆쑝硫?洹몃깷 Update
                    }
                    else
                    {
                        if (Update_LayOut(modGlobalConstant.MP_STEP_UPDATE) == false)
                        {
                            return;
                        }
                        sDeletedFormName = cdvFactory.Text + ":" + txtLayOutID.Text;
                        foreach (System.Windows.Forms.Form tempLoopVar_frmChild in MPGV.gfrmMDI.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (frmChild.Name == sDeletedFormName)
                            {
                                ((frmFMBDesign) frmChild).OriginalDesignSize = new Size(MPCF.ToInt(txtWidth.Text) + 20, MPCF.ToInt(txtHeight.Text) + 20);
                                double dScale = FMBCF.GetScale(((frmFMBDesign) frmChild).ZoomScale);
                                ((frmFMBDesign) frmChild).DesignSize = new Size(MPCF.ToInt(((frmFMBDesign) frmChild).OriginalDesignSize.Width * dScale), MPCF.ToInt(((frmFMBDesign) frmChild).OriginalDesignSize.Height * dScale));
                                goto endOfForLoop2;
                            }
                        }
endOfForLoop2:
                                            
                        if (modListRoutine.ViewLayOutList(lisLayOutList, '1', cdvFactory.Text) == false)
                        {
                            return;
                        }
                        if (lisLayOutList.Items.Count > 0)
                        {
                            MPCF.FindListItem(lisLayOutList, MPCF.RTrim(txtLayOutID.Text), false);
                        }
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.btnUpdate_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnDelete_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                System.Windows.Forms.Form frmChild;
                string sDeletedFormName = "";
                
                if (CheckCondition("DELETE") == true)
                {
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(5), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.No)
                    {
                        return;
                    }
                    if (Update_LayOut(modGlobalConstant.MP_STEP_DELETE) == true)
                    {
                        if (FMBFI.gIMdiForm.RefreshDesignList("1", cdvFactory.Text, txtLayOutID.Text, "", "") == false)
                        {
                            return;
                        }
                        sDeletedFormName = cdvFactory.Text + ":" + txtLayOutID.Text;
                        foreach (System.Windows.Forms.Form tempLoopVar_frmChild in MPGV.gfrmMDI.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (frmChild is frmFMBDesign)
                            {
                                if (frmChild.Name == sDeletedFormName)
                                {
                                    ((frmFMBDesign) frmChild).DeleteFlag = true;
                                    frmChild.Close();
                                    goto endOfForLoop;
                                }
                            }
                        }
endOfForLoop:
                        if (modListRoutine.ViewLayOutList(lisLayOutList, '1', cdvFactory.Text) == true)
                        {
                            if (lisLayOutList.Items.Count > 0)
                            {
                                lisLayOutList.Items[0].Selected = true;
                            }
                        }
                        else
                        {
                            return;
                        }
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.btnDelete_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateLayOut.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnCreate_GotFocus(object sender, System.EventArgs e)
        {
            
            try
            {
                if (MPCF.ToInt(txtWidth.Text) == 0)
                {
                    txtWidth.Text = System.Convert.ToString(((Size) modGlobalVariable.gGlobalOptions.GetOptions(MPCF.RTrim(cdvFactory.Text), clsOptionData.Options.DefaultLayoutSize)).Width);
                }
                if (MPCF.ToInt(txtHeight.Text) == 0)
                {
                    txtHeight.Text = System.Convert.ToString(((Size)modGlobalVariable.gGlobalOptions.GetOptions(MPCF.RTrim(cdvFactory.Text), clsOptionData.Options.DefaultLayoutSize)).Height);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.btnCreate_GotFocus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnUpdate_GotFocus(object sender, System.EventArgs e)
        {
            
            try
            {
                if (MPCF.ToInt(txtWidth.Text) == 0)
                {
                    txtWidth.Text = System.Convert.ToString(((Size) modGlobalVariable.gGlobalOptions.GetOptions(MPCF.RTrim(cdvFactory.Text), clsOptionData.Options.DefaultLayoutSize)).Width);
                }
                if (MPCF.ToInt(txtHeight.Text) == 0)
                {
                    txtHeight.Text = System.Convert.ToString(((Size)modGlobalVariable.gGlobalOptions.GetOptions(MPCF.RTrim(cdvFactory.Text), clsOptionData.Options.DefaultLayoutSize)).Height);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.btnUpdate_GotFocus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_ButtonPress(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                cdvFactory.Init();
                cdvFactory.Columns.Add("LayoutID", 100, HorizontalAlignment.Left);
                cdvFactory.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFactory.SelectedSubItemIndex = 0;
                cdvFactory.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1',null);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_SelectedItemChanged(System.Object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(this, cdvFactory, null, null, null, null, false);
                if (modListRoutine.ViewLayOutList(lisLayOutList, '1', cdvFactory.Text) == true)
                {
                    if (lisLayOutList.Items.Count > 0)
                    {
                        lisLayOutList.Items[0].Selected = true;
                    }
                }
                else
                {
                    return;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.cdvFactory_SelectedItemChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBCreateLayOut_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (!(this.ActiveControl == null))
                {
                    if (this.ActiveControl is TextBox || this.ActiveControl is UltraTextEditor || this.ActiveControl is Miracom.UI.Controls.MCCodeView.MCCodeView)
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
                MPCF.ShowMsgBox("frmFMBCreateLayOut.frmFMBCreateLayOut_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void txtHeight_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
                {
                    if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
                    {
                        e.Handled = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.txtHeight_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void txtWidth_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (e.KeyChar != (char)13 && e.KeyChar != (char)8)
                {
                    if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
                    {
                        e.Handled = true;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateLayOut.txtWidth_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
