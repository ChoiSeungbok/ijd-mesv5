namespace ADMINClient
{
    partial class frmMDIMain
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMDIMain));
            Infragistics.Win.Appearance appearance1 = new Infragistics.Win.Appearance("Menu", 31103813);
            Infragistics.Win.Appearance appearance2 = new Infragistics.Win.Appearance("Favorites", 31170157);
            Infragistics.Win.Appearance appearance3 = new Infragistics.Win.Appearance("Operation", 31181579);
            Infragistics.Win.Appearance appearance4 = new Infragistics.Win.Appearance("Resource", 31187626);
            Infragistics.Win.Appearance appearance5 = new Infragistics.Win.Appearance("Dispatcher", 31193516);
            Infragistics.Win.Appearance appearance6 = new Infragistics.Win.Appearance("RMS", 31204188);
            Infragistics.Win.UltraWinDock.DockAreaPane dockAreaPane1 = new Infragistics.Win.UltraWinDock.DockAreaPane(Infragistics.Win.UltraWinDock.DockedLocation.DockedLeft, new System.Guid("70d4e40e-c291-46b9-a24a-3bced01962c7"));
            Infragistics.Win.UltraWinDock.DockableControlPane dockableControlPane1 = new Infragistics.Win.UltraWinDock.DockableControlPane(new System.Guid("184ceb3b-af4f-492c-95e0-6ce84e5b748b"), new System.Guid("00000000-0000-0000-0000-000000000000"), -1, new System.Guid("70d4e40e-c291-46b9-a24a-3bced01962c7"), -1);
            Infragistics.Win.UltraWinDock.DockAreaPane dockAreaPane2 = new Infragistics.Win.UltraWinDock.DockAreaPane(Infragistics.Win.UltraWinDock.DockedLocation.DockedLeft, new System.Guid("e7fb2ed4-932d-4dd8-bda0-93ee6e6c93cd"));
            Infragistics.Win.UltraWinDock.DockableControlPane dockableControlPane2 = new Infragistics.Win.UltraWinDock.DockableControlPane(new System.Guid("42be94c1-4a72-4627-8c9c-4dcf5c4306bb"), new System.Guid("00000000-0000-0000-0000-000000000000"), -1, new System.Guid("e7fb2ed4-932d-4dd8-bda0-93ee6e6c93cd"), -1);
            this.pnlMenu = new System.Windows.Forms.Panel();
            this.tvMenu = new System.Windows.Forms.TreeView();
            this.pnlMenuBtm = new System.Windows.Forms.Panel();
            this.btnMenuRefresh = new System.Windows.Forms.Button();
            this.pnlFavorites = new System.Windows.Forms.Panel();
            this.tvFavorites = new System.Windows.Forms.TreeView();
            this.pnlFavoritesBtm = new System.Windows.Forms.Panel();
            this.btnFavoritesRefresh = new System.Windows.Forms.Button();
            this.tolMain = new System.Windows.Forms.ToolStrip();
            this.mnuMain = new System.Windows.Forms.MenuStrip();
            this.tsmTopSystem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmLogout = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmChangePassword = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmMenuWindow = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmFavorites = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmClientUpgrade = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmOption = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmExit = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmTopWindows = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmTabbedMdi = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmCloseAll = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmTopHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.udmMain = new Infragistics.Win.UltraWinDock.UltraDockManager(this.components);
            this._frmMDIMainCoreUnpinnedTabAreaLeft = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainCoreUnpinnedTabAreaRight = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainCoreUnpinnedTabAreaTop = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainCoreUnpinnedTabAreaBottom = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainCoreAutoHideControl = new Infragistics.Win.UltraWinDock.AutoHideControl();
            this.dockableWindow1 = new Infragistics.Win.UltraWinDock.DockableWindow();
            this.dockableWindow2 = new Infragistics.Win.UltraWinDock.DockableWindow();
            this.windowDockingArea1 = new Infragistics.Win.UltraWinDock.WindowDockingArea();
            this.windowDockingArea2 = new Infragistics.Win.UltraWinDock.WindowDockingArea();
            this.utmMain = new Infragistics.Win.UltraWinTabbedMdi.UltraTabbedMdiManager(this.components);
            this.pnlMenu.SuspendLayout();
            this.pnlMenuBtm.SuspendLayout();
            this.pnlFavorites.SuspendLayout();
            this.pnlFavoritesBtm.SuspendLayout();
            this.mnuMain.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.udmMain)).BeginInit();
            this._frmMDIMainCoreAutoHideControl.SuspendLayout();
            this.dockableWindow1.SuspendLayout();
            this.dockableWindow2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.utmMain)).BeginInit();
            this.SuspendLayout();
            // 
            // pgbMain
            // 
            this.pgbMain.Location = new System.Drawing.Point(2, 600);
            this.pgbMain.Value = 100;
            // 
            // pnlMenu
            // 
            this.pnlMenu.Controls.Add(this.tvMenu);
            this.pnlMenu.Controls.Add(this.pnlMenuBtm);
            this.pnlMenu.Location = new System.Drawing.Point(0, 18);
            this.pnlMenu.Name = "pnlMenu";
            this.pnlMenu.Size = new System.Drawing.Size(200, 529);
            this.pnlMenu.TabIndex = 63;
            // 
            // tvMenu
            // 
            this.tvMenu.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tvMenu.Location = new System.Drawing.Point(0, 0);
            this.tvMenu.Name = "tvMenu";
            this.tvMenu.Size = new System.Drawing.Size(200, 499);
            this.tvMenu.TabIndex = 3;
            this.tvMenu.Enter += new System.EventHandler(this.tvMenu_Enter);
            this.tvMenu.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tvMenu_AfterSelect);
            this.tvMenu.Click += new System.EventHandler(this.tvMenu_Click);
            // 
            // pnlMenuBtm
            // 
            this.pnlMenuBtm.Controls.Add(this.btnMenuRefresh);
            this.pnlMenuBtm.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlMenuBtm.Location = new System.Drawing.Point(0, 499);
            this.pnlMenuBtm.Name = "pnlMenuBtm";
            this.pnlMenuBtm.Size = new System.Drawing.Size(200, 30);
            this.pnlMenuBtm.TabIndex = 2;
            // 
            // btnMenuRefresh
            // 
            this.btnMenuRefresh.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMenuRefresh.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnMenuRefresh.Image = ((System.Drawing.Image)(resources.GetObject("btnMenuRefresh.Image")));
            this.btnMenuRefresh.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.btnMenuRefresh.Location = new System.Drawing.Point(173, 3);
            this.btnMenuRefresh.Name = "btnMenuRefresh";
            this.btnMenuRefresh.Size = new System.Drawing.Size(24, 24);
            this.btnMenuRefresh.TabIndex = 4;
            this.btnMenuRefresh.Click += new System.EventHandler(this.btnMenuRefresh_Click);
            // 
            // pnlFavorites
            // 
            this.pnlFavorites.Controls.Add(this.tvFavorites);
            this.pnlFavorites.Controls.Add(this.pnlFavoritesBtm);
            this.pnlFavorites.Location = new System.Drawing.Point(0, 18);
            this.pnlFavorites.Name = "pnlFavorites";
            this.pnlFavorites.Size = new System.Drawing.Size(200, 529);
            this.pnlFavorites.TabIndex = 65;
            // 
            // tvFavorites
            // 
            this.tvFavorites.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tvFavorites.Location = new System.Drawing.Point(0, 0);
            this.tvFavorites.Name = "tvFavorites";
            this.tvFavorites.Size = new System.Drawing.Size(200, 499);
            this.tvFavorites.TabIndex = 0;
            this.tvFavorites.Enter += new System.EventHandler(this.tvFavorites_Enter);
            this.tvFavorites.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tvFavorites_AfterSelect);
            this.tvFavorites.Click += new System.EventHandler(this.tvFavorites_Click);
            // 
            // pnlFavoritesBtm
            // 
            this.pnlFavoritesBtm.Controls.Add(this.btnFavoritesRefresh);
            this.pnlFavoritesBtm.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlFavoritesBtm.Location = new System.Drawing.Point(0, 499);
            this.pnlFavoritesBtm.Name = "pnlFavoritesBtm";
            this.pnlFavoritesBtm.Size = new System.Drawing.Size(200, 30);
            this.pnlFavoritesBtm.TabIndex = 2;
            // 
            // btnFavoritesRefresh
            // 
            this.btnFavoritesRefresh.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.btnFavoritesRefresh.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnFavoritesRefresh.Image = ((System.Drawing.Image)(resources.GetObject("btnFavoritesRefresh.Image")));
            this.btnFavoritesRefresh.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.btnFavoritesRefresh.Location = new System.Drawing.Point(173, 3);
            this.btnFavoritesRefresh.Name = "btnFavoritesRefresh";
            this.btnFavoritesRefresh.Size = new System.Drawing.Size(24, 24);
            this.btnFavoritesRefresh.TabIndex = 4;
            this.btnFavoritesRefresh.Click += new System.EventHandler(this.btnFavoritesRefresh_Click);
            // 
            // tolMain
            // 
            this.tolMain.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.tolMain.Location = new System.Drawing.Point(0, 24);
            this.tolMain.Name = "tolMain";
            this.tolMain.Size = new System.Drawing.Size(892, 25);
            this.tolMain.TabIndex = 57;
            // 
            // mnuMain
            // 
            this.mnuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmTopSystem,
            this.tsmTopWindows,
            this.tsmTopHelp});
            this.mnuMain.Location = new System.Drawing.Point(0, 0);
            this.mnuMain.MdiWindowListItem = this.tsmTopWindows;
            this.mnuMain.Name = "mnuMain";
            this.mnuMain.ShowItemToolTips = true;
            this.mnuMain.Size = new System.Drawing.Size(892, 24);
            this.mnuMain.TabIndex = 56;
            // 
            // tsmTopSystem
            // 
            this.tsmTopSystem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmLogout,
            this.tsmChangePassword,
            this.tsmMenuWindow,
            this.toolStripSeparator1,
            this.tsmClientUpgrade,
            this.tsmOption,
            this.toolStripSeparator2,
            this.tsmExit});
            this.tsmTopSystem.Name = "tsmTopSystem";
            this.tsmTopSystem.Size = new System.Drawing.Size(57, 20);
            this.tsmTopSystem.Text = "System";
            // 
            // tsmLogout
            // 
            this.tsmLogout.Name = "tsmLogout";
            this.tsmLogout.ShortcutKeys = System.Windows.Forms.Keys.F2;
            this.tsmLogout.Size = new System.Drawing.Size(168, 22);
            this.tsmLogout.Text = "Log Out";
            this.tsmLogout.Click += new System.EventHandler(this.tsmLogout_Click);
            // 
            // tsmChangePassword
            // 
            this.tsmChangePassword.Name = "tsmChangePassword";
            this.tsmChangePassword.Size = new System.Drawing.Size(168, 22);
            this.tsmChangePassword.Text = "Change Password";
            this.tsmChangePassword.Click += new System.EventHandler(this.tsmChangePassword_Click);
            // 
            // tsmMenuWindow
            // 
            this.tsmMenuWindow.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmMenu,
            this.tsmFavorites});
            this.tsmMenuWindow.Name = "tsmMenuWindow";
            this.tsmMenuWindow.Size = new System.Drawing.Size(168, 22);
            this.tsmMenuWindow.Text = "Menu Window";
            // 
            // tsmMenu
            // 
            this.tsmMenu.Name = "tsmMenu";
            this.tsmMenu.Size = new System.Drawing.Size(121, 22);
            this.tsmMenu.Text = "Menu";
            this.tsmMenu.Click += new System.EventHandler(this.tsmMenu_Click);
            // 
            // tsmFavorites
            // 
            this.tsmFavorites.Name = "tsmFavorites";
            this.tsmFavorites.Size = new System.Drawing.Size(121, 22);
            this.tsmFavorites.Text = "Favorites";
            this.tsmFavorites.Click += new System.EventHandler(this.tsmFavorites_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(165, 6);
            // 
            // tsmClientUpgrade
            // 
            this.tsmClientUpgrade.Name = "tsmClientUpgrade";
            this.tsmClientUpgrade.Size = new System.Drawing.Size(168, 22);
            this.tsmClientUpgrade.Text = "Client Upgrade";
            this.tsmClientUpgrade.Click += new System.EventHandler(this.tsmClientUpgrade_Click);
            // 
            // tsmOption
            // 
            this.tsmOption.Name = "tsmOption";
            this.tsmOption.Size = new System.Drawing.Size(168, 22);
            this.tsmOption.Text = "Option";
            this.tsmOption.Click += new System.EventHandler(this.tsmOption_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(165, 6);
            // 
            // tsmExit
            // 
            this.tsmExit.Name = "tsmExit";
            this.tsmExit.Size = new System.Drawing.Size(168, 22);
            this.tsmExit.Text = "Exit";
            this.tsmExit.Click += new System.EventHandler(this.tsmExit_Click);
            // 
            // tsmTopWindows
            // 
            this.tsmTopWindows.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmTabbedMdi,
            this.tsmCloseAll,
            this.toolStripSeparator4});
            this.tsmTopWindows.Name = "tsmTopWindows";
            this.tsmTopWindows.Size = new System.Drawing.Size(68, 20);
            this.tsmTopWindows.Text = "Windows";
            // 
            // tsmTabbedMdi
            // 
            this.tsmTabbedMdi.Name = "tsmTabbedMdi";
            this.tsmTabbedMdi.Size = new System.Drawing.Size(139, 22);
            this.tsmTabbedMdi.Text = "Tabbed MDI";
            this.tsmTabbedMdi.Click += new System.EventHandler(this.tsmTabbedMdi_Click);
            // 
            // tsmCloseAll
            // 
            this.tsmCloseAll.Name = "tsmCloseAll";
            this.tsmCloseAll.Size = new System.Drawing.Size(139, 22);
            this.tsmCloseAll.Text = "Close All";
            this.tsmCloseAll.Click += new System.EventHandler(this.tsmCloseAll_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(136, 6);
            // 
            // tsmTopHelp
            // 
            this.tsmTopHelp.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmHelp,
            this.toolStripSeparator3,
            this.tsmAbout});
            this.tsmTopHelp.Name = "tsmTopHelp";
            this.tsmTopHelp.Size = new System.Drawing.Size(44, 20);
            this.tsmTopHelp.Text = "Help";
            // 
            // tsmHelp
            // 
            this.tsmHelp.Name = "tsmHelp";
            this.tsmHelp.ShortcutKeys = System.Windows.Forms.Keys.F1;
            this.tsmHelp.Size = new System.Drawing.Size(118, 22);
            this.tsmHelp.Text = "Help";
            this.tsmHelp.Click += new System.EventHandler(this.tsmHelp_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(115, 6);
            // 
            // tsmAbout
            // 
            this.tsmAbout.Name = "tsmAbout";
            this.tsmAbout.Size = new System.Drawing.Size(118, 22);
            this.tsmAbout.Text = "About";
            this.tsmAbout.Click += new System.EventHandler(this.tsmAbout_Click);
            // 
            // udmMain
            // 
            appearance1.Image = 52;
            appearance2.Image = 66;
            appearance3.Image = 18;
            appearance4.Image = 22;
            appearance5.Image = 50;
            appearance6.Image = 98;
            this.udmMain.Appearances.Add(appearance1);
            this.udmMain.Appearances.Add(appearance2);
            this.udmMain.Appearances.Add(appearance3);
            this.udmMain.Appearances.Add(appearance4);
            this.udmMain.Appearances.Add(appearance5);
            this.udmMain.Appearances.Add(appearance6);
            this.udmMain.AutoHideDelay = 0;
            dockAreaPane1.DockedBefore = new System.Guid("e7fb2ed4-932d-4dd8-bda0-93ee6e6c93cd");
            dockableControlPane1.Control = this.pnlMenu;
            dockableControlPane1.FlyoutSize = new System.Drawing.Size(200, -1);
            dockableControlPane1.Key = "SYS_MENU_MENU";
            dockableControlPane1.OriginalControlBounds = new System.Drawing.Rectangle(137, 88, 200, 546);
            dockableControlPane1.Pinned = false;
            dockableControlPane1.Settings.Appearance = new Infragistics.Win.LinkedAppearance(31103813);
            dockableControlPane1.Size = new System.Drawing.Size(100, 100);
            dockableControlPane1.Text = "Menu";
            dockAreaPane1.Panes.AddRange(new Infragistics.Win.UltraWinDock.DockablePaneBase[] {
            dockableControlPane1});
            dockAreaPane1.Size = new System.Drawing.Size(95, 665);
            dockableControlPane2.Control = this.pnlFavorites;
            dockableControlPane2.FlyoutSize = new System.Drawing.Size(200, -1);
            dockableControlPane2.Key = "SYS_MENU_FAVORITES";
            dockableControlPane2.OriginalControlBounds = new System.Drawing.Rectangle(336, 85, 200, 546);
            dockableControlPane2.Pinned = false;
            dockableControlPane2.Settings.Appearance = new Infragistics.Win.LinkedAppearance(31170157);
            dockableControlPane2.Size = new System.Drawing.Size(100, 100);
            dockableControlPane2.Text = "Favorites";
            dockAreaPane2.Panes.AddRange(new Infragistics.Win.UltraWinDock.DockablePaneBase[] {
            dockableControlPane2});
            dockAreaPane2.Size = new System.Drawing.Size(95, 665);
            this.udmMain.DockAreas.AddRange(new Infragistics.Win.UltraWinDock.DockAreaPane[] {
            dockAreaPane1,
            dockAreaPane2});
            this.udmMain.HostControl = this;
            this.udmMain.ImageList = this.imlSmallIcon;
            // 
            // _frmMDIMainCoreUnpinnedTabAreaLeft
            // 
            this._frmMDIMainCoreUnpinnedTabAreaLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this._frmMDIMainCoreUnpinnedTabAreaLeft.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainCoreUnpinnedTabAreaLeft.Location = new System.Drawing.Point(0, 49);
            this._frmMDIMainCoreUnpinnedTabAreaLeft.Name = "_frmMDIMainCoreUnpinnedTabAreaLeft";
            this._frmMDIMainCoreUnpinnedTabAreaLeft.Owner = this.udmMain;
            this._frmMDIMainCoreUnpinnedTabAreaLeft.Size = new System.Drawing.Size(21, 547);
            this._frmMDIMainCoreUnpinnedTabAreaLeft.TabIndex = 58;
            // 
            // _frmMDIMainCoreUnpinnedTabAreaRight
            // 
            this._frmMDIMainCoreUnpinnedTabAreaRight.Dock = System.Windows.Forms.DockStyle.Right;
            this._frmMDIMainCoreUnpinnedTabAreaRight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainCoreUnpinnedTabAreaRight.Location = new System.Drawing.Point(892, 49);
            this._frmMDIMainCoreUnpinnedTabAreaRight.Name = "_frmMDIMainCoreUnpinnedTabAreaRight";
            this._frmMDIMainCoreUnpinnedTabAreaRight.Owner = this.udmMain;
            this._frmMDIMainCoreUnpinnedTabAreaRight.Size = new System.Drawing.Size(0, 547);
            this._frmMDIMainCoreUnpinnedTabAreaRight.TabIndex = 59;
            // 
            // _frmMDIMainCoreUnpinnedTabAreaTop
            // 
            this._frmMDIMainCoreUnpinnedTabAreaTop.Dock = System.Windows.Forms.DockStyle.Top;
            this._frmMDIMainCoreUnpinnedTabAreaTop.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainCoreUnpinnedTabAreaTop.Location = new System.Drawing.Point(21, 49);
            this._frmMDIMainCoreUnpinnedTabAreaTop.Name = "_frmMDIMainCoreUnpinnedTabAreaTop";
            this._frmMDIMainCoreUnpinnedTabAreaTop.Owner = this.udmMain;
            this._frmMDIMainCoreUnpinnedTabAreaTop.Size = new System.Drawing.Size(871, 0);
            this._frmMDIMainCoreUnpinnedTabAreaTop.TabIndex = 60;
            // 
            // _frmMDIMainCoreUnpinnedTabAreaBottom
            // 
            this._frmMDIMainCoreUnpinnedTabAreaBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this._frmMDIMainCoreUnpinnedTabAreaBottom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainCoreUnpinnedTabAreaBottom.Location = new System.Drawing.Point(21, 596);
            this._frmMDIMainCoreUnpinnedTabAreaBottom.Name = "_frmMDIMainCoreUnpinnedTabAreaBottom";
            this._frmMDIMainCoreUnpinnedTabAreaBottom.Owner = this.udmMain;
            this._frmMDIMainCoreUnpinnedTabAreaBottom.Size = new System.Drawing.Size(871, 0);
            this._frmMDIMainCoreUnpinnedTabAreaBottom.TabIndex = 61;
            // 
            // _frmMDIMainCoreAutoHideControl
            // 
            this._frmMDIMainCoreAutoHideControl.Controls.Add(this.dockableWindow1);
            this._frmMDIMainCoreAutoHideControl.Controls.Add(this.dockableWindow2);
            this._frmMDIMainCoreAutoHideControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainCoreAutoHideControl.Location = new System.Drawing.Point(21, 49);
            this._frmMDIMainCoreAutoHideControl.Name = "_frmMDIMainCoreAutoHideControl";
            this._frmMDIMainCoreAutoHideControl.Owner = this.udmMain;
            this._frmMDIMainCoreAutoHideControl.Size = new System.Drawing.Size(15, 547);
            this._frmMDIMainCoreAutoHideControl.TabIndex = 62;
            // 
            // dockableWindow1
            // 
            this.dockableWindow1.Controls.Add(this.pnlMenu);
            this.dockableWindow1.Location = new System.Drawing.Point(-10000, 0);
            this.dockableWindow1.Name = "dockableWindow1";
            this.dockableWindow1.Owner = this.udmMain;
            this.dockableWindow1.Size = new System.Drawing.Size(200, 547);
            this.dockableWindow1.TabIndex = 67;
            // 
            // dockableWindow2
            // 
            this.dockableWindow2.Controls.Add(this.pnlFavorites);
            this.dockableWindow2.Location = new System.Drawing.Point(-10000, 0);
            this.dockableWindow2.Name = "dockableWindow2";
            this.dockableWindow2.Owner = this.udmMain;
            this.dockableWindow2.Size = new System.Drawing.Size(200, 547);
            this.dockableWindow2.TabIndex = 68;
            // 
            // windowDockingArea1
            // 
            this.windowDockingArea1.Dock = System.Windows.Forms.DockStyle.Left;
            this.windowDockingArea1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.windowDockingArea1.Location = new System.Drawing.Point(21, 49);
            this.windowDockingArea1.Name = "windowDockingArea1";
            this.windowDockingArea1.Owner = this.udmMain;
            this.windowDockingArea1.Size = new System.Drawing.Size(100, 665);
            this.windowDockingArea1.TabIndex = 64;
            // 
            // windowDockingArea2
            // 
            this.windowDockingArea2.Dock = System.Windows.Forms.DockStyle.Left;
            this.windowDockingArea2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.windowDockingArea2.Location = new System.Drawing.Point(21, 49);
            this.windowDockingArea2.Name = "windowDockingArea2";
            this.windowDockingArea2.Owner = this.udmMain;
            this.windowDockingArea2.Size = new System.Drawing.Size(100, 665);
            this.windowDockingArea2.TabIndex = 66;
            // 
            // utmMain
            // 
            this.utmMain.Enabled = false;
            this.utmMain.MdiParent = this;
            this.utmMain.UseMnemonics = true;
            this.utmMain.ViewStyle = Infragistics.Win.UltraWinTabbedMdi.ViewStyle.VisualStudio2005;
            // 
            // frmMDIMain
            // 
            this.ClientSize = new System.Drawing.Size(892, 616);
            this.Controls.Add(this._frmMDIMainCoreAutoHideControl);
            this.Controls.Add(this.windowDockingArea1);
            this.Controls.Add(this.windowDockingArea2);
            this.Controls.Add(this._frmMDIMainCoreUnpinnedTabAreaTop);
            this.Controls.Add(this._frmMDIMainCoreUnpinnedTabAreaBottom);
            this.Controls.Add(this._frmMDIMainCoreUnpinnedTabAreaRight);
            this.Controls.Add(this._frmMDIMainCoreUnpinnedTabAreaLeft);
            this.Controls.Add(this.tolMain);
            this.Controls.Add(this.mnuMain);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.mnuMain;
            this.Name = "frmMDIMain";
            this.Text = "MESplus AdminClient 5";
            this.Load += new System.EventHandler(this.frmMDIMain_Load);
            this.Activated += new System.EventHandler(this.frmMDIMain_Activated);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmMDIMain_FormClosing);
            this.Controls.SetChildIndex(this.mnuMain, 0);
            this.Controls.SetChildIndex(this.tolMain, 0);
            this.Controls.SetChildIndex(this._frmMDIMainCoreUnpinnedTabAreaLeft, 0);
            this.Controls.SetChildIndex(this._frmMDIMainCoreUnpinnedTabAreaRight, 0);
            this.Controls.SetChildIndex(this._frmMDIMainCoreUnpinnedTabAreaBottom, 0);
            this.Controls.SetChildIndex(this._frmMDIMainCoreUnpinnedTabAreaTop, 0);
            this.Controls.SetChildIndex(this.windowDockingArea2, 0);
            this.Controls.SetChildIndex(this.windowDockingArea1, 0);
            this.Controls.SetChildIndex(this.pgbMain, 0);
            this.Controls.SetChildIndex(this._frmMDIMainCoreAutoHideControl, 0);
            this.pnlMenu.ResumeLayout(false);
            this.pnlMenuBtm.ResumeLayout(false);
            this.pnlFavorites.ResumeLayout(false);
            this.pnlFavoritesBtm.ResumeLayout(false);
            this.mnuMain.ResumeLayout(false);
            this.mnuMain.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.udmMain)).EndInit();
            this._frmMDIMainCoreAutoHideControl.ResumeLayout(false);
            this.dockableWindow1.ResumeLayout(false);
            this.dockableWindow2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.utmMain)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip tolMain;
        private System.Windows.Forms.MenuStrip mnuMain;
        private System.Windows.Forms.ToolStripMenuItem tsmTopSystem;
        private System.Windows.Forms.ToolStripMenuItem tsmLogout;
        private System.Windows.Forms.ToolStripMenuItem tsmChangePassword;
        private System.Windows.Forms.ToolStripMenuItem tsmMenuWindow;
        private System.Windows.Forms.ToolStripMenuItem tsmMenu;
        private System.Windows.Forms.ToolStripMenuItem tsmFavorites;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem tsmClientUpgrade;
        private System.Windows.Forms.ToolStripMenuItem tsmOption;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem tsmExit;
        private System.Windows.Forms.ToolStripMenuItem tsmTopWindows;
        private System.Windows.Forms.ToolStripMenuItem tsmCloseAll;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripMenuItem tsmTopHelp;
        private System.Windows.Forms.ToolStripMenuItem tsmHelp;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem tsmAbout;
        private Infragistics.Win.UltraWinDock.UltraDockManager udmMain;
        private Infragistics.Win.UltraWinDock.AutoHideControl _frmMDIMainCoreAutoHideControl;
        private Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainCoreUnpinnedTabAreaTop;
        private Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainCoreUnpinnedTabAreaBottom;
        private Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainCoreUnpinnedTabAreaLeft;
        private Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainCoreUnpinnedTabAreaRight;
        private System.Windows.Forms.Panel pnlMenu;
        private System.Windows.Forms.Panel pnlMenuBtm;
        private System.Windows.Forms.Button btnMenuRefresh;
        private Infragistics.Win.UltraWinDock.DockableWindow dockableWindow1;
        private Infragistics.Win.UltraWinDock.WindowDockingArea windowDockingArea1;
        private System.Windows.Forms.TreeView tvMenu;
        private System.Windows.Forms.Panel pnlFavorites;
        private System.Windows.Forms.TreeView tvFavorites;
        private System.Windows.Forms.Panel pnlFavoritesBtm;
        private System.Windows.Forms.Button btnFavoritesRefresh;
        private Infragistics.Win.UltraWinDock.DockableWindow dockableWindow2;
        private Infragistics.Win.UltraWinDock.WindowDockingArea windowDockingArea2;
        private Infragistics.Win.UltraWinTabbedMdi.UltraTabbedMdiManager utmMain;
        private System.Windows.Forms.ToolStripMenuItem tsmTabbedMdi;
    }
}
