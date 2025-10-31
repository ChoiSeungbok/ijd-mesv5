using CUS_COM;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_QCM
{
    public partial class frmViewInspectionList : CUS_COM.frmViewForm02
    {
        public frmViewInspectionList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum INSPECTION_LIST
        {
            INSP_ID,
            INSP_TYPE,
            LOT_ID,
            MAT_GRADE,
            MAT_SIZE,
            REQUEST_TIME,
            JUDGE_TIME,
            INSP_STATUS,
            INSP_JUDGE,
            MAT_ID,
            MAT_DESC,
            UNIT,
            QTY,
            VENDOR_LOT_ID
        }

        private enum COLLECTION_DATA
        {
            CHAR_COL,
            CHAR_DESC_COL,
            CHAR_SEQ,
            LOWER_SPEC_LIMIT,
            TARGET_VALUE,
            UPPER_SPEC_LIMIT,
            SPEC_COL,
            OPT_INPUT_COL,
            VALUE_TYPE_COL,
            VALUE_COUNT_COL,
            DEF_UNIT_FLAG_COL,
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL
        }

        #endregion

        #region " Variable Definition"

        private const int DEFAULT_COL_COUNT = 17;
        private clsDerivedCharList cls_derived_char_list;

        private const int MAX_DATA_COUNT = 5000;

        #endregion

        #region " Function Definition"

        private bool ViewInspectionList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "FROM_DATE";
                dvcArgu[2].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "TO_DATE";
                dvcArgu[3].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[4].sCondition_ID = "INSP_STATUS";
                dvcArgu[4].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[5].sCondition_ID = "INSP_OPER";
                dvcArgu[5].sCondition_Value = cdvInspOper.Text + "%";

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = "%" + cdvMat.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CQCM3001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionList);
                    lblTotalCount.Text = "0";
                    return true;
                }

                MPCF.ClearList(spdInspectionList);

                lblTotalCount.Text = string.Format("{0:#,###}", dt.Rows.Count);

                foreach (DataRow xRow in dt.Rows)
                {
                    i = spdInspectionList_Sheet1.RowCount++;

                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_ID].Value = xRow["INSP_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_TYPE].Value = xRow["INSP_TYPE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOT_ID].Value = xRow["LOT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_GRADE].Value = xRow["MAT_GRADE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_SIZE].Value = xRow["MAT_SIZE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.REQUEST_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_REQ_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.JUDGE_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_JUDGE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_STATUS].Value = xRow["INSP_STATUS"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_JUDGE].Value = xRow["INSP_JUDGE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_ID].Value = xRow["MAT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_DESC].Value = xRow["MAT_DESC"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.UNIT].Value = xRow["UNIT"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.QTY].Value = xRow["QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.VENDOR_LOT_ID].Value = xRow["VENDOR_LOT_ID"];
                }

                MPCF.FitColumnHeader(spdInspectionList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        /// <summary>
        /// 검사 데이터 조회
        /// </summary>
        /// <param name="inspId">검사ID</param>
        /// <returns></returns>
        private bool ViewInspectionData(string inspId)
        {
            try
            {
                int iValueCnt = 0;
                int iRow = 0;
                string s_value_name;

                TRSNode in_node = new TRSNode("view_lot_data_In");
                TRSNode out_node = new TRSNode("view_lot_data_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("INSP_ID", inspId);

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Inspection_Data", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.CHAR_COL].Text == out_node.GetList(0)[i].GetString("CHAR_ID")   //dt.Rows[i]["CHAR_ID"].ToString()
                            && spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.UNIT_SEQ_COL].Text == out_node.GetList(0)[i].GetInt("UNIT_SEQ").ToString())
                        {
                            iRow = j;
                            break;
                        }

                    }

                    spdDataCollection.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA.UNIT_COL, out_node.GetList(0)[i].GetString("UNIT_ID"));

                    // iUnitCnt = MPCF.ToInt(dt.Rows[0]["UNIT_COUNT"].ToString());
                    iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");

                    if (iValueCnt > 25)
                    {
                        iValueCnt = 25;
                    }

                    for (int k = 1; k <= iValueCnt; k++)
                    {
                        s_value_name = "VALUE_" + k.ToString();
                        if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                        {
                            if (out_node.GetList(0)[i].GetString(s_value_name) != "")
                            {
                                spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = MPCF.ToDbl(out_node.GetList(0)[i].GetString(s_value_name));
                            }
                        }
                        else
                        {                            
                            spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = out_node.GetList(0)[i].GetString(s_value_name);
                        }

                    }
                }

                //Spec Out 확인
                ApplyColorBySpecOut();

                return true;
                //return bResult;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool viewInspStatusList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                + "   DATA_1 AS VALUE "
                                              + " FROM MGCMTBLDAT "
                                            + " WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                            + "  AND TABLE_NAME = '" + CSGC.CP_GCM_INSP_STATUS + "' "
                                            + "  AND KEY_1 != 'C' "
                                            + " ORDER BY DATA_3");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);



            return true;
        }

        private void ClearList(string sType)
        {
            switch (sType)
            {
                case "COL_SET_CHANGED":

                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
            }

        }

        private void ApplyColorBySpecOut()
        {
            if (spdDataCollection.ActiveSheet.RowCount < 1)
            {
                return;
            }

            try
            {
                for (int iRow = 0; iRow < spdDataCollection.ActiveSheet.RowCount; iRow++)
                {
                    for (int iCol = (int)COLLECTION_DATA.VALUE_START_COL; iCol < spdDataCollection.ActiveSheet.ColumnCount; iCol++)
                    {
                        bool bSpecOut = false;

                        //검사항목이 숫자타입 일 때만
                        if (spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_TYPE_COL].Value.ToString() == "N")
                        {
                            //입력값(검사 결과값)이 숫자일 때
                            if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) == true)
                            {
                                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value) == true)
                                {
                                    if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value))
                                    {
                                        bSpecOut = true;
                                    }
                                }

                                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value) == true)
                                {
                                    if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value))
                                    {
                                        bSpecOut = true;
                                    }
                                }

                                if (bSpecOut)
                                {
                                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Red;
                                }
                                else
                                {
                                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                                }
                            }
                            else
                            {
                                spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                            }

                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void SelectedItemChangedByColSet(string inspId)
        {
            string colSetId = string.Empty;
            int colSetVersion = 1;
            string lotId = string.Empty;
            string matId = string.Empty;
            int matVer = 1;
            string oper = string.Empty;

            try
            {
                //Clear
                MPCF.ClearList(spdDataCollection, true);

                if (MPCF.Trim(inspId) != "")
                {
                    TRSNode in_node = new TRSNode("view_lot_data_In");
                    TRSNode out_node = new TRSNode("view_lot_data_Out");

                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '3';
                    in_node.AddString("INSP_ID", inspId);

                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Inspection_Data", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    colSetId = out_node.GetString("COL_SET_ID");

                    if (!String.IsNullOrEmpty(colSetId))
                    {
                        lotId = out_node.GetString("LOT_ID");
                        matId = out_node.GetString("MAT_ID");
                        matVer = out_node.GetInt("MAT_VER");
                        oper = out_node.GetString("INSP_OPER");

                        cdvColSetID.Text = colSetId;
                        colSetVersion = out_node.GetInt("COL_SET_VERSION");
                        txtColSetVer.Text = colSetVersion.ToString();


                        cls_derived_char_list = new clsDerivedCharList();
                        cls_derived_char_list.GetDerivedInfo(colSetId, colSetVersion, lotId, "", "", "");

                        if (ViewCharacterList(spdDataCollection, '5', colSetId, colSetVersion, 'Y', cls_derived_char_list, lotId, matId, matVer, oper) == false)
                        {
                            return;
                        }
                    }
                    else
                    {
                        ClearList("COL_SET_CHANGED");
                    }
                }
                else
                {
                    ClearList("COL_SET_CHANGED");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        public bool ViewCharacterList(Control control, char ProcStep, string ColSetID, int ColSetVersion, char cIncludeUnitID, clsDerivedCharList cls_derived_char_list, string LotID, string sMatID, int iMatVer, string sOper)
        {

            int i;
            int j;
            int k;
            //int m;
            int i_index;
            int iLastRow = 0;
            int iUnitCnt = 0;
            int iValueCnt = 0;
            int iUnitSeq = 0;
            int iMaxColumnCnt = 0;
            int iColCnt = 0;
            string sDefaultValue;
            string sUnitTbl;
            string sValueTbl;
            char cDefUnitFlag;
            char cDefUnitOvrFlag;
            //FarPoint.Win.Spread.CellType.ComboBoxCellType UnitCellType = null;
            FarPoint.Win.Spread.CellType.ComboBoxCellType ValueCellType = null;


            TRSNode in_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_OUT");
            List<TRSNode> unit_list;

            try
            {
                spdDataCollection.SuspendLayout();
                spdDataCollection.ActiveSheet.RowCount = 0;
                spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;
                spdDataCollection.ResumeLayout();

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;
                in_node.AddChar("INCLUDE_UNIT_ID", cIncludeUnitID);
                in_node.AddString("COL_SET_ID", ColSetID);
                in_node.AddInt("COL_SET_VERSION", ColSetVersion);

                in_node.AddString("MAT_ID", sMatID);
                in_node.AddInt("MAT_VER", iMatVer);
                in_node.AddString("OPER", sOper);
                // in_node.AddString("LOT_ID", LotID);

                do
                {
                    if (MPCR.CallService("EDC", "EDC_View_Attach_Character_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    //컬럼의 max count 를 구해온다.
                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        iColCnt = 0;
                        iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        if (iValueCnt > 0)
                        {
                            iColCnt = DEFAULT_COL_COUNT + iValueCnt;
                        }
                        else
                        {
                            iColCnt = DEFAULT_COL_COUNT;
                        }

                        if (iColCnt > iMaxColumnCnt)
                        {
                            iMaxColumnCnt = iColCnt;
                        }

                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        // Initialize
                        FarPoint.Win.Spread.SheetView with_1 = spdDataCollection.ActiveSheet;

                        iLastRow = with_1.RowCount - 1;
                        iUnitCnt = out_node.GetList(0)[i].GetInt("UNIT_COUNT");
                        iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        //UnitCellType = null;
                        ValueCellType = null;
                        with_1.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50;

                        with_1.RowCount += iUnitCnt;
                        if (with_1.ColumnCount < DEFAULT_COL_COUNT + iValueCnt)
                        {
                            with_1.ColumnCount = DEFAULT_COL_COUNT + iValueCnt;
                        }

                        sDefaultValue = out_node.GetList(0)[i].GetString("DEF_VALUE");
                        sUnitTbl = out_node.GetList(0)[i].GetString("UNIT_TBL");
                        sValueTbl = out_node.GetList(0)[i].GetString("VALUE_TBL");
                        cDefUnitFlag = out_node.GetList(0)[i].GetChar("DEF_UNIT_FLAG");
                        cDefUnitOvrFlag = out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG");

                        iUnitSeq = 0;
                        for (j = iLastRow + 1; j < with_1.RowCount; j++)
                        {
                            iUnitSeq++;
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_COL, out_node.GetList(0)[i].GetString("CHAR_ID"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_DESC_COL, out_node.GetList(0)[i].GetString("CHAR_DESC"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_SEQ, out_node.GetList(0)[i].GetInt("SEQ_NUM"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT, out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.TARGET_VALUE, out_node.GetList(0)[i].GetString("TARGET_VALUE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT, out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"));


                            with_1.SetValue(j, (int)COLLECTION_DATA.SPEC_COL, MPCF.GetSpecInfo(out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("TARGET_VALUE")));
                            with_1.SetValue(j, (int)COLLECTION_DATA.OPT_INPUT_COL, out_node.GetList(0)[i].GetChar("OPT_INPUT_FLAG"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_TYPE_COL, out_node.GetList(0)[i].GetChar("VALUE_TYPE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_COUNT_COL, out_node.GetList(0)[i].GetInt("VALUE_COUNT"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.DEF_UNIT_OVR_FLAG_COL, out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.DEF_VALUE_COL, out_node.GetList(0)[i].GetString("DEF_VALUE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UNIT_TBL_COL, out_node.GetList(0)[i].GetString("UNIT_TBL"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_TBL_COL, out_node.GetList(0)[i].GetString("VALUE_TBL"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UNIT_SEQ_COL, iUnitSeq);
                        }

                        i_index = 0;

                        //VALUE_TYPE에 따라 컬럼의 셀 타입을 지정해준다.
                        for (j = (int)COLLECTION_DATA.VALUE_START_COL; j < (int)COLLECTION_DATA.VALUE_START_COL + iValueCnt; j++)
                        {
                            for (k = iLastRow + 1; k < with_1.RowCount; k++)
                            {
                                if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                                {
                                    MPCR.SetNumberCell(with_1.Cells[k, j]);
                                }
                                else
                                {
                                    MPCR.SetAsciiCell(with_1.Cells[k, j]);
                                }

                                if (cls_derived_char_list != null)
                                {
                                    if (out_node.GetList(0)[i].GetChar("DERIVED_PARAM_FLAG") == 'Y')
                                    {
                                        with_1.Cells[k, j].Locked = true;
                                        with_1.Cells[k, j].BackColor = System.Drawing.Color.Cyan;
                                        with_1.Rows[k].Tag = "AUTO";

                                        cls_derived_char_list.SetCharLocation(out_node.GetList(0)[i].GetString("CHAR_ID"), with_1, i_index, k, j);
                                    }
                                }
                            }

                            i_index += 1;
                        }

                        // ColSet의 케릭터에 셋팅한 유닛ID 정보에 맞게 셀의 상태를 바꿔준다.
                        unit_list = out_node.GetList(0)[i].GetList("UNIT_LIST");
                        //Unit ID Cell Lock

                        /*
                        if (unit_list.Count < 1)
                        {
                            if (cDefUnitFlag == 'C')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = true;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.WhiteSmoke;
                                    with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), out_node.GetList(0)[i].GetString("UNIT"));
                                    if (out_node.GetList(0)[i].GetString("UNIT") == "")
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "*");
                                    }
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "CHARACTER");
                                }

                            }
                            else if (cDefUnitFlag == 'E')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.White;
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                }
                            }
                            else
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.White;
                                }
                            }
                        }
                        else
                        {
                            if (cDefUnitFlag == 'Y')
                            {
                                for (m = 0; m < unit_list.Count; m++)
                                {
                                    if (m > iUnitCnt - 1)
                                    {
                                        break;
                                    }

                                    // null_flag check
                                    if (unit_list[m].GetChar("NULL_FLAG") == 'Y')
                                    {
                                        with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                    }
                                    else
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), unit_list[m].GetString("DEF_UNIT_ID"));
                                    }

                                    if (out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG") == 'Y')
                                    {
                                    }
                                    else
                                    {
                                        with_1.Cells[iLastRow + 1 + m, (int)COLLECTION_DATA.UNIT_COL].Locked = true;
                                        with_1.Cells[iLastRow + 1 + m, (int)COLLECTION_DATA.UNIT_COL].BackColor = System.Drawing.Color.WhiteSmoke;
                                    }
                                }
                            }

                            if ((cDefUnitFlag == 'Y' && cDefUnitOvrFlag == 'Y' && sUnitTbl != "") ||
                                (cDefUnitFlag == ' ' && sUnitTbl != ""))
                            {
                                for (j = iLastRow + 1; j <= with_1.RowCount - 1; j++)
                                {
                                    if (UnitCellType == null)
                                    {
                                        if (BASLIST.ViewGCMDataList(control, '1', sUnitTbl, -1, null, "", false, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), j, null) == false)
                                        {
                                            return false;
                                        }
                                        else
                                        {
                                            UnitCellType = (FarPoint.Win.Spread.CellType.ComboBoxCellType)(with_1.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType);
                                            with_1.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50;
                                        }
                                    }
                                    else
                                    {
                                        with_1.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType = UnitCellType;
                                    }
                                }
                            }

                        }*/

                        //기본값 세팅 - > ColSet의 케릭터에 셋팅한 기본값을 넣어준다.                        
                        for (j = (int)COLLECTION_DATA.VALUE_START_COL; j <= iValueCnt + (int)COLLECTION_DATA.VALUE_START_COL - 1; j++)
                        {
                            for (k = iLastRow + 1; k <= with_1.RowCount - 1; k++)
                            {
                                if (sDefaultValue != "")
                                {
                                    with_1.SetValue(k, j, sDefaultValue);
                                }
                                if (sValueTbl != "")
                                {
                                    if (ValueCellType == null)
                                    {
                                        if (BASLIST.ViewGCMDataList(control, '1', sValueTbl, -1, null, "", false, j, k, null) == false)
                                        {
                                            return false;
                                        }
                                        else
                                        {
                                            ValueCellType = (FarPoint.Win.Spread.CellType.ComboBoxCellType)(with_1.Cells[k, j].CellType);
                                        }
                                    }
                                    else
                                    {
                                        with_1.Cells[k, j].CellType = ValueCellType;
                                    }
                                }
                            }
                        }

                        //value count 가 다른 char id의 max value count 보다 작을경우 해당 컬럼은 lock을 하고, 색을 바꿔준다.
                        with_1.ColumnCount = iMaxColumnCnt;
                        for (j = iValueCnt + (int)COLLECTION_DATA.VALUE_START_COL; j < with_1.ColumnCount; j++)
                        {
                            for (k = iLastRow + 1; k < with_1.RowCount; k++)
                            {
                                with_1.Cells[k, j].Locked = true;
                                //with_1.Cells[k, j].BackColor = System.Drawing.Color.WhiteSmoke;
                                with_1.Cells[k, j].LockBackColor = System.Drawing.Color.WhiteSmoke;
                            }
                        }
                    }

                    in_node.SetString("NEXT_CHAR_ID", out_node.GetString("NEXT_CHAR_ID"));
                } while (in_node.GetString("NEXT_CHAR_ID") != "");

                // 추가 컬럼헤더 span 및 seq 나타내기    
                FarPoint.Win.Spread.SheetView with_2 = spdDataCollection.ActiveSheet;
                int iColumnSeq = 0;

                if (with_2.ColumnCount > DEFAULT_COL_COUNT)
                {
                    with_2.ColumnHeader.Cells.Get(0, (int)COLLECTION_DATA.VALUE_START_COL).ColumnSpan = with_2.ColumnCount - DEFAULT_COL_COUNT;
                    for (i = (int)COLLECTION_DATA.VALUE_START_COL; i < with_2.ColumnCount; i++)
                    {
                        iColumnSeq++;
                        with_2.ColumnHeader.Cells.Get(1, i).Value = iColumnSeq;
                    }
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

        #region " Event Definition"
        private void spdInspectionList_SelectionChanged(object sender, FarPoint.Win.Spread.SelectionChangedEventArgs e)
        {
            string inspId = string.Empty;



            if (spdInspectionList_Sheet1.RowCount == 0)
            {
                return;
            }

            inspId = spdInspectionList_Sheet1.Cells[spdInspectionList_Sheet1.ActiveRowIndex, (int)INSPECTION_LIST.INSP_ID].Text;

            if (!String.IsNullOrEmpty(inspId))
            {
                spdDataCollection_Sheet1.RowCount = 0;
                SelectedItemChangedByColSet(inspId);

                if (ViewInspectionData(inspId) == false)
                {
                    CSCF.ClearSpread(spdDataCollection, 0, (int)COLLECTION_DATA.VALUE_START_COL, "");
                }
            }
        }

        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvInspectionType.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                  + "         DATA_1 AS VALUE "
                                                  + "   FROM MGCMTBLDAT   "
                                                  + "  WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                  + "  AND TABLE_NAME = 'C_INSP_TYPE' "
                                                  + "  AND KEY_1 != 'IQC' "
                                                  + "  ORDER BY DATA_2 ");

            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvInspectionType.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

        }
        private void btnView_Click(object sender, EventArgs e)
        {
            ViewInspectionList();
        }

        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            viewInspStatusList(cdvStatus.GetListView);
            cdvStatus.InsertEmptyRow(0, 1);
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
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
                /*
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }*/

                viewOperList(cdvOper.GetListView);

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            /*
            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                                + "               OPER_DESC AS NAME "
                                                + "         FROM MWIPOPRDEF "
                                                + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                                + "          AND SUB_AREA_ID = '" + cdvWorkPlace.Text + "' "
                                                + "          AND OPER_GRP_2 <> 'NONE' "
                                                + "         AND OPER_GRP_2 > ' ' "
                                                + "        ORDER BY OPER"); */


            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_2 <> 'NONE' "
                                               + "         AND OPER_GRP_2 > ' ' "
                                               + "        ORDER BY OPER");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

            return true;
        }

        private void cdpInspOper_ButtonPress(object sender, EventArgs e)
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
                /*
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }*/

                viewOperList(cdvInspOper.GetListView);

                cdvInspOper.InsertEmptyRow(0, 1);
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
                spdInspectionList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdInspectionList_Sheet1);
                spdDataCollection_Sheet1.SheetName = "Sheet2";
                excelSp.Sheets.Add(spdDataCollection_Sheet1);

                //병합된 칼럼 색깔이 안나와서
                for (int i = 0; i < excelSp.Sheets[1].ColumnCount; i++)
                {
                    excelSp.Sheets[1].ColumnHeader.Columns[i].BackColor = Color.FromArgb(14, 86, 155);
                }

                EXTFUC.SaveExcel(excelSp, "InspectionList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMat.Text = popup.sMat_id;
                    cdvMat.DisplayText = popup.sMat_Desc;
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

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
                cdvMat.Text = "";
        }

        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (spdInspectionList.ActiveSheet.RowCount != 0)
            {



                frmPopFtpUpDown popup = new frmPopFtpUpDown();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.g_PopYn = "Y";
                popup.g_LotId = spdInspectionList.ActiveSheet.Cells[spdInspectionList.ActiveSheet.ActiveRowIndex, (int)INSPECTION_LIST.LOT_ID].Text;
                popup.g_Mat_id = spdInspectionList.ActiveSheet.Cells[spdInspectionList.ActiveSheet.ActiveRowIndex, (int)INSPECTION_LIST.MAT_ID].Text;
                popup.g_Mat_Desc = spdInspectionList.ActiveSheet.Cells[spdInspectionList.ActiveSheet.ActiveRowIndex, (int)INSPECTION_LIST.MAT_DESC].Text;
                popup.g_Area_Id = cdvDept.Text;
                popup.g_SearchType = "B";




                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                {
                    return;
                }


            }
        }
        #endregion

    }
}
