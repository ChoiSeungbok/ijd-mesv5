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

//CWIP2014
namespace CUS_WIP
{
    public partial class frmTranGritBlendingOrder : CUS_COM.frmViewForm01
    {
        public frmTranGritBlendingOrder()
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
            MAT_VER,                // 6 : 제품 버전
            UNIT,                   // 7 : 단위
            ORDER_QTY,              // 8 : 지시수량
            PROD_QTY,               // 9 : 생산수량
            STOCK,                  //10 : 창고
            ORDER_STATUS,           //11 : 작업지시 상태
            FLOW,                   //12 : 플로우
            FLOW_DESC               //13 : 플로우명
        }

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드            
            MAT_DESC,               // 4 : 제품명
            QTY_1,                  // 5 : 생산수량           
            INPUT_QTY_1,            // 6 : 생산수량  
            CREATE_TIME,            // 7 : 생산시간
            TI_VALUE,               // 8 : TI
            BI_VALUE,               // 9 : BI
            TTI_VALUE,              //10 : TTI
            BTI_VALUE,              //11 : BTI
            MA_VALUE,               //12 : MA
            SS_VALUE,               //13 : SS
            OPER,                   //14 : 공정 
            LOT_TYPE
        }

        private enum BLD_INFO
        {
            QTY_1,                  // 1 : 생산수량           
            TI_VALUE,               // 2 : TI
            BI_VALUE,               // 3 : BI
            TTI_VALUE,              // 4 : TTI
            BTI_VALUE,              // 5 : BTI
            MA_VALUE,               // 6 : MA
            SS_VALUE,               // 7 : SS
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 사업장 정보 조회 함수
        public static bool ViewSubArea(Control control, string sArea_ID)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_ID;

                if (TPDR.GetDataOne("", ref dt, "CWIP2014-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_1"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //사이즈 정보 조회 함수
        public static bool ViewSize(Control control)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                if (TPDR.GetDataOne("", ref dt, "CWIP2014-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_1"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //작업지시 정보 조회
        private void ViewOrder()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvOrder.Text;
                
                if (TPDR.GetDataOne("", ref dt, "CWIP2014-003", dvcArgu, false, false, ref sSql) == false)
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
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_STATUS].Value = dt.Rows[i]["ORDER_STATUS"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                }
                MPCF.FitColumnHeader(spdWorkOrder);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
         
        //lot 리스트 조회
        private void ViewLotList(FarPoint.Win.Spread.FpSpread sSpread, string sOper, string sSize)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOper;

                dvcArgu[2].sCondition_ID = "C_SIZE";
                dvcArgu[2].sCondition_Value = sSize + "%";

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2014-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(sSpread);
                    return;
                }

                MPCF.ClearList(sSpread);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    sSpread.ActiveSheet.RowCount++;

                    if (MPCF.ToDbl(dt.Rows[i]["INPUT_QTY"]) == MPCF.ToDbl(dt.Rows[i]["QTY_1"]))
                        sSpread.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, false);                    
                    else
                        sSpread.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, true);

                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];                    
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.QTY_1].Value = dt.Rows[i]["QTY_1"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Value = dt.Rows[i]["INPUT_QTY"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TI_VALUE].Value = dt.Rows[i]["TI_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.BI_VALUE].Value = dt.Rows[i]["BI_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TTI_VALUE].Value = dt.Rows[i]["TTI_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.BTI_VALUE].Value = dt.Rows[i]["BTI_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MA_VALUE].Value = dt.Rows[i]["MA_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.SS_VALUE].Value = dt.Rows[i]["SS_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                }
                MPCF.FitColumnHeader(sSpread);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        //저장 함수
        private bool SaveData()
        {
            try
            {                
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode Lot_list;
                
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddString("CREATE_LOT_KEY", txtCreateLotKey.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddString("MAT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text);
                        Lot_list.AddString("LOT_TYPE", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Text);
                        Lot_list.AddString("OUT_OPER", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Text));
                    }
                }

                for (int i = 0; i < spdLotList2.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddString("MAT_ID", spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text);
                        Lot_list.AddString("LOT_TYPE", spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Text);
                        Lot_list.AddString("OUT_OPER", spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Text));
                    }
                }

                for (int i = 0; i < spdLotList3.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddString("MAT_ID", spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text);
                        Lot_list.AddString("LOT_TYPE", spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Text);
                        Lot_list.AddString("OUT_OPER", spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Text));
                    }
                }
                
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Blending_Order", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);
                
                

                return true;                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        //선택 blending 평균값 계산
        private void fnCalAvg(FarPoint.Win.Spread.FpSpread sSelectSpread, FarPoint.Win.Spread.FpSpread sAvgSpread)
        {
            double dSumQty = 0;
            double dQty = 0;
            double dAvgTI = 0;
            double dAvgBI = 0;
            double dAvgTTI = 0;
            double dAvgBTI = 0;
            double dAvgMA = 0;
            double dAvgSS = 0;
            int icount = 0;
            int ICheckCount = 0;

            try
            {               
                icount = sSelectSpread.ActiveSheet.RowCount;

                for (int i = 0; i < icount; i++)
                {
                    if (sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        dSumQty = dSumQty + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Value);
                        dQty = MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Value);
                        dAvgTI = dAvgTI + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TI_VALUE].Value) * dQty;                        
                        dAvgBI = dAvgBI + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.BI_VALUE].Value) * dQty;
                        dAvgTTI = dAvgTTI + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TTI_VALUE].Value) * dQty;
                        dAvgBTI = dAvgBTI + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.BTI_VALUE].Value) * dQty;
                        dAvgMA = dAvgMA + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MA_VALUE].Value) * dQty;
                        dAvgSS = dAvgSS + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.SS_VALUE].Value) * dQty;

                        ICheckCount++;
                    }
                }

                if (ICheckCount > 0)
                {
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value = dSumQty;

                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value = Math.Round(dAvgTI / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value = Math.Round(dAvgBI / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value = Math.Round(dAvgTTI / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.BTI_VALUE].Value = Math.Round(dAvgBTI / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value = Math.Round(dAvgMA / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value = Math.Round(dAvgSS / dSumQty, 2);
                }
                else
                {
                    CSCF.ClearSpread(sAvgSpread, 0, 0, "0");
                }

                fnSumCalAvg();
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void fnSumCalAvg()
        {
            double dSumQty = 0;
            double dQty = 0;
            double dAvgTI = 0;
            double dAvgBI = 0;
            double dAvgTTI = 0;
            double dAvgBTI = 0;
            double dAvgMA = 0;
            double dAvgSS = 0;

            try
            {
                if (MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;
                    dAvgBTI = dAvgBTI + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.BTI_VALUE].Value) * dQty;
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                }

                if (MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;
                    dAvgBTI = dAvgBTI + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.BTI_VALUE].Value) * dQty;
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                }

                if (MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;
                    dAvgBTI = dAvgBTI + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.BTI_VALUE].Value) * dQty;
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                }

                spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value = dSumQty;
                spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value = Math.Round(dAvgTI / dSumQty, 2);
                spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value = Math.Round(dAvgBI / dSumQty, 2);
                spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value = Math.Round(dAvgTTI / dSumQty, 2);
                spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.BTI_VALUE].Value = Math.Round(dAvgBTI / dSumQty, 2);
                spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value = Math.Round(dAvgMA / dSumQty, 2);
                spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value = Math.Round(dAvgSS / dSumQty, 2);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크 함수
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

                switch (CHECK)
                {

                    case CSGC.CHECK.NONE:

                        break;

                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvOrder.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                            cdvOrder.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:

                        if (MPCF.Trim(cdvOrder.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                            cdvOrder.Focus();
                            return false;
                        }

                        if (MPCF.Trim(txtCreateLotKey.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCreateLotKey.Text + "]");
                            txtCreateLotKey.Focus();
                            return false;
                        }

                        break;
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        //초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {

                    case "ORDER":

                        CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData1, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData2, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData3, 0, 0, "0");
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLotList2);
                        MPCF.ClearList(spdLotList3);
                        break;

                    case "SAVE":

                        cdvOrder.Text = "";

                        MPCF.ClearList(spdWorkOrder);
                        CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData1, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData2, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData3, 0, 0, "0");
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLotList2);
                        MPCF.ClearList(spdLotList3);
                        break;

                    case "ALL":

                        cdvOrder.Text = "";
                        cdvWarehouse.Text = "";
                        cdvSize.Text = "";
                        cdvWarehouse2.Text = "";
                        cdvSize2.Text = "";
                        cdvWarehouse3.Text = "";
                        cdvSize3.Text = "";
                        txtCreateLotKey.Text = "";

                        MPCF.ClearList(spdWorkOrder);
                        CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData1, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData2, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData3, 0, 0, "0");
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLotList2);
                        MPCF.ClearList(spdLotList3);
                        break;

                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranGritBlendingOrder_Load(object sender, EventArgs e)
        {
            try
            {
                CSCF.ClearSpread(spdAvgData, 0, 0, "0");
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }

                for (int i = ((ListView)cdvDept.GetListView).Items.Count -1; i >= 0; i--)
                {
                    if (((ListView)cdvDept.GetListView).Items[i].SubItems[0].Text != CSGC.CP_AREA_GRT)
                    {
                        ((ListView)cdvDept.GetListView).Items[i].Remove();
                    }
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvWorkPlace.Text = "";
                cdvOrder.Text = "";

                MPCF.ClearList(spdWorkOrder);
                CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                //MPCF.ClearList(spdBlendingLot);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (ViewSubArea(cdvWorkPlace.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOrder.Text = "";

                MPCF.ClearList(spdWorkOrder);
                CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                //MPCF.ClearList(spdBlendingLot);                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {            
            try
            {               
                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_WorkOrder = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvOrder_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                ClearData("ORDER");

                if (MPCF.Trim(cdvOrder.Text) != "")
                {                    
                    ViewOrder();
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvSize_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvSize.Init();
                MPCF.InitListView(cdvSize.GetListView);
                cdvSize.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvSize.SelectedSubItemIndex = 0;

                if (ViewSize(cdvSize.GetListView) == false)
                {
                    return;
                }

                cdvSize.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvSize2_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvSize2.Init();
                MPCF.InitListView(cdvSize2.GetListView);
                cdvSize2.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvSize2.SelectedSubItemIndex = 0;

                if (ViewSize(cdvSize2.GetListView) == false)
                {
                    return;
                }

                cdvSize2.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvSize3_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvSize3.Init();
                MPCF.InitListView(cdvSize3.GetListView);
                cdvSize3.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvSize3.SelectedSubItemIndex = 0;

                if (ViewSize(cdvSize3.GetListView) == false)
                {
                    return;
                }

                cdvSize3.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvWarehouse_ButtonPress(object sender, EventArgs e)
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

                cdvWarehouse.Init();
                MPCF.InitListView(cdvWarehouse.GetListView);
                cdvWarehouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse.SelectedSubItemIndex = 0;
                cdvWarehouse.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvWarehouse.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvWarehouse2_ButtonPress(object sender, EventArgs e)
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

                cdvWarehouse2.Init();
                MPCF.InitListView(cdvWarehouse2.GetListView);
                cdvWarehouse2.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse2.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse2.SelectedSubItemIndex = 0;
                cdvWarehouse2.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse2.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvWarehouse2.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvWarehouse3_ButtonPress(object sender, EventArgs e)
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

                cdvWarehouse3.Init();
                MPCF.InitListView(cdvWarehouse3.GetListView);
                cdvWarehouse3.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse3.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse3.SelectedSubItemIndex = 0;
                cdvWarehouse3.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse3.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvWarehouse3.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdWorkOrder_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            //string sOrder_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                //for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                //{
                //    spdWorkOrder.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                //}

                //spdWorkOrder.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                //sOrder_id = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.ORDER_ID].Text;                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
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
                        fnCalAvg(spdLotList, spdAvgData1);
                    }                    
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                fnCalAvg(spdLotList, spdAvgData1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList2_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList2, 0, 0, true, true);
                        fnCalAvg(spdLotList2, spdAvgData2);
                    }
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList2_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                fnCalAvg(spdLotList2, spdAvgData2);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList3_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList3, 0, 0, true, true);
                        fnCalAvg(spdLotList3, spdAvgData3);
                    }
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList3_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                fnCalAvg(spdLotList3, spdAvgData3);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewLot_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return;
                }

                ViewLotList(spdLotList, cdvWarehouse.Text, cdvSize.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewLot2_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                if (MPCF.Trim(cdvWarehouse2.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse2.Focus();
                    return;
                }

                ViewLotList(spdLotList2, cdvWarehouse2.Text, cdvSize2.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewLot3_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                if (MPCF.Trim(cdvWarehouse3.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse3.Focus();
                    return;
                }

                ViewLotList(spdLotList3, cdvWarehouse3.Text, cdvSize3.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //초기화버튼
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업지시 조회
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewOrder();
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

                if (SaveData() == true)
                {
                    ClearData("SAVE");
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
