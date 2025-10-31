using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;
using CUS_COM.Controls;

namespace CUS_COM.BaseForm
{
    public partial class frmKeyPad : Form
    {
        private bool bInitValue = false;
        private string oInitValue;
        private bool bFirstInput = false;

        public frmKeyPad()
        {
            InitializeComponent();
        }

        private void btnNumZero_Click(object sender, EventArgs e)
        {
            SetNumber('0');
            btnEnter.Focus();
        }

        private void btnNumOne_Click(object sender, EventArgs e)
        {
            SetNumber('1');
            btnEnter.Focus();
        }

        private void btnNumTwo_Click(object sender, EventArgs e)
        {
            SetNumber('2');
            btnEnter.Focus();
        }

        private void btnNumThree_Click(object sender, EventArgs e)
        {
            SetNumber('3');
            btnEnter.Focus();
        }

        private void btnNumFour_Click(object sender, EventArgs e)
        {
            SetNumber('4');
            btnEnter.Focus();
        }

        private void btnNumFive_Click(object sender, EventArgs e)
        {
            SetNumber('5');
            btnEnter.Focus();
        }

        private void btnNumSix_Click(object sender, EventArgs e)
        {
            SetNumber('6');
            btnEnter.Focus();
        }

        private void btnNumSeven_Click(object sender, EventArgs e)
        {
            SetNumber('7');
            btnEnter.Focus();
        }

        private void btnNumEight_Click(object sender, EventArgs e)
        {
            SetNumber('8');
            btnEnter.Focus();
        }

        private void btnNumNine_Click(object sender, EventArgs e)
        {
            SetNumber('9');
            btnEnter.Focus();
        }

        private void btnDot_Click(object sender, EventArgs e)
        {
            SetNumber('.');
            btnEnter.Focus();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            SetNumber('C');
            btnEnter.Focus();
        }

        private void btnBackspace_Click(object sender, EventArgs e)
        {
            SetNumber('B');
            btnEnter.Focus();
        }

        private void btnEnter_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void frmKeyPad_KeyPress(object sender, KeyPressEventArgs e)
        {
            // 실행되지 않음
            if (e.KeyChar == Convert.ToChar(Keys.Enter)
                || e.KeyChar == Convert.ToChar(Keys.Tab))
            {
                this.Close();
            }
            else if (e.KeyChar == Convert.ToChar(Keys.Escape))
            {
                if (bInitValue == true)
                {
                    SetNumber('I');
                }
                this.Close();
            }
            else if (e.KeyChar == Convert.ToChar(Keys.C))
            {
                SetNumber('C');
                this.Close();
            }
            else if (e.KeyChar == Convert.ToChar(Keys.Back))
            {
                SetNumber('B');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D0) || e.KeyChar == Convert.ToChar(Keys.NumPad0))
            {
                SetNumber('0');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D1) || e.KeyChar == Convert.ToChar(Keys.NumPad1))
            {
                SetNumber('1');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D2) || e.KeyChar == Convert.ToChar(Keys.NumPad2))
            {
                SetNumber('2');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D3) || e.KeyChar == Convert.ToChar(Keys.NumPad3))
            {
                SetNumber('3');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D4) || e.KeyChar == Convert.ToChar(Keys.NumPad4))
            {
                SetNumber('4');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D5) || e.KeyChar == Convert.ToChar(Keys.NumPad5))
            {
                SetNumber('5');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D6) || e.KeyChar == Convert.ToChar(Keys.NumPad6))
            {
                SetNumber('6');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D7) || e.KeyChar == Convert.ToChar(Keys.NumPad7))
            {
                SetNumber('7');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D8) || e.KeyChar == Convert.ToChar(Keys.NumPad8))
            {
                SetNumber('8');
            }
            else if (e.KeyChar == Convert.ToChar(Keys.D9) || e.KeyChar == Convert.ToChar(Keys.NumPad9))
            {
                SetNumber('9');
            }
        }

        /// <summary>
        /// 초기값을 저장합니다.
        /// </summary>
        private void GetInitValue()
        {
            if (this.Tag != null && this.Tag is udcTextBoxReg)
            {
                oInitValue = this.Text;
                bInitValue = true;
            }
        }

        /// <summary>
        /// 입력한 값을 TextBox로 전달합니다.
        /// </summary>
        /// <param name="value"></param>
        private void SetNumber(char btnChar)
        {
            try
            {
                udcTextBoxReg parentControl;

                if (this.Tag != null && this.Tag is udcTextBoxReg)
                {
                    parentControl = ((udcTextBoxReg)this.Tag);

                    if (bFirstInput == false)
                    {
                        parentControl.Text = "0";
                        bFirstInput = true;
                    }

                    if (btnChar == 'I')
                    {
                        parentControl.Text = oInitValue;
                    }
                    else if (btnChar == 'C')
                    {
                        parentControl.ClearField();
                    }
                    else if (btnChar == 'B')
                    {
                        parentControl.RemoveLastValue();
                    }
                    else if (btnChar == '0')
                    {
                        parentControl.AddValue(0);
                    }
                    else if (btnChar == '1')
                    {
                        parentControl.AddValue(1);
                    }
                    else if (btnChar == '2')
                    {
                        parentControl.AddValue(2);
                    }
                    else if (btnChar == '3')
                    {
                        parentControl.AddValue(3);
                    }
                    else if (btnChar == '4')
                    {
                        parentControl.AddValue(4);
                    }
                    else if (btnChar == '5')
                    {
                        parentControl.AddValue(5);
                    }
                    else if (btnChar == '6')
                    {
                        parentControl.AddValue(6);
                    }
                    else if (btnChar == '7')
                    {
                        parentControl.AddValue(7);
                    }
                    else if (btnChar == '8')
                    {
                        parentControl.AddValue(8);
                    }
                    else if (btnChar == '9')
                    {
                        parentControl.AddValue(9);
                    }
                    else if (btnChar == '.')
                    {
                        parentControl.AddValue('.');
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmKeyPad_Click(object sender, EventArgs e)
        {

        }

        private void frmKeyPad_Leave(object sender, EventArgs e)
        {
            
        }
    }
}
