using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_SHP
{
    public partial class frmTranReturnLot : CUS_COM.frmTranForm01
    {
        public frmTranReturnLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum RET_ORDER
        {
            RET_ORDER_ID,          // 1 : 반품 지시 번호
            LINE_NO,               // 2 : 라인 번호
            MAT_ID,                // 3 : 제품
            MAT_VER,               // 4 : 버전
            MAT_DESC,              // 5 : 제품명
            RET_ORD_STATUS,        // 6 : 반품 지시 상태
            RET_ORD_DATE,          // 7 : 반품 지시 일자
            QTY,                   // 8 : 수량
            RETURNED_QTY,          // 9 : 반품된 수량
            UNIT,                  // 10 : 단위
            OPER,                  // 11 : 창고
            OPER_DESC,             // 12 : 창고명
            CUSTOMER_ID,           // 13 : 고객사
            CUSTOMER_SITE_ID,      // 14 : 고객사 SITE ID
            CUSTOMER_NUMBER,       // 15 : 고객사 번호
            CUSTOMER_NAME,         // 16 : 고객사명
            SHIP_ORDER_ID,         // 17 : 출하 지시 번호
            SHIP_ORDER_SEQ,        // 18 : 출하 지시 순번
            SHIP_LINE_IF_ID,       // 19 : 인터페이스 라인 ID 
            SHIP_LINE_LOT_IF_ID,   // 20 : 인터페이스 LOT ID
            REFERENCE_LINE_ID,     // 21 : 참고 라인 ID
            LABEL_NAME             // 22 : 품목명
        }

        private enum RET_LOT
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
            BOX_ID,                  // 12 : 박스 ID
            FINAL_BOX_ID,            // 13 : 최종 박스 ID
            CMF_2,                   // 14 : 검사 LOT ID
            RET_FLAG,                // 15 : 반품 여부
            ORG_QTY,                 // 16 : 초기 수량
            COMMENT                  // 17 : COMMENT
        }


        #endregion

        #region " Variable Definition "
        string matId = "";
        string retOrderId = "";
        string retLineNo = "";
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblNotice.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //Return Order LIST 조회 함수
        private void ViewReturnOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatID.Text;

                dvcArgu[3].sCondition_ID = "RET_ORDER_ID";
                dvcArgu[3].sCondition_Value = txtReturnOrderNo.Text;

                dvcArgu[4].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[4].sCondition_Value = cdvCustomerID.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CSHP2007-001", dvcArgu, false, false, ref sSql) == false)
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

                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.RET_ORDER_ID].Value = dt.Rows[i]["RET_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.LINE_NO].Value = dt.Rows[i]["LINE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.RET_ORD_STATUS].Value = dt.Rows[i]["RET_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.RET_ORD_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RET_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.QTY].Value = dt.Rows[i]["QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.RETURNED_QTY].Value = dt.Rows[i]["RETURNED_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.OPER].Value = dt.Rows[i]["OPER"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.CUSTOMER_SITE_ID].Value = dt.Rows[i]["CUSTOMER_SITE_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.CUSTOMER_NUMBER].Value = dt.Rows[i]["CUSTOMER_NUMBER"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.SHIP_LINE_IF_ID].Value = dt.Rows[i]["SHIP_LINE_IF_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.SHIP_LINE_LOT_IF_ID].Value = dt.Rows[i]["SHIP_LINE_LOT_IF_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.REFERENCE_LINE_ID].Value = dt.Rows[i]["REFERENCE_LINE_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];

                    if (retOrderId == spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.RET_ORDER_ID].Value.ToString().Trim()
                          && retLineNo == spdOrderList_Sheet1.Cells[i, (int)RET_ORDER.LINE_NO].Value.ToString().Trim())
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
        //SHIPPING LOT LIST 조회 함수
        private void ViewShippingLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = matId;

                dvcArgu[2].sCondition_ID = "PACK_LOT_ID";
                dvcArgu[2].sCondition_Value = txtReturnLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2006-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    // 조회되는 데이터가 없으면, 과거 데이터로 간주하여 추가
                    i_Row = spdReturnLotList_Sheet1.RowCount;
                    spdReturnLotList_Sheet1.RowCount++;

                    spdReturnLotList_Sheet1.SetValue(i_Row, (int)RET_LOT.CHK, true);
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_LOT_ID].Value = txtReturnLotID.Text;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LOT_ID].Value = txtReturnLotID.Text;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.QTY].Value = 0;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.UNIT].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_FLAG].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_ORDER_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LINE_NO].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ERP_PACK_ORDER_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_FLAG].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_ORDER_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.BOX_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.FINAL_BOX_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.CMF_2].Value = txtReturnLotID.Text;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.RET_FLAG].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_QTY].Value = 0;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.COMMENT].Value = " ";

                    MPCF.FitColumnHeader(spdReturnLotList);
                    spdReturnLotList_Sheet1.Columns.Get((int)RET_LOT.COMMENT).Width = 400;



                    return;
                }

                // 데이터가 조회되면 데이터 찾아서 추가
                i_Row = spdReturnLotList_Sheet1.RowCount++;

                spdReturnLotList_Sheet1.SetValue(i_Row, (int)RET_LOT.CHK, false);
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_LOT_ID].Value = dt.Rows[0]["ORG_LOT_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LOT_ID].Value = dt.Rows[0]["PACK_LOT_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_FLAG].Value = dt.Rows[0]["PACK_FLAG"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_ORDER_ID].Value = dt.Rows[0]["PACK_ORDER_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LINE_NO].Value = dt.Rows[0]["PACK_LINE_NO"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[0]["CMF_5"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_FLAG].Value = dt.Rows[0]["SHIP_FLAG"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_ORDER_ID].Value = dt.Rows[0]["SHIP_ORDER_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.BOX_ID].Value = dt.Rows[0]["BOX_ID_1"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.FINAL_BOX_ID].Value = dt.Rows[0]["BOX_ID_2"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.CMF_2].Value = dt.Rows[0]["CMF_2"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.RET_FLAG].Value = dt.Rows[0]["RET_FLAG"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_QTY].Value = dt.Rows[0]["QTY"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.COMMENT].Value = " ";

                MPCF.FitColumnHeader(spdReturnLotList);
                spdReturnLotList_Sheet1.Columns.Get((int)RET_LOT.COMMENT).Width = 400;

                txtReturnLotID.SelectAll();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //붙여넣기로 멀티로 입력가능하도록 수정 (20211028 syw)
        private void ViewShippingLotList2(string sLotId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = matId;

                dvcArgu[2].sCondition_ID = "PACK_LOT_ID";
                dvcArgu[2].sCondition_Value = sLotId;

                if (TPDR.GetDataOne("", ref dt, "CSHP2006-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    // 조회되는 데이터가 없으면, 과거 데이터로 간주하여 추가
                    i_Row = spdReturnLotList_Sheet1.RowCount;
                    spdReturnLotList_Sheet1.RowCount++;

                    spdReturnLotList_Sheet1.SetValue(i_Row, (int)RET_LOT.CHK, true);
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_LOT_ID].Value = sLotId;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LOT_ID].Value = sLotId;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.QTY].Value = 0;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.UNIT].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_FLAG].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_ORDER_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LINE_NO].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ERP_PACK_ORDER_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_FLAG].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_ORDER_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.BOX_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.FINAL_BOX_ID].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.CMF_2].Value = txtReturnLotID.Text;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.RET_FLAG].Value = "";
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_QTY].Value = 0;
                    spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.COMMENT].Value = " ";

                    MPCF.FitColumnHeader(spdReturnLotList);
                    spdReturnLotList_Sheet1.Columns.Get((int)RET_LOT.COMMENT).Width = 400;
                    return;
                }

                // 데이터가 조회되면 데이터 찾아서 추가
                i_Row = spdReturnLotList_Sheet1.RowCount++;

                spdReturnLotList_Sheet1.SetValue(i_Row, (int)RET_LOT.CHK, false);
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_LOT_ID].Value = dt.Rows[0]["ORG_LOT_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LOT_ID].Value = dt.Rows[0]["PACK_LOT_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_FLAG].Value = dt.Rows[0]["PACK_FLAG"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_ORDER_ID].Value = dt.Rows[0]["PACK_ORDER_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.PACK_LINE_NO].Value = dt.Rows[0]["PACK_LINE_NO"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[0]["CMF_5"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_FLAG].Value = dt.Rows[0]["SHIP_FLAG"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.SHIP_ORDER_ID].Value = dt.Rows[0]["SHIP_ORDER_ID"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.BOX_ID].Value = dt.Rows[0]["BOX_ID_1"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.FINAL_BOX_ID].Value = dt.Rows[0]["BOX_ID_2"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.CMF_2].Value = dt.Rows[0]["CMF_2"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.RET_FLAG].Value = dt.Rows[0]["RET_FLAG"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.ORG_QTY].Value = dt.Rows[0]["QTY"];
                spdReturnLotList_Sheet1.Cells[i_Row, (int)RET_LOT.COMMENT].Value = " ";

                MPCF.FitColumnHeader(spdReturnLotList);
                spdReturnLotList_Sheet1.Columns.Get((int)RET_LOT.COMMENT).Width = 400;

                txtReturnLotID.SelectAll();

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
                for (int i = 0; i < spdReturnLotList_Sheet1.RowCount; i++)
                {
                    if (spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.QTY].Text);
                    }
                }

                spdReturnLotList_Sheet1.ColumnFooter.Cells[0, (int)RET_LOT.CHK].Value = iCount;
                spdReturnLotList_Sheet1.ColumnFooter.Cells[0, (int)RET_LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        // 반품
        private bool ReturnLot()
        {
            TRSNode in_node = new TRSNode("save_return_Lot_In");
            TRSNode out_node = new TRSNode("save_return_Lot_Out");
            TRSNode label_in_node = new TRSNode("print_label_In");
            TRSNode lot_list;
            TRSNode label_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("RET_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)RET_ORDER.RET_ORDER_ID].Text);
                in_node.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)RET_ORDER.LINE_NO].Text));
                in_node.AddString("RETURN_DATE", MPCF.ToStandardTime(dtpReturnDate.Value, MPGC.MP_CONVERT_DATETIME_FORMAT));

                double d_total_lot_qty = 0;
                double d_req_qty = MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)RET_ORDER.QTY].Text);

                // 반품 요청 수량 - 반품된 수량으로 체크
                d_req_qty -= MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)RET_ORDER.RETURNED_QTY].Text);


                for (int i = 0; i < spdReturnLotList_Sheet1.RowCount; i++)
                {
                    if (spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (string.Equals(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("RET_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.PACK_LOT_ID].Text);
                        lot_list.AddString("CMF_2", spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CMF_2].Text);
                        lot_list.AddDouble("QTY", MPCF.ToDbl(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.QTY].Text))
;
                        if (MPCF.ToDbl(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.QTY].Text) <= 0)
                        {
                            //CMN114 ERROR -0보다 큰 값을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(114));
                            return false;
                        }

                        d_total_lot_qty += MPCF.ToDbl(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.QTY].Text);

                        send_flag = true;
                    }
                }

                if (d_req_qty < d_total_lot_qty)
                {
                    //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(126));
                    return false;
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                in_node.AddDouble("TOTAL_QTY", d_total_lot_qty);

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Return_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                MPCR.SetInMsg(label_in_node);

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    label_list = label_in_node.AddNode("LOT_LIST");
                    label_list.AddString("LOT_ID", out_node.GetList(0)[i].GetString("LOT_ID"));
                }

                if (out_node.GetList(0).Count > 0)
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
        public bool ViewPrintLabel(TRSNode in_node)
        {
            string sFileName = "";
            try
            {
                sFileName = cdvLabelSize.Text;

                CSCF.ViewLabelList(sFileName, in_node, 'D');

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
                    case "RETURN":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdReturnLotList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        for (int i = 0; i < spdReturnLotList_Sheet1.RowCount; i++)
                        {
                            if (spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                            {
                                // 출하 지시 매핑 되어 있는데
                                if (MPCF.Trim(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.SHIP_ORDER_ID].Text) != "")
                                {
                                    // 분할 반품이라면
                                    if (MPCF.ToDbl(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.QTY].Text) != MPCF.ToDbl(spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.ORG_QTY].Text))
                                    {
                                        if (MPCF.Trim(cdvLabelSize.Text) == "")
                                        {
                                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                                            cdvLabelSize.Focus();
                                            return false;
                                        }
                                    }
                                }
                            }
                        }

                        break;

                    case "INPUT":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (MPCF.Trim(matId) == "")
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (MPCF.Trim(txtReturnLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblReturnLotID.Text + "]");
                            txtReturnLotID.Focus();
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
                        MPCF.ClearList(spdReturnLotList);
                        spdReturnLotList.ActiveSheet.ColumnFooter.Cells[0, (int)RET_LOT.CHK].Value = 0;
                        spdReturnLotList.ActiveSheet.ColumnFooter.Cells[0, (int)RET_LOT.QTY].Value = 0;

                        this.txtReturnLotID.Text = "";
                        matId = "";
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdReturnLotList);
                        spdReturnLotList.ActiveSheet.ColumnFooter.Cells[0, (int)RET_LOT.CHK].Value = 0;
                        spdReturnLotList.ActiveSheet.ColumnFooter.Cells[0, (int)RET_LOT.QTY].Value = 0;
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        this.dtpReturnDate.Value = DateTime.Now;

                        this.cdvDept.Text = "";
                        this.cdvMatID.Text = "";
                        this.cdvCustomerID.Text = "";
                        this.txtReturnOrderNo.Text = "";
                        this.txtReturnLotID.Text = "";
                        matId = "";
                        break;

                    case "ORDER_CLICK_CELL":

                        MPCF.ClearList(spdReturnLotList);
                        spdReturnLotList.ActiveSheet.ColumnFooter.Cells[0, (int)RET_LOT.CHK].Value = 0;
                        spdReturnLotList.ActiveSheet.ColumnFooter.Cells[0, (int)RET_LOT.QTY].Value = 0;

                        this.txtReturnLotID.Text = "";
                        matId = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition"
        private void frmTranReturnLot_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpReturnDate.Value = DateTime.Now;
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
        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatID.Text = popup.sMat_id;
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
        private void cdvCustomerID_ButtonPress(object sender, EventArgs e)
        {
            //고객사 팝업으로 변경
            try
            {
                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustomerID.Text = popup.g_CustomerId;
                    this.cdvCustomerID.DisplayText = popup.g_CustomerDesc;
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
        private void txtReturnLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT") == false)
                        return;

                    // 출하 진행 LOT 조회
                    ViewShippingLotList2(txtReturnLotID.Text);
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

                ViewReturnOrderList();
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
                if (CheckCondition("RETURN") == false)
                    return;

                if (ReturnLot())
                {
                    btnView_Click(null, null);
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

                matId = spdOrderList.ActiveSheet.Cells[e.Row, (int)RET_ORDER.MAT_ID].Text;
                retOrderId = spdOrderList.ActiveSheet.Cells[e.Row, (int)RET_ORDER.RET_ORDER_ID].Text;
                retLineNo = spdOrderList.ActiveSheet.Cells[e.Row, (int)RET_ORDER.LINE_NO].Text;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdReturnLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdReturnLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdReturnLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }
        private void spdReturnLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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
        private void spdReturnLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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
        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }
        private void cdvCustomerID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvCustomerID.DisplayText == "")
                cdvCustomerID.Text = "";
        }
        private void txtReturnOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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
        private void spdReturnLotList_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {


                SheetView sv = spdReturnLotList.ActiveSheet;

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

                            ViewShippingLotList2(sColumnList[0]);

                        }
                    }

                    //sv.RemoveRows(iActiveRow, (sv.RowCount - iActiveRow - 1) == 0 ? 1 : (sv.RowCount - iActiveRow - 1));

                    // if (sv.RowCount - iActiveRow - 1 != 0)
                    // {
                    //     sv.RowCount++;
                    // }


                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;
        }
        private void txtComment_TextChanged(object sender, EventArgs e)
        {
            if (ChkAllComment.Checked == true)
            {
                for (int i = 0; i < spdReturnLotList_Sheet1.RowCount; i++)
                {
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.COMMENT].Text = txtComment.Text.Trim();
                }
            }
            else
            {
                spdReturnLotList_Sheet1.Cells[spdReturnLotList_Sheet1.ActiveRowIndex, (int)RET_LOT.COMMENT].Text = txtComment.Text.Trim();
            }

        }
        #endregion


    }
}
