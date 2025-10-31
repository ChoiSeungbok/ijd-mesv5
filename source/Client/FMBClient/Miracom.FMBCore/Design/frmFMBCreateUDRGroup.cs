
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Infragistics.Win.UltraWinEditors;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBCreateUDRGroup.vb
//   Description : Create/Update/Delete UDR Group
//
//   FMB Version : 1.0.0
//
//   Function List
//       - CheckCondition() : Check the conditions before transaction
//       - View_UDR_Group() : View User Define Resource Group Information
//       - Update_UDR_Group() : Create/Update/Delete User Define Resource Group
//       - Exist_Control_UDR_Group() : Check Exist Control Out of the User Define Group
//       - Move_Controls_UDR_Group() : Move Controls by Force
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-11 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public class frmFMBCreateUDRGroup : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBCreateUDRGroup()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
        }
        
        public frmFMBCreateUDRGroup(string sUserGroup)
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            
            sSelectedUserGroup = sUserGroup;
            
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
        internal System.Windows.Forms.ColumnHeader ColumnHeader2;
        internal System.Windows.Forms.ColumnHeader ColumnHeader1;
        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Button btnDelete;
        internal System.Windows.Forms.Button btnUpdate;
        internal System.Windows.Forms.Button btnCreate;
        internal System.Windows.Forms.Panel pnlList;
        internal Miracom.UI.Controls.MCListView.MCListView lisGroupList;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.ColumnHeader ColumnHeader3;
        internal System.Windows.Forms.ColumnHeader ColumnHeader4;
        internal System.Windows.Forms.TabPage tbpGeneral;
        internal System.Windows.Forms.TabPage tbpCopy;
        internal System.Windows.Forms.GroupBox grpGroup;
        internal System.Windows.Forms.Label lblHeight;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtHeight;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtWidth;
        internal System.Windows.Forms.Label lblWidth;
        internal System.Windows.Forms.Label lblUpdateTime;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtUpdateTime;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtCreateTime;
        internal System.Windows.Forms.Label lblCreateTime;
        internal System.Windows.Forms.Label lblDesc;
        internal System.Windows.Forms.Label lblGroupID;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtDesc;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtGroupID;
        internal System.Windows.Forms.GroupBox grpCopy;
        internal System.Windows.Forms.Label lblToGroup;
        internal Infragistics.Win.UltraWinEditors.UltraTextEditor txtToGroup;
        internal System.Windows.Forms.Button btnCopy;
        internal System.Windows.Forms.TabControl tabUDR;
        internal System.Windows.Forms.Splitter spdMid;
        internal System.Windows.Forms.TabPage tbpUser;
        internal System.Windows.Forms.Panel pnlUserMid;
        internal System.Windows.Forms.Panel pnlUserMidRight;
        internal Miracom.UI.Controls.MCListView.MCListView lisUserlist;
        internal System.Windows.Forms.Panel pnlGroup;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvGroup;
        internal System.Windows.Forms.Label lblGroup;
        internal System.Windows.Forms.Label lblUserList;
        internal System.Windows.Forms.Panel pnlUserMidLeft;
        internal Miracom.UI.Controls.MCListView.MCListView lisAttachUser;
        internal System.Windows.Forms.Label lblAttachUser;
        internal System.Windows.Forms.ColumnHeader ColumnHeader11;
        internal System.Windows.Forms.ColumnHeader ColumnHeader12;
        internal System.Windows.Forms.ColumnHeader ColumnHeader7;
        internal System.Windows.Forms.ColumnHeader ColumnHeader8;
        internal System.Windows.Forms.Panel pnlUserAttach;
        internal System.Windows.Forms.Button btnDel;
        internal System.Windows.Forms.Button btnAdd;
        [System.Diagnostics.DebuggerStepThrough()]
        private void InitializeComponent()
        {
            this.ColumnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnCreate = new System.Windows.Forms.Button();
            this.pnlList = new System.Windows.Forms.Panel();
            this.lisGroupList = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader4 = new System.Windows.Forms.ColumnHeader();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.tabUDR = new System.Windows.Forms.TabControl();
            this.tbpGeneral = new System.Windows.Forms.TabPage();
            this.grpGroup = new System.Windows.Forms.GroupBox();
            this.lblHeight = new System.Windows.Forms.Label();
            this.txtHeight = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtWidth = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblWidth = new System.Windows.Forms.Label();
            this.lblUpdateTime = new System.Windows.Forms.Label();
            this.txtUpdateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtCreateTime = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.lblCreateTime = new System.Windows.Forms.Label();
            this.lblDesc = new System.Windows.Forms.Label();
            this.lblGroupID = new System.Windows.Forms.Label();
            this.txtDesc = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.txtGroupID = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.tbpCopy = new System.Windows.Forms.TabPage();
            this.grpCopy = new System.Windows.Forms.GroupBox();
            this.btnCopy = new System.Windows.Forms.Button();
            this.lblToGroup = new System.Windows.Forms.Label();
            this.txtToGroup = new Infragistics.Win.UltraWinEditors.UltraTextEditor();
            this.tbpUser = new System.Windows.Forms.TabPage();
            this.pnlUserMid = new System.Windows.Forms.Panel();
            this.pnlUserAttach = new System.Windows.Forms.Panel();
            this.btnDel = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.pnlUserMidRight = new System.Windows.Forms.Panel();
            this.lisUserlist = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader11 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader12 = new System.Windows.Forms.ColumnHeader();
            this.pnlGroup = new System.Windows.Forms.Panel();
            this.cdvGroup = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblGroup = new System.Windows.Forms.Label();
            this.lblUserList = new System.Windows.Forms.Label();
            this.pnlUserMidLeft = new System.Windows.Forms.Panel();
            this.lisAttachUser = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader7 = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader8 = new System.Windows.Forms.ColumnHeader();
            this.lblAttachUser = new System.Windows.Forms.Label();
            this.spdMid = new System.Windows.Forms.Splitter();
            this.pnlBottom.SuspendLayout();
            this.pnlList.SuspendLayout();
            this.pnlMid.SuspendLayout();
            this.tabUDR.SuspendLayout();
            this.tbpGeneral.SuspendLayout();
            this.grpGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGroupID)).BeginInit();
            this.tbpCopy.SuspendLayout();
            this.grpCopy.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtToGroup)).BeginInit();
            this.tbpUser.SuspendLayout();
            this.pnlUserMid.SuspendLayout();
            this.pnlUserAttach.SuspendLayout();
            this.pnlUserMidRight.SuspendLayout();
            this.pnlGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvGroup)).BeginInit();
            this.pnlUserMidLeft.SuspendLayout();
            this.SuspendLayout();
            // 
            // ColumnHeader2
            // 
            this.ColumnHeader2.Text = "Description";
            this.ColumnHeader2.Width = 120;
            // 
            // ColumnHeader1
            // 
            this.ColumnHeader1.Text = "Group ID";
            this.ColumnHeader1.Width = 100;
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Controls.Add(this.btnDelete);
            this.pnlBottom.Controls.Add(this.btnUpdate);
            this.pnlBottom.Controls.Add(this.btnCreate);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 408);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(682, 40);
            this.pnlBottom.TabIndex = 2;
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Location = new System.Drawing.Point(600, 11);
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
            this.btnDelete.Location = new System.Drawing.Point(520, 11);
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
            this.btnUpdate.Location = new System.Drawing.Point(440, 11);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(74, 23);
            this.btnUpdate.TabIndex = 1;
            this.btnUpdate.Text = "Update";
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnCreate
            // 
            this.btnCreate.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCreate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnCreate.Location = new System.Drawing.Point(360, 11);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(74, 23);
            this.btnCreate.TabIndex = 0;
            this.btnCreate.Text = "Create";
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // pnlList
            // 
            this.pnlList.Controls.Add(this.lisGroupList);
            this.pnlList.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlList.Location = new System.Drawing.Point(0, 0);
            this.pnlList.Name = "pnlList";
            this.pnlList.Padding = new System.Windows.Forms.Padding(3, 3, 3, 0);
            this.pnlList.Size = new System.Drawing.Size(216, 408);
            this.pnlList.TabIndex = 0;
            // 
            // lisGroupList
            // 
            this.lisGroupList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader1,
            this.ColumnHeader2,
            this.ColumnHeader3,
            this.ColumnHeader4});
            this.lisGroupList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisGroupList.EnableSort = true;
            this.lisGroupList.EnableSortIcon = true;
            this.lisGroupList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisGroupList.FullRowSelect = true;
            this.lisGroupList.Location = new System.Drawing.Point(3, 3);
            this.lisGroupList.MultiSelect = false;
            this.lisGroupList.Name = "lisGroupList";
            this.lisGroupList.Size = new System.Drawing.Size(210, 405);
            this.lisGroupList.TabIndex = 0;
            this.lisGroupList.UseCompatibleStateImageBehavior = false;
            this.lisGroupList.View = System.Windows.Forms.View.Details;
            this.lisGroupList.SelectedIndexChanged += new System.EventHandler(this.lisGroupList_SelectedIndexChanged);
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
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.tabUDR);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(216, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 3, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(466, 408);
            this.pnlMid.TabIndex = 1;
            // 
            // tabUDR
            // 
            this.tabUDR.Controls.Add(this.tbpGeneral);
            this.tabUDR.Controls.Add(this.tbpCopy);
            this.tabUDR.Controls.Add(this.tbpUser);
            this.tabUDR.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabUDR.Location = new System.Drawing.Point(3, 3);
            this.tabUDR.Name = "tabUDR";
            this.tabUDR.SelectedIndex = 0;
            this.tabUDR.Size = new System.Drawing.Size(460, 405);
            this.tabUDR.TabIndex = 0;
            // 
            // tbpGeneral
            // 
            this.tbpGeneral.Controls.Add(this.grpGroup);
            this.tbpGeneral.Location = new System.Drawing.Point(4, 22);
            this.tbpGeneral.Name = "tbpGeneral";
            this.tbpGeneral.Size = new System.Drawing.Size(452, 379);
            this.tbpGeneral.TabIndex = 0;
            this.tbpGeneral.Text = "General";
            // 
            // grpGroup
            // 
            this.grpGroup.Controls.Add(this.lblHeight);
            this.grpGroup.Controls.Add(this.txtHeight);
            this.grpGroup.Controls.Add(this.txtWidth);
            this.grpGroup.Controls.Add(this.lblWidth);
            this.grpGroup.Controls.Add(this.lblUpdateTime);
            this.grpGroup.Controls.Add(this.txtUpdateTime);
            this.grpGroup.Controls.Add(this.txtCreateTime);
            this.grpGroup.Controls.Add(this.lblCreateTime);
            this.grpGroup.Controls.Add(this.lblDesc);
            this.grpGroup.Controls.Add(this.lblGroupID);
            this.grpGroup.Controls.Add(this.txtDesc);
            this.grpGroup.Controls.Add(this.txtGroupID);
            this.grpGroup.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpGroup.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpGroup.Location = new System.Drawing.Point(0, 0);
            this.grpGroup.Name = "grpGroup";
            this.grpGroup.Size = new System.Drawing.Size(452, 379);
            this.grpGroup.TabIndex = 1;
            this.grpGroup.TabStop = false;
            // 
            // lblHeight
            // 
            this.lblHeight.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblHeight.Location = new System.Drawing.Point(231, 69);
            this.lblHeight.Name = "lblHeight";
            this.lblHeight.Size = new System.Drawing.Size(88, 14);
            this.lblHeight.TabIndex = 81;
            this.lblHeight.Text = "Height";
            // 
            // txtHeight
            // 
            this.txtHeight.Location = new System.Drawing.Point(323, 65);
            this.txtHeight.MaxLength = 5;
            this.txtHeight.Name = "txtHeight";
            this.txtHeight.Size = new System.Drawing.Size(120, 19);
            this.txtHeight.TabIndex = 3;
            this.txtHeight.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtWidth
            // 
            this.txtWidth.Location = new System.Drawing.Point(103, 65);
            this.txtWidth.MaxLength = 5;
            this.txtWidth.Name = "txtWidth";
            this.txtWidth.Size = new System.Drawing.Size(120, 19);
            this.txtWidth.TabIndex = 2;
            this.txtWidth.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblWidth
            // 
            this.lblWidth.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblWidth.Location = new System.Drawing.Point(9, 69);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(88, 14);
            this.lblWidth.TabIndex = 78;
            this.lblWidth.Text = "Width";
            // 
            // lblUpdateTime
            // 
            this.lblUpdateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUpdateTime.Location = new System.Drawing.Point(231, 93);
            this.lblUpdateTime.Name = "lblUpdateTime";
            this.lblUpdateTime.Size = new System.Drawing.Size(88, 14);
            this.lblUpdateTime.TabIndex = 69;
            this.lblUpdateTime.Text = "Update Time";
            // 
            // txtUpdateTime
            // 
            this.txtUpdateTime.Location = new System.Drawing.Point(323, 89);
            this.txtUpdateTime.MaxLength = 20;
            this.txtUpdateTime.Name = "txtUpdateTime";
            this.txtUpdateTime.ReadOnly = true;
            this.txtUpdateTime.Size = new System.Drawing.Size(120, 19);
            this.txtUpdateTime.TabIndex = 5;
            this.txtUpdateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtCreateTime
            // 
            this.txtCreateTime.Location = new System.Drawing.Point(103, 89);
            this.txtCreateTime.MaxLength = 20;
            this.txtCreateTime.Name = "txtCreateTime";
            this.txtCreateTime.ReadOnly = true;
            this.txtCreateTime.Size = new System.Drawing.Size(120, 19);
            this.txtCreateTime.TabIndex = 4;
            this.txtCreateTime.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // lblCreateTime
            // 
            this.lblCreateTime.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCreateTime.Location = new System.Drawing.Point(8, 93);
            this.lblCreateTime.Name = "lblCreateTime";
            this.lblCreateTime.Size = new System.Drawing.Size(88, 14);
            this.lblCreateTime.TabIndex = 66;
            this.lblCreateTime.Text = "Create Time";
            // 
            // lblDesc
            // 
            this.lblDesc.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblDesc.Location = new System.Drawing.Point(9, 44);
            this.lblDesc.Name = "lblDesc";
            this.lblDesc.Size = new System.Drawing.Size(88, 14);
            this.lblDesc.TabIndex = 5;
            this.lblDesc.Text = "Description";
            // 
            // lblGroupID
            // 
            this.lblGroupID.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGroupID.Location = new System.Drawing.Point(9, 20);
            this.lblGroupID.Name = "lblGroupID";
            this.lblGroupID.Size = new System.Drawing.Size(88, 14);
            this.lblGroupID.TabIndex = 4;
            this.lblGroupID.Text = "Group ID";
            // 
            // txtDesc
            // 
            this.txtDesc.Location = new System.Drawing.Point(103, 41);
            this.txtDesc.MaxLength = 50;
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.Size = new System.Drawing.Size(341, 19);
            this.txtDesc.TabIndex = 1;
            this.txtDesc.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // txtGroupID
            // 
            this.txtGroupID.Location = new System.Drawing.Point(103, 17);
            this.txtGroupID.MaxLength = 20;
            this.txtGroupID.Name = "txtGroupID";
            this.txtGroupID.Size = new System.Drawing.Size(136, 19);
            this.txtGroupID.TabIndex = 0;
            this.txtGroupID.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // tbpCopy
            // 
            this.tbpCopy.Controls.Add(this.grpCopy);
            this.tbpCopy.Location = new System.Drawing.Point(4, 22);
            this.tbpCopy.Name = "tbpCopy";
            this.tbpCopy.Size = new System.Drawing.Size(452, 379);
            this.tbpCopy.TabIndex = 1;
            this.tbpCopy.Text = "Copy Group";
            // 
            // grpCopy
            // 
            this.grpCopy.Controls.Add(this.btnCopy);
            this.grpCopy.Controls.Add(this.lblToGroup);
            this.grpCopy.Controls.Add(this.txtToGroup);
            this.grpCopy.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpCopy.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpCopy.Location = new System.Drawing.Point(0, 0);
            this.grpCopy.Name = "grpCopy";
            this.grpCopy.Size = new System.Drawing.Size(452, 379);
            this.grpCopy.TabIndex = 2;
            this.grpCopy.TabStop = false;
            // 
            // btnCopy
            // 
            this.btnCopy.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnCopy.Location = new System.Drawing.Point(252, 15);
            this.btnCopy.Name = "btnCopy";
            this.btnCopy.Size = new System.Drawing.Size(74, 23);
            this.btnCopy.TabIndex = 5;
            this.btnCopy.Text = "Copy";
            this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
            // 
            // lblToGroup
            // 
            this.lblToGroup.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblToGroup.Location = new System.Drawing.Point(9, 20);
            this.lblToGroup.Name = "lblToGroup";
            this.lblToGroup.Size = new System.Drawing.Size(88, 14);
            this.lblToGroup.TabIndex = 4;
            this.lblToGroup.Text = "To Group ID";
            // 
            // txtToGroup
            // 
            this.txtToGroup.Location = new System.Drawing.Point(103, 17);
            this.txtToGroup.MaxLength = 20;
            this.txtToGroup.Name = "txtToGroup";
            this.txtToGroup.Size = new System.Drawing.Size(136, 19);
            this.txtToGroup.TabIndex = 0;
            this.txtToGroup.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            // 
            // tbpUser
            // 
            this.tbpUser.Controls.Add(this.pnlUserMid);
            this.tbpUser.Location = new System.Drawing.Point(4, 22);
            this.tbpUser.Name = "tbpUser";
            this.tbpUser.Size = new System.Drawing.Size(452, 379);
            this.tbpUser.TabIndex = 2;
            this.tbpUser.Text = "User Setup";
            // 
            // pnlUserMid
            // 
            this.pnlUserMid.Controls.Add(this.pnlUserAttach);
            this.pnlUserMid.Controls.Add(this.pnlUserMidRight);
            this.pnlUserMid.Controls.Add(this.pnlUserMidLeft);
            this.pnlUserMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlUserMid.Location = new System.Drawing.Point(0, 0);
            this.pnlUserMid.Name = "pnlUserMid";
            this.pnlUserMid.Padding = new System.Windows.Forms.Padding(0, 0, 0, 3);
            this.pnlUserMid.Size = new System.Drawing.Size(452, 379);
            this.pnlUserMid.TabIndex = 1;
            this.pnlUserMid.Resize += new System.EventHandler(this.pnlRight_Resize);
            // 
            // pnlUserAttach
            // 
            this.pnlUserAttach.Controls.Add(this.btnDel);
            this.pnlUserAttach.Controls.Add(this.btnAdd);
            this.pnlUserAttach.Location = new System.Drawing.Point(200, 112);
            this.pnlUserAttach.Name = "pnlUserAttach";
            this.pnlUserAttach.Size = new System.Drawing.Size(43, 120);
            this.pnlUserAttach.TabIndex = 20;
            // 
            // btnDel
            // 
            this.btnDel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnDel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnDel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDel.Location = new System.Drawing.Point(9, 63);
            this.btnDel.Name = "btnDel";
            this.btnDel.Size = new System.Drawing.Size(24, 24);
            this.btnDel.TabIndex = 1;
            this.btnDel.Text = ">";
            this.btnDel.Click += new System.EventHandler(this.btnDel_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnAdd.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAdd.Location = new System.Drawing.Point(9, 34);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(24, 24);
            this.btnAdd.TabIndex = 0;
            this.btnAdd.Text = "<";
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // pnlUserMidRight
            // 
            this.pnlUserMidRight.Controls.Add(this.lisUserlist);
            this.pnlUserMidRight.Controls.Add(this.pnlGroup);
            this.pnlUserMidRight.Controls.Add(this.lblUserList);
            this.pnlUserMidRight.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlUserMidRight.Location = new System.Drawing.Point(252, 0);
            this.pnlUserMidRight.Name = "pnlUserMidRight";
            this.pnlUserMidRight.Size = new System.Drawing.Size(200, 376);
            this.pnlUserMidRight.TabIndex = 19;
            // 
            // lisUserlist
            // 
            this.lisUserlist.AllowDrop = true;
            this.lisUserlist.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader11,
            this.ColumnHeader12});
            this.lisUserlist.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisUserlist.EnableSort = true;
            this.lisUserlist.EnableSortIcon = true;
            this.lisUserlist.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisUserlist.FullRowSelect = true;
            this.lisUserlist.Location = new System.Drawing.Point(0, 48);
            this.lisUserlist.Name = "lisUserlist";
            this.lisUserlist.Size = new System.Drawing.Size(200, 328);
            this.lisUserlist.TabIndex = 2;
            this.lisUserlist.TabStop = false;
            this.lisUserlist.UseCompatibleStateImageBehavior = false;
            this.lisUserlist.View = System.Windows.Forms.View.Details;
            // 
            // ColumnHeader11
            // 
            this.ColumnHeader11.Text = "User ID";
            this.ColumnHeader11.Width = 80;
            // 
            // ColumnHeader12
            // 
            this.ColumnHeader12.Text = "Description";
            this.ColumnHeader12.Width = 150;
            // 
            // pnlGroup
            // 
            this.pnlGroup.Controls.Add(this.cdvGroup);
            this.pnlGroup.Controls.Add(this.lblGroup);
            this.pnlGroup.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlGroup.Location = new System.Drawing.Point(0, 14);
            this.pnlGroup.Name = "pnlGroup";
            this.pnlGroup.Size = new System.Drawing.Size(200, 34);
            this.pnlGroup.TabIndex = 1;
            // 
            // cdvGroup
            // 
            this.cdvGroup.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.cdvGroup.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvGroup.BorderHotColor = System.Drawing.Color.Black;
            this.cdvGroup.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvGroup.BtnToolTipText = "";
            this.cdvGroup.DescText = "";
            this.cdvGroup.DisplaySubItemIndex = -1;
            this.cdvGroup.DisplayText = "";
            this.cdvGroup.Focusing = null;
            this.cdvGroup.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvGroup.Index = 0;
            this.cdvGroup.IsViewBtnImage = false;
            this.cdvGroup.Location = new System.Drawing.Point(93, 7);
            this.cdvGroup.MaxLength = 20;
            this.cdvGroup.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvGroup.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvGroup.Name = "cdvGroup";
            this.cdvGroup.ReadOnly = true;
            this.cdvGroup.SearchSubItemIndex = 0;
            this.cdvGroup.SelectedDescIndex = -1;
            this.cdvGroup.SelectedSubItemIndex = -1;
            this.cdvGroup.SelectionStart = 0;
            this.cdvGroup.Size = new System.Drawing.Size(99, 20);
            this.cdvGroup.SmallImageList = null;
            this.cdvGroup.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvGroup.TabIndex = 1;
            this.cdvGroup.TextBoxToolTipText = "";
            this.cdvGroup.TextBoxWidth = 99;
            this.cdvGroup.VisibleButton = true;
            this.cdvGroup.VisibleColumnHeader = false;
            this.cdvGroup.VisibleDescription = false;
            this.cdvGroup.ButtonPress += new System.EventHandler(this.cdvGroup_ButtonPress);
            this.cdvGroup.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvGroup_SelectedItemChanged);
            // 
            // lblGroup
            // 
            this.lblGroup.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGroup.Location = new System.Drawing.Point(4, 10);
            this.lblGroup.Name = "lblGroup";
            this.lblGroup.Size = new System.Drawing.Size(82, 14);
            this.lblGroup.TabIndex = 0;
            this.lblGroup.Text = "Security Group";
            // 
            // lblUserList
            // 
            this.lblUserList.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblUserList.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUserList.Location = new System.Drawing.Point(0, 0);
            this.lblUserList.Name = "lblUserList";
            this.lblUserList.Size = new System.Drawing.Size(200, 14);
            this.lblUserList.TabIndex = 0;
            this.lblUserList.Text = " All User List";
            // 
            // pnlUserMidLeft
            // 
            this.pnlUserMidLeft.Controls.Add(this.lisAttachUser);
            this.pnlUserMidLeft.Controls.Add(this.lblAttachUser);
            this.pnlUserMidLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlUserMidLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlUserMidLeft.Name = "pnlUserMidLeft";
            this.pnlUserMidLeft.Size = new System.Drawing.Size(192, 376);
            this.pnlUserMidLeft.TabIndex = 16;
            // 
            // lisAttachUser
            // 
            this.lisAttachUser.AllowDrop = true;
            this.lisAttachUser.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader7,
            this.ColumnHeader8});
            this.lisAttachUser.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisAttachUser.EnableSort = true;
            this.lisAttachUser.EnableSortIcon = true;
            this.lisAttachUser.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisAttachUser.FullRowSelect = true;
            this.lisAttachUser.Location = new System.Drawing.Point(0, 14);
            this.lisAttachUser.Name = "lisAttachUser";
            this.lisAttachUser.Size = new System.Drawing.Size(192, 362);
            this.lisAttachUser.TabIndex = 1;
            this.lisAttachUser.TabStop = false;
            this.lisAttachUser.UseCompatibleStateImageBehavior = false;
            this.lisAttachUser.View = System.Windows.Forms.View.Details;
            // 
            // ColumnHeader7
            // 
            this.ColumnHeader7.Text = "User ID";
            this.ColumnHeader7.Width = 80;
            // 
            // ColumnHeader8
            // 
            this.ColumnHeader8.Text = "Description";
            this.ColumnHeader8.Width = 150;
            // 
            // lblAttachUser
            // 
            this.lblAttachUser.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblAttachUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblAttachUser.Location = new System.Drawing.Point(0, 0);
            this.lblAttachUser.Name = "lblAttachUser";
            this.lblAttachUser.Size = new System.Drawing.Size(192, 14);
            this.lblAttachUser.TabIndex = 0;
            this.lblAttachUser.Text = "Attached User List";
            // 
            // spdMid
            // 
            this.spdMid.Location = new System.Drawing.Point(216, 0);
            this.spdMid.Name = "spdMid";
            this.spdMid.Size = new System.Drawing.Size(3, 408);
            this.spdMid.TabIndex = 3;
            this.spdMid.TabStop = false;
            // 
            // frmFMBCreateUDRGroup
            // 
            this.AcceptButton = this.btnCreate;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(682, 448);
            this.Controls.Add(this.spdMid);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlList);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.KeyPreview = true;
            this.MinimumSize = new System.Drawing.Size(690, 482);
            this.Name = "frmFMBCreateUDRGroup";
            this.ShowInTaskbar = false;
            this.Tag = "FMB4002";
            this.Text = "Create UDR Group";
            this.Activated += new System.EventHandler(this.frmFMBCreateUDRGroup_Activated);
            this.Load += new System.EventHandler(this.frmFMBCreateUDRGroup_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlList.ResumeLayout(false);
            this.pnlMid.ResumeLayout(false);
            this.tabUDR.ResumeLayout(false);
            this.tbpGeneral.ResumeLayout(false);
            this.grpGroup.ResumeLayout(false);
            this.grpGroup.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtUpdateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtCreateTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtDesc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGroupID)).EndInit();
            this.tbpCopy.ResumeLayout(false);
            this.grpCopy.ResumeLayout(false);
            this.grpCopy.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtToGroup)).EndInit();
            this.tbpUser.ResumeLayout(false);
            this.pnlUserMid.ResumeLayout(false);
            this.pnlUserAttach.ResumeLayout(false);
            this.pnlUserMidRight.ResumeLayout(false);
            this.pnlGroup.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvGroup)).EndInit();
            this.pnlUserMidLeft.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        
        #region " Variable Definition"
        private bool b_load_flag = false;
        private string sExistFlag = "";
        private string sSelectedUserGroup = "";
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
                if (txtGroupID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    txtGroupID.Focus();
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
                    case "COPY":
                        
                        if (lisGroupList.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(27), Application.ProductName, MessageBoxButtons.OK, 1);
                            lisGroupList.Focus();
                            return false;
                        }
                        if (txtToGroup.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            lisGroupList.Focus();
                            return false;
                        }
                        break;
                    case "USER_ATTACH":

                        if (lisGroupList.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(27), Application.ProductName, MessageBoxButtons.OK, 1);
                            lisGroupList.Focus();
                            return false;
                        }
                        if (lisUserlist.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(27), Application.ProductName, MessageBoxButtons.OK, 1);
                            lisUserlist.Focus();
                            return false;
                        }
                        break;
                    case "USER_DETACH":

                        if (lisGroupList.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(27), Application.ProductName, MessageBoxButtons.OK, 1);
                            lisGroupList.Focus();
                            return false;
                        }
                        if (lisAttachUser.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(27), Application.ProductName, MessageBoxButtons.OK, 1);
                            lisAttachUser.Focus();
                            return false;
                        }
                        break;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // View_UDR_Group()
        //       - View User Define Resource Group Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool View_UDR_Group()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_UDR_Group_In");
                TRSNode out_node = new TRSNode("View_UDR_Group_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("GROUP_ID", lisGroupList.SelectedItems[0].Text);

                if (MPCR.CallService("FMB", "FMB_View_UDR_Group", in_node, ref out_node) == false)
                {
                    return false;
                }

                txtGroupID.Text = MPCF.RTrim(out_node.GetString("GROUP_ID"));
                txtDesc.Text = MPCF.RTrim(out_node.GetString("GROUP_DESC"));
                txtCreateTime.Text = MPCF.MakeDateFormat(out_node.GetString("CREATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtUpdateTime.Text = MPCF.MakeDateFormat(out_node.GetString("UPDATE_TIME"), DATE_TIME_FORMAT.NONE);
                txtWidth.Text = System.Convert.ToString(out_node.GetInt("WIDTH"));
                txtHeight.Text = System.Convert.ToString(out_node.GetInt("HEIGHT"));
                                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.View_UDR_Group()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Update_UDR_Group()
        //       - Create/Update/Delete User Define Group
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep   : Process Step
        //
        private bool Update_UDR_Group(char sStep)
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Update_UDR_Group_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("GROUP_ID", txtGroupID.Text);
                in_node.AddString("GROUP_DESC", txtDesc.Text);
                in_node.AddInt("WIDTH", MPCF.ToInt(txtWidth.Text));
                in_node.AddInt("HEIGHT", MPCF.ToInt(txtHeight.Text));

                if (MPCR.CallService("FMB", "FMB_Update_UDR_Group", in_node, ref out_node) == false)
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.Update_UDR_Group()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }

        private bool Attach_User(char sStep, string sUser, string sGroup)
        {

            try
            {
                TRSNode in_node = new TRSNode("Attach_User_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("GROUP_ID", sGroup);
                in_node.AddString("USER", sUser, true);

                if (MPCR.CallService("FMB", "FMB_Update_FMB_Group", in_node, ref out_node) == false)
                {
                    return false;
                }               

                return true;
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmSPCAttachUserToChart.Attach_User()" + "\r\n" + ex.Message);
                return false;
            }

        }

        public void SelectClear(ListView list)
        {

            try
            {
                int i;
                for (i = 0; i <= list.Items.Count - 1; i++)
                {
                    list.Items[i].Selected = false;
                }
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SelectClear()" + "\r\n" + ex.Message);
            }

        }

        // Update_UDR_Group()
        //       - Create/Update/Delete User Define Group
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep   : Process Step
        //
        private bool Copy_UDR_Group()
        {
            
            try
            {

                TRSNode in_node = new TRSNode("Copy_UDr_Group_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("FROM_GROUP", MPCF.Trim(lisGroupList.SelectedItems[0].Text));
                in_node.AddString("TO_GROUP", MPCF.RTrim(txtToGroup.Text));

                if (MPCR.CallService("FMB", "FMB_Copy_UDR_Group", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.ShowSuccessMsg(out_node);
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.Copy_UDr_Group()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Exist_Control_UDR_Group()
        //       - Check Exist Control Out of the User Define Group
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool Exist_Control_UDR_Group()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Exist_Control_In");
                TRSNode out_node = new TRSNode("Exist_Control_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddChar("LAYOUT_GROUP_FLAG", 'G');
                in_node.AddString("GROUP_ID", txtGroupID.Text);
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
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.Exist_Control_UDR_Group()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Move_Controls_UDR_Group()
        //       - Move Controls by Force
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool Move_Controls_UDR_Group()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("Moving_by_Force_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddChar("LAYOUT_GROUP_FLAG", 'G');
                in_node.AddString("GROUP_ID", txtGroupID.Text);
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
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.Move_Controls_UDR_Group()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        #endregion
        
        #region " Event Implementations"
        
        private void frmFMBCreateUDRGroup_Activated(object sender, System.EventArgs e)
        {
            
            try
            {
                if (b_load_flag == false)
                {
                    lisGroupList.Focus();
                    if (modListRoutine.ViewUDR_GroupList(lisGroupList, '1') == true)
                    {
                        if (lisGroupList.Items.Count > 0)
                        {
                            if (sSelectedUserGroup == "")
                            {
                                lisGroupList.Items[0].Selected = true;
                            }
                            else
                            {
                                MPCF.FindListItem(lisGroupList, sSelectedUserGroup,false);
                            }
                        }
                    }
                    else
                    {
                        return;
                    }
                    SECLIST.ViewSECUserList(lisUserlist);
                    b_load_flag = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.frmFMBCreateUDRGroup_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBCreateUDRGroup_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                MPCF.InitListView(lisGroupList);
                MPCF.InitListView(lisAttachUser);
                MPCF.InitListView(lisUserlist);

                this.pnlRight_Resize(null, null);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.frmFMBCreateUDRGroup_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void lisGroupList_SelectedIndexChanged(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                MPCF.FieldClear(grpGroup, null, null, null, null, null, false);
                MPCF.ClearList(lisAttachUser,false);
                if (lisGroupList.SelectedItems.Count > 0)
                {
                    lisGroupList.Text = lisGroupList.SelectedItems[0].Text;
                    if (View_UDR_Group() == true)
                    {
                        modListRoutine.ViewFMBGroupList(lisAttachUser, '1', lisGroupList.SelectedItems[0].Text,"");
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.lisGroupList_SelectedIndexChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnCreate_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                if (MPCF.ToInt(txtWidth.Text) == 0)
                {
                    txtWidth.Text = ((Size)modGlobalVariable.gGlobalOptions.GetOptions(MPGV.gsFactory, clsOptionData.Options.DefaultUDRSize)).Width.ToString();
                }
                if (MPCF.ToInt(txtHeight.Text) == 0)
                {
                    txtHeight.Text = ((Size)modGlobalVariable.gGlobalOptions.GetOptions(MPGV.gsFactory, clsOptionData.Options.DefaultUDRSize)).Height.ToString();
                }
                if (CheckCondition("CREATE") == true)
                {
                    if (Update_UDR_Group(modGlobalConstant.MP_STEP_CREATE) == false)
                    {
                        return;
                    }
                    if (FMBFI.gIMdiForm.RefreshUdrGroupList() == false)
                    {
                        return;
                    }
                    if (modListRoutine.ViewUDR_GroupList(lisGroupList, '1') == false)
                    {
                        return;
                    }
                    if (lisGroupList.Items.Count > 0)
                    {
                        MPCF.FindListItem(lisGroupList, MPCF.RTrim(txtGroupID.Text), false);
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.btnCreate_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnUpdate_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                System.Windows.Forms.Form frmChild;
                string sDeletedFormName = "";
                DialogResult result;

                if (MPCF.ToInt(txtWidth.Text) == 0)
                {
                    txtWidth.Text = ((Size)modGlobalVariable.gGlobalOptions.GetOptions(MPGV.gsFactory, clsOptionData.Options.DefaultUDRSize)).Width.ToString();
                }
                if (MPCF.ToInt(txtHeight.Text) == 0)
                {
                    txtHeight.Text = ((Size)modGlobalVariable.gGlobalOptions.GetOptions(MPGV.gsFactory, clsOptionData.Options.DefaultUDRSize)).Height.ToString();
                }
                if (CheckCondition("CREATE") == true)
                {
                    //蹂寃쏀븯?ㅻ뒗 LayOut??Width? Height 諛뽰쑝濡?而⑦듃濡ㅼ씠 議댁옱?섎㈃ 媛뺤젣濡??대룞 ?쒗궗寃껋씤吏 臾쇱뼱蹂몃떎.
                    if (Exist_Control_UDR_Group() == false)
                    {
                        return;
                    }
                    if (sExistFlag == "Y")
                    {
                        result = MPCF.ShowMsgBox(MPCF.GetMessage(11), Application.ProductName, MessageBoxButtons.YesNoCancel, 1);
                        //媛뺤젣 ?대룞
                        if (result == DialogResult.Yes)
                        {
                            if (Move_Controls_UDR_Group() == false)
                            {
                                return;
                            }
                            if (Update_UDR_Group(modGlobalConstant.MP_STEP_UPDATE) == false)
                            {
                                return;
                            }
                            sDeletedFormName = txtGroupID.Text;
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
                            if (modListRoutine.ViewUDR_GroupList(lisGroupList, '1') == false)
                            {
                                return;
                            }
                            if (lisGroupList.Items.Count > 0)
                            {
                                MPCF.FindListItem(lisGroupList, MPCF.RTrim(txtGroupID.Text), false);
                            }
                            //媛뺤젣濡??대룞?쒗궎吏 ?딄퀬 ?낅젰??媛믪쑝濡?Update
                        }
                        else if (result == DialogResult.No)
                        {
                            if (Update_UDR_Group(modGlobalConstant.MP_STEP_UPDATE) == false)
                            {
                                return;
                            }
                            sDeletedFormName = txtGroupID.Text;
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
                            if (modListRoutine.ViewUDR_GroupList(lisGroupList, '1') == false)
                            {
                                return;
                            }
                            if (lisGroupList.Items.Count > 0)
                            {
                                MPCF.FindListItem(lisGroupList, MPCF.RTrim(txtGroupID.Text), false);
                            }
                        }
                        else if (result == DialogResult.Cancel)
                        {
                            View_UDR_Group();
                            return;
                        }
                        //蹂寃쏀븯?ㅻ뒗 LayOut??Width? Height 諛뽰쑝濡?而⑦듃濡ㅼ씠 議댁옱?섏? ?딆쑝硫?洹몃깷 Update
                    }
                    else
                    {
                        if (Update_UDR_Group(modGlobalConstant.MP_STEP_UPDATE) == false)
                        {
                            return;
                        }
                        sDeletedFormName = txtGroupID.Text;
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
                        if (modListRoutine.ViewUDR_GroupList(lisGroupList, '1') == false)
                        {
                            return;
                        }
                        if (lisGroupList.Items.Count > 0)
                        {
                            MPCF.FindListItem(lisGroupList, MPCF.RTrim(txtGroupID.Text), false);
                        }
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.btnUpdate_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                    if (Update_UDR_Group(modGlobalConstant.MP_STEP_DELETE) == true)
                    {
                        if (FMBFI.gIMdiForm.RefreshUdrGroupList() == false)
                        {
                            return;
                        }
                        sDeletedFormName = txtGroupID.Text;
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
                        if (modListRoutine.ViewUDR_GroupList(lisGroupList, '1') == true)
                        {
                            if (lisGroupList.Items.Count > 0)
                            {
                                lisGroupList.Items[0].Selected = true;
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
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.btnDelete_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
                
        
        private void frmFMBCreateUDRGroup_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            
            try
            {
                if (!(this.ActiveControl == null))
                {
                    if (this.ActiveControl is TextBox || this.ActiveControl is UltraTextEditor)
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
                MPCF.ShowMsgBox("frmFMBCreateUDRGroup.frmFMBCreateUDRGroup_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateResource.txtHeight_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBCreateResource.txtWidth_KeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnCopy_Click(System.Object sender, System.EventArgs e)
        {
            try
            {
                if (CheckCondition("COPY") == false)
                {
                    return;
                }
                if (Copy_UDR_Group() == false)
                {
                    return;
                }
                if (FMBFI.gIMdiForm.RefreshUdrGroupList() == false)
                {
                    return;
                }
                if (modListRoutine.ViewUDR_GroupList(lisGroupList, '1') == false)
                {
                    return;
                }
                if (lisGroupList.Items.Count > 0)
                {
                    MPCF.FindListItem(lisGroupList, MPCF.RTrim(txtGroupID.Text), false);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBCreateResource.btnCopy_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        private void cdvGroup_ButtonPress(object sender, System.EventArgs e)
        {

            try
            {
                cdvGroup.Init();
                MPCF.InitListView(cdvGroup.GetListView);
                cdvGroup.Columns.Add("UserGroup", 100, HorizontalAlignment.Left);
                cdvGroup.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvGroup.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                cdvGroup.SelectedSubItemIndex = 0;
                if (SECLIST.ViewSecGroupList(cdvGroup.GetListView, '1',null,"") == false) return; // TODO: might not be correct. Was : Exit Sub
                cdvGroup.AddEmptyRow(1);
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmSPCAttachUserToChart.cdvGroup_ButtonPress()" + "\r\n" + ex.Message);
            }

        }
        private void cdvGroup_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {

                if (cdvGroup.Text == "")
                {
                    if (SECLIST.ViewSECUserList(lisUserlist) == false) return; // TODO: might not be correct. Was : Exit Sub

                    if (lisUserlist.Items.Count > 0)
                    {
                        lisUserlist.Items[0].Selected = true;
                    }
                }
                else
                {
                    if (SECLIST.ViewSECUserList(lisUserlist, '2', -1, null, "", (cdvGroup.Text)) == false) return; // TODO: might not be correct. Was : Exit Sub

                    if (lisUserlist.Items.Count > 0)
                    {
                        lisUserlist.Items[0].Selected = true;
                    }
                }
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmSPCAttachUserToChart.cdvGroup_SelectedItemChanged()" + "\r\n" + ex.Message);
            }
        }
        //private void cdvGroup_SelectedItemChanged(object sender, UI.MCCodeViewSelChanged_EventArgs e)
        //{

            

        //}

        private void btnAdd_Click(object sender, System.EventArgs e)
        {

            try
            {
                string sUser;
                string sGroup;
                string[] sSelect = new string[lisUserlist.SelectedItems.Count];
                //ListViewItem itmX;
                int i;
                int j;
                int iIdx = 0;
                

                SelectClear(lisAttachUser);
                if (CheckCondition("USER_ATTACH") == false) return; // TODO: might not be correct. Was : Exit Sub

                for (i = 0; i <= lisUserlist.SelectedItems.Count - 1; i++)
                {
                    sUser = lisUserlist.SelectedItems[i].Text;
                    sGroup = lisGroupList.SelectedItems[0].Text;
                    if (MPCF.FindListItem(lisAttachUser, sUser, false) == false)
                    {
                        if (Attach_User(MPGC.MP_STEP_CREATE, sUser, sGroup) == true)
                        {
                            sSelect[i] = sUser;
                        }
                        else
                        {
                            for (j = 0; j <= sSelect.Length - 1; j++)
                            {
                                MPCF.FindListItem(lisAttachUser, sSelect[j], false);
                            }
                            SelectClear(lisUserlist);
                            return; // TODO: might not be correct. Was : Exit Sub
                        }
                    }
                    else
                    {
                        sSelect[i] = sUser;
                        iIdx = lisUserlist.SelectedItems[i].Index;
                    }
                }
                if (modListRoutine.ViewFMBGroupList(lisAttachUser, '1', lisGroupList.SelectedItems[0].Text,"") == false) return; // TODO: might not be correct. Was : Exit Sub

                SelectClear(lisUserlist);
                if (sSelect.Length == 1)
                {
                    if (iIdx < lisUserlist.Items.Count - 1)
                    {
                        lisUserlist.Items[iIdx + 1].Selected = true;
                    }
                }
                for (i = 0; i <= sSelect.Length - 1; i++)
                {
                    MPCF.FindListItem(lisAttachUser, sSelect[i], false);
                }

                if ( FMBFI.gIMdiForm.RefreshUdrGroupList() == false) return; // TODO: might not be correct. Was : Exit Sub

            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmSPCAttachUserToChart.btnAdd_Click()" + "\r\n" + ex.Message);
            }

        }

        private void btnDel_Click(object sender, System.EventArgs e)
        {

            try
            {
                string sUser;
                string sGroup;
                int iIdx = 0;
                int i;
                int iCount;

                if (CheckCondition("USER_DETACH") == false) return; // TODO: might not be correct. Was : Exit Sub

                iCount = lisAttachUser.SelectedItems.Count;
                SelectClear(lisUserlist);
                for (i = lisAttachUser.SelectedItems.Count - 1; i >= 0; i += -1)
                {
                    sUser = lisAttachUser.SelectedItems[i].Text;
                    sGroup = lisGroupList.SelectedItems[0].Text;

                    if (Attach_User(MPGC.MP_STEP_DELETE, sUser, sGroup) == true)
                    {
                        iIdx = lisAttachUser.SelectedItems[i].Index;
                        lisAttachUser.Items.RemoveAt(iIdx);
                        MPCF.FindListItem(lisUserlist, sUser, false);
                    }
                }
                if (iCount == 1)
                {
                    if (iIdx < lisAttachUser.Items.Count)
                    {
                        lisAttachUser.Items[iIdx].Selected = true;
                    }
                }

                if (FMBFI.gIMdiForm.RefreshUdrGroupList() == false) return; // TODO: might not be correct. Was : Exit Sub

            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmSPCAttachUserToChart.btnDel_Click()" + "\r\n" + ex.Message);
            }

        }

        private void pnlRight_Resize(object sender, System.EventArgs e)
        {

            try
            {
                MPCF.FieldAdjust(pnlUserMid, pnlUserMidLeft, pnlUserMidRight, pnlUserAttach, 40);
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmSPCAttachUserToChart.pnlRight_Resize()" + "\r\n" + ex.Message);
            }

        }

        #endregion

        
    }
    
}
