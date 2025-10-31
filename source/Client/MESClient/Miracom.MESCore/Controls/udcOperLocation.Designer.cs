namespace Miracom.MESCore.Controls
{
    partial class udcOperLocation
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlControl = new System.Windows.Forms.Panel();
            this.ctrlLocation = new Miracom.MESCore.Controls.udcGCM();
            this.pnlMargin1 = new System.Windows.Forms.Panel();
            this.ctrlOper = new Miracom.MESCore.Controls.udcOperationInv();
            this.pnlLabel = new System.Windows.Forms.Panel();
            this.lblLabel = new System.Windows.Forms.Label();
            this.txtDesc = new System.Windows.Forms.TextBox();
            this.pnlMarginLabel = new System.Windows.Forms.Panel();
            this.pnlMarginDesc = new System.Windows.Forms.Panel();
            this.pnlControl.SuspendLayout();
            this.pnlLabel.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlControl
            // 
            this.pnlControl.Controls.Add(this.ctrlLocation);
            this.pnlControl.Controls.Add(this.pnlMargin1);
            this.pnlControl.Controls.Add(this.ctrlOper);
            this.pnlControl.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlControl.Location = new System.Drawing.Point(125, 0);
            this.pnlControl.Name = "pnlControl";
            this.pnlControl.Size = new System.Drawing.Size(205, 20);
            this.pnlControl.TabIndex = 2;
            // 
            // ctrlLocation
            // 
            this.ctrlLocation.AddEmptyRowToLast = false;
            this.ctrlLocation.AddEmptyRowToTop = false;
            this.ctrlLocation.ButtonWidth = 21;
            this.ctrlLocation.DisplaySubItemIndex = 0;
            this.ctrlLocation.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ctrlLocation.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ctrlLocation.LabelFont = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ctrlLocation.LabelText = "Shift";
            this.ctrlLocation.LabelWidth = 0;
            this.ctrlLocation.ListCond_ExtFactory = "";
            this.ctrlLocation.ListCond_ListName = "";
            this.ctrlLocation.ListCond_ModuleName = "";
            this.ctrlLocation.ListCond_Step = '1';
            this.ctrlLocation.ListCond_TableName = "LOCATION";
            this.ctrlLocation.Location = new System.Drawing.Point(105, 0);
            this.ctrlLocation.MaximumSize = new System.Drawing.Size(0, 20);
            this.ctrlLocation.MaxLength = 32767;
            this.ctrlLocation.MinimumSize = new System.Drawing.Size(100, 20);
            this.ctrlLocation.Name = "ctrlLocation";
            this.ctrlLocation.ReadOnly = false;
            this.ctrlLocation.SearchSubItemIndex = 0;
            this.ctrlLocation.SelectedDescIndex = 1;
            this.ctrlLocation.SelectedSubItemIndex = 0;
            this.ctrlLocation.Size = new System.Drawing.Size(100, 20);
            this.ctrlLocation.TabIndex = 9;
            this.ctrlLocation.TextBoxWidth = 100;
            this.ctrlLocation.VisibleButton = true;
            this.ctrlLocation.VisibleColumnHeader = false;
            this.ctrlLocation.VisibleDescription = false;
            this.ctrlLocation.SelectedItemChanged += new Miracom.UI.MCCodeViewSelChangedHandler(this.ctrlLocation_SelectedItemChanged);
            this.ctrlLocation.ButtonPress += new System.EventHandler(this.ctrlLocation_ButtonPress);
            this.ctrlLocation.ButtonPressAfter += new System.EventHandler(this.ctrlLocation_ButtonPressAfter);
            this.ctrlLocation.TextBoxKeyPress += new System.Windows.Forms.KeyPressEventHandler(this.ctrlLocation_TextBoxKeyPress);
            this.ctrlLocation.TextBoxTextChanged += new System.EventHandler(this.ctrlLocation_TextBoxTextChanged);
            this.ctrlLocation.TextBoxLostFocus += new System.EventHandler(this.ctrlLocation_TextBoxLostFocus);
            this.ctrlLocation.TextBoxGotFocus += new System.EventHandler(this.ctrlLocation_TextBoxLostFocus);
            // 
            // pnlMargin1
            // 
            this.pnlMargin1.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlMargin1.Location = new System.Drawing.Point(100, 0);
            this.pnlMargin1.Name = "pnlMargin1";
            this.pnlMargin1.Size = new System.Drawing.Size(5, 20);
            this.pnlMargin1.TabIndex = 8;
            // 
            // ctrlOper
            // 
            this.ctrlOper.AddEmptyRowToLast = false;
            this.ctrlOper.AddEmptyRowToTop = false;
            this.ctrlOper.ButtonWidth = 21;
            this.ctrlOper.DisplaySubItemIndex = 0;
            this.ctrlOper.Dock = System.Windows.Forms.DockStyle.Left;
            this.ctrlOper.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ctrlOper.LabelFont = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ctrlOper.LabelText = "Operation";
            this.ctrlOper.LabelWidth = 0;
            this.ctrlOper.ListCond_ExtFactory = "";
            this.ctrlOper.ListCond_Step = '1';
            this.ctrlOper.Location = new System.Drawing.Point(0, 0);
            this.ctrlOper.Name = "ctrlOper";
            this.ctrlOper.ReadOnly = false;
            this.ctrlOper.SearchSubItemIndex = 0;
            this.ctrlOper.SelectedDescIndex = 1;
            this.ctrlOper.SelectedSubItemIndex = 0;
            this.ctrlOper.Size = new System.Drawing.Size(100, 20);
            this.ctrlOper.TabIndex = 13;
            this.ctrlOper.TextBoxWidth = 100;
            this.ctrlOper.VisibleButton = true;
            this.ctrlOper.VisibleColumnHeader = false;
            this.ctrlOper.VisibleDescription = false;
            // 
            // pnlLabel
            // 
            this.pnlLabel.Controls.Add(this.lblLabel);
            this.pnlLabel.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlLabel.Location = new System.Drawing.Point(0, 0);
            this.pnlLabel.Name = "pnlLabel";
            this.pnlLabel.Size = new System.Drawing.Size(120, 20);
            this.pnlLabel.TabIndex = 2;
            // 
            // lblLabel
            // 
            this.lblLabel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.lblLabel.Location = new System.Drawing.Point(0, 3);
            this.lblLabel.Name = "lblLabel";
            this.lblLabel.Size = new System.Drawing.Size(120, 17);
            this.lblLabel.TabIndex = 1;
            this.lblLabel.Text = "Oper/Location";
            this.lblLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // txtDesc
            // 
            this.txtDesc.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtDesc.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtDesc.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.txtDesc.ForeColor = System.Drawing.SystemColors.ControlText;
            this.txtDesc.Location = new System.Drawing.Point(335, 0);
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.ReadOnly = true;
            this.txtDesc.Size = new System.Drawing.Size(0, 20);
            this.txtDesc.TabIndex = 2;
            this.txtDesc.Visible = false;
            // 
            // pnlMarginLabel
            // 
            this.pnlMarginLabel.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlMarginLabel.Location = new System.Drawing.Point(120, 0);
            this.pnlMarginLabel.Name = "pnlMarginLabel";
            this.pnlMarginLabel.Size = new System.Drawing.Size(5, 20);
            this.pnlMarginLabel.TabIndex = 7;
            // 
            // pnlMarginDesc
            // 
            this.pnlMarginDesc.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnlMarginDesc.Location = new System.Drawing.Point(330, 0);
            this.pnlMarginDesc.Name = "pnlMarginDesc";
            this.pnlMarginDesc.Size = new System.Drawing.Size(5, 20);
            this.pnlMarginDesc.TabIndex = 8;
            // 
            // udcOperLocation
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.Controls.Add(this.txtDesc);
            this.Controls.Add(this.pnlMarginDesc);
            this.Controls.Add(this.pnlControl);
            this.Controls.Add(this.pnlMarginLabel);
            this.Controls.Add(this.pnlLabel);
            this.MinimumSize = new System.Drawing.Size(0, 20);
            this.Name = "udcOperLocation";
            this.Size = new System.Drawing.Size(330, 20);
            this.FontChanged += new System.EventHandler(this.udcOperLocation_FontChanged);
            this.pnlControl.ResumeLayout(false);
            this.pnlLabel.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel pnlControl;
        private System.Windows.Forms.Label lblLabel;
        private System.Windows.Forms.TextBox txtDesc;
        private System.Windows.Forms.Panel pnlLabel;
        private System.Windows.Forms.Panel pnlMarginLabel;
        private System.Windows.Forms.Panel pnlMargin1;
        private Miracom.MESCore.Controls.udcGCM ctrlLocation;
        private System.Windows.Forms.Panel pnlMarginDesc;
        private Miracom.MESCore.Controls.udcOperationInv ctrlOper;

    }
}
