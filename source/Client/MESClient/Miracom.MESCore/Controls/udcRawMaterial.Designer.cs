namespace Miracom.MESCore.Controls
{
    partial class udcRawMaterial
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
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlMaterial = new System.Windows.Forms.Panel();
            this.cdvMat = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            this.lblMat = new System.Windows.Forms.Label();
            this.pnlMid = new System.Windows.Forms.Panel();
            this.txtDesc = new System.Windows.Forms.TextBox();
            this.pnlLeft = new System.Windows.Forms.Panel();
            this.pnlLabel = new System.Windows.Forms.Panel();
            this.pnlMaterial.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvMat)).BeginInit();
            this.pnlMid.SuspendLayout();
            this.pnlLeft.SuspendLayout();
            this.pnlLabel.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlMaterial
            // 
            this.pnlMaterial.Controls.Add(this.cdvMat);
            this.pnlMaterial.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMaterial.Location = new System.Drawing.Point(60, 0);
            this.pnlMaterial.Name = "pnlMaterial";
            this.pnlMaterial.Size = new System.Drawing.Size(150, 23);
            this.pnlMaterial.TabIndex = 1;
            // 
            // cdvMat
            // 
            this.cdvMat.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvMat.BorderHotColor = System.Drawing.Color.Black;
            this.cdvMat.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvMat.BtnToolTipText = "";
            this.cdvMat.DescText = "";
            this.cdvMat.DisplaySubItemIndex = -1;
            this.cdvMat.DisplayText = "";
            this.cdvMat.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cdvMat.Focusing = null;
            this.cdvMat.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvMat.Index = 0;
            this.cdvMat.IsViewBtnImage = false;
            this.cdvMat.Location = new System.Drawing.Point(0, 0);
            this.cdvMat.MaxLength = 30;
            this.cdvMat.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvMat.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvMat.Name = "cdvMat";
            this.cdvMat.ReadOnly = false;
            this.cdvMat.SearchSubItemIndex = 0;
            this.cdvMat.SelectedDescIndex = -1;
            this.cdvMat.SelectedSubItemIndex = -1;
            this.cdvMat.SelectionStart = 0;
            this.cdvMat.Size = new System.Drawing.Size(150, 23);
            this.cdvMat.SmallImageList = null;
            this.cdvMat.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvMat.TabIndex = 0;
            this.cdvMat.TextBoxToolTipText = "";
            this.cdvMat.TextBoxWidth = 150;
            this.cdvMat.VisibleButton = true;
            this.cdvMat.VisibleColumnHeader = false;
            this.cdvMat.VisibleDescription = false;
            this.cdvMat.ButtonPress += new System.EventHandler(this.cdvMat_ButtonPress);
            // 
            // lblMat
            // 
            this.lblMat.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblMat.Location = new System.Drawing.Point(0, 3);
            this.lblMat.Name = "lblMat";
            this.lblMat.Size = new System.Drawing.Size(60, 14);
            this.lblMat.TabIndex = 0;
            this.lblMat.Text = "Material";
            this.lblMat.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.txtDesc);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(210, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(8, 0, 0, 0);
            this.pnlMid.Size = new System.Drawing.Size(2, 23);
            this.pnlMid.TabIndex = 3;
            // 
            // txtDesc
            // 
            this.txtDesc.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtDesc.Location = new System.Drawing.Point(8, 0);
            this.txtDesc.Multiline = true;
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.ReadOnly = true;
            this.txtDesc.Size = new System.Drawing.Size(0, 23);
            this.txtDesc.TabIndex = 0;
            // 
            // pnlLeft
            // 
            this.pnlLeft.Controls.Add(this.pnlMaterial);
            this.pnlLeft.Controls.Add(this.pnlLabel);
            this.pnlLeft.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLeft.Location = new System.Drawing.Point(0, 0);
            this.pnlLeft.Name = "pnlLeft";
            this.pnlLeft.Size = new System.Drawing.Size(210, 23);
            this.pnlLeft.TabIndex = 2;
            // 
            // pnlLabel
            // 
            this.pnlLabel.Controls.Add(this.lblMat);
            this.pnlLabel.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLabel.Location = new System.Drawing.Point(0, 0);
            this.pnlLabel.Name = "pnlLabel";
            this.pnlLabel.Size = new System.Drawing.Size(60, 23);
            this.pnlLabel.TabIndex = 0;
            // 
            // udcRawMaterial
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlLeft);
            this.Name = "udcRawMaterial";
            this.Size = new System.Drawing.Size(212, 23);
            this.pnlMaterial.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cdvMat)).EndInit();
            this.pnlMid.ResumeLayout(false);
            this.pnlMid.PerformLayout();
            this.pnlLeft.ResumeLayout(false);
            this.pnlLabel.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlMaterial;
        private UI.Controls.MCCodeView.MCCodeView cdvMat;
        private System.Windows.Forms.Label lblMat;
        private System.Windows.Forms.Panel pnlMid;
        private System.Windows.Forms.TextBox txtDesc;
        private System.Windows.Forms.Panel pnlLeft;
        private System.Windows.Forms.Panel pnlLabel;


    }
}
