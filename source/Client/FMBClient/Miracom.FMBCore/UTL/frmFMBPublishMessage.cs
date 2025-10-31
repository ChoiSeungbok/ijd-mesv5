
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using Miracom.CliFrx;
using Miracom.MESCore;

//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : frmFMBPublishMessage.vb
//   Description : Publish Message
//
//   FMB Version : 1.0.0
//
//   Function List
//       -
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
    public class frmFMBPublishMessage : System.Windows.Forms.Form
    {
        delegate void SetMessageDelegate(string sMsg);

        private SetMessageDelegate _SetMessageDelegate;
    
  #region " Windows Form Auto Generated Code "
        
        public frmFMBPublishMessage()
        {
            
            //???몄텧? Windows Form ?붿옄?대꼫???꾩슂?⑸땲??
            InitializeComponent();
            
            //InitializeComponent()瑜??몄텧???ㅼ쓬??珥덇린???묒뾽??異붽??섏떗?쒖삤.
            _SetMessageDelegate = new SetMessageDelegate(SetMessage);
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
        internal System.Windows.Forms.Panel pnlMessage;
        public System.Windows.Forms.TextBox txtMessage;
        internal System.Windows.Forms.Button btnClear;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlBottom = new System.Windows.Forms.Panel();
            base.Activated += new System.EventHandler(frmFMBPublishMessage_Activated);
            base.Load += new System.EventHandler(frmFMBPublishMessage_Load);
            this.btnClose = new System.Windows.Forms.Button();
            this.btnClose.Click += new System.EventHandler(btnClose_Click);
            this.pnlMessage = new System.Windows.Forms.Panel();
            this.txtMessage = new System.Windows.Forms.TextBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnClear.Click += new System.EventHandler(btnClear_Click);
            this.pnlBottom.SuspendLayout();
            this.pnlMessage.SuspendLayout();
            this.SuspendLayout();
            //
            //pnlBottom
            //
            this.pnlBottom.Controls.Add(this.btnClear);
            this.pnlBottom.Controls.Add(this.btnClose);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 506);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(742, 40);
            this.pnlBottom.TabIndex = 2;
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
            this.btnClose.TabIndex = 3;
            this.btnClose.Text = "Close";
            //
            //pnlMessage
            //
            this.pnlMessage.Controls.Add(this.txtMessage);
            this.pnlMessage.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMessage.DockPadding.All = 3;
            this.pnlMessage.Location = new System.Drawing.Point(0, 0);
            this.pnlMessage.Name = "pnlMessage";
            this.pnlMessage.Size = new System.Drawing.Size(742, 506);
            this.pnlMessage.TabIndex = 3;
            //
            //txtMessage
            //
            this.txtMessage.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtMessage.Location = new System.Drawing.Point(3, 3);
            this.txtMessage.Multiline = true;
            this.txtMessage.Name = "txtMessage";
            this.txtMessage.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtMessage.Size = new System.Drawing.Size(736, 500);
            this.txtMessage.TabIndex = 1;
            this.txtMessage.Text = "";
            //
            //btnClear
            //
            this.btnClear.Anchor = (System.Windows.Forms.AnchorStyles) (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right);
            this.btnClear.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.btnClear.Location = new System.Drawing.Point(580, 9);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(74, 23);
            this.btnClear.TabIndex = 4;
            this.btnClear.Text = "Clear";
            //
            //frmFMBPublishMessage
            //
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.ClientSize = new System.Drawing.Size(742, 546);
            this.Controls.Add(this.pnlMessage);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (0)));
            this.MinimumSize = new System.Drawing.Size(750, 580);
            this.Name = "frmFMBPublishMessage";
            this.Text = "Message";
            this.pnlBottom.ResumeLayout(false);
            this.pnlMessage.ResumeLayout(false);
            this.ResumeLayout(false);
            
        }
        
        #endregion
        
        #region " Variable Definition"
        
        public bool b_load_flag;
        
        #endregion
        
        #region " Event Implementations"

        public void SetMessageEvent(string sMsg)
        {
            try
            {
                IAsyncResult r = BeginInvoke(_SetMessageDelegate, new object[] { sMsg });
                EndInvoke(r);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmUTLPublishMessage.SetMessageEvent()\n" + ex.Message);
            }

        }
        private void SetMessage(string sMsg)
        {
            try
            {
                txtMessage.Text = MPCF.RTrim(sMsg);
                txtMessage.SelectionStart = txtMessage.TextLength;
                txtMessage.ScrollToCaret();
                this.Focus();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmUTLPublishMessage.SetMessage()\n" + ex.Message);
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
                MPCF.ShowMsgBox("frmFMBPublishMessage.btnClose_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBPublishMessage_Activated(object sender, System.EventArgs e)
        {
            
            try
            {
                if (b_load_flag == false)
                {
                    if (MPGV.gsMessage != "" && MPGV.gsMessage != txtMessage.Text)
                    {
                        txtMessage.Text = MPGV.gsMessage;
                        txtMessage.SelectionStart = txtMessage.TextLength;
                        txtMessage.ScrollToCaret();
                        ((frmMDIMainCore)MPGV.gfrmMDI).VisibleMessagePanel(false);
                    }
                    b_load_flag = true;
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBPublishMessage.frmFMBPublishMessage_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void frmFMBPublishMessage_Load(object sender, System.EventArgs e)
        {
            
            try
            {
                FMBCF.GetTextboxStyle(this.Controls);
                MPCF.ToClientLanguage(this);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBPublishMessage.frmFMBPublishMessage_Load()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        private void btnClear_Click(System.Object sender, System.EventArgs e)
        {
            
            try
            {
                txtMessage.Text = "";
                MPGV.gsMessage = "";
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBPublishMessage.btnClear_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            
        }
        
        #endregion
        
    }
    
}
