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

namespace CUS_WIP
{
    public partial class frmWIPViewActualOfLots : CUS_COM.frmTranForm02
    {
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
            RWK_FLAG,
            RES_ID,
            MAT_DESC,
            UNIT,
            INPUT_QTY,
            GOOD_QTY,
            BAD_QTY,
            DEPT,
            WORKPLACE
        }

        private enum MAT_USAGE
        {
            INV_LOT_ID,
            OPER,
            INPUT_TIME,
            MAT_DESC,
            INPUT_QTY,
            UNIT
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

        /// <summary>
        /// Lot별 실적 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Lot_List()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdLotList);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FR_DT";
                dvcArgu[1].sCondition_Value = dtpFromDate.Value.ToString("yyyyMMdd");

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

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Tag = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.RWK_FLAG].Value = dt.Rows[i]["RWK_FLAG"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RWK_FLAG].Tag = dt.Rows[i]["RES_GRP_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Value = dt.Rows[i]["RES_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Tag = dt.Rows[i]["RES_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.INPUT_QTY].Value = dt.Rows[i]["IN_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.GOOD_QTY].Value = dt.Rows[i]["OUT_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.BAD_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.DEPT].Value = dt.Rows[i]["AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.DEPT].Tag = dt.Rows[i]["AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.WORKPLACE].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.WORKPLACE].Tag = dt.Rows[i]["SUB_AREA_ID"];
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
        /// <returns></returns>
        private bool View_Material_Usage(string as_lot_id)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
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

                if (TPDR.GetDataOne("", ref dt, "CWIP3006-002", dvcArgu, false, false, ref sSql) == false)
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

        private void btnView_Click(object sender, EventArgs e)
        {
            int i = 0;

            spdMaterialList_Sheet1.RowCount = 0;

            for (i = 0; i < spdEquip.Sheets.Count; i++)
                spdEquip.Sheets[i].RowCount = 0;

            View_Lot_List();
        }

        private void spdLotList_SelectionChanged(object sender, FarPoint.Win.Spread.SelectionChangedEventArgs e)
        {
            string s_lot_id = "";
            string s_res_id = "";
            string s_res_grp_1 = "";

            if(spdLotList_Sheet1.RowCount > 0)
            {
                spdMaterialList_Sheet1.RowCount = 0;

                for (int i = 0; i < spdEquip.Sheets.Count; i++)
                    spdEquip.Sheets[i].RowCount = 0;

                s_lot_id = spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.LOT_ID].Text;
                s_res_id = spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.RES_ID].Tag.ToString();

                s_res_grp_1 = MPCF.Trim(spdLotList_Sheet1.Cells[e.Range.Row, (int)LOT.RWK_FLAG].Tag);

                View_Material_Usage(s_lot_id);

                // Press 설비
                if (s_res_grp_1 == "E002")
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Press", 0);
                    spdEquip.ActiveSheet = spdEquip_Press;
                    View_Press_EQP(s_lot_id, s_res_id);
                }
                // 컵조립 설비
                else if (s_res_grp_1 == "")
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
                else
                {
                    grpEquipmentData.Text = MPCF.FindLanguage("Equipment Data", 0);
                    spdEquip.ActiveSheet = spdEquip_Default;
                }
            }
        }

        private void frmWIPViewActualOfLots_Load(object sender, EventArgs e)
        {
            spdEquip.ActiveSheet = spdEquip_Default;
            grpEquipmentData.Text = MPCF.FindLanguage("Equipment Data", 0);
        }
    }
}
