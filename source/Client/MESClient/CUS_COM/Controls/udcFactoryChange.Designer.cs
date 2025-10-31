namespace CUS_COM.Controls
{
    partial class udcFactoryChange
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
            this.pnlUvFactory = new System.Windows.Forms.Panel();
            this.rdUvIJDV1 = new System.Windows.Forms.RadioButton();
            this.rdUvIJDK1 = new System.Windows.Forms.RadioButton();
            this.pnlUvFactory.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlUvFactory
            // 
            this.pnlUvFactory.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pnlUvFactory.Controls.Add(this.rdUvIJDV1);
            this.pnlUvFactory.Controls.Add(this.rdUvIJDK1);
            this.pnlUvFactory.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlUvFactory.Location = new System.Drawing.Point(0, 0);
            this.pnlUvFactory.Name = "pnlUvFactory";
            this.pnlUvFactory.Size = new System.Drawing.Size(239, 39);
            this.pnlUvFactory.TabIndex = 326;
            // 
            // rdUvIJDV1
            // 
            this.rdUvIJDV1.AutoSize = true;
            this.rdUvIJDV1.Dock = System.Windows.Forms.DockStyle.Right;
            this.rdUvIJDV1.Location = new System.Drawing.Point(120, 0);
            this.rdUvIJDV1.Name = "rdUvIJDV1";
            this.rdUvIJDV1.Size = new System.Drawing.Size(115, 35);
            this.rdUvIJDV1.TabIndex = 1;
            this.rdUvIJDV1.TabStop = true;
            this.rdUvIJDV1.Text = "베트남(Vietnam)";
            this.rdUvIJDV1.UseVisualStyleBackColor = true;
            this.rdUvIJDV1.CheckedChanged += new System.EventHandler(this.rdUvIJDV1_CheckedChanged);
            // 
            // rdUvIJDK1
            // 
            this.rdUvIJDK1.AutoSize = true;
            this.rdUvIJDK1.Dock = System.Windows.Forms.DockStyle.Left;
            this.rdUvIJDK1.Location = new System.Drawing.Point(0, 0);
            this.rdUvIJDK1.Name = "rdUvIJDK1";
            this.rdUvIJDK1.Size = new System.Drawing.Size(90, 35);
            this.rdUvIJDK1.TabIndex = 0;
            this.rdUvIJDK1.TabStop = true;
            this.rdUvIJDK1.Text = "한국(Korea)";
            this.rdUvIJDK1.UseVisualStyleBackColor = true;
            this.rdUvIJDK1.CheckedChanged += new System.EventHandler(this.rdUvIJDK1_CheckedChanged);
            // 
            // udcFactoryChange
            // 
            this.BackColor = System.Drawing.Color.White;
            this.Controls.Add(this.pnlUvFactory);
            this.Name = "udcFactoryChange";
            this.Size = new System.Drawing.Size(239, 39);
            this.pnlUvFactory.ResumeLayout(false);
            this.pnlUvFactory.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Panel pnlUvFactory;
        private System.Windows.Forms.RadioButton rdUvIJDV1;
        private System.Windows.Forms.RadioButton rdUvIJDK1;
    }
}
