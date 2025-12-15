
using System;
using System.Data;
using System.Collections;
using System.Diagnostics;
using System.Text.RegularExpressions;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.TRSCore;


namespace Miracom.MESCore
{
    public class frmChangePassword : System.Windows.Forms.Form
    {
        #region " Windows Form auto generated code "

        public frmChangePassword()
        {
            
            InitializeComponent();

        }
        
        
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


        public bool sNextbtnHidden = false;

        private System.ComponentModel.Container components = null;
        



        private System.Windows.Forms.Panel pnlMid;
        private System.Windows.Forms.GroupBox grpPassword;
        private System.Windows.Forms.TextBox txtConfirmPassword;
        private System.Windows.Forms.Label lblConfirmPassword;
        private System.Windows.Forms.TextBox txtNewPassword;
        private System.Windows.Forms.Label lblNewPassword;
        private System.Windows.Forms.TextBox txtPassword;
        private System.Windows.Forms.TextBox txtUserId;
        private System.Windows.Forms.Label lblCurrentPassword;
        private System.Windows.Forms.Label lblUserId;
        protected System.Windows.Forms.Panel pnlBottom;
        protected System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Label label1;
        protected System.Windows.Forms.Button btnNext;
        protected System.Windows.Forms.Button btnOK;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.pnlMid = new System.Windows.Forms.Panel();
            this.grpPassword = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.txtConfirmPassword = new System.Windows.Forms.TextBox();
            this.lblConfirmPassword = new System.Windows.Forms.Label();
            this.txtNewPassword = new System.Windows.Forms.TextBox();
            this.lblNewPassword = new System.Windows.Forms.Label();
            this.txtPassword = new System.Windows.Forms.TextBox();
            this.txtUserId = new System.Windows.Forms.TextBox();
            this.lblCurrentPassword = new System.Windows.Forms.Label();
            this.lblUserId = new System.Windows.Forms.Label();
            this.pnlBottom = new System.Windows.Forms.Panel();
            this.btnNext = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnOK = new System.Windows.Forms.Button();
            this.pnlMid.SuspendLayout();
            this.grpPassword.SuspendLayout();
            this.pnlBottom.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlMid
            // 
            this.pnlMid.Controls.Add(this.grpPassword);
            this.pnlMid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlMid.Location = new System.Drawing.Point(0, 0);
            this.pnlMid.Name = "pnlMid";
            this.pnlMid.Padding = new System.Windows.Forms.Padding(3, 0, 3, 0);
            this.pnlMid.Size = new System.Drawing.Size(391, 178);
            this.pnlMid.TabIndex = 0;
            // 
            // grpPassword
            // 
            this.grpPassword.Controls.Add(this.label1);
            this.grpPassword.Controls.Add(this.txtConfirmPassword);
            this.grpPassword.Controls.Add(this.lblConfirmPassword);
            this.grpPassword.Controls.Add(this.txtNewPassword);
            this.grpPassword.Controls.Add(this.lblNewPassword);
            this.grpPassword.Controls.Add(this.txtPassword);
            this.grpPassword.Controls.Add(this.txtUserId);
            this.grpPassword.Controls.Add(this.lblCurrentPassword);
            this.grpPassword.Controls.Add(this.lblUserId);
            this.grpPassword.Dock = System.Windows.Forms.DockStyle.Fill;
            this.grpPassword.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.grpPassword.Location = new System.Drawing.Point(3, 0);
            this.grpPassword.Name = "grpPassword";
            this.grpPassword.Size = new System.Drawing.Size(385, 178);
            this.grpPassword.TabIndex = 0;
            this.grpPassword.TabStop = false;
            // 
            // label1
            // 
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(6, 111);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(373, 64);
            this.label1.TabIndex = 8;
            this.label1.Text = "1.영어 대문자, 소문자, 숫자, 특수문자 포함한 8자리이상입니다.\r\n2.패스워드 변경주기는 3개월입니다.\r\n3.비밀번호 분실시 담당자에게 문의 " +
    "바랍니다.\r\n◆ MES담당자(010-8962-6376), 생산기획팀(010-5257-3714)\r\n";
            // 
            // txtConfirmPassword
            // 
            this.txtConfirmPassword.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtConfirmPassword.Location = new System.Drawing.Point(140, 88);
            this.txtConfirmPassword.MaxLength = 20;
            this.txtConfirmPassword.Name = "txtConfirmPassword";
            this.txtConfirmPassword.PasswordChar = '*';
            this.txtConfirmPassword.Size = new System.Drawing.Size(172, 20);
            this.txtConfirmPassword.TabIndex = 7;
            // 
            // lblConfirmPassword
            // 
            this.lblConfirmPassword.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblConfirmPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblConfirmPassword.Location = new System.Drawing.Point(15, 91);
            this.lblConfirmPassword.Name = "lblConfirmPassword";
            this.lblConfirmPassword.Size = new System.Drawing.Size(117, 14);
            this.lblConfirmPassword.TabIndex = 6;
            this.lblConfirmPassword.Text = "Confirm Password";
            // 
            // txtNewPassword
            // 
            this.txtNewPassword.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtNewPassword.Location = new System.Drawing.Point(140, 64);
            this.txtNewPassword.MaxLength = 20;
            this.txtNewPassword.Name = "txtNewPassword";
            this.txtNewPassword.PasswordChar = '*';
            this.txtNewPassword.Size = new System.Drawing.Size(172, 20);
            this.txtNewPassword.TabIndex = 5;
            // 
            // lblNewPassword
            // 
            this.lblNewPassword.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblNewPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblNewPassword.Location = new System.Drawing.Point(15, 67);
            this.lblNewPassword.Name = "lblNewPassword";
            this.lblNewPassword.Size = new System.Drawing.Size(117, 14);
            this.lblNewPassword.TabIndex = 4;
            this.lblNewPassword.Text = "New Password";
            // 
            // txtPassword
            // 
            this.txtPassword.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtPassword.Location = new System.Drawing.Point(140, 40);
            this.txtPassword.MaxLength = 20;
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '*';
            this.txtPassword.Size = new System.Drawing.Size(172, 20);
            this.txtPassword.TabIndex = 3;
            // 
            // txtUserId
            // 
            this.txtUserId.Location = new System.Drawing.Point(140, 16);
            this.txtUserId.MaxLength = 20;
            this.txtUserId.Name = "txtUserId";
            this.txtUserId.ReadOnly = true;
            this.txtUserId.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.txtUserId.Size = new System.Drawing.Size(172, 20);
            this.txtUserId.TabIndex = 1;
            this.txtUserId.TabStop = false;
            // 
            // lblCurrentPassword
            // 
            this.lblCurrentPassword.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblCurrentPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCurrentPassword.Location = new System.Drawing.Point(15, 43);
            this.lblCurrentPassword.Name = "lblCurrentPassword";
            this.lblCurrentPassword.Size = new System.Drawing.Size(117, 14);
            this.lblCurrentPassword.TabIndex = 2;
            this.lblCurrentPassword.Text = "Current Password";
            // 
            // lblUserId
            // 
            this.lblUserId.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.lblUserId.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUserId.Location = new System.Drawing.Point(15, 19);
            this.lblUserId.Name = "lblUserId";
            this.lblUserId.Size = new System.Drawing.Size(117, 14);
            this.lblUserId.TabIndex = 0;
            this.lblUserId.Text = "User ID";
            // 
            // pnlBottom
            // 
            this.pnlBottom.Controls.Add(this.btnNext);
            this.pnlBottom.Controls.Add(this.btnCancel);
            this.pnlBottom.Controls.Add(this.btnOK);
            this.pnlBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnlBottom.Location = new System.Drawing.Point(0, 178);
            this.pnlBottom.Name = "pnlBottom";
            this.pnlBottom.Padding = new System.Windows.Forms.Padding(3);
            this.pnlBottom.Size = new System.Drawing.Size(391, 36);
            this.pnlBottom.TabIndex = 1;
            // 
            // btnNext
            // 
            this.btnNext.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnNext.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnNext.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnNext.Location = new System.Drawing.Point(5, 7);
            this.btnNext.Name = "btnNext";
            this.btnNext.Size = new System.Drawing.Size(88, 23);
            this.btnNext.TabIndex = 2;
            this.btnNext.Text = "Change next time";
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnCancel.Location = new System.Drawing.Point(312, 8);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 1;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnOK
            // 
            this.btnOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnOK.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnOK.Location = new System.Drawing.Point(230, 8);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 0;
            this.btnOK.Text = "OK";
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // frmChangePassword
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
            this.CancelButton = this.btnCancel;
            this.ClientSize = new System.Drawing.Size(391, 214);
            this.Controls.Add(this.pnlMid);
            this.Controls.Add(this.pnlBottom);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmChangePassword";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Change Password";
            this.Closed += new System.EventHandler(this.frmChangePassword_Closed);
            this.Load += new System.EventHandler(this.frmChangePassword_Load);
            this.pnlMid.ResumeLayout(false);
            this.grpPassword.ResumeLayout(false);
            this.grpPassword.PerformLayout();
            this.pnlBottom.ResumeLayout(false);
            this.ResumeLayout(false);

        }
        
        #endregion
        
        #region " Function Definition"
        
        //
        // CheckCondition()
        //       - Check the conditions before transaction
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - ByVal FuncName As String : Function Name
        //       - Optional ByVal ProcStep As String : Process Step
        //
        private bool CheckCondition()
        {
            
            try
            {
                
                if (MPCF.CheckValue(txtPassword, 1) == false)
                {
                    return false;
                }
                if (MPCF.CheckValue(txtNewPassword, 1) == false)
                {
                    return false;
                }
                if (MPCF.CheckValue(txtConfirmPassword, 1) == false)
                {
                    return false;
                }





                if (MPGV.gsFactory == "IJDK1")
                {

                 

                    //10자리 이상
                    if (txtNewPassword.Text != null && txtNewPassword.Text.Length < 8)
                    {
                        MPCF.ShowMsgBox("패스워드는 8자리 이상입니다.");
                        return false;
                    }

                    //숫자1이상, 영문1이상, 특수문자1이상
                    Regex regexPass = new Regex(@"^(?=.*?[A-Z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{9,}$", RegexOptions.IgnorePatternWhitespace);

                    if (regexPass.IsMatch(txtNewPassword.Text) ==false)
                    {
                        MPCF.ShowMsgBox("숫자1이상, 영문1이상, 특수문자1이상으로 패스워드 조합되어야합니다.");
                        return false;
                    }

                }



                return true;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            
        }
        
        //
        // Update_User()
        //       - Create/Update/Delete user
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - ByVal ProcStep As String ("1" - Create, "2" - Update, "3" - Delete)
        //
        private bool Change_Password()
        {
            TRSNode in_node = new TRSNode("CHANGE_PASSWORD_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("CURRENT_PASSWORD", txtPassword.Text.ToUpper(), true);
                in_node.AddString("NEW_PASSWORD", txtNewPassword.Text.ToUpper(), true);
                in_node.AddString("CONFIRM_PASSWORD", txtConfirmPassword.Text.ToUpper(), true);

                if (MPCR.CallService("SEC", "SEC_Change_Password", in_node, ref out_node) == false)
                {
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }
        
        //
        // Change_Password_Ext()
        //       - Change user password
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - ByVal ProcStep As String
        //
        private bool Change_Password_Ext()
        {
            TRSNode in_node = new TRSNode("CHANGE_PASSWORD_EXT_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("CURRENT_PASSWORD", txtPassword.Text.ToUpper(), true);
                in_node.AddString("NEW_PASSWORD", txtNewPassword.Text.ToUpper(), true);
                in_node.AddString("CONFIRM_PASSWORD", txtConfirmPassword.Text.ToUpper(), true);


                if (MPCR.CallService("SEC", "SEC_Change_Password_Ext", in_node, ref out_node) == false)
                {
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        
        
        #endregion
        
        private void frmChangePassword_Load(object sender, System.EventArgs e)
        {
            
            MPGV.gIBaseFormEvent.Form_Load(this, e);
            
            txtUserId.Text = MPGV.gsUserID;
            
        }
        
        private void btnOK_Click(System.Object sender, System.EventArgs e)
        {
            try
            {
                
                if (CheckCondition() == false)
                {
                    return;
                }
                
                //If Change_Password() = False Then Exit Sub
                
                //Add by J.S 2006/4/6 for ASC
                if (Change_Password_Ext() == false)
                {
                    return;
                }
                
                this.Close();
                
                this.DialogResult = System.Windows.Forms.DialogResult.Yes;
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        private void btnCancel_Click(System.Object sender, System.EventArgs e)
        {
            this.Close();
            this.DialogResult = System.Windows.Forms.DialogResult.Cancel;
        }
        
        private void frmChangePassword_Closed(object sender, System.EventArgs e)
        {
            if (this.MdiParent == null)
            {
                
            }
            else
            {
                if (this.MdiParent.IsMdiContainer == true)
                {
                    this.Dispose();
                }
            }
            
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            this.Close();
            this.DialogResult = System.Windows.Forms.DialogResult.Yes;
        }
    }
    
}
