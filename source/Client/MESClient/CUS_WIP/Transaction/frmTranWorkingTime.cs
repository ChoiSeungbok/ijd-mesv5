using System;
using System.Data;
using System.Windows.Forms;


using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;
using System.Text.RegularExpressions;
using FarPoint.Win.Spread.CellType;

namespace CUS_WIP
{
    public partial class frmTranWorkingTime : CUS_COM.frmViewForm01
    {

        public frmTranWorkingTime()
        {
            InitializeComponent();
            InitControl();
        }


        #region " Constant Definition "

        private enum WORKINGTIME
        {
            CHK,
            WORK_SEQ,
            WORK_DATE,
            WEEK,
            USER_ID,
            USER_DESC,
            AREA_ID,
            AREA_DESC,
            AREA_BUTTON,
            OPER,
            OPER_DESC,
            OPER_BUTTON,
            START_DT,
            START_TIME,
            END_DT,
            END_TIME,
            BREAK_TIME,
            TOTAL_WORK_TIME,
            TOTAL_CONV_TIME,
            WEK_01_ST_TIME,
            WEK_01_OV_TIME,
            WEK_02_ST_TIME,
            WEK_02_OV_TIME,
            HOL_01_ST_TIME,
            HOL_01_OV_TIME,
            HOL_02_ST_TIME,
            HOL_02_OV_TIME,
            REMARKS

        }
        private enum BREAKTIME
        {
            BREAK_DESC,
            BREAK_START,
            BREAK_END,
            BREAK_TOTAL
        }
        private enum WORKTYPE
        {
            WEEK_TYPE,
            WORK_TYPE_DESC1,
            WORK_TYPE_DESC2,
            WORK_START,
            WORK_END,
            WORK_TOTAL,
            CONVERT_RATE
        }

        #endregion

        #region " Variable Definition "
        private string gUserID = string.Empty;
        private string gUserDesc = string.Empty;
        private string gUserArea = string.Empty;
        private string gUserAreaDesc = string.Empty;
        private string gUserOper = string.Empty;
        private string gUserOperDesc = string.Empty;

        private string gStartTime = "08:00";
        private string gEndTime = "17:00";

        #endregion


        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            SheetView sv = spdWorkingTime_Sheet1;
            int iCheckCount = 0;

            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        //if (string.IsNullOrEmpty(MPCF.Trim(cdvDept.Text)))
                        //{
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        //    cdvDept.Focus();
                        //    return false;
                        //}
                        break;
                    case CSGC.CHECK.ADD:

                        break;
                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (Convert.ToBoolean(sv.Cells[i, (int)WORKINGTIME.CHK] == null ? false : sv.Cells[i, (int)WORKINGTIME.CHK].Value))
                            {

                                if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)WORKINGTIME.WORK_DATE].Value)))
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    sv.SetActiveCell(i, (int)WORKINGTIME.WORK_DATE);
                                    return false;
                                }

                                if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)WORKINGTIME.USER_ID].Value)))
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    sv.SetActiveCell(i, (int)WORKINGTIME.USER_ID);
                                    return false;
                                }
                                if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)WORKINGTIME.USER_DESC].Value)))
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    sv.SetActiveCell(i, (int)WORKINGTIME.USER_DESC);
                                    return false;
                                }

                                if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)WORKINGTIME.AREA_ID].Value)))
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    sv.SetActiveCell(i, (int)WORKINGTIME.AREA_ID);
                                    return false;
                                }
                                /*
                                if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)WORKINGTIME.OPER].Value)))
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    sv.SetActiveCell(i, (int)WORKINGTIME.OPER);
                                    return false;
                                }*/

                                iCheckCount++;
                            }
                        }

                        if (iCheckCount == 0)
                        {
                            //체크항목이 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
                            return false;
                        }
                        break;
                    case CSGC.CHECK.DELETE:
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (Convert.ToBoolean(sv.Cells[i, (int)WORKINGTIME.CHK] == null ? false : sv.Cells[i, (int)WORKINGTIME.CHK].Value))
                            {
                                iCheckCount++;
                            }
                        }

                        if (iCheckCount == 0)
                        {
                            //체크항목이 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
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

        private void SetWorkTimeSheet()
        {
            SheetView sv = spdWorkingTime_Sheet1;

            try
            {
                //sv.Columns.Get((int)WORKINGTIME.WORK_SEQ).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.WEEK).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.AREA_ID).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.OPER).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.START_DT).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.END_DT).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.WEK_01_ST_TIME).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.WEK_01_OV_TIME).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.WEK_02_ST_TIME).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.WEK_02_OV_TIME).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.HOL_01_ST_TIME).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.HOL_01_OV_TIME).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.HOL_02_ST_TIME).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.HOL_02_OV_TIME).Visible = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void SetBreakTimeSheet()
        {
            SheetView sv = spdBreakTime_Sheet1;

            try
            {
                sv.Columns.Get((int)BREAKTIME.BREAK_START).Visible = false;
                sv.Columns.Get((int)BREAKTIME.BREAK_END).Visible = false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void SetConvTimeSheet()
        {
            SheetView sv = spdConvTime.ActiveSheet;

            try
            {
                // sv.Columns.Get((int)WORKTYPE.WEEK_TYPE).Visible = false;
                sv.Columns.Get((int)WORKTYPE.WORK_START).Visible = false;
                sv.Columns.Get((int)WORKTYPE.WORK_END).Visible = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private bool ValidDuplicate(string sWorkSeq, string sWorkDate, string sUserId, string sStartTime, string sEndTime)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "WORK_DATE";
                dvcArgu[1].sCondition_Value = sWorkDate.Trim().Replace("-", "").Substring(0, 8);

                dvcArgu[2].sCondition_ID = "USER_ID";
                dvcArgu[2].sCondition_Value = sUserId.Trim();

                dvcArgu[3].sCondition_ID = "START_TIME";
                dvcArgu[3].sCondition_Value = sStartTime.Replace(":", "").Trim();

                dvcArgu[4].sCondition_ID = "END_TIME";
                dvcArgu[4].sCondition_Value = sEndTime.Replace(":", "").Trim();

                dvcArgu[5].sCondition_ID = "WORK_SEQ";
                dvcArgu[5].sCondition_Value = string.IsNullOrEmpty(sWorkSeq.ToString()) ? 0 : long.Parse(sWorkSeq.ToString());

                if (TPDR.GetDataOne("", ref dt, "CWIP1003-008", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }
                if (dt.Rows.Count > 0)
                {
                    return true;
                }

                return false;

            }
            catch (Exception ex)
            {
                throw ex;

            }
        }

        private bool ViewOperList(Control control, string sArea)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                if (TPDR.GetDataOne("", ref dt, "CWIP1003-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["CODE"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            //   itmX.SubItems.Add(row["CODE"].ToString());
                            itmX.SubItems.Add(row["DATA"].ToString());
                        }
                       ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private bool ViewUserList(Control control, string sArea, string sOper)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = GetUserInfo("", "", sArea, sOper);

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["USER_ID"].ToString(), (int)SMALLICON_INDEX.IDX_USER);

                        if (((ListView)control).Columns.Count > 1)
                        {

                            itmX.SubItems.Add(row["USER_DESC"].ToString());
                            itmX.SubItems.Add(row["AREA_DESC"].ToString());
                            itmX.SubItems.Add(row["OPER_DESC"].ToString());
                        }
                       ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private void ViewWorkTimeList()
        {
            try
            {
                MPCF.ClearList(spdWorkingTime);
                SheetView sv = spdWorkingTime.ActiveSheet;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = string.Format("{0}%", cdvDept.Text);

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = string.Format("{0}%", cdvOper.Text);

                dvcArgu[3].sCondition_ID = "TEAM";
                dvcArgu[3].sCondition_Value = string.Format("{0}%", "");

                dvcArgu[4].sCondition_ID = "USER_ID";
                dvcArgu[4].sCondition_Value = string.Format("{0}%", cdvUser.Text);

                dvcArgu[5].sCondition_ID = "USER_DESC";
                dvcArgu[5].sCondition_Value = string.Format("{0}%", txtUserDesc.Text);

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "");

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToWorkDate.Text.Replace("-", "");

                if (TPDR.GetDataOne("", ref dt, "CWIP1003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    sv.RowCount++;

                    sv.Cells[i, (int)WORKINGTIME.CHK].Value = false;
                    sv.Cells[i, (int)WORKINGTIME.WORK_SEQ].Value = dt.Rows[i]["WORK_SEQ"];
                    sv.Cells[i, (int)WORKINGTIME.WORK_DATE].Value = string.Format("{0}-{1}-{2}", dt.Rows[i]["WORK_DATE"].ToString().Substring(0, 4), dt.Rows[i]["WORK_DATE"].ToString().Substring(4, 2), dt.Rows[i]["WORK_DATE"].ToString().Substring(6, 2));
                    sv.Cells[i, (int)WORKINGTIME.WEEK].Value = dt.Rows[i]["WEEK"];
                    sv.Cells[i, (int)WORKINGTIME.USER_ID].Value = dt.Rows[i]["USER_ID"];
                    sv.Cells[i, (int)WORKINGTIME.USER_DESC].Value = dt.Rows[i]["USER_DESC"];
                    sv.Cells[i, (int)WORKINGTIME.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    sv.Cells[i, (int)WORKINGTIME.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    sv.Cells[i, (int)WORKINGTIME.OPER].Value = dt.Rows[i]["OPER"];
                    sv.Cells[i, (int)WORKINGTIME.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    sv.Cells[i, (int)WORKINGTIME.START_DT].Value = dt.Rows[i]["START_DT"];
                    sv.Cells[i, (int)WORKINGTIME.START_TIME].Value = dt.Rows[i]["START_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.END_DT].Value = dt.Rows[i]["END_DT"];
                    sv.Cells[i, (int)WORKINGTIME.END_TIME].Value = dt.Rows[i]["END_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.TOTAL_WORK_TIME].Value = dt.Rows[i]["TOTAL_WORK_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.TOTAL_CONV_TIME].Value = dt.Rows[i]["TOTAL_CONV_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.BREAK_TIME].Value = dt.Rows[i]["BREAK_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.WEK_01_ST_TIME].Value = dt.Rows[i]["WEK_01_ST_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.WEK_01_OV_TIME].Value = dt.Rows[i]["WEK_01_OV_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.WEK_02_ST_TIME].Value = dt.Rows[i]["WEK_02_ST_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.WEK_02_OV_TIME].Value = dt.Rows[i]["WEK_02_OV_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.HOL_01_ST_TIME].Value = dt.Rows[i]["HOL_01_ST_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.HOL_01_OV_TIME].Value = dt.Rows[i]["HOL_01_OV_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.HOL_02_ST_TIME].Value = dt.Rows[i]["HOL_02_ST_TIME"];
                    sv.Cells[i, (int)WORKINGTIME.HOL_02_OV_TIME].Value = dt.Rows[i]["HOL_02_OV_TIME"];


                    sv.Cells[i, (int)WORKINGTIME.REMARKS].Value = dt.Rows[i]["REMARKS"];
                }

                MPCF.FitColumnHeader(spdWorkingTime);
                return;

            }
            catch (Exception ex)
            {
                throw ex;

            }
        }

        //휴계시간 조회
        private void ViewBreakTimeList()
        {
            try
            {

                MPCF.ClearList(spdBreakTime);
                SheetView sv = spdBreakTime.ActiveSheet;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                string sView_Id;

                sView_Id = "CWIP1003-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBreakTime);
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    sv.RowCount++;

                    sv.Cells[i, (int)BREAKTIME.BREAK_DESC].Value = dt.Rows[i]["BREAK_DESC"];
                    sv.Cells[i, (int)BREAKTIME.BREAK_START].Value = dt.Rows[i]["BREAK_START"];
                    sv.Cells[i, (int)BREAKTIME.BREAK_END].Value = dt.Rows[i]["BREAK_END"];
                    sv.Cells[i, (int)BREAKTIME.BREAK_TOTAL].Value = dt.Rows[i]["BREAK_TOTAL"];
                }

                //MPCF.FitColumnHeader(spdWorkingTime);
                return;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        //작업시간구분
        private void ViewWorkTypeList()
        {
            try
            {

                MPCF.ClearList(spdConvTime);
                SheetView sv = spdConvTime.ActiveSheet;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                string sView_Id;


                sView_Id = "CWIP1003-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdConvTime);
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    sv.RowCount++;


                    sv.Cells[i, (int)WORKTYPE.WORK_TYPE_DESC1].Value = dt.Rows[i]["WORK_TYPE_DESC1"];
                    sv.Cells[i, (int)WORKTYPE.WORK_TYPE_DESC2].Value = dt.Rows[i]["WORK_TYPE_DESC2"];
                    sv.Cells[i, (int)WORKTYPE.WEEK_TYPE].Value = dt.Rows[i]["WEEK_TYPE"];
                    sv.Cells[i, (int)WORKTYPE.WORK_START].Value = dt.Rows[i]["WORK_START"];
                    sv.Cells[i, (int)WORKTYPE.WORK_END].Value = dt.Rows[i]["WORK_END"];
                    sv.Cells[i, (int)WORKTYPE.WORK_TOTAL].Value = dt.Rows[i]["WORK_TOTAL"];
                    sv.Cells[i, (int)WORKTYPE.CONVERT_RATE].Value = dt.Rows[i]["CONVERT_RATE"];

                }
                // MPCF.FitColumnHeader(spdWorkingTime);
                return;
            }
            catch (Exception ex)
            {
                throw ex;

            }
        }

        private DataTable GetUserInfo(string sUserID, string sUserName, string sArea = "", string sOper = "")
        {
            DataTable dt = null;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = string.Format("{0}%", "");

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = string.Format("{0}%", "");

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = string.Format("{0}%", "");

                dvcArgu[4].sCondition_ID = "USER_ID";
                dvcArgu[4].sCondition_Value = string.IsNullOrEmpty(sUserID.ToString()) ? "%" : sUserID.ToString();

                dvcArgu[5].sCondition_ID = "USER_DESC";
                dvcArgu[5].sCondition_Value = string.IsNullOrEmpty(sUserName.ToString()) ? "%" : sUserName.ToString();

                if (TPDR.GetDataOne("", ref dt, "CWIP1003-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return null;
                }
                return dt;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private void SetSheetUserInfo(string sType, int iRow, DataTable dt)
        {
            try
            {
                SheetView sv = spdWorkingTime.ActiveSheet;

                if (sType == "ADD")
                {
                    sv.Cells[iRow, (int)WORKINGTIME.USER_ID].Value = gUserID;
                    sv.Cells[iRow, (int)WORKINGTIME.USER_DESC].Value = gUserDesc;
                    sv.Cells[iRow, (int)WORKINGTIME.AREA_ID].Value = gUserArea;
                    sv.Cells[iRow, (int)WORKINGTIME.AREA_DESC].Value = gUserAreaDesc;
                    sv.Cells[iRow, (int)WORKINGTIME.OPER].Value = gUserOper;
                    sv.Cells[iRow, (int)WORKINGTIME.OPER_DESC].Value = gUserOperDesc;

                }
                else
                {
                    if (dt == null)
                    {
                        sv.Cells[iRow, (int)WORKINGTIME.USER_ID].Value = ""; ;
                        sv.Cells[iRow, (int)WORKINGTIME.USER_DESC].Value = "";
                        sv.Cells[iRow, (int)WORKINGTIME.AREA_ID].Value = "";
                        sv.Cells[iRow, (int)WORKINGTIME.AREA_DESC].Value = "";
                        sv.Cells[iRow, (int)WORKINGTIME.OPER].Value = "";
                        sv.Cells[iRow, (int)WORKINGTIME.OPER_DESC].Value = "";
                    }
                    else
                    {
                        sv.Cells[iRow, (int)WORKINGTIME.USER_ID].Value = dt.Rows[0]["USER_ID"];
                        sv.Cells[iRow, (int)WORKINGTIME.USER_DESC].Value = dt.Rows[0]["USER_DESC"];
                        sv.Cells[iRow, (int)WORKINGTIME.AREA_ID].Value = dt.Rows[0]["AREA_ID"];
                        sv.Cells[iRow, (int)WORKINGTIME.AREA_DESC].Value = dt.Rows[0]["AREA_DESC"];
                        sv.Cells[iRow, (int)WORKINGTIME.OPER].Value = dt.Rows[0]["OPER"];
                        sv.Cells[iRow, (int)WORKINGTIME.OPER_DESC].Value = dt.Rows[0]["OPER_DESC"];
                    }
                }

                if (string.IsNullOrEmpty(sv.Cells[iRow, (int)WORKINGTIME.AREA_ID].Value.ToString().Trim()))
                {
                    sv.Cells[iRow, (int)WORKINGTIME.AREA_ID].Value = cdvDept.Text;
                    sv.Cells[iRow, (int)WORKINGTIME.AREA_DESC].Value = cdvDept.DisplayText;
                }
                //if (string.IsNullOrEmpty(sv.Cells[iRow, (int)WORKINGTIME.OPER].Value.ToString().Trim()))
                //{
                //    sv.Cells[iRow, (int)WORKINGTIME.OPER].Value = cdvOper.Text;
                //    sv.Cells[iRow, (int)WORKINGTIME.OPER_DESC].Value = cdvOper.DisplayText;
                //}
                return;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        //휴계시간,시간대별 작업시간,총작업시간,환산시간계산
        private void GetCalTime(int iWorkRow)
        {
            try
            {
                SheetView sv = spdWorkingTime.ActiveSheet;

                if (sv.Cells[iWorkRow, (int)WORKINGTIME.WORK_DATE].Text == ""
                    || sv.Cells[iWorkRow, (int)WORKINGTIME.START_TIME].Text == ""
                    || sv.Cells[iWorkRow, (int)WORKINGTIME.END_TIME].Text == ""
                    )
                    return;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "WORK_DATE";
                dvcArgu[1].sCondition_Value = sv.Cells[iWorkRow, (int)WORKINGTIME.WORK_DATE].Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "START_TIME";
                dvcArgu[2].sCondition_Value = sv.Cells[iWorkRow, (int)WORKINGTIME.START_TIME].Text.Replace(":", "");

                dvcArgu[3].sCondition_ID = "END_TIME";
                dvcArgu[3].sCondition_Value = sv.Cells[iWorkRow, (int)WORKINGTIME.END_TIME].Text.Replace(":", "");

                if (TPDR.GetDataOne("", ref dt, "CWIP1003-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    sv.Cells[iWorkRow, (int)WORKINGTIME.WEEK].Value = dt.Rows[i]["WEEK"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.START_DT].Value = dt.Rows[i]["START_DT"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.END_DT].Value = dt.Rows[i]["END_DT"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.TOTAL_WORK_TIME].Value = dt.Rows[i]["TOTAL_WORK_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.TOTAL_CONV_TIME].Value = dt.Rows[i]["TOTAL_CONV_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.BREAK_TIME].Value = dt.Rows[i]["BREAK_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.WEK_01_ST_TIME].Value = dt.Rows[i]["WEK_01_ST_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.WEK_01_OV_TIME].Value = dt.Rows[i]["WEK_01_OV_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.WEK_02_ST_TIME].Value = dt.Rows[i]["WEK_02_ST_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.WEK_02_OV_TIME].Value = dt.Rows[i]["WEK_02_OV_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.HOL_01_ST_TIME].Value = dt.Rows[i]["HOL_01_ST_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.HOL_01_OV_TIME].Value = dt.Rows[i]["HOL_01_OV_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.HOL_02_ST_TIME].Value = dt.Rows[i]["HOL_02_ST_TIME"];
                    sv.Cells[iWorkRow, (int)WORKINGTIME.HOL_02_OV_TIME].Value = dt.Rows[i]["HOL_02_OV_TIME"];

                }
                MPCF.FitColumnHeader(spdWorkingTime);
                return;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private bool SaveWorkTime(char sProcstep)
        {
            try
            {
                SheetView sv = spdWorkingTime_Sheet1;
                //   TRSNode in_node = new TRSNode("Insert_WorkTime_In");
                //   TRSNode out_node = new TRSNode("Insert_WorkTime_Out");
                //   TRSNode tbl_list;



                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)WORKINGTIME.CHK] == null ? false : sv.Cells[i, (int)WORKINGTIME.CHK].Value))
                    {
                        if (sProcstep == '1')
                        {
                            if (ValidDuplicate(
                                   sv.Cells[i, (int)WORKINGTIME.WORK_SEQ].Value.ToString(),
                                   sv.Cells[i, (int)WORKINGTIME.WORK_DATE].Value.ToString(),
                                   sv.Cells[i, (int)WORKINGTIME.USER_ID].Value.ToString(),
                                   string.Format("{0}{1}", sv.Cells[i, (int)WORKINGTIME.START_DT].Value, GetConvertTime(sv.Cells[i, (int)WORKINGTIME.START_TIME].Value)),
                                   string.Format("{0}{1}", sv.Cells[i, (int)WORKINGTIME.START_DT].Value, GetConvertTime(sv.Cells[i, (int)WORKINGTIME.END_TIME].Value))
                                   ))
                            {
                                //CMN524 ERROR - 해당 사용자는 중복된 시간이 있습니다.
                                MPCF.ShowMsgBox(string.Format("{0}[{1}]", MPCF.GetMessage(524), sv.Cells[i, (int)WORKINGTIME.USER_ID].Value.ToString()));
                                return false;
                            }
                        }

                        TRSNode in_node = new TRSNode("Insert_WorkTime_In");
                        TRSNode out_node = new TRSNode("Insert_WorkTime_Out");
                        TRSNode tbl_list;
                        MPCR.SetInMsg(in_node);
                        in_node.ProcStep = sProcstep;

                        tbl_list = in_node.AddNode("TBL_LIST");

                        tbl_list.AddInt("WORK_SEQ", sv.Cells[i, (int)WORKINGTIME.WORK_SEQ].Value);
                        tbl_list.AddString("WORK_DATE", sv.Cells[i, (int)WORKINGTIME.WORK_DATE].Value.ToString().Replace("-", "").Substring(0, 8));
                        tbl_list.AddString("USER_ID", sv.Cells[i, (int)WORKINGTIME.USER_ID].Value);
                        tbl_list.AddString("USER_DESC", sv.Cells[i, (int)WORKINGTIME.USER_DESC].Value);
                        tbl_list.AddString("AREA_ID", sv.Cells[i, (int)WORKINGTIME.AREA_ID].Value);
                        tbl_list.AddString("OPER", sv.Cells[i, (int)WORKINGTIME.OPER].Value);
                        tbl_list.AddString("OPER_DESC", sv.Cells[i, (int)WORKINGTIME.OPER_DESC].Value);
                        tbl_list.AddString("START_DT", sv.Cells[i, (int)WORKINGTIME.START_DT].Value);
                        tbl_list.AddString("START_TIME", GetConvertTime(sv.Cells[i, (int)WORKINGTIME.START_TIME].Value));
                        tbl_list.AddString("END_DT", sv.Cells[i, (int)WORKINGTIME.END_DT].Value);
                        tbl_list.AddString("END_TIME", GetConvertTime(sv.Cells[i, (int)WORKINGTIME.END_TIME].Value));
                        tbl_list.AddDouble("TOTAL_WORK_TIME", sv.Cells[i, (int)WORKINGTIME.TOTAL_WORK_TIME].Value);
                        tbl_list.AddDouble("TOTAL_CONV_TIME", sv.Cells[i, (int)WORKINGTIME.TOTAL_CONV_TIME].Value);
                        tbl_list.AddDouble("BREAK_TIME", sv.Cells[i, (int)WORKINGTIME.BREAK_TIME].Value);
                        tbl_list.AddDouble("WEK_01_ST_TIME", sv.Cells[i, (int)WORKINGTIME.WEK_01_ST_TIME].Value);
                        tbl_list.AddDouble("WEK_01_OV_TIME", sv.Cells[i, (int)WORKINGTIME.WEK_01_OV_TIME].Value);
                        tbl_list.AddDouble("WEK_02_ST_TIME", sv.Cells[i, (int)WORKINGTIME.WEK_02_ST_TIME].Value);
                        tbl_list.AddDouble("WEK_02_OV_TIME", sv.Cells[i, (int)WORKINGTIME.WEK_02_OV_TIME].Value);
                        tbl_list.AddDouble("HOL_01_ST_TIME", sv.Cells[i, (int)WORKINGTIME.HOL_01_ST_TIME].Value);
                        tbl_list.AddDouble("HOL_01_OV_TIME", sv.Cells[i, (int)WORKINGTIME.HOL_01_OV_TIME].Value);
                        tbl_list.AddDouble("HOL_02_ST_TIME", sv.Cells[i, (int)WORKINGTIME.HOL_02_ST_TIME].Value);
                        tbl_list.AddDouble("HOL_02_OV_TIME", sv.Cells[i, (int)WORKINGTIME.HOL_02_OV_TIME].Value);
                        tbl_list.AddString("REMARKS", sv.Cells[i, (int)WORKINGTIME.REMARKS].Value);


                        if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Working_Time", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                        else
                        {
                            sv.Cells[i, (int)WORKINGTIME.CHK].Value = false;
                        }
                    }
                }


                return true;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private string GetConvertTime(object d)
        {
            string rtn = " ";

            try
            {
                if (d != null)
                {
                    DateTime dt = Convert.ToDateTime(d);
                    rtn = dt.ToString("HH:mm");
                }
            }
            catch (Exception ex)
            {
                throw ex;
            }
            return rtn;
        }

        private void SetSheetWorkingTime(int iCol, int iRow)
        {
            try
            {
                DataTable dt = null;
                SheetView sv = spdWorkingTime_Sheet1;

                if (iCol == (int)WORKINGTIME.WORK_DATE || iCol == (int)WORKINGTIME.START_TIME || iCol == (int)WORKINGTIME.END_TIME)
                {
                    GetCalTime(iRow);
                }
                else if (iCol == (int)WORKINGTIME.USER_ID)
                {
                    dt = GetUserInfo(sv.Cells[iRow, (int)WORKINGTIME.USER_ID].Text, "");
                    SetSheetUserInfo("CELL", iRow, dt);
                }
                else if (iCol == (int)WORKINGTIME.USER_DESC)
                {
                    dt = GetUserInfo("", sv.Cells[iRow, (int)WORKINGTIME.USER_DESC].Text);
                    SetSheetUserInfo("CELL", iRow, dt);
                }
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
        #endregion

        #region " Event Definition"

        private void frmTranWorkingTime_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.FieldClear(pnlStsCond);

                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = DateTime.Now;
                MPCF.ClearList(spdWorkingTime);

                SetWorkTimeSheet();
                SetBreakTimeSheet();
                SetConvTimeSheet();

                //기본 사용자 정보
                gUserID = MPGV.gsUserID;
                DataTable dt = GetUserInfo(gUserID, "");
                if (dt != null)
                {
                    gUserDesc = dt.Rows[0]["USER_DESC"].ToString().Trim();
                    gUserArea = dt.Rows[0]["AREA_ID"].ToString().Trim();
                    gUserAreaDesc = dt.Rows[0]["AREA_DESC"].ToString().Trim();
                    gUserOper = dt.Rows[0]["OPER"].ToString().Trim();
                    gUserOperDesc = dt.Rows[0]["OPER_DESC"].ToString().Trim();
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
                    return;

                ViewWorkTimeList();
                // ViewBreakTimeList();
                // ViewWorkTypeList();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                    return;

                DialogResult dr = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                if (dr == DialogResult.OK)
                {
                    if (SaveWorkTime('2'))
                    {
                        ViewWorkTimeList();

                        MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    }

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveWorkTime('1'))
                {
                    ViewWorkTimeList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                SheetView sv = spdWorkingTime_Sheet1;
                int iRow = sv.RowCount;

                sv.RowCount++;
                sv.Cells[iRow, (int)WORKINGTIME.CHK].Value = true;
                sv.Cells[iRow, (int)WORKINGTIME.WORK_SEQ].Value = "";
                sv.Cells[iRow, (int)WORKINGTIME.WORK_DATE].Value = DateTime.Now;
                sv.Cells[iRow, (int)WORKINGTIME.START_DT].Value = DateTime.Now.ToString("yyyyMMd");
                sv.Cells[iRow, (int)WORKINGTIME.START_TIME].Value = gStartTime;
                sv.Cells[iRow, (int)WORKINGTIME.END_DT].Value = DateTime.Now.ToString("yyyyMMdd");
                sv.Cells[iRow, (int)WORKINGTIME.END_TIME].Value = gEndTime;

                SetSheetUserInfo("ADD", iRow, null);

                GetCalTime(iRow);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            SheetView sv = spdWorkingTime.ActiveSheet;

            try
            {
                for (int i = sv.RowCount - 1; i >= 0; i--)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)WORKINGTIME.CHK] == null ? false : sv.Cells[i, (int)WORKINGTIME.CHK].Value))
                    {
                        sv.RemoveRows(i, 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkingTime_Change(object sender, ChangeEventArgs e)
        {
            try
            {
                SetSheetWorkingTime(e.Column, spdWorkingTime_Sheet1.ActiveRowIndex);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkingTime_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                SheetView sv = spdWorkingTime_Sheet1;
                int iActiveRow = sv.ActiveRowIndex;

                if (e.Control && e.KeyCode == Keys.V)
                {
                    if (iActiveRow < 0)
                        return;

                    string[] rowSeparators = new string[] { "\r\n" };
                    string sClipboard = Clipboard.GetText();
                    string[] sList = sClipboard.Split(rowSeparators, StringSplitOptions.None);
                    string[] columnSeparators = new string[] { "\t" };

                    for (int i = 0; i < sList.Length - 1; i++)
                    {
                        string[] sColumnList = sList[i].Split(columnSeparators, StringSplitOptions.None);

                        sv.Cells[iActiveRow, 0].Value = true;

                        if (sColumnList.Length == 1)
                        {
                            sv.Cells[iActiveRow, sv.ActiveColumnIndex].Value = sColumnList[0];

                            if (sv.ActiveColumnIndex == (int)WORKINGTIME.USER_ID || sv.ActiveColumnIndex == (int)WORKINGTIME.USER_DESC)
                            {
                                sv.Cells[iActiveRow, (int)WORKINGTIME.WORK_SEQ].Value = "";
                                sv.Cells[iActiveRow, (int)WORKINGTIME.WORK_DATE].Value = DateTime.Now;
                                sv.Cells[iActiveRow, (int)WORKINGTIME.START_DT].Value = DateTime.Now.ToString("yyyyMMd");
                                sv.Cells[iActiveRow, (int)WORKINGTIME.START_TIME].Value = gStartTime;
                                sv.Cells[iActiveRow, (int)WORKINGTIME.END_DT].Value = DateTime.Now.ToString("yyyyMMdd");
                                sv.Cells[iActiveRow, (int)WORKINGTIME.END_TIME].Value = gEndTime;
                            }
                            SetSheetWorkingTime(sv.ActiveColumnIndex, iActiveRow);

                            if (sv.Cells[iActiveRow, (int)WORKINGTIME.USER_ID].Value != null && sv.Cells[iActiveRow, (int)WORKINGTIME.USER_ID].Value.ToString() != ""
                                    && sv.Cells[iActiveRow, (int)WORKINGTIME.USER_DESC].Value != null && sv.Cells[iActiveRow, (int)WORKINGTIME.USER_DESC].Value.ToString() != "")
                            {
                                GetCalTime(iActiveRow);

                                iActiveRow++;
                                if ((sv.RowCount - 1) < iActiveRow)
                                    sv.RowCount++;
                            }
                        }
                        else
                        {
                            int c = 1;
                            for (int j = 0; j < sColumnList.Length; j++)
                            {
                                if (j == 2 || j == 6 || j == 8 || j == 9)
                                {
                                    c++;
                                }
                                if (j == 8)
                                {
                                    c++;
                                }

                                sv.Cells[iActiveRow, c + j].Value = sColumnList[j];
                            }

                            GetCalTime(iActiveRow);

                            iActiveRow++;
                            if ((sv.RowCount - 1) < iActiveRow)
                                sv.RowCount++;
                        }
                    }

                    //sv.RemoveRows(iActiveRow, (sv.RowCount - iActiveRow - 1) == 0 ? 1 : (sv.RowCount - iActiveRow - 1));

                    //if (sv.RowCount - iActiveRow - 1 != 0)
                    //{
                    //    sv.RowCount++;
                    //}
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;

        }

        private void spdWorkingTime_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)WORKINGTIME.CHK)
                    {
                        CSCF.CheckSpreadCell(spdWorkingTime, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkingTime_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                SheetView sv = spdWorkingTime_Sheet1;

                if (e.Column == (int)WORKINGTIME.AREA_BUTTON
                    || e.Column == (int)WORKINGTIME.OPER_BUTTON)
                {

                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)WORKINGTIME.AREA_BUTTON)
                    {
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', "C_WORK_DEPARTMENT") == false)
                            return;

                        sv.Cells[e.Row, (int)WORKINGTIME.OPER].Value = string.Empty;
                        sv.Cells[e.Row, (int)WORKINGTIME.OPER_DESC].Value = string.Empty;

                    }
                    else if (e.Column == (int)WORKINGTIME.OPER_BUTTON)
                    {
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[e.Row, (int)WORKINGTIME.AREA_ID].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(e.Row, (int)WORKINGTIME.WORK_DATE);
                            return;
                        }

                        if (ViewOperList(cdvGridButton.GetListView, sv.Cells[e.Row, (int)WORKINGTIME.AREA_ID].Value.ToString()) == false)
                            return;
                    }

                    cdvGridButton.ShowPopupList(e.Row, e.Column);

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            SheetView sv = spdWorkingTime.ActiveSheet;
            try
            {
                if (sv.ActiveColumnIndex == (int)WORKINGTIME.AREA_BUTTON)
                {
                    sv.SetValue(e.Row, (int)WORKINGTIME.AREA_ID, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)WORKINGTIME.AREA_DESC, e.SelectedItem.SubItems[1].Text);
                }

                else if (sv.ActiveColumnIndex == (int)WORKINGTIME.OPER_BUTTON)
                {
                    sv.SetValue(e.Row, (int)WORKINGTIME.OPER, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)WORKINGTIME.OPER_DESC, e.SelectedItem.SubItems[1].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkingTime_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdWorkingTime_Sheet1.ActiveColumnIndex != 0)
                spdWorkingTime_Sheet1.Cells[spdWorkingTime_Sheet1.ActiveRowIndex, (int)WORKINGTIME.CHK].Value = true;
        }
        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("CODE", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("DATA", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', "C_WORK_DEPARTMENT") == false)
                {
                    return;
                }
                // cdvDept.InsertEmptyRow(0, 1);
                cdvOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false) return;

                ViewBreakTimeList();
                ViewWorkTypeList();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("CODE", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("DATA", 100, HorizontalAlignment.Left);
                cdvOper.DisplaySubItemIndex = 1;
                cdvOper.SelectedSubItemIndex = 0;

                if (ViewOperList(cdvOper.GetListView, cdvDept.Text) == false)
                {
                    return;
                }
                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }




        private void chkColHidden_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                SheetView sv = spdWorkingTime_Sheet1;
                if (chkColHidden.Checked)
                {
                    sv.Columns.Get((int)WORKINGTIME.WEK_01_ST_TIME).Visible = true;
                    sv.Columns.Get((int)WORKINGTIME.WEK_01_OV_TIME).Visible = true;
                    sv.Columns.Get((int)WORKINGTIME.WEK_02_ST_TIME).Visible = true;
                    sv.Columns.Get((int)WORKINGTIME.WEK_02_OV_TIME).Visible = true;
                    sv.Columns.Get((int)WORKINGTIME.HOL_01_ST_TIME).Visible = true;
                    sv.Columns.Get((int)WORKINGTIME.HOL_01_OV_TIME).Visible = true;
                    sv.Columns.Get((int)WORKINGTIME.HOL_02_ST_TIME).Visible = true;
                    sv.Columns.Get((int)WORKINGTIME.HOL_02_OV_TIME).Visible = true;

                }
                else
                {
                    sv.Columns.Get((int)WORKINGTIME.WEK_01_ST_TIME).Visible = false;
                    sv.Columns.Get((int)WORKINGTIME.WEK_01_OV_TIME).Visible = false;
                    sv.Columns.Get((int)WORKINGTIME.WEK_02_ST_TIME).Visible = false;
                    sv.Columns.Get((int)WORKINGTIME.WEK_02_OV_TIME).Visible = false;
                    sv.Columns.Get((int)WORKINGTIME.HOL_01_ST_TIME).Visible = false;
                    sv.Columns.Get((int)WORKINGTIME.HOL_01_OV_TIME).Visible = false;
                    sv.Columns.Get((int)WORKINGTIME.HOL_02_ST_TIME).Visible = false;
                    sv.Columns.Get((int)WORKINGTIME.HOL_02_OV_TIME).Visible = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvTeam_ButtonPress(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvUser_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvUser.Init();
                MPCF.InitListView(cdvUser.GetListView);
                cdvUser.Columns.Add("USER_ID", 10, HorizontalAlignment.Left);
                cdvUser.Columns.Add("USER_DESC", 20, HorizontalAlignment.Left);
                cdvUser.Columns.Add("AREA_DESC", 20, HorizontalAlignment.Left);
                cdvUser.Columns.Add("OPER_DESC", 100, HorizontalAlignment.Left);
                cdvUser.DisplaySubItemIndex = 1;
                cdvUser.SelectedSubItemIndex = 0;

                if (ViewUserList(cdvUser.GetListView, cdvDept.Text, cdvOper.Text) == false)
                {
                    return;
                }
                cdvUser.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvUser_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (cdvUser.Text != "")
                {
                    txtUserDesc.Text = cdvUser.DisplayText;
                    cdvUser.DisplayText = cdvUser.Text;
                }
                else
                    txtUserDesc.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                //MPCF.FieldClear(pnlStsCond);
                MPCF.ClearList(spdWorkingTime);
                // MPCF.ClearList(spdConvTime);
                // MPCF.ClearList(spdBreakTime);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                SheetView sv = spdWorkingTime_Sheet1;
                sv.Columns.Get((int)WORKINGTIME.CHK).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.AREA_ID).Visible = true;
                sv.Columns.Get((int)WORKINGTIME.AREA_BUTTON).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.OPER).Visible = true;
                sv.Columns.Get((int)WORKINGTIME.OPER_BUTTON).Visible = false;

                EXTFUC.SaveExcel(spdWorkingTime, string.Format("WorkingTime_{0}", string.IsNullOrEmpty(cdvDept.Text) ? "ALL" : cdvDept.Text));

                sv.Columns.Get((int)WORKINGTIME.CHK).Visible = true;
                sv.Columns.Get((int)WORKINGTIME.AREA_ID).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.AREA_BUTTON).Visible = true;
                sv.Columns.Get((int)WORKINGTIME.OPER).Visible = false;
                sv.Columns.Get((int)WORKINGTIME.OPER_BUTTON).Visible = true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        #endregion
    }
}
