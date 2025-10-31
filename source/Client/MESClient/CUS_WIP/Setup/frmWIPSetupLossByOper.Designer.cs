namespace CUS_WIP
{
    partial class frmWIPSetupLossByOper
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmWIPSetupLossByOper));
            this.pnlAttachLossFill = new System.Windows.Forms.Panel();
            this.pnlLossList = new System.Windows.Forms.Panel();
            this.lisLossList = new Miracom.UI.Controls.MCListView.MCListView();
            this.colLossCode = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colLossDesc = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.pnlAttachLoss = new System.Windows.Forms.Panel();
            this.lisAttachLoss = new Miracom.UI.Controls.MCListView.MCListView();
            this.colAttachLossCode = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colAttachLossDesc = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.pnlAttachLossMid = new System.Windows.Forms.Panel();
            this.btnDown = new System.Windows.Forms.Button();
            this.btnUp = new System.Windows.Forms.Button();
            this.btnToRight = new System.Windows.Forms.Button();
            this.btnToLeft = new System.Windows.Forms.Button();
            this.colOper = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colOperDesc = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.lisOperList = new Miracom.UI.Controls.MCListView.MCListView();
            this.btnGCM = new System.Windows.Forms.Button();
            this.pnlFind.SuspendLayout();
            this.pnlRight.SuspendLayout();
            this.pnlFilter.SuspendLayout();
            this.grpFilter.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlAttachLossFill.SuspendLayout();
            this.pnlLossList.SuspendLayout();
            this.pnlAttachLoss.SuspendLayout();
            this.pnlAttachLossMid.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnExcel
            // 
            this.btnExcel.Click += new System.EventHandler(this.btnExcel_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Click += new System.EventHandler(this.btnRefresh_Click);
            // 
            // btnNext
            // 
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // txtFind
            // 
            this.txtFind.TextChanged += new System.EventHandler(this.txtFind_TextChanged);
            // 
            // splMain
            // 
            this.splMain.Size = new System.Drawing.Size(4, 501);
            // 
            // pnlRight
            // 
            this.pnlRight.Controls.Add(this.pnlAttachLossFill);
            this.pnlRight.Size = new System.Drawing.Size(498, 501);
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.lisOperList);
            this.pnlLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlLeft.Size = new System.Drawing.Size(232, 501);
            // 
            // btnCreate
            // 
            this.btnCreate.Location = new System.Drawing.Point(231, 6);
            this.btnCreate.Size = new System.Drawing.Size(10, 26);
            this.btnCreate.Visible = false;
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(246, 6);
            this.btnDelete.Size = new System.Drawing.Size(10, 26);
            this.btnDelete.Visible = false;
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(518, 7);
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(626, 7);
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnGCM);
            this.pnlBottom.Location = new System.Drawing.Point(0, 501);
            this.pnlBottom.Size = new System.Drawing.Size(734, 40);
            this.pnlBottom.Controls.SetChildIndex(this.btnClose, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnUpdate, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnDelete, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnCreate, 0);
            this.pnlBottom.Controls.SetChildIndex(this.pnlFind, 0);
            this.pnlBottom.Controls.SetChildIndex(this.btnGCM, 0);
            // 
            // pnlCenter
            // 
            this.pnlCenter.Size = new System.Drawing.Size(734, 501);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Text = "SetupForm02";
            // 
            // pnlAttachLossFill
            // 
            this.pnlAttachLossFill.Controls.Add(this.pnlLossList);
            this.pnlAttachLossFill.Controls.Add(this.pnlAttachLoss);
            this.pnlAttachLossFill.Controls.Add(this.pnlAttachLossMid);
            this.pnlAttachLossFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlAttachLossFill.Location = new System.Drawing.Point(0, 0);
            this.pnlAttachLossFill.Name = "pnlAttachLossFill";
            this.pnlAttachLossFill.Padding = new System.Windows.Forms.Padding(0, 5, 0, 0);
            this.pnlAttachLossFill.Size = new System.Drawing.Size(498, 501);
            this.pnlAttachLossFill.TabIndex = 1;
            this.pnlAttachLossFill.Resize += new System.EventHandler(this.pnlAttachOperFill_Resize);
            // 
            // pnlLossList
            // 
            this.pnlLossList.Controls.Add(this.lisLossList);
            this.pnlLossList.Location = new System.Drawing.Point(272, 8);
            this.pnlLossList.Name = "pnlLossList";
            this.pnlLossList.Size = new System.Drawing.Size(216, 487);
            this.pnlLossList.TabIndex = 6;
            // 
            // lisLossList
            // 
            this.lisLossList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colLossCode,
            this.colLossDesc});
            this.lisLossList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisLossList.EnableSort = true;
            this.lisLossList.EnableSortIcon = true;
            this.lisLossList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisLossList.FullRowSelect = true;
            this.lisLossList.Location = new System.Drawing.Point(0, 0);
            this.lisLossList.Name = "lisLossList";
            this.lisLossList.Size = new System.Drawing.Size(216, 487);
            this.lisLossList.TabIndex = 1;
            this.lisLossList.UseCompatibleStateImageBehavior = false;
            this.lisLossList.View = System.Windows.Forms.View.Details;
            // 
            // colLossCode
            // 
            this.colLossCode.Text = "Loss Code";
            this.colLossCode.Width = 68;
            // 
            // colLossDesc
            // 
            this.colLossDesc.Text = "Description";
            this.colLossDesc.Width = 129;
            // 
            // pnlAttachLoss
            // 
            this.pnlAttachLoss.Controls.Add(this.lisAttachLoss);
            this.pnlAttachLoss.Location = new System.Drawing.Point(10, 8);
            this.pnlAttachLoss.Name = "pnlAttachLoss";
            this.pnlAttachLoss.Size = new System.Drawing.Size(192, 487);
            this.pnlAttachLoss.TabIndex = 3;
            // 
            // lisAttachLoss
            // 
            this.lisAttachLoss.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colAttachLossCode,
            this.colAttachLossDesc});
            this.lisAttachLoss.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisAttachLoss.EnableSort = false;
            this.lisAttachLoss.EnableSortIcon = false;
            this.lisAttachLoss.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisAttachLoss.FullRowSelect = true;
            this.lisAttachLoss.Location = new System.Drawing.Point(0, 0);
            this.lisAttachLoss.Name = "lisAttachLoss";
            this.lisAttachLoss.Size = new System.Drawing.Size(192, 487);
            this.lisAttachLoss.TabIndex = 0;
            this.lisAttachLoss.UseCompatibleStateImageBehavior = false;
            this.lisAttachLoss.View = System.Windows.Forms.View.Details;
            // 
            // colAttachLossCode
            // 
            this.colAttachLossCode.Text = "Loss Code";
            this.colAttachLossCode.Width = 69;
            // 
            // colAttachLossDesc
            // 
            this.colAttachLossDesc.Text = "Description";
            this.colAttachLossDesc.Width = 128;
            // 
            // pnlAttachLossMid
            // 
            this.pnlAttachLossMid.Controls.Add(this.btnDown);
            this.pnlAttachLossMid.Controls.Add(this.btnUp);
            this.pnlAttachLossMid.Controls.Add(this.btnToRight);
            this.pnlAttachLossMid.Controls.Add(this.btnToLeft);
            this.pnlAttachLossMid.Location = new System.Drawing.Point(212, 64);
            this.pnlAttachLossMid.Name = "pnlAttachLossMid";
            this.pnlAttachLossMid.Size = new System.Drawing.Size(46, 277);
            this.pnlAttachLossMid.TabIndex = 4;
            // 
            // btnDown
            // 
            this.btnDown.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnDown.Image = ((System.Drawing.Image)(resources.GetObject("btnDown.Image")));
            this.btnDown.Location = new System.Drawing.Point(11, 214);
            this.btnDown.Name = "btnDown";
            this.btnDown.Size = new System.Drawing.Size(24, 24);
            this.btnDown.TabIndex = 9;
            this.btnDown.UseVisualStyleBackColor = true;
            this.btnDown.Click += new System.EventHandler(this.btnDown_Click);
            // 
            // btnUp
            // 
            this.btnUp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnUp.Image = ((System.Drawing.Image)(resources.GetObject("btnUp.Image")));
            this.btnUp.Location = new System.Drawing.Point(11, 184);
            this.btnUp.Name = "btnUp";
            this.btnUp.Size = new System.Drawing.Size(24, 24);
            this.btnUp.TabIndex = 8;
            this.btnUp.UseVisualStyleBackColor = true;
            this.btnUp.Click += new System.EventHandler(this.btnUp_Click);
            // 
            // btnToRight
            // 
            this.btnToRight.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnToRight.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnToRight.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnToRight.Location = new System.Drawing.Point(11, 141);
            this.btnToRight.Name = "btnToRight";
            this.btnToRight.Size = new System.Drawing.Size(24, 24);
            this.btnToRight.TabIndex = 5;
            this.btnToRight.Text = ">";
            this.btnToRight.Click += new System.EventHandler(this.btnToRight_Click);
            // 
            // btnToLeft
            // 
            this.btnToLeft.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnToLeft.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnToLeft.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnToLeft.Location = new System.Drawing.Point(11, 112);
            this.btnToLeft.Name = "btnToLeft";
            this.btnToLeft.Size = new System.Drawing.Size(24, 24);
            this.btnToLeft.TabIndex = 4;
            this.btnToLeft.Text = "< ";
            this.btnToLeft.Click += new System.EventHandler(this.btnToLeft_Click);
            // 
            // colOper
            // 
            this.colOper.Text = "Operation";
            this.colOper.Width = 69;
            // 
            // colOperDesc
            // 
            this.colOperDesc.Text = "Description";
            this.colOperDesc.Width = 128;
            // 
            // lisOperList
            // 
            this.lisOperList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colOper,
            this.colOperDesc});
            this.lisOperList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lisOperList.EnableSort = false;
            this.lisOperList.EnableSortIcon = false;
            this.lisOperList.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lisOperList.FullRowSelect = true;
            this.lisOperList.Location = new System.Drawing.Point(0, 0);
            this.lisOperList.Name = "lisOperList";
            this.lisOperList.Size = new System.Drawing.Size(232, 501);
            this.lisOperList.TabIndex = 1;
            this.lisOperList.UseCompatibleStateImageBehavior = false;
            this.lisOperList.View = System.Windows.Forms.View.Details;
            this.lisOperList.SelectedIndexChanged += new System.EventHandler(this.lisOperList_SelectedIndexChanged);
            // 
            // btnGCM
            // 
            this.btnGCM.Location = new System.Drawing.Point(385, 8);
            this.btnGCM.Name = "btnGCM";
            this.btnGCM.Size = new System.Drawing.Size(125, 25);
            this.btnGCM.TabIndex = 5;
            this.btnGCM.Text = "Loss Code Add";
            this.btnGCM.UseVisualStyleBackColor = true;
            this.btnGCM.Click += new System.EventHandler(this.btnGCM_Click);
            // 
            // frmWIPSetupLossByOper
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(734, 541);
            this.Name = "frmWIPSetupLossByOper";
            this.Text = "Loss by operation Setup";
            this.Load += new System.EventHandler(this.frmWIPSetupLossByOper_Load);
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
            this.pnlAttachLossFill.ResumeLayout(false);
            this.pnlLossList.ResumeLayout(false);
            this.pnlAttachLoss.ResumeLayout(false);
            this.pnlAttachLossMid.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlAttachLossFill;
        private System.Windows.Forms.Panel pnlLossList;
        private System.Windows.Forms.Panel pnlAttachLoss;
        private System.Windows.Forms.Panel pnlAttachLossMid;
        private System.Windows.Forms.Button btnToRight;
        private System.Windows.Forms.Button btnToLeft;
        private Miracom.UI.Controls.MCListView.MCListView lisLossList;
        private System.Windows.Forms.ColumnHeader colLossCode;
        private System.Windows.Forms.ColumnHeader colLossDesc;
        private Miracom.UI.Controls.MCListView.MCListView lisAttachLoss;
        private System.Windows.Forms.ColumnHeader colAttachLossCode;
        private System.Windows.Forms.ColumnHeader colAttachLossDesc;
        private Miracom.UI.Controls.MCListView.MCListView lisOperList;
        private System.Windows.Forms.ColumnHeader colOper;
        private System.Windows.Forms.ColumnHeader colOperDesc;
        private System.Windows.Forms.Button btnDown;
        private System.Windows.Forms.Button btnUp;
        private System.Windows.Forms.Button btnGCM;
    }
}