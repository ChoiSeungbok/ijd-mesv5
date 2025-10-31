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

namespace CUS_SHP
{
    public partial class frmTranCancelShippingLot : CUS_COM.frmTranForm01
    {
        public frmTranCancelShippingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum SHIP_MST
        {
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
            LABEL_NAME,            // 4 : 라벨명
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
            CHK,                     // 1 : CHECK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID
            QTY,                     // 4 : 수량
            UNIT,                    // 5 : 단위
            PACK_FLAG,               // 6 : 포장 여부
            PACK_ORDER_ID,           // 7 : 포장 지시 번호
            PACK_LINE_NO,            // 8 : 포장 라인 번호
            ERP_PACK_ORDER_ID,       // 9 : ERP 포장 지시 번호
            SHIP_FLAG,               // 10 : 출하 여부
            SHIP_ORDER_ID,           // 11 : 출하 지시 번호
            SHIP_ORDER_SEQ,          // 12 : 출하 지시 순번
            BOX_ID,                  // 13 : 박스 ID
            FINAL_BOX_ID             // 14 : 최종 박스 ID
        }


        #endregion

        #region " Variable Definition "
        string shipOrderId = "";
        string seq = "";
        bool b_refresh_flag = false;
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
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //출하지시 마스터 정보 조회 함수
        private void ViewShippingOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                b_refresh_flag = false;

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

                dvcArgu[6].sCondition_ID = "DELETE_FLAG";
                dvcArgu[6].sCondition_Value = cdvDeleteFlag.Text;


                if (TPDR.GetDataOne("", ref dt, "CSHP2003-006", dvcArgu, false, false, ref sSql) == false)
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

                    if (shipOrderId == spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORDER_ID].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderList, i);
                        b_refresh_flag = true;
                    }
                }
                MPCF.FitColumnHeader(spdOrderList);

                if(b_refresh_flag == false)
                {
                    shipOrderId = "";
                    seq = "";
                }

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                b_refresh_flag = false;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = shipOrderId;

                dvcArgu[2].sCondition_ID = "DELETE_FLAG";
                dvcArgu[2].sCondition_Value = cdvDeleteFlag.Text;


                if (TPDR.GetDataOne("", ref dt, "CSHP2003-007", dvcArgu, false, false, ref sSql) == false)
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
                            && seq== spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SEQ].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderDetailList, i);
                        b_refresh_flag = true;
                    }
                }
                MPCF.FitColumnHeader(spdOrderDetailList);

                if(b_refresh_flag == false)
                {
                    shipOrderId = "";
                    seq = "";
                }

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = shipOrderId;

                dvcArgu[2].sCondition_ID = "REGIST_FLAG";
                dvcArgu[2].sCondition_Value = "Y";

                if (TPDR.GetDataOne("", ref dt, "CSHP2006-003", dvcArgu, false, false, ref sSql) == false)
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

                    spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, false);
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

        private void CheckCount()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                    }
                }

                spdPackingLotList_Sheet1.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = iCount;
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

                if (TPDR.GetDataOne("", ref dt, "CSHP2006-005", dvcArgu, false, false, ref sSql) == false)
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

                    spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, false);
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

        // 포장 LOT 스캔 -> 체크
        private void ScanPackLot()
        {
            try
            {
                bool checkFlag = false;
                //string sBoxID = "";

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    // 그리드 데이터 체크
                    if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text, txtPackingLotID.Text))
                    {
                        spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, true);
                        checkFlag = true;
                        //sBoxID = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text;
                        break;
                    }
                }

                //if (MPCF.Trim(sBoxID) != "")
                //{
                //    txtBoxID.Text = sBoxID;
                //    ScanPackBox();
                //}

                if(checkFlag == false)
                {
                    //CMN481 INFO - 데이터가 존재하지 않습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(481));
                }

                txtPackingLotID.SelectAll();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 포장 박스 스캔 -> 체크
        private void ScanPackBox()
        {
            try
            {
                bool checkFlag = false;
                //string sFinalBoxID = "";

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    // 그리드 데이터 체크
                    if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text, txtBoxID.Text))
                    {
                        spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, true);
                        checkFlag = true;
                        //if(string.IsNullOrEmpty(sFinalBoxID))
                        //{
                        //    sFinalBoxID = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text;
                        //}
                    }
                }

                //if (MPCF.Trim(sFinalBoxID) != "")
                //{
                //    txtFinalBoxID.Text = sFinalBoxID;
                //    ScanPackFinalBox();
                //}

                if (checkFlag == false)
                {
                    //CMN481 INFO - 데이터가 존재하지 않습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(481));
                }

                txtBoxID.SelectAll();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 포장 최종 박스 스캔 -> 체크
        private void ScanPackFinalBox()
        {
            try
            {
                bool checkFlag = false;

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    // 그리드 데이터 체크
                    if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text, txtFinalBoxID.Text))
                    {
                        spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, true);
                        checkFlag = true;
                    }
                }

                if (checkFlag == false)
                {
                    //CMN481 INFO - 데이터가 존재하지 않습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(481));
                }

                txtFinalBoxID.SelectAll();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 출하 등록
        private bool RegistShippingLot()
        {
            TRSNode in_node = new TRSNode("regist_shipping_Lot_In");
            TRSNode out_node = new TRSNode("regist_shipping_Lot_Out");
            TRSNode lot_list;
            TRSNode box_list;
            TRSNode final_box_list;
            Dictionary<string, double> dict_box = new Dictionary<string, double>();
            Dictionary<string, double> dict_final_box = new Dictionary<string, double>();
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("SHIP_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)SHIP_MST.SHIP_ORDER_ID].Text);

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if(string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_ORDER_ID].Text) != "")
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        send_flag = true;

                        //BOX, FINAL BOX 수량 Validation
                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text) != "")
                        {
                            if (dict_box.ContainsKey(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text))
                            {
                                dict_box[spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text] += 1;
                            }
                            else
                            {
                                dict_box.Add(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text, 1);
                            }
                        }

                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text) != "")
                        {
                            if (dict_final_box.ContainsKey(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text))
                            {
                                dict_final_box[spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text] += 1;
                            }
                            else
                            {
                                dict_final_box.Add(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text, 1);
                            }
                        }
                    }
                }

                if (dict_box.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item in dict_box)
                    {
                        box_list = in_node.AddNode("PACK_BOX_LIST");
                        box_list.AddString("BOX_ID", item.Key);
                        box_list.AddDouble("QTY", item.Value);
                    }
                }

                if(dict_final_box.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item in dict_final_box)
                    {
                        final_box_list = in_node.AddNode("PACK_FINAL_BOX_LIST");
                        final_box_list.AddString("FINAL_BOX_ID", item.Key);
                        final_box_list.AddDouble("QTY", item.Value);
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Ship_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // 출하 등록 취소
        private bool CancelRegistShippingLot()
        {
            TRSNode in_node = new TRSNode("cancel_shipping_Lot_In");
            TRSNode out_node = new TRSNode("cancel_shipping_Lot_Out");
            TRSNode lot_list;
            TRSNode box_list;
            TRSNode final_box_list;
            Dictionary<string, double> dict_box = new Dictionary<string, double>();
            Dictionary<string, double> dict_final_box = new Dictionary<string, double>();

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("SHIP_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)SHIP_MST.SHIP_ORDER_ID].Text);

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_ORDER_ID].Text) == "")
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);

                        //BOX, FINAL BOX 수량 Validation
                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text) != "")
                        {
                            if (dict_box.ContainsKey(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text))
                            {
                                dict_box[spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text] += 1;
                            }
                            else
                            {
                                dict_box.Add(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text, 1);
                            }
                        }

                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text) != "")
                        {
                            if (dict_final_box.ContainsKey(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text))
                            {
                                dict_final_box[spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text] += 1;
                            }
                            else
                            {
                                dict_final_box.Add(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text, 1);
                            }
                        }
                    }
                }

                if (dict_box.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item in dict_box)
                    {
                        box_list = in_node.AddNode("PACK_BOX_LIST");
                        box_list.AddString("BOX_ID", item.Key);
                        box_list.AddDouble("QTY", item.Value);
                    }
                }

                if (dict_final_box.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item in dict_final_box)
                    {
                        final_box_list = in_node.AddNode("PACK_FINAL_BOX_LIST");
                        final_box_list.AddString("FINAL_BOX_ID", item.Key);
                        final_box_list.AddDouble("QTY", item.Value);
                    }
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Ship_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

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
                    case "REGIST":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdPackingLotList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        break;

                    case "INPUT_LOT":
                        if (MPCF.Trim(txtPackingLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPackLotID.Text + "]");
                            txtPackingLotID.Focus();
                            return false;
                        }

                        break;

                    case "INPUT_BOX":
                        if (MPCF.Trim(txtBoxID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblBoxID.Text + "]");
                            txtBoxID.Focus();
                            return false;
                        }

                        break;

                    case "INPUT_FINAL_BOX":
                        if (MPCF.Trim(txtFinalBoxID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFinalBoxID.Text + "]");
                            txtFinalBoxID.Focus();
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
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        this.txtPackingLotID.Text = "";
                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        this.cdvDept.Text = "";
                        this.cdvShipOper.Text = "";
                        this.txtShippingOrderNo.Text = "";
                        this.txtPackingLotID.Text = "";
                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
                        this.cdvDeleteFlag.Text = "";
                        break;

                    case "ORDER_CLICK_CELL":
                        
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        this.txtPackingLotID.Text = "";
                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
                        break;

                    case "DTL_ORDER_CLICK_CELL":

                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        this.txtPackingLotID.Text = "";
                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
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

        private bool ViewShipDetail(int iRow)
        {

            try
            {
                if (iRow < 0)
                {
                    return false;
                }

                for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                {
                    spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdOrderList.ActiveSheet.Rows[iRow].BackColor = Color.FromArgb(255, 192, 255);

                shipOrderId = spdOrderList.ActiveSheet.Cells[iRow, (int)SHIP_MST.SHIP_ORDER_ID].Text;

                //if (spdOrderDetailList.ActiveSheet.RowCount > 0 && iRowD > -1)
                //{
                //    seq = spdOrderDetailList.ActiveSheet.Cells[iRowD, (int)SHIP_DTL.SEQ].Text;
                //}

                // 출하지시 상세 정보 조회
                ViewShippingOrderDetailList(shipOrderId);

                if (string.Equals(cdvDept.Text, CSGC.CP_AREA_HM))
                {
                    // 포장 진행 LOT 조회
                    ViewPackingLotListForHM(shipOrderId);
                }

                if (shipOrderId!="" && seq != "")
                {
                    ViewPackingLotList(shipOrderId, seq);
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

        #region " Event Definition"
        private void frmTranRegistShippingLot_Load(object sender, EventArgs e)
        {
            try
            {
                lblBoxID.Visible = false;
                txtBoxID.Visible = false;

                lblFinalBoxID.Visible = false;
                txtFinalBoxID.Visible = false;

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
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (string.Equals(cdvDept.Text, CSGC.CP_AREA_HM))
                {
                    lblBoxID.Visible = true;
                    txtBoxID.Visible = true;

                    lblFinalBoxID.Visible = true;
                    txtFinalBoxID.Visible = true;
                }
                else
                {
                    lblBoxID.Visible = false;
                    txtBoxID.Visible = false;

                    lblFinalBoxID.Visible = false;
                    txtFinalBoxID.Visible = false;
                }
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
        private void txtPackingLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT_LOT") == false)
                        return;

                    ScanPackLot();
                    CheckCount();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtBoxID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT_BOX") == false)
                        return;

                    ScanPackBox();
                    CheckCount();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtFinalBoxID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT_FINAL_BOX") == false)
                        return;

                    ScanPackFinalBox();
                    CheckCount();
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
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");               

                ViewShippingOrderList();
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
                if (CheckCondition("REGIST") == false)
                    return;

                if (RegistShippingLot())
                {                    
                    btnView_Click(null, null);                 
                  
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
                if (CheckCondition("REGIST") == false)
                    return;

                if (CancelRegistShippingLot())
                {                 

                    btnView_Click(null, null);

                    if(b_refresh_flag == true)
                    {
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
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            ClearList("ORDER_CLICK_CELL");

            try
            {              

                if (e.ColumnHeader == true)
                {
                    return;
                }
                
                for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                {
                    spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdOrderList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                shipOrderId = spdOrderList.ActiveSheet.Cells[e.Row, (int)SHIP_MST.SHIP_ORDER_ID].Text;

                //seq = spdOrderList.ActiveSheet.Cells[e.Row, (int)SHIP_DTL.SEQ].Text;
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
        private void spdPackingLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdPackingLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdPackingLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
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
        private void spdPackingLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdPackingLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvDeleteFlag_ButtonPress(object sender, EventArgs e)
        {
            //DELETE FLAG 추가
            cdvDeleteFlag.Init();
            MPCF.InitListView(cdvDeleteFlag.GetListView);

            cdvDeleteFlag.Columns.Add("Flag", 30, HorizontalAlignment.Left);

            ListViewItem item = new ListViewItem("Y", 14);
            item.SubItems.Add("Y");
            cdvDeleteFlag.Items.Add(item);

            cdvDeleteFlag.InsertEmptyRow(0, 1);
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

        #endregion

    }
}
