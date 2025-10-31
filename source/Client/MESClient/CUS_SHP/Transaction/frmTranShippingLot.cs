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
using CUS_COM.Reports;

namespace CUS_SHP
{
    public partial class frmTranShippingLot : CUS_COM.frmTranForm01
    {
        public frmTranShippingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum SHIP_MST
        {
            CHK,                    // 1 : CHECK
            SHIP_ORDER_ID,          // 2 : 출하 지시 번호
            SHIP_ORD_DATE,          // 3 : 출하 지시 일자
            CUSTOMER_ID,            // 4 : 거래선 ID
            CUSTOMER_NUMBER,        // 5 : 거래선 번호
            CUSTOMER_NAME,          // 6 : 거래선명
            AREA_ID,                // 7 : 사업부
            OPER,                   // 8 : 출하창고
            OPER_DESC,              // 9 : 출하창고명
            DELIVERY,               // 10 : 납품처
            DELIVERY_ID,            // 11 : 납품처 ID
            DELIVERY_NAME,          // 12 : 납품처명
            DELIVERY_LOCATION,      // 13 : 납품 위치
            DELIVERY_PHONE_NO,      // 14 : 납품사 핸드폰 번호
            DELIVERY_USER_ID,       // 15 : 납품자
            SHIP_ORD_STATUS         // 16 : 출하 지시 상태
        }

        private enum SHIP_DTL
        {
            SHIP_ORDER_ID,         // 1 : 출하 지시 번호
            SEQ,                   // 2 : 출하 순번            
            MAT_DESC,              // 3 : 제품명
            LABEL_NAME,            // 4 :  라벨명
            SHIP_ORD_STATUS,       // 5 : 출하 상태
            PACK_ORDER_ID,         // 6 : 포장 지시 번호
            PACK_LINE_NO,          // 7 : 포장 라인 번호
            ERP_PACK_ORDER_ID,     // 8 : ERP 포장 지시 번호
            QTY,                   // 9 : 수량
            REG_QTY,               // 10 : 등록 수량
            UNIT,                  // 11 : 단위           
            MAT_ID,                // 12 : 제품
            MAT_VER                // 13: 버전
        }

        private enum PACK_LOT
        {
            ORG_LOT_ID,              // 1 : 공정 LOT ID
            PACK_LOT_ID,             // 2 : 포장 LOT ID
            QTY,                     // 3 : 수량
            UNIT,                    // 4 : 단위
            PACK_FLAG,               // 5 : 포장 여부
            PACK_ORDER_ID,           // 6 : 포장 지시 번호
            PACK_LINE_NO,            // 7 : 포장 라인 번호
            ERP_PACK_ORDER_ID,       // 8 : ERP 포장 지시 번호
            SHIP_FLAG,               // 9 : 출하 여부
            SHIP_ORDER_ID,           // 10 : 출하 지시 번호
            SHIP_ORDER_SEQ,          // 11 : 출하 지시 순번
            BOX_ID,                  // 12 : 박스 ID
            FINAL_BOX_ID             // 13 : 최종 박스 ID
        }


        #endregion

        #region " Variable Definition "
        string shipOrderId = "";
        string seq = "";
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                //lblShipReport.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnPrin2.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //출하지시 마스터 정보 조회 함수
        private void ViewShippingOrderList(string selShipOrderId = "")
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[2].sCondition_Value = txtShippingOrderNo.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvShipOper.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CSHP2003-009", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderList);
                    return;
                }

                MPCF.ClearList(spdOrderList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderList_Sheet1.RowCount++;

                    spdOrderList_Sheet1.SetValue(i, (int)SHIP_MST.CHK, false);
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORD_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SHIP_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.CUSTOMER_NUMBER].Value = dt.Rows[i]["CUSTOMER_NUMBER"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.OPER].Value = dt.Rows[i]["OPER"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY].Value = dt.Rows[i]["DELIVERY"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_LOCATION].Value = dt.Rows[i]["DELIVERY_LOCATION"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_PHONE_NO].Value = dt.Rows[i]["DELIVERY_PHONE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_USER_ID].Value = dt.Rows[i]["DELIVERY_USER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORD_STATUS].Value = dt.Rows[i]["SHIP_ORD_STATUS"];

                    if (selShipOrderId == spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORDER_ID].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderList, i);
                    }
                }


                if (cdvDept.Text == "HM")
                {
                    //lblShipReport.Visible = true;
                    btnPrin2.Visible = true;
                }
                else
                {
                    // lblShipReport.Visible = false;
                    btnPrin2.Visible = false;
                }

                MPCF.FitColumnHeader(spdOrderList);



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //출하지시 상세 정보 조회 함수
        private void ViewShippingOrderDetailList(string shipOrderId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = shipOrderId;

                if (TPDR.GetDataOne("", ref dt, "CSHP2003-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderDetailList);
                    return;
                }

                MPCF.ClearList(spdOrderDetailList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderDetailList_Sheet1.RowCount++;

                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SHIP_ORD_STATUS].Value = dt.Rows[i]["SHIP_ORD_STATUS"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_1"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.QTY].Value = dt.Rows[i]["QTY"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.REG_QTY].Value = dt.Rows[i]["REG_QTY"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];

                    if (shipOrderId == spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SHIP_ORDER_ID].Value.ToString().Trim()
                            && seq == spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SEQ].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderDetailList, i);
                    }
                }
                MPCF.FitColumnHeader(spdOrderDetailList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PACKING LOT LIST 조회 함수 (HM 전용)
        private void ViewPackingLotListForHM(string shipOrderId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = shipOrderId;

                if (TPDR.GetDataOne("", ref dt, "CSHP2008-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackingLotList);
                    return;
                }

                MPCF.ClearList(spdPackingLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                }
                MPCF.FitColumnHeader(spdPackingLotList);

                for (i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                }

                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PACKING LOT LIST 조회 함수 (HM 외 모든 사업부 전용)
        private void ViewPackingLotList(string shipOrderId, string seq)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = shipOrderId;

                dvcArgu[2].sCondition_ID = "SEQ";
                dvcArgu[2].sCondition_Value = seq;

                if (TPDR.GetDataOne("", ref dt, "CSHP2008-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackingLotList);
                    return;
                }

                MPCF.ClearList(spdPackingLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                }
                MPCF.FitColumnHeader(spdPackingLotList);

                for (i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                }

                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 출하
        private bool ShippingLot()
        {
            TRSNode in_node = new TRSNode("save_shipping_Lot_In");
            TRSNode out_node = new TRSNode("save_shipping_Lot_Out");
            TRSNode lot_list;
            bool send_flag = false;
            string fileName = "sal510q";

            try
            {
                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '4';

                for (int i = 0; i < spdOrderList_Sheet1.RowCount; i++)
                {
                    if (spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("SHIP_ORDER_LIST");
                        lot_list.AddString("SHIP_ORDER_ID", spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORDER_ID].Text);
                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                //CMN494 INFO -  출하 작업을 진행하시겠습니까?
                if (MPCF.ShowMsgBox(MPCF.GetMessage(494), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Ship_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                CSCF.ViewLabelList(fileName, in_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(string sType)
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

                switch (sType)
                {
                    case "SHIP":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }


                        break;

                    case "PRINT":
                        if (MPCF.Trim(cdvLabelSize.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
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
                    case "VIEW":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        this.cdvDept.Text = "";
                        this.cdvShipOper.Text = "";
                        this.txtShippingOrderNo.Text = "";
                        break;

                    case "ORDER_CLICK_CELL":

                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        break;

                    case "DTL_ORDER_CLICK_CELL":

                        MPCF.ClearList(spdPackingLotList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewPrintLabel(string sFileName)
        {
            try
            {
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        private bool fngetReportType(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            // string s_flow = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Value.ToString();

            in_node.AddString("SQL", "SELECT KEY_1 AS CODE,  "
                                                + "      DATA_1 AS VALUE    "
                                                + "  FROM MGCMTBLDAT  "
                                                + "  WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                + "   AND TABLE_NAME = 'C_INSP_SHIP_REPORT' "
                                                + "   AND DATA_2 = '" + cdvDept.Text + "' ");


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



        private bool fngetQcReport(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            // string s_flow = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Value.ToString();


            in_node.AddString("SQL", "SELECT(CASE WHEN MAT.MAT_GRP_1 = 'CTM' THEN CTM.REPORT_NO"
                                         + " WHEN MAT.MAT_GRP_1 = 'HM' THEN HM.REPORT_NO"
                                         + "            WHEN MAT.MAT_GRP_1 = 'GRT' THEN GRT.REPORT_NO"
                                         + "           ELSE null END) AS CODE"
                                         + "     , MIN(PAK.PACK_LOT_ID) || '~' || MAX(PAK.PACK_LOT_ID) AS VALUE"
                                         + "  FROM CPAKLOTSTS PAK, MWIPMATDEF MAT, CSHPORDDTL DTL,"
                                         + "       CQCMRPTCTM CTM, CQCMRPTHMM HM, CQCMRPTGRN GRT"
                                         + " WHERE PAK.FACTORY = MAT.FACTORY"
                                         + "   AND PAK.FACTORY = DTL.FACTORY"
                                         + "   AND MAT.FACTORY = DTL.FACTORY"
                                         + "   AND DTL.PACK_ORDER_ID = PAK.PACK_ORDER_ID"
                                         + "   AND DTL.PACK_LINE_NO = PAK.PACK_LINE_NO"
                                         + "   AND PAK.MAT_ID = MAT.MAT_ID"
                                         + "   AND PAK.MAT_VER = MAT.MAT_VER"
                                         + "   AND PAK.PACK_LOT_ID = CTM.PACK_LOT_ID(+)"
                                         + "   AND PAK.PACK_ORDER_ID = CTM.PACK_ORDER_ID(+)"
                                         + "   AND PAK.PACK_LOT_ID = HM.PACK_LOT_ID(+)"
                                         + "   AND PAK.PACK_ORDER_ID = HM.PACK_ORDER_ID(+)"
                                         + "   AND PAK.PACK_LOT_ID = GRT.LOT_ID(+)"
                                         + "   AND TO_CHAR(PAK.PACK_LINE_NO) = GRT.LINE_NUMBER(+)"
                                         + "   AND PAK.PACK_ORDER_ID = GRT.HEADER_ID(+)"
                                         + "   AND PAK.FACTORY = '" + MPGV.gsFactory + "' "
         //   + "   AND DTL.SHIP_ORDER_ID = '" + spdOrderDetailList.ActiveSheet.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, (int)SHIP_DTL.SHIP_ORDER_ID].Text + "'"
         //   + "   AND DTL.SEQ = " + spdOrderDetailList.ActiveSheet.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, (int)SHIP_DTL.SEQ].Text +  ""

         + "   AND DTL.SHIP_ORDER_ID = '5660850'"
         + "   AND DTL.SEQ = '9'"

                                         + "   AND PAK.PACK_FLAG = 'Y'"
                                         + "   AND PAK.SHIP_ORDER_ID <> ' '"
                                         // + "   AND PAK.SHIP_FLAG <> 'Y'"
                                         + "GROUP BY MAT.MAT_GRP_1,CTM.REPORT_NO ,HM.REPORT_NO ,GRT.REPORT_NO");





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


        private void fnPrintShipReportHM(string sViewID, string sFileName)
        {
            try
            {

                string sLots = "";


                if (spdOrderDetailList.ActiveSheet.RowCount == 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }


                if (spdPackingLotList.ActiveSheet.RowCount > 0)
                {

                    {
                        for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                        {
                            sLots = sLots + ",'" + spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value.ToString() + "'";
                        }
                    }

                }


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int iRowCount = 0;
                // int i = 0;





                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = spdOrderDetailList_Sheet1.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, (int)SHIP_DTL.SHIP_ORDER_ID].Value;

                dvcArgu[2].sCondition_ID = "SHIP_ORDR_SEQ";
                dvcArgu[2].sCondition_Value = spdOrderDetailList_Sheet1.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, (int)SHIP_DTL.SEQ].Value;


                dvcArgu[3].sCondition_ID = "SQL_TEXT";
                dvcArgu[3].sCondition_Type = "TEXT";

                if (sLots == "")
                {
                    dvcArgu[3].sCondition_Value = "AND 1=1";
                }
                else
                {
                    dvcArgu[3].sCondition_Value = "AND  A.PACK_LOT_ID IN ('Z'" + sLots + ")";
                }

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                dt.Columns.Add("IMAGE_A", typeof(Byte[]));
                dt.Columns.Add("IMAGE_B", typeof(Byte[]));

                iRowCount = dt.Rows.Count;

                // 이미지 조회 ( row별로 Loop )
                for (int i = 0; i < iRowCount; i++)
                {
                    string sReportNo = dt.Rows[i]["REPORT_NO"].ToString();
                    string sPackLotID = dt.Rows[i]["IMAGE_LOT_ID"].ToString();

                    TPDR.DirectViewCond[] dvcArgu_img = new TPDR.DirectViewCond[3];
                    DataTable dtImage = null;


                    dvcArgu_img[0].sCondition_ID = "FACTORY";
                    dvcArgu_img[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu_img[1].sCondition_ID = "REPORT_NO";
                    dvcArgu_img[1].sCondition_Value = sReportNo;

                    dvcArgu_img[2].sCondition_ID = "LOT_ID";
                    dvcArgu_img[2].sCondition_Value = sPackLotID;





                    if (TPDR.GetDataOne("", ref dtImage, "CQCM2101-010", dvcArgu_img, false, false, ref sSql) == false)
                    {
                        if (dtImage != null)
                            dtImage.Dispose();

                        GC.Collect();
                        return;
                    }

                    dt.Rows[i]["IMAGE_A"] = dtImage.Rows[0]["IMAGE_A"];
                    dt.Rows[i]["IMAGE_B"] = dtImage.Rows[0]["IMAGE_B"];

                }


                //일반성적서 pip510p

                DevReport.PreviewXtraReport(dt, sFileName);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition"
        private void frmTranShippingLot_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
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
        private void cdvShipOper_ButtonPress(object sender, EventArgs e)
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

                cdvShipOper.Init();
                MPCF.InitListView(cdvShipOper.GetListView);
                cdvShipOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvShipOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvShipOper.SelectedSubItemIndex = 0;
                cdvShipOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvShipOper.GetListView, '5', cdvDept.Text, "", "", "", 'Y', "", ' ', 'Y') == false)
                {
                    return;
                }

                cdvShipOper.InsertEmptyRow(0, 1);
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
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                SheetView sv = spdOrderList_Sheet1;
                string selShipOrderId = string.Empty;
                if (sv.RowCount > 0)
                {
                    selShipOrderId = sv.Cells[sv.ActiveRowIndex, (int)SHIP_MST.SHIP_ORDER_ID].Value.ToString().Trim();
                }
                ViewShippingOrderList(selShipOrderId);
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
                if (CheckCondition("SHIP") == false)
                    return;

                if (ShippingLot())
                {
                    btnView_Click(null, null);

                    // 출하지시 상세 정보 조회
                    ViewShippingOrderDetailList(shipOrderId);

                    if (string.Equals(cdvDept.Text, CSGC.CP_AREA_HM))
                    {
                        // 포장 진행 LOT 조회
                        ViewPackingLotListForHM(shipOrderId);
                    }
                    else
                    {
                        if (shipOrderId != "" && seq != "")
                        {
                            ViewPackingLotList(shipOrderId, seq);
                        }
                    }
                }
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
                ClearList("ORDER_CLICK_CELL");

                if (e.ColumnHeader == true)
                {
                    if (spdOrderList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdOrderList, e.Row, e.Column, true, true, false);
                    }
                }
                else
                {
                    if (e.Row < 0)
                    {
                        return;
                    }

                    for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                    {
                        spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }

                    spdOrderList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                    shipOrderId = spdOrderList.ActiveSheet.Cells[e.Row, (int)SHIP_MST.SHIP_ORDER_ID].Text;

                    // 출하지시 상세 정보 조회
                    ViewShippingOrderDetailList(shipOrderId);

                    if (string.Equals(cdvDept.Text, CSGC.CP_AREA_HM))
                    {
                        // 포장 진행 LOT 조회
                        ViewPackingLotListForHM(shipOrderId);
                    }
                    else
                    {
                        if (shipOrderId != "" && seq != "")
                        {
                            ViewPackingLotList(shipOrderId, seq);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdOrderDetailList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
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

                for (int i = 0; i < spdOrderDetailList.ActiveSheet.RowCount; i++)
                {
                    spdOrderDetailList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdOrderDetailList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                if (!string.Equals(cdvDept.Text, CSGC.CP_AREA_HM))
                {
                    ClearList("DTL_ORDER_CLICK_CELL");

                    seq = spdOrderDetailList.ActiveSheet.Cells[e.Row, (int)SHIP_DTL.SEQ].Text;

                    // 포장 진행 LOT 조회
                    ViewPackingLotList(shipOrderId, seq);
                }
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
                if (CheckCondition("PRINT") == false)
                    return;

                if (ViewPrintLabel(cdvLabelSize.Text))
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvLabelSize_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabelSize.Init();
                MPCF.InitListView(cdvLabelSize.GetListView);
                cdvLabelSize.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabelSize.SelectedSubItemIndex = 2;
                cdvLabelSize.DisplaySubItemIndex = 0;

                if (COM_LIST.ViewLabelGCMList(cdvLabelSize.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_SHIP) == false)
                {
                    return;
                }

                cdvLabelSize.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtShippingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void dtpFromWorkDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }
        private void dtpFromWorkDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromWorkDate.CustomFormat = " ";
                    break;
            }
        }
        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }
        private void btnPrint2_Click(object sender, EventArgs e)
        {

            //일단 HM만 되도록. 다른데는 제외
            //성적서 바인딩확인
            fnPrintShipReportHM("CQCM2101-008", "pip520pa");

            /*
            if (cdvShipReportType.Text == "HM_01") //일반
            {
                fnPrintShipReportHM("CQCM2101-006", "pip520pa");
            }
            else if (cdvShipReportType.Text == "HM_02")
            {
                fnPrintShipReportHM("CQCM2101-007", "pip520pb");
            }
            else
            {
                fnPrintShipReportHM("CQCM2101-006", "pip520pa");
            }
            */
        }

        #endregion


    }
}
