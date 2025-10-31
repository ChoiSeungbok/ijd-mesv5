using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

using FarPoint.Win.Spread;

//using CUS_QCM;
using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Diagnostics;

namespace CUS_WIP
{
    public partial class frmTranISkyDiaTran : CUS_COM.frmTranForm06
    {
        public frmTranISkyDiaTran()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Variable Definition "
        int BeforOrderRow = 0;
        int beforQceRow = 0;


        private const int DEFAULT_COL_COUNT = 17;
        private clsDerivedCharList cls_derived_char_list;
        #endregion

        #region " Constant Definition "
        private enum PACK_ORDER
        {
            CHK,                   // 1 : CHK
            PACK_ORDER_ID,         // 2 : 포장 지시 번호
            LINE_NO,               // 3 : 포장 라인 번호
            ERP_PACK_ORDER_ID,     // 4 : ERP 포장 지시 번호
            MAT_ID,                // 5 : 제품
            MAT_VER,               // 6 : 버전
            MAT_DESC,              // 7 : 제품명
            PACK_ORD_DATE,         // 8 : 포장지시일자
            QTY,                   // 9 : 포장수량
            REG_QTY,               // 10 : 등록 수량
            PACKED_QTY,            // 11 : 포장된 수량
            REMAIN_QTY,            // 12 : 남은 수량
            STOCK_QTY,             // 13 : 재고 수량
            UNIT,                  // 14 : 단위
            CONV_UNIT_QTY,         // 15 : 제품 단위 수량           
            CONV_STOCK_QTY,        // 16 : 환산 재고 수량           
            CONV_UNIT,             // 17 : 환산 단위
            PACK_ORD_STATUS,       // 18 : 포장상태
            CUSTOMER_ID,           // 19 : 고객사
            CUSTOMER_SITE_ID,      // 20 : 고객사 SITE ID
            CUSTOMER_NAME,         // 21 : 고객사명
            DELIVERY_ID,           // 22 : 납품처 ID
            DELIVERY_NAME,         // 23 : 최종 납품처명
            PACKING_INSTRUCTIONS,  // 24 : 용기
            CTM_STOCK_QTY,         // 25 : CTM CW-RUD-QC 창고 재고
            OPER,                  // 26 : 창고
            OPER_DESC,             // 27 : 창고명
            DRAWING_FLAG,          // 28 : 도면유무
            ORDER_TYPE,            // 29 : 주문유형
            REQUEST_DATE,          // 30 : 출하요청일 
            SCHEDULE_SHIP_DATE,    // 31 : 예상납기일
            BARE_INPUT_DATE,       // 32 : 베어인계일
            EXPECT_SHIP_DATE,      // 33 : 출하예정일
            PO_GUBUN,              // 34: 발주구분
            LABEL_TYPE,            // 35 : 라벨 유형
            LABEL_MESH,            // 36 : 라벨 사이즈 
            LABEL_NAME,            // 37 : 라벨품명
            INCLUDE_INSPECTION,    // 38 : 검사 성적서 포함 여부
            PACK_COMMENT,          // 39 : 비고
            TREE_MONTH,            // 40 : 3개월평균(스펠링틀린건......^^;)
            SIX_MONTH,             // 41 : 비고
            PART_NO,               // 42 : PART_NO(PDC 전용)
            DRAW_NO,               // 43 : DRAW_NO(PDC 전용)
            DOC_NO,                // 44 : DOC_NO(PDC 전용)
            DOC_LINE_NO,          // 45 : DOC_LINE_NO(PDC 전용)
            ORDER_ID
        }

        private enum CUTLOT_INFO
        {
            START_END,
            ORDER_ID,
            LOT_ID,
            ROUND_MAT_ID,
            ROUND_MAT_DESC,
            ROUND_QTY,
            ROUND_EDIT_QTY,
            CUT_LOT_ID,
            CUT_MAT_ID,
            CUT_MAT_DESC,
            CUT_QTY,
            CUT_LOSS_CODE,
            CUT_LOSS_QTY,
            FLOW,
            OPER,
            NEXT_OPER,
        }

        private enum QCLOT_INFO
        {
            START_END,
            ORDER_ID,
            LOT_ID,
            ROUND_MAT_ID,
            ROUND_MAT_DESC,
            ROUND_QTY,
            ROUND_EDIT_QTY,
            QC_LOT_ID,
            QC_MAT_ID,
            QC_MAT_DESC,
            QC_QTY,
            QC_LOSS_CODE,
            QC_LOSS_QTY,
            FLOW,
            OPER,
            NEXT_OPER,
            COL_SET_ID,
            COL_SET_VERSION,
            INSP_ID
        }


        private enum WHLOT_INFO
        {
            CHK,                   // 1 : 공정 LOT ID
            LOT_ID,                // 2 : 공정 LOT ID
            MAT_DESC,              // 3 : 제품명
            QTY,                   // 4 : 수량
            PACKED_QTY,            // 5 : 포장된 수량
            REMAIN_QTY,            // 6 : 포장 등록 가능 수량
            UNIT,                  // 7 : 단위
            PACKING_INSTRUCTIONS,  // 8 : 용기
            DRAWING_FLAG,          // 9 : 도면유무
            MAT_ID,                // 10 : 제품
            MAT_VER,               // 11 : 버전
            OPER,                  // 12 : 창고
            OPER_DESC              // 13 : 창고명
        }

        private enum PACKLOT_INFO
        {
            CHK,                     // 1 : CHECK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID
            SEQ,                     // 4 : 순번
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            QTY,                     // 8 : 수량
            UNIT,                    // 9 : 단위
            CMF_1,                   // 10 : 코팅 퍼센트(GRT 전용)
            PACK_FLAG,               // 11 : 포장 여부
            PACK_ORDER_ID,           // 12 : 포장 지시 번호
            PACK_LINE_NO,            // 13 : 포장 라인 번호
            ERP_PACK_ORDER_ID,       // 14 : ERP 포장 지시 번호
            SHIP_FLAG,               // 15 : 출하 여부
            BOX_ID,                  // 16 : 박스 ID
            FINAL_BOX_ID             // 17 : 최종 박스 ID
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

        private enum SHIP_PACK_LOT
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
            FINAL_BOX_ID,           // 14 : 최종 박스 ID
            REPORT_NO                // 15:  Report No

        }

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

        }

        private enum COLLECTION_DATA
        {

            CHAR_COL,
            CHAR_DESC_COL,
            CHAR_SEQ,
            LOWER_SPEC_LIMIT,
            TARGET_VALUE,
            UPPER_SPEC_LIMIT,
            SPEC_COL,
            OPT_INPUT_COL,
            VALUE_TYPE_COL,
            VALUE_COUNT_COL,
            DEF_UNIT_FLAG_COL,
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL

        }

        private enum LOT_ING_INFO
        {

            CHK,                   // 1 : 공정 LOT ID
            INPUT_LOT_ID,
            LOT_ID,                // 2 : 공정 LOT ID
            MAT_DESC,              // 3 : 제품명
            QTY,                   // 4 : 수량
            PACKED_QTY,            // 5 : 포장된 수량
            REMAIN_QTY,            // 6 : 포장 등록 가능 수량
            UNIT,                  // 7 : 단위
            PACKING_INSTRUCTIONS,  // 8 : 용기
            DRAWING_FLAG,          // 9 : 도면유무
            MAT_ID,                // 10 : 제품
            MAT_VER,               // 11 : 버전
            OPER,                  // 12 : 창고
            OPER_DESC              // 13 : 창고명

        }

        #endregion


        #region "sheet Search"

        #region 주문지시조회
        //주문지시조회
        private void ViewOrderList()
        {
            try
            {




                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[14];
                DataTable dt = null;
                string sSql = "";
                string sViewID = "";
                List<string> ItemList1 = new List<string>();
                List<string> ItemList2 = new List<string>();

                //     string sSqlText = "";
                //    string sGradeList_1 = "";
                //    string sGradeList_2 = "";
                //   string sGradeList_3 = "";
                //    string sGradeList_4 = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = "CTM";

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = "";

                dvcArgu[3].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[3].sCondition_Value = "";

                dvcArgu[4].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[4].sCondition_Value = "";

                dvcArgu[5].sCondition_ID = "PACK_ORD_STATUS";
                dvcArgu[5].sCondition_Value = "WAIT";

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";


                sViewID = "CWIP2091-001";
                dvcArgu[8].sCondition_ID = "ITEM_LIST1";
                dvcArgu[8].sCondition_Value = "";

                dvcArgu[9].sCondition_ID = "ITEM_LIST2";
                dvcArgu[9].sCondition_Value = "";



                dvcArgu[10].sCondition_ID = "MAT_DESC";
                dvcArgu[10].sCondition_Value = txtOrderMatdesc.Text;

                dvcArgu[11].sCondition_ID = "ERP_PACK_ORDER_ID";
                dvcArgu[11].sCondition_Value = "";

                dvcArgu[12].sCondition_ID = "NEGATIVE_FLAG";
                dvcArgu[12].sCondition_Value = "N";




                dvcArgu[13].sCondition_ID = "SQL_TEXT";
                dvcArgu[13].sCondition_Type = "TEXT";
                dvcArgu[13].sCondition_Value = " AND 1=1";

                MPCF.ClearList(spdOrderList);
                MPCF.ClearList(spdPackingLotList);
                MPCF.ClearList(spdCutOperLotList);
                MPCF.ClearList(spdDataCollection);
                MPCF.ClearList(spdOrderDetailList);
                MPCF.ClearList(spdPackShipList);
                MPCF.ClearList(spdQcOperLotList);
                MPCF.ClearList(spdWhLotList);



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();




                    return;
                }


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderList_Sheet1.RowCount++;


                    spdOrderList_Sheet1.SetValue(i, (int)PACK_ORDER.CHK, false);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LINE_NO].Value = dt.Rows[i]["LINE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_1"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PACK_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.QTY].Value = dt.Rows[i]["QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REG_QTY].Value = dt.Rows[i]["REG_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACKED_QTY].Value = dt.Rows[i]["PACKED_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value = dt.Rows[i]["REMAIN_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.STOCK_QTY].Value = dt.Rows[i]["STOCK_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CONV_UNIT_QTY].Value = dt.Rows[i]["CONV_UNIT_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CONV_STOCK_QTY].Value = dt.Rows[i]["CONV_STOCK_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CONV_UNIT].Value = dt.Rows[i]["CONV_UNIT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Value = dt.Rows[i]["PACK_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_SITE_ID].Value = dt.Rows[i]["CUSTOMER_SITE_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACKING_INSTRUCTIONS].Value = dt.Rows[i]["PACKING_INSTRUCTIONS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CTM_STOCK_QTY].Value = dt.Rows[i]["CTM_STOCK_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER].Value = dt.Rows[i]["OPER"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.ORDER_TYPE].Value = dt.Rows[i]["ORDER_TYPE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REQUEST_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["REQUEST_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SCHEDULE_SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SCHEDULE_SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.BARE_INPUT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CMF_2"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["EXPECT_SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PO_GUBUN].Value = dt.Rows[i]["PO_GUBUN"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_TYPE].Value = dt.Rows[i]["LABEL_TYPE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_MESH].Value = dt.Rows[i]["LABEL_MESH"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.INCLUDE_INSPECTION].Value = dt.Rows[i]["INCLUDE_INSPECTION"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_COMMENT].Value = dt.Rows[i]["PACK_COMMENT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.TREE_MONTH].Value = dt.Rows[i]["TREE_MONTH"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SIX_MONTH].Value = dt.Rows[i]["SIX_MONTH"];

                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PART_NO].Value = dt.Rows[i]["PART_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DRAW_NO].Value = dt.Rows[i]["DRAW_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DOC_NO].Value = dt.Rows[i]["DOC_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DOC_LINE_NO].Value = dt.Rows[i]["DOC_LINE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];

                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Text.Trim().ToUpper() == "WAIT")
                    {
                        spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Locked = false;
                    }
                    else
                    {
                        spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Locked = true;
                    };



                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Trim() == "")  //
                    {
                        spdOrderList.ActiveSheet.Rows[i].ForeColor = Color.Red;
                    }
                    else if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", "") == DateTime.Now.ToString("yyyyMMdd")) //출하예정일이 현재일이면 파란색
                    {
                        spdOrderList_Sheet1.Rows.Get(i).ForeColor = Color.Blue; //System.Drawing.Color.FromArgb(((int)(((byte)(1)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
                    }
                    else if (Convert.ToInt32(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", "")) < Convert.ToInt32(DateTime.Now.ToString("yyyyMMdd"))) //출하예정일이 지났으면 녹색
                    {
                        spdOrderList_Sheet1.Rows.Get(i).ForeColor = Color.Green; //System.Drawing.Color.FromArgb(((int)(((byte)(29)))), ((int)(((byte)(219)))), ((int)(((byte)(22)))));
                    }
                    else
                    {

                    }



                };


                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.SIX_MONTH).Visible = true;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.BARE_INPUT_DATE).Locked = true;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.BARE_INPUT_DATE).Visible = false;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.PART_NO).Locked = true;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DRAW_NO).Locked = true;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_NO).Locked = true;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_LINE_NO).Locked = true;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.PART_NO).Visible = false;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DRAW_NO).Visible = false;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_NO).Visible = false;
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_LINE_NO).Visible = false;



                SetSheetColor();

                MPCF.FitColumnHeader(spdOrderList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region 절단가공(외주가공)

        private void ViewCutLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "ERP_PACK_ORDER_ID";
                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[1].sCondition_Value = "";
                }
                else
                {
                    dvcArgu[1].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Text;
                }


                dvcArgu[2].sCondition_ID = "MAT_ID";
                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[2].sCondition_Value = "";
                }
                else
                {
                    dvcArgu[2].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.MAT_ID].Text;
                }

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvCutWo.Text;




                sViewID = "CWIP2091-002";

                MPCF.ClearList(spdCutOperLotList);

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
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
                buttonStart.Text = "COMPLETE";
                buttonStart.TextColor = System.Drawing.Color.White;
                buttonStart.UseVisualStyleBackColor = false;








                for (i = 0; i < dt.Rows.Count; i++)
                {

                    /*
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];

                    */

                    spdCutOperLotList_Sheet1.RowCount++;


                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_MAT_ID].Value = dt.Rows[i]["ROUND_MAT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_MAT_DESC].Value = dt.Rows[i]["ROUND_MAT_DESC"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_EDIT_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_LOT_ID].Value = dt.Rows[i]["CUT_LOT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_MAT_ID].Value = dt.Rows[i]["CUT_MAT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_MAT_DESC].Value = dt.Rows[i]["CUT_MAT_DESC"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_QTY].Value = dt.Rows[i]["CUT_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_LOSS_CODE].Value = dt.Rows[i]["CUT_LOSS_CODE"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_LOSS_QTY].Value = dt.Rows[i]["CUT_LOSS_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.NEXT_OPER].Value = dt.Rows[i]["NEXT_OPER"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];


                    spdCutOperLotList_Sheet1.Cells[i, (int)LOT_INFO.START_END].CellType = buttonStart;


                    txtCutLotId.Text = "";



                }
                MPCF.FitColumnHeader(spdCutOperLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void ViewCutLotList2()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "ERP_PACK_ORDER_ID";
                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[1].sCondition_Value = "";
                }
                else
                {
                    dvcArgu[1].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Text;
                }


                dvcArgu[2].sCondition_ID = "MAT_ID";
                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[2].sCondition_Value = "";
                }
                else
                {
                    dvcArgu[2].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.MAT_ID].Text;
                }

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvCutWo.Text;

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtCutLotId.Text;


                sViewID = "CWIP2091-007";

                MPCF.ClearList(spdCutOperLotList);

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
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
                buttonStart.Text = "COMPLETE";
                buttonStart.TextColor = System.Drawing.Color.White;
                buttonStart.UseVisualStyleBackColor = false;








                for (i = 0; i < dt.Rows.Count; i++)
                {

                    /*
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];

                    */

                    spdCutOperLotList_Sheet1.RowCount++;


                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_MAT_ID].Value = dt.Rows[i]["ROUND_MAT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_MAT_DESC].Value = dt.Rows[i]["ROUND_MAT_DESC"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ROUND_EDIT_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_LOT_ID].Value = dt.Rows[i]["CUT_LOT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_MAT_ID].Value = dt.Rows[i]["CUT_MAT_ID"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_MAT_DESC].Value = dt.Rows[i]["CUT_MAT_DESC"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_QTY].Value = dt.Rows[i]["CUT_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_LOSS_CODE].Value = dt.Rows[i]["CUT_LOSS_CODE"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.CUT_LOSS_QTY].Value = dt.Rows[i]["CUT_LOSS_QTY"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.NEXT_OPER].Value = dt.Rows[i]["NEXT_OPER"];
                    spdCutOperLotList_Sheet1.Cells[i, (int)CUTLOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];


                    spdCutOperLotList_Sheet1.Cells[i, (int)LOT_INFO.START_END].CellType = buttonStart;


                    // cdvCutWo.Text = "";
                    // cdvCutPo.Text = "";



                }
                MPCF.FitColumnHeader(spdCutOperLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private bool SaveCutProcess()
        {
            try
            {


                if (MPCF.ToDbl(spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.ROUND_EDIT_QTY].Text) == 0)
                {
                    MPCF.ShowMsgBox("투입수량 입력하여야 합니다.");
                    return false;

                }

                if (MPCF.ToDbl(spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.CUT_QTY].Text) == 0)
                {
                    MPCF.ShowMsgBox("생산수량 입력하여야 합니다.");
                    return false;

                }


                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '9';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.OPER].Value);
                in_node.AddString("ORDER_ID", spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.ORDER_ID].Value);


                Lot_list = in_node.AddNode("LOT_TBL");
                Lot_list.AddString("LOT_ID", spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.CUT_LOT_ID].Text);
                Lot_list.AddString("ORDER_ID", spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.ORDER_ID].Text);
                //Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                Lot_list.AddDouble("SUM_QTY", MPCF.ToDbl(spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.CUT_QTY].Text));
                Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.CUT_QTY].Text));
                Lot_list.AddDouble("LOSS_QTY", 0);



                Lot_list.AddString("BOM_LOT_ID", spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.LOT_ID].Text);


                Lot_list.AddString("BOM_OUT_OPER", "CO-SKY");
                Lot_list.AddString("BOM_LOT_TYPE", "WIP");
                Lot_list.AddString("IBOM_NPUT_TYPE", "BOM");
                Lot_list.AddString("BOM_MAT_ID", spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.ROUND_MAT_ID].Text);
                Lot_list.AddDouble("BOM_QTY_1", MPCF.ToDbl(spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.ROUND_QTY].Text));
                Lot_list.AddDouble("BOM_BOM_QTY", MPCF.ToDbl(spdCutOperLotList_Sheet1.Cells[spdCutOperLotList_Sheet1.ActiveRowIndex, (int)CUTLOT_INFO.ROUND_EDIT_QTY].Text));


                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
                    return false;
                else
                {
                    MPCR.ShowSuccessMsg(out_node);

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

        #region 절단품검사

        private void ViewQcLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "ERP_PACK_ORDER_ID";
                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[1].sCondition_Value = "";

                }
                else
                {

                    dvcArgu[1].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Text;
                }

                dvcArgu[2].sCondition_ID = "MAT_ID";

                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[2].sCondition_Value = "";

                }
                else
                {

                    dvcArgu[2].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.MAT_ID].Text;
                }



                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvQcWo.Text;

                sViewID = "CWIP2091-003";



                MPCF.ClearList(spdQcOperLotList);


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }





                FarPoint.Win.Spread.CellType.ButtonCellType buttonStart = new FarPoint.Win.Spread.CellType.ButtonCellType();




                buttonStart.BackgroundStyle = FarPoint.Win.BackStyle.Gradient;
                buttonStart.ButtonColor = System.Drawing.Color.Blue;
                buttonStart.ButtonColor2 = System.Drawing.Color.Blue;
                buttonStart.DarkColor = System.Drawing.Color.Blue;
                buttonStart.GradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
                buttonStart.LightColor = System.Drawing.Color.Blue;
                buttonStart.Text = "COMPLETE";
                buttonStart.TextColor = System.Drawing.Color.White;
                buttonStart.UseVisualStyleBackColor = false;







                for (i = 0; i < dt.Rows.Count; i++)
                {

                    /*
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];

                    */

                    spdQcOperLotList_Sheet1.RowCount++;


                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_MAT_ID].Value = dt.Rows[i]["ROUND_MAT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_MAT_DESC].Value = dt.Rows[i]["ROUND_MAT_DESC"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_EDIT_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_LOT_ID].Value = dt.Rows[i]["QC_LOT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_MAT_ID].Value = dt.Rows[i]["QC_MAT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_MAT_DESC].Value = dt.Rows[i]["QC_MAT_DESC"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_QTY].Value = dt.Rows[i]["QC_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_LOSS_CODE].Value = dt.Rows[i]["QC_LOSS_CODE"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_LOSS_QTY].Value = dt.Rows[i]["QC_LOSS_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.NEXT_OPER].Value = dt.Rows[i]["NEXT_OPER"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];

                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.COL_SET_ID].Value = dt.Rows[i]["COL_SET_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.COL_SET_VERSION].Value = dt.Rows[i]["COL_SET_VERSION"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.INSP_ID].Value = dt.Rows[i]["INSP_ID"];

                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.START_END].CellType = buttonStart;



                    txtQcLotId.Text = "";




                }
                MPCF.FitColumnHeader(spdQcOperLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewQcLotList2()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ERP_PACK_ORDER_ID";
                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[1].sCondition_Value = "";

                }
                else
                {

                    dvcArgu[1].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Text;
                }


                dvcArgu[2].sCondition_ID = "MAT_ID";

                if (spdOrderList_Sheet1.RowCount == 0)
                {
                    dvcArgu[2].sCondition_Value = "";

                }
                else
                {

                    dvcArgu[2].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.MAT_ID].Text;
                }



                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvQcWo.Text;

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtQcLotId.Text;

                sViewID = "CWIP2091-008";



                MPCF.ClearList(spdQcOperLotList);


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }





                FarPoint.Win.Spread.CellType.ButtonCellType buttonStart = new FarPoint.Win.Spread.CellType.ButtonCellType();




                buttonStart.BackgroundStyle = FarPoint.Win.BackStyle.Gradient;
                buttonStart.ButtonColor = System.Drawing.Color.Blue;
                buttonStart.ButtonColor2 = System.Drawing.Color.Blue;
                buttonStart.DarkColor = System.Drawing.Color.Blue;
                buttonStart.GradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
                buttonStart.LightColor = System.Drawing.Color.Blue;
                buttonStart.Text = "COMPLETE";
                buttonStart.TextColor = System.Drawing.Color.White;
                buttonStart.UseVisualStyleBackColor = false;









                for (i = 0; i < dt.Rows.Count; i++)
                {

                    /*
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];

                    */

                    spdQcOperLotList_Sheet1.RowCount++;


                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_MAT_ID].Value = dt.Rows[i]["ROUND_MAT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_MAT_DESC].Value = dt.Rows[i]["ROUND_MAT_DESC"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ROUND_EDIT_QTY].Value = dt.Rows[i]["ROUND_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_LOT_ID].Value = dt.Rows[i]["QC_LOT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_MAT_ID].Value = dt.Rows[i]["QC_MAT_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_MAT_DESC].Value = dt.Rows[i]["QC_MAT_DESC"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_QTY].Value = dt.Rows[i]["QC_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_LOSS_CODE].Value = dt.Rows[i]["QC_LOSS_CODE"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.QC_LOSS_QTY].Value = dt.Rows[i]["QC_LOSS_QTY"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.NEXT_OPER].Value = dt.Rows[i]["NEXT_OPER"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];

                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.COL_SET_ID].Value = dt.Rows[i]["COL_SET_ID"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.COL_SET_VERSION].Value = dt.Rows[i]["COL_SET_VERSION"];
                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.INSP_ID].Value = dt.Rows[i]["INSP_ID"];

                    spdQcOperLotList_Sheet1.Cells[i, (int)QCLOT_INFO.START_END].CellType = buttonStart;



                    //  cdvQcWo.Text = "";
                    //    cdvQcPo.Text = "";


                }
                MPCF.FitColumnHeader(spdQcOperLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void SetSheetColor()
        {
            try
            {

                for (int i = 0; i < spdOrderList_Sheet1.RowCount; i++)
                {
                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SCHEDULE_SHIP_DATE].Value.ToString().Length <= 1)
                    {
                        spdOrderList_Sheet1.Rows.Get(i).LockBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
                    }
                    else
                    {
                        spdOrderList_Sheet1.Rows.Get(i).LockBackColor = System.Drawing.Color.White;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private bool Collect_Inspection_Data()
        {

            /*
            if (CheckCondition(CSGC.CHECK.SAVE) == false)
                return false;
                */

            TRSNode in_node = new TRSNode("COLLECT_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");
            TRSNode data_list;
            //   TRSNode loss_list;

            int iRow = 0;
            // int iLossRow = 0;
            int i_value_start = (int)COLLECTION_DATA.VALUE_START_COL;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.QC_LOT_ID].Text));
                in_node.AddString("MAT_ID", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.QC_MAT_ID].Text));
                in_node.AddInt("MAT_VER", 1);

                in_node.AddString("COL_SET_ID", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.COL_SET_ID].Text));
                in_node.AddInt("COL_SET_VERSION", MPCF.ToInt(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.COL_SET_VERSION].Text));

                in_node.AddString("INSP_ID", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.INSP_ID].Text));
                in_node.AddInt("INSP_SEQ", 1);




                in_node.AddString("RWK_OPER", "");

                in_node.AddString("INSP_COMMENT", txtQcComment.Text);

                for (iRow = 0; iRow < spdDataCollection.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddString("CHAR_ID", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.CHAR_COL].Value);
                    data_list.AddInt("CHAR_SEQ", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.CHAR_SEQ].Value);
                    data_list.AddInt("UNIT_SEQ", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UNIT_SEQ_COL].Value);
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UNIT_COL].Value);
                    data_list.AddChar("VALUE_TYPE", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_TYPE_COL].Value);
                    data_list.AddInt("VALUE_COUNT", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_COUNT_COL].Value);


                    for (int iCol = 1; iCol - 1 + i_value_start < spdDataCollection.ActiveSheet.ColumnCount; iCol++)
                    {
                        if (iCol > 26)
                            break;

                        data_list.AddString("VALUE_" + iCol.ToString(), spdDataCollection.ActiveSheet.Cells[iRow, iCol - 1 + i_value_start].Value);
                    }
                }

                /*
                for (iLossRow = 0; iLossRow < spdLossInfo.ActiveSheet.RowCount; iLossRow++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_QTY].Value) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");

                        loss_list.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_CODE].Value);  // LOSS_CODE
                        loss_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_QTY].Value));
                        if (spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.MAIN_YN].Value.ToString().ToUpper() == "TRUE")
                        {
                            loss_list.AddChar("MAIN_FLAG", 'Y');
                        }
                        else
                        {
                            loss_list.AddChar("MAIN_FLAG", 'N');
                        }
                    }
                }
                */


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data", in_node, ref out_node, false) == false)
                {
                    return false;
                }



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }


        private bool Inspection_Judge()
        {
            //Vaildation check
            /*
            if (VaildationCheckJudge() == false)
            {
                return false;
            }
            */

            TRSNode in_node = new TRSNode("INSPECTION_JUDGE_IN");
            TRSNode out_node = new TRSNode("INSPECTION_JUDGE_OUT");
            //TRSNode loss_list;
            TRSNode worker_list;

            // int iRow = 0;
            // int iWrkRow = 0;

            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';

                //INSP_ID, LOT_ID, INSP_JUDGE_FLAG, REWORK_OPER, INSP_COMMENT
                sLotID = MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.QC_LOT_ID].Text);

                in_node.AddString("INSP_ID", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.INSP_ID].Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.COL_SET_ID].Text));
                in_node.AddInt("COL_SET_VERSION", MPCF.ToInt(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.COL_SET_VERSION].Text));
                in_node.AddChar("INSP_JUDGE_FLAG", "P");  // 검사요청 ID
                in_node.AddString("TO_FLOW", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.FLOW].Text));
                in_node.AddString("TO_OPER", MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.OPER].Text));                   //재가공 공정
                in_node.AddString("INSP_COMMENT", MPCF.Trim(txtQcComment.Text));                        //주석
                in_node.AddString("JUDGE_OPER", "OC06020_2");                        // GCM "C_INSP_JUDGE" 검색용


                /*

                // Loss 정보
                for (iRow = 0; iRow < spdLossInfo.ActiveSheet.RowCount; iRow++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");

                        loss_list.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_CODE].Value);  // LOSS_CODE
                        loss_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value));
                        if (spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.MAIN_YN].Value.ToString().ToUpper() == "TRUE")
                        {
                            loss_list.AddChar("MAIN_FLAG", 'Y');
                        }
                        else
                        {
                            loss_list.AddChar("MAIN_FLAG", 'N');
                        }
                    }
                }
                */


                worker_list = in_node.AddNode("WORKER_LIST");

                worker_list.AddString("WORKER_ID", "SKYDIA");  // WORKER_ID
                worker_list.AddString("WORKER_DESC", "SKYDIA");  // WORKER_DESC
                worker_list.AddString("WORK_TYPE", " ");  // WORK_TYPE


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Inspection_Judge", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }



        #endregion

        #region 포장등록


        private void ViewWHLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.MAT_ID].Text;

                dvcArgu[2].sCondition_ID = "MAT_VER";
                dvcArgu[2].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.MAT_VER].Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = "CW-CUT-Q";

                MPCF.ClearList(spdWhLotList);
                MPCF.ClearList(spdPackingLotList);

                if (TPDR.GetDataOne("", ref dt, "CWIP2091-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWhLotList);
                    return;
                }

                MPCF.ClearList(spdWhLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWhLotList_Sheet1.RowCount++;

                    spdWhLotList_Sheet1.SetValue(i, (int)WHLOT_INFO.CHK, false);
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.PACKED_QTY].Value = dt.Rows[i]["PACKED_QTY"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.REMAIN_QTY].Value = (MPCF.ToDbl(dt.Rows[i]["QTY"]) - MPCF.ToDbl(dt.Rows[i]["PACKED_QTY"])).ToString();
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];

                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.DRAWING_FLAG].Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.DRAWING_FLAG].Value;
                    spdWhLotList_Sheet1.Cells[i, (int)WHLOT_INFO.PACKING_INSTRUCTIONS].Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.PACKING_INSTRUCTIONS].Value;



                }
                MPCF.FitColumnHeader(spdWhLotList);


                spdWhLotList_Sheet1.Columns[(int)WHLOT_INFO.CHK].Locked = false;
                spdWhLotList_Sheet1.Columns[(int)WHLOT_INFO.LOT_ID].Locked = false;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }






        private void ViewPackingLotList2()
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

                dvcArgu[1].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[1].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text;

                dvcArgu[2].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[2].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2091-010", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackShipList);
                    return;
                }

                MPCF.ClearList(spdPackShipList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    spdPackingLotList_Sheet1.SetValue(i, (int)PACKLOT_INFO.CHK, false);

                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.QTY].Value = dt.Rows[i]["QTY"];


                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                }
                MPCF.FitColumnHeader(spdPackingLotList_Sheet1);

                for (i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACKLOT_INFO.QTY].Text);
                }

                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACKLOT_INFO.QTY].Value = dSumQty;


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion

        #region 출하

        private void ViewShippingOrderDetailList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[1].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text;

                dvcArgu[2].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[2].sCondition_Value = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text;


                if (TPDR.GetDataOne("", ref dt, "CWIP2091-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderDetailList);

                    MPCF.ClearList(spdPackShipList);
                    return;
                }

                MPCF.ClearList(spdOrderDetailList);
                MPCF.ClearList(spdPackShipList);

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




                }
                MPCF.FitColumnHeader(spdOrderDetailList);

                ViewPackingLotList(spdOrderDetailList_Sheet1.Cells[0, (int)SHIP_DTL.SHIP_ORDER_ID].Text, spdOrderDetailList_Sheet1.Cells[0, (int)SHIP_DTL.SEQ].Text);


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }







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

                if (TPDR.GetDataOne("", ref dt, "CWIP2091-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackShipList);
                    return;
                }

                MPCF.ClearList(spdPackShipList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackShipList_Sheet1.RowCount++;

                    spdPackShipList_Sheet1.SetValue(i, (int)SHIP_PACK_LOT.CHK, true);

                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_5"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                }
                MPCF.FitColumnHeader(spdPackShipList_Sheet1);

                for (i = 0; i < spdPackShipList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdPackShipList.ActiveSheet.Cells[i, (int)SHIP_PACK_LOT.QTY].Text);
                }

                spdPackShipList.ActiveSheet.ColumnFooter.Cells[0, (int)SHIP_PACK_LOT.QTY].Value = dSumQty;


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        #endregion

        #region "진행현황"

        //LOT 진행정보 조회
        private void ViewLotIngList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = txtIViewMatdesc.Text;

                dvcArgu[2].sCondition_ID = "MAT_VER";
                dvcArgu[2].sCondition_Value = 1;


                dvcArgu[3].sCondition_ID = "OPER";


                if (rdoCutOper.Checked == true)
                {
                    dvcArgu[3].sCondition_Value = "CO-SKY";
                }
                else if (rdoQcOper.Checked == true)
                {
                    dvcArgu[3].sCondition_Value = "OC06020";
                }
                else if (rdoCutWh.Checked == true)
                {
                    dvcArgu[3].sCondition_Value = "CW-CUT-Q";
                }
                else if (rdoStgWh.Checked == true)
                {
                    dvcArgu[3].sCondition_Value = "CB-STG";
                }


                MPCF.ClearList(spdLotIngView);

                if (TPDR.GetDataOne("", ref dt, "CWIP2091-009", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotIngView);
                    return;
                }


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotIngView_Sheet1.RowCount++;

                    spdLotIngView_Sheet1.SetValue(i, (int)LOT_ING_INFO.CHK, false);
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.INPUT_LOT_ID].Value = dt.Rows[i]["INPUT_LOT_ID"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.PACKED_QTY].Value = dt.Rows[i]["PACKED_QTY"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.REMAIN_QTY].Value = (MPCF.ToDbl(dt.Rows[i]["QTY"]) - MPCF.ToDbl(dt.Rows[i]["PACKED_QTY"])).ToString();
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];



                }
                MPCF.FitColumnHeader(spdLotIngView);


                spdLotIngView_Sheet1.Columns[(int)LOT_ING_INFO.CHK].Locked = false;
                spdLotIngView_Sheet1.Columns[(int)LOT_ING_INFO.LOT_ID].Locked = false;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion



        #endregion

        #region " Event Definition "

        private void frmTranISkyDiaTran_Load(object sender, EventArgs e)
        {
            //한국 CTM 고정 한국 외주업체 (SKY DIA에서만 사용)
            cdvDept.Text = CSGC.CP_AREA_CTM;

        }

        private void InitControl()
        {
            try
            {


                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            ViewOrderList();
        }


        private void spdOrderList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                /*
                if(BeforOrderRow == e.Range.Row)
                {
                    return;
                }
                */


                cdvCutWo.Text = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.ORDER_ID].Text;
                cdvQcWo.Text = spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.ORDER_ID].Text;


                switch (tbMenu.SelectedIndex)
                {
                    case 0:  //절단가공(외주가공)
                        ViewCutLotList();
                        break;
                    case 1: //절단품검사
                        ViewQcLotList();
                        SelectedItemChangedByColSet();
                        break;
                    case 2: //포장등록
                        ViewWHLotList();
                        ViewPackingLotList2();
                        break;
                    case 3: //출하등록
                        ViewShippingOrderDetailList();
                        break;
                    case 4: //현황

                        break;

                }

                BeforOrderRow = e.Range.Row;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }

        private void btnDrawing_Click(object sender, EventArgs e)
        {
            if (spdQcOperLotList_Sheet1.RowCount == 0)
            {
                return;
            }


            string sMatid = "";
            int iRow = 0;
            if (spdQcOperLotList_Sheet1.ActiveRowIndex > 0)
            {
                iRow = spdQcOperLotList_Sheet1.ActiveRowIndex;
            }

            sMatid = spdQcOperLotList_Sheet1.Cells[iRow, (int)QCLOT_INFO.QC_MAT_ID].Text;
            string url = @"http://197.200.11.142/DIA_FILE_SERVER/DRAWING_FILE/" + MPCF.Trim(sMatid) + ".PDF";
            Process.Start(new ProcessStartInfo(url) { UseShellExecute = true });
        }

        private void btnDrawing2_Click(object sender, EventArgs e)
        {
            if (spdCutOperLotList_Sheet1.RowCount == 0)
            {
                return;
            }


            string sMatid = "";
            int iRow = 0;
            if (spdCutOperLotList_Sheet1.ActiveRowIndex > 0)
            {
                iRow = spdCutOperLotList_Sheet1.ActiveRowIndex;
            }

            sMatid = spdCutOperLotList_Sheet1.Cells[iRow, (int)CUTLOT_INFO.CUT_MAT_ID].Text;
            string url = @"http://197.200.11.142/DIA_FILE_SERVER/DRAWING_FILE/" + MPCF.Trim(sMatid) + ".PDF";
            Process.Start(new ProcessStartInfo(url) { UseShellExecute = true });
        }
        private void cdvCutWo_ButtonPress(object sender, EventArgs e)
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

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;

                popup.g_SubAreaCode = "C_OSP";
                popup.g_SubAreaDesc = "사외외주";

                popup.g_OperCode = "OC90010";
                popup.g_OperDesc = "외주가공";

                popup.g_WorkOrder = "%-SK%";
                /*
                popup.cdvOrderStatus.Text = "O";
                popup.cdvOrderStatus.DisplayText = "Open";
                */

                popup.dtpFromDate.Text = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";
                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();


                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvCutWo.Text = popup.g_WorkOrder;
                    cdvCutPo.Text = popup.g_PoNo;

                    ViewCutLotList();

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


        private void cdvCutPo_ButtonPress(object sender, EventArgs e)
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

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;

                popup.g_SubAreaCode = "C_OSP";
                popup.g_SubAreaDesc = "사외외주";

                popup.g_OperCode = "OC90010";
                popup.g_OperDesc = "외주가공";

                popup.g_WorkOrder = "%-SK%";
                /*
                popup.cdvOrderStatus.Text = "O";
                popup.cdvOrderStatus.DisplayText = "Open";
                */

                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";


                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvCutWo.Text = popup.g_WorkOrder;
                    cdvCutPo.Text = popup.g_PoNo;

                    ViewCutLotList();

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



        private void cdvQcWo_ButtonPress(object sender, EventArgs e)
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

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;

                popup.g_SubAreaCode = "C_CUT";
                popup.g_SubAreaDesc = "CTM 가공";

                popup.g_OperCode = "OC06020";
                popup.g_OperDesc = "절단품 검사";

                popup.g_WorkOrder = "%-SK%";
                popup.cdvOrderStatus.Text = "O";
                popup.cdvOrderStatus.DisplayText = "Open";
                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";


                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvQcWo.Text = popup.g_WorkOrder;
                    cdvCutPo.Text = popup.g_PoNo;
                    popup = null;

                    ViewQcLotList();
                    SelectedItemChangedByColSet();

                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void cdvQcPo_ButtonPress(object sender, EventArgs e)
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

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;

                popup.g_SubAreaCode = "C_CUT";
                popup.g_SubAreaDesc = "CTM 가공";

                popup.g_OperCode = "OC06020";
                popup.g_OperDesc = "절단품 검사";

                popup.g_WorkOrder = "%-SK%";
                popup.cdvOrderStatus.Text = "O";
                popup.cdvOrderStatus.DisplayText = "Open";

                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";


                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvQcWo.Text = popup.g_WorkOrder;
                    cdvCutPo.Text = popup.g_PoNo;
                    popup = null;

                    ViewQcLotList();
                    SelectedItemChangedByColSet();

                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void spdQcOperLotList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (beforQceRow == e.Range.Row)
            {
                return;
            }

            beforQceRow = e.Range.Row;

            SelectedItemChangedByColSet();
        }

        private void btnQcDataSave_Click(object sender, EventArgs e)
        {
            try
            {

                //공통 탭, 검사탭 모두 저장
                if (Collect_Inspection_Data() == false)
                {
                    return;
                }

                //재조회
                //  ViewQcLotList();
                SelectedItemChangedByColSet();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnJudge_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(503), MessageBoxButtons.YesNo, 1) != System.Windows.Forms.DialogResult.Yes)
                {
                    return;
                }


                //string sLotID;

                //데이터 재저장


                //공통 탭, 검사탭 모두 저장
                if (Collect_Inspection_Data() == false)
                {
                    return;
                }

                //판정
                if (Inspection_Judge() == false)
                {
                    return;
                }

                //재조회
                ViewQcLotList();
                SelectedItemChangedByColSet();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnMerge_Click(object sender, EventArgs e)
        {
            try
            {


                CUS_WIP.frmTranMergeLot popup = new CUS_WIP.frmTranMergeLot();

                if (spdWhLotList_Sheet1.ActiveRowIndex >= 0)
                {
                    popup.txtLotID.Text = spdWhLotList_Sheet1.Cells[spdWhLotList_Sheet1.ActiveRowIndex, (int)WHLOT_INFO.LOT_ID].Text;
                }






                if (popup.ShowDialog() == DialogResult.OK)
                {
                    ViewWHLotList();

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

        private void btnsplite_Click(object sender, EventArgs e)
        {
            try
            {


                CUS_WIP.frmTranSplitLot popup = new CUS_WIP.frmTranSplitLot();

                if (spdWhLotList_Sheet1.ActiveRowIndex >= 0)
                {
                    popup.txtLotID.Text = spdWhLotList_Sheet1.Cells[spdWhLotList_Sheet1.ActiveRowIndex, (int)WHLOT_INFO.LOT_ID].Text;
                }



                if (popup.ShowDialog() == DialogResult.OK)
                {
                    ViewWHLotList();

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

        private void btnRight_Click(object sender, EventArgs e)
        {
            int i_total_Qty = 0;
            int i_lot_Qty = 0;
            int i_create_qty = 0;
            int beforeRowCount = 0;
            int currentRowCount = 0;
            int i_activeRow = 0;
            int i_lot_count = 0;

            try
            {
                /*
                if (CheckCondition("ADD") == false)
                    return;
                    */

                i_activeRow = spdWhLotList.ActiveSheet.ActiveRowIndex;

                beforeRowCount = spdPackingLotList_Sheet1.RowCount;

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (string.Equals(spdWhLotList.ActiveSheet.Cells[i_activeRow, (int)WHLOT_INFO.LOT_ID].Text, spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.ORG_LOT_ID].Text))
                    {
                        i_create_qty += MPCF.ToInt(spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.QTY].Text);
                    }
                }

                i_total_Qty = MPCF.ToInt(this.txtPackingQty.Text);
                i_lot_Qty = MPCF.ToInt(this.txtLotSize.Text);
                i_lot_count = i_total_Qty / MPCF.ToInt(this.txtLotSize.Text);

                if (i_lot_count * MPCF.ToInt(this.txtLotSize.Text) < i_total_Qty)
                {
                    i_lot_count++;
                }

                if (i_total_Qty <= 0)
                {
                    //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblPackingQty.Text + "]");
                    txtPackingQty.Focus();
                    return;
                }

                for (int i = 0; i < i_lot_count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    currentRowCount = spdPackingLotList_Sheet1.RowCount - 1;
                    spdPackingLotList_Sheet1.SetValue(currentRowCount, (int)PACKLOT_INFO.CHK, true);
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.ORG_LOT_ID].Value = spdWhLotList.ActiveSheet.Cells[i_activeRow, (int)WHLOT_INFO.LOT_ID].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.PACK_LOT_ID].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.SEQ].Value = spdPackingLotList_Sheet1.RowCount;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.MAT_ID].Value = spdWhLotList.ActiveSheet.Cells[i_activeRow, (int)WHLOT_INFO.MAT_ID].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.MAT_VER].Value = spdWhLotList.ActiveSheet.Cells[i_activeRow, (int)WHLOT_INFO.MAT_VER].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.MAT_DESC].Value = spdWhLotList.ActiveSheet.Cells[i_activeRow, (int)WHLOT_INFO.MAT_DESC].Text;

                    if (spdPackingLotList_Sheet1.RowCount == i_lot_count + beforeRowCount)
                    {
                        spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.QTY].Value = i_total_Qty.ToString();
                    }
                    else
                    {
                        spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.QTY].Value = i_lot_Qty.ToString();
                        i_total_Qty -= i_lot_Qty;
                    }

                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.UNIT].Value = spdWhLotList.ActiveSheet.Cells[i_activeRow, (int)WHLOT_INFO.UNIT].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.CMF_1].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.PACK_FLAG].Value = "N";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.PACK_ORDER_ID].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.PACK_LINE_NO].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.BOX_ID].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACKLOT_INFO.FINAL_BOX_ID].Value = "";

                }


                spdWhLotList.ActiveSheet.RemoveRows(spdWhLotList.ActiveSheet.ActiveRowIndex, 1);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtCutLotId_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                ViewCutLotList2();
                txtCutLotId.Text = "";
            }
        }

        private void txtQcLotId_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                ViewQcLotList2();
                txtQcLotId.Text = "";
            }
        }

        private void spdCutOperLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {

                switch (e.Column)
                {
                    case (int)LOT_INFO.START_END:


                        SaveCutProcess();

                        ViewCutLotList();


                        break;
                }




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWhLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true || e.ColumnFooter == true || e.Row < 0)
                {
                    txtPackingQty.Text = "";

                    txtLotSize.Text = "";

                    return;
                }
                for (int i = 0; i < spdWhLotList.ActiveSheet.RowCount; i++)
                {
                    spdWhLotList.ActiveSheet.SetValue(i, (int)WHLOT_INFO.CHK, false);
                    spdWhLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                spdWhLotList.ActiveSheet.Cells[e.Row, (int)WHLOT_INFO.CHK].Value = true;
                spdWhLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                txtPackingQty.Text = spdWhLotList.ActiveSheet.Cells[e.Row, (int)WHLOT_INFO.REMAIN_QTY].Text;
                txtLotSize.Text = spdWhLotList.ActiveSheet.Cells[e.Row, (int)WHLOT_INFO.REMAIN_QTY].Text;



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnLeft_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_LOT_ID].Text) != "")
                        {
                            continue;
                        }

                        spdPackingLotList_Sheet1.RemoveRows(i, 1);
                        i--;
                    }
                }

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.SEQ].Value = i + 1;
                }

                MPCF.FitColumnHeader(spdPackingLotList);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPackSave_Click(object sender, EventArgs e)
        {

            CreatePackingLot();

        }


        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                bool b_label_flag = false;
                bool check_flag = false;
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                MPCR.SetInMsg(in_node);
                in_node.AddChar("MESH_DELETE_FLAG", 'N');

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        check_flag = true;

                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_ORDER_ID].Text) == "")
                        {
                            continue;
                        }

                        label_list = in_node.AddNode("PACK_LOT_LIST");
                        label_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_LOT_ID].Text);
                        label_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.ORG_LOT_ID].Text);
                        b_label_flag = true;
                    }
                }

                if (check_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }

                if (b_label_flag == false)
                {
                    //CMN506 ERROR - 출하 라벨은 주문 지시를 가지고 있어야 출력이 가능합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(506));
                    return;
                }



                ViewPrintLabel("mtl900hm3p", in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOrderDetailList_CellClick(object sender, CellClickEventArgs e)
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


                    // 포장 진행 LOT 조회
                    ViewPackingLotList(spdOrderDetailList.ActiveSheet.Cells[e.Row, (int)SHIP_DTL.SHIP_ORDER_ID].Text, spdOrderDetailList.ActiveSheet.Cells[e.Row, (int)SHIP_DTL.SEQ].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnShipSave_Click(object sender, EventArgs e)
        {
            RegistShippingLot();

        }

        private void btnQcView_Click(object sender, EventArgs e)
        {

            try
            {

                CUS_WIP.frmWIPViewActualOfLots popup = new CUS_WIP.frmWIPViewActualOfLots();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_Dept = cdvDept.Text;
                popup.g_DeptDisplay = cdvDept.DisplayText;
                popup.cdvDept.Enabled = false;

                popup.g_Workplace = "C_OSP";
                popup.g_WorkplaceDisplay = "사외 외주";
                popup.cdvWorkPlace.Enabled = false;

                popup.g_Oper = "OC90010";
                popup.g_g_OperDisplay = "외주가공";
                popup.cdvOper.Enabled = false;

                popup.cdvOrder.Text = "%-SK";
                popup.cdvOrder.Enabled = false;

                popup.cdvResource.Enabled = false;
                popup.cdvOrderType.Enabled = false;
                popup.g_PopYn = "Y";




                /*

                popup.dtpFromDate.Text = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";
                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

    */

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

        private void btnOperView_Click(object sender, EventArgs e)
        {
            try
            {





                CUS_QCM.frmViewInspectionDataCut popup = new CUS_QCM.frmViewInspectionDataCut();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.txtWo.Text = "%-SK";
                popup.txtWo.Enabled = false;

                /*

                popup.dtpFromDate.Text = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";
                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

    */

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

        private void btnWhView_Click(object sender, EventArgs e)
        {
            try
            {





                CUS_WIP.frmWIPViewOperLotList popup = new CUS_WIP.frmWIPViewOperLotList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvDept.Enabled = false;



                /*

                popup.dtpFromDate.Text = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";
                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

    */

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

        private void btnPackView_Click(object sender, EventArgs e)
        {
            try
            {





                CUS_SHP.frmViewPackingLot popup = new CUS_SHP.frmViewPackingLot();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvDept.Enabled = false;



                /*

                popup.dtpFromDate.Text = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";
                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

    */

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

        private void btnShipView_Click(object sender, EventArgs e)
        {
            try
            {

                CUS_SHP.frmViewShippingLot popup = new CUS_SHP.frmViewShippingLot();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvDept.Enabled = false;


                /*

                popup.dtpFromDate.Text = DateTime.Now.AddDays(-365).ToShortDateString();

                popup.g_PoYn = "Y";
                popup.g_AutoSearchYn = "Y";
                popup.g_FromDt = DateTime.Now.AddDays(-365).ToShortDateString();

    */

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

        private void btnIngView_Click(object sender, EventArgs e)
        {

            ViewLotIngList();




        }

        private void spdLotIngView_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true || e.ColumnFooter == true || e.Row < 0)
                {
                    return;
                }
                for (int i = 0; i < spdLotIngView.ActiveSheet.RowCount; i++)
                {

                    if (spdLotIngView.ActiveSheet.Cells[i, (int)LOT_ING_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdLotIngView.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }
                    else
                    {
                        spdLotIngView.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }
                }


                if (spdLotIngView.ActiveSheet.Cells[e.Row, (int)LOT_ING_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                {
                    spdLotIngView.ActiveSheet.Cells[e.Row, (int)LOT_ING_INFO.CHK].Value = false;
                    spdLotIngView.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 255, 255);
                }
                else
                {
                    spdLotIngView.ActiveSheet.Cells[e.Row, (int)LOT_ING_INFO.CHK].Value = true;

                    spdLotIngView.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 0, 0);
                }





            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewMerge_Click(object sender, EventArgs e)
        {
            try
            {


                if (rdoCutWh.Checked == false)
                {
                    MPCF.ShowMsgBox("포장대기에서만 병합가능합니다.");
                }



                // int iCount = 0;
                string sMatId = "";

                CUS_WIP.frmTranMergeLot popup = new CUS_WIP.frmTranMergeLot();

                if (spdLotIngView_Sheet1.ActiveRowIndex >= 0)
                {
                    popup.txtLotID.Text = spdLotIngView_Sheet1.Cells[spdLotIngView_Sheet1.ActiveRowIndex, (int)LOT_ING_INFO.LOT_ID].Text;

                    sMatId = spdLotIngView_Sheet1.Cells[spdLotIngView_Sheet1.ActiveRowIndex, (int)LOT_ING_INFO.MAT_ID].Text;

                    popup.dtLotList.Columns.Add("LOT");

                    for (int i = 0; i < spdLotIngView_Sheet1.RowCount; i++)
                    {
                        if (spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.CHK].Value.ToString().ToUpper() == "TRUE" && popup.txtLotID.Text != spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.LOT_ID].Text)
                        {
                            if (sMatId != spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.MAT_ID].Text)
                            {

                                MPCF.ShowMsgBox("동일품목끼리만 병합가능합니다.");

                                popup = null;
                                return;

                            }

                            DataRow row = popup.dtLotList.NewRow();

                            row[0] = spdLotIngView_Sheet1.Cells[i, (int)LOT_ING_INFO.LOT_ID].Text;

                            popup.dtLotList.Rows.Add(row);

                        }


                    }

                }






                if (popup.ShowDialog() == DialogResult.OK)
                {
                    ViewWHLotList();

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

        private void rdoCutOper_CheckedChanged(object sender, EventArgs e)
        {


            if (rdoCutOper.Checked == true)
            {
                rdoCutOper.Checked = true;
                rdoQcOper.Checked = false;
                rdoCutWh.Checked = false;
                rdoStgWh.Checked = false;
            }

        }

        private void rdoQcOper_CheckedChanged(object sender, EventArgs e)
        {

            if (rdoQcOper.Checked == true)
            {
                rdoCutOper.Checked = false;
                rdoQcOper.Checked = true;
                rdoCutWh.Checked = false;
                rdoStgWh.Checked = false;
            }

        }

        private void rdoCutWh_CheckedChanged(object sender, EventArgs e)
        {

            if (rdoCutWh.Checked == true)
            {
                rdoCutOper.Checked = false;
                rdoQcOper.Checked = false;
                rdoCutWh.Checked = true;
                rdoStgWh.Checked = false;
            }
        }

        private void rdoStgWh_CheckedChanged(object sender, EventArgs e)
        {

            if (rdoStgWh.Checked == true)
            {
                rdoCutOper.Checked = false;
                rdoQcOper.Checked = false;
                rdoCutWh.Checked = false;
                rdoStgWh.Checked = true;
            }
        }

        private void btnViewSplite_Click(object sender, EventArgs e)
        {
            try
            {



                if (rdoCutWh.Checked == false)
                {
                    MPCF.ShowMsgBox("포장대기에서만 분할가능합니다.");
                }



                CUS_WIP.frmTranSplitLot popup = new CUS_WIP.frmTranSplitLot();

                if (spdLotIngView_Sheet1.ActiveRowIndex >= 0)
                {
                    popup.txtLotID.Text = spdLotIngView_Sheet1.Cells[spdLotIngView_Sheet1.ActiveRowIndex, (int)LOT_ING_INFO.LOT_ID].Text;
                }



                if (popup.ShowDialog() == DialogResult.OK)
                {
                    ViewWHLotList();

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

        private void cdvCutPo_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                ViewCutLotList();
            }
        }

        private void cdvCutWo_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                ViewCutLotList();
            }
        }

        private void cdvQcPo_KeyPress(object sender, KeyPressEventArgs e)
        {
            ViewQcLotList();
            SelectedItemChangedByColSet();
        }

        private void cdvQcWo_KeyPress(object sender, KeyPressEventArgs e)
        {
            ViewQcLotList();
            SelectedItemChangedByColSet();
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {

            try
            {

                string sFileName = string.Empty;

                sFileName = "LotDataList";
                EXTFUC.SaveExcel(spdLotIngView, sFileName);


            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }


        #endregion

        #region " Function Definition "
        private bool CreatePackingLot()
        {
            TRSNode in_node = new TRSNode("create_packing_Lot_In");
            TRSNode out_node = new TRSNode("create_packing_Lot_Out");
            TRSNode label_in_node = new TRSNode("print_label_In");
            TRSNode lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("PACK_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                in_node.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text));
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_ORDER_ID].Text) != "")
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.PACK_LOT_ID].Text);
                        lot_list.AddDouble("QTY", MPCF.ToDbl(spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.QTY].Text));
                        lot_list.AddString("COATING_PERCENT", spdPackingLotList_Sheet1.Cells[i, (int)PACKLOT_INFO.CMF_1].Text);

                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Create_Pack_Lot", in_node, ref out_node) == false)
                    return false;


                ConfirmPackingLot(out_node);



                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



        private bool ConfirmPackingLot(TRSNode PackNode)
        {
            TRSNode in_node = new TRSNode("confirm_packing_Lot_In");
            TRSNode out_node = new TRSNode("confirm_packing_Lot_Out");
            TRSNode label_in_node = new TRSNode("print_label_In");
            TRSNode lot_list;
            TRSNode label_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("PACK_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                in_node.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text));



                in_node.AddChar("OSP_SHIP_FlAG", 'Y');

                //TO_창고지정(외주는  CB-STG-S 라는 스카이 전용 창고 만듬 ERP코드는 B-STG)
                in_node.AddString("TO_OPER_CODE", "CB-STG-S");


                for (int i = 0; i < PackNode.GetList(0).Count; i++)
                {
                    lot_list = in_node.AddNode("PACK_LOT_LIST");
                    lot_list.AddString("ORG_LOT_ID", PackNode.GetList(0)[i].GetString("ORG_LOT_ID"));
                    lot_list.AddString("PACK_LOT_ID", PackNode.GetList(0)[i].GetString("PACK_LOT_ID"));

                }


                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Confirm_Pack_Order", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);


                MPCR.SetInMsg(label_in_node);
                label_in_node.AddChar("MESH_DELETE_FLAG", 'N');


                for (int i = 0; i < PackNode.GetList(0).Count; i++)
                {
                    label_list = label_in_node.AddNode("PACK_LOT_LIST");
                    label_list.AddString("PACK_LOT_ID", PackNode.GetList(0)[i].GetString("PACK_LOT_ID"));
                    label_list.AddString("ORG_LOT_ID", PackNode.GetList(0)[i].GetString("ORG_LOT_ID"));
                }



                ViewPrintLabel("mtl900hm3p", label_in_node);


                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        public bool ViewPrintLabel(string sFileName, TRSNode in_node)
        {
            try
            {
                CSCF.ViewLabelList(sFileName, in_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


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
                in_node.AddString("SHIP_ORDER_ID", spdOrderDetailList.ActiveSheet.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, (int)SHIP_DTL.SHIP_ORDER_ID].Text);

                for (int i = 0; i < spdPackShipList_Sheet1.RowCount; i++)
                {
                    if (spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (string.Equals(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        if (MPCF.Trim(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.SHIP_ORDER_ID].Text) != "")
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.PACK_LOT_ID].Text);
                        send_flag = true;

                        //BOX, FINAL BOX 수량 Validation
                        if (MPCF.Trim(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.BOX_ID].Text) != "")
                        {
                            if (dict_box.ContainsKey(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.BOX_ID].Text))
                            {
                                dict_box[spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.BOX_ID].Text] += 1;
                            }
                            else
                            {
                                dict_box.Add(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.BOX_ID].Text, 1);
                            }
                        }

                        if (MPCF.Trim(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.FINAL_BOX_ID].Text) != "")
                        {
                            if (dict_final_box.ContainsKey(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.FINAL_BOX_ID].Text))
                            {
                                dict_final_box[spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.FINAL_BOX_ID].Text] += 1;
                            }
                            else
                            {
                                dict_final_box.Add(spdPackShipList_Sheet1.Cells[i, (int)SHIP_PACK_LOT.FINAL_BOX_ID].Text, 1);
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

                //  MPCR.ShowSuccessMsg(out_node);

                //나중에 ProcStep 하나더따서 합칠예정...일단 급해서..등록확정따로...
                ShippingLot();


                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        private bool ShippingLot()
        {
            TRSNode in_node = new TRSNode("save_shipping_Lot_In");
            TRSNode out_node = new TRSNode("save_shipping_Lot_Out");
            TRSNode lot_list;


            try
            {
                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '4';


                lot_list = in_node.AddNode("SHIP_ORDER_LIST");
                lot_list.AddString("SHIP_ORDER_ID", spdOrderDetailList.ActiveSheet.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, (int)SHIP_DTL.SHIP_ORDER_ID].Text);


                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Ship_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);


                ViewOrderList();

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        private void SelectedItemChangedByColSet()
        {

            if (spdQcOperLotList_Sheet1.ActiveRowIndex < 0)
            {
                return;
            }

            string sLotID;
            string sOper;
            string sMatID;
            string sColSetID;
            string sColSetVersion;
            string sInspID;
            int iMatVer;


            try
            {
      



                sOper = spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.OPER].Text;
                sMatID = spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.QC_MAT_ID].Text;
                iMatVer = 1;
                sLotID = spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.QC_LOT_ID].Text;
                sColSetID = spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.COL_SET_ID].Text;
                if (MPCF.Trim(spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.COL_SET_VERSION].Text) == "")
                {
                    sColSetVersion = "1";
                }
                else
                {
                    sColSetVersion = spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.COL_SET_VERSION].Text;
                }

                sInspID = spdQcOperLotList_Sheet1.Cells[spdQcOperLotList_Sheet1.ActiveRowIndex, (int)QCLOT_INFO.INSP_ID].Text;





                //Clear
                MPCF.ClearList(spdDataCollection, true);

                if (MPCF.Trim(sColSetID) != "")
                {
                    FindColSetVersion(sColSetID, sLotID, sMatID, iMatVer, sOper, sColSetVersion, sInspID);
                }
                else
                {
                    MPCF.FieldClear(panDataCollection);
                    MPCF.ClearList(spdDataCollection);
                }

                // txtColSetVer.Text = "";  Col Set ID 버전
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void FindColSetVersion(string sColSetID, string sLotID, string sMatID, int iMatVer, string sOper, string sColSetVersion, string sInspID)
        {
            try
            {

                TRSNode in_node = new TRSNode("FIND_COL_SET_VERSION_IN");
                TRSNode out_node = new TRSNode("FIND_COL_SET_VERSION_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                // in_node.AddString("LOT_ID", sLotID);
                in_node.AddString("MAT_ID", sMatID);
                in_node.AddInt("MAT_VER", iMatVer);
                in_node.AddString("OPER", sOper);
                in_node.AddString("EVENT_ID", "");
                in_node.AddString("COL_SET_ID", sColSetID);
                in_node.AddChar("LOT_OR_RES_FLAG", 'L');

                if (MPCR.CallService("EDC", "EDC_Find_Col_Set_Version", in_node, ref out_node, false) == false)
                {
                    return;
                }

                //   txtColSetVer.Text = out_node.GetInt("COL_SET_VERSION").ToString();

                cls_derived_char_list = new clsDerivedCharList();
                cls_derived_char_list.GetDerivedInfo(sColSetID, Convert.ToInt32(sColSetVersion), sLotID, "", "", "");

                if (ViewCharacterList(spdDataCollection, '5', sColSetID, Convert.ToInt32(sColSetVersion), 'Y', cls_derived_char_list, sLotID, sMatID, iMatVer, sOper) == false)
                {
                    return;
                }


                if (ViewInspData2(sInspID, sColSetID, sLotID) == false)
                {
                    CSCF.ClearSpread(spdDataCollection, 0, (int)COLLECTION_DATA.VALUE_START_COL, "");
                }


            }
            catch
            {

            }
        }

        public bool ViewCharacterList(Control control, char ProcStep, string ColSetID, int ColSetVersion, char cIncludeUnitID, clsDerivedCharList cls_derived_char_list, string LotID, string sMatID, int iMatVer, string sOper)
        {

            int i;
            int j;
            int k;
            int m;
            int i_index;
            int iLastRow = 0;
            int iUnitCnt = 0;
            int iValueCnt = 0;
            int iUnitSeq = 0;
            int iMaxColumnCnt = 0;
            int iColCnt = 0;
            string sDefaultValue;
            string sUnitTbl;
            string sValueTbl;
            char cDefUnitFlag;
            char cDefUnitOvrFlag;
            FarPoint.Win.Spread.CellType.ComboBoxCellType UnitCellType = null;
            FarPoint.Win.Spread.CellType.ComboBoxCellType ValueCellType = null;


            TRSNode in_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_OUT");
            List<TRSNode> unit_list;

            try
            {
                spdDataCollection.SuspendLayout();
                spdDataCollection.ActiveSheet.RowCount = 0;
                spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;
                spdDataCollection.ResumeLayout();



                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;
                in_node.AddChar("INCLUDE_UNIT_ID", cIncludeUnitID);
                in_node.AddString("COL_SET_ID", ColSetID);
                in_node.AddInt("COL_SET_VERSION", ColSetVersion);

                in_node.AddString("MAT_ID", sMatID);
                in_node.AddInt("MAT_VER", iMatVer);
                in_node.AddString("OPER", sOper);
                // in_node.AddString("LOT_ID", LotID);

                do
                {
                    if (MPCR.CallService("EDC", "EDC_View_Attach_Character_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    //컬럼의 max count 를 구해온다.
                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        iColCnt = 0;
                        iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        if (iValueCnt > 0)
                        {
                            iColCnt = DEFAULT_COL_COUNT + iValueCnt;
                        }
                        else
                        {
                            iColCnt = DEFAULT_COL_COUNT;
                        }

                        if (iColCnt > iMaxColumnCnt)
                        {
                            iMaxColumnCnt = iColCnt;
                        }

                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        // Initialize
                        FarPoint.Win.Spread.SheetView with_1 = spdDataCollection.ActiveSheet;

                        iLastRow = with_1.RowCount - 1;
                        iUnitCnt = out_node.GetList(0)[i].GetInt("UNIT_COUNT");
                        iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        UnitCellType = null;
                        ValueCellType = null;
                        with_1.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50;

                        with_1.RowCount += iUnitCnt;
                        if (with_1.ColumnCount < DEFAULT_COL_COUNT + iValueCnt)
                        {
                            with_1.ColumnCount = DEFAULT_COL_COUNT + iValueCnt;
                        }

                        sDefaultValue = out_node.GetList(0)[i].GetString("DEF_VALUE");
                        sUnitTbl = out_node.GetList(0)[i].GetString("UNIT_TBL");
                        sValueTbl = out_node.GetList(0)[i].GetString("VALUE_TBL");
                        cDefUnitFlag = out_node.GetList(0)[i].GetChar("DEF_UNIT_FLAG");
                        cDefUnitOvrFlag = out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG");

                        iUnitSeq = 0;
                        for (j = iLastRow + 1; j < with_1.RowCount; j++)
                        {


                            iUnitSeq++;
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_COL, out_node.GetList(0)[i].GetString("CHAR_ID"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_DESC_COL, out_node.GetList(0)[i].GetString("CHAR_DESC"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_SEQ, out_node.GetList(0)[i].GetInt("SEQ_NUM"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT, out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.TARGET_VALUE, out_node.GetList(0)[i].GetString("TARGET_VALUE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT, out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"));


                            with_1.SetValue(j, (int)COLLECTION_DATA.SPEC_COL, MPCF.GetSpecInfo(out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("TARGET_VALUE")));
                            with_1.SetValue(j, (int)COLLECTION_DATA.OPT_INPUT_COL, out_node.GetList(0)[i].GetChar("OPT_INPUT_FLAG"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_TYPE_COL, out_node.GetList(0)[i].GetChar("VALUE_TYPE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_COUNT_COL, out_node.GetList(0)[i].GetInt("VALUE_COUNT"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.DEF_UNIT_OVR_FLAG_COL, out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.DEF_VALUE_COL, out_node.GetList(0)[i].GetString("DEF_VALUE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UNIT_TBL_COL, out_node.GetList(0)[i].GetString("UNIT_TBL"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_TBL_COL, out_node.GetList(0)[i].GetString("VALUE_TBL"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UNIT_SEQ_COL, iUnitSeq);
                        }

                        i_index = 0;

                        //VALUE_TYPE에 따라 컬럼의 셀 타입을 지정해준다.
                        for (j = (int)COLLECTION_DATA.VALUE_START_COL; j < (int)COLLECTION_DATA.VALUE_START_COL + iValueCnt; j++)
                        {
                            for (k = iLastRow + 1; k < with_1.RowCount; k++)
                            {
                                if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                                {
                                    MPCR.SetNumberCell(with_1.Cells[k, j]);
                                }
                                else
                                {
                                    MPCR.SetAsciiCell(with_1.Cells[k, j]);
                                }

                                if (cls_derived_char_list != null)
                                {
                                    if (out_node.GetList(0)[i].GetChar("DERIVED_PARAM_FLAG") == 'Y')
                                    {
                                        with_1.Cells[k, j].Locked = true;
                                        with_1.Cells[k, j].BackColor = System.Drawing.Color.Cyan;
                                        with_1.Rows[k].Tag = "AUTO";

                                        cls_derived_char_list.SetCharLocation(out_node.GetList(0)[i].GetString("CHAR_ID"), with_1, i_index, k, j);
                                    }
                                }
                            }

                            i_index += 1;
                        }

                        // ColSet의 케릭터에 셋팅한 유닛ID 정보에 맞게 셀의 상태를 바꿔준다.
                        unit_list = out_node.GetList(0)[i].GetList("UNIT_LIST");
                        //Unit ID Cell Lock


                        if (unit_list.Count < 1)
                        {
                            if (cDefUnitFlag == 'C')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = true;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.WhiteSmoke;
                                    with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), out_node.GetList(0)[i].GetString("UNIT"));
                                    if (out_node.GetList(0)[i].GetString("UNIT") == "")
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "*");
                                    }
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "CHARACTER");
                                }

                            }
                            else if (cDefUnitFlag == 'E')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.White;
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                }
                            }
                            else
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.White;
                                }
                            }
                        }
                        else
                        {
                            if (cDefUnitFlag == 'Y')
                            {
                                for (m = 0; m < unit_list.Count; m++)
                                {
                                    if (m > iUnitCnt - 1)
                                    {
                                        break;
                                    }

                                    // null_flag check
                                    if (unit_list[m].GetChar("NULL_FLAG") == 'Y')
                                    {
                                        with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                    }
                                    else
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), unit_list[m].GetString("DEF_UNIT_ID"));
                                    }

                                    if (out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG") == 'Y')
                                    {
                                    }
                                    else
                                    {
                                        with_1.Cells[iLastRow + 1 + m, (int)COLLECTION_DATA.UNIT_COL].Locked = true;
                                        with_1.Cells[iLastRow + 1 + m, (int)COLLECTION_DATA.UNIT_COL].BackColor = System.Drawing.Color.WhiteSmoke;
                                    }
                                }
                            }

                            if ((cDefUnitFlag == 'Y' && cDefUnitOvrFlag == 'Y' && sUnitTbl != "") ||
                                (cDefUnitFlag == ' ' && sUnitTbl != ""))
                            {
                                for (j = iLastRow + 1; j <= with_1.RowCount - 1; j++)
                                {
                                    if (UnitCellType == null)
                                    {
                                        if (BASLIST.ViewGCMDataList(control, '1', sUnitTbl, -1, null, "", false, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), j, null) == false)
                                        {
                                            return false;
                                        }
                                        else
                                        {
                                            UnitCellType = (FarPoint.Win.Spread.CellType.ComboBoxCellType)(with_1.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType);
                                            with_1.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50;
                                        }
                                    }
                                    else
                                    {
                                        with_1.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType = UnitCellType;
                                    }
                                }
                            }

                        }

                        //기본값 세팅 - > ColSet의 케릭터에 셋팅한 기본값을 넣어준다.                        
                        for (j = (int)COLLECTION_DATA.VALUE_START_COL; j <= iValueCnt + (int)COLLECTION_DATA.VALUE_START_COL - 1; j++)
                        {
                            for (k = iLastRow + 1; k <= with_1.RowCount - 1; k++)
                            {
                                if (sDefaultValue != "")
                                {
                                    with_1.SetValue(k, j, sDefaultValue);
                                }
                                if (sValueTbl != "")
                                {
                                    if (ValueCellType == null)
                                    {
                                        if (BASLIST.ViewGCMDataList(control, '1', sValueTbl, -1, null, "", false, j, k, null) == false)
                                        {
                                            return false;
                                        }
                                        else
                                        {
                                            ValueCellType = (FarPoint.Win.Spread.CellType.ComboBoxCellType)(with_1.Cells[k, j].CellType);
                                        }
                                    }
                                    else
                                    {
                                        with_1.Cells[k, j].CellType = ValueCellType;
                                    }
                                }
                            }
                        }

                        //value count 가 다른 char id의 max value count 보다 작을경우 해당 컬럼은 lock을 하고, 색을 바꿔준다.
                        with_1.ColumnCount = iMaxColumnCnt;
                        for (j = iValueCnt + (int)COLLECTION_DATA.VALUE_START_COL; j < with_1.ColumnCount; j++)
                        {
                            for (k = iLastRow + 1; k < with_1.RowCount; k++)
                            {
                                with_1.Cells[k, j].Locked = true;
                                //with_1.Cells[k, j].BackColor = System.Drawing.Color.WhiteSmoke;
                                with_1.Cells[k, j].LockBackColor = System.Drawing.Color.WhiteSmoke;
                            }
                        }
                    }

                    in_node.SetString("NEXT_CHAR_ID", out_node.GetString("NEXT_CHAR_ID"));
                } while (in_node.GetString("NEXT_CHAR_ID") != "");

                // 추가 컬럼헤더 span 및 seq 나타내기    
                FarPoint.Win.Spread.SheetView with_2 = spdDataCollection.ActiveSheet;
                int iColumnSeq = 0;

                if (with_2.ColumnCount > DEFAULT_COL_COUNT)
                {
                    with_2.ColumnHeader.Cells.Get(0, (int)COLLECTION_DATA.VALUE_START_COL).ColumnSpan = with_2.ColumnCount - DEFAULT_COL_COUNT;
                    for (i = (int)COLLECTION_DATA.VALUE_START_COL; i < with_2.ColumnCount; i++)
                    {
                        iColumnSeq++;
                        with_2.ColumnHeader.Cells.Get(1, i).Value = iColumnSeq;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        private bool ViewInspData2(string sInspID, string sColSetID, string sLotID)
        {


            int iValueCnt = 0;
            int iRow = 0;
            string s_value_name;

            try
            {

                TRSNode in_node = new TRSNode("view_lot_data_In");
                TRSNode out_node = new TRSNode("view_lot_data_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("INSP_ID", sInspID);
                in_node.AddString("COL_SET_ID", sColSetID);
                in_node.AddString("LOT_ID", sLotID);






                if (MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Inspection_Data", in_node, ref out_node) == false)
                {
                    return false;
                }




                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.CHAR_COL].Text == out_node.GetList(0)[i].GetString("CHAR_ID")   //dt.Rows[i]["CHAR_ID"].ToString()
                            && spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.UNIT_SEQ_COL].Text == out_node.GetList(0)[i].GetInt("UNIT_SEQ").ToString())
                        {
                            iRow = j;
                            break;
                        }

                    }

                    //spdDataCollection.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA.UNIT_COL, out_node.GetList(0)[i].GetString("UNIT_ID"));

                    // iUnitCnt = MPCF.ToInt(dt.Rows[0]["UNIT_COUNT"].ToString());
                    iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");

                    if (iValueCnt > 25)
                    {
                        iValueCnt = 25;
                    }

                    for (int k = 1; k <= iValueCnt; k++)
                    {
                        s_value_name = "VALUE_" + k.ToString();
                        if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                        {
                            if (out_node.GetList(0)[i].GetString(s_value_name) != "")
                            {
                                // spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = MPCF.ToDbl(out_node.GetList(0)[i].GetString(s_value_name));
                                spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = out_node.GetList(0)[i].GetString(s_value_name);
                            }
                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = out_node.GetList(0)[i].GetString(s_value_name);
                        }

                    }
                }

                //Spec Out 확인
                ApplyColorBySpecOut();

                return true;
                //return bResult;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ApplyColorBySpecOut()
        {
            if (spdDataCollection.ActiveSheet.RowCount < 1)
            {
                return;
            }

            try
            {
                for (int iRow = 0; iRow < spdDataCollection.ActiveSheet.RowCount; iRow++)
                {
                    for (int iCol = (int)COLLECTION_DATA.VALUE_START_COL; iCol < spdDataCollection.ActiveSheet.ColumnCount; iCol++)
                    {
                        bool bSpecOut = false;

                        //검사항목이 숫자타입 일 때만
                        if (spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_TYPE_COL].Value.ToString() == "N")
                        {
                            //입력값(검사 결과값)이 숫자일 때
                            if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) == true)
                            {
                                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value) == true)
                                {
                                    if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value))
                                    {
                                        bSpecOut = true;
                                    }
                                }

                                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value) == true)
                                {
                                    if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value))
                                    {
                                        bSpecOut = true;
                                    }
                                }

                                if (bSpecOut)
                                {
                                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Red;
                                }
                                else
                                {
                                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                                }
                            }
                            else
                            {
                                spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                            }

                        }
                    }
                }

            }


            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }






        #endregion


    }

}
