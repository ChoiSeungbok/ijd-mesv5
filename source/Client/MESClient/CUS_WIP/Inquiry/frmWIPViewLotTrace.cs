using CUS_COM;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_WIP
{
    public partial class frmWIPViewLotTrace : CUS_COM.frmViewForm01
    {
        public frmWIPViewLotTrace()
        {
            InitializeComponent();
            InitControl();
        }


        #region " Constant Definition "
        private enum LOT_TREE
        {
            LOT_ID,
            TO_LOT_ID,
            MAT_ID,
            MAT_DESC,
            OPER,
            OPER_DESC,
            LEVEL
        }

        private enum LOT
        {
            LOT_ID,
            HIST_SEQ,
            TRAN_CODE,
            TRAN_TIME,
            OPER,
            OPER_DESC,
            START_TIME,
            END_TIME,
            RWK_FLAG,
            RES_ID,
            RES_DESC,
            ORDER_ID,
            MAT_ID,
            MAT_DESC,
            UNIT,
            QTY,
            DEPT,
            WORKPLACE,
            INSP_ID,
            JUDGE
        }

        private enum MAT_USAGE
        {
            INV_LOT_ID,
            OPER,
            INPUT_TIME,
            MAT_ID,
            MAT_DESC,
            INPUT_QTY,
            STORED_QTY,
            UNIT,
            PO_NO,
            VENDOR_DESC,
            IN_STORE_DATE
        }

        private enum EQP_PRESS
        {
            PROFILE,
            STEP,
            COLLECT_SEC,
            PRESSURE_S,
            PRESSURE_C,
            POWER_S,
            POWER_C,
            CURRENT_S,
            CURRENT_C,
            VOLTAGE_C,
            RESITANCE_C,
            INCH_1,
            INCH_2,
            PROCESS_TIME
        }

        private enum EQP_CUP
        {
            RECIPE_ID,
            JUDGE,
            INPUT_COUNT,
            CUP_TYPE,
            CUP_WEIGHT_STD,
            CUP_WEIGHT_VALUE,
            POWDER_INJECTION_POSITION,
            ROBOT_MEAS_STD,
            ROBOT_MEAS_VALUE,
            PRECISION_WEIGH_STD,
            PRECISION_WEIGH_VALUE,
            PRESS_TIME,
            NUM_OF_PRESS,
            KNIFE_FLAT_USAGE,
            CARBIDE_TYPE,
            CARBIDE_SAM_PASS_CNT,
            CARBIDE_SAM_PASS_RESULT,
            CARBIDE_WEIGHT_STD,
            CARBIDE_WEIGHT_VALUE,
            CARBIDE_HIEGHT_STD,
            CARBIDE_HIEGHT_VALUE_1,
            CARBIDE_HIEGHT_VALUE_2,
            CARBIDE_HIEGHT_VALUE_3,
            CARBIDE_HIEGHT_VALUE_4,
            CARBIDE_HIEGHT_VALUE_5,
            CARBIND_OUTER_DIA_STD,
            CARBIND_OUTER_DIA_VALUE,
            COMPLETE_FLATNESS_STD,
            COMPLETE_FLATNESS_VALUE,
            COMPLETE_WEIGHT_STD,
            COMPLETE_WEIGHT_VALUE,
            CARBIDE_INPUT_COUNT,
            IMPACT_OPERATION_INPUT_QTY,
            NG_CNT
        }

        private enum EQP_LASER
        {
            GRADE,
            LASER_MARKING,
            INK_PRINT,
            INPUT_NO,
            WO
        }

        private enum EQP_ROUND
        {
            RECIPE_ID,
            START_TIME,
            END_TIME,
            JUDGE,
            NUM_OF_DEFECT_STD,
            OUT_DIA_MIN_STD,
            OVERALL_THICK_TARGET_STD,
            OVERALL_THICK_MIN_STD,
            OVERALL_THICK_MAX_STD,
            FLAT_MIN,
            FLAT_MAX,
            SIZE_UM,
            SIZE_UM2,
            CLASSIFICATION,
            OUTER_DIA_1,
            OUTER_DIA_2,
            OUTER_DIA_MIN,
            OVERALL_THICK_1,
            OVERALL_THICK_2,
            OVERALL_THICK_3,
            OVERALL_THICK_4,
            OVERALL_THICK_5,
            OVERALL_THICK_6,
            OVERALL_THICK_7,
            OVERALL_THICK_8,
            OVERALL_THICK_9,
            OVERALL_THICK_MIN,
            OVERALL_THICK_MAX,
            FLATNESS_1,
            FLATNESS_2,
            FLATNESS_3,
            FLATNESS_4,
            FLATNESS_5,
            FLATNESS_6,
            FLATNESS_7,
            FLATNESS_8,
            FLATNESS_9,
            FLATNESS_MAX,
            DEFECT_IMAGE_1,
            DEFECT_IMAGE_2
        }

        private enum EQP_BALLMILL
        {
            DEGREE,
            ITEM,
            VALUE,
            COLLECT_TIME
        }

        private enum EQP_IMPACT
        {
            RECIPE_ID,
            START_TIME,
            END_TIME,
            FLATNESS_1,
            FLATNESS_2,
            FLATNESS_3,
            FLATNESS_4,
            FLATNESS_5,
            WEIGHT,
            AIR_POCKET,
            IMPACT_NO,
            IMPACT_TIME,
            JUDGE
        }

        private enum EQP_DRY
        {
            WORK_TIME,
            OPER_PRESS,
            PRESS_HOLD_TIME_1,
            PRESS_HOLD_TIME_2,
            PRESS_FLAG,
            DISCHARGE_FLAG
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

        private enum WORKER_INFO
        {
            WORKER_ID,              // 1 : 사번
            WORKER_DESC             // 2 : 이름
        }



        private enum SHIPPING_LOT
        {
            CHK,                     // 1 : CHK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID       
            INSPECTION_LOT_ID,       // 4 : 검사 LOT ID             
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            QTY,                     // 8 : 수량
            UNIT,                    // 9 : 단위
            CONV_UNIT_QTY,           // 10 : 제품 단위 수량           
            CONV_STOCK_QTY,          // 11 : 환산 재고 수량           
            CONV_UNIT,               // 12 : 환산 단위
            AREA_DESC,               // 13 : 사업부
            CUSTOMER_ID,             // 14 : 고객사 
            CUSTOMER_NAME,           // 15 : 고객사명
            DELIVERY_ID,             // 16 : 고객사 
            DELIVERY_NAME,           // 17 : 고객사명
            PACK_FLAG,               // 18 : 포장 여부
            PACK_DATE,               // 19 : 포장 일자
            PACK_ORDER_ID,           // 20 : 포장 지시 번호
            PACK_LINE_NO,            // 21 : 포장 지시 라인 번호
            PACK_ORD_DATE,           // 22 : 포장 지시 일자
            ERP_PACK_ORDER_ID,       // 23 : ERP 포장 지시 번호
            SHIP_FLAG,               // 24 : 출하 상태
            SHIP_DATE,               // 25 : 출하 일자
            SHIP_ORDER_ID,           // 26 : 출하 지시 번호
            SHIP_ORDER_SEQ,          // 27 : 출하 지시 순번
            BOX_ID_1,                // 28 : 중 박스 ID
            BOX_ID_2,                // 29 : 대 박스 ID
            PACKING_INSTRUCTIONS     // 30 : 용기
        }

        #endregion

        #region " Variable Definition"

        private const int DEFAULT_COL_COUNT = 17;
        private clsDerivedCharList cls_derived_char_list;

        private const int MAX_DATA_COUNT = 5000;

        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        /// <summary>
        /// Lot별 실적 조회
        /// </summary>
        /// <returns></returns>
        private bool ViewLotList()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
            DataTable dt = null;
            string sSql = "";
            int i = 0;
            string s_view_id = "";

            try
            {
                MPCF.ClearList(spdLotTree);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = txtLotID.Text;

                s_view_id = "CWIP3010-001";

                if (TPDR.GetDataOne("", ref dt, s_view_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotTree_Sheet1.RowCount++;
                    spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.LOT_ID].Value = dt.Rows[i]["TREE_KEY"];
                    spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.LOT_ID].Tag = dt.Rows[i]["LOT_ID"];
                    //spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.TO_LOT_ID].Value = dt.Rows[i]["TO_LOT_ID"];
                    spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotTree_Sheet1.Cells[i, (int)LOT_TREE.LEVEL].Value = MPCF.ToInt(dt.Rows[i]["LVL"]);
                }

                MPCF.FitColumnHeader(spdLotTree);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool ViewLotHistory(string lotId)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
            DataTable dt = null;
            string sSql = "";
            int i = 0;
            string s_view_id = "";

            try
            {
                MPCF.ClearList(spdLotList);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = lotId;

                s_view_id = "CWIP3010-002";

                if (TPDR.GetDataOne("", ref dt, s_view_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.HIST_SEQ].Value = dt.Rows[i]["HIST_SEQ"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.TRAN_CODE].Value = dt.Rows[i]["TRAN_CODE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.TRAN_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["TRAN_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.RWK_FLAG].Value = dt.Rows[i]["RWK_FLAG"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Tag = dt.Rows[i]["RES_GRP_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.DEPT].Value = dt.Rows[i]["AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.DEPT].Tag = dt.Rows[i]["AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.WORKPLACE].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.WORKPLACE].Tag = dt.Rows[i]["SUB_AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.JUDGE].Value = dt.Rows[i]["JUDGE"];
                }

                MPCF.FitColumnHeader(spdLotList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 자재 사용 실적 조회
        /// </summary>
        /// <param name="as_lot_id"></param>
        /// <param name="as_res_grp"></param>
        /// <returns></returns>
        private bool View_Material_Usage(string as_lot_id, string sOper)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdMaterialList);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = as_lot_id;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CWIP3010-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMaterialList_Sheet1.RowCount++;
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.INPUT_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["TRAN_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.INPUT_QTY].Value = dt.Rows[i]["TRAN_QTY"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.STORED_QTY].Value = dt.Rows[i]["RECV_QTY"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.UNIT].Value = dt.Rows[i]["TRAN_UNIT"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.IN_STORE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                }

                MPCF.FitColumnHeader(spdMaterialList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }






        private void ViewShipingList(string as_lot_id)
        {
            TRSNode in_node = new TRSNode("VIEW_SHIPPING_LOT_IN ");
            TRSNode out_node = new TRSNode("VIEW_SHIPPING_LOT_OUT");


            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = as_lot_id;



                if (TPDR.GetDataOne("", ref dt, "CWIP3010-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdShippingLotList);
                    return;
                }

                MPCF.ClearList(spdShippingLotList);



                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdShippingLotList_Sheet1.RowCount++;


                    spdShippingLotList_Sheet1.SetValue(i, (int)SHIPPING_LOT.CHK, false);
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.INSPECTION_LOT_ID].Value = dt.Rows[i]["INSPECTION_LOT_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CONV_UNIT_QTY].Value = dt.Rows[i]["CONV_UNIT_QTY"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CONV_STOCK_QTY].Value = dt.Rows[i]["CONV_QTY"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CONV_UNIT].Value = dt.Rows[i]["CONV_UNIT"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_DATE].Value = dt.Rows[i]["PACK_DATE"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_ORD_DATE].Value = dt.Rows[i]["PACK_ORD_DATE"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["ERP_PACK_ORDER_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_DATE].Value = dt.Rows[i]["SHIP_DATE"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.BOX_ID_1].Value = dt.Rows[i]["BOX_ID_1"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.BOX_ID_2].Value = dt.Rows[i]["BOX_ID_2"];
                    spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACKING_INSTRUCTIONS].Value = dt.Rows[i]["PACKING_INSTRUCTIONS"];
                }

                //MPCF.FitColumnHeader(spdShippingLotList);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        /// <summary>
        /// 작업자 정보 조회
        /// </summary>
        /// <param name="lot_id"></param>
        /// <param name="histSeq"></param>
        /// <returns></returns>
        private bool ViewWorkerList(string lot_id, int histSeq)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = lot_id;

                dvcArgu[2].sCondition_ID = "HIST_SEQ";
                dvcArgu[2].sCondition_Value = histSeq;

                if (TPDR.GetDataOne("", ref dt, "CWIP3010-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWorkerList);
                    return false;
                }

                MPCF.ClearList(spdWorkerList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                }
                MPCF.FitColumnHeader(spdWorkerList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// Press 설비 데이터 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Press_EQP(string as_lot_id, string as_res_id)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdEquip);
                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-011", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip.ActiveSheet.RowCount++;
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.PROFILE].Value = dt.Rows[i]["PROFILE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.STEP].Value = dt.Rows[i]["STEP"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.COLLECT_SEC].Value = dt.Rows[i]["PERIOD_SEC"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.PRESSURE_S].Value = dt.Rows[i]["PRESSURE_S"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.PRESSURE_C].Value = dt.Rows[i]["PRESSURE_C"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.POWER_S].Value = dt.Rows[i]["POWER_S"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.POWER_C].Value = dt.Rows[i]["POWER_C"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.CURRENT_S].Value = dt.Rows[i]["CURRENT_S"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.CURRENT_C].Value = dt.Rows[i]["CURRENT_C"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.VOLTAGE_C].Value = dt.Rows[i]["VOLTAGE_C"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.RESITANCE_C].Value = dt.Rows[i]["RESITANCE_C"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.INCH_1].Value = dt.Rows[i]["INCH_1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.INCH_2].Value = dt.Rows[i]["INCH_2"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_PRESS.PROCESS_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["PROCESS_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                }

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool View_Cup_EQP(string as_lot_id, string as_res_id)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdEquip);
                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-012", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip.ActiveSheet.RowCount++;

                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.RECIPE_ID].Value = dt.Rows[i]["RECIPE_ID"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.JUDGE].Value = dt.Rows[i]["JUDGMENT"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.INPUT_COUNT].Value = dt.Rows[i]["CUP_INPUT_COUNTER"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CUP_TYPE].Value = dt.Rows[i]["CUP_TYPE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CUP_WEIGHT_STD].Value = dt.Rows[i]["CUP_WEIGHT_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CUP_WEIGHT_VALUE].Value = dt.Rows[i]["CUP_WEIGHT_VALUE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.POWDER_INJECTION_POSITION].Value = dt.Rows[i]["POWDER_INJECTION_LOCATION"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.ROBOT_MEAS_STD].Value = dt.Rows[i]["ROBOT_MEASURABLE_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.ROBOT_MEAS_VALUE].Value = dt.Rows[i]["ROBOT_MEASURABLE_VALUE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.PRECISION_WEIGH_STD].Value = dt.Rows[i]["PRECISION_WEIGH_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.PRECISION_WEIGH_VALUE].Value = dt.Rows[i]["PRECISION_WEIGH_VALUE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.PRESS_TIME].Value = dt.Rows[i]["PRESS_TIME"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.NUM_OF_PRESS].Value = dt.Rows[i]["NUMBER_OF_PRESSES"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.KNIFE_FLAT_USAGE].Value = dt.Rows[i]["KNIFE_FLATTENING_USE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_TYPE].Value = dt.Rows[i]["CARBIDE_TYPE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_SAM_PASS_CNT].Value = dt.Rows[i]["CARBIDE_SAMPLE_PASSED_NO"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_SAM_PASS_RESULT].Value = dt.Rows[i]["CARBIDE_SAMPLE_RESULT"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_WEIGHT_STD].Value = dt.Rows[i]["CARBIDE_WEIGHT_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_WEIGHT_VALUE].Value = dt.Rows[i]["CARBIDE_WEIGHT_VALUE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_HIEGHT_STD].Value = dt.Rows[i]["CARBIDE_HEIGHT_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_HIEGHT_VALUE_1].Value = dt.Rows[i]["CARBIDE_HEIGHT_P1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_HIEGHT_VALUE_2].Value = dt.Rows[i]["CARBIDE_HEIGHT_P2"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_HIEGHT_VALUE_3].Value = dt.Rows[i]["CARBIDE_HEIGHT_P3"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_HIEGHT_VALUE_4].Value = dt.Rows[i]["CARBIDE_HEIGHT_P4"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_HIEGHT_VALUE_5].Value = dt.Rows[i]["CARBIDE_HEIGHT_P5"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIND_OUTER_DIA_STD].Value = dt.Rows[i]["CARBIDE_OUTER_DIAMETER_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIND_OUTER_DIA_VALUE].Value = dt.Rows[i]["CARBIDE_OUTER_DIAMETER_VALUE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.COMPLETE_FLATNESS_STD].Value = dt.Rows[i]["COMPLETE_FLATNESS_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.COMPLETE_FLATNESS_VALUE].Value = dt.Rows[i]["COMPLETE_FLATNESS_VALUE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.COMPLETE_WEIGHT_STD].Value = dt.Rows[i]["COMPLETE_WEIGHT_STANDARD"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.COMPLETE_WEIGHT_VALUE].Value = dt.Rows[i]["COMPLETE_WEIGHT_VALUE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.CARBIDE_INPUT_COUNT].Value = dt.Rows[i]["CARBIDE_INPUT_COUNT"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.IMPACT_OPERATION_INPUT_QTY].Value = dt.Rows[i]["IMPACT_PROCESS_INPUT_COUNT"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_CUP.NG_CNT].Value = dt.Rows[i]["NG_COUND"];
                }

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// Laser Marking 설비 데이터 조회
        /// </summary>
        /// <param name="as_lot_id"></param>
        /// <param name="as_res_id"></param>
        /// <returns></returns>
        private bool View_Laser_EQP(string as_lot_id, string as_res_id)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdEquip);
                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-013", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip.ActiveSheet.RowCount++;

                    spdEquip.ActiveSheet.Cells[i, (int)EQP_LASER.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_LASER.LASER_MARKING].Value = dt.Rows[i]["LASER_MARKING_FLAG"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_LASER.INK_PRINT].Value = dt.Rows[i]["INK_PRINT_FLAG"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_LASER.INPUT_NO].Value = dt.Rows[i]["INPUT_NO"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_LASER.WO].Value = dt.Rows[i]["ORDER_ID"];
                }

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// Round 설비 데이터 조회
        /// </summary>
        /// <param name="as_lot_id"></param>
        /// <param name="as_res_id"></param>
        /// <returns></returns>
        private bool View_Round_EQP(string as_lot_id, string as_res_id)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdEquip);
                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-014", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip.ActiveSheet.RowCount++;

                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.RECIPE_ID].Value = dt.Rows[i]["RECIPE_ID"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i][""].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i][""].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.JUDGE].Value = dt.Rows[i]["JUDGMENT"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.NUM_OF_DEFECT_STD].Value = dt.Rows[i]["S_DEFECT_NUMBER"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OUT_DIA_MIN_STD].Value = dt.Rows[i]["S_OUTER_DIAMETER_MIN"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_TARGET_STD].Value = dt.Rows[i]["S_ALL_THICKNESS_TARGET"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_MIN_STD].Value = dt.Rows[i]["S_ALL_THICKNESS_MIN"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_MAX_STD].Value = dt.Rows[i]["S_ALL_THICKNESS_MAX"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLAT_MIN].Value = dt.Rows[i]["S_FLATNESS_MIN"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLAT_MAX].Value = dt.Rows[i]["S_FLATNESS_MAX"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.SIZE_UM].Value = dt.Rows[i]["SIZE_UM"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.SIZE_UM2].Value = dt.Rows[i]["SIZE_UM2"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.CLASSIFICATION].Value = dt.Rows[i]["CLASSFICATION"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OUTER_DIA_1].Value = dt.Rows[i]["OUTER_DIAMETER_1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OUTER_DIA_2].Value = dt.Rows[i]["OUTER_DIAMETER_2"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OUTER_DIA_MIN].Value = dt.Rows[i]["OUTER_DIAMETER_MIN"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_1].Value = dt.Rows[i]["ALL_THICKNESS_1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_2].Value = dt.Rows[i]["ALL_THICKNESS_2"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_3].Value = dt.Rows[i]["ALL_THICKNESS_3"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_4].Value = dt.Rows[i]["ALL_THICKNESS_4"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_5].Value = dt.Rows[i]["ALL_THICKNESS_5"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_6].Value = dt.Rows[i]["ALL_THICKNESS_6"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_7].Value = dt.Rows[i]["ALL_THICKNESS_7"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_8].Value = dt.Rows[i]["ALL_THICKNESS_8"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_9].Value = dt.Rows[i]["ALL_THICKNESS_9"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_MIN].Value = dt.Rows[i]["ALL_THICKNESS_MIN"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.OVERALL_THICK_MAX].Value = dt.Rows[i]["ALL_THICKNESS_MAX"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_1].Value = dt.Rows[i]["FLATNESS_1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_2].Value = dt.Rows[i]["FLATNESS_2"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_3].Value = dt.Rows[i]["FLATNESS_3"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_4].Value = dt.Rows[i]["FLATNESS_4"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_5].Value = dt.Rows[i]["FLATNESS_5"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_6].Value = dt.Rows[i]["FLATNESS_6"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_7].Value = dt.Rows[i]["FLATNESS_7"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_8].Value = dt.Rows[i]["FLATNESS_8"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_9].Value = dt.Rows[i]["FLATNESS_9"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.FLATNESS_MAX].Value = dt.Rows[i]["FLATNESS_MAX"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.DEFECT_IMAGE_1].Value = dt.Rows[i]["DEFECT_IMAGE_1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.DEFECT_IMAGE_2].Value = dt.Rows[i]["DEFECT_IMAGE_2"];
                }

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// Ball Mill 설비 데이터 조회
        /// </summary>
        /// <param name="as_lot_id"></param>
        /// <param name="as_res_id"></param>
        /// <returns></returns>
        private bool View_Ball_Mill_EQP(string as_lot_id, string as_res_id)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdEquip);
                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-015", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip.ActiveSheet.RowCount++;

                    spdEquip.ActiveSheet.Cells[i, (int)EQP_BALLMILL.DEGREE].Value = dt.Rows[i]["COL_SEQ"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_BALLMILL.ITEM].Value = dt.Rows[i]["CHAR_DESC"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_BALLMILL.ITEM].Tag = dt.Rows[i]["CHAR_ID"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_BALLMILL.VALUE].Value = dt.Rows[i]["VALUE_1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_BALLMILL.COLLECT_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                }

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// Ball Mill 설비 데이터 조회
        /// </summary>
        /// <param name="as_lot_id"></param>
        /// <param name="as_res_id"></param>
        /// <returns></returns>
        private bool View_Impact_EQP(string as_lot_id, string as_res_id)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdEquip);
                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-016", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip.ActiveSheet.RowCount++;

                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.RECIPE_ID].Value = dt.Rows[i]["RECIPE_ID"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.START_TIME].Value = dt.Rows[i]["START_TIME"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.END_TIME].Value = dt.Rows[i]["END_TIME"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.FLATNESS_1].Value = dt.Rows[i]["FLATNESS_1"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.FLATNESS_2].Value = dt.Rows[i]["FLATNESS_2"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.FLATNESS_3].Value = dt.Rows[i]["FLATNESS_3"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.FLATNESS_4].Value = dt.Rows[i]["FLATNESS_4"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.FLATNESS_5].Value = dt.Rows[i]["FLATNESS_5"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.WEIGHT].Value = dt.Rows[i]["WEIGHT"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.AIR_POCKET].Value = dt.Rows[i]["AIR_POCKET"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.IMPACT_NO].Value = dt.Rows[i]["IMPACT_NO"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.IMPACT_TIME].Value = dt.Rows[i]["IMPACT_TIME"];
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_IMPACT.JUDGE].Value = dt.Rows[i]["JUDGMENT"];
                }

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool View_EDC_Data(string as_lot_id, string as_mat_id, string as_oper)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                spdEquip_BallMill.RowCount = 0;
                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                dvcArgu[1].sCondition_ID = "FACTORY";
                dvcArgu[1].sCondition_Value = MPGV.gsFactory;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = as_mat_id;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = as_oper;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-017", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip_BallMill.RowCount++;

                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.DEGREE].Value = dt.Rows[i]["COL_SEQ"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.ITEM].Value = dt.Rows[i]["CHAR_DESC"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.ITEM].Tag = dt.Rows[i]["CHAR_ID"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.VALUE].Value = dt.Rows[i]["VALUE_1"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.COLLECT_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                }

                if (dt.Rows.Count == 0)
                    spdEquip.ActiveSheet = spdEquip_Default;
                else
                    spdEquip.ActiveSheet = spdEquip_BallMill;

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// Dry CIP 설비 데이터 조회
        /// </summary>
        /// <param name="as_lot_id"></param>
        /// <param name="as_res_id"></param>
        /// <returns></returns>
        private bool View_Dry_CIP_EQP(string as_lot_id, string as_res_id, int i_start_hist_seq)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
            DataTable dt = null;
            string sSql = "";
            int i = 0, iRow = 0;

            try
            {
                spdEquip_DryCIP.RowCount = 3;
                spdEquip_DryCIP.Cells[0, 1].Value = "";

                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                dvcArgu[1].sCondition_ID = "HIST_SEQ";
                dvcArgu[1].sCondition_Value = i_start_hist_seq;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-018", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    if (i == 0)
                        spdEquip_DryCIP.Cells[0, 1].Value = dt.Rows[i]["WORK_TIME"];
                    else if (i > 1)
                    {
                        iRow = spdEquip_DryCIP.RowCount;
                        spdEquip_DryCIP.RowCount++;
                        spdEquip_DryCIP.Cells[iRow, (int)EQP_DRY.WORK_TIME].Value = dt.Rows[i]["WORK_TIME"];
                        spdEquip_DryCIP.Cells[iRow, (int)EQP_DRY.OPER_PRESS].Value = dt.Rows[i]["OPERATION_PRESS"];
                        spdEquip_DryCIP.Cells[iRow, (int)EQP_DRY.PRESS_HOLD_TIME_1].Value = dt.Rows[i]["PRESS_HOLD_TIME_1"];
                        spdEquip_DryCIP.Cells[iRow, (int)EQP_DRY.PRESS_HOLD_TIME_2].Value = dt.Rows[i]["PRESS_HOLD_TIME_2"];
                        spdEquip_DryCIP.Cells[iRow, (int)EQP_DRY.PRESS_FLAG].Value = dt.Rows[i]["PRESS_OPERATION_FLAG"];
                        spdEquip_DryCIP.Cells[iRow, (int)EQP_DRY.DISCHARGE_FLAG].Value = dt.Rows[i]["DISCHARGE_OPERATION_FLAG"];
                    }
                }

                if (dt.Rows.Count == 0)
                    spdEquip.ActiveSheet = spdEquip_Default;
                else
                    spdEquip.ActiveSheet = spdEquip_DryCIP;

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool View_Extruding_EQP(string as_lot_id, string as_res_id, int ai_hist_seq)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                spdEquip_EDR.RowCount = 0;

                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = as_lot_id;

                dvcArgu[1].sCondition_ID = "HIST_SEQ";
                dvcArgu[1].sCondition_Value = ai_hist_seq;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-019", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEquip_EDR.RowCount++;
                    spdEquip_EDR.Cells[i, 0].Value = dt.Rows[i]["RES_DESC"];
                    spdEquip_EDR.Cells[i, 0].Tag = dt.Rows[i]["RES_ID"];
                    spdEquip_EDR.Cells[i, 1].Value = dt.Rows[i]["CUM"];
                }

                if (dt.Rows.Count == 0)
                    spdEquip.ActiveSheet = spdEquip_Default;
                else
                    spdEquip.ActiveSheet = spdEquip_EDR;

                MPCF.FitColumnHeader(spdEquip);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// Dry CIP Sheet의 언어 변환
        /// </summary>
        private void ConvertLangOfSheet()
        {
            try
            {
                spdEquip_DryCIP.Cells[0, 0].Value = MPCF.FindLanguage(spdEquip_DryCIP.Cells[0, 0].Text, CAPTION_TYPE.LABEL);

                for (int i = 0; i < spdEquip_DryCIP.ColumnCount; i++)
                {
                    spdEquip_DryCIP.Cells[2, i].Text = MPCF.FindLanguage(spdEquip_DryCIP.Cells[2, i].Text, CAPTION_TYPE.LABEL);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void SelectedItemChangedByColSet(string inspId)
        {
            string colSetId = string.Empty;
            int colSetVersion = 1;
            string lotId = string.Empty;
            string matId = string.Empty;
            int matVer = 1;
            string oper = string.Empty;

            try
            {
                //Clear
                MPCF.ClearList(spdDataCollection, true);

                if (MPCF.Trim(inspId) != "")
                {
                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                    DataTable dt = null;
                    string sSql = "";

                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "INSP_ID";
                    dvcArgu[1].sCondition_Value = inspId;

                    if (TPDR.GetDataOne("", ref dt, "CWIP3010-005", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdWorkerList);
                        return;
                    }

                    colSetId = dt.Rows[0]["COL_SET_ID"].ToString();

                    if (MPCF.Trim(colSetId) != "")
                    {
                        lotId = dt.Rows[0]["LOT_ID"].ToString();
                        matId = dt.Rows[0]["MAT_ID"].ToString();
                        matVer = MPCF.ToInt(dt.Rows[0]["MAT_VER"]);
                        oper = dt.Rows[0]["INSP_OPER"].ToString();

                        cdvColSetID.Text = colSetId;
                        colSetVersion = MPCF.ToInt(dt.Rows[0]["COL_SET_VERSION"]);
                        txtColSetVer.Text = colSetVersion.ToString();


                        cls_derived_char_list = new clsDerivedCharList();
                        cls_derived_char_list.GetDerivedInfo(colSetId, colSetVersion, lotId, "", "", "");

                        if (ViewCharacterList(spdDataCollection, '5', colSetId, colSetVersion, 'Y', cls_derived_char_list, lotId, matId, matVer, oper) == false)
                        {
                            return;
                        }
                    }
                    else
                    {
                        ClearList("COL_SET_CHANGED");
                    }
                }
                else
                {
                    ClearList("COL_SET_CHANGED");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void ClearList(string sType)
        {
            switch (sType)
            {
                case "COL_SET_CHANGED":

                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
                case "LOT_TREE_CHANGED":

                    MPCF.ClearList(spdMaterialList);

                    MPCF.FitColumnHeader(spdEquip);

                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
            }

        }

        public bool ViewCharacterList(Control control, char ProcStep, string ColSetID, int ColSetVersion, char cIncludeUnitID, clsDerivedCharList cls_derived_char_list, string LotID, string sMatID, int iMatVer, string sOper)
        {

            int i;
            int j;
            int k;
            //int m;
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
            //FarPoint.Win.Spread.CellType.ComboBoxCellType UnitCellType = null;
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
                        //UnitCellType = null;
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

                        /*
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

                        }*/

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

        /// <summary>
        /// 검사 데이터 조회
        /// </summary>
        /// <param name="inspId">검사ID</param>
        /// <returns></returns>
        private bool ViewInspectionData(string inspId)
        {
            try
            {
                int iValueCnt = 0;
                int iRow = 0;
                string s_value_name;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspId;

                if (TPDR.GetDataOne("", ref dt, "CWIP3010-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.CHAR_COL].Text == dt.Rows[i]["CHAR_ID"].ToString()  //dt.Rows[i]["CHAR_ID"].ToString()
                            && spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.UNIT_SEQ_COL].Text == MPCF.ToInt(dt.Rows[i]["UNIT_SEQ"]).ToString())
                        {
                            iRow = j;
                            break;
                        }

                    }

                    spdDataCollection.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA.UNIT_COL, dt.Rows[i]["UNIT_ID"].ToString());

                    // iUnitCnt = MPCF.ToInt(dt.Rows[0]["UNIT_COUNT"].ToString());
                    iValueCnt = MPCF.ToInt(dt.Rows[i]["VALUE_COUNT"]);

                    if (iValueCnt > 25)
                    {
                        iValueCnt = 25;
                    }

                    for (int k = 1; k <= iValueCnt; k++)
                    {
                        s_value_name = "VALUE_" + k.ToString();
                        if (string.Equals(dt.Rows[i]["VALUE_TYPE"].ToString(), "N"))
                        {
                            if (MPCF.Trim(dt.Rows[i][s_value_name]) != "")
                            {
                                spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = MPCF.ToDbl(dt.Rows[i][s_value_name]);
                            }
                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = dt.Rows[i][s_value_name];
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

        #endregion

        #region " Event Definition "
        private void btnView_Click(object sender, EventArgs e)
        {
            int i = 0;

            spdMaterialList_Sheet1.RowCount = 0;

            for (i = 0; i < spdEquip.Sheets.Count; i++)
                spdEquip.Sheets[i].RowCount = 0;

            ViewLotList();
        }

        private void spdLotList_SelectionChanged(object sender, FarPoint.Win.Spread.SelectionChangedEventArgs e)
        {
            string s_lot_id = "";
            string s_res_id = "";
            string s_res_grp_1 = "";
            string s_mat_id = "";
            string s_oper = "";
            int i_start_hist_seq = 0;

            if (spdLotList_Sheet1.RowCount > 0)
            {
                spdMaterialList_Sheet1.RowCount = 0;

                for (int i = 0; i < spdEquip.Sheets.Count; i++)
                    spdEquip.Sheets[i].RowCount = 0;

                s_lot_id = spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.LOT_ID].Text;
                s_res_id = spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.RES_ID].Text;
                s_mat_id = spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.MAT_ID].Text;
                s_oper = spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.OPER].Text;
                i_start_hist_seq = MPCF.ToInt(spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.HIST_SEQ].Value);

                s_res_grp_1 = MPCF.Trim(spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.RES_ID].Tag);

                View_Material_Usage(s_lot_id, s_oper);

                //작업자 정보 조회
                ViewWorkerList(s_lot_id, i_start_hist_seq);





                // Press 설비
                if (s_res_grp_1 == "E002")
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Press", 0);
                    spdEquip.ActiveSheet = spdEquip_Press;
                    View_Press_EQP(s_lot_id, s_res_id);
                }
                // 컵조립 설비
                else if (s_res_grp_1 == "E027")
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Cup Assembly", 0);
                    spdEquip.ActiveSheet = spdEquip_Cup;
                    View_Cup_EQP(s_lot_id, s_res_id);
                }
                // Laser Marking 설비
                else if (s_res_grp_1 == "E025")
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Laser Marking", 0);
                    spdEquip.ActiveSheet = spdEquip_Laser;
                    View_Laser_EQP(s_lot_id, s_res_id);
                }
                // Round 검사 설비
                else if (s_res_grp_1 == "E026")
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Round Inspection", 0);
                    spdEquip.ActiveSheet = spdEquip_Round;
                    View_Round_EQP(s_lot_id, s_res_id);
                }
                // Impact 설비
                else if (s_res_grp_1 == "E006")
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Impact", 0);
                    spdEquip.ActiveSheet = spdEquip_Impact;
                    View_Impact_EQP(s_lot_id, s_res_id);
                }
                // 볼밀 설비
                else if (s_res_grp_1 == "E005")
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Ball Mill", 0);
                    spdEquip.ActiveSheet = spdEquip_BallMill;
                    View_Ball_Mill_EQP(s_lot_id, s_res_id);
                }
                // CIP 설비의 Count 정보, 온도 정보 표시
                else if (s_res_grp_1 == "E018")
                {
                    grpEquipmentData.Text = "Dry CIP";
                    spdEquip.ActiveSheet = spdEquip_BallMill;
                    View_Dry_CIP_EQP(s_lot_id, s_res_id, i_start_hist_seq);
                }
                // 압출기의 Count 정보 표시
                else if (s_res_grp_1 == "E020")
                {
                    grpEquipmentData.Text = "EDR&MD";
                    spdEquip.ActiveSheet = spdEquip_EDR;
                    View_Extruding_EQP(s_lot_id, s_res_id, i_start_hist_seq);
                }
                else
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Equipment Data", 0);
                    spdEquip.ActiveSheet = spdEquip_Default;
                    if (View_EDC_Data(s_lot_id, s_mat_id, s_oper) == false)
                        spdEquip.ActiveSheet = spdEquip_Default;
                }

                string inspId = MPCF.Trim(spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.INSP_ID].Value);

                if (!String.IsNullOrEmpty(inspId))
                {
                    spdDataCollection_Sheet1.RowCount = 0;
                    SelectedItemChangedByColSet(inspId);

                    if (ViewInspectionData(inspId) == false)
                    {
                        CSCF.ClearSpread(spdDataCollection, 0, (int)COLLECTION_DATA.VALUE_START_COL, "");
                    }
                }
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdLotList, "LotList");
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
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void frmWIPViewLotTrace_Load(object sender, EventArgs e)
        {
            spdEquip.ActiveSheet = spdEquip_Default;
            grpEquipmentData.Text = MPCF.FindLanguage("Equipment Data", 0);

            ConvertLangOfSheet();
        }

        private void spdLotTree_SelectionChanged(object sender, FarPoint.Win.Spread.SelectionChangedEventArgs e)
        {
            string lotId = string.Empty;

            lotId = MPCF.Trim(spdLotTree_Sheet1.Cells[e.Range.Row, (int)LOT_TREE.LOT_ID].Tag);

            ViewLotHistory(lotId);
            ViewShipingList(lotId);

            ClearList("LOT_TREE_CHANGED");
        }

        #endregion
    }
}
