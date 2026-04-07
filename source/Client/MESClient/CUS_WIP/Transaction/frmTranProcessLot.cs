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
using Miracom.WIPCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.IO;
using System.IO.Ports;
using RawInput_dll;
using System.Runtime.InteropServices.WindowsRuntime;

namespace CUS_WIP
{
    public partial class frmTranProcessLot : CUS_COM.frmTranForm03
    {
        public frmTranProcessLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKORDER
        {
            ORDER_ID,               // 1 : 작업지시번호
            ORDER_STATUS,           // 2 : 작업지시 상태
            START_DATE,             // 3 : 시작일
            END_DATE,               // 4 : 완료일
            MAT_ID,                 // 5 : 제품코드
            MAT_DESC,               // 6 : 제품명
            UNIT,                   // 7 : 단위
            ORDER_QTY,              // 8 : 지시수량
            IN_QTY,                 // 9 : 투입수량
            PROD_QTY,               //10 : 생산수량
            LOSS_QTY,               //11 : 불량수량
            RWK_IN_QTY,             //12 : 재작업 투입 수량
            RWK_PROD_QTY,           //13 : 재작업 생산 수량
            CREATE_CODE_DESC,       //14 : 작업지시 종류 
            STOCK,                  //15 : 창고
            FLOW,                   //16 : 플로우 
            UNIT_QTY                //17 : LOT 기본 수량
        }

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명            
            PROD_QTY,               // 5 : 생산수량
            GOOD_QTY,               // 6 : 양품수량
            BAD_QTY,                // 7 : 불량수량
            START_TIME,             // 8 : 시작시간
            RES_ID,
            INV_BUTTON,
            OPER,
            COMMENT,
            IN_QTY,
        }

        private enum WORKER_INFO
        {
            CHK,                    // 1 : CHECK
            WORKER,                 // 2 : 이름
            WORKER_ID               // 3 : 사번
        }

        private enum TOOL_INFO
        {
            TOOL_ID,                // 1 : TOOL
            WORK_COUNT,             // 2 : 작업수
            LIMIT_COUNT             // 3 : 한계작업수
        }

        private enum LOSS_INFO
        {
            LOSS_CODE,              // 1 : 불량코드
            LOSS_DESC,              // 2 : 불량명
            LOSS_QTY                // 3 : 불량수량
        }

        #endregion

        #region " Variable Definition "

        string sPrintStartYN = "";
        string sPrintEndYN = "";
        string sPrintLabelID = "";
        string sPrinListName = "";
        bool bCreateLotKey = false;
        bool bOverCreateLot = false;
        bool bValidateNonInputINV = false;
        bool bCheckResTime = false;

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnStart.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnInputMat.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnLotData.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNonOper.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnWorker.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnTranRes.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPress.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnMatSetup.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업지시 조회 함수
        private void ViewOrder()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = cdvOrder.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWorkOrder);
                    return;
                }

                MPCF.ClearList(spdWorkOrder);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkOrder_Sheet1.RowCount++;

                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_STATUS].Value = dt.Rows[i]["STATUS_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.START_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.END_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.IN_QTY].Value = dt.Rows[i]["OPER_IN_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.LOSS_QTY].Value = dt.Rows[i]["OPER_LOSS_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.RWK_IN_QTY].Value = dt.Rows[i]["RWK_IN_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.RWK_PROD_QTY].Value = dt.Rows[i]["RWK_OUT_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                }
                MPCF.FitColumnHeader(spdWorkOrder);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업자 조회 함수
        private void ViewWorkerList()
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

                dvcArgu[4].sCondition_ID = "WORKER_GROUP";
                dvcArgu[4].sCondition_Value = cdvWorkGroup.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWorkerList);
                    return;
                }

                MPCF.ClearList(spdWorkerList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.SetValue(i, (int)WORKER_INFO.CHK, false);
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER].Value = dt.Rows[i]["WORKER"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                }
                MPCF.FitColumnHeader(spdWorkerList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Tool정보 조회 함수
        private void ViewToolList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "RES_ID";
                dvcArgu[1].sCondition_Value = cdvResource.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2001-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdToollist);
                    return;
                }

                MPCF.ClearList(spdToollist);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdToollist_Sheet1.RowCount++;

                    spdToollist_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    spdToollist_Sheet1.Cells[i, (int)TOOL_INFO.WORK_COUNT].Value = dt.Rows[i]["WORK_COUNT"];
                    spdToollist_Sheet1.Cells[i, (int)TOOL_INFO.LIMIT_COUNT].Value = dt.Rows[i]["LIMIT_COUNT"];

                }
                MPCF.FitColumnHeader(spdToollist);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Loss정보 조회 함수
        private void ViewLossList(string sLotID)
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

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = sLotID;

                if (TPDR.GetDataOne("", ref dt, "CWIP2001-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLossList);
                    return;
                }

                MPCF.ClearList(spdLossList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLossList_Sheet1.RowCount++;

                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];

                }
                MPCF.FitColumnHeader(spdLossList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LOT ID, 묶음번호, cell ID 인지 판단하여 해당 리스트를 리턴한다.
        private void ViewLotInfo(string sLot_ID)
        {
            string sLotId = "";
            int iRow = 0;
            bool bContinueFlag = false;
            string sTmp = "";
            string sConName = "";

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLot_ID);
                in_node.AddString("OPER", cdvOper.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    txtLotID.Text = "";
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    bContinueFlag = false;



                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text)
                        {
                            bContinueFlag = true;
                            break;
                        }
                    }
                    //20230223 추가 다른작지 검사진행중인거를 끌고오는경우있어서 추가
                    if (out_node.GetString("OPER_OPTION_2") == "N")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(112)); // CMN112 ERROR - 이 Lot은 Start 시킬수 있는 상태가 아닙니다.
                        txtLotID.Text = "";
                        return;
                    }



                    if (spdLotList.ActiveSheet.RowCount > 0)
                    {
                        if (spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.OPER].Text != out_node.GetList("LOT_TBL")[i].GetString("OPER"))
                        {
                            //CMN457 ERROR - 이 LOT은 해당 공정에 존재하지 않습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(457));
                            txtLotID.Text = "";
                            return;
                        }
                    }

                    if (out_node.GetString("OPER_OPTION_1") != "Y")
                    {
                        if (spdLotList.ActiveSheet.RowCount == 0)
                        {
                            cdvDept.Text = out_node.GetList("LOT_TBL")[0].GetString("AREA_ID");
                            cdvDept.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("AREA_DESC");
                            cdvWorkPlace.Text = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_ID");
                            cdvWorkPlace.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_DESC");
                            cdvOper.Text = out_node.GetList("LOT_TBL")[0].GetString("OPER");
                            cdvOper.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("OPER_DESC");
                            cdvOrder.Text = out_node.GetList("LOT_TBL")[0].GetString("ORDER_ID");
                            txtComment.Text = out_node.GetList("LOT_TBL")[0].GetString("COMMENT");

                            if (out_node.GetList("LOT_TBL")[i].GetString("START_TIME") != "")
                            {
                                cdvResource.Text = out_node.GetList("LOT_TBL")[0].GetString("RES_ID");
                                cdvResource.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("RES_DESC");
                            }
                            else
                            {
                                cdvResource.Text = "";
                            }
                        }
                    }

                    if (bContinueFlag == true)
                        continue;

                    iRow = spdLotList.ActiveSheet.RowCount;

                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.GOOD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1") - out_node.GetList("LOT_TBL")[i].GetDouble("LOSS_QTY"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.BAD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("LOSS_QTY"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.START_TIME, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.IN_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.COMMENT, out_node.GetList("LOT_TBL")[i].GetString("COMMENT"));


                    if (MPCF.Trim(out_node.GetList("LOT_TBL")[i].GetString("START_TIME")) != "")
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.RES_ID, out_node.GetList("LOT_TBL")[i].GetString("RES_DESC"));
                    else
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.RES_ID, "");

                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER"));
                }



                /*
                //CMF17 작업시작(착공시간가져오도록)... 이부분은 아래와 같이 되도록 따로 코등(20220525)
                if (grpLotAddInfo.Visible == true)
                {
                    //커스텀 컨트롤인 경우
                    foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                    {
                        if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView ||
                            ctr is System.Windows.Forms.DateTimePicker)
                        {
                            // 현재 보여지는 컨트롤만 in_node에 담는다.
                            if (ctr.Visible == true)
                            {

                                if (ctr is System.Windows.Forms.DateTimePicker)
                                {
                                    if (ctr.Tag != null && ctr.Tag.ToString() != "")
                                    {


                                        Control ctr1 = new Control();

                                        sConName = ctr.Name;
                                        sConName = sConName.Replace("dtpDate", "dtpTime");
                                        ctr1 = CUS_WIP.Controls.udcAddLotControl.Gf_Get_DateTimePicker_By_Name(sConName, grpLotAddInfo);

                                        if (ctr.Tag.ToString() == "LOT_CMF_17")
                                        {

                                            ctr.Text = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[0].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME);
                                            ctr1.Text = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[0].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME);

                                        }
                                        else
                                        {
                                            ctr.Text = MPCF.MakeDateFormat("0");
                                            ctr1.Text = MPCF.MakeDateFormat("0");
                                        }
                                    }
                                }


                            }
                        }
                    }
                }
                */


                // 첫번째 LOT의 정보를 보여주도록 수정 할 것.
                if (grpLotAddInfo.Visible == true)
                {
                    //첫번째 LOT이 시작되어 있지 않은경우 그룹 id의 저장되어 있는 값을 가져온다. 
                    if (MPCF.Trim(out_node.GetList("LOT_TBL")[0].GetString("START_TIME")) == "")
                    {
                        //커스텀 컨트롤인 경우
                        foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                        {
                            if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView ||
                                ctr is System.Windows.Forms.DateTimePicker)
                            {
                                if (ctr.Visible == true)
                                {
                                    for (int k = 0; k < out_node.MemberCount; k++)
                                    {
                                        if (out_node.Members[k].Name.Contains("CMF"))
                                        {
                                            if (out_node.Members[k].Name == ctr.Tag.ToString())
                                            {
                                                ctr.Text = out_node.Members[k].Value;

                                                if (((Miracom.UI.Controls.MCCodeView.MCCodeView)ctr).VisibleButton == true)
                                                {
                                                    sTmp = ctr.Tag.ToString() + "_DESC";
                                                    ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctr).DisplayText = out_node.GetString(sTmp);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //첫번째 LOT이 시작되어 있는경우 시작시 등록하였던 값을 가져온다.
                    else
                    {
                        //커스텀 컨트롤인 경우
                        foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                        {
                            if (ctr.Visible == true)
                            {
                                for (int k = 0; k < out_node.GetList("LOT_TBL")[0].MemberCount; k++)
                                {
                                    if (out_node.GetList("LOT_TBL")[0].Members[k].Name.Contains("CMF"))
                                    {
                                        if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView)
                                        {
                                            if (out_node.GetList("LOT_TBL")[0].Members[k].Name == ctr.Tag.ToString())
                                            {
                                                ctr.Text = out_node.GetList("LOT_TBL")[0].Members[k].Value;

                                                if (((Miracom.UI.Controls.MCCodeView.MCCodeView)ctr).VisibleButton == true)
                                                {
                                                    sTmp = ctr.Tag.ToString() + "_DESC";
                                                    ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctr).DisplayText = out_node.GetList("LOT_TBL")[0].GetString(sTmp);
                                                }
                                            }
                                        }
                                        else if (ctr is System.Windows.Forms.DateTimePicker)
                                        {
                                            if (ctr.Tag != null && ctr.Tag.ToString() != "")
                                            {



                                                Control ctr1 = new Control();

                                                sConName = ctr.Name;
                                                sConName = sConName.Replace("dtpDate", "dtpTime");
                                                ctr1 = CUS_WIP.Controls.udcAddLotControl.Gf_Get_DateTimePicker_By_Name(sConName, grpLotAddInfo);

                                                if (ctr.Tag.ToString() == "LOT_CMF_17")
                                                {

                                                    ctr.Text = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[0].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME);
                                                    ctr1.Text = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[0].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME);

                                                }
                                                else
                                                {
                                                    ctr.Text = MPCF.MakeDateFormat("0");
                                                    ctr1.Text = MPCF.MakeDateFormat("0");
                                                }


                                                /*
                                                if (out_node.GetList("LOT_TBL")[0].Members[k].Name == ctr.Tag.ToString())
                                                {
                                                    if (out_node.GetList("LOT_TBL")[0].Members[k].Value.ToString() != "")
                                                    {
                                                        ((System.Windows.Forms.DateTimePicker)ctr).Value = MPCF.ToDate(out_node.GetList("LOT_TBL")[0].Members[k].Value);
                                                        Control ctr1 = new Control();
                                                        sConName = ctr.Name;
                                                        sConName = sConName.Replace("dtpDate", "dtpTime");
                                                        
                                                        ctr1 = CUS_WIP.Controls.udcAddLotControl.Gf_Get_DateTimePicker_By_Name(sConName, grpLotAddInfo);
                                                        ((System.Windows.Forms.DateTimePicker)ctr1).Value = MPCF.ToDate(out_node.GetList("LOT_TBL")[0].Members[k].Value);
                                                    }
                                                }
                                                */



                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }



                MPCF.FitColumnHeader(spdLotList);

                //lot id 텍스트 초기화
                txtLotID.Text = "";
                LotCheckCount();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //불량정보 등록 함수
        private bool SaveLossData()
        {
            try
            {
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode loss_list;

                double d_loss_qty = 0;
                double d_prod_qty = 0;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);
                //in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("CUASE_OPER", cdvCauseOper.Text);
                in_node.AddString("RES_ID", cdvResource.Text);

                for (int i = 0; i < spdLossList.ActiveSheet.RowCount; i++)
                {
                    if (MPCF.ToDbl(spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                    {
                        loss_list = in_node.AddNode("LOSS_TBL");
                        loss_list.AddString("CODE", spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_CODE].Text);
                        loss_list.AddDouble("VALUE", spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text);
                        loss_list.AddChar("QTY_FLAG", '1');

                        d_loss_qty += MPCF.ToDbl(spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value);
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Loss", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                d_prod_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Value);

                spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.BAD_QTY, d_loss_qty);
                spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.GOOD_QTY, d_prod_qty - d_loss_qty);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



        private bool InputBomCheck()
        {
            try
            {
                TRSNode in_node = new TRSNode("GCM_CHK_IN");
                TRSNode out_node = new TRSNode("GCM_CHK_OUT");
                string sBOmpopYn = "N";
                string sSqlLot = "";




                out_node = new TRSNode("BAS_SQL_Query_In");
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("SQL", string.Format("SELECT DATA_2 FROM MGCMTBLDAT WHERE FACTORY = '{0}' AND TABLE_NAME = '{1}' AND KEY_1 ='{2}'", MPGV.gsFactory, "C_BOM_CHK_OPER", cdvOper.Text));
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return true;
                }

                if (out_node.GetList("ROWS").Count == 0)
                {
                    return true;
                }

                if (out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA") == "Y")
                {

                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                    DataTable dt = null;
                    string sSql = "";
                    int i = 0;


                    for (int iRow = 0; iRow < spdLotList.ActiveSheet.RowCount; iRow++)
                    {
                        if (spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                        {
                            sSqlLot = sSqlLot + "'" + spdLotList_Sheet1.Cells[iRow, 1].Value + "',";
                        }
                    }


                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                    dvcArgu[1].sCondition_ID = "ORDER_ID";
                    dvcArgu[1].sCondition_Value = cdvOrder.Text;


                    dvcArgu[2].sCondition_ID = "OPER";
                    dvcArgu[2].sCondition_Value = cdvOper.Text;


                    dvcArgu[3].sCondition_ID = "PROD_QTY";
                    dvcArgu[3].sCondition_Value = Convert.ToDouble(spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Text);
                    // dvcArgu[3].sCondition_Type = "Double";

                    dvcArgu[4].sCondition_ID = "LOT_ID_QUERY";
                    dvcArgu[4].sCondition_Value = sSqlLot;
                    dvcArgu[4].sCondition_Type = "TEXT";

                    if (TPDR.GetDataOne("", ref dt, "CWIP0001-008", dvcArgu, false, false, ref sSql) == false)
                    {
                        return true;
                    }
                    else
                    {
                        for (i = 0; i < dt.Rows.Count; i++)
                        {

                            if (dt.Rows[i]["QTY_CHK"].ToString() == "Y")
                            {
                                sBOmpopYn = "Y";
                            }
                        }
                    } 
                }
                else
                {
                    sBOmpopYn = "Y";
                }

                


                if(sBOmpopYn == "Y")
                {




                    if (spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Text == "0")
                    {
                        return false;
                    }


                    //sSqlLot = sSqlLot + "''";


                    frmTranInputCheck popup2 = new frmTranInputCheck();

                    popup2.C_ORDER_ID = cdvOrder.Text;
                    popup2.C_OPER = cdvOper.Text;
                    popup2.C_PROD_QTY = spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Text;
                    popup2.C_LOT_ID = sSqlLot;

                    if (popup2.ShowDialog() == DialogResult.OK)
                    {
                        return true;
                    }
                    else
                    {
                        return false;

                    }

                }
                else
                {
                    return true;
                }



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



        //작업 시작/종료 = > step 1 : 시작 , step 2 : 완료 
        private bool SaveProcess(char c_step)
        {
            int iRow = 0;
            bool bPrint = false;
            string sConName = "";

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;
                TRSNode Worker_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddString("RES_ID", cdvResource.Text);
                in_node.AddString("COMMENT", txtComment.Text);
                in_node.AddString("TO_OPER", cdvToOper.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {

                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        //CTM 전처리에서 수량이 계속 누략되는 현상 발생 원인 확인차 이단 임시로 코딩(현장에서는 불량수량만 입력 수량을 수기입력안한다고 함.
                        if (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text) < MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.IN_QTY].Text))
                        {

                            MPCF.ShowMsgBox("수량이 작아질수는 없습니다.(The quantity cannot be increased.)");
                            return false;
                        }

                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        Lot_list.AddDouble("GOOD_QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GOOD_QTY].Text));
                        Lot_list.AddDouble("LOSS_QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.BAD_QTY].Text));


                        //20220221 LOT별로 입력 가능하도록 수정.
                        if (rdoAll.Checked)
                        {
                            Lot_list.AddString("COMMENT", txtComment.Text);
                        }
                        else
                        {
                            Lot_list.AddString("COMMENT", MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.COMMENT].Text));
                        }


                    }
                }

                //C_OPER_OPTION의 DATA_9에 Y인 경우(그릿의 추가 문자 포함)인 경우 
                if (panCreateKey.Visible == true)
                {
                    in_node.AddString("CREATE_LOT_KEY", cdvLotKey.Text);
                }

                //LOT 추가 데이터가 있는 경우 각 컨트롤의 TAG 값(테이블 컬럼명)과 TEXT값을 in_node에 담아 서버에 보낸다.
                if (grpLotAddInfo.Visible == true)
                {
                    //커스텀 컨트롤인 경우
                    foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                    {
                        if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView ||
                            ctr is System.Windows.Forms.DateTimePicker)
                        {
                            // 현재 보여지는 컨트롤만 in_node에 담는다.
                            if (ctr.Visible == true)
                            {
                                if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView)
                                    in_node.AddString(ctr.Tag.ToString(), ctr.Text);
                                else
                                {
                                    if (ctr is System.Windows.Forms.DateTimePicker)
                                    {
                                        if (ctr.Tag != null && ctr.Tag.ToString() != "")
                                        {
                                            Control ctr1 = new Control();

                                            sConName = ctr.Name;
                                            sConName = sConName.Replace("dtpDate", "dtpTime");
                                            ctr1 = CUS_WIP.Controls.udcAddLotControl.Gf_Get_DateTimePicker_By_Name(sConName, grpLotAddInfo);

                                            in_node.AddString(ctr.Tag.ToString(), ctr.Text.Replace("-", "") + ctr1.Text.Replace(":", "") + "00");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                //작업자 리스트
                for (int k = 0; k < spdWorkerList.ActiveSheet.RowCount; k++)
                {
                    if (spdWorkerList.ActiveSheet.Cells[k, (int)WORKER_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Worker_list = in_node.AddNode("WORKER_TBL");
                        Worker_list.AddString("WORKER_ID", spdWorkerList.ActiveSheet.Cells[k, (int)WORKER_INFO.WORKER_ID].Text);
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Process_Lot", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                //저장 후 로직
                if (c_step == '1')
                {
                    MPCF.ClearList(spdLotList);

                    //시작 처리된 lot id를 받아 화면에 보이게 해준다.
                    for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                    {
                        iRow = spdLotList.ActiveSheet.RowCount;

                        spdLotList.ActiveSheet.RowCount++;
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.GOOD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.BAD_QTY, 0);
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.START_TIME, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME));
                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.RES_ID, out_node.GetList("LOT_TBL")[i].GetString("RES_DESC"));

                    }

                    if (CheckPrintOption(cdvOper.Text, cdvOrder.Text))
                    {
                        if (sPrintStartYN == "Y")
                            bPrint = true;
                    }
                }
                else if (c_step == '2')
                {
                    if (CheckPrintOption(cdvOper.Text, cdvOrder.Text))
                    {
                        if (sPrintEndYN == "Y")
                            bPrint = true;
                    }
                }

                //프린트 공정인 경우 프린트 한다.
                if (bPrint == true)
                {
                    PrintLable(sPrintLabelID, sPrinListName, out_node.GetString("GROUP_ID"));
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iLotCount = 0;
            int iWorkerCount = 0;
            double dOrderQty = 0;
            double dCreateQty = 0;
            double dProdQty = 0;
            string stmp = "";

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
                    case CSGC.CHECK.START:

                        if (MPCF.Trim(cdvOrder.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                            cdvOrder.Focus();
                            return false;
                        }

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        //MFO에 설비가 등록되어 있는 공정인지 체크한다.
                        if (CheckOperResource(cdvOper.Text) > 0)
                        {
                            if (MPCF.Trim(cdvResource.Text) == "")
                            {
                                //CMN428 CONFIRM - 설비 정보가 입력되지 않았습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(428));
                                cdvResource.Focus();
                                return false;
                            }
                        }

                        if (panCreateKey.Visible == true)
                        {
                            //CMN530 INFO -  Lot뒤 문자 등록 여부  확인하세요. 계속 진행 하시겠습니까?
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(530), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                            {
                                return false;
                            }
                        }

                        //작업지시 대비 lot 수량이 많은지 여부를 체크한다. 
                        //bOverCreateLot 체크 공정에서는 작업지시수량보다 수량이 오버되게 lot을 생성할 수 없다.
                        if (bOverCreateLot == true)
                        {
                            dProdQty = 0;
                            dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.ORDER_QTY].Text);
                            dCreateQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.IN_QTY].Text);

                            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                            {
                                dProdQty = dProdQty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);
                            }

                            if (dOrderQty < dProdQty + dCreateQty)
                            {
                                //CMN538 INFO -  해당 공정에서는 작업지시 수량보다 생성수량이 많을 수 없습니다. 생성 수량을 확인하세요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(538));
                                return false;
                            }
                        }

                        break;

                    case CSGC.CHECK.END:

                        //to oper 체크가 되어 있는경우 다음 공정을 지정해 줘야 한다.
                        if (chkToOper.Checked == true)
                        {
                            //to_oper 체크
                            if (MPCF.Trim(cdvToOper.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + chkToOper.Text + "]");
                                cdvToOper.Focus();
                                return false;
                            }
                        }

                        //lot 체크
                        if (MPCF.Trim(cdvOrder.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                            cdvOrder.Focus();
                            return false;
                        }

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpLotInfo.Text + "]");
                            return false;
                        }

                        //작업자 체크
                        for (int i = 0; i < spdWorkerList.ActiveSheet.RowCount; i++)
                        {
                            if (spdWorkerList.ActiveSheet.Cells[i, (int)WORKER_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iWorkerCount++;
                        }

                        if (iWorkerCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpWorkerInfo.Text + "]");
                            return false;
                        }

                        //MFO에 설비가 등록되어 있는 공정인지 체크한다.
                        if (CheckOperResource(cdvOper.Text) > 0)
                        {
                            if (MPCF.Trim(cdvResource.Text) == "")
                            {
                                //CMN428 CONFIRM - 설비 정보가 입력되지 않았습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(428));
                                cdvResource.Focus();
                                return false;
                            }
                        }

                        //자재 투입 여부를 체크한다.
                        //bom에 등록된 자재가 일치하는지 여부를 확인 후 진행 여부를 물어본다. 
                        if (bValidateNonInputINV == true)
                        {
                            if (spdLotList.ActiveSheet.RowCount > 0)
                                stmp = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.LOT_ID].Text;

                            //자재 투입이 되었는지 체크하는 함수 
                            if (CheckInputMaterial(cdvOper.Text, cdvOrder.Text, stmp) == false)
                            {
                                //CMN539 INFO -  미투입 자재가 존재합니다. 계속 진행하시겠습니까?
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(539), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                                {
                                    return false;
                                }
                            }
                        }

                        //특정공정에 대해 설비 시간 등록 여부를 체크한다.
                        //열처리로, 디왁싱 공정인 경우 설비 가동 시간을 등록하게 한다. 등록 확인 여부를 체크 한다. 
                        //설비 데이터를 lot단위가 아니라 시간단위로 받기 때문에 시간 조정이 필요함. _20210818_lwg -> 이명재 차장 요청
                        if (bCheckResTime == true)
                        {
                            if (grpLotAddInfo.Visible == true)
                            {
                                foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                                {
                                    if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView)
                                    {
                                        //3번째 컨트롤에 설비시간 등록 확인여부를 확인한다. 
                                        if (ctr.Name == "cdvsts3" && ctr.Visible == true)
                                        {
                                            if (ctr.Text != "Y")
                                            {
                                                //CMN552 INFO - 설비시간 등록 확인 체크가 안되었습니다. 설비 시간등록 확인 체크를 해주세요.
                                                MPCF.ShowMsgBox(MPCF.GetMessage(552));
                                                ctr.Focus();
                                                return false;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        break;

                    case CSGC.CHECK.SAVE:

                        if (MPCF.Trim(cdvCauseOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCauseOper.Text + "]");
                            cdvCauseOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.START_TIME].Text) == "")
                        {
                            //CMN469 INFO - 불량 저장은 LOT이 시작된 이후에 등록 되어야 합니다. LOT 상태를 확인하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(469));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.ADD:

                        if (spdWorkOrder.ActiveSheet.RowCount == 0)
                        {
                            //CMN452 CONFIRM  - 선택된 작업지시가 없습니다. 작업지시를 선택하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(452));
                            return false;
                        }

                        //UNIT_QTY 수량이 0이 아닌경우 자동으로 UNIT 수량만큼 ADD되도록 하기 위해_20210401_LWG
                        if (MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.UNIT_QTY].Text) == 0)
                        {
                            if (MPCF.Trim(txtProdQty.Text) == "" || MPCF.ToDbl(txtProdQty.Text) == 0)
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblProdQty.Text + "]");
                                txtProdQty.Focus();
                                return false;
                            }
                        }

                        //작업지시 대비 lot 수량이 많은지 여부를 체크한다. 
                        //bOverCreateLot 체크 공정에서는 작업지시수량보다 수량이 오버되게 lot을 생성할 수 없다.
                        if (bOverCreateLot == true)
                        {
                            dProdQty = 0;
                            dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.ORDER_QTY].Text);
                            dCreateQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.IN_QTY].Text);

                            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                            {
                                dProdQty = dProdQty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);
                            }

                            if (dOrderQty <= dProdQty + dCreateQty + MPCF.ToDbl(txtProdQty.Text))
                            {
                                //CMN538 INFO -  해당 공정에서는 작업지시 수량보다 생성수량이 많을 수 없습니다. 생성 수량을 확인하세요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(538));
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

        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ORDER":

                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdLotList);
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.GOOD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.BAD_QTY].Value = 0;
                        cdvLotKey.Text = "";


                        break;

                    case "RESOURCE":

                        MPCF.ClearList(spdToollist);

                        break;

                    case "WORKER":

                        MPCF.ClearList(spdWorkerList);

                        break;

                    case "OPER":

                        MPCF.ClearList(spdLossList);
                        MPCF.ClearList(spdWorkerList);
                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdLotList);
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.GOOD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.BAD_QTY].Value = 0;
                        txtLotID.Text = "";
                        cdvLotKey.Text = "";

                        break;

                    case "LOSS":

                        MPCF.ClearList(spdLossList);

                        break;

                    case "END":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLossList);
                        MPCF.ClearList(spdWorkerList);
                        MPCF.ClearList(spdToollist);

                        txtLotID.Text = "";
                        txtComment.Text = "";
                        cdvLotKey.Text = "";
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.GOOD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.BAD_QTY].Value = 0;

                        //lot 추가정보 부분
                        MPCF.FieldClear(grpLotAddInfo);
                        txtLotID.Focus();

                        break;

                    case "ALL":

                        cdvOrder.Text = "";
                        cdvResource.Text = "";
                        cdvWorkGroup.Text = "";
                        txtComment.Text = "";
                        cdvLotKey.Text = "";

                        //MPCF.FieldClear(grpLotAddInfo);
                        MPCF.FieldClear(panLotInfo);
                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdToollist);
                        MPCF.ClearList(spdLossList);

                        //lot 추가정보 부분
                        MPCF.FieldClear(grpLotAddInfo);
                        txtLotID.Focus();
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.GOOD_QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.BAD_QTY].Value = 0;

                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //공정 데이터 체크
        private bool CheckOperData(string sOper)
        {
            bool bResult = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                if (dt.Rows.Count > 0)
                    bResult = true;

                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //공정 옵션 조회
        private void CheckOperOption(string sArea_id, string sSubArea_id, string sOper)
        {
            try
            {
                bCreateLotKey = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_id;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = sSubArea_id;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                if (dt.Rows.Count > 0)
                {
                    //create lot key 가능 공정
                    if (dt.Rows[0]["ADD_CREATE_LOT_KEY_OPER"].ToString() == "Y")
                    {
                        bCreateLotKey = true;
                    }
                    else
                        bCreateLotKey = false;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //공정 벨리데이션 조회
        private void CheckOperValidation(string sOper)
        {
            bOverCreateLot = false;
            bValidateNonInputINV = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                if (dt.Rows.Count > 0)
                {
                    //작업지시 수량 over되는지 여부 체크 
                    //작지대비 10% 이상 열어놓았지만 특정공정은 타이트하게 관리 필요하여
                    if (dt.Rows[0]["OVER_ORDER"].ToString() == "Y")
                        bOverCreateLot = true;
                    else
                        bOverCreateLot = false;

                    //특정공정에 대해 자재 투입여부를 체크한다.
                    if (dt.Rows[0]["CHECK_INPUT_LOT"].ToString() == "Y")
                        bValidateNonInputINV = true;
                    else
                        bValidateNonInputINV = false;

                    //특정공정에 대해 설비 시간 등록 여부를 체크한다.
                    if (dt.Rows[0]["CHECK_RES_TIME"].ToString() == "Y")
                        bCheckResTime = true;
                    else
                        bCheckResTime = false;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private bool CheckInputMaterial(string sOper, string sOrder, string sLotId)
        {
            bool bResult = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOper;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = sOrder;

                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = sLotId;

                if (TPDR.GetDataOne("", ref dt, "CWIP2001-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    if (MPCF.ToInt(dt.Rows[0]["NOT_IN_MAT_COUNT"].ToString()) == 0)
                        bResult = true;
                    else
                        bResult = false;
                }
                else
                    bResult = false;

                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        //레시피 전공 공정 체크
        private bool CheckResTransferCheck(string sOper)
        {
            bool bResult = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2001-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                if (dt.Rows.Count > 0)
                    bResult = true;

                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //프린팅 여부 체크 
        private bool CheckPrintOption(string sOper, string sOrder)
        {
            sPrintStartYN = "";
            sPrintEndYN = "";
            sPrintLabelID = "";
            sPrinListName = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = sOrder;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    sPrintStartYN = dt.Rows[0]["START_YN"].ToString();
                    sPrintEndYN = dt.Rows[0]["END_YN"].ToString();
                    sPrintLabelID = dt.Rows[0]["LABLE_ID"].ToString();
                    sPrinListName = dt.Rows[0]["LIST_TYPE"].ToString();
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //프린팅 함수
        private void PrintLable(string sPrintLabel, string sPrinListName, string sGroup_id = "")
        {
            try
            {
                TRSNode print_node = new TRSNode("Print_In");
                TRSNode Print_Lot_list;
                MPCR.SetInMsg(print_node);

                if (sPrinListName == "LOT_LIST")
                {
                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                        {
                            Print_Lot_list = print_node.AddNode(sPrinListName);
                            Print_Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        }
                    }
                }
                else if (sPrinListName == "GROUP_LIST")
                {
                    if (sGroup_id == "")
                    {
                        //CMN466 INFO - 리스트가 존재하지 않습니다. 확인해주세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(466));
                        return;
                    }

                    Print_Lot_list = print_node.AddNode(sPrinListName);
                    Print_Lot_list.AddString("GROUP_ID", sGroup_id);
                }

                CSCF.ViewLabelList(sPrintLabel, print_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void LotCheckCount()
        {
            double dSumProd = 0;
            double dSumGood = 0;
            double dSumLoss = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;

                        dSumProd = dSumProd + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);
                        dSumGood = dSumGood + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GOOD_QTY].Text);
                        dSumLoss = dSumLoss + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.BAD_QTY].Text);
                    }
                }

                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = iCount;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = dSumProd;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.GOOD_QTY].Value = dSumGood;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.BAD_QTY].Value = dSumLoss;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //공정별 설비 유무 체크
        private int CheckOperResource(string sOper)
        {
            int iResult = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return iResult;
                }

                if (dt.Rows.Count > 0)
                {
                    iResult = MPCF.ToInt(dt.Rows[0]["RES_COUNT"].ToString());
                }

                return iResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return iResult;
            }
        }

        public bool Clipboard_to_LotList(string pClipboard)
        { 
            // bool bResult = false;

            try
            {
                // Row Data를 담기위해 List<T> 컬렉션 선언
                List<List<string>> tables = new List<List<string>>();

                // 줄바꿈 기준으로 Split
                string importText = pClipboard;
                string[] plines = importText.Split('\n');


                // Split 된 문자만큼 반복
                for (int i = 0; i < plines.Length - 1; i++)
                {
                    // 없다면 빠져나감
                    if (string.IsNullOrEmpty(plines[i]))
                        break;

                    // 임시로 String을 담을 List<T> 선언
                    List<string> cellList = new List<string>();
                    string[] cells = plines[i].Split('\t');

                    for (int j = 0; j <= cells.Length - 1; j++)
                    {
                        cells[j] = cells[j].Replace(Environment.NewLine, string.Empty);
                    }
                    // 임시 List<T>에 값을 담고, 담아진 List를 
                    cellList.AddRange(cells);
                    // List 배열에 List를 Add한다.
                    tables.Add(cellList);
                }

                // bResult = true;
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

        private void frmTranProcessLot_Load(object sender, EventArgs e)
        {
            string[] s_port;
            bool bSkip = false;

            try
            {
                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    cdvOper_SelectedItemChanged(sender, null);
                }

                chkToOper.Checked = false;
                cdvToOper.Enabled = false;
                cdvToOper.Text = "";

                s_port = SerialPort.GetPortNames();
                //cboPort.Items.Clear();
                for (int i = 0; i < s_port.Length; i++)
                {
                    bSkip = false;

                    for (int k = 0; k < cboPort.Items.Count; k++)
                    {
                        if (cboPort.Items[k].ToString() == s_port[i])
                        {
                            bSkip = true;
                            break;
                        }
                    }

                    if (bSkip != true)
                    {
                        cboPort.Items.Add(s_port[i]);
                    }
                }
                cboPort.Items.Add("");

                rh_Sanner = new ReceivedHandler(rhText);

                if (cboPort.Text != "")
                {
                    Open_Port(cboPort.Text, 'N');
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.Trim(cdvOrder.Text) != "")
                    {
                        //작업지시 변경시 LOT 목록을 지운다.
                        MPCF.ClearList(spdLotList);

                        ViewOrder();
                    }
                    else
                    {
                        ClearList("ORDER");
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOrder.Text) != "")
                {
                    //작업지시 변경시 LOT 목록을 지운다.
                    MPCF.ClearList(spdLotList);

                    ViewOrder();
                }
                else
                {
                    ClearList("ORDER");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkGroup_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWorkGroup.Init();
                MPCF.InitListView(cdvWorkGroup.GetListView);
                cdvWorkGroup.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkGroup.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkGroup.SelectedSubItemIndex = 0;
                cdvWorkGroup.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvWorkGroup.GetListView, '1', CSGC.CP_GCM_WORKER_GROUP) == false)
                {
                    return;
                }

                cdvWorkGroup.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업자 그룹을 선택시 작업자 리스트를 조회한다. 
        private void cdvWorkGroup_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkGroup.Text) != "")
                    ViewWorkerList();
                else
                    ClearList("WORKER");

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //조회조건 설비 변경 시 Tool 정보 조회한다. 
        private void cdvResource_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvResource.Text) != "")
                    ViewToolList();
                else
                    ClearList("RESOURCE");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //공정 조회조건을 변경시 각 공정에 맞는 불량 코드 리스트를 조회한다.
        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearList("OPER");

                if (MPCF.Trim(cdvOper.Text) != "")
                    ViewLossList("");

                cdvCauseOper.Text = cdvOper.Text;
                cdvCauseOper.DisplayText = cdvOper.DisplayText;

                //공정 데이터 입력이 있는지 여부를 확인하여 공정 데이터 입력이 있는경우 하단 그룹판넬을 VISIBLE 해주면서 컨트롤을 나오게 한다.
                if (CheckOperData(cdvOper.Text) == true)
                {
                    grpLotAddInfo.Controls.Clear();
                    grpLotAddInfo.Visible = true;

                    CUS_WIP.Controls.udcAddLotControl newControl = new CUS_WIP.Controls.udcAddLotControl();
                    newControl.s_Oper = cdvOper.Text;
                    grpLotAddInfo.Controls.Add(newControl);
                    newControl.Dock = DockStyle.Fill;
                    newControl.sArea_id = cdvDept.Text;
                    newControl.sSub_Area_id = cdvWorkPlace.Text;
                    newControl.sOper_id = cdvOper.Text;
                }
                else
                {
                    grpLotAddInfo.Controls.Clear();
                    grpLotAddInfo.Visible = false;
                }

                //설비 데이터 전송 공정 체크여부. 
                if (CheckResTransferCheck(cdvOper.Text) == true)
                {
                    btnTranRes.Enabled = true;
                }
                else
                {
                    btnTranRes.Enabled = false;
                }

                //공정옵션 조회
                if (MPCF.Trim(cdvDept.Text) != "" && MPCF.Trim(cdvWorkPlace.Text) != "" && MPCF.Trim(cdvOper.Text) != "")
                {
                    CheckOperOption(cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text);

                    if (bCreateLotKey == true)
                    {
                        panCreateKey.Visible = true;
                        cdvLotKey.Text = "";
                    }
                    else
                    {
                        panCreateKey.Visible = false;
                        cdvLotKey.Text = "";
                    }
                }
                else
                {
                    panCreateKey.Visible = false;
                    cdvLotKey.Text = "";
                }

                //공정별 벨리데이션을 조회한다.
                CheckOperValidation(cdvOper.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //공정 변경시 원인 공정도 같이 바꿔준다.
        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                ClearList("OPER");

                if (MPCF.Trim(cdvOper.Text) != "")
                    ViewLossList("");

                cdvCauseOper.Text = cdvOper.Text;
                cdvCauseOper.DisplayText = cdvOper.DisplayText;

                //공정 데이터 입력이 있는지 여부를 확인하여 공정 데이터 입력이 있는경우 하단 그룹판넬을 VISIBLE 해주면서 컨트롤을 나오게 한다.
                if (CheckOperData(cdvOper.Text) == true)
                {
                    grpLotAddInfo.Controls.Clear();
                    grpLotAddInfo.Visible = true;

                    CUS_WIP.Controls.udcAddLotControl newControl = new CUS_WIP.Controls.udcAddLotControl();
                    newControl.s_Oper = cdvOper.Text;
                    grpLotAddInfo.Controls.Add(newControl);
                    newControl.Dock = DockStyle.Fill;
                    newControl.sArea_id = cdvDept.Text;
                    newControl.sSub_Area_id = cdvWorkPlace.Text;
                    newControl.sOper_id = cdvOper.Text;
                }
                else
                {
                    grpLotAddInfo.Controls.Clear();
                    grpLotAddInfo.Visible = false;
                }

                if (CheckResTransferCheck(cdvOper.Text) == true)
                {
                    btnTranRes.Enabled = true;
                }
                else
                {
                    btnTranRes.Enabled = false;
                }

                //공정옵션 조회
                if (MPCF.Trim(cdvDept.Text) != "" && MPCF.Trim(cdvWorkPlace.Text) != "" && MPCF.Trim(cdvOper.Text) != "")
                {
                    CheckOperOption(cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text);

                    if (bCreateLotKey == true)
                    {
                        panCreateKey.Visible = true;
                        cdvLotKey.Text = "";
                    }
                    else
                    {
                        panCreateKey.Visible = false;
                        cdvLotKey.Text = "";
                    }
                }
                else
                {
                    panCreateKey.Visible = false;
                    cdvLotKey.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCauseOper_ButtonPress(object sender, EventArgs e)
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

                cdvCauseOper.Init();
                MPCF.InitListView(cdvCauseOper.GetListView);
                cdvCauseOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCauseOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCauseOper.SelectedSubItemIndex = 0;
                cdvCauseOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvCauseOper.GetListView, '2', cdvDept.Text) == false)
                {
                    return;
                }

                cdvCauseOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void chkToOper_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                if (chkToOper.Checked == true)
                {
                    cdvToOper.Enabled = true;
                }
                else
                {
                    cdvToOper.Enabled = false;
                }
                cdvToOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //다음공정 지정
        private void cdvToOper_ButtonPress(object sender, EventArgs e)
        {
            string sFlow = "";

            try
            {
                if (spdWorkOrder.ActiveSheet.RowCount > 0)
                {
                    sFlow = spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.FLOW].Text;
                }

                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                //공정 조회
                if (WIPLIST.ViewOperationList(cdvToOper.GetListView, '2', sFlow) == false)
                    return;

                cdvToOper.InsertEmptyRow(0, 1);
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

                    if (MPCF.Trim(cdvOrder.Text) != "")
                    {
                        ViewOrder();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot id 선택 버튼
        private void txtLotID_ButtonClick(object sender, Infragistics.Win.Misc.AlertButtonClickedEventArgs e)
        {
            txtLotID.sArea_id = cdvDept.Text;
            txtLotID.sArea_desc = cdvDept.DisplayText;
            txtLotID.sSub_Area_id = cdvWorkPlace.Text;
            txtLotID.sSub_Area_desc = cdvWorkPlace.DisplayText;
            txtLotID.sOper_id = cdvOper.Text;
            txtLotID.sOper_desc = cdvOper.DisplayText;
            //txtLotID.sRes_id = cdvResource.Text;
            //txtLotID.sRes_desc = cdvResource.DisplayText;
            txtLotID.sOrder = cdvOrder.Text;
        }

        //lot id 선택시 loss 코드 재조회
        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sLotID = "";

            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
                    }

                    LotCheckCount();
                }
                else
                {
                    sLotID = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                    ViewLossList(sLotID);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                LotCheckCount();

                if (e.Column == (int)LOT_INFO.INV_BUTTON)
                {

                    frmTranInputLotMaterials popup = new frmTranInputLotMaterials();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = cdvDept.Text;
                    popup.sArea_desc = cdvDept.DisplayText;
                    popup.sSub_area_id = cdvWorkPlace.Text;
                    popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                    popup.sOper_id = cdvOper.Text;
                    popup.sOper_desc = cdvOper.DisplayText;
                    popup.sOrder_id = cdvOrder.Text;
                    popup.sLot_id = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                    popup.sLot_Qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Text);

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        popup = null;
                    }
                    else
                        return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //생산 수량을 변경하면 양품수량을 다시 계산 해준다. 
        private void spdLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            double d_prod_qty = 0;
            double d_loss_qty = 0;

            try
            {
                if (e.Column == (int)LOT_INFO.PROD_QTY)
                {
                    d_loss_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BAD_QTY].Value);
                    d_prod_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PROD_QTY].Value);

                    spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.GOOD_QTY, d_prod_qty - d_loss_qty);
                }

                LotCheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업자 전체 체크
        private void spdWorkerList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)WORKER_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdWorkerList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot 수량 키인 후 엔터
        private void txtProdQty_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnAdd.PerformClick();
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        //LOT 추가 버튼
        private void btnAdd_Click(object sender, EventArgs e)
        {
            int iRow = 0;
            double dLotUnitQty = 0;

            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                dLotUnitQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.UNIT_QTY].Text);

                if (dLotUnitQty == 0)
                {
                    dLotUnitQty = MPCF.ToDbl(txtProdQty.Text);
                }
                else
                {
                    //입력 수량에 곱할지 여부 확인 필요
                    //dLotUnitQty = dLotUnitQty * MPCF.ToDbl(txtProdQty.Text);
                }

                iRow = spdLotList.ActiveSheet.RowCount;
                spdLotList.ActiveSheet.RowCount++;

                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, "");
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.MAT_ID].Text);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.MAT_DESC].Text);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, dLotUnitQty);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.GOOD_QTY, dLotUnitQty);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.BAD_QTY, 0);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.START_TIME, "");

                txtProdQty.Text = "";

                LotCheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LOT 삭제 버튼
        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = spdLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                ViewLossList("");

                LotCheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //grit의 코팅 공정인 경우 lot 뒤에 글씨를 붙인다.
        private void cdvLotKey_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLotKey.Init();
                MPCF.InitListView(cdvLotKey.GetListView);
                cdvLotKey.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvLotKey.SelectedSubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvLotKey.GetListView, '1', CSGC.CP_GCM_ADD_LOT_CHAR) == false)
                {
                    return;
                }

                cdvLotKey.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //불량 저장
        private void btnLossSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveLossData())
                {
                    LotCheckCount();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //전체 클리어
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //투입자재 클릭
        private void btnInputMat_Click(object sender, EventArgs e)
        {
            try
            {

                frmTranMaterialInputByLevel popup = new frmTranMaterialInputByLevel();

                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper_id = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sOrder_id = cdvOrder.Text;

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

        //작업자 클릭.
        private void btnWorker_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranWorkerRegistration popup = new frmTranWorkerRegistration();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sGroup_id = cdvWorkGroup.Text;
                popup.sGroup_desc = cdvWorkGroup.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    popup = null;
                    ViewWorkerList();
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //비가동
        private void btnNonOper_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranNonOperation popup = new frmTranNonOperation();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sRes_id = cdvResource.Text;
                popup.sRes_desc = cdvResource.DisplayText;

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

        //lot data 입력
        private void btnLotData_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranInputLotData popup = new frmTranInputLotData();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvWorkPlace.Text = cdvWorkPlace.Text;
                popup.cdvWorkPlace.DisplayText = cdvWorkPlace.DisplayText;
                popup.cdvOper.Text = cdvOper.Text;
                popup.cdvOper.DisplayText = cdvOper.DisplayText;
                popup.cdvResource.Text = cdvResource.Text;
                popup.cdvResource.DisplayText = cdvResource.DisplayText;
                popup.txtLotID.Text = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;

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

        private void btnTranRes_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranTransferResInfo popup = new frmTranTransferResInfo();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper_id = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sOrder_id = cdvOrder.Text;

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

        private void btnPress_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdLotList.ActiveSheet.RowCount == 0)
                {
                    //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpLotInfo.Text + "]");
                    return;
                }

                frmTranLotPressData popup = new frmTranLotPressData();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.c_Area = cdvDept.Text;
                popup.c_Area_desc = cdvDept.DisplayText;
                popup.c_Sub_area_id = cdvWorkPlace.Text;
                popup.c_Sub_area_desc = cdvWorkPlace.DisplayText;
                popup.c_Oper_id = cdvOper.Text;
                popup.c_Oper_desc = cdvOper.DisplayText;
                popup.c_ResId = cdvResource.Text;
                popup.c_Res_desc = cdvResource.DisplayText;
                popup.txtLotID.Text = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;

                foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                {
                    if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView)
                    {
                        if (ctr.Visible == true)
                        {
                            if (ctr.Tag.ToString() == "LOT_CMF_4")
                            {
                                popup.c_Profile = ctr.Text;
                            }
                        }
                    }
                }

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

        //작업시작
        private void btnStart_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.START) == false)
                    return;

                if (SaveProcess('1'))
                {
                    ViewOrder();
                    ViewLossList("");
                    ViewWorkerList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업완료
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.END) == false)
                    return;



                if (InputBomCheck() == false)
                {
                    return;
                }


                if (SaveProcess('2'))
                {
                    ClearList("END");
                    ViewOrder();
                    ViewLossList("");
                    ViewWorkerList();
                    ViewToolList();

                    chkToOper.Checked = false;
                    cdvToOper.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoAll_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoAll.Checked)
            {
                rdoLot.Checked = false;
                txtComment.Visible = true;
                spdLotList_Sheet1.Columns[(int)LOT_INFO.COMMENT].Visible = false;
            }
            else
            {
                rdoLot.Checked = true;
                txtComment.Visible = false;
                spdLotList_Sheet1.Columns[(int)LOT_INFO.COMMENT].Visible = true;
            }
        }

        private void rdoLot_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoAll.Checked)
            {
                rdoLot.Checked = false;
                txtComment.Visible = true;
                spdLotList_Sheet1.Columns[(int)LOT_INFO.COMMENT].Visible = false;
            }
            else
            {
                rdoLot.Checked = true;
                txtComment.Visible = false;
                spdLotList_Sheet1.Columns[(int)LOT_INFO.COMMENT].Visible = true;
            }
        }

        private void btnMatSetup_Click(object sender, EventArgs e)
        {
            try
            {

                frmWIPSetupDiaMaterial popup = new frmWIPSetupDiaMaterial();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.b_Popup_flag = true; ;
                popup.s_MatId = spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.MAT_ID].Text;
                popup.s_MatDesc = spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.MAT_DESC].Text;
                popup.i_MatVer = 1;
                /*
                    frmTranInputLotMaterials popup = new frmTranInputLotMaterials();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = cdvDept.Text;
                    popup.sArea_desc = cdvDept.DisplayText;
                    popup.sSub_area_id = cdvWorkPlace.Text;
                    popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                    popup.sOper_id = cdvOper.Text;
                    popup.sOper_desc = cdvOper.DisplayText;
                    popup.sOrder_id = cdvOrder.Text;
                    popup.sLot_id = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                    popup.sLot_Qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Text);
                */

                if (popup.ShowDialog() == DialogResult.OK)
                {
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

        #endregion

        #region " Serial Definition "

        public delegate void ReceivedHandler(string sText);
        ReceivedHandler rh_Sanner;

        private void btnPortOpen_Click(object sender, EventArgs e)
        {
            try
            {
                Open_Port(cboPort.Text, 'Y');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranProcessLot_FormClosed(object sender, FormClosedEventArgs e)
        {
            try
            {
                spScanner.Close();

                if (cboPort.SelectedIndex != -1)
                    MPCF.SaveRegSetting(Application.ProductName, this.Name, cboPort.Name, cboPort.SelectedItem.ToString());
                else
                    MPCF.SaveRegSetting(Application.ProductName, this.Name, cboPort.Name, "");

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cboPort_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (cboPort.Text == "")
                {
                    if (spScanner.IsOpen == true)
                    {
                        spScanner.Close();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spScanner_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string input = "";

            try
            {
                System.Threading.Thread.Sleep(100);

                input = spScanner.ReadExisting();

                if (!string.IsNullOrEmpty(input))
                {
                    string[] sInputData = input.Split('\r');

                    IAsyncResult result = BeginInvoke(rh_Sanner, sInputData[0]);
                    EndInvoke(result);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void Open_Port(string s_port, char c_MsgYN)
        {
            try
            {
                if (spScanner.IsOpen == true)
                {
                    spScanner.Close();
                }

                spScanner.PortName = s_port;
                spScanner.BaudRate = 9600;
                spScanner.DataBits = 8;
                spScanner.Parity = Parity.None;
                spScanner.StopBits = StopBits.One;
                spScanner.Handshake = Handshake.None;
                spScanner.RtsEnable = false;
                spScanner.DtrEnable = false;

                spScanner.Open();
                if (spScanner.IsOpen == true)
                {
                    if (c_MsgYN == 'Y')
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(500));
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void rhText(string sText)
        {
            txtLotID.Text = sText;
            ViewLotInfo(sText);
        }











        #endregion

        private void txtClipboard_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.V) // Use Keys.Return or Keys.Enter
            {
                Clipboard_to_LotList(Clipboard.GetText()); 
            }
        }

        private void spdLotList_KeyDown(object sender, KeyEventArgs e)
        {            
            try
            {
                if (e.KeyCode == Keys.V)
                {
                    if (chkPaste.Checked == true)
                    {
                        string s = Clipboard.GetText();
                        string[] lines = s.Replace("\n", "").Split('\r');

                        if (lines.Length > 0)
                        {
                            for (int i = 0; i < lines.Length - 1; i++)
                            {
                                string sLotId = lines[i];

                                if (sLotId != "")
                                {
                                    ViewLotInfo(sLotId);
                                }
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

        private void chkPaste_CheckedChanged(object sender, EventArgs e)
        {
            if (chkPaste.Checked == true)
            {
                spdLotList.Focus();
            }
            
        }
    }

}
