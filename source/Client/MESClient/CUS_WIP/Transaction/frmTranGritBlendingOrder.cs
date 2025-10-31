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
using CUS_COM.Reports;

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
            BLD_QTY,                // 6 : 진행중 BLD 수량                 
            INPUT_QTY_1,            // 7 : 생산수량  
            CREATE_TIME,            // 8 : 생산시간
            PSD_UP_VALUE,           // 9 : '+'
            SS_VALUE,               //10 : SS
            OS_VALUE,               //11 : OS
            PSD_LO_VALUE,           //12 : '-' 
            TI_VALUE,               //13 : TI
            BI_VALUE,               //14 : BI
            TTI_VALUE,              //15 : TTI
            MA_VALUE,               //16 : MA
            HLT_VALUE,              //17 : HLT
            EILLPT_VALUE,           //18 : EILLPT        
            OPER,                   //19 : 공정 
            LOT_TYPE,               //20 :
            COMMENT                 //21 :
        }

        private enum BLD_INFO
        {
            RATE,                   // 0 : 중량 비율
            QTY_1,                  // 1 : 생산수량               
            PSD_UP_VALUE,           // 2 : '+'
            SS_VALUE,               // 3 : SS
            OS_VALUE,               // 4 : OS
            PSD_LO_VALUE,           // 5 : '-' 
            TI_VALUE,               // 6 : TI
            BI_VALUE,               // 7 : BI
            TTI_VALUE,              // 8 : TTI
            MA_VALUE,               // 9 : MA
            HLT_VALUE,              //10 : HLT
            EILLPT_VALUE            //11 : EILLPT
        }

        #endregion

        #region " Variable Definition "

        string sBlendingMapping_yn = "";

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
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
        public bool ViewSize(Control control)
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
                dvcArgu[1].sCondition_Value = cdvDept.Text;


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
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

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

                    //블랜딩 맵핑여부 확인
                    sBlendingMapping_yn = dt.Rows[i]["BLD_YN"].ToString();

                    if (sBlendingMapping_yn == "Y")
                    {
                        cdvLotKey.Text = dt.Rows[i]["CREATE_LOT_KEY"].ToString();
                        txtLotID.Text = dt.Rows[i]["LOT_ID"].ToString();
                    }
                    else
                    {
                        cdvLotKey.Text = "";
                        txtLotID.Text = "";
                    }

                    txtComment.Text = dt.Rows[0]["ORDER_DESC"].ToString();
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
                    sSpread.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, false);
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];                    
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.QTY_1].Value = dt.Rows[i]["QTY_1"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.BLD_QTY].Value = dt.Rows[i]["BLD_QTY"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Value = dt.Rows[i]["INPUT_QTY"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_UP_VALUE].Value = dt.Rows[i]["PSD_UP_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.SS_VALUE].Value = dt.Rows[i]["SS_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.OS_VALUE].Value = dt.Rows[i]["OS_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_LO_VALUE].Value = dt.Rows[i]["PSD_LO_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TI_VALUE].Value = dt.Rows[i]["TI_VALUE"];                    
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.BI_VALUE].Value = dt.Rows[i]["BI_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TTI_VALUE].Value = dt.Rows[i]["TTI_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MA_VALUE].Value = dt.Rows[i]["MA_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.HLT_VALUE].Value = dt.Rows[i]["HLT_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.EILLPT_VALUE].Value = dt.Rows[i]["EILLPT_VALUE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    sSpread.ActiveSheet.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }
                MPCF.FitColumnHeader(sSpread);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewOrderLotList()
        {
            int iRow = 0;
            FarPoint.Win.Spread.FpSpread spdSeet = new FarPoint.Win.Spread.FpSpread();

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

                if (TPDR.GetDataOne("", ref dt, "CWIP2014-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    MPCF.ClearList(spdLotList2);
                    MPCF.ClearList(spdLotList3);
                    MPCF.ClearList(spdLotList4);
                    MPCF.ClearList(spdLotList5);
                    return;
                }

                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdLotList2);
                MPCF.ClearList(spdLotList3);
                MPCF.ClearList(spdLotList4);
                MPCF.ClearList(spdLotList5);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 1)
                        spdSeet = spdLotList;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 2)
                        spdSeet = spdLotList2;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 3)
                        spdSeet = spdLotList3;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 4)
                        spdSeet = spdLotList4;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 5)
                        spdSeet = spdLotList5;

                    iRow = spdSeet.ActiveSheet.RowCount;
                    spdSeet.ActiveSheet.RowCount++;

                    spdSeet.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, false);
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.QTY_1].Value = dt.Rows[i]["QTY_1"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.BLD_QTY].Value = dt.Rows[i]["BLD_QTY"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.INPUT_QTY_1].Value = dt.Rows[i]["INPUT_QTY"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.PSD_UP_VALUE].Value = dt.Rows[i]["PSD_UP_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.SS_VALUE].Value = dt.Rows[i]["SS_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.OS_VALUE].Value = dt.Rows[i]["OS_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.PSD_LO_VALUE].Value = dt.Rows[i]["PSD_LO_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.TI_VALUE].Value = dt.Rows[i]["TI_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.BI_VALUE].Value = dt.Rows[i]["BI_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.TTI_VALUE].Value = dt.Rows[i]["TTI_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.MA_VALUE].Value = dt.Rows[i]["MA_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.HLT_VALUE].Value = dt.Rows[i]["HLT_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.EILLPT_VALUE].Value = dt.Rows[i]["EILLPT_VALUE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdSeet.ActiveSheet.Cells[iRow, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                                  
                }
                MPCF.FitColumnHeader(spdLotList);
                MPCF.FitColumnHeader(spdLotList2);
                MPCF.FitColumnHeader(spdLotList3);
                MPCF.FitColumnHeader(spdLotList4);
                MPCF.FitColumnHeader(spdLotList5);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewOrderAvg()
        {
            FarPoint.Win.Spread.FpSpread spdSeet = new FarPoint.Win.Spread.FpSpread();

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

                CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                CSCF.ClearSpread(spdAvgData1, 0, 0, "0");
                CSCF.ClearSpread(spdAvgData2, 0, 0, "0");
                CSCF.ClearSpread(spdAvgData3, 0, 0, "0");

                if (TPDR.GetDataOne("", ref dt, "CWIP2014-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 1)
                        spdSeet = spdAvgData1;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 2)
                        spdSeet = spdAvgData2;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 3)
                        spdSeet = spdAvgData3;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 4)
                        spdSeet = spdAvgData4;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 5)
                        spdSeet = spdAvgData5;
                    else if (MPCF.ToInt(dt.Rows[i]["SHEET_NO"].ToString()) == 99)
                        spdSeet = spdAvgData;

                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value = dt.Rows[i]["QTY_1"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Value = dt.Rows[i]["QTY_RATE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value = dt.Rows[i]["PSD_UP_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value = dt.Rows[i]["SS_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value = dt.Rows[i]["OS_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value = dt.Rows[i]["PSD_LO_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value = dt.Rows[i]["TI_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value = dt.Rows[i]["BI_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value = dt.Rows[i]["TTI_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value = dt.Rows[i]["MA_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value = dt.Rows[i]["HLT_VALUE"];
                    spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value = dt.Rows[i]["EILLPT_VALUE"];
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private void ViewOrderReport()
        {
            FarPoint.Win.Spread.FpSpread spdSeet = new FarPoint.Win.Spread.FpSpread();

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = cdvOrder.Text;


                if (TPDR.GetDataOne("", ref dt, "CWIP2014-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }
     
                DevReport.PreviewXtraReport(dt, "PRD160P");


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
            double dOrderQty = 0;
            int iSheetCount = 5;
            FarPoint.Win.Spread.FpSpread spdSeet = new FarPoint.Win.Spread.FpSpread();

            try
            {
                dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[0, (int)WORKORDER.ORDER_QTY].Text);

                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode Lot_list;
                TRSNode Avg_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("AREA_ID", cdvDept.Text);
                //in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddString("CREATE_LOT_KEY", cdvLotKey.Text);
                in_node.AddString("COMMENT", txtComment.Text);
                in_node.AddDouble("SUM_QTY", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0,(int)BLD_INFO.QTY_1].Text));


                for (int k = 0; k < iSheetCount; k++)
                {
                    if (k == 0)
                        spdSeet = spdLotList;
                    else if (k == 1)
                        spdSeet = spdLotList2;
                    else if (k == 2)
                        spdSeet = spdLotList3;
                    else if (k == 3)
                        spdSeet = spdLotList4;
                    else if (k == 4)
                        spdSeet = spdLotList5;

                    for (int i = 0; i < spdSeet.ActiveSheet.RowCount; i++)
                    {
                        if (spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                        {
                            Lot_list = in_node.AddNode("LOT_TBL");
                            Lot_list.AddString("LOT_ID", spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                            Lot_list.AddString("MAT_ID", spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text);
                            Lot_list.AddString("LOT_TYPE", spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Text);
                            Lot_list.AddString("OUT_OPER", spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Text);
                            Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Text));
                            Lot_list.AddDouble("BOM_QTY", Math.Round(MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_QTY_1].Text) / dOrderQty, 5));
                            Lot_list.AddString("INPUT_TYPE", CSGC.CP_MAT_INPUT_TYPE_BOM);
                            Lot_list.AddInt("SHEET_NO", k + 1);
                            Lot_list.AddDouble("PSD_UP_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_UP_VALUE].Text));
                            Lot_list.AddDouble("SS_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.SS_VALUE].Text));
                            Lot_list.AddDouble("OS_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.OS_VALUE].Text));
                            Lot_list.AddDouble("PSD_LO_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_LO_VALUE].Text));
                            Lot_list.AddDouble("TI_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.TI_VALUE].Text));
                            Lot_list.AddDouble("BI_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.BI_VALUE].Text));
                            Lot_list.AddDouble("TTI_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.TTI_VALUE].Text));
                            Lot_list.AddDouble("MA_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.MA_VALUE].Text));
                            Lot_list.AddDouble("HLT_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.HLT_VALUE].Text));
                            Lot_list.AddDouble("EILLPT_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[i, (int)LOT_INFO.EILLPT_VALUE].Text));
                        }
                    }
                }

                for (int k = 0; k < iSheetCount; k++)
                {
                    if (k == 0)
                        spdSeet = spdAvgData1;
                    else if (k == 1)
                        spdSeet = spdAvgData2;
                    else if (k == 2)
                        spdSeet = spdAvgData3;
                    else if (k == 3)
                        spdSeet = spdAvgData4;
                    else if (k == 4)
                        spdSeet = spdAvgData5;

                    if (MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) > 0)
                    {
                        Avg_list = in_node.AddNode("AVG_TBL");
                        Avg_list.AddInt("SHEET_NO", k + 1);
                        Avg_list.AddDouble("QTY_1", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text));
                        Avg_list.AddDouble("RATE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Text));
                        Avg_list.AddDouble("PSD_UP_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Text));
                        Avg_list.AddDouble("SS_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Text));
                        Avg_list.AddDouble("OS_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Text));
                        Avg_list.AddDouble("PSD_LO_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Text));
                        Avg_list.AddDouble("TI_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Text));
                        Avg_list.AddDouble("BI_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Text));
                        Avg_list.AddDouble("TTI_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Text));
                        Avg_list.AddDouble("MA_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Text));
                        Avg_list.AddDouble("HLT_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Text));
                        Avg_list.AddDouble("EILLPT_VALUE", MPCF.ToDbl(spdSeet.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Text));
                    }

                }

                Avg_list = in_node.AddNode("AVG_TBL");
                Avg_list.AddInt("SHEET_NO", 99);
                Avg_list.AddDouble("QTY_1", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text));
                Avg_list.AddDouble("RATE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Text));
                Avg_list.AddDouble("PSD_UP_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Text));
                Avg_list.AddDouble("SS_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Text));
                Avg_list.AddDouble("OS_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Text));
                Avg_list.AddDouble("PSD_LO_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Text));
                Avg_list.AddDouble("TI_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Text));
                Avg_list.AddDouble("BI_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Text));
                Avg_list.AddDouble("TTI_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Text));
                Avg_list.AddDouble("MA_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Text));
                Avg_list.AddDouble("HLT_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Text));
                Avg_list.AddDouble("EILLPT_VALUE", MPCF.ToDbl(spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Text));

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Blending_Order", in_node, ref out_node) == false)
                    return false;
                else                
                    MPCR.ShowSuccessMsg(out_node);

                //프린트 양식 변경.
                //txtLotID.Text = out_node.GetString("LOT_ID");
                //if (MPCF.Trim(out_node.GetString("LOT_ID")) != "")
                //{
                //    PrintLable(CSGC.CP_LABEL_T_BLANDING, out_node.GetString("LOT_ID"));
                //}

                //lot으로 프린팅 된 것을 order로 프린팅 되도록 수정. _20210318_lwg
                if (MPCF.Trim(cdvOrder.Text) != "")
                {
                    ViewOrderReport();
                }

                return true;                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool CancelData()
        {
            try
            {
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                in_node.AddString("ORDER_ID", cdvOrder.Text);

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
            double dAllSumQty = 0;
            double dQty = 0;
            double dAvgPSDUP = 0;
            double dAvgSS = 0;
            double dAvgOS = 0;
            double dAvgPSDLO = 0;
            double dAvgTI = 0;
            double dAvgBI = 0;
            double dAvgTTI = 0;            
            double dAvgMA = 0;
            double dAvgHLT = 0;
            double dAvgEILL = 0;

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

                        dAvgPSDUP = dAvgPSDUP + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_UP_VALUE].Value) * dQty;
                        dAvgSS = dAvgSS + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.SS_VALUE].Value) * dQty;
                        dAvgOS = dAvgOS + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.OS_VALUE].Value) * dQty;
                        dAvgPSDLO = dAvgPSDLO + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_LO_VALUE].Value) * dQty;
                        dAvgTI = dAvgTI + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TI_VALUE].Value) * dQty;
                        dAvgBI = dAvgBI + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.BI_VALUE].Value) * dQty;
                        dAvgTTI = dAvgTTI + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.TTI_VALUE].Value) * dQty;
                        dAvgMA = dAvgMA + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.MA_VALUE].Value) * dQty;
                        dAvgHLT = dAvgHLT + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.HLT_VALUE].Value) * dQty;
                        dAvgEILL = dAvgEILL + MPCF.ToDbl(sSelectSpread.ActiveSheet.Cells[i, (int)LOT_INFO.EILLPT_VALUE].Value) * dQty;

                        ICheckCount++;
                    }
                }

                if (ICheckCount > 0)
                {
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value = dSumQty;

                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value = Math.Round(dAvgPSDUP / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value = Math.Round(dAvgSS / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value = Math.Round(dAvgOS / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value = Math.Round(dAvgPSDLO / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value = Math.Round(dAvgTI / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value = Math.Round(dAvgBI / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value = Math.Round(dAvgTTI / dSumQty, 2);                   
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value = Math.Round(dAvgMA / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value = Math.Round(dAvgHLT / dSumQty, 2);
                    sAvgSpread.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value = Math.Round(dAvgEILL / dSumQty, 2);

                    dAllSumQty = MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) +
                                 MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) +
                                 MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) +
                                 MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) +
                                 MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);

                    spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Value = (MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) / dAllSumQty) * 100;
                    spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Value = (MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) / dAllSumQty) * 100;
                    spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Value = (MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) / dAllSumQty) * 100;
                    spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Value = (MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) / dAllSumQty) * 100;
                    spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.RATE].Value = (MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value) / dAllSumQty) * 100;
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
            double dAvgPSDUP = 0;
            double dAvgSS = 0;
            double dAvgOS = 0;
            double dAvgPSDLO = 0;
            double dAvgTI = 0;
            double dAvgBI = 0;
            double dAvgTTI = 0;
            double dAvgMA = 0;
            double dAvgHLT = 0;
            double dAvgEILL = 0;

            try
            {
                if (MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgPSDUP = dAvgPSDUP + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                    dAvgOS = dAvgOS + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value) * dQty;
                    dAvgPSDLO = dAvgPSDLO + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value) * dQty;
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;                   
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgHLT = dAvgHLT + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value) * dQty;
                    dAvgEILL = dAvgEILL + MPCF.ToDbl(spdAvgData1.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value) * dQty;
                }

                if (MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgPSDUP = dAvgPSDUP + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                    dAvgOS = dAvgOS + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value) * dQty;
                    dAvgPSDLO = dAvgPSDLO + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value) * dQty;
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgHLT = dAvgHLT + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value) * dQty;
                    dAvgEILL = dAvgEILL + MPCF.ToDbl(spdAvgData2.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value) * dQty;
                }

                if (MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgPSDUP = dAvgPSDUP + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                    dAvgOS = dAvgOS + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value) * dQty;
                    dAvgPSDLO = dAvgPSDLO + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value) * dQty;
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgHLT = dAvgHLT + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value) * dQty;
                    dAvgEILL = dAvgEILL + MPCF.ToDbl(spdAvgData3.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value) * dQty;
                }

                if (MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgPSDUP = dAvgPSDUP + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                    dAvgOS = dAvgOS + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value) * dQty;
                    dAvgPSDLO = dAvgPSDLO + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value) * dQty;
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgHLT = dAvgHLT + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value) * dQty;
                    dAvgEILL = dAvgEILL + MPCF.ToDbl(spdAvgData4.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value) * dQty;
                }

                if (MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Text) != 0)
                {
                    dSumQty = dSumQty + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dQty = MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value);
                    dAvgPSDUP = dAvgPSDUP + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value) * dQty;
                    dAvgSS = dAvgSS + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value) * dQty;
                    dAvgOS = dAvgOS + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value) * dQty;
                    dAvgPSDLO = dAvgPSDLO + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value) * dQty;
                    dAvgTI = dAvgTI + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value) * dQty;
                    dAvgBI = dAvgBI + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value) * dQty;
                    dAvgTTI = dAvgTTI + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value) * dQty;
                    dAvgMA = dAvgMA + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value) * dQty;
                    dAvgHLT = dAvgHLT + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value) * dQty;
                    dAvgEILL = dAvgEILL + MPCF.ToDbl(spdAvgData5.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value) * dQty;
                }

                if (dSumQty != 0)
                {
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value = dSumQty;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value = Math.Round(dAvgPSDUP / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value = Math.Round(dAvgSS / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value = Math.Round(dAvgOS / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value = Math.Round(dAvgPSDLO / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value = Math.Round(dAvgTI / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value = Math.Round(dAvgBI / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value = Math.Round(dAvgTTI / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value = Math.Round(dAvgMA / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value = Math.Round(dAvgHLT / dSumQty, 2);
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value = Math.Round(dAvgEILL / dSumQty, 2);
                }
                else
                {
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.QTY_1].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_UP_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.SS_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.OS_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.PSD_LO_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TI_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.BI_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.TTI_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.MA_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.HLT_VALUE].Value = 0;
                    spdAvgData.ActiveSheet.Cells[0, (int)BLD_INFO.EILLPT_VALUE].Value = 0;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //프린팅 함수
        private void PrintLable(string sPrintLabel, string sLotID)
        {
            try
            {
                TRSNode print_node = new TRSNode("Print_In");
                TRSNode Print_Lot_list;
                MPCR.SetInMsg(print_node);

                Print_Lot_list = print_node.AddNode("LOT_LIST");
                Print_Lot_list.AddString("LOT_ID", sLotID);
                          
                CSCF.ViewLabelList(sPrintLabel, print_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return false;
                //}

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

                        //if (MPCF.Trim(txtCreateLotKey.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCreateLotKey.Text + "]");
                        //    txtCreateLotKey.Focus();
                        //    return false;
                        //}

                        break;

                    case CSGC.CHECK.CANCEL:


                        if (MPCF.Trim(cdvOrder.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                            cdvOrder.Focus();
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
                        CSCF.ClearSpread(spdAvgData4, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData5, 0, 0, "0");
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLotList2);
                        MPCF.ClearList(spdLotList3);
                        MPCF.ClearList(spdLotList4);
                        MPCF.ClearList(spdLotList5);
                        break;

                    case "SAVE":

                        cdvOrder.Text = "";
                        cdvLotKey.Text = "";

                        MPCF.ClearList(spdWorkOrder);
                        CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData1, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData2, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData3, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData4, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData5, 0, 0, "0");
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLotList2);
                        MPCF.ClearList(spdLotList3);
                        MPCF.ClearList(spdLotList4);
                        MPCF.ClearList(spdLotList5);
                        break;

                    case "ALL":

                        cdvOrder.Text = "";
                        cdvWarehouse.Text = "";
                        cdvSize.Text = "";
                        cdvWarehouse2.Text = "";
                        cdvSize2.Text = "";
                        cdvWarehouse3.Text = "";
                        cdvSize3.Text = "";
                        cdvLotKey.Text = "";
                        txtLotID.Text = "";

                        MPCF.ClearList(spdWorkOrder);
                        CSCF.ClearSpread(spdAvgData, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData1, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData2, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData3, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData4, 0, 0, "0");
                        CSCF.ClearSpread(spdAvgData5, 0, 0, "0");
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLotList2);
                        MPCF.ClearList(spdLotList3);
                        MPCF.ClearList(spdLotList4);
                        MPCF.ClearList(spdLotList5);
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
                //cdvOrder.Text = "";
                //MPCF.ClearList(spdWorkOrder);
                //CSCF.ClearSpread(spdAvgData, 0, 0, "0");         
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
                if (MPCF.Trim(cdvOrder.Text) != "")
                {
                    ViewOrder();

                    if (sBlendingMapping_yn == "Y")
                    {
                        ViewOrderLotList();
                        ViewOrderAvg();
                    }
                }
                else
                {
                    sBlendingMapping_yn = "N";
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvOrder_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    ViewOrder();

                    if (sBlendingMapping_yn == "Y")
                    {
                        ViewOrderLotList();
                        ViewOrderAvg();
                    }
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

        private void cdvSize4_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvSize4.Init();
                MPCF.InitListView(cdvSize4.GetListView);
                cdvSize4.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvSize4.SelectedSubItemIndex = 0;

                if (ViewSize(cdvSize4.GetListView) == false)
                {
                    return;
                }

                cdvSize4.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvSize5_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvSize5.Init();
                MPCF.InitListView(cdvSize5.GetListView);
                cdvSize5.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvSize5.SelectedSubItemIndex = 0;

                if (ViewSize(cdvSize5.GetListView) == false)
                {
                    return;
                }

                cdvSize5.InsertEmptyRow(0, 1);
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return;
                //}

                cdvWarehouse.Init();
                MPCF.InitListView(cdvWarehouse.GetListView);
                cdvWarehouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse.SelectedSubItemIndex = 0;
                cdvWarehouse.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, 'K', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return;
                //}

                cdvWarehouse2.Init();
                MPCF.InitListView(cdvWarehouse2.GetListView);
                cdvWarehouse2.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse2.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse2.SelectedSubItemIndex = 0;
                cdvWarehouse2.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse2.GetListView, 'K', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return;
                //}

                cdvWarehouse3.Init();
                MPCF.InitListView(cdvWarehouse3.GetListView);
                cdvWarehouse3.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse3.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse3.SelectedSubItemIndex = 0;
                cdvWarehouse3.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse3.GetListView, 'K', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
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

        private void cdvWarehouse4_ButtonPress(object sender, EventArgs e)
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return;
                //}

                cdvWarehouse4.Init();
                MPCF.InitListView(cdvWarehouse4.GetListView);
                cdvWarehouse4.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse4.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse4.SelectedSubItemIndex = 0;
                cdvWarehouse4.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse4.GetListView, 'K', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvWarehouse4.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvWarehouse5_ButtonPress(object sender, EventArgs e)
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return;
                //}

                cdvWarehouse5.Init();
                MPCF.InitListView(cdvWarehouse5.GetListView);
                cdvWarehouse5.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse5.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse5.SelectedSubItemIndex = 0;
                cdvWarehouse5.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse5.GetListView, 'K', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvWarehouse5.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvLotKey_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLotKey.Init();
                MPCF.InitListView(cdvLotKey.GetListView);
                cdvLotKey.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvLotKey.Columns.Add("Desc", 100, HorizontalAlignment.Left);
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

        private void spdWorkOrder_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;           
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
               
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string sLotID = "";

            try
            {
                if (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                {
                    //CMN420 ERROR -수량은 0보다 커야 합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(420));
                    spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                    return;
                }

                sLotID = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                for (int i = 0; i < spdLotList2.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList3.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                for (int i = 0; i < spdLotList4.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                for (int i = 0; i < spdLotList5.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                fnCalAvg(spdLotList, spdAvgData1);

                if (spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                {
                    if (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                    {
                        spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    }
                    else
                    {
                        spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = false;
                    }

                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = false;                    
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = false;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = false;
                }
                else
                {
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = true;
                    spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            double dLot_qty = 0;
            double dInput_qty = 0;
            double dBld_qty = 0;

            try
            {
                if (e.Column == (int)LOT_INFO.INPUT_QTY_1 || e.Column == (int)LOT_INFO.PSD_UP_VALUE || e.Column == (int)LOT_INFO.SS_VALUE
                    || e.Column == (int)LOT_INFO.OS_VALUE || e.Column == (int)LOT_INFO.PSD_LO_VALUE || e.Column == (int)LOT_INFO.TI_VALUE
                    || e.Column == (int)LOT_INFO.BI_VALUE || e.Column == (int)LOT_INFO.TTI_VALUE || e.Column == (int)LOT_INFO.MA_VALUE
                    || e.Column == (int)LOT_INFO.HLT_VALUE || e.Column == (int)LOT_INFO.EILLPT_VALUE)
                {
                    if (e.Column == (int)LOT_INFO.INPUT_QTY_1)
                    {
                        dLot_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text);
                        dInput_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Text);
                        dBld_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text);

                        if (dInput_qty > dLot_qty - dBld_qty)
                        {
                            //CMN420 ERROR -수량은 0보다 커야 합니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(420));
                            spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.INPUT_QTY_1, dLot_qty - dBld_qty);
                            return;
                        }
                    }

                    fnCalAvg(spdLotList, spdAvgData1);
                }
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
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList2_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string sLotID = "";

            try
            {
                if (MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                {
                    //CMN420 ERROR -수량은 0보다 커야 합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(420));
                    spdLotList2.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                    return;
                }

                sLotID = spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList2.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList3.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList2.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList4.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList2.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList5.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList2.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                fnCalAvg(spdLotList2, spdAvgData2);

                if (spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                {
                    if (MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                    {
                        spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    }
                    else
                    {
                        spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = false;
                    }

                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = false;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = false;
                }
                else
                {
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = true;
                    spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList2_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            double dLot_qty = 0;
            double dInput_qty = 0;
            double dBld_qty = 0;

            try
            {
                if (e.Column == (int)LOT_INFO.INPUT_QTY_1 || e.Column == (int)LOT_INFO.PSD_UP_VALUE || e.Column == (int)LOT_INFO.SS_VALUE
                    || e.Column == (int)LOT_INFO.OS_VALUE || e.Column == (int)LOT_INFO.PSD_LO_VALUE || e.Column == (int)LOT_INFO.TI_VALUE
                    || e.Column == (int)LOT_INFO.BI_VALUE || e.Column == (int)LOT_INFO.TTI_VALUE || e.Column == (int)LOT_INFO.MA_VALUE
                    || e.Column == (int)LOT_INFO.HLT_VALUE || e.Column == (int)LOT_INFO.EILLPT_VALUE)
                {
                    if (e.Column == (int)LOT_INFO.INPUT_QTY_1)
                    {
                        dLot_qty = MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text);
                        dInput_qty = MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Text);
                        dBld_qty = MPCF.ToDbl(spdLotList2.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text);

                        if (dInput_qty > dLot_qty - dBld_qty)
                        {
                            //CMN420 ERROR -수량은 0보다 커야 합니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(420));
                            spdLotList2.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.INPUT_QTY_1, dLot_qty - dBld_qty);
                            return;
                        }
                    }

                    fnCalAvg(spdLotList2, spdAvgData2);
                }
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
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList3_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string sLotID = "";

            try
            {
                if (MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                {
                    //CMN420 ERROR -수량은 0보다 커야 합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(420));
                    spdLotList3.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                    return;
                }

                sLotID = spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList3.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList2.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList3.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList4.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList3.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList5.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList3.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                fnCalAvg(spdLotList3, spdAvgData3);

                if (spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                {
                    if (MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                    {
                        spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    }
                    else
                    {
                        spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = false;
                    }

                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = false;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = false;
                }
                else
                {
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = true;
                    spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList3_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            double dLot_qty = 0;
            double dInput_qty = 0;
            double dBld_qty = 0;

            try
            {
                if (e.Column == (int)LOT_INFO.INPUT_QTY_1 || e.Column == (int)LOT_INFO.PSD_UP_VALUE || e.Column == (int)LOT_INFO.SS_VALUE
                    || e.Column == (int)LOT_INFO.OS_VALUE || e.Column == (int)LOT_INFO.PSD_LO_VALUE || e.Column == (int)LOT_INFO.TI_VALUE
                    || e.Column == (int)LOT_INFO.BI_VALUE || e.Column == (int)LOT_INFO.TTI_VALUE || e.Column == (int)LOT_INFO.MA_VALUE
                    || e.Column == (int)LOT_INFO.HLT_VALUE || e.Column == (int)LOT_INFO.EILLPT_VALUE)
                {
                    if (e.Column == (int)LOT_INFO.INPUT_QTY_1)
                    {
                        dLot_qty = MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text);
                        dInput_qty = MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Text);
                        dBld_qty = MPCF.ToDbl(spdLotList3.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text);

                        if (dInput_qty > dLot_qty - dBld_qty)
                        {
                            //CMN420 ERROR -수량은 0보다 커야 합니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(420));
                            spdLotList3.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.INPUT_QTY_1, dLot_qty - dBld_qty);
                            return;
                        }
                    }

                    fnCalAvg(spdLotList3, spdAvgData3);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList4_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList4_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string sLotID = "";

            try
            {
                if (MPCF.ToDbl(spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                {
                    //CMN420 ERROR -수량은 0보다 커야 합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(420));
                    spdLotList4.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                    return;
                }

                sLotID = spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList4.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList2.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList4.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                for (int i = 0; i < spdLotList3.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList4.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                for (int i = 0; i < spdLotList5.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList5.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList4.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                fnCalAvg(spdLotList4, spdAvgData4);

                if (spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                {
                    if (MPCF.ToDbl(spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                    {
                        spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    }
                    else
                    {
                        spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = false;
                    }

                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = false;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = false;
                }
                else
                {
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = true;
                    spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList4_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            double dLot_qty = 0;
            double dInput_qty = 0;
            double dBld_qty = 0;

            try
            {
                if (e.Column == (int)LOT_INFO.INPUT_QTY_1 || e.Column == (int)LOT_INFO.PSD_UP_VALUE || e.Column == (int)LOT_INFO.SS_VALUE
                    || e.Column == (int)LOT_INFO.OS_VALUE || e.Column == (int)LOT_INFO.PSD_LO_VALUE || e.Column == (int)LOT_INFO.TI_VALUE
                    || e.Column == (int)LOT_INFO.BI_VALUE || e.Column == (int)LOT_INFO.TTI_VALUE || e.Column == (int)LOT_INFO.MA_VALUE
                    || e.Column == (int)LOT_INFO.HLT_VALUE || e.Column == (int)LOT_INFO.EILLPT_VALUE)
                {
                    if (e.Column == (int)LOT_INFO.INPUT_QTY_1)
                    {
                        dLot_qty = MPCF.ToDbl(spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text);
                        dInput_qty = MPCF.ToDbl(spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Text);
                        dBld_qty = MPCF.ToDbl(spdLotList4.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text);

                        if (dInput_qty > dLot_qty - dBld_qty)
                        {
                            //CMN420 ERROR -수량은 0보다 커야 합니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(420));
                            spdLotList4.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.INPUT_QTY_1, dLot_qty - dBld_qty);
                            return;
                        }
                    }

                    fnCalAvg(spdLotList4, spdAvgData4);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList5_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList5_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string sLotID = "";

            try
            {
                if (MPCF.ToDbl(spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                {
                    //CMN420 ERROR -수량은 0보다 커야 합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(420));
                    spdLotList5.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                    return;
                }

                sLotID = spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList5.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }
                for (int i = 0; i < spdLotList2.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList2.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList5.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                for (int i = 0; i < spdLotList3.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList3.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList5.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                for (int i = 0; i < spdLotList4.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList4.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == sLotID)
                        {
                            //CMN509 INFO - 이 LOT은 이미 선택되어 있습니다. LOT을 확인 하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(509));
                            spdLotList5.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, false);
                            return;
                        }
                    }
                }

                fnCalAvg(spdLotList5, spdAvgData5);

                if (spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                {
                    if (MPCF.ToDbl(spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text) == MPCF.ToDbl(spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text))
                    {
                        spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    }
                    else
                    {
                        spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = false;
                    }

                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = false;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = false;
                }
                else
                {
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_UP_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.SS_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.OS_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.PSD_LO_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TI_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BI_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.TTI_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.MA_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.HLT_VALUE].Locked = true;
                    spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.EILLPT_VALUE].Locked = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList5_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            double dLot_qty = 0;
            double dInput_qty = 0;
            double dBld_qty = 0;

            try
            {
                if (e.Column == (int)LOT_INFO.INPUT_QTY_1 || e.Column == (int)LOT_INFO.PSD_UP_VALUE || e.Column == (int)LOT_INFO.SS_VALUE
                    || e.Column == (int)LOT_INFO.OS_VALUE || e.Column == (int)LOT_INFO.PSD_LO_VALUE || e.Column == (int)LOT_INFO.TI_VALUE
                    || e.Column == (int)LOT_INFO.BI_VALUE || e.Column == (int)LOT_INFO.TTI_VALUE || e.Column == (int)LOT_INFO.MA_VALUE
                    || e.Column == (int)LOT_INFO.HLT_VALUE || e.Column == (int)LOT_INFO.EILLPT_VALUE)
                {
                    if (e.Column == (int)LOT_INFO.INPUT_QTY_1)
                    {
                        dLot_qty = MPCF.ToDbl(spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.QTY_1].Text);
                        dInput_qty = MPCF.ToDbl(spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.INPUT_QTY_1].Text);
                        dBld_qty = MPCF.ToDbl(spdLotList5.ActiveSheet.Cells[e.Row, (int)LOT_INFO.BLD_QTY].Text);

                        if (dInput_qty > dLot_qty - dBld_qty)
                        {
                            //CMN420 ERROR -수량은 0보다 커야 합니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(420));
                            spdLotList5.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.INPUT_QTY_1, dLot_qty - dBld_qty);
                            return;
                        }
                    }

                    fnCalAvg(spdLotList5, spdAvgData5);
                }
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

                CSCF.ClearSpread(spdAvgData1, 0, 0, "0");

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

                CSCF.ClearSpread(spdAvgData2, 0, 0, "0");

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

                CSCF.ClearSpread(spdAvgData3, 0, 0, "0");

                ViewLotList(spdLotList3, cdvWarehouse3.Text, cdvSize3.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewLot4_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                if (MPCF.Trim(cdvWarehouse4.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse4.Focus();
                    return;
                }

                CSCF.ClearSpread(spdAvgData4, 0, 0, "0");

                ViewLotList(spdLotList4, cdvWarehouse4.Text, cdvSize4.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewLot5_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                if (MPCF.Trim(cdvWarehouse5.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse5.Focus();
                    return;
                }

                CSCF.ClearSpread(spdAvgData5, 0, 0, "0");

                ViewLotList(spdLotList5, cdvWarehouse5.Text, cdvSize5.Text);

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

                //CMN529 INFO -  Blending 작업지시 등록 정보 및 Lot뒤 문자 등록 여부  확인하세요. 계속 진행 하시겠습니까?
                if (MPCF.ShowMsgBox(MPCF.GetMessage(529), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                {
                    return;
                }

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

        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                //CMN520 INFO - Blending 작업지시 맵핑내역을 정말 삭제 하시겠습니까?
                if (MPCF.ShowMsgBox(MPCF.GetMessage(520), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                {
                    return;
                }

                if (CancelData() == true)
                {
                    ClearData("SAVE");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void btnPrint_Click(object sender, EventArgs e)
        {
            ViewOrderReport();
        }
        #endregion

    }
}
