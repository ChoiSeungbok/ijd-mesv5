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
            CREATE_DATE             // 6 : 생성일자
        }

        private enum MOVE_INFO
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            CREATE_DATE             // 6 : 생성일자
        }


        #endregion

        #region " Variable Definition "

        string sMove_id = "";
        string s_from_oper_grp = "";
        string s_to_oper_grp = "";
        bool bCheckMergeArea = false;

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
                dvcArgu[3].sCondition_Value = cdvOper.Text;

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "PRESS_RES_ID";
                dvcArgu[2].sCondition_Value = cdvResource.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-002", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
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

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLot_ID);

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
                            continue;
                        }
                    }

                    sOper = out_node.GetList("LOT_TBL")[i].GetString("OPER");
                    if (cdvOper.Text != sOper)
                    {
                        //CMN457 ERROR - 이 LOT은 해당 공정에 존재하지 않습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(457) + " [ " + sOper + " ]");
                        return;
                    }

                    iRow = spdMoveLotList.ActiveSheet.RowCount;

                    spdMoveLotList.ActiveSheet.RowCount++;
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CHK, true);
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CREATE_DATE, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.DATE));

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
                //step 1: 저장 , step 2: 취소
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("TO_SUB_AREA_ID", cdvToWorkPlace.Text);
                in_node.AddString("TO_OPER", cdvToOper.Text);

                if(chkMerge.Visible == true)
                {
                    in_node.AddChar("MERGE_YN", chkMerge.Checked == true ? 'Y' : 'N');
                }
                else
                {
                    in_node.AddChar("MERGE_YN", 'N');
                }

                in_node.AddString("MOVE_ID", sMove_id);

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

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Move_Lot_Order", in_node, ref out_node) == false)
                    return false;
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                    sMove_id = "";
                }

                //라벨 출력
                if (sStep == '1')
                {
                    PrintLable(CSGC.CP_LABEL_MOVE_1, out_node.GetString("MOVE_ID"));
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
                }

                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
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

        private void PrintLable(string sPrintLabel, string sMoveID)
        {
            try
            {
                TRSNode print_node = new TRSNode("Print_In");
                MPCR.SetInMsg(print_node);

                print_node.AddString("MOVE_ID", sMoveID);

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

                        if (MPCF.Trim(cdvToWorkPlace.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToWorkPlace.Text + "]");
                            cdvToWorkPlace.Focus();
                            return false;
                        }

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
                        chkMerge.Checked = false;
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

                cdvToWorkPlace.Text = "";
                cdvToOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'D', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
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

                if (MPCF.Trim(cdvToWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToWorkPlace.Text + "]");
                    cdvToWorkPlace.Focus();
                    return;
                }

                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'D', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
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

                //라벨 출력
                PrintLable(CSGC.CP_LABEL_MOVE_1, spdMoveList.ActiveSheet.Cells[spdMoveList.ActiveSheet.ActiveRowIndex, (int)MOVE_LIST.MOVE_ORDER_ID].Text);
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

                        spdLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                spdMoveLotList.ActiveSheet.SortRows((int)MOVE_INFO.LOT_ID, true, false);
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

                        spdMoveLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }
                
                spdLotList.ActiveSheet.SortRows((int)LOT_INFO.LOT_ID, true, false);
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
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
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
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    ViewLotInfo(txtLotID.Text);
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
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (MoveLot('1', sMove_id))
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
        
        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
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

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if (string.Equals(dt.Rows[0]["OPER_GRP_1"].ToString(), "PROD"))
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
                else
                {
                    s_to_oper_grp = "";
                     
                    if (string.Equals(s_from_oper_grp, "PROD"))
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
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        #endregion

        
    }
}
