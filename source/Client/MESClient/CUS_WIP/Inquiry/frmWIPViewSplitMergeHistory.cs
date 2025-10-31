using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;

namespace CUS_WIP
{
    public partial class frmWIPViewSplitMergeHistory : CUS_COM.frmViewForm02
    {
        public frmWIPViewSplitMergeHistory()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum SPLIT_INFO
        {
            TRAN_TIME,
            LOT_ID,
            FROM_TO_LOT_ID,
            FROM_TO_FLAG,            
            MAT_ID, 
            MAT_DESC, 
            FROM_QTY,                   //기존수량
            TO_QTY,                     //적용수량
            AREA_ID, 
            SUB_AREA_ID, 
            OPER, 
            OPER_DESC,
            TRSN_USER_ID,
            COMMENT            
        }

        private enum MERGE_INFO
        {
            TRAN_TIME,
            LOT_ID,
            FROM_TO_LOT_ID,
            FROM_TO_FLAG,
            MAT_ID,
            MAT_DESC,
            FROM_QTY,                   //기존수량
            TO_QTY,                     //적용수량
            AREA_ID,
            SUB_AREA_ID,
            OPER,
            OPER_DESC,
            TRSN_USER_ID,
            COMMENT
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewSplitList()
        {
            string sViewID = "";
            string sSql = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;

                sViewID = "CWIP3022-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text + "%";

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOperList.Text + "%";

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[5].sCondition_ID = "FROM_TIME";
                dvcArgu[5].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[6].sCondition_ID = "TO_TIME";
                dvcArgu[6].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");

                dvcArgu[7].sCondition_ID = "PACK_CHK";
                if(chkPackNotView.Checked == true)
                {
                    dvcArgu[7].sCondition_Value = "Y";
                }
                else
                {
                    dvcArgu[7].sCondition_Value = "N";
                }


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdSplitList);
                    return;
                }

                MPCF.ClearList(spdSplitList);

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    spdSplitList.ActiveSheet.RowCount++;
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.TRAN_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.FROM_TO_LOT_ID].Value = dt.Rows[i]["FROM_TO_LOT_ID"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.FROM_TO_FLAG].Value = dt.Rows[i]["FROM_TO_FLAG"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];                    
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.FROM_QTY].Value = dt.Rows[i]["FROM_QTY"];      //기존수량
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.TO_QTY].Value = dt.Rows[i]["TO_QTY"];          //적용수량
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.TRSN_USER_ID].Value = dt.Rows[i]["TRAN_USER"];
                    spdSplitList.ActiveSheet.Cells[i, (int)SPLIT_INFO.COMMENT].Value = dt.Rows[i]["TRAN_COMMENT"];                   
                }
 
                //MPCF.FitColumnHeader(spdSplitList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewMergeList()
        {
            string sViewID = "";
            string sSql = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;

                sViewID = "CWIP3022-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text + "%";

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOperList.Text + "%";

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[5].sCondition_ID = "FROM_TIME";
                dvcArgu[5].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[6].sCondition_ID = "TO_TIME";
                dvcArgu[6].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");

                dvcArgu[7].sCondition_ID = "PACK_CHK";
                if (chkPackNotView.Checked == true)
                {
                    dvcArgu[7].sCondition_Value = "Y";
                }
                else
                {
                    dvcArgu[7].sCondition_Value = "N";
                }


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMergeList);
                    return;
                }

                MPCF.ClearList(spdMergeList);

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    spdMergeList.ActiveSheet.RowCount++;
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.TRAN_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.FROM_TO_LOT_ID].Value = dt.Rows[i]["FROM_TO_LOT_ID"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.FROM_TO_FLAG].Value = dt.Rows[i]["FROM_TO_FLAG"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.FROM_QTY].Value = dt.Rows[i]["FROM_QTY"];      //기존수량
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.TO_QTY].Value = dt.Rows[i]["TO_QTY"];          //적용수량
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.TRSN_USER_ID].Value = dt.Rows[i]["TRAN_USER"];
                    spdMergeList.ActiveSheet.Cells[i, (int)MERGE_INFO.COMMENT].Value = dt.Rows[i]["TRAN_COMMENT"];
                }

                MPCF.FitColumnHeader(spdMergeList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        //if (MPCF.Trim(txtLotID.Text) == "")
                        //{
                        //    if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        //    {
                        //        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                        //        cdvWorkPlace.Focus();
                        //        return false;
                        //    }
                        //}

                        break;

                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ClearData()
        {
            try
            {
                MPCF.ClearList(spdSplitList);
                MPCF.ClearList(spdMergeList);

                cdvWorkPlace.Text = "";
                cdvOperList.Text = "";
                txtLotID.Text = "";

                tbSplitMerge.SelectedIndex = 0;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmWIPViewSplitMergeHistory_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpToDate.Value = DateTime.Now;
                this.dtpFromDate.Value = dtpToDate.Value.AddDays(-7);

                if (MPCF.Trim(cdvDept.Text) == CSGV.gs_area_hm)
                {
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.FROM_QTY].CellType).DecimalPlaces = 5;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.TO_QTY].CellType).DecimalPlaces = 5;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.FROM_QTY].CellType).DecimalPlaces = 5;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.TO_QTY].CellType).DecimalPlaces = 5;
                }
                else
                {
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.FROM_QTY].CellType).DecimalPlaces = 0;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.TO_QTY].CellType).DecimalPlaces = 0;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.FROM_QTY].CellType).DecimalPlaces = 0;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.TO_QTY].CellType).DecimalPlaces = 0;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData();

                if (MPCF.Trim(cdvDept.Text) == CSGV.gs_area_hm)
                {
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.FROM_QTY].CellType).DecimalPlaces = 5;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.TO_QTY].CellType).DecimalPlaces = 5;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.FROM_QTY].CellType).DecimalPlaces = 5;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.TO_QTY].CellType).DecimalPlaces = 5;
                }
                else
                {
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.FROM_QTY].CellType).DecimalPlaces = 0;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdSplitList.ActiveSheet.Columns[(int)SPLIT_INFO.TO_QTY].CellType).DecimalPlaces = 0;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.FROM_QTY].CellType).DecimalPlaces = 0;
                    ((FarPoint.Win.Spread.CellType.NumberCellType)spdMergeList.ActiveSheet.Columns[(int)MERGE_INFO.TO_QTY].CellType).DecimalPlaces = 0;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOperList_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }





                TRSNode in_node = new TRSNode("SQL_IN");
                TRSNode out_node = new TRSNode("SQL_OUT");

                MPCF.InitListView(cdvOperList.GetListView);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                string sOperSql = "";
                sOperSql = "   ";

                if (cdvWorkPlace.Text.Trim().Length == 0)
                {
                    sOperSql = "   ";
                }
                else  
                {
                    sOperSql = " AND SUB_AREA_ID = '" + cdvWorkPlace.Text + "' ";
                }




                in_node.AddString("SQL", "SELECT OPER AS CODE "
                                       + "      ,OPER_DESC AS VALUE FROM MWIPOPRDEF"
                                       + "  WHERE FACTORY ='" + MPGV.gsFactory + "' AND AREA_ID = '" + cdvDept.Text + "' " + sOperSql + " ORDER BY 1,2");


                do
                {
                    if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    MPCR.FillDataView(cdvOperList.GetListView, out_node);

                    in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
                } while (out_node.GetInt("NEXT_ROW") > 0);


                cdvOperList.InsertEmptyRow(0, 1);























                /*
                //20230215 공정기준 예매하게 되어있음 기준 이렇게 한 이유 모름 삭제. 전체조회되게 변경
                
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }
                

                cdvOperList.Init();
                MPCF.InitListView(cdvOperList.GetListView);
                cdvOperList.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOperList.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOperList.SelectedSubItemIndex = 0;
                cdvOperList.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOperList.GetListView, 'M', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvOperList.InsertEmptyRow(0, 1);

                */
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSplitList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            string sLot_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                if (e.Column == (int)SPLIT_INFO.LOT_ID || e.Column == (int)SPLIT_INFO.FROM_TO_LOT_ID)
                {
                    sLot_id = spdSplitList.ActiveSheet.Cells[e.Row, e.Column].Text;

                    if (sLot_id != "")
                    {
                        txtLotID.Text = sLot_id;
                        btnView.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMergeList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            string sLot_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                if (e.Column == (int)MERGE_INFO.LOT_ID || e.Column == (int)MERGE_INFO.FROM_TO_LOT_ID)
                {
                    sLot_id = spdMergeList.ActiveSheet.Cells[e.Row, e.Column].Text;

                    if (sLot_id != "")
                    {
                        txtLotID.Text = sLot_id;
                        btnView.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                if (tbSplitMerge.SelectedIndex == 0)
                {
                    ViewSplitList();
                }
                else
                {
                    ViewMergeList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";
            FarPoint.Win.Spread.FpSpread Sspead = new FpSpread();

            try
            {
                sFileName = "SplitMergeHistory";

                if (tbSplitMerge.SelectedIndex == 0)
                {
                    sFileName = sFileName + "_Split";
                    Sspead = spdSplitList;
                }
                else
                {
                    sFileName = sFileName + "_Merge";
                    Sspead = spdMergeList;
                }

                EXTFUC.SaveExcel(Sspead, sFileName);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion


    }
}
