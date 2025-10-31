using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;
using CUS_COM.BaseForm;

namespace CUS_COM.Controls
{
    public partial class udcTextPackLotID : UserControl, intCodeListControl
    {
        public udcTextPackLotID()
        {
            InitializeComponent();

            Init();
        }

        private void udcTextPackLotID_Load(object sender, EventArgs e)
        {

        }

        public void Init()
        {
            this.Text = "";
        }
        public bool CheckValue()
        {
            return MPCF.CheckValue(this.txtLotID, 1);
        }

        public void ClearField()
        {
            txtLotID.Text = "";
        }

        #region "Properties"

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public override string Text
        {
            get
            {
                return txtLotID.Text;
            }
            set
            {
                txtLotID.Text = value;
            }
        }
        public new Color BackColor
        {
            get
            {
                return panInfo.BackColor;
            }
            set
            {
                panInfo.BackColor = value;
                lblLotId.BackColor = value;
            }
        }

        [Category("TextBackColor"), Description("텍스트 BackColor")]
        public Color TextBackColor
        {
            get
            {
                return txtLotID.BackColor;
            }
            set
            {
                txtLotID.BackColor = value;
            }
        }

        public int MaxLength
        {
            get
            {
                return txtLotID.MaxLength;
            }
        }

        public string LabelText
        {
            get
            {
                return lblLotId.Text;
            }
            set
            {
                lblLotId.Text = value;
            }
        }

        public bool ReadOnly
        {
            get
            {
                return txtLotID.ReadOnly;
            }
            set
            {
                if (value == true)
                    txtLotID.BackColor = this.BackColor;
                else
                    txtLotID.BackColor = SystemColors.Window;
                txtLotID.ReadOnly = value;
            }
        }


        public bool VisibleButton
        {
            get
            {
                return btnPop.Visible;
            }
            set
            {
                btnPop.Visible= value;
            }
        }


        [Browsable(true), DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
        public Font LabelFont
        {
            get
            {
                return lblLotId.Font;
            }
            set
            {
                lblLotId.Font = value;
            }
        }

        [Browsable(false)]
        public string sArea_id
        {
            get;
            set;
        }
        [Browsable(false)]
        public string sArea_desc
        {
            get;
            set;
        }

        [Browsable(false)]
        public string sOper_id
        {
            get;
            set;
        }


        [Browsable(false)]
        public string sOper_desc
        {
            get;
            set;
        }

        [Browsable(false)]
        public string sMat_id
        {
            get;
            set;
        }

        [Browsable(false)]
        public bool b_Stop_Flag
        {
            get;
            set;
        }

        #endregion

        #region "Control Events"


        private System.Windows.Forms.KeyPressEventHandler KeyPressEvent;
        new public event System.Windows.Forms.KeyPressEventHandler KeyPress
        {
            add
            {
                KeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Combine(KeyPressEvent, value);
            }
            remove
            {
                KeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Remove(KeyPressEvent, value);
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (KeyPressEvent != null)
                KeyPressEvent(this, e);
        }



        private Infragistics.Win.Misc.AlertButtonClickedHandler ButtonClickEvent;
        public event Infragistics.Win.Misc.AlertButtonClickedHandler ButtonClick
        {
            add
            {
                ButtonClickEvent = (Infragistics.Win.Misc.AlertButtonClickedHandler)System.Delegate.Combine(ButtonClickEvent, value);
            }
            remove
            {
                ButtonClickEvent = (Infragistics.Win.Misc.AlertButtonClickedHandler)System.Delegate.Remove(ButtonClickEvent, value);
            }
        }

        private void btnPop_Click(object sender, EventArgs e)
        {
            try
            {
                if (ButtonClickEvent != null)
                    ButtonClickEvent(this, null);

                frmPopPackLotList popup = new frmPopPackLotList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = sArea_id;
                popup.sArea_desc = sArea_desc;
                popup.sOper_id = sOper_id;
                popup.sOper_desc = sOper_desc;
                popup.sMat_id = sMat_id;
                
                if (popup.ShowDialog() == DialogResult.OK)
                {
                    if (CSGV.l_lot_list.Count > 0)
                    {
                        if (CSGV.l_lot_list.Count > 0)
                        {
                            for (int i = 0; i < CSGV.l_lot_list.Count; i++)
                            {
                                txtLotID.Text = CSGV.l_lot_list[i].ToString();

                                if(b_Stop_Flag == true)
                                {
                                    break;
                                }

                                KeyPressEvent(this, new KeyPressEventArgs((char)13));
                            }

                            txtLotID.Text = "";
                            CSGV.l_lot_list.Clear();
                        }
                    } 

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion
    }
}
