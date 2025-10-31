
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Miracom.FMBUI;
using Miracom.FMBUI.Controls;
using System.ComponentModel;
using Infragistics.Win.UltraWinToolbars;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.RASCore;
using Miracom.TRSCore;
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
//       - ViewLayout() : View Layout
//       - ViewResourceListDetail() : View Resource/Tag List Detail
//       - RefreshResourceListDetail() : Refresh Resource/Tag List Detail
//       - UpdateResourceListDetail() : Update Resource/Tag List Detail
//       - GetControl() : Get Control from the panel
//       - RefreshControl() : Refresh Control Status
//       - AddControl() : Add Control to panel
//       - RedrawControls() : Redraw Controls
//       - AddSelectedControls() : Add control to pnlFMBDesign.SelectedControls
//       - RemoveSelectedControls() : Remove control from pnlFMBDesign.SelectedControls
//       - InitControls() : Initialize Controls
//       - IsContains() : Check control is contained within pnlFMBDesign.SelectedControls
//       - IsModifiedControl() :  Check control is modified
//       - SetModifiedControl() :  Set control is modified
//       - UpdateResTag() :  Update Resource / Tag
//       - DeleteResTag() :  Delete Resource / Tag
//       - PropertiesResTag() :  Property Resource / Tag
//       - InitMainMenu() :Initialize Main Menu
//       - EnableMainMenu() :  Enable available menu
//
//   Detail Description
//       -
//
//   History
//       - 2005-01-21 : Created by Laverwon
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public class frmFMBDesign : System.Windows.Forms.Form
    {

        #region " Windows Form 디자이너에서 생성한 코드 "

        delegate bool RefreshControlDelegate(Control.ControlCollection CtrlCollection, ref FMBUI.clsCtrlStatus ResourceStatus, int iStep);

        private RefreshControlDelegate _RefreshControlDelegate;
        public frmFMBDesign(string sFormName, string sTag)
        {

            this.Name = sFormName;
            this.Tag = sTag;
            this.pnlFMBDesign = new udcFMBDesign(this);

            //이 호출은 Windows Form 디자이너에 필요합니다.
            InitializeComponent();

            _RefreshControlDelegate = new RefreshControlDelegate(RefreshControl);
            //InitializeComponent()를 호출한 다음에 초기화 작업을 추가하십시오.

            this.pnlFMBDesign.SuspendLayout();
            this.SuspendLayout();

            SetStyle(ControlStyles.ResizeRedraw, true);
            SetStyle(ControlStyles.DoubleBuffer | ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint, true);

            this.pnlBackGround.Controls.Add(this.pnlFMBDesign);
            this.pnlBackGround.Controls.Add(this.pnlBottom);
            this.pnlBackGround.Controls.Add(this.pnlRight);
            //
            //pnlFMBDesign
            //
            this.pnlFMBDesign.AllowDrop = true;
            this.pnlFMBDesign.BackColor = System.Drawing.Color.White;
            this.pnlFMBDesign.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlFMBDesign.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pnlFMBDesign.Location = new System.Drawing.Point(10, 10);
            this.pnlFMBDesign.Name = "pnlFMBDesign";
            this.pnlFMBDesign.Size = new System.Drawing.Size(780, 580);
            this.pnlFMBDesign.TabIndex = 4;

            this.pnlFMBDesign.ResumeLayout();
            this.ResumeLayout();

        }

        //Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
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

        private IContainer components;

        //Windows Form 디자이너에 필요합니다.

        //'참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
        //'Windows Form 디자이너를 사용하여 수정할 수 있습니다.  
        //'코드 편집기를 사용하여 수정하지 마십시오.
        internal System.Windows.Forms.Panel pnlBackGround;
        public udcFMBDesign pnlFMBDesign;
        internal System.Windows.Forms.Panel pnlBottom;
        internal System.Windows.Forms.Panel pnlBottomTop;
        internal System.Windows.Forms.Panel pnlBottomLeft;
        internal System.Windows.Forms.Panel pnlRight;
        internal System.Windows.Forms.Panel pnlRightFill;
        internal System.Windows.Forms.Panel pnlRightLeft;
        internal System.Windows.Forms.Panel pnlRightBottom;
        internal System.Windows.Forms.Panel pnlRightTop;
        internal System.Windows.Forms.Panel pnlBottomFill;
        internal System.Windows.Forms.ImageList imlDesignToolbars;
        internal System.Windows.Forms.Timer tmrRefresh;
        [System.Diagnostics.DebuggerStepThrough()]
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmFMBDesign));
            this.imlDesignToolbars = new System.Windows.Forms.ImageList(this.components);
            this.pnlBackGround = new System.Windows.Forms.Panel();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.pnlBottomFill = new System.Windows.Forms.Panel();
            this.pnlBottomTop = new System.Windows.Forms.Panel();
            this.pnlBottomLeft = new System.Windows.Forms.Panel();
            this.pnlRight = new System.Windows.Forms.Panel();
            this.pnlRightFill = new System.Windows.Forms.Panel();
            this.pnlRightLeft = new System.Windows.Forms.Panel();
            this.pnlRightBottom = new System.Windows.Forms.Panel();
            this.pnlRightTop = new System.Windows.Forms.Panel();
            this.tmrRefresh = new System.Windows.Forms.Timer(this.components);
            this.pnlBottom.SuspendLayout();
            this.pnlRight.SuspendLayout();
            this.SuspendLayout();
            // 
            // imlDesignToolbars
            // 
            this.imlDesignToolbars.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imlDesignToolbars.ImageStream")));
            this.imlDesignToolbars.TransparentColor = System.Drawing.Color.Transparent;
            this.imlDesignToolbars.Images.SetKeyName(0, "");
            this.imlDesignToolbars.Images.SetKeyName(1, "");
            this.imlDesignToolbars.Images.SetKeyName(2, "");
            this.imlDesignToolbars.Images.SetKeyName(3, "");
            this.imlDesignToolbars.Images.SetKeyName(4, "");
            this.imlDesignToolbars.Images.SetKeyName(5, "");
            this.imlDesignToolbars.Images.SetKeyName(6, "");
            this.imlDesignToolbars.Images.SetKeyName(7, "");
            this.imlDesignToolbars.Images.SetKeyName(8, "");
            this.imlDesignToolbars.Images.SetKeyName(9, "");
            this.imlDesignToolbars.Images.SetKeyName(10, "");
            this.imlDesignToolbars.Images.SetKeyName(11, "");
            this.imlDesignToolbars.Images.SetKeyName(12, "");
            this.imlDesignToolbars.Images.SetKeyName(13, "");
            this.imlDesignToolbars.Images.SetKeyName(14, "");
            this.imlDesignToolbars.Images.SetKeyName(15, "");
            this.imlDesignToolbars.Images.SetKeyName(16, "");
            this.imlDesignToolbars.Images.SetKeyName(17, "");
            this.imlDesignToolbars.Images.SetKeyName(18, "");
            this.imlDesignToolbars.Images.SetKeyName(19, "");
            this.imlDesignToolbars.Images.SetKeyName(20, "");
            this.imlDesignToolbars.Images.SetKeyName(21, "");
            this.imlDesignToolbars.Images.SetKeyName(22, "");
            this.imlDesignToolbars.Images.SetKeyName(23, "");
            this.imlDesignToolbars.Images.SetKeyName(24, "");
            this.imlDesignToolbars.Images.SetKeyName(25, "");
            this.imlDesignToolbars.Images.SetKeyName(26, "");
            this.imlDesignToolbars.Images.SetKeyName(27, "");
            this.imlDesignToolbars.Images.SetKeyName(28, "");
            // 
            // pnlBackGround
            // 
            this.pnlBackGround.Location = new System.Drawing.Point(0, 0);
            this.pnlBackGround.Name = "pnlBackGround";
            this.pnlBackGround.Padding = new System.Windows.Forms.Padding(10, 10, 0, 0);
            this.pnlBackGround.Size = new System.Drawing.Size(800, 600);
            this.pnlBackGround.TabIndex = 5;
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.pnlBottomFill);
            this.pnlBottom.Controls.Add(this.pnlBottomTop);
            this.pnlBottom.Controls.Add(this.pnlBottomLeft);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(10, 590);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(780, 10);
            this.pnlBottom.TabIndex = 3;
            // 
            // pnlBottomFill
            // 
            this.pnlBottomFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlBottomFill.Location = new System.Drawing.Point(5, 5);
            this.pnlBottomFill.Name = "pnlBottomFill";
            this.pnlBottomFill.Size = new System.Drawing.Size(775, 5);
            this.pnlBottomFill.TabIndex = 2;
            // 
            // pnlBottomTop
            // 
            this.pnlBottomTop.BackColor = System.Drawing.Color.DimGray;
            this.pnlBottomTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlBottomTop.Location = new System.Drawing.Point(5, 0);
            this.pnlBottomTop.Name = "pnlBottomTop";
            this.pnlBottomTop.Size = new System.Drawing.Size(775, 5);
            this.pnlBottomTop.TabIndex = 1;
            // 
            // pnlBottomLeft
            // 
            this.pnlBottomLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlBottomLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlBottomLeft.Name = "pnlBottomLeft";
            this.pnlBottomLeft.Size = new System.Drawing.Size(5, 10);
            this.pnlBottomLeft.TabIndex = 0;
            // 
            // pnlRight
            // 
            this.pnlRight.Controls.Add(this.pnlRightFill);
            this.pnlRight.Controls.Add(this.pnlRightLeft);
            this.pnlRight.Controls.Add(this.pnlRightBottom);
            this.pnlRight.Controls.Add(this.pnlRightTop);
            this.pnlRight.Dock = System.Windows.Forms.DockStyle.Right;
            this.pnlRight.Location = new System.Drawing.Point(790, 10);
            this.pnlRight.Name = "pnlRight";
            this.pnlRight.Size = new System.Drawing.Size(10, 590);
            this.pnlRight.TabIndex = 2;
            // 
            // pnlRightFill
            // 
            this.pnlRightFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlRightFill.Location = new System.Drawing.Point(5, 5);
            this.pnlRightFill.Name = "pnlRightFill";
            this.pnlRightFill.Size = new System.Drawing.Size(5, 580);
            this.pnlRightFill.TabIndex = 3;
            // 
            // pnlRightLeft
            // 
            this.pnlRightLeft.BackColor = System.Drawing.Color.DimGray;
            this.pnlRightLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlRightLeft.Location = new System.Drawing.Point(0, 5);
            this.pnlRightLeft.Name = "pnlRightLeft";
            this.pnlRightLeft.Size = new System.Drawing.Size(5, 580);
            this.pnlRightLeft.TabIndex = 2;
            // 
            // pnlRightBottom
            // 
            this.pnlRightBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlRightBottom.Location = new System.Drawing.Point(0, 585);
            this.pnlRightBottom.Name = "pnlRightBottom";
            this.pnlRightBottom.Size = new System.Drawing.Size(10, 5);
            this.pnlRightBottom.TabIndex = 1;
            // 
            // pnlRightTop
            // 
            this.pnlRightTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlRightTop.Location = new System.Drawing.Point(0, 0);
            this.pnlRightTop.Name = "pnlRightTop";
            this.pnlRightTop.Size = new System.Drawing.Size(10, 5);
            this.pnlRightTop.TabIndex = 0;
            // 
            // tmrRefresh
            // 
            this.tmrRefresh.Tick += new System.EventHandler(this.tmrRefresh_Tick);

            // 
            // frmFMBDesign
            // 
            this.AllowDrop = true;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.AutoScroll = true;
            this.BackColor = System.Drawing.Color.DarkGray;
            this.ClientSize = new System.Drawing.Size(1016, 734);
            this.Controls.Add(this.pnlBackGround);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "frmFMBDesign";
            this.Text = "frmFMBDesign";
            this.Load += new System.EventHandler(this.frmFMBDesign_Load);
            this.Activated += new System.EventHandler(this.frmFMBDesign_Activated);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmFMBDesign_FormClosed);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmFMBDesign_FormClosing);
            this.pnlBottom.ResumeLayout(false);
            this.pnlRight.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        #region " Property Implementations"

        private Point m_ptStartPos = new Point();

        private bool m_bLoading = true;
        private bool m_bDesignMode = false;
        private int m_iZoomScale = 0;
        private Size m_szOriginalDesignSize;

        private bool m_bDeleteFlag = false;
        private bool m_bSelectingCtrl = false;
        private bool m_bSelectedSelectingCtrl = false;
        private bool m_bGotFocus = false;
        ArrayList ctrlArray = new ArrayList();

        [Description("Gets or sets IsLoading"), DefaultValue(false), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool IsLoading
        {
            get
            {
                return m_bLoading;
            }
            set
            {

                if (m_bLoading.Equals(value) == false)
                {
                    m_bLoading = value;
                }
            }
        }

        [Description("Gets or sets IsDesignMode"), DefaultValue(false), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool IsDesignMode
        {
            get
            {
                return m_bDesignMode;
            }
            set
            {


                if (m_bDesignMode.Equals(value) == false)
                {
                    if (value == false)
                    {
                        if (IsModifiedControl() == true)
                        {
                            if ((DialogResult)MPCF.ShowMsgBox(this.Name + " - " + MPCF.GetMessage(12), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                if (UpdateResourceListDetail() == true)
                                {

                                }
                            }
                        }
                    }
                    m_bDesignMode = value;
                    InitControls(value);
                    pnlFMBDesign.Invalidate(true);
                    //tsmZoomIn.Enabled = !value;
                    //tsmZoomOut.Enabled = !value;
                    //tsmSaveDesign.Enabled = value;
                    //tsmAddRes.Enabled = value;

                    ZoomScale = 0;
                }
            }
        }

        [Description("Gets or sets DesignSize"), Browsable(true), DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
        public Size DesignSize
        {
            get
            {
                return pnlBackGround.Size;
            }
            set
            {


                if (pnlBackGround.Size.Equals(value) == false)
                {
                    pnlBackGround.Size = value;
                }
            }
        }

        [Description("Gets or sets ZoomScale"), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int ZoomScale
        {
            get
            {
                return m_iZoomScale;
            }
            set
            {
                if (m_iZoomScale.Equals(value) == false)
                {
                    m_iZoomScale = value;
                    //if (value >= 5)
                    //{
                    //    tsmZoomIn.Enabled = false;
                    //}
                    //else
                    //{
                    //    if (IsDesignMode == true)
                    //    {
                    //        tsmZoomIn.Enabled = false;
                    //    }
                    //    else
                    //    {
                    //        tsmZoomIn.Enabled = true;
                    //    }
                    //}
                    //if (value <= -5)
                    //{
                    //    tsmZoomOut.Enabled = false;
                    //}
                    //else
                    //{
                    //    if (IsDesignMode == true)
                    //    {
                    //        tsmZoomOut.Enabled = false;
                    //    }
                    //    else
                    //    {
                    //        tsmZoomOut.Enabled = true;
                    //    }
                    //}
                }
            }
        }

        [Description("Gets or sets OriginalDesignSize"), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public Size OriginalDesignSize
        {
            get
            {
                return m_szOriginalDesignSize;
            }
            set
            {

                if (m_szOriginalDesignSize.Equals(value) == false)
                {
                    m_szOriginalDesignSize = value;
                }
            }
        }

        [Description("Gets or sets DeleteFlag"), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool DeleteFlag
        {
            get
            {
                return m_bDeleteFlag;
            }
            set
            {

                if (m_bDeleteFlag.Equals(value) == false)
                {
                    m_bDeleteFlag = value;
                }
            }
        }

        [Description("Gets or sets IsSelectingCtrl"), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        private bool IsSelectingCtrl
        {
            get
            {
                return m_bSelectingCtrl;
            }
            set
            {

                if (m_bSelectingCtrl.Equals(value) == false)
                {
                    m_bSelectingCtrl = value;
                }
            }
        }

        [Description("Gets or sets IsSelectedSelectingCtrl"), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        private bool IsSelectedSelectingCtrl
        {
            get
            {
                return m_bSelectedSelectingCtrl;
            }
            set
            {

                if (m_bSelectedSelectingCtrl.Equals(value) == false)
                {
                    m_bSelectedSelectingCtrl = value;
                }
            }
        }

        [Description("Gets or sets IsGotFocus"), Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        private bool IsGotFocus
        {
            get
            {
                return m_bGotFocus;
            }
            set
            {

                if (m_bGotFocus.Equals(value) == false)
                {
                    m_bGotFocus = value;
                }
            }
        }

        #endregion

        #region " Event Implementations"

        private void frmFMBDesign_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                if (DeleteFlag == true)
                {
                }
                else
                {
                    if (IsDesignMode == true)
                    {
                        if (IsModifiedControl() == true)
                        {
                            if ((DialogResult)MPCF.ShowMsgBox(this.Name + " - " + MPCF.GetMessage(12), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                if (UpdateResourceListDetail() == true)
                                {

                                }
                                else
                                {
                                    e.Cancel = true;
                                    return;
                                }
                            }
                        }
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.frmFMBDesign_Closing()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        private void frmFMBDesign_FormClosed(object sender, FormClosedEventArgs e)
        {
            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in this.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (!(ctrl == null))
                    {
                        ctrl.Dispose();
                        ctrl = null;
                    }
                }

                this.Dispose();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.frmFMBDesign_Closed()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void CtrlBase_CtrlMouseEnter(System.Object sender, System.EventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }

                //IsSelectingCtrl = true;
                IsSelectedSelectingCtrl = ctrl.IsSelected;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlMouseEnter()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlMouseLeave(System.Object sender, System.EventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }

                //IsSelectingCtrl = false;
                IsSelectedSelectingCtrl = false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlMouseLeave()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlLostFocus(System.Object sender, System.EventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }

                if (Control.ModifierKeys == Keys.Control)
                {
                    //' 1) Control Key를 누른 상태에서 이미 선택되어진 Control를 선택한 경우 -> 선택 유지
                    //' 2) Control Key를 누른 상태에서 선택되지 않은 Control를 선택한 경우 -> 선택 유지
                    //' 3) Control Key를 누른 상태에서 아무 곳이나 클릭한 경우 -> 선택 유지
                    if (IsSelectingCtrl == true)
                    {
                        // 1) Control를 선택한 경우
                        if (IsSelectedSelectingCtrl == true)
                        {
                            // 1) Control Key를 누른 상태에서 이미 선택되어진 Control를 선택한 경우 -> 선택 유지
                            ctrl.CanLostFocus = false;
                            //Debug.WriteLine("1-1")
                            //DebugWrite(ctrl)
                        }
                        else
                        {
                            // 2) Control Key를 누른 상태에서 선택되지 않은 Control를 선택한 경우 -> 선택 유지, 비활성
                            ctrl.CanLostFocus = false;
                            ctrl.IsFocused = false;
                            ctrl.RedrawCtrl();
                            //Debug.WriteLine("1-2")
                            //DebugWrite(ctrl)
                        }
                    }
                    else
                    {
                        // 3) Control Key를 누른 상태에서 아무 곳이나 클릭한 경우 -> 선택 유지
                        ctrl.CanLostFocus = false;
                        //DebugWrite(ctrl)
                        //Debug.WriteLine("1-3")
                    }
                }
                else
                {
                    //' 1) 이미 선택되어진 Control를 선택한 경우 - 선택 유지
                    //' 2) 일반적으로 다른 Control를 선택한 경우 - 선택 해제
                    //' 3) Control이 아닌 다른 곳을 선택한 경우 - 선택 유지
                    if (IsSelectingCtrl == true)
                    {
                        // 1) Control를 선택한 경우
                        if (IsSelectedSelectingCtrl == true)
                        {
                            // 1) 이미 선택되어진 Control를 선택하려는 경우 - 선택 유지
                            ctrl.CanLostFocus = false;
                            ctrl.IsFocused = false;
                            ctrl.RedrawCtrl();
                            //Debug.WriteLine("2-1")
                            //DebugWrite(ctrl)
                        }
                        else
                        {
                            // 2) 선택되지 않은 Control를 선택하려는 경우 - 선택 해제
                            RemoveSelectedControls(ctrl);
                            //Debug.WriteLine("2-2")
                            //DebugWrite(ctrl)
                        }
                    }
                    else
                    {
                        // 3) Control이 아닌 다른 곳을 선택한 경우 - 선택 유지
                        ctrl.CanLostFocus = false;
                        //Debug.WriteLine("2-3")
                        //DebugWrite(ctrl)
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlLostFocus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlGotFocus(System.Object sender, System.EventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }

                IsGotFocus = true;

                if (Control.ModifierKeys == Keys.Control)
                {
                    //' 1) 이미 선택되어진 Control를 선택 해제 시 -> 비선택
                    //' 2) Control Key와 함께 선택 시 -> 선택
                    if (ctrl.IsSelected == true)
                    {
                        // 1) 이미 선택되어진 Control일 경우 -> 비선택
                        ctrl.CanGotFocus = false;
                        RemoveSelectedControls(ctrl);
                        //Debug.WriteLine("1-1")
                        //DebugWrite(ctrl)
                        return;
                    }
                    else
                    {
                        // 2) 선택되어진 Control이 아닐 경우 -> 선택
                        if (pnlFMBDesign.SelectedControlsCount() > 0)
                        {
                            //' 1) 다른 선택되어진 Control이 있을 경우
                            //' 2) 다른 선택되어진 Control에서 먼저 LostFocus Event가 발생하므로 LostFocus Event 처리 필요
                            AddSelectedControls(ctrl);
                            //Debug.WriteLine("1-2-1")
                            //DebugWrite(ctrl)
                            return;
                        }
                        else
                        {
                            // 2) 다른 선택되어진 Control이 없을 경우 - OK
                            AddSelectedControls(ctrl);
                            //Debug.WriteLine("1-2-2")
                            //DebugWrite(ctrl)
                            return;
                        }
                    }
                }
                else
                {
                    //' 1) 이미 선택되어진 Control들 중에 Focus를 활성 시킴
                    //' 2) 일반적인 선택 시
                    if (ctrl.IsSelected == true && IsSelectedContains(ctrl) == true)
                    {
                        if (ctrl.IsFocused == true)
                        {
                            return;
                        }
                        else
                        {
                            // 1) 이미 선택되어진 Control을 재선택한 경우 -> Focus 활성화, 나머지는 Focus 비활성화
                            int i;
                            for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                            {
                                if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == true)
                                {
                                    ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused = false;
                                    ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).RedrawCtrl();
                                }
                            }
                            RemoveSelectedControls(ctrl);
                            AddSelectedControls(ctrl);
                            //Debug.WriteLine("2-1")
                            //DebugWrite(ctrl)
                            return;
                        }
                    }
                    else
                    {
                        // 2) 일반적인 선택인 경우
                        int i;
                        for (i = pnlFMBDesign.SelectedControlsCount(); i > 0; i--)
                        {
                            ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsHot = false;
                            ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsFocused = false;
                            ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsSelected = false;
                            ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsPressed = false;
                            ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).RedrawCtrl();
                            pnlFMBDesign.SelectedControls.Remove((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]);
                        }
                        AddSelectedControls(ctrl);
                        //Debug.WriteLine("2-2")
                        //DebugWrite(ctrl)
                        return;

                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlGotFocus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlMouseDown(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }
                //' 1) GotFocus가 아닌 상태에서 MouseDown시 처리
                //' 2) MouseDown 상태에서 Control 이동 및 크기 변경 처리
                if (IsGotFocus == true)
                {
                    IsGotFocus = false;
                    //Debug.WriteLine("1-1")
                    //DebugWrite(ctrl)
                }
                else
                {
                    //' 1) Control Key를 누른 상태에서 이미 선택되어지고 활성상태인 경우 -> 비선택/비활성
                    //' 2) Control Key를 누른 상태에서 선택되지 않은 경우 -> 선택/활성, 나머지는 유지
                    //' 3) Control Key를 누르지 않은 상태에서 선택되지 않은 경우 -> 선택/활성, 나머지는 비선택/비활성
                    if (ctrl.IsSelected == true)
                    {
                        // 1) Control Key를 누른 상태에서 이미 선택되어지고 활성상태인 경우 -> 비선택/비활성
                        if (Control.ModifierKeys == Keys.Control)
                        {
                            RemoveSelectedControls(ctrl);
                        }
                        IsGotFocus = false;
                        //Debug.WriteLine("2-1")
                        //DebugWrite(ctrl)
                    }
                    else
                    {
                        if (Control.ModifierKeys == Keys.Control)
                        {
                            // 2) Control Key를 누른 상태에서 선택되지 않은 경우 -> 선택/활성, 나머지는 유지
                        }
                        else
                        {
                            // 3) Control Key를 누르지 않은 상태에서 선택되지 않은 경우 -> 선택/활성, 나머지는 비선택/비활성
                            int i;
                            for (i = pnlFMBDesign.SelectedControlsCount(); i > 0; i--)
                            {
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsHot = false;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsFocused = false;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsSelected = false;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).IsPressed = false;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]).RedrawCtrl();
                                pnlFMBDesign.SelectedControls.Remove((udcCtrlBase)pnlFMBDesign.SelectedControls[i - 1]);
                            }
                        }
                        AddSelectedControls(ctrl);
                        IsGotFocus = false;
                        //Debug.WriteLine("2-2")
                        //DebugWrite(ctrl)
                    }
                }

                if (pnlFMBDesign.SelectedControlsCount() > 1)
                {
                    m_ptStartPos = ctrl.PointToScreen(new Point(e.X, e.Y));
                    ctrl.Cursor = Cursors.SizeAll;
                    ctrl.IsPressed = true;
                    ctrl.CanMouseDown = false;
                    ctrl.RedrawCtrl();
                    //Debug.WriteLine("3-1")
                    //DebugWrite(ctrl)
                }
                else
                {
                    m_ptStartPos = new Point();
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlMouseDown()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlMouseMove(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }

                if (pnlFMBDesign.SelectedControlsCount() > 1)
                {
                    ctrl.CanMouseMove = false;
                }

                if (ctrl.IsPressed == true && !(m_ptStartPos.IsEmpty))
                {
                    Point ptScreen = ctrl.PointToScreen(new Point(e.X, e.Y));
                    Size szDelta = new Size(ptScreen.X - m_ptStartPos.X, ptScreen.Y - m_ptStartPos.Y);

                    if (Math.Abs(szDelta.Width) < SystemInformation.DragSize.Width && Math.Abs(szDelta.Height) < SystemInformation.DragSize.Height)
                    {
                        return;
                    }

                    int i;
                    for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                    {
                        if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetMoveToSize(Miracom.FMBUI.Controls.modDefines.CTRL_HITTEST_TRACKER_ALL, szDelta) == true)
                        {
                            m_ptStartPos = ptScreen;
                        }
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlMouseMove()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlMouseUp(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }

                m_ptStartPos = new Point();

                if (pnlFMBDesign.SelectedControlsCount() > 1)
                {
                    ctrl.IsPressed = false;
                    ctrl.CanMouseUp = false;
                    ctrl.Cursor = Cursors.Default;
                    ctrl.RedrawCtrl();
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlMouseUp()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlKeyDown(System.Object sender, System.Windows.Forms.KeyEventArgs e)
        {

            try
            {
                if (sender == null)
                {
                    return;
                }
                if (!(sender is udcCtrlBase))
                {
                    return;
                }
                udcCtrlBase ctrl = (udcCtrlBase)sender;
                ctrl.IsDesignMode = IsDesignMode;
                if (IsDesignMode == false)
                {
                    return;
                }

                if (pnlFMBDesign.SelectedControlsCount() > 0)
                {
                    ctrl.CanKeyDown = false;
                }

                int i;
                if (e.Control == true && e.Shift == false)
                {
                    if (this.Enabled == true)
                    {
                        Point ptLocation = new Point();
                        for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                        {
                            switch (e.KeyCode)
                            {
                                case Keys.Up:

                                    ptLocation = new Point(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().X, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().Y - 1);
                                    break;
                                case Keys.Right:

                                    ptLocation = new Point(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().X + 1, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().Y);
                                    break;
                                case Keys.Down:

                                    ptLocation = new Point(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().X, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().Y + 1);
                                    break;
                                case Keys.Left:

                                    ptLocation = new Point(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().X - 1, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().Y);
                                    break;
                            }
                            if (e.KeyCode == Keys.Up || e.KeyCode == Keys.Right || e.KeyCode == Keys.Down || e.KeyCode == Keys.Left)
                            {
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetLocation(ptLocation, true);
                            }
                        }
                    }
                }
                else if (e.Control == true && e.Shift == true)
                {
                    if (this.Enabled == true)
                    {
                        Size szSize = new Size();
                        for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                        {
                            switch (e.KeyCode)
                            {
                                case Keys.Up:

                                    szSize = new Size(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Width, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Height - 1);
                                    break;
                                case Keys.Right:

                                    szSize = new Size(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Width + 1, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Height);
                                    break;
                                case Keys.Down:

                                    szSize = new Size(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Width, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Height + 1);
                                    break;
                                case Keys.Left:

                                    szSize = new Size(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Width - 1, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Height);
                                    break;
                            }
                            if (e.KeyCode == Keys.Up || e.KeyCode == Keys.Right || e.KeyCode == Keys.Down || e.KeyCode == Keys.Left)
                            {
                                if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.HorizontalLine)
                                {
                                    if (szSize.Width < modGlobalConstant.CTRL_MININUM_SIZE || szSize.Height < modGlobalConstant.LINE_MININUM_SIZE)
                                    {
                                        return;
                                    }
                                    if (szSize.Height > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                                    {
                                        return;
                                    }
                                }
                                else if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.VerticalLine)
                                {
                                    if (szSize.Width < modGlobalConstant.LINE_MININUM_SIZE || szSize.Height < modGlobalConstant.CTRL_MININUM_SIZE)
                                    {
                                        return;
                                    }
                                    if (szSize.Width > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                                    {
                                        return;
                                    }
                                }
                                else
                                {
                                    if (szSize.Width < modGlobalConstant.CTRL_MININUM_SIZE || szSize.Height < modGlobalConstant.CTRL_MININUM_SIZE)
                                    {
                                        return;
                                    }
                                    if (szSize.Width > modGlobalConstant.CTRL_MAXIMUM_SIZE || szSize.Height > modGlobalConstant.CTRL_MAXIMUM_SIZE)
                                    {
                                        return;
                                    }
                                }
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetSize(szSize, true);
                            }
                        }
                    }
                }
                else
                {
                    if (this.Enabled == true)
                    {
                        if (e.KeyCode == Keys.Delete)
                        {
                            string sFactory = "";
                            string sLayout = "";
                            bool IsRefresh = false;
                            if (pnlFMBDesign.SelectedControlsCount() < 1)
                            {
                                return;
                            }
                            if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                            {
                                sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                                sLayout = FMBCF.GetStringBySeperator(Name, ":", 2);
                            }
                            else if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                            {
                                sFactory = MPGV.gsFactory;
                                sLayout = Name;
                            }

                            ArrayList copySelectedControls = new ArrayList();
                            //ControlCollection copySelectedControls = null;
                            char cResourceType;
                            for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                            {
                                copySelectedControls.Add(pnlFMBDesign.SelectedControls[i]);
                            }
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(5), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                for (i = copySelectedControls.Count - 1; i >= 0; i--)
                                {
                                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                                    {
                                        cResourceType = modGlobalConstant.FMB_RESOURCE_TYPE;
                                    }
                                    else if (Miracom.FMBUI.Enums.eToolType.SubResource == ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType)
                                    {
                                        cResourceType = modGlobalConstant.FMB_SUB_RESOURCE_TYPE;
                                    }
                                    else if (Miracom.FMBUI.Enums.eToolType.Tool == ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType)
                                    {
                                        cResourceType = modGlobalConstant.FMB_TOOL_TYPE;
                                    }
                                    else if (Miracom.FMBUI.Enums.eToolType.Port == ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType)
                                    {
                                        cResourceType = modGlobalConstant.FMB_PORT_TYPE;
                                    }
                                    else
                                    {
                                        cResourceType = modGlobalConstant.FMB_TAG_TYPE;
                                    }

                                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port || ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                    {
                                        if (FMBCF.DeleteSubResource(this.Tag.ToString(), sFactory, sLayout, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.MotherResourceID, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name, cResourceType) == false)
                                        {
                                            return;
                                        }
                                    }
                                    else
                                    {
                                        if (FMBCF.DeleteResource(this.Tag.ToString(), sFactory, sLayout, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name, cResourceType) == false)
                                        {
                                            return;
                                        }
                                    }
                                    if (((udcCtrlBase)copySelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource && Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                                    {
                                        IsRefresh = true;
                                    }
                                    if (((udcCtrlBase)copySelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port && Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                                    {
                                        IsRefresh = true;
                                    }
                                    if (((udcCtrlBase)copySelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource && Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                                    {
                                        IsRefresh = true;
                                    }
                                    if (((udcCtrlBase)copySelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool && Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                                    {
                                        IsRefresh = true;
                                    }
                                }

                                if (IsRefresh == true)
                                {
                                    if (copySelectedControls.Count == 1)
                                    {
                                        if (((udcCtrlBase)copySelectedControls[0]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port ||
                                            ((udcCtrlBase)copySelectedControls[0]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                        {
                                            if (FMBFI.gIMdiForm.RefreshDesignList("2", sFactory, sLayout, ((udcCtrlBase)copySelectedControls[0]).Name,((udcCtrlBase)copySelectedControls[0]).CtrlStatus.MotherResourceID, "") == false)
                                            {
                                                return;
                                            }
                                        }
                                        else
                                        {
                                            if (FMBFI.gIMdiForm.RefreshDesignList("2", sFactory, sLayout, ((udcCtrlBase)copySelectedControls[0]).Name, "") == false)
                                            {
                                                return;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (FMBFI.gIMdiForm.RefreshDesignList("5", sFactory, sLayout, "", "") == false)
                                        {
                                            return;
                                        }
                                    }
                                }
                                for (i = copySelectedControls.Count - 1; i >= 0; i--)
                                {
                                    pnlFMBDesign.Controls.Remove((udcCtrlBase)copySelectedControls[i]);
                                }
                            }
                            else
                            {
                                ctrl.CanKeyDown = false;
                            }
                        }
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlKeyDown()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlContextMenu(System.Object sender, CtrlContextMenu_EventArgs e)
        {

            try
            {
                switch (((MenuItem)sender).MergeOrder)
                {
                    case 1:

                        CtrlBase_CtrlUpdate(sender, e);
                        break;
                    case 2:

                        CtrlBase_CtrlDelete(sender, e);
                        break;
                    case 3:

                        CtrlBase_CtrlProperties(sender, e);
                        break;
                    case 4:

                        CtrlBase_CtrlViewResourceStatus(sender, e);
                        break;
                    case 5:

                        CtrlBase_CtrlViewResourceHistory(sender, e);
                        break;
                    case 6:

                        CtrlBase_CtrlTranEvent(sender, e);
                        break;
                    case 7:

                        udcCtrlBase copyCtrl = (udcCtrlBase)e.CtrlSender;
                        pnlFMBDesign.ClipboardControl = copyCtrl;
                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlContextMenu()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlUpdate(System.Object sender, CtrlContextMenu_EventArgs e)
        {


            try
            {

                if (!(e.CtrlSender is udcCtrlBase))
                {
                    return;
                }

                udcCtrlBase ctrl = (udcCtrlBase)e.CtrlSender;
                string sFactory;


                switch (ctrl.CtrlStatus.ToolType)
                {
                    case Miracom.FMBUI.Enums.eToolType.Resource:

                        frmFMBCreateResource form = new frmFMBCreateResource(modGlobalConstant.MP_STEP_UPDATE);

                        form.Tag = Tag;
                        if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                            form.txtFactory.Text = sFactory;
                            form.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            sFactory = MPGV.gsFactory;
                            form.txtFactory.Text = sFactory;
                            form.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlUpdate() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                            return;
                        }
                        form.cdvResID.Text = ctrl.Name;
                        form.txtX.Text = ctrl.GetLocation().X.ToString();
                        form.txtY.Text = ctrl.GetLocation().Y.ToString();
                        form.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        form.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        if (form.ShowDialog(this) == DialogResult.OK)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = form.cdvResID.Text;
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(form.txtX.Text), MPCF.ToInt(form.txtY.Text)));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(form.txtWidth.Text), MPCF.ToInt(form.txtHeight.Text)));
                            ResourceStatus.Text = form.txtText.Text;
                            ResourceStatus.ResTagFlag = form.txtResTagFlag.Text;
                            ResourceStatus.PrimaryStatus = form.txtPriSts.Text;
                            ResourceStatus.UpDownFlag = form.txtUpDown.Text;
                            ResourceStatus.LastEvent = form.txtLastEvent.Text;
                            ResourceStatus.AreaID = form.txtArea.Text;
                            ResourceStatus.SubAreaID = form.txtSubArea.Text;
                            ResourceStatus.ResourceType = form.txtResourceType.Text;
                            if (MPCF.Trim(form.txtProcMode.Text) != "")
                            {
                                ResourceStatus.ProcMode = MPCF.Trim(form.txtProcMode.Text).Substring(0, 1);
                            }
                            if (form.txtCtrlMode.Text == "ON LINE")
                            {
                                ResourceStatus.CtrlMode = "OL";
                            }
                            else if (form.txtCtrlMode.Text == "ON LINE REAL")
                            {
                                ResourceStatus.CtrlMode = "OR";
                            }
                            else if (form.txtCtrlMode.Text == "OFF LINE")
                            {
                                ResourceStatus.CtrlMode = "OF";
                            }
                            ResourceStatus.WIPRate = MPCF.ToDbl(form.txtWIP.Text);
                            if (form.utcText.Color.IsSystemColor == true || form.utcText.Color.IsKnownColor == true)
                            {
                                ResourceStatus.TextColor = MPCF.ToInt(form.utcText.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.TextColor = form.utcText.Color.ToArgb();
                            }
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            if (form.cboSize.Text == "")
                            {
                                ResourceStatus.TextSize = 0;
                            }
                            else
                            {
                                ResourceStatus.TextSize = MPCF.ToInt(form.cboSize.Text);
                            }
                            ResourceStatus.TextStyle = form.cboTextStyle.SelectedIndex;
                            ResourceStatus.ToolType = ctrl.CtrlStatus.ToolType;
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                }
                                else
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                }
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            if (form.utcBack.Color.IsSystemColor == true || form.utcBack.Color.IsKnownColor == true)
                            {
                                ResourceStatus.BackColor = MPCF.ToInt(form.utcBack.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.BackColor = form.utcBack.Color.ToArgb();
                            }

                            ResourceStatus.ImageIndex = form.iImageIndex;
                            ResourceStatus.ResShape = MPCF.ToChar(form.cboShape.SelectedIndex);
                            if (form.cboSignalPos.SelectedIndex > 0)
                            {
                                ResourceStatus.IsViewSignal = true;
                                ResourceStatus.SignalPosition = MPCF.ToChar(form.cboSignalPos.SelectedIndex);
                            }

                            if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT && form.cdvLayOut.Text != FMBCF.GetStringBySeperator(Name, ":", 2))
                            {
                                string sMoveForm = sFactory + ":" + form.cdvLayOut.Text;
                                Form frmChild;
                                bool bFindFlag = false;
                                foreach (Form tempLoopVar_frmChild in this.MdiParent.MdiChildren)
                                {
                                    frmChild = tempLoopVar_frmChild;
                                    if (frmChild is frmFMBDesign)
                                    {
                                        if (frmChild.Name == sMoveForm)
                                        {
                                            bFindFlag = true;
                                            ((frmFMBDesign)frmChild).AddControl(ResourceStatus, true, false);
                                            this.pnlFMBDesign.Controls.Remove(ctrl);
                                            if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), form.cdvResID.Text, form.cdvLayOut.Text) == false)
                                            {
                                                return;
                                            }
                                            break;
                                        }
                                    }
                                }
                                if (bFindFlag == false)
                                {
                                    this.pnlFMBDesign.Controls.Remove(ctrl);
                                    if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), form.cdvResID.Text, form.cdvLayOut.Text) == false)
                                    {
                                        return;
                                    }
                                }
                            }
                            if (ResourceStatus.ToolType == Enums.eToolType.Port)
                            {
                                ResourceStatus.MotherResourceID = ctrl.CtrlStatus.MotherResourceID;
                            }

                            ctrl.SetCtrlStatusData(ResourceStatus, 1, true);
                            ctrl.CtrlStatus.IsSaveFlag = false;
                        }
                        break;

                    case Miracom.FMBUI.Enums.eToolType.SubResource:

                        frmFMBCreateSubResource subform = new frmFMBCreateSubResource(modGlobalConstant.MP_STEP_UPDATE);


                        subform.Tag = Tag;
                        if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                            subform.txtFactory.Text = sFactory;
                            subform.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            sFactory = MPGV.gsFactory;
                            subform.txtFactory.Text = sFactory;
                            subform.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlUpdate() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                            return;
                        }
                        subform.cdvSubResID.Text = ctrl.Name;
                        subform.txtX.Text = ctrl.GetLocation().X.ToString();
                        subform.txtY.Text = ctrl.GetLocation().Y.ToString();
                        subform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        subform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        subform.cdvResID.Text = ctrl.GetMotherResourceID();
                        subform.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                        if (subform.ShowDialog(this) == DialogResult.OK)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = subform.cdvSubResID.Text;
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(subform.txtX.Text), MPCF.ToInt(subform.txtY.Text)));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(subform.txtWidth.Text), MPCF.ToInt(subform.txtHeight.Text)));
                            ResourceStatus.Text = subform.txtText.Text;
                            ResourceStatus.ResTagFlag = subform.txtResTagFlag.Text;
                            ResourceStatus.MotherResourceID = subform.cdvResID.Text;
                            ResourceStatus.ToolType = Enums.eToolType.SubResource;
                            ResourceStatus.PrimaryStatus = subform.txtPriSts.Text;
                            ResourceStatus.UpDownFlag = subform.txtUpDown.Text;
                            ResourceStatus.LastEvent = subform.txtLastEvent.Text;
                            ResourceStatus.ResourceType = subform.txtSubResType.Text;
                            if (subform.utcText.Color.IsSystemColor == true || subform.utcText.Color.IsKnownColor == true)
                            {
                                ResourceStatus.TextColor = MPCF.ToInt(subform.utcText.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.TextColor = subform.utcText.Color.ToArgb();
                            }
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            if (subform.cboSize.Text == "")
                            {
                                ResourceStatus.TextSize = 0;
                            }
                            else
                            {
                                ResourceStatus.TextSize = MPCF.ToInt(subform.cboSize.Text);
                            }
                            ResourceStatus.TextStyle = subform.cboTextStyle.SelectedIndex;


                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                }
                                else
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                }
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            if (subform.utcBack.Color.IsSystemColor == true || subform.utcBack.Color.IsKnownColor == true)
                            {
                                ResourceStatus.BackColor = MPCF.ToInt(subform.utcBack.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.BackColor = subform.utcBack.Color.ToArgb();
                            }
                            ResourceStatus.ImageIndex = subform.iImageIndex;

                            if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT && subform.cdvLayOut.Text != FMBCF.GetStringBySeperator(Name, ":", 2))
                            {
                                string sMoveForm = sFactory + ":" + subform.cdvLayOut.Text;
                                Form frmChild;
                                bool bFindFlag = false;
                                foreach (Form tempLoopVar_frmChild in this.MdiParent.MdiChildren)
                                {
                                    frmChild = tempLoopVar_frmChild;
                                    if (frmChild is frmFMBDesign)
                                    {
                                        if (frmChild.Name == sMoveForm)
                                        {
                                            bFindFlag = true;
                                            ((frmFMBDesign)frmChild).AddControl(ResourceStatus, true, false);
                                            this.pnlFMBDesign.Controls.Remove(ctrl);
                                            if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), subform.cdvSubResID.Text, subform.cdvLayOut.Text) == false)
                                            {
                                                return;
                                            }
                                            break;
                                        }
                                    }
                                }
                                if (bFindFlag == false)
                                {
                                    this.pnlFMBDesign.Controls.Remove(ctrl);
                                    if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), subform.cdvSubResID.Text, subform.cdvLayOut.Text) == false)
                                    {
                                        return;
                                    }
                                }
                            }
                            ctrl.SetCtrlStatusData(ResourceStatus, 1, true);
                            ctrl.CtrlStatus.IsSaveFlag = false;
                        }
                        break;

                    case Miracom.FMBUI.Enums.eToolType.Tool:

                        frmFMBCreateTool toolform = new frmFMBCreateTool(modGlobalConstant.MP_STEP_UPDATE);


                        toolform.Tag = Tag;
                        if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                            toolform.txtFactory.Text = sFactory;
                            toolform.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            sFactory = MPGV.gsFactory;
                            toolform.txtFactory.Text = sFactory;
                            toolform.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlUpdate() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                            return;
                        }
                        toolform.cdvToolID.Text = ctrl.Name;
                        toolform.txtX.Text = ctrl.GetLocation().X.ToString();
                        toolform.txtY.Text = ctrl.GetLocation().Y.ToString();
                        toolform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        toolform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        if (toolform.ShowDialog(this) == DialogResult.OK)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = toolform.cdvToolID.Text;
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(toolform.txtX.Text), MPCF.ToInt(toolform.txtY.Text)));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(toolform.txtWidth.Text), MPCF.ToInt(toolform.txtHeight.Text)));
                            ResourceStatus.Text = toolform.txtText.Text;
                            ResourceStatus.ResTagFlag = toolform.txtResTagFlag.Text;
                            ResourceStatus.LastEvent = toolform.txtLastToolEvent.Text;
                            if (toolform.utcText.Color.IsSystemColor == true || toolform.utcText.Color.IsKnownColor == true)
                            {
                                ResourceStatus.TextColor = MPCF.ToInt(toolform.utcText.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.TextColor = toolform.utcText.Color.ToArgb();
                            }
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            if (toolform.cboSize.Text == "")
                            {
                                ResourceStatus.TextSize = 0;
                            }
                            else
                            {
                                ResourceStatus.TextSize = MPCF.ToInt(toolform.cboSize.Text);
                            }
                            ResourceStatus.TextStyle = toolform.cboTextStyle.SelectedIndex;
                            ResourceStatus.ToolType = ctrl.CtrlStatus.ToolType;
                            ResourceStatus.LastEvent = toolform.txtLastToolEvent.Text;
                            ResourceStatus.PrimaryStatus = toolform.txtToolStatus.Text;
                            ResourceStatus.ResourceType = toolform.txtToolType.Text;
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                }
                                else
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                }
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }

                            if (toolform.utcBack.Color.IsSystemColor == true || toolform.utcBack.Color.IsKnownColor == true)
                            {
                                ResourceStatus.BackColor = MPCF.ToInt(toolform.utcBack.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.BackColor = toolform.utcBack.Color.ToArgb();
                            }
                            ResourceStatus.ImageIndex = toolform.iImageIndex;

                            if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT && toolform.cdvLayOut.Text != FMBCF.GetStringBySeperator(Name, ":", 2))
                            {
                                string sMoveForm = sFactory + ":" + toolform.cdvLayOut.Text;
                                Form frmChild;
                                bool bFindFlag = false;
                                foreach (Form tempLoopVar_frmChild in this.MdiParent.MdiChildren)
                                {
                                    frmChild = tempLoopVar_frmChild;
                                    if (frmChild is frmFMBDesign)
                                    {
                                        if (frmChild.Name == sMoveForm)
                                        {
                                            bFindFlag = true;
                                            ((frmFMBDesign)frmChild).AddControl(ResourceStatus, true, false);
                                            this.pnlFMBDesign.Controls.Remove(ctrl);
                                            if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), toolform.cdvToolID.Text, toolform.cdvLayOut.Text) == false)
                                            {
                                                return;
                                            }
                                            break;
                                        }
                                    }
                                }
                                if (bFindFlag == false)
                                {
                                    this.pnlFMBDesign.Controls.Remove(ctrl);
                                    if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), toolform.cdvToolID.Text, toolform.cdvLayOut.Text) == false)
                                    {
                                        return;
                                    }
                                }
                            }
                            ctrl.SetCtrlStatusData(ResourceStatus, 1, true);
                            ctrl.CtrlStatus.IsSaveFlag = false;
                        }
                        break;

                    case Miracom.FMBUI.Enums.eToolType.Port:

                        frmFMBCreatePort portform = new frmFMBCreatePort(modGlobalConstant.MP_STEP_UPDATE);


                        portform.Tag = Tag;
                        if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                            portform.txtFactory.Text = sFactory;
                            portform.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (Tag.ToString() == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            sFactory = MPGV.gsFactory;
                            portform.txtFactory.Text = sFactory;
                            portform.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlUpdate() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                            return;
                        }
                        portform.cdvPortID.Text = ctrl.Name;
                        portform.cdvResID.Text = ctrl.GetMotherResourceID();
                        portform.txtX.Text = ctrl.GetLocation().X.ToString();
                        portform.txtY.Text = ctrl.GetLocation().Y.ToString();
                        portform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        portform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        portform.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                        if (portform.ShowDialog(this) == DialogResult.OK)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = portform.cdvPortID.Text;
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(portform.txtX.Text), MPCF.ToInt(portform.txtY.Text)));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(portform.txtWidth.Text), MPCF.ToInt(portform.txtHeight.Text)));
                            ResourceStatus.Text = portform.txtText.Text;
                            ResourceStatus.ResTagFlag = portform.txtResTagFlag.Text;
                            ResourceStatus.MotherResourceID = portform.cdvResID.Text;
                            ResourceStatus.PrimaryStatus = portform.txtPortStatus.Text;
                            ResourceStatus.ResourceType = portform.txtPortType.Text;
                            if (portform.utcText.Color.IsSystemColor == true || portform.utcText.Color.IsKnownColor == true)
                            {
                                ResourceStatus.TextColor = MPCF.ToInt(portform.utcText.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.TextColor = portform.utcText.Color.ToArgb();
                            }
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            if (portform.cboSize.Text == "")
                            {
                                ResourceStatus.TextSize = 0;
                            }
                            else
                            {
                                ResourceStatus.TextSize = MPCF.ToInt(portform.cboSize.Text);
                            }
                            ResourceStatus.TextStyle = portform.cboTextStyle.SelectedIndex;
                            ResourceStatus.ToolType = ctrl.CtrlStatus.ToolType;

                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            if (portform.utcBack.Color.IsSystemColor == true || portform.utcBack.Color.IsKnownColor == true)
                            {
                                ResourceStatus.BackColor = MPCF.ToInt(portform.utcBack.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.BackColor = portform.utcBack.Color.ToArgb();
                            }
                            ResourceStatus.ImageIndex = portform.iImageIndex;

                            if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT && portform.cdvLayOut.Text != FMBCF.GetStringBySeperator(Name, ":", 2))
                            {
                                string sMoveForm = sFactory + ":" + portform.cdvLayOut.Text;
                                Form frmChild;
                                bool bFindFlag = false;
                                foreach (Form tempLoopVar_frmChild in this.MdiParent.MdiChildren)
                                {
                                    frmChild = tempLoopVar_frmChild;
                                    if (frmChild is frmFMBDesign)
                                    {
                                        if (frmChild.Name == sMoveForm)
                                        {
                                            bFindFlag = true;
                                            ((frmFMBDesign)frmChild).AddControl(ResourceStatus, true, false);
                                            this.pnlFMBDesign.Controls.Remove(ctrl);
                                            if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), portform.cdvPortID.Text, portform.cdvLayOut.Text) == false)
                                            {
                                                return;
                                            }
                                            break;
                                        }
                                    }
                                }
                                if (bFindFlag == false)
                                {
                                    this.pnlFMBDesign.Controls.Remove(ctrl);
                                    if (FMBFI.gIMdiForm.RefreshDesignList("4", sFactory, FMBCF.GetStringBySeperator(Name, ":", 2), portform.cdvPortID.Text, portform.cdvLayOut.Text) == false)
                                    {
                                        return;
                                    }
                                }
                            }
                            ctrl.SetCtrlStatusData(ResourceStatus, 1, true);
                            ctrl.CtrlStatus.IsSaveFlag = false;
                        }
                        break;
                    default:

                        //frmFMBCreateTag form = new frmFMBCreateTag(modGlobalConstant.MP_STEP_UPDATE); => 변수 form 이 중복되어 form1으로 명칭 변경(2007.02.21)
                        frmFMBCreateTag form1 = new frmFMBCreateTag(modGlobalConstant.MP_STEP_UPDATE);


                        form1.Tag = Tag;
                        if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                            form1.txtFactory.Text = sFactory;
                            form1.txtLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            sFactory = MPGV.gsFactory;
                            form1.txtFactory.Text = sFactory;
                            form1.txtLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlUpdate() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                            return;
                        }
                        form1.txtTagID.Text = ctrl.Name;
                        form1.txtX.Text = ctrl.GetLocation().X.ToString();
                        form1.txtY.Text = ctrl.GetLocation().Y.ToString();
                        if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.VerticalLine)
                        {
                            form1.txtWidth.Text = ctrl.GetSize().Height.ToString();
                            form1.txtHeight.Text = ctrl.GetSize().Width.ToString();
                        }
                        else
                        {
                            form1.txtWidth.Text = ctrl.GetSize().Width.ToString();
                            form1.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        }
                        if (form1.ShowDialog(this) == DialogResult.OK)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = form1.txtTagID.Text;
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(form1.txtX.Text), MPCF.ToInt(form1.txtY.Text)));
                            if (form1.cboShape.SelectedIndex == MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.VerticalLine) - 1)
                            {
                                ResourceStatus.SetSize(new Size(MPCF.ToInt(form1.txtHeight.Text), MPCF.ToInt(form1.txtWidth.Text)));
                            }
                            else
                            {
                                ResourceStatus.SetSize(new Size(MPCF.ToInt(form1.txtWidth.Text), MPCF.ToInt(form1.txtHeight.Text)));
                            }
                            ResourceStatus.ResTagFlag = form1.txtResTagFlag.Text;
                            ResourceStatus.Text = form1.txtText.Text;
                            if (form1.utcText.Color.IsSystemColor == true || form1.utcText.Color.IsKnownColor == true)
                            {
                                ResourceStatus.TextColor = MPCF.ToInt(form1.utcText.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.TextColor = form1.utcText.Color.ToArgb();
                            }
                            if (form1.utcBack.Color.IsSystemColor == true || form1.utcBack.Color.IsKnownColor == true)
                            {
                                ResourceStatus.BackColor = MPCF.ToInt(form1.utcBack.Color.ToKnownColor());
                            }
                            else
                            {
                                ResourceStatus.BackColor = form1.utcBack.Color.ToArgb();
                            }
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            if (form1.cboSize.Text == "")
                            {
                                ResourceStatus.TextSize = 0;
                            }
                            else
                            {
                                ResourceStatus.TextSize = MPCF.ToInt(form1.cboSize.Text);
                            }
                            ResourceStatus.TextStyle = form1.cboTextStyle.SelectedIndex;
                            ResourceStatus.ToolType = (Miracom.FMBUI.Enums.eToolType)form1.cboShape.SelectedIndex + 1;
                            ResourceStatus.IsNoEvent = form1.chkNoMouseEvent.Checked;
                            ctrl.SetCtrlStatusData(ResourceStatus, 1, true);
                            ctrl.CtrlStatus.IsSaveFlag = false;
                        }
                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlUpdate()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlDelete(System.Object sender, CtrlContextMenu_EventArgs e)
        {

            try
            {
                if (!(e.CtrlSender is udcCtrlBase))
                {
                    return;
                }

                udcCtrlBase ctrl = (udcCtrlBase)e.CtrlSender;

                if (this.pnlFMBDesign.Contains(ctrl) == false)
                {
                    return;
                }

                string sFactory = "";
                string sLayout = "";
                char cResourceType = ' ';
                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                    sLayout = FMBCF.GetStringBySeperator(Name, ":", 2);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                    sLayout = Name;
                }

                if (e.FunctionName == "KEY_DELETE")
                {
                    if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                    {
                        cResourceType = modGlobalConstant.FMB_RESOURCE_TYPE;
                    }
                    else if (Miracom.FMBUI.Enums.eToolType.SubResource == ctrl.CtrlStatus.ToolType)
                    {
                        cResourceType = modGlobalConstant.FMB_SUB_RESOURCE_TYPE;
                    }
                    else if (Miracom.FMBUI.Enums.eToolType.Tool == ctrl.CtrlStatus.ToolType)
                    {
                        cResourceType = modGlobalConstant.FMB_TOOL_TYPE;
                    }
                    else if (Miracom.FMBUI.Enums.eToolType.Port == ctrl.CtrlStatus.ToolType)
                    {
                        cResourceType = modGlobalConstant.FMB_PORT_TYPE;
                    }
                    else
                    {
                        cResourceType = modGlobalConstant.FMB_TAG_TYPE;
                    }

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(5), "FMB Client", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                    {
                        if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port || ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                        {
                            if (FMBCF.DeleteSubResource(System.Convert.ToString(this.Tag), sFactory, sLayout, ctrl.CtrlStatus.MotherResourceID, ctrl.Name, cResourceType) == false)
                            {
                                return;
                            }

                        }
                        else
                        {
                            if (FMBCF.DeleteResource(System.Convert.ToString(this.Tag), sFactory, sLayout, ctrl.Name, cResourceType) == false)
                            {
                                return;
                            }
                        }


                        if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource && System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            if (FMBFI.gIMdiForm.RefreshDesignList("2", sFactory, sLayout, ctrl.Name, "") == false)
                            {
                                return;
                            }
                        }
                        pnlFMBDesign.Controls.Remove(ctrl);
                    }
                }
                else
                {
                    switch (ctrl.CtrlStatus.ToolType)
                    {
                        case Miracom.FMBUI.Enums.eToolType.Resource:

                            frmFMBCreateResource form = new frmFMBCreateResource(modGlobalConstant.MP_STEP_DELETE);
                            form.Tag = Tag;
                            form.txtFactory.Text = sFactory;
                            form.cdvLayOut.Text = sLayout;
                            form.cdvResID.Text = ctrl.Name;
                            form.txtX.Text = ctrl.GetLocation().X.ToString();
                            form.txtY.Text = ctrl.GetLocation().Y.ToString();
                            form.txtWidth.Text = ctrl.GetSize().Width.ToString();
                            form.txtHeight.Text = ctrl.GetSize().Height.ToString();
                            if (form.ShowDialog(this) == DialogResult.OK)
                            {
                                pnlFMBDesign.Controls.Remove(ctrl);
                            }
                            break;
                        case Miracom.FMBUI.Enums.eToolType.SubResource:

                            frmFMBCreateSubResource subform = new frmFMBCreateSubResource(modGlobalConstant.MP_STEP_DELETE);
                            subform.Tag = Tag;
                            subform.txtFactory.Text = sFactory;
                            subform.cdvLayOut.Text = sLayout;
                            subform.cdvSubResID.Text = ctrl.Name;
                            subform.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                            subform.txtX.Text = ctrl.GetLocation().X.ToString();
                            subform.txtY.Text = ctrl.GetLocation().Y.ToString();
                            subform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                            subform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                            if (subform.ShowDialog(this) == DialogResult.OK)
                            {
                                pnlFMBDesign.Controls.Remove(ctrl);
                            }
                            break;
                        case Miracom.FMBUI.Enums.eToolType.Tool:

                            frmFMBCreateTool toolform = new frmFMBCreateTool(modGlobalConstant.MP_STEP_DELETE);
                            toolform.Tag = Tag;
                            toolform.txtFactory.Text = sFactory;
                            toolform.cdvLayOut.Text = sLayout;
                            toolform.cdvToolID.Text = ctrl.Name;
                            toolform.txtX.Text = ctrl.GetLocation().X.ToString();
                            toolform.txtY.Text = ctrl.GetLocation().Y.ToString();
                            toolform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                            toolform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                            toolform.txtCreateUser.Text = ctrl.CtrlStatus.MotherResourceID;
                            if (toolform.ShowDialog(this) == DialogResult.OK)
                            {
                                pnlFMBDesign.Controls.Remove(ctrl);
                            }
                            break;
                        case Miracom.FMBUI.Enums.eToolType.Port:

                            frmFMBCreatePort portform = new frmFMBCreatePort(modGlobalConstant.MP_STEP_DELETE);
                            portform.Tag = Tag;
                            portform.txtFactory.Text = sFactory;
                            portform.cdvLayOut.Text = sLayout;
                            portform.cdvPortID.Text = ctrl.Name;
                            portform.txtX.Text = ctrl.GetLocation().X.ToString();
                            portform.txtY.Text = ctrl.GetLocation().Y.ToString();
                            portform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                            portform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                            portform.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                            if (portform.ShowDialog(this) == DialogResult.OK)
                            {
                                pnlFMBDesign.Controls.Remove(ctrl);
                            }
                            break;
                        default:

                            frmFMBCreateTag form1 = new frmFMBCreateTag(modGlobalConstant.MP_STEP_DELETE);
                            form1.Tag = Tag;
                            form1.txtFactory.Text = sFactory;
                            form1.txtLayOut.Text = sLayout;
                            form1.txtTagID.Text = ctrl.Name;
                            form1.txtX.Text = ctrl.GetLocation().X.ToString();
                            form1.txtY.Text = ctrl.GetLocation().Y.ToString();
                            if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.VerticalLine)
                            {
                                form1.txtWidth.Text = ctrl.GetSize().Height.ToString();
                                form1.txtHeight.Text = ctrl.GetSize().Width.ToString();
                            }
                            else
                            {
                                form1.txtWidth.Text = ctrl.GetSize().Width.ToString();
                                form1.txtHeight.Text = ctrl.GetSize().Height.ToString();
                            }
                            if (form1.ShowDialog(this) == DialogResult.OK)
                            {
                                pnlFMBDesign.Controls.Remove(ctrl);
                            }
                            break;
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlDelete()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlProperties(System.Object sender, CtrlContextMenu_EventArgs e)
        {

            try
            {
                if (!(e.CtrlSender is udcCtrlBase))
                {
                    return;
                }

                udcCtrlBase ctrl = (udcCtrlBase)e.CtrlSender;

                switch (ctrl.CtrlStatus.ToolType)
                {
                    case Miracom.FMBUI.Enums.eToolType.Resource:

                        frmFMBCreateResource form = new frmFMBCreateResource(modGlobalConstant.MP_STEP_VIEW);
                        form.Tag = Tag;
                        if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            form.txtFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                            form.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            form.txtFactory.Text = MPGV.gsFactory;
                            form.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlProperties() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                            return;
                        }
                        form.cdvResID.Text = ctrl.Name;
                        form.txtX.Text = ctrl.GetLocation().X.ToString();
                        form.txtY.Text = ctrl.GetLocation().Y.ToString();
                        form.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        form.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        if (form.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }
                        break;
                    case Miracom.FMBUI.Enums.eToolType.SubResource:

                        frmFMBCreateSubResource subform = new frmFMBCreateSubResource(modGlobalConstant.MP_STEP_VIEW);
                        subform.Tag = Tag;
                        if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            subform.txtFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                            subform.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            subform.txtFactory.Text = MPGV.gsFactory;
                            subform.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlProperties() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                            return;
                        }
                        subform.cdvSubResID.Text = ctrl.Name;
                        subform.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                        subform.txtX.Text = ctrl.GetLocation().X.ToString();
                        subform.txtY.Text = ctrl.GetLocation().Y.ToString();
                        subform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        subform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        if (subform.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }
                        break;
                    case Miracom.FMBUI.Enums.eToolType.Tool:

                        frmFMBCreateTool toolform = new frmFMBCreateTool(modGlobalConstant.MP_STEP_VIEW);
                        toolform.Tag = Tag;
                        if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            toolform.txtFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                            toolform.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            toolform.txtFactory.Text = MPGV.gsFactory;
                            toolform.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlProperties() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                            return;
                        }
                        toolform.cdvToolID.Text = ctrl.Name;
                        toolform.txtX.Text = ctrl.GetLocation().X.ToString();
                        toolform.txtY.Text = ctrl.GetLocation().Y.ToString();
                        toolform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        toolform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        if (toolform.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }
                        break;
                    case Miracom.FMBUI.Enums.eToolType.Port:

                        frmFMBCreatePort portform = new frmFMBCreatePort(modGlobalConstant.MP_STEP_VIEW);
                        portform.Tag = Tag;
                        if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            portform.txtFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                            portform.cdvLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            portform.txtFactory.Text = MPGV.gsFactory;
                            portform.cdvLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlProperties() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                            return;
                        }
                        portform.cdvPortID.Text = ctrl.Name;
                        portform.txtX.Text = ctrl.GetLocation().X.ToString();
                        portform.txtY.Text = ctrl.GetLocation().Y.ToString();
                        portform.txtWidth.Text = ctrl.GetSize().Width.ToString();
                        portform.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        portform.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                        if (portform.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }
                        break;
                    //Dim form As Form1 = New Form1
                    //form.ShowDialog(Me)
                    default:

                        frmFMBCreateTag form1 = new frmFMBCreateTag(modGlobalConstant.MP_STEP_VIEW);
                        form1.Tag = Tag;
                        if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                        {
                            form1.txtFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                            form1.txtLayOut.Text = FMBCF.GetStringBySeperator(Name, ":", 2);
                        }
                        else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                        {
                            form1.txtFactory.Text = MPGV.gsFactory;
                            form1.txtLayOut.Text = Name;
                        }
                        else
                        {
                            MPCF.ShowMsgBox("CtrlBase_CtrlProperties() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                            return;
                        }
                        form1.txtTagID.Text = ctrl.Name;
                        form1.txtX.Text = ctrl.GetLocation().X.ToString();
                        form1.txtY.Text = ctrl.GetLocation().Y.ToString();
                        if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.VerticalLine)
                        {
                            form1.txtWidth.Text = ctrl.GetSize().Height.ToString();
                            form1.txtHeight.Text = ctrl.GetSize().Width.ToString();
                        }
                        else
                        {
                            form1.txtWidth.Text = ctrl.GetSize().Width.ToString();
                            form1.txtHeight.Text = ctrl.GetSize().Height.ToString();
                        }
                        if (form1.ShowDialog(this) == DialogResult.OK)
                        {
                            //Do Nothing - Only View
                        }
                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlProperties()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }


        public void CtrlBase_CtrlViewResourceStatus(System.Object sender, CtrlContextMenu_EventArgs e)
        {

            try
            {
                if (!(e.CtrlSender is udcCtrlBase))
                {
                    return;
                }

                udcCtrlBase ctrl = (udcCtrlBase)e.CtrlSender;


                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                {
                    frmFMBViewResourceStatus form = new frmFMBViewResourceStatus();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        form.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        form.cdvFactory.Text = MPGV.gsFactory;
                    }
                    form.cdvResID.Text = ctrl.Name;
                    form.MdiParent = MPGV.gfrmMDI;
                    form.Show();
                    form.btnView.PerformClick();
                }
                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                {
                    frmFMBViewSubResourceStatus subForm = new frmFMBViewSubResourceStatus();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        subForm.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        subForm.cdvFactory.Text = MPGV.gsFactory;
                    }
                    subForm.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                    subForm.cdvSubResID.Text = ctrl.Name;
                    subForm.MdiParent = MPGV.gfrmMDI;
                    subForm.Show();
                    subForm.btnView.PerformClick();
                }
                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                {
                    frmFMBViewPortStatus portForm = new frmFMBViewPortStatus();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        portForm.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        portForm.cdvFactory.Text = MPGV.gsFactory;
                    }
                    portForm.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                    portForm.cdvPortID.Text = ctrl.Name;
                    portForm.MdiParent = MPGV.gfrmMDI;
                    portForm.Show();
                    portForm.btnView.PerformClick();
                }
                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                {
                    frmFMBViewToolStatus toolform = new frmFMBViewToolStatus();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        toolform.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        toolform.cdvFactory.Text = MPGV.gsFactory;
                    }
                    toolform.cdvToolID.Text = ctrl.Name;
                    toolform.MdiParent = MPGV.gfrmMDI;
                    toolform.Show();
                    toolform.btnView.PerformClick();
                }
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlViewResourceStatus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlViewResourceHistory(System.Object sender, CtrlContextMenu_EventArgs e)
        {

            try
            {
                if (!(e.CtrlSender is udcCtrlBase))
                {
                    return;
                }

                udcCtrlBase ctrl = (udcCtrlBase)e.CtrlSender;

                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                {
                    frmFMBViewResourceHistory form = new frmFMBViewResourceHistory();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        form.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        form.cdvFactory.Text = MPGV.gsFactory;
                    }
                    form.cdvResID.Text = ctrl.Name;
                    form.MdiParent = MPGV.gfrmMDI;
                    form.Show();
                    form.btnView.PerformClick();
                }
                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                {
                    frmFMBViewSubResourceHistory subresForm = new frmFMBViewSubResourceHistory();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        subresForm.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        subresForm.cdvFactory.Text = MPGV.gsFactory;
                    }
                    subresForm.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                    subresForm.cdvSubResID.Text = ctrl.Name;
                    subresForm.MdiParent = MPGV.gfrmMDI;
                    subresForm.Show();
                    subresForm.btnProcess.PerformClick();
                }
                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                {
                    frmFMBViewToolHistory toolForm = new frmFMBViewToolHistory();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        toolForm.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        toolForm.cdvFactory.Text = MPGV.gsFactory;
                    }
                    toolForm.cdvToolType.Text = ctrl.CtrlStatus.ResourceType;
                    toolForm.cdvToolID.Text = ctrl.Name;
                    toolForm.MdiParent = MPGV.gfrmMDI;
                    toolForm.Show();
                    toolForm.btnProcess.PerformClick();
                }
                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                {
                    frmFMBViewPortHistory portForm = new frmFMBViewPortHistory();
                    if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                    {
                        portForm.cdvFactory.Text = FMBCF.GetStringBySeperator(Name, ":", 1);
                    }
                    else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                    {
                        portForm.cdvFactory.Text = MPGV.gsFactory;
                    }
                    portForm.cdvResID.Text = ctrl.CtrlStatus.MotherResourceID;
                    portForm.cdvPortID.Text = ctrl.Name;
                    portForm.MdiParent = MPGV.gfrmMDI;
                    portForm.Show();
                    portForm.btnProcess.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlViewResourceHistory()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlTranEvent(System.Object sender, CtrlContextMenu_EventArgs e)
        {

            try
            {
                if (!(e.CtrlSender is udcCtrlBase))
                {
                    return;
                }

                udcCtrlBase ctrl = (udcCtrlBase)e.CtrlSender;


                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                {
                    MPGV.gsCurrentRes_ID = ctrl.Name;
                    Form form = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmRASTranEvent");
                    if (form == null)
                    {
                        form = new frmRASTranEvent();
                    }

                    form.MdiParent = MPGV.gfrmMDI;
                    form.Show();

                    MPGV.gsCurrentRes_ID = "";
                }
                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                {
                    Form form = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmRASTranToolEvent");
                    if (form == null)
                    {
                        form = new frmRASTranToolEvent();
                    }
                    form.MdiParent = MPGV.gfrmMDI;
                    form.Show();

                }
                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                {
                    Form subresForm = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmRASTranChangePortStatus");
                    if (subresForm == null)
                    {
                        subresForm = new frmRASTranChangePortStatus();
                    }
                    subresForm.MdiParent = MPGV.gfrmMDI;
                    subresForm.Show();

                }
                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                {
                    Form subresForm = FMBCF.GetChildForm(MPGV.gfrmMDI, "frmRASTranSubEvent");
                    if (subresForm == null)
                    {
                        subresForm = new frmRASTranSubEvent();
                    }
                    subresForm.MdiParent = MPGV.gfrmMDI;
                    subresForm.Show();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.CtrlBase_CtrlTranEvent()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        private void frmFMBDesign_Load(object sender, System.EventArgs e)
        {

            try
            {
                Cursor = Cursors.WaitCursor;

                IsLoading = true;

                if (MPGV.giAutoRefreshTime > 0)
                {
                    tmrRefresh.Interval = MPGV.giAutoRefreshTime * 1000;

                }

                if (MPGV.gbAutoRefresh == true)
                {
                    tmrRefresh.Start();
                }
                else
                {
                    tmrRefresh.Stop();
                }

                //tsmTopFormat.Enabled = false;
                //tsmSaveDesign.Enabled = IsDesignMode;
                //tsmAddRes.Enabled = IsDesignMode;

                pnlFMBDesign.pnlTracker.BackColor = Color.FromArgb(0, Color.Beige);

                if (IsDesignMode == true)
                {
                    pnlFMBDesign.BackColor = Color.WhiteSmoke;
                }
                else
                {
                    pnlFMBDesign.BackColor = Color.White;
                }

                string sFactory;
                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }
                else
                {
                    return;
                }
                if (FMBCF.ViewGlobalOption(sFactory) == false)
                {
                    return;
                }

                if (ViewLayout() == false)
                {
                    return;
                }

                ctrlArray.Clear();
                if (ViewResourceListDetail() == false)
                {
                    return;
                }

                if (ViewToolListDetail() == false)
                {
                    return;
                }
                if (ViewSubResourceListDetail() == false)
                {
                    return;
                }
                if (ViewPortListDetail() == false)
                {
                    return;
                }

                SortControls();
                pnlFMBDesign.Select();

                Cursor = Cursors.Default;


                //ChangeMenuText(mnuDesign);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.frmFMBDesign_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        private void frmFMBDesign_Activated(object sender, System.EventArgs e)
        {
            try
            {
                pnlFMBDesign.Select();
                pnlFMBDesign.Focus();
                if (IsLoading == true)
                {

                    IsLoading = false;
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.frmFMBDesign_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        private void tmrRefresh_Tick(object sender, System.EventArgs e)
        {

            try
            {

                if (IsDesignMode == true)
                {
                    return;
                }
                if (ZoomScale != 0)
                {
                    ZoomScale = 0;
                    DesignSize = OriginalDesignSize;
                }
                string sFactory;
                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }
                else
                {
                    return;
                }
                if (FMBCF.ViewGlobalOption(sFactory) == false)
                {
                    return;
                }
                if (RefreshResourceListDetail() == false)
                {
                    return;
                }
                if (SetModifiedControl(false) == false)
                {
                    return;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tmrRefresh_Tick()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        #endregion

        #region " Format Functions"

        public udcCtrlBase FindFocusCtrl()
        {

            udcCtrlBase ctrl = null;

            try
            {
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == true)
                    {
                        ctrl = (udcCtrlBase)pnlFMBDesign.SelectedControls[i];
                        break;
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.FindFocusCtrl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

            return ctrl;

        }

        public bool Format_Lefts()
        {

            try
            {
                int iLeft;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iLeft = FocusedCtrl.GetLocation().X;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetLocation(new Point(iLeft, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().Y), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Lefts()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Centers()
        {

            try
            {
                int iCenter;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iCenter = FocusedCtrl.GetLocation().X + FocusedCtrl.GetSize().Width / 2;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetLocation(new Point(iCenter - ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Width / 2, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().Y), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Centers()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Rights()
        {

            try
            {
                int iRight;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iRight = FocusedCtrl.GetLocation().X + FocusedCtrl.GetSize().Width;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetLocation(new Point(iRight - ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Width, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().Y), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Rights()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Tops()
        {

            try
            {
                int iTop;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iTop = FocusedCtrl.GetLocation().Y;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetLocation(new Point(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().X, iTop), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Tops()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Middles()
        {

            try
            {
                int iMiddle;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iMiddle = MPCF.ToInt(FocusedCtrl.GetLocation().Y + FocusedCtrl.GetSize().Height / 2.0);
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetLocation(new Point(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().X, iMiddle - ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Height / 2), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Middles()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Bottoms()
        {

            try
            {
                int iBottom;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iBottom = FocusedCtrl.GetLocation().Y + FocusedCtrl.GetSize().Height;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetLocation(new Point(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetLocation().X, iBottom - ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Height), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Bottoms()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Width()
        {

            try
            {
                int iWidth;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iWidth = FocusedCtrl.GetSize().Width;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetSize(new Size(iWidth, ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Height), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Width()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Height()
        {

            try
            {
                int iHeight;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iHeight = FocusedCtrl.GetSize().Height;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetSize(new Size(((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).GetSize().Width, iHeight), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Height()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_Both()
        {

            try
            {
                int iWidth;
                int iHeight;
                udcCtrlBase FocusedCtrl = FindFocusCtrl();
                if (FocusedCtrl == null)
                {
                    return false;
                }
                iWidth = FocusedCtrl.GetSize().Width;
                iHeight = FocusedCtrl.GetSize().Height;
                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused == false)
                    {
                        ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).SetSize(new Size(iWidth, iHeight), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_Both()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_HMakeEqual()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.LEFT_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int iWidth = ((udcCtrlBase)arrCtrl[arrCtrl.Count - 1]).GetLocation().X - ((udcCtrlBase)arrCtrl[0]).GetLocation().X;
                int i;
                for (i = 0; i <= arrCtrl.Count - 2; i++)
                {
                    iWidth -= ((udcCtrlBase)arrCtrl[i]).GetSize().Width;
                }

                iWidth /= arrCtrl.Count - 1;

                if (iWidth < 0)
                {
                    iWidth = 0;
                }

                int iFocusedIndex = 0;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point((((udcCtrlBase)arrCtrl[i + 1]).GetLocation().X - iWidth) - ((udcCtrlBase)arrCtrl[i]).GetSize().Width, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i - 1]).GetLocation().X + ((udcCtrlBase)arrCtrl[i - 1]).GetSize().Width + iWidth, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_HMakeEqual()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_HIncrease()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.LEFT_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int iFocusedIndex = 0;
                int i;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                int iIncWidth = 0;
                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    iIncWidth++;
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X - iIncWidth, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                iIncWidth = 0;
                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    iIncWidth++;
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X + iIncWidth, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_HIncrease()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_HDecrease()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.LEFT_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int iFocusedIndex = 0;
                int i;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                int iDecWidth = 0;
                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    if ((((udcCtrlBase)arrCtrl[i]).GetLocation().X + ((udcCtrlBase)arrCtrl[i]).GetSize().Width / 2) != (((udcCtrlBase)arrCtrl[i + 1]).GetLocation().X + ((udcCtrlBase)arrCtrl[i + 1]).GetSize().Width / 2))
                    {
                        iDecWidth++;
                        ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X + iDecWidth, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                    }
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                iDecWidth = 0;
                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    if ((((udcCtrlBase)arrCtrl[i]).GetLocation().X + ((udcCtrlBase)arrCtrl[i]).GetSize().Width / 2) != (((udcCtrlBase)arrCtrl[i - 1]).GetLocation().X + ((udcCtrlBase)arrCtrl[i - 1]).GetSize().Width / 2))
                    {
                        iDecWidth++;
                        ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X - iDecWidth, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_HDecrease()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_HRemove()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.LEFT_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int i;
                int iFocusedIndex = 0;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i + 1]).GetLocation().X - ((udcCtrlBase)arrCtrl[i]).GetSize().Width, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i - 1]).GetLocation().X + ((udcCtrlBase)arrCtrl[i - 1]).GetSize().Width, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y), false);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_HRemove()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_VMakeEqual()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.TOP_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int iHeight = ((udcCtrlBase)arrCtrl[arrCtrl.Count - 1]).GetLocation().Y - ((udcCtrlBase)arrCtrl[0]).GetLocation().Y;
                int i;
                for (i = 0; i <= arrCtrl.Count - 2; i++)
                {
                    iHeight -= ((udcCtrlBase)arrCtrl[i]).GetSize().Height;
                }

                iHeight /= arrCtrl.Count - 1;

                if (iHeight < 0)
                {
                    iHeight = 0;
                }

                int iFocusedIndex = 0;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, (((udcCtrlBase)arrCtrl[i + 1]).GetLocation().Y - iHeight) - ((udcCtrlBase)arrCtrl[i]).GetSize().Height), false);
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, ((udcCtrlBase)arrCtrl[i - 1]).GetLocation().Y + ((udcCtrlBase)arrCtrl[i - 1]).GetSize().Height + iHeight), false);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_VMakeEqual()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_VIncrease()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.TOP_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int iFocusedIndex = 0;
                int i;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                int iIncHeight = 0;
                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    iIncHeight++;
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y - iIncHeight), false);
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                iIncHeight = 0;
                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    iIncHeight++;
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y + iIncHeight), false);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_VIncrease()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_VDecrease()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.TOP_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int iFocusedIndex = 0;
                int i;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                int iDecHeight = 0;
                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    if ((((udcCtrlBase)arrCtrl[i]).GetLocation().Y + ((udcCtrlBase)arrCtrl[i]).GetSize().Height / 2) != (((udcCtrlBase)arrCtrl[i + 1]).GetLocation().Y + ((udcCtrlBase)arrCtrl[i + 1]).GetSize().Height / 2))
                    {
                        iDecHeight++;
                        ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y + iDecHeight), false);
                    }
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                iDecHeight = 0;
                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    if ((((udcCtrlBase)arrCtrl[i]).GetLocation().Y + ((udcCtrlBase)arrCtrl[i]).GetSize().Height / 2) != (((udcCtrlBase)arrCtrl[i - 1]).GetLocation().Y + ((udcCtrlBase)arrCtrl[i - 1]).GetSize().Height / 2))
                    {
                        iDecHeight++;
                        ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, ((udcCtrlBase)arrCtrl[i]).GetLocation().Y - iDecHeight), false);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_VDecrease()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_VRemove()
        {

            try
            {
                ArrayList arrCtrl = new ArrayList(pnlFMBDesign.SelectedControls);
                SelectedControlSort comparer = new SelectedControlSort(SelectedControlSort.SortOrder.TOP_ALL_ORDER);
                arrCtrl.Sort(comparer);

                int i;
                int iFocusedIndex = 0;
                for (i = 0; i <= arrCtrl.Count - 1; i++)
                {
                    if (((udcCtrlBase)arrCtrl[i]).IsFocused == true)
                    {
                        iFocusedIndex = i;
                        break;
                    }
                }

                for (i = iFocusedIndex - 1; i >= 0; i--)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, (((udcCtrlBase)arrCtrl[i + 1]).GetLocation().Y) - ((udcCtrlBase)arrCtrl[i]).GetSize().Height), false);
                }

                if (iFocusedIndex >= arrCtrl.Count - 1)
                {
                    return true;
                }

                for (i = iFocusedIndex + 1; i <= arrCtrl.Count - 1; i++)
                {
                    ((udcCtrlBase)arrCtrl[i]).SetLocation(new Point(((udcCtrlBase)arrCtrl[i]).GetLocation().X, ((udcCtrlBase)arrCtrl[i - 1]).GetLocation().Y + ((udcCtrlBase)arrCtrl[i - 1]).GetSize().Height), false);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_VMakeEqual()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_BringToFront()
        {

            try
            {
                TRSNode in_node = new TRSNode("Priority_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                Control ctrl;
                foreach (Control tempLoopVar_ctrl in this.pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).IsSelected == true)
                        {
                            ((udcCtrlBase)ctrl).BringToFront();
                            if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                            {
                                MPCR.SetInMsg(in_node);
                                in_node.ProcStep = '1';
                                in_node.Factory = FMBCF.GetStringBySeperator(Name, ":", 1);
                                in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));

                                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_SUB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);

                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TOOL_TYPE);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_PORT_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TAG_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }



                                if (MPCR.CallService("FMB", "FMB_Resource_Priority", in_node, ref out_node) == false)
                                {
                                    return false;
                                }

                            }
                            else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                            {
                                MPCR.SetInMsg(in_node);
                                in_node.ProcStep = '1';

                                in_node.AddString("GROUP_ID", Name);
                                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_SUB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);

                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TOOL_TYPE);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_PORT_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TAG_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }

                                if (MPCR.CallService("FMB", "FMB_UDR_Priority", in_node, ref out_node) == false)
                                {
                                    return false;
                                }
                            }
                            return true;
                        }
                    }
                }
                return false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_BringToFront()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool Format_SendToBack()
        {

            try
            {
                TRSNode in_node = new TRSNode("Priority_In");
                TRSNode out_node = new TRSNode("Cmn_Out");


                Control ctrl;
                foreach (Control tempLoopVar_ctrl in this.pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).IsSelected == true)
                        {
                            ((udcCtrlBase)ctrl).SendToBack();
                            if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                            {
                                MPCR.SetInMsg(in_node);
                                in_node.ProcStep = '2';
                                in_node.Factory = FMBCF.GetStringBySeperator(Name, ":", 1);
                                in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_SUB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);

                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TOOL_TYPE);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_PORT_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TAG_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }

                                if (MPCR.CallService("FMB", "FMB_Resource_Priority", in_node, ref out_node) == false)
                                {
                                    return false;
                                }
                            }
                            else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                            {
                                MPCR.SetInMsg(in_node);
                                in_node.ProcStep = '2';
                                in_node.AddString("GROUP_ID", Name);
                                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_SUB_RESOURCE_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);

                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TOOL_TYPE);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_PORT_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TAG_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }

                                if (MPCR.CallService("FMB", "FMB_UDR_Priority", in_node, ref out_node) == false)
                                {
                                    return false;
                                }
                            }

                            return true;
                        }
                    }
                }

                return false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.Format_SendToBack()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        #endregion

        #region " Functions Implementations"

        public void DebugWrite(udcCtrlBase ctrl)
        {

            Debug.WriteLine(ctrl.Name + " : IsHot - " + ctrl.IsHot + ", IsSelected - " + ctrl.IsSelected + ", IsFocused - " + ctrl.IsFocused);
            int i;
            for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
            {
                Debug.WriteLine("[" + i + "]" + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name + " : IsHot - " + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsHot + ", IsSelected - " + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsSelected + ", IsFocused - " + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).IsFocused);
            }

        }
        public bool RefreshControlEvent(Control.ControlCollection CtrlCollection, ref FMBUI.clsCtrlStatus ResourceStatus, int iStep)
        {

            try
            {
                IAsyncResult r = BeginInvoke(_RefreshControlDelegate, new object[] { CtrlCollection, ResourceStatus, iStep });
                bool bReturn = (bool)EndInvoke(r);

                return bReturn;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RefreshControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }
        // RefreshControl()
        //       - Refresh Control Status
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal ResourceStatus As clsCtrlStatus : Control to refresh
        //
        private static bool RefreshControl(Control.ControlCollection CtrlCollection, ref FMBUI.clsCtrlStatus ResourceStatus, int iStep)
        {

            try
            {
                udcCtrlBase ctrl = null;

                if (ResourceStatus.ToolType == Enums.eToolType.Port)
                {
                    ctrl = FMBCF.GetControl(CtrlCollection, ResourceStatus.Key, ResourceStatus.MotherResourceID, ResourceStatus.ToolType);
                }
                else
                {
                    ctrl = FMBCF.GetControl(CtrlCollection, ResourceStatus.Key, ResourceStatus.ToolType);
                }

                if (ctrl == null)
                {
                    return false;
                }

                if (ResourceStatus.IsDeleteRes == true)
                {
                    CtrlCollection.Remove(ctrl);
                    return true;
                }

                ctrl.IsRefreshed = true;

                //hkyung 
                //if (ResourceStatus.ToolType == Enums.eToolType.Resource || ResourceStatus.ToolType == Enums.eToolType.SubResource)
                //{
                //    ((udcCtrlBase)ctrl).CtrlStatus.BackColor = ResourceStatus.BackColor;
                //}
                ctrl.SetCtrlStatusData(ResourceStatus, iStep, false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RefreshControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ChangeMyMenus()
        //       - Change Language of Menu
        // Return Value
        //       -
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
                MPCF.ShowMsgBox("frmFMBDesign.ChangeMyMenus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // ViewLayout()
        //       - View Layout
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool ViewLayout()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_View_LayOut_In");
                TRSNode out_node = new TRSNode("FMB_View_LayOut_Out");

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '1';
                    in_node.Factory = FMBCF.GetStringBySeperator(Name, ":", 1);

                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));

                    if (MPCR.CallService("FMB", "FMB_View_LayOut", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                    DesignSize = new Size(out_node.GetInt("WIDTH") + 20, out_node.GetInt("HEIGHT") + 20);
                    OriginalDesignSize = DesignSize;

                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '1';
                    in_node.AddString("GROUP_ID", Name);

                    if (MPCR.CallService("FMB", "FMB_View_UDR_Group", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    DesignSize = new Size(out_node.GetInt("WIDTH") + 20, out_node.GetInt("HEIGHT") + 20);
                    OriginalDesignSize = DesignSize;
                }
                else
                {
                    MPCF.ShowMsgBox("ViewLayout() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                    return false;
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.ViewLayout()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewResourceListDetail()
        //       - View Resource/Tag List Detail
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool ViewResourceListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_View_Resource_List_In");
                TRSNode out_node;
                int i;
                ArrayList a_list = new ArrayList();
                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');
                    in_node.AddChar("INCLUDE_DEL_RES", ' ');
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);


                    do
                    {
                        out_node = new TRSNode("FMB_View_Resource_List_Out");
                        if (MPCR.CallService("FMB", "FMB_View_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }

                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                    foreach (object obj in a_list)
                    {
                        out_node = null;
                        out_node = (TRSNode)obj;

                        for (i = 0; i < out_node.GetList(0).Count; i++)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                            ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                            ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                            ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_TAG_FLAG"));
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                            {
                                ResourceStatus.TextStyle = -1;
                            }
                            else
                            {
                                ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                            }
                            ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                            ResourceStatus.ToolType = (Enums.eToolType)out_node.GetList(0)[i].GetInt("TAG_TYPE");
                            if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                            {
                                ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                                ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PRI_STS"));
                                ResourceStatus.ProcMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE"));
                                ResourceStatus.CtrlMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE"));
                                ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG"));
                                ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE"));
                                ResourceStatus.AreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID"));
                                ResourceStatus.SubAreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID"));
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                                {
                                    ResourceStatus.IsProcessMode = true;
                                }
                                else
                                {
                                    ResourceStatus.IsProcessMode = false;
                                }
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                                {
                                    ResourceStatus.IsUseEventColor = true;
                                    if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                    }
                                    else
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                    }
                                }
                                else
                                {
                                    ResourceStatus.IsUseEventColor = false;
                                }
                                ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                                ResourceStatus.ResShape = out_node.GetList(0)[i].GetChar("RES_SHAPE");
                                if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                                {
                                    ResourceStatus.IsViewSignal = true;
                                    ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                                }
                                else
                                {
                                    ResourceStatus.IsViewSignal = false;
                                }
                                ResourceStatus.WIPRate = out_node.GetList(0)[i].GetDouble("WIP_RATE");

                            }
                            else
                            {
                                if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                                {
                                    ResourceStatus.IsNoEvent = true;
                                }
                                else
                                {
                                    ResourceStatus.IsNoEvent = false;
                                }
                            }
                            ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                            ctrlArray.Add(ResourceStatus);
                            //if (AddControl(ResourceStatus, false, false) == false)
                            //{
                            //    return false;
                            //}
                        }
                    }

                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;
                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);


                    do
                    {
                        out_node = new TRSNode("FMB_View_Resource_List_Out");
                        if (MPCR.CallService("FMB", "FMB_View_UDR_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }

                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                    foreach (object obj in a_list)
                    {
                        out_node = null;
                        out_node = (TRSNode)obj;

                        for (i = 0; i < out_node.GetList(0).Count; i++)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                            ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                            ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                            ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_TAG_FLAG"));
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                            {
                                ResourceStatus.TextStyle = -1;
                            }
                            else
                            {
                                ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                            }
                            ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                            ResourceStatus.ToolType = (Enums.eToolType)out_node.GetList(0)[i].GetInt("TAG_TYPE");
                            if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                            {
                                ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                                ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PRI_STS"));
                                ResourceStatus.ProcMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE"));
                                ResourceStatus.CtrlMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE"));
                                ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG"));
                                ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE"));
                                ResourceStatus.AreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID"));
                                ResourceStatus.SubAreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID"));
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                                {
                                    ResourceStatus.IsProcessMode = true;
                                }
                                else
                                {
                                    ResourceStatus.IsProcessMode = false;
                                }
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                                {
                                    ResourceStatus.IsUseEventColor = true;
                                    if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                    }
                                    else
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                    }
                                }
                                else
                                {
                                    ResourceStatus.IsUseEventColor = false;
                                }
                                ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                                ResourceStatus.ResShape = out_node.GetList(0)[i].GetChar("RES_SHAPE");
                                if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                                {
                                    ResourceStatus.IsViewSignal = true;
                                    ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                                }
                                else
                                {
                                    ResourceStatus.IsViewSignal = false;
                                }
                                ResourceStatus.WIPRate = out_node.GetList(0)[i].GetDouble("WIP_RATE");
                            }
                            else
                            {
                                if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                                {
                                    ResourceStatus.IsNoEvent = true;
                                }
                                else
                                {
                                    ResourceStatus.IsNoEvent = false;
                                }
                            }
                            ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                            ctrlArray.Add(ResourceStatus);
                            //if (AddControl(ResourceStatus, false, false) == false)
                            //{
                            //    return false;
                            //}
                        }
                    }

                }
                else
                {
                    MPCF.ShowMsgBox("ViewResourceListDetail() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                    return false;
                }

                this.pnlFMBDesign.ResumeLayout(false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.ViewResourceListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        private void SortControls()
        {
            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
            CtrlSeqSort ctrlSort = new CtrlSeqSort();
            ctrlArray.Sort(ctrlSort);

            int i;
            for (i = 0; i < ctrlArray.Count; i++)
            {
                ResourceStatus = (clsCtrlStatus)ctrlArray[i];
                if (AddControl(ResourceStatus, false, false) == false)
                {
                    return;
                }
            }
            ctrlArray.Clear();
        }
        public bool ViewToolListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_TOOL_LIST_IN_DETAIL");
                TRSNode out_node = new TRSNode("FMB_VIEW_TOOL_LIST_OUT_DETAIL");
                ArrayList a_list = new ArrayList();
                int i;
                //string sKey = "";
                //string sText = "";
                //Point ptLocation;
                //Size szRegion;
                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');
                    in_node.AddChar("INCLUDE_DEL_RES", ' ');
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_Tool_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));

                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_UDR_Tool_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else
                {
                    MPCF.ShowMsgBox("ViewToolDetail() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                    return false;
                }
                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                        ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_ID"));
                        ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                        ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                        ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                        ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                        ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                        ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                        ResourceStatus.MotherResourceID = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                        {
                            ResourceStatus.TextStyle = -1;
                        }
                        else
                        {
                            ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                        }
                        ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                        ResourceStatus.ToolType = Enums.eToolType.Tool;
                        if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                        {
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_TOOL_EVENT_ID"));
                            ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_STATUS"));
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_TOOL_EVENT_ID"));
                            ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("TOOL_UP_DOWN_FLAG"));
                            ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_TYPE"));
                            ResourceStatus.AreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID"));
                            ResourceStatus.SubAreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID"));
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                }
                                else
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                }
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                            if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                            {
                                ResourceStatus.IsViewSignal = true;
                                ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                            }
                            else
                            {
                                ResourceStatus.IsViewSignal = false;
                            }
                        }
                        else
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                            {
                                ResourceStatus.IsNoEvent = true;
                            }
                            else
                            {
                                ResourceStatus.IsNoEvent = false;
                            }
                        }
                        ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                        ctrlArray.Add(ResourceStatus);
                        //if (AddControl(ResourceStatus, false, false) == false)
                        //{
                        //    return false;
                        //}
                    }
                }
                this.pnlFMBDesign.ResumeLayout(false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.ViewToolListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool ViewSubResourceListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_SUB_RESOURCE_LIST_IN_DETAIL");
                TRSNode out_node = new TRSNode("FMB_VIEW_SUB_RESOURCE_LIST_OUT_DETAIL");
                ArrayList a_list = new ArrayList();
                int i;
                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();


                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');
                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_Sub_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);
                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {

                        if (MPCR.CallService("FMB", "FMB_View_UDR_Sub_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }

                else
                {
                    MPCF.ShowMsgBox("ViewSubResourceListDetail() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                    return false;
                }

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                        ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_ID"));
                        ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                        ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                        ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                        ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                        ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                        ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                        ResourceStatus.MotherResourceID = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                        //ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetString("res_tag_flag);
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                        {
                            ResourceStatus.TextStyle = -1;
                        }
                        else
                        {
                            ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                        }
                        ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                        ResourceStatus.ToolType = Enums.eToolType.SubResource;
                        if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                        {
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                            ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_PRI_STS"));
                            ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("SUB_UP_DOWN_FLAG"));
                            ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_TYPE"));
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                }
                                else
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                }
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                            if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                            {
                                ResourceStatus.IsViewSignal = true;
                                ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                            }
                            else
                            {
                                ResourceStatus.IsViewSignal = false;
                            }
                        }
                        else
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                            {
                                ResourceStatus.IsNoEvent = true;
                            }
                            else
                            {
                                ResourceStatus.IsNoEvent = false;
                            }
                        }
                        ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                        ctrlArray.Add(ResourceStatus);
                        //if (AddControl(ResourceStatus, false, false) == false)
                        //{
                        //    return false;
                        //}
                    }
                }
                this.pnlFMBDesign.ResumeLayout(false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.ViewSubResourceListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public bool ViewPortListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_PORT_LIST_IN_DETAIL");
                TRSNode out_node = new TRSNode("FMB_VIEW_PORT_LIST_OUT_DETAIL");
                ArrayList a_list = new ArrayList();

                int i;
                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');
                    in_node.AddChar("INCLUDE_DEL_RES", ' ');
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);


                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_Port_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);


                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_UDR_Port_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }

                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else
                {
                    MPCF.ShowMsgBox("ViewPortListDetail() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                    return false;
                }

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                        ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("PORT_ID"));
                        ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                        ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                        ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                        ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                        ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                        ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                        ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("PORT_STATUS"));
                        ResourceStatus.MotherResourceID = out_node.GetList(0)[i].GetString("RES_ID");
                        //ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetString("res_tag_flag);
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                        {
                            ResourceStatus.TextStyle = -1;
                        }
                        else
                        {
                            ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                        }
                        ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                        ResourceStatus.ToolType = Enums.eToolType.Port;
                        if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                        {
                            ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetChar("PORT_TYPE"));

                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                            if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                            {
                                ResourceStatus.IsViewSignal = true;
                                ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                            }
                            else
                            {
                                ResourceStatus.IsViewSignal = false;
                            }
                        }
                        else
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                            {
                                ResourceStatus.IsNoEvent = true;
                            }
                            else
                            {
                                ResourceStatus.IsNoEvent = false;
                            }
                        }
                        ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                        ctrlArray.Add(ResourceStatus);
                        //if (AddControl(ResourceStatus, false, false) == false)
                        //{
                        //    return false;
                        //}
                    }
                }
                this.pnlFMBDesign.ResumeLayout(false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.ViewPortListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // RefreshResourceListDetail()
        //       - Refresh Resource/Tag List Detail
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool RefreshResourceListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_View_Resource_List_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();
                int i;

                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();
                ctrlArray.Clear();

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');
                    in_node.AddChar("INCLUDE_DEL_RES", ' ');
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        out_node = new TRSNode("FMB_View_Resource_List_Out");
                        if (MPCR.CallService("FMB", "FMB_View_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                    foreach (object obj in a_list)
                    {
                        out_node = null;
                        out_node = (TRSNode)obj;

                        for (i = 0; i < out_node.GetList(0).Count; i++)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                            ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                            ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                            ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_TAG_FLAG"));
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                            {
                                ResourceStatus.TextStyle = -1;
                            }
                            else
                            {
                                ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                            }
                            ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                            ResourceStatus.ToolType = (Enums.eToolType)out_node.GetList(0)[i].GetInt("TAG_TYPE");
                            if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                            {
                                ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                                ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PRI_STS"));
                                ResourceStatus.ProcMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE"));
                                ResourceStatus.CtrlMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE"));
                                ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG"));
                                ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE"));
                                ResourceStatus.AreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID"));
                                ResourceStatus.SubAreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID"));
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                                {
                                    ResourceStatus.IsProcessMode = true;
                                }
                                else
                                {
                                    ResourceStatus.IsProcessMode = false;
                                }
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                                {
                                    ResourceStatus.IsUseEventColor = true;
                                    if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                    }
                                    else
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                    }
                                }
                                else
                                {
                                    ResourceStatus.IsUseEventColor = false;
                                }
                                ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                                ResourceStatus.ResShape = out_node.GetList(0)[i].GetChar("RES_SHAPE");
                                if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                                {
                                    ResourceStatus.IsViewSignal = true;
                                    ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                                }
                                else
                                {
                                    ResourceStatus.IsViewSignal = false;
                                }
                                ResourceStatus.WIPRate = out_node.GetList(0)[i].GetDouble("WIP_RATE");
                            }
                            else
                            {
                                if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                                {
                                    ResourceStatus.IsNoEvent = true;
                                }
                                else
                                {
                                    ResourceStatus.IsNoEvent = false;
                                }
                            }
                            if (RefreshControl(this.pnlFMBDesign.Controls, ref ResourceStatus, 1) == false)
                            {
                                ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                                ctrlArray.Add(ResourceStatus);
                                //if (AddControl(ResourceStatus, false, true) == false)
                                //{
                                //    return false;
                                //}
                            }
                        }
                    }
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;
                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {

                        out_node = new TRSNode("FMB_View_Resource_List_Out");
                        if (MPCR.CallService("FMB", "FMB_View_UDR_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                    foreach (object obj in a_list)
                    {
                        out_node = null;
                        out_node = (TRSNode)obj;

                        for (i = 0; i < out_node.GetList(0).Count; i++)
                        {
                            clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                            ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                            ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                            ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                            ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                            ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                            ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                            ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                            ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_TAG_FLAG"));
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                            {
                                ResourceStatus.TextStyle = -1;
                            }
                            else
                            {
                                ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                            }
                            ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                            ResourceStatus.ToolType = (Enums.eToolType)out_node.GetList(0)[i].GetInt("TAG_TYPE");
                            if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                            {
                                ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                                ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PRI_STS"));
                                ResourceStatus.ProcMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE"));
                                ResourceStatus.CtrlMode = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE"));
                                ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG"));
                                ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE"));
                                ResourceStatus.AreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID"));
                                ResourceStatus.SubAreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID"));
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                                {
                                    ResourceStatus.IsProcessMode = true;
                                }
                                else
                                {
                                    ResourceStatus.IsProcessMode = false;
                                }
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                                {
                                    ResourceStatus.IsUseEventColor = true;
                                    if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                    }
                                    else
                                    {
                                        ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                    }
                                }
                                else
                                {
                                    ResourceStatus.IsUseEventColor = false;
                                }
                                ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                                ResourceStatus.ResShape = out_node.GetList(0)[i].GetChar("RES_SHAPE");
                                if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                                {
                                    ResourceStatus.IsViewSignal = true;
                                    ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                                }
                                else
                                {
                                    ResourceStatus.IsViewSignal = false;
                                }
                                ResourceStatus.WIPRate = out_node.GetList(0)[i].GetDouble("WIP_RATE");
                            }
                            else
                            {
                                if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                                {
                                    ResourceStatus.IsNoEvent = true;
                                }
                                else
                                {
                                    ResourceStatus.IsNoEvent = false;
                                }
                            }
                            if (RefreshControl(this.pnlFMBDesign.Controls, ref ResourceStatus, 1) == false)
                            {
                                ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                                ctrlArray.Add(ResourceStatus);
                                //if (AddControl(ResourceStatus, false, true) == false)
                                //{
                                //    return false;
                                //}
                            }
                        }
                    }

                }
                else
                {
                    MPCF.ShowMsgBox("RefreshResourceListDetail() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                    return false;
                }
                if (RefreshSubResourceListDetail() == false)
                {
                    return false;
                }

                if (RefreshToolListDetail() == false)
                {
                    return false;
                }

                if (RefreshPortListDetail() == false)
                {
                    return false;
                }
                RefreshDeleteControls();

                SortControls();

                SetRefreshedControl(false);

                this.pnlFMBDesign.ResumeLayout(false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RefreshResourceListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // RefreshSubResourceListDetail()
        //       - Refresh SubResource/Tag List Detail
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool RefreshSubResourceListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_SUB_RESOURCE_LIST_IN_DETAIL");
                TRSNode out_node = new TRSNode("FMB_VIEW_SUB_RESOURCE_LIST_OUT_DETAIL");
                ArrayList a_list = new ArrayList();
                int i;
                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();


                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');
                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_Sub_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);
                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {

                        if (MPCR.CallService("FMB", "FMB_View_UDR_Sub_Resource_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else
                {
                    MPCF.ShowMsgBox("RefreshSubResourceListDetail() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                    return false;
                }
                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                        ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_ID"));
                        ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                        ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                        ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                        ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                        ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                        ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                        ResourceStatus.MotherResourceID = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                        //ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetString("res_tag_flag);
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                        {
                            ResourceStatus.TextStyle = -1;
                        }
                        else
                        {
                            ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                        }
                        ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                        ResourceStatus.ToolType = Enums.eToolType.SubResource;
                        if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                        {
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                            ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_PRI_STS"));
                            ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("SUB_UP_DOWN_FLAG"));
                            ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("SUBRES_TYPE"));
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID"));
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                }
                                else
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                }
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                            if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                            {
                                ResourceStatus.IsViewSignal = true;
                                ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                            }
                            else
                            {
                                ResourceStatus.IsViewSignal = false;
                            }
                        }
                        else
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                            {
                                ResourceStatus.IsNoEvent = true;
                            }
                            else
                            {
                                ResourceStatus.IsNoEvent = false;
                            }
                        }
                        if (RefreshControl(this.pnlFMBDesign.Controls, ref ResourceStatus, 1) == false)
                        {
                            ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                            ctrlArray.Add(ResourceStatus);
                            //if (AddControl(ResourceStatus, false, false) == false)
                            //{
                            //    return false;
                            //}
                        }
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RefreshSubResourceListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // RefreshToolListDetail()
        //       - Refresh SubResource/Tag List Detail
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool RefreshToolListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_TOOL_LIST_IN_DETAIL");
                TRSNode out_node = new TRSNode("FMB_VIEW_TOOL_LIST_OUT_DETAIL");
                ArrayList a_list = new ArrayList();
                int i;
                //string sKey = "";
                //string sText = "";
                //Point ptLocation;
                //Size szRegion;
                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');
                    in_node.AddChar("INCLUDE_DEL_RES", ' ');
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_Tool_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);
                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));

                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_UDR_Tool_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);
                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else
                {
                    MPCF.ShowMsgBox("RefreshSubToolListDetail() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                    return false;
                }
                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                        ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_ID"));
                        ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                        ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                        ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                        ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                        ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                        ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                        ResourceStatus.MotherResourceID = MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID"));
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                        {
                            ResourceStatus.TextStyle = -1;
                        }
                        else
                        {
                            ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                        }
                        ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                        ResourceStatus.ToolType = Enums.eToolType.Tool;
                        if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                        {
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_TOOL_EVENT_ID"));
                            ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_STATUS"));
                            ResourceStatus.LastEvent = MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_TOOL_EVENT_ID"));
                            ResourceStatus.UpDownFlag = MPCF.Trim(out_node.GetList(0)[i].GetChar("TOOL_UP_DOWN_FLAG"));
                            ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetString("TOOL_TYPE"));
                            ResourceStatus.AreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("AREA_ID"));
                            ResourceStatus.SubAreaID = MPCF.Trim(out_node.GetList(0)[i].GetString("SUB_AREA_ID"));
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                                }
                                else
                                {
                                    ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                                }
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                            if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                            {
                                ResourceStatus.IsViewSignal = true;
                                ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                            }
                            else
                            {
                                ResourceStatus.IsViewSignal = false;
                            }
                        }
                        else
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                            {
                                ResourceStatus.IsNoEvent = true;
                            }
                            else
                            {
                                ResourceStatus.IsNoEvent = false;
                            }
                        }
                        if (RefreshControl(this.pnlFMBDesign.Controls, ref ResourceStatus, 1) == false)
                        {
                            ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                            ctrlArray.Add(ResourceStatus);
                            //if (AddControl(ResourceStatus, false, false) == false)
                            //{
                            //    return false;
                            //}
                        }
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RefreshSubToolListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }


        // RefreshSubResourceListDetail()
        //       - Refresh SubResource/Tag List Detail
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool RefreshPortListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_VIEW_PORT_LIST_IN_DETAIL");
                TRSNode out_node = new TRSNode("FMB_VIEW_PORT_LIST_OUT_DETAIL");
                ArrayList a_list = new ArrayList();

                int i;
                string sFactory = "";

                this.pnlFMBDesign.SuspendLayout();

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');
                    in_node.AddChar("INCLUDE_DEL_RES", ' ');
                    in_node.AddChar("INCLUDE_PROC_LOT_INFO", ' ');

                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);


                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_Port_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);


                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.Factory = sFactory;

                    in_node.AddChar("RES_TYPE", ' ');

                    in_node.AddString("GROUP_ID", Name);
                    in_node.AddInt("NEXT_SEQ", int.MaxValue);

                    do
                    {
                        if (MPCR.CallService("FMB", "FMB_View_UDR_Port_List_Detail", in_node, ref out_node) == false)
                        {
                            return false;
                        }

                        a_list.Add(out_node);

                        in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));
                    } while (in_node.GetInt("NEXT_SEQ") != 0);

                }
                else
                {
                    MPCF.ShowMsgBox("RefreshPortListDetail() Failed.", "FMB Client", MessageBoxButtons.OK, 1);
                    return false;
                }
                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                        ResourceStatus.Key = MPCF.Trim(out_node.GetList(0)[i].GetString("PORT_ID"));
                        ResourceStatus.SetLocation(new Point(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_X")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_Y"))));
                        ResourceStatus.SetSize(new Size(MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_WIDTH")), MPCF.ToInt(out_node.GetList(0)[i].GetInt("LOC_HEIGHT"))));
                        ResourceStatus.Text = MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT"));
                        ResourceStatus.TextColor = out_node.GetList(0)[i].GetInt("TEXT_COLOR");
                        ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                        ResourceStatus.TextSize = out_node.GetList(0)[i].GetInt("TEXT_SIZE");
                        ResourceStatus.PrimaryStatus = MPCF.Trim(out_node.GetList(0)[i].GetString("PORT_STATUS"));
                        ResourceStatus.MotherResourceID = out_node.GetList(0)[i].GetString("RES_ID");
                        //ResourceStatus.ResTagFlag = MPCF.Trim(out_node.GetList(0)[i].GetString("res_tag_flag);
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) == "")
                        {
                            ResourceStatus.TextStyle = -1;
                        }
                        else
                        {
                            ResourceStatus.TextStyle = out_node.GetList(0)[i].GetChar("TEXT_STYLE") - '0';
                        }
                        ResourceStatus.BackColor = out_node.GetList(0)[i].GetInt("BACK_COLOR");
                        ResourceStatus.ToolType = Enums.eToolType.Port;
                        if (ResourceStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                        {
                            ResourceStatus.ResourceType = MPCF.Trim(out_node.GetList(0)[i].GetChar("PORT_TYPE"));

                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                            {
                                ResourceStatus.IsProcessMode = true;
                            }
                            else
                            {
                                ResourceStatus.IsProcessMode = false;
                            }
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                            {
                                ResourceStatus.IsUseEventColor = true;
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                            }
                            else
                            {
                                ResourceStatus.IsUseEventColor = false;
                            }
                            ResourceStatus.ImageIndex = out_node.GetList(0)[i].GetInt("IMAGE_IDX");
                            if (MPCF.ToInt(out_node.GetList(0)[i].GetChar("SIGNAL_FLAG")) > 0)
                            {
                                ResourceStatus.IsViewSignal = true;
                                ResourceStatus.SignalPosition = out_node.GetList(0)[i].GetChar("SIGNAL_FLAG");
                            }
                            else
                            {
                                ResourceStatus.IsViewSignal = false;
                            }
                        }
                        else
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NO_MOUSE_EVENT")) == "Y")
                            {
                                ResourceStatus.IsNoEvent = true;
                            }
                            else
                            {
                                ResourceStatus.IsNoEvent = false;
                            }
                        }
                        if (RefreshControl(this.pnlFMBDesign.Controls, ref ResourceStatus, 1) == false)
                        {
                            ResourceStatus.Seq = out_node.GetList(0)[i].GetInt("SEQ");
                            ctrlArray.Add(ResourceStatus);
                            //if (AddControl(ResourceStatus, false, false) == false)
                            //{
                            //    return false;
                            //}
                        }
                    }
                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RefreshPortListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }
        // UpdateResourceListDetail()
        //       - Update Resource/Tag List Detail
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool UpdateResourceListDetail()
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_Update_ResLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                Control ctrl;

                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {

                    foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                    {
                        ctrl = tempLoopVar_ctrl;
                        if (ctrl is udcCtrlBase)
                        {
                            if (((udcCtrlBase)ctrl).CtrlStatus.IsSaveFlag == true)
                            {
                                in_node.Init();
                                MPCR.SetInMsg(in_node);
                                in_node.ProcStep = modGlobalConstant.MP_STEP_UPDATE;
                                in_node.Factory = FMBCF.GetStringBySeperator(Name, ":", 1);

                                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).GetMotherResourceID());
                                    in_node.AddString("TOOL_ID", ((udcCtrlBase)ctrl).Name);
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TOOL_TYPE);
                                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                                    in_node.AddInt("LOC_WIDTH", ((udcCtrlBase)ctrl).GetSize().Width);
                                    in_node.AddInt("LOC_HEIGHT", ((udcCtrlBase)ctrl).GetSize().Height);
                                    in_node.AddInt("LOC_X", ((udcCtrlBase)ctrl).GetLocation().X);
                                    in_node.AddInt("LOC_Y", ((udcCtrlBase)ctrl).GetLocation().Y);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID);
                                    in_node.AddString("PORT_ID", MPCF.Trim(((udcCtrlBase)ctrl).Name));
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_PORT_TYPE);
                                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                                    in_node.AddInt("LOC_WIDTH", ((udcCtrlBase)ctrl).GetSize().Width);
                                    in_node.AddInt("LOC_HEIGHT", ((udcCtrlBase)ctrl).GetSize().Height);
                                    in_node.AddInt("LOC_X", ((udcCtrlBase)ctrl).GetLocation().X);
                                    in_node.AddInt("LOC_Y", ((udcCtrlBase)ctrl).GetLocation().Y);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).GetMotherResourceID());
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_SUB_RESOURCE_TYPE);
                                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                                    in_node.AddInt("LOC_WIDTH", ((udcCtrlBase)ctrl).GetSize().Width);
                                    in_node.AddInt("LOC_HEIGHT", ((udcCtrlBase)ctrl).GetSize().Height);
                                    in_node.AddInt("LOC_X", ((udcCtrlBase)ctrl).GetLocation().X);
                                    in_node.AddInt("LOC_Y", ((udcCtrlBase)ctrl).GetLocation().Y);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_RESOURCE_TYPE);
                                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                                    in_node.AddInt("LOC_WIDTH", ((udcCtrlBase)ctrl).GetSize().Width);
                                    in_node.AddInt("LOC_HEIGHT", ((udcCtrlBase)ctrl).GetSize().Height);
                                    in_node.AddInt("LOC_X", ((udcCtrlBase)ctrl).GetLocation().X);
                                    in_node.AddInt("LOC_Y", ((udcCtrlBase)ctrl).GetLocation().Y);
                                }
                                else
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TAG_TYPE);
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                    in_node.AddString("LAYOUT_ID", FMBCF.GetStringBySeperator(Name, ":", 2));
                                    in_node.AddInt("LOC_WIDTH", ((udcCtrlBase)ctrl).GetSize().Width);
                                    in_node.AddInt("LOC_HEIGHT", ((udcCtrlBase)ctrl).GetSize().Height);
                                    in_node.AddInt("LOC_X", ((udcCtrlBase)ctrl).GetLocation().X);
                                    in_node.AddInt("LOC_Y", ((udcCtrlBase)ctrl).GetLocation().Y);
                                }
                                in_node.AddInt("TAG_TYPE", MPCF.ToInt(((udcCtrlBase)ctrl).CtrlStatus.ToolType));
                                in_node.AddString("TEXT", ((udcCtrlBase)ctrl).CtrlStatus.Text);
                                in_node.AddInt("TEXT_COLOR", ((udcCtrlBase)ctrl).CtrlStatus.TextColor);
                                in_node.AddInt("TEXT_SIZE", ((udcCtrlBase)ctrl).CtrlStatus.TextSize);

                                if (((udcCtrlBase)ctrl).CtrlStatus.TextStyle == -1)
                                {
                                    in_node.AddChar("TEXT_STYLE", '0');
                                }
                                else
                                {
                                    in_node.AddChar("TEXT_STYLE", (char)(((udcCtrlBase)ctrl).CtrlStatus.TextStyle + '0'));
                                }
                                in_node.AddInt("BACK_COLOR", ((udcCtrlBase)ctrl).CtrlStatus.BackColor);
                                if (((udcCtrlBase)ctrl).CtrlStatus.IsNoEvent == true)
                                {
                                    in_node.AddChar("NO_MOUSE_EVENT", 'Y');
                                }
                                else
                                {
                                    in_node.AddChar("NO_MOUSE_EVENT", ' ');
                                }
                                if (((udcCtrlBase)ctrl).CtrlStatus.IsViewSignal == true)
                                {
                                    in_node.AddChar("SIGNAL_FLAG", ((udcCtrlBase)ctrl).CtrlStatus.SignalPosition);
                                }
                                else
                                {
                                    in_node.AddChar("SIGNAL_FLAG", ' ');
                                }
                                in_node.AddChar("RES_SHAPE", ((udcCtrlBase)ctrl).CtrlStatus.ResShape);
                                if (MPCR.CallService("FMB", "FMB_Update_Resource_Location", in_node, ref out_node) == false)
                                {
                                    return false;
                                }
                                ((udcCtrlBase)ctrl).CtrlStatus.IsSaveFlag = false;

                            }
                        }
                    }

                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {

                    foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                    {
                        ctrl = tempLoopVar_ctrl;
                        if (ctrl is udcCtrlBase)
                        {
                            if (((udcCtrlBase)ctrl).CtrlStatus.IsSaveFlag == true)
                            {
                                in_node.Init();
                                MPCR.SetInMsg(in_node);
                                in_node.ProcStep = modGlobalConstant.MP_STEP_UPDATE;
                                in_node.AddString("GROUP_ID", Name);
                                in_node.AddInt("LOC_WIDTH", ((udcCtrlBase)ctrl).GetSize().Width);
                                in_node.AddInt("LOC_HEIGHT", ((udcCtrlBase)ctrl).GetSize().Height);
                                in_node.AddInt("LOC_X", ((udcCtrlBase)ctrl).GetLocation().X);
                                in_node.AddInt("LOC_Y", ((udcCtrlBase)ctrl).GetLocation().Y);
                                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).GetMotherResourceID());
                                    in_node.AddString("TOOL_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).GetMotherResourceID());
                                    in_node.AddString("PORT_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).GetMotherResourceID());
                                    in_node.AddString("SUBRES_ID", ((udcCtrlBase)ctrl).Name);
                                }
                                else
                                {
                                    in_node.AddString("RES_ID", ((udcCtrlBase)ctrl).Name);
                                }

                                if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_RESOURCE_TYPE);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_SUB_RESOURCE_TYPE);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_PORT_TYPE);
                                }
                                else if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TOOL_TYPE);
                                }
                                else
                                {
                                    in_node.AddChar("RES_TYPE", modGlobalConstant.FMB_TAG_TYPE);
                                }


                                in_node.AddInt("TAG_TYPE", MPCF.ToInt(((udcCtrlBase)ctrl).CtrlStatus.ToolType));
                                in_node.AddString("TEXT", ((udcCtrlBase)ctrl).CtrlStatus.Text);
                                in_node.AddInt("TEXT_COLOR", ((udcCtrlBase)ctrl).CtrlStatus.TextColor);
                                in_node.AddInt("TEXT_SIZE", ((udcCtrlBase)ctrl).CtrlStatus.TextSize);

                                if (((udcCtrlBase)ctrl).CtrlStatus.TextStyle == -1)
                                {
                                    in_node.AddChar("TEXT_STYLE", ' ');
                                }
                                else
                                {
                                    in_node.AddChar("TEXT_STYLE", (char)(((udcCtrlBase)ctrl).CtrlStatus.TextStyle + '0'));
                                }
                                in_node.AddInt("BACK_COLOR", ((udcCtrlBase)ctrl).CtrlStatus.BackColor);
                                if (((udcCtrlBase)ctrl).CtrlStatus.IsNoEvent == true)
                                {
                                    in_node.AddChar("NO_MOUSE_EVENT", 'Y');
                                }
                                else
                                {
                                    in_node.AddChar("NO_MOUSE_EVENT", ' ');
                                }
                                if (((udcCtrlBase)ctrl).CtrlStatus.IsViewSignal == true)
                                {
                                    in_node.AddChar("SIGNAL_FLAG", ((udcCtrlBase)ctrl).CtrlStatus.SignalPosition);
                                }
                                else
                                {
                                    in_node.AddChar("SIGNAL_FLAG", ' ');
                                }
                                in_node.AddChar("RES_SHAPE", ((udcCtrlBase)ctrl).CtrlStatus.ResShape);
                                if (MPCR.CallService("FMB", "FMB_Update_UDR_ResLoc", in_node, ref out_node) == false)
                                {
                                    return false;
                                }

                                ((udcCtrlBase)ctrl).CtrlStatus.IsSaveFlag = false;

                            }
                        }
                    }

                }
                else
                {
                    MPCF.ShowMsgBox("UpdateResourceList() Failed.", Application.ProductName, MessageBoxButtons.OK, 1);
                    return false;
                }

                MPCR.ShowSuccessMsg(out_node);
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.UpdateResourceListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // AddControl()
        //       - Add Control to panel
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal ResourceStatus As clsCtrlStatus : Control to add
        //
        public bool AddControl(clsCtrlStatus ResourceStatus, bool bCreate, bool bRefresh)
        {

            try
            {
                this.pnlFMBDesign.SuspendLayout();

                udcCtrlTag ctrlTag;
                switch (ResourceStatus.ToolType)
                {
                    case Miracom.FMBUI.Enums.eToolType.Resource:

                        udcCtrlResource ctrlResource = new udcCtrlResource(modGlobalVariable.gimlResource);

                        MPCF.ToClientLanguage(ctrlResource.ContextMenu.MenuItems);
                        ctrlResource.SetCtrlStatusData(ResourceStatus, 1, true);

                        ctrlResource.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlResource.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlResource.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlResource.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlResource.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlResource.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlResource.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlResource.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlResource.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);

                        //ctrlResource.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlResource.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlResource.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlResource.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlResource.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlResource.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlResource.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlResource.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlResource.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlResource);
                        if (bCreate == true)
                        {
                            ctrlResource.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlResource.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;
                    case Miracom.FMBUI.Enums.eToolType.Rectangle:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);

                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.Ellipse:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.Triangle:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.VerticalLine:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.HorizontalLine:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.PieType1:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.PieType2:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.PieType3:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.PieType4:
                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;

                    case Miracom.FMBUI.Enums.eToolType.TextType:

                        //udcCtrlTag ctrlTag = new udcCtrlTag();
                        ctrlTag = new udcCtrlTag();
                        MPCF.ToClientLanguage(ctrlTag.ContextMenu.MenuItems);
                        ctrlTag.SetCtrlStatusData(ResourceStatus, 1, true);
                        //ctrlTag.CtrlMouseEnter += new System.EventHandler(CtrlBase_CtrlMouseEnter);
                        //ctrlTag.CtrlMouseLeave += new System.EventHandler(CtrlBase_CtrlMouseLeave);
                        //ctrlTag.CtrlMouseDown += new System.EventHandler(CtrlBase_CtrlMouseDown);
                        //ctrlTag.CtrlMouseUp += new System.EventHandler(CtrlBase_CtrlMouseUp);
                        //ctrlTag.CtrlMouseMove += new System.EventHandler(CtrlBase_CtrlMouseMove);
                        //ctrlTag.CtrlGotFocus += new System.EventHandler(CtrlBase_CtrlGotFocus);
                        //ctrlTag.CtrlLostFocus += new System.EventHandler(CtrlBase_CtrlLostFocus);
                        //ctrlTag.CtrlContextMenu += new System.EventHandler(CtrlBase_CtrlContextMenu);
                        //ctrlTag.CtrlKeyDown += new System.EventHandler(CtrlBase_CtrlKeyDown);
                        ctrlTag.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTag.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTag.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTag.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTag.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTag.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTag.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTag.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTag.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTag);
                        if (bCreate == true)
                        {
                            ctrlTag.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTag.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;
                    case Miracom.FMBUI.Enums.eToolType.SubResource:

                        udcCtrlSubResource ctrlSubResource = new udcCtrlSubResource(modGlobalVariable.gimlResource);

                        MPCF.ToClientLanguage(ctrlSubResource.ContextMenu.MenuItems);
                        ctrlSubResource.SetCtrlStatusData(ResourceStatus, 1, true);

                        ctrlSubResource.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlSubResource.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlSubResource.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlSubResource.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlSubResource.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlSubResource.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlSubResource.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlSubResource.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlSubResource.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlSubResource);
                        if (bCreate == true)
                        {
                            ctrlSubResource.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlSubResource.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;
                    case Miracom.FMBUI.Enums.eToolType.Port:

                        udcCtrlPort ctrlPort = new udcCtrlPort(modGlobalVariable.gimlResource);
                        MPCF.ToClientLanguage(ctrlPort.ContextMenu.MenuItems);
                        ctrlPort.SetCtrlStatusData(ResourceStatus, 1, true);

                        ctrlPort.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlPort.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlPort.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlPort.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlPort.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlPort.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlPort.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlPort.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlPort.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlPort);
                        if (bCreate == true)
                        {
                            ctrlPort.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlPort.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;
                    case Miracom.FMBUI.Enums.eToolType.Tool:

                        udcCtrlTool ctrlTool = new udcCtrlTool(modGlobalVariable.gimlResource);

                        MPCF.ToClientLanguage(ctrlTool.ContextMenu.MenuItems);
                        ctrlTool.SetCtrlStatusData(ResourceStatus, 1, true);
                        ctrlTool.CtrlMouseEnter += new CtrlMouseEnterEventHandler(CtrlBase_CtrlMouseEnter);
                        ctrlTool.CtrlMouseLeave += new CtrlMouseLeaveEventHandler(CtrlBase_CtrlMouseLeave);
                        ctrlTool.CtrlMouseDown += new CtrlMouseDownEventHandler(CtrlBase_CtrlMouseDown);
                        ctrlTool.CtrlMouseUp += new CtrlMouseUpEventHandler(CtrlBase_CtrlMouseUp);
                        ctrlTool.CtrlMouseMove += new CtrlMouseMoveEventHandler(CtrlBase_CtrlMouseMove);
                        ctrlTool.CtrlGotFocus += new CtrlGotFocusEventHandler(CtrlBase_CtrlGotFocus);
                        ctrlTool.CtrlLostFocus += new CtrlLostFocusEventHandler(CtrlBase_CtrlLostFocus);
                        ctrlTool.CtrlContextMenu += new CtrlContextMenuEventHandler(CtrlBase_CtrlContextMenu);
                        ctrlTool.CtrlKeyDown += new CtrlKeyDownEventHandler(CtrlBase_CtrlKeyDown);
                        pnlFMBDesign.Controls.Add(ctrlTool);
                        if (bCreate == true)
                        {
                            ctrlTool.BringToFront();
                        }
                        if (bRefresh == true)
                        {
                            ctrlTool.IsRefreshed = true;
                        }
                        modGlobalVariable.giToolType = MPCF.ToInt(Miracom.FMBUI.Enums.eToolType.Null);
                        break;
                    default:

                        if (pnlFMBDesign.Focus() == true)
                        {
                            pnlFMBDesign.SetFocus(null);
                        }
                        else
                        {
                            pnlFMBDesign.Select();
                        }
                        break;
                }

                this.pnlFMBDesign.ResumeLayout(false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.AddControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        //void ctrlResource_CtrlMouseEnter(object sender, EventArgs e)
        //{
        //    throw new Exception("The method or operation is not implemented.");
        //}

        // RedrawControls()
        //       - Redraw Controls
        // Return Value
        //       -
        // Arguments
        //        -
        //
        public void RedrawControls()
        {

            try
            {
                this.pnlFMBDesign.SuspendLayout();

                Control ctrl;
                foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        ((udcCtrlBase)ctrl).RedrawCtrl();
                    }
                }

                this.pnlFMBDesign.ResumeLayout(false);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RedrawControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // AddSelectedControls()
        //       - Add control to pnlFMBDesign.SelectedControls
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal ctrl As udcCtrlBase : Control to add
        //
        public bool AddSelectedControls(udcCtrlBase ctrl)
        {

            try
            {
                string sCtrlType;
                string sSelectedType;

                // Resource Type / Tag Type 정의
                if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                {
                    sCtrlType = "R:";
                }
                else if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                {
                    sCtrlType = "S:";
                }
                else if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                {
                    sCtrlType = "P:";
                }
                else if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                {
                    sCtrlType = "L:";
                }
                else
                {
                    sCtrlType = "T:";
                }

                for (int i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {
                    // Resource Type / Tag Type 인지 분기
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                    {
                        sSelectedType = "R:";
                    }
                    else if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                    {
                        sSelectedType = "S:";
                    }
                    else if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                    {
                        sSelectedType = "P:";
                    }
                    else if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                    {
                        sSelectedType = "L:";
                    }
                    else
                    {
                        sSelectedType = "T:";
                    }

                    // 현재 Add 하려는 Control이 있는 경우에는 Skip
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port || ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                    {
                        if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.MotherResourceID == ctrl.CtrlStatus.MotherResourceID)
                        {
                            if (FMBCF.ToAsc(sSelectedType + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name) == FMBCF.ToAsc(sCtrlType + ctrl.Name))
                            {
                                return true;
                            }
                        }
                    }
                    else
                    {
                        if (FMBCF.ToAsc(sSelectedType + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name) == FMBCF.ToAsc(sCtrlType + ctrl.Name))
                        {
                            return false;
                        }
                    }
                }

                //' 이미 다른 선택되어진 Control이 있을 경우에
                //' Add 하기전에 Focus를 False로 설정한다.
                if (pnlFMBDesign.SelectedControlsCount() > 0)
                {
                    ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).IsFocused = false;
                    ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).RedrawCtrl();
                }

                // Control를 선택리스트의 마지막에 추가한다.
                ctrl.IsHot = true;
                ctrl.IsSelected = true;
                ctrl.IsFocused = true;
                ctrl.RedrawCtrl();
                pnlFMBDesign.SelectedControls.Add(ctrl);

                if (pnlFMBDesign.SelectedControlsCount() == 1)
                {
                    //tsmLefts.Enabled = false;
                    //tsmCenters.Enabled = false;
                    //tsmRights.Enabled = false;
                    //tsmTops.Enabled = false;
                    //tsmMiddles.Enabled = false;
                    //tsmBottoms.Enabled = false;
                    //tsmWidth.Enabled = false;
                    //tsmHeight.Enabled = false;
                    //tsmBoth.Enabled = false;
                    //tsmHMakeEqual.Enabled = false;
                    //tsmHIncrease.Enabled = false;
                    //tsmHDecrease.Enabled = false;
                    //tsmHRemove.Enabled = false;
                    //tsmVMakeEqual.Enabled = false;
                    //tsmVIncrease.Enabled = false;
                    //tsmVDecrease.Enabled = false;
                    //tsmVRemove.Enabled = false;
                    //tsmBring.Enabled = true;
                    //tsmSend.Enabled = true;
                    //tsmUpdateRes.Enabled = true;
                    //tsmDeleteRes.Enabled = true;
                    //tsmProperties.Enabled = true;

                }
                else if (pnlFMBDesign.SelectedControlsCount() > 1)
                {
                    // 2개 이상의 Control이 선택되어진 경우
                    //tsmLefts.Enabled = true;
                    //tsmCenters.Enabled = true;
                    //tsmRights.Enabled = true;
                    //tsmTops.Enabled = true;
                    //tsmMiddles.Enabled = true;
                    //tsmBottoms.Enabled = true;
                    //tsmWidth.Enabled = true;
                    //tsmHeight.Enabled = true;
                    //tsmBoth.Enabled = true;
                    //tsmHMakeEqual.Enabled = true;
                    //tsmHIncrease.Enabled = true;
                    //tsmHDecrease.Enabled = true;
                    //tsmHRemove.Enabled = true;
                    //tsmVMakeEqual.Enabled = true;
                    //tsmVIncrease.Enabled = true;
                    //tsmVDecrease.Enabled = true;
                    //tsmVRemove.Enabled = true;
                    //tsmBring.Enabled = false;
                    //tsmSend.Enabled = false;
                    //tsmUpdateRes.Enabled = false;
                    //tsmDeleteRes.Enabled = false;
                    //tsmProperties.Enabled = false;
                }
                else
                {
                    // 선택되어진 Control이 없을 경우 -> Format Menu 초기화
                    //tsmLefts.Enabled = false;
                    //tsmCenters.Enabled = false;
                    //tsmRights.Enabled = false;
                    //tsmTops.Enabled = false;
                    //tsmMiddles.Enabled = false;
                    //tsmBottoms.Enabled = false;
                    //tsmWidth.Enabled = false;
                    //tsmHeight.Enabled = false;
                    //tsmBoth.Enabled = false;
                    //tsmHMakeEqual.Enabled = false;
                    //tsmHIncrease.Enabled = false;
                    //tsmHDecrease.Enabled = false;
                    //tsmHRemove.Enabled = false;
                    //tsmVMakeEqual.Enabled = false;
                    //tsmVIncrease.Enabled = false;
                    //tsmVDecrease.Enabled = false;
                    //tsmVRemove.Enabled = false;
                    //tsmBring.Enabled = false;
                    //tsmSend.Enabled = false;
                    //tsmUpdateRes.Enabled = false;
                    //tsmDeleteRes.Enabled = false;
                    //tsmProperties.Enabled = false;
                }


                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.AddSelectedControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // RemoveSelectedControls()
        //       - Remove control from pnlFMBDesign.SelectedControls
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal ctrl As udcCtrlBase : Control to remove
        //
        public bool RemoveSelectedControls(udcCtrlBase ctrl)
        {

            try
            {
                bool bRemoved = false;
                //string sCtrlType;
                //string sSelectedType;

                //// Resource Type / Tag Type 정의
                //if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                //{
                //    sCtrlType = "R:";
                //}
                //else
                //{
                //    sCtrlType = "T:";
                //}

                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {

                    //// Resource Type / Tag Type 인지 분기
                    //if (((udcCtrlBase) pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                    //{
                    //    sSelectedType = "R:";
                    //}
                    //else
                    //{
                    //    sSelectedType = "T:";
                    //}

                    // 현재 Remove 하려는 Control를 찾아 선택리스트에서 삭제
                    //if (FMBCF.ToAsc(sSelectedType + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name) == FMBCF.ToAsc(sCtrlType + ctrl.Name))
                    //if (pnlFMBDesign.SelectedControls[i].Name == ctrl.Name)
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Enums.eToolType.Port || ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Enums.eToolType.SubResource)
                    {
                        if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name == ctrl.Name && ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.MotherResourceID == ctrl.CtrlStatus.MotherResourceID)
                        {
                            ctrl.IsSelected = false;
                            ctrl.IsFocused = false;
                            ctrl.RedrawCtrl();
                            pnlFMBDesign.SelectedControls.Remove(pnlFMBDesign.SelectedControls[i]);
                            bRemoved = true;

                            // 다른 선택되어진 Control이 있을 경우에 그 Control를 Focus를 활성화한다.
                            if (pnlFMBDesign.SelectedControlsCount() > 0)
                            {
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).IsSelected = true;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).IsFocused = true;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).RedrawCtrl();

                            }
                            break;
                        }
                    }
                    else
                    {
                        if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name == ctrl.Name)
                        {
                            ctrl.IsSelected = false;
                            ctrl.IsFocused = false;
                            ctrl.RedrawCtrl();
                            pnlFMBDesign.SelectedControls.Remove(pnlFMBDesign.SelectedControls[i]);
                            bRemoved = true;

                            // 다른 선택되어진 Control이 있을 경우에 그 Control를 Focus를 활성화한다.
                            if (pnlFMBDesign.SelectedControlsCount() > 0)
                            {
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).IsSelected = true;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).IsFocused = true;
                                ((udcCtrlBase)pnlFMBDesign.SelectedControls[pnlFMBDesign.SelectedControlsCount() - 1]).RedrawCtrl();
                            }
                            break;
                        }
                    }
                }

                if (pnlFMBDesign.SelectedControlsCount() == 1)
                {
                    // 1개의 Control이 선택되어진 경우
                    //tsmLefts.Enabled = false;
                    //tsmCenters.Enabled = false;
                    //tsmRights.Enabled = false;
                    //tsmTops.Enabled = false;
                    //tsmMiddles.Enabled = false;
                    //tsmBottoms.Enabled = false;
                    //tsmWidth.Enabled = false;
                    //tsmHeight.Enabled = false;
                    //tsmBoth.Enabled = false;
                    //tsmHMakeEqual.Enabled = false;
                    //tsmHIncrease.Enabled = false;
                    //tsmHDecrease.Enabled = false;
                    //tsmHRemove.Enabled = false;
                    //tsmVMakeEqual.Enabled = false;
                    //tsmVIncrease.Enabled = false;
                    //tsmVDecrease.Enabled = false;
                    //tsmVRemove.Enabled = false;
                    //tsmBring.Enabled = true;
                    //tsmSend.Enabled = true;
                    //tsmUpdateRes.Enabled = true;
                    //tsmDeleteRes.Enabled = true;
                    //tsmProperties.Enabled = true;
                }
                else if (pnlFMBDesign.SelectedControlsCount() > 1)
                {
                    // 2개 이상의 Control이 선택되어진 경우
                    //tsmLefts.Enabled = true;
                    //tsmCenters.Enabled = true;
                    //tsmRights.Enabled = true;
                    //tsmTops.Enabled = true;
                    //tsmMiddles.Enabled = true;
                    //tsmBottoms.Enabled = true;
                    //tsmWidth.Enabled = true;
                    //tsmHeight.Enabled = true;
                    //tsmBoth.Enabled = true;
                    //tsmHMakeEqual.Enabled = true;
                    //tsmHIncrease.Enabled = true;
                    //tsmHDecrease.Enabled = true;
                    //tsmHRemove.Enabled = true;
                    //tsmVMakeEqual.Enabled = true;
                    //tsmVIncrease.Enabled = true;
                    //tsmVDecrease.Enabled = true;
                    //tsmVRemove.Enabled = true;
                    //tsmBring.Enabled = false;
                    //tsmSend.Enabled = false;
                    //tsmUpdateRes.Enabled = false;
                    //tsmDeleteRes.Enabled = false;
                    //tsmProperties.Enabled = false;
                }
                else
                {
                    // 선택되어진 Control이 없을 경우 -> Format Menu 초기화
                    //tsmLefts.Enabled = false;
                    //tsmCenters.Enabled = false;
                    //tsmRights.Enabled = false;
                    //tsmTops.Enabled = false;
                    //tsmMiddles.Enabled = false;
                    //tsmBottoms.Enabled = false;
                    //tsmWidth.Enabled = false;
                    //tsmHeight.Enabled = false;
                    //tsmBoth.Enabled = false;
                    //tsmHMakeEqual.Enabled = false;
                    //tsmHIncrease.Enabled = false;
                    //tsmHDecrease.Enabled = false;
                    //tsmHRemove.Enabled = false;
                    //tsmVMakeEqual.Enabled = false;
                    //tsmVIncrease.Enabled = false;
                    //tsmVDecrease.Enabled = false;
                    //tsmVRemove.Enabled = false;
                    //tsmBring.Enabled = false;
                    //tsmSend.Enabled = false;
                    //tsmUpdateRes.Enabled = false;
                    //tsmDeleteRes.Enabled = false;
                    //tsmProperties.Enabled = false;
                }

                //SetToolBar();

                return bRemoved;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RemoveSelectedControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }


        // InitControls()
        //       - Initialize Controls
        // Return Value
        //       -
        // Arguments
        //        - ByVal bDesignMode As Boolean : Design mode flag
        //
        public void InitControls(bool bDesignMode)
        {

            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        ((udcCtrlBase)ctrl).IsHot = false;
                        ((udcCtrlBase)ctrl).IsSelected = false;
                        ((udcCtrlBase)ctrl).IsFocused = false;
                        ((udcCtrlBase)ctrl).IsPressed = false;
                        ((udcCtrlBase)ctrl).IsModified = false;
                        ((udcCtrlBase)ctrl).IsDesignMode = bDesignMode;
                    }
                }

                int i;
                for (i = pnlFMBDesign.SelectedControlsCount(); i > 0; i--)
                {
                    pnlFMBDesign.SelectedControls.RemoveAt(i - 1);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.InitControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // IsContains()
        //       - Check control is contained within pnlFMBDesign.SelectedControls
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        - ByVal ctrl As udcCtrlBase : Control to check
        //
        public bool IsSelectedContains(udcCtrlBase ctrl)
        {

            try
            {
                string sCtrlType;
                string sSelectedType;

                // Resource Type / Tag Type 정의
                if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                {
                    sCtrlType = "R:";
                }
                else if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                {
                    sCtrlType = "S:";
                }
                else if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                {
                    sCtrlType = "P:";
                }
                else if (ctrl.CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                {
                    sCtrlType = "L:";
                }
                else
                {
                    sCtrlType = "T:";
                }

                int i;
                for (i = 0; i < pnlFMBDesign.SelectedControlsCount(); i++)
                {

                    // Resource Type / Tag Type 인지 분기
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Resource)
                    {
                        sSelectedType = "R:";
                    }
                    else if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                    {
                        sSelectedType = "S:";
                    }
                    else if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port)
                    {
                        sSelectedType = "P:";
                    }
                    else if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Tool)
                    {
                        sSelectedType = "L:";
                    }
                    else
                    {
                        sSelectedType = "T:";
                    }

                    // 선택리스트에 속해있는 Control일 경우에 True를 Return
                    if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.Port || ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.SubResource)
                    {
                        if (((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).CtrlStatus.MotherResourceID == ctrl.CtrlStatus.MotherResourceID)
                        {
                            if (FMBCF.ToAsc(sSelectedType + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name) == FMBCF.ToAsc(sCtrlType + ctrl.Name))
                            {
                                return true;
                            }
                        }
                    }
                    else
                    {
                        if (FMBCF.ToAsc(sSelectedType + ((udcCtrlBase)pnlFMBDesign.SelectedControls[i]).Name) == FMBCF.ToAsc(sCtrlType + ctrl.Name))
                        {
                            return true;
                        }
                    }
                }

                // 선택리스트에 없는 경우에 False를 Return
                return false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.IsSelectedContains()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // IsModifiedControl()
        //       - Check control is modified
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        private bool IsModifiedControl()
        {

            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).CtrlStatus.IsSaveFlag == true)
                        {
                            return true;
                        }
                    }
                }

                return false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.IsModifiedControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // SetModifiedControl()
        //       - Set control is modified
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        private bool SetModifiedControl(bool bModified)
        {

            try
            {
                Control ctrl;
                String abc = "";
                foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    abc = ctrl.Name;
                    if (ctrl is udcCtrlBase)
                    {
                        ((udcCtrlBase)ctrl).CtrlStatus.IsSaveFlag = bModified;
                        ((udcCtrlBase)ctrl).CtrlStatus.ZoomScale = this.ZoomScale;
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.IsModifiedControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // UpdateResTag()
        //       - Update Resource/Tag
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool UpdateResTag()
        {

            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in this.pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).IsSelected == true)
                        {
                            CtrlContextMenu_EventArgs eventArgs = new CtrlContextMenu_EventArgs(null, ((udcCtrlBase)ctrl));
                            CtrlBase_CtrlUpdate(null, eventArgs);
                            return true;
                        }
                    }
                }
                return false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.UpdateResTag()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // DeleteResTag()
        //       - Delete Resource/Tag
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool DeleteResTag()
        {

            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in this.pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).IsSelected == true)
                        {
                            CtrlContextMenu_EventArgs eventArgs = new CtrlContextMenu_EventArgs(null, ((udcCtrlBase)ctrl));
                            CtrlBase_CtrlDelete(null, eventArgs);
                            return true;
                        }
                    }
                }
                return false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.UpdateResTag()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // PropertiesResTag()
        //       - Property Resource/Tag
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        public bool PropertiesResTag()
        {

            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in this.pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).IsSelected == true)
                        {
                            CtrlContextMenu_EventArgs eventArgs = new CtrlContextMenu_EventArgs(null, ((udcCtrlBase)ctrl));
                            CtrlBase_CtrlProperties(null, eventArgs);
                            return true;
                        }
                    }
                }
                return false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.UpdateResTag()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // InitMainMenu()
        //       - Intialize Main Menu
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //

        // EnableMainMenu()
        //       - Enable Available Menu
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //


        // RefreshDeleteControls()
        //       - Refresh Control which is deleted
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        private void RefreshDeleteControls()
        {

            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).IsRefreshed == false)
                        {
                            pnlFMBDesign.Controls.Remove(ctrl);
                        }
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.RefreshDeleteControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // SetRefreshedControl()
        //       - Set control is refreshed
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //        -
        //
        private void SetRefreshedControl(bool bRefreshed)
        {

            try
            {
                Control ctrl;
                foreach (Control tempLoopVar_ctrl in pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        ((udcCtrlBase)ctrl).IsRefreshed = bRefreshed;
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.SetRefreshedControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        #endregion

        #region " Class SelectedControlSort Implementations"

        public class SelectedControlSort : IComparer
        {


            public enum SortOrder
            {
                LEFT_ORDER = 0,
                TOP_ORDER = 1,
                LEFT_ALL_ORDER = 2,
                TOP_ALL_ORDER = 3
            }

            private SortOrder m_iSortOrder;

            public SelectedControlSort(SortOrder eSortOrder)
            {

                m_iSortOrder = eSortOrder;

            }

            public int Compare(object x, object y)
            {

                int iCon1 = 0;
                int iCon2 = 0;

                switch (m_iSortOrder)
                {
                    case SortOrder.LEFT_ORDER:

                        iCon1 = ((udcCtrlBase)x).GetLocation().X;
                        iCon2 = ((udcCtrlBase)y).GetLocation().X;
                        break;
                    case SortOrder.TOP_ORDER:

                        iCon1 = ((udcCtrlBase)x).GetLocation().Y;
                        iCon2 = ((udcCtrlBase)y).GetLocation().Y;
                        break;
                    case SortOrder.LEFT_ALL_ORDER:

                        if (((udcCtrlBase)x).GetLocation().X == ((udcCtrlBase)y).GetLocation().X && ((udcCtrlBase)x).GetLocation().Y == ((udcCtrlBase)y).GetLocation().Y)
                        {
                            return 0;
                        }
                        else
                        {
                            if (((udcCtrlBase)x).GetLocation().X == ((udcCtrlBase)y).GetLocation().X)
                            {
                                iCon1 = ((udcCtrlBase)x).GetLocation().Y;
                                iCon2 = ((udcCtrlBase)y).GetLocation().Y;
                            }
                            else
                            {
                                iCon1 = ((udcCtrlBase)x).GetLocation().X;
                                iCon2 = ((udcCtrlBase)y).GetLocation().X;
                            }
                        }
                        break;
                    case SortOrder.TOP_ALL_ORDER:

                        if (((udcCtrlBase)x).GetLocation().X == ((udcCtrlBase)y).GetLocation().X && ((udcCtrlBase)x).GetLocation().Y == ((udcCtrlBase)y).GetLocation().Y)
                        {
                            return 0;
                        }
                        else
                        {
                            if (((udcCtrlBase)x).GetLocation().Y == ((udcCtrlBase)y).GetLocation().Y)
                            {
                                iCon1 = ((udcCtrlBase)x).GetLocation().X;
                                iCon2 = ((udcCtrlBase)y).GetLocation().X;
                            }
                            else
                            {

                                iCon1 = ((udcCtrlBase)x).GetLocation().Y;
                                iCon2 = ((udcCtrlBase)y).GetLocation().Y;
                            }
                        }
                        break;
                }

                return new CaseInsensitiveComparer().Compare(iCon1, iCon2);

            }

        }

        #endregion

        public void tsmLefts_Click(object sender, EventArgs e)
        {
            try
            {
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Lefts();
                RedrawControls();

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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Centers();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Rights();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Tops();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Middles();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Bottoms();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Width();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Height();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_Both();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_HMakeEqual();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_HIncrease();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_HDecrease();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_HRemove();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_VMakeEqual();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_VIncrease();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_VDecrease();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 2)
                {
                    return;
                }
                Format_VRemove();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 1)
                {
                    return;
                }
                Format_BringToFront();
                RedrawControls();
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
                if (IsDesignMode == false)
                {
                    return;
                }
                if (pnlFMBDesign.SelectedControlsCount() < 1)
                {
                    return;
                }
                Format_SendToBack();
                RedrawControls();
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
                string sFactory = "";
                if (IsDesignMode == true)
                {
                    if (IsModifiedControl() == true)
                    {
                        if ((DialogResult)MPCF.ShowMsgBox(this.Name + " - " + MPCF.GetMessage(13), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.No)
                        {
                            return;
                        }
                    }
                }
                if (ZoomScale != 0)
                {
                    ZoomScale = 0;
                    DesignSize = OriginalDesignSize;
                }
                //string sFactory;
                if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                }
                else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    sFactory = MPGV.gsFactory;
                }
                else
                {
                    return;
                }
                if (FMBCF.ViewGlobalOption(sFactory) == false)
                {
                    return;
                }
                if (RefreshResourceListDetail() == false)
                {
                    return;
                }
                if (SetModifiedControl(false) == false)
                {
                    return;
                }
                RedrawControls();
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
                Cursor = Cursors.WaitCursor;
                double dScale = new double();

                int iWidth;
                int iHeight;
                Size szNewSize;
                Control ctrl;
                this.Cursor = Cursors.WaitCursor;
                this.SuspendLayout();
                this.pnlFMBDesign.SuspendLayout();
                ZoomScale++;
                dScale = FMBCF.GetScale(ZoomScale);
                iWidth = 0;
                iHeight = 0;
                szNewSize = new Size(MPCF.ToInt(OriginalDesignSize.Width * dScale), MPCF.ToInt(OriginalDesignSize.Height * dScale));
                ctrl = new Control();
                foreach (Control tempLoopVar_ctrl in this.pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        ((udcCtrlBase)ctrl).CtrlStatus.ZoomScale = ZoomScale;
                        iWidth = MPCF.ToInt((((udcCtrlBase)ctrl).GetSize().Width + Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2) * FMBCF.GetScale(ZoomScale));
                        iHeight = MPCF.ToInt((((udcCtrlBase)ctrl).GetSize().Height + Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2) * FMBCF.GetScale(ZoomScale));
                        Size szNew = new Size(iWidth, iHeight);
                        ((udcCtrlBase)ctrl).Size = szNew;
                        Point ptNew = new Point(MPCF.ToInt((((udcCtrlBase)ctrl).GetLocation().X - Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE) * FMBCF.GetScale(ZoomScale)), MPCF.ToInt((((udcCtrlBase)ctrl).GetLocation().Y - Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE) * FMBCF.GetScale(ZoomScale)));
                        ((udcCtrlBase)ctrl).Location = ptNew;
                    }
                }
                DesignSize = szNewSize;
                this.pnlFMBDesign.ResumeLayout(false);
                this.ResumeLayout();
                this.Cursor = Cursors.Default;
                RedrawControls();
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
                Cursor = Cursors.WaitCursor;
                double dScale = new double();

                int iWidth;
                int iHeight;
                Size szNewSize;
                Control ctrl;
                this.Cursor = Cursors.WaitCursor;
                this.SuspendLayout();
                this.pnlFMBDesign.SuspendLayout();
                ZoomScale--;
                dScale = FMBCF.GetScale(ZoomScale);
                iWidth = 0;
                iHeight = 0;
                szNewSize = new Size(MPCF.ToInt(OriginalDesignSize.Width * dScale), MPCF.ToInt(OriginalDesignSize.Height * dScale));
                ctrl = new Control();
                foreach (Control tempLoopVar_ctrl in this.pnlFMBDesign.Controls)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        ((udcCtrlBase)ctrl).CtrlStatus.ZoomScale = ZoomScale;
                        iWidth = MPCF.ToInt((((udcCtrlBase)ctrl).GetSize().Width + Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2) * FMBCF.GetScale(ZoomScale));
                        iHeight = MPCF.ToInt((((udcCtrlBase)ctrl).GetSize().Height + Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2) * FMBCF.GetScale(ZoomScale));
                        if (((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.HorizontalLine || ((udcCtrlBase)ctrl).CtrlStatus.ToolType == Miracom.FMBUI.Enums.eToolType.VerticalLine)
                        {
                            if (iWidth < Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.LINE_MININUM_SIZE)
                            {
                                iWidth = Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.LINE_MININUM_SIZE;
                            }
                            if (iHeight < Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.LINE_MININUM_SIZE)
                            {
                                iHeight = Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.LINE_MININUM_SIZE;
                            }
                        }
                        else
                        {
                            if (iWidth < Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.CTRL_MININUM_SIZE)
                            {
                                iWidth = Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.CTRL_MININUM_SIZE;
                            }
                            if (iHeight < Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.CTRL_MININUM_SIZE)
                            {
                                iHeight = Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE * 2 + modGlobalConstant.CTRL_MININUM_SIZE;
                            }
                        }
                        Size szNew = new Size(iWidth, iHeight);
                        ((udcCtrlBase)ctrl).Size = szNew;
                        Point ptNew = new Point(MPCF.ToInt((((udcCtrlBase)ctrl).GetLocation().X - Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE) * FMBCF.GetScale(ZoomScale)), MPCF.ToInt((((udcCtrlBase)ctrl).GetLocation().Y - Miracom.FMBUI.Controls.modDefines.CTRL_TRACKER_SIZE) * FMBCF.GetScale(ZoomScale)));
                        ((udcCtrlBase)ctrl).Location = ptNew;
                    }
                }
                DesignSize = szNewSize;
                this.pnlFMBDesign.ResumeLayout(false);
                this.ResumeLayout();
                this.Cursor = Cursors.Default;
                RedrawControls();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.tsmZoomOut_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

        public void tsmDesignMode_Click(object sender, EventArgs e)
        {
            if (IsDesignMode == false)
            {
                if (ZoomScale != 0)
                {
                    ZoomScale = 0;
                    DesignSize = OriginalDesignSize;
                    if (RefreshResourceListDetail() == false)
                    {
                        return;
                    }
                }
                IsDesignMode = true;
                pnlFMBDesign.IsDesignMode = true;
                //tsmTopFormat.Enabled = true;
                if (SetModifiedControl(false) == false)
                {
                    return;
                }
                //tsmDesignMode.Checked = true;
            }
            else
            {
                IsDesignMode = false;
                pnlFMBDesign.IsDesignMode = false;
                //tsmTopFormat.Enabled = false;
                //tsmDesignMode.Checked = false;
            }
        }

        public void tsmSaveDesign_Click(object sender, EventArgs e)
        {
            if (IsDesignMode == false)
            {
                return;
            }

            if (UpdateResourceListDetail() == true)
            {

            }
            else
            {
                return;
            }
        }

        public void tsmAddRes_Click(object sender, EventArgs e)
        {
            if (IsDesignMode == false)
            {
                return;
            }
            string sGroupID = "";
            string sLayOut = "";
            string sFactory = "";
            if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
            {
                sFactory = FMBCF.GetStringBySeperator(Name, ":", 1);
                sLayOut = FMBCF.GetStringBySeperator(Name, ":", 2);
            }
            else if (System.Convert.ToString(Tag) == modGlobalConstant.FMB_CATEGORY_GROUP)
            {
                sFactory = MPGV.gsFactory;
                sGroupID = Name;
            }
            else
            {
                return;
            }
            frmFMBAddMultiResources form = new frmFMBAddMultiResources(sFactory, sGroupID, sLayOut);
            form.Tag = Tag;
            if (form.ShowDialog(this) == DialogResult.OK)
            {
                int i;
                for (i = 0; i <= form.lisResourceList.CheckedItems.Count - 1; i++)
                {
                    clsCtrlStatus ResourceStatus = new clsCtrlStatus();
                    ResourceStatus.Key = form.lisResourceList.CheckedItems[i].Text;
                    ResourceStatus.SetLocation(new Point(MPCF.ToInt(form.lisResourceList.CheckedItems[i].SubItems[11].Text), MPCF.ToInt(form.lisResourceList.CheckedItems[i].SubItems[12].Text)));
                    ResourceStatus.SetSize(new Size(MPCF.ToInt(form.lisResourceList.CheckedItems[i].SubItems[9].Text), MPCF.ToInt(form.lisResourceList.CheckedItems[i].SubItems[10].Text)));
                    ResourceStatus.Text = form.lisResourceList.CheckedItems[i].SubItems[4].Text;
                    if (Color.FromName(form.lisResourceList.CheckedItems[i].SubItems[5].Text).ToKnownColor() > 0)
                    {
                        ResourceStatus.TextColor = MPCF.ToInt(Color.FromName(form.lisResourceList.CheckedItems[i].SubItems[5].Text).ToKnownColor());
                    }
                    else
                    {
                        ResourceStatus.TextColor = FMBCF.ConvertStringToColor(form.lisResourceList.CheckedItems[i].SubItems[5].Text);
                    }
                    if (Color.FromName(form.lisResourceList.CheckedItems[i].SubItems[6].Text).ToKnownColor() > 0)
                    {
                        ResourceStatus.BackColor = MPCF.ToInt(Color.FromName(form.lisResourceList.CheckedItems[i].SubItems[6].Text).ToKnownColor());
                    }
                    else
                    {
                        ResourceStatus.BackColor = FMBCF.ConvertStringToColor(form.lisResourceList.CheckedItems[i].SubItems[6].Text);
                    }
                    ResourceStatus.TextFontName = System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.DefaultFontName));
                    if (form.lisResourceList.CheckedItems[i].SubItems[7].Text == "")
                    {
                        ResourceStatus.TextSize = 0;
                    }
                    else
                    {
                        ResourceStatus.TextSize = MPCF.ToInt(form.lisResourceList.CheckedItems[i].SubItems[7].Text);
                    }
                    ResourceStatus.TextStyle = MPCF.ToInt(@Enum.Parse(typeof(FontStyle), MPCF.Trim(form.lisResourceList.CheckedItems[i].SubItems[8].Text)));
                    ResourceStatus.ToolType = Miracom.FMBUI.Enums.eToolType.Resource;
                    ResourceStatus.LastEvent = form.lisResourceList.CheckedItems[i].SubItems[13].Text;
                    ResourceStatus.PrimaryStatus = form.lisResourceList.CheckedItems[i].SubItems[14].Text;
                    ResourceStatus.ProcMode = form.lisResourceList.CheckedItems[i].SubItems[15].Text;
                    ResourceStatus.CtrlMode = form.lisResourceList.CheckedItems[i].SubItems[16].Text;
                    ResourceStatus.ResourceType = form.lisResourceList.CheckedItems[i].SubItems[18].Text;
                    ResourceStatus.UpDownFlag = form.lisResourceList.CheckedItems[i].SubItems[17].Text;
                    ResourceStatus.AreaID = form.lisResourceList.CheckedItems[i].SubItems[2].Text;
                    ResourceStatus.SubAreaID = form.lisResourceList.CheckedItems[i].SubItems[3].Text;
                    ResourceStatus.ResTagFlag = "R";

                    if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.IsProcessMode)) == "P")
                    {
                        ResourceStatus.IsProcessMode = true;
                    }
                    else
                    {
                        ResourceStatus.IsProcessMode = false;
                    }
                    if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.UseEventColor)) == "Y")
                    {
                        ResourceStatus.IsUseEventColor = true;
                        if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(sFactory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                        {
                            ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                        }
                        else
                        {
                            ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(sFactory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                        }
                    }
                    else
                    {
                        ResourceStatus.IsUseEventColor = false;
                    }
                    ResourceStatus.ImageIndex = MPCF.ToInt(form.lisResourceList.CheckedItems[i].SubItems[19].Text);
                    ResourceStatus.IsViewSignal = true;
                    ResourceStatus.SignalPosition = '1';

                    if (AddControl(ResourceStatus, true, false) == false)
                    {
                        return;
                    }
                }
                if (System.Convert.ToString(this.Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    if (FMBFI.gIMdiForm.RefreshDesignList("5", sFactory, sLayOut, "", "") == false)
                    {
                        return;
                    }
                }
            }
        }

        public void tsmUpdateRes_Click(object sender, EventArgs e)
        {
            if (IsDesignMode == true)
            {
                UpdateResTag();
            }
        }

        public void tsmDeleteRes_Click(object sender, EventArgs e)
        {
            if (IsDesignMode == true)
            {
                DeleteResTag();
            }
        }

        public void tsmProperties_Click(object sender, EventArgs e)
        {
            if (IsDesignMode == true)
            {
                PropertiesResTag();
            }
        }



    }

    public class CtrlSeqSort : IComparer
    {

        public int Compare(object con1, object con2)
        {

            try
            {
                int iCon1;
                int iCon2;
                int return_value;

                iCon1 = ((clsCtrlStatus)con1).Seq;
                iCon2 = ((clsCtrlStatus)con2).Seq;

                return_value = new CaseInsensitiveComparer().Compare(iCon1, iCon2);
                return_value = -1 * return_value;
                return return_value;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("ControlNameSort.Compare()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return 0;
            }

        }

    }
}
