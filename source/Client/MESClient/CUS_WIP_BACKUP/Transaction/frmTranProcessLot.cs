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
            START_DATE,             // 2 : 시작일
            END_DATE,               // 3 : 완료일
            MAT_ID,                 // 4 : 제품코드
            MAT_DESC,               // 5 : 제품명
            UNIT,                   // 6 : 단위
            ORDER_QTY,              // 7 : 지시수량
            PROD_QTY,               // 8 : 생산수량
            STOCK                   // 9 : 창고
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
            START_TIME              // 8 : 시작시간
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = cdvOrder.Text;

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
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.START_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.END_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
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
                            continue;
                        }
                    }

                    if (out_node.GetString("OPER_OPTION_1") != "Y")
                    {
                        if (i == 0)
                        {
                            cdvDept.Text = out_node.GetList("LOT_TBL")[0].GetString("AREA_ID");
                            cdvDept.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("AREA_DESC");
                            cdvWorkPlace.Text = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_ID");
                            cdvWorkPlace.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_DESC");
                            cdvOper.Text = out_node.GetList("LOT_TBL")[0].GetString("OPER");
                            cdvOper.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("OPER_DESC");
                            cdvOrder.Text = out_node.GetList("LOT_TBL")[0].GetString("ORDER_ID");

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
                }


                // 첫번째 LOT의 정보를 보여주도록 수정 할 것.
                if (grpLotAddInfo.Visible == true)
                {
                    //커스텀 컨트롤인 경우
                    foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                    {
                        if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView)
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

                MPCF.FitColumnHeader(spdLotList);

                //lot id 텍스트 초기화
                txtLotID.Text = "";

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

        //작업 시작/종료 = > step 1 : 시작 , step 2 : 완료 
        private bool SaveProcess(char c_step)
        {
            int iRow = 0;
            bool bPrint = false;

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

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        Lot_list.AddDouble("GOOD_QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GOOD_QTY].Text));
                        Lot_list.AddDouble("LOSS_QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.BAD_QTY].Text));
                    }
                }

                //LOT 추가 데이터가 있는 경우 각 컨트롤의 TAG 값(테이블 컬럼명)과 TEXT값을 in_node에 담아 서버에 보낸다.
                if (grpLotAddInfo.Visible == true)
                {
                    //커스텀 컨트롤인 경우
                    foreach (Control ctr in grpLotAddInfo.Controls[0].Controls)
                    {
                        if (ctr is Miracom.UI.Controls.MCCodeView.MCCodeView)
                        {
                            // 현재 보여지는 컨트롤만 in_node에 담는다.
                            if (ctr.Visible == true)
                            {
                                in_node.AddString(ctr.Tag.ToString(), ctr.Text);
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

                        break;

                    case CSGC.CHECK.END:

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

                        if (MPCF.Trim(txtProdQty.Text) == "" || MPCF.ToDbl(txtProdQty.Text) == 0)
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblProdQty.Text + "]");
                            txtProdQty.Focus();
                            return false;
                        }

                        if (spdWorkOrder.ActiveSheet.RowCount == 0)
                        {
                            //CMN452 CONFIRM  - 선택된 작업지시가 없습니다. 작업지시를 선택하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(452));
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

                        txtLotID.Text = "";

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

                        //lot 추가정보 부분
                        MPCF.FieldClear(grpLotAddInfo);
                        txtLotID.Focus();

                        break;

                    case "ALL":

                        cdvOrder.Text = "";
                        cdvResource.Text = "";
                        cdvWorkGroup.Text = "";
                        txtComment.Text = "";

                        MPCF.FieldClear(panLotInfo);
                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdToollist);
                        MPCF.ClearList(spdLossList);

                        //lot 추가정보 부분
                        MPCF.FieldClear(grpLotAddInfo);
                        txtLotID.Focus();

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

        #endregion

        #region " Event Definition "

        private void frmTranProcessLot_Load(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    cdvOper_SelectedItemChanged(sender, null);
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

                if (CheckResTransferCheck(cdvOper.Text) == true)
                {
                    btnTranRes.Enabled = true;
                }
                else
                {
                    btnTranRes.Enabled = false;
                }
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
                cdvCauseOper.DisplayText= cdvOper.DisplayText;

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
            txtLotID.sRes_id = cdvResource.Text;
            txtLotID.sRes_desc = cdvResource.DisplayText;
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

            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                iRow = spdLotList.ActiveSheet.RowCount;
                spdLotList.ActiveSheet.RowCount++;

                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, "");
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.MAT_ID].Text);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.MAT_DESC].Text);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, MPCF.ToDbl(txtProdQty.Text));
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.GOOD_QTY, MPCF.ToDbl(txtProdQty.Text));
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.BAD_QTY, 0);
                spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.START_TIME, "");

                txtProdQty.Text = "";
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
                frmTranInputMaterials popup = new frmTranInputMaterials();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper_id = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sRes_id = cdvResource.Text;
                popup.sRes_desc = cdvResource.DisplayText;
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
                popup.sSub_area_desc= cdvWorkPlace.DisplayText;
                popup.sOper = cdvOper.Text;
                popup.sOper_desc= cdvOper.DisplayText;
                popup.sGroup_id = cdvWorkGroup.Text;
                popup.sGroup_desc= cdvWorkGroup.DisplayText;
                
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

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvWorkPlace.Text = cdvWorkPlace.Text;
                popup.cdvWorkPlace.DisplayText= cdvWorkPlace.DisplayText;
                popup.cdvOper.Text = cdvOper.Text;
                popup.cdvOper.DisplayText = cdvOper.DisplayText;
                popup.cdvResource.Text = cdvResource.Text;
                popup.cdvResource.DisplayText = cdvResource.DisplayText;

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
                    //MPCF.ClearList(spdLotList);
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

                if (SaveProcess('2'))
                {
                    ClearList("END");
                    ViewLossList("");
                    ViewWorkerList();
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
