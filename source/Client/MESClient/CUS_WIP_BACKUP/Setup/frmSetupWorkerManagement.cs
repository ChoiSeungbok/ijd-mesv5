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
    public partial class frmSetupWorkerManagement : CUS_COM.frmTranForm01
    {
        public frmSetupWorkerManagement()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        // 작업자 정보
        private enum WORKER_INFO : int
        {
            CHECK,                  // 1 : 선택
            WORKER_ID,              // 2 : 사번
            WORKER_DESC,            // 3 : 작업자 명
            AREA_ID,                // 4 : 사업부 코드
            AREA_DESC,              // 5 : 사업부명
            AREA_SELECT,            // 6 : 사업부 버튼
            SUB_AREA_ID,            // 7 : 작업장 코드
            SUB_AREA_DESC,          // 8 : 작업장명
            SUB_AREA_SELECT,        // 9 : 작업장 버튼     
            DEPT_CODE,              // 10: 부서정보코드  
            DEPT_DESC,              // 11: 부서정보명      
            DEPT_SELECT,            // 12: 부서정보 버튼        
        }

        #endregion

        #region " Variable Definition "

        int worker_row = 0;
   
        int check_cnt = 0; 

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewWorkerList()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CWIP1001-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "DEPT_CODE";
                dvcArgu[3].sCondition_Value = cdvDeptCode.Text;

                MPCF.ClearList(spdWorker);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorker_Sheet1.RowCount++;

                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Value = dt.Rows[i]["DEPT_CODE"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_DESC].Value = dt.Rows[i]["DEPT_DESC"];
                }
                MPCF.FitColumnHeader(spdWorker);
                worker_row = spdWorker_Sheet1.RowCount;

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
                        break;

                    case CSGC.CHECK.DELETE:
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

        private bool CheckRow(int row)
        {
            try
            { 
                if (spdWorker_Sheet1.Cells[row, (int)WORKER_INFO.WORKER_ID].Text.Trim() == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdWorker.ActiveSheet.SetActiveCell(row, (int)WORKER_INFO.WORKER_ID);
                    return false;
                }
                if (spdWorker_Sheet1.Cells[row, (int)WORKER_INFO.WORKER_DESC].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdWorker.ActiveSheet.SetActiveCell(row, (int)WORKER_INFO.WORKER_DESC);
                    return false;
                }   
                if (spdWorker_Sheet1.Cells[row, (int)WORKER_INFO.AREA_ID].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdWorker.ActiveSheet.SetActiveCell(row, (int)WORKER_INFO.AREA_ID);
                    return false;
                }
                if (spdWorker_Sheet1.Cells[row, (int)WORKER_INFO.SUB_AREA_ID].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdWorker.ActiveSheet.SetActiveCell(row, (int)WORKER_INFO.SUB_AREA_ID);
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

        // 작업자 목록 정보로 저장
        private bool SaveWorkerInfo()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode worker_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';

                check_cnt = 0;

                for (int i = 0; i < spdWorker_Sheet1.RowCount; i++)
                {
                    if (spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (CheckRow(i))
                        {
                            worker_list = in_node.AddNode("WORKER_LIST");

                            worker_list.AddString("WORKER_ID", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Text.Trim());
                            worker_list.AddString("WORKER_DESC", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Text.Trim());
                            worker_list.AddString("AREA_ID", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_ID].Text);
                            worker_list.AddString("SUB_AREA_ID", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.SUB_AREA_ID].Text);
                            worker_list.AddString("DEPT_CODE", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Text);

                            check_cnt++;
                        }
                        else
                        {
                            return false;
                        }
                    }  
                }

                if (check_cnt > 0)
                {
                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Worker_Management", in_node, ref out_node) == false)
                    {
                        return false;
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

        // 선택된 작업자 삭제
        private bool DeleteWorkerList()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode worker_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';

                check_cnt = 0; 

                for (int i = 0; i < spdWorker_Sheet1.RowCount; i++)
                {
                    if (spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        worker_list = in_node.AddNode("WORKER_LIST");

                        worker_list.AddString("WORKER_ID", spdWorker.ActiveSheet.Cells[i, (int)WORKER_INFO.WORKER_ID].Text.Trim());
                        check_cnt++;
                    }
                }

                if(check_cnt > 0)
                {
                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Worker_Management", in_node, ref out_node) == false)
                    {
                        return false;
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

        #endregion

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                {
                    return;
                }

                ViewWorkerList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            int iRow = spdWorker_Sheet1.RowCount;

            try
            {
                spdWorker_Sheet1.RowCount++;
                spdWorker_Sheet1.SetValue(iRow, (int)WORKER_INFO.CHECK, true);
                spdWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.AREA_ID].Value = cdvDept.Text;
                spdWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.AREA_DESC].Value = cdvDept.DisplayText;
                spdWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.SUB_AREA_ID].Value = cdvWorkPlace.Text;
                spdWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.SUB_AREA_DESC].Value = cdvWorkPlace.DisplayText;
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
                for (int i = spdWorker.ActiveSheet.RowCount - 1; i >= worker_row; i--)
                {
                    if (spdWorker.ActiveSheet.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdWorker.ActiveSheet.RemoveRows(i, 1);
                    }
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
                {
                    return;
                }

                // 작업자 목록 정보로 저장
                if(SaveWorkerInfo())
                {
                    ViewWorkerList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                {
                    return;
                }

                DialogResult dr = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                if (dr == DialogResult.OK)
                {
                    if (DeleteWorkerList())
                    {
                        ViewWorkerList();

                        MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    }
                }    
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void spdWorker_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)WORKER_INFO.AREA_SELECT || e.Column == (int)WORKER_INFO.SUB_AREA_SELECT || e.Column == (int)WORKER_INFO.DEPT_SELECT)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)WORKER_INFO.AREA_SELECT)
                    {
                        //사업부 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                            return;

                        spdWorker_Sheet1.Cells[e.Row, (int)WORKER_INFO.SUB_AREA_ID].Value = "";
                        spdWorker_Sheet1.Cells[e.Row, (int)WORKER_INFO.SUB_AREA_DESC].Value = "";
                    }
                    else if (e.Column == (int)WORKER_INFO.SUB_AREA_SELECT)
                    {
                        //작업장 조회
                        if (BASLIST.ViewGCMDataList_AREA(cdvGridButton.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, spdWorker_Sheet1.Cells[e.Row, (int)WORKER_INFO.AREA_ID].Text) == false)
                            return;
                    }
                    else if (e.Column == (int)WORKER_INFO.DEPT_SELECT)
                    {
                        //부서정보 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_DEPT_CODE) == false)
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

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdWorker.ActiveSheet.ActiveColumnIndex == (int)WORKER_INFO.AREA_SELECT)
                {
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.AREA_ID, e.SelectedItem.SubItems[0].Text);
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.AREA_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (spdWorker.ActiveSheet.ActiveColumnIndex == (int)WORKER_INFO.SUB_AREA_SELECT)
                {
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.SUB_AREA_ID, e.SelectedItem.SubItems[0].Text);
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.SUB_AREA_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (spdWorker.ActiveSheet.ActiveColumnIndex == (int)WORKER_INFO.DEPT_SELECT)
                {
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.DEPT_CODE, e.SelectedItem.SubItems[0].Text);
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.DEPT_DESC, e.SelectedItem.SubItems[1].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDeptCode_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDeptCode.Init();
                MPCF.InitListView(cdvDeptCode.GetListView);
                cdvDeptCode.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDeptCode.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDeptCode.SelectedSubItemIndex = 0;
                cdvDeptCode.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDeptCode.GetListView, '1', CSGC.CP_GCM_DEPT_CODE) == false)
                {
                    return;
                }

                cdvDeptCode.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
