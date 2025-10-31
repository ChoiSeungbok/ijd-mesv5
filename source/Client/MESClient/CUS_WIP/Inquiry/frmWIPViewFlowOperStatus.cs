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
using Microsoft.VisualBasic;
using FarPoint.Excel;
using FarPoint.Win;
using FarPoint.Win.Spread.CellType;
using Microsoft.Office.Interop.Excel;

namespace CUS_WIP
{
    public partial class frmWIPViewFlowOperStatus : CUS_COM.frmViewForm01
    {
        public frmWIPViewFlowOperStatus()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Constant Definition "

        private enum FLOW_LIST
        {
            CHK,                    // 1 : CHK
            FLOW,                   // 2 : 항목
            FLOW_DESC               // 3 : 항목명
        }

        private enum WO_LOT_LIST
        {
            TREE_SEQ,
            ORDER_ID,                    // 1 : ORDER_ID
            LOT_ID,                   // 2 :LOT_ID
            SUM_QTY               // 3 : 수량
        }


        private enum WIP_OPER
        {
            TREE_SEQ,
            FLOW,
            MAT_ID,
            MAT_DESC,
            OPER_01,
            OPER_02,
            OPER_03,
            OPER_04,
            OPER_05,
            OPER_06,
            OPER_07,
            OPER_08,
            OPER_09,
            OPER_10,
            OPER_11,
            OPER_12,
            OPER_13,
            OPER_14,
            OPER_15,
            OPER_16,
            OPER_17,
            OPER_18,
            OPER_19,
            OPER_20
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


                /*
                cdvDept.Text = CSGC.CP_AREA_CTM; ///CTM 전용이 아니기는 한데...거의 CTM만 쓸거라.


                if (cdvDept.Text == CSGC.CP_AREA_CTM)
                {
                    rdoFlowGen.Checked = true;
                    rdoFlowAll.Checked = false;
                }
                else
                {
                    rdoFlowGen.Checked = false;
                    rdoFlowAll.Checked = true;
                }
                */

                cdvDept.Text = "";
                cdvDept.DisplayText = "";

                ViewFlowList(cdvDept.Text);

                if (spdItemList_Sheet1.RowCount == 0)
                {
                    rdoFlowGen.Checked = false;
                    rdoFlowAll.Checked = true;
                }
                else
                {
                    rdoFlowGen.Checked = true;
                    rdoFlowAll.Checked = false;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        MPCF.ClearList(spdWipOperationList);
                        MPCF.ClearList(spdWoLotList);

                        break;
                    case "VIEW_WO_LOT":

                        MPCF.ClearList(spdWoLotList);
                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
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






        private void ViewWipOperStatusList()
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
                System.Data.DataTable dt = null;
                string sSql = "";
                string sViewID = "";
                string[] arrTag = new string[20];




                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "CREATE_CODE";
                dvcArgu[2].sCondition_Value = cdvOrderType.Text;

                dvcArgu[3].sCondition_ID = "MAT_TYPE";
                dvcArgu[3].sCondition_Value = cdvMatType.Text;

                dvcArgu[4].sCondition_ID = "MAT_ID";
                dvcArgu[4].sCondition_Value = cdvMatId.Text;

                dvcArgu[5].sCondition_ID = "MAT_DESC";
                dvcArgu[5].sCondition_Value = txtMatDesc.Text;


                dvcArgu[6].sCondition_ID = "EOH_DATE";
                dvcArgu[6].sCondition_Value = dtpWorkDate.Text.Replace("-", "");


                dvcArgu[7].sCondition_ID = "SEARCH_TYPE";

                if (rdoNow.Checked || dtpWorkDate.Text == DateTime.Now.ToString("yyyy-MM-dd"))
                {
                    dvcArgu[7].sCondition_Value = "A";
                }
                else if (rdoPrev.Checked)
                {
                    dvcArgu[7].sCondition_Value = "B";
                }
                else
                {
                    dvcArgu[7].sCondition_Value = "C";
                }


                string sGradeList_1 = "";
                string sSqlText = "";

                SheetView sv = spdItemList_Sheet1;


                for (int iRow = 0; iRow < sv.RowCount; iRow++)
                {
                    if (sv.Cells[iRow, (int)FLOW_LIST.CHK].Value.ToString().ToUpper() == "TRUE")
                    {

                        sGradeList_1 = sGradeList_1 + ",'" + sv.Cells[iRow, (int)FLOW_LIST.FLOW].Value.ToString() + "'";

                    }
                }

                if (sGradeList_1 == "")
                {
                    // sSqlText = sSqlText + " AND 1=1";
                    for (int iRow = 0; iRow < sv.RowCount; iRow++)
                    {
                        sGradeList_1 = sGradeList_1 + ",'" + sv.Cells[iRow, (int)FLOW_LIST.FLOW].Value.ToString() + "'";
                    }
                    sSqlText = sSqlText + " AND  A.FLOW IN(''" + sGradeList_1 + ")";

                }
                else
                {
                    sSqlText = sSqlText + " AND  A.FLOW IN(''" + sGradeList_1 + ")";
                }

                if (rdoFlowGen.Checked)
                {
                    sSqlText = sSqlText + " AND  A.FLOW IN( SELECT KEY_2 FROM mgcmtbldat WHERE TABLE_NAME ='C_WIP_OPER_FLOW_LIST')";
                }

                dvcArgu[8].sCondition_ID = "SQL_TEXT";
                dvcArgu[8].sCondition_Type = "TEXT";



                if (sSqlText == "")
                {
                    dvcArgu[8].sCondition_Value = "AND 1=1";
                }
                else
                {
                    dvcArgu[8].sCondition_Value = sSqlText;
                }


                sViewID = "CWIP3042-001";


                //CWIP3019-001-03
                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWipOperationList);
                    return;
                }

                MPCF.ClearList(spdWipOperationList);
                if (dt == null)
                {
                    return;
                }



                /*
                for (int iColumn = (int)WIP_OPER.OPER_01; iColumn < (int)WIP_OPER.OPER_20; iColumn++)
                {
                        spdWipOperationList_Sheet1.Columns[iColumn].Visible = false;
                }
                */



                spdWipOperationList_Sheet1.Columns.Count = (int)WIP_OPER.OPER_20 + 1;

                int iGroupStartRow = 0;
                int iColumnCount = 0;

                FarPoint.Win.Spread.CellType.NumberCellType numCellTypes = new FarPoint.Win.Spread.CellType.NumberCellType
                {
                    DecimalPlaces = 5,
                    FixedPoint = false,
                    ShowSeparator = true
                };

                for (i = 0; i < dt.Rows.Count; i++)
                {

                    spdWipOperationList_Sheet1.RowCount++;

                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.TREE_SEQ].Value = dt.Rows[i]["TREE_SEQ"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];



                    if (spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.TREE_SEQ].Text == "0")
                    {


                        //this.spdWipOperationList_Sheet1.Rows.Get(i).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(210)))), ((int)(((byte)(210)))));

                        spdWipOperationList_Sheet1.Rows[i].BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(227)))), ((int)(((byte)(254)))));
                        spdWipOperationList_Sheet1.Rows.Get(i).LockBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(227)))), ((int)(((byte)(254)))));
                        spdWipOperationList_Sheet1.Rows.Get(i).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold);
                        spdWipOperationList_Sheet1.Rows.Get(i).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;


                        if (iColumnCount < MPCF.ToInt(dt.Rows[i]["OPER_COUNT"].ToString()))
                        {
                            iColumnCount = MPCF.ToInt(dt.Rows[i]["OPER_COUNT"].ToString());
                        }



                        if (i == 0)
                        {
                            iGroupStartRow = i + 1;
                        }
                        else
                        {
                            // spdWipOperationList_Sheet1.Rows.AddRangeGroup(iGroupStartRow, i - 1);

                            spdWipOperationList_Sheet1.Rows.AddRangeGroup(iGroupStartRow, i - iGroupStartRow);


                            iGroupStartRow = i + 1;
                        }

                    }
                    else
                    {
                        if (dt.Rows.Count <= (i + 1))
                        {
                            spdWipOperationList_Sheet1.Rows.AddRangeGroup(iGroupStartRow, i - iGroupStartRow + 1);
                        }

                        this.spdWipOperationList_Sheet1.Rows.Get(i).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;


                        this.spdWipOperationList_Sheet1.Cells.Get(i, (int)WIP_OPER.OPER_01, i, (int)WIP_OPER.OPER_20).CellType = numCellTypes;

                    }
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_01].Value = dt.Rows[i]["OPER_01"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_02].Value = dt.Rows[i]["OPER_02"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_03].Value = dt.Rows[i]["OPER_03"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_04].Value = dt.Rows[i]["OPER_04"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_05].Value = dt.Rows[i]["OPER_05"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_06].Value = dt.Rows[i]["OPER_06"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_07].Value = dt.Rows[i]["OPER_07"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_08].Value = dt.Rows[i]["OPER_08"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_09].Value = dt.Rows[i]["OPER_09"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_10].Value = dt.Rows[i]["OPER_10"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_11].Value = dt.Rows[i]["OPER_11"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_12].Value = dt.Rows[i]["OPER_12"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_13].Value = dt.Rows[i]["OPER_13"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_14].Value = dt.Rows[i]["OPER_14"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_15].Value = dt.Rows[i]["OPER_15"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_16].Value = dt.Rows[i]["OPER_16"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_17].Value = dt.Rows[i]["OPER_17"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_18].Value = dt.Rows[i]["OPER_18"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_19].Value = dt.Rows[i]["OPER_19"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_20].Value = dt.Rows[i]["OPER_20"];

                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_01].Tag = dt.Rows[i]["OPER_TAG_01"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_02].Tag = dt.Rows[i]["OPER_TAG_02"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_03].Tag = dt.Rows[i]["OPER_TAG_03"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_04].Tag = dt.Rows[i]["OPER_TAG_04"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_05].Tag = dt.Rows[i]["OPER_TAG_05"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_06].Tag = dt.Rows[i]["OPER_TAG_06"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_07].Tag = dt.Rows[i]["OPER_TAG_07"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_08].Tag = dt.Rows[i]["OPER_TAG_08"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_09].Tag = dt.Rows[i]["OPER_TAG_09"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_10].Tag = dt.Rows[i]["OPER_TAG_10"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_11].Tag = dt.Rows[i]["OPER_TAG_11"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_12].Tag = dt.Rows[i]["OPER_TAG_12"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_13].Tag = dt.Rows[i]["OPER_TAG_13"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_14].Tag = dt.Rows[i]["OPER_TAG_14"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_15].Tag = dt.Rows[i]["OPER_TAG_15"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_16].Tag = dt.Rows[i]["OPER_TAG_16"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_17].Tag = dt.Rows[i]["OPER_TAG_17"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_18].Tag = dt.Rows[i]["OPER_TAG_18"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_19].Tag = dt.Rows[i]["OPER_TAG_19"];
                    spdWipOperationList_Sheet1.Cells[i, (int)WIP_OPER.OPER_20].Tag = dt.Rows[i]["OPER_TAG_20"];

                    this.spdWipOperationList_Sheet1.RangeGroupSummaryColumnRight = false;
                    this.spdWipOperationList_Sheet1.RangeGroupSummaryRowBelow = false;


                }

                spdWipOperationList_Sheet1.Columns.Count = 4 + iColumnCount;

                for (int j = 4; j < spdWipOperationList_Sheet1.Columns.Count; j++)
                {

                    spdWipOperationList_Sheet1.ColumnHeader.Cells.Get(0, j).Value = (j - 3).ToString();
                }

                // FarPoint.Win.BevelBorder bevelBorder1 = new FarPoint.Win.BevelBorder(FarPoint.Win.BevelBorderType.Lowered);


                MPCF.FitColumnHeader(spdWipOperationList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void ViewWoLotList(int iRow, int iCol)
        {
            try
            {

                MPCF.ClearList(spdWoLotList);

                if (spdWipOperationList_Sheet1.Rows.Count <= 0)
                {
                    return;
                }

                if (spdWipOperationList_Sheet1.Cells[iRow, (int)WIP_OPER.TREE_SEQ].Text == "0")
                {
                    return;
                }
                if (spdWipOperationList_Sheet1.Cells[iRow, iCol].Text.Trim() == "")
                {
                    return;
                }


                if ((int)WIP_OPER.OPER_01 > iCol)
                {
                    return;
                }



                //SheetView sv = spdWipOperationList_Sheet1;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                System.Data.DataTable dt = null;
                string sSql = "";
                int i = 0;
                //string sViewId = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text.Trim();

                dvcArgu[2].sCondition_ID = "CREATE_CODE";
                dvcArgu[2].sCondition_Value = cdvOrderType.Text.Trim();


                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = spdWipOperationList.ActiveSheet.Cells[iRow, (int)WIP_OPER.MAT_ID].Text;


                dvcArgu[4].sCondition_ID = "EOH_DATE";
                dvcArgu[4].sCondition_Value = dtpWorkDate.Text.Replace("-", "");

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = spdWipOperationList.ActiveSheet.Cells[iRow, iCol].Tag;


                dvcArgu[6].sCondition_ID = "SEARCH_TYPE";

                if (rdoNow.Checked || dtpWorkDate.Text == DateTime.Now.ToString("yyyy-MM-dd"))
                {
                    dvcArgu[6].sCondition_Value = "A";
                }
                else if (rdoPrev.Checked)
                {
                    dvcArgu[6].sCondition_Value = "B";
                }
                else
                {
                    dvcArgu[6].sCondition_Value = "C";
                }


                dvcArgu[7].sCondition_ID = "TREE_SEQ";

                if (rdoWo.Checked)
                {
                    dvcArgu[7].sCondition_Value = 0;
                }
                else if (rdoLot.Checked)
                {
                    dvcArgu[7].sCondition_Value = 1;
                }
                else
                {
                    dvcArgu[7].sCondition_Value = 2;  //2는전체
                }



                if (TPDR.GetDataOne("", ref dt, "CWIP3042-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWoLotList);
                    return;
                }

                MPCF.ClearList(spdWoLotList);
                this.spdWoLotList.ActiveSheet.ClearRangeGroup(true);

                int iGroupStartRow = 0;


                FarPoint.Win.Spread.CellType.NumberCellType numberCellType1 = new FarPoint.Win.Spread.CellType.NumberCellType();
                numberCellType1.DecimalPlaces = 5;
                numberCellType1.FixedPoint = false;
                numberCellType1.ShowSeparator = true;

                for (i = 0; i < dt.Rows.Count; i++)
                {


                    if (rdoAll.Checked)
                    {

                        spdWoLotList_Sheet1.RowCount++;

                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.TREE_SEQ].Value = dt.Rows[i]["TREE_SEQ"];
                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.SUM_QTY].Value = dt.Rows[i]["SUM_QTY"];


                        if (spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.TREE_SEQ].Text == "0")
                        {


                            this.spdWoLotList_Sheet1.Rows[i].BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(227)))), ((int)(((byte)(254)))));
                            this.spdWoLotList_Sheet1.Rows.Get(i).LockBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(210)))), ((int)(((byte)(227)))), ((int)(((byte)(254)))));
                            this.spdWoLotList_Sheet1.Rows.Get(i).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold);
                            this.spdWoLotList_Sheet1.Rows.Get(i).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;




                            if (i == 0)
                            {
                                iGroupStartRow = i + 1;
                            }
                            else
                            {
                                // spdWipOperationList_Sheet1.Rows.AddRangeGroup(iGroupStartRow, i - 1);

                                spdWoLotList_Sheet1.Rows.AddRangeGroup(iGroupStartRow, i - iGroupStartRow);


                                iGroupStartRow = i + 1;
                            }

                        }
                        else
                        {

                            if (i == 110)
                            {
                                spdItemList_Sheet1.RowCount++;
                            }


                            if (dt.Rows.Count <= (i + 1))
                            {
                                spdWoLotList_Sheet1.Rows.AddRangeGroup(iGroupStartRow, i - iGroupStartRow + 1);
                            }

                            this.spdWoLotList_Sheet1.Rows.Get(i).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;


                            this.spdWoLotList_Sheet1.Cells.Get(i, (int)WO_LOT_LIST.SUM_QTY).CellType = numberCellType1;

                        }


                    }
                    else
                    {

                        spdWoLotList_Sheet1.RowCount++;
                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.TREE_SEQ].Value = dt.Rows[i]["TREE_SEQ"];
                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                        spdWoLotList_Sheet1.Cells[i, (int)WO_LOT_LIST.SUM_QTY].Value = dt.Rows[i]["SUM_QTY"];
                    }

                }



                this.spdWoLotList.ActiveSheet.RangeGroupSummaryColumnRight = false;
                this.spdWoLotList.ActiveSheet.RangeGroupSummaryRowBelow = false;

                MPCF.FitColumnHeader(spdItemList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void ViewFlowList(string sDept)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                System.Data.DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewId = "";

                if (sDept != "")
                {



                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "AREA_ID";
                    dvcArgu[1].sCondition_Value = sDept;


                    if (rdoFlowGen.Checked)
                    {
                        sViewId = "CWIP3042-004";

                    }
                    else
                    {
                        sViewId = "CWIP3042-002";
                    }


                    if (TPDR.GetDataOne("", ref dt, sViewId, dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdItemList);
                        return;
                    }

                    MPCF.ClearList(spdItemList);

                    for (i = 0; i < dt.Rows.Count; i++)
                    {
                        spdItemList_Sheet1.RowCount++;

                        spdItemList_Sheet1.SetValue(i, (int)FLOW_LIST.CHK, false);
                        spdItemList_Sheet1.Cells[i, (int)FLOW_LIST.FLOW].Value = dt.Rows[i]["FLOW"];
                        spdItemList_Sheet1.Cells[i, (int)FLOW_LIST.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                    }
                    MPCF.FitColumnHeader(spdItemList);

                }
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


        #region " Event Definition "
        private void frmWIPViewFlowOperStatus_Load(object sender, EventArgs e)
        {
            try
            {
                //조회 조건 최조 세팅
                //Create Code
                cdvOrderType.Text = "PROD";
                cdvOrderType.DisplayText = "Product Lot";
                cdvDept.Text = "";


                //일자
                dtpWorkDate.Text = DateTime.Now.AddDays(-1).ToShortDateString();

                //라디오버튼 (현재 혹은 과거)
                rdoNow.Checked = true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
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

                ViewFlowList(cdvDept.Text);
                MPCF.ClearList(spdWipOperationList);


                if (cdvDept.Text == CSGC.CP_AREA_CTM)
                {
                    rdoFlowGen.Checked = true;
                }
                else
                {
                    rdoFlowAll.Checked = true;
                }

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

                ClearData("VIEW");

                ViewWipOperStatusList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {

                ClearData("VIEW_WO_LOT");


                if (e.ColumnHeader || e.Row < 0)
                {
                    return;
                }


                if (e.Column >= (int)WIP_OPER.OPER_01)
                {

                    ViewWoLotList(e.Row, e.Column);

                }



                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    //   EXTFUC.SetSelectRowColor(spdWipOperationList, e.Row);

                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                FpSpread excelSp = new FpSpread();
                spdWipOperationList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdWipOperationList_Sheet1);


                EXTFUC.SaveExcel(excelSp, "ViewStock");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoNow_CheckedChanged(object sender, EventArgs e)
        {

            MPCF.ClearList(spdWipOperationList);
        }

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoPrev_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoPrev.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else if (rdoPrev2.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else
            {
                dtpWorkDate.Enabled = false;
            }
        }

        private void rdoPrev2_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoPrev.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else if (rdoPrev2.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else
            {
                dtpWorkDate.Enabled = false;
            }
        }

        private void spdItemList_CellClick(object sender, CellClickEventArgs e)
        {
            SheetView sv = spdItemList.ActiveSheet;

            try
            {
                if (e.ColumnHeader == true)
                {
                    if (sv.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdItemList, e.Row, e.Column, true, true, false);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoAll_CheckedChanged(object sender, EventArgs e)
        {

            SheetView sv = spdWipOperationList_Sheet1;

            ViewWoLotList(sv.ActiveRowIndex, sv.ActiveColumnIndex);
        }

        private void rdoWo_CheckedChanged(object sender, EventArgs e)
        {
            SheetView sv = spdWipOperationList_Sheet1;

            ViewWoLotList(sv.ActiveRowIndex, sv.ActiveColumnIndex);
        }

        private void rdoLot_CheckedChanged(object sender, EventArgs e)
        {
            SheetView sv = spdWipOperationList_Sheet1;

            ViewWoLotList(sv.ActiveRowIndex, sv.ActiveColumnIndex);
        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {
                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_WIP_OPER_FLOW_LIST";

                popup.sTable_name_desc = "조회 플로우List";
                popup.sComment = "해당화면에 등록된 플로우만 현황에 해당 조회됩니다.";




                if (popup.ShowDialog() == DialogResult.OK)
                {

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

        private void rdoFlowGen_CheckedChanged(object sender, EventArgs e)
        {

            if (rdoFlowGen.Checked == true)
            {
                rdoFlowGen.Checked = true;
                rdoFlowAll.Checked = false;
            }
            else
            {
                rdoFlowGen.Checked = false;
                rdoFlowAll.Checked = true;
            }


            ViewFlowList(cdvDept.Text);

        }

        private void rdoFlowAll_CheckedChanged(object sender, EventArgs e)
        {

            if (rdoFlowAll.Checked == true)
            {
                rdoFlowGen.Checked = false;
                rdoFlowAll.Checked = true;
            }
            else
            {

                rdoFlowGen.Checked = true;
                rdoFlowAll.Checked = false;
            }


            ViewFlowList(cdvDept.Text);
        }

        private void frmWIPViewFlowOperStatus_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!SaveRegistry.ContainsKey(cdvDept.Name))
                this.SaveRegistry.Add(cdvDept.Name, cdvDept.Text + ';' + cdvDept.DisplayText);
            this.SaveRegistry.Add(cdvOrderType.Name, cdvOrderType.Text + ';' + cdvOrderType.DisplayText);

        }

        #endregion
    }
}
