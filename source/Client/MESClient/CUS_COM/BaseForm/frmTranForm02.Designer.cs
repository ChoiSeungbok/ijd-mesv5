namespace CUS_COM
{
    partial class frmTranForm02
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
            this.dtpFromDate = new System.Windows.Forms.DateTimePicker();
            this.label1 = new System.Windows.Forms.Label();
            this.dtpToDate = new System.Windows.Forms.DateTimePicker();
            this.label2 = new System.Windows.Forms.Label();
            this.pnlStsCond.SuspendLayout();
            this.pnlMID.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).BeginInit();
            this.pnlBottom.SuspendLayout();
            this.pnlCenter.SuspendLayout();
            this.pnlTop.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlStsCond
            // 
            this.pnlStsCond.Controls.Add(this.label2);
            this.pnlStsCond.Controls.Add(this.dtpToDate);
            this.pnlStsCond.Controls.Add(this.label1);
            this.pnlStsCond.Controls.Add(this.dtpFromDate);
            this.pnlStsCond.Size = new System.Drawing.Size(1219, 98);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond2, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.pnlStsCond3, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvDept, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblDept, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvWorkPlace, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblWorkPlace, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.cdvOper, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.lblOper, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.dtpFromDate, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.label1, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.dtpToDate, 0);
            this.pnlStsCond.Controls.SetChildIndex(this.label2, 0);
            // 
            // pnlStsCond3
            // 
            this.pnlStsCond3.Location = new System.Drawing.Point(0, 88);
            // 
            // lblFormName
            // 
            this.lblFormName.Location = new System.Drawing.Point(10, 17);
            // 
            // cdvOper
            // 
            this.cdvOper.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvOper.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            // 
            // cdvWorkPlace
            // 
            this.cdvWorkPlace.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvWorkPlace.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            // 
            // cdvDept
            // 
            this.cdvDept.MCViewStyle.BorderColor = System.Drawing.SystemColors.Control;
            this.cdvDept.MCViewStyle.BorderHotColor = System.Drawing.SystemColors.Control;
            // 
            // pnlTop
            // 
            this.pnlTop.Size = new System.Drawing.Size(1239, 0);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Size = new System.Drawing.Size(1235, 0);
            this.lblFormTitle.Text = "TranForm01";
            // 
            // dtpFromDate
            // 
            this.dtpFromDate.CalendarFont = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.dtpFromDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.dtpFromDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpFromDate.Location = new System.Drawing.Point(109, 50);
            this.dtpFromDate.Name = "dtpFromDate";
            this.dtpFromDate.Size = new System.Drawing.Size(111, 26);
            this.dtpFromDate.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(11, 55);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(40, 16);
            this.label1.TabIndex = 160;
            this.label1.Text = "Date";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // dtpToDate
            // 
            this.dtpToDate.CalendarFont = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.dtpToDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.dtpToDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpToDate.Location = new System.Drawing.Point(249, 50);
            this.dtpToDate.Name = "dtpToDate";
            this.dtpToDate.Size = new System.Drawing.Size(111, 26);
            this.dtpToDate.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.Black;
            this.label2.Location = new System.Drawing.Point(227, 56);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(17, 16);
            this.label2.TabIndex = 162;
            this.label2.Text = "~";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // frmTranForm02
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1239, 840);
            this.Name = "frmTranForm02";
            this.Text = "frmTranForm02";
            this.pnlStsCond.ResumeLayout(false);
            this.pnlStsCond.PerformLayout();
            this.pnlMID.ResumeLayout(false);
            this.pnlMID.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cdvOper)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvWorkPlace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cdvDept)).EndInit();
            this.pnlBottom.ResumeLayout(false);
            this.pnlCenter.ResumeLayout(false);
            this.pnlTop.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        public System.Windows.Forms.Label label2;
        public System.Windows.Forms.Label label1;
        public System.Windows.Forms.DateTimePicker dtpFromDate;
        public System.Windows.Forms.DateTimePicker dtpToDate;
    }
}