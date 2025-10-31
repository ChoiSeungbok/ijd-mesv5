
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;
//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBSendMessage.vb
//   Description : Send Message
//
//   FMB Version : 1.0.0
//
//   Function List
//       - SendMessage : Send Message
//       - CheckCondition : Check the conditions before transaction
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
namespace Miracom.FMBCore
{
    public class frmFMBSendMessage : System.Windows.Forms.Form
    {
        
        #region " Windows Form Auto Generated Code "
        
        public frmFMBSendMessage()
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
        internal System.Windows.Forms.Button btnSend;
        internal System.Windows.Forms.Button btnClose;
        internal System.Windows.Forms.Panel pnlTop;
        internal System.Windows.Forms.GroupBox grpTop;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvFactory;
        internal System.Windows.Forms.Label lblFactory;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvUserID;
        internal System.Windows.Forms.Label lblUser;
        internal System.Windows.Forms.Label lblUserGroup;
        internal Miracom.UI.Controls.MCCodeView.MCCodeView cdvUserGroup;
        internal System.Windows.Forms.Panel pnlMid;
        internal System.Windows.Forms.TextBox txtMessage;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            base.Load += new System.EventHandler(frmFMBSendMessage_Load);
            this.btnSend = new System.Windows.Forms.Button();
            this.btnSend.Click += new System.EventHandler(btnSend_Click);
            this.btnClose = new System.Windows.Forms.Button();
            this.btnClose.Click += new System.EventHandler(btnClose_Click);
            this.pnlTop = new System.Windows.Forms.Panel();
            this.grpTop = new System.Windows.Forms.GroupBox();
            this.cdvFactory = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvFactory.ButtonPress += new System.EventHandler(cdvFactory_ButtonPress);
            this.cdvFactory.TextBoxTextChanged += new System.EventHandler(cdvFactory_TextBoxTextChanged);
            this.lblFactory = new System.Windows.Forms.Label();
            this.cdvUserID = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvUserID.ButtonPress += new System.EventHandler(cdvUserID_ButtonPress);
            this.lblUser = new System.Windows.Forms.Label();
            this.lblUserGroup = new System.Windows.Forms.Label();
            this.cdvUserGroup = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.cdvUserGroup.ButtonPress += new System.EventHandler(cdvUserGroup_ButtonPress);
            this.cdvUserGroup.TextBoxTextChanged += new System.EventHandler(cdvUserGroup_TextBoxTextChanged);
            this.pnlMid = new System.Windows.Forms.Panel();
            this.txtMessage = new System.Windows.Forms.TextBox();
            this.pnlBottom.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.grpTop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize) this.cdvFactory).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvUserID).BeginInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvUserGroup).BeginInit();
            this.pnlMid.SuspendLayout();
            this.SuspendLayout();
            //
            //pnlBottom
            //
            this.pnlBottom.Controls.Add(this.btnSend);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 506);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 2;
            //
            //btnSend
            //
            this.btnSend.Anchor = (System.Windows.Forms.AnchorStyles) (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
            this.btnSend.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnSend.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnSend.Location = new System.Drawing.Point(579, 9);
            this.btnSend.Name = "btnSend";
            this.btnSend.Size = new System.Drawing.Size(74, 23);
            this.btnSend.TabIndex = 0;
            this.btnSend.Text = "Send";
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
            this.grpTop.Controls.Add(this.cdvFactory);
            this.grpTop.Controls.Add(this.lblFactory);
            this.grpTop.Controls.Add(this.cdvUserID);
            this.grpTop.Controls.Add(this.lblUser);
            this.grpTop.Controls.Add(this.lblUserGroup);
            this.grpTop.Controls.Add(this.cdvUserGroup);
            this.grpTop.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpTop.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpTop.Location = new System.Drawing.Point(3, 0);
            this.grpTop.Name = "grpTop";
            this.grpTop.Size = new System.Drawing.Size(736, 71);
            this.grpTop.TabIndex = 0;
            this.grpTop.TabStop = false;
            //
            //cdvFactory
            //
            this.cdvFactory.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvFactory.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvFactory.BtnToolTipText = "";
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
            this.cdvFactory.SelectedSubItemIndex = - 1;
            this.cdvFactory.SelectionStart = 0;
            this.cdvFactory.Size = new System.Drawing.Size(200, 20);
            this.cdvFactory.SmallImageList = null;
            this.cdvFactory.TabIndex = 0;
            this.cdvFactory.TextBoxToolTipText = "";
            this.cdvFactory.VisibleButton = true;
            this.cdvFactory.VisibleColumnHeader = false;
            //
            //lblFactory
            //
            this.lblFactory.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblFactory.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.lblFactory.Location = new System.Drawing.Point(13, 20);
            this.lblFactory.Name = "lblFactory";
            this.lblFactory.Size = new System.Drawing.Size(100, 14);
            this.lblFactory.TabIndex = 50;
            this.lblFactory.Text = "Factory";
            //
            //cdvUserID
            //
            this.cdvUserID.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvUserID.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvUserID.BtnToolTipText = "";
            this.cdvUserID.Focusing = null;
            this.cdvUserID.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.cdvUserID.Index = 0;
            this.cdvUserID.IsViewBtnImage = false;
            this.cdvUserID.Location = new System.Drawing.Point(118, 41);
            this.cdvUserID.MaxLength = 20;
            this.cdvUserID.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvUserID.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvUserID.Name = "cdvUserID";
            this.cdvUserID.ReadOnly = false;
            this.cdvUserID.SelectedSubItemIndex = - 1;
            this.cdvUserID.SelectionStart = 0;
            this.cdvUserID.Size = new System.Drawing.Size(200, 20);
            this.cdvUserID.SmallImageList = null;
            this.cdvUserID.TabIndex = 1;
            this.cdvUserID.TextBoxToolTipText = "";
            this.cdvUserID.VisibleButton = true;
            this.cdvUserID.VisibleColumnHeader = false;
            //
            //lblUser
            //
            this.lblUser.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUser.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.lblUser.Location = new System.Drawing.Point(13, 44);
            this.lblUser.Name = "lblUser";
            this.lblUser.Size = new System.Drawing.Size(100, 14);
            this.lblUser.TabIndex = 4;
            this.lblUser.Text = "User ID";
            //
            //lblUserGroup
            //
            this.lblUserGroup.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUserGroup.Location = new System.Drawing.Point(418, 20);
            this.lblUserGroup.Name = "lblUserGroup";
            this.lblUserGroup.Size = new System.Drawing.Size(100, 14);
            this.lblUserGroup.TabIndex = 6;
            this.lblUserGroup.Text = "User Group";
            //
            //cdvUserGroup
            //
            this.cdvUserGroup.StyleBorder = System.Windows.Forms.BorderStyle.FixedSingle;
            this.cdvUserGroup.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvUserGroup.BtnToolTipText = "";
            this.cdvUserGroup.Focusing = null;
            this.cdvUserGroup.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.cdvUserGroup.Index = 0;
            this.cdvUserGroup.IsViewBtnImage = false;
            this.cdvUserGroup.Location = new System.Drawing.Point(523, 17);
            this.cdvUserGroup.MaxLength = 20;
            this.cdvUserGroup.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvUserGroup.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvUserGroup.Name = "cdvUserGroup";
            this.cdvUserGroup.ReadOnly = false;
            this.cdvUserGroup.SelectedSubItemIndex = - 1;
            this.cdvUserGroup.SelectionStart = 0;
            this.cdvUserGroup.Size = new System.Drawing.Size(200, 20);
            this.cdvUserGroup.SmallImageList = null;
            this.cdvUserGroup.TabIndex = 2;
            this.cdvUserGroup.TextBoxToolTipText = "";
            this.cdvUserGroup.VisibleButton = true;
            this.cdvUserGroup.VisibleColumnHeader = false;
            //
            //pnlMid
            //
            this.pnlMid.Controls.Add(this.txtMessage);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.DockPadding.Left = 3;
            this.pnlMid.DockPadding.Right = 3;
            this.pnlMid.DockPadding.Top = 5;
            this.pnlMid.Location = new System.Drawing.Point(0, 71);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Size = new System.Drawing.Size(742, 435);
            this.pnlMid.TabIndex = 1;
            //
            //txtMessage
            //
            this.txtMessage.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtMessage.Location = new System.Drawing.Point(3, 5);
            this.txtMessage.Multiline = true;
            this.txtMessage.Name = "txtMessage";
            this.txtMessage.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtMessage.Size = new System.Drawing.Size(736, 430);
            this.txtMessage.TabIndex = 0;
            this.txtMessage.Text = "";
            //
            //frmFMBSendMessage
            //
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 546);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlTop);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBSendMessage";
            this.Tag = "FMB6001";
            this.Text = "Send Message";
            this.pnlBottom.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.grpTop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize) this.cdvFactory).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvUserID).EndInit();
            ((System.ComponentModel.ISupportInitialize) this.cdvUserGroup).EndInit();
            this.pnlMid.ResumeLayout(false);
            this.ResumeLayout(false);
            
        }
        
        #endregion
        
        #region " Function Implementations"
        
        // SendMessage()
        //       - Send Message
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       -
        //
        private bool SendMessage()
        {
            
            try
            {
                TRSNode in_node = new TRSNode("UTL_Publish_Message_In");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("SEND_COMPUTER_ID", MPGV.gsComputerName);
                in_node.AddString("SEND_USER_ID", MPGV.gsUserID, true);
                in_node.AddString("SEND_USER_GROUP", MPGV.gsUserGroup);

                in_node.AddString("TO_FACTORY", cdvFactory.Text);
                in_node.AddString("TO_USER_GROUP", cdvUserGroup.Text);
                in_node.AddString("TO_USER_ID", cdvUserID.Text, true);
                in_node.AddString("MESSAGE", txtMessage.Text);

                
                string sPublishChannel;
                sPublishChannel = "/" + MPGV.gsSiteID;
                sPublishChannel += "/UTL";
                if (in_node.GetString("TO_FACTORY") != "")
                {
                    sPublishChannel += "/" + cdvFactory.Text;
                }
                else
                {
                    sPublishChannel += "/*";
                }
                if (in_node.GetString("TO_USER_GROUP") != "")
                {
                    sPublishChannel += "/" + cdvUserGroup.Text;
                }
                else
                {
                    sPublishChannel += "/*";
                }
                if (in_node.GetString("TO_USER_ID") != "")
                {
                    sPublishChannel += "/" + cdvUserID.Text;
                }
                else
                {
                    sPublishChannel += "/*";
                }

                if (MPCR.CallService("UTL", "UTL_Publish_Message", in_node, DeliveryMode.Multicast) == false)
                {
                    return false;
                }
                           
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.SendMessage()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
            
        }
        
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
                        if (cdvUserGroup.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                            cdvFactory.Focus();
                            return false;
                        }
                        break;
                }
                
                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.CheckCondition()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvUserGroup_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("1") == false)
                {
                    return;
                }
                
                cdvUserGroup.Init();
                MPCF.InitListView(cdvUserGroup.GetListView);
                cdvUserGroup.Columns.Add("UserGroup", 100, HorizontalAlignment.Left);
                cdvUserGroup.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvUserGroup.SelectedSubItemIndex = 0;
                cdvUserGroup.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                SECLIST.ViewSecGroupList(cdvUserGroup.GetListView, '1',null, cdvFactory.Text);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.cdvUserGroup_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvFactory_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvUserGroup.ListClear();
                cdvUserGroup.Text = "";
                cdvUserID.ListClear();
                cdvUserID.Text = "";
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.cdvFactory_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvUserGroup_TextBoxTextChanged(object sender, System.EventArgs e)
        {
            
            try
            {
                cdvUserID.ListClear();
                cdvUserID.Text = "";
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.cdvUserGroup_TextBoxTextChanged()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void cdvUserID_ButtonPress(object sender, System.EventArgs e)
        {
            
            try
            {
                if (CheckCondition("1") == false)
                {
                    return;
                }
                
                cdvUserID.Init();
                MPCF.InitListView(cdvUserID.GetListView);
                cdvUserID.Columns.Add("UserID", 100, HorizontalAlignment.Left);
                cdvUserID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvUserID.SelectedSubItemIndex = 0;
                cdvUserID.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                SECLIST.ViewSECUserList(cdvUserID.GetListView, '2',  -1,null, cdvFactory.Text,cdvUserGroup.Text);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.cdvUserID_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnSend_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                if (MPCF.RTrim(this.txtMessage.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(36), Application.ProductName, MessageBoxButtons.OK, 1);
                    txtMessage.Focus();
                    return;
                }
                if (SendMessage() == false)
                {
                    return;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.btnSend_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
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
                MPCF.ShowMsgBox("frmFMBSendMessage.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        protected override void OnDeactivate(System.EventArgs e)
        {
            
            try
            {
                if (btnSend.Focused == true)
                {
                    txtMessage.Focus();
                    txtMessage.SelectionStart = txtMessage.TextLength;
                }
                
                base.OnDeactivate(e);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.OnDeactivate()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBSendMessage_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                MPCR.CheckSecurityFormControl(this);
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSendMessage.frmFMBSendMessage_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
