using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_RAS
{
    public partial class frmTranResourceRepairInfoRegistration : CUS_COM.frmTranForm01
    {
        public frmTranResourceRepairInfoRegistration()
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
            WEEKEND_FLAG,           // 5 : 주말 여부
            WEEKDAY_WEEKEND,        // 6 : 주중/주말
            AREA_ID,                // 7 : 조직코드
            AREA_DESC,              // 8 : 조직명
            SUB_AREA_ID,            // 8 : 사업장 코드
            SUB_AREA_DESC,          // 9 : 사업장명
            OPER,                   // 10 :  공정코드
            OPER_DESC,              // 11: 공정명
            GRADE,                  // 12 : 등급
            WORK_USER,              // 13 : 작성자
            REPAIR_TYPE,            // 14 : 수리유형코드
            RES,                    // 15: 설비코드
            RES_DESC,               // 16: 설비명
            ALRAM_TIME,             // 17: 고장통보시간
            ACTION_START_TIME,      // 18: 조치시작시간
            ACTION_END_TIME,        // 19: 조지완료시간
            ACTION_USE_TIME,        // 20: 실 조치시간
            TOTAL_USE_TIME,         // 21: 총 조치시간
            WORST_BM_TIME,          // 22: Worst BM 조치시간
            RECEPTION_DATA,         // 23: 접수내용
            BREAK_CLASS,            // 24. 고장분류코드
            BREAK_CLASS_DESC,       // 25. 고장분류명
            BREAK_PART,             // 26. 고장부위코드
            BREAK_PART_DESC,        // 27. 고장부위명
            BREAK_TYPE,             // 28. 고장유형
            BREAK_TYPE_DESC,        // 29. 고장유형명
            CAUSE_DATA,             // 30. 원인
            ACTION_DATA,            // 31. 조치사항
            REMARK,                 // 32. 비고
            MAN_HOUR,               // 33. 총 공수
            REPAIR_STATUS,          // 34. 진행상태
        }

        private enum SPARE_INFO : int
        {
            CHECK,                  // 1 : 선택
            SPARE_ID,               // 2 : 스페어파트 번호
            SPARE_MAT_ID,           // 3 : 품명
            SPARE_SELECT,           // 4 : 품명 선택
            SPARE_SPEC_ID,          // 5 : 사용규격
            USE_COUNT,              // 6 : 사용개수
        }

        private enum WORKER_INFO : int
        {
            CHECK,                  // 1 : 선택
            WORKER_ID,              // 2 : 작업자 ID
            WORKER_DESC             // 3 : 작업자명
        }
        #endregion

        #region " Variable Definition "

        int spare_row = 0;

        string worstBmTime = "";
        string repairId = "";

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNew.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 설비수리 리스트 조회
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
                dvcArgu[7].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "");

                dvcArgu[8].sCondition_ID = "TO_DATE";
                dvcArgu[8].sCondition_Value = dtpToWorkDate.Text.Replace("-", "");

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
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WEEKEND_FLAG].Value = dt.Rows[i]["WEEKEND_FLAG"].ToString().Trim();
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WEEKDAY_WEEKEND].Value = dt.Rows[i]["WEEKDAY_WEEKEND"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.GRADE].Value = dt.Rows[i]["GRADE"].ToString();
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.WORK_USER].Value = dt.Rows[i]["WORK_USER"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.REPAIR_TYPE].Value = dt.Rows[i]["REPAIR_TYPE"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.RES].Value = dt.Rows[i]["RES_ID"];
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
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_CLASS].Value = dt.Rows[i]["BREAK_CLASS"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_CLASS_DESC].Value = dt.Rows[i]["BREAK_CLASS_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_PART].Value = dt.Rows[i]["BREAK_PART"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_PART_DESC].Value = dt.Rows[i]["BREAK_PART_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_TYPE].Value = dt.Rows[i]["BREAK_TYPE"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.BREAK_TYPE_DESC].Value = dt.Rows[i]["BREAK_TYPE_DESC"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.CAUSE_DATA].Value = dt.Rows[i]["CAUSE_DATA"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.ACTION_DATA].Value = dt.Rows[i]["ACTION_DATA"];
                    spdResRepList_Sheet1.Cells[i, (int)REPAIR_INFO.REMARK].Value = dt.Rows[i]["REMARK"];
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

                    MPCF.ClearList(spdSpare);
                    return;
                }

                spare_row = dt.Rows.Count;

                MPCF.ClearList(spdSpare);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdSpare_Sheet1.RowCount++;

                    spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.CHECK].Value = true;
                    spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.SPARE_ID].Value = dt.Rows[i]["SPARE_ID"];
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
        private void ViewWorkerList(String repairId)
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
                dvcArgu[2].sCondition_Value = cdvAreaId.Text;

                dvcArgu[3].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[3].sCondition_Value = cdvSubAreaId.Text;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWorker);
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

                    case CSGC.CHECK.SAVE:
                        if(MPCF.Trim(txtRepairId.Text) == "")
                        { 
                            MPCF.ShowMsgBox(MPCF.GetMessage(454));
                            return false;
                        }
                       
                        if (MPCF.Trim(cdvAreaId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblAreaId.Text + "]");
                            cdvAreaId.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvSubAreaId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblSubAreaId.Text + "]");
                            cdvSubAreaId.Focus();
                            return false;
                        }

                        //if (MPCF.Trim(cdvDetailOper.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDetailOper.Text + "]");
                        //    cdvDetailOper.Focus();
                        //    return false;
                        //}

                        //if (MPCF.Trim(cdvResId.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResId.Text + "]");
                        //    cdvResId.Focus();
                        //    return false;
                        //}
                        break;

                    case CSGC.CHECK.DELETE:
                        if (MPCF.Trim(txtRepairId.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(454));
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

        //사용 부품 입력 벨리데이션 체크
        private bool CheckRow(int row)
        {
            try
            {
                if (spdSpare_Sheet1.Cells[row, (int)SPARE_INFO.SPARE_ID].Text.Trim() == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdSpare_Sheet1.SetActiveCell(row, (int)SPARE_INFO.SPARE_ID);
                    return false;
                }
                if (spdSpare_Sheet1.Cells[row, (int)SPARE_INFO.USE_COUNT].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdSpare_Sheet1.SetActiveCell(row, (int)SPARE_INFO.USE_COUNT);
                    return false;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //수리상세 초기화
        private void ClearDetail()
        {
            txtRepairId.Text = "";
            dtpWorkDate.Text = "";
            cdvAreaId.Text = "";
            cdvSubAreaId.Text = "";
            cdvDetailRepairType.Text = "";
            dtpAlramTime.Text = "";
            cdvDetailRepairStatus.Text = "";
            cdvWeekend.Text = "";
            cdvDetailOper.Text = "";
            cdvResId.Text = "";
            cdvGrade.Text = "";
            dtpActionStartTime.Text = "";
            dtpActionEndTime.Text = "";
            txtReceptionData.Text = "";
            cdvDetailBreakClass.Text = "";
            cdvBreakPart.Text = "";
            cdvBreakType.Text = "";
            txtCauseData.Text = "";
            txtActionData.Text = "";
            txtRemark.Text = "";
        }

        //Break Part, Break Type 조회
        public static bool ViewGcmCodeList_Break(Control control, string sTableName, string sKey_1 = "")
        {
            string sViewID = "";

            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                sViewID = "CRAS2002-004";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "TABLE_NAME";
                dvcArgu[1].sCondition_Value = sTableName;

                dvcArgu[2].sCondition_ID = "KEY_1";
                dvcArgu[2].sCondition_Value = sKey_1;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            if (MPGV.gcLanguage == '2')
                                itmX.SubItems.Add(row["DATA_2"].ToString());
                            else
                                itmX.SubItems.Add(row["DATA_1"].ToString());
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

        //품명 조회
        private bool ViewSpareMatTypeList(Control control)
        {
            string sViewID = "";

            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                string sSql = "";

                sViewID = "CRAS2002-005";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["SPARE_ID"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["SPARE_MAT_ID"].ToString());
                            itmX.SubItems.Add(row["SPARE_SPEC_ID"].ToString());
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

        //수리 등급 조회
        private void ViewResGrade(string sResId)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2002-006";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "RES_ID";
                dvcArgu[1].sCondition_Value = sResId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    cdvGrade.Text = dt.Rows[i]["RES_GRADE"].ToString();
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //수리 번호 채번
        private bool CreateRepairId()
        {
            try
            {
                TRSNode in_node = new TRSNode("Create Repair");
                TRSNode out_node = new TRSNode("");
  
                MPCR.SetInMsg(in_node);

                //cStep 1 : create
                in_node.ProcStep = '1';
                //in_node.AddString("WORK_DATE", dtpWorkDate.Text.Replace("-", ""));

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Resouce_Repairinfo_Registration", in_node, ref out_node) == false)
                {
                    return false;
                }

                txtRepairId.Text = MPCF.Trim(out_node.GetString("REPAIR_ID"));
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool SaveRepair()
        { 
            try
            {
                repairId = MPCF.Trim(txtRepairId.Text);

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode spare_list;
                TRSNode worker_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';

                //수리정보
                in_node.AddString("REPAIR_ID", repairId);
                in_node.AddString("WORK_DATE", dtpWorkDate.Text.Replace("-", ""));
                in_node.AddChar("WEEKEND_FLAG", cdvWeekend.Text.Trim());
                in_node.AddString("REPAIR_STATUS", cdvDetailRepairStatus.Text);
                in_node.AddString("AREA_ID", cdvAreaId.Text);
                in_node.AddString("SUB_AREA_ID", cdvSubAreaId.Text);
                in_node.AddString("OPER", cdvDetailOper.Text);
                in_node.AddString("RES_ID", cdvResId.Text);
                in_node.AddString("GRADE", cdvGrade.Text);
                in_node.AddString("REPAIR_TYPE", cdvDetailRepairType.Text);
                in_node.AddString("ALRAM_TIME", MPCF.DestroyDateFormat(dtpAlramTime.Text));
                in_node.AddString("ACTION_START_TIME", MPCF.DestroyDateFormat(dtpActionStartTime.Text));
                in_node.AddString("ACTION_END_TIME", MPCF.DestroyDateFormat(dtpActionEndTime.Text));

                //ACTION_USE_TIME = ACTION_END_TIME - ACTION_START_TIME (분)
                TimeSpan ts = MPCF.ToDate(MPCF.DestroyDateFormat(dtpActionEndTime.Text)) - MPCF.ToDate(MPCF.DestroyDateFormat(dtpActionStartTime.Text));
                in_node.AddDouble("ACTION_USE_TIME", ts.TotalMinutes);

                //ACTION_TOTAL_TIME = ACTION_END_TIME - ALARM_TIME (분)
                TimeSpan totalTs = MPCF.ToDate(MPCF.DestroyDateFormat(dtpActionEndTime.Text)) - MPCF.ToDate(MPCF.DestroyDateFormat(dtpAlramTime.Text));
                in_node.AddDouble("TOTAL_USE_TIME", totalTs.TotalMinutes);

                in_node.AddString("RECEPTION_DATA", MPCF.Trim(txtReceptionData.Text));
                in_node.AddString("BREAK_CLASS", cdvDetailBreakClass.Text);
                in_node.AddString("BREAK_PART", cdvBreakPart.Text);
                in_node.AddString("BREAK_TYPE", cdvBreakType.Text);
                in_node.AddString("CAUSE_DATA", MPCF.Trim(txtCauseData.Text));
                in_node.AddString("ACTION_DATA", MPCF.Trim(txtActionData.Text));
                in_node.AddString("PREVENTION_DATA", MPCF.Trim(txtRemark.Text));

                DateTime standardDate = new DateTime(dtpWorkDate.Value.Year, 1, 1);
                Calendar calendar = CultureInfo.CurrentCulture.Calendar;
                int week = calendar.GetWeekOfYear(dtpWorkDate.Value, CalendarWeekRule.FirstDay, DayOfWeek.Monday) - calendar.GetWeekOfYear(standardDate, CalendarWeekRule.FirstDay, DayOfWeek.Monday) + 1;
                in_node.AddInt("WEEK", week);
                in_node.AddInt("MONTH", dtpWorkDate.Value.Month);

                //사용부품
                for (int i = 0; i < spdSpare_Sheet1.RowCount; i++)
                {
                    if (spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (CheckRow(i))
                        {
                            spare_list = in_node.AddNode("SPARE_LIST");

                            spare_list.AddString("SPARE_ID", spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.SPARE_ID].Text.Trim());
                            spare_list.AddString("SPARE_MAT_ID", spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.SPARE_MAT_ID].Text);
                            spare_list.AddString("SPARE_SPEC_ID", spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.SPARE_SPEC_ID].Text);
                            spare_list.AddDouble("USE_COUNT", MPCF.ToDbl(spdSpare_Sheet1.Cells[i, (int)SPARE_INFO.USE_COUNT].Text));
                        }
                        else
                        {
                            return false;
                        }
                    }      
                }

                //작업자 정보
                for(int i = 0; i < spdWorker_Sheet1.RowCount; i++)
                {
                    if (spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        worker_list = in_node.AddNode("WORKER_LIST");

                        worker_list.AddString("WORKER_ID", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Text.Trim());
                        worker_list.AddString("WORKER_DESC", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Text);
                    }
                }

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Resouce_Repairinfo_Registration", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //수리 정보 삭제
        private bool DeleteRepair()
        {
            try
            {
                repairId = MPCF.Trim(txtRepairId.Text);

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '3';

                in_node.AddString("REPAIR_ID", repairId);

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Resouce_Repairinfo_Registration", in_node, ref out_node) == false)
                {
                    return false;
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

        #region " Event Definition"
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

                if (BASLIST.ViewGCMDataList(cdvRepairType.GetListView, '1',CSGC.CP_GCM_REPAIR_TYPE) == false)
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearDetail();
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
                for (int i = 0; i < spdResRepList_Sheet1.RowCount; i++)
                {
                    spdResRepList_Sheet1.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                if (e.ColumnHeader)
                {
                    ClearDetail();
                    MPCF.ClearList(spdSpare);
                    MPCF.ClearList(spdWorker);

                    return;
                }
                    

                if (e.Row < 0)
                    return;

                spdResRepList_Sheet1.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                txtRepairId.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.REPAIR_ID].Text.Trim();
                dtpWorkDate.Value = Convert.ToDateTime(spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.WORK_DATE].Text);
                cdvAreaId.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.AREA_ID].Text;
                cdvAreaId.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.AREA_DESC].Text;
                cdvDetailOper.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.OPER].Text;
                cdvDetailOper.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.OPER_DESC].Text;
                cdvDetailRepairType.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.REPAIR_TYPE].Text;       
                dtpAlramTime.Value = Convert.ToDateTime(spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.ALRAM_TIME].Text);

                cdvDetailRepairStatus.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.REPAIR_STATUS].Text;
                cdvWeekend.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.WEEKEND_FLAG].Text;
                cdvWeekend.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.WEEKDAY_WEEKEND].Text;
                cdvSubAreaId.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.SUB_AREA_ID].Text;
                cdvSubAreaId.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.SUB_AREA_DESC].Text;
                cdvResId.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.RES].Text;
                cdvResId.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.RES_DESC].Text;
                cdvGrade.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.GRADE].Text;

                dtpActionStartTime.Value = Convert.ToDateTime(spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.ACTION_START_TIME].Text);
                dtpActionEndTime.Value = Convert.ToDateTime(spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.ACTION_END_TIME].Text);
                txtReceptionData.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.RECEPTION_DATA].Text;

                cdvDetailBreakClass.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.BREAK_CLASS].Text;
                cdvDetailBreakClass.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.BREAK_CLASS_DESC].Text;
                cdvBreakPart.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.BREAK_PART].Text;
                cdvBreakPart.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.BREAK_PART_DESC].Text;
                cdvBreakType.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.BREAK_TYPE].Text;
                cdvBreakType.DisplayText = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.BREAK_TYPE_DESC].Text;

                txtCauseData.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.CAUSE_DATA].Text;
                txtActionData.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.ACTION_DATA].Text;
                txtRemark.Text = spdResRepList_Sheet1.Cells[e.Row, (int)REPAIR_INFO.REMARK].Text;

                repairId = txtRepairId.Text;
               
                ViewSpareList(repairId);
                ViewWorkerList(repairId);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvDetailRepairStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDetailRepairStatus.Init();
                MPCF.InitListView(cdvDetailRepairStatus.GetListView);
                cdvDetailRepairStatus.Columns.Add("CODE", 50, HorizontalAlignment.Left);
                cdvDetailRepairStatus.Columns.Add("DATA", 100, HorizontalAlignment.Left);
                cdvDetailRepairStatus.SelectedSubItemIndex = 0;
                cdvDetailRepairStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDetailRepairStatus.GetListView, '1', CSGC.CP_GCM_REPAIR_STATUS) == false)
                {
                    return;
                }

                cdvDetailRepairStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWeekend_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWeekend.Init();
                MPCF.InitListView(cdvWeekend.GetListView);
                cdvWeekend.Columns.Add("CODE", 50, HorizontalAlignment.Left);
                cdvWeekend.Columns.Add("DATA", 100, HorizontalAlignment.Left);
                cdvWeekend.SelectedSubItemIndex = 0;
                cdvWeekend.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvWeekend.GetListView, '1', CSGC.CP_GCM_WEEKEND_FLAG) == false)
                {
                    return;
                }

                cdvWeekend.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDetailRepairType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDetailRepairType.Init();
                MPCF.InitListView(cdvDetailRepairType.GetListView);
                cdvDetailRepairType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDetailRepairType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDetailRepairType.SelectedSubItemIndex = 0;
                cdvDetailRepairType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDetailRepairType.GetListView, '1', CSGC.CP_GCM_REPAIR_TYPE) == false)
                {
                    return;
                }

                cdvDetailRepairType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvArea_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvAreaId.Init();
                MPCF.InitListView(cdvAreaId.GetListView);
                cdvAreaId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvAreaId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvAreaId.SelectedSubItemIndex = 0;
                cdvAreaId.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvAreaId.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }

                cdvAreaId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvSubAreaId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvAreaId.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblAreaId.Text + "]");
                    cdvAreaId.Focus();
                    return;
                }

                cdvSubAreaId.Init();
                MPCF.InitListView(cdvSubAreaId.GetListView);
                cdvSubAreaId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvSubAreaId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvSubAreaId.SelectedSubItemIndex = 0;
                cdvSubAreaId.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvSubAreaId.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvAreaId.Text) == false)
                {
                    return;
                }

                cdvSubAreaId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDetailOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvAreaId.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblAreaId.Text + "]");
                    cdvAreaId.Focus();
                    return;
                }

                if (MPCF.Trim(cdvSubAreaId.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblSubAreaId.Text + "]");
                    cdvSubAreaId.Focus();
                    return;
                }

                cdvDetailOper.Init();
                MPCF.InitListView(cdvDetailOper.GetListView);
                cdvDetailOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDetailOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDetailOper.SelectedSubItemIndex = 0;
                cdvDetailOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvDetailOper.GetListView, '1', cdvAreaId.Text, cdvSubAreaId.Text) == false)
                {
                    return;
                }

                cdvDetailOper.InsertEmptyRow(0, 1);
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
                if (MPCF.Trim(cdvDetailOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDetailOper.Text + "]");
                    cdvDetailOper.Focus();
                    return;
                }

                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResId.SelectedSubItemIndex = 0;
                cdvResId.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvResId.GetListView, '1', cdvDetailOper.Text) == false)
                {
                    return;
                }

                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }        
        }

        private void cdvGrade_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvGrade.Init();
                MPCF.InitListView(cdvGrade.GetListView);
                cdvGrade.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvGrade.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvGrade.SelectedSubItemIndex = 0;
                cdvGrade.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvGrade.GetListView, '1', CSGC.CP_GCM_GRADE) == false)
                {
                    return;
                }

                cdvGrade.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDetailBreakClass_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDetailBreakClass.Init();
                MPCF.InitListView(cdvDetailBreakClass.GetListView);
                cdvDetailBreakClass.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDetailBreakClass.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDetailBreakClass.SelectedSubItemIndex = 0;
                cdvDetailBreakClass.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDetailBreakClass.GetListView, '1', CSGC.CP_GCM_BREAK_CLASS) == false)
                {
                    return;
                }

                cdvDetailBreakClass.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvBreakPart_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvBreakPart.Init();
                MPCF.InitListView(cdvBreakPart.GetListView);
                cdvBreakPart.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvBreakPart.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvBreakPart.SelectedSubItemIndex = 0;
                cdvBreakPart.DisplaySubItemIndex = 1;

                if (ViewGcmCodeList_Break(cdvBreakPart.GetListView, CSGC.CP_GCM_BREAK_PART, cdvDetailBreakClass.Text) == false)
                {
                    return;
                }

                cdvBreakPart.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvBreakType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvBreakType.Init();
                MPCF.InitListView(cdvBreakType.GetListView);
                cdvBreakType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvBreakType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvBreakType.SelectedSubItemIndex = 0;
                cdvBreakType.DisplaySubItemIndex = 1;

                if (ViewGcmCodeList_Break(cdvBreakType.GetListView, CSGC.CP_GCM_BREAK_TYPE, cdvDetailBreakClass.Text) == false)
                {
                    return;
                }

                cdvBreakType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            ClearDetail();

            dtpWorkDate.Text = DateTime.Now.ToString("yyyy-MM-dd");

            if(CreateRepairId())
            {
                MPCF.ClearList(spdSpare);
                MPCF.ClearList(spdWorker);
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (txtRepairId.Text == "")
                {
                    //CMN454 ERROR - 선택된 수리 정보가 없습니다. 먼저 수리 정보를 선택하여 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(454));
                    return;
                }

                spdSpare_Sheet1.Rows.Add(spdSpare_Sheet1.RowCount, 1);
                spdSpare_Sheet1.Cells[spdSpare_Sheet1.RowCount - 1, (int)SPARE_INFO.CHECK].Value = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = spdSpare.ActiveSheet.RowCount - 1; i >= spare_row; i--)
                {
                    if (spdSpare.ActiveSheet.Cells[i, (int)SPARE_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdSpare.ActiveSheet.RemoveRows(i, 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSpare_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)SPARE_INFO.SPARE_SELECT)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)SPARE_INFO.SPARE_SELECT)
                    {
                        if (ViewSpareMatTypeList(cdvGridButton.GetListView) == false)
                        {
                            return;
                        }
                    }

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    cdvGridButton.InsertEmptyRow(0, 1);
                }
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
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if(SaveRepair())
                {
                    ViewSpareList(txtRepairId.Text);
                    ViewWorkerList(txtRepairId.Text);

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
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

                if (DeleteRepair())
                {
                    ClearDetail();
                    ClearList();

                    ViewRepairList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAreaId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvSubAreaId.Text = "";
                cdvDetailOper.Text = "";
                cdvResId.Text = "";

                MPCF.ClearList(spdWorker);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvSubAreaId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvDetailOper.Text = "";
                cdvResId.Text = "";

                ViewWorkerList(txtRepairId.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranResourceRepairInfoRegistration_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdSpare.ActiveSheet.ActiveColumnIndex == (int)SPARE_INFO.SPARE_SELECT)
                {
                    spdSpare_Sheet1.SetValue(e.Row, (int)SPARE_INFO.SPARE_ID, e.SelectedItem.SubItems[0].Text);
                    spdSpare_Sheet1.SetValue(e.Row, (int)SPARE_INFO.SPARE_MAT_ID, e.SelectedItem.SubItems[1].Text);
                    spdSpare_Sheet1.SetValue(e.Row, (int)SPARE_INFO.SPARE_SPEC_ID, e.SelectedItem.SubItems[2].Text);
                }

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
                //GRADE 가져오기
                //ViewResGrade(MPCF.Trim(cdvResId.Text));        
                cdvGrade.Text = "";   
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDetailBreakClass_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvBreakType.Text = "";
                cdvBreakPart.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvBreakPart_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvBreakType.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDetailOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvResId.Text = "";
                cdvGrade.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion
    }
}
