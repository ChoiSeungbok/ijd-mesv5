using System;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Globalization;


using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

using FarPoint.Win.Spread.Model;


namespace CUS_WIP
{
    public partial class frmTranInpPdcPress : CUS_COM.frmTranForm06
    {
        public frmTranInpPdcPress()
        {
            InitializeComponent();

            InitControl();
        }

        DefaultSheetDataModel defModelData;

        //  bool b_allow_changed;
        int beforeRow = 0;
        int beforeCol = 0;

        #region " Constant Definition "
        private enum LOT_INFO
        {
            START_END
           , BOM_INPUT
           , ORDER_ID
           , LOT_ID
           , MAT_ID
           , MAT_VER
           , MAT_DESC
           , FLOW
           , WORK_DATE
           , REQ_QTY
           , PASS_QTY
           , NG_QTY
           , WAIT_QTY
           , INV_LOT_ID
           , INV_MAT_ID
           , INV_MAT_DESC
           , LOT_STATUS
           , CREATE_CODE
           , COL_SET_ID
           , AREA_ID
           , AREA_DESC
           , SUB_AREA_ID
           , SUB_AREA_DESC
           , OPER
           , OPER_DESC
           , TO_OPER
           , LAST_COMMENT
           , EDC_HIST_SEQ
           , EDC_COL_SEQ
           , START_TIME
           , RES_ID
           , RES_DESC
           , COL_SET_VERSION
           , FIRST_OP_YN
        }

        private enum COLLECTION_DATA
        {
            UNIT_SEQ,
            MC,
            WORKER_ID,
            POQC014,
            POQC006,
            POQC054,
            POQC055,
            POQC056,
            POQC057,
            POQC058,
            POQC059,
            POQC060,
            POQC061,
            JUDGE_PASS,
            JUDGE_LOSS,
            WAIT_QTY,
            COPY,
            PASTE,
            JUDGE_COMMENT

        }
        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {


                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGCM.Anchor = AnchorStyles.Top | AnchorStyles.Right;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void ClearList(string sType)
        {
            switch (sType)
            {
                case "LOT_INFO":

                    //           MPCF.FieldClear(panLotInfo,txtLotID);
                    MPCF.ClearList(spdLotList);


                    //MPCF.FieldClear(panDataCollection);
                    MPCF.ClearList(spdDataCollection);

                    break;

                case "COL_SET_CHANGED":

                    //MPCF.ClearList(spdDataCollection);
                    //txtColSetVer.Text = "";
                    //spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
            }

        }


        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {


                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;


                    case CSGC.CHECK.SAVE:

                        if (spdDataCollection.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            spdDataCollection.Select();
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


        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "FROM_DATE";
                dvcArgu[1].sCondition_Value = dtpFromDate.Text.Replace("-", "");


                dvcArgu[2].sCondition_ID = "TO_DATE";
                dvcArgu[2].sCondition_Value = dtpToDate.Text.Replace("-", "");


                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = txtWo.Text;

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text;


                dvcArgu[5].sCondition_ID = "STATUS";
                dvcArgu[5].sCondition_Value = cdvWorkType.Text;



                if (TPDR.GetDataOne("", ref dt, "CWIP2041-001", dvcArgu, false, false, ref sSql) == false)
                {
                    MPCF.ClearList(spdLotList);
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }


                FarPoint.Win.Spread.CellType.ButtonCellType buttonStart = new FarPoint.Win.Spread.CellType.ButtonCellType();
                FarPoint.Win.Spread.CellType.ButtonCellType buttonEnd = new FarPoint.Win.Spread.CellType.ButtonCellType();



                buttonStart.BackgroundStyle = FarPoint.Win.BackStyle.Gradient;
                buttonStart.ButtonColor = System.Drawing.Color.Blue;
                buttonStart.ButtonColor2 = System.Drawing.Color.Blue;
                buttonStart.DarkColor = System.Drawing.Color.Blue;
                buttonStart.GradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
                buttonStart.LightColor = System.Drawing.Color.Blue;
                buttonStart.Text = "START";
                buttonStart.TextColor = System.Drawing.Color.White;
                buttonStart.UseVisualStyleBackColor = false;


                buttonEnd.BackgroundStyle = FarPoint.Win.BackStyle.Gradient;
                buttonEnd.ButtonColor = System.Drawing.Color.Red;
                buttonEnd.ButtonColor2 = System.Drawing.Color.Red;
                buttonEnd.DarkColor = System.Drawing.Color.Red;
                buttonEnd.GradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
                buttonEnd.LightColor = System.Drawing.Color.Red;
                buttonEnd.Text = "END";
                buttonEnd.TextColor = System.Drawing.Color.White;
                buttonEnd.UseVisualStyleBackColor = false;


                MPCF.ClearList(spdLotList);





                for (i = 0; i < dt.Rows.Count; i++)
                {

                    /*
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];

                    */

                    spdLotList_Sheet1.RowCount++;


                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.WORK_DATE].Value = dt.Rows[i]["WORK_DATE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.REQ_QTY].Value = dt.Rows[i]["REQ_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.PASS_QTY].Value = dt.Rows[i]["PASS_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.NG_QTY].Value = dt.Rows[i]["NG_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.WAIT_QTY].Value = dt.Rows[i]["WAIT_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INV_MAT_ID].Value = dt.Rows[i]["INV_MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INV_MAT_DESC].Value = dt.Rows[i]["INV_MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_STATUS].Value = dt.Rows[i]["LOT_STATUS"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COL_SET_ID].Value = dt.Rows[i]["COL_SET_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.TO_OPER].Value = dt.Rows[i]["TO_OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LAST_COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.EDC_HIST_SEQ].Value = dt.Rows[i]["EDC_HIST_SEQ"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.EDC_COL_SEQ].Value = dt.Rows[i]["EDC_COL_SEQ"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.START_TIME].Value = dt.Rows[i]["START_TIME"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COL_SET_VERSION].Value = dt.Rows[i]["COL_SET_VERSION"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.FIRST_OP_YN].Value = dt.Rows[i]["FIRST_OP_YN"];


                    if (MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value) == "")
                    {
                        spdLotList_Sheet1.Cells[i, (int)LOT_INFO.START_END].CellType = buttonStart;
                    }
                    else
                    {
                        spdLotList_Sheet1.Cells[i, (int)LOT_INFO.START_END].CellType = buttonEnd;
                    }




                }
                MPCF.FitColumnHeader(spdLotList);

                ViewEdcData();


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //작업 시작/종료 = > step 1 : 시작 , step 2 : 완료 
        private bool SaveProcess(char c_step)
        {
            //  int iRow = 0;
            int iActiceRow = 0;
            //   bool bPrint = false;
            //   string sConName = "";


            if (MPCF.Trim(cdvMC.Text) == "")
            {
                MPCF.ShowMsgBox("Please Input M/C (설비입력 필수입니다.)");
                return false;
            }


            if (MPCF.ToDbl(txtPassQty.Text) == 0 && MPCF.ToDbl(txtBadQty.Text) == 0)
            {
                MPCF.ShowMsgBox("Please Input Pass/NG Check (합격 불합격 체크는 필수입니다.)");
                return false;
            }


            iActiceRow = spdLotList.ActiveSheet.ActiveRowIndex;
            Double iPassQty = MPCF.ToDbl(txtPassQty.Text);//MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.PASS_QTY].Text);
            Double iNgQty = MPCF.ToDbl(txtBadQty.Text);// MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.NG_QTY].Text);
            Double iReqQty = MPCF.ToDbl(txtWaitQty.Text); // MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.REQ_QTY].Text);
            Double iInqty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.WAIT_QTY].Text);


            try
            {


                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;
                TRSNode Worker_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.AREA_ID].Text);
                in_node.AddString("SUB_AREA_ID", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.SUB_AREA_ID].Text);
                in_node.AddString("OPER", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.OPER].Text);
                in_node.AddString("ORDER_ID", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.ORDER_ID].Text);
                in_node.AddString("RES_ID", cdvMC.Text);
                in_node.AddString("COMMENT", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.LAST_COMMENT].Text);
                in_node.AddString("TO_OPER", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.TO_OPER].Text);


                Lot_list = in_node.AddNode("LOT_TBL");
                Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.LOT_ID].Text);

                if (c_step == '1')
                {
                    Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.WAIT_QTY].Text));
                }
                else if (c_step == '2')
                {

                    //20230113 분활될거 생각해서 해당 체크 제거
                    /*if(iInqty != iPassQty + iNgQty)
                     {
                        MPCF.ShowMsgBox("(PASS/NG)--All quantities must be determined._모든수량은 판정이되어야합니다.");
                        return false;
                      }
                    */


                    if (iInqty != iPassQty + iNgQty)
                    {
                        if (spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.FIRST_OP_YN].Text != "Y")
                        {
                            /*
                                if (MPCF.ShowMsgBox("processing the Partial quantity,splite the LOT first (Splite Yes/No?) \r\n  부분처리시 먼저 LOT 분할해주세요?(분할하시겠습니까?) ", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                                {
                                    if (SaveSplite() == false)
                                    {
                                        return false;
                                    }
                                }
                                */
                            //그냥 물어보지 말고 바로 분할되게 수정.
                            if (SaveSplite() == false)
                            {
                                return false;
                            }
                        }

                    }


                    Lot_list.AddDouble("QTY_1", iPassQty + iNgQty);
                    //  Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.PASS_QTY].Text) + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.NG_QTY].Text));
                }
                Lot_list.AddDouble("GOOD_QTY_1", iPassQty);
                Lot_list.AddDouble("LOSS_QTY_1", iNgQty);

                //Lot_list.AddDouble("GOOD_QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.PASS_QTY].Text));
                // Lot_list.AddDouble("LOSS_QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.NG_QTY].Text));

                Lot_list.AddString("COMMENT", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.LAST_COMMENT].Text);


                Worker_list = in_node.AddNode("WORKER_TBL");
                Worker_list.AddString("WORKER_ID", cdvWorker.Text);




                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Process_Lot", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    if (c_step == '1')
                    {

                        MPCR.ShowSuccessMsg(out_node);
                    }
                }



                //저장 후 로직
                if (c_step == '1')
                {
                    //  MPCF.ClearList(spdLotList);


                    ViewLotList();

                }
                else if (c_step == '2')
                {
                    //저장후 프레스 타수저장여부 체크
                    //금형타수 선택적으로 따로뺌
                    SaveUseCount(cdvMC.Text);
                    ViewLotList();
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool SaveSplite()
        {
            int iActiceRow = 0;

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                iActiceRow = spdLotList.ActiveSheet.ActiveRowIndex;

                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.LOT_ID].Text);

                Lot_list = in_node.AddNode("LOT_TBL");
                Lot_list.AddString("LOT_ID", "");
                // Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.WAIT_QTY].Text));
                Lot_list.AddDouble("QTY_1", MPCF.ToDbl(txtWaitQty.Text));

                in_node.AddString("COMMENT", txtComment.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Split_Wip_Lot", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    // MPCR.ShowSuccessMsg(out_node);
                }

                // MPCF.ClearList(spdLotList);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void SaveUseCount(string sResId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                int iUseCount = 0;


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "RES_iD";
                dvcArgu[1].sCondition_Value = sResId;

                if (TPDR.GetDataOne("", ref dt, "CWIP2041-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    return;
                }

                iUseCount = ((MPCF.ToInt(txtPassQty.Text) + MPCF.ToInt(txtBadQty.Text)) / 2) - 1;

                /*
                if (MPCF.ShowMsgBox("Do you want to calculate the number of times a mold is used?(Add " + iUseCount + " Count) " + "\r\n" + "금형사용횟수를 계산시겠습니까?", MessageBoxButtons.YesNo, 1) == DialogResult.No)
                {
                    iUseCount = -1;
                }
                else
                {
                }
                */


                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode Tool_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    Tool_list = in_node.AddNode("TOOL_TBL");
                    Tool_list.AddString("TOOL_ID", dt.Rows[i]["TOOL_ID"]);

                    if (MPCF.ToInt(dt.Rows[i]["USE_COUNT"].ToString()) + iUseCount < 0)
                    {
                        Tool_list.AddInt("USE_COUNT", MPCF.ToInt("0"));
                    }
                    else
                    {
                        Tool_list.AddInt("USE_COUNT", MPCF.ToInt(dt.Rows[i]["USE_COUNT"].ToString()) + iUseCount);
                    };
                }

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Mold_Tool_Event", in_node, ref out_node) == false)
                    return;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void ViewEdcData()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                string sMc = "";
                int i = 0;
                int LotQty = 0;
                //   int iLossCount = 0;
                //   int iGroupSeq = 0;
                //   int iGroupSeqCount = 0;
                //  string sLossCountchk = "N";




                int iPassQty = 0;
                // int iLossQty = 0;
                int iWaitQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Value);

                dvcArgu[2].sCondition_ID = "HIST_SEQ";
                dvcArgu[2].sCondition_Value = MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.EDC_HIST_SEQ].Value);

                dvcArgu[3].sCondition_ID = "COL_SEQ";
                dvcArgu[3].sCondition_Value = MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.EDC_COL_SEQ].Value);

                dvcArgu[4].sCondition_ID = "COL_SET_ID";
                dvcArgu[4].sCondition_Value = MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.COL_SET_ID].Value);


                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.OPER].Value);





                //    dvcArgu[2].sCondition_ID = "GROUP_ID";
                //    dvcArgu[2].sCondition_Value = cdvWorkGroup.Text;


                if (TPDR.GetDataOne("", ref dt, "CWIP2041-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    // return;
                }


                MPCF.ClearList(spdDataCollection);

                LossCombobox();
                ProfileCombobox();

                LotQty = MPCF.ToInt(MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.WAIT_QTY].Value));

                if (MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.RES_DESC].Text) == "")
                {
                    sMc = "XX";
                }
                else
                {
                    sMc = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.RES_DESC].Text;
                }


                for (i = 0; i < LotQty; i++)
                {


                    if (i < dt.Rows.Count)
                    {
                        spdDataCollection_Sheet1.RowCount++;



                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value = i + 1;
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.MC].Value = sMc.Substring(sMc.Length - 2);
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.WORKER_ID].Value = cdvWorker.DisplayText;
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC014].Value = dt.Rows[i]["POQC014"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC006].Value = dt.Rows[i]["POQC006"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC054].Value = dt.Rows[i]["POQC054"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC055].Value = dt.Rows[i]["POQC055"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC056].Value = dt.Rows[i]["POQC056"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC057].Value = dt.Rows[i]["POQC057"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC058].Value = dt.Rows[i]["POQC058"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC059].Value = dt.Rows[i]["POQC059"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC060].Value = dt.Rows[i]["POQC060"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.POQC061].Value = dt.Rows[i]["POQC061"];
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value = dt.Rows[i]["JUDGE_PASS"].ToString() == "Y" ? true : false;
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Text = dt.Rows[i]["JUDGE_LOSS"].ToString();






                        if (dt.Rows[i]["JUDGE_PASS"].ToString() == "Y" || dt.Rows[i]["JUDGE_LOSS"].ToString().Length > 1)
                        {
                            spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.WAIT_QTY].Value = false;
                        }
                        else
                        {
                            spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.WAIT_QTY].Value = true;
                        }
                        //  spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.WAIT_QTY].Value = dt.Rows[i]["JUDGE_PASS"].ToString() != "N" && dt.Rows[i]["JUDGE_LOSS"].ToString().Length == 0 ? true : false;
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.JUDGE_COMMENT].Value = dt.Rows[i]["JUDGE_COMMENT"];


                        //합격수량 카운트
                        if (dt.Rows[i]["JUDGE_PASS"].ToString() == "Y")
                        {
                            iPassQty = iPassQty + 1;
                        }

                        /*
                        if (dt.Rows[i]["JUDGE_LOSS"].ToString().Trim() != "")
                        {

                         //   sLossCountchk = "N";
                            for (iLossCount =0; iLossCount < spdBadData_Sheet1.ColumnCount; iLossCount++)
                            {

                                if(spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Text == spdBadData_Sheet1.ColumnHeader.Cells[0, iLossCount].Text)
                                {
                                    spdBadData_Sheet1.Cells[0, iLossCount].Text = (MPCF.ToInt(spdDataCollection_Sheet1.Cells[0, iLossCount]) + 1).ToString();
                                    sLossCountchk = "Y";
                                }

                            }

                            iLossQty = iLossQty + 1;
                        }
                        */



                    }
                    else
                    {
                        spdDataCollection_Sheet1.RowCount++;

                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value = i + 1;
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.MC].Value = sMc.Substring(sMc.Length - 2);
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.WORKER_ID].Value = cdvWorker.DisplayText;
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                        spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.WAIT_QTY].Value = true;


                        iWaitQty = iWaitQty + 1;

                    }



                }

                /*

                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.GROUP_SEQ).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.UNIT_SEQ).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.MC).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.WORKER_ID).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC014).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC006).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC054).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC055).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC056).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC057).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC058).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC059).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC060).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.POQC061).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.JUDGE_PASS).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.JUDGE_LOSS).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.WAIT_QTY).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.COPY).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.PASTE).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection_Sheet1.Columns.Get((int)COLLECTION_DATA.JUDGE_COMMENT).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                */




                QtyCount("2");

                //txtPassQty.Text = iPassQty.ToString();
                //txtBadQty.Text = iLossQty.ToString();
                //txtWaitQty.Text = iWaitQty.ToString();
                txtCopyRow.Text = "";


                MPCF.FitColumnHeader(spdLotList);
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void QtyCount(string sStep)
        {


            try
            {
                int i = 0;
                int iLossCount = 0;


                txtPassQty.Text = "0";
                txtBadQty.Text = "0";
                txtWaitQty.Text = "0";

                spdBadData_Sheet1.RowCount = 0;
                spdBadData_Sheet1.RowCount++;



                for (i = 0; i < spdDataCollection_Sheet1.RowCount; i++)
                {

                    if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value.ToString().ToUpper() == "TRUE")
                    {
                        txtPassQty.Text = (MPCF.ToInt(txtPassQty.Text) + 1).ToString();
                    }


                    if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.WAIT_QTY].Value.ToString().ToUpper() == "TRUE")
                    {
                        txtWaitQty.Text = (MPCF.ToInt(txtWaitQty.Text) + 1).ToString();
                    }



                    if (spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Text != "")
                    {
                        txtBadQty.Text = (MPCF.ToInt(txtBadQty.Text) + 1).ToString();

                        for (iLossCount = 0; iLossCount < spdBadData_Sheet1.ColumnCount; iLossCount++)
                        {

                            if (spdDataCollection_Sheet1.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Text == spdBadData_Sheet1.ColumnHeader.Cells[0, iLossCount].Text)
                            {
                                spdBadData_Sheet1.Cells[0, iLossCount].Text = (MPCF.ToInt(spdBadData_Sheet1.Cells[0, iLossCount].Text) + 1).ToString();

                            }

                        }
                    }
                }


                if (sStep == "1")
                {
                    txtEditFlag.Text = "Y";
                }
                else
                {
                    txtEditFlag.Text = "N";
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private bool EdcDataSave()
        {


            int iInputRow;

            TRSNode in_node = new TRSNode("COLLECT_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");
            TRSNode char_item, unit_item, value_item;
            CultureInfo ci_inter = new CultureInfo("en-US");

            try
            {


                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text));
                in_node.AddInt("HIST_SEQ", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.EDC_HIST_SEQ].Text));
                in_node.AddChar("LOT_EDC_TRAN_FLAG", 'Y');
                in_node.AddString("MAT_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_ID].Text));
                in_node.AddInt("MAT_VER", MPCF.ToInt(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_VER].Text));
                in_node.AddString("FLOW", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.FLOW].Text));
                in_node.AddString("OPER", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.OPER].Text));
                in_node.AddString("MEAS_RES_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.RES_ID].Text));
                in_node.AddString("COL_SET_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.COL_SET_ID].Text));
                in_node.AddString("PROC_FLOW", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.FLOW].Text));

                in_node.AddInt("COL_SET_VERSION", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.COL_SET_VERSION].Text));
                in_node.AddString("PROC_OPER", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.OPER].Text));
                in_node.AddString("PROC_RES_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.RES_ID].Text));




                for (int iCol = (int)COLLECTION_DATA.POQC014; iCol < (int)COLLECTION_DATA.JUDGE_COMMENT; iCol++)
                {
                    switch (iCol)
                    {
                        case (int)COLLECTION_DATA.POQC014:
                        case (int)COLLECTION_DATA.POQC006:
                        case (int)COLLECTION_DATA.POQC054:
                        case (int)COLLECTION_DATA.POQC055:
                        case (int)COLLECTION_DATA.POQC056:
                        case (int)COLLECTION_DATA.POQC057:
                        case (int)COLLECTION_DATA.POQC058:
                        case (int)COLLECTION_DATA.POQC059:
                        case (int)COLLECTION_DATA.POQC060:
                        case (int)COLLECTION_DATA.POQC061:
                        case (int)COLLECTION_DATA.JUDGE_PASS:
                        case (int)COLLECTION_DATA.JUDGE_LOSS:
                        case (int)COLLECTION_DATA.JUDGE_COMMENT:


                            char_item = in_node.AddNode("CHAR_LIST");

                            char_item.AddString("CHAR_ID", MPCF.Trim(spdDataCollection_Sheet1.ColumnFooter.Cells[0, iCol].Text));
                            char_item.AddString("COL_SET_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.COL_SET_ID].Text));
                            char_item.AddInt("COL_SET_VERSION", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.COL_SET_VERSION].Text));
                            char_item.AddInt("COL_SEQ", 1);
                            char_item.AddInt("CHAR_SEQ_NUM", MPCF.Trim(spdDataCollection_Sheet1.ColumnFooter.Cells[1, iCol].Text));



                            iInputRow = 0;

                            for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                            {

                                //if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value.ToString().ToUpper() == "TRUE" || MPCF.Trim(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value)=="")
                                //{


                                unit_item = char_item.AddNode("UNIT_LIST");
                                unit_item.AddString("UNIT_ID", " ");
                                unit_item.AddInt("UNIT_SEQ_NUM", MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(iInputRow, (int)COLLECTION_DATA.UNIT_SEQ)));
                                unit_item.AddChar("VALUE_TYPE", MPCF.Trim(spdDataCollection.ActiveSheet.ColumnFooter.Cells[2, iCol].Text));

                                value_item = unit_item.AddNode("VALUE_LIST");


                                if (MPCF.Trim(spdDataCollection_Sheet1.ColumnFooter.Cells[2, iCol].Text) == "N" && MPCF.CheckNumeric(spdDataCollection.ActiveSheet.GetValue(iInputRow, iCol)) == true)
                                {
                                    value_item.AddString("VALUE", MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iInputRow, iCol].Text).ToString(ci_inter.NumberFormat));
                                }
                                else
                                {
                                    if (iCol == (int)COLLECTION_DATA.JUDGE_PASS)
                                    {
                                        value_item.AddString("VALUE", spdDataCollection.ActiveSheet.Cells[iInputRow, iCol].Value.ToString().ToUpper() == "TRUE" ? "Y" : "N");
                                    }
                                    else
                                    {
                                        value_item.AddString("VALUE", MPCF.Trim(spdDataCollection.ActiveSheet.Cells[iInputRow, iCol].Text));
                                    }
                                }
                                iInputRow = iInputRow + 1;

                                //}
                            }

                            if (txtPassQty.Text == "0" && txtBadQty.Text == "0")
                            {
                                MPCF.ShowMsgBox("Not is Pass or NG Data (판정된 Data가없습니다.)");
                                return false;
                            }
                            /*
                            if(iInputRow == 0)
                            {
                                MPCF.ShowMsgBox("Not is Pass or NG Data (판정된 Data가없습니다.)");
                                return false;
                            }
                            */

                            break;
                        default:

                            break;

                    }

                }



                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Input_Lot_Data", in_node, ref out_node, false) == false)
                {

                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }

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


        private void LossCombobox()
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            StringBuilder sb;

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            sb = new StringBuilder();

            sb.Append("SELECT * FROM ");
            sb.Append("(SELECT ' ' AS LOSS_CODE, ' ' AS LOSS_DESC, '0' AS SEQ FROM DUAL UNION ALL  ");
            sb.Append(" SELECT A.KEY_2 AS LOSS_CODE, ");
            sb.Append("          C.DATA_1 AS LOSS_DESC, ");
            sb.Append("           replace(A.DATA_1,' ','999') AS SEQ");
            sb.Append("     FROM MGCMTBLDAT A , MGCMTBLDAT C ");
            sb.Append(" WHERE A.FACTORY = C.FACTORY ");
            sb.Append("                                 AND A.KEY_2 = C.KEY_1 ");
            sb.Append("                                 AND C.TABLE_NAME = 'LOSS_CODE' ");
            sb.Append("     AND A.FACTORY = '" + MPGV.gsFactory + "'");
            sb.Append("     AND A.TABLE_NAME = 'C_OPER_LOSS' ");
            sb.AppendLine("     AND A.KEY_1 = '" + spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.OPER].Value + "' )");
            sb.Append(" ORDER BY TO_NUMBER(SEQ)");
            in_node.AddString("SQL", sb.ToString());

            sb = new StringBuilder();
            in_node.AddString("SQL", sb.ToString());

            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
            {
                return;
            }

            string[] sItemData;
            string[] sItems;

            if (out_node.GetList("ROWS").Count > 0)
            {
                sItemData = new string[out_node.GetList("ROWS").Count];
                sItems = new string[out_node.GetList("ROWS").Count];

                for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                {
                    sItems[i] = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                    sItemData[i] = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA");



                    spdBadData_Sheet1.ColumnCount = 0;

                    for (int r = 0; r < out_node.GetList("ROWS").Count; r++)
                    {
                        if (r != 0)
                        {
                            spdBadData_Sheet1.ColumnCount++;


                            spdBadData_Sheet1.ColumnHeader.Cells[0, r - 1].Text = out_node.GetList("ROWS")[r].GetList("COLS")[1].GetString("DATA");

                            spdBadData_Sheet1.ColumnFooter.Cells[0, r - 1].Text = out_node.GetList("ROWS")[r].GetList("COLS")[0].GetString("DATA");

                        }

                    }

                    MPCF.FitColumnHeader(spdBadData);



                }

                FarPoint.Win.Spread.CellType.ComboBoxCellType cb2 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();//CellType 정의 
                cb2.ItemData = sItems;//ItemData 값 지정. 
                cb2.Items = sItemData; //Items 값 지정.. 
                cb2.EditorValue = FarPoint.Win.Spread.CellType.EditorValue.ItemData;

                spdDataCollection.ActiveSheet.Columns[(int)COLLECTION_DATA.JUDGE_LOSS].CellType = cb2; //CellType 지정. .

            }
        }


        private void ProfileCombobox()
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            StringBuilder sb;

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            sb = new StringBuilder();

            sb.Append("SELECT * FROM ");
            sb.Append("(SELECT ' ' AS CODE, ' ' AS NAME, 0 AS SEQ FROM DUAL UNION ALL  ");
            sb.Append(" SELECT A.KEY_1 AS CODE,A.DATA_1 AS NAME,  ROWNUM AS SEQ ");
            sb.Append("     FROM MGCMTBLDAT A  WHERE A.FACTORY = '" + MPGV.gsFactory + "' AND A.TABLE_NAME = 'C_PDC_PROFILE') ");
            sb.Append(" ORDER BY 3");
            in_node.AddString("SQL", sb.ToString());

            sb = new StringBuilder();
            in_node.AddString("SQL", sb.ToString());

            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
            {
                return;
            }

            string[] sItemData;
            string[] sItems;

            if (out_node.GetList("ROWS").Count > 0)
            {
                sItemData = new string[out_node.GetList("ROWS").Count];
                sItems = new string[out_node.GetList("ROWS").Count];

                for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                {
                    sItems[i] = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                    sItemData[i] = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA");
                }

                FarPoint.Win.Spread.CellType.ComboBoxCellType cb2 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();//CellType 정의 
                cb2.ItemData = sItems;//ItemData 값 지정. 
                cb2.Items = sItemData; //Items 값 지정.. 
                cb2.EditorValue = FarPoint.Win.Spread.CellType.EditorValue.ItemData;

                spdDataCollection.ActiveSheet.Columns[(int)COLLECTION_DATA.POQC054].CellType = cb2; //CellType 지정. .

            }
        }


        private bool SaveLossData()
        {

            try
            {
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode loss_list;


                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);
                //in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("CUASE_OPER", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.OPER].Text);
                in_node.AddString("RES_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.RES_ID].Text);


                for (int i = 0; i < spdBadData.ActiveSheet.ColumnCount; i++)
                {
                    if (MPCF.Trim(spdBadData.ActiveSheet.Cells[0, i].Text) != "" && MPCF.ToInt(spdBadData.ActiveSheet.Cells[0, i].Text) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_TBL");
                        loss_list.AddString("CODE", spdBadData.ActiveSheet.ColumnFooter.Cells[0, i].Text);
                        loss_list.AddDouble("VALUE", MPCF.ToInt(spdBadData.ActiveSheet.Cells[0, i].Text));
                        loss_list.AddChar("QTY_FLAG", '1');
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Loss", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    // MPCR.ShowSuccessMsg(out_node);
                    return true;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }



        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


        #region " Event Definition "

        private void spdDataCollection_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            // if (!b_loaded)
            //     return;

            try
            {
                int iRow = e.Row;
                int iCol = e.Column;

                // b_loaded = false;
                if (e.Column == (int)COLLECTION_DATA.JUDGE_PASS)
                {
                    if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value = " ";
                        spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.WAIT_QTY].Value = false;

                    }
                    else if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "FALSE")
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value = true;

                    }
                }

                else if (e.Column == (int)COLLECTION_DATA.WAIT_QTY)
                {
                    if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value = " ";
                        spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                    }
                    else if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "FALSE")
                    {
                        if (MPCF.Trim(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_LOSS].Text) == "")
                        {
                            spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value = true;
                        }
                    }
                }
                else if (e.Column == (int)COLLECTION_DATA.COPY)
                {
                    if (txtCopyRow.Text == iRow.ToString())
                    {
                        txtCopyRow.Text = "";
                        spdDataCollection.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                    }
                    else
                    {
                        txtCopyRow.Text = iRow.ToString();


                        for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                        {
                            spdDataCollection.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                        }

                        spdDataCollection.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(217, 229, 255);
                    }


                }
                else if (e.Column == (int)COLLECTION_DATA.PASTE)
                {



                    if (MPCF.Trim(txtCopyRow.Text).Length != 0)
                    {
                        int icopyRow = MPCF.ToInt(txtCopyRow.Text);

                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC014].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC014].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC006].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC006].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC054].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC054].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC055].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC055].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC056].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC056].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC057].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC057].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC058].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC058].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC059].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC059].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC060].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC060].Value;
                        spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.POQC061].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.POQC061].Value;
                        // spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.JUDGE_PASS].Value;
                        // spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value;
                        // spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.WAIT_QTY].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.WAIT_QTY].Value;
                        // spdDataCollection_Sheet1.Cells[iRow, (int)COLLECTION_DATA.JUDGE_COMMENT].Value = spdDataCollection_Sheet1.Cells[icopyRow, (int)COLLECTION_DATA.JUDGE_COMMENT].Value;

                    }
                }

                QtyCount("1");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private void spdDataCollection_Change(object sender, ChangeEventArgs e)
        {

            int iRow = e.Row;
            int iCol = e.Column;




            //  b_loaded = false;

            if (e.Column == (int)COLLECTION_DATA.JUDGE_LOSS)
            {
                if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().Trim() != "")
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.WAIT_QTY].Value = false;


                }
                else
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.WAIT_QTY].Value = true;
                }

                QtyCount("1");


            }
            else
            {
                txtEditFlag.Text = "Y";
            }



        }


        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 0)
            {

            }
            else
            {

            }
        }




        private void frmTranInpPdcPress_Load(object sender, EventArgs e)
        {

            cdvDept.Text = CSGC.CP_AREA_PDC;

            defModelData = new DefaultSheetDataModel(0, spdDataCollection.ActiveSheet.Columns.Count);
            spdDataCollection.ActiveSheet.Models.Data = defModelData;
            this.defModelData.Changed += new SheetDataModelEventHandler(this.defModelData_Changed);


        }

        private void defModelData_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            // if (!b_allow_changed)
            //     return;


            int iRow = e.Row;
            int iCol = e.Column;



            if (e.Column == (int)COLLECTION_DATA.JUDGE_LOSS)
            {

                if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().Trim() != "")
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.WAIT_QTY].Value = false;
                }
            }




        }

        private void spdDataCollection_EditModeOff(object sender, EventArgs e)
        {


            int iActiveRow = spdDataCollection.ActiveSheet.ActiveRowIndex;
            int iActiveCol = spdDataCollection.ActiveSheet.ActiveColumnIndex;
            int iRowCount = spdDataCollection.ActiveSheet.RowCount;
            int iAutoInput = MPCF.ToInt(txtAutoInput.Text);
            int iCopyRow = 0;
            /*
                        if (iRowCount >= iActiveRow + 1)
                        {
                            spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, iActiveCol);
                        }
            */

            // 20220428 합격NG 대기 정리되기전에 저장하면 중복등록 발생할수 있어서 editMode Off전까지 저장 안되도록 수정. 
            btnDatSave.Enabled = true;

            for (int iRow = 1; iRow < iAutoInput; iRow++)
            {
                if (iRowCount == iActiveRow + iRow)
                {
                    return;
                }

                switch (iActiveCol)
                {
                    case (int)COLLECTION_DATA.POQC014:
                    case (int)COLLECTION_DATA.POQC006:
                    case (int)COLLECTION_DATA.POQC054:
                    case (int)COLLECTION_DATA.POQC055:
                    case (int)COLLECTION_DATA.POQC056:
                    case (int)COLLECTION_DATA.POQC057:
                    case (int)COLLECTION_DATA.POQC058:
                    case (int)COLLECTION_DATA.POQC059:
                    case (int)COLLECTION_DATA.POQC060:
                    case (int)COLLECTION_DATA.POQC061:



                        iCopyRow = iActiveRow + iRow;

                        spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value = spdDataCollection.ActiveSheet.Cells[iActiveRow, iActiveCol].Value;


                        break;
                }





                /*

                if (iActiveCol == (int)COLLECTION_DATA.JUDGE_PASS)
                {
                    if (spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value = " ";
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.WAIT_QTY].Value = false;

                    }
                    else if (spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value.ToString().ToUpper() == "FALSE")
                    {
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value = true;

                    }
                }
                else if (iActiveCol == (int)COLLECTION_DATA.WAIT_QTY)
                {
                    if (spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value = " ";
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                    }
                    else if (spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value.ToString().ToUpper() == "FALSE")
                    {
                        if (MPCF.Trim(spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.JUDGE_LOSS].Text) == "")
                        {
                            spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value = true;
                        }
                    }
                }
                else if(iActiveCol == (int)COLLECTION_DATA.JUDGE_LOSS)
                {
                    if (spdDataCollection.ActiveSheet.Cells[iCopyRow, iActiveCol].Value.ToString().Trim() != "")
                    {
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.WAIT_QTY].Value = false;


                    }
                    else
                    {
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                        spdDataCollection.ActiveSheet.Cells[iCopyRow, (int)COLLECTION_DATA.WAIT_QTY].Value = true;
                    }



                }

                */





            }

            if (iRowCount >= iActiveRow + iAutoInput)
            {
                spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + iAutoInput, iActiveCol);
            }



        }

        private void spdDataCollection_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }



                for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                {

                    spdDataCollection.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdDataCollection.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                if (txtCopyRow.Text != "")
                {
                    spdDataCollection.ActiveSheet.Rows[MPCF.ToInt(txtCopyRow.Text)].BackColor = Color.FromArgb(217, 229, 255);
                }




            }
            catch
            {

            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void ultraGroupBox1_Click(object sender, EventArgs e)
        {

        }


        private void cdvWorkType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWorkType.Init();
                MPCF.InitListView(cdvWorkType.GetListView);
                cdvWorkType.Columns.Add("Key_1", 50, HorizontalAlignment.Left);
                cdvWorkType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkType.Columns.Add("Count", 0, HorizontalAlignment.Left);
                cdvWorkType.SelectedSubItemIndex = 0;
                cdvWorkType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvWorkType.GetListView, '1', CSGC.CP_GCM_WORK_TYPE) == false)
                {
                    return;
                }

                cdvWorkType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }

        private void cdvWorker_ButtonPress(object sender, EventArgs e)
        {




            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvWorker.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';



            in_node.AddString("SQL", "SELECT A.WORKER_ID AS CODE, "
                                               + "       B.WORKER_DESC AS VALUE "
                                               + "  FROM CWIPWRKGRP  A  INNER JOIN CWIPWRKDEF B ON A.FACTORY = B.FACTORY AND A.WORKER_ID = B.WORKER_ID"
                                               + "  WHERE A.FACTORY = '" + MPGV.gsFactory + "' "
                                               + "   AND A.OPER = 'OP16010'"
                                               //  + "   AND A.OPER = '" + MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.OPER].Value) + "'"
                                               + " ORDER BY 1,2");

            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvWorker.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

            //return true;


        }

        private void cdvMC_ButtonPress(object sender, EventArgs e)
        {

            try
            {


                cdvMC.Init();
                MPCF.InitListView(cdvMC.GetListView);
                cdvMC.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMC.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMC.SelectedSubItemIndex = 0;
                cdvMC.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvMC.GetListView, '1', "OP16010") == false)
                    return;

                cdvMC.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            ClearList("LOT_INFO");
            ViewLotList();
        }


        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            /*
            string s_lot_id = "";
            string s_oper = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                spdDataCollection_Sheet1.RowCount = 0;

                s_lot_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;
                s_oper = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.OPER].Text;

                // ViewBomInfo(s_lot_id, s_oper);
              //  ViewEdcData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            */
        }

        private void spdLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {

                switch (e.Column)
                {
                    case (int)LOT_INFO.START_END:

                        if (spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.LOT_STATUS].Text == "WAIT")
                        {
                            SaveProcess('1');
                        }
                        else
                        {
                            SaveProcess('2');
                        }


                        break;

                    case (int)LOT_INFO.BOM_INPUT:

                        try
                        {
                            frmTranMaterialInputByLevel popup = new frmTranMaterialInputByLevel();

                            popup.StartPosition = FormStartPosition.CenterParent;
                            popup.sArea_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.AREA_ID].Text;
                            popup.sArea_desc = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.AREA_DESC].Text;
                            popup.sSub_area_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.SUB_AREA_ID].Text;
                            popup.sSub_area_desc = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.SUB_AREA_DESC].Text;
                            popup.sOper_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.OPER].Text;
                            popup.sOper_desc = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.OPER_DESC].Text;
                            //popup.sRes_id = cdvResource.Text;
                            //popup.sRes_desc = cdvResource.DisplayText;
                            popup.sOrder_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.ORDER_ID].Text;

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


                        break;
                }




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void spdLotList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            /*
            if( beforeRow == e.Range.Row)
            {
                return;
            }
            */

            if (txtEditFlag.Text == "Y")
            {
                if (MPCF.ShowMsgBox("Do you wish to Changing Row?(InputData No Save)" + "\r\n" + "입력데이터를 저장하지 않으셨습니다. 그래도 진행하시겠습니까?", MessageBoxButtons.YesNo, 2) == DialogResult.No)
                {
                    e.Range.Row = beforeRow;
                    e.Range.Column = beforeCol;
                    spdLotList_Sheet1.ActiveRowIndex = beforeRow;
                    spdLotList_Sheet1.ActiveColumnIndex = beforeCol;

                    //    spdDataCollection_Sheet1.SetActiveCell(beforeRow, beforeCol);
                    //    spdDataCollection_Sheet1.ActiveCell.ResetCanFocus();

                }
                else
                {
                    ViewEdcData();
                }
            }
            else
            {
                ViewEdcData();
            }

            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
            {

                spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
            }

            spdLotList.ActiveSheet.Rows[e.Range.Row].BackColor = Color.FromArgb(255, 192, 255);


            beforeRow = e.Range.Row;
            beforeCol = e.Range.Column;

        }

        private void btnDatSave_Click(object sender, EventArgs e)
        {
            if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text == "")
            {

                MessageBox.Show("Please start button first." + "\r\n" + "START 후 등록 가능합니다.");

                return;
            }


            if (SaveLossData() == false)
            {

            }

            if (EdcDataSave() == false)
            {
                return;
            }

            ViewLotList();

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void txtAutoInput_TextChanged(object sender, EventArgs e)
        {
            int LotQty = MPCF.ToInt(MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.WAIT_QTY].Value));
            int QtyChk = 0;

            bool isNum = int.TryParse(txtAutoInput.Text, out QtyChk);

            if (!isNum)
            {
                MPCF.ShowMsgBox("is Not Number (숫자만 입력 가능합니다.)");
                txtAutoInput.Text = "0";
            }




            if (MPCF.ToInt(txtAutoInput.Text) > LotQty)
            {
                MPCF.ShowMsgBox("Request Qty Over(요청수량보다 클수 없습니다.)");
                txtAutoInput.Text = "0";
            }
        }

        private void spdDataCollection_EditModeOn(object sender, EventArgs e)
        {
            // 20220428 합격NG 대기 정리되기전에 저장하면 중복등록 발생할수 있어서 editMode Off전까지 저장 안되도록 수정. 
            btnDatSave.Enabled = false;
        }

        private void spdDataCollection_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {


        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {
                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "TEST_ITEM_ISSUE2";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "품목별 TEST및RND 자재기타입출고 계정";
                    popup.sComment = "해당화면에서 등록된 품목은 생산진행시 자재소요에대해서 등록된 기타출고 계정으로 출고됩니다.";

                }
                else
                {
                    popup.sTable_name_desc = "Test / Rnd Etc Account";
                    popup.sComment = "Items registered will be Inputed to ETC In/Out accounts registered for material requirements during production.";

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

        #endregion
    }

}
