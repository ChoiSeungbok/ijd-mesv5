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
    public partial class frmTranScrapMoldConfrim : CUS_COM.frmTranForm01
    {
        public frmTranScrapMoldConfrim()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum REQUEST_INFO : int
        {
            REQ_NO,             // 1. 요청번호
            REQ_USER_DESC,      // 2. 요청자명
            OPER_DESC,          // 3. 요청 공정
            REQ_TIME,           // 4. 요청 일시
            REQ_STATUS_DESC,    // 5. 요청 상태명
            REQ_COMMENT         // 6. 요청 비고
        }

        private enum MOLD_INFO  : int
        {
           // CHECK,              // 1. 선택
            REQ_NO,             // 2. 요청번호
            TOOL_ID,            // 3. 금형 번호
            TOOL_DESC,          // 4. 금형 명
            TOOL_GRP_DESC,      // 5. 금형 모델
            TOOL_TYPE,          // 6. 금형 구분
            TOOL_TYPE_DESC      // 7. 금형 구분명
        }

        #endregion

        #region " Variable Definition "

        string selected_request_no = "";
        int selected_row = -1;

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

                        //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                        //    cdvWorkPlace.Focus();
                        //    return false;
                        //}

                        //if (MPCF.Trim(cdvOper.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                        //    cdvOper.Focus();
                        //    return false;
                        //}

                        break;

                    case CSGC.CHECK.SAVE:
                        if (selected_request_no == "")
                        {
                            //CMN458 ERROR - 선택된 요청 번호가 없습니다. 먼저 요청 번호를 선택하여 주세요
                            MPCF.ShowMsgBox(MPCF.GetMessage(458));
                            return false;
                        }

                        if (MPCF.Trim(cdvWorker.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorker.Text + "]");
                            cdvWorker.Focus();
                            return false;
                        }

                        if (cdvOutType.Enabled)
                        {
                            if (string.IsNullOrEmpty(cdvOutType.Text))
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOutType.Text + "]");
                                cdvOutType.Focus();
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

        //  초기화
        public void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":
                        selected_request_no = "";
                        selected_row = -1;

                        MPCF.ClearList(spdRequestListInfo);

                        cdvWorker.Text = "";
                        txtComment.Text = "";
                        break;

                    case "LIST":
                        selected_row = -1;

                        MPCF.ClearList(spdRequestListInfo);

                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 설비 작업자 리스트 조회
        private bool ViewResWorkerList(Control control, string sViewID)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                string sSql = "";

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
                        itmX = new ListViewItem(row["WORKER_ID"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["WORKER_DESC"].ToString());
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

        //요청 정보 조회
        public void ViewRequestInfo()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2007-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text + "%";

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[4].sCondition_ID = "MOLD_MODEL";
                dvcArgu[4].sCondition_Value = cdvModel.Text;

                dvcArgu[5].sCondition_ID = "MOLD_TYPE";
                dvcArgu[5].sCondition_Value = cdvMoldType.Text;

                dvcArgu[6].sCondition_ID = "TOOL_ID";
                dvcArgu[6].sCondition_Value = cdvToolId.Text;

                MPCF.ClearList(spdRequestInfo);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRequestInfo_Sheet1.RowCount++;

                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_NO].Value = dt.Rows[i]["REQ_NO"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_USER_DESC].Value = dt.Rows[i]["REQ_USER_DESC"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["REQ_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME).Substring(0, 16);
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_STATUS_DESC].Value = dt.Rows[i]["REQ_STATUS_DESC"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_COMMENT].Value = dt.Rows[i]["REQ_COMMENT"];

                    if (selected_request_no == dt.Rows[i]["REQ_NO"].ToString())
                    {
                        selected_row = i;
                        spdRequestInfo.ActiveSheet.Rows[selected_row].BackColor = Color.FromArgb(255, 192, 255);
                    }
                }

                MPCF.FitColumnHeader(spdRequestInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 폐기 요청된 금형 리스트 조회
        private void ViewScrapMoldList(string requestNo)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2006-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REQ_NO";
                dvcArgu[1].sCondition_Value = requestNo;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRequestListInfo_Sheet1.RowCount++;

                    spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.REQ_NO].Value = dt.Rows[i]["REQ_NO"];
                    spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.TOOL_DESC].Value = dt.Rows[i]["TOOL_DESC"];
                    spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.TOOL_GRP_DESC].Value = dt.Rows[i]["TOOL_GRP_DESC"];
                    spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.TOOL_TYPE].Value = dt.Rows[i]["TOOL_TYPE"];
                    spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.TOOL_TYPE_DESC].Value = dt.Rows[i]["TOOL_TYPE_DESC"];
                }
                MPCF.FitColumnHeader(spdRequestListInfo);

                return;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 금형 폐기 처리
        private bool ScrapMold()
        {
            TRSNode in_node = new TRSNode("Tran_In");
            TRSNode out_node = new TRSNode("Tran_Out");
            TRSNode mold_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("REQ_NO", selected_request_no);

                //선택된 폐기할 금형 리스트
                for (int i = 0; i < spdRequestListInfo_Sheet1.RowCount; i++)
                {
                   // if (spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                   // {
                        mold_list = in_node.AddNode("TOOL_LIST");

                        mold_list.AddString("TOOL_ID", spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.TOOL_ID].Text.Trim());
                        mold_list.AddString("TOOL_TYPE", spdRequestListInfo_Sheet1.Cells[i, (int)MOLD_INFO.TOOL_TYPE].Text);
                   // }
                }

                in_node.AddString("ETC_OUT_TYPE", cdvOutType.Text);
                in_node.AddString("CONFIRM_USER_ID", cdvWorker.Text);
                in_node.AddString("CONFIRM_COMMENT", txtComment.Text);

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Scrap_Mold_Confirm", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCF.ShowMsgBox(MPCF.GetMessage(52));

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

        private void cdvModel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvModel.Init();
                MPCF.InitListView(cdvModel.GetListView);
                cdvModel.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvModel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvModel.SelectedSubItemIndex = 0;
                cdvModel.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvModel.GetListView, '1', MPGC.MP_RAS_TOOL_GRP) == false)
                {
                    return;
                }

                cdvModel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMoldType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMoldType.Init();
                MPCF.InitListView(cdvMoldType.GetListView);
                cdvMoldType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMoldType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMoldType.SelectedSubItemIndex = 0;
                cdvMoldType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMoldType.GetListView, '1', CSGC.CP_GCM_MOLD_TYPE) == false)
                {
                    return;
                }
                cdvMoldType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorker_ButtonPress(object sender, EventArgs e)
        {

            /*
            string sView_Id = "";

            try
            {
               // sView_Id = "CRAS2007-001";
                sView_Id = "CINV2009-004";  //임시로 하나의 사업무 모두 나오게 하고  요청사항이 있을 때 바꿔주도록 함.

                cdvWorker.Init();
                MPCF.InitListView(cdvWorker.GetListView);
                cdvWorker.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorker.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorker.SelectedSubItemIndex = 0;
                cdvWorker.DisplaySubItemIndex = 1;

                //작업자 호출
                if(ViewResWorkerList(cdvWorker.GetListView, sView_Id) ==false)
                {
                    return ;
                }
                cdvWorker.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            } */

            string sViewID = "";
            try
            {
                sViewID = "CRAS2007-004";

                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvWorker.Init();
                MPCF.InitListView(cdvWorker.GetListView);
                cdvWorker.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorker.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorker.SelectedSubItemIndex = 0;
                cdvWorker.DisplaySubItemIndex = 1;

                //요청자 호출 (Sub Area 는 넣지 않음)
                if (COM_LIST.ViewWorkerList(cdvWorker.GetListView, sViewID, cdvDept.Text, "") == false)
                {
                    return;
                }

                cdvWorker.InsertEmptyRow(0, 1);
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

                ClearData("ALL");

                ViewRequestInfo();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdRequestInfo_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                for (int i = 0; i < spdRequestInfo.ActiveSheet.RowCount; i++)
                {
                    spdRequestInfo.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                ClearData("ALL");
                if (e.ColumnHeader || e.Row < 0)
                {                    
                    return;
                }

                selected_row = e.Row;
                spdRequestInfo.ActiveSheet.Rows[selected_row].BackColor = Color.FromArgb(255, 192, 255);
                selected_request_no = spdRequestInfo_Sheet1.Cells[selected_row, (int)REQUEST_INFO.REQ_NO].Text;

                ViewScrapMoldList(selected_request_no);
            }
            catch(Exception ex)
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

                //CMN462 INFO -진짜 폐기처리 하시겠습니까?
                DialogResult dr = MessageBox.Show(MPCF.GetMessage(462), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                if (dr == DialogResult.OK)
                {
                    if (ScrapMold())
                    {
                        ViewRequestInfo();

                        ClearData("LIST");

                        ViewRequestInfo();
                        ViewScrapMoldList(selected_request_no);
                        selected_request_no = "";

                       
                    }
                }
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
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                //창고 조회
                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '3', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToolId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvMoldType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMoldType.Text + "]");
                    cdvMoldType.Focus();
                    return;
                }

                cdvToolId.Init();
                MPCF.InitListView(cdvToolId.GetListView);
                cdvToolId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToolId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolId.SelectedSubItemIndex = 0;
                cdvToolId.DisplaySubItemIndex = 1;

                //금형번호 호출
                if (RASLIST.ViewToolList(cdvToolId.GetListView, '1', cdvMoldType.Text, ' ', false, null) == false)
                {
                    return;
                }
                cdvToolId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMoldType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvToolId.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOutType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOutType.Init();
                MPCF.InitListView(cdvOutType.GetListView);
                cdvOutType.Columns.Add("DESC", 50, HorizontalAlignment.Left);
                cdvOutType.Columns.Add("ID", 100, HorizontalAlignment.Left);
                cdvOutType.SelectedSubItemIndex = 1;
                cdvOutType.DisplaySubItemIndex = 0;

                if (COM_LIST.ViewEtcTypeList(cdvOutType.GetListView, "CRAS2007-003", cdvDept.Text, "ISSUE") == false)
                {
                    return;
                }

                cdvOutType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion
    }
}
