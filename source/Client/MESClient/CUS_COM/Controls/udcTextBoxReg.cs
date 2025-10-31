using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;
using CUS_COM.BaseForm;

namespace CUS_COM.Controls
{
    public partial class udcTextBoxReg : TextBox, intCodeListControl
    {
        public udcTextBoxReg()
        {
            InitializeComponent();
            Init();
        }

        #region Variable Define
        private string preText;
        private frmKeyPad keyPad;
        private bool _isNumeric;
        private bool _ReadOnly;

        [Category("Save Registry"), Description("레지스트리 저장")]
        public bool SaveRegistry
        {
            get;
            set;
        }

        [Category("Is Numeric"), Description("숫자")]
        public bool IsNumeric
        {
            get
            {
                return _isNumeric;
            }
            set
            {
                _isNumeric = value;
                ImeMode = ImeMode.Off;
                TextAlign = HorizontalAlignment.Right;
            }
        }

        [Category("Is Required"), Description("필수여부")]
        public bool IsRequired
        {
            get;
            set;
        }

        [EditorBrowsable(EditorBrowsableState.Advanced)]
        public new bool ReadOnly
        {
            get
            {
                return _ReadOnly;
            }
            set
            {
                _ReadOnly = value;
                if (_ReadOnly)
                {
                    this.BackColor = SystemColors.Control;
                    this.TabStop = false;
                }
                else
                {
                    this.BackColor = System.Drawing.Color.FromArgb(234, 250, 238);
                    this.TabStop = true;
                }

                base.ReadOnly = _ReadOnly;
            }
        }

        #endregion

        #region Event Define
        protected override void OnCreateControl()
        {
            SetDegin();
            base.OnCreateControl();
        }

        protected override void OnEnter(EventArgs e)
        {
            SelectAll();
            base.OnEnter(e);
        }

        protected override void OnClick(EventArgs e)
        {
            SelectAll();
            base.OnClick(e);
        }

        private void udcTextBoxRef_TextChange(object sender, EventArgs e)
        {
            if (_isNumeric && !_ReadOnly)
            {
                int cPosition = this.SelectionStart;
                this.Text = CheckTextNumeric(this.Text);
                this.Select(cPosition, 0);
            }
        }
        protected override void OnKeyDown(KeyEventArgs e)
        {
            if (_isNumeric && !_ReadOnly)
            {
                preText = this.Text;
            }
            base.OnKeyDown(e);
        }
        private void SOITextBoxNumber_MouseClick(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            //ShowKeyPad();
        }
        #endregion

        #region Function Define
        public void Init()
        {
            this.Font = new System.Drawing.Font("맑은 고딕", 12.75F, System.Drawing.FontStyle.Regular);
            this.Text = "";
        }
        public bool CheckValue()
        {
            if (_isNumeric)
            {
                return MPCF.CheckValue(this, 2);
            }
            else
            {
                return MPCF.CheckValue(this, 1);
            }
        }
        /// <summary>
        /// TextBox Clear
        /// </summary>
        public void ClearField()
        {
            if (_isNumeric)
            {
                this.Text = "";
            }
            else
            {
                this.Text = "";
            }
        }

        private void SetDegin()
        {
            double d_text = 0;
            this.BorderStyle = BorderStyle.FixedSingle;

            if (_isNumeric)
            {
                if(double.TryParse(this.Text, out d_text) == false)
                    this.Text = "";

                this.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            }
            else
            {
                //this.Text = "";
                this.TextAlign = System.Windows.Forms.HorizontalAlignment.Left;
            }

            if (IsRequired)
            {
                this.BackColor = Color.FromArgb(234, 250, 238);
            }
        }

        public void RemoveLastValue()
        {
            if (!this.Text.Equals(""))
            {
                string newText = this.Text.Remove(this.Text.Length - 1);
                if (IsNumeric && newText.Equals(""))
                {
                    newText = "";
                }

                this.Text = newText;
            }
        }

        protected string CheckTextNumeric(string text)
        {
            double var = 0.0;
            bool change = double.TryParse(text, out var);

            if (preText != null)
            {
                //다 지웠을때 0으로 넣어줌
                if (text.Equals(""))
                {
                    change = true;
                    text = "";
                }
                //숫자가 아니면 이전 텍스트를 보여준다
                if (!change)
                {
                    if (text.Equals("-"))
                    {
                        text = "-0";
                    }
                    else
                    {
                        text = preText;
                    }
                }
                //숫자인 경우 0 관련 처리
                else if (this.Text.Length > 1 && !this.Text.Contains("."))
                {
                    if (this.Text.StartsWith("0"))
                    {
                        text = this.Text.Remove(0, 1);
                    }
                    else if (this.Text.StartsWith("-0") && this.Text.Length > 2)
                    {
                        text = this.Text.Remove(1, 1);
                    }
                }
            }

            return text;
        }

        //keypad send value
        public void AddValue(object obj)
        {
            if (_isNumeric)
            {
                preText = this.Text;
                string oldValue = preText + obj.ToString();
                double result;

                if (Double.TryParse(oldValue, out result))
                {
                    if (preText == "0" && obj.ToString() != ".")
                    {
                        this.Text = obj.ToString();
                    }
                    else
                    {
                        this.Text = oldValue;
                    }
                }
                else
                {
                    this.Text = preText;
                }
            }
            else
            {
                this.Text = this.Text + obj.ToString();
            }
        }

        private void ShowKeyPad()
        {
            try
            {
                if (_isNumeric == true && _ReadOnly == false)
                {
                    if (keyPad == null
                        || keyPad.IsDisposed == true)
                    {
                        keyPad = new frmKeyPad();
                        keyPad.Owner = this.FindForm();

                        Point controlLocation = this.Parent.PointToScreen(new Point(this.Left, this.Top));
                        Point parentLocation = keyPad.Owner.PointToScreen(new Point(keyPad.Owner.ClientRectangle.Left, keyPad.Owner.ClientRectangle.Bottom));

                        controlLocation.X += (this.Width - keyPad.Width);

                        //화면 밖으로 나가는 창에 대한 처리
                        if (parentLocation.Y < (controlLocation.Y + keyPad.Height + this.Height))
                        {
                            controlLocation.Y -= keyPad.Height;
                        }
                        else
                        {
                            controlLocation.Y += this.Height;
                        }

                        keyPad.Tag = this;
                        keyPad.StartPosition = FormStartPosition.Manual;
                        keyPad.Location = controlLocation;
                        keyPad.ShowDialog();

                        this.Update();
                    }
                }
            }
            finally
            {
                if (keyPad != null)
                {
                    keyPad.Dispose();
                }
            }
        }
        #endregion
    }
}
