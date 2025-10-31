using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.Collections;
using Miracom.FMBUI;
using Miracom.FMBUI.Controls;
using Miracom.CliFrx;
using Miracom.RASCore;
using Miracom.MESCore;
using Miracom.TRSCore;
namespace Miracom.FMBCore
{
    public partial class udcFMBLayout : UserControl
    {
        delegate bool RefreshControlDelegate(Control.ControlCollection CtrlCollection, ref FMBUI.clsCtrlStatus ResourceStatus, int iStep);
        private RefreshControlDelegate _RefreshControlDelegate;
        public udcFMBLayout()
        {
            this.Name = LayOutName;
            this.Tag = LayOutTag;
            this.pnlFMBDesign = new udcFMBDesign(this);
            InitializeComponent();

            modGlobalVariable.gimlResource = this.imlResource;
            
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

        #region " Property Implementations"

        private bool m_bLoading = true;
        private bool m_bDesignMode = false;
        private int m_iZoomScale = 0;
        private Size m_szOriginalDesignSize;

        private bool m_bDeleteFlag = false;
        private bool m_bSelectingCtrl = false;
        private bool m_bSelectedSelectingCtrl = false;
        private bool m_bGotFocus = false;
        private string m_sName = "";
        private string m_sTag = "";

        ArrayList ctrlArray = new ArrayList();
        public string LayOutName
        {
            get
            {
                return m_sName;
            }
            set
            {

                if (m_sName.Equals(value) == false)
                {
                    m_sName = value;
                }
            }
        }

        public string LayOutTag
        {
            get
            {
                return m_sTag;
            }
            set
            {

                if (m_sTag.Equals(value) == false)
                {
                    m_sTag = value;
                }
            }
        }
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
                
        private void udcFMBLayout_FormClosed(object sender, FormClosedEventArgs e)
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
                MPCF.ShowMsgBox("udcFMBLayout.udcFMBLayout_Closed()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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

                IsSelectingCtrl = true;
                IsSelectedSelectingCtrl = ctrl.IsSelected;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlMouseEnter()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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

                IsSelectingCtrl = false;
                IsSelectedSelectingCtrl = false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlMouseLeave()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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

                

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlLostFocus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlGotFocus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlMouseDown()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlMouseMove()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlMouseUp()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlKeyDown()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void CtrlBase_CtrlContextMenu(System.Object sender, CtrlContextMenu_EventArgs e)
        {

            try
            {
                switch (((MenuItem)sender).MergeOrder)
                {
                    case 1:

                        //CtrlBase_CtrlUpdate(sender, e);
                        break;
                    case 2:

                        //CtrlBase_CtrlDelete(sender, e);
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

                        //udcCtrlBase copyCtrl = (udcCtrlBase)e.CtrlSender;
                        //pnlFMBDesign.ClipboardControl = copyCtrl;
                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlContextMenu()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlProperties()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlViewResourceStatus()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlViewResourceHistory()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.CtrlBase_CtrlTranEvent()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        private void udcFMBLayout_Load(object sender, System.EventArgs e)
        {

            try
            {
                
                IsLoading = true;

                
                pnlFMBDesign.pnlTracker.BackColor = Color.FromArgb(0, Color.Beige);

                if (IsDesignMode == true)
                {
                    pnlFMBDesign.BackColor = Color.WhiteSmoke;
                }
                else
                {
                    pnlFMBDesign.BackColor = Color.White;
                }

                

                pnlFMBDesign.Select();

                


                //ChangeMenuText(mnuDesign);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.udcFMBLayout_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public void ViewLayoutInfo()
        {
            try
            {
            Cursor = Cursors.WaitCursor;
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
            Cursor = Cursors.Default;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.udcFMBLayout_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.FindFocusCtrl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

            return ctrl;

        }

        #endregion

        #region " Functions Implementations"

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
                MPCF.ShowMsgBox("udcFMBLayout.RefreshControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.RefreshControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
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
                MPCF.ShowMsgBox("udcFMBLayout.ViewLayout()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.ViewResourceListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

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
                MPCF.ShowMsgBox("udcFMBLayout.ViewToolListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.ViewSubResourceListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.ViewPortListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                SetRefreshedControl(false);

                this.pnlFMBDesign.ResumeLayout(false);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.RefreshResourceListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.RefreshSubResourceListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.RefreshSubToolListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.RefreshPortListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.UpdateResourceListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.AddControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.RedrawControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.AddSelectedControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.RemoveSelectedControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.InitControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // InitControls()
        //       - Initialize Controls
        // Return Value
        //       -
        // Arguments
        //        - ByVal bDesignMode As Boolean : Design mode flag
        //
        protected override void InitLayout()
        {

            try
            {

                pnlFMBDesign.Controls.Clear();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("udcFMBLayout.InitControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.IsSelectedContains()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.IsModifiedControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.IsModifiedControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.UpdateResTag()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.RefreshDeleteControls()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("udcFMBLayout.SetRefreshedControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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

        #endregion

  
    }
}
