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

namespace CUS_WIP
{
    public partial class frmTranWorkerRegistration : CUS_COM.frmTranForm01
    {
        public frmTranWorkerRegistration()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKER_INFO : int
        {
            CHECK,                  // 1 : 선택
            WORKER_DESC,            // 2 : 이름
            DEPT_CODE,              // 3 : 부서코드
            DEPT_DESC,              // 4 : 부서명
            WORKER_ID               // 5 : 사번
        }

        private enum REGISTERED_WORKER_INFO : int
        {
            CHECK,                  // 1 : 선택
            WORKER_DESC,            // 2 : 이름
            DEPT_CODE,              // 3 : 부서코드
            GROUP_ID,               // 4 : 작업조
            WORKER_ID,               // 5 : 사번
            WORK_TYPE
        }

        #endregion

        #region " Variable Definition "

        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper = "";
        public string sOper_desc = "";
        public string sGroup_id = "";
        public string sGroup_desc = "";

        string area_id = "";
        string sub_area_id = "";
        string oper = "";
        string group_id = "";

        #endregion

        #region " Function Defintion "

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

        //벨리데이션 체크 함수
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

                        if (MPCF.Trim(cdvCusOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvCusOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvGroupId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblGroupId.Text + "]");
                            cdvGroupId.Focus();
                            return false;
                        }
                        break;

                    case CSGC.CHECK.SAVE:
                        if (MPCF.Trim(area_id) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(sub_area_id) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
                            return false;
                        }

                        if (MPCF.Trim(oper) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvCusOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(group_id) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblGroupId.Text + "]");
                            cdvGroupId.Focus();
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

        //전체 작업자 정보 조회
        private void ViewEntireWorkerList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvCusOper.Text;

                dvcArgu[4].sCondition_ID = "GROUP_ID";
                dvcArgu[4].sCondition_Value = cdvGroupId.Text;


                if (TPDR.GetDataOne("", ref dt, "CWIP2006-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdEntireWorker);
                    return;
                }

                MPCF.ClearList(spdEntireWorker);

                area_id = cdvDept.Text;
                sub_area_id = cdvWorkPlace.Text;
                oper = cdvCusOper.Text;
                group_id = cdvGroupId.Text;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdEntireWorker_Sheet1.RowCount++;

                    spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Value = dt.Rows[i]["DEPT_CODE"];
                    spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_DESC].Value = dt.Rows[i]["DEPT_DESC"];
                    spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];               
                }
                MPCF.FitColumnHeader(spdEntireWorker);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //등록된 작업자 정보 조회
        private void ViewRegisteredWorkerList()
        {
            try
            {
                ViewRegisteredWorkerList(cdvDept.Text, cdvWorkPlace.Text, cdvCusOper.Text, cdvGroupId.Text);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewRegisteredWorkerList(string areaId, string subAreaId, string oper, string groupId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = areaId;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = subAreaId;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = oper;

                dvcArgu[4].sCondition_ID = "GROUP_ID";
                dvcArgu[4].sCondition_Value = groupId;

                if (TPDR.GetDataOne("", ref dt, "CWIP2006-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdRegWorker);
                    return;
                }

                MPCF.ClearList(spdRegWorker);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRegWorker_Sheet1.RowCount++;

                    spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.DEPT_CODE].Value = dt.Rows[i]["DEPT_CODE"];
                    spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                    spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];
                }
                MPCF.FitColumnHeader(spdRegWorker);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SaveWorkGroup()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode worker_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';

                in_node.AddString("AREA_ID", area_id);
                in_node.AddString("SUB_AREA_ID", sub_area_id);
                in_node.AddString("OPER", oper);
                in_node.AddString("GROUP_ID", group_id);

                for (int i = 0; i < spdRegWorker_Sheet1.RowCount; i++)
                {
                    worker_list = in_node.AddNode("WORKER_LIST");
                    worker_list.AddString("WORKER_ID", spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORKER_ID].Text.Trim());
                    worker_list.AddString("WORK_TYPE", spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORK_TYPE].Text.Trim());
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Worker_Registration", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region " Event Defintion "
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewEntireWorkerList();
                ViewRegisteredWorkerList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;
            bool c_flag = true;

            try
            {
                if (group_id == "") return;

                for (int i = spdEntireWorker_Sheet1.RowCount-1; i >=0; i--)
                {
                    if (spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        c_flag = true;

                        sTmp = spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Text;

                        for (int k = 0; k < spdRegWorker_Sheet1.RowCount; k++)
                        {
                            if (spdRegWorker_Sheet1.Cells[k, (int)REGISTERED_WORKER_INFO.WORKER_ID].Text == sTmp)
                            {
                                c_flag = false;
                                continue;
                            }
                        }

                        if (c_flag)
                        {
                            iRow = spdRegWorker_Sheet1.RowCount;
                            spdRegWorker_Sheet1.RowCount++;

                            spdRegWorker_Sheet1.SetValue(iRow, (int)REGISTERED_WORKER_INFO.CHECK, true);
                            spdRegWorker_Sheet1.Cells[iRow, (int)REGISTERED_WORKER_INFO.WORKER_DESC].Value = spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Text;
                            spdRegWorker_Sheet1.Cells[iRow, (int)REGISTERED_WORKER_INFO.DEPT_CODE].Value = spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Text;
                            spdRegWorker_Sheet1.Cells[iRow, (int)REGISTERED_WORKER_INFO.GROUP_ID].Value = group_id;
                            spdRegWorker_Sheet1.Cells[iRow, (int)REGISTERED_WORKER_INFO.WORKER_ID].Value = spdEntireWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Text;
                        }

                        spdEntireWorker_Sheet1.RemoveRows(i, 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;
            bool c_flag = true;

            try
            {
                for (int i = spdRegWorker_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        c_flag = true;

                        sTmp = spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORKER_ID].Text;

                        for (int k = 0; k < spdEntireWorker_Sheet1.RowCount; k++)
                        {
                            if (spdEntireWorker_Sheet1.Cells[k, (int)WORKER_INFO.WORKER_ID].Text == sTmp)
                            {
                                c_flag = false;
                                continue;
                            }
                        }

                        if (c_flag)
                        {
                            iRow = spdEntireWorker_Sheet1.RowCount;
                            spdEntireWorker_Sheet1.RowCount++;

                            spdEntireWorker_Sheet1.SetValue(iRow, (int)WORKER_INFO.CHECK, false);
                            spdEntireWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.WORKER_DESC].Value = spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORKER_DESC].Text;
                            spdEntireWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.DEPT_CODE].Value = spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.DEPT_CODE].Text;
                            spdEntireWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.WORKER_ID].Value = spdRegWorker_Sheet1.Cells[i, (int)REGISTERED_WORKER_INFO.WORKER_ID].Text;
                        }

                        spdRegWorker_Sheet1.RemoveRows(i, 1);
                    }
                }

                spdEntireWorker_Sheet1.SortRows((int)WORKER_INFO.WORKER_ID, true, false);
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

                if(SaveWorkGroup())
                {
                    ViewEntireWorkerList();
                    ViewRegisteredWorkerList(area_id, sub_area_id, oper, group_id);

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    this.DialogResult = DialogResult.OK;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGroupId_ButtonPress(object sender, EventArgs e)
        { 
            try
            {
                cdvGroupId.Init();
                MPCF.InitListView(cdvGroupId.GetListView);
                cdvGroupId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvGroupId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvGroupId.SelectedSubItemIndex = 0;
                cdvGroupId.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvGroupId.GetListView, '1', CSGC.CP_GCM_WORKER_GROUP) == false)
                {
                    return;
                }

                cdvGroupId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranWorkerRegistration_Load(object sender, EventArgs e)
        {

            cdvDept.Text = sArea_id;
            cdvDept.DisplayText = sArea_desc;
            cdvWorkPlace.Text = sSub_area_id;
            cdvWorkPlace.DisplayText = sSub_area_desc;
            cdvCusOper.Text = sOper;
            cdvCusOper.DisplayText = sOper_desc;
            cdvGroupId.Text = sGroup_id;
            cdvGroupId.DisplayText = sGroup_desc;

           if (CheckCondition(CSGC.CHECK.VIEW) == false)
               return;

            ViewEntireWorkerList();
            ViewRegisteredWorkerList();

        }

        private void cdvCusOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvCusOper.Init();
                MPCF.InitListView(cdvCusOper.GetListView);
                cdvCusOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCusOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCusOper.SelectedSubItemIndex = 0;
                cdvCusOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvCusOper.GetListView, 'M', cdvDept.Text, cdvWorkPlace.Text, "", "") == false)
                {
                    return;
                }

                cdvCusOper.InsertEmptyRow(0, 1);
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
                cdvCusOper.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion
    }
}
