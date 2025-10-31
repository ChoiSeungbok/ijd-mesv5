using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;

namespace Miracom.MESCore.Controls
{
    public partial class udcOperLocation : UserControl, intCodeListControl
    {
        private char m_cond_c_step;
        private string m_cond_s_filter;
        private string m_cond_s_ext_factory;

        private bool m_b_visible_desc = false;

        private int m_SelectedSubItemIndex = 0;
        private int m_DisplaySubItemIndex = 1;
        private int m_SelectedDescIndex = -1;

        public udcOperLocation()
        {
            InitializeComponent();

            Init();
        }

        #region "Control Events"

        private MCCodeViewSelChangedHandler OperSelectedItemChangedEvent;
        public event MCCodeViewSelChangedHandler OperSelectedItemChanged
        {
            add
            {
                OperSelectedItemChangedEvent = (MCCodeViewSelChangedHandler)System.Delegate.Combine(OperSelectedItemChangedEvent, value);
            }
            remove
            {
                OperSelectedItemChangedEvent = (MCCodeViewSelChangedHandler)System.Delegate.Remove(OperSelectedItemChangedEvent, value);
            }
        }

        private System.EventHandler OperButtonPressEvent;
        public event System.EventHandler OperButtonPress
        {
            add
            {
                OperButtonPressEvent = (System.EventHandler)System.Delegate.Combine(OperButtonPressEvent, value);
            }
            remove
            {
                OperButtonPressEvent = (System.EventHandler)System.Delegate.Remove(OperButtonPressEvent, value);
            }
        }

        private System.EventHandler OperButtonPressAfterEvent;
        public event System.EventHandler OperButtonPressAfter
        {
            add
            {
                OperButtonPressAfterEvent = (System.EventHandler)System.Delegate.Combine(OperButtonPressAfterEvent, value);
            }
            remove
            {
                OperButtonPressAfterEvent = (System.EventHandler)System.Delegate.Remove(OperButtonPressAfterEvent, value);
            }
        }

        private System.Windows.Forms.KeyPressEventHandler OperTextKeyPressEvent;
        public event System.Windows.Forms.KeyPressEventHandler OperTextKeyPress
        {
            add
            {
                OperTextKeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Combine(OperTextKeyPressEvent, value);
            }
            remove
            {
                OperTextKeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Remove(OperTextKeyPressEvent, value);
            }
        }

        private System.EventHandler OperTextChangedEvent;
        public event System.EventHandler OperTextChanged
        {
            add
            {
                OperTextChangedEvent = (System.EventHandler)System.Delegate.Combine(OperTextChangedEvent, value);
            }
            remove
            {
                OperTextChangedEvent = (System.EventHandler)System.Delegate.Remove(OperTextChangedEvent, value);
            }
        }

        private System.EventHandler OperTextLostFocusEvent;
        public event System.EventHandler OperTextLostFocus
        {
            add
            {
                OperTextLostFocusEvent = (System.EventHandler)System.Delegate.Combine(OperTextLostFocusEvent, value);
            }
            remove
            {
                OperTextLostFocusEvent = (System.EventHandler)System.Delegate.Remove(OperTextLostFocusEvent, value);
            }
        }

        private System.EventHandler OperTextGotFocusEvent;
        public event System.EventHandler OperTextGotFocus
        {
            add
            {
                OperTextGotFocusEvent = (System.EventHandler)System.Delegate.Combine(OperTextGotFocusEvent, value);
            }
            remove
            {
                OperTextGotFocusEvent = (System.EventHandler)System.Delegate.Remove(OperTextGotFocusEvent, value);
            }
        }

        private MCCodeViewSelChangedHandler LocationSelectedItemChangedEvent;
        public event MCCodeViewSelChangedHandler LocationSelectedItemChanged
        {
            add
            {
                LocationSelectedItemChangedEvent = (MCCodeViewSelChangedHandler)System.Delegate.Combine(LocationSelectedItemChangedEvent, value);
            }
            remove
            {
                LocationSelectedItemChangedEvent = (MCCodeViewSelChangedHandler)System.Delegate.Remove(LocationSelectedItemChangedEvent, value);
            }
        }

        private System.EventHandler LocationButtonPressEvent;
        public event System.EventHandler LocationButtonPress
        {
            add
            {
                LocationButtonPressEvent = (System.EventHandler)System.Delegate.Combine(LocationButtonPressEvent, value);
            }
            remove
            {
                LocationButtonPressEvent = (System.EventHandler)System.Delegate.Remove(LocationButtonPressEvent, value);
            }
        }

        private System.EventHandler LocationButtonPressAfterEvent;
        public event System.EventHandler LocationButtonPressAfter
        {
            add
            {
                LocationButtonPressAfterEvent = (System.EventHandler)System.Delegate.Combine(LocationButtonPressAfterEvent, value);
            }
            remove
            {
                LocationButtonPressAfterEvent = (System.EventHandler)System.Delegate.Remove(LocationButtonPressAfterEvent, value);
            }
        }

        private System.Windows.Forms.KeyPressEventHandler LocationTextKeyPressEvent;
        public event System.Windows.Forms.KeyPressEventHandler LocationTextKeyPress
        {
            add
            {
                LocationTextKeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Combine(LocationTextKeyPressEvent, value);
            }
            remove
            {
                LocationTextKeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Remove(LocationTextKeyPressEvent, value);
            }
        }

        private System.EventHandler LocationTextChangedEvent;
        public event System.EventHandler LocationTextChanged
        {
            add
            {
                LocationTextChangedEvent = (System.EventHandler)System.Delegate.Combine(LocationTextChangedEvent, value);
            }
            remove
            {
                LocationTextChangedEvent = (System.EventHandler)System.Delegate.Remove(LocationTextChangedEvent, value);
            }
        }

        private System.EventHandler LocationTextLostFocusEvent;
        public event System.EventHandler LocationTextLostFocus
        {
            add
            {
                LocationTextLostFocusEvent = (System.EventHandler)System.Delegate.Combine(LocationTextLostFocusEvent, value);
            }
            remove
            {
                LocationTextLostFocusEvent = (System.EventHandler)System.Delegate.Remove(LocationTextLostFocusEvent, value);
            }
        }

        private System.EventHandler LocationTextGotFocusEvent;
        public event System.EventHandler LocationTextGotFocus
        {
            add
            {
                LocationTextGotFocusEvent = (System.EventHandler)System.Delegate.Combine(LocationTextGotFocusEvent, value);
            }
            remove
            {
                LocationTextGotFocusEvent = (System.EventHandler)System.Delegate.Remove(LocationTextGotFocusEvent, value);
            }
        }

        private void ctrlOper_ButtonPress(object sender, EventArgs e)
        {
            if (OperButtonPressEvent != null)
                OperButtonPressEvent(this, e);
        }

        private void ctrlOper_ButtonPressAfter(object sender, EventArgs e)
        {
            if (OperButtonPressAfterEvent != null)
                OperButtonPressAfterEvent(this, e);
        }

        private void ctrlOper_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            ctrlLocation.Text = "";
            if (MPCF.Trim(ctrlOper.Text) != "" &&
                MPCF.Trim(ctrlLocation.Text) != "")
            {
                txtDesc.Text = ctrlOper.DescText + " / " + ctrlLocation.DescText;
            }
            else
            {
                txtDesc.Text = ctrlOper.DescText;
            }

            if (OperSelectedItemChangedEvent != null)
                OperSelectedItemChangedEvent(this, e);
        }

        private void ctrlOper_TextBoxGotFocus(object sender, EventArgs e)
        {
            if (OperTextGotFocusEvent != null)
                OperTextGotFocusEvent(this, e);
        }

        private void ctrlOper_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            if (OperTextKeyPressEvent != null)
                OperTextKeyPressEvent(this, e);
        }

        private void ctrlOper_TextBoxLostFocus(object sender, EventArgs e)
        {
            if (OperTextLostFocusEvent != null)
                OperTextLostFocusEvent(this, e);
        }

        private void ctrlOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (OperTextChangedEvent != null)
                OperTextChangedEvent(this, e);
        }


        private void ctrlLocation_ButtonPress(object sender, EventArgs e)
        {
            if (MPCF.Trim(ctrlOper.Text) == "")
            {
                ctrlLocation.ListCond_ArguList = new string[] { "%" };
            }
            else
            {
                ctrlLocation.ListCond_ArguList = new string[] { MPCF.Trim(ctrlOper.Text) };
                ctrlLocation.ListCond_Key1 = MPCF.Trim(ctrlOper.Text);
            }

            if (LocationButtonPressEvent != null)
                LocationButtonPressEvent(this, e);
        }

        private void ctrlLocation_ButtonPressAfter(object sender, EventArgs e)
        {
            if (LocationButtonPressAfterEvent != null)
                LocationButtonPressAfterEvent(this, e);
        }

        private void ctrlLocation_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            if (MPCF.Trim(ctrlOper.Text) != "" &&
                MPCF.Trim(ctrlLocation.Text) != "")
            {
                txtDesc.Text = ctrlOper.DescText + " / " + ctrlLocation.DescText;
            }
            else
            {
                txtDesc.Text = ctrlLocation.DescText;
            }

            if (LocationSelectedItemChangedEvent != null)
                LocationSelectedItemChangedEvent(this, e);
        }

        private void ctrlLocation_TextBoxGotFocus(object sender, EventArgs e)
        {
            if (LocationTextGotFocusEvent != null)
                LocationTextGotFocusEvent(this, e);
        }

        private void ctrlLocation_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            if (LocationTextKeyPressEvent != null)
                LocationTextKeyPressEvent(this, e);
        }

        private void ctrlLocation_TextBoxLostFocus(object sender, EventArgs e)
        {
            if (LocationTextLostFocusEvent != null)
                LocationTextLostFocusEvent(this, e);
        }

        private void ctrlLocation_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (LocationTextChangedEvent != null)
                LocationTextChangedEvent(this, e);
        }

        
        #endregion

        #region "Properties"

        public new bool Enabled
        {
            get
            {
                return ctrlOper.Enabled;
            }
            set
            {
                ctrlOper.Enabled = value;
                ctrlLocation.Enabled = value;
            }
        }
        
        public char ListCond_Step
        {
            get
            {
                return m_cond_c_step;
            }
            set
            {
                m_cond_c_step = value;
            }
        }
        public string ListCond_ExtFactory
        {
            get
            {
                if (m_cond_s_ext_factory == null) m_cond_s_ext_factory = "";
                return m_cond_s_ext_factory;
            }
            set
            {
                m_cond_s_ext_factory = value;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string ListCond_Filter
        {
            get
            {
                if (m_cond_s_filter == null) m_cond_s_filter = "";
                return m_cond_s_filter;
            }
            set
            {
                m_cond_s_filter = value;
            }
        }

        [Browsable(true), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public Miracom.MESCore.Controls.udcOperationInv GetOper
        {
            get
            {
                return ctrlOper;
            }
        }

        [Browsable(true), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public Miracom.MESCore.Controls.udcGCM GetLocation
        {
            get
            {
                return ctrlLocation;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string OperText
        {
            get
            {
                return ctrlOper.Text;
            }
            set
            {
                ctrlOper.Text = value;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string LocationText
        {
            get
            {
                return ctrlLocation.Text;
            }
            set
            {
                ctrlLocation.Text = value;
            }
        }

        public string LabelText
        {
            get
            {
                return lblLabel.Text;
            }
            set
            {
                lblLabel.Text = value;
            }
        }

        public int LabelWidth
        {
            get
            {
                return lblLabel.Width;
            }
            set
            {
                pnlLabel.Width = value;
                lblLabel.Width = value;
            }
        }

        public int OperWidth
        {
            get
            {
                return ctrlOper.Width;
            }
            set
            {
                ctrlOper.Width = value;
            }
        }

        public int LocationWidth
        {
            get
            {
                return ctrlLocation.Width;
            }
            set
            {
                int i_width = value;
                pnlControl.Width = ctrlOper.Width + pnlMargin1.Width + i_width;
                ctrlLocation.Width = i_width;
            }
        }

        public bool VisibleDesc
        {
            get
            {
                return m_b_visible_desc;
            }
            set
            {
                m_b_visible_desc = value;
                txtDesc.Visible = value;

                if (m_b_visible_desc)
                {
                    pnlMarginDesc.Width = pnlMarginLabel.Width;
                    txtDesc.Dock = DockStyle.Fill;
                    pnlControl.Dock = DockStyle.Left;
                }
                else
                {
                    txtDesc.Width = 0;
                    txtDesc.Dock = DockStyle.None;
                    pnlMarginDesc.Width = 0;
                    pnlControl.Dock = DockStyle.Fill;
                }
            }
        }

        public int SelectedSubItemIndex
        {
            get
            {
                return m_SelectedSubItemIndex;
            }
            set
            {
                m_SelectedSubItemIndex = value;
                ctrlOper.SelectedSubItemIndex = m_SelectedSubItemIndex;
                ctrlLocation.SearchSubItemIndex = m_SelectedSubItemIndex;
            }
        }

        public int DisplaySubItemIndex
        {
            get
            {
                return m_DisplaySubItemIndex;
            }
            set
            {
                m_DisplaySubItemIndex = value;
                ctrlOper.DisplaySubItemIndex = m_DisplaySubItemIndex;
                ctrlLocation.DisplaySubItemIndex = m_DisplaySubItemIndex;
            }
        }

        public int SelectedDescIndex
        {
            get
            {
                return m_SelectedDescIndex;
            }
            set
            {
                m_SelectedDescIndex = value;
                ctrlOper.SelectedDescIndex = m_SelectedDescIndex;
                ctrlLocation.SelectedDescIndex = m_SelectedDescIndex;
            }
        }

#if _INV

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public Miracom.MESCore.Controls.OperFlagList ListCond_OperFlagList
        {
            get
            {
                return ctrlOper.ListCond_OperFlagList;
            }
            set
            {
                ctrlOper.ListCond_OperFlagList = value;
            }
        }

#endif


        #endregion

        private void udcOperLocation_FontChanged(object sender, EventArgs e)
        {
            ctrlOper.Font = this.Font;
            ctrlLocation.Font = this.Font;
        }

        public void Init()
        {
            m_cond_c_step = '1';
            m_cond_s_ext_factory = "";
            m_cond_s_filter = "";

            VisibleDesc = false;

            ctrlOper.Init();

            ctrlLocation.Init();
            ctrlLocation.ListCond_Step = '1';
            ctrlLocation.ListCond_TableName = "@ERP_STOCK_CODE";
            ctrlLocation.GetListView.Columns[0].Tag = "KEY_2";
            ctrlLocation.GetListView.Columns[1].Tag = "DATA_4";

            DisplaySubItemIndex = 1;
            SelectedDescIndex = 1;
            //SearchSubItemIndex = 0;
            SelectedSubItemIndex = 0;
        }

        public bool CheckValue()
        {
            if (MPCF.CheckValue(ctrlOper, 1) == true &&
                MPCF.CheckValue(ctrlLocation, 1) == true) return true;
            else return false;
        }

        public void ClearField()
        {
            ctrlOper.ClearField();
            ctrlLocation.ClearField();
            txtDesc.Text = "";
        }
    }
}
