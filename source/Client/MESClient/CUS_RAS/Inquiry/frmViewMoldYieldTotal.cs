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

namespace CUS_RAS
{
    public partial class frmViewMoldYieldTotal : CUS_COM.frmViewForm01
    {
        public frmViewMoldYieldTotal()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum BRAND_BK_LIST
        {
            S_TYPE,
            RES_NAME,
            TOOL_TYPE,
            TOTAL_AVG,
            TOTAL_1,
            TOTAL_2,
            TOTAL_3,
            IJ_AVG,
            IJ_1,
            IJ_2,
            IJ_3,
            DG_AVG,
            DG_1,
            DG_2,
            DG_3,
            GS_AVG,
            GS_1,
            GS_2,
            GS_3,
        }

        private enum YELLD_BK_LIST
        {
            TYPE_DESC,
            UOM,
            SUM_YEAR,
            SUM_1Q,
            SUM_2Q,
            SUM_3Q,
            SUM_4Q,
            SUM_1M,
            SUM_2M,
            SUM_3M,
            SUM_4M,
            SUM_5M,
            SUM_6M,
            SUM_7M,
            SUM_8M,
            SUM_9M,
            SUM_10M,
            SUM_11M,
            SUM_12M,
        }

        private enum RES_BK_LIST
        {
            S_TYPE,
            S_TYPE_2,
            UOM,
            TOOL_TYPE,
            RES_NAME,
            SUM_YEAR,
            SUM_1Q,
            SUM_2Q,
            SUM_3Q,
            SUM_4Q,
            SUM_1M,
            SUM_2M,
            SUM_3M,
            SUM_4M,
            SUM_5M,
            SUM_6M,
            SUM_7M,
            SUM_8M,
            SUM_9M,
            SUM_10M,
            SUM_11M,
            SUM_12M,
        }



        private enum RES_YER_LIST
        {
            CHK,
            STD_YEAR,
            STD_YEAR_BUTTON,
            STD_TYPE_CODE,
            STD_TYPE,
            STD_TYPE_BUTTON,
            UOM,
            AREA_ID,
            AREA_ID_BUTTON,
            SUM_1Q,
            SUM_2Q,
            SUM_3Q,
            SUM_4Q,
            SUM_1M,
            SUM_2M,
            SUM_3M,
            SUM_4M,
            SUM_5M,
            SUM_6M,
            SUM_7M,
            SUM_8M,
            SUM_9M,
            SUM_10M,
            SUM_11M,
            SUM_12M,
            INSERT_TYPE,
        }



        private enum MOLD_INFO : int
        {
            CHK,
            TOOL_ID,
            MAT_ID,
            MAT_DESC,
            MOLD_MODEL,
            MOLD_TYPE,
            AREA_ID,
            AREA_DESC,
            OPER,
            OPER_DESC,
            BREAK_DATE,
            BREAK_YYYY,
            BREAK_MM,
            BREAK_DD,
            BREAK_WEEK,
            TOOL_KIND,
            TOOL_KIND_DESC,
            OCCUR_TIME,
            RES_ID,
            RES_DESC,
            CAR,
            HOGI_CAR,
            WORKER_ID,
            WORKER_DESC,
            TOP_BASE,
            TOP_BASE_DESC,
            USE_COUNT,
            ISSUE_COMMENT,
            ISSUE_TYPE,
            ISSUE_TYPE_DESC,
            BREAK_CAUSE,
            ACTION_COMMENT,
            BO_SEC,
            BREAK_PATTERN,
            BREAK_PATTERN_DESC,
            CROWN_NO,
            CARBIDE_LOT,
            SIZE_1,
            SIZE_2,
            SIZE_3,
            C_SCAN,
            C_SCAN_DESC,
            BREAK_TYPE,
            BREAK_TYPE_DESC,
            VENDOR_LOT_ID,
            MAT_TYPE,
            MAT_TYPE_DESC,
            GRADE,
            GRADE_DESC,
            BO_DIE_NO,
            D10_TYPE,
            D10_TYPE_DESC,
            D10_CREATE_TIME,
            D10_WEIGHT,
            D10_HEIGHT,
            M15_LOT_ID,
            M13_LOT_ID,
            REMARK,
            BK_TYPE,
        }

        #endregion

        #region " Variable Definition "
        int iTabIndex = 0;
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewBraBkList()
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
                //dvcArgu[1].sCondition_Value = cdvDept.Text;

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[1].sCondition_Value = "CTM";
                }
                else
                {
                    dvcArgu[1].sCondition_Value = cdvDept.Text;
                }



                dvcArgu[2].sCondition_ID = "ST_YYYY";
                dvcArgu[2].sCondition_Value = cdvYear.Text;



                dvcArgu[3].sCondition_ID = "BK_TYPE";

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[3].sCondition_Value = "RND";
                }
                else
                {
                    dvcArgu[3].sCondition_Value = "PROD";
                }



                if (TPDR.GetDataOne("", ref dt, "CRAS3008-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBraBkList);
                    return;
                }



                MPCF.ClearList(spdBraBkList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBraBkList.ActiveSheet.RowCount++;

                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.S_TYPE].Value = dt.Rows[i]["S_TYPE"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.RES_NAME].Value = dt.Rows[i]["RES_NAME"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.TOOL_TYPE].Value = dt.Rows[i]["TOOL_TYPE"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.TOTAL_AVG].Value = dt.Rows[i]["TOTAL_AVG"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.TOTAL_1].Value = dt.Rows[i]["TOTAL_1"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.TOTAL_2].Value = dt.Rows[i]["TOTAL_2"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.TOTAL_3].Value = dt.Rows[i]["TOTAL_3"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.IJ_AVG].Value = dt.Rows[i]["IJ_AVG"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.IJ_1].Value = dt.Rows[i]["IJ_1"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.IJ_2].Value = dt.Rows[i]["IJ_2"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.IJ_3].Value = dt.Rows[i]["IJ_3"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.DG_AVG].Value = dt.Rows[i]["DG_AVG"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.DG_1].Value = dt.Rows[i]["DG_1"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.DG_2].Value = dt.Rows[i]["DG_2"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.DG_3].Value = dt.Rows[i]["DG_3"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.GS_AVG].Value = dt.Rows[i]["GS_AVG"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.GS_1].Value = dt.Rows[i]["GS_1"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.GS_2].Value = dt.Rows[i]["GS_2"];
                    spdBraBkList.ActiveSheet.Cells[i, (int)BRAND_BK_LIST.GS_3].Value = dt.Rows[i]["GS_3"];

                }



                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.TOTAL_1).Value = Int32.Parse(cdvYear.Text) - 2 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.TOTAL_2).Value = Int32.Parse(cdvYear.Text) - 1 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.TOTAL_3).Value = cdvYear.Text + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.IJ_1).Value = Int32.Parse(cdvYear.Text) - 2 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.IJ_2).Value = Int32.Parse(cdvYear.Text) - 1 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.IJ_3).Value = cdvYear.Text + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.DG_1).Value = Int32.Parse(cdvYear.Text) - 2 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.DG_2).Value = Int32.Parse(cdvYear.Text) - 1 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.DG_3).Value = cdvYear.Text + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.GS_1).Value = Int32.Parse(cdvYear.Text) - 2 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.GS_2).Value = Int32.Parse(cdvYear.Text) - 1 + "년";
                spdBraBkList_Sheet1.ColumnHeader.Cells.Get(1, (int)BRAND_BK_LIST.GS_3).Value = cdvYear.Text + "년";


                //MPCF.FitColumnHeader(spdLotList);



                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void VieYeiBkList()
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
                /*
                
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                */

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[1].sCondition_Value = "CTM";
                }
                else
                {
                    dvcArgu[1].sCondition_Value = cdvDept.Text;
                }



                dvcArgu[2].sCondition_ID = "ST_YYYY";
                dvcArgu[2].sCondition_Value = cdvYear.Text;


                dvcArgu[3].sCondition_ID = "BK_TYPE";

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[3].sCondition_Value = "RND";
                }
                else
                {
                    dvcArgu[3].sCondition_Value = "PROD";
                }





                if (TPDR.GetDataOne("", ref dt, "CRAS3008-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdYeiBkList);
                    return;
                }

                MPCF.ClearList(spdYeiBkList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdYeiBkList.ActiveSheet.RowCount++;

                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.TYPE_DESC].Value = dt.Rows[i]["TYPE_DESC"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.UOM].Value = dt.Rows[i]["UOM"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_YEAR].Value = dt.Rows[i]["SUM_YEAR"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_1Q].Value = dt.Rows[i]["SUM_1Q"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_2Q].Value = dt.Rows[i]["SUM_2Q"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_3Q].Value = dt.Rows[i]["SUM_3Q"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_4Q].Value = dt.Rows[i]["SUM_4Q"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_1M].Value = dt.Rows[i]["SUM_1M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_2M].Value = dt.Rows[i]["SUM_2M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_3M].Value = dt.Rows[i]["SUM_3M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_4M].Value = dt.Rows[i]["SUM_4M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_5M].Value = dt.Rows[i]["SUM_5M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_6M].Value = dt.Rows[i]["SUM_6M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_7M].Value = dt.Rows[i]["SUM_7M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_8M].Value = dt.Rows[i]["SUM_8M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_9M].Value = dt.Rows[i]["SUM_9M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_10M].Value = dt.Rows[i]["SUM_10M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_11M].Value = dt.Rows[i]["SUM_11M"];
                    spdYeiBkList.ActiveSheet.Cells[i, (int)YELLD_BK_LIST.SUM_12M].Value = dt.Rows[i]["SUM_12M"];

                }
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_1M).Value = cdvYear.DisplayText + " 1월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_2M).Value = cdvYear.DisplayText + " 2월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_3M).Value = cdvYear.DisplayText + " 3월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_4M).Value = cdvYear.DisplayText + " 4월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_5M).Value = cdvYear.DisplayText + " 5월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_6M).Value = cdvYear.DisplayText + " 6월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_7M).Value = cdvYear.DisplayText + " 7월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_8M).Value = cdvYear.DisplayText + " 8월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_9M).Value = cdvYear.DisplayText + " 9월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_10M).Value = cdvYear.DisplayText + " 10월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_11M).Value = cdvYear.DisplayText + " 11월";
                spdYeiBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)YELLD_BK_LIST.SUM_12M).Value = cdvYear.DisplayText + " 12월";

                //MPCF.FitColumnHeader(spdwLotList);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void ViewResBkList()
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

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[1].sCondition_Value = "CTM";
                }
                else
                {
                    dvcArgu[1].sCondition_Value = cdvDept.Text;
                }



                dvcArgu[2].sCondition_ID = "ST_YYYY";
                dvcArgu[2].sCondition_Value = cdvYear.Text;


                dvcArgu[3].sCondition_ID = "BK_TYPE";

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[3].sCondition_Value = "RND";
                }
                else
                {
                    dvcArgu[3].sCondition_Value = "PROD";
                }


                if (TPDR.GetDataOne("", ref dt, "CRAS3008-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdResBkList);
                    return;
                }

                MPCF.ClearList(spdResBkList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdResBkList.ActiveSheet.RowCount++;

                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.S_TYPE].Value = dt.Rows[i]["S_TYPE"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.S_TYPE_2].Value = dt.Rows[i]["S_TYPE_2"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.UOM].Value = dt.Rows[i]["UOM"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.TOOL_TYPE].Value = dt.Rows[i]["TOOL_TYPE"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.RES_NAME].Value = dt.Rows[i]["RES_NAME"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.UOM].Value = dt.Rows[i]["UOM"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_YEAR].Value = dt.Rows[i]["SUM_YEAR"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_1Q].Value = dt.Rows[i]["SUM_1Q"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_2Q].Value = dt.Rows[i]["SUM_2Q"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_3Q].Value = dt.Rows[i]["SUM_3Q"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_4Q].Value = dt.Rows[i]["SUM_4Q"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_1M].Value = dt.Rows[i]["SUM_1M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_2M].Value = dt.Rows[i]["SUM_2M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_3M].Value = dt.Rows[i]["SUM_3M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_4M].Value = dt.Rows[i]["SUM_4M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_5M].Value = dt.Rows[i]["SUM_5M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_6M].Value = dt.Rows[i]["SUM_6M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_7M].Value = dt.Rows[i]["SUM_7M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_8M].Value = dt.Rows[i]["SUM_8M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_9M].Value = dt.Rows[i]["SUM_9M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_10M].Value = dt.Rows[i]["SUM_10M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_11M].Value = dt.Rows[i]["SUM_11M"];
                    spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.SUM_12M].Value = dt.Rows[i]["SUM_12M"];

                    if (spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.S_TYPE_2].Text == "목표")
                    {
                        spdResBkList.ActiveSheet.Rows[i].BackColor = Color.Gainsboro;
                    }
                    if (spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.S_TYPE_2].Text == "소계")
                    {
                        spdResBkList.ActiveSheet.Rows[i].BackColor = Color.WhiteSmoke;
                    }
                    if (spdResBkList.ActiveSheet.Cells[i, (int)RES_BK_LIST.S_TYPE_2].Text == "합계")
                    {
                        spdResBkList.ActiveSheet.Rows[i].BackColor = Color.WhiteSmoke;

                    }
                }



                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_1M).Value = cdvYear.DisplayText + " 1월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_2M).Value = cdvYear.DisplayText + " 2월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_3M).Value = cdvYear.DisplayText + " 3월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_4M).Value = cdvYear.DisplayText + " 4월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_5M).Value = cdvYear.DisplayText + " 5월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_6M).Value = cdvYear.DisplayText + " 6월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_7M).Value = cdvYear.DisplayText + " 7월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_8M).Value = cdvYear.DisplayText + " 8월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_9M).Value = cdvYear.DisplayText + " 9월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_10M).Value = cdvYear.DisplayText + " 10월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_11M).Value = cdvYear.DisplayText + " 11월";
                spdResBkList_Sheet1.ColumnHeader.Cells.Get(0, (int)RES_BK_LIST.SUM_12M).Value = cdvYear.DisplayText + " 12월";

                //MPCF.FitColumnHeader(spdwLotList);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private void ViewResNowList()
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;

                DataTable dt2 = null;
                string sSql = "";
                int i = 0;
                int iCol = 0;
                string sViewId = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[1].sCondition_Value = "CTM";
                }
                else
                {
                    dvcArgu[1].sCondition_Value = cdvDept.Text;
                }

                if (cdvDept.Text == "CTM")
                {
                    sViewId = "CRAS3008-004";
                }
                else if (cdvDept.Text == "GRT")
                {
                    sViewId = "CRAS3008-005";
                }
                else
                {
                    sViewId = "CRAS3008-004";

                }

                if (TPDR.GetDataOne("", ref dt, sViewId, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdResNowList);
                    return;
                }



                if (TPDR.GetDataOne("", ref dt2, "CRAS3008-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt2 != null)
                        dt2.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdResNowList);
                    return;
                }



                MPCF.ClearList(spdResNowList);


                spdResNowList_Sheet1.ColumnCount = 0;

                spdResNowList_Sheet1.ColumnCount = dt.Columns.Count;


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdResNowList.ActiveSheet.RowCount++;

                    for (iCol = 0; iCol < dt.Columns.Count; iCol++)
                    {
                        spdResNowList.ActiveSheet.Cells[i, iCol].Value = dt.Rows[i][iCol];
                    }


                }



                spdResNowList_Sheet1.ColumnHeader.Cells.Get(0, 0).Value = "Press";
                spdResNowList_Sheet1.Columns.Get(0).Width = 120F;
                spdResNowList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "단위";
                spdResNowList_Sheet1.Columns.Get(0).Width = 120F;
                spdResNowList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "평균(L-press)";
                spdResNowList_Sheet1.Columns.Get(1).Width = 120F;
                spdResNowList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "평균(B-press)";
                spdResNowList_Sheet1.Columns.Get(2).Width = 120F;
                spdResNowList_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "평균(G-press)";
                spdResNowList_Sheet1.Columns.Get(3).Width = 120F;

                for (iCol = 0; iCol < dt2.Rows.Count; iCol++)
                {
                    spdResNowList_Sheet1.ColumnHeader.Cells.Get(0, iCol + 5).Value = dt2.Rows[iCol][0];
                    spdResNowList_Sheet1.Columns.Get(iCol + 5).Width = 120F;
                }



                //MPCF.FitColumnHeader(spdwLotList);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void ViewYldStList()
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


                dvcArgu[2].sCondition_ID = "ST_YYYY";
                dvcArgu[2].sCondition_Value = cdvYear.Text;


                dvcArgu[3].sCondition_ID = "BK_TYPE";

                if (cdvDept.Text == "CRD") //CTM 사업부의 개발품을 사업부로 넣어달라고 해서 이렇게함...^^;
                {
                    dvcArgu[3].sCondition_Value = "RND";
                }
                else
                {
                    dvcArgu[3].sCondition_Value = "PROD";
                }

                if (TPDR.GetDataOne("", ref dt, "CRAS3008-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdResYerList);
                    return;
                }

                MPCF.ClearList(spdResYerList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdResYerList.ActiveSheet.RowCount++;

                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.STD_YEAR].Value = dt.Rows[i]["STD_YEAR"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.STD_TYPE_CODE].Value = dt.Rows[i]["STD_TYPE_CODE"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.STD_TYPE].Value = dt.Rows[i]["STD_TYPE"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.UOM].Value = dt.Rows[i]["UOM"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_1Q].Value = dt.Rows[i]["SUM_1Q"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_2Q].Value = dt.Rows[i]["SUM_2Q"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_3Q].Value = dt.Rows[i]["SUM_3Q"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_4Q].Value = dt.Rows[i]["SUM_4Q"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_1M].Value = dt.Rows[i]["SUM_1M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_2M].Value = dt.Rows[i]["SUM_2M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_3M].Value = dt.Rows[i]["SUM_3M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_4M].Value = dt.Rows[i]["SUM_4M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_5M].Value = dt.Rows[i]["SUM_5M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_6M].Value = dt.Rows[i]["SUM_6M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_7M].Value = dt.Rows[i]["SUM_7M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_8M].Value = dt.Rows[i]["SUM_8M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_9M].Value = dt.Rows[i]["SUM_9M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_10M].Value = dt.Rows[i]["SUM_10M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_11M].Value = dt.Rows[i]["SUM_11M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.SUM_12M].Value = dt.Rows[i]["SUM_12M"];
                    spdResYerList.ActiveSheet.Cells[i, (int)RES_YER_LIST.INSERT_TYPE].Value = "";

                }


                //MPCF.FitColumnHeader(spdwLotList);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private void ViewToolInfo()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;


                if (TPDR.GetDataOne("", ref dt, "CRAS3008-008", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdToolList);

                    return;
                }

                MPCF.ClearList(spdToolList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdToolList.ActiveSheet.RowCount++;

                    spdToolList.ActiveSheet.SetValue(i, (int)MOLD_INFO.CHK, false);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_MODEL].Value = dt.Rows[i]["MOLD_MODEL"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_TYPE].Value = dt.Rows[i]["MOLD_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["BREAK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_YYYY].Value = dt.Rows[i]["BREAK_YYYY"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_MM].Value = dt.Rows[i]["BREAK_MM"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_DD].Value = dt.Rows[i]["BREAK_DD"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_WEEK].Value = dt.Rows[i]["BREAK_WEEK"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_KIND].Value = dt.Rows[i]["TOOL_KIND"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_KIND_DESC].Value = dt.Rows[i]["TOOL_KIND_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OCCUR_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["OCCUR_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CAR].Value = dt.Rows[i]["CAR"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.HOGI_CAR].Value = dt.Rows[i]["HOGI_CAR"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOP_BASE].Value = dt.Rows[i]["TOP_BASE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOP_BASE_DESC].Value = dt.Rows[i]["TOP_BASE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.USE_COUNT].Value = dt.Rows[i]["USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ISSUE_COMMENT].Value = dt.Rows[i]["ISSUE_COMMENT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ISSUE_TYPE].Value = dt.Rows[i]["ISSUE_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ISSUE_TYPE_DESC].Value = dt.Rows[i]["ISSUE_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_CAUSE].Value = dt.Rows[i]["BREAK_CAUSE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ACTION_COMMENT].Value = dt.Rows[i]["ACTION_COMMENT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BO_SEC].Value = dt.Rows[i]["BO_TIME"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_PATTERN].Value = dt.Rows[i]["BREAK_PATTERN"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_PATTERN_DESC].Value = dt.Rows[i]["BREAK_PATTERN_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CROWN_NO].Value = dt.Rows[i]["CROWN_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CARBIDE_LOT].Value = dt.Rows[i]["CARBIDE_LOT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.SIZE_1].Value = dt.Rows[i]["SIZE_1"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.SIZE_2].Value = dt.Rows[i]["SIZE_2"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.SIZE_3].Value = dt.Rows[i]["SIZE_3"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.C_SCAN].Value = dt.Rows[i]["C_SCAN"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.C_SCAN_DESC].Value = dt.Rows[i]["C_SCAN_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_TYPE].Value = dt.Rows[i]["BREAK_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_TYPE_DESC].Value = dt.Rows[i]["BREAK_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_TYPE_DESC].Value = dt.Rows[i]["MAT_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.GRADE_DESC].Value = dt.Rows[i]["GRADE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BO_DIE_NO].Value = dt.Rows[i]["BO_DIE_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_TYPE].Value = dt.Rows[i]["D10_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_TYPE_DESC].Value = dt.Rows[i]["D10_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["D10_CREATE_TIME"].ToString(), DATE_TIME_FORMAT.TIME);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_WEIGHT].Value = dt.Rows[i]["D10_WEIGHT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_HEIGHT].Value = dt.Rows[i]["D10_HEIGHT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.M15_LOT_ID].Value = dt.Rows[i]["M15_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.M13_LOT_ID].Value = dt.Rows[i]["M13_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.REMARK].Value = dt.Rows[i]["REMARK"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BK_TYPE].Value = dt.Rows[i]["BK_TYPE"];

                }

                MPCF.FitColumnHeader(spdToolList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




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


                if (MPCF.Trim(cdvYear.Text) == "" && tbOperType.SelectedIndex != 4)
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblYear.Text + "]");
                    lblYear.Focus();
                    return false;
                }

                //if (MPCF.Trim(cdvOper.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                //    cdvOper.Focus();
                //    return false;
                //}

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

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

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":
                        break;

                    case "VIEW":
                        break;

                    case "AREA":

                        MPCF.ClearList(spdBraBkList);
                        MPCF.ClearList(spdYeiBkList);
                        MPCF.ClearList(spdResBkList);
                        MPCF.ClearList(spdResNowList);
                        MPCF.ClearList(spdResYerList);
                        MPCF.ClearList(spdToolList);

                        break;

                    case "SUB_AREA":

                        break;

                    case "OPER":


                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ViewPrintShipLabel(string sFileName, TRSNode in_node)
        {
            try
            {
                if (string.IsNullOrEmpty(sFileName))
                {
                    //라벨 파일 조회
                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                    DataTable dt = null;
                    string sSql = "";

                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "KEY_1";
                    dvcArgu[1].sCondition_Value = cdvDept.Text;

                    if (TPDR.GetDataOne("", ref dt, "CSHP2001-010", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();
                        return false;
                    }

                    sFileName = dt.Rows[0]["KEY_2"].ToString();
                }

                CSCF.ViewLabelList(sFileName, in_node, 'E');

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private DataTable GetOperInfo(string sOper)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CWIP3007-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                return dt;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        public static string ShowFileOpenDialogs(string sFileName)
        {
            try
            {
                //파일오픈창 생성 및 설정
                SaveFileDialog sfd = new SaveFileDialog();
                sfd.Title = "파일 위치 지정";
                sfd.FileName = MPCF.Trim(sFileName.Replace(" ", "_")) + "_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".xls";
                sfd.Filter = "엑셀 파일 (*.xls, *.xlsx) | *.xls; *.xlsx | 모든 파일 (*.*) | *.*";

                //파일 오픈창 로드
                DialogResult dr = sfd.ShowDialog();

                //OK버튼 클릭시
                if (dr == DialogResult.OK)
                {
                    //File 명과 확장자를 가지고 온다.
                    //string fileName = ofd.SafeFileName;
                    //File 경로와 File 명을 모두 가지고 온다.
                    string fileFullName = sfd.FileName;
                    //File 경로만 가지고 온다.
                    //string filePath = fileFullName.Replace(fileName, "");

                    return fileFullName;
                }
                //취소버튼 클릭시 또는 ESC키로 파일창을 종료 했을경우
                else if (dr == DialogResult.Cancel)
                {
                    return string.Empty;
                }

                return string.Empty;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return string.Empty;
            }
        }

        private bool InsertBkData()
        {
            try
            {
                TRSNode in_node = new TRSNode("Tool_Code_In");
                TRSNode out_node = new TRSNode("Tool_Code_Out");
                TRSNode tool_list;

                int iRowNum = 0;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                {
                    if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        tool_list = in_node.AddNode("TOOL_TBL");
                        tool_list.AddString("TOOL_ID", spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_ID].Text);


                        tool_list.AddString("AREA_ID", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.AREA_ID].Text);
                        tool_list.AddString("OPER", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.OPER].Text);
                        tool_list.AddString("MAT_ID", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.MAT_ID].Text);


                        tool_list.AddString("BREAK_DATE", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BREAK_DATE].Text.Replace("-", "").Replace(":", ""));
                        tool_list.AddString("OCCUR_TIME", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.OCCUR_TIME].Text.Replace("-", "").Replace(":", ""));
                        tool_list.AddString("TOOL_KIND", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.TOOL_KIND].Text);
                        tool_list.AddString("WORKER_ID", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.WORKER_ID].Text);
                        tool_list.AddString("ISSUE_TYPE", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.ISSUE_TYPE].Text);
                        tool_list.AddString("ISSUE_COMMENT", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.ISSUE_COMMENT].Text);
                        tool_list.AddString("BREAK_CAUSE", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BREAK_CAUSE].Text);
                        tool_list.AddString("ACTION_COMMENT", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.ACTION_COMMENT].Text);
                        tool_list.AddString("BO_TIME", "");
                        tool_list.AddString("BREAK_PATTERN", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BREAK_PATTERN].Text);
                        tool_list.AddString("CROWN_NO", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.CROWN_NO].Text);
                        tool_list.AddString("CARBIDE_LOT", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.CARBIDE_LOT].Text);
                        tool_list.AddDouble("SIZE_1", MPCF.ToDbl(spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.SIZE_1].Text));
                        tool_list.AddDouble("SIZE_2", MPCF.ToDbl(spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.SIZE_2].Text));
                        tool_list.AddDouble("SIZE_3", MPCF.ToDbl(spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.SIZE_3].Text));
                        tool_list.AddString("C_SCAN", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.C_SCAN].Text);
                        tool_list.AddString("BREAK_TYPE", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BREAK_TYPE].Text);
                        tool_list.AddString("MAT_TYPE", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.MAT_TYPE].Text);
                        tool_list.AddString("GRADE", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.GRADE].Text);
                        tool_list.AddString("BO_DIE_NO", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BO_DIE_NO].Text);
                        tool_list.AddString("D10_TYPE", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.D10_TYPE].Text);
                        tool_list.AddString("D10_CREATE_TIME", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.D10_TYPE].Text.Replace("-", "").Replace(":", "") + "000000");
                        tool_list.AddDouble("D10_WEIGHT", MPCF.ToDbl(spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.D10_WEIGHT].Text));
                        tool_list.AddDouble("D10_HEIGHT", MPCF.ToDbl(spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.D10_HEIGHT].Text));
                        tool_list.AddString("M15_LOT_ID", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.M15_LOT_ID].Text);
                        tool_list.AddString("M13_LOT_ID", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.M13_LOT_ID].Text);
                        tool_list.AddString("REMARK", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.REMARK].Text);
                        tool_list.AddString("CMF_1", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BK_TYPE].Text);


                        tool_list.AddString("VENDOR_LOT_ID", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.VENDOR_LOT_ID].Text);
                        tool_list.AddString("LIMIT_COUNT", "");
                        tool_list.AddString("USE_COUNT", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.USE_COUNT].Text);
                        tool_list.AddString("ALAM_COUNT", "");



                    }
                }



                //일단 입력 안하면  PROD 값 양산으로
                if (spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BK_TYPE].Text == "")
                {
                    in_node.AddString("CMF_1", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BK_TYPE].Text);
                }
                else
                {
                    in_node.AddString("CMF_1", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BK_TYPE].Text);
                }


                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Mold_Break_Registration", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool DeleteBkData()
        {
            try
            {
                TRSNode in_node = new TRSNode("Tool_Code_In");
                TRSNode out_node = new TRSNode("Tool_Code_Out");
                TRSNode tool_list;

                int iRowNum = 0;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '4';
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                {
                    if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        tool_list = in_node.AddNode("TOOL_TBL");
                        tool_list.AddString("TOOL_ID", spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_ID].Text);

                    }
                }



                //일단 입력 안하면  PROD 값 양산으로
                if (spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BK_TYPE].Text == "")
                {
                    in_node.AddString("CMF_1", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BK_TYPE].Text);
                }
                else
                {
                    in_node.AddString("CMF_1", spdToolList.ActiveSheet.Cells[iRowNum, (int)MOLD_INFO.BK_TYPE].Text);
                }


                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Mold_Break_Registration", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool InsertYeildSt()
        {
            TRSNode in_node = new TRSNode("create_in");
            TRSNode out_node = new TRSNode("create_out");
            TRSNode Std_list;
            bool send_flag = false;
            string scmf2 = "";
            string scmf3 = "";
            try
            {

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                for (int i = 0; i < spdResYerList_Sheet1.RowCount; i++)
                {
                    if (spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.CHK].Text.ToString().ToUpper() == "TRUE")
                    {

                        Std_list = in_node.AddNode("YEILD_LIST");
                        Std_list.AddString("STD_YEAR", spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.STD_YEAR].Text);

                        Std_list.AddInt("STD_TYPE", MPCF.ToInt(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.STD_TYPE_CODE].Text));
                        // Std_list.AddString("STD_TYPE_DESC", spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.STD_TYPE].Text);
                        Std_list.AddString("STD_TYPE_DESC", " ");
                        Std_list.AddString("AREA_ID", spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.AREA_ID].Text);


                        Std_list.AddDouble("QTR_01", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_1Q].Text));
                        Std_list.AddDouble("QTR_02", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_2Q].Text));
                        Std_list.AddDouble("QTR_03", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_3Q].Text));
                        Std_list.AddDouble("QTR_04", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_4Q].Text));

                        Std_list.AddDouble("MTH_01", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_1M].Text));
                        Std_list.AddDouble("MTH_02", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_2M].Text));
                        Std_list.AddDouble("MTH_03", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_3M].Text));
                        Std_list.AddDouble("MTH_04", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_4M].Text));

                        Std_list.AddDouble("MTH_05", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_5M].Text));
                        Std_list.AddDouble("MTH_06", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_6M].Text));
                        Std_list.AddDouble("MTH_07", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_7M].Text));
                        Std_list.AddDouble("MTH_08", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_8M].Text));

                        Std_list.AddDouble("MTH_09", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_9M].Text));
                        Std_list.AddDouble("MTH_10", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_10M].Text));
                        Std_list.AddDouble("MTH_11", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_11M].Text));
                        Std_list.AddDouble("MTH_12", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_12M].Text));



                        switch (spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.STD_TYPE_CODE].Text)
                        {

                            case "5":
                                scmf2 = "L-press 전체";
                                scmf3 = "ANVIL";
                                break;

                            case "6":
                                scmf2 = "B-press 전체";
                                scmf3 = "ANVIL";
                                break;

                            case "7":
                                scmf2 = "G-press 전체";
                                scmf3 = "ANVIL";
                                break;

                            case "8":
                                scmf2 = "L-press 전체";
                                scmf3 = "DIE";
                                break;

                            case "9":
                                scmf2 = "B-press 전체";
                                scmf3 = "DIE";
                                break;

                            case "10":
                                scmf2 = "G-press 전체";
                                scmf3 = "DIE";
                                break;
                        }

                        Std_list.AddString("CMF_2", scmf2);
                        Std_list.AddString("CMF_3", scmf3);



                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_ras_yield_st", in_node, ref out_node) == false)
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
        private bool DeleteYeildSt()
        {
            TRSNode in_node = new TRSNode("etc_in_InvLot_In");
            TRSNode out_node = new TRSNode("etc_in_InvLot_Out");
            TRSNode Std_list;
            bool send_flag = false;

            try
            {

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                for (int i = 0; i < spdResYerList_Sheet1.RowCount; i++)
                {
                    if (spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        Std_list = in_node.AddNode("YEILD_LIST");
                        Std_list.AddString("STD_YEAR", spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.STD_YEAR].Text);

                        Std_list.AddInt("STD_TYPE", MPCF.ToInt(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.STD_TYPE_CODE].Text));
                        Std_list.AddString("STD_TYPE_DESC", spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.STD_TYPE].Text);
                        Std_list.AddString("AREA_ID", spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.AREA_ID].Text);


                        Std_list.AddDouble("QTR_01", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_1Q].Text));
                        Std_list.AddDouble("QTR_02", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_2Q].Text));
                        Std_list.AddDouble("QTR_03", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_3Q].Text));
                        Std_list.AddDouble("QTR_04", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_4Q].Text));

                        Std_list.AddDouble("MTH_01", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_1M].Text));
                        Std_list.AddDouble("MTH_02", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_2M].Text));
                        Std_list.AddDouble("MTH_03", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_3M].Text));
                        Std_list.AddDouble("MTH_04", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_4M].Text));

                        Std_list.AddDouble("MTH_05", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_5M].Text));
                        Std_list.AddDouble("MTH_06", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_6M].Text));
                        Std_list.AddDouble("MTH_07", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_7M].Text));
                        Std_list.AddDouble("MTH_08", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_8M].Text));

                        Std_list.AddDouble("MTH_09", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_9M].Text));
                        Std_list.AddDouble("MTH_10", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_10M].Text));
                        Std_list.AddDouble("MTH_11", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_11M].Text));
                        Std_list.AddDouble("MTH_12", MPCF.ToDbl(spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.SUM_12M].Text));


                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    // MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_ras_yield_st", in_node, ref out_node) == false)
                {
                    return false;
                }


                MPCR.ShowSuccessMsg(out_node);



                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool viewYearList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT TO_CHAR(SYSDATE,'YYYY')-LEVEL+1 AS CODE, TO_CHAR(SYSDATE,'YYYY')-LEVEL+1 ||'년' AS VALUE  "
                                                + "   FROM DUAL CONNECT BY LEVEL <= ((TO_CHAR(SYSDATE,'YYYY')+1)-2015) ");


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
        private bool viewAreaList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT 'CTM' AS CODE, 'CTM' AS VALUE FROM DUAL UNION ALL "
                + "   SELECT 'CRD' AS CODE, 'CTM(RND)' AS VALUE FROM DUAL   UNION ALL "
            + "   SELECT 'GRT' AS CODE, 'GRT' AS VALUE FROM DUAL  ");


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
        private bool viewStdList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            //  in_node.AddString("SQL", " SELECT KEY_1 AS CODE, DATA_1 AS VALUE FROM MGCMTBLDAT WHERE TABLE_NAME = 'C_MOLD_YEAR_STD'");


            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, DATA_1 AS VALUE FROM MGCMTBLDAT WHERE TABLE_NAME = 'C_MOLD_YEAR_STD' ORDER BY TO_NUMBER(KEY_1) ");



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
        #endregion

        #region " Event Definition "

        private void frmViewMoldYieldTotal_Load(object sender, EventArgs e)
        {
            try
            {
                iTabIndex = 0;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                /*
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

                //특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvDept.Tag) != "")
                {
                    for (int i = cdvDept.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvDept.GetListView.Items[i - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                        {
                            cdvDept.GetListView.Items[i - 1].Remove();
                        }
                    }
                }
                */

                viewAreaList(cdvDept.GetListView);
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
                ClearData("AREA");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdwLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void tbOperType_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {


                switch (tbOperType.SelectedIndex)
                {
                    case 0:
                        iTabIndex = 0;
                        btnSave.Visible = false;
                        btnDelete.Visible = false;
                        break;
                    case 1:
                        iTabIndex = 1;
                        btnSave.Visible = false;
                        btnDelete.Visible = false;
                        break;
                    case 2:
                        iTabIndex = 2;
                        btnSave.Visible = false;
                        btnDelete.Visible = false;
                        break;
                    case 3:
                        iTabIndex = 3;
                        btnSave.Visible = false;
                        btnDelete.Visible = false;
                        break;
                    case 4:
                        iTabIndex = 4;
                        btnSave.Visible = true;
                        btnDelete.Visible = false;
                        break;
                    case 5:
                        iTabIndex = 5;
                        btnSave.Visible = true;
                        btnDelete.Visible = true;
                        break;
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                {
                    return;
                }

                if (chkAllSearch.Checked == true)
                {
                    ViewBraBkList();
                    VieYeiBkList();
                    ViewResBkList();
                    ViewResNowList();
                    ViewYldStList();
                    ViewToolInfo();
                }
                else
                {
                    switch (tbOperType.SelectedIndex)
                    {
                        case 0:
                            ViewBraBkList();
                            break;
                        case 1:
                            VieYeiBkList();
                            break;
                        case 2:
                            ViewResBkList();
                            break;
                        case 3:
                            ViewResNowList();
                            break;
                        case 4:
                            ViewYldStList();
                            break;
                        case 5:
                            ViewToolInfo();
                            break;
                    }
                }


                tbOperType.SelectedIndex = iTabIndex;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                /*
                string sFileName = string.Empty;

                if (tbOperType.SelectedIndex == 0)
                {
                  //  sFileName = string.IsNullOrEmpty(cdvOper.DisplayText) ? "Operation" : cdvOper.DisplayText;
                  
                    EXTFUC.SaveExcel(spdBraBkList, sFileName);
                }
                else
                {
                   // sFileName = string.IsNullOrEmpty(cdvOper.DisplayText) ? "Warehouse" : cdvOper.DisplayText;
                    EXTFUC.SaveExcel(spdYeiBkList, sFileName);
                }          
                */

                if (MPCF.ShowMsgBox("레포트 전체를 출력하시겠습니까?", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {


                    switch (tbOperType.SelectedIndex)
                    {
                        case 0:
                            EXTFUC.SaveExcel(spdBraBkList, tabPage1.Text);
                            break;
                        case 1:
                            EXTFUC.SaveExcel(spdYeiBkList, tabPage2.Text);
                            break;
                        case 2:
                            EXTFUC.SaveExcel(spdResBkList, tabPage3.Text);
                            break;
                        case 3:
                            EXTFUC.SaveExcel(spdResNowList, tabPage4.Text);
                            break;
                        case 4:
                            EXTFUC.SaveExcel(spdResYerList, tabPage5.Text);
                            break;
                        case 5:
                            EXTFUC.SaveExcel(spdToolList, tabPage6.Text);
                            break;
                    }



                }
                else
                {
                    FpSpread excelSp = new FpSpread();
                    SheetView sheet1 = new SheetView();
                    SheetView sheet2 = new SheetView();
                    SheetView sheet3 = new SheetView();
                    SheetView sheet4 = new SheetView();
                    SheetView sheet5 = new SheetView();
                    SheetView sheet6 = new SheetView();

                    string sFileName = ShowFileOpenDialogs("Report");


                    //.xlsx
                    if (String.IsNullOrEmpty(sFileName))
                    {
                        return;
                    }


                    sheet1 = spdBraBkList_Sheet1;
                    sheet1.SheetName = tabPage1.Text;  //string.IsNullOrEmpty(cdvOper.DisplayText) ? "Sheet1" : cdvOper.DisplayText;
                    sheet1.ColumnCount = spdBraBkList_Sheet1.ColumnCount;
                    sheet1.RowCount = spdBraBkList_Sheet1.RowCount;
                    sheet1.Protect = false;
                    excelSp.Sheets.Add(sheet1);
                    //  excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);

                    sFileName.Replace("xlsx", "xls");


                    sheet2 = spdYeiBkList_Sheet1;
                    sheet2.SheetName = tabPage2.Text;  //string.IsNullOrEmpty(cdvOper.DisplayText) ? "Sheet1" : cdvOper.DisplayText;
                    sheet2.ColumnCount = spdYeiBkList_Sheet1.ColumnCount;
                    sheet2.RowCount = spdYeiBkList_Sheet1.RowCount;
                    sheet2.Protect = false;
                    excelSp.Sheets.Add(sheet2);
                    excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);


                    sheet3 = spdResBkList_Sheet1;
                    sheet3.SheetName = tabPage3.Text;  //string.IsNullOrEmpty(cdvOper.DisplayText) ? "Sheet1" : cdvOper.DisplayText;
                    sheet3.ColumnCount = spdResBkList_Sheet1.ColumnCount;
                    sheet3.RowCount = spdResBkList_Sheet1.RowCount;
                    sheet3.Protect = false;
                    excelSp.Sheets.Add(sheet3);
                    excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);








                    sheet4 = spdResNowList_Sheet1;
                    sheet4.SheetName = tabPage4.Text;  //string.IsNullOrEmpty(cdvOper.DisplayText) ? "Sheet1" : cdvOper.DisplayText;
                    sheet4.ColumnCount = spdResNowList_Sheet1.ColumnCount;
                    sheet4.RowCount = spdResNowList_Sheet1.RowCount;
                    sheet4.Protect = false;
                    excelSp.Sheets.Add(sheet4);
                    excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);



                    sheet5 = spdResYerList_Sheet1;
                    sheet5.SheetName = tabPage5.Text;  //string.IsNullOrEmpty(cdvOper.DisplayText) ? "Sheet1" : cdvOper.DisplayText;
                    sheet5.ColumnCount = spdResYerList_Sheet1.ColumnCount;
                    sheet5.RowCount = spdResYerList_Sheet1.RowCount;
                    sheet5.Protect = false;
                    excelSp.Sheets.Add(sheet5);
                    excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);


                    sheet6 = spdToolList_Sheet1;
                    sheet6.SheetName = tabPage6.Text;  //string.IsNullOrEmpty(cdvOper.DisplayText) ? "Sheet1" : cdvOper.DisplayText;
                    sheet6.ColumnCount = spdToolList_Sheet1.ColumnCount;
                    sheet6.RowCount = spdToolList_Sheet1.RowCount;
                    sheet6.Protect = false;
                    excelSp.Sheets.Add(sheet6);
                    excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);

                    System.Diagnostics.Process.Start(sFileName);

                    sheet1.Protect = true;
                }


            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void spdLotList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {

        }
        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
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
        private void spdwLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void fpSpread1_CellClick(object sender, CellClickEventArgs e)
        {

        }
        private void cdvYear_ButtonPress(object sender, EventArgs e)
        {

            viewYearList(cdvYear.GetListView);
            cdvYear.InsertEmptyRow(0, 1);


        }
        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                SheetView sv = spdResYerList_Sheet1;
                int iRow = sv.RowCount++;


                spdResYerList_Sheet1.Cells[iRow, (int)RES_YER_LIST.INSERT_TYPE].Text = "N";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void btnRowDel_Click(object sender, EventArgs e)
        {
            SheetView sv = spdResYerList.ActiveSheet;

            try
            {
                for (int i = sv.RowCount - 1; i >= 0; i--)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)RES_YER_LIST.CHK] == null ? false : sv.Cells[i, (int)RES_YER_LIST.CHK].Value))
                    {
                        if (spdResYerList_Sheet1.Cells[i, (int)RES_YER_LIST.INSERT_TYPE].Text == "N")
                        {
                            sv.RemoveRows(i, 1);
                        }
                    }
                }

                DeleteYeildSt();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdResYerList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                SheetView sv = spdResYerList.ActiveSheet;


                cdvGridButton.Init();
                MPCF.InitListView(cdvGridButton.GetListView);
                cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                if (e.Column == (int)RES_YER_LIST.STD_YEAR_BUTTON)
                {

                    viewYearList(cdvGridButton.GetListView);


                }

                switch (e.Column)
                {
                    case (int)RES_YER_LIST.STD_YEAR_BUTTON:
                        viewYearList(cdvGridButton.GetListView);
                        cdvGridButton.ShowPopupList(e.Row, e.Column);
                        break;
                    case (int)RES_YER_LIST.AREA_ID_BUTTON:
                        viewAreaList(cdvGridButton.GetListView);
                        cdvGridButton.ShowPopupList(e.Row, e.Column);
                        break;
                    case (int)RES_YER_LIST.STD_TYPE_BUTTON:
                        viewStdList(cdvGridButton.GetListView);
                        cdvGridButton.ShowPopupList(e.Row, e.Column);
                        break;
                }




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            SheetView sv = spdResYerList.ActiveSheet;
            try
            {


                switch (sv.ActiveColumnIndex)
                {
                    case (int)RES_YER_LIST.STD_YEAR_BUTTON:
                        sv.SetValue(e.Row, (int)RES_YER_LIST.STD_YEAR, e.SelectedItem.SubItems[0].Text);
                        break;
                    case (int)RES_YER_LIST.AREA_ID_BUTTON:
                        sv.SetValue(e.Row, (int)RES_YER_LIST.AREA_ID, e.SelectedItem.SubItems[0].Text);
                        break;
                    case (int)RES_YER_LIST.STD_TYPE_BUTTON:
                        sv.SetValue(e.Row, (int)RES_YER_LIST.STD_TYPE_CODE, e.SelectedItem.SubItems[0].Text);
                        sv.SetValue(e.Row, (int)RES_YER_LIST.STD_TYPE, e.SelectedItem.SubItems[1].Text);
                        break;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdResYerList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdResYerList_Sheet1.ActiveColumnIndex != 0)
                spdResYerList_Sheet1.Cells[spdResYerList_Sheet1.ActiveRowIndex, (int)RES_YER_LIST.CHK].Value = true;
        }
        private void btnSave_Click(object sender, EventArgs e)
        {

            switch (iTabIndex)
            {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    InsertYeildSt();
                    break;
                case 5:
                    InsertBkData();
                    break;
            }

        }
        private void btnDelete_Click(object sender, EventArgs e)
        {
            switch (iTabIndex)
            {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    DeleteBkData();
                    break;
            }
        }

        #endregion


    }
}
