using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;
using Miracom.TRSCore;

namespace Miracom.MESCore.Controls
{
    [DefaultEvent("SelectedItemChanged")]
    public partial class udcOperationInv : UserControl, intCodeListControl
    {
        
        private char m_cond_c_step;
        private string m_cond_s_mat_id;
        private int m_cond_i_mat_ver;
        private string m_cond_s_flow;
        private string m_cond_s_filter;
        private string m_cond_s_ext_factory;

        private bool b_refuse_event_exec = false;
        private bool b_add_empty_row_to_top = false;
        private bool b_add_empty_row_to_last = false;

        private OperFlagList m_cond_flag_list = null;



        public udcOperationInv()
        {
            InitializeComponent();

            Init();
        }
        

        #region "Control Events"
        
        private MCCodeViewSelChangedHandler SelectedItemChangedEvent;
        public event MCCodeViewSelChangedHandler SelectedItemChanged
        {
            add
            {
                SelectedItemChangedEvent = (MCCodeViewSelChangedHandler)System.Delegate.Combine(SelectedItemChangedEvent, value);
            }
            remove
            {
                SelectedItemChangedEvent = (MCCodeViewSelChangedHandler)System.Delegate.Remove(SelectedItemChangedEvent, value);
            }
        }

        private System.EventHandler ButtonPressEvent;
        public event System.EventHandler ButtonPress
        {
            add
            {
                ButtonPressEvent = (System.EventHandler)System.Delegate.Combine(ButtonPressEvent, value);
            }
            remove
            {
                ButtonPressEvent = (System.EventHandler)System.Delegate.Remove(ButtonPressEvent, value);
            }
        }

        private System.EventHandler ButtonPressAfterEvent;
        public event System.EventHandler ButtonPressAfter
        {
            add
            {
                ButtonPressAfterEvent = (System.EventHandler)System.Delegate.Combine(ButtonPressAfterEvent, value);
            }
            remove
            {
                ButtonPressAfterEvent = (System.EventHandler)System.Delegate.Remove(ButtonPressAfterEvent, value);
            }
        }

        private System.Windows.Forms.KeyPressEventHandler TextBoxKeyPressEvent;
        public event System.Windows.Forms.KeyPressEventHandler TextBoxKeyPress
        {
            add
            {
                TextBoxKeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Combine(TextBoxKeyPressEvent, value);
            }
            remove
            {
                TextBoxKeyPressEvent = (System.Windows.Forms.KeyPressEventHandler)System.Delegate.Remove(TextBoxKeyPressEvent, value);
            }
        }

        private System.EventHandler TextBoxTextChangedEvent;
        public event System.EventHandler TextBoxTextChanged
        {
            add
            {
                TextBoxTextChangedEvent = (System.EventHandler)System.Delegate.Combine(TextBoxTextChangedEvent, value);
            }
            remove
            {
                TextBoxTextChangedEvent = (System.EventHandler)System.Delegate.Remove(TextBoxTextChangedEvent, value);
            }
        }

        private System.EventHandler TextBoxLostFocusEvent;
        public event System.EventHandler TextBoxLostFocus
        {
            add
            {
                TextBoxLostFocusEvent = (System.EventHandler)System.Delegate.Combine(TextBoxLostFocusEvent, value);
            }
            remove
            {
                TextBoxLostFocusEvent = (System.EventHandler)System.Delegate.Remove(TextBoxLostFocusEvent, value);
            }
        }

        private System.EventHandler TextBoxGotFocusEvent;
        public event System.EventHandler TextBoxGotFocus
        {
            add
            {
                TextBoxGotFocusEvent = (System.EventHandler)System.Delegate.Combine(TextBoxGotFocusEvent, value);
            }
            remove
            {
                TextBoxGotFocusEvent = (System.EventHandler)System.Delegate.Remove(TextBoxGotFocusEvent, value);
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            if (ButtonPressEvent != null)
                ButtonPressEvent(this, e);

            if (b_refuse_event_exec == true)
            {
                b_refuse_event_exec = false;
                return;
            }

            ViewOperList(cdvOper.GetListView, ListCond_Step, null);
            //WIPLIST.ViewOperationList(cdvOper.GetListView, ListCond_Step, ListCond_MatID, ListCond_MatVersion, ListCond_Flow, ListCond_Filter, null, ListCond_ExtFactory);
            if (b_add_empty_row_to_top == true)
            {
                cdvOper.InsertEmptyRow(0, 1);
            }
            if (b_add_empty_row_to_last == true)
            {
                cdvOper.AddEmptyRow(1);
            }

            if (ButtonPressAfterEvent != null)
                ButtonPressAfterEvent(this, e);
        }

        private void cdvOper_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            if (SelectedItemChangedEvent != null)
                SelectedItemChangedEvent(this, e);
        }

        private void cdvOper_TextBoxGotFocus(object sender, EventArgs e)
        {
            if (TextBoxGotFocusEvent != null)
                TextBoxGotFocusEvent(this, e);
        }

        private void cdvOper_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            if (TextBoxKeyPressEvent != null)
                TextBoxKeyPressEvent(this, e);
        }

        private void cdvOper_TextBoxLostFocus(object sender, EventArgs e)
        {
            if (TextBoxLostFocusEvent != null)
                TextBoxLostFocusEvent(this, e);
        }

        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (TextBoxTextChangedEvent != null)
                TextBoxTextChangedEvent(this, e);
        }


        #endregion

        #region "Properties"

        public new bool Enabled
        {
            get
            {
                return cdvOper.Enabled;
            }
            set
            {
                cdvOper.Enabled = value;
            }
        }
        
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool RefuseEventExec
        {
            get
            {
                return b_refuse_event_exec;
            }
            set
            {
                b_refuse_event_exec = value;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public ListView.ListViewItemCollection Items
        {
            get
            {
                return cdvOper.Items;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public ListView.ColumnHeaderCollection Columns
        {
            get
            {
                return cdvOper.Columns;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public ListViewItem SelectedItem
        {
            get
            {
                return cdvOper.SelectedItem;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public bool IsPopup
        {
            get
            {
                return cdvOper.IsPopup;
            }
            set
            {
                cdvOper.IsPopup = value;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public override string Text
        {
            get
            {
                return cdvOper.Text;
            }
            set
            {
                cdvOper.Text = value;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string DisplayText
        {
            get
            {
                return cdvOper.DisplayText;
            }
            set
            {
                cdvOper.DisplayText = value;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string DescText
        {
            get
            {
                return cdvOper.DescText;
            }
            set
            {
                cdvOper.DescText = value;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public ListView GetListView
        {
            get
            {
                return cdvOper.GetListView;
            }
        }



        public new Color BackColor
        {
            get
            {
                return cdvOper.BackColor;
            }
            set
            {
                cdvOper.BackColor = value;
                lblOper.BackColor = value;
            }
        }

        public int ButtonWidth
        {
            get
            {
                return cdvOper.ButtonWidth;
            }
            set
            {
                cdvOper.ButtonWidth = value;
            }
        }

        public int TextBoxWidth
        {
            get
            {
                return cdvOper.TextBoxWidth;
            }
            set
            {
                cdvOper.TextBoxWidth = value;
            }
        }

        public int LabelWidth
        {
            get
            {
                return lblOper.Width;
            }
            set
            {
                lblOper.Width = value;
                pnlLeft.Width = value;
            }
        }

        public int MaxLength
        {
            get
            {
                return cdvOper.MaxLength;
            }
        }

        public string LabelText
        {
            get
            {
                return lblOper.Text;
            }
            set
            {
                lblOper.Text = value;
            }
        }




        public int SelectedSubItemIndex
        {
            get
            {
                return cdvOper.SelectedSubItemIndex;
            }
            set
            {
                cdvOper.SelectedSubItemIndex = value;
            }
        }

        public int DisplaySubItemIndex
        {
            get
            {
                return cdvOper.DisplaySubItemIndex;
            }
            set
            {
                cdvOper.DisplaySubItemIndex = value;
            }
        }

        public int SelectedDescIndex
        {
            get
            {
                return cdvOper.SelectedDescIndex;
            }
            set
            {
                cdvOper.SelectedDescIndex = value;
            }
        }

        public int SearchSubItemIndex
        {
            get
            {
                return cdvOper.SearchSubItemIndex;
            }
            set
            {
                cdvOper.SearchSubItemIndex = value;
            }
        }

        public bool ReadOnly
        {
            get
            {
                return cdvOper.ReadOnly;
            }
            set
            {
                if (value == true)
                    cdvOper.BackColor = this.BackColor;
                else
                    cdvOper.BackColor = SystemColors.Window;
                cdvOper.ReadOnly = value;
            }
        }



        public bool VisibleButton
        {
            get
            {
                return cdvOper.VisibleButton;
            }
            set
            {
                cdvOper.VisibleButton = value;
            }
        }

        public bool VisibleDescription
        {
            get
            {
                return cdvOper.VisibleDescription;
            }
            set
            {
                cdvOper.VisibleDescription = value;
            }
        }

        public bool VisibleColumnHeader
        {
            get
            {
                return cdvOper.VisibleColumnHeader;
            }
            set
            {
                cdvOper.VisibleColumnHeader = value;
            }
        }

        public bool AddEmptyRowToTop
        {
            get
            {
                return b_add_empty_row_to_top;
            }
            set
            {
                b_add_empty_row_to_top = value;
            }
        }

        public bool AddEmptyRowToLast
        {
            get
            {
                return b_add_empty_row_to_last;
            }
            set
            {
                b_add_empty_row_to_last = value;
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
        public string ListCond_MatID
        {
            get
            {
                if (m_cond_s_mat_id == null) m_cond_s_mat_id = "";
                return m_cond_s_mat_id;
            }
            set
            {
                m_cond_s_mat_id = value;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int ListCond_MatVersion
        {
            get
            {
                return m_cond_i_mat_ver;
            }
            set
            {
                m_cond_i_mat_ver = value;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string ListCond_Flow
        {
            get
            {
                if (m_cond_s_flow == null) m_cond_s_flow = "";
                return m_cond_s_flow;
            }
            set
            {
                m_cond_s_flow = value;
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
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden), DescriptionAttribute("WIP_FLAG=공정창고")]
        public OperFlagList ListCond_OperFlagList
        {
            get
            {
                if (m_cond_flag_list == null)
                {
                    m_cond_flag_list = new OperFlagList();
                    m_cond_flag_list.Check = true;
                }
                return m_cond_flag_list;
            }
            set
            {
                m_cond_flag_list = value;
            }
        }

        [Browsable(true), DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
        public Font LabelFont
        {
            get
            {
                return lblOper.Font;
            }
            set
            {
                lblOper.Font = value;
            }
        }
        #endregion

        




        private void udcOperationInv_FontChanged(object sender, EventArgs e)
        {
            cdvOper.Font = this.Font;
        }
        
        public void Init()
        {
            m_cond_c_step = '1';
            m_cond_s_ext_factory = "";
            m_cond_s_mat_id = "";
            m_cond_i_mat_ver = 0;
            m_cond_s_flow = "";
            m_cond_s_filter = "";

            SelectedDescIndex = 1;
            SearchSubItemIndex = 0;

            cdvOper.Init();
            MPCF.InitListView(cdvOper.GetListView);
            cdvOper.Columns.Add("Operation", 100, HorizontalAlignment.Left);
            cdvOper.Columns.Add("Desc", 200, HorizontalAlignment.Left);
            cdvOper.SelectedSubItemIndex = 0;
            cdvOper.MaxLength = 10;
        }
        
        public bool CheckValue()
        {
            return MPCF.CheckValue(this.cdvOper, 1);
        }

        public void ClearField()
        {
            cdvOper.Text = "";
        }

        public bool ViewOperList(Control control, char c_step, TreeNode parentNode)
        {

            int i;
            ListViewItem itmX;
            TreeNode nodeX;

            TRSNode in_node = new TRSNode("VIEW_OPER_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_OPER_LIST_OUT");

            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                if (!(parentNode == null))
                {
                    parentNode.Nodes.Clear();
                }
                else
                {
                    MPCF.ClearList(control, true);
                }
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            do
            {
                if (MPCR.CallService("INV", "INV_View_Oper_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (ListCond_OperFlagList.Check)
                    {
                        if (ListCond_OperFlagList.WIP_FLAG != '%' && ListCond_OperFlagList.WIP_FLAG != out_node.GetList(0)[i].GetChar("WIP_FLAG")) continue;
                        if (ListCond_OperFlagList.NG_FLAG != '%' && ListCond_OperFlagList.NG_FLAG != out_node.GetList(0)[i].GetChar("NG_FLAG")) continue;
                        if (ListCond_OperFlagList.TRAN_IN_FLAG != '%' && ListCond_OperFlagList.TRAN_IN_FLAG != out_node.GetList(0)[i].GetChar("TRAN_IN_FLAG")) continue;
                        if (ListCond_OperFlagList.TRAN_OUT_FLAG != '%' && ListCond_OperFlagList.TRAN_OUT_FLAG != out_node.GetList(0)[i].GetChar("TRAN_OUT_FLAG")) continue;
                        if (ListCond_OperFlagList.IN_OUT_FLAG != '%' && ListCond_OperFlagList.IN_OUT_FLAG != out_node.GetList(0)[i].GetChar("IN_OUT_FLAG")) continue;
                        if (ListCond_OperFlagList.IN_WIP_FLAG != '%' && ListCond_OperFlagList.IN_WIP_FLAG != out_node.GetList(0)[i].GetChar("INV_IN_WIP_FLAG")) continue;
                        if (ListCond_OperFlagList.IQC_FLAG != '%' && ListCond_OperFlagList.IQC_FLAG != out_node.GetList(0)[i].GetChar("IQC_REQ_FLAG")) continue;
                        if (ListCond_OperFlagList.INV_WH_FLAG != '%' && ListCond_OperFlagList.INV_WH_FLAG != out_node.GetList(0)[i].GetChar("INV_WH_FLAG")) continue;
                        if (ListCond_OperFlagList.INTRANSIT_FLAG != '%' && ListCond_OperFlagList.INTRANSIT_FLAG != out_node.GetList(0)[i].GetChar("INV_INTRANSIT_FLAG")) continue;
                        if (ListCond_OperFlagList.SPARE_FLAG != '%' && ListCond_OperFlagList.SPARE_FLAG != out_node.GetList(0)[i].GetChar("SPARE_FLAG")) continue;
                    }
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(out_node.GetList(0)[i].GetString("OPER"), (int)SMALLICON_INDEX.IDX_OPER);
                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetString("OPER_DESC"));
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(out_node.GetList(0)[i].GetString("OPER") + " : " + out_node.GetList(0)[i].GetString("OPER_DESC"),
                            (int)SMALLICON_INDEX.IDX_OPER, (int)SMALLICON_INDEX.IDX_OPER);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox)control).Items.Add(out_node.GetList(0)[i].GetString("OPER"));

                    }
                }

                in_node.SetString("NEXT_OPER", out_node.GetString("NEXT_OPER"));
            } while (in_node.GetString("NEXT_OPER") != "");

            return true;
        }

    }
    [Description("InvOper Flag Filter")]
    public class OperFlagList
    {
        public bool Check = false;

        public char WIP_FLAG = '%';         //공정창고
        public char NG_FLAG = '%';          //부적합창고
        public char TRAN_IN_FLAG = '%';     //입고가능
        public char TRAN_OUT_FLAG = '%';    //출고가능
        public char IN_OUT_FLAG = '%';      //사내사외구분
        public char IN_WIP_FLAG = '%';      //공정(투입)대기
        public char IQC_FLAG = '%';         //검사의뢰 사용
        public char INV_WH_FLAG = '%';      //자재창고
        public char INTRANSIT_FLAG = '%';   //입고대기
        public char SPARE_FLAG = '%';       //예비부품
    }

}
