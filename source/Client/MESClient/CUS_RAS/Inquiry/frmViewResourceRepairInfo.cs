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
    public partial class frmViewResourceRepairInfo : CUS_COM.frmTranForm02
    {
        public frmViewResourceRepairInfo()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum REPAIR_INFO : int
        {
            REPAIR_ID,              // 1 : 수리번호
            WORK_DATE,              // 2 : 등록일
            MONTH,                  // 3 : 월
            WEEK,                   // 4 : 주차
            WEEKDAY_WEEKEND,        // 5 : 주중/주말
            AREA_ID,                // 6 : 조직코드
            AREA_DESC,              // 7 : 조직명
            SUB_AREA_ID,            // 8 : 사업장코드
            SUB_AREA_DESC,          // 9 : 사업장명
            OPER_DESC,              // 10: 공정명
            GRADE,                  // 11: 등급
            WORK_USER,              // 12: 작성자
            REPAIR_TYPE,            // 13: 수리유형코드
            RES_DESC,               // 14: 설비명
            ALRAM_TIME,             // 15: 고장통보시간
            ACTION_START_TIME,      // 16: 조치시작시간
            ACTION_END_TIME,        // 17: 조지완료시간
            ACTION_USE_TIME,        // 18: 실 조치시간
            TOTAL_USE_TIME,         // 19: 총 조치시간
            WORST_BM_TIME,          // 20: Worst BM 조치시간
            RECEPTION_DATA,         // 21: 접수내용
            BREAK_CLASS_DESC,       // 22. 고장분류명
            BREAK_PART_DESC,        // 23. 고장부위명
            BREAK_TYPE_DESC,        // 24. 고장유형명
            CAUSE_DATA,             // 25. 원인
            ACTION_DATA,            // 26. 조치사항
            REMARK,                 // 27. 비고
            WORKER_COUNT,           // 28. 투입입원
            MAN_HOUR,               // 29. 총 공수
            REPAIR_STATUS,          // 30. 진행상태
        }

        private enum SPARE_INFO : int
        {
            SPARE_TYPE,             // 1 : 분류
            SPARE_MAT_ID,           // 2 : 품명
            SPARE_SPEC_ID,          // 3 : 사용규격
            USE_COUNT,              // 4 : 사용개수
        }

        private enum WORKER_INFO : int
        {
            CHECK,                  // 1 : 선택
            WORKER_ID,              // 2 : 작업자 ID(사번)
            WORKER_DESC             // 3 : 작업자명
        }

        #endregion

        #region " Variable Definition "

        string repairId = "";
        string areaid = "";
        string subareaid = "";
        string worstBmTime = "";

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

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
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

        //리스트 초기화
        private void ClearList()
        {
            try
            {
                MPCF.ClearList(spdResRepList);
                MPCF.ClearList(spdSpare);
                MPCF.ClearList(spdWorker);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewRepairList()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2002-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "REPAIR_TYPE";
                dvcArgu[4].sCondition_Value = cdvRepairType.Text;

                dvcArgu[5].sCondition_ID = "REPAIR_STATUS";
                dvcArgu[5].sCondition_Value = cdvRepairStatus.Text;

                dvcArgu[6].sCondition_ID = "BREAK_CLASS";
                dvcArgu[6].sCondition_Value = cdvBreakClass.Text;

                dvcArgu[7].sCondition_ID = "FROM_DATE";
                dvcArgu[7].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[8].sCondition_ID = "TO_DATE";
                dvcArgu[8].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[9].sCondition_ID = "LANGUAGE";
                dvcArgu[9].sCondition_Value = MPGV.gcLanguage;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdResRepList_Sheet1.RowCount++;

                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.REPAIR_ID].Value = dt.Rows[i]["REPAIR_ID"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.MONTH].Value = dt.Rows[i]["MONTH"].ToString();
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WEEK].Value = dt.Rows[i]["WEEK"].ToString();
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WEEKDAY_WEEKEND].Value = dt.Rows[i]["WEEKDAY_WEEKEND"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.GRADE].Value = dt.Rows[i]["GRADE"].ToString();
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WORK_USER].Value = dt.Rows[i]["WORK_USER"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.REPAIR_TYPE].Value = dt.Rows[i]["REPAIR_TYPE"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.ALRAM_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["ALRAM_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME).Substring(0, 16);
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.ACTION_START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["ACTION_START_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME).Substring(0, 16);
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.ACTION_END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["ACTION_END_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME).Substring(0, 16);
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.ACTION_USE_TIME].Value = dt.Rows[i]["ACTION_USE_TIME"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.TOTAL_USE_TIME].Value = dt.Rows[i]["TOTAL_USE_TIME"];
                    worstBmTime = dt.Rows[i]["WORST_BM_TIME"].ToString();
                    if (MPCF.ToDbl(dt.Rows[i]["WORST_BM_TIME"]) > 0)
                    {
                        spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WORST_BM_TIME].Value = worstBmTime;
                        spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WORST_BM_TIME].ForeColor = Color.FromArgb(255, 0, 0);
                    }
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.RECEPTION_DATA].Value = dt.Rows[i]["RECEPTION_DATA"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_CLASS_DESC].Value = dt.Rows[i]["BREAK_CLASS_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_PART_DESC].Value = dt.Rows[i]["BREAK_PART_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_TYPE_DESC].Value = dt.Rows[i]["BREAK_TYPE_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.CAUSE_DATA].Value = dt.Rows[i]["CAUSE_DATA"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.ACTION_DATA].Value = dt.Rows[i]["ACTION_DATA"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.REMARK].Value = dt.Rows[i]["REMARK"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WORKER_COUNT].Value = dt.Rows[i]["WORKER_COUNT"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.MAN_HOUR].Value = dt.Rows[i]["MAN_HOUR"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.REPAIR_STATUS].Value = dt.Rows[i]["REPAIR_STATUS"];
                }
                MPCF.FitColumnHeader(spdResRepList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //사용 부품 리스트 조회
        private void ViewSpareList(string repairId)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2002-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPAIR_ID";
                dvcArgu[1].sCondition_Value = repairId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                MPCF.ClearList(spdSpare);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdSpare_Sheet1.RowCount++;

                    spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.SPARE_TYPE].Value = dt.Rows[i]["SPARE_TYPE"];
                    spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.SPARE_MAT_ID].Value = dt.Rows[i]["SPARE_MAT_ID"];
                    spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.SPARE_SPEC_ID].Value = dt.Rows[i]["SPARE_SPEC_ID"];
                    spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.USE_COUNT].Value = dt.Rows[i]["USE_COUNT"];
                }

                MPCF.FitColumnHeader(spdSpare);
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업자 정보 리스트 조회
        private void ViewWorkerList(String repairId, string areaId, string subareaId)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2002-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPAIR_ID";
                dvcArgu[1].sCondition_Value = repairId;

                dvcArgu[2].sCondition_ID = "AREA_ID";
                dvcArgu[2].sCondition_Value = areaId;

                dvcArgu[3].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[3].sCondition_Value = subareaId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                MPCF.ClearList(spdWorker);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorker_Sheet1.RowCount++;

                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.CHECK].Value = Convert.ToBoolean(dt.Rows[i]["CHECK"]);
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                }

                MPCF.FitColumnHeader(spdWorker);
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition"

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearList();

                ViewRepairList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdResRepList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                //for (int i = 0; i < spdResRepList_Sheet1.RowCount; i++)
                //{
                //    spdResRepList_Sheet1.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                //}

                if (e.ColumnHeader)
                {
                    MPCF.ClearList(spdSpare);
                    MPCF.ClearList(spdWorker);

                    return;
                }


                if (e.Row < 0)
                    return;

                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdResRepList, e.Row);
                }

                //spdResRepList_Sheet1.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                repairId = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.REPAIR_ID].Text.Trim();
                areaid = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.AREA_ID].Text.Trim();
                subareaid = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.SUB_AREA_ID].Text.Trim();

                ViewSpareList(repairId);
                ViewWorkerList(repairId, areaid, subareaid);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvBreakClass_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvBreakClass.Init();
                MPCF.InitListView(cdvBreakClass.GetListView);
                cdvBreakClass.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvBreakClass.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvBreakClass.SelectedSubItemIndex = 0;
                cdvBreakClass.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvBreakClass.GetListView, '1', CSGC.CP_GCM_BREAK_CLASS) == false)
                {
                    return;
                }

                cdvBreakClass.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRepairType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvRepairType.Init();
                MPCF.InitListView(cdvRepairType.GetListView);
                cdvRepairType.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvRepairType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvRepairType.SelectedSubItemIndex = 0;
                cdvRepairType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvRepairType.GetListView, '1', CSGC.CP_GCM_REPAIR_TYPE) == false)
                {
                    return;
                }

                cdvRepairType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRepairStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvRepairStatus.Init();
                MPCF.InitListView(cdvRepairStatus.GetListView);
                cdvRepairStatus.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvRepairStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvRepairStatus.SelectedSubItemIndex = 0;
                cdvRepairStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvRepairStatus.GetListView, '1', CSGC.CP_GCM_REPAIR_STATUS) == false)
                {
                    return;
                }

                cdvRepairStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmViewResourceRepairInfo_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromDate.Value = dtpToDate.Value.AddDays(-7);
                //dtpFromDate.Format = DateTimePickerFormat.Custom;
                //dtpFromDate.CustomFormat = " ";
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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                FpSpread excelSp = new FpSpread();
                spdResRepList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdResRepList_Sheet1);
                spdSpare_Sheet1.SheetName = "Sheet2";
                excelSp.Sheets.Add(spdSpare_Sheet1);
                spdWorker_Sheet1.SheetName = "Sheet3";
                excelSp.Sheets.Add(spdWorker_Sheet1);

                EXTFUC.SaveExcel(excelSp, "ResourceRepairInfo");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void dtpFromDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        #endregion
    }
}
