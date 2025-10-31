using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
namespace Miracom.RASCore
{
    public partial class frmRASTranCarrierEvent : Miracom.MESCore.TranForm01
    {
        public frmRASTranCarrierEvent()
        {
            InitializeComponent();
        }

        private int mi_attr_row;
        private static string[] ms_attr_name;

        private struct EVN_ITEM
        {
            public string change_item;
            public char change_flag;
            public string change_value;
            public char change_opt;
        };

        private struct CMF_ITEM
        {
            public string prompt;
            public string name;
            public int index;
        };

        private EVN_ITEM[] m_items;
        private CMF_ITEM[] m_cmfs;

        private void InitEventInfo()
        {
            // Add Default Items
            foreach (CarrierEventItem cei in modGlobalVariables.DefaultCarrierItems)
            {
                int i_row = spdData.ActiveSheet.RowCount++;
                spdData.ActiveSheet.Cells[i_row, 0].Tag = cei.ItemName;
                spdData.ActiveSheet.Cells[i_row, 0].Text = cei.ItemLabel;

                if (cei.IsDateTime)
                {
                    FarPoint.Win.Spread.CellType.DateTimeCellType DateCellType = new FarPoint.Win.Spread.CellType.DateTimeCellType();
                    DateCellType.DateTimeFormat = FarPoint.Win.Spread.CellType.DateTimeFormat.UserDefined;
                    DateCellType.UserDefinedFormat = "yyyy-MM-dd HH:mm:ss";
                    spdData.ActiveSheet.Cells[i_row, 1].CellType = DateCellType;
                    spdData.ActiveSheet.Cells[i_row, 2].CellType = DateCellType;
                }
            }

            ViewCMFItem();

            View_Attribute_Name_List();           
            
        }
        
        private void ViewCMFItem()
        {
            TRSNode out_node = new TRSNode("VIEW_FACTORY_CMF_ITEM_OUT");
            int i, i_row, i_count;

            try
            {
                
                if (WIPLIST.ViewFactoryCmfData('1', MPGC.MP_CMF_CARRIER, ref out_node, "", true) == false)
                {
                    return;
                }

                i_count = 0;

                m_cmfs = new CMF_ITEM[out_node.GetList(0).Count];
                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    string prompt = MPCF.Trim(out_node.GetList(0)[i].GetString("PROMPT"));
                    string cmf_seq = "CRR_CMF_" + (i + 1).ToString();

                    if (string.IsNullOrEmpty(prompt) == false)
                    {
                        i_row = spdData.ActiveSheet.RowCount;
                        spdData.ActiveSheet.RowCount++;
                        spdData.ActiveSheet.Cells[i_row, 0].Tag = cmf_seq;
                        spdData.ActiveSheet.Cells[i_row, 0].Text = prompt;
                        spdData.ActiveSheet.Cells[i_row, 3].Tag = out_node.GetList(0)[i].GetString("TABLE_NAME");

                        m_cmfs[i_count].name = cmf_seq;
                        m_cmfs[i_count].prompt = prompt;
                        m_cmfs[i_count].index = i_row;
                        i_count++;
                        
                    }                   
                }
                mi_attr_row = modGlobalVariables.DefaultCarrierItems.Count + i_count;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        public static bool View_Attribute_Name_List()
        {

            int i;
            ArrayList a_list;

            TRSNode in_node = new TRSNode("List_In");
            TRSNode out_node;

            a_list = new ArrayList();

           
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("ATTR_TYPE", MPGC.MP_ATTR_TYPE_CARRIER);
            in_node.AddString("NEXT_ATTR_NAME", "");
            in_node.AddInt("NEXT_ATTR_SEQ", 0);

            do
            {
                out_node = new TRSNode("List_Out");

                if (MPCR.CallService("BAS", "BAS_View_Attribute_Name_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                a_list.Add(out_node);

                in_node.SetString("NEXT_ATTR_NAME", out_node.GetString("NEXT_ATTR_NAME"));
                in_node.SetInt("NEXT_ATTR_SEQ", out_node.GetInt("NEXT_ATTR_SEQ"));

            } while (in_node.GetString("NEXT_ATTR_NAME") != "" || in_node.GetInt("NEXT_ATTR_SEQ") > 0);

            foreach (object obj in a_list)
            {
                out_node = null;
                out_node = (TRSNode)obj;

                ms_attr_name = new string[out_node.GetList(0).Count];
                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    ms_attr_name[i] = out_node.GetList(0)[i].GetString("ATTR_NAME");
                }
            }

            return true;
        }

        private bool ViewAttributeValue(string s_att_name, int i_row)
        {
            TRSNode in_node = new TRSNode("ATTR_IN");
            TRSNode out_node = new TRSNode("ATTR_OUT");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddString("ATTR_TYPE", MPGC.MP_ATTR_TYPE_CARRIER);
            in_node.AddString("ATTR_KEY", MPCF.Trim(cdvCrrID.Text));
            in_node.AddString("ATTR_NAME", MPCF.Trim(s_att_name));
            
                if (MPCR.CallService("BAS", "BAS_View_Attribute", in_node, ref out_node) == false)
                {
                    return false;
                }

                spdData.ActiveSheet.Cells[i_row, 1].Value = out_node.GetString("ATTR_VALUE");

                if (out_node.GetChar("VALID_TBL_TYPE") == 'A' || out_node.GetChar("VALID_TBL_TYPE") == 'Q')
                {
                    spdData.ActiveSheet.Cells[i_row, 3].Tag = out_node.GetString("VALID_TBL");
                }

                spdData.ActiveSheet.Rows[i_row].Height = spdData.ActiveSheet.GetPreferredRowHeight(i_row);

          
            return true;

        }

        private bool View_Carrier()
        {
            TRSNode in_node = new TRSNode("View_Carrier_In");
            TRSNode out_node = new TRSNode("View_Carrier_Out");
            int i;
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("CRR_ID", MPCF.Trim(cdvCrrID.Text));

                if (MPCR.CallService("RAS", "RAS_View_Carrier", in_node, ref out_node) == false)
                {
                    return false;
                }
                txtLastEvent.Text = out_node.GetString("LAST_TRAN_CODE");
                txtLastEventTime.Text = MPCF.MakeDateFormat(out_node.GetString("LAST_TRAN_TIME"));

                int i_row = 0;
                foreach (CarrierEventItem cei in modGlobalVariables.DefaultCarrierItems)
                {
                    string value = out_node.GetMember(cei.ItemName).Value;
                    
                    if (cei.IsDateTime)
                    {
                        value = MPCF.MakeDateFormat(value, DATE_TIME_FORMAT.DATETIME);
                    }
                    spdData.ActiveSheet.Cells[i_row, 1].Value = value;
                    i_row++;
                }

                for (i = i_row; i < mi_attr_row; i++)
                {
                    if (MPCF.Trim(spdData.ActiveSheet.Cells[i, 0].Tag) != "")
                    {
                        spdData.ActiveSheet.Cells[i, 1].Value = out_node.GetString(MPCF.Trim(spdData.ActiveSheet.Cells[i, 0].Tag));
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
        private bool View_Carrier_Event()
        {
            TRSNode in_node = new TRSNode("View_Carrier_Event_In");
            TRSNode out_node = new TRSNode("View_Carrier_Event_In");

            FarPoint.Win.Spread.CellType.ButtonCellType btnCell;
            int i;
            double d_temp;

            TRSNode node = null;
            m_items = new EVN_ITEM[30];
            try
            {
                // Clear Spread
                spdData.ActiveSheet.RowCount = mi_attr_row;
                for (i = 0; i < spdData.ActiveSheet.RowCount; i++)
                {
                    spdData.ActiveSheet.Cells[i, 2].Value = MPCF.Trim(spdData.ActiveSheet.Cells[i, 1].Value);
                    spdData.ActiveSheet.Cells[i, 2].Locked = true;
                    spdData.ActiveSheet.Cells[i, 2].BackColor = System.Drawing.Color.WhiteSmoke;
                    spdData.ActiveSheet.Cells[i, 2].ColumnSpan = 2;
                    spdData.ActiveSheet.Cells[i, 0].Font = new Font("MS Sans Serif", 8, FontStyle.Regular);
                }

                out_node = new TRSNode("View_Carrier_Event_Out");
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("CRR_EVENT_ID", MPCF.Trim(cdvCrrEventID.Text));

                if (MPCR.CallService("RAS", "RAS_View_Carrier_Event", in_node, ref out_node) == false)
                {
                    return false;
                }
                cdvCrrEventID.DescText = out_node.GetString("CRR_EVENT_DESC");

                int index = 0;
                for (i = 0; i < out_node.GetList("CHG_LIST").Count; i++)
                {
                    node = out_node.GetList("CHG_LIST")[i];
                    m_items[i].change_item = MPCF.Trim(node.GetString("CHG_ITEM"));
                    m_items[i].change_flag = node.GetChar("CHG_FLAG");
                    m_items[i].change_value = MPCF.Trim(node.GetString("CHG_VALUE"));
                    m_items[i].change_opt = node.GetChar("CHG_OPT");

                    if (string.IsNullOrEmpty(m_items[i].change_item)) continue;

                    if (Array.Exists(ms_attr_name, s => s.Equals(m_items[i].change_item)))
                    {
                        index = spdData.ActiveSheet.RowCount;
                        spdData.ActiveSheet.RowCount++;
                        spdData.ActiveSheet.Cells[index, 0].Value = m_items[i].change_item;
                        spdData.ActiveSheet.Cells[index, 0].Tag = m_items[i].change_item;

                        spdData.ActiveSheet.Cells[index, 2].Locked = true;
                        spdData.ActiveSheet.Cells[index, 2].BackColor = System.Drawing.Color.WhiteSmoke;
                        spdData.ActiveSheet.Cells[index, 2].ColumnSpan = 2;

                        ViewAttributeValue(m_items[i].change_item, spdData.ActiveSheet.RowCount - 1);
                    }
                    else
                    {
                        index = modGlobalVariables.DefaultCarrierItems.FindIndex(s => s.Equals(m_items[i].change_item));

                        if (index < 0)
                        {
                            CMF_ITEM cmf = Array.Find(m_cmfs, s => s.name.Equals(m_items[i].change_item) || s.prompt.Equals(m_items[i].change_item));
                            index = cmf.index;
                        }
                    }

                    if (m_items[i].change_opt == '1')
                    {
                        spdData.ActiveSheet.Cells[index, 0].Font = new Font("MS Sans Serif", 8, FontStyle.Bold);
                    }

                    if (m_items[i].change_flag == 'Y')
                    {
                        if (string.IsNullOrEmpty(m_items[i].change_value))
                        {
                            spdData.ActiveSheet.Cells[index, 2].Value = "";
                            spdData.ActiveSheet.Cells[index, 2].Locked = false;
                            spdData.ActiveSheet.Cells[index, 2].BackColor = System.Drawing.Color.White;
                            if (MPCF.Trim(spdData.ActiveSheet.Cells[index, 3].Tag) != "")
                            {
                                btnCell = new FarPoint.Win.Spread.CellType.ButtonCellType();
                                btnCell.Text = "...";
                                spdData.ActiveSheet.Cells[index, 3].CellType = btnCell;
                                spdData.ActiveSheet.Cells[index, 2].ColumnSpan = 1;
                            }
                        }
                        else
                        {
                            spdData.ActiveSheet.Cells[index, 2].Value = m_items[i].change_value;
                        }
                    }
                    else if (m_items[i].change_flag == 'R')
                    {
                        spdData.ActiveSheet.Cells[index, 2].Value = "";
                    }
                    else if (m_items[i].change_flag == 'T')
                    {
                        spdData.ActiveSheet.Cells[index, 2].Value = MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_DATETIME_FORMAT);
                    }
                    else if (m_items[i].change_flag == '+')
                    {
                        d_temp = MPCF.ToDbl(spdData.ActiveSheet.Cells[index, 1].Value) + MPCF.ToDbl(m_items[i].change_value);
                        spdData.ActiveSheet.Cells[index, 2].Value = d_temp;
                    }
                    else if (m_items[i].change_flag == '-')
                    {
                        d_temp = MPCF.ToDbl(spdData.ActiveSheet.Cells[index, 1].Value) - MPCF.ToDbl(m_items[i].change_value);
                        spdData.ActiveSheet.Cells[index, 2].Value = d_temp;
                    }

                    CarrierEventItem cei = modGlobalVariables.DefaultCarrierItems.Find(delegate(CarrierEventItem item)
                    {
                        return item.ItemName.Equals(m_items[i].change_item);
                    });

                    if (cei != null && cei.IsDateTime)
                    {
                        if (string.IsNullOrEmpty(m_items[i].change_value))
                        {
                            spdData.ActiveSheet.Cells[index, 2].Value = DateTime.Now;
                        }
                        else
                        {
                            spdData.ActiveSheet.Cells[index, 2].Value = MPCF.MakeDateFormat(m_items[i].change_value, DATE_TIME_FORMAT.DATETIME);
                        }
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

        private bool Carrier_Event(char ProcStep)
        {
            int j;
            int i;
            TRSNode in_node = new TRSNode("CRR_EVENT_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;

                in_node.AddString("CRR_ID", cdvCrrID.Text);
                in_node.AddString("CRR_EVENT_ID", cdvCrrEventID.Text);
                in_node.AddString("TRAN_COMMENT", txtComment.Text);

                for (j = 0; j < spdData.ActiveSheet.RowCount; j++)
                {
                    for (i = 0; i < m_items.Length; i++)
                    {
                        if (m_items[i].change_opt == '1')
                        {
                            if (m_items[i].change_item.Equals(MPCF.Trim(spdData.ActiveSheet.Cells[j, 0].Tag)) ||
                                m_items[i].change_item.Equals(MPCF.Trim(spdData.ActiveSheet.Cells[j, 0].Text)))
                            {
                                if (MPCF.Trim(spdData.ActiveSheet.Cells[j, 2].Value) == "")
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    spdData.ActiveSheet.SetActiveCell(j, 2);
                                    spdData.EditModePermanent = true;
                                    spdData.EditMode = true;
                                    return false;
                                }
                                break;
                            }                            
                        }
                    }
                }

                for (i = 0; i < modGlobalVariables.DefaultCarrierItems.Count; i++)
                {
                    CarrierEventItem cei = modGlobalVariables.DefaultCarrierItems.Find(delegate(CarrierEventItem item)
                    {
                        return item.ItemName.Equals(spdData.ActiveSheet.Cells[i, 0].Tag.ToString());
                    });

                    string value = MPCF.Trim(spdData.ActiveSheet.Cells[i, 2].Value);
                    if (cei.IsDateTime)
                    {
                        value = MPCF.DestroyDateFormat(value);
                    }
                    in_node.AddMember(cei.ItemName, value, cei.ItemType);
                }
                for (i = modGlobalVariables.DefaultCarrierItems.Count; i < mi_attr_row; i++)
                {
                    in_node.AddString(MPCF.Trim( spdData.ActiveSheet.Cells[i, 0].Tag), MPCF.Trim(spdData.ActiveSheet.Cells[i, 2].Value));
                }
                for (i = mi_attr_row; i < spdData.ActiveSheet.RowCount; i++)
                {
                    in_node.AddString(MPCF.Trim(spdData.ActiveSheet.Cells[i, 0].Value), MPCF.Trim(spdData.ActiveSheet.Cells[i, 2].Value));
                }
             
                if (MPCR.CallService("RAS", "RAS_Carrier_Event", in_node, ref out_node) == false)
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;

        }


        private void cdvCrrType_ButtonPress(object sender, System.EventArgs e)
        {
            cdvCrrType.Init();
            MPCF.InitListView(cdvCrrType.GetListView);
            cdvCrrType.Columns.Add("Carrier Type", 50, HorizontalAlignment.Left);
            cdvCrrType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvCrrType.SelectedSubItemIndex = 0;
            BASLIST.ViewGCMDataList(cdvCrrType.GetListView, '1', MPGC.MP_RAS_CRR_TYPE1);
        }

        private void cdvCrrGroup_ButtonPress(object sender, EventArgs e)
        {
            cdvCrrGroup.Init();
            MPCF.InitListView(cdvCrrGroup.GetListView);
            cdvCrrGroup.Columns.Add("Carrier Group", 50, HorizontalAlignment.Left);
            cdvCrrGroup.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvCrrGroup.SelectedSubItemIndex = 0;
            RASLIST.ViewCarrierGroupList(cdvCrrGroup.GetListView);
            cdvCrrGroup.InsertEmptyRow(0, 1);
        }

        private void cdvCrrGroup_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (MPCF.Trim(cdvCrrGroup.Text) != "")
            {
                cdvCrrID.Text = "";
            }
        }
        private void cdvCrrID_ButtonPress(System.Object sender, System.EventArgs e)
        {
            if (MPCF.Trim(cdvCrrGroup.Text) == "" && MPCF.Trim(cdvCrrType.Text) == "")
            {
                if (MPGO.RequireCarrierFilter() == true)
                {
                    if (MPCF.Trim(cdvCrrID.Text) == "")
                    {
                        cdvCrrID.IsPopup = false;
                        MPCF.ShowMsgBox(MPCF.GetMessage(258));
                        cdvCrrID.Focus();
                        return;
                    }
                }
            }

            cdvCrrID.Init();
            MPCF.InitListView(cdvCrrID.GetListView);
            cdvCrrID.Columns.Add("Carrier ID", 50, HorizontalAlignment.Left);
            cdvCrrID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvCrrID.SelectedSubItemIndex = 0;
            RASLIST.ViewCarrierList(cdvCrrID.GetListView, '1', cdvCrrGroup.Text, cdvCrrType.Text, cdvCrrID.Text);
        }

        private void cdvCrrEventID_ButtonPress(object sender, EventArgs e)
        {
            cdvCrrEventID.Init();
            MPCF.InitListView(cdvCrrEventID.GetListView);
            cdvCrrEventID.Columns.Add("Carrier ID", 50, HorizontalAlignment.Left);
            cdvCrrEventID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvCrrEventID.SelectedSubItemIndex = 0;
            cdvCrrEventID.DisplaySubItemIndex = 0;
            RASLIST.ViewCarrierEventList(cdvCrrEventID.GetListView, '1', null);
        }

        private void cdvCrrEventID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if(MPCF.Trim( cdvCrrEventID.Text ) != "")
            {
                spdData.ActiveSheet.RowCount = mi_attr_row;
                View_Carrier_Event();                
            }
        }

        private void frmRASTranCarrierEvent_Load(object sender, EventArgs e)
        {
            InitEventInfo();            
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            if (Carrier_Event('1') == true)
            {
                spdData.ActiveSheet.RowCount = mi_attr_row;
                View_Carrier();
                View_Carrier_Event();
            }
        }

        private void cdvCrrID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            txtLastEvent.Text = "";
            txtLastEventTime.Text = "";
            spdData.ActiveSheet.ClearRange(0, 1, spdData.ActiveSheet.RowCount, 1, true);
            spdData.ActiveSheet.RowCount = mi_attr_row;
            if(MPCF.Trim( cdvCrrID.Text ) != "")
            {
                View_Carrier();
            }            
        }

        private void cdvCrrID_TextBoxTextChanged(object sender, EventArgs e)
        {
            cdvCrrEventID.Text = "";
            cdvCrrEventID.DescText = "";
            txtLastEvent.Text = "";
            txtLastEventTime.Text = "";
            spdData.ActiveSheet.ClearRange(0, 1, spdData.ActiveSheet.RowCount, 2, true);
            spdData.ActiveSheet.RowCount = mi_attr_row;
            cdvCrrEventID.Text = "";
            cdvCrrEventID.DescText = "";
       }
       private void spdData_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
       {
           try
           {
               cdvTableData.Init();
               cdvTableData.ViewPosition = Control.MousePosition;
               MPCF.InitListView(cdvTableData.GetListView);
               cdvTableData.Columns.Add("Table Name", 50, HorizontalAlignment.Left);
               cdvTableData.Columns.Add("Table Desc", 50, HorizontalAlignment.Left);
               BASLIST.ViewGCMDataList(cdvTableData.GetListView, '1', MPCF.Trim(spdData.ActiveSheet.Cells[e.Row, e.Column].Tag));

               if (cdvTableData.ShowPopupList(e.Row, e.Column) == false)
               {
                   return;
               }
           }
           catch (Exception ex)
           {
               MPCF.ShowMsgBox(ex.Message);
           }
       }

       private void cdvTableData_SelectedItemChanged(object sender, UI.MCSSCodeViewSelChanged_EventArgs e)
       {
           spdData.ActiveSheet.Cells[e.Row, 2].Value = MPCF.Trim(e.SelectedItem.Text);
       }
       
    }
}

