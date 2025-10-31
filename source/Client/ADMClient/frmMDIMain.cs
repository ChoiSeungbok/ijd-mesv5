using System;
using System.Data;
using System.Text;
using System.Drawing;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;
using System.Diagnostics;
using Microsoft.Win32;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.UTLCore;
using Infragistics.Win.UltraWinDock;

namespace ADMINClient
{
    public partial class frmMDIMain : frmMDIMainCore, intMdiFormFunction
    {
        public frmMDIMain()
        {
            InitializeComponent();
        }

        #region " Constant Definition "

        #endregion

        #region " Variable Definition "

        private bool b_load_flag = false;

        #endregion

        #region " Form Event Definition"

        private void frmMDIMain_Load(System.Object sender, System.EventArgs e)
        {
            m_ImgBackPic = (new frmMDIBackPic()).pbxBackImage.Image;

            //Set Size & Location of MDI Form

            this.Top = 0;
            this.Left = 0;
            this.Width = 0;
            this.Height = 0;

            if (LoadResource() == false)
            {
                return;
            }

            //Added by LAVERWON (2006/07/07)
            //Request Reply Retry Wait Time
            MPGV.giRequestReplyWaitTime = 30;

            //Add by J.S. 2011.10.27 for load TAB MDI
            if (MPCF.GetRegSetting(Application.ProductName, "Option", "TabbedMdi", "false") == "true")
            {
                tsmTabbedMdi.Checked = true;
                utmMain.Enabled = true;
            }
            else
            {
                tsmTabbedMdi.Checked = false;
                utmMain.Enabled = false;
            }
        }

        private void frmMDIMain_Activated(object sender, System.EventArgs e)
        {
            if (b_load_flag == false)
            {
                this.Hide();

                //Set Size & Location of MDI Form

                this.Top = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_top", "0"));
                this.Left = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_left", "0"));
                this.Width = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_width", "1024"));
                this.Height = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_height", "768"));

                // 주의사항!
                // login이 Dispose되면서 Activated 이벤트가 다시 호출되므로 b_load_flag는 
                // 반드시 login 화면이 Display 되기 전에 셋팅 되어야 한다.
                b_load_flag = true;

                if (MPCF.GetRegSetting(Application.ProductName, "Option", "BackGroundLogin", "N") == "Y")
                {
                    bool UpgradeFlag = false;

                    if (MPCF.GetRegSetting(Application.ProductName, "Option", "BackGroundLogin", "") != "")
                        MPCF.DeleteRegSetting(Application.ProductName, "Option", "BackGroundLogin");

                    // 다운로드 파일명, 업그레이드 파일명, 클라이언트 버전을 얻기 위해서 frmLogin을 Load 시킴. 화면에는 보이지 않게 함. 
                    frmLogin login = new frmLogin();
                    login.Width = 0;
                    login.Height = 0;
                    login.Show();
                    login.Dispose();

                    MPGV.gsPassword = MPCF.GetRegSetting(Application.ProductName, "Settings", "Password", "");

                    if (MPIF.gInit.InitMsgHandler() == false)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(104));
                        MPGV.gbLogoutFlag = true;

                        Close();
                        Application.Exit();
                        return;
                    }

                    if (MPCR.SEC_Login_Ext(ref UpgradeFlag) == false)
                    {
                        MPGV.gbLogoutFlag = true;
                        
                        MPIF.gInit.TermMsgHandler();
                        Close();
                        Application.Exit();
                        return;
                    }

                    if (UpgradeFlag == true)
                    {
                        // 업그레이드시에 자동으로 로그인 하도록 설정하기 위해서
                        MPCF.SaveRegSetting(Application.ProductName, "Option", "BackGroundLogin", "Y");
                        MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", MPGV.gsSiteID);
                        MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", MPGV.gsRemoteAddress);
                        MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", MPGV.gsFactory);
                        MPCF.SaveRegSetting(Application.ProductName, "Settings", "UserName", MPGV.gsUserID);
                        MPCF.SaveRegSetting(Application.ProductName, "Settings", "Password", MPGV.gsPassword);

                        MPGV.gbLogoutFlag = true;

                        Close();
                        Application.Exit();
                        return;
                    }

                }
                else
                {

                    frmLogin login = new frmLogin();
                    if (login.ShowDialog(this) == System.Windows.Forms.DialogResult.Cancel)
                    {
                        b_load_flag = true;
                        MPGV.gbLogoutFlag = true;

                        Close();
                        Application.Exit();
                        return;
                    }
                    login.Dispose();
                }

                this.TopMost = true;
                this.Show();
                this.TopMost = false;


                if (MPCF.GetRegSetting(Application.ProductName, "Option", "BackGroundLogin", "") != "")
                    MPCF.DeleteRegSetting(Application.ProductName, "Option", "BackGroundLogin");

                if (MPCF.GetRegSetting(Application.ProductName, "Settings", "Password", "") != "")
                    MPCF.DeleteRegSetting(Application.ProductName, "Settings", "Password");

                if (MPGV.gcChangePassword == 'Y')
                {
                    Form f = new frmChangePassword();
                    if (f.ShowDialog() == System.Windows.Forms.DialogResult.Cancel)
                    {
                        b_load_flag = true;
                        MPGV.gbLogoutFlag = true;

                        f.Dispose();
                        this.Close();
                        Application.Exit();
                        return;
                    }
                    MPGV.gcChangePassword = ' ';
                    f.Dispose();
                }

                if (InitMainForm() == false) return;
            }

#if _TOOL
            if (this.ActiveMdiChild == null)
            {
            }
            else
            {
                if (this.ActiveMdiChild.Name == "frmRASTranToolEvent")
                {
                    frmRASTranToolEvent frmRASTranToolEvent = null;
                    frmRASTranToolEvent = (frmRASTranToolEvent)this.ActiveMdiChild;

                    frmRASTranToolEvent.bRunning = true;
                    frmRASTranToolEvent.DrawDefectMap();

                    frmRASTranToolEvent.bRunningClean = true;
                    frmRASTranToolEvent.DrawDefectMapClean();

                }
            }
#endif

            clsTaskMan.InitialTaskManFunction();

        }

        private void frmMDIMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult dResult = DialogResult.None;
            if (MPGV.gbLogoutFlag == false)
            {
                dResult = MPCF.ShowMsgBox(MPCF.GetMessage(4), Application.ProductName, MessageBoxButtons.YesNo, 2);
                if (dResult == DialogResult.No || dResult == DialogResult.Cancel)
                {
                    e.Cancel = true;
                    return;
                }
            }

            SaveSystemMenu();

            if (this.WindowState != FormWindowState.Minimized)
            {
                MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_top", this.Top.ToString());
                MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_left", this.Left.ToString());
                MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_width", this.Width.ToString());
                MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_height", this.Height.ToString());
            }

            //Add by J.S. 2011.10.27 for save TAB MDI
            if (utmMain.Enabled == true)
            {
                MPCF.SaveRegSetting(Application.ProductName, "Option", "TabbedMdi", "true");
            }
            else
            {
                MPCF.SaveRegSetting(Application.ProductName, "Option", "TabbedMdi", "false");
            }
        }

        #endregion

        #region "Default Menu Event Definition"

        private void tsmLogout_Click(object sender, EventArgs e)
        {
            DialogResult dResult;

            MPGV.gbLogoutFlag = true;

            dResult = MPCF.ShowMsgBox(MPCF.GetMessage(13), Application.ProductName, MessageBoxButtons.YesNo, 2);
            if (dResult == DialogResult.No || dResult == DialogResult.Cancel)
            {
                MPGV.gbLogoutFlag = false;
                return;
            }

            this.Close();
            Application.Exit();

            Process.Start(Application.ExecutablePath);
            MPGV.gbLogoutFlag = false;
        }

        private void tsmChangePassword_Click(object sender, EventArgs e)
        {
            frmChangePassword f = new frmChangePassword();
            f.ShowDialog();
            f.Dispose();
        }

        private void tsmClientUpgrade_Click(object sender, EventArgs e)
        {
            if (MPCF.ShowMsgBox(MPCF.GetMessage(11), Application.ProductName, MessageBoxButtons.YesNo, 1) == System.Windows.Forms.DialogResult.No)
            {
                return;
            }

            if (MPCR.Client_Upgrade(2) == 1)
            {
                MPGV.gbLogoutFlag = true;
                this.Close();
                Application.Exit();
            }
        }

        private void tsmOption_Click(object sender, EventArgs e)
        {
            frmOptionCore f = new frmOptionCore(true);
            f.ShowDialog();
            f.Dispose();
        }

        private void tsmExit_Click(object sender, EventArgs e)
        {
            this.Close();
            Application.Exit();
        }

        private void tsmTabbedMdi_Click(object sender, EventArgs e)
        {
            if (tsmTabbedMdi.Checked == true)
                tsmTabbedMdi.Checked = false;
            else
                tsmTabbedMdi.Checked = true;

            utmMain.Enabled = tsmTabbedMdi.Checked;
        }

        private void tsmCloseAll_Click(object sender, EventArgs e)
        {
            foreach (Form f in this.MdiChildren)
            {
                f.Close();
                f.Dispose();
            }
        }

        private void tsmHelp_Click(object sender, EventArgs e)
        {
            //GetHelpURL()
            //Shell("explorer.exe http://61.106.159.83/MESplus_V32/wwhelp.htm")
        }

        private void tsmAbout_Click(object sender, EventArgs e)
        {
            frmAbout f = new frmAbout();
            f.ShowDialog();
            f.Dispose();
        }

        private void tsmMenu_Click(object sender, EventArgs e)
        {
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_MENU].Closed = false;
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_MENU].Activate();
        }

        private void tsmFavorites_Click(object sender, EventArgs e)
        {
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_FAVORITES].Closed = false;
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_FAVORITES].Activate();
        }

        private void tsmOperation_Click(object sender, EventArgs e)
        {
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_OPERATION].Closed = false;
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_OPERATION].Activate();
        }

        private void tsmResource_Click(object sender, EventArgs e)
        {
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_RESOURCE].Closed = false;
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_RESOURCE].Activate();
        }

        private void tsmDispatcher_Click(object sender, EventArgs e)
        {
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_DISPATCHER].Closed = false;
            udmMain.ControlPanes[MPGC.MP_SYS_DOCK_DISPATCHER].Activate();
        }

        #endregion

        #region " Function Definition "

        // InitMainForm()
        //       - Initialize Main Form
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //		-
        //
        protected override bool InitMainForm()
        {
            try
            {
                if (base.InitMainForm() == false) return false;
                if (GetAvailableFunctionList(mnuMain, 1, tolMain) == false) return false;

                SetFavoriteMenu();
                LoadSystemMenu();
                ChangeMenuText(mnuMain);
                ChangeDockText();
                SetDockingMenu();

                if (base.InitMainFormAfter() == false) return false;

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.InitMainForm()\n" + ex.Message);
                return false;
            }
        }

        public void FavoritesRefresh()
        {
            try
            {
                if (b_can_get_favorites == false) return;

                // 즐겨찾기 메뉴를 다시 그리고
                SetFavoriteMenu();

                // 즐겨찾기 트리를 다시 그린다.
                MPCF.InitTreeView(tvFavorites);
                SetFavoritesTree();

                //2008.12.16 Add by J.S. for Refresh Toolbar
                ViewFavoritesList(tolMain);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Add by J.S. 2009.01.07 refresh main menu after menu setup
        public void MenuRefresh()
        {
            int i_menu_count;

            try
            {
                i_menu_count = mnuMain.Items.Count;
                for (int i = 0; i < i_menu_count; i++)
                {
                    if (mnuMain.Items.Count > 3)
                    {
                        foreach (ToolStripMenuItem menu in mnuMain.Items)
                        {
                            if (MPCF.RTrim(menu.Tag) != "")
                            {
                                mnuMain.Items.Remove(menu);
                                break;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (GetAvailableFunctionList(mnuMain, 1, tolMain) == false)
                {
                    return;
                }

                // Menu Tree를 다시 그린다.
                MPCF.InitTreeView(tvMenu);
                SetMenuTree();
                SetFavoriteMenu();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        public Control ActiveMenu(MenuInfoTag m_menu_tag)
        {
            return ExecuteMenu(m_menu_tag);
        }

        public void ActiveMenu(string s_func_name)
        {
            ToolStripMenuItem m_find_menu;

            try
            {
                if (MPCF.Trim(s_func_name) == "") return;

                m_find_menu = null;
                foreach (ToolStripMenuItem menu in mnuMain.Items)
                {
                    if (menu.Tag == null) continue;

                    m_find_menu = null;
                    m_find_menu = FindMenuItem(s_func_name, menu);
                    if (m_find_menu != null)
                        break;
                }

                if (m_find_menu != null)
                    m_find_menu.PerformClick();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private ToolStripMenuItem FindMenuItem(string s_func_name, ToolStripMenuItem menu)
        {
            MenuInfoTag m_menu_tag;
            ToolStripMenuItem m_menu_item;
            ToolStripMenuItem m_find_menu;
            int i;

            try
            {
                if (menu.Tag != null)
                {
                    m_menu_tag = (MenuInfoTag)menu.Tag;
                    if (!(m_menu_tag.Equals(null)))
                        if (MPCF.Trim(m_menu_tag.s_assembly_name) != "")
                            if (MPCF.Trim(m_menu_tag.s_func_name) == s_func_name)
                                return menu;
                }

                m_find_menu = null;
                for (i = 0; i < menu.DropDownItems.Count; i++)
                {
                    if (menu.DropDownItems[i] is ToolStripMenuItem)
                    {
                        m_menu_item = (ToolStripMenuItem)menu.DropDownItems[i];

                        m_find_menu = null;
                        m_find_menu = FindMenuItem(s_func_name, m_menu_item);
                        if (m_find_menu != null)
                            break;
                    }
                }

                return m_find_menu;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return null;
            }
        }
        
        private bool SetDockingMenu()
        {

            try
            {
                MPCF.InitTreeView(tvMenu);
                MPCF.InitTreeView(tvFavorites);

                SetDockingTree();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("SetDockingMenu() is Failed.\n" + ex.Message);
                return false;
            }

            return true;

        }

        private bool LoadSystemMenu()
        {

            string filename = "SystemMenu.bin";
            System.IO.FileStream stream = null;

            try
            {
                // Keep docking Menu text 
                foreach (DockableControlPane DockPan in udmMain.ControlPanes)
                    DockPan.Tag = DockPan.Text;

                stream = new System.IO.FileStream(Application.StartupPath + "\\" + filename, System.IO.FileMode.Open, System.IO.FileAccess.Read, System.IO.FileShare.Read);
                udmMain.LoadFromBinary(stream);

            }
            catch (Exception)
            {
                return false;
            }
            finally
            {
                if (stream != null)
                {
                    stream.Close();
                }
            }

            return true;
        }

        private bool SaveSystemMenu()
        {

            string filename = "SystemMenu.bin";
            System.IO.FileStream stream = null;
            try
            {
                stream = new System.IO.FileStream(Application.StartupPath + "\\" + filename, System.IO.FileMode.OpenOrCreate, System.IO.FileAccess.ReadWrite, System.IO.FileShare.None);
                this.udmMain.SaveAsBinary(stream);

            }
            catch (Exception)
            {
                return false;
            }
            finally
            {
                if (stream != null)
                {
                    stream.Close();
                }
            }

            return true;
        }

        private void SetFavoriteMenu()
        {
            if (b_can_get_favorites == false) return;

            ListView lisTmp;
            MenuInfoTag m_menu_tag;
            ToolStripMenuItem favorite_top_menu;
            ToolStripMenuItem favorite_menu;

            if (MPGV.gTitleColor.IsEmpty == false)
                tolMain.BackColor = MPGV.gTitleColor;

            favorite_top_menu = null;
            foreach (ToolStripMenuItem top_menu in mnuMain.Items)
            {
                if (top_menu.Tag == null) continue;

                m_menu_tag = (MenuInfoTag)top_menu.Tag;
                if (m_menu_tag.s_func_name == "TOP0005")
                {
                    favorite_top_menu = top_menu;
                    break;
                }
            }
            if (favorite_top_menu == null) return;

            for (int i = 0; i < favorite_top_menu.DropDownItems.Count; i++)
            {
                if (!(favorite_top_menu.DropDownItems[i] is ToolStripMenuItem)) continue;

                favorite_menu = (ToolStripMenuItem)favorite_top_menu.DropDownItems[i];
                if (((MenuInfoTag)(favorite_menu.Tag)).s_func_name.IndexOf("FAV") < 0)
                {
                    favorite_top_menu.DropDownItems.Remove(favorite_menu);
                    i--;
                }
            }

            // 즐겨찾기 TOP메뉴에 하위 메뉴가 존재하고 마지막이 메뉴라면 구분선 추가
            if (favorite_top_menu.DropDownItems.Count > 0)
                if (favorite_top_menu.DropDownItems[favorite_top_menu.DropDownItems.Count - 1] is ToolStripMenuItem)
                    favorite_top_menu.DropDownItems.Add(new ToolStripSeparator());

            lisTmp = new ListView();
            lisTmp.View = View.Details;

            lisTmp.Columns.Add(new ColumnHeader());
            lisTmp.Columns.Add(new ColumnHeader());
            SECLIST.ViewFavoritesList(lisTmp, '1', MPGV.gsProgramID, null, "");

            foreach (ListViewItem lis in lisTmp.Items)
            {
                m_menu_tag = (MenuInfoTag)lis.Tag;

                favorite_menu = new ToolStripMenuItem();
                favorite_menu.Tag = m_menu_tag;
                favorite_menu.Text = lis.SubItems[1].Text;
                favorite_menu.Click += new EventHandler(ToolStripMenuItem_Click);
                favorite_top_menu.DropDownItems.Add(favorite_menu);
            }
        }

        private void ChangeDockText()
        {
            if (udmMain == null) return;
            foreach (DockableControlPane DockPan in udmMain.ControlPanes)
            {
                if (MPCF.Trim(DockPan.Tag) == "")
                {
                    if (DockPan.Key == MPGC.MP_SYS_DOCK_MENU)
                        DockPan.Tag = "Menu";
                    else if (DockPan.Key == MPGC.MP_SYS_DOCK_FAVORITES)
                        DockPan.Tag = "Favorites";
                }

                DockPan.Text = MPCF.FindLanguage(MPCF.Trim(DockPan.Tag), 0);
            }

        }

        public bool PublishUTLMsgTune()
        {

            try
            {
                if (MPCR.PublishUTLMsgTune() == false)
                {
                    return false;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;

        }

        public bool ViewUTLPublishMessage(bool bActivated)
        {

            try
            {
                Form f;

                f = MPCF.GetChildForm(this, "frmUTLPublishMessage", false);

                if (bActivated == true)
                {
                    if (f == null)
                    {
                        MPGV.gbShowMessagePanel = true;
                    }
                    else
                    {
                        MPGV.gbShowMessagePanel = false;
                        ((frmUTLPublishMessage)f).SetMessageEvent(MPGV.gsMessage);
                    }
                }
                else
                {
                    if (f == null)
                    {
                        f = new frmUTLPublishMessage();
                        f.MdiParent = this;
                        f.Show();
                        ((frmUTLPublishMessage)f).SetMessageEvent(MPGV.gsMessage);
                    }
                    else
                    {
                        ((frmUTLPublishMessage)f).SetMessageEvent(MPGV.gsMessage);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;

        }

        public ImageList GetSmallIconList()
        {
            ImageList imlTemp;

            imlTemp = new ImageList();
            imlTemp.ColorDepth = imlSmallIcon.ColorDepth;
            imlTemp.ImageSize = imlSmallIcon.ImageSize;
            imlTemp.TransparentColor = imlSmallIcon.TransparentColor;
            for (int i = 0; i < imlSmallIcon.Images.Count; i++)
            {
                imlTemp.Images.Add(imlSmallIcon.Images[i]);
            }
            return imlTemp;
        }

        public ImageList GetToolBarIconList()
        {
            ImageList imlTemp;

            imlTemp = new ImageList();
            imlTemp.ColorDepth = imlToolBar.ColorDepth;
            imlTemp.ImageSize = imlToolBar.ImageSize;
            imlTemp.TransparentColor = imlToolBar.TransparentColor;
            for (int i = 0; i < imlToolBar.Images.Count; i++)
            {
                imlTemp.Images.Add(imlToolBar.Images[i]);
            }
            return imlTemp;
        }

        public bool LoadResource()
        {
            if (MPCF.LoadMessageResource("ADMINMessage.xml") == false)
            {
                return false;
            }
            if (MPCF.LoadCaptionResource("ADMINCaption.xml") == false)
            {
                return false;
            }
            if (MPIF.gInit.GetClientOptions() == false)
            {
                return false;
            }

            return true;
        }

        #endregion

        #region " Left Main Routine"

        private bool SetDockingTree()
        {

            SetMenuTree();
            SetFavoritesTree();
            //pnlModeler.WFMToolbarPanel_Load(); // WFMToolbarPanel 초기화

            return true;

        }

        private void SetMenuTree()
        {
            try
            {
                TreeNode node;

                tvMenu.ShowRootLines = false;
                node = tvMenu.Nodes.Add(MPGV.gsFactory);
                node.ImageIndex = (int)SMALLICON_INDEX.IDX_FACTORY;
                node.SelectedImageIndex = (int)SMALLICON_INDEX.IDX_FACTORY;
                SECLIST.ViewFunctionList(tvMenu, MPGV.gsProgramID, MPGV.gsUserGroup, node, false);
                node.ExpandAll();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void SetFavoritesTree()
        {
            try
            {
                if (b_can_get_favorites == false) return;

                TreeNode node;

                //Favorites Setting
                tvFavorites.ShowRootLines = false;
                node = tvFavorites.Nodes.Add(MPGV.gsFactory);
                node.ImageIndex = (int)SMALLICON_INDEX.IDX_FACTORY;
                node.SelectedImageIndex = (int)SMALLICON_INDEX.IDX_FACTORY;
                SECLIST.ViewFavoritesList(tvFavorites, '1', MPGV.gsProgramID, node, "");
                node.ExpandAll();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void tvMenu_AfterSelect(object sender, System.Windows.Forms.TreeViewEventArgs e)
        {
            if (e.Node == null) return;
            if (e.Node.Tag == null) return;

            tvMenu.Tag = ExecuteMenu((MenuInfoTag)e.Node.Tag);
        }

        private void tvMenu_Enter(object sender, System.EventArgs e)
        {
            try
            {
                if (tvMenu.Tag == null) return;

                if (tvMenu.Tag is Control)
                    ((Control)tvMenu.Tag).Focus();

                tvMenu.Tag = null;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        
        private void tvFavorites_AfterSelect(object sender, System.Windows.Forms.TreeViewEventArgs e)
        {
            if (e.Node == null) return;
            if (e.Node.Tag == null) return;

            tvFavorites.Tag = ExecuteMenu((MenuInfoTag)e.Node.Tag);
        }

        private void tvFavorites_Enter(object sender, System.EventArgs e)
        {
            try
            {
                if (tvFavorites.Tag == null) return;

                if (tvFavorites.Tag is Control)
                    ((Control)tvFavorites.Tag).Focus();

                tvFavorites.Tag = null;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void tvMenu_Click(object sender, EventArgs e)
        {
            tvMenu.SelectedNode = null;
        }

        private void tvFavorites_Click(object sender, EventArgs e)
        {
            tvFavorites.SelectedNode = null;
        }
        
        private void btnMenuRefresh_Click(System.Object sender, System.EventArgs e)
        {
            try
            {
                MPCF.InitTreeView(tvMenu);
                SetMenuTree();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnFavoritesRefresh_Click(System.Object sender, System.EventArgs e)
        {
            FavoritesRefresh();
        }

        #endregion

        public bool ViewWIPTranStartLot(bool bDispatcherFlag, string sLotID, string sResourceID)
        {
            return true;
        }

        public bool ViewWIPTranEndLot(bool bDispatcherFlag, string sLotID, string sResourceID)
        {
            return true;
        }

        public bool ViewWIPTranMoveLot(bool bDispatcherFlag, string sLotID)
        {
            return true;
        }

        public bool ViewWIPTranSkipLot(bool bDispatcherFlag, string sLotID)
        {
            return true;
        }

        public bool PublishALMMsgTune()
        {
            return true;
        }

        public bool ViewALMPublishMessage()
        {
            return true;
        }

        public bool PublishSPCMsgTune()
        {
            return true;
        }

        public bool ViewSPCPublishData(object SPC_Publish_Data_In)
        {
            return true;
        }

        public bool ViewSPCPublishMessage()
        {
            return true;
        }

        public bool PublishBBSMsgTune()
        {
            return true;
        }
        public bool ViewBBSPublishMessage()
        {
            return true;
        }
    }
}

