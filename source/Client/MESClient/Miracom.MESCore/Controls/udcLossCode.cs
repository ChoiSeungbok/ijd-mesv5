using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using Miracom.MESCore;
using Miracom.CliFrx;
using Miracom.UI;
using Miracom.TRSCore;

namespace Miracom.MESCore.Controls
{
    public partial class udcLossCode : UserControl
    {
        private char m_cond_c_step;
        private string m_cond_s_ext_factory;
        private string m_cond_s_module;
        private string m_cond_s_loss_table;
        private string m_cond_s_lot_id;

        private double m_d_lot_qty_1;
        private double m_d_lot_qty_2;
        private double m_d_lot_qty_3;
        private double m_d_loss_qty;
        private int m_i_loss_count;
        private double m_d_out_qty;

        private List<string> m_list_loss_code;
        private List<double> m_list_loss_qty;

        private int COL_CODE = 0;
        private int COL_BTN = 1;
        private int COL_DESC = 2;
        private int COL_QTY_1 = 3;
        private int COL_QTY_2 = 4;
        private int COL_QTY_3 = 5;

        private bool m_b_view_loss = false;
        private bool m_b_input_loss = true;
        private CTYPE m_e_control_type = CTYPE.INPUT;

        public enum CTYPE
        {
            VIEW, INPUT, BOTH
        }
        
        public udcLossCode()
        {
            InitializeComponent();

            Init();
        }

        #region " Control Events "

        private MCSSCodeViewSelChangedHandler SelectedItemChangedEvent;
        public event MCSSCodeViewSelChangedHandler SelectedItemChanged
        {
            add
            {
                SelectedItemChangedEvent = (MCSSCodeViewSelChangedHandler)System.Delegate.Combine(SelectedItemChangedEvent, value);
            }
            remove
            {
                SelectedItemChangedEvent = (MCSSCodeViewSelChangedHandler)System.Delegate.Remove(SelectedItemChangedEvent, value);
            }
        }

        private System.EventHandler LossQtyChangedEvent;
        public event System.EventHandler LossQtyChanged
        {
            add
            {
                LossQtyChangedEvent = (System.EventHandler)System.Delegate.Combine(LossQtyChangedEvent, value);
            }
            remove
            {
                LossQtyChangedEvent = (System.EventHandler)System.Delegate.Remove(LossQtyChangedEvent, value);
            }
        }

        #endregion

        #region " Properties "

        public CTYPE ListCond_ControlType
        {
            get
            {
                return m_e_control_type;
            }
            set
            {
                m_e_control_type = value;
                if (m_e_control_type == CTYPE.VIEW)
                {
                    spdLossList_Sheet1.Columns[COL_BTN].Visible = false;
                    m_b_view_loss = true;
                    m_b_input_loss = false;
                }
                else
                {
                    if (m_e_control_type == CTYPE.BOTH)
                    {
                        m_b_view_loss = true;
                    }
                    else
                    {
                        m_b_view_loss = false;
                    }
                    m_b_input_loss = true;
                    spdLossList_Sheet1.Columns[COL_BTN].Visible = true;
                }
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
        public string ListCond_LossTable
        {
            get
            {
                if (m_cond_s_loss_table == null) m_cond_s_loss_table = "";
                return m_cond_s_loss_table;
            }
            set
            {
                m_cond_s_loss_table = value;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string ListCond_LotID
        {
            get
            {
                if (m_cond_s_lot_id == null) m_cond_s_lot_id = "";
                return m_cond_s_lot_id;
            }
            set
            {
                m_cond_s_lot_id = value;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string ListCond_Module
        {
            get
            {
                if (m_cond_s_module == null) m_cond_s_module = "";
                return m_cond_s_module;
            }
            set
            {
                m_cond_s_module = value;
            }
        }

        //public double InQty
        //{
        //    get
        //    {
        //        return m_d_lot_qty;
        //    }
        //    set
        //    {
        //        m_d_lot_qty = value;
        //    }
        //}
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public double TotalLossQty
        {
            get
            {
                return m_d_loss_qty;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public double OutQty
        {
            get
            {
                return m_d_out_qty;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public int LossCount
        {
            get
            {
                return m_i_loss_count;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public List<string> LossCodeList
        {
            get
            {
                if (m_list_loss_code == null) m_list_loss_code = new List<string>();
                return m_list_loss_code;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public List<double> LossQtyList
        {
            get
            {
                if (m_list_loss_qty == null) m_list_loss_qty = new List<double>();
                return m_list_loss_qty;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public double Lot_Qty_1
        {
            set
            {
                m_d_lot_qty_1 = value;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public double Lot_Qty_2
        {
            set
            {
                m_d_lot_qty_2 = value;
            }
        }
        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public double Lot_Qty_3
        {
            set
            {
                m_d_lot_qty_3 = value;
            }
        }

        public bool VisibleQty1
        {
            get
            {
                return spdLossList_Sheet1.Columns[COL_QTY_1].Visible;
            }
            set
            {
                spdLossList_Sheet1.Columns[COL_QTY_1].Visible = value;
            }
        }

        public bool VisibleQty2
        {
            get
            {
                return spdLossList_Sheet1.Columns[COL_QTY_2].Visible;
            }
            set
            {
                spdLossList_Sheet1.Columns[COL_QTY_2].Visible = value;
            }
        }

        public bool VisibleQty3
        {
            get
            {
                return spdLossList_Sheet1.Columns[COL_QTY_3].Visible;
            }
            set
            {
                spdLossList_Sheet1.Columns[COL_QTY_3].Visible = value;
            }
        }

        #endregion

        #region " Function "

        public void Init()
        {
            m_cond_c_step = '1';
            m_cond_s_ext_factory = "";
            m_cond_s_loss_table = "";

            m_d_loss_qty = 0;
            m_d_loss_qty = 0;
            m_d_out_qty = 0;

            VisibleQty1 = true;
            VisibleQty2 = false;
            VisibleQty3 = false;

            if (m_b_input_loss)
            {
                spdLossList_Sheet1.RowCount = 1;
            }
            else
            {
                spdLossList_Sheet1.RowCount = 0;
            }
        }

        public bool CheckValue()
        {
            return true;
        }

        public void ClearField()
        {
            spdLossList_Sheet1.RowCount = 0;
            m_list_loss_code.Clear();
            m_list_loss_qty.Clear();

            if (m_b_input_loss)
            {
                spdLossList_Sheet1.RowCount = 1;
            }
        }

        private void SumLoss()
        {
            double d_total_qty;
            int i_total_count;
            int i;

            d_total_qty = 0;
            i_total_count = 0;
            LossCodeList.Clear();
            LossQtyList.Clear();

            for (i = 0; i < spdLossList.ActiveSheet.RowCount; i++)
            {
                if (spdLossList.ActiveSheet.GetValue(i, COL_CODE) == null || MPCF.Trim(spdLossList.ActiveSheet.GetValue(i, COL_CODE)) == "") continue;
                if (spdLossList.ActiveSheet.GetValue(i, COL_QTY_1) == null || MPCF.ToDbl(spdLossList.ActiveSheet.GetValue(i, COL_QTY_1)) <= 0) continue;
                if (spdLossList.ActiveSheet.Rows[i].Locked == true) continue;

                d_total_qty += MPCF.ToDbl(spdLossList.ActiveSheet.GetValue(i, COL_QTY_1));
                i_total_count++;
                LossCodeList.Add(MPCF.Trim(spdLossList.ActiveSheet.GetValue(i, COL_CODE)));
                LossQtyList.Add(MPCF.ToDbl(spdLossList.ActiveSheet.GetValue(i, COL_QTY_1)));
            }

            m_d_loss_qty = d_total_qty;
            m_i_loss_count = i_total_count;
            m_d_out_qty = m_d_lot_qty_1 - d_total_qty;
        }

        public virtual bool ViewLossInfo(bool inv_lot)
        {
            if (inv_lot) m_cond_s_module = "INV";
            else m_cond_s_module = "WIP";

            return ViewLossInfo();
        }
        public virtual bool ViewLossInfo()
        {
            TRSNode in_node = new TRSNode("WIP_View_Lot_In");
            TRSNode out_node = new TRSNode("WIP_View_Lot_Out");
            System.Collections.ArrayList a_list;
            int i;
            string sQuery, table_name;
            DataTable dtOut = null;

            try
            {
                if (m_b_view_loss == false) return true;

                if (ListCond_Module == "") ListCond_Module = "WIP";

                a_list = new System.Collections.ArrayList();

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                table_name = "MWIPLOTLSM";
                if (ListCond_Module == "INV")
                {
                    table_name = "MINVLOTLSM";
                }

                sQuery = "" +
                    string.Format(" SELECT                                                    ") + " \r\n" +
                    string.Format(" KEY_1, DATA_1, QTY_1, QTY_2, QTY_3                        ") + " \r\n" +
                    string.Format(" FROM                                                      ") + " \r\n" +
                    string.Format(" (                                                         ") + " \r\n" +
                    string.Format("     SELECT                                                ") + " \r\n" +
                    string.Format("     L.FACTORY, LOSS_CODE, LOSS_TBL,                       ") + " \r\n" +
                    string.Format("     NVL(SUM(DECODE(QTY_FLAG, '1', LOSS_QTY, 0)), 0) QTY_1,") + " \r\n" +
                    string.Format("     NVL(SUM(DECODE(QTY_FLAG, '2', LOSS_QTY, 0)), 0) QTY_2,") + " \r\n" +
                    string.Format("     NVL(SUM(DECODE(QTY_FLAG, '3', LOSS_QTY, 0)), 0) QTY_3 ") + " \r\n" +
                    string.Format("      FROM {0} L, MWIPOPRDEF O                             ", table_name) + " \r\n" +
                    string.Format("     WHERE L.FACTORY = '{0}'                               ", in_node.Factory) + " \r\n" +
                    string.Format("     AND L.LOT_ID = '{0}'                                  ", ListCond_LotID) + " \r\n" +
                    string.Format("     AND L.FACTORY = O.FACTORY                             ") + " \r\n" +
                    string.Format("     AND L.OPER = O.OPER                                   ") + " \r\n" +
                    string.Format("     GROUP BY L.FACTORY, LOSS_CODE, LOSS_TBL               ") + " \r\n" +
                    string.Format(" ) L, MGCMTBLDAT G                                         ") + " \r\n" +
                    string.Format(" WHERE L.FACTORY = G.FACTORY                               ") + " \r\n" +
                    string.Format(" AND L.LOSS_TBL = G.TABLE_NAME                             ") + " \r\n" +
                    string.Format(" AND L.LOSS_CODE = G.KEY_1                                 ") + " \r\n" +
                    string.Format(" ORDER BY KEY_1                                            ");

                in_node.AddString("SQL", sQuery);

                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                dtOut = MPCR.ConvertToDataTable(out_node);

                spdLossList_Sheet1.RowCount = 0;

                if (dtOut != null)
                {
                    for (i = 0; i < dtOut.Rows.Count; i++)
                    {
                        spdLossList_Sheet1.RowCount = i + 1;
                        spdLossList_Sheet1.Cells[i, COL_CODE].Value = MPCF.Trim(dtOut.Rows[i][0]);
                        spdLossList_Sheet1.Cells[i, COL_DESC].Value = MPCF.Trim(dtOut.Rows[i][1]);
                        spdLossList_Sheet1.Cells[i, COL_BTN].ResetCellType();
                        spdLossList_Sheet1.Cells[i, COL_QTY_1].Value = MPCF.ToDbl(dtOut.Rows[i][2]);
                        spdLossList_Sheet1.Cells[i, COL_QTY_2].Value = MPCF.ToDbl(dtOut.Rows[i][3]);
                        spdLossList_Sheet1.Cells[i, COL_QTY_3].Value = MPCF.ToDbl(dtOut.Rows[i][4]);

                        spdLossList_Sheet1.Rows[i].Locked = true;
                        spdLossList_Sheet1.Rows[i].BackColor = Color.WhiteSmoke;
                    }
                }

                if (m_b_input_loss)
                {
                    spdLossList_Sheet1.RowCount += 1;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        public bool ViewLotInfo(string lot_id)
        {
            return ViewLotInfo(lot_id, false);
        }
        public bool ViewLotInfo(string lot_id, bool inv_lot)
        {
            TRSNode in_node = new TRSNode("WIP_View_Lot_In");
            TRSNode out_node = new TRSNode("WIP_View_Lot_Out");
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", MPCF.Trim(lot_id));

                if (inv_lot)
                {
                    m_cond_s_module = "INV";
                    if (MPCR.CallService("INV", "INV_View_Lot", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                else
                {
                    m_cond_s_module = "WIP";
                    if (MPCR.CallService("WIP", "WIP_View_Lot", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }

                ListCond_LotID = lot_id;
                Lot_Qty_1 = out_node.GetDouble("QTY_1");
                Lot_Qty_2 = out_node.GetDouble("QTY_2");
                Lot_Qty_3 = out_node.GetDouble("QTY_3");

                if (out_node.GetString("OPER") != "")
                {
                    View_Operation(out_node.GetString("OPER"));
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        // View_Operation()
        //       -  View Operation Information
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //
        private bool View_Operation(string oper)
        {

            TRSNode in_node = new TRSNode("View_Operation_In");
            TRSNode out_node = new TRSNode("View_Operation_Out");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddString("OPER", oper);

            if (MPCR.CallService("WIP", "WIP_View_Operation", in_node, ref out_node) == false)
            {
                return false;
            }

            ListCond_LossTable = out_node.GetString("LOSS_TBL");

            return true;
        }

        #endregion

        private void udcLossCode_FontChanged(object sender, EventArgs e)
        {
            spdLossList.Font = this.Font;
        }

        private void spdLossList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            //FarPoint.Win.Spread.FpSpread spdUnit;
            string s_code;
            int i_code_index;
            int i;

            //if (ListCond_LossTable == "") return;
            //spdUnit = (FarPoint.Win.Spread.FpSpread)sender;

            if (e.Column == 1)
            {
                //cdvCode.Tag = null;

                cdvCode.Init();
                MPCF.InitListView(cdvCode.GetListView);
                cdvCode.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvCode.Columns.Add("Desc", 50, HorizontalAlignment.Left);
                BASLIST.ViewGCMDataList(cdvCode.GetListView, '1', "INV_DEFECT_CODE");

                if (cdvCode.Items.Count > 0)
                {
                    for (i = 0; i < spdLossList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLossList_Sheet1.Rows[i].Locked == true) continue;

                        s_code = MPCF.Trim(spdLossList.ActiveSheet.GetValue(i, 0));
                        if (s_code != "")
                        {
                            i_code_index = MPCF.FindListItemIndex(cdvCode.GetListView, s_code, true);
                            if (i_code_index >= 0)
                            {
                                cdvCode.Items.RemoveAt(i_code_index);
                            }
                        }
                    }

                    if (cdvCode.Items.Count > 0)
                    {
                        if (cdvCode.ShowPopupList(e.Row, e.Column) == false)
                        {
                            return;
                        }

                        //cdvCode.Tag = sender;
                    }
                }
            }
            //else if (e.Column == 3)
            //{
            //    if (spdUnit.ActiveSheet.Cells[e.Row, e.Column].Value != spdUnit.ActiveSheet.Cells[e.Row, e.Column].Tag)
            //    {
            //        spdLossList_EditModeOff(sender, null);
            //        spdUnit.ActiveSheet.Cells[e.Row, e.Column].Tag = spdUnit.ActiveSheet.Cells[e.Row, e.Column].Value;
            //    }
            //}
        }

        private void spdLossList_EditModeOff(object sender, EventArgs e)
        {
            FarPoint.Win.Spread.FpSpread spdUnit;            
            int i_row;

            spdUnit = (FarPoint.Win.Spread.FpSpread)sender;

            i_row = spdUnit.ActiveSheet.ActiveRowIndex;

            if (spdUnit.ActiveSheet.ActiveColumnIndex == COL_QTY_1)
            {
                if (spdUnit.ActiveSheet.GetValue(i_row, COL_CODE) == null || MPCF.Trim(spdUnit.ActiveSheet.GetValue(i_row, COL_CODE)) == "")
                {
                    spdUnit.ActiveSheet.SetValue(i_row, COL_QTY_1, null);
                    SumLoss();
                    return;
                }

                SumLoss();

                if (m_d_out_qty < 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(198));
                    spdUnit.ActiveSheet.SetValue(i_row, COL_QTY_1, null);
                    SumLoss(); 
                    return;
                }

                if (m_b_input_loss)
                {
                    //마지막 Row이고 Loss입력컨트롤일 때 AddEmptyRow
                    if (i_row == spdUnit.ActiveSheet.RowCount - 1)
                    {
                        spdUnit.ActiveSheet.RowCount++;
                        i_row++;
                        spdUnit.ActiveSheet.Cells[i_row, COL_BTN].Locked = false;
                    }
                }
                if (LossQtyChangedEvent != null)
                    LossQtyChangedEvent(this, e);
            }
        }

        private void cdvCode_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            int i_row;

            //if (cdvCode.Tag == null) return;

            //FarPoint.Win.Spread.FpSpread spdUnit = (FarPoint.Win.Spread.FpSpread)cdvCode.Tag;

            i_row = e.Row;

            spdLossList.ActiveSheet.Cells[i_row, COL_CODE].Value = e.SelectedItem.Text;
            spdLossList.ActiveSheet.Cells[i_row, COL_DESC].Value = e.SelectedItem.SubItems[1].Text;

            if (SelectedItemChangedEvent != null)
                SelectedItemChangedEvent(this, e);
        }

    }
}
