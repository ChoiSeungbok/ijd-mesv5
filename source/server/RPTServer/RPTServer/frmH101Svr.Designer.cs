namespace RPTServer
{
    partial class frmH101Svr
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmH101Svr));
            this.lblDeviceName = new System.Windows.Forms.Label();
            this.chkTop = new System.Windows.Forms.CheckBox();
            this.lblProcTimeLabel = new System.Windows.Forms.Label();
            this.btnClear = new System.Windows.Forms.Button();
            this.lblTranCountLabel = new System.Windows.Forms.Label();
            this.lblTranCount = new System.Windows.Forms.Label();
            this.btnExit = new System.Windows.Forms.Button();
            this.lblTranCountBox = new System.Windows.Forms.Label();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.lblProcessStatus = new System.Windows.Forms.Label();
            this.lblDiffTime = new System.Windows.Forms.Label();
            this.pnlTop = new System.Windows.Forms.Panel();
            this.lblProcTimeBox = new System.Windows.Forms.Label();
            this.btnShort = new System.Windows.Forms.Button();
            this.btnLong = new System.Windows.Forms.Button();
            this.pnlFill = new System.Windows.Forms.Panel();
            this.txtMessage = new System.Windows.Forms.RichTextBox();
            this.pnlBottom.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.pnlFill.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblDeviceName
            // 
            this.lblDeviceName.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblDeviceName.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblDeviceName.Font = new System.Drawing.Font("Verdana", 9F);
            this.lblDeviceName.Location = new System.Drawing.Point(1, 0);
            this.lblDeviceName.Name = "lblDeviceName";
            this.lblDeviceName.Size = new System.Drawing.Size(269, 18);
            this.lblDeviceName.TabIndex = 24;
            // 
            // chkTop
            // 
            this.chkTop.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.chkTop.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.chkTop.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkTop.Location = new System.Drawing.Point(3, 7);
            this.chkTop.Name = "chkTop";
            this.chkTop.Size = new System.Drawing.Size(42, 16);
            this.chkTop.TabIndex = 18;
            this.chkTop.Text = "Top";
            this.chkTop.CheckedChanged += new System.EventHandler(this.chkTop_CheckedChanged);
            // 
            // lblProcTimeLabel
            // 
            this.lblProcTimeLabel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblProcTimeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.lblProcTimeLabel.Location = new System.Drawing.Point(88, 20);
            this.lblProcTimeLabel.Name = "lblProcTimeLabel";
            this.lblProcTimeLabel.Size = new System.Drawing.Size(52, 17);
            this.lblProcTimeLabel.TabIndex = 17;
            this.lblProcTimeLabel.Text = "Proc Time";
            this.lblProcTimeLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnClear
            // 
            this.btnClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnClear.Location = new System.Drawing.Point(178, 3);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(45, 22);
            this.btnClear.TabIndex = 16;
            this.btnClear.Text = "Clear";
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // lblTranCountLabel
            // 
            this.lblTranCountLabel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblTranCountLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.lblTranCountLabel.Location = new System.Drawing.Point(11, 20);
            this.lblTranCountLabel.Name = "lblTranCountLabel";
            this.lblTranCountLabel.Size = new System.Drawing.Size(55, 17);
            this.lblTranCountLabel.TabIndex = 16;
            this.lblTranCountLabel.Text = "Tran Count";
            this.lblTranCountLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblTranCount
            // 
            this.lblTranCount.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.lblTranCount.Location = new System.Drawing.Point(7, 35);
            this.lblTranCount.Name = "lblTranCount";
            this.lblTranCount.Size = new System.Drawing.Size(68, 13);
            this.lblTranCount.TabIndex = 18;
            this.lblTranCount.Text = "0";
            this.lblTranCount.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // btnExit
            // 
            this.btnExit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnExit.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnExit.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnExit.Location = new System.Drawing.Point(225, 3);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(45, 22);
            this.btnExit.TabIndex = 17;
            this.btnExit.Text = "Exit";
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // lblTranCountBox
            // 
            this.lblTranCountBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblTranCountBox.Location = new System.Drawing.Point(5, 28);
            this.lblTranCountBox.Name = "lblTranCountBox";
            this.lblTranCountBox.Size = new System.Drawing.Size(72, 24);
            this.lblTranCountBox.TabIndex = 23;
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.chkTop);
            this.pnlBottom.Controls.Add(this.btnClear);
            this.pnlBottom.Controls.Add(this.btnExit);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 150);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Size = new System.Drawing.Size(271, 28);
            this.pnlBottom.TabIndex = 20;
            // 
            // lblProcessStatus
            // 
            this.lblProcessStatus.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblProcessStatus.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.lblProcessStatus.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblProcessStatus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblProcessStatus.Location = new System.Drawing.Point(229, 24);
            this.lblProcessStatus.Name = "lblProcessStatus";
            this.lblProcessStatus.Size = new System.Drawing.Size(26, 26);
            this.lblProcessStatus.TabIndex = 15;
            // 
            // lblDiffTime
            // 
            this.lblDiffTime.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblDiffTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.lblDiffTime.Location = new System.Drawing.Point(86, 35);
            this.lblDiffTime.Name = "lblDiffTime";
            this.lblDiffTime.Size = new System.Drawing.Size(66, 13);
            this.lblDiffTime.TabIndex = 21;
            this.lblDiffTime.Text = "0";
            this.lblDiffTime.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // pnlTop
            // 
            this.pnlTop.Controls.Add(this.lblDeviceName);
            this.pnlTop.Controls.Add(this.lblProcTimeLabel);
            this.pnlTop.Controls.Add(this.lblTranCountLabel);
            this.pnlTop.Controls.Add(this.lblTranCount);
            this.pnlTop.Controls.Add(this.lblProcessStatus);
            this.pnlTop.Controls.Add(this.lblTranCountBox);
            this.pnlTop.Controls.Add(this.lblDiffTime);
            this.pnlTop.Controls.Add(this.lblProcTimeBox);
            this.pnlTop.Controls.Add(this.btnShort);
            this.pnlTop.Controls.Add(this.btnLong);
            this.pnlTop.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTop.Location = new System.Drawing.Point(0, 0);
            this.pnlTop.Name = "pnlTop";
            this.pnlTop.Padding = new System.Windows.Forms.Padding(1, 0, 1, 0);
            this.pnlTop.Size = new System.Drawing.Size(271, 56);
            this.pnlTop.TabIndex = 19;
            // 
            // lblProcTimeBox
            // 
            this.lblProcTimeBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblProcTimeBox.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblProcTimeBox.Location = new System.Drawing.Point(84, 28);
            this.lblProcTimeBox.Name = "lblProcTimeBox";
            this.lblProcTimeBox.Size = new System.Drawing.Size(70, 24);
            this.lblProcTimeBox.TabIndex = 22;
            // 
            // btnShort
            // 
            this.btnShort.BackColor = System.Drawing.SystemColors.Control;
            this.btnShort.Cursor = System.Windows.Forms.Cursors.Default;
            this.btnShort.ForeColor = System.Drawing.SystemColors.ControlText;
            this.btnShort.Location = new System.Drawing.Point(167, 27);
            this.btnShort.Name = "btnShort";
            this.btnShort.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.btnShort.Size = new System.Drawing.Size(21, 21);
            this.btnShort.TabIndex = 19;
            this.btnShort.Text = "↑";
            this.btnShort.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnShort.UseVisualStyleBackColor = false;
            this.btnShort.Click += new System.EventHandler(this.btnShort_Click);
            // 
            // btnLong
            // 
            this.btnLong.BackColor = System.Drawing.SystemColors.Control;
            this.btnLong.Cursor = System.Windows.Forms.Cursors.Default;
            this.btnLong.ForeColor = System.Drawing.SystemColors.ControlText;
            this.btnLong.Location = new System.Drawing.Point(166, 27);
            this.btnLong.Name = "btnLong";
            this.btnLong.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.btnLong.Size = new System.Drawing.Size(21, 21);
            this.btnLong.TabIndex = 20;
            this.btnLong.Text = "↓";
            this.btnLong.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnLong.UseVisualStyleBackColor = false;
            this.btnLong.Click += new System.EventHandler(this.btnLong_Click);
            // 
            // pnlFill
            // 
            this.pnlFill.Controls.Add(this.txtMessage);
            this.pnlFill.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlFill.Location = new System.Drawing.Point(0, 56);
            this.pnlFill.Name = "pnlFill";
            this.pnlFill.Padding = new System.Windows.Forms.Padding(1);
            this.pnlFill.Size = new System.Drawing.Size(271, 94);
            this.pnlFill.TabIndex = 21;
            // 
            // txtMessage
            // 
            this.txtMessage.BackColor = System.Drawing.SystemColors.Control;
            this.txtMessage.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtMessage.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtMessage.Location = new System.Drawing.Point(1, 1);
            this.txtMessage.Name = "txtMessage";
            this.txtMessage.ReadOnly = true;
            this.txtMessage.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.None;
            this.txtMessage.Size = new System.Drawing.Size(269, 92);
            this.txtMessage.TabIndex = 1;
            this.txtMessage.Text = "";
            this.txtMessage.WordWrap = false;
            // 
            // frmH101Svr
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(271, 178);
            this.Controls.Add(this.pnlFill);
            this.Controls.Add(this.pnlTop);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "frmH101Svr";
            this.Text = "RPTServer";
            this.pnlBottom.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.pnlFill.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        internal System.Windows.Forms.Label lblDeviceName;
        private System.Windows.Forms.CheckBox chkTop;
        private System.Windows.Forms.Label lblProcTimeLabel;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Label lblTranCountLabel;
        private System.Windows.Forms.Label lblTranCount;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Label lblTranCountBox;
        private System.Windows.Forms.Panel pnlBottom;
        private System.Windows.Forms.Label lblProcessStatus;
        private System.Windows.Forms.Label lblDiffTime;
        private System.Windows.Forms.Panel pnlTop;
        private System.Windows.Forms.Label lblProcTimeBox;
        private System.Windows.Forms.Button btnShort;
        private System.Windows.Forms.Button btnLong;
        private System.Windows.Forms.Panel pnlFill;
        private System.Windows.Forms.RichTextBox txtMessage;
    }
}

