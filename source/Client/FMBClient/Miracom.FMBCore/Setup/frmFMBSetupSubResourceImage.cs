#define _SPCTYPE
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Miracom.FMBUI.Controls;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBSetupResourceImage.vb
//   Description : Update Resource Image
//
//   FMB Version : 1.0.0
//
//   Function List
//       - CheckCondition() : Check the conditions before transaction
//       - Update_Resource_Image() : Update Resource Image
//       - ViewImageList() : View Image List
//
//   Detail Description
//       -
//
//   History
//       - 2005-03-21 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public class frmFMBSetupSubResourceImage : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBSetupSubResourceImage()
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
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.GroupBox grpFactory;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.Panel pnlImgMid;
        internal System.Windows.Forms.Panel pnlImgMidRight;
        internal System.Windows.Forms.Panel pnlImgMidMid;
        internal System.Windows.Forms.Button btnDel;
        internal System.Windows.Forms.Button btnAdd;
        internal Miracom.UI.Controls.MCListView.MCListView lisImagelist;
        internal System.Windows.Forms.ColumnHeader ColumnHeader15;
        internal System.Windows.Forms.Panel pnlRes;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvType;
        private GroupBox grpSubResource;
        internal Miracom.UI.Controls.MCListView.MCListView lisResource;
        internal ColumnHeader ColumnHeader1;
        internal ColumnHeader colRes;
        internal ColumnHeader ColumnHeader3;
        private GroupBox grpResource;
        internal Miracom.UI.Controls.MCListView.MCListView lisMainResource;
        internal ColumnHeader columnHeader5;
        internal ColumnHeader columnHeader6;
        private Panel pnlLeft;
        internal Label lblType;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnClose = new System.Windows.Forms.Button();
            this.pnlTop = new System.Windows.Forms.Panel();
            this.grpFactory = new System.Windows.Forms.GroupBox();
            this.cdvType = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblType = new System.Windows.Forms.Label();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblFactory = new System.Windows.Forms.Label();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.pnlRes = new System.Windows.Forms.Panel();
            this.grpSubResource = new System.Windows.Forms.GroupBox();
            this.lisResource = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.colRes = new System.Windows.Forms.ColumnHeader();
            this.ColumnHeader3 = new System.Windows.Forms.ColumnHeader();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.grpResource = new System.Windows.Forms.GroupBox();
            this.lisMainResource = new Miracom.UI.Controls.MCListView.MCListView();
            this.columnHeader5 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader6 = new System.Windows.Forms.ColumnHeader();
            this.pnlImgMid = new System.Windows.Forms.Panel();
            this.pnlImgMidRight = new System.Windows.Forms.Panel();
            this.lisImagelist = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader15 = new System.Windows.Forms.ColumnHeader();
            this.pnlImgMidMid = new System.Windows.Forms.Panel();
            this.btnDel = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.pnlBottom.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.grpFactory.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvType)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).BeginInit();
            this.pnlMid.SuspendLayout();
            this.pnlRes.SuspendLayout();
            this.grpSubResource.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.grpResource.SuspendLayout();
            this.pnlImgMid.SuspendLayout();
            this.pnlImgMidRight.SuspendLayout();
            this.pnlImgMidMid.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 513);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 2;
            // 
            // btnClose
            // 
            this.btnClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClose.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClose.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClose.Location = new System.Drawing.Point(659, 9);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(74, 23);
            this.btnClose.TabIndex = 0;
            this.btnClose.Text = "Close";
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // pnlTop
            // 
            this.pnlTop.Controls.Add(this.grpFactory);
            this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTop.Location = new System.Drawing.Point(0, 0);
            this.pnlTop.Name = "pnlTop";
            this.pnlTop.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlTop.Size = new System.Drawing.Size(742, 52);
            this.pnlTop.TabIndex = 0;
            // 
            // grpFactory
            // 
            this.grpFactory.Controls.Add(this.cdvType);
            this.grpFactory.Controls.Add(this.lblType);
            this.grpFactory.Controls.Add(this.cdvFactory);
            this.grpFactory.Controls.Add(this.lblFactory);
            this.grpFactory.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpFactory.Location = new System.Drawing.Point(3, 0);
            this.grpFactory.Name = "grpFactory";
            this.grpFactory.Size = new System.Drawing.Size(736, 52);
            this.grpFactory.TabIndex = 1;
            this.grpFactory.TabStop = false;
            // 
            // cdvType
            // 
            this.cdvType.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvType.BorderHotColor = System.Drawing.Color.Black;
            this.cdvType.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvType.BtnToolTipText = "";
            this.cdvType.DescText = "";
            this.cdvType.DisplaySubItemIndex = -1;
            this.cdvType.DisplayText = "";
            this.cdvType.Focusing = null;
            this.cdvType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvType.Index = 0;
            this.cdvType.IsViewBtnImage = false;
            this.cdvType.Location = new System.Drawing.Point(483, 17);
            this.cdvType.MaxLength = 10;
            this.cdvType.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvType.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvType.Name = "cdvType";
            this.cdvType.ReadOnly = false;
            this.cdvType.SearchSubItemIndex = 0;
            this.cdvType.SelectedDescIndex = -1;
            this.cdvType.SelectedSubItemIndex = -1;
            this.cdvType.SelectionStart = 0;
            this.cdvType.Size = new System.Drawing.Size(200, 20);
            this.cdvType.SmallImageList = null;
            this.cdvType.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvType.TabIndex = 51;
            this.cdvType.TextBoxToolTipText = "";
            this.cdvType.TextBoxWidth = 200;
            this.cdvType.VisibleButton = true;
            this.cdvType.VisibleColumnHeader = false;
            this.cdvType.VisibleDescription = false;
            this.cdvType.TextBoxTextChanged += new System.EventHandler(this.cdvType_TextBoxTextChanged);
            this.cdvType.ButtonPress += new System.EventHandler(this.cdvType_ButtonPress);
            this.cdvType.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.cdvType_SelectedItemChanged);
            // 
            // lblType
            // 
            this.lblType.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblType.Location = new System.Drawing.Point(382, 20);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(100, 14);
            this.lblType.TabIndex = 52;
            this.lblType.Text = "Type";
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
            this.cdvFactory.Location = new System.Drawing.Point(116, 17);
            this.cdvFactory.MaxLength = 10;
            this.cdvFactory.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvFactory.Name = "cdvFactory";
            this.cdvFactory.ReadOnly = false;
            this.cdvFactory.SearchSubItemIndex = 0;
            this.cdvFactory.SelectedDescIndex = -1;
            this.cdvFactory.SelectedSubItemIndex = -1;
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
            this.cdvFactory.TextBoxTextChanged += new System.EventHandler(this.cdvFactory_TextBoxTextChanged);
            this.cdvFactory.ButtonPress += new System.EventHandler(this.cdvFactory_ButtonPress);
            // 
            // lblFactory
            // 
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblFactory.Location = new System.Drawing.Point(15, 20);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(100, 14);
            this.lblFactory.TabIndex = 50;
            this.lblFactory.Text = "Factory";
            // 
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.pnlRes);
            this.pnlMid.Controls.Add(this.pnlImgMid);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 52);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3);
            this.pnlMid.Size = new System.Drawing.Size(742, 461);
            this.pnlMid.TabIndex = 1;
            // 
            // pnlRes
            // 
            this.pnlRes.Controls.Add(this.grpSubResource);
            this.pnlRes.Controls.Add(this.pnlLeft);
            this.pnlRes.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlRes.Location = new System.Drawing.Point(3, 3);
            this.pnlRes.Name = "pnlRes";
            this.pnlRes.Size = new System.Drawing.Size(484, 455);
            this.pnlRes.TabIndex = 3;
            // 
            // grpSubResource
            // 
            this.grpSubResource.Controls.Add(this.lisResource);
            this.grpSubResource.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpSubResource.Location = new System.Drawing.Point(201, 0);
            this.grpSubResource.Name = "grpSubResource";
            this.grpSubResource.Size = new System.Drawing.Size(283, 455);
            this.grpSubResource.TabIndex = 3;
            this.grpSubResource.TabStop = false;
            // 
            // lisResource
            // 
            this.lisResource.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader1,
            this.colRes,
            this.ColumnHeader3});
            this.lisResource.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisResource.EnableSort = true;
            this.lisResource.EnableSortIcon = true;
            this.lisResource.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisResource.FullRowSelect = true;
            this.lisResource.Location = new System.Drawing.Point(3, 16);
            this.lisResource.MultiSelect = false;
            this.lisResource.Name = "lisResource";
            this.lisResource.Size = new System.Drawing.Size(277, 436);
            this.lisResource.TabIndex = 1;
            this.lisResource.UseCompatibleStateImageBehavior = false;
            this.lisResource.View = System.Windows.Forms.View.Details;
            // 
            // ColumnHeader1
            // 
            this.ColumnHeader1.Text = "Image";
            this.ColumnHeader1.Width = 55;
            // 
            // colRes
            // 
            this.colRes.Text = "Resource";
            this.colRes.Width = 154;
            // 
            // ColumnHeader3
            // 
            this.ColumnHeader3.Text = "Description";
            this.ColumnHeader3.Width = 257;
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.grpResource);
            this.pnlLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Size = new System.Drawing.Size(201, 455);
            this.pnlLeft.TabIndex = 4;
            // 
            // grpResource
            // 
            this.grpResource.Controls.Add(this.lisMainResource);
            this.grpResource.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpResource.Location = new System.Drawing.Point(0, 0);
            this.grpResource.Name = "grpResource";
            this.grpResource.Size = new System.Drawing.Size(201, 455);
            this.grpResource.TabIndex = 2;
            this.grpResource.TabStop = false;
            this.grpResource.Text = "Resource";
            // 
            // lisMainResource
            // 
            this.lisMainResource.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader5,
            this.columnHeader6});
            this.lisMainResource.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisMainResource.EnableSort = true;
            this.lisMainResource.EnableSortIcon = true;
            this.lisMainResource.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisMainResource.FullRowSelect = true;
            this.lisMainResource.Location = new System.Drawing.Point(3, 16);
            this.lisMainResource.MultiSelect = false;
            this.lisMainResource.Name = "lisMainResource";
            this.lisMainResource.Size = new System.Drawing.Size(195, 436);
            this.lisMainResource.TabIndex = 3;
            this.lisMainResource.UseCompatibleStateImageBehavior = false;
            this.lisMainResource.View = System.Windows.Forms.View.Details;
            this.lisMainResource.SelectedIndexChanged += new System.EventHandler(this.lisMainResource_SelectedIndexChanged);
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Resource";
            this.columnHeader5.Width = 102;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Description";
            this.columnHeader6.Width = 257;
            // 
            // pnlImgMid
            // 
            this.pnlImgMid.Controls.Add(this.pnlImgMidRight);
            this.pnlImgMid.Controls.Add(this.pnlImgMidMid);
            this.pnlImgMid.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlImgMid.Location = new System.Drawing.Point(487, 3);
            this.pnlImgMid.Name = "pnlImgMid";
            this.pnlImgMid.Padding = new System.Windows.Forms.Padding(0, 0, 5, 0);
            this.pnlImgMid.Size = new System.Drawing.Size(252, 455);
            this.pnlImgMid.TabIndex = 0;
            // 
            // pnlImgMidRight
            // 
            this.pnlImgMidRight.Controls.Add(this.lisImagelist);
            this.pnlImgMidRight.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlImgMidRight.Location = new System.Drawing.Point(47, 0);
            this.pnlImgMidRight.Name = "pnlImgMidRight";
            this.pnlImgMidRight.Size = new System.Drawing.Size(200, 455);
            this.pnlImgMidRight.TabIndex = 18;
            // 
            // lisImagelist
            // 
            this.lisImagelist.AllowDrop = true;
            this.lisImagelist.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader15});
            this.lisImagelist.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisImagelist.EnableSort = true;
            this.lisImagelist.EnableSortIcon = true;
            this.lisImagelist.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisImagelist.FullRowSelect = true;
            this.lisImagelist.Location = new System.Drawing.Point(0, 0);
            this.lisImagelist.Name = "lisImagelist";
            this.lisImagelist.Size = new System.Drawing.Size(200, 455);
            this.lisImagelist.TabIndex = 0;
            this.lisImagelist.UseCompatibleStateImageBehavior = false;
            this.lisImagelist.View = System.Windows.Forms.View.Details;
            // 
            // ColumnHeader15
            // 
            this.ColumnHeader15.Text = "Image";
            this.ColumnHeader15.Width = 174;
            // 
            // pnlImgMidMid
            // 
            this.pnlImgMidMid.Controls.Add(this.btnDel);
            this.pnlImgMidMid.Controls.Add(this.btnAdd);
            this.pnlImgMidMid.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pnlImgMidMid.Location = new System.Drawing.Point(4, 170);
            this.pnlImgMidMid.Name = "pnlImgMidMid";
            this.pnlImgMidMid.Size = new System.Drawing.Size(38, 108);
            this.pnlImgMidMid.TabIndex = 0;
            // 
            // btnDel
            // 
            this.btnDel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnDel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnDel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDel.Location = new System.Drawing.Point(7, 57);
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
            this.btnAdd.Location = new System.Drawing.Point(7, 28);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(24, 24);
            this.btnAdd.TabIndex = 0;
            this.btnAdd.Text = "<";
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // frmFMBSetupSubResourceImage
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 553);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlTop);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBSetupSubResourceImage";
            this.Tag = "FMB1002";
            this.Text = "Resource Image Setup";
            this.Load += new System.EventHandler(this.frmFMBSetupResourceImage_Load);
            this.pnlBottom.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.grpFactory.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvType)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvFactory)).EndInit();
            this.pnlMid.ResumeLayout(false);
            this.pnlRes.ResumeLayout(false);
            this.grpSubResource.ResumeLayout(false);
            this.pnlLeft.ResumeLayout(false);
            this.grpResource.ResumeLayout(false);
            this.pnlImgMid.ResumeLayout(false);
            this.pnlImgMidRight.ResumeLayout(false);
            this.pnlImgMidMid.ResumeLayout(false);
            this.ResumeLayout(false);

        }
        
        #endregion
        
        #region " Variable Definition"
        private ImageList imlRes;
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
                    case "UPDATE":
                        
                        if (cdvFactory.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), "FMB Client", MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        if (pnlLeft.Visible == true)
                        {
                            if (lisMainResource.SelectedItems.Count == 0)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(19) + " (Resource)", "FMB Client", MessageBoxButtons.OK, 1);
                                lisMainResource.Focus();
                                return false;
                            }
                        }
                        if (lisResource.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(19) , "FMB Client", MessageBoxButtons.OK, 1);
                            lisResource.Focus();
                            return false;
                        }
                        if (lisImagelist.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(19) + " (Image)", "FMB Client", MessageBoxButtons.OK, 1);
                            lisImagelist.Focus();
                            return false;
                        }
                        break;
                    case "DELETE":
                        
                        if (cdvFactory.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), "FMB Client", MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        if (pnlLeft.Visible == true)
                        {
                            if (lisMainResource.SelectedItems.Count == 0)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(19) + " (Resource)", "FMB Client", MessageBoxButtons.OK, 1);
                                lisMainResource.Focus();
                                return false;
                            }
                        }
                        if (lisResource.SelectedItems.Count == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(19) , "FMB Client", MessageBoxButtons.OK, 1);
                            lisResource.Focus();
                            return false;
                        }
                        break;
                        
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBViewLotListDetail.CheckCondition()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
        // Update_Resource_Image()
        //       - Update/Delete Resource Image
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String  : Step
        //
        private bool Update_Resource_Image(char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("UPDATE_RESOURCE_IMAGE_IN");
                TRSNode out_node = new TRSNode("CMN_OUT");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.Factory = MPCF.RTrim(cdvFactory.Text);

                if (cdvType.Text == "TOOL" || cdvType.Text == "RES")
                {
                    in_node.AddString("RES_ID", MPCF.LTrim(lisResource.SelectedItems[0].SubItems[1].Text));                    
                }
                else
                {
                    in_node.AddString("RES_ID", lisMainResource.SelectedItems[0].Text);
                    in_node.AddString("SUBRES_ID", lisResource.SelectedItems[0].SubItems[1].Text);
                }

                in_node.AddString("RES_TYPE", cdvType.Text);
                if (sStep != modGlobalConstant.MP_STEP_DELETE)
                {
                    in_node.AddInt("IMAGE_IDX", lisImagelist.SelectedItems[0].Index);
                }

                if (MPCR.CallService("FMB", "FMB_Update_Resource_Image", in_node, ref out_node) == false)
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.Update_Resource_Image()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }
        }

        
        // ViewImageList()
        //       - View Image List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool ViewImageList()
        {
            
            try
            {
                ListViewItem itmx;
                int i;
                udcCtrlResource ctrlRes = new udcCtrlResource(modGlobalVariable.gimlResource);
                imlRes = ctrlRes.imlResource;
                lisImagelist.SmallImageList = imlRes;
                for (i = 0; i <= imlRes.Images.Count - 1; i++)
                {
                    itmx = new ListViewItem("", i);
                    lisImagelist.Items.Add(itmx);
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.ViewImageList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }
        }
        
        #endregion
        
        #region " Event Implementations"
        
        private void btnClose_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                this.Dispose();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.btnClose_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBSetupResourceImage_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                MPCF.InitListView(lisResource);
                MPCF.InitListView(lisMainResource);
                MPCF.InitListView(lisImagelist);
                ViewImageList();
                lisMainResource.SmallImageList = imlRes;
                lisResource.SmallImageList = imlRes;
                
                FMBCF.CheckAllFactoryOption(cdvFactory);
                if (modGlobalVariable.gbAllFactory == false)
                {
                    MPCF.InitListView(lisResource);
                    lisResource.SmallImageList = imlRes;
                    lisMainResource.SmallImageList = imlRes;
                    //modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.frmFMBSetupResourceImage_Load()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                cdvFactory.SmallImageList = MPGV.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1',null);
                cdvFactory.AddEmptyRow(1);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }

        }
        
        private void cdvFactory_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCF.ClearList(lisResource, true);
                MPCF.ClearList(lisMainResource, true);
                cdvType.Text = "";
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnAdd_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("UPDATE") == false)
                {
                    return;
                }
                if (Update_Resource_Image(modGlobalConstant.MP_STEP_UPDATE) == true)
                {
                    MPCF.InitListView(lisResource);
                    lisResource.SmallImageList = imlRes;
                    if (pnlLeft.Visible == true)
                    {
                        modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text, cdvType.Text, lisMainResource.SelectedItems[0].Text);
                    }
                    else
                    {
                        modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text, cdvType.Text, "");
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.btnAdd_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnDel_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("DELETE") == false)
                {
                    return;
                }
                if (Update_Resource_Image(modGlobalConstant.MP_STEP_DELETE) == true)
                {
                    MPCF.InitListView(lisResource);
                    lisResource.SmallImageList = imlRes;
                    if (pnlLeft.Visible == true)
                    {
                        modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text, cdvType.Text, lisMainResource.SelectedItems[0].Text);
                    }
                    else
                    {
                        modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text, cdvType.Text, "");
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.btnDel_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion

        private void cdvType_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(lisResource, true);
                MPCF.ClearList(lisMainResource, true);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }

        private void cdvType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

            try
            {
                MPCF.InitListView(lisMainResource);
                MPCF.ClearList(lisResource, true);
                lisMainResource.SmallImageList = imlRes;
                if (cdvType.Text == "TOOL" || cdvType.Text == "RES")
                {
                    pnlLeft.Visible = false;
                    modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text, cdvType.Text, "");
                }
                else
                {
                    pnlLeft.Visible = true;
                    modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text, cdvType.Text, "");
                    modListRoutine.ViewResourceList(lisMainResource, "", "", "", "", "", false, MPGV.gsFactory, true);
                }
                if (cdvType.Text == "SUBRES")
                {
                    colRes.Text = "Sub Resource";
                }
                else if (cdvType.Text == "TOOL")
                {
                    colRes.Text = "Tool";
                }
                else if (cdvType.Text == "PORT")
                {
                    colRes.Text = "Port";
                }
                else
                {
                    colRes.Text = "Resource";
                }
                 

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.cdvType_SelectedItemChanged()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }

        private void lisMainResource_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                MPCF.InitListView(lisResource);
                lisResource.SmallImageList = imlRes;
                if (lisMainResource.SelectedItems.Count > 0)
                    modListRoutine.ViewResourceImageList(lisResource, '1', cdvFactory.Text, cdvType.Text, lisMainResource.SelectedItems[0].Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupResourceImage.btnDel_Click()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }

        private void cdvType_ButtonPress(object sender, EventArgs e)
        {
            cdvType.Init();
            MPCF.InitListView(cdvType.GetListView);
            cdvType.Columns.Add("Sub RES Type", 150, HorizontalAlignment.Left);
            cdvType.Columns.Add("Desc", 200, HorizontalAlignment.Left);
            cdvType.SelectedSubItemIndex = 0;
            BASLIST.ViewGCMDataList(cdvType.GetListView, '2', "FMB_SUBRES_TYPE");
        }
        
    }
    
}
