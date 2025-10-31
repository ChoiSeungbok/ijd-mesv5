
using System.Diagnostics;
using System;
using System.Windows.Forms;
using System.Collections;
using System.Drawing;

using System.Data;
using Infragistics.Win.UltraWinTabbedMdi;
using Infragistics.Win.UltraWinToolbars;
using Infragistics.Win.UltraWinDock;
using System.IO;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.FMBCore;
using Miracom.RASCore;
using Miracom.TRSCore;
using Miracom.MsgHandler;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmMDIMain.vb
//   Description : Main Form
//
//   FMB Version : 1.0.0
//
//   Function List
//       - AddResource() : Add Created Resource in Design List TreeView
//       - DeleteResource() : Delete Deleted Resource in Design List TreeView
//       - CreateResourceEvent() : Create Resource Event Process
//       - DeleteResourceEvent() : Delete Resource Event Process
//       - GetStateButtonTool() : Get StateButtonTool
//       - InitDesignList() : Initialize Design List
//       - AddNewForm() : Add Form
//       - ViewFactoryList() : View Factory List
//       - ViewLayoutList() : View Layout List
//       - ViewResourceList() : View Resource List
//       - ViewUDRGroupList() : View User Define Resource Group List
//       - InitMainForm() : Initialize Main Form
//       - ChangeMyMenus() : Change Language of Menu
//       - ChangeDockText() : Change Language of Docking Controls
//       - SetBackGroundColorOfMDIForm() : Set Back Color of MDI Form
//       - DisableMainMenu() : Disable Main Menu
//       - EnableMainMenu() : Enable Main Menu
//       - RefreshDesignList() :Refresh Design List
//       - RefreshUdrGroupList() :Refresh User Define Group List
//       - SaveSystemMenu() :Save System Menu
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-23 : Created by H.K.Kim
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace FMBClient
{
    public class frmMDIMain : frmMDIMainCore, intFMBMdiFormFunction
    {
        
        
        #region " Windows Form Auto Generated Code "
        
        delegate void AddResourceDelegate(string sFactory, string sResource, string sUpDownFlag);
        delegate void AddToolDelegate(string sFactory, string sTool, string sUpDownFlag);
        delegate void AddSubResourceDelegate(string sFactory, string sResource, string sSubResource, string sUpDownFlag);
        delegate void AddPortDelegate(string sFactory,string sResource, string sPort, string sUpDownFlag);
        delegate void DeleteResourceDelegate(string sFactory, string sResource);
        delegate void DeleteToolDelegate(string sFactory, string sTool);
        delegate void DeleteSubResourceDelegate(string sFactory,string sResource, string sSubResource);
        delegate void DeletePortDelegate(string sFactory,string sResource, string sPort);

        private AddResourceDelegate _AddResourceDelegate;
        private AddToolDelegate _AddToolDelegate;
        private AddPortDelegate _AddPortDelegate;
        private AddSubResourceDelegate _AddSubResourceDelegate;
        public ToolStrip tolMain;
        private MenuStrip mnuMain;
        private ToolStripMenuItem tsmTopSystem;
        private ToolStripMenuItem tsmLogout;
        private ToolStripMenuItem tsmSaveConfig;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripMenuItem tsmClientUpgrade;
        private ToolStripMenuItem tsmOption;
        private ToolStripSeparator toolStripSeparator2;
        private ToolStripMenuItem tsmExit;
        private ToolStripMenuItem tsmTopWindows;
        private ToolStripMenuItem tsmTabbedMdi;
        private ToolStripMenuItem tsmCloseAll;
        private ToolStripSeparator toolStripSeparator4;
        private ToolStripMenuItem tsmTopHelp;
        private ToolStripMenuItem tsmHelp;
        private ToolStripSeparator toolStripSeparator3;
        private ToolStripMenuItem tsmAbout;
        private ToolStripSeparator toolStripSeparator5;
        private ToolStripMenuItem tsmDesignList;
        private ToolStripMenuItem tsmToolsList;
        private ToolStripButton tsbLefts;
        private ToolStripButton tsbCenter;
        private ToolStripButton tsbRight;
        private ToolStripButton tsbTops;
        private ToolStripButton tsbMiddles;
        private ToolStripButton tsbBottoms;
        private ToolStripButton tsbWidth;
        private ToolStripButton tsbHeight;
        private ToolStripButton tsbBoth;
        private ToolStripButton tsbHMakeEqual;
        private ToolStripButton tsbHIncrease;
        private ToolStripButton tsbHDecrease;
        private ToolStripButton tsbHRemove;
        private ToolStripButton tsbVMakeEqual;
        private ToolStripButton tsbVIncrease;
        private ToolStripButton tsbVDecrease;
        private ToolStripButton tsbVRemove;
        private ToolStripButton tsbBring;
        private ToolStripButton tsbSend;
        private ToolStripSeparator toolStripSeparator6;
        private ToolStripMenuItem tsmTopDesign;
        private ToolStripMenuItem tsmDesignMode;
        private ToolStripMenuItem tsmSaveDesign;
        private ToolStripSeparator toolStripSeparator7;
        private ToolStripMenuItem tsmAddRes;
        private ToolStripSeparator toolStripSeparator8;
        private ToolStripMenuItem tsmUpdateRes;
        private ToolStripMenuItem tsmDeleteRes;
        private ToolStripMenuItem tsmProperties;
        private MenuStrip mnuDesign;
        private ToolStripMenuItem tsmTopFormat;
        private ToolStripMenuItem tsmTopView;
        private ToolStripMenuItem tsmReload;
        private ToolStripSeparator toolStripSeparator9;
        private ToolStripMenuItem tsmZoomIn;
        private ToolStripMenuItem tsmZoomOut;
        private ToolStripMenuItem tsmLefts;
        private ToolStripMenuItem tsmCenters;
        private ToolStripMenuItem tsmRights;
        private ToolStripSeparator tsmSp1;
        private ToolStripMenuItem tsmTops;
        private ToolStripMenuItem tsmMiddles;
        private ToolStripMenuItem tsmBottoms;
        private ToolStripSeparator tsmSp2;
        private ToolStripMenuItem tsmWidth;
        private ToolStripMenuItem tsmHeight;
        private ToolStripMenuItem tsmBoth;
        private ToolStripSeparator tsmSp3;
        private ToolStripMenuItem tsmHMakeEqual;
        private ToolStripMenuItem tsmHIncrease;
        private ToolStripMenuItem tsmHDecrease;
        private ToolStripMenuItem tsmHRemove;
        private ToolStripSeparator tsmSp4;
        private ToolStripMenuItem tsmVMakeEqual;
        private ToolStripMenuItem tsmVIncrease;
        private ToolStripMenuItem tsmVDecrease;
        private ToolStripMenuItem tsmVRemove;
        private ToolStripSeparator tsmSp5;
        private ToolStripMenuItem tsmBring;
        private ToolStripMenuItem tsmSend;
        private ToolStripButton tsbDesignMode;
        private ToolStripButton tsbSaveDesign;
        private ToolStripSeparator toolStripSeparator10;
        private DeleteResourceDelegate _DeleteResourceDelegate;
        private DeleteToolDelegate _DeleteToolDelegate;
        private DeleteSubResourceDelegate _DeleteSubResourceDelegate;
        internal ImageList imlTools;
        private MenuItem mnuDeleteFile;
        private DeletePortDelegate _DeletePortDelegate;
        
        public frmMDIMain()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            _AddResourceDelegate = new AddResourceDelegate( AddResource);
            _DeleteResourceDelegate = new DeleteResourceDelegate( DeleteResource);
            _AddToolDelegate = new AddToolDelegate(AddTool);
            _DeleteToolDelegate = new DeleteToolDelegate(DeleteTool);
            _AddPortDelegate = new AddPortDelegate(AddPort);
            _DeletePortDelegate = new DeletePortDelegate(DeletePort);
            _AddSubResourceDelegate = new AddSubResourceDelegate(AddSubResource);
            _DeleteSubResourceDelegate = new DeleteSubResourceDelegate(DeleteSubResource);
            
            this.trvDesignList.Size = new Size(0, 0);
            this.lisTools.Size = new Size(0, 0);
            
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

        private System.ComponentModel.IContainer components;

        //Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        
        //李멸퀬: ?ㅼ쓬 ?꾨줈?쒖???Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
        //Windows Form ?붿옄?대꼫瑜??ъ슜?섏뿬 ?섏젙?????덉뒿?덈떎.
        //肄붾뱶 ?몄쭛湲곕? ?ъ슜?섏뿬 ?섏젙?섏? 留덉떗?쒖삤.
        internal Infragistics.Win.UltraWinTabbedMdi.UltraTabbedMdiManager utmmMDIMain;
        internal Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainUnpinnedTabAreaLeft;
        internal Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainUnpinnedTabAreaRight;
        internal Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainUnpinnedTabAreaTop;
        internal Infragistics.Win.UltraWinDock.UnpinnedTabArea _frmMDIMainUnpinnedTabAreaBottom;
        internal Infragistics.Win.UltraWinDock.AutoHideControl _frmMDIMainAutoHideControl;
        internal Infragistics.Win.UltraWinDock.UltraDockManager udmMDIMain;
        internal System.Windows.Forms.ListView lisTools;
        internal System.Windows.Forms.ColumnHeader colTools;
        internal Infragistics.Win.UltraWinDock.DockableWindow DockableWindow1;
        internal System.Windows.Forms.ContextMenu mnuDesignList;
        internal System.Windows.Forms.MenuItem mnuDeleteResource;
        internal System.Windows.Forms.MenuItem mnuProperties;
        internal System.Windows.Forms.MenuItem mnuViewResourceStatus;
        internal System.Windows.Forms.MenuItem mnuViewResourceHistory;
        internal System.Windows.Forms.MenuItem mnuSeperator1;
        internal System.Windows.Forms.MenuItem mnuUpdateLayout;
        internal System.Windows.Forms.MenuItem mnuUpdateUserGroupDesign;
        //internal System.Windows.Forms.StatusBarPanel stsMDIMainPanel1;
        //internal System.Windows.Forms.StatusBarPanel stsMDIMainPanel2;
        //internal System.Windows.Forms.StatusBarPanel stsMDIMainPanel3;
        //internal System.Windows.Forms.StatusBarPanel stsMDIMainPanel4;
        //internal System.Windows.Forms.StatusBarPanel stsMDIMainPanel5;
        //internal System.Windows.Forms.StatusBarPanel stsMDIMainPanel6;
        internal System.Windows.Forms.MenuItem mnuTranEvent;
        internal Infragistics.Win.UltraWinDock.DockableWindow DockableWindow2;
        internal Infragistics.Win.UltraWinDock.WindowDockingArea WindowDockingArea3;
        internal Infragistics.Win.UltraWinDock.WindowDockingArea WindowDockingArea1;
        internal Infragistics.Win.UltraWinDock.WindowDockingArea WindowDockingArea4;
        internal System.Windows.Forms.MenuItem mnuRefreshDesignList;
        internal System.Windows.Forms.TreeView trvDesignList;
        public System.Windows.Forms.ImageList imlResource;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMDIMain));
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem("Resource", 0);
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("Sub Resource", 11);
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("Port", 12);
            System.Windows.Forms.ListViewItem listViewItem4 = new System.Windows.Forms.ListViewItem("Tool", 13);
            System.Windows.Forms.ListViewItem listViewItem5 = new System.Windows.Forms.ListViewItem("Rectangle", 1);
            System.Windows.Forms.ListViewItem listViewItem6 = new System.Windows.Forms.ListViewItem("Ellipse", 2);
            System.Windows.Forms.ListViewItem listViewItem7 = new System.Windows.Forms.ListViewItem("Triangle", 3);
            System.Windows.Forms.ListViewItem listViewItem8 = new System.Windows.Forms.ListViewItem("Vertical Line", 4);
            System.Windows.Forms.ListViewItem listViewItem9 = new System.Windows.Forms.ListViewItem("Horizontal Line", 5);
            System.Windows.Forms.ListViewItem listViewItem10 = new System.Windows.Forms.ListViewItem("Pie Type 1", 6);
            System.Windows.Forms.ListViewItem listViewItem11 = new System.Windows.Forms.ListViewItem("Pie Type 2", 7);
            System.Windows.Forms.ListViewItem listViewItem12 = new System.Windows.Forms.ListViewItem("Pie Type 3", 8);
            System.Windows.Forms.ListViewItem listViewItem13 = new System.Windows.Forms.ListViewItem("Pie Type 4", 9);
            System.Windows.Forms.ListViewItem listViewItem14 = new System.Windows.Forms.ListViewItem("Text", 10);
            Infragistics.Win.UltraWinDock.DockAreaPane dockAreaPane1 = new Infragistics.Win.UltraWinDock.DockAreaPane(Infragistics.Win.UltraWinDock.DockedLocation.DockedLeft, new System.Guid("270db845-e86e-4718-b23e-280489641535"));
            Infragistics.Win.UltraWinDock.DockableControlPane dockableControlPane1 = new Infragistics.Win.UltraWinDock.DockableControlPane(new System.Guid("d6c4cb0e-d248-4898-a68f-c99aa995796b"), new System.Guid("e4d7c431-9633-4e11-b469-e22a5679db55"), -1, new System.Guid("270db845-e86e-4718-b23e-280489641535"), 0);
            Infragistics.Win.UltraWinDock.DockableControlPane dockableControlPane2 = new Infragistics.Win.UltraWinDock.DockableControlPane(new System.Guid("45e3eee4-fe9c-4037-9279-cc8ea0b5a46c"), new System.Guid("85b1e5d3-b597-4d04-b704-f7fa1c49dd3d"), -1, new System.Guid("270db845-e86e-4718-b23e-280489641535"), 0);
            Infragistics.Win.UltraWinDock.DockAreaPane dockAreaPane2 = new Infragistics.Win.UltraWinDock.DockAreaPane(Infragistics.Win.UltraWinDock.DockedLocation.Floating, new System.Guid("85b1e5d3-b597-4d04-b704-f7fa1c49dd3d"));
            Infragistics.Win.UltraWinDock.DockAreaPane dockAreaPane3 = new Infragistics.Win.UltraWinDock.DockAreaPane(Infragistics.Win.UltraWinDock.DockedLocation.Floating, new System.Guid("e4d7c431-9633-4e11-b469-e22a5679db55"));
            this.trvDesignList = new System.Windows.Forms.TreeView();
            this.mnuDesignList = new System.Windows.Forms.ContextMenu();
            this.mnuRefreshDesignList = new System.Windows.Forms.MenuItem();
            this.mnuDeleteResource = new System.Windows.Forms.MenuItem();
            this.mnuUpdateLayout = new System.Windows.Forms.MenuItem();
            this.mnuUpdateUserGroupDesign = new System.Windows.Forms.MenuItem();
            this.mnuProperties = new System.Windows.Forms.MenuItem();
            this.mnuSeperator1 = new System.Windows.Forms.MenuItem();
            this.mnuViewResourceStatus = new System.Windows.Forms.MenuItem();
            this.mnuViewResourceHistory = new System.Windows.Forms.MenuItem();
            this.mnuTranEvent = new System.Windows.Forms.MenuItem();
            this.mnuDeleteFile = new System.Windows.Forms.MenuItem();
            this.lisTools = new System.Windows.Forms.ListView();
            this.colTools = new System.Windows.Forms.ColumnHeader();
            this.imlTools = new System.Windows.Forms.ImageList(this.components);
            this.utmmMDIMain = new Infragistics.Win.UltraWinTabbedMdi.UltraTabbedMdiManager(this.components);
            this.udmMDIMain = new Infragistics.Win.UltraWinDock.UltraDockManager(this.components);
            this._frmMDIMainUnpinnedTabAreaLeft = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainUnpinnedTabAreaRight = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainUnpinnedTabAreaTop = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainUnpinnedTabAreaBottom = new Infragistics.Win.UltraWinDock.UnpinnedTabArea();
            this._frmMDIMainAutoHideControl = new Infragistics.Win.UltraWinDock.AutoHideControl();
            this.DockableWindow1 = new Infragistics.Win.UltraWinDock.DockableWindow();
            this.DockableWindow2 = new Infragistics.Win.UltraWinDock.DockableWindow();
            this.WindowDockingArea3 = new Infragistics.Win.UltraWinDock.WindowDockingArea();
            this.WindowDockingArea1 = new Infragistics.Win.UltraWinDock.WindowDockingArea();
            this.WindowDockingArea4 = new Infragistics.Win.UltraWinDock.WindowDockingArea();
            this.imlResource = new System.Windows.Forms.ImageList(this.components);
            this.tolMain = new System.Windows.Forms.ToolStrip();
            this.tsbLefts = new System.Windows.Forms.ToolStripButton();
            this.tsbCenter = new System.Windows.Forms.ToolStripButton();
            this.tsbRight = new System.Windows.Forms.ToolStripButton();
            this.tsbTops = new System.Windows.Forms.ToolStripButton();
            this.tsbMiddles = new System.Windows.Forms.ToolStripButton();
            this.tsbBottoms = new System.Windows.Forms.ToolStripButton();
            this.tsbWidth = new System.Windows.Forms.ToolStripButton();
            this.tsbHeight = new System.Windows.Forms.ToolStripButton();
            this.tsbBoth = new System.Windows.Forms.ToolStripButton();
            this.tsbHMakeEqual = new System.Windows.Forms.ToolStripButton();
            this.tsbHIncrease = new System.Windows.Forms.ToolStripButton();
            this.tsbHDecrease = new System.Windows.Forms.ToolStripButton();
            this.tsbHRemove = new System.Windows.Forms.ToolStripButton();
            this.tsbVMakeEqual = new System.Windows.Forms.ToolStripButton();
            this.tsbVIncrease = new System.Windows.Forms.ToolStripButton();
            this.tsbVDecrease = new System.Windows.Forms.ToolStripButton();
            this.tsbVRemove = new System.Windows.Forms.ToolStripButton();
            this.tsbBring = new System.Windows.Forms.ToolStripButton();
            this.tsbSend = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbDesignMode = new System.Windows.Forms.ToolStripButton();
            this.tsbSaveDesign = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator10 = new System.Windows.Forms.ToolStripSeparator();
            this.mnuMain = new System.Windows.Forms.MenuStrip();
            this.tsmTopSystem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmLogout = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSaveConfig = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmClientUpgrade = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmOption = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmExit = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmDesignList = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmToolsList = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmTopWindows = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmTabbedMdi = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmCloseAll = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmTopHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmTopDesign = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmDesignMode = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSaveDesign = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator7 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmAddRes = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmUpdateRes = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmDeleteRes = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmProperties = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuDesign = new System.Windows.Forms.MenuStrip();
            this.tsmTopFormat = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmLefts = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmCenters = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmRights = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSp1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmTops = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmMiddles = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmBottoms = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSp2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmWidth = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmHeight = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmBoth = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSp3 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmHMakeEqual = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmHIncrease = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmHDecrease = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmHRemove = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSp4 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmVMakeEqual = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmVIncrease = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmVDecrease = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmVRemove = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSp5 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmBring = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmSend = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmTopView = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmReload = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator9 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmZoomIn = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmZoomOut = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.utmmMDIMain)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.udmMDIMain)).BeginInit();
            this.DockableWindow1.SuspendLayout();
            this.DockableWindow2.SuspendLayout();
            this.WindowDockingArea3.SuspendLayout();
            this.tolMain.SuspendLayout();
            this.mnuMain.SuspendLayout();
            this.mnuDesign.SuspendLayout();
            this.SuspendLayout();
            // 
            // imlSmallIcon
            // 
            this.imlSmallIcon.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imlSmallIcon.ImageStream")));
            this.imlSmallIcon.Images.SetKeyName(0, "");
            this.imlSmallIcon.Images.SetKeyName(1, "");
            this.imlSmallIcon.Images.SetKeyName(2, "");
            this.imlSmallIcon.Images.SetKeyName(3, "");
            this.imlSmallIcon.Images.SetKeyName(4, "");
            this.imlSmallIcon.Images.SetKeyName(5, "");
            this.imlSmallIcon.Images.SetKeyName(6, "");
            this.imlSmallIcon.Images.SetKeyName(7, "");
            this.imlSmallIcon.Images.SetKeyName(8, "");
            this.imlSmallIcon.Images.SetKeyName(9, "");
            this.imlSmallIcon.Images.SetKeyName(10, "");
            this.imlSmallIcon.Images.SetKeyName(11, "");
            this.imlSmallIcon.Images.SetKeyName(12, "");
            this.imlSmallIcon.Images.SetKeyName(13, "");
            this.imlSmallIcon.Images.SetKeyName(14, "");
            this.imlSmallIcon.Images.SetKeyName(15, "");
            this.imlSmallIcon.Images.SetKeyName(16, "");
            this.imlSmallIcon.Images.SetKeyName(17, "");
            this.imlSmallIcon.Images.SetKeyName(18, "");
            this.imlSmallIcon.Images.SetKeyName(19, "");
            this.imlSmallIcon.Images.SetKeyName(20, "");
            this.imlSmallIcon.Images.SetKeyName(21, "");
            this.imlSmallIcon.Images.SetKeyName(22, "");
            this.imlSmallIcon.Images.SetKeyName(23, "");
            this.imlSmallIcon.Images.SetKeyName(24, "");
            this.imlSmallIcon.Images.SetKeyName(25, "");
            this.imlSmallIcon.Images.SetKeyName(26, "");
            this.imlSmallIcon.Images.SetKeyName(27, "");
            this.imlSmallIcon.Images.SetKeyName(28, "");
            this.imlSmallIcon.Images.SetKeyName(29, "");
            this.imlSmallIcon.Images.SetKeyName(30, "");
            this.imlSmallIcon.Images.SetKeyName(31, "");
            this.imlSmallIcon.Images.SetKeyName(32, "");
            this.imlSmallIcon.Images.SetKeyName(33, "");
            this.imlSmallIcon.Images.SetKeyName(34, "");
            this.imlSmallIcon.Images.SetKeyName(35, "");
            this.imlSmallIcon.Images.SetKeyName(36, "");
            this.imlSmallIcon.Images.SetKeyName(37, "");
            this.imlSmallIcon.Images.SetKeyName(38, "");
            this.imlSmallIcon.Images.SetKeyName(39, "");
            this.imlSmallIcon.Images.SetKeyName(40, "");
            this.imlSmallIcon.Images.SetKeyName(41, "");
            this.imlSmallIcon.Images.SetKeyName(42, "");
            this.imlSmallIcon.Images.SetKeyName(43, "");
            this.imlSmallIcon.Images.SetKeyName(44, "");
            this.imlSmallIcon.Images.SetKeyName(45, "");
            this.imlSmallIcon.Images.SetKeyName(46, "");
            this.imlSmallIcon.Images.SetKeyName(47, "");
            this.imlSmallIcon.Images.SetKeyName(48, "");
            this.imlSmallIcon.Images.SetKeyName(49, "");
            this.imlSmallIcon.Images.SetKeyName(50, "");
            this.imlSmallIcon.Images.SetKeyName(51, "");
            this.imlSmallIcon.Images.SetKeyName(52, "");
            this.imlSmallIcon.Images.SetKeyName(53, "");
            this.imlSmallIcon.Images.SetKeyName(54, "");
            this.imlSmallIcon.Images.SetKeyName(55, "");
            this.imlSmallIcon.Images.SetKeyName(56, "");
            this.imlSmallIcon.Images.SetKeyName(57, "");
            this.imlSmallIcon.Images.SetKeyName(58, "");
            this.imlSmallIcon.Images.SetKeyName(59, "");
            this.imlSmallIcon.Images.SetKeyName(60, "");
            this.imlSmallIcon.Images.SetKeyName(61, "");
            this.imlSmallIcon.Images.SetKeyName(62, "");
            this.imlSmallIcon.Images.SetKeyName(63, "");
            this.imlSmallIcon.Images.SetKeyName(64, "");
            this.imlSmallIcon.Images.SetKeyName(65, "");
            this.imlSmallIcon.Images.SetKeyName(66, "");
            this.imlSmallIcon.Images.SetKeyName(67, "");
            this.imlSmallIcon.Images.SetKeyName(68, "");
            this.imlSmallIcon.Images.SetKeyName(69, "");
            this.imlSmallIcon.Images.SetKeyName(70, "");
            this.imlSmallIcon.Images.SetKeyName(71, "");
            this.imlSmallIcon.Images.SetKeyName(72, "");
            this.imlSmallIcon.Images.SetKeyName(73, "");
            this.imlSmallIcon.Images.SetKeyName(74, "");
            this.imlSmallIcon.Images.SetKeyName(75, "");
            this.imlSmallIcon.Images.SetKeyName(76, "");
            this.imlSmallIcon.Images.SetKeyName(77, "");
            this.imlSmallIcon.Images.SetKeyName(78, "");
            this.imlSmallIcon.Images.SetKeyName(79, "");
            this.imlSmallIcon.Images.SetKeyName(80, "");
            this.imlSmallIcon.Images.SetKeyName(81, "");
            this.imlSmallIcon.Images.SetKeyName(82, "");
            this.imlSmallIcon.Images.SetKeyName(83, "");
            this.imlSmallIcon.Images.SetKeyName(84, "");
            this.imlSmallIcon.Images.SetKeyName(85, "");
            this.imlSmallIcon.Images.SetKeyName(86, "");
            this.imlSmallIcon.Images.SetKeyName(87, "");
            this.imlSmallIcon.Images.SetKeyName(88, "");
            this.imlSmallIcon.Images.SetKeyName(89, "");
            this.imlSmallIcon.Images.SetKeyName(90, "");
            this.imlSmallIcon.Images.SetKeyName(91, "");
            this.imlSmallIcon.Images.SetKeyName(92, "");
            this.imlSmallIcon.Images.SetKeyName(93, "");
            this.imlSmallIcon.Images.SetKeyName(94, "");
            this.imlSmallIcon.Images.SetKeyName(95, "");
            this.imlSmallIcon.Images.SetKeyName(96, "");
            this.imlSmallIcon.Images.SetKeyName(97, "");
            this.imlSmallIcon.Images.SetKeyName(98, "");
            this.imlSmallIcon.Images.SetKeyName(99, "");
            this.imlSmallIcon.Images.SetKeyName(100, "");
            this.imlSmallIcon.Images.SetKeyName(101, "");
            this.imlSmallIcon.Images.SetKeyName(102, "");
            this.imlSmallIcon.Images.SetKeyName(103, "");
            this.imlSmallIcon.Images.SetKeyName(104, "White Image");
            this.imlSmallIcon.Images.SetKeyName(105, "");
            this.imlSmallIcon.Images.SetKeyName(106, "Subequip9.ico");
            this.imlSmallIcon.Images.SetKeyName(107, "Port_down.ico");
            // 
            // imlToolBar
            // 
            this.imlToolBar.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imlToolBar.ImageStream")));
            this.imlToolBar.Images.SetKeyName(0, "2.4.1_FactorySetup.ico");
            this.imlToolBar.Images.SetKeyName(1, "2.4.2_MaterialSetup.ico");
            this.imlToolBar.Images.SetKeyName(2, "2.4.3_FlowSetup.ico");
            this.imlToolBar.Images.SetKeyName(3, "2.4.4_OperationSetup.ico");
            this.imlToolBar.Images.SetKeyName(4, "2.4.5_ReworkFlowSetup.ico");
            this.imlToolBar.Images.SetKeyName(5, "2.4.7_CycleTimeSetup.ico");
            this.imlToolBar.Images.SetKeyName(6, "2.4.8_CalendarSetup.ico");
            this.imlToolBar.Images.SetKeyName(7, "");
            this.imlToolBar.Images.SetKeyName(8, "3.1.1_Create.ico");
            this.imlToolBar.Images.SetKeyName(9, "3.1.2_Start.ico");
            this.imlToolBar.Images.SetKeyName(10, "3.1.3_Multi-Start.ico");
            this.imlToolBar.Images.SetKeyName(11, "3.1.4_End.ico");
            this.imlToolBar.Images.SetKeyName(12, "3.1.5_Multi-End.ico");
            this.imlToolBar.Images.SetKeyName(13, "3.1.6_Move.ico");
            this.imlToolBar.Images.SetKeyName(14, "3.1.8_Rework.ico");
            this.imlToolBar.Images.SetKeyName(15, "3.1.12_Split.ico");
            this.imlToolBar.Images.SetKeyName(16, "3.1.13_Merge.ico");
            this.imlToolBar.Images.SetKeyName(17, "3.1.7_Skip.ico");
            this.imlToolBar.Images.SetKeyName(18, "3.1.14_Combine.ico");
            this.imlToolBar.Images.SetKeyName(19, "3.1.16_Hold.ico");
            this.imlToolBar.Images.SetKeyName(20, "3.1.17_Release.ico");
            this.imlToolBar.Images.SetKeyName(21, "3.1.18_Ship.ico");
            this.imlToolBar.Images.SetKeyName(22, "3.1.19_Receive.ico");
            this.imlToolBar.Images.SetKeyName(23, "3.1.20_Adapt.ico");
            this.imlToolBar.Images.SetKeyName(24, "3.1.21_Loss.ico");
            this.imlToolBar.Images.SetKeyName(25, "3.1.21_Bonus.ico");
            this.imlToolBar.Images.SetKeyName(26, "");
            this.imlToolBar.Images.SetKeyName(27, "3.1.25_DeleteLotHistory.ico");
            this.imlToolBar.Images.SetKeyName(28, "2.6.1_ResourceSetup.ico");
            this.imlToolBar.Images.SetKeyName(29, "2.6.5_EventSetup.ico");
            this.imlToolBar.Images.SetKeyName(30, "3.4.1_Event.ico");
            this.imlToolBar.Images.SetKeyName(31, "");
            this.imlToolBar.Images.SetKeyName(32, "");
            this.imlToolBar.Images.SetKeyName(33, "");
            this.imlToolBar.Images.SetKeyName(34, "");
            this.imlToolBar.Images.SetKeyName(35, "");
            this.imlToolBar.Images.SetKeyName(36, "");
            this.imlToolBar.Images.SetKeyName(37, "2.3.2_GeneralCodeDataSetup.ico");
            this.imlToolBar.Images.SetKeyName(38, "2.1.1_MessageSetup.ico");
            this.imlToolBar.Images.SetKeyName(39, "2.2.1_User.ico");
            this.imlToolBar.Images.SetKeyName(40, "2.2.2_SecurityGroupSetup.ico");
            this.imlToolBar.Images.SetKeyName(41, "2.2.3_AttachFunction_to_SecurityGroup.ico");
            this.imlToolBar.Images.SetKeyName(42, "2.2.4_FunctionSetup.ico");
            this.imlToolBar.Images.SetKeyName(43, "2.2.5_PrivilegeGroupSetup.ico");
            this.imlToolBar.Images.SetKeyName(44, "2.2.6_PrivilegeDefinitionSetup.ico");
            this.imlToolBar.Images.SetKeyName(45, "2.2.6_PrivilegeGroup-UserRelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(46, "2.3.1_GeneralCodeTableSetup.ico");
            this.imlToolBar.Images.SetKeyName(47, "2.6.22_PortSetup.ico");
            this.imlToolBar.Images.SetKeyName(48, "2.4.6_RepairOperationSetup.ico");
            this.imlToolBar.Images.SetKeyName(49, "2.4.10_SetupOptionSetup.ico");
            this.imlToolBar.Images.SetKeyName(50, "2.4.14_MFOOptionSetup.ico");
            this.imlToolBar.Images.SetKeyName(51, "2.6.2_ResourceGroupSetup.ico");
            this.imlToolBar.Images.SetKeyName(52, "2.6.3_Resource-ResourceGroupRelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(53, "2.6.6_ResourceEventRelationtSetup.ico");
            this.imlToolBar.Images.SetKeyName(54, "2.6.7_ResourceLaborSetup.ico");
            this.imlToolBar.Images.SetKeyName(55, "2.6.8_SubResourceSetup.ico");
            this.imlToolBar.Images.SetKeyName(56, "2.6.9_PMSecuritySetup.ico");
            this.imlToolBar.Images.SetKeyName(57, "2.6.10_PMScheduleSetup.ico");
            this.imlToolBar.Images.SetKeyName(58, "2.6.11_CheckQuerySetup.ico");
            this.imlToolBar.Images.SetKeyName(59, "2.6.12_AttachQuerytoCheckList.ico");
            this.imlToolBar.Images.SetKeyName(60, "2.6.13_CheckTypeDefinition.ico");
            this.imlToolBar.Images.SetKeyName(61, "2.6.14_CarrierSetup.ico");
            this.imlToolBar.Images.SetKeyName(62, "2.6.15_CarrierGroupSetup.ico");
            this.imlToolBar.Images.SetKeyName(63, "2.6.17_CarrierEventSetup.ico");
            this.imlToolBar.Images.SetKeyName(64, "2.6.18_ToolTypeSetup.ico");
            this.imlToolBar.Images.SetKeyName(65, "2.6.19_ToolEventSetup.ico");
            this.imlToolBar.Images.SetKeyName(66, "2.6.20_ToolSetup.ico");
            this.imlToolBar.Images.SetKeyName(67, "2.6.21_Tool-EventRelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(68, "3.4.12_DeleteToolHistory2.ico");
            this.imlToolBar.Images.SetKeyName(69, "3.1.9_RepairLot.ico");
            this.imlToolBar.Images.SetKeyName(70, "3.1.10_RepairEndLot.ico");
            this.imlToolBar.Images.SetKeyName(71, "3.1.11_LocalRepairLot.ico");
            this.imlToolBar.Images.SetKeyName(72, "3.1.23_StoreLot.ico");
            this.imlToolBar.Images.SetKeyName(73, "3.1.24_Un-StoreLot.ico");
            this.imlToolBar.Images.SetKeyName(74, "3.1.26_OpenReturnLot.ico");
            this.imlToolBar.Images.SetKeyName(75, "3.1.27_CloseReturnLot.ico");
            this.imlToolBar.Images.SetKeyName(76, "3.1.28_MakeBatch.ico");
            this.imlToolBar.Images.SetKeyName(77, "3.1.29_ReleaseBatch.ico");
            this.imlToolBar.Images.SetKeyName(78, "3.1.30_StartBatch.ico");
            this.imlToolBar.Images.SetKeyName(79, "3.1.31_EndBatch.ico");
            this.imlToolBar.Images.SetKeyName(80, "3.1.32_CollectLotDefect.ico");
            this.imlToolBar.Images.SetKeyName(81, "3.1.33_CleanLotDefect.ico");
            this.imlToolBar.Images.SetKeyName(82, "3.1.34_Terminate.ico");
            this.imlToolBar.Images.SetKeyName(83, "3.1.35_MultiTerminate.ico");
            this.imlToolBar.Images.SetKeyName(84, "3.1.36_ReserveLot.ico");
            this.imlToolBar.Images.SetKeyName(85, "3.1.36_UnreserveLot.ico");
            this.imlToolBar.Images.SetKeyName(86, "3.1.38_MakeSubLotBatch.ico");
            this.imlToolBar.Images.SetKeyName(87, "3.1.39_Reserve Lot Batch.ico");
            this.imlToolBar.Images.SetKeyName(88, "3.1.40_ReserveSubLotBatch.ico");
            this.imlToolBar.Images.SetKeyName(89, "3.4.2_SubResourceEvent.ico");
            this.imlToolBar.Images.SetKeyName(90, "3.4.3_DeleteResourceHistory.ico");
            this.imlToolBar.Images.SetKeyName(91, "3.4.4_DeleteSub-ResourceHistory.ico");
            this.imlToolBar.Images.SetKeyName(92, "3.4.5_CleanCarrier.ico");
            this.imlToolBar.Images.SetKeyName(93, "3.4.6_AttachLottoCarrier.ico");
            this.imlToolBar.Images.SetKeyName(94, "3.4.7_AttachCarriertoLot.ico");
            this.imlToolBar.Images.SetKeyName(95, "3.4.8_AssignSubLottoCarrier.ico");
            this.imlToolBar.Images.SetKeyName(96, "3.4.9_CarrierChange-Exchange.ico");
            this.imlToolBar.Images.SetKeyName(97, "3.4.10_Carrier Event.ico");
            this.imlToolBar.Images.SetKeyName(98, "3.4.11_ToolEvent.ico");
            this.imlToolBar.Images.SetKeyName(99, "1.1.12_DockingWindow-Modeler.ico");
            this.imlToolBar.Images.SetKeyName(100, "1.1.8_DockingWindow-Favorities.ico");
            this.imlToolBar.Images.SetKeyName(101, "1.1.9_DockingWindow-Operation.ico");
            this.imlToolBar.Images.SetKeyName(102, "1.1.10_DockingWindow-Resource.ico");
            this.imlToolBar.Images.SetKeyName(103, "1.1.11_DockingWindow-Dispatcher.ico");
            this.imlToolBar.Images.SetKeyName(104, "1.1.6_Help.ico");
            this.imlToolBar.Images.SetKeyName(105, "1.1.5_SendMessage.ico");
            this.imlToolBar.Images.SetKeyName(106, "2.4.13_BatchKeepFlagSetup.ico");
            this.imlToolBar.Images.SetKeyName(107, "2.4.15_YieldSetup.ico");
            this.imlToolBar.Images.SetKeyName(108, "2.6.4_Resource-MFORelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(109, "2.6.16_CarrierGroupRelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(110, "3.4.13_ChangePortState.ico");
            this.imlToolBar.Images.SetKeyName(111, "3.4.14_ChangeTransferState.ico");
            this.imlToolBar.Images.SetKeyName(112, "3.4.15_ChangeAssociationState.ico");
            this.imlToolBar.Images.SetKeyName(113, "3.4.16_ChangeAssociationState.ico");
            this.imlToolBar.Images.SetKeyName(114, "3.4.17_ChangeReservationState.ico");
            this.imlToolBar.Images.SetKeyName(115, "3.4.18_MakeCheckResult.ico");
            this.imlToolBar.Images.SetKeyName(116, "Amc Application.ico");
            this.imlToolBar.Images.SetKeyName(117, "1.1.6_Help2.ico");
            this.imlToolBar.Images.SetKeyName(118, "2.2.8_FlexibleHeaderSetup.ico");
            this.imlToolBar.Images.SetKeyName(119, "2.4.9_CalendarSetup.ico");
            this.imlToolBar.Images.SetKeyName(120, "2.4.9_CalendarSetup_M.ico");
            this.imlToolBar.Images.SetKeyName(121, "2.4.9_CalendarSetup_Y.ico");
            this.imlToolBar.Images.SetKeyName(122, "2.4.11_FutureActionSetup.ico");
            this.imlToolBar.Images.SetKeyName(123, "2.4.12_QueueTimeSetup.ico");
            this.imlToolBar.Images.SetKeyName(124, "2.4.16_IDGeneratorSetup.ico");
            this.imlToolBar.Images.SetKeyName(125, "2.4.17_IDGeneratorRelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(126, "2.4.18_BatchCreationRuleSetup.ico");
            this.imlToolBar.Images.SetKeyName(127, "2.4.19_BatchCreationRuleRelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(128, "2.5.1_BOMSetSetup.ico");
            this.imlToolBar.Images.SetKeyName(129, "2.5.2_AttachMaterialtoVersion.ico");
            this.imlToolBar.Images.SetKeyName(130, "2.5.3_ApprovalandReleaseBOMsetVersion.ico");
            this.imlToolBar.Images.SetKeyName(131, "2.7.1_CharacterSetup.ico");
            this.imlToolBar.Images.SetKeyName(132, "2.7.2_CollectionSetSetup.ico");
            this.imlToolBar.Images.SetKeyName(133, "2.7.3_AttachCharactertoVersion.ico");
            this.imlToolBar.Images.SetKeyName(134, "2.7.4_AttachCollectionSettoMFO.ico");
            this.imlToolBar.Images.SetKeyName(135, "2.7.5_ApprovalandReleaseCollectionSetVersion.ico");
            this.imlToolBar.Images.SetKeyName(136, "2.8.1_RecipeSetup.ico");
            this.imlToolBar.Images.SetKeyName(137, "2.8.2_RecipeVersionSetup.ico");
            this.imlToolBar.Images.SetKeyName(138, "2.8.3_ApprovalandReleaseRecipeVersion.ico");
            this.imlToolBar.Images.SetKeyName(139, "2.8.4_AttachRecipeToMFO.ico");
            this.imlToolBar.Images.SetKeyName(140, "2.9.1_DispatcherRuleSetup.ico");
            this.imlToolBar.Images.SetKeyName(141, "2.9.2_DispatcherRuleItemSetup.ico");
            this.imlToolBar.Images.SetKeyName(142, "2.9.3_DispatcherSetup.ico");
            this.imlToolBar.Images.SetKeyName(143, "2.9.4_DispatcherSimulationSetup.ico");
            this.imlToolBar.Images.SetKeyName(144, "2.9.4_DistpatcherRelationSetup.ico");
            this.imlToolBar.Images.SetKeyName(145, "2.9.5_ReferenceOperationSetup.ico");
            this.imlToolBar.Images.SetKeyName(146, "2.10.1_AlarmSetup.ico");
            this.imlToolBar.Images.SetKeyName(147, "2.10.2_AttachAlarmToMFO.ico");
            this.imlToolBar.Images.SetKeyName(148, "2.10.2_AttachAlarmToResource.ico");
            this.imlToolBar.Images.SetKeyName(149, "2.12_AttributeSetup.ico");
            this.imlToolBar.Images.SetKeyName(150, "2.14.1_ServiceMemberSetup.ico");
            this.imlToolBar.Images.SetKeyName(151, "2.14.2_MemberSetup.ico");
            this.imlToolBar.Images.SetKeyName(152, "2.15.1_WIPModeler.ico");
            this.imlToolBar.Images.SetKeyName(153, "2.15.2_RASModeler.ico");
            this.imlToolBar.Images.SetKeyName(154, "3.2.1_InInventory.ico");
            this.imlToolBar.Images.SetKeyName(155, "3.2.2_OutInventory.ico");
            this.imlToolBar.Images.SetKeyName(156, "3.2.3_TransferInventory.ico");
            this.imlToolBar.Images.SetKeyName(157, "3.2.4_ConvertInventoryTypetoLot.ico");
            this.imlToolBar.Images.SetKeyName(158, "3.2.5_ConvertLottoInventoryType.ico");
            this.imlToolBar.Images.SetKeyName(159, "3.2.6_Consume.ico");
            this.imlToolBar.Images.SetKeyName(160, "3.2.7_Scrap.ico");
            this.imlToolBar.Images.SetKeyName(161, "3.2.8_DeleteInventoryHistory.ico");
            this.imlToolBar.Images.SetKeyName(162, "3.3.1_Assmble.ico");
            this.imlToolBar.Images.SetKeyName(163, "3.3.4_DeleteBOMHistory.ico");
            this.imlToolBar.Images.SetKeyName(164, "3.5.1_CollectLotData.ico");
            this.imlToolBar.Images.SetKeyName(165, "3.5.2_ChangeLotData.ico");
            this.imlToolBar.Images.SetKeyName(166, "3.5.3_ChangeResourceData.ico");
            this.imlToolBar.Images.SetKeyName(167, "3.5.4_DeleteLotDataHistory.ico");
            this.imlToolBar.Images.SetKeyName(168, "3.5.5_DeleteResourceDataHistory.ico");
            this.imlToolBar.Images.SetKeyName(169, "3.6.1_StartSubLot.ico");
            this.imlToolBar.Images.SetKeyName(170, "3.6.2_EndSubLot.ico");
            this.imlToolBar.Images.SetKeyName(171, "3.6.3_ReworkSub-Lot.ico");
            this.imlToolBar.Images.SetKeyName(172, "3.6.4_DeleteSub-LotHistory.ico");
            this.imlToolBar.Images.SetKeyName(173, "3.6.5_SplitExtension.ico");
            this.imlToolBar.Images.SetKeyName(174, "3.6.6_MergeExtension.ico");
            this.imlToolBar.Images.SetKeyName(175, "3.6.7_CombineEctension.ico");
            this.imlToolBar.Images.SetKeyName(176, "3.6.8_LossExtension.ico");
            this.imlToolBar.Images.SetKeyName(177, "3.6.9_Sort Extension.ico");
            this.imlToolBar.Images.SetKeyName(178, "3.8.1_RaiseAlarm.ico");
            this.imlToolBar.Images.SetKeyName(179, "3.8.2_ClearAlarm.ico");
            this.imlToolBar.Images.SetKeyName(180, "3.10.1_AdjustLotPriority.ico");
            this.imlToolBar.Images.SetKeyName(181, "3.10.2_ManualRe-DispatchLot.ico");
            this.imlToolBar.Images.SetKeyName(182, "3.11.1_LotLabelPrint.ico");
            this.imlToolBar.Images.SetKeyName(183, "3.12.1_InputAttributeValue.ico");
            this.imlToolBar.Images.SetKeyName(184, "3.12.2_ChangeCMFValue.ico");
            this.imlToolBar.Images.SetKeyName(185, "4.1.1_ViewLotStatus.ico");
            this.imlToolBar.Images.SetKeyName(186, "4.1.2_ViewLotHistory1.ico");
            this.imlToolBar.Images.SetKeyName(187, "4.1.2_ViewLotHistory.ico");
            this.imlToolBar.Images.SetKeyName(188, "4.4.1_ViewResourceStatus.ico");
            this.imlToolBar.Images.SetKeyName(189, "4.4.2_ViewResourceHistory.ico");
            this.imlToolBar.Images.SetKeyName(190, "4.4.3_ViewPortHistory.ico");
            this.imlToolBar.Images.SetKeyName(191, "4.4.3_ViewSubResourceHistory.ico");
            this.imlToolBar.Images.SetKeyName(192, "4.4.4_ViewResourceListbyGroup.ico");
            this.imlToolBar.Images.SetKeyName(193, "4.4.5_ViewResourceListbyMFO.ico");
            this.imlToolBar.Images.SetKeyName(194, "4.4.6_ViewLotListbyResource.ico");
            this.imlToolBar.Images.SetKeyName(195, "4.4.7_ViewEventListbyEventGroup.ico");
            this.imlToolBar.Images.SetKeyName(196, "4.4.8_ViewLotListbyResourceGroup.ico");
            this.imlToolBar.Images.SetKeyName(197, "4.4.9_ViewResourceDownHistory.ico");
            this.imlToolBar.Images.SetKeyName(198, "4.4.10_ViewResourceLabor.ico");
            this.imlToolBar.Images.SetKeyName(199, "4.4.11_ViewCarrierStatus.ico");
            this.imlToolBar.Images.SetKeyName(200, "4.4.12_ViewCarrierHistory.ico");
            this.imlToolBar.Images.SetKeyName(201, "4.4.13_viewCarrierHistroybyLot.ico");
            this.imlToolBar.Images.SetKeyName(202, "4.4.14_ViewCarrierLotList.ico");
            this.imlToolBar.Images.SetKeyName(203, "4.4.17_ViewTool.ico");
            this.imlToolBar.Images.SetKeyName(204, "4.4.18_ViewToolList.ico");
            this.imlToolBar.Images.SetKeyName(205, "4.4.19_ViewToolListbyOperation.ico");
            this.imlToolBar.Images.SetKeyName(206, "4.4.20_ViewToolListbyResource.ico");
            this.imlToolBar.Images.SetKeyName(207, "4.4.21_ViewToolHistory.ico");
            this.imlToolBar.Images.SetKeyName(208, "4.4.22_ViewToolDefectData.ico");
            this.imlToolBar.Images.SetKeyName(209, "4.4.24_ViewCheckResult.ico");
            this.imlToolBar.Images.SetKeyName(210, "4.5.1_ViewLotData.ico");
            this.imlToolBar.Images.SetKeyName(211, "4.7.1_ViewAlarmHistory.ico");
            this.imlToolBar.Images.SetKeyName(212, "4.8.1_ViewLotRecipeHistory.ico");
            this.imlToolBar.Images.SetKeyName(213, "5.1.1_ProductionOrderSetup.ico");
            this.imlToolBar.Images.SetKeyName(214, "5.1.1_ProductionPlanSetup.ico");
            this.imlToolBar.Images.SetKeyName(215, "5.1.3_PlannedLotSetup.ico");
            this.imlToolBar.Images.SetKeyName(216, "5.1.4_WorkOrderSetup.ico");
            this.imlToolBar.Images.SetKeyName(217, "5.1.5_ViewProductionOrder.ico");
            this.imlToolBar.Images.SetKeyName(218, "5.1.6_ViewProductionPlan.ico");
            this.imlToolBar.Images.SetKeyName(219, "5.1.7_ViewPlannedLot.ico");
            this.imlToolBar.Images.SetKeyName(220, "5.1.8_ViewWorkOrder.ico");
            this.imlToolBar.Images.SetKeyName(221, "5.1.9_CreateLotBasedonOrder.ico");
            this.imlToolBar.Images.SetKeyName(222, "5.1.10_CreateLotBasedonPlan.ico");
            this.imlToolBar.Images.SetKeyName(223, "5.1.11_CreatePlannedLot.ico");
            this.imlToolBar.Images.SetKeyName(224, "5.1.12_AttachLotToOrder.ico");
            this.imlToolBar.Images.SetKeyName(225, "6.1.1_ChartSetup.ico");
            this.imlToolBar.Images.SetKeyName(226, "6.1.2_SpecManagement.ico");
            this.imlToolBar.Images.SetKeyName(227, "6.1.3_AttachUsertoChart.ico");
            this.imlToolBar.Images.SetKeyName(228, "6.1.4_ChartSetSetup.ico");
            this.imlToolBar.Images.SetKeyName(229, "6.1.5_TroubleandActionCodeSetup.ico");
            this.imlToolBar.Images.SetKeyName(230, "6.2.1_RealtimeMonitoringControlChart.ico");
            this.imlToolBar.Images.SetKeyName(231, "6.2.3_ControlChart.ico");
            this.imlToolBar.Images.SetKeyName(232, "6.2.4_CapabilityAnalysis.ico");
            this.imlToolBar.Images.SetKeyName(233, "6.2.12_MultiRealtimeMonitoringControlChart.ico");
            this.imlToolBar.Images.SetKeyName(234, "6.3.1_ViewEDCData.ico");
            this.imlToolBar.Images.SetKeyName(235, "6.3.3_ViewOOCHistory.ico");
            this.imlToolBar.Images.SetKeyName(236, "6.3.4_ViewProcessCapability.ico");
            this.imlToolBar.Images.SetKeyName(237, "6.3.5_ViewExcludedEDCHistory.ico");
            this.imlToolBar.Images.SetKeyName(238, "6.3.6_ViewChartList.ico");
            this.imlToolBar.Images.SetKeyName(239, "7.4.3_ZoomOut.ico");
            this.imlToolBar.Images.SetKeyName(240, "7.1.1_SaveLayoutConfiguration.ico");
            this.imlToolBar.Images.SetKeyName(241, "7.2.1_GlobalOptionSetup.ico");
            this.imlToolBar.Images.SetKeyName(242, "7.2.2._ResourceImageSetup.ico");
            this.imlToolBar.Images.SetKeyName(243, "7.2.3_NewLayout.ico");
            this.imlToolBar.Images.SetKeyName(244, "7.2.4_NewUserDesign.ico");
            this.imlToolBar.Images.SetKeyName(245, "7.3.1_DesignMode.ico");
            this.imlToolBar.Images.SetKeyName(246, "7.3.2_SaveDesign.ico");
            this.imlToolBar.Images.SetKeyName(247, "7.3.3_AddMultiResource.ico");
            this.imlToolBar.Images.SetKeyName(248, "7.4.1_Reload.ico");
            this.imlToolBar.Images.SetKeyName(249, "7.4.2_ZoomIn.ico");
            this.imlToolBar.Images.SetKeyName(250, "2.9.6_DispatchEventConfigurationSetup.ico");
            // 
            // pgbMain
            // 
            this.pgbMain.Value = 100;
            this.pgbMain.Location = new System.Drawing.Point(2, 718);
            
            // 
            // trvDesignList
            // 
            this.trvDesignList.ContextMenu = this.mnuDesignList;
            this.trvDesignList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.trvDesignList.HideSelection = false;
            this.trvDesignList.Location = new System.Drawing.Point(0, 18);
            this.trvDesignList.Name = "trvDesignList";
            this.trvDesignList.Size = new System.Drawing.Size(187, 302);
            this.trvDesignList.TabIndex = 47;
            this.trvDesignList.MouseUp += new System.Windows.Forms.MouseEventHandler(this.trvDesignList_MouseUp);
            this.trvDesignList.MouseMove += new System.Windows.Forms.MouseEventHandler(this.trvDesignList_MouseMove);
            this.trvDesignList.MouseDown += new System.Windows.Forms.MouseEventHandler(this.trvDesignList_MouseDown);
            this.trvDesignList.Click += new System.EventHandler(this.trvDesignList_Click);
            // 
            // mnuDesignList
            // 
            this.mnuDesignList.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.mnuRefreshDesignList,
            this.mnuDeleteResource,
            this.mnuUpdateLayout,
            this.mnuUpdateUserGroupDesign,
            this.mnuProperties,
            this.mnuSeperator1,
            this.mnuViewResourceStatus,
            this.mnuViewResourceHistory,
            this.mnuTranEvent,
            this.mnuDeleteFile});
            this.mnuDesignList.Popup += new System.EventHandler(this.mnuDesignList_Popup);
            // 
            // mnuRefreshDesignList
            // 
            this.mnuRefreshDesignList.Index = 0;
            this.mnuRefreshDesignList.Text = "Refresh Design List";
            this.mnuRefreshDesignList.Click += new System.EventHandler(this.mnuRefreshDesignList_Click);
            // 
            // mnuDeleteResource
            // 
            this.mnuDeleteResource.Index = 1;
            this.mnuDeleteResource.Text = "Delete Resource";
            this.mnuDeleteResource.Click += new System.EventHandler(this.mnuDeleteResource_Click);
            // 
            // mnuUpdateLayout
            // 
            this.mnuUpdateLayout.Index = 2;
            this.mnuUpdateLayout.Text = "Update Layout";
            this.mnuUpdateLayout.Click += new System.EventHandler(this.mnuUpdateLayout_Click);
            // 
            // mnuUpdateUserGroupDesign
            // 
            this.mnuUpdateUserGroupDesign.Index = 3;
            this.mnuUpdateUserGroupDesign.Text = "Update User Group Design";
            this.mnuUpdateUserGroupDesign.Click += new System.EventHandler(this.mnuUpdateUserGroupDesign_Click);
            // 
            // mnuProperties
            // 
            this.mnuProperties.Index = 4;
            this.mnuProperties.Text = "Properties";
            this.mnuProperties.Click += new System.EventHandler(this.mnuProperties_Click);
            // 
            // mnuSeperator1
            // 
            this.mnuSeperator1.Index = 5;
            this.mnuSeperator1.Text = "-";
            // 
            // mnuViewResourceStatus
            // 
            this.mnuViewResourceStatus.Index = 6;
            this.mnuViewResourceStatus.Text = "View Resource Status";
            this.mnuViewResourceStatus.Click += new System.EventHandler(this.mnuViewResourceStatus_Click);
            // 
            // mnuViewResourceHistory
            // 
            this.mnuViewResourceHistory.Index = 7;
            this.mnuViewResourceHistory.Text = "View Resource History";
            this.mnuViewResourceHistory.Click += new System.EventHandler(this.mnuViewResourceHistory_Click);
            // 
            // mnuTranEvent
            // 
            this.mnuTranEvent.Index = 8;
            this.mnuTranEvent.Text = "Event";
            this.mnuTranEvent.Click += new System.EventHandler(this.mnuTranEvent_Click);
            // 
            // mnuDeleteFile
            // 
            this.mnuDeleteFile.Index = 9;
            this.mnuDeleteFile.Text = "Delete File";
            this.mnuDeleteFile.Click += new System.EventHandler(this.mnuDeleteFile_Click);
            // 
            // lisTools
            // 
            this.lisTools.Alignment = System.Windows.Forms.ListViewAlignment.Left;
            this.lisTools.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lisTools.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colTools});
            this.lisTools.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisTools.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.None;
            this.lisTools.HideSelection = false;
            listViewItem1.StateImageIndex = 0;
            listViewItem1.Tag = "0";
            listViewItem2.Tag = "11";
            listViewItem3.Tag = "12";
            listViewItem4.Tag = "13";
            listViewItem5.Checked = true;
            listViewItem5.StateImageIndex = 1;
            listViewItem5.Tag = "1";
            listViewItem6.Checked = true;
            listViewItem6.StateImageIndex = 2;
            listViewItem6.Tag = "2";
            listViewItem7.Checked = true;
            listViewItem7.StateImageIndex = 3;
            listViewItem7.Tag = "3";
            listViewItem8.Checked = true;
            listViewItem8.StateImageIndex = 4;
            listViewItem8.Tag = "4";
            listViewItem9.Checked = true;
            listViewItem9.StateImageIndex = 5;
            listViewItem9.Tag = "5";
            listViewItem10.Checked = true;
            listViewItem10.StateImageIndex = 6;
            listViewItem10.Tag = "6";
            listViewItem11.Checked = true;
            listViewItem11.StateImageIndex = 7;
            listViewItem11.Tag = "7";
            listViewItem12.Checked = true;
            listViewItem12.StateImageIndex = 8;
            listViewItem12.Tag = "8";
            listViewItem13.Checked = true;
            listViewItem13.StateImageIndex = 9;
            listViewItem13.Tag = "9";
            listViewItem14.Checked = true;
            listViewItem14.StateImageIndex = 10;
            listViewItem14.Tag = "10";
            this.lisTools.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2,
            listViewItem3,
            listViewItem4,
            listViewItem5,
            listViewItem6,
            listViewItem7,
            listViewItem8,
            listViewItem9,
            listViewItem10,
            listViewItem11,
            listViewItem12,
            listViewItem13,
            listViewItem14});
            this.lisTools.Location = new System.Drawing.Point(0, 18);
            this.lisTools.MultiSelect = false;
            this.lisTools.Name = "lisTools";
            this.lisTools.Size = new System.Drawing.Size(187, 322);
            this.lisTools.SmallImageList = this.imlTools;
            this.lisTools.TabIndex = 19;
            this.lisTools.UseCompatibleStateImageBehavior = false;
            this.lisTools.View = System.Windows.Forms.View.List;
            this.lisTools.MouseUp += new System.Windows.Forms.MouseEventHandler(this.lisTools_MouseUp);
            this.lisTools.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.lisTools_ItemDrag);
            // 
            // colTools
            // 
            this.colTools.Text = "Tools";
            this.colTools.Width = 120;
            // 
            // imlTools
            // 
            this.imlTools.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imlTools.ImageStream")));
            this.imlTools.TransparentColor = System.Drawing.Color.Transparent;
            this.imlTools.Images.SetKeyName(0, "");
            this.imlTools.Images.SetKeyName(1, "");
            this.imlTools.Images.SetKeyName(2, "");
            this.imlTools.Images.SetKeyName(3, "");
            this.imlTools.Images.SetKeyName(4, "");
            this.imlTools.Images.SetKeyName(5, "");
            this.imlTools.Images.SetKeyName(6, "");
            this.imlTools.Images.SetKeyName(7, "");
            this.imlTools.Images.SetKeyName(8, "");
            this.imlTools.Images.SetKeyName(9, "");
            this.imlTools.Images.SetKeyName(10, "");
            this.imlTools.Images.SetKeyName(11, "sub.jpg");
            this.imlTools.Images.SetKeyName(12, "port.jpg");
            this.imlTools.Images.SetKeyName(13, "tool.jpg");
            // 
            // utmmMDIMain
            // 
            this.utmmMDIMain.MdiParent = this;
            this.utmmMDIMain.TabGroupSettings.ButtonStyle = Infragistics.Win.UIElementButtonStyle.VisualStudio2005Button;
            this.utmmMDIMain.TabGroupSettings.ScrollArrowStyle = Infragistics.Win.UltraWinTabs.ScrollArrowStyle.VisualStudio;
            this.utmmMDIMain.TabGroupSettings.ScrollButtons = Infragistics.Win.UltraWinTabbedMdi.DefaultableTabScrollButtons.Automatic;
            this.utmmMDIMain.TabGroupSettings.TabButtonStyle = Infragistics.Win.UIElementButtonStyle.VisualStudio2005Button;
            this.utmmMDIMain.TabGroupSettings.TabStyle = Infragistics.Win.UltraWinTabs.TabStyle.VisualStudio2005;
            this.utmmMDIMain.UseMnemonics = true;
            this.utmmMDIMain.ViewStyle = Infragistics.Win.UltraWinTabbedMdi.ViewStyle.VisualStudio2005;
            // 
            // udmMDIMain
            // 
            dockAreaPane1.DockedBefore = new System.Guid("85b1e5d3-b597-4d04-b704-f7fa1c49dd3d");
            dockAreaPane1.FloatingLocation = new System.Drawing.Point(327, 255);
            dockableControlPane1.Control = this.trvDesignList;
            dockableControlPane1.Key = "DESIGN_LIST";
            dockableControlPane1.OriginalControlBounds = new System.Drawing.Rectangle(248, 156, 160, 280);
            dockableControlPane1.Size = new System.Drawing.Size(187, 306);
            dockableControlPane1.Text = "Design List";
            dockableControlPane2.Control = this.lisTools;
            dockableControlPane2.Key = "TOOLS_LIST";
            dockableControlPane2.OriginalControlBounds = new System.Drawing.Rectangle(360, 116, 160, 232);
            dockableControlPane2.Size = new System.Drawing.Size(187, 327);
            dockableControlPane2.Text = "Tools List";
            dockAreaPane1.Panes.AddRange(new Infragistics.Win.UltraWinDock.DockablePaneBase[] {
            dockableControlPane1,
            dockableControlPane2});
            dockAreaPane1.Size = new System.Drawing.Size(187, 665);
            dockAreaPane2.ChildPaneStyle = Infragistics.Win.UltraWinDock.ChildPaneStyle.TabGroup;
            dockAreaPane2.DockedBefore = new System.Guid("e4d7c431-9633-4e11-b469-e22a5679db55");
            dockAreaPane2.FloatingLocation = new System.Drawing.Point(327, 255);
            dockAreaPane2.Size = new System.Drawing.Size(187, 671);
            dockAreaPane3.ChildPaneStyle = Infragistics.Win.UltraWinDock.ChildPaneStyle.TabGroup;
            dockAreaPane3.FloatingLocation = new System.Drawing.Point(338, 316);
            dockAreaPane3.Size = new System.Drawing.Size(187, 355);
            this.udmMDIMain.DockAreas.AddRange(new Infragistics.Win.UltraWinDock.DockAreaPane[] {
            dockAreaPane1,
            dockAreaPane2,
            dockAreaPane3});
            this.udmMDIMain.HostControl = this;
            // 
            // _frmMDIMainUnpinnedTabAreaLeft
            // 
            this._frmMDIMainUnpinnedTabAreaLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this._frmMDIMainUnpinnedTabAreaLeft.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainUnpinnedTabAreaLeft.Location = new System.Drawing.Point(0, 49);
            this._frmMDIMainUnpinnedTabAreaLeft.Name = "_frmMDIMainUnpinnedTabAreaLeft";
            this._frmMDIMainUnpinnedTabAreaLeft.Owner = this.udmMDIMain;
            this._frmMDIMainUnpinnedTabAreaLeft.Size = new System.Drawing.Size(0, 665);
            this._frmMDIMainUnpinnedTabAreaLeft.TabIndex = 5;
            // 
            // _frmMDIMainUnpinnedTabAreaRight
            // 
            this._frmMDIMainUnpinnedTabAreaRight.Dock = System.Windows.Forms.DockStyle.Right;
            this._frmMDIMainUnpinnedTabAreaRight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainUnpinnedTabAreaRight.Location = new System.Drawing.Point(1016, 49);
            this._frmMDIMainUnpinnedTabAreaRight.Name = "_frmMDIMainUnpinnedTabAreaRight";
            this._frmMDIMainUnpinnedTabAreaRight.Owner = this.udmMDIMain;
            this._frmMDIMainUnpinnedTabAreaRight.Size = new System.Drawing.Size(0, 665);
            this._frmMDIMainUnpinnedTabAreaRight.TabIndex = 6;
            // 
            // _frmMDIMainUnpinnedTabAreaTop
            // 
            this._frmMDIMainUnpinnedTabAreaTop.Dock = System.Windows.Forms.DockStyle.Top;
            this._frmMDIMainUnpinnedTabAreaTop.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainUnpinnedTabAreaTop.Location = new System.Drawing.Point(0, 49);
            this._frmMDIMainUnpinnedTabAreaTop.Name = "_frmMDIMainUnpinnedTabAreaTop";
            this._frmMDIMainUnpinnedTabAreaTop.Owner = this.udmMDIMain;
            this._frmMDIMainUnpinnedTabAreaTop.Size = new System.Drawing.Size(1016, 0);
            this._frmMDIMainUnpinnedTabAreaTop.TabIndex = 7;
            // 
            // _frmMDIMainUnpinnedTabAreaBottom
            // 
            this._frmMDIMainUnpinnedTabAreaBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this._frmMDIMainUnpinnedTabAreaBottom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainUnpinnedTabAreaBottom.Location = new System.Drawing.Point(0, 714);
            this._frmMDIMainUnpinnedTabAreaBottom.Name = "_frmMDIMainUnpinnedTabAreaBottom";
            this._frmMDIMainUnpinnedTabAreaBottom.Owner = this.udmMDIMain;
            this._frmMDIMainUnpinnedTabAreaBottom.Size = new System.Drawing.Size(1016, 0);
            this._frmMDIMainUnpinnedTabAreaBottom.TabIndex = 8;
            // 
            // _frmMDIMainAutoHideControl
            // 
            this._frmMDIMainAutoHideControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this._frmMDIMainAutoHideControl.Location = new System.Drawing.Point(21, 23);
            this._frmMDIMainAutoHideControl.Name = "_frmMDIMainAutoHideControl";
            this._frmMDIMainAutoHideControl.Owner = this.udmMDIMain;
            this._frmMDIMainAutoHideControl.Size = new System.Drawing.Size(194, 718);
            this._frmMDIMainAutoHideControl.TabIndex = 9;
            // 
            // DockableWindow1
            // 
            this.DockableWindow1.Controls.Add(this.trvDesignList);
            this.DockableWindow1.Location = new System.Drawing.Point(0, 0);
            this.DockableWindow1.Name = "DockableWindow1";
            this.DockableWindow1.Owner = this.udmMDIMain;
            this.DockableWindow1.Size = new System.Drawing.Size(187, 320);
            this.DockableWindow1.TabIndex = 61;
            // 
            // DockableWindow2
            // 
            this.DockableWindow2.Controls.Add(this.lisTools);
            this.DockableWindow2.Location = new System.Drawing.Point(0, 325);
            this.DockableWindow2.Name = "DockableWindow2";
            this.DockableWindow2.Owner = this.udmMDIMain;
            this.DockableWindow2.Size = new System.Drawing.Size(187, 340);
            this.DockableWindow2.TabIndex = 62;
            // 
            // WindowDockingArea3
            // 
            this.WindowDockingArea3.Controls.Add(this.DockableWindow1);
            this.WindowDockingArea3.Controls.Add(this.DockableWindow2);
            this.WindowDockingArea3.Dock = System.Windows.Forms.DockStyle.Left;
            this.WindowDockingArea3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WindowDockingArea3.Location = new System.Drawing.Point(0, 49);
            this.WindowDockingArea3.Name = "WindowDockingArea3";
            this.WindowDockingArea3.Owner = this.udmMDIMain;
            this.WindowDockingArea3.Size = new System.Drawing.Size(192, 665);
            this.WindowDockingArea3.TabIndex = 0;
            // 
            // WindowDockingArea1
            // 
            this.WindowDockingArea1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.WindowDockingArea1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WindowDockingArea1.Location = new System.Drawing.Point(4, 4);
            this.WindowDockingArea1.Name = "WindowDockingArea1";
            this.WindowDockingArea1.Owner = this.udmMDIMain;
            this.WindowDockingArea1.Size = new System.Drawing.Size(187, 671);
            this.WindowDockingArea1.TabIndex = 0;
            // 
            // WindowDockingArea4
            // 
            this.WindowDockingArea4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.WindowDockingArea4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WindowDockingArea4.Location = new System.Drawing.Point(0, 50);
            this.WindowDockingArea4.Name = "WindowDockingArea4";
            this.WindowDockingArea4.Owner = this.udmMDIMain;
            this.WindowDockingArea4.Size = new System.Drawing.Size(187, 355);
            this.WindowDockingArea4.TabIndex = 49;
            // 
            // imlResource
            // 
            this.imlResource.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.imlResource.ImageSize = new System.Drawing.Size(32, 32);
            this.imlResource.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // tolMain
            // 
            this.tolMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbLefts,
            this.tsbCenter,
            this.tsbRight,
            this.tsbTops,
            this.tsbMiddles,
            this.tsbBottoms,
            this.tsbWidth,
            this.tsbHeight,
            this.tsbBoth,
            this.tsbHMakeEqual,
            this.tsbHIncrease,
            this.tsbHDecrease,
            this.tsbHRemove,
            this.tsbVMakeEqual,
            this.tsbVIncrease,
            this.tsbVDecrease,
            this.tsbVRemove,
            this.tsbBring,
            this.tsbSend,
            this.toolStripSeparator6,
            this.tsbDesignMode,
            this.tsbSaveDesign,
            this.toolStripSeparator10});
            this.tolMain.Location = new System.Drawing.Point(0, 24);
            this.tolMain.Name = "tolMain";
            this.tolMain.Size = new System.Drawing.Size(1016, 25);
            this.tolMain.TabIndex = 59;
            // 
            // tsbLefts
            // 
            this.tsbLefts.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbLefts.Image = ((System.Drawing.Image)(resources.GetObject("tsbLefts.Image")));
            this.tsbLefts.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbLefts.Name = "tsbLefts";
            this.tsbLefts.Size = new System.Drawing.Size(23, 22);
            this.tsbLefts.ToolTipText = "Lefts";
            // 
            // tsbCenter
            // 
            this.tsbCenter.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbCenter.Image = ((System.Drawing.Image)(resources.GetObject("tsbCenter.Image")));
            this.tsbCenter.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbCenter.Name = "tsbCenter";
            this.tsbCenter.Size = new System.Drawing.Size(23, 22);
            this.tsbCenter.Text = "Centers";
            // 
            // tsbRight
            // 
            this.tsbRight.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbRight.Image = ((System.Drawing.Image)(resources.GetObject("tsbRight.Image")));
            this.tsbRight.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbRight.Name = "tsbRight";
            this.tsbRight.Size = new System.Drawing.Size(23, 22);
            this.tsbRight.Text = "Rights";
            // 
            // tsbTops
            // 
            this.tsbTops.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTops.Image = ((System.Drawing.Image)(resources.GetObject("tsbTops.Image")));
            this.tsbTops.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTops.Name = "tsbTops";
            this.tsbTops.Size = new System.Drawing.Size(23, 22);
            this.tsbTops.Text = "Tops";
            // 
            // tsbMiddles
            // 
            this.tsbMiddles.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbMiddles.Image = ((System.Drawing.Image)(resources.GetObject("tsbMiddles.Image")));
            this.tsbMiddles.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbMiddles.Name = "tsbMiddles";
            this.tsbMiddles.Size = new System.Drawing.Size(23, 22);
            this.tsbMiddles.Text = "Middles";
            this.tsbMiddles.ToolTipText = "Middles";
            // 
            // tsbBottoms
            // 
            this.tsbBottoms.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBottoms.Image = ((System.Drawing.Image)(resources.GetObject("tsbBottoms.Image")));
            this.tsbBottoms.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBottoms.Name = "tsbBottoms";
            this.tsbBottoms.Size = new System.Drawing.Size(23, 22);
            this.tsbBottoms.Text = "Bottoms";
            // 
            // tsbWidth
            // 
            this.tsbWidth.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbWidth.Image = ((System.Drawing.Image)(resources.GetObject("tsbWidth.Image")));
            this.tsbWidth.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbWidth.Name = "tsbWidth";
            this.tsbWidth.Size = new System.Drawing.Size(23, 22);
            this.tsbWidth.Text = "Width";
            // 
            // tsbHeight
            // 
            this.tsbHeight.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHeight.Image = ((System.Drawing.Image)(resources.GetObject("tsbHeight.Image")));
            this.tsbHeight.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHeight.Name = "tsbHeight";
            this.tsbHeight.Size = new System.Drawing.Size(23, 22);
            this.tsbHeight.Text = "Height";
            // 
            // tsbBoth
            // 
            this.tsbBoth.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBoth.Image = ((System.Drawing.Image)(resources.GetObject("tsbBoth.Image")));
            this.tsbBoth.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBoth.Name = "tsbBoth";
            this.tsbBoth.Size = new System.Drawing.Size(23, 22);
            this.tsbBoth.Text = "Both";
            // 
            // tsbHMakeEqual
            // 
            this.tsbHMakeEqual.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHMakeEqual.Image = ((System.Drawing.Image)(resources.GetObject("tsbHMakeEqual.Image")));
            this.tsbHMakeEqual.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHMakeEqual.Name = "tsbHMakeEqual";
            this.tsbHMakeEqual.Size = new System.Drawing.Size(23, 22);
            this.tsbHMakeEqual.Text = "Make Equal";
            // 
            // tsbHIncrease
            // 
            this.tsbHIncrease.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHIncrease.Image = ((System.Drawing.Image)(resources.GetObject("tsbHIncrease.Image")));
            this.tsbHIncrease.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHIncrease.Name = "tsbHIncrease";
            this.tsbHIncrease.Size = new System.Drawing.Size(23, 22);
            this.tsbHIncrease.Text = "Increase";
            // 
            // tsbHDecrease
            // 
            this.tsbHDecrease.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHDecrease.Image = ((System.Drawing.Image)(resources.GetObject("tsbHDecrease.Image")));
            this.tsbHDecrease.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHDecrease.Name = "tsbHDecrease";
            this.tsbHDecrease.Size = new System.Drawing.Size(23, 22);
            this.tsbHDecrease.Text = "Decrease";
            // 
            // tsbHRemove
            // 
            this.tsbHRemove.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHRemove.Image = ((System.Drawing.Image)(resources.GetObject("tsbHRemove.Image")));
            this.tsbHRemove.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHRemove.Name = "tsbHRemove";
            this.tsbHRemove.Size = new System.Drawing.Size(23, 22);
            this.tsbHRemove.Text = "Remove";
            // 
            // tsbVMakeEqual
            // 
            this.tsbVMakeEqual.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbVMakeEqual.Image = ((System.Drawing.Image)(resources.GetObject("tsbVMakeEqual.Image")));
            this.tsbVMakeEqual.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbVMakeEqual.Name = "tsbVMakeEqual";
            this.tsbVMakeEqual.Size = new System.Drawing.Size(23, 22);
            this.tsbVMakeEqual.Text = "Make Equal";
            this.tsbVMakeEqual.ToolTipText = "Make Equal";
            // 
            // tsbVIncrease
            // 
            this.tsbVIncrease.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbVIncrease.Image = ((System.Drawing.Image)(resources.GetObject("tsbVIncrease.Image")));
            this.tsbVIncrease.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbVIncrease.Name = "tsbVIncrease";
            this.tsbVIncrease.Size = new System.Drawing.Size(23, 22);
            this.tsbVIncrease.Text = "Increase";
            // 
            // tsbVDecrease
            // 
            this.tsbVDecrease.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbVDecrease.Image = ((System.Drawing.Image)(resources.GetObject("tsbVDecrease.Image")));
            this.tsbVDecrease.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbVDecrease.Name = "tsbVDecrease";
            this.tsbVDecrease.Size = new System.Drawing.Size(23, 22);
            this.tsbVDecrease.Text = "Decrease";
            // 
            // tsbVRemove
            // 
            this.tsbVRemove.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbVRemove.Image = ((System.Drawing.Image)(resources.GetObject("tsbVRemove.Image")));
            this.tsbVRemove.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbVRemove.Name = "tsbVRemove";
            this.tsbVRemove.Size = new System.Drawing.Size(23, 22);
            this.tsbVRemove.Text = "Remove";
            // 
            // tsbBring
            // 
            this.tsbBring.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBring.Image = ((System.Drawing.Image)(resources.GetObject("tsbBring.Image")));
            this.tsbBring.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBring.Name = "tsbBring";
            this.tsbBring.Size = new System.Drawing.Size(23, 22);
            this.tsbBring.Text = "Bring To Front";
            // 
            // tsbSend
            // 
            this.tsbSend.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbSend.Image = ((System.Drawing.Image)(resources.GetObject("tsbSend.Image")));
            this.tsbSend.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbSend.Name = "tsbSend";
            this.tsbSend.Size = new System.Drawing.Size(23, 22);
            this.tsbSend.Text = "Send To Back";
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbDesignMode
            // 
            this.tsbDesignMode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbDesignMode.Image = ((System.Drawing.Image)(resources.GetObject("tsbDesignMode.Image")));
            this.tsbDesignMode.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbDesignMode.Name = "tsbDesignMode";
            this.tsbDesignMode.Size = new System.Drawing.Size(23, 22);
            this.tsbDesignMode.Text = "Design Mode";
            // 
            // tsbSaveDesign
            // 
            this.tsbSaveDesign.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbSaveDesign.Image = ((System.Drawing.Image)(resources.GetObject("tsbSaveDesign.Image")));
            this.tsbSaveDesign.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbSaveDesign.Name = "tsbSaveDesign";
            this.tsbSaveDesign.Size = new System.Drawing.Size(23, 22);
            this.tsbSaveDesign.Text = "Save Design";
            // 
            // toolStripSeparator10
            // 
            this.toolStripSeparator10.Name = "toolStripSeparator10";
            this.toolStripSeparator10.Size = new System.Drawing.Size(6, 25);
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
            this.mnuMain.Size = new System.Drawing.Size(1016, 24);
            this.mnuMain.TabIndex = 58;
            // 
            // tsmTopSystem
            // 
            this.tsmTopSystem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmLogout,
            this.tsmSaveConfig,
            this.toolStripSeparator1,
            this.tsmClientUpgrade,
            this.toolStripSeparator2,
            this.tsmOption,
            this.tsmExit,
            this.toolStripSeparator5,
            this.tsmDesignList,
            this.tsmToolsList});
            this.tsmTopSystem.Name = "tsmTopSystem";
            this.tsmTopSystem.Size = new System.Drawing.Size(60, 20);
            this.tsmTopSystem.Text = "System";
            // 
            // tsmLogout
            // 
            this.tsmLogout.Name = "tsmLogout";
            this.tsmLogout.ShortcutKeys = System.Windows.Forms.Keys.F2;
            this.tsmLogout.Size = new System.Drawing.Size(182, 22);
            this.tsmLogout.Text = "Log Out";
            this.tsmLogout.Click += new System.EventHandler(this.tsmLogout_Click);
            // 
            // tsmSaveConfig
            // 
            this.tsmSaveConfig.Name = "tsmSaveConfig";
            this.tsmSaveConfig.Size = new System.Drawing.Size(182, 22);
            this.tsmSaveConfig.Text = "Save Configuration";
            this.tsmSaveConfig.Click += new System.EventHandler(this.tsmSaveConfig_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(179, 6);
            // 
            // tsmClientUpgrade
            // 
            this.tsmClientUpgrade.Name = "tsmClientUpgrade";
            this.tsmClientUpgrade.Size = new System.Drawing.Size(182, 22);
            this.tsmClientUpgrade.Text = "Client Upgrade";
            this.tsmClientUpgrade.Click += new System.EventHandler(this.tsmClientUpgrade_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(179, 6);
            // 
            // tsmOption
            // 
            this.tsmOption.Name = "tsmOption";
            this.tsmOption.Size = new System.Drawing.Size(182, 22);
            this.tsmOption.Text = "Option";
            this.tsmOption.Click += new System.EventHandler(this.tsmOption_Click);
            // 
            // tsmExit
            // 
            this.tsmExit.Name = "tsmExit";
            this.tsmExit.Size = new System.Drawing.Size(182, 22);
            this.tsmExit.Text = "Exit";
            this.tsmExit.Click += new System.EventHandler(this.tsmExit_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(179, 6);
            // 
            // tsmDesignList
            // 
            this.tsmDesignList.Name = "tsmDesignList";
            this.tsmDesignList.Size = new System.Drawing.Size(182, 22);
            this.tsmDesignList.Text = "Design List";
            this.tsmDesignList.Click += new System.EventHandler(this.tsmDesignList_Click);
            // 
            // tsmToolsList
            // 
            this.tsmToolsList.Name = "tsmToolsList";
            this.tsmToolsList.Size = new System.Drawing.Size(182, 22);
            this.tsmToolsList.Text = "Tools List";
            this.tsmToolsList.Click += new System.EventHandler(this.tsmToolsList_Click);
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
            this.tsmTabbedMdi.Checked = true;
            this.tsmTabbedMdi.CheckOnClick = true;
            this.tsmTabbedMdi.CheckState = System.Windows.Forms.CheckState.Checked;
            this.tsmTabbedMdi.Name = "tsmTabbedMdi";
            this.tsmTabbedMdi.Size = new System.Drawing.Size(145, 22);
            this.tsmTabbedMdi.Text = "Tabbed MDI";
            this.tsmTabbedMdi.Click += new System.EventHandler(this.tsmTabbedMdi_Click);
            // 
            // tsmCloseAll
            // 
            this.tsmCloseAll.Name = "tsmCloseAll";
            this.tsmCloseAll.Size = new System.Drawing.Size(145, 22);
            this.tsmCloseAll.Text = "Close All";
            this.tsmCloseAll.Click += new System.EventHandler(this.tsmCloseAll_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(142, 6);
            // 
            // tsmTopHelp
            // 
            this.tsmTopHelp.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmHelp,
            this.toolStripSeparator3,
            this.tsmAbout});
            this.tsmTopHelp.Name = "tsmTopHelp";
            this.tsmTopHelp.Size = new System.Drawing.Size(42, 20);
            this.tsmTopHelp.Text = "Help";
            // 
            // tsmHelp
            // 
            this.tsmHelp.Name = "tsmHelp";
            this.tsmHelp.ShortcutKeys = System.Windows.Forms.Keys.F1;
            this.tsmHelp.Size = new System.Drawing.Size(119, 22);
            this.tsmHelp.Text = "Help";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(116, 6);
            // 
            // tsmAbout
            // 
            this.tsmAbout.Name = "tsmAbout";
            this.tsmAbout.Size = new System.Drawing.Size(119, 22);
            this.tsmAbout.Text = "About";
            this.tsmAbout.Click += new System.EventHandler(this.tsmAbout_Click);
            // 
            // tsmTopDesign
            // 
            this.tsmTopDesign.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmDesignMode,
            this.tsmSaveDesign,
            this.toolStripSeparator7,
            this.tsmAddRes,
            this.toolStripSeparator8,
            this.tsmUpdateRes,
            this.tsmDeleteRes,
            this.tsmProperties});
            this.tsmTopDesign.MergeAction = System.Windows.Forms.MergeAction.Replace;
            this.tsmTopDesign.Name = "tsmTopDesign";
            this.tsmTopDesign.Size = new System.Drawing.Size(56, 20);
            this.tsmTopDesign.Text = "Design";
            this.tsmTopDesign.DropDownOpening += new System.EventHandler(this.tsmTopDesign_DropDownOpening);
            // 
            // tsmDesignMode
            // 
            this.tsmDesignMode.CheckOnClick = true;
            this.tsmDesignMode.Image = ((System.Drawing.Image)(resources.GetObject("tsmDesignMode.Image")));
            this.tsmDesignMode.Name = "tsmDesignMode";
            this.tsmDesignMode.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.D)));
            this.tsmDesignMode.Size = new System.Drawing.Size(219, 22);
            this.tsmDesignMode.Text = "Design Mode";
            this.tsmDesignMode.Click += new System.EventHandler(this.tsmDesignMode_Click);
            // 
            // tsmSaveDesign
            // 
            this.tsmSaveDesign.Image = ((System.Drawing.Image)(resources.GetObject("tsmSaveDesign.Image")));
            this.tsmSaveDesign.Name = "tsmSaveDesign";
            this.tsmSaveDesign.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.tsmSaveDesign.Size = new System.Drawing.Size(219, 22);
            this.tsmSaveDesign.Text = "Save Design";
            this.tsmSaveDesign.Click += new System.EventHandler(this.tsmSaveDesign_Click);
            // 
            // toolStripSeparator7
            // 
            this.toolStripSeparator7.Name = "toolStripSeparator7";
            this.toolStripSeparator7.Size = new System.Drawing.Size(216, 6);
            // 
            // tsmAddRes
            // 
            this.tsmAddRes.Image = ((System.Drawing.Image)(resources.GetObject("tsmAddRes.Image")));
            this.tsmAddRes.Name = "tsmAddRes";
            this.tsmAddRes.Size = new System.Drawing.Size(219, 22);
            this.tsmAddRes.Text = "Add Multi Resources";
            this.tsmAddRes.Click += new System.EventHandler(this.tsmAddRes_Click);
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(216, 6);
            // 
            // tsmUpdateRes
            // 
            this.tsmUpdateRes.Image = ((System.Drawing.Image)(resources.GetObject("tsmUpdateRes.Image")));
            this.tsmUpdateRes.Name = "tsmUpdateRes";
            this.tsmUpdateRes.Size = new System.Drawing.Size(219, 22);
            this.tsmUpdateRes.Text = "Update Resource/Tag";
            this.tsmUpdateRes.Click += new System.EventHandler(this.tsmUpdateRes_Click);
            // 
            // tsmDeleteRes
            // 
            this.tsmDeleteRes.Image = ((System.Drawing.Image)(resources.GetObject("tsmDeleteRes.Image")));
            this.tsmDeleteRes.Name = "tsmDeleteRes";
            this.tsmDeleteRes.Size = new System.Drawing.Size(219, 22);
            this.tsmDeleteRes.Text = "Delete Resource/Tag";
            this.tsmDeleteRes.Click += new System.EventHandler(this.tsmDeleteRes_Click);
            // 
            // tsmProperties
            // 
            this.tsmProperties.Image = ((System.Drawing.Image)(resources.GetObject("tsmProperties.Image")));
            this.tsmProperties.Name = "tsmProperties";
            this.tsmProperties.Size = new System.Drawing.Size(219, 22);
            this.tsmProperties.Text = "Properties Resource/Tag";
            this.tsmProperties.Click += new System.EventHandler(this.tsmProperties_Click);
            // 
            // mnuDesign
            // 
            this.mnuDesign.Dock = System.Windows.Forms.DockStyle.None;
            this.mnuDesign.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmTopDesign,
            this.tsmTopFormat,
            this.tsmTopView});
            this.mnuDesign.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
            this.mnuDesign.Location = new System.Drawing.Point(290, 163);
            this.mnuDesign.Name = "mnuDesign";
            this.mnuDesign.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
            this.mnuDesign.ShowItemToolTips = true;
            this.mnuDesign.Size = new System.Drawing.Size(165, 24);
            this.mnuDesign.TabIndex = 60;
            this.mnuDesign.Visible = false;
            // 
            // tsmTopFormat
            // 
            this.tsmTopFormat.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmLefts,
            this.tsmCenters,
            this.tsmRights,
            this.tsmSp1,
            this.tsmTops,
            this.tsmMiddles,
            this.tsmBottoms,
            this.tsmSp2,
            this.tsmWidth,
            this.tsmHeight,
            this.tsmBoth,
            this.tsmSp3,
            this.tsmHMakeEqual,
            this.tsmHIncrease,
            this.tsmHDecrease,
            this.tsmHRemove,
            this.tsmSp4,
            this.tsmVMakeEqual,
            this.tsmVIncrease,
            this.tsmVDecrease,
            this.tsmVRemove,
            this.tsmSp5,
            this.tsmBring,
            this.tsmSend});
            this.tsmTopFormat.MergeAction = System.Windows.Forms.MergeAction.Replace;
            this.tsmTopFormat.Name = "tsmTopFormat";
            this.tsmTopFormat.Size = new System.Drawing.Size(56, 20);
            this.tsmTopFormat.Text = "Format";
            // 
            // tsmLefts
            // 
            this.tsmLefts.Image = ((System.Drawing.Image)(resources.GetObject("tsmLefts.Image")));
            this.tsmLefts.Name = "tsmLefts";
            this.tsmLefts.Size = new System.Drawing.Size(156, 22);
            this.tsmLefts.Text = "Lefts";
            this.tsmLefts.Click += new System.EventHandler(this.tsmLefts_Click);
            // 
            // tsmCenters
            // 
            this.tsmCenters.Image = ((System.Drawing.Image)(resources.GetObject("tsmCenters.Image")));
            this.tsmCenters.Name = "tsmCenters";
            this.tsmCenters.Size = new System.Drawing.Size(156, 22);
            this.tsmCenters.Text = "Centers";
            this.tsmCenters.Click += new System.EventHandler(this.tsmCenters_Click);
            // 
            // tsmRights
            // 
            this.tsmRights.Image = ((System.Drawing.Image)(resources.GetObject("tsmRights.Image")));
            this.tsmRights.Name = "tsmRights";
            this.tsmRights.Size = new System.Drawing.Size(156, 22);
            this.tsmRights.Text = "Rights";
            this.tsmRights.Click += new System.EventHandler(this.tsmRights_Click);
            // 
            // tsmSp1
            // 
            this.tsmSp1.Name = "tsmSp1";
            this.tsmSp1.Size = new System.Drawing.Size(153, 6);
            // 
            // tsmTops
            // 
            this.tsmTops.Image = ((System.Drawing.Image)(resources.GetObject("tsmTops.Image")));
            this.tsmTops.Name = "tsmTops";
            this.tsmTops.Size = new System.Drawing.Size(156, 22);
            this.tsmTops.Text = "Tops";
            this.tsmTops.Click += new System.EventHandler(this.tsmTops_Click);
            // 
            // tsmMiddles
            // 
            this.tsmMiddles.Image = ((System.Drawing.Image)(resources.GetObject("tsmMiddles.Image")));
            this.tsmMiddles.Name = "tsmMiddles";
            this.tsmMiddles.Size = new System.Drawing.Size(156, 22);
            this.tsmMiddles.Text = "Middles";
            this.tsmMiddles.Click += new System.EventHandler(this.tsmMiddles_Click);
            // 
            // tsmBottoms
            // 
            this.tsmBottoms.Image = ((System.Drawing.Image)(resources.GetObject("tsmBottoms.Image")));
            this.tsmBottoms.Name = "tsmBottoms";
            this.tsmBottoms.Size = new System.Drawing.Size(156, 22);
            this.tsmBottoms.Text = "Bottoms";
            this.tsmBottoms.Click += new System.EventHandler(this.tsmBottoms_Click);
            // 
            // tsmSp2
            // 
            this.tsmSp2.Name = "tsmSp2";
            this.tsmSp2.Size = new System.Drawing.Size(153, 6);
            // 
            // tsmWidth
            // 
            this.tsmWidth.Image = ((System.Drawing.Image)(resources.GetObject("tsmWidth.Image")));
            this.tsmWidth.Name = "tsmWidth";
            this.tsmWidth.Size = new System.Drawing.Size(156, 22);
            this.tsmWidth.Text = "Width";
            this.tsmWidth.Click += new System.EventHandler(this.tsmWidth_Click);
            // 
            // tsmHeight
            // 
            this.tsmHeight.Image = ((System.Drawing.Image)(resources.GetObject("tsmHeight.Image")));
            this.tsmHeight.Name = "tsmHeight";
            this.tsmHeight.Size = new System.Drawing.Size(156, 22);
            this.tsmHeight.Text = "Height";
            this.tsmHeight.Click += new System.EventHandler(this.tsmHeight_Click);
            // 
            // tsmBoth
            // 
            this.tsmBoth.Image = ((System.Drawing.Image)(resources.GetObject("tsmBoth.Image")));
            this.tsmBoth.Name = "tsmBoth";
            this.tsmBoth.Size = new System.Drawing.Size(156, 22);
            this.tsmBoth.Text = "Both";
            this.tsmBoth.Click += new System.EventHandler(this.tsmBoth_Click);
            // 
            // tsmSp3
            // 
            this.tsmSp3.Name = "tsmSp3";
            this.tsmSp3.Size = new System.Drawing.Size(153, 6);
            // 
            // tsmHMakeEqual
            // 
            this.tsmHMakeEqual.Image = ((System.Drawing.Image)(resources.GetObject("tsmHMakeEqual.Image")));
            this.tsmHMakeEqual.Name = "tsmHMakeEqual";
            this.tsmHMakeEqual.Size = new System.Drawing.Size(156, 22);
            this.tsmHMakeEqual.Text = "Make Equal";
            this.tsmHMakeEqual.Click += new System.EventHandler(this.tsmHMakeEqual_Click);
            // 
            // tsmHIncrease
            // 
            this.tsmHIncrease.Image = ((System.Drawing.Image)(resources.GetObject("tsmHIncrease.Image")));
            this.tsmHIncrease.Name = "tsmHIncrease";
            this.tsmHIncrease.Size = new System.Drawing.Size(156, 22);
            this.tsmHIncrease.Text = "Increase";
            this.tsmHIncrease.Click += new System.EventHandler(this.tsmHIncrease_Click);
            // 
            // tsmHDecrease
            // 
            this.tsmHDecrease.Image = ((System.Drawing.Image)(resources.GetObject("tsmHDecrease.Image")));
            this.tsmHDecrease.Name = "tsmHDecrease";
            this.tsmHDecrease.Size = new System.Drawing.Size(156, 22);
            this.tsmHDecrease.Text = "Decrease";
            this.tsmHDecrease.Click += new System.EventHandler(this.tsmHDecrease_Click);
            // 
            // tsmHRemove
            // 
            this.tsmHRemove.Image = ((System.Drawing.Image)(resources.GetObject("tsmHRemove.Image")));
            this.tsmHRemove.Name = "tsmHRemove";
            this.tsmHRemove.Size = new System.Drawing.Size(156, 22);
            this.tsmHRemove.Text = "Remove";
            this.tsmHRemove.Click += new System.EventHandler(this.tsmHRemove_Click);
            // 
            // tsmSp4
            // 
            this.tsmSp4.Name = "tsmSp4";
            this.tsmSp4.Size = new System.Drawing.Size(153, 6);
            // 
            // tsmVMakeEqual
            // 
            this.tsmVMakeEqual.Image = ((System.Drawing.Image)(resources.GetObject("tsmVMakeEqual.Image")));
            this.tsmVMakeEqual.Name = "tsmVMakeEqual";
            this.tsmVMakeEqual.Size = new System.Drawing.Size(156, 22);
            this.tsmVMakeEqual.Text = "Make Equal";
            this.tsmVMakeEqual.Click += new System.EventHandler(this.tsmVMakeEqual_Click);
            // 
            // tsmVIncrease
            // 
            this.tsmVIncrease.Image = ((System.Drawing.Image)(resources.GetObject("tsmVIncrease.Image")));
            this.tsmVIncrease.Name = "tsmVIncrease";
            this.tsmVIncrease.Size = new System.Drawing.Size(156, 22);
            this.tsmVIncrease.Text = "Increase";
            this.tsmVIncrease.Click += new System.EventHandler(this.tsmVIncrease_Click);
            // 
            // tsmVDecrease
            // 
            this.tsmVDecrease.Image = ((System.Drawing.Image)(resources.GetObject("tsmVDecrease.Image")));
            this.tsmVDecrease.Name = "tsmVDecrease";
            this.tsmVDecrease.Size = new System.Drawing.Size(156, 22);
            this.tsmVDecrease.Text = "Decrease";
            this.tsmVDecrease.Click += new System.EventHandler(this.tsmVDecrease_Click);
            // 
            // tsmVRemove
            // 
            this.tsmVRemove.Image = ((System.Drawing.Image)(resources.GetObject("tsmVRemove.Image")));
            this.tsmVRemove.Name = "tsmVRemove";
            this.tsmVRemove.Size = new System.Drawing.Size(156, 22);
            this.tsmVRemove.Text = "Remove";
            this.tsmVRemove.Click += new System.EventHandler(this.tsmVRemove_Click);
            // 
            // tsmSp5
            // 
            this.tsmSp5.Name = "tsmSp5";
            this.tsmSp5.Size = new System.Drawing.Size(153, 6);
            // 
            // tsmBring
            // 
            this.tsmBring.Image = ((System.Drawing.Image)(resources.GetObject("tsmBring.Image")));
            this.tsmBring.Name = "tsmBring";
            this.tsmBring.Size = new System.Drawing.Size(156, 22);
            this.tsmBring.Text = "Bring To Front";
            this.tsmBring.Click += new System.EventHandler(this.tsmBring_Click);
            // 
            // tsmSend
            // 
            this.tsmSend.Image = ((System.Drawing.Image)(resources.GetObject("tsmSend.Image")));
            this.tsmSend.Name = "tsmSend";
            this.tsmSend.Size = new System.Drawing.Size(156, 22);
            this.tsmSend.Text = "Send To Back";
            this.tsmSend.Click += new System.EventHandler(this.tsmSend_Click);
            // 
            // tsmTopView
            // 
            this.tsmTopView.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmReload,
            this.toolStripSeparator9,
            this.tsmZoomIn,
            this.tsmZoomOut});
            this.tsmTopView.MergeAction = System.Windows.Forms.MergeAction.Replace;
            this.tsmTopView.Name = "tsmTopView";
            this.tsmTopView.Size = new System.Drawing.Size(45, 20);
            this.tsmTopView.Text = "View";
            // 
            // tsmReload
            // 
            this.tsmReload.Image = ((System.Drawing.Image)(resources.GetObject("tsmReload.Image")));
            this.tsmReload.Name = "tsmReload";
            this.tsmReload.Size = new System.Drawing.Size(132, 22);
            this.tsmReload.Text = "Reload";
            this.tsmReload.Click += new System.EventHandler(this.tsmReload_Click);
            // 
            // toolStripSeparator9
            // 
            this.toolStripSeparator9.Name = "toolStripSeparator9";
            this.toolStripSeparator9.Size = new System.Drawing.Size(129, 6);
            // 
            // tsmZoomIn
            // 
            this.tsmZoomIn.Image = ((System.Drawing.Image)(resources.GetObject("tsmZoomIn.Image")));
            this.tsmZoomIn.Name = "tsmZoomIn";
            this.tsmZoomIn.Size = new System.Drawing.Size(132, 22);
            this.tsmZoomIn.Text = "Zoom In";
            this.tsmZoomIn.Click += new System.EventHandler(this.tsmZoomIn_Click);
            // 
            // tsmZoomOut
            // 
            this.tsmZoomOut.Image = ((System.Drawing.Image)(resources.GetObject("tsmZoomOut.Image")));
            this.tsmZoomOut.Name = "tsmZoomOut";
            this.tsmZoomOut.Size = new System.Drawing.Size(132, 22);
            this.tsmZoomOut.Text = "Zoom Out";
            this.tsmZoomOut.Click += new System.EventHandler(this.tsmZoomOut_Click);
            // 
            // frmMDIMain
            // 
            this.ClientSize = new System.Drawing.Size(1016, 734);
            this.Controls.Add(this._frmMDIMainAutoHideControl);
            this.Controls.Add(this.mnuDesign);
            this.Controls.Add(this.WindowDockingArea3);
            this.Controls.Add(this._frmMDIMainUnpinnedTabAreaTop);
            this.Controls.Add(this._frmMDIMainUnpinnedTabAreaBottom);
            this.Controls.Add(this._frmMDIMainUnpinnedTabAreaLeft);
            this.Controls.Add(this._frmMDIMainUnpinnedTabAreaRight);
            this.Controls.Add(this.tolMain);
            this.Controls.Add(this.mnuMain);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "frmMDIMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "MESplus FMBClient 5";
            this.Load += new System.EventHandler(this.frmMDIMain_Load);
            this.Activated += new System.EventHandler(this.frmMDIMain_Activated);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmMDIMain_FormClosing);
            this.Controls.SetChildIndex(this.mnuMain, 0);
            this.Controls.SetChildIndex(this.tolMain, 0);
            this.Controls.SetChildIndex(this._frmMDIMainUnpinnedTabAreaRight, 0);
            this.Controls.SetChildIndex(this._frmMDIMainUnpinnedTabAreaLeft, 0);
            this.Controls.SetChildIndex(this._frmMDIMainUnpinnedTabAreaBottom, 0);
            this.Controls.SetChildIndex(this._frmMDIMainUnpinnedTabAreaTop, 0);
            this.Controls.SetChildIndex(this.WindowDockingArea3, 0);
            this.Controls.SetChildIndex(this.pgbMain, 0);
            this.Controls.SetChildIndex(this.mnuDesign, 0);
            this.Controls.SetChildIndex(this._frmMDIMainAutoHideControl, 0);
            ((System.ComponentModel.ISupportInitialize)(this.utmmMDIMain)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.udmMDIMain)).EndInit();
            this.DockableWindow1.ResumeLayout(false);
            this.DockableWindow2.ResumeLayout(false);
            this.WindowDockingArea3.ResumeLayout(false);
            this.tolMain.ResumeLayout(false);
            this.tolMain.PerformLayout();
            this.mnuMain.ResumeLayout(false);
            this.mnuMain.PerformLayout();
            this.mnuDesign.ResumeLayout(false);
            this.mnuDesign.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }
        
        #endregion
        
        #region " Variable Definition"
        private bool b_load_flag = false;
        #endregion
        
        #region " Functions Implementations"


        // AddResource()
        //       - Add Created Resource in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sResource As String
        //
        private void AddResource(string sFactory, string sResource, string sUpDownFlag)
        {
            
            try
            {
                trvDesignList.BeginUpdate();
                
                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (((clsDesignListTag) nodeFactory.Tag).LoadFlag == true)
                {
                    TreeNode nodeResource = nodeFactory.Nodes.Add(sResource);
                    clsDesignListTag nodeTag = new clsDesignListTag();
                    nodeTag.SetTagData(sResource, modGlobalConstant.FMB_CATEGORY_RESOURCE, sFactory, "", false);
                    nodeResource.Tag = nodeTag;
                    if (sUpDownFlag == "U")
                    {
                        nodeResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                        nodeResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                    }
                    else
                    {
                        nodeResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                        nodeResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                    }
                }
                trvDesignList.EndUpdate();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.AddResource()" + "\r\n" + ex.Message);
            }
            
        }
        
        // DeleteResource()
        //       - Delete Deleted Resource in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sResource As String
        //
        private void DeleteResource(string sFactory, string sResource)
        {
            
            try
            {
                trvDesignList.BeginUpdate();
                
                TreeNode nodeDeletedResource = null;
                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (!(nodeFactory == null))
                {
                    nodeDeletedResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sResource, true);
                    if (!(nodeDeletedResource == null))
                    {
                        nodeDeletedResource.Remove();
                    }
                }
                
                trvDesignList.EndUpdate();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeleteResource()" + "\r\n" + ex.Message);
            }
            
        }
        

        // AddTool()
        //       - Add Created Tool in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sTool As String
        //
        private void AddTool(string sFactory, string sTool, string sUpDownFlag)
        {

            try
            {
                trvDesignList.BeginUpdate();

                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (((clsDesignListTag)nodeFactory.Tag).LoadFlag == true)
                {
                    TreeNode nodeResource = nodeFactory.Nodes.Add(sTool);
                    clsDesignListTag nodeTag = new clsDesignListTag();
                    nodeTag.SetTagData(sTool, modGlobalConstant.FMB_CATEGORY_TOOL, sFactory, "", false);
                    nodeResource.Tag = nodeTag;

                }
                trvDesignList.EndUpdate();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.AddTool()" + "\r\n" + ex.Message);
            }

        }

        // DeleteTool()
        //       - Delete Deleted Resource in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sResource As String
        //
        private void DeleteTool(string sFactory, string sTool)
        {

            try
            {
                trvDesignList.BeginUpdate();

                TreeNode nodeDeletedResource = null;
                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (!(nodeFactory == null))
                {
                    nodeDeletedResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sTool, true);
                    if (!(nodeDeletedResource == null))
                    {
                        nodeDeletedResource.Remove();
                    }
                }

                trvDesignList.EndUpdate();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeleteTool()" + "\r\n" + ex.Message);
            }

        }

        // AddPort()
        //       - Add Created Port in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sPort As String
        //
        private void AddPort(string sFactory, string sResource, string sPort, string sUpDownFlag)
        {

            try
            {
                trvDesignList.BeginUpdate();

                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (((clsDesignListTag)nodeFactory.Tag).LoadFlag == true)
                {
                    TreeNode nodeResource = nodeFactory.Nodes.Add(sPort);
                    clsDesignListTag nodeTag = new clsDesignListTag();
                    nodeTag.SetTagData(sPort, sResource,  modGlobalConstant.FMB_CATEGORY_PORT , sFactory, "", false);
                    nodeResource.Tag = nodeTag;

                }
                trvDesignList.EndUpdate();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.AddTool()" + "\r\n" + ex.Message);
            }

        }

        // DeletePort()
        //       - Delete Deleted Resource in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sResource As String
        //
        private void DeletePort(string sFactory, string sResource, string sPort)
        {

            try
            {
                trvDesignList.BeginUpdate();

                TreeNode nodeDeletedResource = null;
                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (!(nodeFactory == null))
                {
                    nodeDeletedResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sResource, sPort, true);
                    if (!(nodeDeletedResource == null))
                    {
                        nodeDeletedResource.Remove();
                    }
                }

                trvDesignList.EndUpdate();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeletePort()" + "\r\n" + ex.Message);
            }

        }

        // AddSubResource()
        //       - Add Created Sub Resource in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sSubResource As String
        //
        private void AddSubResource(string sFactory,string sResource, string sSubResource, string sUpDownFlag)
        {

            try
            {
                trvDesignList.BeginUpdate();

                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (((clsDesignListTag)nodeFactory.Tag).LoadFlag == true)
                {
                    TreeNode nodeResource = nodeFactory.Nodes.Add(sSubResource);
                    clsDesignListTag nodeTag = new clsDesignListTag();
                    nodeTag.SetTagData(sSubResource,sResource, modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE, sFactory, "", false);
                    nodeResource.Tag = nodeTag;
                    if (sUpDownFlag == "U")
                    {
                        nodeResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                        nodeResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                    }
                    else
                    {
                        nodeResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                        nodeResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                    }
                }
                trvDesignList.EndUpdate();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.AddSubResource()" + "\r\n" + ex.Message);
            }

        }

        // DeleteSubResource()
        //       - Delete Deleted Sub Resource in Design List TreeView
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sSubResource As String
        //
        private void DeleteSubResource(string sFactory,string Resource, string sSubResource)
        {

            try
            {
                trvDesignList.BeginUpdate();

                TreeNode nodeDeletedResource = null;
                TreeNode nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                if (!(nodeFactory == null))
                {
                    nodeDeletedResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory,Resource, sSubResource, true);
                    if (!(nodeDeletedResource == null))
                    {
                        nodeDeletedResource.Remove();
                    }
                }

                trvDesignList.EndUpdate();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeleteSubResource()" + "\r\n" + ex.Message);
            }

        }
        
        // CreateResourceEvent()
        //       - Create Resource Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sResource As String
        //
        public void CreateResourceEvent(string sFactory, string sResource, string sUpDownFlag)
        {
            
            try
            {
                IAsyncResult r = BeginInvoke(_AddResourceDelegate, new object[] { sFactory, sResource, sUpDownFlag });
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.CreateResourceEvent()" + "\r\n" + ex.Message);
            }
            
        }
        

        // CreateToolEvent()
        //       - Create Tool Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sTool As String
        //
        public void CreateToolEvent(string sFactory, string sTool)
        {

            try
            {
                IAsyncResult r = BeginInvoke(_AddToolDelegate, new object[] { sFactory, sTool });

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.CreateToolEvent()" + "\r\n" + ex.Message);
            }

        }

        // CreatePortEvent()
        //       - Create Port Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sPort As String
        //
        public void CreatePortEvent(string sFactory, string sPort)
        {

            try
            {
                IAsyncResult r = BeginInvoke(_AddPortDelegate, new object[] { sFactory, sPort });

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.CreatePortEvent()" + "\r\n" + ex.Message);
            }

        }

        // CreateSubResourceEvent()
        //       - Create Sub Resource Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sSubResource As String
        //
        public void CreateSubResourceEvent(string sFactory, string sResource, string sSubResource, string sUpDownFlag)
        {

            try
            {
                IAsyncResult r = BeginInvoke(_AddSubResourceDelegate, new object[] { sFactory, sResource, sSubResource, sUpDownFlag });

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.CreateSubResourceEvent()" + "\r\n" + ex.Message);
            }

        }

        // DeleteResourceEvent()
        //       - Delete Resource Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sResource As String
        //
        public void DeleteResourceEvent(string sFactory, string sResource)
        {
            
            try
            {
                IAsyncResult r = BeginInvoke(_DeleteResourceDelegate, new object[] { sFactory, sResource });
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeleteResourceEvent()" + "\r\n" + ex.Message);
            }
            
        }
        
        // DeleteToolEvent()
        //       - Delete Tool Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sTool As String
        //
        public void DeleteToolEvent(string sFactory, string sTool)
        {

            try
            {
                IAsyncResult r = BeginInvoke(_DeleteToolDelegate, new object[] { sFactory, sTool });

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeleteToolEvent()" + "\r\n" + ex.Message);
            }

        }

        // DeleteSubResourceEvent()
        //       - Delete Sub Resource Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sSubResource As String
        //
        public void DeleteSubResourceEvent(string sFactory, string sResource, string sSubResource)
        {

            try
            {
                IAsyncResult r = BeginInvoke(_DeleteSubResourceDelegate, new object[] { sFactory,sResource, sSubResource });

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeleteSubResourceEvent()" + "\r\n" + ex.Message);
            }

        }

        // DeletePortEvent()
        //       - Delete Port Event Process
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sPort As String
        //
        public void DeletePortEvent(string sFactory, string sPort)
        {

            try
            {
                IAsyncResult r = BeginInvoke(_DeletePortDelegate, new object[] { sFactory, sPort });

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.DeletePortEvent()" + "\r\n" + ex.Message);
            }

        }
        
        // InitDesignList()
        //       - Initialize Design List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        //
        public bool InitDesignList()
        {
            
            try
            {
                mnuDeleteResource.Visible = false;
                mnuUpdateLayout.Visible = false;
                mnuUpdateUserGroupDesign.Visible = false;
                mnuProperties.Visible = false;
                mnuSeperator1.Visible = false;
                mnuViewResourceStatus.Visible = false;
                mnuViewResourceHistory.Visible = false;

                MPCF.InitTreeView(this.trvDesignList);
                if (ViewFactoryList() == false)
                {
                    return false;
                }
                if (ViewFMBGroupList() == false)
                {
                    return false;
                }
                if (ViewLayoutFileList() == false)
                {
                    return false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.InitDesignList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }

       
        
        // GetStateButtonTool()
        //       - Get StateButtonTool
        // Return Value
        //       - Infragistics.Win.UltraWinToolbars.StateButtonTool
        // Arguments
        //       - ByVal tool As Infragistics.Win.UltraWinToolbars.ToolBase
        //
        private static Infragistics.Win.UltraWinToolbars.StateButtonTool GetStateButtonTool(Infragistics.Win.UltraWinToolbars.ToolBase tool)
        {
            
            try
            {
                return ((Infragistics.Win.UltraWinToolbars.StateButtonTool) tool);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.GetStateButtonTool()" + "\r\n" + ex.Message);
                return null;
            }
            
        }
        
        // AddNewForm()
        //       - Add Form
        // Return Value
        //       -
        // Arguments
        //       - ByVal sFormName As String : Form Name
        //       - ByVal sTag As String : Form Tag
        //
        private void AddNewForm(string sFormName, string sTag)
        {
            
            try
            {
                if (this.utmmMDIMain.Enabled == false)
                {
                    this.utmmMDIMain.Enabled = true;
                }

                frmFMBDesign newForm = new frmFMBDesign(sFormName, sTag);
                newForm.Name = sFormName;
                newForm.Tag = sTag;
                newForm.Text = sFormName;
                newForm.MdiParent = this;
                newForm.Show();


                if ( tsmTabbedMdi.Checked == false && this.utmmMDIMain.Enabled == true)
                {
                    this.utmmMDIMain.Enabled = false;
                }
                
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.AddNewForm()" + "\r\n" + ex.Message);
            }
            
        }

        public bool ViewFMBGroupList()
        {

            try
            {
                TRSNode in_node = new TRSNode("View_FMB_Group_List_In");
                TRSNode out_node;
             
                int i;
                TreeNode nodeGroup;
                string sLayout = "";
                
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("NEXT_USER", MPGV.gsUserID, true);
                in_node.AddString("NEXT_GROUP", "");

                 trvDesignList.BeginUpdate();

                for (i = trvDesignList.Nodes.Count - 1; i >= 0; i += -1)
                {
                    if (((clsDesignListTag)trvDesignList.Nodes[i].Tag).Category == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        trvDesignList.Nodes[i].Remove();
                    }
                }

                do
                {
                    out_node = new TRSNode("View_FMB_Group_List_Out");

                    if (MPCR.CallService("FMB", "FMB_View_FMB_Group_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        sLayout = out_node.GetList(0)[i].GetString("GROUP_ID");
                        nodeGroup = trvDesignList.Nodes.Add(sLayout);
                        clsDesignListTag nodeTag = new clsDesignListTag();
                        nodeTag.SetTagData(sLayout, modGlobalConstant.FMB_CATEGORY_GROUP, "", sLayout, false);
                        nodeGroup.Tag = nodeTag;
                        nodeGroup.ImageIndex = MPCF.ToInt(SMALLICON_INDEX.IDX_SUB_AREA);
                        nodeGroup.SelectedImageIndex = MPCF.ToInt(SMALLICON_INDEX.IDX_SUB_AREA);
                    }

                    in_node.SetString("NEXT_GROUP", out_node.GetString("NEXT_GROUP"));
                }
                while (in_node.GetString("NEXT_GROUP") != "");

                trvDesignList.EndUpdate();
                return true;
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewUDRGroupList()" + "\r\n" + ex.Message);
                return false;
            }

        }

        // ViewFactoryList()
        //       - View Factory List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool ViewFactoryList()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("View_Factory_List_In");
                TRSNode out_node;

                int i;
                TreeNode nodeFactory;
                string sFactory = "";
                
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("NEXT_FACTORY", "");
                
                trvDesignList.BeginUpdate();
                
                trvDesignList.Nodes.Clear();

                if (modGlobalVariable.gbAllFactory == false)
                {
                    nodeFactory = trvDesignList.Nodes.Add(MPGV.gsFactory);
                    clsDesignListTag nodeTag = new clsDesignListTag();
                    nodeTag.SetTagData(MPGV.gsFactory, modGlobalConstant.FMB_CATEGORY_FACTORY, MPGV.gsFactory, "", false);
                    nodeFactory.Tag = nodeTag;
                    nodeFactory.ImageIndex = 4;
                    nodeFactory.SelectedImageIndex = 4;
                    
                }
                else
                {
                    
                    do
                    {
                        out_node = new TRSNode("View_Factory_List_Out");

                        if (MPCR.CallService("WIP", "WIP_View_Factory_List", in_node, ref out_node) == false)
                        {
                            return false;
                        }

                        for (i = 0; i < out_node.GetList(0).Count; i++)
                        {
                            sFactory = out_node.GetList(0)[i].GetString("FACTORY");
                            nodeFactory = trvDesignList.Nodes.Add(sFactory);
                            clsDesignListTag nodeTag = new clsDesignListTag();
                            nodeTag.SetTagData(sFactory, modGlobalConstant.FMB_CATEGORY_FACTORY, sFactory, "", false);
                            nodeFactory.Tag = nodeTag;
                            nodeFactory.ImageIndex = 4;
                            nodeFactory.SelectedImageIndex = 4;
                        }
                        
                        in_node.SetString("NEXT_FACTORY", out_node.GetString("NEXT_FACTORY"));
                    } while (in_node.GetString("NEXT_FACTORY") != "");
                }

                trvDesignList.EndUpdate();
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewFactoryList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        // ViewLayoutList()
        //       - View Layout List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal sFactory As String
        //
        public bool ViewLayoutList(string sFactory)
        {
            
            try
            {
                TRSNode in_node = new TRSNode("FMB_View_LayOut_List_In");
                TRSNode out_node;
                int i;
                TreeNode nodeFactory;
                TreeNode nodeLayout;
                string sLayout = "";
                ArrayList a_list = new ArrayList();


                nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = sFactory;
                in_node.AddString("NEXT_LAYOUT_ID", "");

                trvDesignList.BeginUpdate();
                
                nodeFactory.Nodes.Clear();
                
                do
                {
                    out_node = new TRSNode("FMB_View_LayOut_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_LayOut_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetString("NEXT_LAYOUT_ID", out_node.GetString("NEXT_LAYOUT_ID"));
                } while (in_node.GetString("NEXT_LAYOUT_ID") != "");
                
                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        sLayout = out_node.GetList(0)[i].GetString("LAYOUT_ID");
                        nodeLayout = nodeFactory.Nodes.Add(sLayout);
                        clsDesignListTag nodeTag = new clsDesignListTag();
                        nodeTag.SetTagData(sLayout, modGlobalConstant.FMB_CATEGORY_LAYOUT, sFactory, sLayout, false);
                        nodeLayout.Tag = nodeTag;
                        nodeLayout.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_AREA);
                        nodeLayout.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_AREA);
                    }
                }

                trvDesignList.EndUpdate();
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewLayoutList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        // ViewResourceList()
        //       - View Resource List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal sFactory As String
        //
        public bool ViewResourceList(string sFactory, string sLayout)
        {
            
            try
            {
                TRSNode in_node = new TRSNode("FMB_View_Resource_List_In");
                TRSNode out_node;

                int i;
                TreeNode nodeFactory;
                TreeNode nodeLayout = null;
                TreeNode nodeResource;
                ArrayList a_list = new ArrayList();
                string sResource = "";
                

                nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                
                if (sLayout.TrimEnd() == "")
                {
                    in_node.ProcStep = '4';
                }
                else
                {
                    in_node.ProcStep = '5';
                    MPCR.SetInMsg(in_node);
                    in_node.AddString("LAYOUT_ID", sLayout.TrimEnd());
                    nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                    if (nodeLayout != null)
                    {
                        nodeLayout.Nodes.Clear();
                    }
                }
                MPCR.SetInMsg(in_node);
                in_node.Factory = sFactory;

                in_node.AddChar("RES_TYPE", ' ');
                in_node.AddInt("NEXT_SEQ", 0);
                in_node.AddChar("INCLUDE_DEL_RES", ' ');
                in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                in_node.AddString("NEXT_RES_ID", " ");
                
                trvDesignList.BeginUpdate();
                
                do
                {
                    out_node = new TRSNode("FMB_View_Resource_List_Out");

                    if (MPCR.CallService("FMB", "FMB_View_Resource_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetString("NEXT_RES_ID", out_node.GetString("NEXT_RES_ID"));
                } while (in_node.GetString("NEXT_RES_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        sResource = out_node.GetList(0)[i].GetString("RES_ID");
                        if (sLayout.TrimEnd() == "")
                        {
                            sLayout = "";
                            nodeResource = nodeFactory.Nodes.Add(sResource);
                            clsDesignListTag nodeTag = new clsDesignListTag();
                            nodeTag.SetTagData(sResource, modGlobalConstant.FMB_CATEGORY_RESOURCE, sFactory, sLayout, false);
                            nodeResource.Tag = nodeTag;
                            nodeResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                            nodeResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                        }
                        else
                        {
                            nodeResource = nodeLayout.Nodes.Add(sResource);
                            clsDesignListTag nodeTag = new clsDesignListTag();
                            nodeTag.SetTagData(sResource, modGlobalConstant.FMB_CATEGORY_RESOURCE, sFactory, sLayout, true);
                            nodeResource.Tag = nodeTag;
                            nodeResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE);
                            nodeResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE);
                        }
                    }
                }

                if (sLayout.TrimEnd() != "")
                {
                    nodeLayout.Expand();
                }
                
                trvDesignList.EndUpdate();
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewResourceList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
         // ViewToolList()
        //       - View Tool List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal sFactory As String
        //
        public bool ViewToolList(string sFactory, string sLayout)
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_TOOL_LIST_IN");
                TRSNode out_node = new TRSNode("FMB_VIEW_TOOL_LIST_OUT");
                int i;
                TreeNode nodeFactory;
                TreeNode nodeTool;
                TreeNode nodeLayout = null;
                string sTool = "";
                string sToolType = "";
                nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);

                if (sLayout.TrimEnd() == "")
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '4';
                }
                else
                {
                    in_node.ProcStep = '5';
                    in_node.AddString("LAYOUT_ID", sLayout.TrimEnd());
                    nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                    if (nodeLayout == null)
                    {
                        return false;
                    }

                }
                in_node.Factory = sFactory;

                in_node.AddChar("RES_TYPE", ' ');
                in_node.AddInt("NEXT_SEQ", 0);
                //in_node.Add("INCLUDE_DEL_RES", ' ');
                in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                in_node.AddString("NEXT_TOOL_ID", " ");

                trvDesignList.BeginUpdate();

                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_Tool_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        sTool = MPCF.RTrim(out_node.GetList(0)[i].GetString("TOOL_ID"));
                        sToolType = MPCF.RTrim(out_node.GetList(0)[i].GetString("TOOL_TYPE"));

                        if (sLayout.TrimEnd() == "")
                        {
                            sLayout = "";
                            nodeTool = nodeFactory.Nodes.Add(sTool);
                            clsDesignListTag nodeTag = new clsDesignListTag();
                            nodeTag.SetTagData(sTool, sToolType, modGlobalConstant.FMB_CATEGORY_TOOL, sFactory, sLayout, false);
                            nodeTool.Tag = nodeTag;
                            nodeTool.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_TOOL);
                            nodeTool.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_TOOL);
                        }
                        else
                        {
                            nodeTool = nodeLayout.Nodes.Add(sTool);
                            clsDesignListTag nodeTag = new clsDesignListTag();
                            nodeTag.SetTagData(sTool, sToolType, modGlobalConstant.FMB_CATEGORY_TOOL, sFactory, sLayout, true);
                            nodeTool.Tag = nodeTag;
                            nodeTool.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_TOOL);
                            nodeTool.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_TOOL);
                        }
                    }

                    in_node.SetString("NEXT_TOOL_ID", out_node.GetString("NEXT_TOOL_ID"));
                } while (MPCF.Trim(out_node.GetString("NEXT_TOOL_ID")) != "");

                if (sLayout.TrimEnd() != "")
                {
                    nodeLayout.Expand();
                }

                trvDesignList.EndUpdate();

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewToolList()" + "\r\n" + ex.Message);
                return false;
            }

        }




         // ViewSubResourceList()
        //       - View Tool List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal sFactory As String
        //
        public bool ViewSubResourceList(string sFactory, string sLayout, string sResID)
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_SUB_RESOURCE_LIST_IN");
                TRSNode out_node = new TRSNode("FMB_VIEW_SUB_RESOURCE_LIST_OUT");
                int i;
                TreeNode nodeFactory;
                TreeNode nodeSubResource;
                TreeNode nodeResource = null;
                TreeNode nodeLayout = null;
                string sResource = "";
                string sSubResource = "";

                nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);

                if (sLayout.TrimEnd() == "")
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '4';
                    in_node.AddString("RES_ID", sResID.TrimEnd());
                    nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sResID, false);
                }
                else
                {
                    if (sResID.TrimEnd() == "")
                    {
                        in_node.ProcStep = '8';
                        in_node.AddString("LAYOUT_ID", sLayout.TrimEnd());
                        nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                        if (nodeLayout == null)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        in_node.ProcStep = '7';
                        in_node.AddString("LAYOUT_ID", sLayout.TrimEnd());
                        in_node.AddString("RES_ID", sResID.TrimEnd());
                        nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                        nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sResID, true);
                        if (nodeLayout == null || nodeResource == null)
                        {
                            return false;
                        }
                    }

                }
                in_node.Factory = sFactory;

                in_node.AddChar("RES_TYPE", ' ');
                in_node.AddInt("NEXT_SEQ", 0);
                //in_node.Add("INCLUDE_DEL_RES", ' ');
                in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                in_node.AddString("NEXT_SUBRES_ID", " ");

                trvDesignList.BeginUpdate();

                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_Sub_Resource_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        sResource = MPCF.RTrim(out_node.GetList(0)[i].GetString("RES_ID"));
                        sSubResource = MPCF.RTrim(out_node.GetList(0)[i].GetString("SUBRES_ID"));
                        
                        if (sLayout.TrimEnd() == "")
                        {
                            sLayout = "";
                            nodeSubResource = nodeResource.Nodes.Add(sSubResource);
                            clsDesignListTag nodeTag = new clsDesignListTag();
                            nodeTag.SetTagData(sSubResource, sResource, modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE, sFactory, sLayout, false);
                            nodeSubResource.Tag = nodeTag;
                            nodeSubResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_RES_DOWN);
                            nodeSubResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_RES_DOWN);
                        }
                        else
                        {
                            if (sResID.TrimEnd() == "")
                            {
                                nodeSubResource = nodeLayout.Nodes.Add(sSubResource);
                                clsDesignListTag nodeTag = new clsDesignListTag();
                                nodeTag.SetTagData(sSubResource, sResource, modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE, sFactory, sLayout, true);
                                nodeSubResource.Tag = nodeTag;
                                nodeSubResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_EQUIP);
                                nodeSubResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_EQUIP);
                            }
                            else
                            {
                                nodeSubResource = nodeResource.Nodes.Add(sSubResource);
                                clsDesignListTag nodeTag = new clsDesignListTag();
                                
                                if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'Y')
                                {
                                    nodeTag.SetTagData(sSubResource, sResource, modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE, sFactory, MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")), true);
                                    nodeSubResource.Tag = nodeTag;
                                    nodeSubResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_EQUIP);
                                    nodeSubResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_EQUIP);
                                }
                                else if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'N')
                                {
                                    if (MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")) == "")
                                    {
                                        nodeTag.SetTagData(sSubResource, sResource, modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE, sFactory, MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")), false);
                                        nodeSubResource.Tag = nodeTag;
                                    }
                                    else
                                    {// 장비와 다른 Layout에 있는 경우
                                        nodeTag.SetTagData(sSubResource, sResource, modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE, sFactory, MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")), true);
                                        nodeSubResource.Tag = nodeTag;
                                    }
                                    nodeSubResource.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_RES_DOWN);
                                    nodeSubResource.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_RES_DOWN);
                                }
                               
                            }
                        }
                    }

                    in_node.SetString("NEXT_SUBRES_ID", out_node.GetString("NEXT_SUBRES_ID"));
                } while (MPCF.Trim(out_node.GetString("NEXT_SUBRES_ID")) != "");

                if (sLayout.TrimEnd() != "")
                {
                    nodeLayout.Expand();
                }

                trvDesignList.EndUpdate();

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewSubResourcelList()" + "\r\n" + ex.Message);
                return false;
            }

        }


        // ViewPortList()
        //       - View Tool List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal sFactory As String
        //
        public bool ViewPortList(string sFactory, string sLayout, string sResID)
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_PORT_LIST_IN");
                TRSNode out_node = new TRSNode("FMB_VIEW_PORT_LIST_OUT");
                int i;
                TreeNode nodeFactory;
                TreeNode nodePort;
                TreeNode nodeLayout = null;
                TreeNode nodeResource = null;
                string sResource = "";
                string sPort = "";

                nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);

                MPCR.SetInMsg(in_node);
                in_node.Factory = sFactory;
                if (sLayout.TrimEnd() == "")
                {                    
                    in_node.ProcStep = '4';
                    in_node.AddString("RES_ID", sResID.TrimEnd());
                    nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sResID, false);
                }
                else
                {
                    if (sResID.TrimEnd() == "")
                    {
                        in_node.ProcStep = '8';
                        in_node.AddString("LAYOUT_ID", sLayout.TrimEnd());
                        nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                        if (nodeLayout == null)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        in_node.ProcStep = '7';
                        in_node.AddString("LAYOUT_ID", sLayout.TrimEnd());
                        in_node.AddString("RES_ID", sResID.TrimEnd());
                        nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                        nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sResID, true);
                        if (nodeLayout == null || nodeResource == null)
                        {
                            return false;
                        }
                    }

                }     
 
                in_node.AddChar("RES_TYPE", ' ');
                in_node.AddInt("NEXT_SEQ", 0);
                in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                in_node.AddString("NEXT_PORT_ID", " ");

                trvDesignList.BeginUpdate();

                do
                {

                    if (MPCR.CallService("FMB", "FMB_View_Port_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        sResource = MPCF.RTrim(out_node.GetList(0)[i].GetString("RES_ID"));
                        sPort = MPCF.RTrim(out_node.GetList(0)[i].GetString("PORT_ID"));
                        if (sLayout.TrimEnd() == "")
                        {
                            sLayout = "";
                            nodePort = nodeResource.Nodes.Add(sPort);
                            clsDesignListTag nodeTag = new clsDesignListTag();
                            nodeTag.SetTagData(sPort, sResource, modGlobalConstant.FMB_CATEGORY_PORT, sFactory, sLayout, false);
                            nodePort.Tag = nodeTag;
                            nodePort.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT_DOWN);
                            nodePort.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT_DOWN);
                        }
                        else
                        {
                            if (sResID.TrimEnd() == "")
                            {
                                nodePort = nodeLayout.Nodes.Add(sPort);
                                clsDesignListTag nodeTag = new clsDesignListTag();
                                nodeTag.SetTagData(sPort, sResource, modGlobalConstant.FMB_CATEGORY_PORT, sFactory, sLayout, true);
                                nodePort.Tag = nodeTag;
                                nodePort.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT);
                                nodePort.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT);
                            }
                            else
                            {

                                nodePort = nodeResource.Nodes.Add(sPort);
                                clsDesignListTag nodeTag = new clsDesignListTag();
                                
                                if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'Y')
                                {
                                    nodeTag.SetTagData(sPort, sResource, modGlobalConstant.FMB_CATEGORY_PORT, sFactory, MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")), true);
                                    nodePort.Tag = nodeTag;
                                    nodePort.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT);
                                    nodePort.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT);
                                }
                                else if (out_node.GetList(0)[i].GetChar("ATTACHED_FLAG") == 'N')
                                {
                                    if (MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")) == "")
                                    {
                                        nodeTag.SetTagData(sPort, sResource, modGlobalConstant.FMB_CATEGORY_PORT, sFactory, MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")), false);
                                        nodePort.Tag = nodeTag;
                                    }
                                    else
                                    {// 장비와 다른 Layout에 있는 경우
                                        nodeTag.SetTagData(sPort, sResource, modGlobalConstant.FMB_CATEGORY_PORT, sFactory, MPCF.RTrim(out_node.GetList(0)[i].GetString("LAYOUT_ID")), true);
                                        nodePort.Tag = nodeTag;
                                    }
                                    nodePort.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT_DOWN);
                                    nodePort.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_PORT_DOWN);
                                }
                            }
                        }
                    }

                    in_node.SetString("NEXT_PORT_ID", out_node.GetString("NEXT_PORT_ID"));
                } while (MPCF.Trim(out_node.GetString("NEXT_PORT_ID")) != "");

                if (sLayout.TrimEnd() != "")
                {
                    nodeLayout.Expand();
                }

                trvDesignList.EndUpdate();

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewPortList()" + "\r\n" + ex.Message);
                return false;
            }

        }

        
        // ViewUDRGroupList()
        //       - View User Define Resource Group List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool ViewUDRGroupList()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("FMB_View_UDR_Group_List_In");
                TRSNode out_node;
                   int i;
                TreeNode nodeGroup;
                string sLayout = "";
                ArrayList a_list = new ArrayList();

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("USER_NAME", MPGV.gsUserID, true);
                in_node.AddString("NEXT_GROUP", "");

                
                trvDesignList.BeginUpdate();
                
                for (i = trvDesignList.Nodes.Count - 1; i >= 0; i--)
                {
                    if (((clsDesignListTag)trvDesignList.Nodes[i].Tag).Category == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        trvDesignList.Nodes[i].Remove();
                    }
                }
                
                do
                {
                    out_node = new TRSNode("FMB_View_UDR_Group_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_UDR_Group_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    
                    a_list.Add(out_node);

                    in_node.SetString("NEXT_GROUP", out_node.GetString("NEXT_GROUP"));
                } while (in_node.GetString("NEXT_GROUP") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        sLayout = out_node.GetList(0)[i].GetString("GROUP_ID");
                        nodeGroup = trvDesignList.Nodes.Add(sLayout);
                        clsDesignListTag nodeTag = new clsDesignListTag();
                        nodeTag.SetTagData(sLayout, modGlobalConstant.FMB_CATEGORY_GROUP, "", sLayout, false);
                        nodeGroup.Tag = nodeTag;
                        nodeGroup.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_AREA);
                        nodeGroup.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_SUB_AREA);
                    }
                }
                trvDesignList.EndUpdate();
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewUDRGroupList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        // InitMainForm()
        //       - Initialize Main Form
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        protected override bool InitMainForm()
        {
            
            try
            {
                ToolStrip tolTemp = new ToolStrip();
                if (base.InitMainForm() == false) return false;
                if (GetAvailableFunctionList(mnuMain, 1, tolTemp) == false) return false;
                ToolStripManager.Merge(mnuDesign, "mnuMain");
                SetToolBar();

                ChangeMenuText(mnuMain);
                ChangeMenuText(mnuDesign);
                ChangeDockText(udmMDIMain);
                MPCF.ToClientLanguage(this);
                
                modGlobalVariable.gimlResource = this.imlResource;

                if (base.InitMainFormAfter() == false) return false;

                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.InitMainForm()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        // ChangeMyMenus()
        //       - Change Language of Menu
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByRef utbManager As UltraToolbarsManager
        //
        private void ChangeMyMenus(UltraToolbarsManager utbManager)
        {
            
            try
            {
                //object menu;
                
                if (utbManager == null)
                {
                    return;
                }
                
                //foreach (object tempLoopVar_menu in utbManager.Tools)
                foreach (Infragistics.Win.UltraWinToolbars.ToolBase menu in utbManager.Tools)
                {
                    //menu = tempLoopVar_menu;
                    //Menu.SharedProps.Caption = MPCF.FindLanguage(Menu.SharedProps.Caption, 2);
                    menu.SharedProps.Caption = MPCF.FindLanguage(menu.SharedProps.Caption, 2);
                }

                           
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ChangeMyMenus()" + "\r\n" + ex.Message);
            }
            
            
        }
        
        // ChangeDockText()
        //       - Change Language of Docking Controls
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByRef udmManager As UltraDockManager
        //
        private void ChangeDockText(UltraDockManager udmManager)
        {
            
            try
            {
                DockableControlPane DockPan;
                int i;
                
                if (udmManager == null)
                {
                    return;
                }
                
                foreach (DockableControlPane tempLoopVar_DockPan in udmManager.ControlPanes)
                {
                    DockPan = tempLoopVar_DockPan;
                    DockPan.Text = MPCF.FindLanguage(DockPan.Text, 0);
                }
                
                for (i = 0; i <= lisTools.Items.Count - 1; i++)
                {
                    lisTools.Items[i].Text = MPCF.FindLanguage(lisTools.Items[i].Text, 0);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ChangeDockText()" + "\r\n" + ex.Message);
            }
            
        }
        
        // SetBackGroundColorOfMDIForm()
        //       - Set Back Color of MDI Form
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        private void SetBackGroundColorOfMDIForm()
        {
            
            try
            {
                Control ctl;
                
                //MDI Background Color 蹂寃?
                //Loop through controls,
                //looking for controls of MdiClient type.
                foreach (Control tempLoopVar_ctl in this.Controls)
                {
                    ctl = tempLoopVar_ctl;
                    if ((ctl) is MdiClient)
                    {
                        
                        // If the control is the correct type,
                        // change the color.
                        ctl.BackColor = System.Drawing.Color.White;
                        break;
                    }
                }

                1.GetHashCode() ; //nop
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.SetBackGroundColorOfMDIForm()" + "\r\n" + ex.Message);
            }
            
        }
        
            
        // RefreshDesignList()
        //       - Refresh Design List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        public bool RefreshDesignList()
        {
            
            try
            {
                if (ViewFactoryList() == false)
                {
                    return false;
                }
                if (ViewFMBGroupList() == false)
                {
                    return false;
                }
                if (ViewLayoutFileList() == false)
                {
                    return false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.RefreshDesignList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        // RefreshUdrGroupList()
        //       - Refresh User Define Group List
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        public bool RefreshUdrGroupList()
        {
            
            try
            {
                if (ViewFMBGroupList() == false)
                {
                    return false;
                }
                if (ViewLayoutFileList() == false)
                {
                    return false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.RefreshUdrGroupList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        public bool RefreshFileList()
        {
            
            try
            {
                if (ViewLayoutFileList() == false)
                {
                    return false;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.RefreshFileList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        private bool LoadSystemMenu()
        {
            
            string filename = "SystemMenu.bin";
            System.IO.FileStream stream = null;
            
            try
            {
                stream = new System.IO.FileStream(Application.StartupPath + "\\" + filename, System.IO.FileMode.Open, System.IO.FileAccess.Read, System.IO.FileShare.Read);
                udmMDIMain.LoadFromBinary(stream);
                
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
        
        // SaveSystemMenu()
        //       - Save System Menu
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool SaveSystemMenu()
        {
            
            string filename = "SystemMenu.bin";
            System.IO.FileStream stream = null;
            
            try
            {
                stream = new System.IO.FileStream(Application.StartupPath + "\\" + filename, System.IO.FileMode.OpenOrCreate, System.IO.FileAccess.ReadWrite, System.IO.FileShare.None);
                this.udmMDIMain.SaveAsBinary(stream);
                
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
        
        private bool ReadLayOut(string sFile)
        {
            
            string sfilename;
            string sCount;
            int iCount;
            int i;
            Form frmChild;
            bool bFindForm;
            try
            {
                sfilename = sFile + ".fmb";
                
                StreamReader sr = File.OpenText(sfilename);
                sCount = sr.ReadLine();
                iCount = MPCF.ToInt(sCount);
                string[] sName = new string[iCount + 1];
                string[] sLayout = new string[iCount + 1];
                string[] sCategory = new string[iCount + 1];
                string[] sFactory = new string[iCount + 1];
                int[] iLocX = new int[iCount + 1];
                int[] iLocY = new int[iCount + 1];
                int[] iWidth = new int[iCount + 1];
                int[] iHeight = new int[iCount + 1];
                
                for (i = 0; i <= iCount - 1; i++)
                {
                    bFindForm = false;
                    sLayout[i] = sr.ReadLine();
                    sName[i] = FMBCF.GetStringBySeperator(sLayout[i], "/", 1);
                    iLocX[i] = MPCF.ToInt(FMBCF.GetStringBySeperator(sLayout[i], "/", 2));
                    iLocY[i] = MPCF.ToInt(FMBCF.GetStringBySeperator(sLayout[i], "/", 3));
                    iWidth[i] = MPCF.ToInt(FMBCF.GetStringBySeperator(sLayout[i], "/", 4));
                    iHeight[i] = MPCF.ToInt(FMBCF.GetStringBySeperator(sLayout[i], "/", 5));
                    sCategory[i] = FMBCF.GetStringBySeperator(sLayout[i], "/", 6);
                    sFactory[i] = FMBCF.GetStringBySeperator(sLayout[i], "/", 7);
                    foreach (Form tempLoopVar_frmChild in this.MdiChildren)
                    {
                        frmChild = tempLoopVar_frmChild;
                        if (sName[i] == frmChild.Name)
                        {
                            frmChild.Activate();
                            bFindForm = true;
                            break;
                        }
                    }
                    
                    if (bFindForm == false)
                    {
                        if (modGlobalVariable.gbAllFactory == false)
                        {
                            if (MPGV.gsFactory == sFactory[i])
                            {
                                AddNewForm(sName[i], sCategory[i]);
                            }
                        }
                        else
                        {
                            if (sCategory[i] == modGlobalConstant.FMB_CATEGORY_GROUP)
                            {
                                if (MPGV.gsFactory == sFactory[i])
                                {
                                    AddNewForm(sName[i], sCategory[i]);
                                }
                            }
                            else
                            {
                                AddNewForm(sName[i], sCategory[i]);
                            }
                        }
                    }
                }
                
                this.utmmMDIMain.Enabled = false;
                tsmTabbedMdi.Checked = false;
                
                foreach (Form tempLoopVar_frmChild in this.MdiChildren)
                {
                    frmChild = tempLoopVar_frmChild;
                    for (i = 0; i <= iCount - 1; i++)
                    {
                        if (sName[i] == frmChild.Name)
                        {
                            frmChild.StartPosition = FormStartPosition.Manual;
                            frmChild.Location = new System.Drawing.Point(iLocX[i], iLocY[i]);
                            frmChild.Size = new Size(iWidth[i], iHeight[i]);
                            break;
                        }
                    }
                }
                
                sr.Close();
                
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ReadLayOut()" + "\r\n" + ex.Message);
                return false;
            }
            
            return true;
            
        }
        
        
        private bool ViewLayoutFileList()
        {
            string[] sFiles;
            string sFile;
            TreeNode nodeFile;
            int i;
            try
            {
                trvDesignList.BeginUpdate();
                for (i = trvDesignList.Nodes.Count - 1; i >= 0; i--)
                {
                    if (((clsDesignListTag)trvDesignList.Nodes[i].Tag).Category == modGlobalConstant.FMB_CATEGORY_FILE)
                    {
                        trvDesignList.Nodes[i].Remove();
                    }
                }
                
                sFiles = Directory.GetFiles(Application.StartupPath, "*.fmb");
                foreach (string s in sFiles)
                {
                    sFile = s;
                    sFile = FMBCF.GetStringBySeperator(sFile, ".", 1);
                    nodeFile = trvDesignList.Nodes.Add(sFile);
                    clsDesignListTag nodeTag = new clsDesignListTag();
                    nodeTag.SetTagData(sFile, modGlobalConstant.FMB_CATEGORY_FILE, "", sFile, false);
                    nodeFile.Tag = nodeTag;
                    nodeFile.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RECIPE);
                    nodeFile.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_RECIPE);
                }
                
                trvDesignList.EndUpdate();
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ViewLayoutFileList()" + "\r\n" + ex.Message);
                return false;
            }
            
        }
        
        private void LoadDefaultLayout()
        {
            
            string sCategory;
            string sFactory;
            string sLayout;
            string sName = string.Empty;
            try
            {
                sCategory = MPCF.GetRegSetting(Application.ProductName, "DefaultLayout", "Category", "");
                sFactory = MPCF.GetRegSetting(Application.ProductName, "DefaultLayout", "Factory", "");
                sLayout = MPCF.GetRegSetting(Application.ProductName, "DefaultLayout", "Layout", "");
                if (sCategory == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sName = sFactory + ":" + sLayout;
                }
                else if (sCategory == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sName = sLayout;
                }
                if (sCategory.Trim() == "")
                {
                    return;
                }
                if (modGlobalVariable.gbAllFactory == false)
                {
                    if (MPGV.gsFactory == sFactory)
                    {
                        AddNewForm(sName, sCategory);
                    }
                }
                else
                {
                    if (sCategory == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        if (MPGV.gsFactory == sFactory)
                        {
                            AddNewForm(sName, sCategory);
                        }
                    }
                    else
                    {
                        AddNewForm(sName, sCategory);
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.LoadDefaultLayout()" + "\r\n" + ex.Message);
            }
            
        }
        
        public void ArrageLayouts(ArrayList sLayouts, int iLayoutCount)
        {
            
            int i;
            Form frmChild;
            bool bFindForm;
            try
            {
                for (i = 0; i <= sLayouts.Count - 1; i++)
                {
                    bFindForm = false;
                    foreach (Form tempLoopVar_frmChild in this.MdiChildren)
                    {
                        frmChild = tempLoopVar_frmChild;
                        if (((modGlobalVariable.gLayouts) sLayouts[i]).sFormName == frmChild.Name)
                        {
                            frmChild.Activate();
                            bFindForm = true;
                            break;
                        }
                    }
                    if (bFindForm == false)
                    {
                        AddNewForm(((modGlobalVariable.gLayouts)sLayouts[i]).sFormName, ((modGlobalVariable.gLayouts)sLayouts[i]).sTag);
                    }
                }
                this.utmmMDIMain.Enabled = false;
                tsmTabbedMdi.Checked = false;
                
                if (iLayoutCount == 2)
                {
                    SetSize(sLayouts, 1, 2);
                }
                else if (iLayoutCount == 4)
                {
                    SetSize(sLayouts, 2, 2);
                }
                else if (iLayoutCount == 6)
                {
                    SetSize(sLayouts, 3, 2);
                }
                else if (iLayoutCount == 9)
                {
                    SetSize(sLayouts, 3, 3);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.ArrageLayouts()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void SetSize(ArrayList sLayouts, int iWCnt, int iHCnt)
        {
            
            int iX;
            int iY;
            int iWidth;
            int iHeight;
            int i;
            int j;
            int k;
            Form frmChild;
            try
            {
                k = 0;
                
                for (i = 0; i <= iWCnt - 1; i++)
                {
                    for (j = 0; j <= iHCnt - 1; j++)
                    {
                        iX = ((m_MDIClient.Width - 4) / iWCnt) * i;
                        iY = ((m_MDIClient.Height - 4) / iHCnt) * j;
                        iWidth = (m_MDIClient.Width - 4) / iWCnt;
                        iHeight = (m_MDIClient.Height - 4) / iHCnt;
                        foreach (Form tempLoopVar_frmChild in this.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (k >= sLayouts.Count)
                            {
                                return;
                            }
                            if (((modGlobalVariable.gLayouts)sLayouts[k]).sFormName == frmChild.Name)
                            {
                                frmChild.StartPosition = FormStartPosition.Manual;
                                frmChild.Location = new System.Drawing.Point(iX, iY);
                                frmChild.Size = new Size(iWidth, iHeight);
                                k++;
                                break;
                            }
                        }
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.SetSize()" + "\r\n" + ex.Message);
            }
            
        }
        public bool ViewUTLPublishMessage(bool bActivated)
        {

            try
            {
                Form f;

                f = MPCF.GetChildForm(this, "frmFMBPublishMessage", false);

                if (bActivated == true)
                {
                    if (f == null)
                    {
                        MPGV.gbShowMessagePanel = true;
                    }
                    else
                    {
                        MPGV.gbShowMessagePanel = false;
                        ((frmFMBPublishMessage)f).SetMessageEvent(MPGV.gsMessage);
                    }
                }
                else
                {
                    if (f == null)
                    {
                        f = new frmFMBPublishMessage();
                        f.MdiParent = this;
                        f.Show();
                        ((frmFMBPublishMessage)f).SetMessageEvent(MPGV.gsMessage);
                    }
                    else
                    {
                        ((frmFMBPublishMessage)f).SetMessageEvent(MPGV.gsMessage);
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

        public bool LoadResource()
        {
            if (MPCF.LoadMessageResource("FMBMessage.xml") == false)
            {
                return false;
            }
            if (MPCF.LoadCaptionResource("FMBCaption.xml") == false)
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

        #region "Interface Function"

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
        public void FavoritesRefresh()
        {
        }
        public void MenuRefresh()
        {
        }
        public ArrayList GetFavoritesMenu()
        {
            return null;
        }
        public bool AddFavoritesMenu(string sTitle)
        {
            return true;
        }
        public bool RemoveFavoritesMenu(string sTitle)
        {
            return true;
        }
        public bool GetFactoryShiftInfor()
        {
            return true;
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
        public bool PublishBBSMsgTune()
        {
            return true;
        }
        public bool ViewBBSPublishMessage()
        {
            return true;
        }
       
        #endregion
      

        #region " Event Implementations"

        private void frmMDIMain_Load(object sender, System.EventArgs e)
        {
            try
            {
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

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.frmMDIMain_Load()" + "\r\n" + ex.Message);
            }
        }
        
        private void frmMDIMain_Activated(object sender, System.EventArgs e)
        {
            try
            {
                if (b_load_flag == false)
                {
                    this.Hide();

                    this.Top = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_top", "0"));
                    this.Left = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_left", "0"));
                    this.Width = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_width", "1024"));
                    this.Height = MPCF.ToInt(MPCF.GetRegSetting(Application.ProductName, "Option", "MDI_height", "768"));

                    b_load_flag = true;

                    if (MPCF.GetRegSetting(Application.ProductName, "Option", "BackGroundLogin", "N") == "Y")
                    {
                        bool UpgradeFlag = false;

                        if (MPCF.GetRegSetting(Application.ProductName, "Option", "BackGroundLogin", "") != "")
                            MPCF.DeleteRegSetting(Application.ProductName, "Option", "BackGroundLogin");

                        // 다운로드 파일명, 업그레이드 파일명, 클라이언트 버전을 얻기 위해서 frmLogin을 Load 시킴. 화면에는 보이지 않게 함. 
                        frmFMBLogin login = new frmFMBLogin();
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

                            if (MPIF.gInit.getMiddleware == "TIBRV")
                            {
                                MPCF.SaveRegSetting(Application.ProductName, "Option", "RvService", MPGV.gsRvService);
                                MPCF.SaveRegSetting(Application.ProductName, "Option", "RvNetwork", MPGV.gsRvNetwork);
                            }

                            MPGV.gbLogoutFlag = true;

                            Close();
                            Application.Exit();
                            return;
                        }

                    }
                    else
                    {

                        frmFMBLogin login = new frmFMBLogin();
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

                    if (InitMainForm() == false)
                    {
                        return;
                    }
                    
                    if (InitDesignList() == false)
                    {
                        return;
                    }

                    if (Miracom.FMBCore.FMBCF.PublishMsgTune() == false)
                    {
                        return;
                    }
                    
                    if (LoadSystemMenu() == false)
                    {
                        //Do Nothing
                    }
                    

                    if (modListRoutine.ViewGlobalOptionList() == false)
                    {
                        return;
                    }
                    
                    LoadDefaultLayout();
                    
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.frmMDIMain_Activated()" + "\r\n" + ex.Message);
            }
            
        }

        private void frmMDIMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                if (MPGV.gbLogoutFlag == false)
                {
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(2), "", MessageBoxButtons.YesNo, 2) == DialogResult.No)
                    {
                        e.Cancel = true;
                        return;
                    }
                }
                if (SaveSystemMenu() == false)
                {
                    //Do Nothing
                }

                if (this.WindowState != FormWindowState.Minimized)
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_top", this.Top.ToString());
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_left", this.Left.ToString());
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_width", this.Width.ToString());
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "MDI_height", this.Height.ToString());
                }

                this.SuspendLayout();
                if (trvDesignList != null)
                {
                    this.trvDesignList.Dispose();
                    this.trvDesignList = null;
                }

                if (lisTools != null)
                {
                    this.lisTools.Dispose();
                    this.lisTools = null;
                }

                if (udmMDIMain != null)
                {
                    this.udmMDIMain.Dispose();
                    this.udmMDIMain = null;
                }
                this.ResumeLayout(false);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.frmMDIMain_FormClosing()" + "\r\n" + ex.Message);
            }
        }

        private void lisTools_ItemDrag(object sender, System.Windows.Forms.ItemDragEventArgs e)
        {
            
            try
            {
                if ((e.Button & MouseButtons.Left) == MouseButtons.Left)
                {
                    try
                    {
                        modGlobalVariable.gNodeSelectedRes = null;
                        if (lisTools.SelectedItems.Count > 0)
                        {
                            modGlobalVariable.giToolType = Convert.ToInt32(lisTools.SelectedItems[0].Tag);
                        }
                    }
                    catch
                    {
                    }
                    finally
                    {
                        lisTools.DoDragDrop(e.Item, DragDropEffects.All | DragDropEffects.Link);
                    }
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.lisTools_ItemDrag()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void lisTools_MouseUp(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            
            try
            {
                modGlobalVariable.giToolType = ListBox.NoMatches;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.lisTools_MouseUp()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void trvDesignList_MouseUp(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            
            try
            {
                modGlobalVariable.gNodeSelectedRes = null;
                modGlobalVariable.giToolType = ListBox.NoMatches;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.trvDesignList_MouseUp()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void trvDesignList_MouseDown(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            
            try
            {
                //If trvDesignList.SelectedNode Is Nothing Then
                //    Exit Sub
                //End If

                modGlobalVariable.gNodeSelectedRes = trvDesignList.GetNodeAt(e.X, e.Y);
                trvDesignList.SelectedNode = modGlobalVariable.gNodeSelectedRes;
                
                //If e.Button = MouseButtons.Left Then
                //    If gNodeSelectedRes Is Nothing Then
                //        Exit Sub
                //    End If
                
                //    If CType(gNodeSelectedRes.Tag, clsDesignListTag).Category = FMB_CATEGORY_RESOURCE Then
                //        If CType(gNodeSelectedRes.Tag, clsDesignListTag).ResAttachFlag = True Then
                //            gNodeSelectedRes = Nothing
                //        End If
                //    Else
                //        gNodeSelectedRes = Nothing
                //    End If
                
                //    If CType(trvDesignList.SelectedNode.Tag, clsDesignListTag).Category = FMB_CATEGORY_LAYOUT Or _
                //        CType(trvDesignList.SelectedNode.Tag, clsDesignListTag).Category = FMB_CATEGORY_GROUP Then
                //        trvDesignList.SelectedNode = Nothing
                //    Else
                //        If CType(trvDesignList.SelectedNode.Tag, clsDesignListTag).Category = FMB_CATEGORY_RESOURCE Then
                //            If CType(trvDesignList.SelectedNode.Tag, clsDesignListTag).ResAttachFlag = True Then
                //                trvDesignList.SelectedNode = Nothing
                //            End If
                //        End If
                //    End If
                //End If
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.trvDesignList_MouseDown()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void trvDesignList_MouseMove(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            
            try
            {
                if (modGlobalVariable.gNodeSelectedRes == null)
                {
                    return;
                }
                
                if ((e.Button & MouseButtons.Left) != MouseButtons.Left)
                {
                    return;
                }

                if (!(((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).Category == modGlobalConstant.FMB_CATEGORY_RESOURCE
                    || ((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).Category == modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE
                    || ((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).Category == modGlobalConstant.FMB_CATEGORY_TOOL
                    || ((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).Category == modGlobalConstant.FMB_CATEGORY_PORT))

                {
                    modGlobalVariable.gNodeSelectedRes = null;
                    return;
                }

                if (((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).ResAttachFlag == true)
                {
                    return;
                }

                try
                {
                    if (((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).Category == modGlobalConstant.FMB_CATEGORY_RESOURCE)
                    {
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Resource);
                    }
                    else if (((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).Category == modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE)
                    {
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.SubResource);
                    }
                    else if (((clsDesignListTag)modGlobalVariable.gNodeSelectedRes.Tag).Category == modGlobalConstant.FMB_CATEGORY_PORT)
                    {
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Port);
                    }
                    else
                    {
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Tool);
                    }
                }
                catch
                {
                }
                finally
                {
                    lisTools.DoDragDrop(modGlobalVariable.gNodeSelectedRes, DragDropEffects.All | DragDropEffects.Link);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.trvDesignList_MouseMove()" + "\r\n" + ex.Message); 
            }
            
        }
        
        
        private void mnuDeleteResource_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                string sLayout;
                string sFactory;
                string sResource;
                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                switch (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category)
                {
                    case modGlobalConstant.FMB_CATEGORY_RESOURCE:

                        frmFMBCreateResource form = new frmFMBCreateResource(modGlobalConstant.MP_STEP_DELETE);
                        form.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        sFactory = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        sLayout = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        sResource = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        form.txtFactory.Text = sFactory;
                        form.cdvLayOut.Text = sLayout;
                        form.cdvResID.Text = sResource;
                        if (form.ShowDialog(this) == DialogResult.OK)
                        {
                            System.Windows.Forms.Form frmChild;
                            foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                            {
                                frmChild = tempLoopVar_frmChild;
                                if (frmChild is frmFMBDesign)
                                {
                                    if (((frmFMBDesign)frmChild).Name == MPCF.RTrim(form.txtFactory.Text) + ":" + MPCF.RTrim(form.cdvLayOut.Text))
                                    {
                                        ((frmFMBDesign)frmChild).pnlFMBDesign.Controls.Remove(FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, MPCF.RTrim(form.cdvResID.Text), Miracom.FMBUI.Enums.eToolType.Resource));
                                        break;
                                    }
                                }
                            }

                            1.GetHashCode(); //nop
                            //RefreshDesignList("3", sFactory, sLayout, sResource)
                        }
                        
                        break;

                    case modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE:

                        frmFMBCreateSubResource subform = new frmFMBCreateSubResource(modGlobalConstant.MP_STEP_DELETE);
                        subform.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        sFactory = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        sLayout = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        sResource = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        subform.txtFactory.Text = sFactory;
                        subform.cdvLayOut.Text = sLayout;
                        subform.cdvSubResID.Text = sResource;
                        subform.cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        if (subform.ShowDialog(this) == DialogResult.OK)
                        {
                            System.Windows.Forms.Form frmChild;
                            foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                            {
                                frmChild = tempLoopVar_frmChild;
                                if (frmChild is frmFMBDesign)
                                {
                                    if (((frmFMBDesign)frmChild).Name == MPCF.RTrim(subform.txtFactory.Text) + ":" + MPCF.RTrim(subform.cdvLayOut.Text))
                                    {
                                        ((frmFMBDesign)frmChild).pnlFMBDesign.Controls.Remove(FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, MPCF.RTrim(subform.cdvSubResID.Text), Miracom.FMBUI.Enums.eToolType.SubResource));
                                        break;
                                    }
                                }
                            }

                            1.GetHashCode(); //nop
                            //RefreshDesignList("3", sFactory, sLayout, sResource)
                        }

                        break;
                    case modGlobalConstant.FMB_CATEGORY_TOOL:

                        frmFMBCreateTool toolform = new frmFMBCreateTool(modGlobalConstant.MP_STEP_DELETE);
                        toolform.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        sFactory = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        sLayout = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        sResource = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        toolform.txtFactory.Text = sFactory;
                        toolform.cdvLayOut.Text = sLayout;
                        toolform.cdvToolID.Text = sResource;
                        if (toolform.ShowDialog(this) == DialogResult.OK)
                        {
                            System.Windows.Forms.Form frmChild;
                            foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                            {
                                frmChild = tempLoopVar_frmChild;
                                if (frmChild is frmFMBDesign)
                                {
                                    if (((frmFMBDesign)frmChild).Name == MPCF.RTrim(toolform.txtFactory.Text) + ":" + MPCF.RTrim(toolform.cdvLayOut.Text))
                                    {
                                        ((frmFMBDesign)frmChild).pnlFMBDesign.Controls.Remove(FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, MPCF.RTrim(toolform.cdvToolID.Text), Miracom.FMBUI.Enums.eToolType.Tool));
                                        break;
                                    }
                                }
                            }

                            1.GetHashCode(); //nop
                            //RefreshDesignList("3", sFactory, sLayout, sResource)
                        }

                        break;

                    case modGlobalConstant.FMB_CATEGORY_PORT:

                        frmFMBCreatePort portform = new frmFMBCreatePort(modGlobalConstant.MP_STEP_DELETE);
                        portform.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        sFactory = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        sLayout = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        sResource = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        portform.txtFactory.Text = sFactory;
                        portform.cdvLayOut.Text = sLayout;
                        portform.cdvPortID.Text = sResource;
                        portform.cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        if (portform.ShowDialog(this) == DialogResult.OK)
                        {
                            System.Windows.Forms.Form frmChild;
                            foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                            {
                                frmChild = tempLoopVar_frmChild;
                                if (frmChild is frmFMBDesign)
                                {
                                    if (((frmFMBDesign)frmChild).Name == MPCF.RTrim(portform.txtFactory.Text) + ":" + MPCF.RTrim(portform.cdvLayOut.Text))
                                    {
                                        ((frmFMBDesign)frmChild).pnlFMBDesign.Controls.Remove(FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, MPCF.RTrim(portform.cdvPortID.Text), MPCF.RTrim(portform.cdvResID.Text), Miracom.FMBUI.Enums.eToolType.Port));
                                        break;
                                    }
                                }
                            }

                            1.GetHashCode(); //nop
                            //RefreshDesignList("3", sFactory, sLayout, sResource)
                        }

                        break;

                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuDeleteResource_Click()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuUpdateLayout_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                frmFMBCreateLayOut form = new frmFMBCreateLayOut(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Layout);
                form.cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                form.ShowDialog(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuUpdateLayout_Click()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuUpdateUserGroupDesign_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                Form form;
                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                form = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmFMBCreateUDRGroup");
                if (form == null)
                {
                    form = new frmFMBCreateUDRGroup(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout);
                    form.MdiParent = this;
                    form.Show();
                }

                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuUpdateUserGroupDesign_Click()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuProperties_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                switch (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category)
                {
                    case modGlobalConstant.FMB_CATEGORY_RESOURCE:

                        frmFMBCreateResource form = new frmFMBCreateResource(modGlobalConstant.MP_STEP_VIEW);
                        form.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        form.txtFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        form.cdvLayOut.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        form.cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        if (form.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }

                        break;

                    case modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE:

                        frmFMBCreateSubResource subform = new frmFMBCreateSubResource(modGlobalConstant.MP_STEP_VIEW);
                        subform.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        subform.txtFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        subform.cdvLayOut.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        subform.cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        subform.cdvSubResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        if (subform.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }

                        break;

                    case modGlobalConstant.FMB_CATEGORY_TOOL:

                        frmFMBCreateTool toolform = new frmFMBCreateTool(modGlobalConstant.MP_STEP_VIEW);
                        toolform.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        toolform.txtFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        toolform.cdvLayOut.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        toolform.cdvToolID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        if (toolform.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }

                        break;

                    case modGlobalConstant.FMB_CATEGORY_PORT:

                        frmFMBCreatePort portform = new frmFMBCreatePort(modGlobalConstant.MP_STEP_VIEW);
                        portform.Tag = modGlobalConstant.FMB_CATEGORY_LAYOUT;
                        portform.txtFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        portform.cdvLayOut.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout;
                        portform.cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        portform.cdvPortID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        if (portform.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }

                        break;

                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuProperties_Click()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuViewResourceStatus_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                switch (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category)
                {
                    case modGlobalConstant.FMB_CATEGORY_RESOURCE:

                        Form form = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmFMBViewResourceStatus");
                        if (form == null)
                        {
                            form = new frmFMBViewResourceStatus();
                        }
                        ((frmFMBViewResourceStatus)form).cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        ((frmFMBViewResourceStatus)form).cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        form.MdiParent = MPGV.gfrmMDI;
                        form.Show();
                        ((frmFMBViewResourceStatus)form).btnView.PerformClick();
                        break;
                    case modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE:

                        Form subform = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmFMBViewSubResourceStatus");
                        if (subform == null)
                        {
                            subform = new frmFMBViewSubResourceStatus();
                        }
                        ((frmFMBViewSubResourceStatus)subform).cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        ((frmFMBViewSubResourceStatus)subform).cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        ((frmFMBViewSubResourceStatus)subform).cdvSubResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        subform.MdiParent = MPGV.gfrmMDI;
                        subform.Show();
                        ((frmFMBViewSubResourceStatus)subform).btnView.PerformClick();
                        break;
                    case modGlobalConstant.FMB_CATEGORY_PORT:

                        Form portform = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmFMBViewPortStatus");
                        if (portform == null)
                        {
                            portform = new frmFMBViewPortStatus();
                        }
                        ((frmFMBViewPortStatus)portform).cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        ((frmFMBViewPortStatus)portform).cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        ((frmFMBViewPortStatus)portform).cdvPortID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        portform.MdiParent = MPGV.gfrmMDI;
                        portform.Show();
                        ((frmFMBViewPortStatus)portform).btnView.PerformClick();
                        break;
                    case modGlobalConstant.FMB_CATEGORY_TOOL:

                        Form toolform = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmFMBViewToolStatus");
                        if (toolform == null)
                        {
                            toolform = new frmFMBViewToolStatus();
                        }
                        ((frmFMBViewToolStatus)toolform).cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        ((frmFMBViewToolStatus)toolform).cdvToolID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        toolform.MdiParent = MPGV.gfrmMDI;
                        toolform.Show();
                        ((frmFMBViewToolStatus)toolform).btnView.PerformClick();
                        break;
                    default:
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuViewResourceStatus_Click()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuViewResourceHistory_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                switch (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category)
                {
                    case modGlobalConstant.FMB_CATEGORY_RESOURCE:
                      

                        Form form = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmFMBViewResourceHistory");
                        if (form == null)
                        {
                            form = new frmFMBViewResourceHistory();
                        }
                        ((frmFMBViewResourceHistory)form).cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        ((frmFMBViewResourceHistory)form).cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        form.MdiParent = MPGV.gfrmMDI;
                        form.Show();
                        ((frmFMBViewResourceHistory)form).btnView.PerformClick();
                        break;
                    case modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE:

                        frmFMBViewSubResourceHistory subresForm = new frmFMBViewSubResourceHistory();

                        subresForm.cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;

                        subresForm.cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        subresForm.cdvSubResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        subresForm.MdiParent = MPGV.gfrmMDI;
                        subresForm.Show();
                        subresForm.btnProcess.PerformClick();
                        break;

                    case modGlobalConstant.FMB_CATEGORY_PORT:

                        frmFMBViewPortHistory portForm = new frmFMBViewPortHistory();

                        portForm.cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;

                        portForm.cdvResID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        portForm.cdvPortID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        portForm.MdiParent = MPGV.gfrmMDI;
                        portForm.Show();
                        portForm.btnProcess.PerformClick();
                        break;
                    case modGlobalConstant.FMB_CATEGORY_TOOL:

                        frmFMBViewToolHistory toolForm = new frmFMBViewToolHistory();

                        toolForm.cdvFactory.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory;
                        toolForm.cdvToolType.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        toolForm.cdvToolID.Text = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        toolForm.MdiParent = MPGV.gfrmMDI;
                        toolForm.Show();
                        toolForm.btnProcess.PerformClick();
                        break;
                    default:
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.frmFMBViewResourceHistory()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuDesignList_Popup(object sender, System.EventArgs e)
        {
            
            try
            {
                if (trvDesignList.SelectedNode == null)
                {
                    mnuDeleteResource.Visible = false;
                    mnuUpdateLayout.Visible = false;
                    mnuUpdateUserGroupDesign.Visible = false;
                    mnuProperties.Visible = false;
                    mnuSeperator1.Visible = false;
                    mnuViewResourceStatus.Visible = false;
                    mnuViewResourceHistory.Visible = false;
                    mnuTranEvent.Visible = false;
                    mnuRefreshDesignList.Visible = true;
                    mnuDeleteFile.Visible = false;
                    return;
                }
                
                switch (((clsDesignListTag) trvDesignList.SelectedNode.Tag).Category)
                {
                    case modGlobalConstant.FMB_CATEGORY_FACTORY:
                        
                        mnuDeleteResource.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuProperties.Visible = false;
                        mnuSeperator1.Visible = false;
                        mnuViewResourceStatus.Visible = false;
                        mnuViewResourceHistory.Visible = false;
                        mnuTranEvent.Visible = false;
                        mnuRefreshDesignList.Visible = true;
                        mnuDeleteFile.Visible = false;
                        break;
                    case modGlobalConstant.FMB_CATEGORY_LAYOUT:
                        
                        mnuDeleteResource.Visible = false;
                        mnuUpdateLayout.Visible = true;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuProperties.Visible = false;
                        mnuSeperator1.Visible = false;
                        mnuViewResourceStatus.Visible = false;
                        mnuViewResourceHistory.Visible = false;
                        mnuTranEvent.Visible = false;
                        mnuRefreshDesignList.Visible = true;
                        mnuDeleteFile.Visible = false;
                        break;
                    case modGlobalConstant.FMB_CATEGORY_GROUP:
                        
                        mnuDeleteResource.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = true;
                        mnuProperties.Visible = false;
                        mnuSeperator1.Visible = false;
                        mnuViewResourceStatus.Visible = false;
                        mnuViewResourceHistory.Visible = false;
                        mnuTranEvent.Visible = false;
                        mnuRefreshDesignList.Visible = false;
                        mnuDeleteFile.Visible = false;
                        break;
                    case modGlobalConstant.FMB_CATEGORY_RESOURCE:
                        
                        if (((clsDesignListTag) trvDesignList.SelectedNode.Tag).ResAttachFlag == true)
                        {
                            mnuDeleteResource.Visible = true;
                            mnuProperties.Visible = true;
                            mnuSeperator1.Visible = true;
                            mnuRefreshDesignList.Visible = false;
                            mnuDeleteResource.Text = "Delete Resource";
                            mnuProperties.Text = "Resource Properties";
                        }
                        else
                        {
                            mnuDeleteResource.Visible = false;
                            mnuProperties.Visible = false;
                            mnuSeperator1.Visible = false;
                            mnuRefreshDesignList.Visible = true;
                        }
                        
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuViewResourceStatus.Visible = true;
                        mnuViewResourceHistory.Visible = true;
                        mnuTranEvent.Visible = true;
                        mnuViewResourceStatus.Text = "Resource Status";
                        mnuViewResourceHistory.Text = "Resource History";
                        mnuTranEvent.Text = "Resource Event";
                        mnuDeleteFile.Visible = false;
                        break;

                    case modGlobalConstant.FMB_CATEGORY_TOOL:

                        if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).ResAttachFlag == true)
                        {
                            mnuDeleteResource.Visible = true;
                            mnuProperties.Visible = true;
                            mnuSeperator1.Visible = true;
                            mnuDeleteResource.Text = "Delete Tool";
                            mnuProperties.Text = "Tool Properties";
                        }
                        else
                        {
                            mnuDeleteResource.Visible = false;
                            mnuProperties.Visible = false;
                            mnuSeperator1.Visible = false;
                        }
                        mnuRefreshDesignList.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuViewResourceStatus.Visible = true;
                        mnuViewResourceHistory.Visible = true;
                        mnuTranEvent.Visible = true;
                        mnuViewResourceStatus.Text = "Tool Status";
                        mnuViewResourceHistory.Text = "Tool History";
                        mnuTranEvent.Text = "Tool Event";
                        mnuDeleteFile.Visible = false;
                        break;

                    case modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE:

                        if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).ResAttachFlag == true)
                        {
                            mnuDeleteResource.Visible = true;
                            mnuProperties.Visible = true;
                            mnuSeperator1.Visible = true;
                            mnuDeleteResource.Text = "Delete SubResource";
                            mnuProperties.Text = "SubResource Properties";
                        }
                        else
                        {
                            mnuDeleteResource.Visible = false;
                            mnuProperties.Visible = false;
                            mnuSeperator1.Visible = false;
                        }
                        mnuRefreshDesignList.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuViewResourceStatus.Visible = true;
                        mnuViewResourceHistory.Visible = true;
                        mnuTranEvent.Visible = true;
                        mnuViewResourceStatus.Text = "SubResource Status";
                        mnuViewResourceHistory.Text = "SubResource History";
                        mnuTranEvent.Text = "SubResource Event";
                        mnuDeleteFile.Visible = false;
                        break;

                    case modGlobalConstant.FMB_CATEGORY_PORT:

                        if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).ResAttachFlag == true)
                        {
                            mnuDeleteResource.Visible = true;
                            mnuProperties.Visible = true;
                            mnuSeperator1.Visible = true;
                            mnuDeleteResource.Text = "Delete Port";
                            mnuProperties.Text = "Port Properties";
                        }
                        else
                        {
                            mnuDeleteResource.Visible = false;
                            mnuProperties.Visible = false;
                            mnuSeperator1.Visible = false;
                        }
                        mnuRefreshDesignList.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuViewResourceStatus.Visible = true;
                        mnuViewResourceHistory.Visible = true;
                        mnuTranEvent.Visible = true;
                        mnuViewResourceStatus.Text = "Port Status";
                        mnuViewResourceHistory.Text = "Port History";
                        mnuTranEvent.Text = "Port Event";
                        mnuDeleteFile.Visible = false;
                        break;
                    case modGlobalConstant.FMB_CATEGORY_TAG:
                        
                        mnuRefreshDesignList.Visible = false;
                        mnuDeleteResource.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuProperties.Visible = false;
                        mnuSeperator1.Visible = false;
                        mnuViewResourceStatus.Visible = false;
                        mnuViewResourceHistory.Visible = false;
                        mnuTranEvent.Visible = false;
                        mnuDeleteFile.Visible = false;
                        break;
                    case modGlobalConstant.FMB_CATEGORY_FILE:
                        
                        mnuDeleteResource.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuProperties.Visible = false;
                        mnuSeperator1.Visible = false;
                        mnuViewResourceStatus.Visible = false;
                        mnuViewResourceHistory.Visible = false;
                        mnuTranEvent.Visible = false;
                        mnuRefreshDesignList.Visible = true;
                        mnuDeleteFile.Visible = true;
                        break;
                    default:
                        
                        mnuRefreshDesignList.Visible = false;
                        mnuDeleteResource.Visible = false;
                        mnuUpdateLayout.Visible = false;
                        mnuUpdateUserGroupDesign.Visible = false;
                        mnuProperties.Visible = false;
                        mnuSeperator1.Visible = false;
                        mnuViewResourceStatus.Visible = false;
                        mnuViewResourceHistory.Visible = false;
                        mnuTranEvent.Visible = false;
                        mnuDeleteFile.Visible = false;
                        break;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuDesignList_Popup()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuTranEvent_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                switch (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category)
                {
                    case modGlobalConstant.FMB_CATEGORY_RESOURCE:

                        Form form = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmRASTranEvent");
                        if (form == null)
                        {
                            form = new frmRASTranEvent();
                        }
                        MPGV.gsCurrentRes_ID = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        form.MdiParent = MPGV.gfrmMDI;
                        form.Show();
                        MPGV.gsCurrentRes_ID = "";
                        break;

                    case modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE:
                        MPGV.gsCurrentRes_ID = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        //MPGV.gsCurrentSubres_ID = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        Form subresForm = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmRASTranSubEvent");
                        if (subresForm == null)
                        {
                            subresForm = new frmRASTranSubEvent();
                        }

                        subresForm.MdiParent = MPGV.gfrmMDI;
                        subresForm.Show();

                        MPGV.gsCurrentRes_ID = "";
                        //MPGV.gsCurrentSubres_ID = "";
                        break;
                    case modGlobalConstant.FMB_CATEGORY_PORT:
                        MPGV.gsCurrentRes_ID = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey;
                        //MPGV.gsCurrentSubres_ID = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key;
                        Form portForm = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmRASTranChangePortStatus");
                        if (portForm == null)
                        {
                            portForm = new frmRASTranChangePortStatus();
                        }

                        portForm.MdiParent = MPGV.gfrmMDI;
                        portForm.Show();

                        MPGV.gsCurrentRes_ID = "";
                        //MPGV.gsCurrentSubres_ID = "";
                        break;
                    case modGlobalConstant.FMB_CATEGORY_TOOL:

                        frmRASTranToolEvent toolForm = new frmRASTranToolEvent();

                        toolForm.MdiParent = MPGV.gfrmMDI;
                        toolForm.Show();
                        if (toolForm == null)
                        {
                            toolForm = new frmRASTranToolEvent();
                        }
                        toolForm.MdiParent = MPGV.gfrmMDI;
                        toolForm.Show();

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuTranEvent_Click()" + "\r\n" + ex.Message);
            }
            
        }
        
        private void mnuRefreshDesignList_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (trvDesignList.SelectedNode == null)
                {
                    InitDesignList();
                    return;
                }
                if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category == modGlobalConstant.FMB_CATEGORY_FACTORY)
                {
                    ViewLayoutList(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory);
                    ViewResourceList(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory, "");
                    //ViewSubResourceList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "");
                    //ViewPortList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "");
                    //ViewToolList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "");
                }
                else if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    ViewResourceList(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Layout);
                    ViewSubResourceList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout, "");
                    ViewPortList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout, "");
                    ViewToolList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout);
                }
                else if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category == modGlobalConstant.FMB_CATEGORY_RESOURCE)
                {
                    trvDesignList.SelectedNode.Nodes.Clear();
                    ViewSubResourceList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "", ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key);
                    ViewPortList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "", ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key);
                    
                }
                else if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category == modGlobalConstant.FMB_CATEGORY_FILE)
                {
                    ViewLayoutFileList();
                }
                
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.mnuRefreshDesignList_Click()" + "\r\n" + ex.Message);
            }
            
        }
        
        #endregion
        
        private void trvDesignList_Click(object sender, System.EventArgs e)
        {
            
            try
            {
                bool bFindForm = false;

                if (trvDesignList.SelectedNode == null)
                {
                    return;
                }
                Form frmChild;
                string sSelectedForm = string.Empty;

                switch (((clsDesignListTag) trvDesignList.SelectedNode.Tag).Category)
                {
                    case modGlobalConstant.FMB_CATEGORY_FACTORY:
                        
                        if (((clsDesignListTag) trvDesignList.SelectedNode.Tag).LoadFlag == false)
                        {
                            if (ViewLayoutList(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory) == false)
                            {
                                break;
                            }
                            if (ViewResourceList(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory, "") == false)
                            {
                                break;
                            }
                            //if (ViewSubResourceList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "") == false)
                            //{
                            //    break;
                            //}
                            //if (ViewPortList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "") == false)
                            //{
                            //    break;
                            //}
                            /*
                            if (ViewToolList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, "") == false)
                            {
                                break;
                            }
                            */
                            ((clsDesignListTag) trvDesignList.SelectedNode.Tag).LoadFlag = true;
                            trvDesignList.SelectedNode.Expand();
                        }
                        break;
                    case modGlobalConstant.FMB_CATEGORY_LAYOUT:
                        
                        sSelectedForm = ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory + ":" + ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Layout;
                        //Form frmChild;
                        foreach (Form tempLoopVar_frmChild in this.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (sSelectedForm == frmChild.Name)
                            {
                                frmChild.Activate();
                                bFindForm = true;
                                break;
                            }
                        }

                        if (bFindForm == false)
                        {
                            string sTag = ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Category;
                            AddNewForm(sSelectedForm, sTag);
                        }
                        if (((clsDesignListTag) trvDesignList.SelectedNode.Tag).LoadFlag == false)
                        {
                            ViewResourceList(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Layout);
                            ViewSubResourceList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout, "");
                            ViewPortList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout, "");
                            ViewToolList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout);
                            ((clsDesignListTag) trvDesignList.SelectedNode.Tag).LoadFlag = true;
                            trvDesignList.SelectedNode.Expand();
                        }
                        break;
                    case modGlobalConstant.FMB_CATEGORY_GROUP:
                        
                        sSelectedForm = ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Layout;
                        //Form frmChild;
                        foreach (Form tempLoopVar_frmChild in this.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (sSelectedForm == frmChild.Name)
                            {
                                frmChild.Activate();
                                bFindForm = true;
                                break;
                            }
                        }

                        if (bFindForm == false)
                        {
                            string strTag = ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Category;
                            AddNewForm(sSelectedForm, strTag);
                        }
                        break;
                    case modGlobalConstant.FMB_CATEGORY_RESOURCE:
                        
                        //System.Windows.Forms.Form frmChild;
                        foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (frmChild is frmFMBDesign)
                            {
                                if (((frmFMBDesign) frmChild).Name == ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Factory + ":" + ((clsDesignListTag) trvDesignList.SelectedNode.Tag).Layout)
                                {
                                    ((frmFMBDesign) frmChild).Activate();
                                    FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key, Miracom.FMBUI.Enums.eToolType.Resource).Select();
                                    break;
                                }
                            }
                        }
                        if (((clsDesignListTag)trvDesignList.SelectedNode.Tag).LoadFlag == false )
                        {
                            ViewSubResourceList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key);
                            ViewPortList(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key);
                            ((clsDesignListTag)trvDesignList.SelectedNode.Tag).LoadFlag = true;
                            trvDesignList.SelectedNode.Expand();
                        }
                        break;
                    case modGlobalConstant.FMB_CATEGORY_PORT:

                        //System.Windows.Forms.Form frmChild;
                        foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (frmChild is frmFMBDesign)
                            {
                                if (((frmFMBDesign)frmChild).Name == ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory + ":" + ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout)
                                {
                                    ((frmFMBDesign)frmChild).Activate();
                                    FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey, Miracom.FMBUI.Enums.eToolType.Port).Select();
                                    break;
                                }
                            }
                        }
                        break;
                    case modGlobalConstant.FMB_CATEGORY_SUB_RESOURCE:

                        //System.Windows.Forms.Form frmChild;
                        foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (frmChild is frmFMBDesign)
                            {
                                if (((frmFMBDesign)frmChild).Name == ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory + ":" + ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout)
                                {
                                    ((frmFMBDesign)frmChild).Activate();
                                    FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).SubKey, Miracom.FMBUI.Enums.eToolType.SubResource).Select();
                                    break;
                                }
                            }
                        }
                        
                        break;
                    case modGlobalConstant.FMB_CATEGORY_TOOL:

                        //System.Windows.Forms.Form frmChild;
                        foreach (System.Windows.Forms.Form tempLoopVar_frmChild in this.MdiChildren)
                        {
                            frmChild = tempLoopVar_frmChild;
                            if (frmChild is frmFMBDesign)
                            {
                                if (((frmFMBDesign)frmChild).Name == ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Factory + ":" + ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout)
                                {
                                    ((frmFMBDesign)frmChild).Activate();
                                    FMBCF.GetControl(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ((clsDesignListTag)trvDesignList.SelectedNode.Tag).Key, Miracom.FMBUI.Enums.eToolType.Tool).Select();
                                    break;
                                }
                            }
                        }
                        break;
                    case modGlobalConstant.FMB_CATEGORY_TAG:
                        
                        break;
                    case modGlobalConstant.FMB_CATEGORY_FILE:
                        
                        ReadLayOut(((clsDesignListTag) trvDesignList.SelectedNode.Tag).Layout);
                        break;
                    default:
                        
                        break;
                        
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.trvDesignList_Click()" + "\r\n" + ex.Message);
            }
            
        }

        public bool RefreshDesignList(string sStep, string sFactory, string sLayout, string sResource, string sMoveLayout)
        {
            if (RefreshDesignList(sStep, sFactory, sLayout, sResource,"", sMoveLayout) == false)
            {
                return false;
            }
            return true;
        }
        public bool RefreshDesignList(string sStep, string sFactory, string sLayout, string sResource, string sParent, string sMoveLayout)
        {
            
            try
            {
                TreeNode nodeFactory;
                TreeNode nodeLayout;
                TreeNode nodeResource;
                int i;

                nodeFactory = FMBCF.FindTreeNode(trvDesignList, null, sFactory, false);
                
                switch (sStep.TrimEnd())
                {
                    
                case "1": //Delete Layout
                    
                    int iSubNodeCount = 0;
                    nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                    if (nodeLayout != null)
                    {
                        iSubNodeCount = nodeLayout.Nodes.Count;
                        nodeLayout.Remove();
                    }
                    
                    if (iSubNodeCount > 0)
                    {
                        for (i = nodeFactory.GetNodeCount(false) - 1; i >= 0; i--)
                        {
                            if (nodeFactory.Nodes[i].ImageIndex == Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN))
                            {
                                nodeFactory.Nodes[i].Remove();
                                continue;
                            }                            
                        }
                        if (ViewResourceList(sFactory, "") == false)
                        {
                            return false;
                        }
                        
                    }
                    break;
                case "2": //Layout에 Attach된 경우 - Refresh Attach Resource List and Remove Not Attach Resource

                    for (i = nodeFactory.GetNodeCount(false) - 1; i >= 0; i--)
                    {
                        if (nodeFactory.Nodes[i].ImageIndex == Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN))
                        {
                            nodeFactory.Nodes[i].Remove();
                            continue;
                        }
                    }
                    if (ViewResourceList(sFactory, "") == false)
                    {
                        return false;
                    }

                    if (ViewResourceList(sFactory, sLayout) == false)
                    {
                        return false;
                    }
                    if (ViewSubResourceList(sFactory, sLayout, "") == false)
                    {
                        return false;
                    }

                    if (ViewPortList(sFactory, sLayout, "") == false)
                    {
                        return false;
                    }

                    if (ViewToolList(sFactory, sLayout) == false)
                    {
                        return false;
                    }
                    if (MPCF.Trim(sParent) != "")
                    {
                        nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                        if (nodeLayout != null)
                        {
                            nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeLayout, sParent, false);
                            if (nodeResource != null)
                            {
                                for (i = nodeResource.Nodes.Count - 1; i >= 0; i--)
                                {
                                    nodeResource.Nodes[i].Remove();
                                }
                                if (ViewSubResourceList(sFactory, sLayout,sParent) == false)
                                {
                                    return false;
                                }

                                if (ViewPortList(sFactory, sLayout, sParent) == false)
                                {
                                    return false;
                                }
                                nodeResource.Expand();
                                ((clsDesignListTag)nodeResource.Tag).LoadFlag = true;
                            }
                        }
                    }
                    foreach (TreeNode temp_node in nodeFactory.Nodes)
                    {
                        if (temp_node.Text != sLayout)
                        {
                            if (temp_node.ImageIndex == (int)SMALLICON_INDEX.IDX_AREA)
                            {
                                temp_node.Nodes.Clear();
                                ((clsDesignListTag)temp_node.Tag).LoadFlag = false;
                            }
                        }
                    }
                    
                    break;
                    
                case "3": //Layout에서 삭제된 경우

                    nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                    if (nodeLayout != null)
                    {
                        nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeLayout, sResource, false);
                        if (nodeResource != null)
                        {
                            nodeResource.Remove();
                        }
                    }
                    for (i = nodeFactory.Nodes.Count - 1; i >= 0; i--)
                    {
                        if (nodeFactory.Nodes[i].ImageIndex == Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN))
                        {
                            nodeFactory.Nodes[i].Remove();
                            continue;
                        }
                        
                    }
                    if (ViewResourceList(sFactory, "") == false)
                    {
                        return false;
                    }
                    if (MPCF.Trim(sParent) != "")
                    {
                        nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                        if (nodeLayout != null)
                        {
                            nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeLayout, sParent, false);
                            if (nodeResource != null)
                            {
                                for (i = nodeResource.Nodes.Count - 1; i >= 0; i--)
                                {
                                    nodeResource.Nodes[i].Remove();
                                }
                                if (ViewSubResourceList(sFactory, sLayout, sParent) == false)
                                {
                                    return false;
                                }

                                if (ViewPortList(sFactory, sLayout, sParent) == false)
                                {
                                    return false;
                                }
                                nodeResource.Expand();
                                ((clsDesignListTag)nodeResource.Tag).LoadFlag = true;
                            }
                        }
                    }
                    foreach (TreeNode temp_node in nodeFactory.Nodes)
                    {
                        if (temp_node.Text != sLayout)
                        {
                            if (temp_node.ImageIndex == (int)SMALLICON_INDEX.IDX_AREA)
                            {
                                temp_node.Nodes.Clear();
                                ((clsDesignListTag)temp_node.Tag).LoadFlag = false;
                            }
                        }
                    }
                    break;
                    
                case "4": //Layout에서 다른 Layout으로 move

                    nodeLayout = FMBCF.FindTreeNode(trvDesignList, nodeFactory, sLayout, false);
                    if (nodeLayout != null)
                    {
                        nodeResource = FMBCF.FindTreeNode(trvDesignList, nodeLayout, sResource, false);
                        if (nodeResource != null)
                        {
                            nodeResource.Remove();
                        }
                    }
                    if (ViewResourceList(sFactory, sLayout) == false)
                    {
                        return false;
                    }
                    if (ViewSubResourceList(sFactory, sLayout, "") == false)
                    {
                        return false;
                    }
                    if (ViewPortList(sFactory, sLayout, "") == false)
                    {
                        return false;
                    }

                    if (ViewToolList(sFactory, sLayout) == false)
                    {
                        return false;
                    }
                    if (ViewResourceList(sFactory, sMoveLayout) == false)
                    {
                        return false;
                    }
                    if (ViewSubResourceList(sFactory, sMoveLayout, "") == false)
                    {
                        return false;
                    }
                    if (ViewPortList(sFactory, sMoveLayout, "") == false)
                    {
                        return false;
                    }

                    if (ViewToolList(sFactory, sMoveLayout) == false)
                    {
                        return false;
                    }
                    
                    break;
                    
                case "5": //Layout에 multi로 추가 삭제
                    
                    for (i = nodeFactory.GetNodeCount(false) - 1; i >= 0; i--)
                    {
                        if (nodeFactory.Nodes[i].ImageIndex == Convert.ToInt32(SMALLICON_INDEX.IDX_RESOURCE_DOWN))
                        {
                            nodeFactory.Nodes[i].Remove();
                            continue;
                        }                        
                    }
                    if (ViewResourceList(sFactory, "") == false)
                    {
                        return false;
                    }
                    
                    if (ViewResourceList(sFactory, sLayout) == false)
                    {
                        return false;
                    }
                   
                    if (ViewSubResourceList(sFactory, sLayout, "") == false)
                    {
                        return false;
                    }
                    
                    if (ViewPortList(sFactory, sLayout, "") == false)
                    {
                        return false;
                    }
                   
                    if (ViewToolList(sFactory, sLayout) == false)
                    {
                        return false;
                    }
                    foreach (TreeNode temp_node in nodeFactory.Nodes)
                    {
                        if (temp_node.Text != sLayout)
                        {
                            if (temp_node.ImageIndex == (int)SMALLICON_INDEX.IDX_AREA)
                            {
                                temp_node.Nodes.Clear();
                                ((clsDesignListTag)temp_node.Tag).LoadFlag = false;
                            }
                        }
                    }
                    break;
                    
                case "6": //Add Layout List
                    
                    int iIndex = 0;
                    if (((clsDesignListTag) nodeFactory.Tag).LoadFlag == true)
                    {
                        nodeLayout = new TreeNode(sLayout);
                        for (i = 0; i <= nodeFactory.Nodes.Count - 1; i++)
                        {
                            if (((clsDesignListTag) nodeFactory.Nodes[i].Tag).Category == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                            {
                                if (MPCF.ToInt(sLayout) < MPCF.ToInt(nodeFactory.Nodes[i].Text))
                                {
                                    iIndex = i;
                                    break;
                                }
                                else
                                {
                                    iIndex = i + 1;
                                }
                            }
                            else
                            {
                                iIndex = i;
                                break;
                            }
                        }
                        nodeFactory.Nodes.Insert(iIndex, nodeLayout);
                        clsDesignListTag nodeTag = new clsDesignListTag();
                        nodeTag.SetTagData(sLayout, modGlobalConstant.FMB_CATEGORY_LAYOUT, sFactory, sLayout, false);
                        nodeLayout.Tag = nodeTag;
                        nodeLayout.ImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_AREA);
                        nodeLayout.SelectedImageIndex = Convert.ToInt32(SMALLICON_INDEX.IDX_AREA);
                    }
                    break;
                }
                
                return true;
            
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.trvDesignList_Click()" + "\r\n" + ex.Message);
                return false;
            }
            
        }


        private void SetToolBar()
        {
            ToolStripMenuItem m_find_menu;

            m_find_menu = null;
            foreach (ToolStripMenuItem menu in mnuMain.Items)
            {
               
                m_find_menu = null;

                //format menu
                if (menu.Text =="Format")
                {
                    m_find_menu = menu;
                }
                if (m_find_menu != null)
                    break;
            }
            if (m_find_menu != null)
            {

                tolMain.Items[0].Click += new EventHandler(tsmLefts_Click);
                tolMain.Items[1].Click += new EventHandler(tsmCenters_Click);
                tolMain.Items[2].Click += new EventHandler(tsmRights_Click);
                tolMain.Items[3].Click += new EventHandler(tsmTops_Click);
                tolMain.Items[4].Click += new EventHandler(tsmMiddles_Click);
                tolMain.Items[5].Click += new EventHandler(tsmBottoms_Click);
                tolMain.Items[6].Click += new EventHandler(tsmWidth_Click);
                tolMain.Items[7].Click += new EventHandler(tsmHeight_Click);
                tolMain.Items[8].Click += new EventHandler(tsmBoth_Click);
                tolMain.Items[9].Click += new EventHandler(tsmHMakeEqual_Click);
                tolMain.Items[10].Click += new EventHandler(tsmHIncrease_Click);
                tolMain.Items[11].Click += new EventHandler(tsmHDecrease_Click);
                tolMain.Items[12].Click += new EventHandler(tsmHRemove_Click);
                tolMain.Items[13].Click += new EventHandler(tsmVMakeEqual_Click);
                tolMain.Items[14].Click += new EventHandler(tsmVIncrease_Click);
                tolMain.Items[15].Click += new EventHandler(tsmVDecrease_Click);
                tolMain.Items[16].Click += new EventHandler(tsmVRemove_Click);
                tolMain.Items[17].Click += new EventHandler(tsmBring_Click);
                tolMain.Items[18].Click += new EventHandler(tsmSend_Click);
            }
            else
            {
                for (int i = 0; i <= 18; i++)
                {
                    tolMain.Items[i].Enabled = false;
                }
            }

            m_find_menu = null;
            foreach (ToolStripMenuItem menu in mnuMain.Items)
            {

                m_find_menu = null;

                //Design menu
                if (menu.Text == "Design")
                {
                    m_find_menu = menu;
                }
                if (m_find_menu != null)
                    break;
            }
            if (m_find_menu != null)
            {
                tolMain.Items[20].Click += new EventHandler(tsmDesignMode_Click);
                tolMain.Items[21].Click += new EventHandler(tsmSaveDesign_Click);
            }
            else
            {
                for (int i = 20; i <= 21; i++)
                {
                    tolMain.Items[i].Enabled = false;
                }
            }

            if (MPGV.gTitleColor.IsEmpty == false)
                tolMain.BackColor = MPGV.gTitleColor;
        }

        public ImageList GetSmallIconList()
        {
            ImageList imlTemp;

            imlTemp = new ImageList();
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
            for (int i = 0; i < imlToolBar.Images.Count; i++)
            {
                imlTemp.Images.Add(imlToolBar.Images[i]);
            }
            return imlTemp;
        }

        public ToolStrip GetToolBar()
        {
            return tolMain;
        }

        private void tsmLogout_Click(object sender, EventArgs e)
        {
            MPGV.gbLogoutFlag = true;
            if (MPCF.ShowMsgBox(MPCF.GetMessage(35), "", MessageBoxButtons.YesNo, 2) == DialogResult.No)
            {
                MPGV.gbLogoutFlag = false;
                return;
            }
            this.Close();
            Application.Exit();
            Process.Start(Application.ExecutablePath);
            MPGV.gbLogoutFlag = false;

        }

        private bool SetEventColorList()
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_DATA_LIST_IN");
                TRSNode out_node = new TRSNode("VIEW_DATA_LIST_OUT");

                int i;


                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = MPGV.gsFactory;
                in_node.Passport = MPGV.gsPassport;
                in_node.Language = MPGV.gcLanguage;
                in_node.UserID = MPGV.gsUserID;
                in_node.Password = MPGV.gsPassword;
                in_node.AddString("TABLE_NAME", "EVENT_COLOR");


                if (MPCR.CallService("BAS", "BAS_View_Data_List", in_node, ref out_node) == false)
                {
                    return false;
                }


                for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                {
                    modGlobalVariable.gArrayEventColors[i].sResourceType = out_node.GetList(0)[i].GetString("KEY_1");
                    modGlobalVariable.gArrayEventColors[i].sEventMode = out_node.GetList(0)[i].GetString("KEY_2");
                    modGlobalVariable.gArrayEventColors[i].sEventStatus = out_node.GetList(0)[i].GetString("KEY_3");
                    if (out_node.GetList(0)[i].GetString("DATA_1") == "")
                    {
                        modGlobalVariable.gArrayEventColors[i].sColor = "White";
                    }
                    else
                    {
                        modGlobalVariable.gArrayEventColors[i].sColor = out_node.GetList(0)[i].GetString("DATA_1");
                    }
                    if (string.IsNullOrEmpty(out_node.GetList(0)[i].GetString("DATA_1"))
                        && string.IsNullOrEmpty(out_node.GetList(0)[i].GetString("KEY_1")) &&
                        string.IsNullOrEmpty(out_node.GetList(0)[i].GetString("KEY_2")) &&
                        string.IsNullOrEmpty(out_node.GetList(0)[i].GetString("KEY_3")))
                        continue;


                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBEventColor.SetEventColorList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }




        private bool ChangeEventColorList(string sResourceType, string sEventMode, string sEventStatus,string sColor)
        {

            try
            {
                int i;

                for (i = 0; i <= modGlobalVariable.gArrayEventColors.Length - 1; i++)
                {
                    if(String.Compare(modGlobalVariable.gArrayEventColors[i].sResourceType , sResourceType) ==0 && String.Compare(modGlobalVariable.gArrayEventColors[i].sEventMode , sEventMode)==0 && String.Compare(modGlobalVariable.gArrayEventColors[i].sEventStatus , sEventStatus)==0)
                    {
                        modGlobalVariable.gArrayEventColors[i].sColor = sColor;
                    }
                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBEventColor.ViewEventList()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }

        private void tsmSaveConfig_Click(object sender, EventArgs e)
        {
            Form form;
            form = new frmFMBSaveLayout(this);
            form.ShowDialog(this);
            
        }

        private void tsmClientUpgrade_Click(object sender, EventArgs e)
        {
            if (MPCF.ShowMsgBox(MPCF.GetMessage(25), "", MessageBoxButtons.YesNo, 2) == DialogResult.No)
            {
                return;
            }
            int ret;
            ret = MPCR.Client_Upgrade(2);
            if (ret == 1)
            {
                MPGV.gbLogoutFlag = true;
                this.Close();
            }
        }

        private void tsmOption_Click(object sender, EventArgs e)
        {
            Form form;
            form = new frmFMBOptionCore(true);
            form.ShowDialog(this);
        }

        private void tsmExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

  
        private void tsmDesignList_Click(object sender, EventArgs e)
        {
            this.udmMDIMain.ControlPanes["DESIGN_LIST"].Closed = false;
            this.udmMDIMain.ControlPanes["DESIGN_LIST"].Activate();
        }

        private void tsmToolsList_Click(object sender, EventArgs e)
        {
            this.udmMDIMain.ControlPanes["TOOLS_LIST"].Closed = false;
            this.udmMDIMain.ControlPanes["TOOLS_LIST"].Activate();
        }

        private void tsmDesignMode_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmDesignMode_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.frmMDIMain_FormClosing()" + "\r\n" + ex.Message);
            }
        }

        private void tsmSaveDesign_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild is frmFMBDesign)
            {
                ((frmFMBDesign)ActiveMdiChild).tsmSaveDesign_Click(sender, e);
            }
        }

        private void tsmUpdateRes_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild is frmFMBDesign)
            {
                ((frmFMBDesign)ActiveMdiChild).tsmUpdateRes_Click(sender, e);
            }
        }

        private void tsmDeleteRes_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild is frmFMBDesign)
            {
                ((frmFMBDesign)ActiveMdiChild).tsmDeleteRes_Click(sender, e);
            }
        }

        private void tsmProperties_Click(object sender, EventArgs e)
        {
            if (ActiveMdiChild is frmFMBDesign)
            {
                ((frmFMBDesign)ActiveMdiChild).tsmProperties_Click(sender, e);
            }
        }

        private void tsmTopDesign_DropDownOpening(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild == null)
                {
                    return;
                }

                if (ActiveMdiChild is frmFMBDesign)
                {

                    if (((frmFMBDesign)ActiveMdiChild).IsDesignMode == true)
                    {
                        tsmDesignMode.Checked = true;
                    }
                    else
                    {
                        tsmDesignMode.Checked = false;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmMDIMain.frmMDIMain_FormClosing()" + "\r\n" + ex.Message);
            }
        }

        public void tsmLefts_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmLefts_Click(sender, e);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmLefts_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmCenters_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmCenters_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmCenters_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmRights_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmRights_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmRights_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmTops_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmTops_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmTops_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmMiddles_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmMiddles_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmMiddles_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmBottoms_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmBottoms_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmBottoms_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }


        public void tsmWidth_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmWidth_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmWidth_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmHeight_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmHeight_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmHeight_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmBoth_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmBoth_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmBoth_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }


        public void tsmHMakeEqual_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmHMakeEqual_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmHMakeEqual_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmHIncrease_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmHIncrease_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmHIncrease_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmHDecrease_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmHDecrease_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmHDecrease_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmHRemove_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmHRemove_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmHRemove_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }
        public void tsmVMakeEqual_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmVMakeEqual_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmVMakeEqual_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmVIncrease_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmVIncrease_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmVIncrease_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmVDecrease_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmVDecrease_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmVDecrease_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmVRemove_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmVRemove_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmVRemove_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmBring_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmBring_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmBring_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmSend_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmSend_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmSend_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmReload_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmReload_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmReload_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmZoomIn_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmZoomIn_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmZoomIn_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmZoomOut_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmZoomOut_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmZoomOut_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        private void tsmTabbedMdi_Click(object sender, EventArgs e)
        {
            bool bEnabled;
            bEnabled = tsmTabbedMdi.Checked;
            this.utmmMDIMain.Enabled = bEnabled;
        }

        private void tsmCloseAll_Click(object sender, EventArgs e)
        {
            foreach (Form f in this.MdiChildren)
            {
                f.Close();
             
            }
        }

        private void tsmAddRes_Click(object sender, EventArgs e)
        {
            try
            {
                if (ActiveMdiChild is frmFMBDesign)
                {
                    ((frmFMBDesign)ActiveMdiChild).tsmAddRes_Click(sender, e);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmAddRes_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        private void tsmAbout_Click(object sender, EventArgs e)
        {
            frmFMBAbout f = new frmFMBAbout();
            f.ShowDialog();
            f.Dispose();
        }

        private void mnuDeleteFile_Click(object sender, EventArgs e)
        {
            if (trvDesignList.SelectedNode == null)
            {
                return;
            }
            if (MPCF.ShowMsgBox(MPCF.GetMessage(5), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.No)
            {
                return;
            }
            if (File.Exists(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout + ".fmb") == true)
            {
                File.Delete(((clsDesignListTag)trvDesignList.SelectedNode.Tag).Layout + ".fmb");
            }
            
            RefreshFileList();
        }

      
    }
}
