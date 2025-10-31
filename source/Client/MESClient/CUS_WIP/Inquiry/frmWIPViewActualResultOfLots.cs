using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.DNMCore;

using CUS_COM;
using CUS_RAS;
using System.IO.Ports;
using FarPoint.Win.Spread;

namespace CUS_WIP
{

    public partial class frmWIPViewActualOfLots : CUS_COM.frmTranForm02
    {

        #region " Variable Definition "
        public string g_Dept = string.Empty;
        public string g_DeptDisplay = string.Empty;
        public string g_Workplace = string.Empty;
        public string g_WorkplaceDisplay = string.Empty;
        public string g_Oper = string.Empty;
        public string g_g_OperDisplay = string.Empty;
        public string g_PopYn = "N";

        #endregion

        public frmWIPViewActualOfLots()
        {
            InitializeComponent();
        }

        private enum LOT
        {
            LOT_ID,
            OPER,
            START_TIME,
            END_TIME,
            CREATE_CODE_DESC,
            RWK_FLAG,
            RES_ID,
            ORDER_ID,
            MAT_DESC,
            UNIT,
            INPUT_QTY,
            GOOD_QTY,
            BAD_QTY,
            DEPT,
            WORKPLACE,
            TRAN_COMMENT
        }

        private enum MAT_USAGE
        {
            INV_LOT_ID,
            OPER,
            INPUT_TIME,
            MAT_DESC,
            INPUT_QTY,
            UNIT,
            CREATE_CODE_DESC
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

        /// <summary>
        /// Lot별 실적 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Lot_List()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[11];
            DataTable dt = null;
            string sSql = "";
            int i = 0;
            string s_view_id = "";

            try
            {
                MPCF.ClearList(spdLotList);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FR_DT";
                dvcArgu[1].sCondition_Value = string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "TO_DT";
                dvcArgu[2].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");

                dvcArgu[3].sCondition_ID = "AREA_ID";
                dvcArgu[3].sCondition_Value = cdvDept.Text;

                dvcArgu[4].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[4].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = cdvOper.Text;

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text;

                dvcArgu[7].sCondition_ID = "RES_ID";
                dvcArgu[7].sCondition_Value = cdvResource.Text;

                dvcArgu[8].sCondition_ID = "MAT_ID";
                dvcArgu[8].sCondition_Value = cdvMatId.Text;

                dvcArgu[9].sCondition_ID = "CREATE_CODE";
                dvcArgu[9].sCondition_Value = cdvOrderType.Text + "%";

                dvcArgu[10].sCondition_ID = "ORDER_ID";
                dvcArgu[10].sCondition_Value = cdvOrder.Text;


                if (chkDate.Checked)
                    s_view_id = "CWIP3006-001-1";
                else
                    s_view_id = "CWIP3006-001-2";

                if (TPDR.GetDataOne("", ref dt, s_view_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for(i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Tag = dt.Rows[i]["START_HIST_SEQ"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Tag = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.CREATE_CODE_DESC].Tag = dt.Rows[i]["CREATE_CODE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RWK_FLAG].Value = dt.Rows[i]["RWK_FLAG"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RWK_FLAG].Tag = dt.Rows[i]["RES_GRP_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Value = dt.Rows[i]["RES_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Tag = dt.Rows[i]["RES_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Tag = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.INPUT_QTY].Value = dt.Rows[i]["IN_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.GOOD_QTY].Value = dt.Rows[i]["OUT_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.BAD_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.DEPT].Value = dt.Rows[i]["AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.DEPT].Tag = dt.Rows[i]["AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.WORKPLACE].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.WORKPLACE].Tag = dt.Rows[i]["SUB_AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.TRAN_COMMENT].Value = dt.Rows[i]["TRAN_COMMENT"];

                }

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
        private bool View_Material_Usage(string as_lot_id, string as_res_grp)
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

                dvcArgu[2].sCondition_ID = "RES_GRP";
                dvcArgu[2].sCondition_Value = as_res_grp;

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-002-1", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for(i = 0; i < dt.Rows.Count; i++)
                {
                    spdMaterialList_Sheet1.RowCount++;
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.INPUT_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["TRAN_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.INPUT_QTY].Value = dt.Rows[i]["TRAN_QTY"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.UNIT].Value = dt.Rows[i]["TRAN_UNIT"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT_USAGE.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE"];
                }

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

                for(i = 0; i < dt.Rows.Count; i++)
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
                    spdEquip.ActiveSheet.Cells[i, (int)EQP_ROUND.END_TIME].Value =   MPCF.MakeDateFormat(dt.Rows[i][""].ToString(), DATE_TIME_FORMAT.DATETIME);
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

                    spdEquip_BallMill .Cells[i, (int)EQP_BALLMILL.DEGREE].Value = dt.Rows[i]["COL_SEQ"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.ITEM].Value = dt.Rows[i]["CHAR_DESC"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.ITEM].Tag = dt.Rows[i]["CHAR_ID"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.VALUE].Value = dt.Rows[i]["VALUE_1"];
                    spdEquip_BallMill.Cells[i, (int)EQP_BALLMILL.COLLECT_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                }

                if (dt.Rows.Count == 0)
                    spdEquip.ActiveSheet = spdEquip_Default;
                else
                    spdEquip.ActiveSheet = spdEquip_BallMill;

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

                for(i = 0; i < dt.Rows.Count; i++)
                {
                    if (i == 0)
                        spdEquip_DryCIP.Cells[0, 1].Value = dt.Rows[i]["WORK_TIME"];
                    else if( i > 1)
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

                for(i = 0; i < dt.Rows.Count; i++)
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

        private void btnView_Click(object sender, EventArgs e)
        {
            int i = 0;

            spdMaterialList_Sheet1.RowCount = 0;

            for (i = 0; i < spdEquip.Sheets.Count; i++)
                spdEquip.Sheets[i].RowCount = 0;

            View_Lot_List();
        }

        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            string s_lot_id = "";
            string s_res_id = "";
            string s_res_grp_1 = "";
            string s_mat_id = "";
            string s_oper = "";
            int i_start_hist_seq = 0;

            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                if (spdLotList_Sheet1.RowCount > 0)
                {
                    spdMaterialList_Sheet1.RowCount = 0;

                    for (int i = 0; i < spdEquip.Sheets.Count; i++)
                        spdEquip.Sheets[i].RowCount = 0;

                    s_lot_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT.LOT_ID].Text;
                    s_res_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT.RES_ID].Tag.ToString();
                    s_mat_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT.MAT_DESC].Tag.ToString();
                    s_oper = spdLotList_Sheet1.Cells[e.Row, (int)LOT.OPER].Tag.ToString();
                    i_start_hist_seq = MPCF.ToInt(spdLotList_Sheet1.Cells[e.Row, (int)LOT.LOT_ID].Tag);

                    s_res_grp_1 = MPCF.Trim(spdLotList_Sheet1.Cells[e.Row, (int)LOT.RWK_FLAG].Tag);

                    View_Material_Usage(s_lot_id, s_res_grp_1);

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
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_SelectionChanged(object sender, FarPoint.Win.Spread.SelectionChangedEventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmWIPViewActualOfLots_Load(object sender, EventArgs e)
        {




        if(g_PopYn == "Y")
            {
                cdvDept.Text = g_Dept;
                cdvDept.DisplayText = g_DeptDisplay;
                cdvWorkPlace.Text = g_Workplace;
                cdvWorkPlace.DisplayText = g_WorkplaceDisplay;
                cdvOper.Text = g_Oper;
                cdvOper.DisplayText = g_g_OperDisplay;
            }


        /*

         public string g_Dept = string.Empty;
        public string g_DeptDisplay = string.Empty;
        public string g_Workplace = string.Empty;
        public string g_WorkplaceDisplay = string.Empty;
        public string g_Oper = string.Empty;
        public string g_g_OperDisplay = string.Empty;
        public string g_PopYn = "N";

    */


        dtpFromDate.Value = DateTime.Now.AddDays(-7);
            //dtpFromDate.Value = DateTime.Now;
            //dtpFromDate.Format = DateTimePickerFormat.Custom;
            //dtpFromDate.CustomFormat = " ";










        //조회 조건 최조 세팅
        cdvOrderType.Text = "PROD";
            cdvOrderType.DisplayText = "Product Lot";

            spdEquip.ActiveSheet = spdEquip_Default;
            grpEquipmentData.Text = MPCF.FindLanguage("Equipment Data", 0);

            ConvertLangOfSheet();
        }

        private void cdvResource_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvResource.Init();
                MPCF.InitListView(cdvResource.GetListView);
                cdvResource.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResource.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResource.SelectedSubItemIndex = 0;
                cdvResource.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvResource.GetListView, '1', cdvOper.Text) == false)
                    return;

                cdvResource.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdLotList, "LotList");


                //FpSpread excelSp = new FpSpread();
                //SheetView sheet1 = new SheetView();

                //string sFileName = EXTFUC.ShowFileOpenDialog(cdvOper.DisplayText);

                //if (String.IsNullOrEmpty(sFileName))
                //{
                //    return;
                //}

                //sheet1 = spdLotList_Sheet1;

                //sheet1.SheetName = cdvOper.DisplayText;
                //sheet1.ColumnCount = spdLotList_Sheet1.ColumnCount;
                //sheet1.RowCount = spdLotList_Sheet1.RowCount;
                //sheet1.Protect = false;
                //excelSp.Sheets.Add(sheet1);

                //excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);

                //MPCF.ShowMsgBox(MPCF.GetMessage(52));  // CMN052 INFO - 작업을 성공적으로 수행하였습니다.

                //sheet1.Protect = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
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

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
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

        private void dtpFromDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtpFromDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromDate.CustomFormat = " ";
                    break;
            }
        }

        private void dtpFromDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_OperCode = cdvOper.Text;
                popup.g_OperDesc = cdvOper.DisplayText;
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
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOrder.DisplayText == "")
                cdvOrder.Text = "";
        }





        private void ResDatapopup()
        {
            try
            {
                //일단 시간없어서....그냥 코딩함..나중에 공정에 설비메뉴별로 GCM으로 딸것.......아마도...추가될떄...--

                FarPoint.Win.Spread.SheetView oSheet = spdLotList.ActiveSheet;

                
                /*
                frmViewHMExtruderData OH22010
frmViewCTMBallmillData OC01120  OC02020 OC02050
frmViewCTMPlanetaryMixerData OC02080
frmViewCTMMixedPowerVacuumFurnaceData OC02100
frmViewCTMProductVacuumFurnaceData OC04080 OC05020
frmViewCTM5000tonPressData OC03160 OR01010
frmViewCTM400tonPressData OC01030
*/


                switch (oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString())
                {
                    case "OH22010":
                        frmViewHMExtruderData popup_01 = new frmViewHMExtruderData();
                        popup_01.StartPosition = FormStartPosition.CenterParent;
                        popup_01.g_Dept = cdvDept.Text;
                        popup_01.g_DeptDisplay = cdvDept.DisplayText;
                        popup_01.g_Oper = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString();
                        popup_01.g_OperDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Text;
                        popup_01.g_ResId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Tag.ToString();
                        popup_01.g_ResDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Text;
                        popup_01.g_searchType = "LOT";
                        popup_01.g_LotId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.LOT_ID].Text;
                        popup_01.g_SearchYn = "Y";
                        popup_01.g_PopYn = "Y";
                        if (popup_01.ShowDialog() == DialogResult.OK)
                        {
                            popup_01 = null;
                        }
                        else
                        {
                            return;
                        }

                        break;


                    case "OC01120":
                    case "OC02020":
                        frmViewCTMBallmillData popup_02 = new frmViewCTMBallmillData();
                        popup_02.StartPosition = FormStartPosition.CenterParent;
                        popup_02.g_Dept = cdvDept.Text;
                        popup_02.g_DeptDisplay = cdvDept.DisplayText;
                        popup_02.g_Oper = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString();
                        popup_02.g_OperDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Text;
                        popup_02.g_ResId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Tag.ToString();
                        popup_02.g_ResDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Text;
                        popup_02.g_searchType = "LOT";
                        popup_02.g_LotId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.LOT_ID].Text;
                        popup_02.g_SearchYn = "Y";
                        popup_02.g_PopYn = "Y";
                        if (popup_02.ShowDialog() == DialogResult.OK)
                        {
                            popup_02 = null;
                        }
                        else
                        {
                            return;
                        }

                        break;
                    case "OC02080":
                        frmViewCTMPlanetaryMixerData popup_03 = new frmViewCTMPlanetaryMixerData();
                        popup_03.StartPosition = FormStartPosition.CenterParent;
                        popup_03.g_Dept = cdvDept.Text;
                        popup_03.g_DeptDisplay = cdvDept.DisplayText;
                        popup_03.g_Oper = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString();
                        popup_03.g_OperDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Text;
                        popup_03.g_ResId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Tag.ToString();
                        popup_03.g_ResDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Text;
                        popup_03.g_searchType = "LOT";
                        popup_03.g_LotId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.LOT_ID].Text;
                        popup_03.g_SearchYn = "Y";
                        popup_03.g_PopYn = "Y";
                        if (popup_03.ShowDialog() == DialogResult.OK)
                        {
                            popup_03 = null;
                        }
                        else
                        {
                            return;
                        }

                        break;
                    case "OC02100":
                        frmViewCTMMixedPowerVacuumFurnaceData popup_04 = new frmViewCTMMixedPowerVacuumFurnaceData();
                        popup_04.StartPosition = FormStartPosition.CenterParent;
                        popup_04.g_Dept = cdvDept.Text;
                        popup_04.g_DeptDisplay = cdvDept.DisplayText;
                        popup_04.g_Oper = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString();
                        popup_04.g_OperDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Text;
                        popup_04.g_ResId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Tag.ToString();
                        popup_04.g_ResDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Text;
                        popup_04.g_searchType = "LOT";
                        popup_04.g_LotId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.LOT_ID].Text;
                        popup_04.g_SearchYn = "Y";
                        popup_04.g_PopYn = "Y";
                        if (popup_04.ShowDialog() == DialogResult.OK)
                        {
                            popup_04 = null;
                        }
                        else
                        {
                            return;
                        }


                        break;
                    case "OC04080":
                    case "OC05020":
                        frmViewCTMProductVacuumFurnaceData popup_05 = new frmViewCTMProductVacuumFurnaceData();
                        popup_05.StartPosition = FormStartPosition.CenterParent;
                        popup_05.g_Dept = cdvDept.Text;
                        popup_05.g_DeptDisplay = cdvDept.DisplayText;
                        popup_05.g_Oper = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString();
                        popup_05.g_OperDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Text;
                        popup_05.g_ResId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Tag.ToString();
                        popup_05.g_ResDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Text;
                        popup_05.g_searchType = "LOT";
                        popup_05.g_LotId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.LOT_ID].Text;
                        popup_05.g_SearchYn = "Y";
                        popup_05.g_PopYn = "Y";
                        if (popup_05.ShowDialog() == DialogResult.OK)
                        {
                            popup_05 = null;
                        }
                        else
                        {
                            return;
                        }
                        break;
                    case "OC03160":
                    case "OR01010":
                        frmViewCTM5000tonPressData popup_06 = new frmViewCTM5000tonPressData();
                        popup_06.StartPosition = FormStartPosition.CenterParent;
                        popup_06.g_Dept = cdvDept.Text;
                        popup_06.g_DeptDisplay = cdvDept.DisplayText;
                        popup_06.g_Oper = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString();
                        popup_06.g_OperDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Text;
                        popup_06.g_ResId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Tag.ToString();
                        popup_06.g_ResDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Text;
                        popup_06.g_searchType = "LOT";
                        popup_06.g_LotId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.LOT_ID].Text;
                        popup_06.g_SearchYn = "Y";
                        popup_06.g_PopYn = "Y";
                        if (popup_06.ShowDialog() == DialogResult.OK)
                        {
                            popup_06 = null;
                        }
                        else
                        {
                            return;
                        }

                        break;
                    case "OC01030":
                        frmViewCTM400tonPressData popup_07 = new frmViewCTM400tonPressData();
                        popup_07.StartPosition = FormStartPosition.CenterParent;
                        popup_07.g_Dept = cdvDept.Text;
                        popup_07.g_DeptDisplay = cdvDept.DisplayText;
                        popup_07.g_Oper = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Tag.ToString();
                        popup_07.g_OperDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.OPER].Text;
                        popup_07.g_ResId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Tag.ToString();
                        popup_07.g_ResDisplay = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.RES_ID].Text;
                        popup_07.g_searchType = "LOT";
                        popup_07.g_LotId = oSheet.Cells[oSheet.ActiveRowIndex, (int)LOT.LOT_ID].Text;
                        popup_07.g_SearchYn = "Y";
                        popup_07.g_PopYn = "Y";
                        if (popup_07.ShowDialog() == DialogResult.OK)
                        {
                            popup_07 = null;
                        }
                        else
                        {
                            return;
                        }

                        break;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void spdLotList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            if (spdLotList.ActiveSheet.RowCount == 0)
            {
                return;
            }
            ResDatapopup();
        }
    }
}
