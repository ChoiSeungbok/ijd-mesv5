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

namespace CUS_SHP
{
    public partial class frmTranPackingFinalBox : CUS_COM.frmTranForm01
    {
        public frmTranPackingFinalBox()
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
            MAT_ID,                // 3 : 제품
            MAT_VER,               // 4 : 버전
            MAT_DESC,              // 5 : 제품명
            SHIP_ORD_STATUS,       // 6 : 출하 상태
            PACK_ORDER_ID,         // 7 : 포장 지시 번호
            PACK_LINE_NO,          // 8 : 포장 라인 번호
            ERP_PACK_ORDER_ID,     // 9 : ERP 포장 지시 번호
            QTY,                   // 10 : 수량
            UNIT                   // 11 : 단위
        }

        private enum PACK_BOX
        {
            CHK,                     // 1 : CHECK
            BOX_ID,                  // 2 : 박스 ID
            PACK_ORDER_ID,           // 3 : 포장 지시 번호
            LINE_NO,                 // 4 : 포장 라인 번호
            QTY,                     // 5 : 수량
            UNIT,                    // 6 : 단위
            FINAL_BOX_ID,            // 7 : 최종 박스 ID
            SHIP_FLAG                // 8 : 출하 여부
        }

        private enum PACK_LOT
        {
            ORG_LOT_ID,              // 1 : 공정 LOT ID
            PACK_LOT_ID,             // 2 : 포장 LOT ID
            QTY,                     // 3 : 수량
            UNIT,                    // 4 : 단위
            BOX_ID,                  // 5 : 박스 ID
            FINAL_BOX_ID,            // 6 : 최종 박스 ID
            SHIP_FLAG                // 7 : 출하 여부
        }

        #endregion

        #region " Variable Definition "
        string shipOrderId = "";
        string packOrderId = "";
        string packLineNo = "";
        string boxID = "";
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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

                if (TPDR.GetDataOne("", ref dt, "CSHP2003-003", dvcArgu, false, false, ref sSql) == false)
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
                    }

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
                }
                MPCF.FitColumnHeader(spdOrderDetailList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PACKING BOX LIST 조회 함수
        private void ViewPackingBoxList(string shipOrderId)
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

                dvcArgu[2].sCondition_ID = "BOX_ID_1";
                dvcArgu[2].sCondition_Value = "";

                if (TPDR.GetDataOne("", ref dt, "CSHP2003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBoxList);
                    return;
                }

                MPCF.ClearList(spdBoxList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBoxList_Sheet1.RowCount++;

                    spdBoxList_Sheet1.SetValue(i, (int)PACK_BOX.CHK, false);
                    spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.QTY].Value = dt.Rows[i]["QTY"];
                    spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                    spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                }
                MPCF.FitColumnHeader(spdBoxList);

                for (i = 0; i < spdBoxList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdBoxList.ActiveSheet.Cells[i, (int)PACK_BOX.QTY].Text);
                }

                spdBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = dSumQty;

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
                for (int i = 0; i < spdBoxList_Sheet1.RowCount; i++)
                {
                    if (spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.QTY].Text);
                    }
                }

                spdBoxList_Sheet1.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = iCount;
                spdBoxList_Sheet1.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount2()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdPackingBoxList_Sheet1.RowCount; i++)
                {
                    if (spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.QTY].Text);
                    }
                }

                spdPackingBoxList_Sheet1.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = iCount;
                spdPackingBoxList_Sheet1.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PACKING FINAL BOX 정보 조회 함수
        private void ViewFinalBox()
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

                dvcArgu[2].sCondition_ID = "BOX_ID_2";
                dvcArgu[2].sCondition_Value = txtFinalBoxID.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2003-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackingBoxList);

                    txtFinalBoxID.SelectAll();
                    return;
                }

                MPCF.ClearList(spdPackingBoxList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingBoxList_Sheet1.RowCount++;

                    spdPackingBoxList_Sheet1.SetValue(i, (int)PACK_BOX.CHK, false);
                    spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.QTY].Value = dt.Rows[i]["QTY"];
                    spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                    spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                }
                MPCF.FitColumnHeader(spdPackingBoxList);

                txtFinalBoxID.SelectAll();

                for (i = 0; i < spdPackingBoxList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdPackingBoxList.ActiveSheet.Cells[i, (int)PACK_BOX.QTY].Text);
                }

                spdPackingBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PACKING LOT LIST 조회 함수
        private void ViewPackingLotList(string boxID, string packOrderId, string packLineNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "BOX_ID_1";
                dvcArgu[1].sCondition_Value = boxID;

                dvcArgu[2].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[2].sCondition_Value = packOrderId;

                dvcArgu[3].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[3].sCondition_Value = packLineNo;

                if (TPDR.GetDataOne("", ref dt, "CSHP2002-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBoxLotList);
                    return;
                }

                MPCF.ClearList(spdBoxLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBoxLotList_Sheet1.RowCount++;

                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                }
                MPCF.FitColumnHeader(spdBoxLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 포장 Box 정보 조회 후 데이터 추가
        private void InputPackBox()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = shipOrderId;

                dvcArgu[2].sCondition_ID = "BOX_ID_1";
                dvcArgu[2].sCondition_Value = txtBoxID.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtBoxID.SelectAll();

                    return;
                }

                if (string.Equals(dt.Rows[0]["SHIP_FLAG"], "Y"))
                {
                    //CMN460 ERROR - 해당 BOX는 이미 출하되었습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(460) + " [" + lblBoxID.Text + "]");
                    return;
                }

                if (MPCF.Trim(dt.Rows[0]["BOX_ID_2"]) != "")
                {
                    //CMN461 ERROR - 해당 BOX는 이미 최종 박스에 포장되었습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(461) + " [" + lblBoxID.Text + "]");
                    return;
                }

                for (int i = 0; i < spdBoxList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Text, dt.Rows[0]["BOX_ID_1"]))
                    {
                        spdBoxList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }

                // TO 그리드에 데이터 삽입
                i_Row = spdPackingBoxList_Sheet1.RowCount++;

                spdPackingBoxList_Sheet1.SetValue(i_Row, (int)PACK_BOX.CHK, true);
                spdPackingBoxList_Sheet1.Cells[i_Row, (int)PACK_BOX.BOX_ID].Value = dt.Rows[0]["BOX_ID_1"];
                spdPackingBoxList_Sheet1.Cells[i_Row, (int)PACK_BOX.PACK_ORDER_ID].Value = dt.Rows[0]["PACK_ORDER_ID"];
                spdPackingBoxList_Sheet1.Cells[i_Row, (int)PACK_BOX.LINE_NO].Value = dt.Rows[0]["PACK_LINE_NO"];
                spdPackingBoxList_Sheet1.Cells[i_Row, (int)PACK_BOX.QTY].Value = dt.Rows[0]["QTY"];
                spdPackingBoxList_Sheet1.Cells[i_Row, (int)PACK_BOX.UNIT].Value = dt.Rows[0]["UNIT"];
                spdPackingBoxList_Sheet1.Cells[i_Row, (int)PACK_BOX.FINAL_BOX_ID].Value = "";
                spdPackingBoxList_Sheet1.Cells[i_Row, (int)PACK_BOX.SHIP_FLAG].Value = dt.Rows[0]["SHIP_FLAG"];
                MPCF.FitColumnHeader(spdPackingBoxList);

                txtBoxID.SelectAll();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //포장 정보 생성 및 제거
        private bool SaveBox()
        {
            TRSNode in_node = new TRSNode("save_final_Box_In");
            TRSNode out_node = new TRSNode("save_final_Box_Out");
            TRSNode lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("FINAL_BOX_ID", txtFinalBoxID.Text);
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdPackingBoxList_Sheet1.RowCount; i++)
                {
                    if (spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (string.Equals(spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.SHIP_FLAG].Text, "Y"))
                        {
                            //CMN460 ERROR - 해당 BOX는 이미 출하되었습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(460));
                            return false;
                        }

                        lot_list = in_node.AddNode("PACK_BOX_LIST");
                        lot_list.AddString("BOX_ID", spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Text);
                        lot_list.AddString("PACK_ORDER_ID", spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.PACK_ORDER_ID].Text);
                        lot_list.AddInt("LINE_NO", MPCF.ToInt(spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.LINE_NO].Text));
                        send_flag = true;
                    }
                }

                if (send_flag == false && string.IsNullOrEmpty(txtFinalBoxID.Text))
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Create_Pack_Final_Box", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                if (out_node.GetChar("PRINT_FLAG") == 'Y')
                {
                    ViewPrintLabel(out_node);
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
                    case "SAVE":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (string.IsNullOrEmpty(txtFinalBoxID.Text) && spdPackingBoxList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        if (MPCF.Trim(cdvLabelSize.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
                            return false;
                        }

                        break;

                    case "BOX_INPUT":
                        if (MPCF.Trim(txtBoxID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblBoxID.Text + "]");
                            txtBoxID.Focus();
                            return false;
                        }

                        if (spdOrderDetailList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case "FINAL_BOX_INPUT":
                        if (MPCF.Trim(txtFinalBoxID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFinalBoxID.Text + "]");
                            txtFinalBoxID.Focus();
                            return false;
                        }

                        if (spdOrderDetailList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case "PRINT":
                        if (MPCF.Trim(txtFinalBoxID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFinalBoxID.Text + "]");
                            txtFinalBoxID.Focus();
                            return false;
                        }

                        if (string.IsNullOrEmpty(txtFinalBoxID.Text) && spdPackingBoxList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

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
                        MPCF.ClearList(spdBoxList);
                        MPCF.ClearList(spdPackingBoxList);
                        MPCF.ClearList(spdBoxLotList);
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = 0;
                        spdPackingBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = 0;
                        spdPackingBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = 0;

                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdBoxList);
                        MPCF.ClearList(spdPackingBoxList);
                        MPCF.ClearList(spdBoxLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        this.cdvShipOper.Text = "";
                        this.cdvWorkPlace.Text = "";
                        this.txtShippingOrderNo.Text = "";
                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = 0;
                        spdPackingBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = 0;
                        spdPackingBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = 0;
                        break;

                    case "ORDER_CLICK_CELL":

                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdBoxList);
                        MPCF.ClearList(spdPackingBoxList);
                        MPCF.ClearList(spdBoxLotList);

                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = 0;
                        spdPackingBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.CHK].Value = 0;
                        spdPackingBoxList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_BOX.QTY].Value = 0;
                        break;

                    case "ORDER_DETAIL_CLICK_CELL":

                        MPCF.ClearList(spdBoxList);
                        MPCF.ClearList(spdBoxLotList);

                        this.txtBoxID.Text = "";
                        this.txtFinalBoxID.Text = "";
                        break;

                    case "BOX_CLICK_CELL":

                        MPCF.ClearList(spdBoxLotList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewPrintLabel(TRSNode in_node)
        {
            string sFileName = "";

            try
            {
                sFileName = cdvLabelSize.Text;

                CSCF.ViewLabelList(sFileName, in_node, 'C');

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
        private void frmTranPackingFinalBox_Load(object sender, EventArgs e)
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

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                string sBoxID = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdBoxList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sBoxID = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Text;

                        for (int k = 0; k < spdPackingBoxList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdPackingBoxList_Sheet1.Cells[k, (int)PACK_BOX.BOX_ID].Text, sBoxID))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (MPCF.Trim(spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.FINAL_BOX_ID].Text) != "")
                        {
                            continue;
                        }

                        if (string.Equals(spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        if (addFlag == true)
                        {
                            iRow = spdPackingBoxList_Sheet1.RowCount++;

                            spdPackingBoxList_Sheet1.SetValue(iRow, (int)PACK_BOX.CHK, true);
                            spdPackingBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.BOX_ID].Value = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Text;
                            spdPackingBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.PACK_ORDER_ID].Value = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.PACK_ORDER_ID].Text;
                            spdPackingBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.LINE_NO].Value = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.LINE_NO].Text;
                            spdPackingBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.QTY].Value = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.QTY].Text;
                            spdPackingBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.UNIT].Value = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.UNIT].Text;
                            spdPackingBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.FINAL_BOX_ID].Value = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.FINAL_BOX_ID].Text;
                            spdPackingBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.SHIP_FLAG].Value = spdBoxList_Sheet1.Cells[i, (int)PACK_BOX.SHIP_FLAG].Text;
                        }

                        spdBoxList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdPackingBoxList);

                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            try
            {
                string sBoxID = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdPackingBoxList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sBoxID = spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Text;

                        for (int k = 0; k < spdBoxList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdBoxList_Sheet1.Cells[k, (int)PACK_BOX.BOX_ID].Text, sBoxID))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (string.Equals(spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        if (!string.Equals(spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.PACK_ORDER_ID].Text, packOrderId))
                        {
                            spdPackingBoxList_Sheet1.RemoveRows(i, 1);
                            continue;
                        }

                        if (addFlag == true)
                        {
                            iRow = spdBoxList_Sheet1.RowCount++;

                            spdBoxList_Sheet1.SetValue(iRow, (int)PACK_BOX.CHK, true);
                            spdBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.BOX_ID].Value = spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.BOX_ID].Text;
                            spdBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.PACK_ORDER_ID].Value = spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.PACK_ORDER_ID].Text;
                            spdBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.LINE_NO].Value = spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.LINE_NO].Text;
                            spdBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.QTY].Value = spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.QTY].Text;
                            spdBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.UNIT].Value = spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.UNIT].Text;
                            spdBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.FINAL_BOX_ID].Value = "";
                            spdBoxList_Sheet1.Cells[iRow, (int)PACK_BOX.SHIP_FLAG].Value = spdPackingBoxList_Sheet1.Cells[i, (int)PACK_BOX.SHIP_FLAG].Text;

                        }

                        spdPackingBoxList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdPackingBoxList);

                CheckCount();
                CheckCount2();
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
                if (CheckCondition("SAVE") == false)
                    return;

                if (SaveBox())
                {
                    ClearList("ORDER_CLICK_CELL");

                    // 출하지시 상세 정보 조회
                    ViewShippingOrderDetailList(shipOrderId);

                    // 포장 박스 정보 조회
                    ViewPackingBoxList(shipOrderId);
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
                    if (CheckCondition("BOX_INPUT") == false)
                        return;

                    InputPackBox();
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
                    if (CheckCondition("FINAL_BOX_INPUT") == false)
                        return;

                    ViewFinalBox();
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

        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            ClearList("ORDER_CLICK_CELL");

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

                for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                {
                    spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdOrderList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                shipOrderId = spdOrderList.ActiveSheet.Cells[e.Row, (int)SHIP_MST.SHIP_ORDER_ID].Text;

                // 출하지시 상세 정보 조회
                ViewShippingOrderDetailList(shipOrderId);

                // 포장 박스 정보 조회
                ViewPackingBoxList(shipOrderId);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdBoxList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdBoxList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdBoxList, e.Row, e.Column, true, true, false);
                    }

                    CheckCount();
                }
                else
                {
                    ClearList("BOX_CLICK_CELL");

                    if (e.Row < 0)
                    {
                        return;
                    }

                    for (int i = 0; i < spdBoxList.ActiveSheet.RowCount; i++)
                    {
                        spdBoxList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }

                    spdBoxList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                    boxID = spdBoxList.ActiveSheet.Cells[e.Row, (int)PACK_BOX.BOX_ID].Text;
                    packOrderId = spdBoxList.ActiveSheet.Cells[e.Row, (int)PACK_BOX.PACK_ORDER_ID].Text;
                    packLineNo = spdBoxList.ActiveSheet.Cells[e.Row, (int)PACK_BOX.LINE_NO].Text;

                    // 포장 진행 LOT 조회
                    ViewPackingLotList(boxID, packOrderId, packLineNo);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPackingBoxList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdPackingBoxList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdPackingBoxList, e.Row, e.Column, true, true, false);
                    }

                    CheckCount2();
                }
                else
                {
                    ClearList("BOX_CLICK_CELL");

                    if (e.Row < 0)
                    {
                        return;
                    }

                    for (int i = 0; i < spdPackingBoxList.ActiveSheet.RowCount; i++)
                    {
                        spdPackingBoxList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }

                    spdPackingBoxList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                    boxID = spdPackingBoxList.ActiveSheet.Cells[e.Row, (int)PACK_BOX.BOX_ID].Text;
                    packOrderId = spdPackingBoxList.ActiveSheet.Cells[e.Row, (int)PACK_BOX.PACK_ORDER_ID].Text;
                    packLineNo = spdPackingBoxList.ActiveSheet.Cells[e.Row, (int)PACK_BOX.LINE_NO].Text;

                    // 포장 진행 LOT 조회
                    ViewPackingLotList(boxID, packOrderId, packLineNo);
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
                cdvLabelSize.DisplaySubItemIndex = 1;

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

        private void btnPrint_Click(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("print_label_In");

            try
            {
                if (CheckCondition("PRINT") == false)
                    return;

                MPCR.SetInMsg(in_node);
                in_node.AddString("FINAL_BOX_ID", MPCF.Trim(txtFinalBoxID.Text));

                ViewPrintLabel(in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdBoxList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void spdBoxList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdPackingBoxList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPackingBoxList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


    }
}
