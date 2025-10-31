using Miracom.UI;
using Miracom.CliFrx;

namespace CUS_COM.Controls
{
    partial class udcCodeReg
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
            this.cdvCodeReg = new Miracom.UI.Controls.MCCodeView.MCCodeView();
            ((System.ComponentModel.ISupportInitialize)(this.cdvCodeReg)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this)).BeginInit();
            this.SuspendLayout();
            // 
            // cdvCodeReg
            // 
            this.cdvCodeReg.BorderColor = System.Drawing.Color.DarkGray;
            this.cdvCodeReg.BorderHotColor = System.Drawing.Color.Black;
            this.cdvCodeReg.BtnFlatStyle = System.Windows.Forms.FlatStyle.System;
            this.cdvCodeReg.BtnToolTipText = "Get flow list";
            this.cdvCodeReg.ButtonWidth = 25;
            this.cdvCodeReg.DescText = "";
            this.cdvCodeReg.DisplaySubItemIndex = -1;
            this.cdvCodeReg.DisplayText = "";
            this.cdvCodeReg.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cdvCodeReg.Focusing = null;
            this.cdvCodeReg.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cdvCodeReg.Index = 0;
            this.cdvCodeReg.IsViewBtnImage = false;
            this.cdvCodeReg.Location = new System.Drawing.Point(0, 0);
            this.cdvCodeReg.MaxLength = 20;
            this.cdvCodeReg.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvCodeReg.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            this.cdvCodeReg.MultiSelect = false;
            this.cdvCodeReg.Name = "cdvCodeReg";
            this.cdvCodeReg.ReadOnly = false;
            this.cdvCodeReg.SameWidthHeightOfButton = false;
            this.cdvCodeReg.SearchSubItemIndex = 0;
            this.cdvCodeReg.SelectedDescIndex = -1;
            this.cdvCodeReg.SelectedDescToQueryText = "";
            this.cdvCodeReg.SelectedSubItemIndex = -1;
            this.cdvCodeReg.SelectedValueToQueryText = "";
            this.cdvCodeReg.SelectionStart = 0;
            this.cdvCodeReg.Size = new System.Drawing.Size(115, 21);
            this.cdvCodeReg.SmallImageList = null;
            this.cdvCodeReg.StyleBorder = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cdvCodeReg.TabIndex = 1;
            this.cdvCodeReg.TabStop = false;
            this.cdvCodeReg.TextBoxToolTipText = "";
            this.cdvCodeReg.TextBoxWidth = 115;
            this.cdvCodeReg.VisibleButton = true;
            this.cdvCodeReg.VisibleColumnHeader = false;
            this.cdvCodeReg.VisibleDescription = false;
            // 
            // udcCodeReg
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.cdvCodeReg);
            this.MCViewStyle.BorderColor = System.Drawing.Color.DarkGray;
            this.MCViewStyle.BorderHotColor = System.Drawing.Color.Black;
            this.Name = "udcCodeReg";
            this.Size = new System.Drawing.Size(115, 21);
            this.TextBoxWidth = 115;
            this.Controls.SetChildIndex(this.cdvCodeReg, 0);
            ((System.ComponentModel.ISupportInitialize)(this.cdvCodeReg)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Miracom.UI.Controls.MCCodeView.MCCodeView cdvCodeReg;
    }
}
