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
    public partial class frmTranMoveOrderRegistration : CUS_COM.frmTranForm01
    {
        public frmTranMoveOrderRegistration()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MOVE_LIST
        {
            MOVE_ORDER_ID,          // 1 : 이동지시 번호
            FROM_AREA_ID,           // 2 : FROM 사업부
            FROM_SUB_AREA_ID,       // 3 : FROM 사업장
            FROM_OPER,              // 4 : FROM 공정
            TO_AREA_ID,             // 5 : TO 사업부
            TO_AREA_DESC,           // 6 : TO 사업부
            TO_SUB_AREA_ID,         // 7 : TO 사업장
            TO_SUB_AREA_DESC,       // 8 : TO 사업장
            TO_OPER,                // 9 : TO 공정
            TO_OPER_DESC,           //10 : TO 공정
            MOVE_STATUS,            //11 : 상태
            MERGE_FLAG              //12 : 병합 여부
        }

        private enum LOT_INFO
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            CREATE_DATE,            // 6 : 생성일자
            PRESS_RES_ID,
            PRESS_RES_DESC,
            ORDER_ID,
            CREATE_CODE,
            CREATE_CODE_DESC,
            COMMENT
        }

        private enum MOVE_INFO
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            CREATE_DATE,            // 6 : 생성일자
            PRESS_RES_ID,
            PRESS_RES_DESC,
            ORDER_ID,
            CREATE_CODE,
            CREATE_CODE_DESC,
            COMMENT
        }

        #endregion

        #region " Variable Definition "

        string sMove_id = "";
        string s_from_oper_grp = "";
        string s_to_oper_grp = "";
        bool bCheckMergeArea = false;
        bool bCheckAutoMerge = false;
        bool bCheckCTMPress = false;
        bool bCheckAreaCTM = false;
        bool bNoModify = false;

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNew.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동지시 list 조회 함수
        private void ViewMoveList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvFromOper.Text;

                dvcArgu[4].sCondition_ID = "MOVE_ID";
                dvcArgu[4].sCondition_Value = txtMoveOrder.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMoveList);
                    return;
                }

                MPCF.ClearList(spdMoveList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoveList_Sheet1.RowCount++;
                    
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_ORDER_ID].Value = dt.Rows[i]["MOVE_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_AREA_ID].Value = dt.Rows[i]["FROM_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_SUB_AREA_ID].Value = dt.Rows[i]["FROM_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_OPER].Value = dt.Rows[i]["FROM_OPER"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_AREA_ID].Value = dt.Rows[i]["TO_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_AREA_DESC].Value = dt.Rows[i]["TO_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_SUB_AREA_ID].Value = dt.Rows[i]["TO_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_SUB_AREA_DESC].Value = dt.Rows[i]["TO_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER].Value = dt.Rows[i]["TO_OPER"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER_DESC].Value = dt.Rows[i]["TO_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_STATUS].Value = dt.Rows[i]["MOVE_STATUS"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MERGE_FLAG].Value = dt.Rows[i]["MERGE_FLAG"];
                }

                MPCF.FitColumnHeader(spdMoveList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot list 조회 함수
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";

                if (bCheckCTMPress)
                    sViewID = "CWIP2010-007";
                else
                    sViewID = "CWIP2010-002";


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvFromOper.Text;

                dvcArgu[2].sCondition_ID = "PRESS_RES_ID";
                dvcArgu[2].sCondition_Value = cdvResource.Text + "%";

                dvcArgu[3].sCondition_ID = "FROM_DATE";
                dvcArgu[3].sCondition_Value = dtpWorkDate.Text.Replace("-", "") + "000000";

                dvcArgu[4].sCondition_ID = "TO_DATE";
                dvcArgu[4].sCondition_Value = dtpWorkDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.SetValue(i, (int)LOT_INFO.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    //spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.PRESS_RES_ID].Value = dt.Rows[i]["PRESS_RES_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.PRESS_RES_DESC].Value = dt.Rows[i]["PRESS_RES_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];                
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }

                MPCF.FitColumnHeader(spdLotList);

                initCheckCount();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void initCheckCount()
        {
            bool allCheck = false;
            //헤더클릭 초기화
            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
            {
                if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().Trim() == "TRUE")
                {
                    allCheck = true;
                    break;
                }
            }

            spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_INFO.CHK].Value = allCheck;
            txtSelectedCount.Text = CheckCount().ToString();
        }

        //이동지시 등록 lot list 조회 함수
        private void ViewMoveLotList(string sMove_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MOVE_ID";
                dvcArgu[1].sCondition_Value = sMove_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMoveLotList);
                    return;
                }

                MPCF.ClearList(spdMoveLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoveLotList_Sheet1.RowCount++;

                    spdMoveLotList_Sheet1.SetValue(i, (int)MOVE_INFO.CHK, false);
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    //jyd :  spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.PRESS_RES_ID].Value = dt.Rows[i]["PRESS_RES_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.PRESS_RES_DESC].Value = dt.Rows[i]["PRESS_RES_DESC"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }

                MPCF.FitColumnHeader(spdMoveLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot 정보 조회 함수
        private void ViewLotInfo(string sLot_ID)
        {
            string sLotId = "";
            string sOper = "";
            int iRow = 0;
            bool b_duplication_flag = false;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLot_ID);
                in_node.AddChar("MOVE_OPEN_STATUS_EXISTS_CHECK", 'Y');

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    for (int k = 0; k < spdMoveLotList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdMoveLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text)
                        {
                            b_duplication_flag = true;
                            break;
                        }
                    }

                    //중복일경우, 추가하지 않음.
                    if(b_duplication_flag == true)
                    {
                        b_duplication_flag = false;
                        break;
                    }

                    sOper = out_node.GetList("LOT_TBL")[i].GetString("OPER");
                    if (cdvFromOper.Text != sOper)
                    {
                        //CMN457 ERROR - 이 LOT은 해당 공정에 존재하지 않습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(457) + " [ " + sOper +"/" + sLotId + " ]");
                        return;
                    }


                    //20210810 송용 이거걸어논 이유 정확히 모름 일단 뺌,문제되면 그때봐서 조치.
                    /*
                    if(MPCF.Trim(out_node.GetList("LOT_TBL")[i].GetString("LOT_CMF_14")) != "")
                    {
                        continue;
                    }
                    */

                    iRow = spdMoveLotList.ActiveSheet.RowCount;

                    spdMoveLotList.ActiveSheet.RowCount++;
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CHK, true);
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CREATE_DATE, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.DATE));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.PRESS_RES_ID, out_node.GetList("LOT_TBL")[i].GetString("PRESS_RES_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.PRESS_RES_DESC, out_node.GetList("LOT_TBL")[i].GetString("PRESS_RES_DESC"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.ORDER_ID, out_node.GetList("LOT_TBL")[i].GetString("ORDER_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CREATE_CODE, out_node.GetList("LOT_TBL")[i].GetString("CREATE_CODE"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CREATE_CODE_DESC, out_node.GetList("LOT_TBL")[i].GetString("CREATE_CODE_DESC"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.COMMENT, out_node.GetList("LOT_TBL")[i].GetString("LAST_COMMENT"));

                    //lot list에 스캔한 lot이 존재한 경우 리스트에서 없애준다.
                    for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                    {
                        if (spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text == sLotId)
                        {
                            spdLotList.ActiveSheet.RemoveRows(k, 1);
                        }
                    }
                }

                MPCF.FitColumnHeader(spdMoveLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //이동지시 등록 저장 함수
        private bool MoveLot(char sStep, string sMove_id)
        {
            TRSNode in_node = new TRSNode("MoveLot_In");
            TRSNode out_node = new TRSNode("MoveLot_Out");
            TRSNode input_list;

            try
            {
                //step 1: 저장 , step 2: 취소 , step 4: CTM press인 경우
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvFromOper.Text);
                in_node.AddString("TO_OPER", cdvToOper.Text);

                if (chkMerge.Visible == true)
                {
                    in_node.AddChar("MERGE_YN", chkMerge.Checked == true ? 'Y' : 'N');
                }
                else
                {
                    in_node.AddChar("MERGE_YN", 'N');
                }

                in_node.AddString("MOVE_ID", sMove_id);

                if (sStep != '4')
                {
                    for (int i = 0; i < spdMoveLotList.ActiveSheet.RowCount; i++)
                    {
                        input_list = in_node.AddNode("LOT_LIST");
                        input_list.AddString("LOT_ID", spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.LOT_ID].Text);
                        input_list.AddDouble("QTY", MPCF.ToDbl(spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.QTY].Text));

                        if (chkMerge.Visible == true)
                        {
                            if (chkMerge.Checked == true)
                            {
                                if (i == 0)
                                    input_list.AddChar("MERGE_LOT_FLAG", 'Y');
                                else
                                    input_list.AddChar("MERGE_LOT_FLAG", 'N');
                            }
                            else
                                input_list.AddChar("MERGE_LOT_FLAG", 'N');
                        }
                        else
                        {
                            input_list.AddChar("MERGE_LOT_FLAG", 'N');
                        }
                    }
                }
                else
                {
                    /*
                        FarPoint.Win.Spread.SortInfo[] sort = new FarPoint.Win.Spread.SortInfo[2];
                        sort[0] = new FarPoint.Win.Spread.SortInfo(0, false, System.Collections.Comparer.DefaultInvariant);
                        sort[1] = new FarPoint.Win.Spread.SortInfo(1, true, System.Collections.Comparer.Default);
                        fpSpread1.ActiveSheet.SortRows(0, 20, sort);
                    */

                    //이동지시 목록 그리드의 리스트를 datatable에 담아 프레스 설비, mat id 별 order by를 해준뒤 서버에 보낸다. 
                    DataTable dt = new DataTable();
                    dt.Columns.Add("LOT_ID", typeof(string));
                    dt.Columns.Add("MAT_ID", typeof(string));
                    dt.Columns.Add("MAT_DESC", typeof(string));
                    dt.Columns.Add("QTY", typeof(double));
                    dt.Columns.Add("CREATE_DATE", typeof(string));
                    dt.Columns.Add("PRESS_RES_ID", typeof(string));

                    for (int i = 0; i < spdMoveLotList.ActiveSheet.RowCount; i++)
                    {
                        dt.Rows.Add(spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.LOT_ID].Text,
                                    spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.MAT_ID].Text,
                                    spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.MAT_DESC].Text,
                                    MPCF.ToDbl(spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.QTY].Text),
                                    spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.CREATE_DATE].Text,
                                    spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.PRESS_RES_ID].Text);
                    }

                    dt = dt.Select("", "PRESS_RES_ID ASC, MAT_ID ASC ,LOT_ID ASC").CopyToDataTable<DataRow>();

                    for (int k = 0; k < dt.Rows.Count; k++)
                    {
                        input_list = in_node.AddNode("LOT_LIST");
                        input_list.AddString("LOT_ID", dt.Rows[k]["LOT_ID"].ToString());
                        input_list.AddString("MAT_ID", dt.Rows[k]["MAT_ID"].ToString());
                        input_list.AddString("PRESS_RES_ID", dt.Rows[k]["PRESS_RES_ID"].ToString());
                        input_list.AddDouble("QTY", dt.Rows[k]["QTY"]);
                        input_list.AddChar("MERGE_LOT_FLAG", 'N');
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Move_Lot_Order", in_node, ref out_node) == false)
                    return false;
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                    sMove_id = "";
                }

                //라벨 출력
              /*  if (sStep == '1')
                {
                    PrintLable(sStep, CSGC.CP_LABEL_MOVE_1, out_node.GetString("MOVE_ID"), null);
                }
                else if (sStep == '4')
                {
                    PrintLable(sStep, CSGC.CP_LABEL_MOVE_2, "", out_node);
                }
              */
                if(MPCF.Trim(cdvFromOper.Text) == "CW-PRS" ||  MPCF.Trim(cdvFromOper.Text) == "CR-ASM")
                {
                    PrintLable(sStep, CSGC.CP_LABEL_MOVE_2, "", out_node);
                }
                else
                {
                    PrintLable(sStep, CSGC.CP_LABEL_MOVE_1, out_node.GetString("MOVE_ID"), null);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //사업부 옵션체크 함수 => merge여부 
        private bool CheckAreaOption()
        {
            bool bResult = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "TABLE_NAME";
                dvcArgu[1].sCondition_Value = CSGC.CP_GCM_AREA_OPTION;

                dvcArgu[2].sCondition_ID = "KEY_1";
                dvcArgu[2].sCondition_Value = cdvDept.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    bCheckMergeArea = false;
                    bCheckAreaCTM = false;
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    if (dt.Rows[0]["DATA_1"].ToString() == "Y")
                    {
                        bResult = true;
                        bCheckMergeArea = true;
                    }
                    else
                    {
                        bResult = false;
                        bCheckMergeArea = false;
                    }

                    if (dt.Rows[0]["DATA_2"].ToString() == "Y")
                        bCheckAreaCTM = true;
                    else
                        bCheckAreaCTM = false;
                }

                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //To Oper 체크 함수
        private void CheckToOper()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvToOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if (string.Equals(dt.Rows[0]["OPER_GRP_1"].ToString(), "PROD"))
                {
                    s_to_oper_grp = dt.Rows[0]["OPER_GRP_1"].ToString();
                    chkMerge.Checked = false;
                    chkMerge.Visible = false;
                }
                else if (string.Equals(dt.Rows[0]["OPER_GRP_1"].ToString(), "LOSS"))
                {
                    s_to_oper_grp = dt.Rows[0]["OPER_GRP_1"].ToString();
                    chkMerge.Checked = false;
                    chkMerge.Visible = false;
                }
                else
                {
                    s_to_oper_grp = "";

                    if (string.Equals(s_from_oper_grp, "PROD")
                        || string.Equals(s_from_oper_grp, "RET"))
                    {
                        chkMerge.Checked = false;
                        chkMerge.Visible = false;
                    }
                    else
                    {
                        if (bCheckMergeArea == true)
                        {
                            if(bCheckAutoMerge == true)
                                chkMerge.Checked = true;
                            else
                                chkMerge.Checked = false;

                            chkMerge.Visible = true;
                        }
                        else
                        {
                            chkMerge.Checked = false;
                            chkMerge.Visible = false;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //From Oper 체크 함수
        private void CheckFromOper()
        {
            bNoModify = false;
            bCheckAutoMerge = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvFromOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if (string.Equals(dt.Rows[0]["OPER_GRP_1"].ToString(), "PROD")
                    || string.Equals(dt.Rows[0]["OPER_GRP_1"].ToString(), "RET"))
                {
                    s_from_oper_grp = dt.Rows[0]["OPER_GRP_1"].ToString();
                    chkMerge.Checked = false;
                    chkMerge.Visible = false;
                }
                else if (string.Equals(dt.Rows[0]["OPER_GRP_1"].ToString(), "LOSS"))
                {
                    s_from_oper_grp = dt.Rows[0]["OPER_GRP_1"].ToString();
                    chkMerge.Checked = false;
                    chkMerge.Visible = false;
                }
                else
                {
                    s_from_oper_grp = "";

                    if (string.Equals(s_to_oper_grp, "PROD"))
                    {
                        chkMerge.Checked = false;
                        chkMerge.Visible = false;
                    }
                    else
                    {
                        if (bCheckMergeArea == true)
                        {
                            chkMerge.Checked = false;
                            chkMerge.Visible = true;
                        }
                        else
                        {
                            chkMerge.Checked = false;
                            chkMerge.Visible = false;
                        }
                    }
                }

                //특정 공정에서 자동으로 MERGE 체크가 되어 있어야 한다.
                // EX) 그릿의 합성 공정에서 보내는 LOT은 산처리로 이동될때 MERGE되서 보내져야 한다.
                if (chkMerge.Visible == true)
                {
                    if (dt.Rows[0]["AUTO_MERGE_YN"].ToString() == "Y")
                    {
                        chkMerge.Checked = true;
                        bCheckAutoMerge = true;
                    }
                    else
                    {
                        chkMerge.Checked = false;
                        bCheckAutoMerge = false;
                    }
                }

                /* 
                   PRESS 창고에서만 내작으로 갈지 베트남으로 갈지 여부를 체크한다. 
                   해당 체크가 되어 있으면 선택된 LOT에 대해서만 이동지시가 만들어지고
                   체크가 선택되어 있지 않으면, 기존처럼 당일 생산 모든 PRESS LOT이 출력물에 나온다.
                */

                if (dt.Rows[0]["VIEW_PRESS_YN"].ToString() == "Y" && bCheckAreaCTM == true)
                {
                    chkPressDay.Visible = true;
                    chkPressDay.Checked = true;
                }
                else
                {
                    chkPressDay.Visible = false;
                    chkPressDay.Checked = false;
                }

                //이동지시 수정 가능 여부(NO_MODIFY 가 'y'인 경우 해당 공정에서는 이동지시를 수정할 수 없다.)
                if (dt.Rows[0]["NO_MODIFY"].ToString() == "Y")
                {
                    bNoModify = true;
                }
                else
                {
                    bNoModify = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //체크수량확인
        private int CheckCount()
        {
            int iReturnCount = 0;

            try
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iReturnCount++;
                    }
                }

                return iReturnCount;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return iReturnCount;
            }
        }

        private void PrintLable(char sStep, string sPrintLabel, string sMoveID, TRSNode out_node)
        {
            try
            {
                TRSNode print_node = new TRSNode("Print_In");
                TRSNode Print_Lot_list;
                MPCR.SetInMsg(print_node);

                //일반 이동지시
                if (sStep == '1')
                {
                    print_node.AddString("MOVE_ID", sMoveID);
                }
                //CTM press이동지시
                else if (sStep == '4')
                {
                    print_node.AddString("WORK_DATE", dtpWorkDate.Text.Replace("-",""));

                    if (chkPressDay.Visible == true && chkPressDay.Checked == true)
                    {
                        print_node.AddChar("SPLIT_DAY_WORK", 'Y');
                    }

                    for (int i = 0; i < out_node.GetList("MOVE_LIST").Count; i++)
                    {
                        Print_Lot_list = print_node.AddNode("MOVE_LIST");
                        Print_Lot_list.AddString("MOVE_ID", out_node.GetList("MOVE_LIST")[i].GetString("MOVE_ID"));
                    }
                }

                CSCF.ViewLabelList(sPrintLabel, print_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            string sTmp = "";

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                
                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return false;
                //}

                if (MPCF.Trim(cdvFromOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                    cdvFromOper.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;

                    case CSGC.CHECK.SAVE:

                        //if (MPCF.Trim(cdvToWorkPlace.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToWorkPlace.Text + "]");
                        //    cdvToWorkPlace.Focus();
                        //    return false;
                        //}

                        if (MPCF.Trim(cdvToOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        if (spdMoveLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                            return false;
                        }

                        if (string.Equals(cdvFromOper.Text, cdvToOper.Text))
                        {
                            //CMN368 ERROR - 기존 공정과 이동 공정이 같습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(368) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        //merge여부가 Y인 경우 같은 제품만 이동리스트에 있어야 한다.
                        if (chkMerge.Checked == true)
                        {
                            for (int i = 0; i < spdMoveLotList.ActiveSheet.RowCount; i++)
                            {
                                sTmp = spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.MAT_ID].Text;

                                for (int k = 0; k < spdMoveLotList.ActiveSheet.RowCount; k++)
                                {
                                    if (i == k)
                                        continue;

                                    if (spdMoveLotList.ActiveSheet.Cells[k, (int)MOVE_INFO.MAT_ID].Text != sTmp)
                                    {
                                        //CMN420 ERROR - 제품 종류가 다른 Lot은 병합할 수 없습니다.
                                        MPCF.ShowMsgBox(MPCF.GetMessage(420));
                                        return false;
                                    }
                                }
                            }
                        }

                        //HM Sintered-Ground Product창고에서 HM 완제품창고로 이동등록시 Lot번호가 변경되지 않도록 Lock설정요청_ 박병호K
                        //GCM -> C_MOVE_OPTION의 data3(수정 불가여부)에 Y로 기준정보 셋업
                        if (bNoModify == true)
                        {
                            if (MPCF.Trim(sMove_id) != "")
                            {
                                //CMN537 INFO -  선택된 공정에서는 이동지시를 수정할 수 없습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(537));
                                return false;
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

        //클리어 함수
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":

                        MPCF.ClearList(spdMoveLotList);
                        //chkMerge.Checked = false;
                        sMove_id = "";

                        break;

                    case "SAVE":

                        MPCF.ClearList(spdMoveList);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdMoveLotList);

                        sMove_id = "";
                        txtLotID.Text = "";
                        txtMoveOrder.Text = "";
                        cdvToWorkPlace.Text = "";
                        cdvToOper.Text = "";
                        txtSelectCount.Text = "1";
                        chkMerge.Checked = false;

                        break;

                    case "NEW":

                        MPCF.ClearList(spdMoveList);
                        MPCF.ClearList(spdMoveLotList);

                        sMove_id = "";
                        cdvToWorkPlace.Text = "";
                        cdvToOper.Text = "";
                        chkMerge.Checked = false;

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion 

        #region " Event Definition "

        private void frmTranMoveOrderRegistration_Load(object sender, EventArgs e)
        {
            try
            {
                if (CheckAreaOption() == true)
                    chkMerge.Visible = true;
                else
                    chkMerge.Visible = false;

                if (MPCF.Trim(cdvFromOper.Text) == "CW-PRS" || MPCF.Trim(cdvFromOper.Text) ==  "CR-ASM")
                {
                    bCheckCTMPress = true;
                    lblDate.Visible = true;
                    dtpWorkDate.Visible = true;
                    chkPressDay.Visible = true;
                    chkPressDay.Checked = true;
                }
                else
                {
                    bCheckCTMPress = false;
                    lblDate.Visible = false;
                    dtpWorkDate.Visible = false;
                    chkPressDay.Visible = false;
                    chkPressDay.Checked = false;
                }

                // 20.12.21 minjae.go
                MPCF.FitColumnHeader(spdMoveList);
                MPCF.FitColumnHeader(spdLotList);
                MPCF.FitColumnHeader(spdMoveLotList);
                //
                dtpWorkDate.Value = DateTime.Now.AddDays(-1);
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
                if (CheckAreaOption() == true)
                    chkMerge.Visible = true;
                else
                    chkMerge.Visible = false;

                chkMerge.Checked = false;
                chkPressDay.Visible = false;
                chkPressDay.Checked = false;

                cdvWorkPlace.Text = "";
                cdvFromOper.Text = "";
                cdvToWorkPlace.Text = "";
                cdvToOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
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

                cdvFromOper.Init();
                MPCF.InitListView(cdvFromOper.GetListView);
                cdvFromOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFromOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFromOper.SelectedSubItemIndex = 0;
                cdvFromOper.DisplaySubItemIndex = 1;

                

                //20220310 전체 창고 다되도록 변경.... 
                 if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, '7', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvFromOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                CheckFromOper();

                if (MPCF.Trim(cdvFromOper.Text) == "CW-PRS" || MPCF.Trim(cdvFromOper.Text) == "CR-ASM")
                {
                    bCheckCTMPress = true;
                    lblDate.Visible = true;
                    dtpWorkDate.Visible = true;
                    chkPressDay.Visible = true;
                    chkPressDay.Checked = true;
                }
                else
                {
                    bCheckCTMPress = false;
                    lblDate.Visible = false;
                    dtpWorkDate.Visible = false;
                    chkPressDay.Visible = false;
                    chkPressDay.Checked = false;
                }

                MPCF.ClearList(spdMoveList);
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdMoveLotList);
                //From Oper에 따라서 To Oper가 변경되므로 초기화
                cdvToWorkPlace.Text = "";
                cdvToOper.Text = "";
                sMove_id = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvFromOper.Text) == "CW-PRS" || MPCF.Trim(cdvFromOper.Text) == "CR-ASM")
                    bCheckCTMPress = true;
                else
                    bCheckCTMPress = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvToWorkPlace.Init();
                MPCF.InitListView(cdvToWorkPlace.GetListView);
                cdvToWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToWorkPlace.SelectedSubItemIndex = 0;
                cdvToWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvToWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvToWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvToOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                CheckToOper();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvFromOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                    cdvFromOper.Focus();
                    return;
                }

                //if (MPCF.Trim(cdvToWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToWorkPlace.Text + "]");
                //    cdvToWorkPlace.Focus();
                //    return;
                //}

                if (string.Equals(s_from_oper_grp, "LOSS"))
                {
                    cdvToOper.Init();
                    MPCF.InitListView(cdvToOper.GetListView);
                    cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                    cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                    cdvToOper.SelectedSubItemIndex = 0;
                    cdvToOper.DisplaySubItemIndex = 1;


                    //20220310 공정 제약 걸어놓은거.(걸오논 이유 모름) .... 전체 공정으로 바꿈....아.ㅁㄴ아ㅣㅗㅂ댜ㅐㄹㅈ뎌ㅐㅑ로ㅕㅑㅐㅁ

                    // if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'J', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                    if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '7', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                    {
                        return;
                    }
                }
                else
                {
                    cdvToOper.Init();
                    MPCF.InitListView(cdvToOper.GetListView);
                    cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                    cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                    cdvToOper.SelectedSubItemIndex = 0;
                    cdvToOper.DisplaySubItemIndex = 1;

                    //  if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'K', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                    if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '7', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                    {
                        return;
                    }
                }



                cdvToOper.InsertEmptyRow(0, 1);


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResource_ButtonPress(object sender, EventArgs e)
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

                cdvResource.Init();
                MPCF.InitListView(cdvResource.GetListView);
                cdvResource.Columns.Add("Key_1", 50, HorizontalAlignment.Left);
                cdvResource.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResource.SelectedSubItemIndex = 0;
                cdvResource.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceListByGroup(cdvResource.GetListView, CSGC.CP_RESOURCE_GROUP_PRESS, cdvDept.Text) == false)
                    return;

                cdvResource.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdMoveLotList.ActiveSheet.RowCount == 0)
                {
                    //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                    return;
                }

                if(spdMoveList.ActiveSheet.RowCount == 0)
                {
                    //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                    return;
                }

                //임시 무조건
                //PrintLable('1', CSGC.CP_LABEL_MOVE_1, spdMoveList.ActiveSheet.Cells[spdMoveList.ActiveSheet.ActiveRowIndex, (int)MOVE_LIST.MOVE_ORDER_ID].Text, null);

                //라벨 출력
                // if (bCheckCTMPress == false)


               if( MPCF.Trim(cdvFromOper.Text) != "CW-PRS" &&  MPCF.Trim(cdvFromOper.Text) != "CR-ASM")
                {
                    PrintLable('1', CSGC.CP_LABEL_MOVE_1, spdMoveList.ActiveSheet.Cells[spdMoveList.ActiveSheet.ActiveRowIndex, (int)MOVE_LIST.MOVE_ORDER_ID].Text, null);
                }
                else
                {
                    TRSNode out_node = new TRSNode("out_node");
                    TRSNode Print_Lot_list;

                    Print_Lot_list = out_node.AddNode("MOVE_LIST");
                    Print_Lot_list.AddString("MOVE_ID", spdMoveList.ActiveSheet.Cells[spdMoveList.ActiveSheet.ActiveRowIndex, (int)MOVE_LIST.MOVE_ORDER_ID].Text);
                    PrintLable('4', CSGC.CP_LABEL_MOVE_2, "" , out_node);
                }
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;

            /*
            if (MPCF.Trim(cdvToWorkPlace.Text) == "")
            {
                //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + lblToWorkPlace.Text + "]");
                return;
            }
            */

            if (MPCF.Trim(cdvToOper.Text) == "")
            {
                //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + lblToOper.Text + "]");
                return;
            }

            try
            {
                for (int i = spdLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.LOT_ID].Text;

                        for (int k = 0; k < spdMoveLotList.ActiveSheet.RowCount; k++)
                        {
                            if (spdMoveLotList.ActiveSheet.Cells[k, (int)MOVE_INFO.LOT_ID].Text == sTmp)
                                continue;
                        }

                        iRow = spdMoveLotList.ActiveSheet.RowCount;
                        spdMoveLotList.ActiveSheet.RowCount++;

                        spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CHK, true);
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.LOT_ID].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.LOT_ID].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.MAT_ID].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.MAT_ID].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.MAT_DESC].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.MAT_DESC].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.QTY].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.QTY].Value;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.CREATE_DATE].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CREATE_DATE].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.PRESS_RES_ID].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.PRESS_RES_ID].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.PRESS_RES_DESC].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.PRESS_RES_DESC].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.ORDER_ID].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.ORDER_ID].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.CREATE_CODE].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CREATE_CODE].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.CREATE_CODE_DESC].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CREATE_CODE_DESC].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.COMMENT].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.COMMENT].Text;

                        spdLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                spdMoveLotList.ActiveSheet.SortRows((int)MOVE_INFO.LOT_ID, true, false);

                initCheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;

            try
            {
                if (MPCF.Trim(cdvToOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                    cdvToOper.Focus();
                    return;
                }

                for (int i = spdMoveLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.LOT_ID].Text;

                        for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                        {
                            if (spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text == sTmp)
                                continue;
                        }

                        iRow = spdLotList.ActiveSheet.RowCount;
                        spdLotList.ActiveSheet.RowCount++;

                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, false);
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.LOT_ID].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.MAT_ID].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_DESC].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.MAT_DESC].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.QTY].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.QTY].Value;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CREATE_DATE].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.CREATE_DATE].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.PRESS_RES_ID].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.PRESS_RES_ID].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.PRESS_RES_DESC].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.PRESS_RES_DESC].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.ORDER_ID].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.ORDER_ID].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CREATE_CODE].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.CREATE_CODE].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CREATE_CODE_DESC].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.CREATE_CODE_DESC].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.COMMENT].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.COMMENT].Text;

                        spdMoveLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }
                
                spdLotList.ActiveSheet.SortRows((int)LOT_INFO.LOT_ID, true, false);

                initCheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMoveList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdMoveList.ActiveSheet.RowCount; i++)
                {
                    spdMoveList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdMoveList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sMove_id = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.MOVE_ORDER_ID].Text;

                cdvToWorkPlace.Text = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.TO_SUB_AREA_ID].Text;
                cdvToWorkPlace.DisplayText = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.TO_SUB_AREA_DESC].Text;
                cdvToOper.Text = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.TO_OPER].Text;
                cdvToOper.DisplayText = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.TO_OPER_DESC].Text;

                if (spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.MERGE_FLAG].Text == "Y")
                    chkMerge.Checked = true;
                else
                    chkMerge.Checked = false;

                if (MPCF.Trim(sMove_id) != "")
                {
                    ViewMoveLotList(sMove_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtSelectCount_KeyPress(object sender, KeyPressEventArgs e)
        {
            int iCount = 0;
            int iCheckCount = 0;

            try
            {
                if (MPCF.ToInt(txtSelectCount.Text) == 0)
                    return;

                for (int i = 0 ; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, true);

                    iCount++;

                    if (iCount == MPCF.ToInt(txtSelectCount.Text))
                        break;
                }

                iCheckCount = CheckCount();

                txtSelectedCount.Text = iCheckCount.ToString();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            int iCount = 0;

            try
            {
                iCount = CheckCount();

                txtSelectedCount.Text = iCount.ToString();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            int iCount = 0;

            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);

                        iCount = CheckCount();
                        txtSelectedCount.Text = iCount.ToString();

                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMoveLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)MOVE_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdMoveLotList, 0, 0, true, true);
                    }
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
                    /*
                    if (MPCF.Trim(cdvToWorkPlace.Text) == "")
                    {
                        //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + lblToWorkPlace.Text + "]");
                        return;
                    }
                    */

                    if (MPCF.Trim(cdvToOper.Text) == "")
                    {
                        //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + lblToOper.Text + "]");
                        return;
                    }


                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    ViewLotInfo(txtLotID.Text);

                    txtLotID.Focus();
                    txtLotID.SelectAll();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //신규 버튼
        private void btnNew_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("NEW");

                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //조회버튼 클릭
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearData("VIEW");

                ViewMoveList();
                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //저장버튼 클릭
        private void btnProcess_Click(object sender, EventArgs e)
        {
            char c_Step;

            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                /*
                if (bCheckCTMPress == true)
                    c_Step = '4';
                else
                    c_Step = '1';
                */

                if (MPCF.Trim(cdvFromOper.Text) == "CW-PRS" ||  MPCF.Trim(cdvFromOper.Text) == "CR-ASM")
                {
                    c_Step = '4';
                }
                else
                {
                    c_Step = '1';
                }

                if (MoveLot(c_Step, sMove_id))
                {
                    ClearData("SAVE");
                    ViewMoveList();
                    ViewLotList();                    
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //취소버튼 클릭
        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdMoveList.ActiveSheet.RowCount <= 0) return;

                if (CheckCondition(CSGC.CHECK.CANCEL) == false)
                    return;               

                sMove_id = spdMoveList.ActiveSheet.Cells[spdMoveList.ActiveSheet.ActiveRowIndex, (int)MOVE_LIST.MOVE_ORDER_ID].Text;

                if (MoveLot('2', sMove_id))
                {
                    ClearData("SAVE");
                    ViewMoveList();
                    ViewLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        private void spdMoveLotList_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvToOper.Text) == "")
                {
                    //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + lblToOper.Text + "]");
                    return;
                }


                SheetView sv = spdMoveLotList.ActiveSheet;

                if (e.Control && e.KeyCode == Keys.V)
                {
                    int iActiveRow = sv.ActiveRowIndex;


                    //줄바꿈을 자르고 마지막은 빈값이므로 포함안시킴
                    string[] rowSeparators = new string[] { "\r\n" };
                    string sClipboard = Clipboard.GetText();
                    string[] sList = sClipboard.Split(rowSeparators, StringSplitOptions.None);

                    for (int i = 0; i < sList.Length - 1; i++)
                    {
                        if (sv.RowCount > 1000)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(510));//최대 검색개수 1000개를 초과했습니다.
                            return;
                        }
                        else
                        {
                            //이제 열로 구분된 값을 다시 잘라서 각 ROW에 넣어준다.
                            string[] columnSeparators = new string[] { "\t" };
                            string[] sColumnList = sList[i].Split(columnSeparators, StringSplitOptions.None);

                            ViewLotInfo(sColumnList[0]);

                        }
                    }



                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;
        }
    }
}
