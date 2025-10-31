namespace MESClient
{
    partial class frmLogin
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlfactorys = new System.Windows.Forms.Panel();
            this.rdoIJDV1 = new System.Windows.Forms.RadioButton();
            this.rdoIJDK1 = new System.Windows.Forms.RadioButton();
            this.chkSavePwd = new System.Windows.Forms.CheckBox();
            this.ChkReloadFun = new System.Windows.Forms.CheckBox();
            this.pnlMain.SuspendLayout();
            this.pnlfactorys.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtFactory
            // 
            this.txtFactory.Location = new System.Drawing.Point(319, 218);
            // 
            // txtUserID
            // 
            this.txtUserID.Location = new System.Drawing.Point(319, 244);
            this.txtUserID.TextChanged += new System.EventHandler(this.txtUserID_TextChanged);
            // 
            // txtPassword
            // 
            this.txtPassword.Location = new System.Drawing.Point(319, 270);
            // 
            // btnOption
            // 
            this.btnOption.Location = new System.Drawing.Point(186, 313);
            this.btnOption.Click += new System.EventHandler(this.btnOption_Click);
            // 
            // btnOK
            // 
            this.btnOK.Location = new System.Drawing.Point(274, 313);
            // 
            // btnExit
            // 
            this.btnExit.Location = new System.Drawing.Point(362, 313);
            // 
            // lblFactory
            // 
            this.lblFactory.Location = new System.Drawing.Point(239, 222);
            // 
            // lblUserID
            // 
            this.lblUserID.Location = new System.Drawing.Point(239, 248);
            // 
            // lblVersion
            // 
            this.lblVersion.Location = new System.Drawing.Point(13, 320);
            // 
            // txtSiteID
            // 
            this.txtSiteID.Location = new System.Drawing.Point(319, 192);
            // 
            // lblSiteID
            // 
            this.lblSiteID.Location = new System.Drawing.Point(239, 196);
            // 
            // pnlMain
            // 
            this.pnlMain.Controls.Add(this.ChkReloadFun);
            this.pnlMain.Controls.Add(this.chkSavePwd);
            this.pnlMain.Controls.Add(this.pnlfactorys);
            this.pnlMain.Controls.SetChildIndex(this.btnOption, 0);
            this.pnlMain.Controls.SetChildIndex(this.btnOK, 0);
            this.pnlMain.Controls.SetChildIndex(this.btnExit, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblFactory, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblUserID, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblPassword, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtFactory, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtUserID, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtPassword, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblVersion, 0);
            this.pnlMain.Controls.SetChildIndex(this.lblSiteID, 0);
            this.pnlMain.Controls.SetChildIndex(this.txtSiteID, 0);
            this.pnlMain.Controls.SetChildIndex(this.pnlfactorys, 0);
            this.pnlMain.Controls.SetChildIndex(this.chkSavePwd, 0);
            this.pnlMain.Controls.SetChildIndex(this.ChkReloadFun, 0);
            // 
            // lblPassword
            // 
            this.lblPassword.Location = new System.Drawing.Point(239, 274);
            // 
            // pnlfactorys
            // 
            this.pnlfactorys.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pnlfactorys.Controls.Add(this.rdoIJDV1);
            this.pnlfactorys.Controls.Add(this.rdoIJDK1);
            this.pnlfactorys.Location = new System.Drawing.Point(8, 197);
            this.pnlfactorys.Name = "pnlfactorys";
            this.pnlfactorys.Size = new System.Drawing.Size(208, 30);
            this.pnlfactorys.TabIndex = 325;
            // 
            // rdoIJDV1
            // 
            this.rdoIJDV1.AutoSize = true;
            this.rdoIJDV1.Location = new System.Drawing.Point(99, 3);
            this.rdoIJDV1.Name = "rdoIJDV1";
            this.rdoIJDV1.Size = new System.Drawing.Size(102, 17);
            this.rdoIJDV1.TabIndex = 1;
            this.rdoIJDV1.TabStop = true;
            this.rdoIJDV1.Text = "베트남(Vietnam)";
            this.rdoIJDV1.UseVisualStyleBackColor = true;
            this.rdoIJDV1.CheckedChanged += new System.EventHandler(this.rdoIJDV1_CheckedChanged);
            // 
            // rdoIJDK1
            // 
            this.rdoIJDK1.AutoSize = true;
            this.rdoIJDK1.Location = new System.Drawing.Point(6, 2);
            this.rdoIJDK1.Name = "rdoIJDK1";
            this.rdoIJDK1.Size = new System.Drawing.Size(81, 17);
            this.rdoIJDK1.TabIndex = 0;
            this.rdoIJDK1.TabStop = true;
            this.rdoIJDK1.Text = "한국(Korea)";
            this.rdoIJDK1.UseVisualStyleBackColor = true;
            this.rdoIJDK1.CheckedChanged += new System.EventHandler(this.rdoIJDK1_CheckedChanged);
            // 
            // chkSavePwd
            // 
            this.chkSavePwd.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.chkSavePwd.AutoSize = true;
            this.chkSavePwd.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.chkSavePwd.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F);
            this.chkSavePwd.Location = new System.Drawing.Point(347, 293);
            this.chkSavePwd.Name = "chkSavePwd";
            this.chkSavePwd.Size = new System.Drawing.Size(100, 17);
            this.chkSavePwd.TabIndex = 326;
            this.chkSavePwd.Text = "Save Password";
            this.chkSavePwd.UseVisualStyleBackColor = true;
            this.chkSavePwd.CheckedChanged += new System.EventHandler(this.chkSavePwd_CheckedChanged);
            // 
            // ChkReloadFun
            // 
            this.ChkReloadFun.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.ChkReloadFun.AutoSize = true;
            this.ChkReloadFun.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ChkReloadFun.Font = new System.Drawing.Font("Microsoft Sans Serif", 7F);
            this.ChkReloadFun.Location = new System.Drawing.Point(137, 293);
            this.ChkReloadFun.Name = "ChkReloadFun";
            this.ChkReloadFun.Size = new System.Drawing.Size(192, 17);
            this.ChkReloadFun.TabIndex = 327;
            this.ChkReloadFun.Text = "이전화면 자동오픈(Last Page Open)";
            this.ChkReloadFun.UseVisualStyleBackColor = true;
            this.ChkReloadFun.CheckedChanged += new System.EventHandler(this.ChkReloadFun_CheckedChanged);
            // 
            // frmLogin
            // 
            this.ClientSize = new System.Drawing.Size(456, 344);
            this.Name = "frmLogin";
            this.Load += new System.EventHandler(this.frmLogin_Load);
            this.pnlMain.ResumeLayout(false);
            this.pnlMain.PerformLayout();
            this.pnlfactorys.ResumeLayout(false);
            this.pnlfactorys.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlfactorys;
        private System.Windows.Forms.RadioButton rdoIJDV1;
        private System.Windows.Forms.RadioButton rdoIJDK1;
        private System.Windows.Forms.CheckBox chkSavePwd;
        private System.Windows.Forms.CheckBox ChkReloadFun;
    }
}