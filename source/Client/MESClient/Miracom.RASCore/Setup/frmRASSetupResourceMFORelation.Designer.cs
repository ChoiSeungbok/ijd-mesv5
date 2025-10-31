namespace Miracom.RASCore
{
    partial class frmRASSetupResourceMFORelation
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.tvMFO = new Miracom.MESCore.Controls.udcMFOTreeList();
            this.tabOption = new System.Windows.Forms.TabControl();
            this.tbpResourceGroup = new System.Windows.Forms.TabPage();
            this.pnlGrpMid = new System.Windows.Forms.Panel();
            this.pnlGrpMidRight = new System.Windows.Forms.Panel();
            this.lisGroupList = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader15 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ColumnHeader16 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lblGroupList = new System.Windows.Forms.Label();
            this.pnlGrpMidMid = new System.Windows.Forms.Panel();
            this.btnDel = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.pnlGrpMidLeft = new System.Windows.Forms.Panel();
            this.lisMFORel1 = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader13 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ColumnHeader14 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lblGroup = new System.Windows.Forms.Label();
            this.tbpResource = new System.Windows.Forms.TabPage();
            this.pnlResMid = new System.Windows.Forms.Panel();
            this.pnlResMidRight = new System.Windows.Forms.Panel();
            this.lisResourceList = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ColumnHeader10 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lblResList = new System.Windows.Forms.Label();
            this.pnlResMidMid = new System.Windows.Forms.Panel();
            this.btnDetach = new System.Windows.Forms.Button();
            this.btnAttach = new System.Windows.Forms.Button();
            this.pnlResMidLeft = new System.Windows.Forms.Panel();
            this.lisMFORel2 = new Miracom.UI.Controls.MCListView.MCListView();
            this.ColumnHeader11 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ColumnHeader12 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lblRes = new System.Windows.Forms.Label();
            this.tbpResourceMfo = new System.Windows.Forms.TabPage();
            this.pnlMfoMid = new System.Windows.Forms.Panel();
            this.pnlMfoMidRight = new System.Windows.Forms.Panel();
            this.udcMFOTreeList = new Miracom.MESCore.Controls.udcMFOTreeList();
            this.label1 = new System.Windows.Forms.Label();
            this.pnlMfoMidMid = new System.Windows.Forms.Panel();
            this.btnMfoDetach = new System.Windows.Forms.Button();
            this.btnMfoAttach = new System.Windows.Forms.Button();
            this.pnlMfoMidLeft = new System.Windows.Forms.Panel();
            this.lisMfo = new Miracom.UI.Controls.MCListView.MCListView();
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label2 = new System.Windows.Forms.Label();
            this.tabRelation = new System.Windows.Forms.TabControl();
            this.tbpMFO = new System.Windows.Forms.TabPage();
            this.tbpRes = new System.Windows.Forms.TabPage();
            this.udcResourceTreeList = new Miracom.MESCore.Controls.udcResourceTreeList01();
            this.pnlFind.SuspendLayout();
            this.pnlRight.SuspendLayout();
            this.pnlFilter.SuspendLayout();
            this.grpFilter.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.tabOption.SuspendLayout();
            this.tbpResourceGroup.SuspendLayout();
            this.pnlGrpMid.SuspendLayout();
            this.pnlGrpMidRight.SuspendLayout();
            this.pnlGrpMidMid.SuspendLayout();
            this.pnlGrpMidLeft.SuspendLayout();
            this.tbpResource.SuspendLayout();
            this.pnlResMid.SuspendLayout();
            this.pnlResMidRight.SuspendLayout();
            this.pnlResMidMid.SuspendLayout();
            this.pnlResMidLeft.SuspendLayout();
            this.tbpResourceMfo.SuspendLayout();
            this.pnlMfoMid.SuspendLayout();
            this.pnlMfoMidRight.SuspendLayout();
            this.pnlMfoMidMid.SuspendLayout();
            this.pnlMfoMidLeft.SuspendLayout();
            this.tabRelation.SuspendLayout();
            this.tbpMFO.SuspendLayout();
            this.tbpRes.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlFind
            // 
            this.pnlFind.TabIndex = 4;
            // 
            // btnExcel
            // 
            this.btnExcel.TabIndex = 3;
            this.btnExcel.Click += new System.EventHandler(this.btnExcel_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.TabIndex = 2;
            this.btnRefresh.Click += new System.EventHandler(this.btnRefresh_Click);
            // 
            // btnNext
            // 
            this.btnNext.TabIndex = 1;
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // txtFind
            // 
            this.txtFind.TabIndex = 0;
            this.txtFind.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtFind_KeyPress);
            // 
            // pnlRight
            // 
            this.pnlRight.Controls.Add(this.tabOption);
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.tabRelation);
            this.pnlLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlLeft.Size = new System.Drawing.Size(232, 506);
            // 
            // btnCreate
            // 
            this.btnCreate.TabIndex = 0;
            // 
            // btnDelete
            // 
            this.btnDelete.TabIndex = 2;
            // 
            // btnUpdate
            // 
            this.btnUpdate.TabIndex = 1;
            // 
            // btnClose
            // 
            this.btnClose.TabIndex = 3;
            // 
            // pnlBottom
            // 
            this.pnlBottom.TabIndex = 0;
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "SetupForm02";
            // 
            // tvMFO
            // 
            this.tvMFO.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tvMFO.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tvMFO.IncludeFlowSeqNum = false;
            this.tvMFO.ListCond_ExtFactory = "";
            this.tvMFO.ListCond_Step = '1';
            this.tvMFO.Location = new System.Drawing.Point(3, 3);
            this.tvMFO.MaterialType = "";
            this.tvMFO.Name = "tvMFO";
            this.tvMFO.Size = new System.Drawing.Size(218, 474);
            this.tvMFO.TabIndex = 0;
            this.tvMFO.VisibleLevel1MFO = true;
            this.tvMFO.VisibleLevel2FO = true;
            this.tvMFO.VisibleLevel3O = true;
            this.tvMFO.VisibleLevel4MO = true;
            this.tvMFO.VisibleLevel5MF = false;
            this.tvMFO.VisibleLevel6M = false;
            this.tvMFO.VisibleLevel7F = false;
            this.tvMFO.VisibleLevel8Factory = false;
            this.tvMFO.VisibleMaterialIncludeDeleteCheck = false;
            this.tvMFO.VisibleMaterialType = false;
            this.tvMFO.VisibleOnlySetData = true;
            this.tvMFO.VisibleViewType = true;
            this.tvMFO.AfterGetTree += new System.EventHandler(this.tvMFO_AfterGetTree);
            this.tvMFO.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tvMFO_AfterSelect);
            this.tvMFO.LevelItemSelect += new System.Windows.Forms.TreeViewEventHandler(this.tvMFO_LevelItemSelect);
            this.tvMFO.GetOnlySetData += new System.EventHandler(this.tvMFO_GetOnlySetData);
            this.tvMFO.SetDataSelectedIndexChanged += new System.EventHandler(this.tvMFO_SetDataSelectedIndexChanged);
            // 
            // tabOption
            // 
            this.tabOption.Controls.Add(this.tbpResourceGroup);
            this.tabOption.Controls.Add(this.tbpResource);
            this.tabOption.Controls.Add(this.tbpResourceMfo);
            this.tabOption.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabOption.Location = new System.Drawing.Point(0, 0);
            this.tabOption.Name = "tabOption";
            this.tabOption.SelectedIndex = 0;
            this.tabOption.Size = new System.Drawing.Size(506, 506);
            this.tabOption.TabIndex = 0;
            this.tabOption.SelectedIndexChanged += new System.EventHandler(this.tabOption_SelectedIndexChanged);
            // 
            // tbpResourceGroup
            // 
            this.tbpResourceGroup.BackColor = System.Drawing.SystemColors.Control;
            this.tbpResourceGroup.Controls.Add(this.pnlGrpMid);
            this.tbpResourceGroup.Location = new System.Drawing.Point(4, 22);
            this.tbpResourceGroup.Name = "tbpResourceGroup";
            this.tbpResourceGroup.Padding = new System.Windows.Forms.Padding(3);
            this.tbpResourceGroup.Size = new System.Drawing.Size(498, 480);
            this.tbpResourceGroup.TabIndex = 0;
            this.tbpResourceGroup.Text = "Resource Group";
            // 
            // pnlGrpMid
            // 
            this.pnlGrpMid.Controls.Add(this.pnlGrpMidRight);
            this.pnlGrpMid.Controls.Add(this.pnlGrpMidMid);
            this.pnlGrpMid.Controls.Add(this.pnlGrpMidLeft);
            this.pnlGrpMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlGrpMid.Location = new System.Drawing.Point(3, 3);
            this.pnlGrpMid.Name = "pnlGrpMid";
            this.pnlGrpMid.Size = new System.Drawing.Size(492, 474);
            this.pnlGrpMid.TabIndex = 2;
            this.pnlGrpMid.Resize += new System.EventHandler(this.pnlGrpMid_Resize);
            // 
            // pnlGrpMidRight
            // 
            this.pnlGrpMidRight.Controls.Add(this.lisGroupList);
            this.pnlGrpMidRight.Controls.Add(this.lblGroupList);
            this.pnlGrpMidRight.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlGrpMidRight.Location = new System.Drawing.Point(266, 0);
            this.pnlGrpMidRight.Name = "pnlGrpMidRight";
            this.pnlGrpMidRight.Size = new System.Drawing.Size(226, 474);
            this.pnlGrpMidRight.TabIndex = 18;
            // 
            // lisGroupList
            // 
            this.lisGroupList.AllowDrop = true;
            this.lisGroupList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader15,
            this.ColumnHeader16});
            this.lisGroupList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisGroupList.EnableSort = true;
            this.lisGroupList.EnableSortIcon = true;
            this.lisGroupList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisGroupList.FullRowSelect = true;
            this.lisGroupList.Location = new System.Drawing.Point(0, 14);
            this.lisGroupList.Name = "lisGroupList";
            this.lisGroupList.Size = new System.Drawing.Size(226, 460);
            this.lisGroupList.TabIndex = 1;
            this.lisGroupList.UseCompatibleStateImageBehavior = false;
            this.lisGroupList.View = System.Windows.Forms.View.Details;
            this.lisGroupList.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.lisGroupList_ItemDrag);
            this.lisGroupList.Click += new System.EventHandler(this.lisGroupList_Click);
            this.lisGroupList.DragDrop += new System.Windows.Forms.DragEventHandler(this.lisGroupList_DragDrop);
            this.lisGroupList.DragEnter += new System.Windows.Forms.DragEventHandler(this.lisGroupList_DragEnter);
            this.lisGroupList.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lisGroupList_MouseDown);
            // 
            // ColumnHeader15
            // 
            this.ColumnHeader15.Text = "Resource Group";
            this.ColumnHeader15.Width = 100;
            // 
            // ColumnHeader16
            // 
            this.ColumnHeader16.Text = "Description";
            this.ColumnHeader16.Width = 150;
            // 
            // lblGroupList
            // 
            this.lblGroupList.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblGroupList.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGroupList.Location = new System.Drawing.Point(0, 0);
            this.lblGroupList.Name = "lblGroupList";
            this.lblGroupList.Size = new System.Drawing.Size(226, 14);
            this.lblGroupList.TabIndex = 0;
            this.lblGroupList.Text = "All Resource Group List";
            // 
            // pnlGrpMidMid
            // 
            this.pnlGrpMidMid.Controls.Add(this.btnDel);
            this.pnlGrpMidMid.Controls.Add(this.btnAdd);
            this.pnlGrpMidMid.Location = new System.Drawing.Point(216, 36);
            this.pnlGrpMidMid.Name = "pnlGrpMidMid";
            this.pnlGrpMidMid.Size = new System.Drawing.Size(38, 108);
            this.pnlGrpMidMid.TabIndex = 0;
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
            // pnlGrpMidLeft
            // 
            this.pnlGrpMidLeft.Controls.Add(this.lisMFORel1);
            this.pnlGrpMidLeft.Controls.Add(this.lblGroup);
            this.pnlGrpMidLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlGrpMidLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlGrpMidLeft.Name = "pnlGrpMidLeft";
            this.pnlGrpMidLeft.Size = new System.Drawing.Size(208, 474);
            this.pnlGrpMidLeft.TabIndex = 16;
            // 
            // lisMFORel1
            // 
            this.lisMFORel1.AllowDrop = true;
            this.lisMFORel1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader13,
            this.ColumnHeader14});
            this.lisMFORel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisMFORel1.EnableSort = true;
            this.lisMFORel1.EnableSortIcon = true;
            this.lisMFORel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisMFORel1.FullRowSelect = true;
            this.lisMFORel1.Location = new System.Drawing.Point(0, 14);
            this.lisMFORel1.Name = "lisMFORel1";
            this.lisMFORel1.Size = new System.Drawing.Size(208, 460);
            this.lisMFORel1.TabIndex = 1;
            this.lisMFORel1.UseCompatibleStateImageBehavior = false;
            this.lisMFORel1.View = System.Windows.Forms.View.Details;
            this.lisMFORel1.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.lisMFORel1_ItemDrag);
            this.lisMFORel1.Click += new System.EventHandler(this.lisMFORel1_Click);
            this.lisMFORel1.DragDrop += new System.Windows.Forms.DragEventHandler(this.lisMFORel1_DragDrop);
            this.lisMFORel1.DragEnter += new System.Windows.Forms.DragEventHandler(this.lisMFORel1_DragEnter);
            this.lisMFORel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lisMFORel1_MouseDown);
            // 
            // ColumnHeader13
            // 
            this.ColumnHeader13.Text = "Resource Group";
            this.ColumnHeader13.Width = 100;
            // 
            // ColumnHeader14
            // 
            this.ColumnHeader14.Text = "Description";
            this.ColumnHeader14.Width = 150;
            // 
            // lblGroup
            // 
            this.lblGroup.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblGroup.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblGroup.Location = new System.Drawing.Point(0, 0);
            this.lblGroup.Name = "lblGroup";
            this.lblGroup.Size = new System.Drawing.Size(208, 14);
            this.lblGroup.TabIndex = 0;
            this.lblGroup.Text = "MFO - Resource Group Relation";
            // 
            // tbpResource
            // 
            this.tbpResource.BackColor = System.Drawing.SystemColors.Control;
            this.tbpResource.Controls.Add(this.pnlResMid);
            this.tbpResource.Location = new System.Drawing.Point(4, 22);
            this.tbpResource.Name = "tbpResource";
            this.tbpResource.Padding = new System.Windows.Forms.Padding(3);
            this.tbpResource.Size = new System.Drawing.Size(498, 480);
            this.tbpResource.TabIndex = 1;
            this.tbpResource.Text = "Resource";
            // 
            // pnlResMid
            // 
            this.pnlResMid.Controls.Add(this.pnlResMidRight);
            this.pnlResMid.Controls.Add(this.pnlResMidMid);
            this.pnlResMid.Controls.Add(this.pnlResMidLeft);
            this.pnlResMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlResMid.Location = new System.Drawing.Point(3, 3);
            this.pnlResMid.Name = "pnlResMid";
            this.pnlResMid.Size = new System.Drawing.Size(492, 474);
            this.pnlResMid.TabIndex = 2;
            this.pnlResMid.Resize += new System.EventHandler(this.pnlResMid_Resize);
            // 
            // pnlResMidRight
            // 
            this.pnlResMidRight.Controls.Add(this.lisResourceList);
            this.pnlResMidRight.Controls.Add(this.lblResList);
            this.pnlResMidRight.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlResMidRight.Location = new System.Drawing.Point(266, 0);
            this.pnlResMidRight.Name = "pnlResMidRight";
            this.pnlResMidRight.Size = new System.Drawing.Size(226, 474);
            this.pnlResMidRight.TabIndex = 18;
            // 
            // lisResourceList
            // 
            this.lisResourceList.AllowDrop = true;
            this.lisResourceList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader9,
            this.ColumnHeader10});
            this.lisResourceList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisResourceList.EnableSort = true;
            this.lisResourceList.EnableSortIcon = true;
            this.lisResourceList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisResourceList.FullRowSelect = true;
            this.lisResourceList.Location = new System.Drawing.Point(0, 14);
            this.lisResourceList.Name = "lisResourceList";
            this.lisResourceList.Size = new System.Drawing.Size(226, 460);
            this.lisResourceList.TabIndex = 16;
            this.lisResourceList.UseCompatibleStateImageBehavior = false;
            this.lisResourceList.View = System.Windows.Forms.View.Details;
            this.lisResourceList.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.lisResourceList_ItemDrag);
            this.lisResourceList.Click += new System.EventHandler(this.lisResourceList_Click);
            this.lisResourceList.DragDrop += new System.Windows.Forms.DragEventHandler(this.lisResourceList_DragDrop);
            this.lisResourceList.DragEnter += new System.Windows.Forms.DragEventHandler(this.lisResourceList_DragEnter);
            this.lisResourceList.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lisResourceList_MouseDown);
            // 
            // ColumnHeader9
            // 
            this.ColumnHeader9.Text = "Resource";
            this.ColumnHeader9.Width = 100;
            // 
            // ColumnHeader10
            // 
            this.ColumnHeader10.Text = "Description";
            this.ColumnHeader10.Width = 150;
            // 
            // lblResList
            // 
            this.lblResList.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblResList.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblResList.Location = new System.Drawing.Point(0, 0);
            this.lblResList.Name = "lblResList";
            this.lblResList.Size = new System.Drawing.Size(226, 14);
            this.lblResList.TabIndex = 14;
            this.lblResList.Text = "All Resource List";
            // 
            // pnlResMidMid
            // 
            this.pnlResMidMid.Controls.Add(this.btnDetach);
            this.pnlResMidMid.Controls.Add(this.btnAttach);
            this.pnlResMidMid.Location = new System.Drawing.Point(216, 36);
            this.pnlResMidMid.Name = "pnlResMidMid";
            this.pnlResMidMid.Size = new System.Drawing.Size(38, 108);
            this.pnlResMidMid.TabIndex = 17;
            // 
            // btnDetach
            // 
            this.btnDetach.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnDetach.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnDetach.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDetach.Location = new System.Drawing.Point(7, 57);
            this.btnDetach.Name = "btnDetach";
            this.btnDetach.Size = new System.Drawing.Size(24, 24);
            this.btnDetach.TabIndex = 17;
            this.btnDetach.Text = ">";
            this.btnDetach.Click += new System.EventHandler(this.btnDetach_Click);
            // 
            // btnAttach
            // 
            this.btnAttach.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnAttach.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnAttach.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAttach.Location = new System.Drawing.Point(7, 28);
            this.btnAttach.Name = "btnAttach";
            this.btnAttach.Size = new System.Drawing.Size(24, 24);
            this.btnAttach.TabIndex = 16;
            this.btnAttach.Text = "<";
            this.btnAttach.Click += new System.EventHandler(this.btnAttach_Click);
            // 
            // pnlResMidLeft
            // 
            this.pnlResMidLeft.Controls.Add(this.lisMFORel2);
            this.pnlResMidLeft.Controls.Add(this.lblRes);
            this.pnlResMidLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlResMidLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlResMidLeft.Name = "pnlResMidLeft";
            this.pnlResMidLeft.Size = new System.Drawing.Size(208, 474);
            this.pnlResMidLeft.TabIndex = 16;
            // 
            // lisMFORel2
            // 
            this.lisMFORel2.AllowDrop = true;
            this.lisMFORel2.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ColumnHeader11,
            this.ColumnHeader12});
            this.lisMFORel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisMFORel2.EnableSort = true;
            this.lisMFORel2.EnableSortIcon = true;
            this.lisMFORel2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisMFORel2.FullRowSelect = true;
            this.lisMFORel2.Location = new System.Drawing.Point(0, 14);
            this.lisMFORel2.Name = "lisMFORel2";
            this.lisMFORel2.Size = new System.Drawing.Size(208, 460);
            this.lisMFORel2.TabIndex = 15;
            this.lisMFORel2.UseCompatibleStateImageBehavior = false;
            this.lisMFORel2.View = System.Windows.Forms.View.Details;
            this.lisMFORel2.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.lisMFORel2_ItemDrag);
            this.lisMFORel2.Click += new System.EventHandler(this.lisMFORel2_Click);
            this.lisMFORel2.DragDrop += new System.Windows.Forms.DragEventHandler(this.lisMFORel2_DragDrop);
            this.lisMFORel2.DragEnter += new System.Windows.Forms.DragEventHandler(this.lisMFORel2_DragEnter);
            this.lisMFORel2.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lisMFORel2_MouseDown);
            // 
            // ColumnHeader11
            // 
            this.ColumnHeader11.Text = "Resource";
            this.ColumnHeader11.Width = 100;
            // 
            // ColumnHeader12
            // 
            this.ColumnHeader12.Text = "Description";
            this.ColumnHeader12.Width = 150;
            // 
            // lblRes
            // 
            this.lblRes.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblRes.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblRes.Location = new System.Drawing.Point(0, 0);
            this.lblRes.Name = "lblRes";
            this.lblRes.Size = new System.Drawing.Size(208, 14);
            this.lblRes.TabIndex = 13;
            this.lblRes.Text = "MFO - Resource Relation";
            // 
            // tbpResourceMfo
            // 
            this.tbpResourceMfo.BackColor = System.Drawing.SystemColors.Control;
            this.tbpResourceMfo.Controls.Add(this.pnlMfoMid);
            this.tbpResourceMfo.Location = new System.Drawing.Point(4, 22);
            this.tbpResourceMfo.Name = "tbpResourceMfo";
            this.tbpResourceMfo.Padding = new System.Windows.Forms.Padding(3);
            this.tbpResourceMfo.Size = new System.Drawing.Size(498, 480);
            this.tbpResourceMfo.TabIndex = 2;
            this.tbpResourceMfo.Text = "MFO";
            // 
            // pnlMfoMid
            // 
            this.pnlMfoMid.Controls.Add(this.pnlMfoMidRight);
            this.pnlMfoMid.Controls.Add(this.pnlMfoMidMid);
            this.pnlMfoMid.Controls.Add(this.pnlMfoMidLeft);
            this.pnlMfoMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMfoMid.Location = new System.Drawing.Point(3, 3);
            this.pnlMfoMid.Name = "pnlMfoMid";
            this.pnlMfoMid.Size = new System.Drawing.Size(492, 474);
            this.pnlMfoMid.TabIndex = 3;
            this.pnlMfoMid.Resize += new System.EventHandler(this.pnlResourceMfo_Resize);
            // 
            // pnlMfoMidRight
            // 
            this.pnlMfoMidRight.Controls.Add(this.udcMFOTreeList);
            this.pnlMfoMidRight.Controls.Add(this.label1);
            this.pnlMfoMidRight.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlMfoMidRight.Location = new System.Drawing.Point(266, 0);
            this.pnlMfoMidRight.Name = "pnlMfoMidRight";
            this.pnlMfoMidRight.Size = new System.Drawing.Size(226, 474);
            this.pnlMfoMidRight.TabIndex = 18;
            // 
            // udcMFOTreeList
            // 
            this.udcMFOTreeList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.udcMFOTreeList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.udcMFOTreeList.IncludeFlowSeqNum = false;
            this.udcMFOTreeList.ListCond_ExtFactory = "";
            this.udcMFOTreeList.ListCond_Step = '1';
            this.udcMFOTreeList.Location = new System.Drawing.Point(0, 14);
            this.udcMFOTreeList.MaterialType = "";
            this.udcMFOTreeList.Name = "udcMFOTreeList";
            this.udcMFOTreeList.Size = new System.Drawing.Size(226, 460);
            this.udcMFOTreeList.TabIndex = 1;
            this.udcMFOTreeList.VisibleLevel1MFO = true;
            this.udcMFOTreeList.VisibleLevel2FO = true;
            this.udcMFOTreeList.VisibleLevel3O = true;
            this.udcMFOTreeList.VisibleLevel4MO = true;
            this.udcMFOTreeList.VisibleLevel5MF = false;
            this.udcMFOTreeList.VisibleLevel6M = false;
            this.udcMFOTreeList.VisibleLevel7F = false;
            this.udcMFOTreeList.VisibleLevel8Factory = false;
            this.udcMFOTreeList.VisibleMaterialIncludeDeleteCheck = false;
            this.udcMFOTreeList.VisibleMaterialType = false;
            this.udcMFOTreeList.VisibleOnlySetData = false;
            this.udcMFOTreeList.VisibleViewType = false;
            // 
            // label1
            // 
            this.label1.Dock = System.Windows.Forms.DockStyle.Top;
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(226, 14);
            this.label1.TabIndex = 0;
            this.label1.Text = "All MFO List";
            // 
            // pnlMfoMidMid
            // 
            this.pnlMfoMidMid.Controls.Add(this.btnMfoDetach);
            this.pnlMfoMidMid.Controls.Add(this.btnMfoAttach);
            this.pnlMfoMidMid.Location = new System.Drawing.Point(216, 36);
            this.pnlMfoMidMid.Name = "pnlMfoMidMid";
            this.pnlMfoMidMid.Size = new System.Drawing.Size(38, 108);
            this.pnlMfoMidMid.TabIndex = 0;
            // 
            // btnMfoDetach
            // 
            this.btnMfoDetach.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnMfoDetach.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnMfoDetach.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMfoDetach.Location = new System.Drawing.Point(7, 57);
            this.btnMfoDetach.Name = "btnMfoDetach";
            this.btnMfoDetach.Size = new System.Drawing.Size(24, 24);
            this.btnMfoDetach.TabIndex = 1;
            this.btnMfoDetach.Text = ">";
            this.btnMfoDetach.Click += new System.EventHandler(this.btnMfoDetach_Click);
            // 
            // btnMfoAttach
            // 
            this.btnMfoAttach.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnMfoAttach.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnMfoAttach.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMfoAttach.Location = new System.Drawing.Point(7, 28);
            this.btnMfoAttach.Name = "btnMfoAttach";
            this.btnMfoAttach.Size = new System.Drawing.Size(24, 24);
            this.btnMfoAttach.TabIndex = 0;
            this.btnMfoAttach.Text = "<";
            this.btnMfoAttach.Click += new System.EventHandler(this.btnMfoAttach_Click);
            // 
            // pnlMfoMidLeft
            // 
            this.pnlMfoMidLeft.Controls.Add(this.lisMfo);
            this.pnlMfoMidLeft.Controls.Add(this.label2);
            this.pnlMfoMidLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlMfoMidLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlMfoMidLeft.Name = "pnlMfoMidLeft";
            this.pnlMfoMidLeft.Size = new System.Drawing.Size(208, 474);
            this.pnlMfoMidLeft.TabIndex = 16;
            // 
            // lisMfo
            // 
            this.lisMfo.AllowDrop = true;
            this.lisMfo.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader3,
            this.columnHeader2,
            this.columnHeader4,
            this.columnHeader1});
            this.lisMfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisMfo.EnableSort = true;
            this.lisMfo.EnableSortIcon = true;
            this.lisMfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisMfo.FullRowSelect = true;
            this.lisMfo.Location = new System.Drawing.Point(0, 14);
            this.lisMfo.Name = "lisMfo";
            this.lisMfo.Size = new System.Drawing.Size(208, 460);
            this.lisMfo.TabIndex = 1;
            this.lisMfo.UseCompatibleStateImageBehavior = false;
            this.lisMfo.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Material";
            this.columnHeader3.Width = 150;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Ver";
            this.columnHeader2.Width = 30;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Flow";
            this.columnHeader4.Width = 80;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "Operation";
            this.columnHeader1.Width = 80;
            // 
            // label2
            // 
            this.label2.Dock = System.Windows.Forms.DockStyle.Top;
            this.label2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label2.Location = new System.Drawing.Point(0, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(208, 14);
            this.label2.TabIndex = 0;
            this.label2.Text = "Resource - MFO Relation";
            // 
            // tabRelation
            // 
            this.tabRelation.Controls.Add(this.tbpMFO);
            this.tabRelation.Controls.Add(this.tbpRes);
            this.tabRelation.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabRelation.Location = new System.Drawing.Point(0, 0);
            this.tabRelation.Name = "tabRelation";
            this.tabRelation.SelectedIndex = 0;
            this.tabRelation.Size = new System.Drawing.Size(232, 506);
            this.tabRelation.TabIndex = 1;
            this.tabRelation.SelectedIndexChanged += new System.EventHandler(this.tabRelation_SelectedIndexChanged);
            // 
            // tbpMFO
            // 
            this.tbpMFO.Controls.Add(this.tvMFO);
            this.tbpMFO.Location = new System.Drawing.Point(4, 22);
            this.tbpMFO.Name = "tbpMFO";
            this.tbpMFO.Padding = new System.Windows.Forms.Padding(3);
            this.tbpMFO.Size = new System.Drawing.Size(224, 480);
            this.tbpMFO.TabIndex = 0;
            this.tbpMFO.Text = "MFO";
            // 
            // tbpRes
            // 
            this.tbpRes.Controls.Add(this.udcResourceTreeList);
            this.tbpRes.Location = new System.Drawing.Point(4, 22);
            this.tbpRes.Name = "tbpRes";
            this.tbpRes.Padding = new System.Windows.Forms.Padding(3);
            this.tbpRes.Size = new System.Drawing.Size(224, 480);
            this.tbpRes.TabIndex = 1;
            this.tbpRes.Text = "Resource";
            // 
            // udcResourceTreeList
            // 
            this.udcResourceTreeList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.udcResourceTreeList.ListCond_ExtFactory = "";
            this.udcResourceTreeList.ListCond_Step = '1';
            this.udcResourceTreeList.Location = new System.Drawing.Point(3, 3);
            this.udcResourceTreeList.Name = "udcResourceTreeList";
            this.udcResourceTreeList.Size = new System.Drawing.Size(218, 474);
            this.udcResourceTreeList.TabIndex = 0;
            this.udcResourceTreeList.VisibleLevel1R = true;
            this.udcResourceTreeList.VisibleLevel2G = true;
            this.udcResourceTreeList.VisibleLevel3T = false;
            this.udcResourceTreeList.VisibleOnlySetData = false;
            this.udcResourceTreeList.VisibleResourceIncludeDeleteCheck = false;
            this.udcResourceTreeList.AfterGetTree += new System.EventHandler(this.udcResourceTreeList_AfterGetTree);
            this.udcResourceTreeList.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.udcResourceTreeList_AfterSelect);
            this.udcResourceTreeList.LevelItemSelect += new System.Windows.Forms.TreeViewEventHandler(this.udcResourceTreeList_LevelItemSelect);
            // 
            // frmRASSetupResourceMFORelation
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.ClientSize = new System.Drawing.Size(742, 546);
            this.Name = "frmRASSetupResourceMFORelation";
            this.Text = "Resource MFO Relation Setup";
            this.Load += new System.EventHandler(this.frmRASSetupResourceMFORelation_Load);
            this.pnlFind.ResumeLayout(false);
            this.pnlFind.PerformLayout();
            this.pnlRight.ResumeLayout(false);
            this.pnlFilter.ResumeLayout(false);
            this.grpFilter.ResumeLayout(false);
            this.grpFilter.PerformLayout();
            this.pnlLeft.ResumeLayout(false);
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.tabOption.ResumeLayout(false);
            this.tbpResourceGroup.ResumeLayout(false);
            this.pnlGrpMid.ResumeLayout(false);
            this.pnlGrpMidRight.ResumeLayout(false);
            this.pnlGrpMidMid.ResumeLayout(false);
            this.pnlGrpMidLeft.ResumeLayout(false);
            this.tbpResource.ResumeLayout(false);
            this.pnlResMid.ResumeLayout(false);
            this.pnlResMidRight.ResumeLayout(false);
            this.pnlResMidMid.ResumeLayout(false);
            this.pnlResMidLeft.ResumeLayout(false);
            this.tbpResourceMfo.ResumeLayout(false);
            this.pnlMfoMid.ResumeLayout(false);
            this.pnlMfoMidRight.ResumeLayout(false);
            this.pnlMfoMidMid.ResumeLayout(false);
            this.pnlMfoMidLeft.ResumeLayout(false);
            this.tabRelation.ResumeLayout(false);
            this.tbpMFO.ResumeLayout(false);
            this.tbpRes.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private Miracom.MESCore.Controls.udcMFOTreeList tvMFO;
        private System.Windows.Forms.TabControl tabOption;
        private System.Windows.Forms.TabPage tbpResourceGroup;
        private System.Windows.Forms.TabPage tbpResource;
        private System.Windows.Forms.Panel pnlGrpMid;
        private System.Windows.Forms.Panel pnlGrpMidRight;
        private Miracom.UI.Controls.MCListView.MCListView lisGroupList;
        private System.Windows.Forms.ColumnHeader ColumnHeader15;
        private System.Windows.Forms.ColumnHeader ColumnHeader16;
        private System.Windows.Forms.Label lblGroupList;
        private System.Windows.Forms.Panel pnlGrpMidMid;
        private System.Windows.Forms.Button btnDel;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Panel pnlGrpMidLeft;
        private Miracom.UI.Controls.MCListView.MCListView lisMFORel1;
        private System.Windows.Forms.ColumnHeader ColumnHeader13;
        private System.Windows.Forms.ColumnHeader ColumnHeader14;
        private System.Windows.Forms.Label lblGroup;
        private System.Windows.Forms.Panel pnlResMid;
        private System.Windows.Forms.Panel pnlResMidRight;
        private Miracom.UI.Controls.MCListView.MCListView lisResourceList;
        private System.Windows.Forms.ColumnHeader ColumnHeader9;
        private System.Windows.Forms.ColumnHeader ColumnHeader10;
        private System.Windows.Forms.Label lblResList;
        private System.Windows.Forms.Panel pnlResMidMid;
        private System.Windows.Forms.Button btnDetach;
        private System.Windows.Forms.Button btnAttach;
        private System.Windows.Forms.Panel pnlResMidLeft;
        private Miracom.UI.Controls.MCListView.MCListView lisMFORel2;
        private System.Windows.Forms.ColumnHeader ColumnHeader11;
        private System.Windows.Forms.ColumnHeader ColumnHeader12;
        private System.Windows.Forms.Label lblRes;
        private System.Windows.Forms.TabControl tabRelation;
        private System.Windows.Forms.TabPage tbpMFO;
        private System.Windows.Forms.TabPage tbpRes;
        private System.Windows.Forms.TabPage tbpResourceMfo;
        private System.Windows.Forms.Panel pnlMfoMid;
        private System.Windows.Forms.Panel pnlMfoMidRight;
        private MESCore.Controls.udcMFOTreeList udcMFOTreeList;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel pnlMfoMidMid;
        private System.Windows.Forms.Button btnMfoDetach;
        private System.Windows.Forms.Button btnMfoAttach;
        private System.Windows.Forms.Panel pnlMfoMidLeft;
        private UI.Controls.MCListView.MCListView lisMfo;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private MESCore.Controls.udcResourceTreeList01 udcResourceTreeList;
        private System.Windows.Forms.ColumnHeader columnHeader2;

    }
}
