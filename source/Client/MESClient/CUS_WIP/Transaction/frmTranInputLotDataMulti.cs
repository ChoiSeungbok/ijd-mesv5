using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Windows.Forms;
using System.Globalization;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;


namespace CUS_WIP
{
    public partial class frmTranInputLotDataMulti : CUS_COM.frmTranForm03
    {
        public frmTranInputLotDataMulti()
        {
            InitializeComponent();

            InitControl();

            cls_derived_char_list = new clsDerivedCharList();
        }

        #region " Constant Definition "

        private const int VALUE_START_COL = 13;
        private const int DEFAULT_COL_COUNT = 13;

        private enum LOT_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 제품코드
            MAT_DESC,               // 3 : 제품명            
            PROD_QTY,               // 4 : 생산수량
            CREATE_DATE,            // 5 : 생성일자
            RES_ID,                 // 6 : 설비
            RES_DESC,               // 7 : 설비명
            COMMENT,                // 8 : 비고
            MAT_VER,                // 9 : 제품 버전
            FLOW,                   //10 : 플로우
            FLOW_SEQ_NUM,                   //11 : 플로우
            OPER                    //12 : 공정
        }

        private enum CHAR_COLUMN
        {
            CHAR_COL,
            CHAR_SEQ,
            CHAR_DESC_COL,
            SPEC_COL,
            OPT_INPUT_COL,
            VALUE_TYPE_COL,
            VALUE_COUNT_COL,
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL
        }

        #endregion

        #region " Variable Definition "

        private clsDerivedCharList cls_derived_char_list;
        int iColSetVer = 0;
        bool bCheckData = false;
        int iLotHistSeq = 0;
        int iColSeq = 0;

        FarPoint.Win.Spread.CellType.NumberCellType typeNumber = new FarPoint.Win.Spread.CellType.NumberCellType();
        FarPoint.Win.Spread.CellType.TextCellType typeAscii = new FarPoint.Win.Spread.CellType.TextCellType();

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LOT ID, 묶음번호, cell ID 인지 판단하여 해당 리스트를 리턴한다.
        private void ViewLotInfo(string sLot_ID)
        {
            int iRow = 0;

            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = "";


                dvcArgu[3].sCondition_ID = "RES_ID";
                dvcArgu[3].sCondition_Value ="";


                dvcArgu[4].sCondition_ID = "ORDER_ID";
                dvcArgu[4].sCondition_Value = "";


                dvcArgu[5].sCondition_ID = "FR_DATE";
                dvcArgu[5].sCondition_Value = "";


                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = "";



                dvcArgu[7].sCondition_ID = "LOT_ID";
                dvcArgu[7].sCondition_Value = sLot_ID;



                if (TPDR.GetDataOne("", ref dt, "CWIP2036-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }


                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdEDCList);

                cdvColset.Text = dt.Rows[0]["COL_SET_ID"].ToString();
                cdvColset.DisplayText = dt.Rows[0]["COL_SET_DESC"].ToString();


                for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                {
                    iRow = spdLotList.ActiveSheet.RowCount;



                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Value = dt.Rows[iRow]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Value = dt.Rows[iRow]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[iRow]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.PROD_QTY].Value = dt.Rows[iRow]["PROD_QTY"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[iRow]["CREATE_DATE"].ToString());
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.RES_ID].Value = dt.Rows[iRow]["RES_ID"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.RES_DESC].Value = dt.Rows[iRow]["RES_DESC"];
                    //    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.COMMENT, dt.Rows[iRow]["COMMENT"]);
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_VER].Value = dt.Rows[iRow]["MAT_VER"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FLOW].Value = dt.Rows[iRow]["FLOW"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FLOW_SEQ_NUM].Value = dt.Rows[iRow]["FLOW_SEQ_NUM"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.OPER].Value = dt.Rows[iRow]["OPER"];





                }

                MPCF.FitColumnHeader(spdLotList);


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }




        private void ViewLotInfos()
        {
            int iRow = 0;

            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;


                dvcArgu[3].sCondition_ID = "RES_ID";
                dvcArgu[3].sCondition_Value = cdvResource.Text;
                

                dvcArgu[4].sCondition_ID = "ORDER_ID";
                dvcArgu[4].sCondition_Value = cdvOrder.Text;


                dvcArgu[5].sCondition_ID = "FR_DATE";
                dvcArgu[5].sCondition_Value = dtpFromDate.Text.Replace("-", "");


                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToDate.Text.Replace("-", "");



                dvcArgu[7].sCondition_ID = "LOT_ID";
                dvcArgu[7].sCondition_Value = txtLotID.Text;



                if (TPDR.GetDataOne("", ref dt, "CWIP2036-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }


                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdEDCList);

                cdvColset.Text = dt.Rows[0]["COL_SET_ID"].ToString();
                cdvColset.DisplayText = dt.Rows[0]["COL_SET_DESC"].ToString();


                for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                {
                    iRow = spdLotList.ActiveSheet.RowCount;

         

                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Value = dt.Rows[iRow]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Value = dt.Rows[iRow]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[iRow]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.PROD_QTY].Value = dt.Rows[iRow]["PROD_QTY"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[iRow]["CREATE_DATE"].ToString());
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.RES_ID].Value = dt.Rows[iRow]["RES_ID"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.RES_DESC].Value = dt.Rows[iRow]["RES_DESC"];
                //    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.COMMENT, dt.Rows[iRow]["COMMENT"]);
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_VER].Value = dt.Rows[iRow]["MAT_VER"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FLOW].Value = dt.Rows[iRow]["FLOW"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FLOW_SEQ_NUM].Value = dt.Rows[iRow]["FLOW_SEQ_NUM"];
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.OPER].Value =   dt.Rows[iRow]["OPER"];





                }

                MPCF.FitColumnHeader(spdLotList);


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }



        //lot의 edc데이터가 있는지 체크하는 함수
        private bool ViewEdcCount(string sLotId)
        {
            bool bResult = false;
            iColSeq = 0;
            iLotHistSeq = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = MPCF.Trim(sLotId);

                dvcArgu[2].sCondition_ID = "COL_SET_ID";
                dvcArgu[2].sCondition_Value = cdvColset.Text;

                dvcArgu[3].sCondition_ID = "COL_SET_VERSION";
                dvcArgu[3].sCondition_Value = iColSetVer;

                if (TPDR.GetDataOne("", ref dt, "CWIP2003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    if (MPCF.ToInt(dt.Rows[0]["HIST_SEQ"].ToString()) != 0)
                    {
                        iLotHistSeq = MPCF.ToInt(dt.Rows[0]["HIST_SEQ"].ToString());
                        iColSeq = MPCF.ToInt(dt.Rows[0]["COL_SEQ"].ToString());
                        bResult = true;                        
                    }
                }

                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void GetColSet()
        {            
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

 


                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2003-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    cdvColset.Text = "";
                    return;
                }

                if (dt.Rows.Count > 0)
                {
                    cdvColset.Text = dt.Rows[0]["COL_SET_ID"].ToString();
                    cdvColset.DisplayText = dt.Rows[0]["COL_SET_DESC"].ToString();                    
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //ColSetVersion 체크
        private void FindColSetVersion(string s_Col_Set_id, string s_Lot_ID, string s_Mat_ID, int i_Mat_Ver, string s_Flow, string s_Oper)
        {
            iColSetVer = 0;
            bCheckData = false;

            try
            {
                TRSNode in_node = new TRSNode("FIND_COL_SET_VERSION_IN");
                TRSNode out_node = new TRSNode("FIND_COL_SET_VERSION_OUT");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", s_Lot_ID);
                in_node.AddString("MAT_ID", s_Mat_ID);
                in_node.AddInt("MAT_VER", i_Mat_Ver);
                in_node.AddString("FLOW", s_Flow);
                in_node.AddString("OPER", s_Oper);
                in_node.AddString("EVENT_ID", "");
                in_node.AddString("COL_SET_ID", s_Col_Set_id);
                in_node.AddChar("LOT_OR_RES_FLAG", 'L');

                if (MPCR.CallService("EDC", "EDC_Find_Col_Set_Version", in_node, ref out_node, false) == false)
                {
                    return;
                }

                iColSetVer = out_node.GetInt("COL_SET_VERSION");

                cls_derived_char_list.GetDerivedInfo(s_Col_Set_id, iColSetVer, s_Lot_ID, "", "", "");

                //col set list를 뿌려준다.
                if (ViewCharacterList(spdEDCList,'5',s_Col_Set_id,iColSetVer,'Y',cls_derived_char_list,s_Lot_ID) == false)
                {
                    return;
                }

                //데이터가 있으면 그리드에 등록된 데이터를 뿌려준다.
                bCheckData = ViewEdcCount(s_Lot_ID);
                
                if (bCheckData == true)
                {
                    if (View_Lot_Data(s_Lot_ID) == false)
                    {
                        CSCF.ClearSpread(spdEDCList, 0, VALUE_START_COL, "");
                    }
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //col set에 맞게 그리드를 그려준다.
        public bool ViewCharacterList(Control control, char ProcStep, string ColSetID, int ColSetVersion, char cIncludeUnitID, clsDerivedCharList cls_derived_char_list, string LotID)
        {

            int i;
            int j;
            int k;
            int m;
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
            FarPoint.Win.Spread.CellType.ComboBoxCellType UnitCellType = null;
            FarPoint.Win.Spread.CellType.ComboBoxCellType ValueCellType = null;

            typeNumber.FocusPosition = FarPoint.Win.Spread.CellType.EditorFocusCursorPosition.SelectAll;
            typeAscii.FocusPosition = FarPoint.Win.Spread.CellType.EditorFocusCursorPosition.SelectAll;

            TRSNode in_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_OUT");
            List<TRSNode> unit_list;

            try
            {
                spdEDCList.SuspendLayout();
                spdEDCList.ActiveSheet.RowCount = 0;
                spdEDCList.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;
                spdEDCList.ResumeLayout();

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;
                in_node.AddChar("INCLUDE_UNIT_ID", cIncludeUnitID);
                in_node.AddString("COL_SET_ID", ColSetID);
                in_node.AddInt("COL_SET_VERSION", ColSetVersion);
                in_node.AddString("LOT_ID", LotID);

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
                        FarPoint.Win.Spread.SheetView with_1 = spdEDCList.ActiveSheet;

                        iLastRow = with_1.RowCount - 1;
                        iUnitCnt = out_node.GetList(0)[i].GetInt("UNIT_COUNT");
                        iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        UnitCellType = null;
                        ValueCellType = null;
                        with_1.Columns[MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].Width = 50;

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
                            with_1.SetValue(j, (int)CHAR_COLUMN.CHAR_COL, out_node.GetList(0)[i].GetString("CHAR_ID"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.CHAR_SEQ, out_node.GetList(0)[i].GetInt("SEQ_NUM"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.CHAR_DESC_COL, out_node.GetList(0)[i].GetString("CHAR_DESC"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.SPEC_COL, MPCF.GetSpecInfo(out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("TARGET_VALUE")));
                            with_1.SetValue(j, (int)CHAR_COLUMN.OPT_INPUT_COL, out_node.GetList(0)[i].GetChar("OPT_INPUT_FLAG"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.VALUE_TYPE_COL, out_node.GetList(0)[i].GetChar("VALUE_TYPE"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.VALUE_COUNT_COL, out_node.GetList(0)[i].GetInt("VALUE_COUNT"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.DEF_UNIT_OVR_FLAG_COL, out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.DEF_VALUE_COL, out_node.GetList(0)[i].GetString("DEF_VALUE"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.UNIT_TBL_COL, out_node.GetList(0)[i].GetString("UNIT_TBL"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.VALUE_TBL_COL, out_node.GetList(0)[i].GetString("VALUE_TBL"));
                            with_1.SetValue(j, (int)CHAR_COLUMN.UNIT_SEQ_COL, iUnitSeq);
                        }

                        i_index = 0;

                        //VALUE_TYPE에 따라 컬럼의 셀 타입을 지정해준다.
                        for (j = VALUE_START_COL; j < VALUE_START_COL + iValueCnt; j++)
                        {
                            for (k = iLastRow + 1; k < with_1.RowCount; k++)
                            {
                                if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                                {
                                    MPCR.SetNumberCell(with_1.Cells[k, j]);                                    
                                    with_1.Cells[k, j].CellType = typeNumber;
                                }
                                else
                                {
                                    MPCR.SetAsciiCell(with_1.Cells[k, j]);
                                    with_1.Cells[k, j].CellType = typeAscii;
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
                        if (unit_list.Count < 1)
                        {
                            if (cDefUnitFlag == 'C')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].Locked = true;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].BackColor = System.Drawing.Color.WhiteSmoke;
                                    with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL), out_node.GetList(0)[i].GetString("UNIT"));
                                    if (out_node.GetList(0)[i].GetString("UNIT") == "")
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL), "*");
                                    }
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL), "CHARACTER");
                                }

                            }
                            else if (cDefUnitFlag == 'E')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].BackColor = System.Drawing.Color.White;
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL), "NULL");
                                }
                            }
                            else
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].BackColor = System.Drawing.Color.White;
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
                                        with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL), "NULL");
                                    }
                                    else
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(CHAR_COLUMN.UNIT_COL), unit_list[m].GetString("DEF_UNIT_ID"));
                                    }

                                    if (out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG") == 'Y')
                                    {
                                    }
                                    else
                                    {
                                        with_1.Cells[iLastRow + 1 + m, (int)CHAR_COLUMN.UNIT_COL].Locked = true;
                                        with_1.Cells[iLastRow + 1 + m, (int)CHAR_COLUMN.UNIT_COL].BackColor = System.Drawing.Color.WhiteSmoke;
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
                                        if (BASLIST.ViewGCMDataList(control, '1', sUnitTbl, -1, null, "", false, MPCF.ToInt(CHAR_COLUMN.UNIT_COL), j, null) == false)
                                        {
                                            return false;
                                        }
                                        else
                                        {
                                            UnitCellType = (FarPoint.Win.Spread.CellType.ComboBoxCellType)(with_1.Cells[j, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].CellType);
                                            with_1.Columns[MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].Width = 50;
                                        }
                                    }
                                    else
                                    {
                                        with_1.Cells[j, MPCF.ToInt(CHAR_COLUMN.UNIT_COL)].CellType = UnitCellType;
                                    }
                                }
                            }
                        }

                        //기본값 세팅 - > ColSet의 케릭터에 셋팅한 기본값을 넣어준다.                        
                        for (j = VALUE_START_COL; j <= iValueCnt + VALUE_START_COL - 1; j++)
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
                        for (j = iValueCnt + VALUE_START_COL; j < with_1.ColumnCount; j++)
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
                FarPoint.Win.Spread.SheetView with_2 = spdEDCList.ActiveSheet;
                int iColumnSeq = 0;

                if (with_2.ColumnCount > DEFAULT_COL_COUNT)
                {
                    with_2.ColumnHeader.Cells.Get(0, VALUE_START_COL).ColumnSpan = with_2.ColumnCount - DEFAULT_COL_COUNT;
                    for (i = VALUE_START_COL; i < with_2.ColumnCount; i++)
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

        //저장된 데이터 가져오는 함수
        private bool View_Lot_Data(string sLotId)
        {
            int iRow = 0;
            int iUnitCnt = 0;
            int iValueCnt = 0;
            string s_value_name;

            TRSNode in_node = new TRSNode("VIEW_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("VIEW_LOT_DATA_OUT");
            System.Collections.ArrayList a_values = new System.Collections.ArrayList();

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLotId);
                in_node.AddInt("HIST_SEQ", iLotHistSeq);
                in_node.AddChar("INCLUDE_DEL_HIST", 'Y');
                in_node.AddString("NEXT_COL_SET_ID", " ");
                in_node.AddInt("NEXT_CHAR_SEQ_NUM", 0);
                in_node.AddInt("NEXT_UNIT_SEQ_NUM", 0);
                in_node.AddInt("NEXT_VALUE_SEQ_NUM", 0);
                in_node.AddInt("NEXT_COL_SEQ", 0);

                do
                {
                    if (MPCR.CallService("EDC", "EDC_View_Lot_Data", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (int i = 0; i < out_node.GetList(0).Count; i++)
                    {                        
                        if (out_node.GetList(0)[i].GetChar("HIS_DEL_FLAG") == 'Y' || out_node.GetList(0)[i].GetInt("COL_SEQ") != iColSeq) 
                            continue;

                        for (int j = 0; j < spdEDCList.ActiveSheet.RowCount; j++)
                        {
                            if (spdEDCList.ActiveSheet.Cells[j, (int)CHAR_COLUMN.CHAR_COL].Text == out_node.GetList(0)[i].GetString("CHAR_ID")
                                && MPCF.ToInt(spdEDCList.ActiveSheet.Cells[j, (int)CHAR_COLUMN.UNIT_SEQ_COL].Text) == out_node.GetList(0)[i].GetInt("UNIT_SEQ_NUM"))
                            {
                                iRow = j;
                                break;
                            }
                        }

                        spdEDCList.ActiveSheet.SetValue(iRow, (int)CHAR_COLUMN.UNIT_COL, out_node.GetList(0)[i].GetString("UNIT_ID"));

                        iUnitCnt = out_node.GetList(0)[i].GetInt("UNIT_COUNT");
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
                                if (MPCF.Trim(out_node.GetList(0)[i].GetString(s_value_name)) != "")
                                {
                                    spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1)].Value = MPCF.ToDbl(out_node.GetList(0)[i].GetString(s_value_name));
                                }
                            }
                            else
                            {
                                spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1)].Value = MPCF.Trim(out_node.GetList(0)[i].GetString(s_value_name));
                            }

                            if (out_node.GetList(0)[i].GetChar("DERIVED_PARAM_FLAG") == 'Y')
                            {
                                spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1)].Locked = true;
                                spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1)].BackColor = System.Drawing.Color.Cyan;
                                spdEDCList.ActiveSheet.Rows[iRow].Tag = "AUTO";

                                cls_derived_char_list.SetCharLocation(out_node.GetList(0)[i].GetString("CHAR_ID"), spdEDCList.ActiveSheet, k - 1, iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1));
                            }
                        }
                    }

                    in_node.SetString("NEXT_COL_SET_ID", out_node.GetString("NEXT_COL_SET_ID"));
                    in_node.SetInt("NEXT_CHAR_SEQ_NUM", out_node.GetInt("NEXT_CHAR_SEQ_NUM"));
                    in_node.SetInt("NEXT_UNIT_SEQ_NUM", out_node.GetInt("NEXT_UNIT_SEQ_NUM"));
                    in_node.SetInt("NEXT_VALUE_SEQ_NUM", out_node.GetInt("NEXT_VALUE_SEQ_NUM"));
                    in_node.SetInt("NEXT_COL_SEQ", out_node.GetInt("NEXT_COL_SEQ"));
                } while (MPCF.Trim(in_node.GetString("NEXT_COL_SET_ID")) != "" ||
                         in_node.GetInt("NEXT_CHAR_SEQ_NUM") > 0 ||
                         in_node.GetInt("NEXT_UNIT_SEQ_NUM") > 0 ||
                         in_node.GetInt("NEXT_VALUE_SEQ_NUM") > 0 ||
                         in_node.GetInt("NEXT_COL_SEQ") > 0);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }
         
        //lot data 서비스 호출
        public bool Collect_Lot_Data()
        {
            int i_value_count;
            int iActRow = 0;

            TRSNode in_node = new TRSNode("COLLECT_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");            
            TRSNode char_item, unit_item, value_item;
            CultureInfo ci_inter = new CultureInfo("en-US");

            iActRow = spdLotList.ActiveSheet.ActiveRowIndex;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.LOT_ID].Text));
                in_node.AddInt("HIST_SEQ", iLotHistSeq);
                in_node.AddChar("LOT_EDC_TRAN_FLAG", 'Y');
                in_node.AddString("MAT_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.MAT_ID].Text));
                in_node.AddInt("MAT_VER", MPCF.ToInt(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.MAT_VER].Text));
                in_node.AddString("FLOW", MPCF.Trim(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.FLOW].Text));
                in_node.AddInt("FLOW_SEQ_NUM", MPCF.ToInt(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.FLOW_SEQ_NUM].Text));
                in_node.AddString("OPER", MPCF.Trim(cdvOper.Text));
                in_node.AddString("MEAS_RES_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.RES_ID].Text));
                in_node.AddString("COL_SET_ID", MPCF.Trim(cdvColset.Text));
                in_node.AddString("PROC_FLOW", MPCF.Trim(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.FLOW].Text));

                in_node.AddInt("COL_SET_VERSION", iColSetVer);                
                in_node.AddString("PROC_OPER", MPCF.Trim(cdvOper.Text));                
                in_node.AddString("PROC_RES_ID", MPCF.Trim(cdvResource.Text));

                char_item = in_node.AddNode("CHAR_LIST");
                for (int i = 0; i < spdEDCList.ActiveSheet.RowCount; i++)
                {
                    if (MPCF.ToInt(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.UNIT_SEQ_COL)) == 1)
                    {
                        if (i != 0)
                        {
                            char_item = in_node.AddNode("CHAR_LIST");
                        }
                    
                        char_item.AddString("CHAR_ID", MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.CHAR_COL)));                        
                        char_item.AddString("COL_SET_ID", MPCF.Trim(cdvColset.Text));
                        char_item.AddInt("COL_SET_VERSION", iColSetVer);
                        char_item.AddInt("COL_SEQ", 1);
                        char_item.AddInt("CHAR_SEQ_NUM", MPCF.ToInt(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.CHAR_SEQ)));                        
                    }
                    unit_item = char_item.AddNode("UNIT_LIST");
                    unit_item.AddString("UNIT_ID", MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.UNIT_COL)));
                    unit_item.AddInt("UNIT_SEQ_NUM", MPCF.ToInt(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.UNIT_SEQ_COL)));
                    unit_item.AddChar("VALUE_TYPE", spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.VALUE_TYPE_COL));

                    i_value_count = MPCF.ToInt(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.VALUE_COUNT_COL));
                    for (int j = 0; j < i_value_count; j++)
                    {
                        value_item = unit_item.AddNode("VALUE_LIST");

                        if (MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.VALUE_TYPE_COL)) == "N" &&
                            MPCF.CheckNumeric(spdEDCList.ActiveSheet.GetValue(i, j + (int)CHAR_COLUMN.VALUE_START_COL)) == true)
                        {
                            value_item.AddString("VALUE", MPCF.ToDbl(spdEDCList.ActiveSheet.GetValue(i, j + (int)CHAR_COLUMN.VALUE_START_COL)).ToString(ci_inter.NumberFormat));
                        }
                        else
                        {
                            value_item.AddString("VALUE", MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, j + (int)CHAR_COLUMN.VALUE_START_COL)));
                        }
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Input_Lot_Data", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else

                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.COMMENT].Value = "SAVE OK(저장완료)";
                //MPCR.ShowSuccessMsg(out_node);

                if (out_node.StatusValue == MPGC.MP_FAIL_STATUS)
                {
                    MPCR.CheckContinueProc(out_node);
                    return false;
                }



                //DrawSpecOutMask(out_node);                                    
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        //스펙 아웃 체크
        public void DrawSpecOutMask(TRSNode out_node)
        {
            int i;
            int m;
            int k;
            int i_value_count;
            int i_row;
            Color spec_out_back_color;

            TRSNode spec_out_mask_ary;
            List<TRSNode> char_list, unit_list;

            i_row = 0;
            char_list = out_node.GetList("CHAR_LIST");

            for (i = 0; i < char_list.Count; i++)
            {
                unit_list = char_list[i].GetList("UNIT_LIST");
                for (k = 0; k < unit_list.Count; k++)
                {
                    spec_out_mask_ary = unit_list[k].GetArray("SPEC_OUT_MASK");
                    i_value_count = spec_out_mask_ary.MemberCount;

                    for (m = 0; m < i_value_count; m++)
                    {
                        spec_out_back_color = Color.White;

                        if (spec_out_mask_ary.GetChar(m.ToString()) == '1' ||
                            spec_out_mask_ary.GetChar(m.ToString()) == '4' ||
                            spec_out_mask_ary.GetChar(m.ToString()) == '5')
                        {
                            spec_out_back_color = Color.Red;
                        }
                        else if (spec_out_mask_ary.GetChar(m.ToString()) == '2' ||
                                 spec_out_mask_ary.GetChar(m.ToString()) == '3')
                        {
                            spec_out_back_color = Color.Yellow;
                        }
                        else if (MPCF.Trim(spdEDCList.ActiveSheet.Rows[i_row].Tag) == "AUTO")
                        {
                            spec_out_back_color = Color.Cyan;
                        }

                        spdEDCList.ActiveSheet.Cells[i_row, VALUE_START_COL + m].BackColor = spec_out_back_color;
                    }
                    i_row++;
                }
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;


                    case CSGC.CHECK.SAVE:

                        if (spdEDCList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            spdEDCList.Select();
                            return false;
                        }

                        for (int i = 0; i < spdEDCList.ActiveSheet.RowCount; i++)
                        {
                            if (MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.CHAR_COL)) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                spdEDCList.ActiveSheet.SetActiveCell(i, (int)CHAR_COLUMN.CHAR_COL);
                                spdEDCList.Select();
                                return false;
                            }

                            // unit_id check
                            if (MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.OPT_INPUT_COL)) != "Y")
                            {
                                for (int j = (int)CHAR_COLUMN.UNIT_COL; j <= (int)CHAR_COLUMN.UNIT_COL + MPCF.ToInt(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.VALUE_COUNT_COL)); j++)
                                {
                                    if (MPCF.Trim(spdEDCList.ActiveSheet.GetTag(i, j)) != "NULL")
                                    {
                                        if (MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, j)) == "" && spdEDCList.ActiveSheet.Cells[i, j].Locked == false)
                                        {
                                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                            spdEDCList.ActiveSheet.SetActiveCell(i, j);
                                            spdEDCList.Select();
                                            return false;
                                        }
                                    }
                                }
                            }
                            if (MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.VALUE_TYPE_COL)) == "N")
                            {
                                for (int j = VALUE_START_COL; j < VALUE_START_COL + MPCF.ToInt(spdEDCList.ActiveSheet.GetValue(i, (int)CHAR_COLUMN.VALUE_COUNT_COL)); j++)
                                {
                                    if (MPCF.Trim(spdEDCList.ActiveSheet.GetValue(i, j)) != "")
                                    {
                                        if (MPCF.CheckNumeric(spdEDCList.ActiveSheet.GetValue(i, j)) == false)
                                        {
                                            //CMN116 ERROR - 이 필드는 숫자를 입력해야 하는 필드입니다.
                                            MPCF.ShowMsgBox(MPCF.GetMessage(116));
                                            spdEDCList.ActiveSheet.SetActiveCell(i, j);
                                            spdEDCList.Select();
                                            return false;
                                        }
                                    }
                                }
                            }
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

        #endregion

        #region " Event Definition "

        private void frmTranInputLotDataMulti_Load(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(txtLotID.Text) != "")
                {
                    btnView.PerformClick();

                    //COLSET ID찾아오기
                    GetColSet();

                    if (MPCF.Trim(cdvColset.Text) != "")
                    {
                        cdvColset_SelectedItemChanged(sender, null);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvColset_ButtonPress(object sender, EventArgs e)
        {
            string s_Flow = "";
            string s_Oper = "";
            string s_Mat_id = "";
            int s_Mat_ver = 0;

            try
            {
                s_Oper = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.OPER].Text;
                s_Flow = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Text;
                s_Mat_id = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.MAT_ID].Text;
                s_Mat_ver = MPCF.ToInt(spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.MAT_VER].Text);

                cdvColset.Init();
                MPCF.InitListView(cdvColset.GetListView);
                cdvColset.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvColset.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvColset.SelectedSubItemIndex = 0;
                cdvColset.DisplaySubItemIndex = 1;

                if (EDCLIST.ViewMFOColSetList(cdvColset.GetListView, '2', null, "", '0', s_Mat_id, s_Mat_ver, s_Flow, s_Oper, 'M', ' ', 'N', -1, -1) == false)
                {
                    return;
                }

                cdvColset.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvColset_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

            cdvColset_change();

            /*
            string s_Lot_id = "";
            string s_Flow = "";
            string s_Oper = "";
            string s_Mat_id = "";
            int s_Mat_ver = 0;
            int iActRow = 0;


            try
            {
                if (MPCF.Trim(cdvColset.Text) != "")
                {

                    iActRow = spdLotList.ActiveSheet.ActiveRowIndex;

                    s_Lot_id = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.LOT_ID].Text;
                    s_Oper = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.OPER].Text;
                    s_Flow = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.FLOW].Text;
                    s_Mat_id = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.MAT_ID].Text;
                    s_Mat_ver = MPCF.ToInt(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.MAT_VER].Text);

                    FindColSetVersion(cdvColset.Text, s_Lot_id, s_Mat_id, s_Mat_ver, s_Flow, s_Oper);
                }
                else
                {
                    MPCF.ClearList(spdEDCList);
                    spdEDCList.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

            */
        }


        private void cdvColset_change()
        {
            string s_Lot_id = "";
            string s_Flow = "";
            string s_Oper = "";
            string s_Mat_id = "";
            int s_Mat_ver = 0;
            int iActRow = 0;


            try
            {
                if (MPCF.Trim(cdvColset.Text) != "")
                {

                    iActRow = spdLotList.ActiveSheet.ActiveRowIndex;

                    s_Lot_id = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.LOT_ID].Text;
                    s_Oper = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.OPER].Text;
                    s_Flow = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.FLOW].Text;
                    s_Mat_id = spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.MAT_ID].Text;
                    s_Mat_ver = MPCF.ToInt(spdLotList.ActiveSheet.Cells[iActRow, (int)LOT_INFO.MAT_VER].Text);

                    FindColSetVersion(cdvColset.Text, s_Lot_id, s_Mat_id, s_Mat_ver, s_Flow, s_Oper);
                }
                else
                {
                    MPCF.ClearList(spdEDCList);
                    spdEDCList.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;
                }

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
                    ViewLotInfo(txtLotID.Text);
                    MPCF.ClearList(spdEDCList);
                    cdvColset.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_ButtonClick(object sender, Infragistics.Win.Misc.AlertButtonClickedEventArgs e)
        {
            try
            {
                txtLotID.sArea_id = cdvDept.Text;
                txtLotID.sArea_desc = cdvDept.DisplayText;
                txtLotID.sSub_Area_id = cdvWorkPlace.Text;
                txtLotID.sSub_Area_desc = cdvWorkPlace.DisplayText;
                txtLotID.sOper_id = cdvOper.Text;
                txtLotID.sOper_desc = cdvOper.DisplayText;
                txtLotID.sRes_id = cdvResource.Text;
                txtLotID.sRes_desc = cdvResource.DisplayText;
                txtLotID.sOrder = cdvOrder.Text;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdEDCList_EditModeOff(object sender, EventArgs e)
        {
            try
            {
                int iColumn;
                int iRow;
                int i_column_count;

                if (spdEDCList.ActiveSheet.RowCount < 1)
                {
                    return;
                }

                iColumn = spdEDCList.ActiveSheet.ActiveColumnIndex;
                iRow = spdEDCList.ActiveSheet.ActiveRowIndex;

                {
                    System.Collections.ArrayList a_values = new System.Collections.ArrayList();
                    string s_char_id;
                    int i_unit_seq;
                    int i_value_count;
                    int i;

                    s_char_id = MPCF.Trim(spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.CHAR_COL].Value);
                    i_unit_seq = MPCF.ToInt(spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.UNIT_SEQ_COL].Value);
                    i_value_count = MPCF.ToInt(spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_COUNT_COL].Value);

                    if (spdEDCList.ActiveSheet.ColumnCount - (int)CHAR_COLUMN.VALUE_START_COL > i_value_count)
                        i_column_count = spdEDCList.ActiveSheet.ColumnCount - (int)CHAR_COLUMN.VALUE_START_COL;
                    else
                        i_column_count = i_value_count;

                    for (i = 0; i < i_column_count; i++)
                    {
                        a_values.Add(spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_START_COL + i].Value);
                    }

                    cls_derived_char_list.SetValue(s_char_id, i_unit_seq, a_values, true);
                    MPCR.RecalculateDerivedParam(spdEDCList, cls_derived_char_list, (int)CHAR_COLUMN.CHAR_COL, (int)CHAR_COLUMN.VALUE_START_COL, (int)CHAR_COLUMN.VALUE_COUNT_COL);
                }

                spdEDCList.ActiveSheet.Cells[iRow, iColumn].Font = new System.Drawing.Font(this.Font, FontStyle.Bold);
                if (iColumn < spdEDCList.ActiveSheet.ColumnCount - 1 && spdEDCList.ActiveSheet.Cells[iRow, iColumn + 1].Locked == false)
                {
                    spdEDCList.ActiveSheet.SetActiveCell(iRow, iColumn + 1);
                }
                else
                {
                    if (iRow + 1 == spdEDCList.ActiveSheet.RowCount)
                    {
                        return;
                    }
                    if (spdEDCList.ActiveSheet.Cells[iRow + 1, (int)CHAR_COLUMN.UNIT_COL].Locked == false)
                    {
                        spdEDCList.ActiveSheet.SetActiveCell(iRow + 1, (int)CHAR_COLUMN.UNIT_COL);
                    }
                    else
                    {
                        int i;
                        for (i = iRow + 1; i < spdEDCList.ActiveSheet.RowCount; i++)
                        {
                            if (spdEDCList.ActiveSheet.Cells[i, (int)CHAR_COLUMN.VALUE_START_COL].Locked == false)
                            {
                                spdEDCList.ActiveSheet.SetActiveCell(i, (int)CHAR_COLUMN.VALUE_START_COL);
                                break;
                            }
                        }
                    }
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

                 ViewLotInfos();

                //    ViewLotInfo(txtLotID.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (Collect_Lot_Data() == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        #endregion



        private void findDate(int iRow)
        {
            string s_Lot_id = "";
            string s_Flow = "";
            string s_Oper = "";
            string s_Mat_id = "";
            int s_Mat_ver = 0;

            try
            {
                if (MPCF.Trim(cdvColset.Text) != "")
                {
                    s_Lot_id = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Text;
                    s_Oper = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.OPER].Text;
                    s_Flow = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FLOW].Text;
                    s_Mat_id = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Text;
                    s_Mat_ver = MPCF.ToInt(spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_VER].Text);

                    FindColSetVersion(cdvColset.Text, s_Lot_id, s_Mat_id, s_Mat_ver, s_Flow, s_Oper);

                    //cdvColset_change();
                }
                else
                {
                    MPCF.ClearList(spdEDCList);
                    spdEDCList.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {

            try
            {
                findDate(e.Row);
                RowColorChange(e.Row);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdEDCList_KeyPress(object sender, KeyPressEventArgs e)
        {

        }

        private void spdEDCList_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (e.Control && e.KeyCode == Keys.S)
                {

                    {
                        if (CheckCondition(CSGC.CHECK.SAVE) == false)
                            return;

                        if (Collect_Lot_Data() == false)
                        {
                            return;
                        }



                        if (spdLotList.ActiveSheet.ActiveRowIndex < spdLotList.ActiveSheet.Rows.Count-1)
                        {
                            spdLotList.ActiveSheet.ActiveRowIndex = spdLotList.ActiveSheet.ActiveRowIndex + 1;
                            findDate(spdLotList.ActiveSheet.ActiveRowIndex);
                            RowColorChange(spdLotList.ActiveSheet.ActiveRowIndex);
                        }


                        spdEDCList.ActiveSheet.ActiveRowIndex = 0;
                        spdEDCList.ActiveSheet.ActiveColumnIndex = 14;

                    }
                }
                else if(e.KeyCode == Keys.Add)
                {
                        {
                            if (CheckCondition(CSGC.CHECK.SAVE) == false)
                                return;

                            if (Collect_Lot_Data() == false)
                            {
                                return;
                            }



                            if (spdLotList.ActiveSheet.ActiveRowIndex < spdLotList.ActiveSheet.Rows.Count - 1)
                            {
                                spdLotList.ActiveSheet.ActiveRowIndex = spdLotList.ActiveSheet.ActiveRowIndex + 1;
                                findDate(spdLotList.ActiveSheet.ActiveRowIndex);
                                RowColorChange(spdLotList.ActiveSheet.ActiveRowIndex);
                        }


                            spdEDCList.ActiveSheet.ActiveRowIndex = 0;
                            spdEDCList.ActiveSheet.ActiveColumnIndex = 14;

                        }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdEDCList_EditModeOn(object sender, EventArgs e)
        {
          //  spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.COMMENT].Value = "Editing(수정중)";
        }

        private void spdLotList_KeyDown(object sender, KeyEventArgs e)
        {

        }

        private void spdLotList_KeyPress(object sender, KeyPressEventArgs e)
        {

        }

        private void spdLotList_KeyUp(object sender, KeyEventArgs e)
        {
            try
            {
                if (spdLotList.ActiveSheet.Rows.Count == 0)
                {
                    return;
                }


                findDate(spdLotList.ActiveSheet.ActiveRowIndex);
                RowColorChange(spdLotList.ActiveSheet.ActiveRowIndex);


            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private  void RowColorChange(int iRow)
        {
            try
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                spdLotList.ActiveSheet.Rows[iRow].BackColor = Color.FromArgb(159, 201, 60);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
    }

}
