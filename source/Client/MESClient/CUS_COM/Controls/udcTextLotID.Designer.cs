namespace CUS_COM.Controls
{
    partial class udcTextLotID
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

        #region 구성 요소 디자이너에서 생성한 코드

        /// <summary> 
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            Infragistics.Win.Appearance appearance23 = new Infragistics.Win.Appearance();
            this.txtLotID = new System.Windows.Forms.TextBox();
            this.lblLotId = new System.Windows.Forms.Label();
            this.btnPop = new Infragistics.Win.Misc.UltraButton();
            this.panInfo = new System.Windows.Forms.Panel();
            this.panInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtLotID
            // 
            this.txtLotID.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.txtLotID.Location = new System.Drawing.Point(62, 6);
            this.txtLotID.Name = "txtLotID";
            this.txtLotID.Size = new System.Drawing.Size(167, 26);
            this.txtLotID.TabIndex = 253;
            this.txtLotID.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtLotID_KeyPress);
            // 
            // lblLotId
            // 
            this.lblLotId.AutoSize = true;
            this.lblLotId.BackColor = System.Drawing.Color.White;
            this.lblLotId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLotId.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblLotId.ForeColor = System.Drawing.Color.Black;
            this.lblLotId.Location = new System.Drawing.Point(2, 11);
            this.lblLotId.Name = "lblLotId";
            this.lblLotId.Size = new System.Drawing.Size(56, 16);
            this.lblLotId.TabIndex = 252;
            this.lblLotId.Text = "LOT ID";
            this.lblLotId.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // btnPop
            // 
            appearance23.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(231)))), ((int)(((byte)(240)))), ((int)(((byte)(248)))));
            appearance23.BackColor2 = System.Drawing.Color.Transparent;
            appearance23.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            appearance23.FontData.BoldAsString = "True";
            appearance23.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.btnPop.Appearance = appearance23;
            this.btnPop.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPop.Location = new System.Drawing.Point(231, 6);
            this.btnPop.Name = "btnPop";
            this.btnPop.Size = new System.Drawing.Size(48, 26);
            this.btnPop.TabIndex = 254;
            this.btnPop.Text = "Open";
            this.btnPop.UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
            this.btnPop.UseOsThemes = Infragistics.Win.DefaultableBoolean.False;
            this.btnPop.Click += new System.EventHandler(this.btnPop_Click);
            // 
            // panInfo
            // 
            this.panInfo.Controls.Add(this.txtLotID);
            this.panInfo.Controls.Add(this.btnPop);
            this.panInfo.Controls.Add(this.lblLotId);
            this.panInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panInfo.Location = new System.Drawing.Point(0, 0);
            this.panInfo.Name = "panInfo";
            this.panInfo.Size = new System.Drawing.Size(285, 39);
            this.panInfo.TabIndex = 255;
            // 
            // udcTextLotID
            // 
            this.BackColor = System.Drawing.Color.White;
            this.Controls.Add(this.panInfo);
            this.Name = "udcTextLotID";
            this.Size = new System.Drawing.Size(285, 39);
            this.panInfo.ResumeLayout(false);
            this.panInfo.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        public System.Windows.Forms.Label lblLotId;
        public System.Windows.Forms.TextBox txtLotID;
        public Infragistics.Win.Misc.UltraButton btnPop;
        private System.Windows.Forms.Panel panInfo;
    }
}
