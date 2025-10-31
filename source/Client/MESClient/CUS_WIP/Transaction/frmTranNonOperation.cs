using System;
using System.Data;
using System.Windows.Forms;


using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;
using CUS_COM.Reports;

namespace CUS_WIP
{      
    public partial class frmTranNonOperation : CUS_COM.frmTranForm03
    {
        #region ""
        public frmTranNonOperation()
        {
            InitializeComponent();
            InitControl();
        }
        #endregion

        #region " Constant Definition "

        private enum RESOURCE
        {
            CHK,
            RES_ID,
            RES_DESC,
            NON_STATUS,
            DOWN_START_TIME,
            DOWN_END_TIME,
            SEQ,
            HIST_SEQ,
            AREA_ID,
            SUB_AREA_ID,
            OPER
        }
        private enum MOSTNONOP
        {
            CHK,
            DOWN_TYPE_1,
            DOWN_TYPE_2,
            DOWN_TYPE_3
        }
        private enum NONOP
        {
            CHK,
            DOWN_TYPE_1,
            DOWN_TYPE_2,
            DOWN_TYPE_3
        }

        #endregion

        #region " Variable Definition "

        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper = "";
        public string sOper_desc = "";
        public string sRes_id = "";
        public string sRes_desc = "";

        #endregion

        #region " Event Definition "
        private void frmTranNonOperation_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvWorkPlace.Text = sSub_area_id;
                cdvWorkPlace.DisplayText = sSub_area_desc;
                cdvOper.Text = sOper;
                cdvOper.DisplayText = sOper_desc;
                cdvResource.Text = sRes_id;
                cdvResource.DisplayText = sRes_desc;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void spdResourceList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            int i = 0;
            bool allChecked = false;

            SheetView svRes = spdResourceList.ActiveSheet;

            if (e.Row >= 0 && Convert.ToBoolean(svRes.Cells[e.Row, (int)RESOURCE.CHK] == null ? false : svRes.Cells[e.Row, (int)RESOURCE.CHK].Value))
                svRes.Cells[e.Row, (int)RESOURCE.CHK].Value = true;

            dtpDownStartTime.Value = DateTime.Now;
            dtpDownEndTime.Value = DateTime.Now;


            if (e.ColumnHeader == false)
            {
                return;
            }

            if (e.Column != (int)RESOURCE.CHK)
            {
                return;
            }

            if (svRes.ColumnHeader.Cells[0, 0].Value == null || Convert.ToBoolean(svRes.ColumnHeader.Cells[0, 0].Value == null ? false : svRes.ColumnHeader.Cells[0, 0].Value) == false)
            {
                allChecked = false;
            }
            else
            {
                allChecked = true;
            }

            if (allChecked == true)
            {
                for (i = 0; i < svRes.RowCount; i++)
                {
                    svRes.Cells[i, 0].Value = false;
                }

                svRes.ColumnHeader.Cells[0, 0].Value = false;
            }
            else
            {
                for (i = 0; i < svRes.RowCount; i++)
                {
                    svRes.Cells[i, 0].Value = true;
                }
                svRes.ColumnHeader.Cells[0, 0].Value = true;
            }
        }
        
        private void spdMostDownTypeList_CellClick(object sender, CellClickEventArgs e)
        {
            SheetView svMostDown = spdMostDownTypeList.ActiveSheet;
            SheetView svDown = spdDownTypeList.ActiveSheet;

            if (e.ColumnHeader)
            {
                return;
            }

            if (e.Column != (int)MOSTNONOP.CHK)
            {
                return;
            }
            
            svDown.ClearSelection();

            if (!Convert.ToBoolean(svMostDown.Cells[e.Row, (int)NONOP.CHK].Value))
            {
                //비가동 선택된 ROW만 체크 나머지 해제
                for (int i = 0; i < svMostDown.RowCount; i++)
                {
                    //해당 ROW
                    if (i == e.Row)
                    {
                        svMostDown.SetValue(e.Row, (int)MOSTNONOP.CHK, true);

                        for (int j = 0; j < svDown.RowCount; j++)
                        {
                            //우선순위와 기본정보들 비교
                            if (svDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_3].Tag == svMostDown.Cells[e.Row, (int)NONOP.DOWN_TYPE_3].Tag)
                            {
                                svDown.SetValue(j, (int)MOSTNONOP.CHK, true);
                                svDown.AddSelection(j, 0, 1, 2);
                            }
                            else
                            {
                                svDown.SetValue(j, (int)MOSTNONOP.CHK, false);
                            }
                        }
                    }
                    else
                    {
                        svMostDown.SetValue(i, (int)MOSTNONOP.CHK, false);
                    }
                }
            }
            else
            {
                svMostDown.SetValue(e.Row, (int)MOSTNONOP.CHK, false);

                //우선순위 비가동 모두 선택해제
                for (int i = 0; i < svDown.RowCount; i++)
                {
                    svDown.SetValue(i, (int)MOSTNONOP.CHK, false);
                }
            }
        }

        private void spdDownTypeList_CellClick(object sender, CellClickEventArgs e)
        {
            SheetView svMostDown = spdMostDownTypeList.ActiveSheet;
            SheetView svDown = spdDownTypeList.ActiveSheet;

            if (e.ColumnHeader)
            {
                return;
            }

            if (e.Column != (int)NONOP.CHK)
            {
                return;
            }
            
            svMostDown.ClearSelection();

            if (!Convert.ToBoolean(svDown.Cells[e.Row, (int)NONOP.CHK].Value))
            {
                //비가동 선택된 ROW만 체크 나머지 해제
                for (int i = 0; i < svDown.RowCount; i++)
                {
                    //해당 ROW
                    if (i == e.Row)
                    {
                        svDown.SetValue(e.Row, (int)NONOP.CHK, true);

                        for (int j = 0; j < svMostDown.RowCount; j++)
                        {
                            //우선순위와 기본정보들 비교
                            if (svMostDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_3].Tag == svDown.Cells[e.Row, (int)NONOP.DOWN_TYPE_3].Tag)
                            {
                                svMostDown.SetValue(j, (int)MOSTNONOP.CHK, true);
                                svMostDown.AddSelection(j, 0, 1, 2);
                            }
                            else
                            {
                                svMostDown.SetValue(j, (int)MOSTNONOP.CHK, false);
                            }
                        }
                    }
                    else
                    {
                        svDown.SetValue(i, (int)NONOP.CHK, false);
                    }
                }
            }
            else
            {
                svDown.SetValue(e.Row, (int)NONOP.CHK, false);

                //우선순위 비가동 모두 선택해제
                for (int i = 0; i < svMostDown.RowCount; i++)
                {
                    svMostDown.SetValue(i, (int)MOSTNONOP.CHK, false);
                }
            }
        }
        
        private void chkEditDate_CheckedChanged(object sender, EventArgs e)
        {
            dtpDownStartTime.Enabled = chkEditDate.Checked;
            dtpDownEndTime.Enabled = chkEditDate.Checked;
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ResSearch();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                if (!CheckCondition(CSGC.CHECK.CANCEL))
                    return;

                if (!SaveNonOperation(MPGC.MP_STEP_DELETE))
                    return;

                ResSearch();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnNonStart_Click(object sender, EventArgs e)
        {
            try
            {
                if (!CheckCondition(CSGC.CHECK.START))
                {
                    return;
                }

                if (!SaveNonOperation(MPGC.MP_STEP_CREATE))
                    return;

                ResSearch();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnEnd_Click(object sender, EventArgs e)
        {
            try
            {
                if (!CheckCondition(CSGC.CHECK.END))
                {
                    return;
                }

                if (!SaveNonOperation(MPGC.MP_STEP_UPDATE))
                    return;

                ResSearch();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }

        private void cdvOrder_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOrder.DisplayText == "")
                cdvOrder.Text = "";
        }

        private void btnLabel_Click(object sender, EventArgs e)
        {


            try
            {


                DataTable dt = new DataTable();

                dt.Columns.Add("MACHINE", typeof(string));
                dt.Columns.Add("NAME_KO", typeof(string));


                string sFileName;


                for (int iRow = 0; iRow < spdResourceList_Sheet1.RowCount; iRow++)
                {
                    if (Convert.ToBoolean(spdResourceList_Sheet1.Cells[iRow, (int)RESOURCE.CHK].Value) == true)
                    {
                        dt.Rows.Add(spdResourceList_Sheet1.Cells[iRow, (int)RESOURCE.RES_ID].Value, spdResourceList_Sheet1.Cells[iRow, (int)RESOURCE.RES_DESC].Value);
                    }
                }

                if (dt.Rows.Count != 0)
                {

                    sFileName = "mcn810t";
                    DevReport.PreviewXtraReport(dt, sFileName);
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }



        }

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                dtpDownStartTime.Value = DateTime.Now;
                dtpDownEndTime.Value = DateTime.Now;

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNonStart.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNonEnd.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                lblDownStartTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                lblDownEndTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                dtpDownStartTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                dtpDownEndTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                chkEditDate.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
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
                SheetView svRes = spdResourceList.ActiveSheet;
                SheetView svDown = spdDownTypeList.ActiveSheet;
                int iCheckCount = 0;

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (string.IsNullOrEmpty(MPCF.Trim(cdvDept.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (string.IsNullOrEmpty(MPCF.Trim(cdvWorkPlace.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
                            return false;
                        }

                        if (string.IsNullOrEmpty(MPCF.Trim(cdvOper.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        break;
                    case CSGC.CHECK.START:

                        //설비 선택 체크
                        if (svRes.RowCount <= 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(grpResourceList.Text + " : " + MPCF.GetMessage(109));
                            return false;
                        }
                        else
                        {
                            for (int i = 0; i < svRes.RowCount; i++)
                            {
                                //체크항목만 확인
                                if (Convert.ToBoolean(svRes.Cells[i, (int)RESOURCE.CHK].Value))
                                {
                                    iCheckCount++;

                                    //비가동 상태가 존재하면 에러
                                    if (!string.IsNullOrEmpty(MPCF.Trim(svRes.Cells[i, (int)RESOURCE.NON_STATUS].Value)))
                                    {
                                        //CMN470 INFO - 현재 비가동 상태입니다, 종료후 START 바랍니다.
                                        MPCF.ShowMsgBox(svRes.Cells[i, (int)RESOURCE.RES_DESC].Value + " : " + MPCF.GetMessage(470));
                                        return false;
                                    }
                                }
                            }

                            if (iCheckCount <= 0)
                            {
                                //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                                MPCF.ShowMsgBox(grpResourceList.Text + " : " + MPCF.GetMessage(109));
                                return false;
                            }
                        }

                        iCheckCount = 0;

                        //비가동 선택 체크
                        if (svDown.RowCount <= 0)
                        {
                            MPCF.ShowMsgBox(grpDownTypeList.Text + " : " + MPCF.GetMessage(109));
                            return false;
                        }
                        else
                        {
                            for (int i = 0; i < svDown.RowCount; i++)
                            {
                                //체크항목만 확인
                                if (Convert.ToBoolean(svDown.Cells[i, (int)NONOP.CHK].Value))
                                {
                                    iCheckCount++;

                                    //비가동 코드가 존재하지 않으면
                                    if (string.IsNullOrEmpty(MPCF.Trim(svDown.Cells[i, (int)NONOP.DOWN_TYPE_3].Tag)))
                                    {
                                        //CMN473 INFO - 비가동 코드 정보가 존재하지 않습니다.
                                        MPCF.ShowMsgBox(svRes.Cells[i, (int)NONOP.DOWN_TYPE_3].Value + " : " + MPCF.GetMessage(473));
                                        return false;
                                    }
                                }
                            }

                            if (iCheckCount <= 0)
                            {
                                //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                                MPCF.ShowMsgBox(grpResourceList.Text + " : " + MPCF.GetMessage(109));
                                return false;
                            }

                            if (iCheckCount >= 2)
                            {
                                //CMN474 INFO - 비가동 코드 정보가 두개 이상입니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(474));
                                return false;
                            }
                        }
                        
                        break;
                    case CSGC.CHECK.END:
                        if (svRes.RowCount <= 0)
                        {
                            MPCF.ShowMsgBox(grpResourceList.Text + " : " + MPCF.GetMessage(109));
                            return false;
                        }
                        else
                        {
                            for (int i = 0; i < svRes.RowCount; i++)
                            {
                                //체크항목만 확인
                                if (Convert.ToBoolean(svRes.Cells[i, (int)RESOURCE.CHK].Value == null ? false : svRes.Cells[i, (int)RESOURCE.CHK].Value))
                                {
                                    iCheckCount++;

                                    //비가동 상태가 존재하지 않으면 에러
                                    if (string.IsNullOrEmpty(MPCF.Trim(svRes.Cells[i, (int)RESOURCE.NON_STATUS].Value)))
                                    {
                                        //CMN471 INFO - 비가동이 존재하지 않습니다. 시작 후 종료해주세요.
                                        MPCF.ShowMsgBox(svRes.Cells[i, (int)RESOURCE.RES_DESC].Value + " : " + MPCF.GetMessage(471));
                                        return false;
                                    }

                                    //비가동 시작시간을 종료시간이 앞에 있을때 에러
                                    if(chkEditDate.Checked)
                                    {
                                        string sStartTime = MPCF.Trim(svRes.Cells[i, (int)RESOURCE.DOWN_START_TIME].Value.ToString().Replace(":", "").Replace("-", "").Replace(" ", ""));
                                        
                                        if (MPCF.ToDbl(sStartTime)
                                            > MPCF.ToDbl(MPCF.ToStandardTime(dtpDownEndTime.Value, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(dtpDownEndTime.Value, MPGC.MP_CONVERT_TIME_FORMAT)))
                                        {
                                            //CMN475 INFO - 종료시간이 시작시간보다 앞일 수 없습니다.
                                            MPCF.ShowMsgBox(svRes.Cells[i, (int)RESOURCE.RES_DESC].Value + " : " + MPCF.GetMessage(475));
                                            return false;
                                        }
                                    }
                                }
                            }

                            if (iCheckCount <= 0)
                            {
                                //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                                MPCF.ShowMsgBox(grpResourceList.Text + " : " + MPCF.GetMessage(109));
                                return false;
                            }
                        }
                        break;
                    case CSGC.CHECK.CANCEL:
                        if (svRes.RowCount <= 0)
                        {
                            MPCF.ShowMsgBox(grpResourceList.Text + " : " + MPCF.GetMessage(109));
                            return false;
                        }
                        else
                        {
                            for (int i = 0; i < svRes.RowCount; i++)
                            {
                                //체크항목만 확인
                                if (Convert.ToBoolean(svRes.Cells[i, (int)RESOURCE.CHK].Value == null ? false : svRes.Cells[i, (int)RESOURCE.CHK].Value))
                                {
                                    iCheckCount++;

                                    //비가동 상태가 존재하지 않으면 에러
                                    if (string.IsNullOrEmpty(MPCF.Trim(svRes.Cells[i, (int)RESOURCE.NON_STATUS].Value)))
                                    {
                                        //CMN472 INFO - 비가동정보가 존재하지 않습니다.
                                        MPCF.ShowMsgBox(svRes.Cells[i, (int)RESOURCE.RES_DESC].Value + " : " + MPCF.GetMessage(472));
                                        return false;
                                    }
                                }
                            }

                            if (iCheckCount <= 0)
                            {
                                //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                                MPCF.ShowMsgBox(grpResourceList.Text + " : " + MPCF.GetMessage(109));
                                return false;
                            }
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
        
        private void ResSearch()
        {
            try
            {
                //초기화
                MPCF.ClearList(spdResourceList);
                spdResourceList.ActiveSheet.ColumnHeader.Cells[0, (int)RESOURCE.CHK].Value = false;

                SheetView svRes = spdResourceList.ActiveSheet;

                //TPDR.GetDataOne 다이렉트 쿼리
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                string sView_Id;

                sView_Id = "CWIP2005-003"; //쿼리번호(뷰아이디)

                dvcArgu[0].sCondition_ID = "P_FACTORY"; //조건코드
                dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값

                dvcArgu[1].sCondition_ID = "P_OPER"; //조건코드
                dvcArgu[1].sCondition_Value = cdvOper.Text; //

                dvcArgu[2].sCondition_ID = "P_RES_ID"; //조건코드
                dvcArgu[2].sCondition_Value = string.Empty; //

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt == null || dt.Rows.Count == 0)
                    {
                        //추후 메시지 필요하면 추가하는 것으로 현재 다른화면도 없음
                    }
                    else
                    {
                        dt.Dispose();
                    }
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    svRes.RowCount++;

                    svRes.Cells[i, (int)RESOURCE.CHK].Value = dt.Rows[i]["CHK"];
                    svRes.Cells[i, (int)RESOURCE.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    svRes.Cells[i, (int)RESOURCE.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    svRes.Cells[i, (int)RESOURCE.NON_STATUS].Value = dt.Rows[i]["NON_STATUS"];
                    svRes.Cells[i, (int)RESOURCE.DOWN_START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["DOWN_START_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    svRes.Cells[i, (int)RESOURCE.DOWN_END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["DOWN_END_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    svRes.Cells[i, (int)RESOURCE.SEQ].Value = dt.Rows[i]["SEQ"];
                    svRes.Cells[i, (int)RESOURCE.HIST_SEQ].Value = dt.Rows[i]["HIST_SEQ"];
                    svRes.Cells[i, (int)RESOURCE.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    svRes.Cells[i, (int)RESOURCE.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    svRes.Cells[i, (int)RESOURCE.OPER].Value = dt.Rows[i]["OPER"];
                }

                //설비리스트 출력되면 해당하는 비가동 코드 호출
                NonOpSearch();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void NonOpSearch()
        {
            try
            {
                //초기화
                MPCF.ClearList(spdMostDownTypeList);
                MPCF.ClearList(spdDownTypeList);

                SheetView svDown = spdDownTypeList.ActiveSheet;
                SheetView svMostDown = spdMostDownTypeList.ActiveSheet;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                string sView_Id;

                sView_Id = "CWIP2005-005"; //쿼리번호(뷰아이디)

                dvcArgu[0].sCondition_ID = "P_FACTORY"; //조건코드
                dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt == null || dt.Rows.Count == 0)
                    {
                        //추후 메시지 필요하면 추가하는 것으로 현재 다른화면도 없음
                    }
                    else
                    {
                        dt.Dispose();
                    }
                    return;
                }

                int j = 0;

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    svDown.RowCount++;
                    //svDown.Cells[i, (int)NONOP.CHK].Value = dt.Rows[i]["CHK"];
                    svDown.Cells[i, (int)NONOP.DOWN_TYPE_1].Tag = dt.Rows[i]["KEY_1"];
                    svDown.Cells[i, (int)NONOP.DOWN_TYPE_2].Tag = dt.Rows[i]["KEY_2"];
                    svDown.Cells[i, (int)NONOP.DOWN_TYPE_3].Tag = dt.Rows[i]["KEY_3"];
                    svDown.Cells[i, (int)NONOP.DOWN_TYPE_1].Value = dt.Rows[i]["DATA_1"];
                    svDown.Cells[i, (int)NONOP.DOWN_TYPE_2].Value = dt.Rows[i]["DATA_2"];
                    svDown.Cells[i, (int)NONOP.DOWN_TYPE_3].Value = dt.Rows[i]["DATA_3"];

                    //우선순위 여부 Y인것만 비가동 우선순위에 보여줌
                    if (MPCF.Trim(dt.Rows[i]["MOST_NOP_YN"]) == "Y")
                    {
                        svMostDown.RowCount++;
                        //svMostDown.Cells[j, (int)MOSTNONOP.CHK].Value = dt.Rows[i]["CHK"];
                        svMostDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_1].Tag = dt.Rows[i]["KEY_1"];
                        svMostDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_2].Tag = dt.Rows[i]["KEY_2"];
                        svMostDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_3].Tag = dt.Rows[i]["KEY_3"];
                        svMostDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_1].Value = dt.Rows[i]["DATA_1"];
                        svMostDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_2].Value = dt.Rows[i]["DATA_2"];
                        svMostDown.Cells[j, (int)MOSTNONOP.DOWN_TYPE_3].Value = dt.Rows[i]["DATA_3"];

                        j++;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private bool SaveNonOperation(char cStep)
        {
            SheetView svRes = spdResourceList.ActiveSheet;
            SheetView svDown = spdDownTypeList.ActiveSheet;

            try
            {
                TRSNode in_node = new TRSNode("Non_Op_In");
                TRSNode out_node = new TRSNode("Non_Op_Out");
                TRSNode res_list;

                MPCR.SetInMsg(in_node);

                //생성 : I 종료 : U 삭제 : D
                in_node.ProcStep = cStep;
                
                for (int i = 0; i < svRes.RowCount; i++)
                {
                    if (i == 0)
                    {
                        //한번만 넣어주면 됨
                        in_node.AddString("AREA_ID", MPCF.Trim(svRes.Cells[i, (int)RESOURCE.AREA_ID].Value));
                        in_node.AddString("SUB_AREA_ID", MPCF.Trim(svRes.Cells[i, (int)RESOURCE.SUB_AREA_ID].Value));
                        in_node.AddString("OPER", MPCF.Trim(svRes.Cells[i, (int)RESOURCE.OPER].Value));
                    }

                    if (Convert.ToBoolean(svRes.Cells[i, (int)RESOURCE.CHK].Value))
                    {
                        res_list = in_node.AddNode("RES_TBL");
                        res_list.AddString("RES_ID", MPCF.Trim(svRes.Cells[i, (int)RESOURCE.RES_ID].Value));

                        //서버에서 KEY 값
                        res_list.AddInt("SEQ", MPCF.ToInt(svRes.Cells[i, (int)RESOURCE.SEQ].Value));
                        res_list.AddInt("HIST_SEQ", MPCF.ToInt(svRes.Cells[i, (int)RESOURCE.HIST_SEQ].Value));
                    }
                }

                if (cStep == MPGC.MP_STEP_CREATE)
                {
                    //비가동 코드 정보
                    for (int i = 0; i < svDown.RowCount; i++)
                    {
                        //체크항목만
                        if (Convert.ToBoolean(svDown.Cells[i, (int)NONOP.CHK].Value))
                        {
                            in_node.AddString("DOWN_CODE", svDown.Cells[i, (int)NONOP.DOWN_TYPE_3].Tag);
                            in_node.AddString("DOWN_TYPE_1", svDown.Cells[i, (int)NONOP.DOWN_TYPE_1].Tag);
                            in_node.AddString("DOWN_TYPE_2", svDown.Cells[i, (int)NONOP.DOWN_TYPE_2].Tag);
                            in_node.AddString("DOWN_TYPE_3", svDown.Cells[i, (int)NONOP.DOWN_TYPE_3].Tag);

                            break;
                        }
                    }

                    if (!chkEditDate.Checked)
                    {
                        in_node.AddString("DOWN_START_TIME", MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_TIME_FORMAT));
                    }
                    else
                    {
                        in_node.AddString("DOWN_START_TIME", MPCF.ToStandardTime(dtpDownStartTime.Value, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(dtpDownStartTime.Value, MPGC.MP_CONVERT_TIME_FORMAT));
                    }
                }
                else if (cStep == MPGC.MP_STEP_UPDATE)
                {
                    if (!chkEditDate.Checked)
                    {
                        in_node.AddString("DOWN_END_TIME", MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_TIME_FORMAT));
                    }
                    else
                    {
                        in_node.AddString("DOWN_END_TIME", MPCF.ToStandardTime(dtpDownEndTime.Value, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(dtpDownEndTime.Value, MPGC.MP_CONVERT_TIME_FORMAT));
                    }
                }
                
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_non_operation", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCF.ShowMsgBox(out_node.Msg);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        #endregion


    }
}
