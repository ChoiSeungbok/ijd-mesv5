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

using System.Data.SqlClient;
using FarPoint.Excel;
using System.Collections;

namespace CUS_RAS
{
    public partial class frmViewCTMFurnaceData : CUS_COM.frmViewForm03
    {
        public frmViewCTMFurnaceData()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum RAS_INFO : int
        {
            RES_ID,
            RES_DESC,
            WORK_DATE,
            WORK_TIME,
            SV_TEMP,
            PV_TEMP,
            VACCUM_PV1,
            VACCUM_PV2,
            THROTTLE_SV,
            THROTTLE_PV,
            THROTTLE_OUT,
            LOT_ID,
            MAT_ID,
            MAT_DESC,
            RES_STATUS
            //START_TIME,
            //END_TIME
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        public static SqlConnection sql_conn = new SqlConnection();
        public static int h_i;

        public static string sqldb = "Data Source=197.200.54.18;Initial Catalog=ILJIN;User ID=sa;Password=iljin;MultipleActiveResultsets=true";
        public static System.Text.Encoding encoding = System.Text.Encoding.GetEncoding(949);

        public static void sql_open()
        {
            sql_conn.ConnectionString = sqldb;
            sql_conn.Open();
        }

        public static void sql_close()
        {
            if (sql_conn.State == ConnectionState.Open)
            {
                sql_conn.Close();
            }
        }


        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static bool ViewOper(Control control, string sArea_ID)
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

                if (TPDR.GetDataOne("", ref dt, "CRAS3010-000", dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["OPER"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["OPER_DESC"].ToString());
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

        private void ViewFurnaceData()
        {
            int i = 0;
            string sSql = "";
            string sViewID = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;

                if (rdoDate.Checked)
                    sViewID = "CRAS3010-001";
                else
                    sViewID = "CRAS3010-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[2].sCondition_ID = "RES_ID";
                dvcArgu[2].sCondition_Value = cdvResId.Text + "%";

                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdFurnace);

                    return;
                }

                MPCF.ClearList(spdFurnace);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdFurnace.ActiveSheet.RowCount++;

                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.WORK_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.SV_TEMP].Value = dt.Rows[i]["SV_TEMP"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.PV_TEMP].Value = dt.Rows[i]["PV_TEMP"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.VACCUM_PV1].Value = dt.Rows[i]["VACCUM_PV1"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.VACCUM_PV2].Value = dt.Rows[i]["VACCUM_PV2"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.THROTTLE_SV].Value = dt.Rows[i]["THROTTLE_SV"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.THROTTLE_PV].Value = dt.Rows[i]["THROTTLE_PV"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.THROTTLE_OUT].Value = dt.Rows[i]["THROTTLE_OUT"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdFurnace.ActiveSheet.Cells[i, (int)RAS_INFO.RES_STATUS].Value = dt.Rows[i]["RES_STATUS"];
                }

                MPCF.FitColumnHeader(spdFurnace);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void ViewFurnaceData_2()
        {



            string sql;
            int iRows;
            SqlDataReader select_rs;
            string start_time, end_time;
            SqlCommand cmd;


            if (sql_conn.State != ConnectionState.Open)
            {
                sql_conn.Close();
                sql_open();
            }

            try
            {
                start_time = string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text;
                end_time = dtpToDate.Text;

                if (cdvResId.Text == "E1000025")
                {
                    sql = "  WITH InitialData AS ( " +
                    " SELECT  'E000025'  AS RES_ID, " +
                    "        'CTM_Dewaxing #1' AS RES_DESC, " +
                    "        1 AS HIST_SEQ, " +
                    "        cre_date as WORK_TIME,  " +
                    "        CONVERT(VARCHAR(10), cre_date, 120) AS WORK_DATE,  " +
                    "        TEMP_SV  AS SV_TEMP, " +
                    "        TEMP_PV  AS PV_TEMP, " +
                    "        VACCUM_PV1, " +
                    "        VACCUM_PV2, " +
                    "        0 AS THROTTLE_SV, " +
                    "        0 as THROTTLE_PV, " +
                    "        0 AS THROTTLE_OUT, " +
                    "        TEMP_OP AS RES_STATUS, " +
                    "        ' ' as START_TIME, " +
                    "        ' ' as END_TIME, " +
                    "        ' ' AS LOT_ID,  " +
                    "        ' ' AS MAT_ID,  " +
                    "        ' ' AS MAT_DESC " +
                    "   FROM dbo.DEWAXING_1  " +
                    "     WHERE YEAR(cre_date) >= YEAR('" + start_time + "') " +
                    " ), " +
                    " FirstTimestamp AS ( " +
                    "     SELECT MIN(WORK_TIME) AS FirstTime " +
                    "     FROM InitialData " +
                    " ), " +
                    " GroupedData AS ( " +
                    "     SELECT  " +
                    "         D.*,     " +
                    "         DATEDIFF(MINUTE, F.FirstTime, D.WORK_TIME) / 3 AS TimeGroup    " +
                    "     FROM InitialData D " +
                    "     CROSS JOIN FirstTimestamp F " +
                    " ), " +
                    " FilteredData AS ( " +
                    "     SELECT  " +
                    "         *,              " +
                    "         ROW_NUMBER() OVER (PARTITION BY TimeGroup ORDER BY WORK_TIME) AS RowNum      " +
                    "     FROM GroupedData " +
                    " ) " +
                    " SELECT RES_ID, " +
                    "        RES_DESC, " +
                    "        HIST_SEQ, " +
                    "        CONVERT(VARCHAR, WORK_TIME, 120) as WORK_TIME,  " +
                    "        WORK_DATE,  " +
                    "        SV_TEMP, " +
                    "        PV_TEMP, " +
                    "        VACCUM_PV1, " +
                    "        VACCUM_PV2, " +
                    "        THROTTLE_SV, " +
                    "        THROTTLE_PV, " +
                    "        THROTTLE_OUT, " +
                    "        RES_STATUS, " +
                    "        START_TIME, " +
                    "        END_TIME, " +
                    "        LOT_ID,  " +
                    "        MAT_ID,  " +
                    "        MAT_DESC " +
                    " FROM FilteredData " +
                    " WHERE RowNum = 1 " +
                      " AND  WORK_DATE >= '" + start_time + "'" +
                      " AND WORK_DATE <= '" + end_time + "'" +
                    " ORDER BY CONVERT(VARCHAR, WORK_TIME, 120);  ";
                }
                else if (cdvResId.Text == "E1000026")
                {

                    sql = "  WITH InitialData AS ( " +
                    " SELECT  'E000026'  AS RES_ID, " +
                    "        'CTM_Dewaxing #2' AS RES_DESC, " +
                    "        1 AS HIST_SEQ, " +
                    "        cre_date as WORK_TIME,  " +
                    "        CONVERT(VARCHAR(10), cre_date, 120) AS WORK_DATE,  " +
                    "        TEMP_SV  AS SV_TEMP, " +
                    "        TEMP_PV  AS PV_TEMP, " +
                    "        VACCUM_PV1, " +
                    "        VACCUM_PV2, " +
                    "        0 AS THROTTLE_SV, " +
                    "        0 as THROTTLE_PV, " +
                    "        0 AS THROTTLE_OUT, " +
                    "        TEMP_OP AS RES_STATUS, " +
                    "        ' ' as START_TIME, " +
                    "        ' ' as END_TIME, " +
                    "        ' ' AS LOT_ID,  " +
                    "        ' ' AS MAT_ID,  " +
                    "        ' ' AS MAT_DESC " +
                    "   FROM dbo.DEWAXING_2  " +
                    "     WHERE YEAR(cre_date) >= YEAR('" + start_time + "') " +
                    " ), " +
                    " FirstTimestamp AS ( " +
                    "     SELECT MIN(WORK_TIME) AS FirstTime " +
                    "     FROM InitialData " +
                    " ), " +
                    " GroupedData AS ( " +
                    "     SELECT  " +
                    "         D.*,     " +
                    "         DATEDIFF(MINUTE, F.FirstTime, D.WORK_TIME) / 3 AS TimeGroup    " +
                    "     FROM InitialData D " +
                    "     CROSS JOIN FirstTimestamp F " +
                    " ), " +
                    " FilteredData AS ( " +
                    "     SELECT  " +
                    "         *,              " +
                    "         ROW_NUMBER() OVER (PARTITION BY TimeGroup ORDER BY WORK_TIME) AS RowNum      " +
                    "     FROM GroupedData " +
                    " ) " +
                    " SELECT RES_ID, " +
                    "        RES_DESC, " +
                    "        HIST_SEQ, " +
                    "        WORK_TIME,  " +
                    "       CONVERT(VARCHAR, WORK_TIME, 120) as  WORK_DATE,  " +
                    "        SV_TEMP, " +
                    "        PV_TEMP, " +
                    "        VACCUM_PV1, " +
                    "        VACCUM_PV2, " +
                    "        THROTTLE_SV, " +
                    "        THROTTLE_PV, " +
                    "        THROTTLE_OUT, " +
                    "        RES_STATUS, " +
                    "        START_TIME, " +
                    "        END_TIME, " +
                    "        LOT_ID,  " +
                    "        MAT_ID,  " +
                    "        MAT_DESC " +
                    " FROM FilteredData " +
                    " WHERE RowNum = 1 " +
                      " AND  WORK_DATE >= '" + start_time + "'" +
                      " AND WORK_DATE <= '" + end_time + "'" +
                    " ORDER BY CONVERT(VARCHAR, WORK_TIME, 120);  ";

                }
                else if (cdvResId.Text == "E1000027")
                {

                    sql = "  WITH InitialData AS ( " +
                            " SELECT  'E000027'  AS RES_ID, " +
                            "        'CTM_Dewaxing #3' AS RES_DESC, " +
                            "        1 AS HIST_SEQ, " +
                            "        cre_date as WORK_TIME,  " +
                            "        CONVERT(VARCHAR(10), cre_date, 120) AS WORK_DATE,  " +
                            "        TEMP_SV  AS SV_TEMP, " +
                            "        TEMP_PV  AS PV_TEMP, " +
                            "        VACCUM_PV1, " +
                            "        0  AS VACCUM_PV2, " +
                            "        THROTTLE_SV, " +
                            "         THROTTLE_PV, " +
                            "        THROTTLE_OUT, " +
                            "        MODE_OP AS RES_STATUS, " +
                            "        ' ' as START_TIME, " +
                            "        ' ' as END_TIME, " +
                            "        ' ' AS LOT_ID,  " +
                            "        ' ' AS MAT_ID,  " +
                            "        ' ' AS MAT_DESC " +
                            "   FROM dbo.DEWAXING_3 " +
                    "     WHERE YEAR(cre_date) >= YEAR('" + start_time + "') " +
                    " ), " +
                    " FirstTimestamp AS ( " +
                    "     SELECT MIN(WORK_TIME) AS FirstTime " +
                    "     FROM InitialData " +
                    " ), " +
                    " GroupedData AS ( " +
                    "     SELECT  " +
                    "         D.*,     " +
                    "         DATEDIFF(MINUTE, F.FirstTime, D.WORK_TIME) / 3 AS TimeGroup    " +
                    "     FROM InitialData D " +
                    "     CROSS JOIN FirstTimestamp F " +
                    " ), " +
                    " FilteredData AS ( " +
                    "     SELECT  " +
                    "         *,              " +
                    "         ROW_NUMBER() OVER (PARTITION BY TimeGroup ORDER BY WORK_TIME) AS RowNum      " +
                    "     FROM GroupedData " +
                    " ) " +
                    " SELECT RES_ID, " +
                    "        RES_DESC, " +
                    "        HIST_SEQ, " +
                    "        CONVERT(VARCHAR, FORMAT(WORK_TIME, 'yyyy-MM-dd HH:mm:ss'), 120) as WORK_TIME,  " +
                    "        WORK_DATE,  " +
                    "        SV_TEMP, " +
                    "        PV_TEMP, " +
                    "        VACCUM_PV1, " +
                    "        VACCUM_PV2, " +
                    "        THROTTLE_SV, " +
                    "        THROTTLE_PV, " +
                    "        THROTTLE_OUT, " +
                    "        RES_STATUS, " +
                    "        START_TIME, " +
                    "        END_TIME, " +
                    "        LOT_ID,  " +
                    "        MAT_ID,  " +
                    "        MAT_DESC " +
                    " FROM FilteredData " +
                    " WHERE RowNum = 1 " +
                      " AND  WORK_DATE >= '" + start_time + "'" +
                      " AND WORK_DATE <= '" + end_time + "'" +
                    " ORDER BY CONVERT(VARCHAR, WORK_TIME, 120);  ";

                }
                else if (cdvResId.Text == "E1000047")
                {

                    sql = "  WITH InitialData AS ( " +
                                " SELECT  'E1000047'  AS RES_ID, " +
                                "        'CTM_바인더 열처리로 #1' AS RES_DESC, " +
                                "        1 AS HIST_SEQ, " +
                                "        cre_date as WORK_TIME,  " +
                                "        CONVERT(VARCHAR(10), cre_date, 120) AS WORK_DATE,  " +
                                "        TEMP_SV  AS SV_TEMP, " +
                                "        TEMP_PV  AS PV_TEMP, " +
                                "        VACCUM_PV1, " +
                                "        REAL_POINT  AS VACCUM_PV2, " +
                                "        0  AS THROTTLE_SV, " +
                                "        0  AS  THROTTLE_PV, " +
                                "        0 AS THROTTLE_OUT, " +
                                "        TEMP_OP AS RES_STATUS, " +
                                "        ' ' as START_TIME, " +
                                "        ' ' as END_TIME, " +
                                "        ' ' AS LOT_ID,  " +
                                "        ' ' AS MAT_ID,  " +
                                "        ' ' AS MAT_DESC " +
                            "   FROM dbo.BINDER " +
                    "     WHERE YEAR(cre_date) >= YEAR('" + start_time + "') " +
                    " ), " +
                    " FirstTimestamp AS ( " +
                    "     SELECT MIN(WORK_TIME) AS FirstTime " +
                    "     FROM InitialData " +
                    " ), " +
                    " GroupedData AS ( " +
                    "     SELECT  " +
                    "         D.*,     " +
                    "         DATEDIFF(MINUTE, F.FirstTime, D.WORK_TIME) / 3 AS TimeGroup    " +
                    "     FROM InitialData D " +
                    "     CROSS JOIN FirstTimestamp F " +
                    " ), " +
                    " FilteredData AS ( " +
                    "     SELECT  " +
                    "         *,              " +
                    "         ROW_NUMBER() OVER (PARTITION BY TimeGroup ORDER BY WORK_TIME) AS RowNum      " +
                    "     FROM GroupedData " +
                    " ) " +
                    " SELECT RES_ID, " +
                    "        RES_DESC, " +
                    "        HIST_SEQ, " +
                    "        CONVERT(VARCHAR, FORMAT(WORK_TIME, 'yyyy-MM-dd HH:mm:ss'), 120) as WORK_TIME,  " +
                    "        WORK_DATE,  " +
                    "        SV_TEMP, " +
                    "        PV_TEMP, " +
                    "        VACCUM_PV1, " +
                    "        VACCUM_PV2, " +
                    "        THROTTLE_SV, " +
                    "        THROTTLE_PV, " +
                    "        THROTTLE_OUT, " +
                    "        RES_STATUS, " +
                    "        START_TIME, " +
                    "        END_TIME, " +
                    "        LOT_ID,  " +
                    "        MAT_ID,  " +
                    "        MAT_DESC " +
                    " FROM FilteredData " +
                    " WHERE RowNum = 1 " +
                      " AND  WORK_DATE >= '" + start_time + "'" +
                      " AND WORK_DATE <= '" + end_time + "'" +
                    " ORDER BY CONVERT(VARCHAR, WORK_TIME, 120);  ";

                }
                else
                {
                    return;
                }


                cmd = new SqlCommand(sql, sql_conn);
                using (SqlDataReader reader = cmd.ExecuteReader())
                {
                    int count = 0;
                    while (reader.Read())
                    {
                        count++;
                    }
                }



                //int count = Convert.ToInt32(cmd.ExecuteScalar());

                select_rs = cmd.ExecuteReader();

                MPCF.ClearList(spdFurnace);
                if (select_rs.HasRows)
                {
                    while (select_rs.Read())
                    {
                        spdFurnace.ActiveSheet.RowCount++;


                        iRows = spdFurnace.ActiveSheet.RowCount - 1;
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.RES_ID].Value = select_rs[0].ToString();
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.RES_DESC].Value = select_rs[1].ToString();
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.WORK_DATE].Text = select_rs[4].ToString();
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.WORK_TIME].Text = select_rs[3].ToString();
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.SV_TEMP].Value = select_rs[5].ToString();
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.PV_TEMP].Value = select_rs[6].ToString();
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.VACCUM_PV1].Value = select_rs[7].ToString();
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.VACCUM_PV2].Value = 0;
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.THROTTLE_SV].Value = 0;
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.THROTTLE_PV].Value = 0;
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.THROTTLE_OUT].Value = 0;
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.LOT_ID].Value = "";
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.MAT_ID].Value = "";
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.MAT_DESC].Value = "";
                        spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.RES_STATUS].Value = select_rs[12].ToString();

                        //바인더 진공로1 계산 (20240204)
                        if (cdvResId.Text == "E1000047")

                        {
                            int aaa = 0, bbb = 0, ccc = 0;
                            double ddd = 0;

                            int MyInt = Convert.ToInt32(select_rs[7]);
                            BitArray oByteArray = new BitArray(BitConverter.GetBytes(MyInt));



                            int MyInt1 = Convert.ToInt32(select_rs[8]);
                            BitArray oByteArray1 = new BitArray(BitConverter.GetBytes(MyInt1));



                            // aaa 계산
                            aaa += Convert.ToInt32(oByteArray[5]) * 1;
                            aaa += Convert.ToInt32(oByteArray[6]) * 2;
                            aaa += Convert.ToInt32(oByteArray[7]) * 4;
                            aaa += Convert.ToInt32(oByteArray[8]) * 8;
                            aaa += Convert.ToInt32(oByteArray[9]) * 16;
                            aaa += Convert.ToInt32(oByteArray[10]) * 32;
                            aaa += Convert.ToInt32(oByteArray[11]) * 64;
                            aaa += Convert.ToInt32(oByteArray[12]) * 128;
                            aaa += Convert.ToInt32(oByteArray[13]) * 256;
                            aaa += Convert.ToInt32(oByteArray[14]) * 512;

                            if (Convert.ToInt32(oByteArray[15]) == 1)
                                aaa = -aaa;

                            // bbb 계산
                            bbb += Convert.ToInt32(oByteArray[0]) * 1;
                            bbb += Convert.ToInt32(oByteArray[1]) * 2;
                            bbb += Convert.ToInt32(oByteArray[2]) * 4;
                            bbb += Convert.ToInt32(oByteArray[3]) * 8;

                            if (Convert.ToInt32(oByteArray[4]) == 1)
                                bbb = -bbb;

                            // ccc 계산
                            ccc += Convert.ToInt32(oByteArray1[0]) * 1;
                            ccc += Convert.ToInt32(oByteArray1[1]) * 2;
                            ccc += Convert.ToInt32(oByteArray1[2]) * 4;
                            ccc += Convert.ToInt32(oByteArray1[3]) * 8;

                            // ddd 계산
                            if (ccc > 0)
                            {
                                ddd = aaa / Math.Pow(10, ccc);
                            }
                            else
                            {
                                ddd = aaa;
                            }


                            ddd *= Math.Pow(10, bbb);

                            spdFurnace.ActiveSheet.Cells[iRows, (int)RAS_INFO.VACCUM_PV1].Value = ddd;
                        }

                    }
                }

                select_rs.Close();

                MPCF.FitColumnHeader(spdFurnace);
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

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvResId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRes.Text + "]");
                            cdvResId.Focus();
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

        private void ClearData()
        {
            try
            {
                MPCF.ClearList(spdFurnace);
                //cdvOper.Text = "";
                //cdvResId.Text = "";
                //txtLotID.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmViewCTMFurnaceData_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = CSGV.gs_area_ctm;
                cdvDept.DisplayText = CSGV.gs_area_ctm;

                txtLotID.Enabled = false;
                btnChngeLotTime.Enabled = false;
                //dtpFromDate.Enabled = true;
                //dtpToDate.Enabled = true;

                if (MPGV.gsUserGroup.Contains("ADMIN"))
                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                else
                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void pnlStsCond_Paint(object sender, PaintEventArgs e)
        {

        }

        private void lblRes_Click(object sender, EventArgs e)
        {

        }
        private void cdvOper_ButtonPress(object sender, EventArgs e)
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

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (ViewOper(cdvOper.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdFurnace);
                cdvResId.Text = "";
                txtLotID.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResId_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResId.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResId.SelectedSubItemIndex = 0;
                cdvResId.DisplaySubItemIndex = 1;


                if (COM_LIST.ViewResourceList(cdvResId.GetListView, '1', cdvOper.Text) == false)
                    return;

                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdFurnace);
                txtLotID.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoDate_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                if (rdoDate.Checked == true)
                {
                    rdoLot.Checked = false;
                    txtLotID.Text = "";
                    txtLotID.Enabled = false;
                    btnChngeLotTime.Enabled = false;
                    dtpFromDate.Enabled = true;
                    dtpToDate.Enabled = true;

                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;
                }
                else
                {
                    rdoLot.Checked = true;
                    txtLotID.Enabled = true;
                    btnChngeLotTime.Enabled = true;
                    dtpFromDate.Enabled = false;
                    dtpToDate.Enabled = false;

                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                    spdFurnace.ActiveSheet.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;
                }
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
                    if (rdoLot.Checked == true)
                    {
                        btnView.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnChngeLotTime_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(txtLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
                    return;
                }

                frmPopUpdateResourceWorkTime popup = new frmPopUpdateResourceWorkTime();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sLot_ID = txtLotID.Text;
                popup.sOper = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sRes_ID = cdvResId.Text;
                popup.sRes_desc = cdvResId.DisplayText;

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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {
                sFileName = cdvResId.Text + "_Data";

                EXTFUC.SaveExcel(spdFurnace, sFileName);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData();
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
                    return;

                // if (cdvDbType.Text == "MC DB" && cdvOper.Text != "OC01040")
                if (cdvDbType.Text == "MC DB")
                {
                    ViewFurnaceData_2();
                }
                else
                {
                    ViewFurnaceData();
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }







        }


        #endregion


    }
}
